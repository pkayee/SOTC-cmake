#include "common.h"

void deleteHorseCtrlWork(void) {
}

void setDashHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x34)) = arg1;
}

void setWallStopHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x38)) = arg1;
}

void setLimitModeHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x44)) = arg1;
}

void setFinalAttainWalkHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x30)) = arg1;
}

void setAllowMaxSpeedHorseCtrlWork(void *arg0, float fparg0)
{
    if (*(*(float **)((char *)(arg0) + 0x78)) < fparg0) {
        (*(float *)((char *)(arg0) + 0x40)) = fparg0;
    }
}

void setFreezeHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x3C)) = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111B78);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111BC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111C08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111D98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111DC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", updateHumanCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40112278);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40112670);
