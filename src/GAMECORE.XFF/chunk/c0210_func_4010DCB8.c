#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010DCB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E250);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E368);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", sendStopKeyFastLegCtrlWork);

void deleteFastLegCtrlWork(void) {
}

void setDashFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x34) = arg1;
}

void setFinalAttainWalkFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x30) = arg1;
}

void setAllowMaxSpeedFastLegCtrlWork(void *arg0, f32 fparg0)
{
    if (*(f32 *)((u8 *)arg0 + 0x7C) < fparg0) {
        *(f32 *)((u8 *)arg0 + 0x50) = fparg0;
    }
}

void setBackFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x38) = arg1;
}

void setNotFastTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x3C) = arg1;
}

void setRunStopTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x40) = arg1;
}

void setWalkStopTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x44) = arg1;
}

void setCurveCollisionFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x48) = arg1;
}

f32 getChkColWidth(void *arg0)
{
    return *(f32 *)((u8 *)arg0 + 0xCC);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", setRunStopTurnAngleFastLegCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E830);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E8B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E8F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E950);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EAE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EBD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EC20);
