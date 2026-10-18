#include "common.h"

extern s32 rootPtn;
extern u8 gcGlobalVar[];
extern const char D_40132CC0[];
extern const char D_40132CD0[];
extern const char D_40132CE0[];
extern const char D_40132CF0[];
extern const char D_40132D08[];
extern f32 D_40130A60;
extern f32 D_40130A64;
extern s32 D_40130A68;
extern s64 D_40130A70;
extern s32 D_40130AE8;
extern f32 D_40130AC8;
extern s32 D_40130ACC;
extern f32 D_40130AE0;
extern s32 D_40130AB8;
extern s32 D_40130AD0;

void createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
s32 checkFadeParam(void *param);
void setFadeParam(void *param, s32 value);

void gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void func_400222E8(void);
void func_40022168(void);
void func_40022220(void);
void func_400221B8(void);
void func_40022270(void);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetGameTimeScaleRatio);
f32 GetGameTimeScaleRatio(void) {
    return *(f32*)(gcGlobalVar + 0x19C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", PauseAI);
void PauseAI(void) {
    *(s32*)(gcGlobalVar + 0x310) = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", ReleaseAI);
void ReleaseAI(void) {
    *(s32*)(gcGlobalVar + 0x310) = 0;
}

void SwitchPadAct(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", gcCreateScriptObj);
void gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6)
{
    createScriptObj(fn, a1, a2, a3, a4, a5, 0, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", _gcCreateChildScriptObj);
void _gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, void *a7)
{
    createScriptObj(fn, a1, a2, a3, a4, a5, a7, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", ChangeGameAnimeTimeScaleRatio);
void ChangeGameAnimeTimeScaleRatio(f32 a, f32 b)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 r;

    *(f32 *)(g + 0x1A8) = a;
    *(f32 *)(g + 0x1A4) = b;
    if (b == 0.0f) {
        *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
        *(f32 *)(g + 0x1A0) = a;
        r = ((*(u64 *)g << 8) >> 8) * (s64)(s32)(a * 256.0f);
        *(u64 *)(g + 0x148) = 0;
        *(u64 *)(g + 0x158) = r >> 8;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetCurrentGameAnimeTimeScaleRatio);
f32 GetCurrentGameAnimeTimeScaleRatio(void)
{
    return *(f32 *)((u8 *)&gcGlobalVar + 0x1A0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetGameAnimeTimeScaleRatio);
f32 GetGameAnimeTimeScaleRatio(void)
{
    return D_40130A64;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetPlayerControlButtonContext);
u8 *GetPlayerControlButtonContext(void)
{
    return (u8 *)&gcGlobalVar + 0x314;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getGameAnimeTimeScaleRatio);
void *getGameAnimeTimeScaleRatio(void)
{
    return &D_40130A60;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", RestoreDefaultGameAnimeTimeScaleRatio);
void RestoreDefaultGameAnimeTimeScaleRatio(void)
{
    D_40130A64 = 0.9f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", SetDefaultGameAnimeTimeScaleRatio);
void SetDefaultGameAnimeTimeScaleRatio(f32 ratio)
{
    D_40130A64 = ratio;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setGameAnimeTimeScaleRatio);
void setGameAnimeTimeScaleRatio(void)
{
    ChangeGameAnimeTimeScaleRatio(D_40130A64, 0.0f);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDummyCount);
s64 getDummyCount(void)
{
    return D_40130A70;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFrameRateMode);
void *getFrameRateMode(void)
{
    return &D_40130A68;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setFrameRateMode);
u64 iosGetTCount();
void func_40021EF0();
void setFrameRateMode(void)
{
    s64 *p = &D_40130A70;
    u64 t = iosGetTCount();

    *p = t;
    *(u64 *)&gcGlobalVar = t;
    func_40021EF0();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021D78);
u64 iosGetTCountExtension();
void func_40021440();
void FlushPadHistory();
void func_400216E8();
void func_40021D78(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    *(u64 *)(g + 0x10) = *(u64 *)(g + 0x100);
    *(u64 *)(g + 0x100) = iosGetTCountExtension();
    func_40021440();
    FlushPadHistory();
    func_400216E8();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021DB8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021E08);
extern u64 D_40130A80;
extern u64 gpfinishctr;
void func_40021E08(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    *(u64 *)(g + 0x20) = D_40130A80;
    *(u64 *)(g + 0x28) = iosGetTCountExtension();
    gpfinishctr += 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021E58);
void graphFrameBufferReInitialize();
void func_40021E58(void)
{
    graphFrameBufferReInitialize();
    D_40130A80 = iosGetTCountExtension();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setDefaultPlayerControlButton);
typedef struct { u8 b[0x28]; } PCBtn;
void setDefaultPlayerControlButton(u8 *a0)
{
    *(PCBtn *)((u8 *)&gcGlobalVar + 0x314) = **(PCBtn **)(a0 + 0x10);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021EF0);
void func_40021EF0(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 r;

    *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
    r = ((*(u64 *)g << 8) >> 8) * (s64)(s32)(*(f32 *)(g + 0x1A0) * 256.0f);
    *(u64 *)(g + 0x148) = 0;
    *(u64 *)(g + 0x158) = r >> 8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", initgcmaingp);
void initgcmaingp(void)
{
    gcCreateScriptObj(func_40022168, 0, &rootPtn, 0x1000, 0, 1, D_40132CD0);
    gcCreateScriptObj(func_40022220, 0, &rootPtn, 0x2000, 0, 10, D_40132CE0);
    gcCreateScriptObj(func_400221B8, 0, &rootPtn, 0x1000, 0, 11, D_40132CF0);
    gcCreateScriptObj(func_40022270, 0, &rootPtn, 0x1000, 0, 2, D_40132D08);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setLayerFade);
void setLayerFade(s32 value)
{
    D_40130ACC = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setFade);
void setFade(void)
{
    setFadeParam(&D_40130AB8, 0x1C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFade);
s32 getFade(void)
{
    return checkFadeParam(&D_40130AB8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFadeValue);
f32 getFadeValue(void)
{
    return D_40130AC8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBarSw);
void *getDemoBarSw(void)
{
    return &D_40130AE8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setDemoBar);
void setDemoBar(f32 a, f32 b)
{
    if (a != 0.0f) {
        SetDefaultGameAnimeTimeScaleRatio(1.0f);
        ChangeGameAnimeTimeScaleRatio(GetGameAnimeTimeScaleRatio(), 0.0f);
    } else {
        RestoreDefaultGameAnimeTimeScaleRatio();
        ChangeGameAnimeTimeScaleRatio(GetGameAnimeTimeScaleRatio(), 0.0f);
    }
    ((void (*)(void *, s32, f32, f32))setFadeParam)(&D_40130AD0, 0x19, a, b);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBar);
s32 getDemoBar(void)
{
    return checkFadeParam(&D_40130AD0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBarFade);
f32 getDemoBarFade(void)
{
    return 1.0f - D_40130AE0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022168);
void graphFrameInit(f32 t);
void InitLayoutObjMatrix();
void scrRun();
void func_40022168(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    for (;;) {
        *(u64 *)(g + 0x80) = iosGetTCountExtension();
        graphFrameInit(*(f32 *)(g + 0x180));
        InitLayoutObjMatrix(*(s32 *)(g + 0x1AC));
        *(u64 *)(g + 0x88) = iosGetTCountExtension();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400221B8);
void calcFadeParam();
void setFadeLayer();
void fadeScreen(f32 f);
void drawDemoBar(s32 a, f32 f);
void graphFrameFinish();
void func_400221B8(void)
{
    for (;;) {
        calcFadeParam(((u8 *)&D_40130AB8));
        setFadeLayer(*(s32 *)(((u8 *)&D_40130AB8) + 0x14));
        fadeScreen(*(f32 *)(((u8 *)&D_40130AB8) + 0x10));
        calcFadeParam(((u8 *)&D_40130AD0));
        drawDemoBar(0x40, *(f32 *)(((u8 *)&D_40130AD0) + 0x10));
        graphFrameFinish();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022220);
void windowDraw();
void func_40022220(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 a = 0;
    u64 b = 0;

    for (;;) {
        *(u64 *)(g + 0xE8) = a;
        *(u64 *)(g + 0xE0) = b;
        b = iosGetTCountExtension();
        windowDraw();
        a = iosGetTCountExtension();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022270);
void InitLightColMan();
void CreateLightColMan();
void TaskExecLightColMan();
void func_40022270(void)
{
    InitLightColMan();
    CreateLightColMan(&rootPtn);
    for (;;) {
        TaskExecLightColMan();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", initgcmain);
void initgcmain(void)
{
    gcCreateScriptObj(func_400222E8, 0, &rootPtn, 0x1000, 0, 1, D_40132CC0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400222E8);
void usbdevFrameInit();
void func_400222E8(void)
{
    scrRun();
    for (;;) {
        usbdevFrameInit();
        scrRun();
    }
}

/* NEARMISS-STUB constructor_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 97.2% cat=sched sub=- | 16 f32/s32 stores + 11 float literals (exact decimals, all const loads match); gcc schedules stores out of source order (13C before 138, EC/D0 groups, F4 before | attempts=1 */
void reset_nico_yaw_pitch_cntrl(u8 *p);
void GAMEUTIL_constructor_move_angle(u8 *p);
void constructor_nico_yaw_pitch_cntrl(u8 *a0)
{
    reset_nico_yaw_pitch_cntrl(a0);
    *(f32 *)(a0 + 0x70) = 1.0f;
    *(f32 *)(a0 + 0x78) = 1.0f;
    *(f32 *)(a0 + 0x80) = 1.39626324176788330078125f;
    *(f32 *)(a0 + 0x84) = -1.39626324176788330078125f;
    *(s32 *)(a0 + 0x6C) = 0;
    *(s32 *)(a0 + 0x74) = 0;
    *(s32 *)(a0 + 0x7C) = 0;
    GAMEUTIL_constructor_move_angle(a0 + 0x88);
    *(s32 *)(a0 + 0xA4) = 0;
    *(f32 *)(a0 + 0xA8) = 1.39626324176788330078125f;
    *(f32 *)(a0 + 0xAC) = -1.39626324176788330078125f;
    GAMEUTIL_constructor_move_angle(a0 + 0xB0);
    *(s32 *)(a0 + 0xCC) = 0;
    *(f32 *)(a0 + 0x138) = 1.0f;
    *(f32 *)(a0 + 0x13C) = 1.0f;
    *(f32 *)(a0 + 0xD8) = 0.872664511203765869140625f;
    *(f32 *)(a0 + 0xEC) = 0.0872664527f;
    *(f32 *)(a0 + 0xF0) = 0.1745329053f;
    *(f32 *)(a0 + 0xF4) = 0.523598730564117431640625f;
    *(f32 *)(a0 + 0xF8) = 0.698131620883941650390625f;
    *(f32 *)(a0 + 0xFC) = 0.3490658105f;
    *(f32 *)(a0 + 0x100) = 0.7999999523162841796875f;
    *(f32 *)(a0 + 0x120) = 1.483529567718505859375f;
    *(f32 *)(a0 + 0x124) = -1.483529567718505859375f;
    *(f32 *)(a0 + 0x128) = 1.5533428192138671875f;
    *(f32 *)(a0 + 0x12C) = -1.5533428192138671875f;
    *(f32 *)(a0 + 0xD0) = 0.0872664527f;
    *(f32 *)(a0 + 0xD4) = 0.1745329053f;
    *(f32 *)(a0 + 0xDC) = 0.698131620883941650390625f;
    *(f32 *)(a0 + 0xE0) = 0.3490658105f;
    *(f32 *)(a0 + 0xE4) = 0.7999999523162841796875f;
    *(s32 *)(a0 + 0xE8) = 0;
    *(s32 *)(a0 + 0x10C) = 0;
    *(s32 *)(a0 + 0x108) = 0;
    *(s32 *)(a0 + 0x104) = 0;
    *(s32 *)(a0 + 0x110) = 0;
    *(s32 *)(a0 + 0x114) = 0;
    *(s32 *)(a0 + 0x118) = 0;
    *(s32 *)(a0 + 0x11C) = 0;
    *(s32 *)(a0 + 0x134) = 0;
    *(s32 *)(a0 + 0x130) = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", constructor_nico_yaw_pitch_cntrl);

/* NEARMISS-STUB func_400224A0 */
#if 0 /* NEARMISS 80.4% cat=cse-hoist sub=- | 0.0f hoisted to callee-saved f24 across calls (ours frame 0x50, s1/s2 flag regs; expected rematerialises zero per block, flags in v0/v1, frame 0x30); float lite | attempts=1 */
f32 GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(f32 a, f32 b);
f32 GAMEUTIL_increase_yaw(f32 a, f32 b, s32 c);
s32 GAMEUTIL_is_between_yaw_and_yaw(f32 a, f32 b, f32 c);
f32 func_40023CF0(f32 a, f32 b, f32 c, f32 d, f32 e, f32 g, f32 h, void *p, void *q);

void func_400224A0(f32 f, u8 *obj)
{
    f32 ratio = *(f32 *)(obj + 0x5C);
    f32 hi = *(f32 *)(obj + 0x80);
    f32 lo = *(f32 *)(obj + 0x84);
    f32 r;
    f32 t;
    f32 res;
    s32 active = 0;
    s32 sel = 0;

    if (*(s32 *)(obj + 0x108) == 1 || *(s32 *)(obj + 0x10C) == 1) {
        active = 1;
    }
    if (active == 1) {
        r = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(*(f32 *)(obj + 0x110), ratio);
        if (0.0f <= r) {
            sel = 1;
        }
        if (sel == 1) {
            if (*(s32 *)(obj + 0x108) == 1) {
                t = GAMEUTIL_increase_yaw(ratio, *(f32 *)(obj + 0x80), 0);
                if (GAMEUTIL_is_between_yaw_and_yaw(t, *(f32 *)(obj + 0x110), *(f32 *)(obj + 0x114)) == 0) {
                    hi = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(ratio, *(f32 *)(obj + 0x114));
                    if (hi < 0.0f) {
                        hi = 0.0f;
                    }
                }
            }
        } else {
            if (*(s32 *)(obj + 0x10C) == 1) {
                t = GAMEUTIL_increase_yaw(ratio, *(f32 *)(obj + 0x84), 0);
                if (GAMEUTIL_is_between_yaw_and_yaw(t, *(f32 *)(obj + 0x110), *(f32 *)(obj + 0x118)) == 0) {
                    lo = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(ratio, *(f32 *)(obj + 0x118));
                    if (0.0f < lo) {
                        lo = 0.0f;
                    }
                }
            }
        }
    }
    res = func_40023CF0(*(f32 *)(obj + 0x6C), *(f32 *)(obj + 0x70), f, *(f32 *)(obj + 0x40),
                        *(f32 *)(obj + 0x7C), hi, lo, obj + 0x3C, obj + 0x88);
    *(s32 *)(obj + 0x38) = 0;
    *(f32 *)(obj + 0x40) = res;
    *(s32 *)(obj + 0x34) = 0;
    if (hi - 0.0174532908f <= res) {
        *(s32 *)(obj + 0x34) = 1;
    } else if (res <= lo + 0.0174532908f) {
        *(s32 *)(obj + 0x38) = 1;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400224A0);

/* NEARMISS-STUB func_40022668 */
#if 0 /* NEARMISS 75.5% cat=branch-layout sub=- | bool-materialised active/sel flags (addiu v0/v1=1 after call), shared clamp tail bc1tl, frame 0x60 vs 0x50 (extra f24/s2), arg regs ok | attempts=1 */
f32 GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(f32 a, f32 b);
f32 GAMEUTIL_get_dist_ratio(f32 v, f32 lo, f32 hi);
f32 GAMEUTIL_get_cur_velocity_move_angle(void *p);
f32 powf(f32, f32);
f32 func_40023E40(u8 *obj, f32 f);
f32 func_40023EE8(u8 *obj, f32 f);
f32 func_40024008(f32, f32, f32, f32, f32, f32, f32, f32, void *, s32, s32, s32, s32, s32, f32, f32);
f32 update_base_yaw_nico_yaw_pitch_cntrl(f32 v, u8 *obj);

void func_40022668(f32 f, u8 *obj, f32 *vec)
{
    f32 ratio = *(f32 *)(obj + 0x5C);
    f32 ang = 0.0f;
    f32 scale = 1.0f;
    s32 active = 0;
    s32 sel;
    f32 r;
    f32 vel;
    f32 res;

    if (*(s32 *)(obj + 0x108) == 1 || *(s32 *)(obj + 0x10C) == 1) {
        active = 1;
    }
    if (active == 1) {
        r = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(*(f32 *)(obj + 0x110), ratio);
        sel = 0;
        if (0.0f <= r) {
            sel = 1;
        }
        if (sel == 1) {
            if (*(s32 *)(obj + 0x108) == 1) {
                r = func_40023E40(obj, ratio);
                ang = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(ratio, r);
                if (ang < 0.0f) {
                    ang = 0.0f;
                }
            }
        } else {
            if (*(s32 *)(obj + 0x10C) == 1) {
                r = func_40023EE8(obj, ratio);
                ang = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(ratio, r);
                if (0.0f < ang) {
                    ang = 0.0f;
                }
            }
        }
        if (ang != 0.0f) {
            f32 a = ang;

            if (ang < 0.0f) {
                a = -ang;
            }
            scale = powf(GAMEUTIL_get_dist_ratio(a, 0.0f, *(f32 *)(obj + 0xE0)), *(f32 *)(obj + 0xE4));
        }
    }
    vel = GAMEUTIL_get_cur_velocity_move_angle(obj + 0x88);
    res = func_40024008(*(f32 *)(obj + 0x70), f, *(f32 *)(obj + 0x54), vec[0], vec[1], vec[2], vec[3],
                        vel, (void *)(obj + 0x54), *(s32 *)(obj + 0xCC), *(s32 *)(obj + 0x30),
                        *(s32 *)(obj + 0x34), *(s32 *)(obj + 0x38), *(s32 *)(obj + 0x3C), ang, scale);
    *(f32 *)(obj + 0x58) = res;
    res = update_base_yaw_nico_yaw_pitch_cntrl(res, obj);
    *(f32 *)(obj + 0x58) = res;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022668);

/* NEARMISS-STUB func_40022820 */
#if 0 /* NEARMISS 82.0% cat=regalloc sub=- | 0.0 held in callee-saved f22 across calls, F in f23; needs rule-13-forbidden local zero | attempts=1 */
f32 func_40023F88(f32 pitch);
f32 GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(f32 pitch1, f32 pitch2);
f32 func_40023FC8(u8 *obj, f32 pitch);
f32 GAMEUTIL_get_dist_ratio(f32 v, f32 lo, f32 hi);
f32 powf(f32, f32);
f32 GAMEUTIL_get_cur_velocity_move_angle(void *p);
f32 func_40024008(f32, f32, f32, f32, f32, f32, f32, f32, void *, s32, s32, s32, s32, s32, f32, f32);
f32 update_base_pitch_nico_yaw_pitch_cntrl(f32 v, u8 *obj);

void func_40022820(f32 f, u8 *obj, u8 *p)
{
    f32 pitch = *(f32 *)(obj + 0x68);
    f32 t1;
    f32 t2;
    f32 x;
    f32 ax;
    f32 r;
    f32 pw;
    f32 v;
    f32 res;
    f32 zero = 0.0f;

    t1 = GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(pitch, func_40023F88(pitch));
    t2 = GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(pitch, func_40023FC8(obj, pitch));
    if (t1 < zero) {
        t1 = 0.0f;
    }
    if (zero < t2) {
        t2 = 0.0f;
    }
    x = t1;
    if (!(t1 <= -t2)) {
        x = t2;
    }
    ax = x;
    if (x < zero) {
        ax = -x;
    }
    r = GAMEUTIL_get_dist_ratio(ax, zero, *(f32 *)(obj + 0xFC));
    pw = powf(r, *(f32 *)(obj + 0x100));
    v = GAMEUTIL_get_cur_velocity_move_angle(obj + 0xB0);
    res = func_40024008(*(f32 *)(obj + 0x78), f, *(f32 *)(obj + 0x60),
                        *(f32 *)(p + 0x10), *(f32 *)(p + 0x14), *(f32 *)(p + 0x18), *(f32 *)(p + 0x1C),
                        v, obj + 0x60, *(s32 *)(obj + 0xE8), *(s32 *)(obj + 0x30),
                        *(s32 *)(obj + 0x44), *(s32 *)(obj + 0x48), *(s32 *)(obj + 0x4C),
                        x, pw);
    *(f32 *)(obj + 0x64) = res;
    res = update_base_pitch_nico_yaw_pitch_cntrl(res, obj);
    *(f32 *)(obj + 0x64) = res;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022820);
