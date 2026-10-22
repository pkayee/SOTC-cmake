# Building

```sh
source .python3/bin/activate        # and binutils 2.42 on PATH, see SETUP.md
make                                # all 10 modules
for f in checksum-*.sha1; do sha1sum -c $f; done
```
A clean full build takes about 25 s on 8 cores (the last run: `make` from scratch, 23 s). Every module's last ninja step is `sha1sum checksum-<MODULE>.sha1`, so a red module shows at the end of its build.

Expect a few linker warnings of the form `mips-linux-gnu-ld: ... can't find matching LO16 reloc against 'D_xxxx' for R_MIPS_HI16`: they are harmless here (a `%hi` whose `%lo` partner lives in another instruction group); the checksums are the judge.

## Targets
`make` = `make all`. One module: `make <alias>`.
| alias | module | what it is |
|---|---|---|
| `loader` | `SCPS_150.97` | boot ELF (`ET_EXEC`): loader, Sony SDK libraries |
| `kernel` | `KERNEL.XFF` | resident kernel: `ios/*` (OS layer), `Sg2/*` (sound), SDK libs |
| `gamecore` | `GAMECORE.XFF` | game logic overlay |
| `manager` | `MANAGER.XFF` | object / effect manager overlay |
| `dbgcore` | `DBGCORE.XFF` | debug tool (`TOOLS/`) |
| `dbgmgr` | `DBGMGR.XFF` | debug tool |
| `grptools` | `GRPTOOLS.XFF` | debug tool |
| `maptool` | `MAPTOOL.XFF` | debug tool |
| `pathtool` | `PATHTOOL.XFF` | debug tool |
| `prttool` | `PRTTOOL.XFF` | debug tool |
`make clean` removes `asm/`, `assets/`, `build/` and the `*.ninja` files (the next `make` re-splits everything).

## One target per configure
`make` runs `./configure.py -c -t <alias>` **once per module, each in its own process**. Never run a bare `./configure.py -c` (all targets in one process): loader symbols leak into `KERNEL.XFF` and its checksum goes red. If you configure by hand: `rm config/<MODULE>/*_auto.txt; ./configure.py -c -t <alias>`.

## What `configure.py` does
1. Runs [splat](https://github.com/ethteck/splat) per module from `config/<MODULE>/<MODULE>.yaml`: splits the original file into `asm/<MODULE>/` (function `.s` files, `nonmatchings/` for functions still in C files), `asm/<MODULE>/data/` and `assets/`.
2. Writes `<MODULE>.ninja` and the linker script `<MODULE>.ld`.
3. Branch workaround: for a branch whose target is not a local `.L` label in the same `.s` file (splat's false function starts, or labels in another function's file) the branch is emitted as a raw `.word`, so the assembler cannot mis-encode it.
4. Per-segment compiler: a segment option string may contain `cc=<dir under tools/cc>` (ninja rule `cc_alt`, via `tools/cc_alt.sh`); default is `ee-gcc2.96`. See [BUILD_FLAGS.md](BUILD_FLAGS.md).
5. Generated `config/<MODULE>/*_auto.txt` files (`undefined_syms_auto.txt`, `undefined_funcs_auto.txt`) are git-ignored; they are deleted before each configure.

## Build layout
`build/<MODULE>/asm/...` and `build/<MODULE>/src/...` hold the `.o` files; `build/<MODULE>/<MODULE>.elf` and `.map` are the link result; the final `build/<MODULE>/<MODULE>` (the XFF file) is produced by `objcopy -O binary` of the ELF followed by `tools/fix_xff.py` (restores the relocated operand words; see [MODULES.md](MODULES.md)). The checksum file names that file.

## The check loop (use it after every change)
```sh
make && for f in checksum-*.sha1; do sha1sum -c $f; done
```
Ten `OK` lines or you are not done.

## CI
`.github/workflows/build.yml` (upstream) builds loader and kernel from files fetched from secret URLs. It does not cover the other 8 modules; extending it is the repository owner's decision. Never commit the game files.
