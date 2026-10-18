#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmScriptSetStatus);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmPlayerDemoEndTypeAllClose);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmMinPriorityForceClose);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", initBgmScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B00);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bossNormalHook);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B68);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044B88);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", scriptNormalHook);

void func_40044BF0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", demoNormalHook);

void initAdpcmOrient(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", deleteAdpcmOrient);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", func_40044CE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0042_bgmScriptSetStatus", bgmSeqNormalHook);

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
