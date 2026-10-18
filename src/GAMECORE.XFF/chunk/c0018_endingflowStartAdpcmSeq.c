#include "common.h"

extern s32 D_40130C58;
extern u8 D_401FC738[];
extern f32 D_40130C64;
extern s32 D_40130C68;
extern s32 D_40130C6C;
extern s32 D_40130C70;
extern s32 D_40130C74;
extern s32 ScrIntrDef_SCREEN_FADEIN;
extern s32 ScrIntrDef_SCREEN_FADEOUT;
void bgmStop(s32 id, s32 a1, f32 t);
void *memset(void *d, s32 c, u32 n);
void setFade(f32 a, f32 b);
s32 getFade();
void sheetMgrSetNoWaitMode();
void PauseGame();
void ReleaseGame();
void scriptIntrSignal();
void setFadeColor();
void fruitsFlagSet();
u8 *GetScrLwsOriClass();
s32 fruitsFlagChk();
void isysRequestDeleteObj();

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", endingflowStartAdpcmSeq);

extern s32 D_401FC780;

void endingflowTickAdpcmSeq(s32 a0)
{
    D_401FC780 = a0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", endingflowEndAdpcmSeq);
void endingflowEndAdpcmSeq(s32 a0)
{
    u8 *p;
    s32 i;

    D_40130C58 = 0;
    if (a0 != 0) {
        p = D_401FC738;
        for (i = 2; i >= 0; i--) {
            if (*(s32 *)(p + 8) != 0) {
                bgmStop(*(s32 *)(p + 8), 0, 100.0f);
                memset(p, 0, 0x18);
            }
            p += 0x18;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", endingflowDemoEnd);

extern s32 endingFlag;

void endingflowDemoEnd(void)
{
    endingFlag |= 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", endingflowDecPlayerHpPersent);

f32 getPlayerHp(void);
void setPlayerHp(f32 val);

void endingflowDecPlayerHpPersent(f32 scale)
{
    f32 hp = getPlayerHp();

    setPlayerHp(hp * scale);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", endingflowSetTimePlayerHpMax);

f32 getPlayerMaxHp(void);
extern f32 D_40130C54;

void endingflowSetTimePlayerHpMax(f32 scale)
{
    f32 maxHp = getPlayerMaxHp();
    f32 hp = getPlayerHp();

    D_40130C54 = (maxHp - hp) / scale;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", func_40029200);

void func_40029200(s32 a0, s32 a1, s32 a2, s32 *a3, s32 *t0)
{
    t0[1] = t0[1] + 1;
    *a3 = -2;
}

void *isysGetThisSubThread(void);
void scrInit(void *thread);
u8 *SCRGetFirstObj(void *table);
void CharaCtrlSetOutsideScriptCtrlStatus(void *obj, s32 n);
void scrRun(void);
extern u8 gcGlobalVar[];
extern u8 *ScriptCtrlDef_SCRPlayerNoWeaponchange;

void func_40029218(void)
{
    u8 *obj;

    scrInit(isysGetThisSubThread());
    while (1)
    {
        obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
        if (obj != NULL)
        {
            CharaCtrlSetOutsideScriptCtrlStatus(obj, *(s32 *)(ScriptCtrlDef_SCRPlayerNoWeaponchange + 4));
        }
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeTickProc);
void fadeTickProc(void)
{
    switch (D_40130C68) {
    case 0:
        break;
    case 100:
        setFade(1.0f, D_40130C64);
        D_40130C68 = D_40130C68 + 1;
        sheetMgrSetNoWaitMode(1);
    case 101:
        if (getFade() == 0) {
            D_40130C68 = 0;
            D_40130C6C |= 2;
        }
        break;
    case 200:
        setFade(0.0f, D_40130C64);
        D_40130C68 = D_40130C68 + 1;
    case 201:
        if (getFade() == 0) {
            D_40130C68 = 0;
            D_40130C6C |= 8;
            sheetMgrSetNoWaitMode(0);
        }
        break;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", initFadeParam);

extern u8 gcGlobalVar[];

void initFadeParam(f32 *p, f32 v)
{
    u8 *g = gcGlobalVar;

    p[0] = *(f32 *)(g + 0x168);
    p[1] = *(f32 *)(g + 0x168);
    p[2] = v;
    p[4] = v;
    p[3] = v;
}

/* NEARMISS-STUB setFadeParam */
#if 0 /* NEARMISS 31.58% cat=sched sub=- | target keeps sw a1 after 2nd lwc1 g168 (load-delay fill); ours hoists sw a1 above the first g168 load (addiu delay slot); f12/f13 float prototype and p[4]-first | attempts=1 */
void setFadeParam(f32 *p, s32 a1, f32 a2, f32 a3)
{
    u8 *g = gcGlobalVar;
    f32 t = p[4];

    p[0] = *(f32 *)(g + 0x168);
    p[1] = *(f32 *)(g + 0x168) + a3;
    p[2] = t;
    p[3] = a2;
    *(s32 *)&p[5] = a1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", setFadeParam);

/* NEARMISS-STUB calcFadeParam */
#if 0 /* NEARMISS 95.75% cat=regalloc sub=- | same instruction order as target; FP register assignment differs: target G in f5, p[0] in f1, p[2] in f4 (ours G in f1, p[0] in f4, p[2] in f5); 3 variants (loc | attempts=1 */
void calcFadeParam(f32 *p)
{
    f32 g = *(f32 *)(gcGlobalVar + 0x168);

    if (g <= p[1])
    {
        p[4] = p[2] + (p[3] - p[2]) * ((g - p[0]) / (p[1] - p[0]));
    }
    else
    {
        p[4] = p[3];
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", calcFadeParam);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", checkFadeParam);

extern u8 gcGlobalVar[];

s32 checkFadeParam(s32 a0)
{
    return *(f32 *)(gcGlobalVar + 0x168) <= *(f32 *)(a0 + 4);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeCheck);

extern s32 D_40130C68;

s32 fadeCheck(void)
{
    return D_40130C68;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeChkStat);

extern s32 D_40130C6C;

s32 fadeChkStat(s32 a0)
{
    return (D_40130C6C & a0) != 0;
}

void scrRun(void);

void fadeWait(void)
{
    while (D_40130C68 != 0)
    {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeIn);
void fadeIn(s32 wait, s32 rel, f32 f)
{
    D_40130C6C = 7;
    D_40130C68 = 0xC8;
    D_40130C64 = f;
    if (rel != 0) {
        ReleaseGame(1);
    }
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEIN);
    if (wait != 0) {
        while (D_40130C68 != 0) {
            scrRun();
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeOut);
void fadeOut(s32 wait, s32 pause, f32 f)
{
    setFadeColor(0);
    D_40130C6C = 1;
    D_40130C68 = 0x64;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEOUT);
    if (wait != 0) {
        while (D_40130C68 != 0) {
            scrRun();
        }
        if (pause != 0) {
            PauseGame(1);
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", fadeWhiteOut);
void fadeWhiteOut(s32 wait, s32 pause, f32 f)
{
    setFadeColor(1);
    D_40130C6C = 1;
    D_40130C68 = 0x64;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEOUT);
    if (wait != 0) {
        while (D_40130C68 != 0) {
            scrRun();
        }
        if (pause != 0) {
            PauseGame(1);
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", _fadeOut);
void _fadeOut(s32 wait, s32 pause, f32 f)
{
    D_40130C6C = 1;
    D_40130C68 = 0x64;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEOUT);
    if (wait != 0) {
        while (D_40130C68 != 0) {
            scrRun();
        }
        if (pause != 0) {
            PauseGame(1);
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", scrFadeIn);
void scrFadeIn(f32 f)
{
    D_40130C6C = 7;
    D_40130C68 = 0xC8;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEIN);
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", scrFadeBlackOut);
void scrFadeBlackOut(f32 f)
{
    setFadeColor(0);
    D_40130C6C = 1;
    D_40130C68 = 0x64;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEOUT);
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", scrFadeWhiteOut);
void scrFadeWhiteOut(f32 f)
{
    setFadeColor(1);
    D_40130C6C = 1;
    D_40130C68 = 0x64;
    D_40130C64 = f;
    scriptIntrSignal(ScrIntrDef_SCREEN_FADEOUT);
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", setTreeId);
void setTreeId(s32 id)
{
    D_40130C70 = id;
    D_40130C74 = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", resetTreeId);
void resetTreeId(s32 id)
{
    s32 i = D_40130C74;

    for (; i < 0x20; i++) {
        fruitsFlagSet(id, i);
    }
    D_40130C74 = 0;
    D_40130C70 = id;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", nico_setFruitsFlag);

u8 *GetScrLwsOriClass();
void fruitsFlagSet(s32, s32);

void nico_setFruitsFlag(void)
{
    u8 *p = GetScrLwsOriClass();

    fruitsFlagSet(*(s32 *)(p + 0x116C), *(s32 *)(p + 0x1174));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", setScriptAnimationObjChildStatus);
s32 setScriptAnimationObjChildStatus(s32 obj)
{
    s32 r = fruitsFlagChk(D_40130C70, D_40130C74);
    u8 *o = GetScrLwsOriClass(obj);

    *(s32 *)(o + 0x116C) = D_40130C70;
    *(s32 *)(o + 0x1170) = 0;
    *(s32 *)(o + 0x1174) = D_40130C74;
    if (r != 0) {
        isysRequestDeleteObj(obj);
    }
    D_40130C74 = D_40130C74 + 1;
    return r == 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", nico_checkTreeAllFruitsAlreadyTaken);

s32 fruitsFlagChk(s32, s32);

s32 nico_checkTreeAllFruitsAlreadyTaken(s32 a0)
{
    s32 i;

    for (i = 0; i < 32; i++) {
        if (fruitsFlagChk(a0, i) == 0) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", _omakeSelectFlagSet);

/* NEARMISS-STUB omakeGetAndSelectCls */
#if 0 /* NEARMISS 94.04% cat=regalloc sub=- | temp regalloc only: cls/8 rounding temps land in a6/a5 (expected t3/t2) and pp in a3 (expected t0); struct copy from D_40132E98 via ldl/ldr and bitmap ops match | attempts=1 */
extern u8 D_401FD09A[];
extern u8 D_401FD0A2[];
extern s8 D_401FD098;

typedef struct OmakeClsList
{
    u8 *list[2];
} OmakeClsList;

extern OmakeClsList D_40132E98;

void omakeGetAndSelectCls(s32 cls)
{
    OmakeClsList tbl = D_40132E98;
    u8 **pp;
    u8 *p;
    u8 *base;
    u8 *flag;
    s32 i;

    D_401FD09A[cls / 8] &= ~(1 << (cls & 7));
    pp = tbl.list;
    p = *pp;
    while (p != NULL) {
        if (*p != 0) {
            i = 0;
            do {
                if (cls == p[i]) {
                    goto done;
                }
                i++;
            } while (p[i] != 0);
        }
        pp++;
        p = *pp;
    }
done:
    D_401FD0A2[cls / 8] &= ~(1 << (cls & 7));
    if (p != NULL) {
        base = (u8 *)&D_401FD098;
        flag = base + 0xB;
        if (*(s32 *)(base + 0x20) != 0) {
            *flag |= 4;
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", omakeGetAndSelectCls);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0018_endingflowStartAdpcmSeq", omakeStatInit);
