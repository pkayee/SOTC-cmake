#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", st_stageboundary);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_400421B8);

extern s32 GetWorldLayoutSheetSegHeader(void);
extern void setLightParam(s32 param);

s32 func_400421B8(void *param)
{
    s32 hdr;

    hdr = GetWorldLayoutSheetSegHeader();
    if (hdr != 0) {
        setLightParam(*(s32 *)(hdr + 0x10) + *(s32 *)((u8 *)param + 0x20) * 0x9c);
    }
    return 0;
}

typedef struct {
    long v[8];
} Boundary;

extern int D_401314A0;
extern Boundary D_401314B0;
extern Boundary D_401314F0;
extern Boundary D_40133160;

void PauseStageBoundaryManager(int pause)
{
    D_401314A0 = pause;
    if (pause == 0) {
        D_401314B0 = D_40133160;
        D_401314F0 = D_40133160;
    }
}

extern void st_stageboundary();
extern char rootPtn[];
extern char D_401331A0[];
extern void *gcCreateScriptObj(void *, int, void *, int, int, int, char *);

void *CreateStageBoundaryManager(int arg)
{
    return gcCreateScriptObj(st_stageboundary, 0, rootPtn, 0x2000, 0, arg, D_401331A0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", st_controltarget);

extern unsigned char D_40131530[];

void *getBossExtControl(void)
{
    return D_40131530;
}

extern unsigned char D_40131534[];

void *getTargetAIControlMode(void)
{
    return D_40131534;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", time_attack_begin);

extern int *DldSysUndefSymbol;
extern int SH_GameObjectStatusDEFAULT[];
extern int SH_TimeAttackItemListDEFAULT[];

typedef struct {
    unsigned int h;
    char pad4[0x10];
} GObjStatus;

static inline int *dldTable(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? t : 0;
}

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (char *)t[4] + ((v >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

void time_attack_init_gstat_adrs(void)
{
    int *sh = DldSysUndefSymbol == SH_GameObjectStatusDEFAULT ? 0 : SH_GameObjectStatusDEFAULT;
    GObjStatus *e = (GObjStatus *)sh[4];
    int i;

    for (i = 0; i < sh[3]; i++, e++) {
        if (dldTable(&e->h) == (DldSysUndefSymbol != SH_TimeAttackItemListDEFAULT ? SH_TimeAttackItemListDEFAULT : 0))
            *(int *)(dldResolve(&e->h) + 0x10) = (int)e;
    }
}

extern float D_40131538;

float time_attack_get_best_time(void)
{
    return D_40131538;
}

extern void setBossIndexTimeAttackBestTime(int);
extern int D_402010E0;

void time_attack_set_best_time(float fparg0)
{
    D_40131538 = fparg0;
    setBossIndexTimeAttackBestTime(D_402010E0);
}

extern int D_4013153C;

int time_attack_get_boss_status(void)
{
    return D_4013153C;
}

extern s32 gstatKaisouMode;
extern s32 gstatTimeAttackMode;

void time_attack_end(void)
{
    gstatTimeAttackMode = 0;
    gstatKaisouMode = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", time_attack_start);

extern s32 D_402010DC;
extern int D_402010D8;
extern void gStatCheckPointSave(void);
extern s32 getGameHardMode(void);
extern s32 gstatBootMcChkExistIcoData(void);
extern void omakeStatInit(s32 a, void *b, s32 c);
extern void setSmallManagerSystemLock(int arg0);
extern void gStatInitNotOmakeInit(void);
extern void bossStatTimeAttackJumpSekiban(s32);

void time_attack_start(void)
{
    s32 uVar1;
    s32 uVar2;

    gStatCheckPointSave();
    gstatTimeAttackMode = 1;
    gstatKaisouMode = D_402010DC;
    gStatInitNotOmakeInit();
    if (gstatKaisouMode == 0) {
        uVar1 = gstatBootMcChkExistIcoData();
        uVar2 = getGameHardMode();
        omakeStatInit(uVar1, 0, uVar2);
    }
    setSmallManagerSystemLock(1);
    bossStatTimeAttackJumpSekiban(D_402010D8);
}

extern void gStatInitNotOmakeInit(void);
extern void bossStatTimeAttackJumpSekiban(s32);
extern int D_402010D8;

void time_attack_retry(void)
{
    gStatInitNotOmakeInit();
    bossStatTimeAttackJumpSekiban(D_402010D8);
}

typedef struct {
    char pad[0xAC];
    int flag;
    char pad2[0x10];
} BossEnt;

extern char SH_BossStatusDEFAULT[];
extern int _gameFlagChk(int);

int time_attack_get_clear_num(void)
{
    char *t = (char *)DldSysUndefSymbol == SH_BossStatusDEFAULT ? 0 : SH_BossStatusDEFAULT;
    int n = 0;
    int i;
    int cnt = *(int *)(t + 0xC);
    BossEnt *e = *(BossEnt **)(t + 0x10);
    for (i = 0; i < cnt; i++) {
        int f = e->flag;
        e++;
        if (_gameFlagChk(f))
            n++;
    }
    return n;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_400428E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_40042BD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_40042E68);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_400430B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0040_st_stageboundary", func_400432A0);
