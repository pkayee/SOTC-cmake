#include "common.h"

extern int *DldSysUndefSymbol;
extern void setAttainRadPathWork(void *, float);
extern void func_40112AF0(void *, void *);
extern void _setStopCtrlModeBaseMoveWork(void *, void *);

static inline int *dldData(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (int *)t[4] : 0;
}

static inline char *dldResolveRe(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (char *)t[4] + ((*h >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

void createHumanCtrlWork(void *w, char *ctrl, unsigned int *h, void *path)
{
    float *o = (float *)dldData(h);

    setAttainRadPathWork(path, 3.1415926f);
    func_40112AF0(w, ctrl);
    _setStopCtrlModeBaseMoveWork(ctrl, dldResolveRe((unsigned int *)o));
    *(float *)(ctrl + 0x34) = o[1];
}

void deleteHumanCtrlWork(void) {
}

void setDashHumanCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x30) = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", func_40112AF0);

void func_40112B20(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", func_40112B28);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", getAttainInversePos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcMoveQuaternion);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcNextMotRatio);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcAttainPosForDirExec);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcMoveAngle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcAngleTime);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcProgRotRatio);
