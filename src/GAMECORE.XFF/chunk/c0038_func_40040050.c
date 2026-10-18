#include "common.h"

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", GetStageContextByPos);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetupStageManager);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", GetStageName);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", GetStageAreaNumber);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", GetStageAreaNumberByPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", GetStageNumberByPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetStageManagerAreaPreload);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0038_func_40040050", SetStageManagerAreaPreloadWithAreaOffset);
