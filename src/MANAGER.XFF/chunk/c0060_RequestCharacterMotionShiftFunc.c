#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", RequestCharacterMotionShiftFunc);
void RequestCharacterMotionShiftFunc(u8 *obj, s32 func)
{
    u8 *cc = chrClass(obj);
    s8 n = cc[0x52D];

    if (n < 8)
    {
        cc[0x52D]++;
        *(s32 *)(cc + n * 4 + 0x540) = func;
    }
}

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
extern void GetMotionMatrix(s32, s32, s32, s32, u8 *, u8 *);

s32 CalcCharacterClassBaseGeo(u8 *obj)
{
    s32 r = *(s8 *)(obj + 0x523);

    if (r == 0)
    {
        GetMotionMatrix(*(s32 *)(obj + 0x340), *(s32 *)(obj + 0x344), *(s32 *)(obj + 0x354), *(s32 *)(obj + 0x33C), obj + 0x40, obj + 0x90);
        obj[0x523] = 1;
    }
    return r;
}




//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ResetCharacterClassSyncMode);
void ResetCharacterClassSyncMode(s32 param_1)
{
    if (*(s32 *)(param_1 + 0xC70) != 0)
    {
        DeleteTwoWayLink(param_1 + 0xC80);
        *(u8 *)(param_1 + 0xD00) = 0;
        *(s32 *)(param_1 + 0xC70) = 0;
        *(u8 *)(param_1 + 0xD01) = 0;
    }
}




/* NEARMISS-STUB SetCharacterClassMotionNormalSyncMode */
#if 0 /* NEARMISS 94.41% cat=regalloc sub=- | first class select is movz form (a0=0 default) vs chrClass movn form | attempts=2 */

void SetCharacterClassMotionNormalSyncMode(s32 param_1, s32 param_2)
{
    u8 *cc;

    if (*(s32 *)(param_1 + 0xC70) != 0)
    {
        DeleteTwoWayLink(param_1 + 0xC80);
        *(u8 *)(param_1 + 0xD00) = 0;
        *(s32 *)(param_1 + 0xC70) = 0;
        *(u8 *)(param_1 + 0xD01) = 0;
    }
    cc = chrClass((u8 *)param_2);
    AddTwoWayLinkNext(cc + 0xC74, param_1 + 0xC80);
    *(u8 *)(param_1 + 0xD00) = 1;
    *(s32 *)(param_1 + 0xC70) = param_2;
    if (param_2 != 0)
    {
        cc = chrClass((u8 *)param_2);
        *(u8 *)(param_1 + 0xD01) = *(u8 *)(cc + 0xFD0);
    }
    else
    {
        *(u8 *)(param_1 + 0xD01) = 0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterClassMotionNormalSyncMode);

/* NEARMISS-STUB ResetCharacterClassMotInterpInfo */
#if 0 /* NEARMISS 10.75% cat=float-ops sub=- | 1.0f in f1 and motion float in f0 vs reverse; store slots differ | attempts=2 */

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

void GetMotionRootIntFrame(s32 a0, s32 a1, s32 a2);
void GetMotionRootFloatFrame(s32 a0, s32 a1, s32 a2, f32 f);
s32 GetMotionResourceFrames();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCharacterClassCurrentAnimationPositionInfo);
void GetCharacterClassCurrentAnimationPositionInfo(s32 param_1, u8 *param_2, s32 param_3)
{
    u8 *base;
    s32 iVar2;
    s32 uVar1;

    base = param_2 + 0x1C0;
    iVar2 = *(s32 *)base + 0x50;
    switch (param_3)
    {
        case 0:
            GetMotionRootIntFrame(param_1, iVar2, param_3);
            return;
        case 1:
            GetMotionRootFloatFrame(param_1, iVar2, param_3, *(f32 *)(base + 0x8));
            return;
        case 2:
            uVar1 = GetMotionResourceFrames(iVar2);
            GetMotionRootIntFrame(param_1, iVar2, uVar1);
            return;
    }
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", acceptMotionShiftFunc);
void acceptMotionShiftFunc(u8 *obj)
{
    u8 *cc = chrClass(obj);
    s8 cVar1;
    s32 iVar2;
    s32 *piVar3;

    cVar1 = *(s8 *)(cc + 0x52D);
    if (cVar1 > 0)
    {
        piVar3 = (s32 *)(cc + 0x540);
        iVar2 = cVar1;
        do
        {
            if (*piVar3 != 0)
            {
                ((void (*)(u8 *))*piVar3)(obj);
                *piVar3 = 0;
            }
            piVar3++;
        } while (--iVar2 != 0);
    }
    *(s8 *)(cc + 0x52D) = 0;
}

/* NEARMISS-STUB GetCalcNumObjWorkSize */
#if 0 /* NEARMISS 63.23% cat=branch-layout sub=if(p3) movn vs branch | if(p3) if-converted to movn vs target beqz branch; t0/s0 regalloc | attempts=2 */
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
    iVar2 = iVar2 + 0x333;
    iVar1 = GetCollisionFinderWorkSize(param_4);
    return iVar2 + iVar1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetCalcNumObjWorkSize);
/* NEARMISS-STUB GetCharSuspension1D */
#if 0 /* NEARMISS 43.57% cat=branch-layout sub=- | if(x>=0) if-converted (c.le.s bc1tl) vs target c.lt.s bc1f real branches | attempts=2 */

f32 GetCharSuspension1D(f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8, f32 *param_9, f32 param_10, f32 param_11)
{
    f32 fVar1;
    f32 fVar2;
    f32 fVar3;

    if (param_1 - param_2 >= 0.0f)
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjControlCallBackFunc);
void SetCharacterObjControlCallBackFunc(u8 *obj, s32 f)
{
    *(s32 *)(chrClass(obj) + 0x9B8) = f;
}



//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjControlBypassFunc);
void SetCharacterObjControlBypassFunc(u8 *obj, s32 f)
{
    u8 *cc = chrClass(obj);

    *(s32 *)(cc + 0x9BC) = f;
}


//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ChangeCharacterObjCollisionEnableFlag);
void ChangeCharacterObjCollisionEnableFlag(u8 *obj, s32 param_2)
{
    u8 *cc = chrClass(obj);
    s32 *piVar3;
    s32 iVar4;
    s32 iVar2;

    piVar3 = (s32 *)(cc + 0x5A0);
    for (iVar4 = 3; iVar4 != -1; iVar4--)
    {
        iVar2 = *piVar3++;
        if (iVar2 != 0)
        {
            SetLayoutObjCollisionEnableFlag(iVar2, param_2);
        }
    }
    SetLayoutObjCollisionEnableFlag(obj, param_2);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", ChangeCharacterObjCollisionResourceAttribute);
void ChangeCharacterObjCollisionResourceAttribute(u8 *obj, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
    u8 *cc = chrClass(obj);
    s32 *piVar3;
    s32 iVar4;
    s32 iVar2;

    piVar3 = (s32 *)(cc + 0x5A0);
    for (iVar4 = 3; iVar4 != -1; iVar4--)
    {
        iVar2 = *piVar3++;
        if (iVar2 != 0)
        {
            ChangeLayoutObjCollisionResourceAttribute(iVar2, param_2, param_3, param_4, param_5, param_6, param_7);
        }
    }
    ChangeLayoutObjCollisionResourceAttribute(obj, param_2, param_3, param_4, param_5, param_6, param_7);
}

void FlushCollisionFinder();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", SetCharacterObjCollisionProcFlag);
void SetCharacterObjCollisionProcFlag(s32 param_1, s32 param_2)
{
    u8 *cc = chrClass((u8 *)param_1);

    if (*(s8 *)(cc + 0x51F) != 0 && param_2 == 0)
    {
        FlushCollisionFinder(cc + 0xD90);
    }
    *(s8 *)(cc + 0x51F) = param_2;
}
void GetGeometryPointerSurfaceAttribute();

u64 GetGeometryPointerCharColAttr(s32 param_1)
{
    u64 auStack_20[2];

    GetGeometryPointerSurfaceAttribute(auStack_20, param_1);
    return auStack_20[0];
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", GetParentCharColAttr);
u8 *GetLayoutClass();

s32 GetParentCharColAttr(u64 *param_1, u8 *obj)
{
    u8 *layout;
    u8 *cc;

    layout = GetLayoutClass(obj);
    if (layout != NULL)
    {
        if (*(s32 *)(layout + 0x124) != 0)
        {
            cc = chrClass(obj);
            if (cc != NULL)
            {
                *param_1 = *(u64 *)(cc + 0x680);
                return 1;
            }
        }
    }
    *param_1 = 0;
    return 0;
}
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", PredictMotionGeometryPotential);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0060_RequestCharacterMotionShiftFunc", PredictMotionGeometryPotentialWithScaleElem);
