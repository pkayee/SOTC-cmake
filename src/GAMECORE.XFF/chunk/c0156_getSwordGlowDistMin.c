#include "common.h"

extern s32 D_40131E04;

extern char D_40136BA0[];
u32 MakeStrHashValue(const char *str);
s32 SpriteMenuGetLayerNoByHash(void *menu, s32 hash);
void SpriteMenuSetDispFlag(void *menu, s32 layer, s32 flag);
void SpriteMenuSetDispFlagAll(void *menu, s32 flag);
s32 SpriteMenuIsFadeCheckAllLayer(void *menu);
void func_400D5530(void);
void func_400D55A8(void);

extern char D_40136C20[];
void timeAttackPauseScriptBegin(void);
void func_400D5620(void);

extern u8 gcGlobalVar[];
extern char D_40136C58[];
extern char D_40136C70[];
extern char D_40136C90[];
u8 *SpriteMenuGetPartsDefByHash(void *menu, s32 layerHash, s32 partHash);
float getDemoBarFade(void);
float getFadeValue(void);

extern char D_40136BB8[];
extern s32 ScrIntrDef_MENU_CONTINUE;
void *isysGetThisSubThread(void);
u8 *GetSpriteMenuClass(void *thread);
void ScrSpriteParamSetup(void *sp, void *param);
void ScrSpriteParamEnd(void *sp, s32 flag);
s32 SpriteMenuGetMenuIdByHash(void *menu, s32 layerHash, s32 hash);
void SpriteMenuSetLayer(void *menu, s32 layer);
void SpriteMenuSetSelectMenuId(void *menu, s32 id);
void func_400D57E0(void);
void scrRun(void);
void scriptIntrSignal();

s32 *getSwordGlowDistMin(void)
{
    return &D_40131E04;
}

extern s32 D_40131E08;

s32 *getSwordGlowDistMax(void)
{
    return &D_40131E08;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", getCollisionGlowSpeed);
extern s32 D_40131E18;

s32 *getCollisionGlowSpeed(void)
{
    return &D_40131E18;
}

extern s32 D_40131E1C;

s32 *getCollisionGlowTime(void)
{
    return &D_40131E1C;
}

extern s32 D_40131E20;

s32 *getCollisionPosOffset(void)
{
    return &D_40131E20;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A58);
void func_400D2A58(u8* work)
{
    *(s32*)work = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", func_400D2A60);
s32 func_400D2A60(s32 a, s32 b)
{
    return a != b;
}

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

/* TIME_ATTACK_PAUSE menu-state callback: switch on t->b (13, 9, 3, 4, default flag 4 clear) */
s32 func_400D2BC8(void *menu, struct TimeAttackView *t)
{
    switch (t->b) {
    case 13:
        if (SpriteMenuIsFadeCheckAllLayer(menu) == 0) {
            SpriteMenuSetDispFlagAll(menu, 0);
            return 1;
        }
        break;
    case 9:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136BA0)), 0);
        return 1;
    case 3:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136BA0)), 0);
        func_400D5530();
        return 1;
    case 4:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136BA0)), 0);
        func_400D55A8();
        return 1;
    }
    if (t->flags & 4) {
        t->flags &= ~4;
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136BA0)), 0);
        return 1;
    }
    return 0;
}

/* TIME_ATTACK_END menu-state callback: switch on t->b (11, 2, 10, default flag 0x10 clear) */
s32 func_400D2D28(void *menu, struct TimeAttackView *t)
{
    switch (t->b) {
    case 11:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C20)), 0);
        return 1;
    case 2:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C20)), 0);
        timeAttackPauseScriptBegin();
        return 1;
    case 10:
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C20)), 0);
        func_400D5620();
        return 1;
    }
    if (t->flags & 0x10) {
        t->flags &= ~0x10;
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C20)), 0);
        return 1;
    }
    return 0;
}

/* TIME_ATTACK_TIME HUD updater: t->pad10 = active, limit/elapsed seconds * 100 into the two parts */
s32 func_400D2E50(void *menu, struct TimeAttackView *t)
{
    s32 el, lim;

    if (*(s32 *)t->pad10 != 0) {
        if (getDemoBarFade() == 1.0f && getFadeValue() == 0.0f) {
            t->elapsed += *(float *)(gcGlobalVar + 0x180);
        }
        lim = (s32)(t->limit * 100.0f);
        el = (s32)(t->elapsed * 100.0f);
        *(s32 *)(SpriteMenuGetPartsDefByHash(menu, MakeStrHashValue(D_40136C58), MakeStrHashValue(D_40136C70)) + 0xC) = el;
        *(s32 *)(SpriteMenuGetPartsDefByHash(menu, MakeStrHashValue(D_40136C58), MakeStrHashValue(D_40136C90)) + 0xC) = lim - el;
    }
    if (t->flags & 0x20) {
        t->flags &= ~0x20;
        SpriteMenuSetDispFlag(menu, SpriteMenuGetLayerNoByHash(menu, MakeStrHashValue(D_40136C58)), 0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", timeAttackInScript);

/* TIME_ATTACK_PAUSE menu script: show layer, run class update (+0x28 / +0x2C) until func_400D2BC8 returns nonzero, continue-signal on state 9 */
void timeAttackPauseScript(void *param)
{
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    struct TimeAttackView *t = &g_TimeAttack;
    u8 sp[16];

    ScrSpriteParamSetup(sp, param);
    SpriteMenuSetDispFlag(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136BA0)), 1);
    SpriteMenuSetLayer(thread, SpriteMenuGetLayerNoByHash(thread, MakeStrHashValue(D_40136BA0)));
    SpriteMenuSetSelectMenuId(thread, SpriteMenuGetMenuIdByHash(thread, MakeStrHashValue(D_40136BA0), MakeStrHashValue(D_40136BB8)));
    while (1) {
        u8 *g = gcGlobalVar;
        ((void (*)(f32, void *, s32, void (*)(void), struct TimeAttackView *))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x170), thread, 1, func_400D57E0, t);
        if (func_400D2BC8(thread, t) != 0)
            break;
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        scrRun();
    }
    ScrSpriteParamEnd(sp, 1);
    switch (t->b) {
    case 3:
    case 4:
        break;
    case 9:
        scriptIntrSignal(ScrIntrDef_MENU_CONTINUE);
        break;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0156_getSwordGlowDistMin", timeAttackRetryScript);
