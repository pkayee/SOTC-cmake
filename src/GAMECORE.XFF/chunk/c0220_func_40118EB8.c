#include "common.h"

/* GAMECORE c0220: init worm ctrl work (p = base work, q = ctrl work). Calls siblings in the TU. */
extern void _resetBaseMoveWork(char *p, char *q);
extern void resetVelocityWormCtrlWork(char *p, char *q);
extern void func_40119260(char *q);

/* GAMECORE c0220 func_40119260: reset block; D_401377B4 is a rodata f32. Store order found by 5040-permutation search (ee-gcc2.96 -O2 offset-sequence match). */
extern const f32 D_401377B4;

/* GAMECORE c0220: tail call to func_401192E8 when w->mode (+0xCC) in {2,3}; mode 1 adds w->+0xD0 to q->+4. */
extern void func_401192E8(char *p, char *q);

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

/* GAMECORE c0220: stores a1 int at +0xCC, f12 at +0xD0, f13 at +0xD4. */
void setOffsetParamWormCtrlWork(char *p, int a, float x, float y)
{
    *(int *)(p + 0xCC) = a;
    *(float *)(p + 0xD0) = x;
    *(float *)(p + 0xD4) = y;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", setLimitTurnWormCtrlWork);
void setLimitTurnWormCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0xD8)) = arg1;
}

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", setWorldPitchLimitWormCtrlWork);
void setWorldPitchLimitWormCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x80)) = fparg0 * 3.1415926f / 180.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0220_func_40118EB8", resetVelocityWormCtrlWork);

void setAcceleParamWormCtrlWork(char *p, float f1, float f2)
{
    *(float *)(p + 0x5C) = f1;
    *(float *)(p + 0x60) = f2;
}

void func_401191D0(char *p, char *q)
{
    _resetBaseMoveWork(p, q);
    resetVelocityWormCtrlWork(p, q);
    *(f32 *)(q + 0xC0) = *(f32 *)(q + 0x58);
    *(f32 *)(q + 0x80) = 3.1415924f;
    *(f32 *)(q + 0x90) = -5.0f;
    *(f32 *)(q + 0x94) = 10.0f;
    *(f32 *)(q + 0x98) = -0.5f;
    *(f32 *)(q + 0x9C) = -2.0f;
    *(s32 *)(q + 0xD8) = 0;
    *(s32 *)(q + 0xE0) = 0;
    func_40119260(q);
}

void func_40119260(char *p)
{
    *(s32 *)(p + 0x30) = 0;
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x34) = 0;
    *(f32 *)(p + 0x40) = D_401377B4;
    *(f32 *)(p + 0x44) = D_401377B4;
    *(f32 *)(p + 0x4C) = 1.0f;
    *(f32 *)(p + 0x48) = D_401377B4;
}

void func_40119290(char *p, char *q)
{
    char *w = *(char **)(p + 0xCC);
    s32 k = *(s32 *)(w + 0xCC);
    if ((u32)(k - 2) < 2) {
        func_401192E8(p, q);
        return;
    }
    if (k == 1) {
        *(f32 *)(q + 4) = *(f32 *)(q + 4) + *(f32 *)(w + 0xD0);
    }
}

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
