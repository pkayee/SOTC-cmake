# Optional: structure recovery with Ghidra and REA

Not needed to build or to match. Useful for recovering struct layouts, call graphs and global tables of the original code. **Pseudo-code is a hypothesis**: matching decides what is true.

## Tools used for this fork
- Ghidra 12.1.4 with the PS2 Emotion Engine (R5900) extension (`ghidra-emotionengine-reloaded`), Temurin JDK 21.
- [REA](https://github.com/morluto/rea) (an MCP wrapper that exposes Ghidra headlessly). The PS2 EE profile used here is two commits on top of REA; install REA with `npx rea-agents setup` and apply them if you want the same behaviour.

## Loading a module
Load the built `build/<MODULE>/<MODULE>.elf`. For the `.XFF` modules (`ET_REL`) every allocated section is `+0x10000` above the address in this repository's config and `asm/` files; the boot ELF `SCPS_150.97.elf` is not shifted. Standalone translation-unit `.o` files are not shifted either.

## Headless fallback
A Ghidra headless script that dumps pseudo-code per function works without REA (any `analyzeHeadless` + a Java/Python post-script that iterates functions with `DecompInterface`). Dump to a directory outside the repository: pseudo-code of the game must not be committed here.

## Rules of thumb
- Anything Ghidra says about a struct is a hypothesis until a function using it reaches 100%.
- Prefer layouts that explain every access in the functions you have already matched.
- Do not commit decompiler output, databases or the game files.
