#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0083_SCRFuncKirinSlopeFallRockLWSLoad", SCRFuncKirinSlopeFallRockLWSLoad);

extern void *isysGetThisSubThread(void);
extern void SCRExecBossPreProcess(s32);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern void updateScriptDataSystem(void *);
extern void SCRExecBossPostProcess(s32);
extern void scrRunM(s32);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0083_SCRFuncKirinSlopeFallRockLWSLoad", func_40073948);
void func_40073948(s32 *a0)
{
    void *thread;

    isysGetThisSubThread();
    for (;;)
    {
        thread = isysGetThisSubThread();
        SCRExecBossPreProcess(*a0);
        CharaCtrlResetAllScriptCtrlStatus(thread);
        updateScriptDataSystem(thread);
        isysGetThisSubThread();
        SCRExecBossPostProcess(*a0);
        scrRunM(1);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0083_SCRFuncKirinSlopeFallRockLWSLoad", func_400739A8);
extern unsigned char gcGlobalVar[];
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysGroupForExit(int, int);
extern void unloadObj(int);

void func_400739A8(void)
{
    int m = 0;
    int *g;

    for (g = isysGroupForFirst(gcGlobalVar + 0x304, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        m = *g;
        unloadObj(m);
    }
    if (m != 0)
        isysGroupForExit(m, 0);
}

u8* GetLayoutClass(void* chara);

void SCRFuncKirinCameraNeckDownIdSet(void* actor)
{
    *(s32*)(GetLayoutClass(actor) + 0x1AC) = 0xA;
}

void SCRFuncKirinCameraNeckDownIdReset(void* actor)
{
    *(s32*)(GetLayoutClass(actor) + 0x1AC) = 0;
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_40073C98(void *character);

void SCRKirinFallRockEnd(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40073C98);
}

extern void *GetSCRCharaAIWorkPtr(int);
extern int SCRGetFirstObj(void *);
extern unsigned char gcGlobalVar[];

void SCRFuncSetFallRockTimerAndSetGroundDestFlag(void)
{
    float temp_f0;
    int temp_v0;
    void *temp_v0_2;

    temp_v0 = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (temp_v0 != 0) {
        temp_v0_2 = GetSCRCharaAIWorkPtr(temp_v0);
        if ((*(int *)((char *)(temp_v0_2) + 0x4198)) != 0) {
            temp_f0 = (*(float *)((char *)(temp_v0_2) + 0x4194)) + 0.5f;
            (*(float *)((char *)(temp_v0_2) + 0x4194)) = temp_f0;
            if (temp_f0 > 5.0f) {
                (*(float *)((char *)(temp_v0_2) + 0x4194)) = 5.0f;
            }
            (*(int *)((char *)(temp_v0_2) + 0x419C)) = 1;
        }
    }
}

void SCRFuncSetFallRockTimer(void)
{
    float temp_f0;
    int temp_v0;
    void *temp_v0_2;

    temp_v0 = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (temp_v0 != 0) {
        temp_v0_2 = GetSCRCharaAIWorkPtr(temp_v0);
        if ((*(int *)((char *)(temp_v0_2) + 0x4198)) != 0) {
            temp_f0 = (*(float *)((char *)(temp_v0_2) + 0x4194)) + 0.5f;
            (*(float *)((char *)(temp_v0_2) + 0x4194)) = temp_f0;
            if (temp_f0 > 5.0f) {
                (*(float *)((char *)(temp_v0_2) + 0x4194)) = 5.0f;
            }
        }
    }
}

void SCRFuncKirinFallRockMain(void *actor)
{
    float temp_f0;
    float temp_f1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr((int)actor);
    temp_f1 = (*(float *)((char *)(temp_v0) + 0x4194));
    if (temp_f1 > 0.0f) {
        temp_f0 = temp_f1 - (*(float *)((char *)(gcGlobalVar) + 0x180));
        (*(float *)((char *)(temp_v0) + 0x4194)) = temp_f0;
        if (temp_f0 < 0.0f) {
            (*(float *)((char *)(temp_v0) + 0x4194)) = 0.0f;
        }
    }
}

int SCRConditionFallRockChack(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr((int)actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x4194)))
        r = 0;
    return r;
}

void SCRFuncKirinFallRockTimerSetFlagOn(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr((int)actor);
    (*(int *)((char *)(temp_v0) + 0x4198)) = 1;
}

void SCRFuncKirinFallRockTimerSetFlagOff(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr((int)actor);
    (*(int *)((char *)(temp_v0) + 0x4198)) = 0;
}

extern char *getSCRDataCtrlWork(void *);

int SCRConditionKirinIntervalOfMovement(void *actor, int n, int lim)
{
    return (int)*(float *)(getSCRDataCtrlWork(actor) + 0x4084) % n < lim;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0083_SCRFuncKirinSlopeFallRockLWSLoad", func_40073C98);

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern int SCRGetSizeOfBossWork(void *);
extern int SCRCharaInitBossWork(int, void *);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(void), int);
extern char *GetScriptClass(void *);
extern void initScriptDataSystem(void *, int);
extern int *GameObject_KNIGHT_ARM_PARTS;
extern int *GameObject_KNIGHT_ARM_BREAK;
extern int *GameObject_KNIGHT_NECK_PARTS;
extern int *GameObject_KNIGHT_NECK_BREAK;
extern int _gameFlagChk(int);
extern void _SCRStartLWS(int, int, int, int *);
extern void func_400744E0(void);

void nico_KnightBossStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x41D3);
    char *c;
    int *w;
    int r;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = (int *)_SCRMallocAlign(part, 0x41A0, 0x10);
    *(int **)(c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    CharaCtrlResetCtrlStatus(th);
    initScriptDataSystem(th, *(int *)(GetScriptClass(th) + 0x48));
    w[0x4190 / 4] = 0;
    w[0x4194 / 4] = 0;
    w[0x4198 / 4] = 0;
    if (_gameFlagChk(0x10A)) {
        _SCRStartLWS(GameObject_KNIGHT_ARM_PARTS[2], -1, 1, 0);
        _SCRStartLWS(GameObject_KNIGHT_ARM_BREAK[2], -1, 1, 0);
    }
    if (_gameFlagChk(0x10B)) {
        _SCRStartLWS(GameObject_KNIGHT_NECK_PARTS[2], -1, 1, 0);
        _SCRStartLWS(GameObject_KNIGHT_NECK_BREAK[2], -1, 1, 0);
    }
    isysJumpSubThread(func_400744E0, w);
}
