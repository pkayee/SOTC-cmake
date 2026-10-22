# Shadow of the Colossus Decompilation Project

A matching decompilation of the **Shadow of the Colossus Preview Version** (disc product code `SCPS_150.97`, files dated 2005-08-10), targeting the PS2 Emotion Engine with the original compilers (`ee-gcc2.96`, and `ee-gcc2.9-991111` for the Sony SDK libraries).

This repository is a fork of [Fantaskink/SOTC](https://github.com/Fantaskink/SOTC) (MIT). Upstream covered the boot ELF `SCPS_150.97` and `KERNEL.XFF`. This fork configures and builds **all 10 modules** of the disc and checks every one of them byte-for-byte against the original file.

> **Most of the matches in this fork were produced by an LLM agent swarm** and verified mechanically (objdiff per function, SHA1 per module, lint against inline assembly). See [docs/CREDITS.md](docs/CREDITS.md) and [docs/MATCHING.md](docs/MATCHING.md).

## Status
All 10 modules build and every module's SHA1 equals the original file's SHA1 (`sha1sum -c checksum-*.sha1`). Functions that are not yet C stay as `INCLUDE_ASM`, so the build is always byte-exact.

| module | functions | matched | of which this fork | upstream baseline | bytes matched |
|---|---:|---:|---:|---:|---:|
| SCPS_150.97 | 1047 | 676 (64.6%) | 553 | 123 | 53.8% |
| GAMECORE.XFF | 3734 | 2430 (65.1%) | 2430 | 0 | 17.0% |
| GRPTOOLS.XFF | 153 | 134 (87.6%) | 134 | 0 | 37.6% |
| KERNEL.XFF | 1109 | 793 (71.5%) | 641 | 152 | 46.5% |
| MANAGER.XFF | 3027 | 1770 (58.5%) | 1770 | 0 | 16.1% |
| DBGMGR.XFF | 132 | 64 (48.5%) | 64 | 0 | 18.5% |
| PRTTOOL.XFF | 287 | 258 (89.9%) | 258 | 0 | 51.9% |
| PATHTOOL.XFF | 118 | 78 (66.1%) | 78 | 0 | 26.5% |
| DBGCORE.XFF | 86 | 61 (70.9%) | 61 | 0 | 17.5% |
| MAPTOOL.XFF | 28 | 17 (60.7%) | 17 | 0 | 15.5% |
| **total** | 9721 | 6281 (64.6%) | 6006 | 275 | 22.4% |


*Generated with `tools/build_queue.py . build/functions.jsonl && tools/progress.py --json` (after a green `make`). "upstream baseline" is what Fantaskink/SOTC had at commit `59b47f6`.* Function counts come from splat's function boundaries; bytes matched is the share of `.text` bytes covered by matched functions.

## Legal notice
This repository contains **no game data**: no disc image, no executables, no assembly of the game, no extracted assets. You need your own copy of the disc. See [docs/BASEROM.md](docs/BASEROM.md).

## Quick start (Linux / WSL2)
```sh
sudo apt install gcc-mipsel-linux-gnu binutils-mips-linux-gnu ninja-build python3-pip python3-venv
python3 -m venv .python3 && source .python3/bin/activate && python3 -m pip install -U -r requirements.txt
scripts/setup_compiler.sh                 # downloads ee-gcc2.96 and ee-gcc2.9-991111 into tools/cc/
# put the 10 original files into iso/ (docs/BASEROM.md), then:
make                                      # configure + build all 10 modules, SHA1-checked
```
Debian testing / binutils 2.46 needs a workaround, see [docs/SETUP.md](docs/SETUP.md).

## Documentation
| document | what is in it |
|---|---|
| [docs/SETUP.md](docs/SETUP.md) | system packages, Python venv, compilers, binutils pitfall, objdiff |
| [docs/BASEROM.md](docs/BASEROM.md) | which disc, how to extract the 10 files, their SHA1s |
| [docs/BUILDING.md](docs/BUILDING.md) | `make`, the 10 targets, what `configure.py` does, the checksum loop |
| [docs/MODULES.md](docs/MODULES.md) | the XFF module format, sizes, config files, chunks |
| [docs/MATCHING.md](docs/MATCHING.md) | how to match one function, house rules, scoring |
| [docs/PATTERNS.md](docs/PATTERNS.md) | compiler idioms that decide a match |
| [docs/SPLITTING.md](docs/SPLITTING.md) | how to split a new file / chunk a module |
| [docs/TOOLING.md](docs/TOOLING.md) | `tools/` reference |
| [docs/NEAR_MISSES.md](docs/NEAR_MISSES.md) | the disabled `#if 0` near-miss stubs |
| [docs/BUILD_FLAGS.md](docs/BUILD_FLAGS.md) | per-segment compiler and flag choices with evidence |
| [docs/REA.md](docs/REA.md) | optional structure recovery with Ghidra |
| [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md) | code style (upstream) and workflow |
| [docs/CREDITS.md](docs/CREDITS.md) | upstream, tools, and the AI-assisted nature of this work |

## Contributing
Read [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md) and [docs/MATCHING.md](docs/MATCHING.md). Upstream chat: <https://discord.gg/WGSnPQFtHU>.

## License
MIT, see `LICENSE` (Copyright 2024 FantaSkink, plus the contributors of this fork).
