#include "common.h"

u8 *GetSCRCharaAIWorkPtr();

extern f32 D_40137084;
extern char D_40132148[];
extern char D_40132160[];
extern char D_40132178[];
extern char D_40132190[];
extern void *isysGetThisSubThread(void);
void bootTexAlphaAnim(void *, void *, f32, f32);

void SCRFuncYamoriBSetBellyDamageParam(void *actor, f32 fparg0)
{
    u8 *work = GetSCRCharaAIWorkPtr(actor);
    *(f32 *)(work + 0x41C8) = fparg0;
}

void SCRFuncYamoriBSetBellyDamageInitWork(void)
{
    u8 *work;
    f32 initial;

    work = GetSCRCharaAIWorkPtr();
    initial = D_40137084;
    *(s32 *)(work + 0x41C0) = 0;
    *(f32 *)(work + 0x41C4) = initial;
}

int SCRConditionYamoriBLessBellyDamageProgress(void *actor, f32 fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!((*(f32 *)((u8 *)(GetSCRCharaAIWorkPtr(actor)) + 0x41C4)) <= fparg0)) {
        var_v0 = 0;
    }
    return var_v0;
}

int SCRConditionYamoriBBellyDamageCheck(void *actor, int damage)
{
    return *(s32 *)(GetSCRCharaAIWorkPtr(actor) + 0x41C0) >= damage;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", SCRFuncYamoriBSetAttainPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", SCRFuncYamoriBSetAttainPosForGroundAttack);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", SCRFuncYamoriBAimInit);

void nico_yamoriArmRightTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132148, 0.0f, -0.05f);
}

void nico_yamoriArmRightTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132148, 1.0f, 0.05f);
}

void nico_yamoriArmLeftTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132160, 0.0f, -0.05f);
}

void nico_yamoriArmLeftTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132160, 1.0f, 0.05f);
}

void nico_yamoriLegRightTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132178, 0.0f, -0.05f);
}

void nico_yamoriLegRightTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132178, 1.0f, 0.05f);
}

void nico_yamoriLegLeftTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132190, 0.0f, -0.05f);
}

void nico_yamoriLegLeftTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40132190, 1.0f, 0.05f);
}

void nico_yamoriAllTexEnd(void)
{
    void *th = isysGetThisSubThread();

    bootTexAlphaAnim(th, D_40132148, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40132160, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40132178, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40132190, 0.0f, -0.05f);
}

void nico_yamoriAllTexStart(void)
{
    void *th = isysGetThisSubThread();

    bootTexAlphaAnim(th, D_40132148, 1.0f, 0.05f);
    bootTexAlphaAnim(th, D_40132160, 1.0f, 0.05f);
    bootTexAlphaAnim(th, D_40132178, 1.0f, 0.05f);
    bootTexAlphaAnim(th, D_40132190, 1.0f, 0.05f);
}

void func_400DC2E0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", func_400DC2E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", func_400DC398);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", func_400DC538);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0166_SCRFuncYamoriBSetBellyDamageParam", demo_common);
