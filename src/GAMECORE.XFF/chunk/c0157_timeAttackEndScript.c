#include "common.h"

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
extern u8 gcGlobalVar[];
u32 MakeStrHashValue(const char *str);
s32 SpriteMenuGetLayerNoByHash(void *menu, s32 hash);
void SpriteMenuSetDispFlag(void *menu, s32 layer, s32 flag);
void SpriteMenuSetDispFlagAll(void *menu, s32 flag);
s32 SpriteMenuIsFadeCheckAllLayer(void *menu);
s32 SpriteMenuGetMenuIdByHash(void *menu, s32 layerHash, s32 hash);
void SpriteMenuSetLayer(void *menu, s32 layer);
void SpriteMenuSetSelectMenuId(void *menu, s32 id);
void *isysGetThisSubThread(void);
u8 *GetSpriteMenuClass(void *thread);
void ScrSpriteParamSetup(void *sp, void *param);
void ScrSpriteParamEnd(void *sp, s32 flag);
void scrRun(void);
void scriptIntrSignal();
extern struct TimeAttackView g_Replay;
extern char D_40136D40[];
extern char D_40136D60[];
void func_400D5E40(void);
extern char D_40136C20[];
extern char D_40136B90[];
extern s32 ScrIntrDef_GAME_CANCEL;
void func_400D59D0(void);
s32 func_400D2D28(void *menu, struct TimeAttackView *t);

extern char D_40136C58[];
extern char D_40136C70[];
extern char D_40136C90[];
u8 *SpriteMenuGetPartsDefByHash(void *menu, s32 layerHash, s32 partHash);
s32 func_400D2E50(void *menu, struct TimeAttackView *t, s32 *flag);

static inline s32 replayInDone(void *menu, struct TimeAttackView *t)
{
    if ((t->b == 8 || t->b == 13) && SpriteMenuIsFadeCheckAllLayer(menu) == 0) {
        SpriteMenuSetDispFlagAll(menu, 0);
        return 1;
    }
    if (t->flags & 2) {
        t->flags &= ~2;
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136D40)), 0);
        return 1;
    }
    return 0;
}

void timeAttackEndScript(void *param)
{
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    struct TimeAttackView *t = &g_TimeAttack;
    u8 sp[16];

    ScrSpriteParamSetup(sp, param);
    SpriteMenuSetDispFlag(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136C20)), 1);
    SpriteMenuSetLayer(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136C20)));
    SpriteMenuSetSelectMenuId(thread, SpriteMenuGetMenuIdByHash(thread, MakeStrHashValue(D_40136C20), MakeStrHashValue(D_40136B90)));
    while (1) {
        u8 *g = gcGlobalVar;
        ((void (*)(f32, void *, s32, void (*)(void), struct TimeAttackView *))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x170), thread, 1, func_400D59D0, t);
        if (func_400D2D28(thread, t) != 0)
            break;
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        scrRun();
    }
    ScrSpriteParamEnd(sp, 1);
    if (t->b == 0xB)
        scriptIntrSignal(ScrIntrDef_GAME_CANCEL);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0157_timeAttackEndScript", timeAttackOverBGScript);

extern char D_40136C30[];
extern char D_40136BD0[];
void func_400D5AC0(void);
void func_400D55A8(void);

static inline s32 timeAttackOverAlertDone(void *menu, struct TimeAttackView *t)
{
    switch (t->b) {
    case 8:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C30)), 0);
        return 1;
    case 4:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C30)), 0);
        t->elapsed = 0;
        func_400D55A8();
        return 1;
    }
    if (t->flags & 0x40) {
        t->flags &= ~0x40;
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C30)), 0);
        return 1;
    }
    return 0;
}

void timeAttackOverAlertScript(void *param)
{
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    struct TimeAttackView *t = &g_TimeAttack;
    u8 sp[16];

    ScrSpriteParamSetup(sp, param);
    SpriteMenuSetDispFlag(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136C30)), 1);
    SpriteMenuSetLayer(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136C30)));
    SpriteMenuSetSelectMenuId(thread, SpriteMenuGetMenuIdByHash(thread, MakeStrHashValue(D_40136C30), MakeStrHashValue(D_40136BD0)));
    while (1) {
        u8 *g = gcGlobalVar;
        ((void (*)(f32, void *, s32, void (*)(void), struct TimeAttackView *))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x170), thread, 1, func_400D5AC0, t);
        if (timeAttackOverAlertDone(thread, t) != 0)
            break;
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        scrRun();
    }
    ScrSpriteParamEnd(sp, 1);
}

