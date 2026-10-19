#include "common.h"

typedef struct BgmObj {
    u8 pad0[0x34];
    s32 mode34;
    float f38;
    u8 pad3C[4];
    s32 x40;
    u32 flags44;
} BgmObj;
typedef struct BgmSlot {
    s32 state;
    s32 prio;
    u8 pad8[0x10];
    s32 *h18;
    s32 objp;
    float f20;
    float f24;
    u8 pad28[8];
    void (*cb)(struct BgmSlot *);
    u8 pad34[0xC];
} BgmSlot;
extern BgmSlot D_402010F0[];
extern void adpcmCloseFadeSetVol(s32, float);

/* GAMECORE c0042 bgm status setter: closes every live slot. */
extern s32 D_40131540;

extern void adpcmDeleteAdpcmSeq(s32);

void bgmScriptSetStatus(s32 st)
{
    BgmSlot *s;
    s32 i;
    u32 fl;

    D_40131540 = st;
    if (st == 1) {
        for (i = 0; i < 3; i++) {
            s = &D_402010F0[i];
            if (s->state != 0) {
                if (s->state - 5U >= 2) {
                    fl = ((BgmObj *)s->objp)->flags44;
                    fl &= ~2;
                    fl &= ~1;
                    ((BgmObj *)s->objp)->flags44 = fl;
                    s->state = 5;
                    ((BgmObj *)s->objp)->x40 = 0;
                }
                if (s->cb != 0) {
                    s->cb(s);
                }
            }
        }
    }
}

/* GAMECORE c0042 bgm slot close loop (slot table D_402010F0, 3 slots stride 0x40). */
void bgmPlayerDemoEndTypeAllClose(void)
{
    BgmSlot *s;
    s32 i;
    u32 fl;

    s = D_402010F0;
    i = 2;
    do {
        if (s->state != 0) {
            if (((BgmObj *)s->objp)->mode34 == 4) {
                s->f24 = ((BgmObj *)s->objp)->f38;
                if (s->state - 5U >= 2) {
                    fl = ((BgmObj *)s->objp)->flags44;
                    fl &= ~2;
                    fl &= ~1;
                    ((BgmObj *)s->objp)->flags44 = fl;
                    s->state = 5;
                    ((BgmObj *)s->objp)->x40 = 0;
                }
                if (s->cb != 0) {
                    s->cb(s);
                }
            }
        }
        i--;
        s++;
    } while (i >= 0);
}

/* GAMECORE c0042: closes the lowest-priority live bgm slot under the given priority (state 6 slot is faded out instead). */
void bgmMinPriorityForceClose(s32 prio)
{
    BgmSlot *s;
    BgmSlot *best;
    s32 i;
    u32 fl;

    best = 0;
    for (i = 0; i < 3; i++) {
        s = &D_402010F0[i];
        if (s->state == 6) {
            adpcmCloseFadeSetVol(*s->h18, 100.0f);
            return;
        }
    }
    for (i = 0; i < 3; i++) {
        s = &D_402010F0[i];
        if (s->state != 0 && s->prio < prio) {
            prio = s->prio;
            best = s;
        }
    }
    if (best != 0) {
        best->f24 = 0;
        if (best->state - 5U >= 2) {
            fl = ((BgmObj *)best->objp)->flags44;
            fl &= ~2;
            fl &= ~1;
            ((BgmObj *)best->objp)->flags44 = fl;
            best->state = 5;
            ((BgmObj *)best->objp)->x40 = 0;
        }
        if (best->cb != 0) {
            best->cb(best);
        }
    }
}

extern int D_40131574;
extern int D_40131570;
extern int D_40131548;
extern void func_40043D88(void);
extern void func_400432A0(void);

void bgmScriptTickProc(void)
{
    D_40131570 = D_40131574 = 0;
    func_40043D88();
    if (D_40131548 < 3) {
        func_400432A0();
    }
}

extern int func_400430B8();

int bgmScriptBossTickProc(void)
{
    return func_400430B8();
}

extern int D_40201200;

void bgmScriptSendSoundSignal(int arg0)
{
    D_40201200 |= 1 << arg0;
}

int bgmScriptRecvSoundSignal(int arg0)
{
    int temp_v1;

    temp_v1 = ((int) D_40201200 >> arg0) & 1;
    if (temp_v1 != 0) {
        D_40201200 ^= 1 << arg0;
    }
    return temp_v1;
}

extern s32 DldSysUndefSymbol;

static inline s32 dldCount(u32 *lp)
{
    u32 off = *lp & 0x3FFFF;
    u8 *t = off != 0 ? *(u8 **)((u8 *)lp - off) : 0;

    return (t != 0 && t != (u8 *)DldSysUndefSymbol) ? *(s32 *)(t + 0xC) : 0;
}

