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

extern s32 DldSysUndefSymbol;
extern char SH_ItemMenuDEFAULT[];
extern char D_40136D18[];
extern char D_40136D30[];
u32 MakeStrHashValue(const char *str);
s32 _omakeSelectFlagChk(s32 bit);
void SpriteMenuSetCheckBoxByHash(s32 menu, s32 layerHash, s32 partHash, s32 flag);

extern s32 _omakeGetFlagChk(s32 bit);
typedef struct { s32 pad0; s32 pad4; s32 flag; s32 padC; } OmakeEnt;
typedef struct { s32 pad[3]; s32 cnt; OmakeEnt *list; } ItemMenu;

extern char D_40136B70[];
extern char D_40136B80[];
extern char D_40136B90[];
s32 SpriteMenuGetMenuIdByHash(u8 *menu, s32 layerHash, s32 hash);
s32 SpriteMenuGetLayerNoByHash(u8 *menu, s32 hash);
void SpriteMenuSetDispFlag(u8 *menu, s32 layer, s32 flag);

extern char D_40136BA0[];
extern char D_40136BB8[];
extern char D_40136BD0[];
extern char D_40136BE8[];

extern char D_40136C08[];

extern char D_40136C20[];

extern char D_40136C30[];

extern char D_40136D40[];
extern char D_40136D50[];
extern char D_40136D60[];

extern char D_40136DE8[];

extern char D_40136DF8[];

extern char D_40136E08[];
extern char D_40136DB8[];
extern char D_40136DD0[];

extern u8 gcGlobalVar[];
extern u8 *GameObject_DEMO_TITLE_STARTER;
s32 opflowChkLoadStart(void);
void fadeOut(s32 wait, s32 pause, f32 f);
u8 *SCRGetFirstObj(void *table);
void SetCharacterObjDemoMotionMode(u8 *obj, s32 a, s32 b, f32 f);
u8 *GetScriptCharacterClass(void *chara);
void isysRequestDeleteObj(s32 obj);
void FinishDemoCameraOrient(s32 a0);
void demoManEnd(s32 o);
void opflowTitleDmoeEnd(void);

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

void ReplayGameOverScriptBegin(void)
{
    struct RV0 {
        s32 a;
        s32 b;
        s32 c;
        u32 flags;
    };
    extern struct RV0 g_Replay;
    extern s32 D_40131EA8;
    extern s32 D_40131EAC;
    extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_BG;
    extern s32 ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_ALERT;

    g_Replay.c = 1;
    g_Replay.b = 7;
    g_Replay.flags &= ~0x80;
    if (D_40131EA8 != 0) {
        D_40131EA8 = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_BG, 0, 0, &D_40131EA8, 0, 0);
    }
    g_Replay.c = 1;
    g_Replay.b = 7;
    g_Replay.flags &= ~0x40;
    if (D_40131EAC != 0) {
        D_40131EAC = 0;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_REPLAY_MODE_OVER_ALERT, 0, 0, &D_40131EAC, 0, 0);
    }
}

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

void func_400D56D8(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136B70), MakeStrHashValue(D_40136B80))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136B70), MakeStrHashValue(D_40136B90)))
                obj[1] = 0xd;
        }
    } else if (flags & 2) {
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136B70)), 0);
        obj[1] = 0xd;
    }
}

void func_400D57E0(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136BA0), MakeStrHashValue(D_40136BB8))) {
            obj[1] = 9;
        } else if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136BA0), MakeStrHashValue(D_40136BD0))) {
            obj[1] = 3;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136BA0), MakeStrHashValue(D_40136BE8)))
                obj[1] = 4;
        }
    } else if (flags & 2) {
        obj[1] = 9;
    }
}

void func_400D58F0(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C08), MakeStrHashValue(D_40136B80))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C08), MakeStrHashValue(D_40136B90)))
                obj[1] = 2;
        }
    } else if (flags & 2) {
        obj[1] = 2;
    }
}

