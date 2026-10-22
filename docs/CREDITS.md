# Credits

## Upstream and tools
- **Fantaskink/SOTC** (MIT): the project this repository forks (baseline `59b47f6`): build system, splat configuration for `SCPS_150.97` and `KERNEL.XFF`, `tools/fix_xff.py`, `tools/parse_xff_relocs.py` (thanks to joshlory), and the first matched functions. Upstream contributors: Fantaskink, johan.riedel, Mc-muffin, sir-Jayro, josh.lory, rinos9429.
- **splat** (ethteck), **spimdisasm**, **rabbitizer**: disassembly and splitting.
- **objdiff** (encounter): per-function diffing.
- **decomp-permuter** (simonlindholm) and **decomp.me**: permutation search and scratches.
- **decompme/compilers**: the `ee-gcc2.96` and `ee-gcc2.9-991111` builds that `scripts/setup_compiler.sh` downloads.
- **ninja**, GNU binutils.
- **REA** (morluto/rea, MIT), **Ghidra** (NSA) and the PS2 Emotion Engine extension for it, used for structure recovery ([REA.md](REA.md)).

## TheRealestNwah/sotc-decomp (CC0)
A separate decompilation of the NTSC-U **retail** game (`SCUS-97472`, same compiler and flags, XFF symbol names preserved), released under CC0. CC0 requires no credit; we give it anyway. It was used in two ways: (1) its one-function files were compiled with our module's exact compile command and scored against our reference objects: 703 functions scored 100% and were imported unchanged in substance (list with the path of the original file: [nwah_derived.tsv](nwah_derived.tsv)); (2) about 900 more scored 95-99% and were used as drafts for a hand match. About 98 commit messages mention it.

## AI-assisted work
**Most of the functions matched in this fork (6006 of the 6281 matched) were produced by an LLM agent swarm** (Claude models, orchestrated with Claude Code): small worker agents wrote C for one function at a time, other agents recovered struct layouts with Ghidra, and everything was accepted only by mechanical checks: objdiff 100% per function, the original SHA1 for every module, and a lint that rejects inline assembly and score-only hacks. The human owner set the rules and made the decisions on flags and compilers. Read the code as you would any decompilation: names and types of fields are best guesses unless a comment says otherwise.
