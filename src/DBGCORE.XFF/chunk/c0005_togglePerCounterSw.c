#include "common.h"

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", togglePerCounterSw);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getPerCounterSw);

extern u8 D_40018FE4[];

void *getPerCounterSw(void)
{
    return &D_40018FE4;
}

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getPerCounterSize);

extern u8 D_40018FE0[];

void *getPerCounterSize(void)
{
    return &D_40018FE0;
}

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getPeakGraphMode);

extern u8 D_40018FF4[];

void *getPeakGraphMode(void)
{
    return &D_40018FF4;
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", func_400185F0);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", dispStageAdminStatus);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", func_40018878);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getAreaAdministrationDispSw);

extern u8 D_4001928C[];

void *getAreaAdministrationDispSw(void)
{
    return &D_4001928C;
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getModelPerson);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getModelStatus);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getCollisionPerson);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", getCollisionStatus);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0005_togglePerCounterSw", createStageAdminMenu);

extern s32 DldSysUndefSymbol;
extern int D_400193D8[];
extern u8 SH_StageAdminDefSTAGEADMIN_NICOWORLD[];
extern void createParamMenu(void *, int);

void createStageAdminMenu(void)
{
    if (D_400193D8[12] == 0 && DldSysUndefSymbol != (s32)SH_StageAdminDefSTAGEADMIN_NICOWORLD && (s32)SH_StageAdminDefSTAGEADMIN_NICOWORLD != 0)
        createParamMenu(D_400193D8, 0);
}