void func_400D59D0(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C20), MakeStrHashValue(D_40136B80))) {
            obj[1] = 0xb;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C20), MakeStrHashValue(D_40136B90))) {
                if (obj[2] == 1)
                    obj[1] = 10;
                else
                    obj[1] = 2;
            }
        }
    } else if (flags & 2) {
        if (obj[2] == 1)
            obj[1] = 10;
        else
            obj[1] = 2;
    }
}

void func_400D5AC0(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C30), MakeStrHashValue(D_40136BD0))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136C30), MakeStrHashValue(D_40136BE8)))
                obj[1] = 4;
        }
    }
}

int GetNumOmakeItem(void)
{
    ItemMenu *m = (ItemMenu *)SH_ItemMenuDEFAULT;
    s32 n, cnt, i;
    OmakeEnt *l;

    if (DldSysUndefSymbol == (s32)SH_ItemMenuDEFAULT)
        m = 0;
    n = 0;
    cnt = m->cnt;
    l = m->list;
    for (i = 0; i < cnt; i++) {
        if (_omakeGetFlagChk(l[i].flag))
            n++;
    }
    return n;
}

void CheckSelectDisp(s32 menu)
{
    extern s32 g_Replay;
    char *t = SH_ItemMenuDEFAULT;
    s32 cnt;
    s32 *e;
    s32 h;

    if (DldSysUndefSymbol == (s32)SH_ItemMenuDEFAULT)
        t = 0;
    e = *(s32 **)(t + 0x10);
    cnt = *(s32 *)(t + 0xC);
    if (g_Replay == menu)
        h = MakeStrHashValue(D_40136D18);
    else
        h = MakeStrHashValue(D_40136D30);
    if (cnt > 0) {
        do {
            cnt--;
            SpriteMenuSetCheckBoxByHash(menu, h, e[0], _omakeSelectFlagChk(e[2]));
            e += 4;
        } while (cnt != 0);
    }
}

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

void func_400D5E40(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D40), MakeStrHashValue(D_40136D50))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D40), MakeStrHashValue(D_40136D60)))
                obj[1] = 0xd;
        }
    } else if (flags & 2) {
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136D40)), 0);
        obj[1] = 0xd;
    }
}

void func_400D5F48(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136DE8), MakeStrHashValue(D_40136D50))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136DE8), MakeStrHashValue(D_40136D60)))
                obj[1] = 2;
        }
    } else if (flags & 2) {
        obj[1] = 2;
    }
}

void func_400D6028(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136DF8), MakeStrHashValue(D_40136D50))) {
            obj[1] = 0xb;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136DF8), MakeStrHashValue(D_40136D60))) {
                if (obj[2] == 1)
                    obj[1] = 10;
                else
                    obj[1] = 2;
            }
        }
    } else if (flags & 2) {
        if (obj[2] == 1)
            obj[1] = 10;
        else
            obj[1] = 2;
    }
}

void func_400D6118(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    if (flags & 1) {
        if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136E08), MakeStrHashValue(D_40136DB8))) {
            obj[1] = 8;
        } else {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136E08), MakeStrHashValue(D_40136DD0)))
                obj[1] = 4;
        }
    }
}

void func_400D61E0(s32 unused, s32 *p)
{
    if (opflowChkLoadStart() == 0)
        fadeOut(1, 0, 0.4f);
    SetCharacterObjDemoMotionMode(SCRGetFirstObj(gcGlobalVar + 0x2B0), 0, 0, 10.0f);
    *(s32 *)(GetScriptCharacterClass(SCRGetFirstObj(gcGlobalVar + 0x2B0)) + 0x1154) = 0;
    SetCharacterObjDemoMotionMode(SCRGetFirstObj(gcGlobalVar + 0x2B4), 0, 0, 10.0f);
    *(s32 *)(GetScriptCharacterClass(SCRGetFirstObj(gcGlobalVar + 0x2B4)) + 0x1154) = 0;
    isysRequestDeleteObj(p[1]);
    FinishDemoCameraOrient(p[0]);
    demoManEnd(*(s32 *)(GameObject_DEMO_TITLE_STARTER + 8));
    opflowTitleDmoeEnd();
}
