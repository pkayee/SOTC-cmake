#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", nico_poseidonStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", SCRFuncPoseidonParallelTrans);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", func_400A3950);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", func_400A3C10);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", func_400A3CB8);

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_400A3228(void *character);

void SCRPoseidonShoot(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400A3228);
}

extern void *isysGetThisSubThread(void);
extern char D_40131B70[];
extern void bootTexAlphaAnim(void *, void *, float, float);

void nico_poseidonToothFTexAnimStrat(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131B70, 1.0f, 0.05f);
}

void nico_poseidonToothFTexAnimEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131B70, 0.0f, -0.05f);
}

extern char D_40131B88[];

void nico_poseidonToothRTexAnimStrat(void)
{
    void *t = isysGetThisSubThread();
    bootTexAlphaAnim(t, D_40131B88, 1.0f, 0.05f);
    bootTexAlphaAnim(t, D_40131B70, 0.0f, -0.05f);
}

void nico_poseidonToothRTexAnimEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131B88, 0.0f, -0.05f);
}

extern char D_40131BA0[];

void nico_poseidonToothLTexAnimStrat(void)
{
    void *t = isysGetThisSubThread();
    bootTexAlphaAnim(t, D_40131BA0, 1.0f, 0.05f);
    bootTexAlphaAnim(t, D_40131B70, 0.0f, -0.05f);
}

void nico_poseidonToothLTexAnimEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131BA0, 0.0f, -0.05f);
}

void nico_poseidonToothTexAnimInit(void)
{
    void *th = isysGetThisSubThread();

    bootTexAlphaAnim(th, D_40131B88, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131BA0, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131B70, 0.0f, -0.05f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0119_nico_poseidonStart", func_400A3F78);
