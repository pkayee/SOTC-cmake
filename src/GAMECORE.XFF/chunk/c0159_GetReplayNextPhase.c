#include "common.h"

extern int D_40131E64;

typedef struct { int a; int b; int c; int flags; } TimeAttack;
extern TimeAttack g_TimeAttack;
extern int D_40131E84;
extern int ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_RETRY;
extern int ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_END;
extern int D_40131E88;
extern int D_40131E90;
extern int ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_OVER_ALERT;
void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 *a3, s32 a4, s32 a5);

int GetReplayNextPhase(void)
{
    switch (D_40131E64) {
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", ReplayGameOverScriptBegin);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5530);
void func_400D5530(void)
{
    g_TimeAttack.b = 3;
    g_TimeAttack.flags &= ~8;
    if (D_40131E84 != 0) {
        D_40131E84 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_RETRY, 0, 0, &D_40131E84, 0, 0);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D55A8);
void func_400D55A8(void)
{
    g_TimeAttack.b = 4;
    g_TimeAttack.flags &= ~0x10;
    if (D_40131E88 != 0) {
        D_40131E88 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_END, 0, 0, &D_40131E88, 0, 0);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5620);
void func_400D5620(void)
{
    g_TimeAttack.c = 1;
    g_TimeAttack.b = 7;
    g_TimeAttack.flags &= ~0x40;
    if (D_40131E90 != 0) {
        D_40131E90 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_TIME_ATTACK_OVER_ALERT, 0, 0, &D_40131E90, 0, 0);
    }
}

void CloseTimeAttackMenu(int a)
{
    if (a == 1)
        g_TimeAttack.flags |= 0xFE;
    else
        g_TimeAttack.flags |= a;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D56D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D57E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D58F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D59D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5AC0);

/* NEARMISS-STUB GetNumOmakeItem */
#if 0 /* NEARMISS 78.625% cat=regalloc sub=- | regs swapped: target t in v1 and DldSys in a0, ours opposite; n=0 and list load order differ | attempts=1 */
typedef struct {
    int flag;
    int pad[3];
} OmakeEnt;

extern char SH_ItemMenuDEFAULT[];
extern s32 DldSysUndefSymbol;
extern s32 _omakeGetFlagChk(s32 bit);

int GetNumOmakeItem(void)
{
    char *t = ((s32)SH_ItemMenuDEFAULT != DldSysUndefSymbol) ? SH_ItemMenuDEFAULT : 0;
    int n = 0;
    int i;
    int cnt;
    OmakeEnt *e;

    cnt = *(int *)(t + 0xC);
    e = (OmakeEnt *)(*(char **)(t + 0x10) + 8);
    for (i = 0; i < cnt; i++) {
        int f = e->flag;
        e++;
        if (_omakeGetFlagChk(f))
            n++;
    }
    return n;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", GetNumOmakeItem);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", CheckSelectDisp);

struct ReplayView {
    s32 a;
    s32 b;
    s32 c;
    u32 flags;
};

extern struct ReplayView g_Replay;
extern s32 D_40131EA0;
extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_RETRY;

void func_400D5CD0(void)
{
    g_Replay.b = 3;
    g_Replay.flags &= ~8;
    if (D_40131EA0 != 0) {
        D_40131EA0 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_RETRY, 0, 0, &D_40131EA0, 0, 0);
    }
}

extern s32 D_40131EA4;
extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_END;

void func_400D5D48(void)
{
    g_Replay.b = 4;
    g_Replay.flags &= ~0x10;
    if (D_40131EA4 != 0) {
        D_40131EA4 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_END, 0, 0, &D_40131EA4, 0, 0);
    }
}

extern s32 D_40131EAC;
extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_ALERT;

void func_400D5DC0(void)
{
    g_Replay.c = 1;
    g_Replay.b = 7;
    g_Replay.flags &= ~0x40;
    if (D_40131EAC != 0) {
        D_40131EAC = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_ALERT, 0, 0, &D_40131EAC, 0, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5E40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5F48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D6028);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D6118);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D61E0);
