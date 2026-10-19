#include "common.h"

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern void scrRunM(int);
extern void func_40068638(void *);
extern void func_40068940(void);

void nico_guardBStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x3CD3);
    char *c;
    char *w;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x3CA0, 0x10);
    *(char **)(c + 0x1150) = w;
    CharaCtrlResetCtrlStatus(th);
    func_40068638(w);
    *(float *)(w + 0x3C90) = 1.0471974611282349f;
    scrRunM(1);
    isysJumpSubThread(func_40068940, w);
}


void nico_guardDStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x3CD3);
    char *c;
    char *w;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x3CA0, 0x10);
    *(char **)(c + 0x1150) = w;
    CharaCtrlResetCtrlStatus(th);
    func_40068638(w);
    *(float *)(w + 0x3C90) = -1.0471974611282349f;
    scrRunM(1);
    isysJumpSubThread(func_40068940, w);
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));

extern void func_40068A50(void *character);

void SCRGuardArrowShoot(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_40068A50);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068940);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068A50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", r1_alert);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", checkpoint_alert);

extern void *isysGetThisSubThread(void);

extern void scrRun(void);

extern void scrInit(void *thread);

void home_test_anim(void)
{
    scrInit(isysGetThisSubThread());
    for (;;) {
        scrRun();
    }
}

extern void scrRunM(int);

extern void iosDebugPrintHashTable(void *);

extern char rootPtn[];

void st_malloc_test(void)
{
    scrInit(isysGetThisSubThread());
    for (;;) {
        scrRunM(0xB4);
        iosDebugPrintHashTable(rootPtn);
    }
}

extern int SeList_st03_air_0;

extern int SeList_st03_wind1_0;

extern int sePlayStageEnv(int, int, int);

void home_sound(void)
{
    scrInit(isysGetThisSubThread());
    sePlayStageEnv(SeList_st03_air_0, 0, 0);
    sePlayStageEnv(SeList_st03_wind1_0, 0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068E50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", nico_horseRStart);
