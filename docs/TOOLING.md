# tools/

All tools find the repo root themselves (`SOTC_ROOT` overrides). Run them from a shell with the venv active and binutils 2.42 first on `PATH`.

| tool | purpose | command | example output |
|---|---|---|---|
| `score` | objdiff one function vs `expected/` | `tools/score KERNEL.XFF sdk/scalbnf scalbnf --build` | `SCORE KERNEL.XFF/sdk/scalbnf/scalbnf 100.0%` |
| `relsort` | stably sort `SHT_REL` entries (used by `score`) | `tools/relsort in.o out.o` | (no output) |
| `jtblcheck` | prove a jump-table switch is byte-identical apart from table symbols | `tools/jtblcheck built.o expected.o fn --judge .score/fn.json` | `JTBL OK ...` |
| `lint` | rule gate: no asm, no dummy volatile, no hacks | `tools/lint --audit` | `AUDIT: 0 violations in 0 functions/blocks` |
| `modules` | module/alias list parsed from `configure.py` | `tools/modules` | `loader SCPS_150.97` ... |
| `build_queue.py` | one JSON row per function (needs a configured tree; sizes from a green build) | `tools/build_queue.py . build/functions.jsonl` | `DBGCORE.XFF: 61/86 funcs (70.9%) ...` |
| `progress.py` | progress bars / `--json` | `tools/progress.py` | `TOTAL ... 6281/9721 64.6% ...` |
| `make_expected` | rebuild `expected/` from the original bytes | `tools/make_expected` | `make_expected: 6004 functions put back to INCLUDE_ASM ...` |
| `rescore_all.py` | score every matched function a fork added | `tools/rescore_all.py -o rescore.tsv` | tsv rows `fn module file pct note` |
| `unmatch` | put a function back to `INCLUDE_ASM` | `tools/unmatch src/KERNEL.XFF/sdk/scalbnf.c scalbnf` | `unmatch: scalbnf restored to INCLUDE_ASM (N body lines removed)` |
| `nearmiss` | write/list/clear near-miss stubs | `tools/nearmiss list` | tab-separated file, function, pct, category |
| `chunk.py`, `slice_rodata.py` | split a module ([SPLITTING.md](SPLITTING.md)) | `tools/chunk.py . GAMECORE.XFF --dry` | |
| `fix_xff.py`, `parse_xff_relocs.py` | XFF container tools (build step, relocation dump) | | |
| `cc_alt.sh` | second-compiler wrapper used by the ninja `cc_alt` rule | | |
| `diff.py`, `first_diff.py`, `find_tu.py`, `findsplits.py`, `elf_patcher.py`, `test-rels.py` | upstream helpers | see file headers | |

Environment: `SOTC_ROOT` (repo root), `OBJDIFF` (path to objdiff-cli), `EXPECTED_DIR` (reference objects, default `expected/`), `SOTC_QUEUE` (queue file for `progress.py`, default `build/functions.jsonl`).

## Re-score every function a fork added (audit)
```sh
tools/build_queue.py . build/functions.jsonl && tools/make_expected
# tools/rescore_all.py -o rescore.tsv
```
`tools/rescore_all.py -o rescore.tsv` does exactly that (8 parallel jobs, about 70 s for 6006 functions) and writes `fn module file pct note` rows.

## Not included
The multi-agent swarm that produced most matches (queue, worktrees, gates, spend control) is a separate project.
