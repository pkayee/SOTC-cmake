# Near-miss stubs

A **near miss** is a C attempt that compiles but does not reach 100%. Instead of throwing it away it is parked next to the still-live `INCLUDE_ASM`, disabled:
```c
/* NEARMISS-STUB dispgpinfo */
#if 0 /* NEARMISS 89.8% cat=sched sub=- | target recomputes the out-buffer address after the call ... | attempts=1 */
void dispgpinfo(...)
{
    ...best attempt, plain C...
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", dispgpinfo);
```
The `INCLUDE_ASM` stays live, so the module remains byte-exact. The block contains no assembly (`tools/lint` scans it). At the time of writing the tree has 388 such stubs (`tools/nearmiss list`).

## Header fields
`NEARMISS <pct>% cat=<category> sub=<tag or -> | <cause, one line> | attempts=<n>`. Categories: `regalloc` `sched` `stack-frame` `struct-layout` `branch-layout` `rodata-const` `call-abi` `inline-unroll` `cse-hoist` `bitops` `float-ops` `volatile-alias` `linker-pad` `sdk-compiler` `vu0-mmi` `no-c-form` `uncategorized`.

## Resuming one
1. `tools/nearmiss list` (tab separated: file, function, pct, category). Start with the highest percentage in a category whose pattern you know ([PATTERNS.md](PATTERNS.md)).
2. Copy the `#if 0` body into a scratch `.c`, remove the stub (`tools/nearmiss clear src/... fn`), put the C above the `INCLUDE_ASM` (comment it out) and iterate with `tools/score ... --build`.
3. At 100% + green checksums keep it; otherwise write the stub back:
```sh
tools/nearmiss stub src/GAMECORE.XFF/chunk/c0004_DebugControl.c dispgpinfo attempt.c --pct 91.2 --cat sched --cause "delay slot differs"
```
`attempt.c` must contain exactly one function (plus at most two helpers), no `#include`, no `INCLUDE_ASM`, no asm.
