#include "common.h"

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_400122A0);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getTimeScale);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", setTimeScale);
extern s32 D_40018F54;
void ChangeGameTimeScale();

void setTimeScale(void)
{
    ChangeGameTimeScale(D_40018F54);
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getCpuForceWeight);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getDispTimer);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getAreaBoundaryDispSw);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getAreaBoundaryDispPolySw);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_400127D8);
extern void seamlessstage_mallocerrorfunc(void);
extern void objectmanager_mallocerrorfunc(void);

void func_400127D8(void)
{
    seamlessstage_mallocerrorfunc();
    objectmanager_mallocerrorfunc();
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", initgcdebug);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", openLogFile);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", addLogFile);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", closeLogFile);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getLogSw);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40012B48);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getDate);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", getTime);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40012D28);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40012FF8);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40013570);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40013A28);
