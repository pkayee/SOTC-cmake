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

extern void _resetBaseMoveWork(void *);
extern void func_40112B20();

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", func_40112AF0);
void func_40112AF0(void *w, void *ctrl)
{
    _resetBaseMoveWork(w);
    *(s32 *)((u8 *)ctrl + 0x30) = 0;
    func_40112B20(ctrl);
}

void func_40112B20(void) {
}

extern s32 *ScriptCtrlDef_SCRAccel;
extern s32 *ScriptCtrlDef_SCRDash;
extern void CharaCtrlSetScriptCtrlStatus(void *, s32);

void func_40112B28(u8 *w)
{
    CharaCtrlSetScriptCtrlStatus(*(void **)(w + 8), ScriptCtrlDef_SCRAccel[1]);
    if (*(s32 *)(*(u8 **)(w + 0xCC) + 0x30) != 0) {
        CharaCtrlSetScriptCtrlStatus(*(void **)(w + 8), ScriptCtrlDef_SCRDash[1]);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", getAttainInversePos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcMoveQuaternion);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcNextMotRatio);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcAttainPosForDirExec);

/* NEARMISS-STUB calcMoveAngle */
#if 0 /* NEARMISS 93.81% cat=cse-hoist sub=- | d2 r105: goto-loop (no loop.c: target rematerialises K/DEG/1.0 in the loop, only tgt*r hoisted by hand) reproduces the body; left: t=K reuses the f24 copy of K  | attempts=1 */
extern float fabsf(float);
extern f32 getRatioFromInterp(f32, f32);

f32 calcMoveAngle(f32 tgt, f32 cur, f32 dt, f32 *out, f32 x)
{
    f32 r = getRatioFromInterp(dt, 0.03333333135f);
    f32 sum = 0.0f;
    f32 t = 0.0f;

    if (dt >= 0.03333333135f && fabsf(tgt - cur) > 0.017453292f) {
        t = 0.03333333135f;
        sum += cur * 0.03333333135f;
        if (!(fabsf(sum + x) <= 0.017453292f)) {
            f32 a = tgt * r;
        loop:
            cur = a + cur * (1.0f - r);
            if (fabsf(tgt - cur) > 0.017453292f) {
                t += 0.03333333135f;
                sum += cur * 0.03333333135f;
                if (!(fabsf(sum + x) <= 0.017453292f))
                    goto loop;
            }
        }
    }
    if (out != 0)
        *out = t;
    return sum;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcMoveAngle);

extern float fabsf(float);
extern f32 calcMoveAngle(f32, f32, f32, f32 *, f32);

static inline int chkMoveAngleInl(float angle, float target)
{
    if (fabsf(angle + target) <= 1.7453291e-02f) {
        return 1;
    }
    if ((target >= 0.0f && angle >= 0.0f) || (target <= 0.0f && angle <= 0.0f)) {
        if (fabsf(angle) >= fabsf(target)) {
            return 1;
        }
    }
    return 0;
}

f32 calcAngleTime(f32 x, f32 cur, f32 spd, f32 d)
{
    f32 t;
    f32 r;

    if (x >= 0.0f) {
        r = calcMoveAngle(spd, cur, d, &t, x);
    } else {
        r = calcMoveAngle(-spd, cur, d, &t, x);
    }
    if (chkMoveAngleInl(r, x) != 0) {
        return t;
    }
    return t += fabsf(r + x) / spd;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0215_createHumanCtrlWork", calcProgRotRatio);
