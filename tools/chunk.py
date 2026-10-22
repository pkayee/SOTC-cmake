#!/usr/bin/env python3
"""chunk.py <decomp dir> <MODULE.XFF> [--target KB] [--min KB] [--max KB] [--dry]  (v4.2)

Split a module's single `asm all_text` segment into `c` chunks at function starts (code only; .data/.rodata stay whole blobs, so a function
that needs its own rodata/data - strings, switch tables, globals - is not matchable until the rodata slicing step v4.3).
Every chunk starts at an 8-aligned function start that is a real function start: not a `func_` label that the previous function branches to
(splat's false starts), and only after a function that ends in jr/j/b + delay slot (+ padding nops). Preferred cut: symbol-name prefix change
after --min KB; forced cut at the next allowed point after --max KB. Chunk names: chunk/cNNNN_<first function>.
Then: reconfigure that module (own process), build, check the module SHA1; on any failure the yaml is restored and the script says why.
"""
import hashlib, os, re, subprocess, sys
from pathlib import Path
dec = Path(sys.argv[1]); mod = sys.argv[2]
def opt(f, d): return float(sys.argv[sys.argv.index(f) + 1]) if f in sys.argv else d
TARGET, MIN, MAX = [int(opt(f, d) * 1024) for f, d in (("--target", 6), ("--min", 3), ("--max", 12))]
os.chdir(dec)
yaml_p = Path("config") / mod / f"{mod}.yaml"; ytxt = yaml_p.read_text()
m = re.search(r"^(\s*)- \[ (0x[0-9A-Fa-f]+), asm, all_text \]\n", ytxt, re.M)
if not m: sys.exit("no `[ off, asm, all_text ]` line (already chunked?)")
indent, text_off = m.group(1), int(m.group(2), 16)
alias = {l.split()[1]: l.split()[0] for l in subprocess.run([str(Path(__file__).resolve().parent / "modules"), "."], capture_output=True, text=True).stdout.splitlines()}[mod]
def configure():
    for f in (Path("config") / mod).glob("*_auto.txt"): f.unlink()
    return subprocess.run(["./configure.py", "-c", "-t", alias], capture_output=True, text=True)
src = Path("asm") / mod / "all_text.s"
if not src.exists(): configure()   # e.g. left over from a failed earlier run
if not src.exists(): sys.exit(f"{src} missing: configure the module first")
INS = re.compile(r"^\s*/\* ([0-9A-Fa-f]+) ([0-9A-Fa-f]{8}) [0-9A-Fa-f]{8} \*/\s+(\S+)(.*)$")
BR = {"b", "beq", "bne", "beqz", "bnez", "bgez", "bgtz", "blez", "bltz", "bc1f", "bc1t", "beql", "bnel", "beqzl", "bnezl", "bgezl", "bgtzl", "blezl", "bltzl", "bc1fl", "bc1tl", "bgezal", "bltzal"}
btargets = set(); funcs = []   # dict(name, off, ins=[(mn, rest)])
cur = None
for ln in src.read_text(errors="replace").splitlines():
    if ln.startswith("glabel "):
        cur = dict(name=ln.split()[1], off=None, ins=[]); funcs.append(cur); continue
    mi = INS.match(ln)
    if mi and cur is not None:
        if cur["off"] is None: cur["off"] = int(mi.group(1), 16); cur["vaddr"] = int(mi.group(2), 16)
        mn, rest = mi.group(3), mi.group(4)
        vaddr = int(mi.group(2), 16)
        if mn == ".word":   # branch to a func_ label rewritten by configure.py (computed workaround): decode the target from the word
            mw = re.search(r"/\* (\w+)\s.*?\b(func_[0-9A-Fa-f]+)\s*\*/", rest)
            if mw and mw.group(1) in BR:
                btargets.add(mw.group(2)); mn = mw.group(1)
        cur["ins"].append((mn, rest))
funcs = [f for f in funcs if f["off"] is not None]
# branch targets that are function-label names -> those labels are false function starts
def ends_clean(f):
    ins = f["ins"]; i = len(ins) - 1
    while i >= 0 and ins[i][0] == "nop": i -= 1
    if i < 0: return False
    # last non-nop is either the delay slot of a jr/j/b, or the jr/j/b itself followed only by its nop delay slot
    for k in (i, i - 1):
        if k >= 0 and (ins[k][0] in ("jr", "j", "b", "eret") or (ins[k][0] == "jr")): return True
    return False
ok = []
for i, f in enumerate(funcs):
    allowed = i == 0 or (f["off"] % 8 == 0 and f["name"] not in btargets and ends_clean(funcs[i - 1]))
    ok.append(allowed)
def prefix(n):
    m2 = re.match(r"([A-Za-z]+?)(?=[A-Z_0-9]|$)", n.lstrip("_")); return (m2.group(1) if m2 else n)[:5].lower()
size = lambda f: 4 * len(f["ins"])
chunks, start, acc = [], 0, 0
for i, f in enumerate(funcs):
    if i > start and ok[i] and (acc >= MAX or (acc >= TARGET) or (acc >= MIN and prefix(funcs[i - 1]["name"]) != prefix(f["name"]))):
        chunks.append((start, i)); start, acc = i, 0
    acc += size(f)
chunks.append((start, len(funcs)))
print(f"{mod}: {len(funcs)} functions, {sum(1 for o in ok if not o) - 0} not cut points, {len({f['name'] for f in funcs} & btargets)} false-start labels, {len(chunks)} chunks "
      f"(avg {sum(size(f) for f in funcs) // len(chunks)} B)")
lines = []
for n, (a, b) in enumerate(chunks):
    nm = funcs[a]["name"]; nm = re.sub(r"[^A-Za-z0-9_]", "", nm)[:40]
    lines.append(f"{indent}- [ {funcs[a]['off']:#x}, c, chunk/c{n:04d}_{nm} ]\n")
if "--dry" in sys.argv: sys.exit(0)
new = ytxt[:m.start()] + "".join(lines) + ytxt[m.end():]
yaml_p.write_text(new)
def fail(msg):
    yaml_p.write_text(ytxt); configure(); print("FAILED, yaml restored and module reconfigured:", msg); sys.exit(1)
r = configure()
if r.returncode: fail("configure: " + r.stderr[-800:])
r = subprocess.run(["ninja", "-f", f"{mod}.ninja"], capture_output=True, text=True)
tail = [l for l in (r.stdout + r.stderr).splitlines() if "FAILED" in l or "Error" in l or "sha1sum" in l][-6:]
sha = Path(f"checksum-{mod}.sha1").read_text().split()[0]
out = Path("build") / mod / mod
good = out.exists() and hashlib.sha1(out.read_bytes()).hexdigest() == sha
print(f"ninja rc={r.returncode} sha1_ok={good}")
if not good: fail(" | ".join(tail))
print("chunked and SHA1 green; yaml updated (commit config/ + src/ with git add -f)")
