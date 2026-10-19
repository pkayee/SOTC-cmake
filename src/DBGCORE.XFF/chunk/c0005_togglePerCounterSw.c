#include "common.h"

typedef struct {
    s32 v[4];
} PerCtrTbl;
extern u8 D_400198B8[];
void togglePerCounterSw();
void func_40016C20(s32 a, float b, float c, float d, float e);

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

void func_400185F0(void *a0, u8 *p)
{
    PerCtrTbl tbl = *(PerCtrTbl *)D_400198B8;

    if (*(u32 *)(p + 0x1C4) & 0x40) {
        *(u32 *)D_40018FE4 = *(u32 *)D_40018FE4 + 1;
        if (*(u32 *)D_40018FE4 > 3)
            *(u32 *)D_40018FE4 = 1;
        togglePerCounterSw();
    }
    func_40016C20(tbl.v[*(u32 *)D_40018FE4], 0.0f, 0.0f, *(float *)(p + 0x26C), *(float *)(p + 0x270));
}

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
