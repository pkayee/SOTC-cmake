#include "common.h"

/* GAMECORE c0038 PROVEN 100. NO-arg variant uses the ternary (return (A && B) ? ctx[8] : -1); the early-return form is for the ByPos variants. */
extern u8 gcGlobalVar[];

/* GAMECORE c0038 PROVEN 100. GetStageContext fills ctx[]; ctx[1]=pos, ctx[8]=area number (+0x20). Globals are BLOCK-SCOPE externs because the file declares D_40131474 as AreaGrid* only LATER (file-scope s32 would conflict). */
extern int GetStageContext();

/* GAMECORE c0038 PROVEN 100. GetStageName: ctx at sp+0, ctx[1]=gcGlobalVar+0x340, strcpy(dst, ctx). */
/* GAMECORE c0038 GetStageName(dst): stage name string is the first bytes of ctx; strcpy(dst, ctx). */
extern u8 gcGlobalVar[];
extern char *strcpy(char *, const char *);

/* GAMECORE c0038 PROVEN 100 (was 89 nearmiss). Key: 'if (A && B) { calls; return x; } return -1;' with early returns; the r=-1 + final-return form swaps a0/v0. ctx[8..9] = stage x/z area index. */
extern u8 gcGlobalVar[];

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", func_40040050);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", func_400402D0);

typedef struct {
    int v[4];
    unsigned short cnt;
    short pad;
} StageData;

extern int *DldSysUndefSymbol;
extern int SH_StageDataDEFAULT[];

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (char *)t[4] + ((v >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

static inline int stageNum(unsigned int *h)
{
    StageData *p = (StageData *)dldResolve(h);

    if (p != 0) {
        int *sh = DldSysUndefSymbol != SH_StageDataDEFAULT ? SH_StageDataDEFAULT : 0;
        StageData *base = 0;

        if (sh != 0)
            base = (StageData *)sh[4];
        return p - base;
    }
    return -1;
}

static inline StageData *stageData(int n)
{
    int *sh = DldSysUndefSymbol != SH_StageDataDEFAULT ? SH_StageDataDEFAULT : 0;

    return sh != 0 ? (StageData *)sh[4] + n : 0;
}

int stagemanager_checkstageAlreadyLoadRequestedByStrptr(unsigned int *h)
{
    return stageData(stageNum(h))->cnt;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", stagemanager_loadstageByStrptrWithTargetObjectAreaCenter);

s32 GetStageContextByPos(s32 *ctx, s32 pos)
{
    extern s32 D_40131474;
    extern s32 D_40131478;

    ctx[1] = pos;
    GetStageContext(ctx);
    if (D_40131474 != 0 && D_40131478 != 0)
        return ctx[8];
    return -1;
}

extern s32 D_40131490;

s32 GetWorldLayoutSheetSegHeader(void)
{
    return D_40131490;
}

StageData *gcGetStageData(int i)
{
    return stageData(i);
}

int gcGetNbStages(void)
{
    StageData *s = DldSysUndefSymbol == SH_StageDataDEFAULT ? 0 : (StageData *)SH_StageDataDEFAULT;

    if (s) {
        return s->v[3];
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", CreateStageManager);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetupStageManager);

extern void func_400402D0();

void SetupStageManager(int a, int b, int c, int d)
{
    func_400402D0(a, -1, c, d);
}

extern void func_400402D0();

void SetupStageManagerWithVariationId(void)
{
    func_400402D0();
}

typedef struct {
    char pad0[0x34];
    int nx;
} AreaGrid;

typedef struct {
    char pad0[8];
    unsigned int h;
    char padC[0x90];
} AreaEnt;

typedef struct {
    int a;
    unsigned int flags;
    char pad8[0x34];
} AreaStage;

extern AreaGrid *D_40131474;
extern AreaEnt *D_40131478;

int CheckStageManagerLoadArea(int x, int z, int k)
{
    AreaStage *s;
    unsigned int f;

    if (D_40131474 != 0 && D_40131478 != 0) {
        s = (AreaStage *)dldResolve(&D_40131478[z * D_40131474->nx + x].h);
        if (s != 0) {
            f = s[k].flags;
            return ((f >> 2) & 1) | (f & 2);
        }
    }
    return 0;
}

typedef struct {
    char pad0[4];
    const float *position;
    char pad8[0x28];
    s128 center;
} StageContext;

extern int GetStageContext(StageContext *);

void GetStageCenter(s128 *center, const float *position)
{
    StageContext context;

    context.position = position;
    GetStageContext(&context);
    *center = context.center;
}

char *GetStageName(char *dst)
{
    s32 ctx[16];

    ctx[1] = (s32)(gcGlobalVar + 0x340);
    GetStageContext((StageContext *)ctx);
    return strcpy(dst, (char *)ctx);
}

s32 GetStageAreaNumber(void)
{
    s32 ctx[16];

    ctx[1] = (s32)(gcGlobalVar + 0x340);
    GetStageContext((StageContext *)ctx);
    return (D_40131474 != 0 && D_40131478 != 0) ? ctx[8] : -1;
}

/* GAMECORE c0038 PROVEN 100. Key: early-return 'if (A != 0 && B != 0) return ctx[8]; return -1;' (r=-1 var => movn at 78%). */
s32 GetStageAreaNumberByPos(s32 pos)
{
    s32 ctx[16];

    ctx[1] = pos;
    GetStageContext((StageContext *)ctx);
    if (D_40131474 != 0 && D_40131478 != 0)
        return ctx[8];
    return -1;
}

s32 GetStageNumberByPos(void)
{
    s32 ctx[16];
    s32 t;

    ctx[1] = (s32)(gcGlobalVar + 0x340);
    GetStageContext((StageContext *)ctx);
    if (D_40131474 != 0 && D_40131478 != 0)
    {
        t = getstagenumber((ctx[8] << 5) | (ctx[9] & 0x1F));
        return getstagenumber((t << 15) | ((ctx[8] << 5) | (ctx[9] & 0x1F)));
    }
    return -1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetStageManagerAreaPreload);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetStageManagerAreaPreloadWithAreaOffset);
