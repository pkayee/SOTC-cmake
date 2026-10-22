# Setup

Linux or WSL2. Everything below was run on Debian testing (binutils 2.46 system package) with the workaround in section 4; Ubuntu 24.04 (binutils 2.42, what upstream CI uses) needs no workaround.

## 1. System packages
```sh
sudo apt install gcc-mipsel-linux-gnu binutils-mips-linux-gnu ninja-build python3-pip python3-venv
```
If compiling fails with 32-bit related errors, also install `gcc-multilib`: the bundled `ee-gcc` binaries are 32-bit i386 executables and need the i386 C library (`libc6-i386`).
Optional: `p7zip-full` or `xorriso` to extract files from the disc image ([BASEROM.md](BASEROM.md)), `jq` (used by `tools/score`).

## 2. Python environment
```sh
python3 -m venv .python3
source .python3/bin/activate
python3 -m pip install -U -r requirements.txt
```
`requirements.txt` pins `splat64[mips]==0.34.0` and `spimdisasm==1.35.0`. Activate the venv in every new shell before `make`.

## 3. Compilers
```sh
scripts/setup_compiler.sh
```
Downloads two tarballs from the public [decompme/compilers](https://github.com/decompme/compilers/releases/tag/compilers) release and unpacks them to `tools/cc/`:
- `ee-gcc2.96.tar.xz` -> `tools/cc/ee-gcc2.96` (default compiler: game code, KERNEL/loader non-SDK code)
- `ee-gcc2.9-991111.tar.xz` -> `tools/cc/ee-gcc2.9-991111` (the Sony SDK libraries, selected per segment with `cc=ee-gcc2.9-991111` in the yaml, see [BUILD_FLAGS.md](BUILD_FLAGS.md))

`tools/cc/*` is git-ignored.

## 4. binutils: the 2.46 problem
Splat's assembly uses the register names `$t4`-`$t7` under `-mabi=eabi`. binutils **2.46** (current Debian) enforces n32-style names there and fails to assemble every module. binutils **2.42** works. Two fixes:
- use Ubuntu 24.04 / WSL2 Ubuntu, or
- build 2.42 locally and put it first on `PATH`:
```sh
tar xf binutils-2.42.tar.xz          # from https://ftp.gnu.org/gnu/binutils/
mkdir build && cd build
../binutils-2.42/configure --target=mips-linux-gnu --prefix=$HOME/binutils-2.42 \
    --disable-werror --disable-gdb --disable-gprofng --disable-sim --disable-libdecnumber --disable-readline
make -j"$(nproc)" && make install
export PATH=$HOME/binutils-2.42/bin:$PATH     # before every make
mips-linux-gnu-as --version | head -1          # must say 2.42
```
Do not "fix" it by changing the yaml register naming or the `-mabi` flag.

## 5. objdiff (for `tools/score`)
Install [objdiff-cli](https://github.com/encounter/objdiff/releases) (version used here: `objdiff-cli 3.8.2`) and either put it on `PATH` or `export OBJDIFF=/path/to/objdiff-cli`.

## 6. Check the toolchain
```sh
ninja --version; objdiff-cli --version; mips-linux-gnu-as --version | head -1; tools/cc/ee-gcc2.96/bin/ee-gcc --version | head -1
```
Expected: ninja 1.x, objdiff-cli 3.x, `2.42`, `2.96-ee-001003-1`.

## 7. Optional: structure recovery
Ghidra, a JDK and the REA wrapper are only needed to recover struct layouts, see [REA.md](REA.md).

Next: [BASEROM.md](BASEROM.md), then [BUILDING.md](BUILDING.md).
