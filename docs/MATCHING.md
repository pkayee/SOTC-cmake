# Matching a function

A function is **matched** when real C compiled with the module's compiler reproduces the original bytes: objdiff 100% for the function **and** the module SHA1 still equals the original (`make` + `sha1sum -c`). Anything else stays `INCLUDE_ASM`.

## Workflow for one function
1. Find a target. `tools/build_queue.py . build/functions.jsonl` writes one JSON row per function (module, file, name, size, `status` = matched / blocked / todo). Look for small `todo` rows.
2. Open the C file (`src/<MODULE>/<file>.c`; chunked modules: `src/<MODULE>/chunk/cNNNN_<name>.c`). The function is an `INCLUDE_ASM("asm/<MODULE>/nonmatchings/<file>", name);` line. The original assembly is that `.s` file (created by `make`).
3. Write C above the line, comment the `INCLUDE_ASM` out (`//INCLUDE_ASM(...)`, upstream style: "replace the `INCLUDE_ASM` line with the reversed C").
4. Make sure `expected/` exists: after a green `make`, `cp -r build expected`.
5. Score: `tools/score <MODULE> <file-rel> <function> --build` (e.g. `tools/score KERNEL.XFF sdk/scalbnf scalbnf --build`). It recompiles only that translation unit and prints `SCORE <module>/<file>/<fn> NN.N%` plus the differing instructions; the full diff is in `.score/<fn>.json`. Never hand-run a compiler.
6. Iterate until 100.0%. [PATTERNS.md](PATTERNS.md) lists what usually decides a mismatch. [decomp.me](https://decomp.me) works too (preset: `Shadow of the Colossus`; `permuter_settings.toml` and `tools/decomp-permuter` for permutation search: `git submodule update --init tools/decomp-permuter`).
7. `make && for f in checksum-*.sha1; do sha1sum -c $f; done` must stay green. Then `tools/lint --worktree` (no rule violations).
8. Not reaching 100? Leave the `INCLUDE_ASM` live and, optionally, park the best attempt as a disabled stub ([NEAR_MISSES.md](NEAR_MISSES.md)).

## House rules
1. **No assembly in C.** Not one instruction, no register-pinned variables (`register T x asm("v1")`), no file-level `asm()`, no pasted `.s`. If a function has no C form (live `$ra` reads, VU0/MMI vector code, COP0 access) it stays `INCLUDE_ASM`; that is a correct outcome. `tools/lint` rejects asm; only the two upstream spin loops in `tools/asm_allow.txt` are exempt.
2. **100% or commented out.** Live C exists only at exactly 100% with every module checksum green.
3. **No hacks:** no `NON_MATCHING`, no `#pragma`, no changing optimisation flags to make one function match. Per-segment flags only with module-wide evidence ([BUILD_FLAGS.md](BUILD_FLAGS.md)).
4. **`volatile`** only for memory-mapped hardware registers and for words shared with interrupts or other threads (through casts, pointers-to-volatile, externs, parameters, globals). Dummy volatile locals used as scheduling/padding hacks (`volatile s32 unused;`) are rejected by `tools/lint` (rule F).
5. **Compiler is per segment.** Sony SDK segments (loader `sdk/libkernl|libgraph|libdma|libnet|libpad2|libvib|libcdvd`, KERNEL `sdk/sce*`) build with `ee-gcc2.9-991111`; everything else `ee-gcc2.96`. gcc 2.9 has no `va_arg`: real users stay `INCLUDE_ASM`.
6. **Alignment:** a function at a non-8-aligned address, or whose neighbour's partial match changes references, stays `INCLUDE_ASM`. The last function of a C segment with size 4 mod 8 may only be C if all checksums hold. Never pad with asm.
7. Never edit `asm/`, `expected/`, yaml or `configure*` as part of matching a function (splitting is a separate, checksum-gated step: [SPLITTING.md](SPLITTING.md)).
8. `__builtin_next_arg` (the SDK's `va_start`) is a compiler builtin, not assembly, and is allowed (used in `sdk/libkernl/kprintf2.c` and `thread.c`).
9. Style: [CONTRIBUTING.md](CONTRIBUTING.md) (Allman braces, 4 spaces, `u8/s32/...` types).

## Re-verifying matched functions
`expected/` normally follows your last green build, so matched functions score against themselves. To audit what is already matched against the original bytes, run `tools/make_expected` (puts every function added since the upstream baseline back to `INCLUDE_ASM` in a scratch copy, builds it, installs the objects as `expected/`), then score the functions (loop in [TOOLING.md](TOOLING.md)). Result for this tree: 5981 of 6006 fork-added functions score 100.0; 23 score 98.0-99.95 solely because of relocation-symbol-name differences (`[.rodata]`/`[.text]` vs a named blob symbol; module SHA1 is green), 2 are `static inline` with no symbol.
