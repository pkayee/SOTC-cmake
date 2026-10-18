#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", func_40118EB8);

void deleteWormCtrlWork(void) {
}

int setAttainSpeedWormCtrlWork(void *arg0, float fparg0)
{
    if ((fparg0 >= 0.0f) && (fparg0 <= (*(float *)((char *)(arg0) + 0x58)))) {
        (*(float *)((char *)(arg0) + 0xC0)) = fparg0;
        return 1;
    }
    return 0;
}

void setAttackParamWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0xC8)) = fparg0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", setOffsetParamWormCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", setLimitTurnWormCtrlWork);

void setRotColCheckWormCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0xE0)) = arg1;
}

void setFallGravCoffWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x90)) = fparg0;
}

void setMaxFallSpeedWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x94)) = fparg0;
}

void setGroundFrictionCoffWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x98)) = fparg0;
}

void setUnderFrictionCoffWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x9C)) = fparg0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", setWorldPitchLimitWormCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", resetVelocityWormCtrlWork);

void setAcceleParamWormCtrlWork(char *p, float f1, float f2)
{
    *(float *)(p + 0x5C) = f1;
    *(float *)(p + 0x60) = f2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", func_401191D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", func_40119260);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", func_40119290);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", func_401192E8);

extern s32 DldSysUndefSymbol;
extern char *getSCRDataCtrlWork(void *);

void createAngryWork(void *a, int *h)
{
    int *w = (int *)(getSCRDataCtrlWork(a) + 0x40D4);
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;
    int g = (t != 0 && t != (int *)DldSysUndefSymbol) ? t[4] : 0;
    w[0] = g;
    w[1] = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", updateAngryWork);

int SCRConditionOverAngryValue(void *actor, float fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!(fparg0 <= (*(float *)((char *)(getSCRDataCtrlWork(actor)) + 0x40D8)))) {
        var_v0 = 0;
    }
    return var_v0;
}

int SCRConditionLessAngryValue(void *actor, float fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!((*(float *)((char *)(getSCRDataCtrlWork(actor)) + 0x40D8)) <= fparg0)) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", updateArrowThrustWork);

void createArrowThrustWork(int a, int *w, int b)
{
    w[1] = 0;
    w[0] = b;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", updateAttackWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", updateAttackWork2);
