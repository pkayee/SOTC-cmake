#include "common.h"

s32 LoaderSysCheckCDBootMode();

s32 isT10000(void)
{
    return LoaderSysCheckCDBootMode() == 0;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_400129D8);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012A48);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012AF0);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012C10);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012C28);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012C90);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_40012DC8);

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
