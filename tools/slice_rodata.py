#!/usr/bin/env python3
"""slice_rodata.py <decomp dir> <MODULE.XFF> [--dry]  (v4.3)

After chunk.py, .rodata is still one `all_rodata` blob, so C code that needs its own literals (strings, switch jump tables, float
constants) cannot match: the TU's rodata would land at the wrong place. Compilers emit a TU's rodata contiguously and in function order,
so every chunk gets the slice of the blob that its functions reference (splat then migrates it into the function files, and a C-compiled
function brings its own rodata back through the TU's .rodata).  Per chunk: the references (%hi/%lo symbols in the chunk's function .s
files that resolve to an address inside .rodata) -> lowest address >= the previous cut, ignoring addresses referenced from >= 3 chunks (shared
tables); cuts are rounded down to 8 (segment alignment); chunks without own references get no slice. The first slice starts at the section
start, the last runs to the section end. Subsegment names equal the code chunk names (what migrate_rodata_to_functions needs).
Then reconfigure the module, build, require the module SHA1; on failure the yaml is restored and the module reconfigured.
"""
import hashlib, os, re, subprocess, sys
from collections import defaultdict
from pathlib import Path
dec = Path(sys.argv[1]); mod = sys.argv[2]; dry = "--dry" in sys.argv
os.chdir(dec)
yaml_p = Path("config") / mod / f"{mod}.yaml"; ytxt = yaml_p.read_text()
m = re.search(r"^(\s*)- \[ (0x[0-9A-Fa-f]+), rodata, all_rodata \]\n", ytxt, re.M)
if not m: sys.exit("no `[ off, rodata, all_rodata ]` line (already sliced, or not chunked?)")
indent, ro_off = m.group(1), int(m.group(2), 16)
BASE = 0x40010000
rm = re.search(r"- name: rodata\n(?:.*\n)*?\s*start: (0x[0-9A-Fa-f]+)\n", ytxt)
foot = re.search(r"- name: xff_footer\n(?:.*\n)*?\s*start: (0x[0-9A-Fa-f]+)\n", ytxt)
ro_end_off = int(foot.group(1), 16)   # rodata runs up to the footer (symtab) in these modules
# the .mdebug/.symtab footer follows .rodata directly; round the real end of rodata to the footer start
ro_lo, ro_hi = BASE + ro_off, BASE + ro_end_off
alias = {l.split()[1]: l.split()[0] for l in subprocess.run([str(Path(__file__).resolve().parent / "modules"), "."], capture_output=True, text=True).stdout.splitlines()}[mod]
def configure():
    for f in (Path("config") / mod).glob("*_auto.txt"): f.unlink()
    return subprocess.run(["./configure.py", "-c", "-t", alias], capture_output=True, text=True)
# symbol addresses from the symbols files
symaddr = {}
for f in (Path("config") / mod).glob("*symbols*.txt"):
    for n, a in re.findall(r"^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", f.read_text(errors="replace"), re.M): symaddr[n] = int(a, 16)
REF = re.compile(r"%(?:hi|lo)\(([A-Za-z_][\w.]*)(?:\s*\+\s*(0x[0-9A-Fa-f]+))?\)")
def addr_of(name, add):
    mm = re.search(r"_([0-9A-Fa-f]{8})$", name)
    a = int(mm.group(1), 16) if mm else symaddr.get(name)
    return None if a is None else a + (int(add, 16) if add else 0)
nm_root = Path("asm") / mod / "nonmatchings" / "chunk"
if not nm_root.exists(): sys.exit(f"{nm_root} missing: configure the module first")
chunks = sorted(p.name for p in nm_root.iterdir() if p.is_dir())
refs = {}
for c in chunks:
    s = set()
    for f in (nm_root / c).glob("*.s"):
        for name, add in REF.findall(f.read_text(errors="replace")):
            a = addr_of(name, add)
            if a is not None and ro_lo <= a < ro_hi: s.add(a)
    refs[c] = s
count = defaultdict(int)
for s in refs.values():
    for a in s: count[a] += 1
cut_prev = ro_lo; slices = []   # (chunk, vram cut)
for c in chunks:
    own = sorted(a for a in refs[c] if a >= cut_prev and count[a] < 3)
    if not own: continue
    cut = own[0] & ~7
    if cut < cut_prev: cut = cut_prev
    if slices and cut == slices[-1][1]: continue      # would give the previous chunk an empty slice
    slices.append((c, cut)); cut_prev = cut + 8
if not slices: sys.exit("no rodata references into the blob: nothing to slice")
slices[0] = (slices[0][0], ro_lo)                     # leading rodata belongs to the first referencing chunk
print(f"{mod}: {len(chunks)} chunks, rodata {ro_hi - ro_lo:#x} bytes, {len(slices)} slices")
if dry: sys.exit(0)
lines = "".join(f"{indent}- [ {cut - BASE:#x}, rodata, chunk/{c} ]\n" for c, cut in slices)
yaml_p.write_text(ytxt[:m.start()] + lines + ytxt[m.end():])
def fail(msg):
    yaml_p.write_text(ytxt); configure(); print("FAILED, yaml restored and module reconfigured:", msg); sys.exit(1)
r = configure()
if r.returncode: fail("configure: " + r.stderr[-800:])
r = subprocess.run(["ninja", "-f", f"{mod}.ninja"], capture_output=True, text=True)
tail = [l for l in (r.stdout + r.stderr).splitlines() if "FAILED" in l or "rror" in l][-6:]
sha = Path(f"checksum-{mod}.sha1").read_text().split()[0]; out = Path("build") / mod / mod
good = out.exists() and hashlib.sha1(out.read_bytes()).hexdigest() == sha
print(f"ninja rc={r.returncode} sha1_ok={good}")
if not good: fail(" | ".join(tail))
print("sliced and SHA1 green; yaml updated (commit config/ with git add -f)")
