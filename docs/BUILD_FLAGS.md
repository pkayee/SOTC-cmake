# Build flags and compilers per segment

Default for all game code: `ee-gcc2.96` (`2.96-ee-001003-1`) with `-O2 -G0 -g2` and the include paths in `permuter_settings.toml`. Any deviation lives in the yaml option string of **one segment** and must carry module-wide evidence: every already-matched function in the affected segments compiles to identical bytes with and without the flag, the change is checksum-gated (all 10 SHA1 green) and lands as its own revertable commit. A flag that only exists to make one function reach 100% is not allowed.

## Summary (counts of yaml segment lines, `config/<MODULE>/<MODULE>.yaml`)
| class | where | count | status |
|---|---|---:|---|
| `-O3` | loader `loaderSys`, `loaderSys2`, `loaderSysFileIO`, `loaderSys3`, `putString` | 5 | **upstream's own** setting at baseline `59b47f6` |
| `cc=ee-gcc2.9-991111` | loader SDK segments (libkernl, libgraph, libdma, libnet, libpad2, libvib, libcdvd, ...) | 53 | evidence below |
| `cc=ee-gcc2.9-991111` | KERNEL `sdk/sce*` | 8 | evidence below |
| `cc=ee-gcc2.9-991111` | MANAGER libmpeg chunks (`c0208b` .. `c0216`) | 9 | evidence below |
| `-fno-strict-aliasing` | KERNEL `ios/*` | 40 | evidence below |
| `-fno-strict-aliasing` | loader `sdk/libgcc/__main` | 1 | evidence below |
| `-fno-builtin` | KERNEL libm segments (`sdk/*f`: `fabsf`, `scalbnf`, ...) | 24 | evidence below |

## `cc=ee-gcc2.9-991111` (Sony SDK libraries)
The SDK libraries were built with an older, different compiler. A survey of SDK functions across five compilers (ee-gcc 2.96, 2.9-991111, 2.9-990721, 3.2-040921, 2.95.2 under wine) found that **2.9-991111** reproduces the SDK's 16-byte callee-save slots, `j callee` sibling calls, `mult` by a register-held constant and the short-loop nops: sample functions (`Exit`, `func_00110218`, `SetT2_COMP`, `sceSifInitRebootNotify`, `sceGsPutDispEnv`, ...) had 3-33 differing instructions under ee-gcc 2.96 and 0 under 2.9-991111; 2.9-990721 matches the same except the loop-nop case; 3.2 and 2.95.2 were worse. Switching 34 loader/KERNEL segments to it left both original module SHA1s unchanged, i.e. every already-matched function in them still compiled exactly. The compiler comes from the same public `decompme/compilers` release as 2.96 (`scripts/setup_compiler.sh`). Its driver lacks the specs macros of `regnames.specs` and does not search `bin/../lib`, hence the `cc_alt` ninja rule / `tools/cc_alt.sh` (cc1 -S, cpp, as). gcc 2.9 has no `va_arg` (shims in `include/cc29/`). Mixed segments (game code followed by libmpeg in MANAGER) are split at the boundary (`c0208_srand` / `c0208b_func_400FF4E8`).

## `-fno-strict-aliasing`
- **KERNEL `ios/*`** (40 segments): the OS layer was built with aliasing assumptions off. Evidence: all matched `ios/*` functions compile identically with and without the flag; several near-misses reach 100% only with it; `Sg2/*` (sound) in the same module does **not** need it and is untouched. Approved and merged as one yaml commit (`650c84b`; checksum-gated).
- **loader `sdk/libgcc/__main`** (1 segment): `__do_global_dtors` is identical with the flag on this segment (the other libgcc2/fp-bit/frame translation units break with it, so it is applied to `__main` alone); `__do_global_ctors`, `__main` and `__do_global_dtors` re-scored 100%, no other segment changed, all checksums green (`fb20fbd`, revert that commit to undo both the flag and `dtors`).
- **MANAGER**: some functions behave as if the original build also used `-fno-strict-aliasing` (stores not reordered past loads of other types). **No flag was applied**: MANAGER has no such segment; the question was never granted and is closed. Those functions stay near-miss stubs.

## `-fno-builtin` (KERNEL libm)
The original calls a real `fabsf` (`jal fabsf`) where ee-gcc 2.96 inlines `abs.s`; newlib's libm is normally built with `-fno-builtin`. 24 libm segments carry the flag (commit `bd86a78`). Evidence: the 16 previously matched functions in those segments stayed 100%, all 35 SDK objects' sections and relocations identical with and without, both SHA1 green, and `__ieee754_rem_pio2f` / `__ieee754_atan2f` reached 100% with a plain `fabsf` call.

## Not flags, but worth knowing
- `__builtin_next_arg(...)` in `sdk/libkernl/kprintf2.c` and `thread.c` is the SDK's `va_start` expansion: a compiler builtin, not inline assembly.
- Review checklist for new flags: (1) name the segment(s); (2) list the already-matched functions in them and show they are unchanged; (3) show the near-misses that now match; (4) full `make` + 10 checksums; (5) separate commit.
