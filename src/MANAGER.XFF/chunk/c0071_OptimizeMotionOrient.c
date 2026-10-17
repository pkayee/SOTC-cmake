#include "common.h"

extern s32 D_4012AF14;
extern s32 D_4012AF18;

void *GetCharacterClass(void *obj);
void ForceAcceptMotion(void *obj);
void InitAnimationClass(void *anim, void *param);
void ResetCharacterClassAnimeFrameTableInfo(void *obj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", OptimizeMotionOrient);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", SearchSubAnimation);

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

/* NEARMISS-STUB RequestCharacterClassMotionDirection */
#if 0 /* NEARMISS 60.0% cat=sched sub=- | lq hoisted above addiu/sw; target lq after sw | attempts=1 */
void RequestCharacterClassMotionDirection(void *obj, void *src)
{
    u128 tmp = *(u128 *)src;

    *(s32 *)((u8 *)obj + 0xBD4) = 1;
    *(u128 *)((u8 *)obj + 0xBF0) = tmp;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", RequestCharacterClassMotionDirection);

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

/* NEARMISS-STUB ResetCharacterClassMotionShiftInfo */
#if 0 /* NEARMISS 97.7% cat=regalloc sub=- | s0/s1 swapped (a1 vs obj) | attempts=1 */
void ResetCharacterClassMotionShiftInfo(void *obj, void *param)
{
    ForceAcceptMotion(obj);
    InitAnimationClass((u8 *)obj + 0x1C0, param);
    ResetCharacterClassAnimeFrameTableInfo(obj);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", ResetCharacterClassMotionShiftInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", DebugCallCharacterObjMotionLeaveFunc);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", getTurnLimitInterp);

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

/* NEARMISS-STUB SetMotionMinimumSpeed */
#if 0 /* NEARMISS 98.1% cat=regalloc sub=- | f0/f1 swap for lwc1 vs const | attempts=1 */
void SetMotionMinimumSpeed(void *obj)
{
    u8 *cc = GetCharacterClass(obj);
    f32 v = *(f32 *)(cc + 0x5B8);
    u8 *p = cc + 0x1C0;

    v = 0.01f + v;
    if (*(s8 *)(cc + 0x5D2) != 0)
    {
        *(f32 *)(p + 0x1C) = v;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", SetMotionMinimumSpeed);

/* NEARMISS-STUB SetMotionMaximumSpeed */
#if 0 /* NEARMISS 98.1% cat=regalloc sub=- | f0/f1 swap for lwc1 vs const | attempts=1 */
void SetMotionMaximumSpeed(void *obj)
{
    u8 *cc = GetCharacterClass(obj);
    f32 v = *(f32 *)(cc + 0x5B4);
    u8 *p = cc + 0x1C0;

    v = v - 0.01f;

    if (*(s8 *)(cc + 0x5D2) != 0)
    {
        *(f32 *)(p + 0x1C) = v;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0071_OptimizeMotionOrient", SetMotionMaximumSpeed);

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
