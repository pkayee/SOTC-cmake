# Building with CMake

The CMake build lives next to the existing `make` build and produces the same files in the same
places (`build/`, `asm/`, `assets/`), so tools that read `build/<module>/*.elf` or `*.map` keep working.
Use one build system at a time; they share those directories.

Linux or WSL2 only: the game's compiler (`ee-gcc` 2.96) is a 32-bit Linux program.

## Quick start

```sh
scripts/bootstrap.sh                 # system packages (Debian/Ubuntu); --dry-run shows what it would do
                                     # put the game files in iso/ as described in the README
cmake --preset default               # sets up what is missing, runs splat, writes the build files
cmake --build out                    # builds every enabled module
ctest --test-dir out                 # checks each result against checksum-<module>.sha1
```

The first `cmake --preset default` takes a while: it creates `.python3`, installs `requirements.txt`,
downloads and verifies the compiler into `tools/cc/ee-gcc2.96`, and runs splat for each enabled module.
Later runs skip whatever is already done.

What it needs: CMake 3.20+, Ninja, the MIPS binutils, `cpp`, `iconv`, `sh`, Python 3 with `venv`, and the
32-bit libc (`libc6-i386`). `perl` is needed only when register rewriting is active (see
[Assembler register names](#assembler-register-names)). `scripts/bootstrap.sh` installs all of these on
Debian/Ubuntu.

## Everyday use

| Task | Command |
|---|---|
| Build one module | `cmake --build out --target loader` (or `kernel`) |
| Extract and build only some modules | `cmake --preset default -DSOTC_MODULES=loader` (a list works: `"loader;kernel"`) |
| Back to all modules | `cmake --preset default -DSOTC_MODULES=all` |
| After editing a module's YAML | just build; CMake notices and re-runs splat for that module |
| Start from scratch | `rm -rf out build asm assets` |
| Skip downloads and installs | `-DDECOMP_AUTO_SETUP=OFF` (the checks still run) |

Splat only re-runs when `config/<module>/<module>.yaml`, `configure.py`, or the module's `asm/` directory
changed or is missing, not on every CMake edit.

## Options

Pass them as `-D<NAME>=<value>` when configuring.

| Option | Default | Meaning |
|---|---|---|
| `SOTC_MODULES` | `all` | Which modules to extract and build: `all` or a list of names from the registry in `CMakeLists.txt` |
| `DECOMP_AUTO_SETUP` | `ON` | Create the venv and download the compiler when missing |
| `DECOMP_CROSS` | `mips-linux-gnu-` | Prefix of the binutils (`as`, `ld`, `objcopy`, `strip`); may be an absolute path prefix |
| `DECOMP_CC` | `tools/cc/ee-gcc2.96/bin/ee-gcc` | The game's compiler |
| `DECOMP_PYTHON` | `.python3/bin/python3` | Python with splat installed |
| `DECOMP_NUMERIC_REGS` | `AUTO` | `AUTO`, `ON` or `OFF`; see below |
| `DECOMP_EEGCC_URL` | decompme release | Where the compiler archive is downloaded from |
| `DECOMP_EEGCC_SHA256` | pinned hash | Expected hash of that archive; empty skips the check |

## How it fits together

```
configure.py --emit-cmake      writes out/<module>/objects.cmake (one decomp_object() per object)
        |
decomp_add_module()            includes it (each decomp_object() defines that object's rule), then
        |                      links with splat's <module>.ld, runs objcopy (+ tools/fix_xff.py for
        v                      the kernel) and registers the sha1 check as a test
cmake --build / ctest
```

| File | Role |
|---|---|
| `CMakeLists.txt` | Module registry, `SOTC_MODULES` selection, includes the files below |
| `cmake/Dependencies.cmake` | Venv, compiler download, tool and game-file checks |
| `cmake/Toolchain.cmake` | Assembler checks, python and patcher settings |
| `cmake/Decomp.cmake` | The rules: objects, link, objcopy, sha1 test |
| `cmake/CheckSha1.cmake` | The comparison `ctest` runs |
| `cmake/probe/eabi_registers.s` | Tiny file used to probe the assembler |
| `tools/elf_patcher_lite.py` | Same patch as `tools/elf_patcher.py`, without the `spimdisasm` import |
| `tools/regs_numeric.pl` | Rewrites `$t0`-style register names to numbers (see below) |
| `configure.py` | Gains `--emit-cmake`; its behaviour for `make` is unchanged |

The legacy `*.ninja` files are only used by `make`. The `*.ld` files are written by splat and are needed by
both builds. `configure-kernel.py` and `configure-SCPS_150.97.py` are not used by either.

## Adding a module

Source subfolders under a module need nothing: the manifest lists every object.

A new module (a new binary from the ISO) needs:

1. `config/<NAME>/<NAME>.yaml` and its symbol files, as for the existing modules.
2. A line in the registry in `CMakeLists.txt`: `<target name>:<NAME>` (`<NAME>` is also the file in `iso/`).
3. `checksum-<NAME>.sha1` containing the original file's sha1 and `build/<NAME>/<NAME>`.
4. The matching entries in `configure.py`: the target alias table, the test that decides whether the file is an
   XFF (`is_xff`), and any section handling that is specific to the loader.

## Assembler register names

The project's assembly uses names like `$t4`. GNU as development snapshots after the 2.45 release apply
n32-style register names to `-mabi=eabi`, where `$t4`-`$t7` do not exist and `$t0`-`$t3` silently mean
different registers, so such an assembler either fails or assembles the wrong code.

`DECOMP_NUMERIC_REGS=AUTO` probes the assembler once at configure time. If it behaves that way, the build pipes
each assembly file through `tools/regs_numeric.pl`, which rewrites register names to numbers (string literals
are left alone) before assembling. Numeric names mean the same on every version. With an assembler that accepts
the names (2.42 and the released 2.45 do), nothing is rewritten. `ON` always rewrites; `OFF` never does
and stops with an error if the assembler needs it. The legacy `make` build does not have this mode.

## Troubleshooting

| Symptom | Cause and fix |
|---|---|
| `ee-gcc does not run` | 32-bit libc missing: `sudo apt install libc6-i386` |
| `could not create .python3` | `sudo apt install python3-venv python3-pip` |
| `downloading the compiler failed` / hash mismatch | The release asset changed or the network failed. Check `DECOMP_EEGCC_URL`, then update `DECOMP_EEGCC_SHA256` (or pass it empty to skip the check) |
| `missing game files: iso/...` | Extract the files from your own ISO into `iso/` |
| `'...as' was not found or cannot run` | Install `binutils-mips-linux-gnu` or set `DECOMP_CROSS` |
| `Unknown module 'x'` | The name is not in the registry in `CMakeLists.txt` |
| `missing and no known rule` for an `asm/...` file | `asm/` was deleted; run `cmake --preset default` again to re-extract |
| `loader_sha1` or `kernel_sha1` fails | Compare `sha1sum iso/<file>` with `checksum-<file>.sha1`; they must be equal. If they differ you have a different game version or a bad dump. If they match, suspect the toolchain (assembler, compiler flags) |
