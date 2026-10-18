#include "common.h"

extern s32 D_4012AF14;
extern s32 D_4012AF18;

void *GetCharacterClass(void *obj);
void ForceAcceptMotion();
void InitAnimationClass(void *anim, void *param);
void ResetCharacterClassAnimeFrameTableInfo(void *obj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", OptimizeMotionOrient);

typedef struct
{
    s32 a;
    s32 id;
    s8 pad[0x3C];
    s32 state;
    s8 pad2[0x38];
} SubAnim;

s32 SearchSubAnimation(s8 *c, s32 id)
{
    s32 i;
    SubAnim *s = *(SubAnim **)(c + 0x308);

    for (i = 0; i < *(s32 *)(c + 0x3EC); i++, s++)
    {
        if (s->state != -2 && s->id == id)
        {
            return i;
        }
    }
    return -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassSlip);
void RequestCharacterClassSlip(void *obj)
{
    if (*(s8 *)((u8 *)obj + 0xC16) == 0)
    {
        *(s8 *)((u8 *)obj + 0xC16) = 1;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassNoClimbableSlip);
void RequestCharacterClassNoClimbableSlip(void *obj)
{
    *(s8 *)((u8 *)obj + 0xC16) = 2;
}

/* NEARMISS-STUB RequestCharacterClassMotionChange */
#if 0 /* NEARMISS 81.8% cat=sched sub=- | sw a1 hoisted above addiu 0xBC0 | attempts=1 */
void RequestCharacterClassMotionChange(void *obj, s32 a1, s32 a2)
{
    u8 *cnt = (u8 *)obj + 0xBC0;

    *(s32 *)((u8 *)obj + 0xBC4) = a1;
    *(s32 *)((u8 *)obj + 0xBC8) = a2;
    if (*(s8 *)cnt <= 0)
    {
        *cnt = *cnt + 1;
    }
    *(s8 *)((u8 *)obj + 0xBCC) = 0;
    *(s32 *)((u8 *)obj + 0xBD0) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionChange);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassAdditionMotionChange);
void RequestCharacterClassAdditionMotionChange(void *obj, s32 a1)
{
    s32 n = *(s8 *)((u8 *)obj + 0xC14);

    if (n < *(s32 *)((u8 *)obj + 0x3EC))
    {
        s32 *list = *(s32 **)((u8 *)obj + 0x304);

        list[n] = a1;
        *(u8 *)((u8 *)obj + 0xC14) = *(u8 *)((u8 *)obj + 0xC14) + 1;
    }
}

/* NEARMISS-STUB RequestCharacterClassMotionChangeWithParam */
#if 0 /* NEARMISS 83.3% cat=sched sub=- | sw a1 hoisted above addiu 0xBC0 | attempts=1 */
void RequestCharacterClassMotionChangeWithParam(void *obj, s32 a1, s32 a2, f32 f)
{
    u8 *cnt = (u8 *)obj + 0xBC0;

    *(s32 *)((u8 *)obj + 0xBC4) = a1;
    *(s32 *)((u8 *)obj + 0xBC8) = a2;
    if (*(s8 *)cnt <= 0)
    {
        *cnt = *cnt + 1;
    }
    *(f32 *)((u8 *)obj + 0xBD0) = f;
    *(s8 *)((u8 *)obj + 0xBCC) = 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionChangeWithParam);

typedef union
{
    s128 q;
    float f[4];
    int i[4];
} Vec4;

void RequestCharacterClassMotionDirection(char *p, Vec4 *v)
{
    ((Vec4 *)(p + 0xBD0))->i[1] = 1;
    ((Vec4 *)(p + 0xBF0))->q = v->q;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionDirectionByGPTop);
void RequestCharacterClassMotionDirectionByGPTop(void *obj)
{
    *(s32 *)((u8 *)obj + 0xBD4) = 3;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionDirectionByGPTail);
void RequestCharacterClassMotionDirectionByGPTail(void *obj)
{
    *(s32 *)((u8 *)obj + 0xBD4) = 4;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionDirectionByGPAirBalanceDir);
void RequestCharacterClassMotionDirectionByGPAirBalanceDir(void *obj)
{
    *(s32 *)((u8 *)obj + 0xBD4) = 5;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionTurnLevel);
void RequestCharacterClassMotionTurnLevel(void *obj, f32 f)
{
    *(f32 *)((u8 *)obj + 0xBE0) = f;
    *(s32 *)((u8 *)obj + 0xBD4) = 2;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassRootOffset);
void RequestCharacterClassRootOffset(void *obj, void *src)
{
    *(u128 *)((u8 *)obj + 0xC00) = *(u128 *)src;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionPlaySpeedUp);
void RequestCharacterClassMotionPlaySpeedUp(void *obj)
{
    *(s32 *)((u8 *)obj + 0xC10) = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionPlaySpeedDown);
void RequestCharacterClassMotionPlaySpeedDown(void *obj)
{
    *(s32 *)((u8 *)obj + 0xC10) = -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionPlaySpeedDown2);
void RequestCharacterClassMotionPlaySpeedDown2(void *obj)
{
    *(s32 *)((u8 *)obj + 0xC10) = -2;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassWindForceMove);
void RequestCharacterClassWindForceMove(void *obj)
{
    *(s8 *)((u8 *)obj + 0xC15) = 1;
}

void ResetCharacterClassMotionShiftInfo(void *obj, void *param)
{
    /* the original calls it with no argument: the asm never reloads a0 before this jal */
    ForceAcceptMotion();
    InitAnimationClass((u8 *)obj + 0x1C0, param);
    ResetCharacterClassAnimeFrameTableInfo(obj);
}

s32 CallMotShiftCallBackElemLeaveFunc(void *list, s32 id, void *ctx);

int DebugCallCharacterObjMotionLeaveFunc(void *object)
{
    int remaining = 1;
    char *character = GetCharacterClass(object);
    char *motion = *(char **)(character + 0x1C0);
    void (**callback)(void *) = (void (**)(void *))(motion + 0xBC);

    do
    {
        void (*leave)(void *) = *callback++;

        if (leave)
        {
            leave(object);
        }
    } while (--remaining >= 0);
    return CallMotShiftCallBackElemLeaveFunc(character + 0x2C4, (int)motion, object);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", SetCharacterObjDemoCutFinishFlag);
void SetCharacterObjDemoCutFinishFlag(void *obj, s32 flag)
{
    *(u8 *)((u8 *)GetCharacterClass(obj) + 0x1000) = flag;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", CancelCharacterClassMotionChange);
void CancelCharacterClassMotionChange(void *obj)
{
    *(s8 *)((u8 *)obj + 0xBC0) = 0;
    *(s8 *)((u8 *)obj + 0xBCC) = 0;
    *(s32 *)((u8 *)obj + 0xBD0) = 0;
}

float getTurnLimitInterp(float from, float to, float time, float elapsed)
{
    float t;

    if (time <= 0.001f)
    {
        return to;
    }
    t = elapsed / time;
    t = (t <= 1.0f) ? t : 1.0f;
    return to * t + from * (1.0f - t);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", getRatioFromInterp);
f32 getRatioFromInterp(f32 a, f32 b)
{
    f32 r;

    if (a <= 0.001f)
    {
        return 1.0f;
    }
    r = b / a;
    if (!(r <= 1.0f))
    {
        r = 1.0f;
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", PredictMotionChangeState);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", FinishCharacterObjAllAdditionMotion);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", getMotionInterpMode);
s32 *getMotionInterpMode(void)
{
    return &D_4012AF14;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", getJumpSpeedLimitEnableFlag);
s32 *getJumpSpeedLimitEnableFlag(void)
{
    return &D_4012AF18;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", entrySyncAnim);

void SetMotionMinimumSpeed(void *actor)
{
    char *c = GetCharacterClass(actor);
    char *m = c + 0x1C0;
    float v = *(float *)(c + 0x5B8) + 0.01f;
    if (*(signed char *)(c + 0x5D2) != 0)
        *(float *)(m + 0x1C) = v;
}

void SetMotionMaximumSpeed(void *actor)
{
    char *c = GetCharacterClass(actor);
    char *m = c + 0x1C0;
    float v = *(float *)(c + 0x5B4) - 0.01f;
    if (*(signed char *)(c + 0x5D2) != 0)
        *(float *)(m + 0x1C) = v;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", ContinueMotionCurrentSpeed);
void ContinueMotionCurrentSpeed(void *obj)
{
    u8 *cc = GetCharacterClass(obj);
    u8 *p = cc + 0x1C0;
    f32 v = *(f32 *)(cc + 0x5B0);

    if (*(s8 *)(cc + 0x5D2) != 0)
    {
        *(f32 *)(p + 0x1C) = v;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", checkShift);
