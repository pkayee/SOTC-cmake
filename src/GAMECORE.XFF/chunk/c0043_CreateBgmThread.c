#include "common.h"

extern void func_40044CE0(void);
extern s32 gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
extern void *memset(void *, int, unsigned int);
extern unsigned char D_40201208[];
extern const char D_40133208[];

void *CreateBgmThread(void *p)
{
    void *r = (void *)gcCreateScriptObj((void *)func_40044CE0, 0, p, 0x1000, 0, 1, D_40133208);

    memset(D_40201208, 0, 0x9c);
    return r;
}

extern void func_400453A0(void);
s32 createScriptObj(void *fn, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

void *CreateWindThread(s32 a, s32 b)
{
    return (void *)createScriptObj(func_400453A0, a, b, 0x1000, 0, 1, 0, 0);
}

void func_400453A0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", func_400453A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", st_activedemo);

extern void *isysGetThisSubThread(void);
extern void gStatUnloadHorseChara(void);
extern void isysRequestDeleteObj(void *);

void st_unload_horse_char(void)
{
    void *t = isysGetThisSubThread();

    gStatUnloadHorseChara();
    isysRequestDeleteObj(t);
}

extern s32 rootPtn;
extern s32 iosCreatePartition(void *, s32);
extern char *GetScriptLayoutClass(void *);
extern void SetScriptLayoutObjLetterProcMode(void *, s32);
extern s32 *_SCRMallocAlign(s32, s32, s32);
extern void isysJumpSubThread(void (*)(void), void *);
extern void st_activedemo(void);
extern s32 func_40045CE8(void);
extern void func_40045D38(void);

void demo_last_battle1(void)
{
    void *th = isysGetThisSubThread();
    s32 part = iosCreatePartition(&rootPtn, 0x43);
    char *c;
    s32 *m;

    *(s32 *)(GetScriptLayoutClass(th) + 0x2D4) = part;
    SetScriptLayoutObjLetterProcMode(th, 1);
    c = GetScriptLayoutClass(th);
    m = _SCRMallocAlign(part, 0x10, 0x10);
    *(s32 **)(c + 0x2D8) = m;
    m[2] = (s32)func_40045CE8;
    m[3] = (s32)func_40045D38;
    isysJumpSubThread(st_activedemo, m);
}

extern u8 gcGlobalVar[];
extern void *SCRGetFirstObj(void *table);
extern s32 nico_ResetPlayerHorseRidingControl(void *obj);

s32 demo_brige_resetHorseParent(void)
{
    return nico_ResetPlayerHorseRidingControl(SCRGetFirstObj(gcGlobalVar + 0x2B4));
}

extern s32 nico_resetHorseRidingStatusForHorse(void *obj);

s32 demo_brige_resetHorseBridle(void)
{
    return nico_resetHorseRidingStatusForHorse(SCRGetFirstObj(gcGlobalVar + 0x2B4));
}

extern s32 *SkelFocusDef_PLAYER_HAND_A_L, *SkelFocusDef_PLAYER_HAND_A_R;
extern float D_40133210[], D_40133220[];
extern void nico_setHorseRidingStatusForHorseIndep(void *, void *, s32, float *, s32, float *);

void demo_bridge_setHorseBridle(void)
{
    void *p = SCRGetFirstObj(gcGlobalVar + 0x2B4);

    nico_setHorseRidingStatusForHorseIndep(p, SCRGetFirstObj(gcGlobalVar + 0x2B0), SkelFocusDef_PLAYER_HAND_A_L[2], D_40133210, SkelFocusDef_PLAYER_HAND_A_R[2], D_40133220);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", func_40045CE8);
s32 func_40045CE8(void)
{
    nico_ResetPlayerHorseRidingControl(SCRGetFirstObj(gcGlobalVar + 0x2B4));
    return createScriptObj((void *)st_unload_horse_char, 0, (s32)&rootPtn, 0x1000, 0, 1, 0, 1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", func_40045D38);
extern void gameflowSetPos(void *obj, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz);

void func_40045D38(void)
{
    gameflowSetPos(SCRGetFirstObj(gcGlobalVar + 0x2B0), 348.0f, -59.0f, -2047.0f, 0.0f, 0.0f, 0.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", func_40045D88);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0043_CreateBgmThread", func_40045E98);
