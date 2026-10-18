#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010A6A8);

void deleteBirdCtrlWork(void) {
}

void getLandMotionOffset(char *p, s128 *out)
{
    *out = *(s128 *)(p + 0xF0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", setParamBirdCtrlWork);

void setRouteAttackBirdCtrlWork(char *p)
{
    *(int *)(p + 0x30) = 1;
    *(int *)(p + 0x154) = 1;
}

void resetRouteAttackBirdCtrlWork(char *p)
{
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x154) = 0;
}

void setFlapWingBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x34) = arg1;
}

void setHoveringBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x38) = arg1;
}

void setHoverAttackBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x3C) = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AE58);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AEC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AEF8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AF60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AF80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", createFastLegCtrlWork);
