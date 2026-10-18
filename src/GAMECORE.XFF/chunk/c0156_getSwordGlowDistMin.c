#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getSwordGlowDistMin);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getSwordGlowDistMax);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionGlowSpeed);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionGlowTime);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionPosOffset);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A58);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", SCRDirectionalArrowBegin);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", SCRDirectionalArrowEnd);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2B90);

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
