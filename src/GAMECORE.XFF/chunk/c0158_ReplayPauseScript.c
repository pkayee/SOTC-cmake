#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayPauseScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayRetryScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayEndScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayOverBGScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayOverAlertScript);

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
extern s32 D_40131E7C;
extern s32 D_40131E80;
extern float D_40131E58;
extern s32 ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_IN;
extern s32 ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_PAUSE;
void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 *a3, s32 a4, s32 a5);

void timeAttackInScriptBegin(void)
{
    g_TimeAttack.c = 0;
    g_TimeAttack.b = 1;
    g_TimeAttack.flags &= ~2;
    if (D_40131E7C != 0) {
        D_40131E7C = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_IN, 0, 0, &D_40131E7C, 0, 0);
    }
}

void timeAttackPauseScriptBegin(void)
{
    g_TimeAttack.c = 0;
    g_TimeAttack.b = 2;
    g_TimeAttack.flags &= ~4;
    if (D_40131E80 != 0) {
        D_40131E80 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_PAUSE, 0, 0, &D_40131E80, 0, 0);
    }
}

extern s32 D_40131E94;
extern s32 ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_TIME;

void timeAttackTimeScriptBegin(float t)
{
    g_TimeAttack.limit = t;
    g_TimeAttack.flags &= ~0x20;
    g_TimeAttack.elapsed = 0;
    *(s32 *)g_TimeAttack.pad10 = 0;
    if (D_40131E94 != 0) {
        D_40131E94 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_TIME, 0, 0, &D_40131E94, 0, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", timeAttackGameOverScriptBegin);

extern s32 D_40131E44;

s32 GetTimeAttackNextPhase(void)
{
    switch (D_40131E44) {
    case 8:
        return 1;
    case 9:
        return 2;
    case 11:
        return 3;
    case 13:
        return 4;
    }
    return 0;
}

float GetTimeAttackTimer(void)
{
    return D_40131E58;
}

extern s32 D_40131E50;

void SetTimeAttackTimeFlag(s32 arg0)
{
    D_40131E50 = arg0;
}

float GetTimeAttackTimeLimit(void)
{
    return g_TimeAttack.limit - g_TimeAttack.elapsed;
}

struct ReplayView {
    s32 a;
    s32 b;
    s32 c;
    u32 flags;
};

extern struct ReplayView g_Replay;
extern s32 D_40131E98;
extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_IN;

void ReplayInScriptBegin(void)
{
    g_Replay.c = 0;
    g_Replay.b = 1;
    g_Replay.flags &= ~2;
    if (D_40131E98 != 0) {
        D_40131E98 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_IN, 0, 0, &D_40131E98, 0, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0158_ReplayPauseScript", ReplayPauseScriptBegin);
