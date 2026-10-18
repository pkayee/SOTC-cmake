#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40020F98);
extern s32 gcGlobalVar;
extern s32 rootPtn;
u64 iosGetTCountExtension();
void doit_wind_manager(f32 t);
void scrRun();
void func_40020F98(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    for (;;) {
        *(u64 *)(g + 0xA0) = iosGetTCountExtension();
        doit_wind_manager(*(f32 *)(g + 0x180));
        *(u64 *)(g + 0xA8) = iosGetTCountExtension();
        scrRun();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40020FE0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", getCullingScreenSize);
extern s32 D_40130A50;
s32 *getCullingScreenSize(void)
{
    return &D_40130A50;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", getScissoringScreenSize);
extern s32 D_40130A54;
s32 *getScissoringScreenSize(void)
{
    return &D_40130A54;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", getPlayerAliveInPauseFlag);
extern s32 D_40130A58;
s32 *getPlayerAliveInPauseFlag(void)
{
    return &D_40130A58;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021080);
void *get_main_cameraman(void);
s32 get_camera_obj(void *cam);
s32 get_clip_screen(s32 obj);
void set_scissor_screen_size(s32 s, s32 idx, s32 x, s32 y);
void update_clip_screen(s32 s);
void doit_cameraman_manager(f32 value);
void func_40021080(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    f32 t;
    s32 clip;

    for (;;) {
        *(u64 *)(g + 0x60) = iosGetTCountExtension();
        t = *(f32 *)(g + 0x180);
        clip = get_clip_screen(get_camera_obj(get_main_cameraman()));
        set_scissor_screen_size(clip, 0, D_40130A50, D_40130A50);
        set_scissor_screen_size(clip, 1, D_40130A54, D_40130A54);
        update_clip_screen(clip);
        doit_cameraman_manager(t);
        *(u64 *)(g + 0x68) = iosGetTCountExtension();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021128);
void *GAMEUTIL_get_boss_obj();
void GAMEUTIL_set_auto_get_flag_boss_interest_position(s32 f);
void func_40021128(void)
{
    for (;;) {
        if (GAMEUTIL_get_boss_obj() == NULL) {
            GAMEUTIL_set_auto_get_flag_boss_interest_position(1);
        }
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", nico_defaultAI);
void nico_defaultAI(void)
{
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", nico_volatileDefaultAI);
void nico_volatileDefaultAI(void)
{
    for (;;) {
        scrRun();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", nico_deleteMyself);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", nico_ResetScriptCtrlAI);
void *isysGetThisSubThread();
void CharaCtrlResetAllScriptCtrlStatus();
void nico_ResetScriptCtrlAI(void)
{
    for (;;) {
        CharaCtrlResetAllScriptCtrlStatus(isysGetThisSubThread());
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_400211D0);
void *GetScriptPriorityGroup();
void func_40020730();
void updatePathInfo();
void func_400211D0(void)
{
    void *p = GetScriptPriorityGroup(4);
    u8 *g = (u8 *)&gcGlobalVar;

    for (;;) {
        func_40020730(p);
        updatePathInfo();
        *(u64 *)(g + 0x70) = iosGetTCountExtension();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021220);
void func_40021220(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    for (;;) {
        *(u64 *)(g + 0x78) = iosGetTCountExtension();
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", st_layoutframetask);
void st_layoutframetask(void)
{
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021268);
void InitFogColMan();
void CreateFogColMan();
void ExecFogColMan();
void *get_main_cameraman_camera_obj();
void func_40021268(void)
{
    InitFogColMan();
    CreateFogColMan(&rootPtn);
    for (;;) {
        ExecFogColMan(get_main_cameraman_camera_obj());
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", initgcchartest);
extern s32 D_40132C98;
void func_40020948();
s32 gcCreateScriptObj();
s32 initgcchartest(void)
{
    return gcCreateScriptObj(func_40020948, 0, *(s32 *)((u8 *)&gcGlobalVar + 0x308), 0x10000, 0, 1, &D_40132C98);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_400212E8);
void isysRequestDeleteObj();
void func_400212E8(void *a0)
{
    isysRequestDeleteObj(a0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021300);
extern s32 D_40130A68;
extern u64 D_40130A70;
extern s32 D_40130A78;
void func_40021300(void)
{
    if (D_40130A68 != 2) {
        D_40130A70 = (u64)((f32)D_40130A70 + 4999999.5f);
        return;
    }
    if (D_40130A78 != 0) {
        D_40130A70 = (u64)((f32)D_40130A70 + 4999999.5f);
    } else {
        D_40130A70 = (u64)((f32)D_40130A70 + 14999999.0f);
    }
    D_40130A78 = (D_40130A78 == 0);
}

/* NEARMISS-STUB func_40021440 */
#if 0 /* NEARMISS 94.27% cat=regalloc sub=- | bnezl delay slot holds dead li v0,1 in target (ours lui v0); s2 hi-part kept live across calls in target; f-reg order target f1=0x178 f2=0x188 f0=0x168 vs ours  | attempts=1 */
s64 iosGetTCount();
f32 iosGetSecondFromTCount(u64 arg0);
u64 __muldi3(u64 a, s64 b);
void func_40021440(void)
{
    u8 *g;
    s64 t;
    u64 r;
    f32 f;

    func_40021300();
    if (D_40130A68 == 0) {
        t = iosGetTCount();
    } else {
        t = D_40130A70;
    }
    g = (u8 *)&gcGlobalVar;
    *(s64 *)(g + 0x110) = *(s64 *)(g + 0x108);
    *(s64 *)(g + 0x130) = *(s64 *)(g + 0x128);
    *(s64 *)(g + 0x150) = *(s64 *)(g + 0x148);
    *(s64 *)g = t;
    if (*(s32 *)(g + 0x1AC) != 0) {
        *(u64 *)(g + 0x138) = ((u64)t << 8) >> 8;
        *(u64 *)(g + 0x128) = 0;
        r = __muldi3(((u64)t << 8) >> 8, (s32)(*(f32 *)(g + 0x1A0) * 256.0f));
        *(u64 *)(g + 0x148) = 0;
        *(u64 *)(g + 0x158) = r >> 8;
    } else {
        *(u64 *)(g + 0x128) = (((u64)t << 8) >> 8) - *(u64 *)(g + 0x138);
        r = __muldi3(((u64)t << 8) >> 8, (s32)(*(f32 *)(g + 0x1A0) * 256.0f));
        *(u64 *)(g + 0x148) = (r >> 8) - *(u64 *)(g + 0x158);
    }
    g = (u8 *)&gcGlobalVar;
    *(s64 *)(g + 0x108) = t - *(s64 *)(g + 0x118);
    *(f32 *)(g + 0x17C) = *(f32 *)(g + 0x178);
    *(f32 *)(g + 0x18C) = *(f32 *)(g + 0x188);
    *(f32 *)(g + 0x16C) = *(f32 *)(g + 0x168);
    *(f32 *)(g + 0x178) = iosGetSecondFromTCount(*(s64 *)(g + 0x128) + *(s64 *)(g + 0x140));
    *(f32 *)(g + 0x188) = iosGetSecondFromTCount(*(s64 *)(g + 0x148) + *(s64 *)(g + 0x160));
    *(f32 *)(g + 0x168) = iosGetSecondFromTCount(*(s64 *)(g + 0x108) + *(s64 *)(g + 0x120));
    *(f32 *)(g + 0x180) = iosGetSecondFromTCount(*(s64 *)(g + 0x128) - *(s64 *)(g + 0x130));
    *(f32 *)(g + 0x190) = iosGetSecondFromTCount(*(s64 *)(g + 0x148) - *(s64 *)(g + 0x150));
    f = iosGetSecondFromTCount(*(s64 *)(g + 0x108) - *(s64 *)(g + 0x110));
    *(f32 *)(g + 0x170) = f;
    *(f32 *)(g + 0x174) = 1.0f / f;
    *(f32 *)(g + 0x184) = 1.0f / *(f32 *)(g + 0x180);
    *(f32 *)(g + 0x194) = 1.0f / *(f32 *)(g + 0x190);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021440);

/* NEARMISS-STUB func_40021638 */
#if 0 /* NEARMISS 94.0% cat=branch-layout sub=- | orig lw v0+bnez with dead addiu v1 in delay slot; ours lw v1+bnezl | attempts=1 */
/* GAMECORE.XFF c0009 func_40021638 best C 94.77%, not live */
extern s32 D_40130A68;
extern s64 D_40130A70;
s64 iosGetTCount();
f32 iosGetSecondFromTCount(u64 arg0);
void func_40021300();
void func_40021440();
void func_40021638(void)
{
    u8 *g;
    s64 t;

    func_40021300();
    if (D_40130A68 == 0) {
        t = iosGetTCount();
    } else {
        t = D_40130A70;
    }
    g = (u8 *)&gcGlobalVar;
    *(s64 *)(g + 0x140) = t;
    *(s64 *)(g + 0x120) = t;
    *(s64 *)(g + 0x158) = t;
    *(s64 *)(g + 0x138) = t;
    *(s64 *)(g + 0x118) = t;
    *(s64 *)(g + 0x148) = 0;
    *(s64 *)(g + 0x128) = 0;
    *(s64 *)(g + 0x108) = 0;
    *(f32 *)(g + 0x178) = iosGetSecondFromTCount(t);
    *(f32 *)(g + 0x188) = iosGetSecondFromTCount(*(s64 *)(g + 0x148) + *(s64 *)(g + 0x160));
    *(f32 *)(g + 0x168) = iosGetSecondFromTCount(*(s64 *)(g + 0x108) + *(s64 *)(g + 0x120));
    func_40021440();
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021638);

/* NEARMISS-STUB func_400216E8 */
#if 0 /* NEARMISS 77.3% cat=regalloc sub=f-reg order a8/a0/zero; delay-slot sd ra | fpu regs f3/f5/f4 in target vs f4/f1/f8 ours; sd ra in bc1f delay slot (target: prologue); target mtc1 zero before lui; branch shape d>0 path matches | attempts=1 */
u64 __muldi3(u64 a, s64 b);
void func_400216E8(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    f32 a8;
    f32 a0;
    f32 a4;
    f32 d;
    f32 v;
    f32 x;
    u64 t;

    a8 = *(f32 *)(g + 0x1A8);
    a0 = *(f32 *)(g + 0x1A0);
    d = a8 - a0;
    a4 = *(f32 *)(g + 0x1A4);
    if (d == 0.0f) {
        *(f32 *)(g + 0x1A4) = 0.0f;
    } else {
        v = a0 + a4 * *(f32 *)(g + 0x180);
        x = v;
        if (d > 0.0f) {
            if (a4 <= 0.0f) {
                x = a8;
            } else if (a8 < v) {
                x = a8;
            }
        } else {
            if (0.0f <= a4) {
                x = a8;
            } else if (v < a8) {
                x = a8;
            }
        }
        *(f32 *)(g + 0x1A0) = x;
        *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
        t = __muldi3((*(u64 *)g << 8) >> 8, (s32)(x * 256.0f));
        *(u64 *)(g + 0x148) = 0;
        *(u64 *)(g + 0x158) = t >> 8;
    }
}
#endif
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_400216E8);
extern s32 gcGlobalVar;
void func_400216E8(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    f32 tgt = *(f32 *)(g + 0x1A8);
    f32 cur = *(f32 *)(g + 0x1A0);
    f32 diff = tgt - cur;
    f32 rate = *(f32 *)(g + 0x1A4);
    f32 n;
    u8 *h;

    if (diff == 0.0f) {
        *(f32 *)(g + 0x1A4) = 0.0f;
    } else {
        n = cur + rate * *(f32 *)(g + 0x180);
        if (diff > 0.0f) {
            if (rate <= 0.0f || n > tgt) {
                n = tgt;
            }
        } else {
            if (rate >= 0.0f || n < tgt) {
                n = tgt;
            }
        }
        h = (u8 *)&gcGlobalVar;
        *(u64 *)(h + 0x160) = *(u64 *)(h + 0x148) + *(u64 *)(h + 0x160);
        *(f32 *)(h + 0x1A0) = n;
        *(u64 *)(h + 0x158) = ((u64)(((*(u64 *)h << 8) >> 8) * (s32)(n * 256.0f))) >> 8;
        *(u64 *)(h + 0x148) = 0;
    }
}

/* NEARMISS-STUB func_400217C8 */
#if 0 /* NEARMISS 98.0% cat=regalloc sub=- | v0/v1 swap of masked value vs sum; 0x138/0x160 store order | attempts=1 */
// func_400217C8 GAMECORE.XFF c0009 best C (98.62%, not live)
void func_400217C8(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 v;

    *(u64 *)(g + 0x140) = *(u64 *)(g + 0x128) + *(u64 *)(g + 0x140);
    v = (*(u64 *)g << 8) >> 8;
    *(u64 *)(g + 0x138) = v;
    *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
    *(u64 *)(g + 0x128) = 0;
    v = v * (s64)(s32)(*(f32 *)(g + 0x1A0) * 256.0f);
    *(u64 *)(g + 0x148) = 0;
    *(u64 *)(g + 0x158) = v >> 8;
}
#endif
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_400217C8);
extern s32 gcGlobalVar;
void func_400217C8(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 t;

    *(u64 *)(g + 0x140) = *(u64 *)(g + 0x128) + *(u64 *)(g + 0x140);
    t = (*(u64 *)g << 8) >> 8;
    *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
    *(u64 *)(g + 0x128) = 0;
    *(u64 *)(g + 0x138) = t;
    *(u64 *)(g + 0x158) = (t * (s32)(*(f32 *)(g + 0x1A0) * 256.0f)) >> 8;
    *(u64 *)(g + 0x148) = 0;
}

/* NEARMISS-STUB func_40021850 */
#if 0 /* NEARMISS 87.2% cat=regalloc sub=- | 4 isysInitGroup loops: target ptr s0/counter s1, ours ptr s1/counter s2; target re-materialises gcGlobalVar base via lui s0 after loop1 (ours folds %hi(+0x228)) | attempts=1 */
void isysInitGroup(u8 *);
void InitObjectManagerResourceInfo(u8 *p);
extern u64 gpfinishctr;
void func_40021638(void);
void func_40021850(void)
{
    s32 n;
    u8 *p;
    u8 *q;
    u64 t;

    p = (u8 *)&gcGlobalVar + 0x228;
    n = 0x11;
    do {
        n--;
        isysInitGroup(p);
        p += 4;
    } while (n >= 0);

    t = iosGetTCountExtension();
    *(u64 *)((u8 *)&gcGlobalVar + 0x8) = t;
    q = (u8 *)&gcGlobalVar + 0x8;
    p = (u8 *)&gcGlobalVar + 0x10;
    n = 0xE;
    do {
        t = *(u64 *)q;
        *(u64 *)p = t;
        *(u64 *)(p + 0x8) = t;
        n--;
        p += 0x10;
    } while (n >= 0);

    *(f32 *)((u8 *)&gcGlobalVar + 0x1A0) = 1.0f;
    gpfinishctr = 0;
    *(f32 *)((u8 *)&gcGlobalVar + 0x19C) = 1.0f;
    *(s32 *)((u8 *)&gcGlobalVar + 0x1AC) = 0;
    *(s32 *)((u8 *)&gcGlobalVar + 0x198) = 0;
    *(u64 *)((u8 *)&gcGlobalVar + 0x1B0) = 0;
    func_40021638();

    *(s32 *)((u8 *)&gcGlobalVar + 0x310) = 0;
    *(s32 *)((u8 *)&gcGlobalVar + 0x30C) = -1;
    isysInitGroup((u8 *)&gcGlobalVar + 0x270);
    isysInitGroup((u8 *)&gcGlobalVar + 0x274);
    isysInitGroup((u8 *)&gcGlobalVar + 0x278);
    isysInitGroup((u8 *)&gcGlobalVar + 0x280);
    isysInitGroup((u8 *)&gcGlobalVar + 0x284);
    isysInitGroup((u8 *)&gcGlobalVar + 0x27C);
    InitObjectManagerResourceInfo((u8 *)&gcGlobalVar + 0x1C8);

    p = (u8 *)&gcGlobalVar + 0x288;
    n = 7;
    do {
        n--;
        isysInitGroup(p);
        p += 4;
    } while (n >= 0);

    p = (u8 *)&gcGlobalVar + 0x2EC;
    n = 3;
    do {
        n--;
        isysInitGroup(p);
        p += 4;
    } while (n >= 0);

    isysInitGroup((u8 *)&gcGlobalVar + 0x2FC);
    isysInitGroup((u8 *)&gcGlobalVar + 0x300);
    isysInitGroup((u8 *)&gcGlobalVar + 0x304);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", func_40021850);

/* NEARMISS-STUB initgc */
#if 0 /* NEARMISS 93.4% cat=regalloc sub=- | 56-bit mask as (x<<8)>>8 scheduled late; with shift form fv0/fv1 swapped on 256.0 mul (regalloc); mask-as-and form 92.9 with dsll placed after float stores and  | attempts=1 */
extern u8 SH_StageDataDEFAULT[];
extern u8 D_40130A88[];
extern u8 D_40130A98[];
extern u8 D_40130AA8[];
extern f32 D_40130A64;
void EntryPadHistory(void);
void execScript(void);
void func_40021D78(void);
void func_40021DB8(void);
void func_40021E58(void);
void func_40021E08(void);
void func_40021850(void);
void iosInitRandom(f32 seed);
void gameModeInit(void);
void initmanager(void);
void sheetMgrCreateStageIndexSkipInfo(s32 a0);
void usbdevInit(void);
void InitPadHistory(void);
void initMcManager(void *a0, void *a1, void *a2);
void graphInit(void);
void optionFlagInit(void);
void initScriptSystem(void);
void iosSetScreenEnv(s32, s32, s32, s32);
void iosSetISchedulerSubthreadTask(void (*f)(void));
void iosSetIStartFunc(void (*f)(void));
void iosSetIFinishFunc(void (*f)(void));
void iosSetDlTransFunc(void (*f)(void));
void iosSetGpFinishFunc(void (*f)(void));
void iosSetIVSyncMode(s32 mode);
void iosPadEntryTickFunc(void (*arg0)(void));
s64 __muldi3(s64 a, s64 b);
void initgc(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    u64 t;
    u64 x;

    *(s32 *)(g + 0x308) = (s32)&rootPtn;
    iosInitRandom(9.43559933f);
    gameModeInit();
    initmanager();
    sheetMgrCreateStageIndexSkipInfo(*(s32 *)(SH_StageDataDEFAULT + 0xC));
    usbdevInit();
    InitPadHistory();
    initMcManager(D_40130AA8, D_40130A88, D_40130A98);
    func_40021850();
    *(s64 *)(g + 0x160) = *(s64 *)(g + 0x148) + *(s64 *)(g + 0x160);
    *(f32 *)(g + 0x1A8) = D_40130A64;
    *(f32 *)(g + 0x1A0) = D_40130A64;
    *(s32 *)(g + 0x1A4) = 0;
    x = *(u64 *)g << 8;
    t = __muldi3(x >> 8, (s32)(D_40130A64 * 256.0f));
    *(s64 *)(g + 0x148) = 0;
    *(u64 *)(g + 0x158) = t >> 8;
    graphInit();
    optionFlagInit();
    initScriptSystem();
    iosSetScreenEnv(0x200, 0x1C0, 0x200, 0x1C0);
    iosSetISchedulerSubthreadTask(execScript);
    iosSetIStartFunc(func_40021D78);
    iosSetIFinishFunc(func_40021DB8);
    iosSetDlTransFunc(func_40021E58);
    iosSetGpFinishFunc(func_40021E08);
    iosSetIVSyncMode(0);
    iosPadEntryTickFunc(EntryPadHistory);
}
#endif
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", initgc);
extern s32 gcGlobalVar;
extern s32 rootPtn;
extern u8 SH_StageDataDEFAULT[];
extern f32 D_40130A64;
extern s32 D_40130AA8;
extern s32 D_40130A88;
extern s32 D_40130A98;
void iosInitRandom(f32 seed);
void gameModeInit(void);
void initmanager(void);
void sheetMgrCreateStageIndexSkipInfo(s32 n);
void usbdevInit(void);
void InitPadHistory(void);
void initMcManager(s32 *a, s32 *b, s32 *c);
void func_40021850(void);
void graphInit(void);
void optionFlagInit(void);
void initScriptSystem(void);
void iosSetScreenEnv(s32 w, s32 h, s32 dw, s32 dh);
void iosSetISchedulerSubthreadTask(void *f);
void iosSetIStartFunc(void *f);
void iosSetIFinishFunc(void *f);
void iosSetDlTransFunc(void *f);
void iosSetGpFinishFunc(void *f);
void iosSetIVSyncMode(s32 m);
void iosPadEntryTickFunc(void *f);
void execScript();
void func_40021D78();
void func_40021DB8();
void func_40021E58();
void func_40021E08();
void EntryPadHistory();
void initgc(void)
{
    u8 *g = (u8 *)&gcGlobalVar;
    f32 f;

    *(s32 *)(g + 0x308) = (s32)&rootPtn;
    iosInitRandom(9.43559933f);
    gameModeInit();
    initmanager();
    sheetMgrCreateStageIndexSkipInfo(*(s32 *)(SH_StageDataDEFAULT + 0xC));
    usbdevInit();
    InitPadHistory();
    initMcManager(&D_40130AA8, &D_40130A88, &D_40130A98);
    func_40021850();
    f = D_40130A64;
    *(u64 *)(g + 0x160) = *(u64 *)(g + 0x148) + *(u64 *)(g + 0x160);
    *(f32 *)(g + 0x1A8) = f;
    *(s32 *)(g + 0x1A4) = 0;
    *(f32 *)(g + 0x1A0) = f;
    *(u64 *)(g + 0x158) = (((*(u64 *)g << 8) >> 8) * (s32)(f * 256.0f)) >> 8;
    *(u64 *)(g + 0x148) = 0;
    graphInit();
    optionFlagInit();
    initScriptSystem();
    iosSetScreenEnv(0x200, 0x1C0, 0x200, 0x1C0);
    iosSetISchedulerSubthreadTask(execScript);
    iosSetIStartFunc(func_40021D78);
    iosSetIFinishFunc(func_40021DB8);
    iosSetDlTransFunc(func_40021E58);
    iosSetGpFinishFunc(func_40021E08);
    iosSetIVSyncMode(0);
    iosPadEntryTickFunc(EntryPadHistory);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", PauseGame);
void func_400217C8();
void PauseGame(s32 a0)
{
    u8 *g = (u8 *)&gcGlobalVar;

    *(s32 *)(g + 0x1AC) |= a0;
    func_400217C8();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", ReleaseGame);
void ReleaseGame(s32 a0)
{
    u8 *g = (u8 *)&gcGlobalVar;

    *(s32 *)(g + 0x1AC) &= ~a0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", ChangeGameTimeScale);
void ChangeGameTimeScale(s32 a0)
{
    *(s32 *)((u8 *)&gcGlobalVar + 0x198) = a0;
    func_400217C8();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0009_func_40020F98", ChangeGameTimeScaleRatio);
void ChangeGameTimeScaleRatio(f32 a0)
{
    *(f32 *)((u8 *)&gcGlobalVar + 0x19C) = a0;
    func_400217C8();
}
