# Compiler idioms that decide a match (ee-gcc 2.96 / 2.9-991111, `-O2 -G0`)

A curated list of the patterns that came up most often while matching. The examples are **generic shapes** written for this document (not code from the game); the "symptom" is what the objdiff diff looks like. The original author's C is unknown: you are looking for any C that makes this compiler emit the same bytes.

| pattern | symptom | fix (shape) |
|---|---|---|
| **GOTO-FAIL** | early `return 0;` exits make gcc set `v0=0` before the branch; temps avoid `v0` | one `goto fail;` to a single `fail: return 0;` after the success return |
| **UNION-LOAD-ALIAS** | a load is kept on one side of stores of another type (float zero stores, 128-bit `sq`) | read it through a block-local union holding both types: `union { f32 f; s32 i; } *u = (void*)p;` |
| **VOID-CALLEE-AS-INT** | a temp born right after a call sits in `v1` in the target, `v0` in yours | the callee was declared returning `int` in the original TU: declare `extern s32 callee();` |
| **IMPLICIT-INT-CALLEE / CALLEE-ARITY** | const after a call in `v1`; extra argument registers overwritten at callee entry | old-style `extern int f();` and fewer declared params |
| **EABI-ARG-ORDER** | int and float params take separate register sequences; the caller emits argument setup in declared order | change only the prototype's parameter order (ABI-identical for the callee) |
| **TU-PROTO-CHECK** | every call to a callee has the wrong argument order | the TU's prototype is wrong; fix it (e.g. floats last) |
| **EXPECT-GUARD** | loop guard `beqz` whose delay slot holds the join's first instruction | `if (__builtin_expect(x, 0)) do { ... } while (x);` with the expect on the bare int |
| **FNPTR-LOCAL-RELOAD** | call through a global function pointer, loop test uses another register | `fn = G; do { fn(); fn = G; } while (...)` |
| **RELOAD-AFTER-GLOBAL-STORE** | a field is re-read after a store to a global | that store aliases `int`: `*(s32 *)&G = v;` |
| **INLINE-AND-BOOL / NESTED-RETURN-BOOL** | boolean in a register without `sltu`; `sltiu` instead of `xori` | `static inline int f(){ if (a && b) return 1; return 0; }`; nested `if (c) return 1; return 0;` |
| **SINGLE-RETURN-LOCAL** | `lw v1` then a single exit | `if/else` assigning one local, one `return` |
| **INDEX-FORM** | `D[i*4+K]` loops vs pointer walks | write the index form the original used |
| **STRUCT-CAST-GLOBAL / HOISTED-GLOBAL-ADDR** | global fields addressed through a base register | read via a struct cast; take `&G` into a local before the loop guard |
| **RETURN-OLD-VALUE** | post-increment on a global | `r = x; x = r + 1; return r;` |
| **CHAINED-ASSIGN** | stores happen y-then-x | `a->x = a->y = 0;` stores `y` first |
| **SMALL-STRUCT COPY / STRUCT-COPY-LOOP** | `lb/sb` x3 or `ld/sd` x4 per iteration | struct assignment, in a `for` loop with a fresh loop variable |
| **FLOAT-LITERAL-ROUND** | float constant differs in the last bit | write the literal the way the original would round (`3.14159253f`) |
| **RODATA-CONST-EXTERN** | extern const reference frees load scheduling | `extern const f32 D_xxxx;` instead of a local literal |
| **BASE-LOCAL-INIT / BLOCK-LOCAL-BASE** | `s`-register order differs; `addiu` base = local | initialise the base local at its declaration, or inside the first branch |
| **DECL-INIT-SUM** | swapped `s` registers around a size sum | one initialised local per addend; pass `extra + (a + b)` |
| **SWITCH-ONE-CASE** | `move a1,a0; li a0,K` in a 1-arg compare | `switch (x) { case K: ... } return 0;` before adding an unused parameter |
| **IF-CHAIN-BNEZL** | branch-likely chain, no jump table | an `if` chain, not a `switch` |
| **NONSTATIC-INLINE-MOVES** | a non-static inline lands at the end of the TU | `static inline` helper plus an exported wrapper |
| **INLINE-PTR-PARAM** | global struct address used for stores and copied for a list op | `static inline` helper taking the struct pointer as a parameter |
| **HW-VOLATILE-REGFORM** | hardware address gives `lui/ori reg` + `0(reg)` | a `volatile` access through a pointer to the register |
| **NON-VOID FALL-OFF WRAPPER** | `sd/ld ra` + `j` | `s32 f(s32 a){ g(a, 0x80); }` (no return) |
| **SDK-CC29** | near-miss differs in `li`/`ld ra` scheduling, 16-byte callee-save slots, `j callee` sibling calls | the segment was built with ee-gcc 2.9-991111: `cc=ee-gcc2.9-991111` ([BUILD_FLAGS.md](BUILD_FLAGS.md)) |
| **NO-C-FORM** | `cfc2/ctc2/lqc2/sqc2` (VU0 macro mode), live `$ra`, COP0 | stays `INCLUDE_ASM` |
| **-fno-strict-aliasing look** | target stores are not reordered past loads/stores of other types | do not change flags; use a union/cast pattern first, or leave a near-miss stub |

General method: read the first diff (`tools/score` shows it), classify it as *register allocation*, *scheduling*, *stack frame*, *branch layout*, *rodata/constant* or *call ABI*, then try the one idiom of that class. Change one thing at a time; the compiler is deterministic.