void timeAttackTimeScript(void *param)
{
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    struct TimeAttackView *t = &g_TimeAttack;
    u8 sp[16];
    s32 flag = 0;

    ScrSpriteParamSetup(sp, param);
    *(s32 *)(SpriteMenuGetPartsDefByHash(thread, MakeStrHashValue(D_40136C58), MakeStrHashValue(D_40136C70)) + 0xC) = 0;
    *(s32 *)(SpriteMenuGetPartsDefByHash(thread, MakeStrHashValue(D_40136C58), MakeStrHashValue(D_40136C90)) + 0xC) = (s32)(t->limit * 100.0f);
    SpriteMenuSetDispFlag(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136C58)), 1);
    while (1) {
        u8 *g = gcGlobalVar;
        ((void (*)(f32, void *, s32, void (*)(void), struct TimeAttackView *))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x180), thread, 1, 0, t);
        if (func_400D2E50(thread, t, &flag) != 0)
            break;
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        scrRun();
    }
    ScrSpriteParamEnd(sp, 1);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0157_timeAttackEndScript", SetItemMenuDisp);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0157_timeAttackEndScript", SelectOmakeItem);

extern char D_40136D18[];
extern char D_40136D70[];
extern char D_40136D80[];
extern char D_40136D90[];
extern char D_40136DA0[];
extern char D_40136DB8[];
extern char D_40136DD0[];
extern s32 D_402184E0;
extern s32 rootPtn;
void st_pausemenu_load_omake_chara(s32 *p);
void SelectOmakeItem(s32 menu, s32 id);
s32 gcCreateScriptObj(void *fn, s32 *a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);

void func_400D4038(u8 *menu, s32 *obj, u32 flags, s32 id)
{
    s32 st;

    if (obj[1] == 14) {
        if (flags & 1) {
            SelectOmakeItem((s32)menu, id);
            return;
        }
        if (flags & 2) {
            SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136D18)), 0);
            SpriteMenuSetLayer(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136D70)));
            SpriteMenuSetSelectMenuId(menu, SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D70), MakeStrHashValue(D_40136D80)));
            obj[1] = 15;
            D_402184E0 = 0;
            gcCreateScriptObj(st_pausemenu_load_omake_chara, &D_402184E0, &rootPtn, 0x1000, 0, 8, D_40136D90);
            return;
        }
    } else {
        if (flags & 1) {
            if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D70), MakeStrHashValue(D_40136DA0))) {
                obj[1] = 9;
            } else if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D70), MakeStrHashValue(D_40136DB8))) {
                obj[1] = 3;
            } else if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D70), MakeStrHashValue(D_40136DD0))) {
                obj[1] = 4;
            } else if (id == SpriteMenuGetMenuIdByHash(menu, MakeStrHashValue(D_40136D70), MakeStrHashValue(D_40136D80))) {
                obj[1] = 14;
            }
        } else if (flags & 2) {
            obj[1] = 9;
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0157_timeAttackEndScript", func_400D42A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0157_timeAttackEndScript", func_400D4470);

void ReplayInScript(void *param)
{
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    struct TimeAttackView *t = &g_Replay;
    u8 sp[16];

    ScrSpriteParamSetup(sp, param);
    SpriteMenuSetDispFlag(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136D40)), 1);
    SpriteMenuSetLayer(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136D40)));
    SpriteMenuSetSelectMenuId(thread, SpriteMenuGetMenuIdByHash(thread, MakeStrHashValue(D_40136D40), MakeStrHashValue(D_40136D60)));
    while (1) {
        u8 *g = gcGlobalVar;
        ((void (*)(f32, void *, s32, void (*)(void), struct TimeAttackView *))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x170), thread, 1, func_400D5E40, t);
        if (replayInDone(thread, t) != 0)
            break;
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        scrRun();
    }
    ScrSpriteParamEnd(sp, 1);
}
