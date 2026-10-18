#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getSwordGlowDistMin);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getSwordGlowDistMax);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionGlowSpeed);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionGlowTime);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionPosOffset);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A58);
void func_400D2A58(u8* work)
{
    *(s32*)work = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A60);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A70);
u64 *GetCollisionDBAttributeAdr(void *surface);

s32 func_400D2A70(void *surface)
{
    u64 attribute = *GetCollisionDBAttributeAdr(surface);
    u64 flags = attribute & (0xF800UL << 20);
    u64 material = attribute & 0x7C000000UL;
    u64 mode = attribute & (0xF000UL << 30);

    if (material == 0x04000000UL || material == 0x64000000UL || material == 0x68000000UL ||
        material == 0x6C000000UL)
    {
        return 0;
    }
    if (material == 0x24000000UL || flags == (0x8000UL << 18) || flags == (0xB800UL << 20) ||
        flags == (0xC000UL << 18) || flags == (0xA000UL << 19) || flags == (0xE000UL << 18) ||
        flags == (0xA000UL << 18) || mode == (0x8000UL << 28))
    {
        return 0;
    }
    return 1;
}

void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));
void func_400D1090(void);

void SCRDirectionalArrowBegin(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_400D1090);
}

void func_400D2B90(void);

void SCRDirectionalArrowEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_400D2B90);
}

void CancelSwordEffect(void);

void func_400D2B90(void)
{
    CancelSwordEffect();
}

struct TimeAttackView {
    s32 a;
    s32 b;
    s32 c;
    u32 flags;
    char pad10[0x4];
    float limit;
    float elapsed;
};

extern struct TimeAttackView g_TimeAttack;

float timeAttackTimeScriptEnd(void)
{
    g_TimeAttack.flags |= 0x20;
    return g_TimeAttack.elapsed;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2BC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2D28);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2E50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", timeAttackInScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", timeAttackPauseScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", timeAttackRetryScript);
