#include "common.h"

extern void *getSCRDataCtrlWork(void *);
extern void resetPassageWork(void *work);
extern s32 DldSysUndefSymbol;
extern s32 execCondition(void *, s32);
extern s32 execSCRBaseFunc(void *, s32);
extern void CharaCtrlSetScriptCtrlStatus(void *, s32);
extern void CharaCtrlSetOutsideScriptCtrlStatus(void *, s32);
extern void CharaCtrlResetAllScriptCtrlStatus(s32);
extern void setGpCalcDist(void *work, f32 distance);
extern void _SCRStartLWS(s32 lws, s32 a1, s32 a2, u8 *a3);
extern void setGameFlagForGameObj(s32 obj);
extern void updateUserPathWorkEx(void *, void *, int);

typedef union { s128 q; float f[4]; int i[4]; } Vec4;
extern int getPointPosFromEvent(char *, int, Vec4 *);
extern void setAttainmentPos(char *, Vec4 *);
extern void getNearPointPosUserPathWork(char *, Vec4 *, int, int);
extern char *GetLayoutClass(void *);
extern char *GetScriptAnimationClass(void *);

void SCRFuncUpdatePathSystem(void *actor)
{
    char *work;

    work = getSCRDataCtrlWork(actor);
    updateUserPathWorkEx(actor, work, *(int *)(work + 0x4058));
}

void SCRFuncSetAttainPointPosForLanding(void *a, int ev)
{
    Vec4 p;
    char *w = getSCRDataCtrlWork(a);
    int m = *(int *)(w + 0x4070);
    if (m == 2 || m == 4) {
        if (getPointPosFromEvent(w, ev, &p))
            setAttainmentPos(w, &p);
    }
}

void SCRFuncSetAttainNearPlayerPoint(void *a, float dy)
{
    Vec4 p;
    char *w = getSCRDataCtrlWork(a);
    p.q = (*(Vec4 **)(*(char **)(w + 0x405C) + 0x134))->q;
    getNearPointPosUserPathWork(w, &p, *(int *)(*(char **)(w + 0x405C) + 0x134), 1);
    p.f[1] += dy;
    setAttainmentPos(w, &p);
}

void SCRFuncSetAttainNearMyselfPoint(void *a, float dy)
{
    Vec4 p;
    char *w = getSCRDataCtrlWork(a);
    p.q = (*(Vec4 **)(GetLayoutClass(a) + 0x134))->q;
    getNearPointPosUserPathWork(w, &p, *(int *)(GetLayoutClass(a) + 0x134), 1);
    p.f[1] += dy;
    setAttainmentPos(w, &p);
}

void SCRFuncResetPathSystem(void *actor)
{
    resetPassageWork(getSCRDataCtrlWork(actor));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncRegressFromPlayer);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncAttackCancelForTwoBoneRay);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncAttackCancelForOneBoneRay);

void SCRFuncResetVolumeTime0(void *actor)
{
    *(s32 *)((u8 *)getSCRDataCtrlWork(actor) + 0x408C) = 0;
}

extern char gcGlobalVar[];
extern int CheckPositionInsideOfJudgeVolumeObject(void *, void *, void *, s128 *);

void SCRFuncVolumeTime0Main(void *a, int b, int c, int d, int e, int f, unsigned int *h)
{
    char buf[0x60];
    char *w = getSCRDataCtrlWork(a);
    s128 pos = **(s128 **)(*(char **)(w + 0x405C) + 0x134);
    unsigned int v = *h;
    int voff = v & 0x3FFFF;
    char *t = voff != 0 ? *(char **)((char *)h - voff) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;

    if (p != 0 && CheckPositionInsideOfJudgeVolumeObject(buf, a, h, &pos))
        *(float *)(w + 0x408C) += *(float *)(gcGlobalVar + 0x190);
    else
        *(int *)(w + 0x408C) = 0;
}

