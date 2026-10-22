# Base ROM: which files and where they go

The build needs the **original** executables, which this repository does not contain. They are the source of the splat disassembly and the reference for every checksum.

## The disc
"Shadow of the Colossus preview code 8/17/05" (TCRF page: `Proto:Shadow_of_the_Colossus_(2005)/Preview_Version`). Main ELF `SCPS_150.97`, mastered by SCEA, files dated 2005-08-09/10. Its image in the project owner's collection is `SotC_Preview Version.ISO`. Retail discs (PAL `SCES-53326`, NTSC-U `SCUS-97472`) are **not supported**: addresses and code differ, every checksum would be red.

## Extract the 10 files into `iso/`
`iso/` is git-ignored. The disc root has `SCPS_150.97`, `KERNEL.XFF`, `GAMECORE.XFF`, `MANAGER.XFF` (plus `STARTUP.XFF`, not used) and a `TOOLS/` directory with the debug modules. Flatten everything into `iso/`.

With 7-Zip (`p7zip-full`):
```sh
mkdir -p iso
7z e -y -oiso "path/to/SotC_Preview Version.ISO" SCPS_150.97 KERNEL.XFF GAMECORE.XFF MANAGER.XFF 'TOOLS/*.XFF'
```
(`7z e` flattens. It also extracts `MDLTOOL.XFF`, which is unused: delete it or ignore it.)

With xorriso:
```sh
mkdir -p iso
for f in SCPS_150.97 KERNEL.XFF GAMECORE.XFF MANAGER.XFF; do xorriso -osirrox on -indev "path/to/SotC_Preview Version.ISO" -extract "/$f" "iso/$f"; done
for f in DBGCORE DBGMGR GRPTOOLS MAPTOOL PATHTOOL PRTTOOL; do xorriso -osirrox on -indev "path/to/SotC_Preview Version.ISO" -extract "/TOOLS/$f.XFF" "iso/$f.XFF"; done
```
Or mount the image (`sudo mount -o loop,ro image.iso /mnt`) and `cp` the files.

## Expected SHA1s
| file | sha1 |
|---|---|
| `SCPS_150.97` | `c4d5576d1cae3721c411a746c7845f5c6f026dbb` |
| `KERNEL.XFF` | `ac00c937b84cbe2e283a97e59e09a11886118388` |
| `GAMECORE.XFF` | `ba0ec0c7a9b426e5fc75dd0c00598321a1e1c530` |
| `MANAGER.XFF` | `63c4cd94e8510dddebfa9e484af4ba69a089e155` |
| `DBGCORE.XFF` | `c47d4f14477a8781e7eb9e72ead5f20032562411` |
| `DBGMGR.XFF` | `947f1bdf83215eb0dc60c3dd17ccfdd7ae4d98c0` |
| `GRPTOOLS.XFF` | `d04ffaa08c1f3628885bfba9b36c8803b65d1704` |
| `MAPTOOL.XFF` | `919e9991fd032046891275d43478b43848b6eb33` |
| `PATHTOOL.XFF` | `fa697109d2d1d772184cfc5958cf72fb7172254c` |
| `PRTTOOL.XFF` | `42429f9161b4b5a2876a6971b9f326ebf8a18ff7` |

These are the same values as `checksum-*.sha1` (a correct build reproduces the original files exactly). Verify the inputs before building:
```sh
cat checksum-*.sha1 | awk '{n=split($2,a,"/"); print $1"  iso/"a[n]}' | sha1sum -c
```
All ten lines must say `OK`.

## If a hash differs
You have the wrong disc, a retail disc, or a damaged extraction. Do not build: every split would be wrong. Re-extract from a verified preview image. Nothing in this repository supports retail yet.

## `expected/`
`expected/` (git-ignored) holds the reference objects for `tools/score`; it is **not** produced by `make`. Create it after a green build with `cp -r build expected`, or with `tools/make_expected` when you want to re-verify already matched functions ([MATCHING.md](MATCHING.md)).
