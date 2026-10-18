#include "common.h"

s32 LoaderSysCheckCDBootMode();

/* DBGMGR c0002: 100 in scratch; `s32 i = 0;` at decl + p=buf INSIDE the if gives the target delay-slot order (i=0 after if: 99.2) */
extern char *iosMallocAlign();

s32 isT10000(void)
{
    return LoaderSysCheckCDBootMode() == 0;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_400129D8);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012A48);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012AF0);

/* DBGMGR c0002: 100 in scratch; obj is s32 (a pointer-typed obj lets gcc CSE the second 0x3e0 load: 78.6) */
void func_40012C10(void *a0, s32 obj)
{
    *(s32 *)(*(s32 *)(obj + 0x3e0) + 0x24) = 0;
    *(s32 *)(*(s32 *)(obj + 0x3e0) + 0x28) = 0;
}

char *func_40012C28(void *a0, s32 obj)
{
    s32 t = *(s32 *)(obj + 0x3e0);
    char *buf = iosMallocAlign(a0, *(s32 *)(t + 0x20) << 8, 4);
    char *p;
    s32 i = 0;
    
    if (0 < *(s32 *)(t + 0x20)) {
        p = buf;
        do {
            *p = 0;
            i++;
            p += 0x100;
        } while (i < *(s32 *)(t + 0x20));
    }
    return buf;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012C90);

void func_40012DC8(void *a0, char *obj)
{
    *(s32 *)(*(char **)(obj + 0x3e0) + 0x2c) = 0;
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", OffsetOverWriter);
extern void *iosDlGetCreateAdrs();
extern int func_40011960(void *, void *, void *);

int OffsetOverWriter(void *a0, void *a1)
{
    return func_40011960(iosDlGetCreateAdrs(), a0, a1);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", initdebugmanager);
extern char D_4001E7F8[];
s32 LoaderSysPrintf();

s32 initdebugmanager(void)
{
    LoaderSysPrintf(D_4001E7F8);
    return 0;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", glPivotKun);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", _gluCylinder);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", gluCylinderLine);
