#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmScriptSetStatus);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmPlayerDemoEndTypeAllClose);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmMinPriorityForceClose);

/* NEARMISS-STUB bgmScriptTickProc */
#if 0 /* NEARMISS 98.888885% cat=branch-layout sub=- | lui order swapped for D_40131570/D_40131574 globals; tail call matches | attempts=1 */
extern int D_40131574;
extern int D_40131570;
extern int D_40131548;
extern void func_40043D88(void);
extern void func_400432A0(void);

void bgmScriptTickProc(void)
{
    D_40131574 = 0;
    D_40131570 = 0;
    func_40043D88();
    if (D_40131548 < 3) {
        func_400432A0();
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmScriptTickProc);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmDemoPackagePlay);

extern int D_40131584;

void bgmEnvTickProckMask(int arg0)
{
    D_40131584 = arg0;
}

/* NEARMISS-STUB initBgmScript */
#if 0 /* NEARMISS 72.8% cat=regalloc sub=- | bits/count register swap (a0/v1); ptr copy reg differs; same 68B shape | attempts=1 */
extern int D_402010E8;

void initBgmScript(void)
{
    s64 bits;
    int count;

    bits = 0x1800000000000000;
    D_402010E8 = 0;
    count = 0;
    do {
        bits >>= 1;
        count++;
    } while ((bits & 1) == 0);
    D_402010E8 = count;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", initBgmScript);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", deleteAdpcmOrient);

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
