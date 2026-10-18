#include "common.h"

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
extern char *getEditWorkInitData(int);
typedef int s128 __attribute__((mode(TI)));
extern int getPointPosFromEvent(char *, int, s128 *);
extern void setAttainmentPos(void *, void *);
extern void setDashHumanCtrlWork(void *, int);
extern void scrRunM(int);
extern void *GetCharacterClass(void *);
extern void setExecGazeIKWork(void *, int);
extern void setGoingAngleGazeIKWork(void *, float);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void), void *);
extern void isysJumpSubThread(void (*)(void), void *);
extern void func_400A6A98(void *);
extern void func_400A6110(void);
extern int GetSCRCharaAIWorkPtr();
extern void deleteUserPathWork(void *);

void nico_shamanStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x3CD3);
    char *c;
    char *w;
    char *pw;
    char *hc;
    float v[4];
    float pos[4];

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x3CA0, 0x10);
    *(char **)(c + 0x1150) = w;
    pw = w + 0x10;
    hc = w + 0x3C50;
    *(char **)(w + 0x3C98) = getEditWorkInitData(*(int *)(GetScriptClass(th) + 0x40));
    CharaCtrlResetCtrlStatus(th);
    createUserPathWork(th, pw, 0, 5.0f, 10.0f);
    memset(v, 0, 0x10);
    v[3] = 1.0f;
    setAttainRangeData(pw, v, 0.0f, 1.0f, 3.1415926f, 10.0f);
    setCreateTempAttain(pw, 0);
    getPointPosFromEvent(pw, 0, (s128 *)pos);
    setAttainmentPos(pw, pos);
    createHumanCtrlWork(th, hc, *(unsigned int **)(GetScriptClass(th) + 0x44), pw);
    setAttainModePathWork(pw, 0);
    _setExecBaseMoveWork(hc, 1);
    setDashHumanCtrlWork(hc, 1);
    setUserPathMode(pw, 0);
    *(int *)(w + 0x3C90) = 0;
    *(float *)(w + 0x3C94) = 0.0f;
    setExecGazeIKWork(GetCharacterClass(th), 1);
    setGoingAngleGazeIKWork(GetCharacterClass(th), 80.0f);
    SetScriptObjDeleteCallBackFunc(th, func_400A6A98, 0);
    scrRunM(1);
    isysJumpSubThread(func_400A6110, w);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0123_nico_shamanStart", func_400A6A98);
void func_400A6A98(void *actor)
{
    deleteUserPathWork(((char *)GetSCRCharaAIWorkPtr(actor)) + 0x10);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0123_nico_shamanStart", nico_sheathScript);
