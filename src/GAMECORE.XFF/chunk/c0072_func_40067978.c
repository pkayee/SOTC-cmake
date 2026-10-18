#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40067978);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_400679C0);

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void createUserPathWork(void *, void *, int, float, float);
extern void *memset(void *, int, unsigned int);
extern void setAttainRangeData(void *, void *, float, float, float, float);
extern void setCreateTempAttain(void *, int);
extern char *GetScriptClass(void *);
extern void createHumanCtrlWork(void *, char *, unsigned int *, void *);
extern void setAttainModePathWork(void *, int);
extern void _setExecBaseMoveWork(void *, int);
extern void setDashHumanCtrlWork(void *, int);
extern void setUserPathMode(void *, int);
extern void *GetCharacterClass(void *);
extern void setExecGazeIKWork(void *, int);
extern void setGoingAngleGazeIKWork(void *, float);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void), void *);
extern void isysJumpSubThread(void (*)(void), void *);
extern int func_40067CF8(void *actor);
extern void func_40067BD8(void);
extern char *GetLayoutClass(void *);
extern void setAttainmentPos(void *, int);
extern char *GameObject_END_SWORD;
extern int D_401317BC;

void nico_guardStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x3CC3);
    char *c;
    char *w;
    char *pw;
    char *hc;
    float v[4];

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x3C90, 0x10);
    *(char **)(c + 0x1150) = w;
    hc = w + 0x3C50;
    pw = w + 0x10;
    CharaCtrlResetCtrlStatus(th);
    createUserPathWork(th, pw, 0, 5.0f, 10.0f);
    memset(v, 0, 0x10);
    v[3] = 1.0f;
    setAttainRangeData(pw, v, 0.0f, 1.0f, 3.1415926f, 10.0f);
    setCreateTempAttain(pw, 0);
    setAttainmentPos(pw, *(int *)(GetLayoutClass(*(void **)(GameObject_END_SWORD + 8)) + 0x134));
    createHumanCtrlWork(th, hc, *(unsigned int **)(GetScriptClass(th) + 0x44), pw);
    setAttainModePathWork(pw, 0);
    _setExecBaseMoveWork(hc, 1);
    setDashHumanCtrlWork(hc, 1);
    setUserPathMode(pw, 0);
    setExecGazeIKWork(GetCharacterClass(th), 1);
    setGoingAngleGazeIKWork(GetCharacterClass(th), 80.0f);
    SetScriptObjDeleteCallBackFunc(th, func_40067CF8, 0);
    D_401317BC = 0;
    isysJumpSubThread(func_40067BD8, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40067BD8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40067CF8);
extern int GetSCRCharaAIWorkPtr();
extern int deleteUserPathWork();

int func_40067CF8(void *actor)
{
    return deleteUserPathWork(((char *)GetSCRCharaAIWorkPtr(actor)) + 0x10);
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_40067D38(void *character);

void SCRGuardSwordPickup(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40067D38);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40067D38);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", guardMainCommon);

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void createUserPathWork(void *, void *, int, float, float);
extern void *memset(void *, int, unsigned int);
extern void setAttainRangeData(void *, void *, float, float, float, float);
extern void setCreateTempAttain(void *, int);
extern char *GetScriptClass(void *);
extern void createHumanCtrlWork(void *, char *, unsigned int *, void *);
extern void setAttainModePathWork(void *, int);
extern void setFollowModePathWork(void *, int);
extern void _setExecBaseMoveWork(void *, int);
extern void setUserPathMode(void *, int);
extern void *GetCharacterClass(void *);
extern void setExecGazeIKWork(void *, int);
extern void setGoingAngleGazeIKWork(void *, float);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void), void *);
extern void isysJumpSubThread(void (*)(void), void *);
extern int func_40068618(void *actor);
extern void func_40068510(void);

void nico_guardAStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x3CC3);
    char *c;
    char *w;
    char *pw;
    char *hc;
    float v[4];

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x3C90, 0x10);
    *(char **)(c + 0x1150) = w;
    hc = w + 0x3C50;
    pw = w + 0x10;
    CharaCtrlResetCtrlStatus(th);
    createUserPathWork(th, pw, 0, 5.0f, 10.0f);
    memset(v, 0, 0x10);
    v[3] = 1.0f;
    setAttainRangeData(pw, v, 0.0f, 0.5f, 3.1415926f, 10.0f);
    setCreateTempAttain(pw, 0);
    createHumanCtrlWork(th, hc, *(unsigned int **)(GetScriptClass(th) + 0x44), pw);
    setAttainModePathWork(pw, 0);
    setFollowModePathWork(pw, 1);
    _setExecBaseMoveWork(hc, 1);
    setUserPathMode(pw, 0);
    setExecGazeIKWork(GetCharacterClass(th), 1);
    setGoingAngleGazeIKWork(GetCharacterClass(th), 80.0f);
    SetScriptObjDeleteCallBackFunc(th, func_40068618, 0);
    isysJumpSubThread(func_40068510, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40068510);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40068618);
int func_40068618(void *actor)
{
    return deleteUserPathWork(((char *)GetSCRCharaAIWorkPtr(actor)) + 0x10);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0072_func_40067978", func_40068638);

int func_40068780(void *actor)
{
    return deleteUserPathWork(((char *)GetSCRCharaAIWorkPtr(actor)) + 0x10);
}
