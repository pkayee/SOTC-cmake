#!/usr/bin/env python3
"""Build queue/functions.jsonl from a configured decomp checkout.

Walks asm/<module>/ (after `./configure.py`) and records every function splat emitted:
- functions in asm/<module>/nonmatchings/<file>/<func>.s  -> live in a `c` split, directly
  matchable (replace INCLUDE_ASM in src/<module>/<file>.c)
- functions in whole-file asm/<module>/<file>.s           -> the segment is still `asm` in
  the yaml; a Sonnet must flip it to `c` and re-run configure before Haikus can work it
  (needs_c_split = true)
Functions already defined in src/ are recorded as matched.

Usage: build_queue.py <decomp dir> <out jsonl>   (merge-preserves status/owner/attempts/best_pct)
"""
import json, re, sys
from pathlib import Path

decomp = Path(sys.argv[1]); out = Path(sys.argv[2])
asm_root = decomp / "asm"; src_root = decomp / "src"
INSTR = re.compile(r"^\s*/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) [0-9A-Fa-f]{8} \*/")
# a definition starts at column 0, is not `extern`, and the line has no ';' (prototypes do)
CDEF = re.compile(r"^(?!extern\b|typedef\b|INCLUDE_ASM)[A-Za-z_][\w \*]* \**([A-Za-z_]\w*)\s*\([^;\n]*$", re.M)
# `static` definitions (inline helpers) have no symbol in the binary: never queue rows for them (v3.10 phantom-row fix)
STATIC_DEF = re.compile(r"^static\b")
SYM = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", re.M)

def elf_sizes(mod):
    """name -> size from the linked ELF (needs a green build); {} if unavailable"""
    import subprocess, shutil
    elf = decomp / "build" / mod / f"{mod}.elf"
    nm = shutil.which("mips-linux-gnu-nm")
    if not elf.exists() or not nm: return {}
    out = subprocess.run([nm, "-S", "--defined-only", str(elf)], capture_output=True, text=True).stdout
    sizes = {}
    for ln in out.splitlines():
        p = ln.split()
        if len(p) == 4 and p[2] in "tT": sizes[p[3]] = int(p[1], 16)
    return sizes

prev = {}
if out.exists():
    for line in out.read_text().splitlines():
        if line.strip():
            d = json.loads(line); prev[d["id"]] = d

ACTIVE_ASM = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*([A-Za-z_]\w*)\)', re.M)   # not commented out
matched = {}   # module -> {name: file_rel}
for mod_dir in sorted(p for p in src_root.iterdir() if p.is_dir()):
    names, still_asm = {}, set()
    for c in mod_dir.rglob("*.c"):
        text = c.read_text(errors="replace")
        still_asm.update(ACTIVE_ASM.findall(text))
        for n in CDEF.findall(text):
            names[n] = str(c.relative_to(mod_dir).with_suffix(""))
    # a C body that coexists with a live INCLUDE_ASM for the same name is a NON_MATCHING draft
    matched[mod_dir.name] = {n: f for n, f in names.items() if n not in still_asm}

def symbol_addrs(mod):
    addrs = {}
    for f in (decomp / "config" / mod).glob("*symbols*.txt"):
        for n, a in SYM.findall(f.read_text(errors="replace")): addrs[n] = a.upper().replace("0X", "0x")
    return addrs

def functions_in(s_file):
    """yield (name, addr, n_instr) for each glabel block in a .s file"""
    name = addr = None; n = 0
    for line in s_file.read_text(errors="replace").splitlines():
        if line.startswith("glabel "):
            if name: yield name, addr, n
            name = line.split()[1]; addr = None; n = 0
        else:
            m = INSTR.match(line)
            if m and name:
                n += 1
                if addr is None: addr = "0x" + m.group(1).upper()
    if name: yield name, addr, n

rows = []
for mod_dir in sorted(p for p in asm_root.iterdir() if p.is_dir()):
    mod = mod_dir.name
    sizes = elf_sizes(mod); addrs = symbol_addrs(mod); seen = set()
    # functions already decompiled: not in asm/, so add them from src/ (+ ELF sizes)
    for name, file_rel in matched.get(mod, {}).items():
        seen.add(name)
        if addrs.get(name) is None and not sizes.get(name): continue   # a C function with no symbol and no size = static inline helper, not a target
        fid = f"{mod}/{file_rel}/{name}"
        rows.append({"id": fid, "module": mod, "file": file_rel, "name": name, "addr": addrs.get(name),
                     "size": sizes.get(name, 0), "needs_c_split": False, "status": "matched",
                     "owner": None, "attempts": 0, "best_pct": 100, "difficulty": 0, "hints": []})
    for s in sorted(mod_dir.rglob("*.s")):
        rel = s.relative_to(mod_dir)
        if rel.parts[0] == "data": continue
        in_c_split = rel.parts[0] == "nonmatchings"
        file_rel = str(Path(*rel.parts[1:-1])) if in_c_split else str(rel.with_suffix(""))
        for name, addr, n in functions_in(s):
            if name in seen: continue
            seen.add(name)
            fid = f"{mod}/{file_rel}/{name}"
            size = n * 4
            diff = 1 if size <= 64 else 2 if size <= 256 else 3 if size <= 1024 else 4
            row = {"id": fid, "module": mod, "file": file_rel, "name": name, "addr": addr,
                   "size": size, "needs_c_split": not in_c_split, "status": "todo",
                   "owner": None, "attempts": 0, "best_pct": 0, "difficulty": diff, "hints": []}
            if fid in prev:
                p = prev[fid]
                # matched is derived from src/ each run; everything else is librarian state
                if p.get("status") in ("in_progress", "blocked", "todo", "skip"): row["status"] = p["status"]
                for k in ("owner", "attempts", "best_pct", "hints"): row[k] = p.get(k, row[k])
            rows.append(row)

rows.sort(key=lambda r: (r["status"] == "matched", r["needs_c_split"], r["size"], r["id"]))
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text("".join(json.dumps(r) + "\n" for r in rows))

by_mod = {}
for r in rows:
    m = by_mod.setdefault(r["module"], {"total": 0, "matched": 0, "bytes": 0, "matched_bytes": 0})
    m["total"] += 1; m["bytes"] += r["size"]
    if r["status"] == "matched": m["matched"] += 1; m["matched_bytes"] += r["size"]
for m, v in by_mod.items():
    print(f"{m}: {v['matched']}/{v['total']} funcs ({100*v['matched']/max(v['total'],1):.1f}%), "
          f"{v['matched_bytes']}/{v['bytes']} bytes ({100*v['matched_bytes']/max(v['bytes'],1):.1f}%)")