void SCRFuncConditionSendKey(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 cond, s32 i, u32 *h)
{
    if (execCondition(a, cond)) {
        u32 v = *h;
        s32 off = v & 0x3FFFF;
        u8 *t = off != 0 ? *(u8 **)((u8 *)h - off) : NULL;
        u8 *p = (t != NULL && t != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : NULL;

        if (p != NULL)
            CharaCtrlSetScriptCtrlStatus(a, *(s32 *)(p + 4));
    }
}

void SCRFuncSendKeyToGameObj(void *a, s32 b, s32 c, s32 d, s32 e, s32 *obj, s32 g, s32 i, u32 *h)
{
    s32 ooff = *obj & 0x3FFFF;
    s32 *ot = ooff != 0 ? *(s32 **)((u8 *)obj - ooff) : NULL;
    s32 *o = (ot != NULL && ot != (s32 *)DldSysUndefSymbol) ? (s32 *)ot[4] : NULL;
    u32 v = *h;
    s32 voff = v & 0x3FFFF;
    u8 *t = voff != 0 ? *(u8 **)((u8 *)h - voff) : NULL;
    u8 *p = (t != NULL && t != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : NULL;

    if (o != NULL && o[2] != 0 && p != NULL)
        CharaCtrlSetScriptCtrlStatus((void *)o[2], *(s32 *)(p + 4));
}

void SCRFuncOutsideSendKeyToGameObj(void *a, s32 b, s32 c, s32 d, s32 e, s32 *obj, s32 g, s32 i, u32 *h)
{
    s32 ooff = *obj & 0x3FFFF;
    s32 *ot = ooff != 0 ? *(s32 **)((u8 *)obj - ooff) : NULL;
    s32 *o = (ot != NULL && ot != (s32 *)DldSysUndefSymbol) ? (s32 *)ot[4] : NULL;
    u32 v = *h;
    s32 voff = v & 0x3FFFF;
    u8 *t = voff != 0 ? *(u8 **)((u8 *)h - voff) : NULL;
    u8 *p = (t != NULL && t != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : NULL;

    if (o != NULL && o[2] != 0 && p != NULL)
        CharaCtrlSetOutsideScriptCtrlStatus((void *)o[2], *(s32 *)(p + 4));
}

void SCRFuncResetKeyToGameObj(void *a, s32 b, s32 c, s32 d, s32 e, s32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : NULL;
    s32 *g = (t != NULL && t != (s32 *)DldSysUndefSymbol) ? (s32 *)t[4] : NULL;

    if (g != NULL && g[2] != 0)
        CharaCtrlResetAllScriptCtrlStatus(g[2]);
}

s32 SCRFuncConditionExecFunc(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 cond, s32 func)
{
    if (execCondition(a, cond)) {
        return execSCRBaseFunc(a, func);
    }
    return 0;
}

s32 SCRFuncSubFunc(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h)
{
    return execSCRBaseFunc(a, h);
}

void SCRFuncSetGpCalcDist(void *actor, f32 r)
{
    setGpCalcDist(getSCRDataCtrlWork(actor), r);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncProgramRotInputForGP);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncInputRotateMotionKey);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncInputRotateMotionKeyToNextPoint);

void SCRFuncStartStageLayoutLWS(void *a, s32 mode, s32 flag, s32 d, s32 e, s32 f, u32 *h)
{
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8 *t = off != 0 ? *(u8 **)((u8 *)h - off) : NULL;
    u8 *p = (t != NULL && t != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : NULL;

    _SCRStartLWS(*(s32 *)(p + 0x48), -1, mode, NULL);
    if (flag)
        setGameFlagForGameObj(*(s32 *)(p + 0x48));
}

void SCRFuncStartGameObjectLWS(void *a, s32 lws, s32 flag, s32 d, s32 e, s32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : NULL;
    s32 *g = (t != NULL && t != (s32 *)DldSysUndefSymbol) ? (s32 *)t[4] : NULL;

    if (g != NULL && g[2] != 0) {
        _SCRStartLWS(g[2], -1, lws, NULL);
        if (flag != 0) {
            setGameFlagForGameObj(g[2]);
        }
    }
    return;
}

s32 SCRFuncStartGameObjectLWSCheckStatus(void *a, s32 mode, s32 flag, s32 d, s32 e, s32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : NULL;
    s32 *g = (t != NULL && t != (s32 *)DldSysUndefSymbol) ? (s32 *)t[4] : NULL;

    if (g != NULL && g[2] != 0) {
        if (mode != *(s32 *)(GetScriptAnimationClass((void *)g[2]) + 0x344)) {
            _SCRStartLWS(g[2], -1, mode, NULL);
            if (flag != 0)
                setGameFlagForGameObj(g[2]);
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncStartEventDemo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0222_SCRFuncUpdatePathSystem", SCRFuncStartEventDemoGameModeCheck);
