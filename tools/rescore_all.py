#!/usr/bin/env python3
"""rescore_all.py [--baseline REF] [--jobs N] [-o out.tsv] — score every matched function added since REF (default 59b47f6).

Needs: a green `make`, `tools/build_queue.py . build/functions.jsonl`, and an original-bytes `expected/` (`tools/make_expected`).
Writes `fn module file pct note` rows; rows below 100 or without a symbol (static inline) are worth reading."""
import argparse, json, os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(os.environ.get("SOTC_ROOT", Path(__file__).resolve().parents[1]))
CDEF = re.compile(r"^\+(?!extern\b|typedef\b|INCLUDE_ASM|\+)[A-Za-z_][\w \*]* \**([A-Za-z_]\w*)\s*\([^;]*$")
ap = argparse.ArgumentParser(description=__doc__); ap.add_argument("--baseline", default="59b47f6"); ap.add_argument("--jobs", type=int, default=8)
ap.add_argument("-o", default="rescore.tsv"); o = ap.parse_args()
diff = subprocess.run(["git", "-C", str(ROOT), "diff", "-U0", o.baseline, "HEAD", "--", "src"], capture_output=True, text=True, check=True).stdout
added = {m.group(1) for m in map(CDEF.match, diff.splitlines()) if m}
rows = [json.loads(l) for l in (ROOT / "build/functions.jsonl").read_text().splitlines() if l.strip()]
todo = [r for r in rows if r["status"] == "matched" and r["name"] in added]
print(f"{len(todo)} functions to score", file=sys.stderr)
def run(r):
    try: p = subprocess.run([str(ROOT / "tools/score"), r["module"], r["file"], r["name"]], capture_output=True, text=True, timeout=120)
    except subprocess.TimeoutExpired: return r, "TIMEOUT", ""
    m = re.search(r"SCORE \S+ ([\d.]+)%(.*)", p.stdout)
    return (r, m.group(1), m.group(2).strip()) if m else (r, "NOSCORE", (p.stderr or p.stdout).strip()[:80].replace("\t", " "))
with ThreadPoolExecutor(o.jobs) as ex, open(o.o, "w") as f:
    f.write("fn\tmodule\tfile\tpct\tnote\n")
    for r, pct, note in ex.map(run, todo): f.write(f"{r['name']}\t{r['module']}\t{r['file']}\t{pct}\t{note}\n")
