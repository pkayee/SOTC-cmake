#include "common.h"

s64 chkCurveCollision(float arg);

extern const f32 D_40137590;

void _setExecBaseMoveWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 4) = arg1;
}

void _setStopCtrlModeBaseMoveWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x20) = arg1;
}

s32 _getStopCtrlModeBaseMoveWork(void *arg0)
{
    return *(s32 *)((u8 *)arg0 + 0x20);
}

void _setBackVolumeBaseMoveWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x24) = arg1;
}

void _setSlideVolumeBaseMoveWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x28) = arg1;
}

s32 func_40105C78(void *arg0);

s32 _resetBaseMoveWork(s32 arg0, void *arg1)
{
    *(s32 *)((u8 *)arg1 + 4) = 0;
    *(s32 *)((u8 *)arg1 + 0x24) = 0;
    return func_40105C78(arg1);
}

extern s32 *ScriptCtrlDef_SCRSlowDown;
extern s32 *ScriptCtrlDef_SCRStop;
u8 *GetCharacterClass(void *chara);
void CharaCtrlSetScriptCtrlStatus(void *chara, s32 status);

s32 _sendStopKeyMoveWork(void *o, s32 *w, s32 slow)
{
    u8 *c = GetCharacterClass(o);

    if (w[1] != 0)
    {
        return 0;
    }
    if (*(s32 *)(c + 0x740) == w[8])
    {
        return 1;
    }
    if (slow != 0)
    {
        CharaCtrlSetScriptCtrlStatus(o, ScriptCtrlDef_SCRSlowDown[1]);
    }
    else
    {
        CharaCtrlSetScriptCtrlStatus(o, ScriptCtrlDef_SCRStop[1]);
    }
    return 0;
}

s32 memcmp(const void *a, const void *b, u32 n);

s32 _compPassagePos(char **p)
{
    char *q = p[3];

    if (q != 0)
    {
        if (memcmp(p[0] + 0x10, q, 12) != 0)
        {
            return 1;
        }
    }
    return 0;
}

s32 _getExecBaseMoveWork(void *arg0)
{
    return *(s32 *)((u8 *)arg0 + 4);
}

void _setAttainFlagBaseMoveWork(s32 *arg0, s32 arg1)
{
    *arg0 = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", _initBaseMoveTmpWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", analyzeMotionPropertyFromKey2);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", estimateAttainPos2);

float calcAngleTime(float angle, float a, float b, float c);

float calcTurnTime2(char *obj, float angle)
{
    return calcAngleTime(angle, *(float *)(obj + 0xA8), *(float *)(obj + 0xA4),
                         *(float *)(**(char ***)(obj + 0x1C) + 0x78));
}

float calcMoveAngle(s32 arg0, float a, float b, float c, float d);
extern const f32 D_40137588;

float calcMoveTurnAngle2(char *p, float a)
{
    return calcMoveAngle(0, a, *(float *)(p + 0xA8), *(float *)(**(char ***)(p + 0x1C) + 0x78), D_40137588);
}

/* decls are inside the body on purpose: apply_ready skips top-level decls whose name appears in the parked NEARMISS stub above
   (gcGlobalVar, calcProgRotRatio) and then deletes the stub, leaving the TU without them */
void calcProgRotRatioForMove2(char *obj, f32 f)
{
    extern u8 gcGlobalVar[];
    void calcProgRotRatio(f32 a, f32 b, f32 c, f32 d, f32 e);

    calcProgRotRatio(f, *(f32 *)(obj + 0xA4), *(f32 *)(gcGlobalVar + 0x190), *(f32 *)(obj + 0xA8),
                     *(f32 *)(**(char ***)(obj + 0x1C) + 0x78));
}

float adjustCurveAngleForCollision(float ang, float lim, float x)
{
    if (lim < __builtin_fabsf(ang))
    {
        switch (chkCurveCollision(x))
        {
        case 3:
            if (ang < 0.0f)
            {
                ang = ang + 6.2831851f;
            }
            break;
        case 2:
            if (0.0f < ang)
            {
                ang = ang + -6.2831851f;
            }
            break;
        }
    }
    return ang;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", calcDownSpeedRatio);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", getHitPosWayCollision);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", moveCtrlClipCollisionDirect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", _initMovePathWork);

extern void *GetCollisionDBPlane(void *);
extern void iosApplyRotMatrix(void *, void *, void *);
extern f32 GetPlaneSlopeDegree(void *);

s32 moveCtrlWallJudgeFunc(void *col, void *w)
{
    f32 plane[4];

    iosApplyRotMatrix(plane, w, GetCollisionDBPlane(col));
    if (__builtin_fabsf(GetPlaneSlopeDegree(plane)) <= *(f32 *)((u8 *)w + 0x40))
    {
        return 0;
    }
    return 1;
}

s32 func_40105C78(void *arg0)
{
    *(f32 *)((u8 *)arg0 + 0x1C) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x10) = D_40137590;
    *(f32 *)((u8 *)arg0 + 0x14) = D_40137590;
    *(f32 *)((u8 *)arg0 + 0x18) = D_40137590;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0204__setExecBaseMoveWork", createBirdCtrlWork);
