#include "common.h"

/* NEARMISS-STUB RequestCharacterMotionShiftFunc */
#if 0 /* NEARMISS 60.0% cat=regalloc sub=- | xor/movz ternary shape kind==9||0x16 ? p+0x90 : 0; temp in a0/a3 not a2 | attempts=1 */
/* best C (60.5%): RequestCharacterMotionShiftFunc, see cause in RESULT line */
void RequestCharacterMotionShiftFunc(s32 param_1, s32 param_2)
{
    s32 iVar2;
    s8 cVar1;

    iVar2 = param_1 + 0x90;
    if (*(u8 *)(param_1 + 8) != 9 && (iVar2 = 0, *(u8 *)(param_1 + 8) == 0x16))
    {
        iVar2 = param_1 + 0x90;
    }
    cVar1 = *(s8 *)(iVar2 + 0x52D);
    if (cVar1 < 8)
    {
        *(s8 *)(iVar2 + 0x52D) = *(s8 *)(iVar2 + 0x52D) + 1;
        *(s32 *)(cVar1 * 4 + iVar2 + 0x540) = param_2;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", RequestCharacterMotionShiftFunc);

/* NEARMISS-STUB GetCharacterClassNodeQuaternionPos */
#if 0 /* NEARMISS 99.8% cat=regalloc sub=arg reg v1 vs v0 for const 1 store | const 1 in v1 not v0 at sb 0x523 (after GetMotionMatrix call) | attempts=1 */
void GetCharacterClassNodeQuaternionPos(s32 *param_1, s32 *param_2, s32 param_3, s32 param_4, s32 param_5)
{
    if (param_5 != 0)
    {
        *param_1 = *(s32 *)(param_3 + 0x154) + param_4 * 0x10;
        *param_2 = *(s32 *)(param_3 + 0x158) + param_4 * 0x40 + 0x30;
    }
    else
    {
        if (*(s8 *)(param_3 + 0x523) == 0)
        {
            GetMotionMatrix(*(s32 *)(param_3 + 0x340), *(s32 *)(param_3 + 0x344), *(s32 *)(param_3 + 0x354), *(s32 *)(param_3 + 0x33C), param_3 + 0x40, param_3 + 0x90);
            *(u8 *)(param_3 + 0x523) = 1;
        }
        *param_1 = *(s32 *)(param_3 + 0x344) + param_4 * 0x10;
        *param_2 = *(s32 *)(param_3 + 0x340) + param_4 * 0x40 + 0x30;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharacterClassNodeQuaternionPos);
/* NEARMISS-STUB CalcCharacterClassBaseGeo */
#if 0 /* NEARMISS 99.0% cat=regalloc sub=- | const 1 in v1 vs v0 | attempts=1 */
s32 CalcCharacterClassBaseGeo(s32 param_1)
{
    s8 cVar1;

    cVar1 = *(s8 *)(param_1 + 0x523);
    if (cVar1 == 0)
    {
        GetMotionMatrix(*(s32 *)(param_1 + 0x340), *(s32 *)(param_1 + 0x344), *(s32 *)(param_1 + 0x354), *(s32 *)(param_1 + 0x33C), param_1 + 0x40, param_1 + 0x90);
        *(s8 *)(param_1 + 0x523) = 1;
    }
    return cVar1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", CalcCharacterClassBaseGeo);




/* NEARMISS-STUB ResetCharacterClassSyncMode */
#if 0 /* NEARMISS 87.0% cat=sched sub=- | store order after DeleteTwoWayLink | attempts=1 */
void ResetCharacterClassSyncMode(s32 param_1)
{
    if (*(s32 *)(param_1 + 0xC70) != 0)
    {
        DeleteTwoWayLink(param_1 + 0xC80);
        *(s32 *)(param_1 + 0xC70) = 0;
        *(u8 *)(param_1 + 0xD01) = 0;
        *(u8 *)(param_1 + 0xD00) = 0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ResetCharacterClassSyncMode);




/* NEARMISS-STUB SetCharacterClassMotionNormalSyncMode */
#if 0 /* NEARMISS 65.0% cat=regalloc sub=- | s1/s2 swap, const 9 hoist | attempts=1 */
void SetCharacterClassMotionNormalSyncMode(s32 param_1, s32 param_2)
{
    s32 iVar1;

    if (*(s32 *)(param_1 + 0xC70) != 0)
    {
        DeleteTwoWayLink(param_1 + 0xC80);
        *(u8 *)(param_1 + 0xD00) = 0;
        *(s32 *)(param_1 + 0xC70) = 0;
        *(u8 *)(param_1 + 0xD01) = 0;
    }
    iVar1 = param_2 + 0x90;
    if (*(u8 *)(param_2 + 8) != 9 && (iVar1 = 0, *(u8 *)(param_2 + 8) == 0x16))
    {
        iVar1 = param_2 + 0x90;
    }
    AddTwoWayLinkNext(iVar1 + 0xC74, param_1 + 0xC80);
    *(u8 *)(param_1 + 0xD00) = 1;
    *(s32 *)(param_1 + 0xC70) = param_2;
    if (param_2 == 0)
    {
        *(u8 *)(param_1 + 0xD01) = 0;
    }
    else
    {
        iVar1 = param_2 + 0x90;
        if (*(u8 *)(param_2 + 8) != 9 && *(u8 *)(param_2 + 8) != 0x16)
        {
            iVar1 = 0;
        }
        *(u8 *)(param_1 + 0xD01) = *(u8 *)(iVar1 + 0xFD0);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterClassMotionNormalSyncMode);

/* NEARMISS-STUB ResetCharacterClassMotInterpInfo */
#if 0 /* NEARMISS 10.0% cat=regalloc sub=- | 1.0f in f0 swap, store reorder | attempts=1 */
void ResetCharacterClassMotInterpInfo(s32 param_1)
{
    s32 motion;
    f32 val;

    *(s32 *)(param_1 + 0x710) = 0;
    *(f32 *)(param_1 + 0x714) = 1.0f;
    *(s32 *)(param_1 + 0x718) = 0;
    *(s32 *)(param_1 + 0x71C) = 0;
    *(f32 *)(param_1 + 0x72C) = 1.0f;
    motion = *(s32 *)(param_1 + 0x1098);
    val = *(f32 *)(motion + 0x138);
    *(f32 *)(param_1 + 0x734) = 1.0f;
    *(f32 *)(param_1 + 0x730) = val;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ResetCharacterClassMotInterpInfo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ResetCharacterClassSlideStatus);

extern u128 ZeroVector;

void ResetCharacterClassSlideStatus(s32 param_1)
{
    *(u128 *)(param_1 + 0xAA0) = ZeroVector;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ResetCharacterClassMotionInterpRootOfs);

extern u128 ZeroPoint;

void ResetCharacterClassMotionInterpRootOfs(s32 param_1)
{
    s32 motion;

    *(u128 *)(param_1 + 0x6C0) = ZeroPoint;
    motion = *(s32 *)(param_1 + 0x354);
    if (motion != 0)
    {
        *(f32 *)(param_1 + 0x6C4) = *(f32 *)(motion + 0x14);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetScalableTurnQuaternionArray);

/* NEARMISS-STUB GetCharacterClassCurrentAnimationPositionInfo */
#if 0 /* NEARMISS 33.22% cat=call-abi sub=- | float arg to GetMotionRootFloatFrame: target passes float in f12 with a0=p1 unchanged and a2=mode unchanged; our prototype puts shape/branch order differently ( | attempts=1 */
void GetMotionRootFloatFrame(s32 a0, s32 a1, s32 a2, f32 f);
void GetCharacterClassCurrentAnimationPositionInfo(s32 param_1, s32 param_2, s32 param_3)
{
    s32 iVar2;
    s32 uVar1;

    iVar2 = *(s32 *)(param_2 + 0x1C0) + 0x50;
    if (param_3 == 1)
    {
        GetMotionRootFloatFrame(param_1, iVar2, param_3, *(f32 *)(param_2 + 0x1C8));
        return;
    }
    if (param_3 < 2)
    {
        if (param_3 == 0)
        {
            GetMotionRootIntFrame(param_1, iVar2, param_3);
            return;
        }
    }
    else if (param_3 == 2)
    {
        uVar1 = GetMotionResourceFrames(iVar2);
        GetMotionRootIntFrame(param_1, iVar2, uVar1);
        return;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharacterClassCurrentAnimationPositionInfo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharacterClassCurAnimationFrameRate);

s32 GetCharacterClassCurAnimationFrameRate(s32 param_1)
{
    s32 result = 0;

    if (*(s32 *)(param_1 + 0x1C0) != 0)
    {
        result = *(s32 *)(*(s32 *)(param_1 + 0x1C0) + 0x5C);
    }
    return result;
}

s32 GetCharacterClassCurAnimationTotalFrame(s32 param_1)
{
    u8 *base;
    s32 result;
    s32 frames;

    base = (u8 *)param_1 + 0x1C0;
    if (*(s32 *)base != 0)
    {
        frames = GetMotionResourceFrames(*(s32 *)base + 0x50);
        result = (s32)((f32)frames * *(f32 *)(base + 0x2C));
    }
    else
    {
        result = 0;
    }
    return result;
}



//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharacterClassCurAnimationCurFrame);

f32 GetCharacterClassCurAnimationCurFrame(s32 param_1)
{
    u8 *base = (u8 *)param_1 + 0x1C0;

    return *(f32 *)(base + 0x8) * *(f32 *)(base + 0x2C);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", regularizeMatAry);

/* NEARMISS-STUB acceptMotionShiftFunc */
#if 0 /* NEARMISS 87.69% cat=regalloc sub=- | cmp 0x16 emitted as xori not li+xor; movz select copies p+0x90 via a0 not v1 and cVar1 in v1 not a0; target lbu a0 keeps cVar1 in a0 | attempts=1 */
void acceptMotionShiftFunc(s32 param_1)
{
    u8 cVar1;
    s8 cVar5;
    s32 iVar2;
    s32 iVar4;
    s32 *piVar3;

    cVar1 = *(u8 *)(param_1 + 8);
    iVar2 = param_1 + 0x90;
    if (cVar1 != 9)
    {
        iVar2 = 0;
        if (cVar1 == 0x16)
        {
            iVar2 = param_1 + 0x90;
        }
    }
    cVar5 = *(s8 *)(iVar2 + 0x52D);
    if (cVar5 > 0)
    {
        piVar3 = (s32 *)(iVar2 + 0x540);
        iVar4 = cVar5;
        do
        {
            if (*piVar3 != 0)
            {
                ((void (*)(s32))*piVar3)(param_1);
                *piVar3 = 0;
            }
            piVar3++;
        } while (--iVar4 != 0);
    }
    *(s8 *)(iVar2 + 0x52D) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", acceptMotionShiftFunc);

/* NEARMISS-STUB GetCalcNumObjWorkSize */
#if 0 /* NEARMISS 57.9% cat=branch-layout sub=if(p3) movn vs branch | compiler emits movn for if(p3) iVar2=iVar3+0x66; asm uses beqz branch; also register names t0/a4-a6 differ | attempts=1 */
s32 GetCollisionFinderWorkSize();

s32 GetCalcNumObjWorkSize(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;

    iVar2 = param_1 * 0x108 + 0x33;
    iVar3 = iVar2 + param_3 * 8 + (param_1 * 0x10 + 0x80) * param_3;
    if (param_3 != 0)
    {
        iVar2 = iVar3 + 0x66;
    }
    if (param_2 != 0)
    {
        iVar2 = iVar2 + param_2 * 0x13b + 0x33;
    }
    iVar1 = GetCollisionFinderWorkSize(param_4);
    return iVar2 + 0x333 + iVar1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCalcNumObjWorkSize);
/* NEARMISS-STUB GetCharSuspension1D */
#if 0 /* NEARMISS 43.0% cat=call-abi sub=- | args in f16-f19 + raw stack floats | attempts=1 */
f32 GetCharSuspension1D(f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8, f32 *param_9, f32 param_10, f32 param_11)
{
    f32 fVar1;
    f32 fVar2;
    f32 fVar3;

    if (0.0f <= param_1 - param_2)
    {
        param_6 = param_7;
    }
    *param_9 = *param_9 + (param_1 - param_2) * 30.0f * (param_5 + param_6 * (1.0f - param_5));
    fVar3 = param_2 + *param_9 * param_8 * param_10;
    fVar2 = fVar3 - param_3;
    *param_9 = *param_9 * param_8;
    fVar1 = fVar2;
    if (fVar2 < 0.0f)
    {
        fVar1 = -fVar2;
    }
    if (param_4 < fVar1)
    {
        if (fVar2 < 0.0f)
        {
            param_4 = -param_4;
        }
        fVar3 = param_4 + param_3;
        *param_9 = (fVar3 - param_2) * param_11 * param_8;
    }
    return fVar3;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharSuspension1D);

/* NEARMISS-STUB SetCharacterObjControlCallBackFunc */
#if 0 /* NEARMISS 50.0% cat=regalloc sub=- | kind select xori+movz vs xor-reg | attempts=1 */
void SetCharacterObjControlCallBackFunc(s32 param_1, s32 param_2)
{
    s32 iVar1;
    s32 kind;
    s32 base;

    kind = *(u8 *)(param_1 + 8);
    base = param_1 + 0x90;
    iVar1 = base;
    if (kind != 9)
    {
        iVar1 = 0;
        if (kind == 0x16)
        {
            iVar1 = base;
        }
    }
    *(s32 *)(iVar1 + 0x9B8) = param_2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjControlCallBackFunc);



/* NEARMISS-STUB SetCharacterObjControlBypassFunc */
#if 0 /* NEARMISS 50.0% cat=regalloc sub=- | kind select xori+movz vs xor-reg | attempts=1 */
void SetCharacterObjControlBypassFunc(s32 param_1, s32 param_2)
{
    s32 iVar1;

    iVar1 = param_1 + 0x90;
    if (*(u8 *)(param_1 + 8) != 9 && (iVar1 = 0, *(u8 *)(param_1 + 8) == 0x16))
    {
        iVar1 = param_1 + 0x90;
    }
    *(s32 *)(iVar1 + 0x9BC) = param_2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjControlBypassFunc);


/* NEARMISS-STUB ChangeCharacterObjCollisionEnableFlag */
#if 0 /* NEARMISS 91.39% cat=regalloc sub=- | callee-saved regs swapped: ours s2=param_2 s3=param_1, target s2=param_1 (struct base) s3=param_2; xor/movn shape and loop match | attempts=1 */
void ChangeCharacterObjCollisionEnableFlag(s32 param_1, s32 param_2)
{
    s32 iVar2;
    s32 *piVar3;
    s32 iVar4;
    u8 cVar1;

    cVar1 = *(u8 *)(param_1 + 8);
    iVar2 = param_1 + 0x90;
    if (cVar1 != 9 && cVar1 != 0x16)
    {
        iVar2 = 0;
    }
    piVar3 = (s32 *)(iVar2 + 0x5A0);
    for (iVar4 = 3; iVar4 != -1; iVar4--)
    {
        iVar2 = *piVar3++;
        if (iVar2 != 0)
        {
            SetLayoutObjCollisionEnableFlag(iVar2, param_2);
        }
    }
    SetLayoutObjCollisionEnableFlag(param_1, param_2);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ChangeCharacterObjCollisionEnableFlag);

/* NEARMISS-STUB ChangeCharacterObjCollisionResourceAttribute */
#if 0 /* NEARMISS 92.0% cat=regalloc sub=- | saved-arg regs s8 vs s2 | attempts=1 */
void ChangeCharacterObjCollisionResourceAttribute(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
    s32 iVar2;
    s32 *piVar3;
    s32 iVar4;

    iVar2 = param_1 + 0x90;
    if (*(u8 *)(param_1 + 8) != 9 && *(u8 *)(param_1 + 8) != 0x16)
    {
        iVar2 = 0;
    }
    piVar3 = (s32 *)(iVar2 + 0x5A0);
    for (iVar4 = 3; iVar4 != -1; iVar4--)
    {
        iVar2 = *piVar3++;
        if (iVar2 != 0)
        {
            ChangeLayoutObjCollisionResourceAttribute(iVar2, param_2, param_3, param_4, param_5, param_6, param_7);
        }
    }
    ChangeLayoutObjCollisionResourceAttribute(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ChangeCharacterObjCollisionResourceAttribute);

/* NEARMISS-STUB SetCharacterObjCollisionProcFlag */
#if 0 /* NEARMISS 59.8% cat=regalloc sub=p2 kept in s1 across jal | asm keeps param_2 in s1 across FlushCollisionFinder (frame 0x20, sd s1); C proves p2==0 in flush branch so gcc stores constant zero, frame 0x10; also movz for t | attempts=1 */
void FlushCollisionFinder();

void SetCharacterObjCollisionProcFlag(s32 param_1, s32 param_2)
{
    s32 iVar1;

    iVar1 = param_1 + 0x90;
    if (*(u8 *)(param_1 + 8) != 9 && (iVar1 = 0, *(u8 *)(param_1 + 8) == 0x16))
    {
        iVar1 = param_1 + 0x90;
    }
    if (*(s8 *)(iVar1 + 0x51F) == 0)
    {
        *(s8 *)(iVar1 + 0x51F) = param_2;
    }
    else if (param_2 == 0)
    {
        FlushCollisionFinder(iVar1 + 0xD90);
        *(s8 *)(iVar1 + 0x51F) = param_2;
    }
    else
    {
        *(s8 *)(iVar1 + 0x51F) = param_2;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjCollisionProcFlag);
void GetGeometryPointerSurfaceAttribute();

u64 GetGeometryPointerCharColAttr(s32 param_1)
{
    u64 auStack_20[2];

    GetGeometryPointerSurfaceAttribute(auStack_20, param_1);
    return auStack_20[0];
}

/* NEARMISS-STUB GetParentCharColAttr */
#if 0 /* NEARMISS 84.4% cat=no-c-form sub=mid-function glabel func_400587E8 | asm has mid-function glabel func_400587E8 (second entry after lw 0x124, C cannot emit); also movn/beqzl layout and reg order differ | attempts=1 */
u8 *GetLayoutClass();

s32 GetParentCharColAttr(u64 *param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;

    iVar4 = 0;
    iVar1 = (s32)GetLayoutClass(param_2);
    if (iVar1 != 0)
    {
        iVar1 = *(s32 *)(iVar1 + 0x124);
        if (iVar1 != 0)
        {
            iVar2 = *(u8 *)(param_2 + 8);
            iVar3 = param_2 + 0x90;
            if (iVar2 != 9 && iVar2 != 0x16)
            {
                iVar3 = 0;
            }
            if (iVar3 != 0)
            {
                iVar4 = 1;
                *param_1 = *(u64 *)(iVar3 + 0x680);
                return iVar4;
            }
        }
    }
    *param_1 = 0;
    return iVar4;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetParentCharColAttr);
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", PredictMotionGeometryPotential);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", PredictMotionGeometryPotentialWithScaleElem);