static inline u8 *dldRow(u32 *lp)
{
    u32 w = *lp;
    u32 off = w & 0x3FFFF;
    u8 *t = off != 0 ? *(u8 **)((u8 *)lp - off) : 0;

    return (t != 0 && t != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : 0;
}
/* GAMECORE c0042: demo package (relative-pointer sheet ref at +4): row count from the sheet header, then clear field +8 of every row's 0x40 target (rows stride 0x50). */
void bgmDemoPackagePlay(u8 *obj)
{
    u8 *row;
    u8 *r;
    s32 n;
    s32 cnt;

    n = dldCount((u32 *)(obj + 4));
    row = dldRow((u32 *)(obj + 4));
    r = row;
    if (n > 0) {
        cnt = n;
        do {
            *(s32 *)(*(u8 **)(r + 0x40) + 8) = 0;
            r += 0x50;
            cnt--;
        } while (cnt != 0);
    }
}

extern int D_40131584;

void bgmEnvTickProckMask(int arg0)
{
    D_40131584 = arg0;
}

extern int D_402010E8;

void initBgmScript(void)
{
    s64 bits;

    bits = 0x1800000000000000;
    D_402010E8 = 0;
    do {
        bits >>= 1;
        D_402010E8++;
    } while (!(bits & 1));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B00);
extern int D_402011F0[];
extern int D_40131544;

void func_40044B00(int param_1)
{
    int *piVar1;
    int iVar2;

    iVar2 = 1;
    piVar1 = D_402011F0;
    do {
        if (*piVar1 == param_1) {
            *piVar1 = 0;
        }
        iVar2 = iVar2 + -1;
        piVar1 = piVar1 + 1;
    } while (-1 < iVar2);
    if (D_40131544 == param_1) {
        D_40131544 = 0;
    }
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bossNormalHook);
void bossNormalHook(int a0, int a1, int a2, int *a3, int *t0)
{
    *a3 = -2;
    t0[5] = t0[5] + 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B68);
extern int D_40131580;

void func_40044B68(int param_1)
{
    if (param_1 == D_40131580) {
        D_40131580 = 0;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B88);
extern int D_402011F8[];
extern int D_40131544;

void func_40044B88(int param_1)
{
    int *piVar1;
    int iVar2;

    iVar2 = 1;
    piVar1 = D_402011F8;
    do {
        if (*piVar1 == param_1) {
            *piVar1 = 0;
        }
        iVar2 = iVar2 + -1;
        piVar1 = piVar1 + 1;
    } while (-1 < iVar2);
    if (D_40131544 == param_1) {
        D_40131544 = 0;
    }
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", scriptNormalHook);
void scriptNormalHook(int a0, int a1, int a2, int *a3, int *t0)
{
    *a3 = -2;
    t0[5] = t0[5] + 1;
}

void func_40044BF0(void) {
}

void demoNormalHook(int a0, int a1, int a2, int *a3, int *t0)
{
    *a3 = -2;
    t0[5] = t0[5] + 1;
}

void initAdpcmOrient(void) {
}

/* GAMECORE c0042: orient table (count at +0xC, 0x50-byte rows at +0x10, row +0x40 = bgm slot): delete the adpcm seq and close each slot. */
void deleteAdpcmOrient(u8 *o)
{
    u8 *row;
    BgmSlot *s;
    s32 n;
    u32 fl;

    row = *(u8 **)(o + 0x10);
    if (*(s32 *)(o + 0xC) > 0) {
        n = *(s32 *)(o + 0xC);
        do {
            if (*(BgmSlot **)(row + 0x40) != 0) {
                adpcmDeleteAdpcmSeq(*(*(BgmSlot **)(row + 0x40))->h18);
                s = *(BgmSlot **)(row + 0x40);
                if (s->state - 5U >= 2) {
                    fl = ((BgmObj *)s->objp)->flags44;
                    fl &= ~2;
                    fl &= ~1;
                    ((BgmObj *)s->objp)->flags44 = fl;
                    s->state = 5;
                    ((BgmObj *)s->objp)->x40 = 0;
                }
                if (s->cb != 0) {
                    s->cb(s);
                }
            }
            n--;
            row += 0x50;
        } while (n != 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044CE0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmSeqNormalHook);
int bgmSeqNormalHook(int a0, int a1, int a2, int *a3)
{
    *a3 = -2;
    return a2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmAutoStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmStandbyWithPri);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmStandby);

extern int adpcmOpenChkComplete(int);

int bgmChkStandbyComplete(int *p)
{
    if (p[2] == 1)
        return 0;
    return adpcmOpenChkComplete(p[0]);
}

void bgmPlay(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0xC)) = fparg0;
    (*(int *)((char *)(arg0) + 0x24)) = (int) ((*(int *)((char *)(arg0) + 0x24)) | 1);
}

typedef struct {
    char pad0[0x18];
    float fadeTime;
    char pad1C[4];
    int *done;
    unsigned int flags;
} Bgm;

void bgmStop(Bgm *bgm, int *done, float time)
{
    bgm->fadeTime = time;
    if (done != 0) {
        *done = 0;
    }
    bgm->done = done;
    bgm->flags |= 4;
}

int bgmStopChk(int arg0)
{
    return arg0;
}

extern unsigned char D_40201208[];

void bgmStopAllAttr(int arg0, int arg1)
{
    void *var_v1;
    int var_a2;

    var_a2 = 2;
    var_v1 = D_40201208;
    do {
        var_a2 -= 1;
        if (((*(int *)((char *)(var_v1) + 8)) != 0) && ((*(int *)((char *)(var_v1) + 4)) & arg0)) {
            (*(int *)((char *)(var_v1) + 0x20)) = 0;
            (*(int *)((char *)(var_v1) + 0x24)) = (int) ((*(int *)((char *)(var_v1) + 0x24)) | 4);
            (*(float *)((char *)(var_v1) + 0x18)) = (float) arg1;
        }
        var_v1 += 0x34;
    } while (var_a2 >= 0);
}

void bgmChangeVol(void *arg0, float fparg0, float fparg1)
{
    (*(float *)((char *)(arg0) + 0x14)) = fparg1;
    (*(float *)((char *)(arg0) + 0x10)) = fparg0;
    (*(int *)((char *)(arg0) + 0x24)) = (int) ((*(int *)((char *)(arg0) + 0x24)) | 2);
}

void bgmStartGameOver(void) {
}

void bgmEndGameOver(void) {
}

void bgmStageInit(void) {
}
