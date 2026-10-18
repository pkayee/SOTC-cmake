#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D7B48);

extern void *GetSCRCharaAIWorkPtr(void *);
extern u8 gcGlobalVar[];

void SCRFuncKameFallPatienceCunterMain(void *actor)
{
    f32 temp_f1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_f1 = *(f32 *)((u8 *)temp_v0 + 0x41A0);
    if (temp_f1 > 0.0f) {
        *(f32 *)((u8 *)temp_v0 + 0x41A0) = temp_f1 - *(f32 *)(gcGlobalVar + 0x180);
    }
}

int SCRConditionKameFallPatienceCunterCheck(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x41A0)))
        r = 0;
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRFuncKameSetMissileRadius);

void SCRFuncKameDemoFlagSet(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B8)) = 1;
}

void SCRFuncKameDemoFlagReset(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B8)) = 0;
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
void func_400D8298(void *character);

void SCRFallRockDelete(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_400D8298);
}

void func_400D82E8(void *character);

void SCRFallRockSub(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400D82E8);
}

extern u8 *GetCharacterClass(void *);
extern void *SCRGetFirstObj(void *);

void SCRSetCrackAnimTimer(void)
{
    void *boss;
    u8 *work;

    boss = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (boss == 0) {
        return;
    }
    work = GetSCRCharaAIWorkPtr(boss);
    if ((*(s64 *)(GetCharacterClass(boss) + 0x680) & 0x01E00000) == 0x200000) {
        *(f32 *)(work + 0x41AC) += 0.5f;
    } else {
        *(f32 *)(work + 0x41AC) = 0.0f;
    }
    if (*(f32 *)(work + 0x41AC) > 5.0f) {
        *(f32 *)(work + 0x41AC) = 5.0f;
    }
}

int SCRConditionKameCrackAnimChack(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x41AC)))
        r = 0;
    return r;
}

void SCRFuncKameCrackAnimMain(void *actor)
{
    f32 temp_f1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_f1 = *(f32 *)((u8 *)temp_v0 + 0x41AC);
    if (temp_f1 > 0.0f) {
        *(f32 *)((u8 *)temp_v0 + 0x41AC) = temp_f1 - *(f32 *)(gcGlobalVar + 0x180);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRFuncKameSetTemporaryTarget);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRConditionKameNextTemporaryTarget);

int SCRConditionKameWallCaseFlagChack(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B4));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8088);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D81B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D81E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8218);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8278);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8298);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D82E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8338);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", nico_unagiBossStart);
