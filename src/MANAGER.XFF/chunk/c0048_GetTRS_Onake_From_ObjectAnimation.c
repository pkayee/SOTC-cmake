#include "common.h"

extern u128 All1Vector;

void func_40043360();
s32 func_40043588();
void func_40044F58();
s32 GetMotionResourceOriginalFrames();
s32 GetMotionResourceFrames();
void ExchangeLWQuaternion();

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetTRS_Onake_From_ObjectAnimation);

/* NEARMISS-STUB func_4004C180 */
#if 0 /* NEARMISS 0.0% cat=vu0-mmi sub=sq-zero | u128 zero store: target is 'sq $zero,0(t0)' (no por/move), ours por v0,zero,zero; sq v0. u128/s128/u_long128/(s64 x2) variants all the same | attempts=1 */
void func_4004C180(s32 a0, u128 *a1, u128 *a2, u128 *a3, u128 *t0, u8 *t1) {
    *a1 = *(u128 *)(t1 + 0x10);
    *a2 = *(u128 *)(t1 + 0x20);
    *a3 = All1Vector;
    *t0 = 0;
    *(f32 *)t0 = *(f32 *)(t1 + 0x50);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C180);

/* NEARMISS-STUB func_4004C1B0 */
#if 0 /* NEARMISS 75.5% cat=bitops sub=sq-zero | see attempt (kX15 haiku best) | attempts=2 */
void func_4004C1B0(s32 a0, u128 *a1, u128 *a2, u128 *a3, u128 *t0, u8 *t1) {
    *a1 = *(u128 *)(t1 + 0x10);
    *a2 = *(u128 *)(t1 + 0x20);
    *a3 = All1Vector;
    *t0 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C1B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C1E0);

/* NEARMISS-STUB func_4004C200 */
#if 0 /* NEARMISS 86.7% cat=float-ops sub=sq-zero | see attempt (kX15 haiku best) | attempts=2 */
void func_4004C200(s32 a0, u128 *a1, u128 *a2, u128 *a3, u128 *t0, u8 *t1) {
    *a1 = *(u128 *)(t1 + 0x10);
    *a2 = *(u128 *)(t1 + 0x20);
    *a3 = *(u128 *)(t1 + 0x30);
    *t0 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C200);

/* NEARMISS-STUB func_4004C228 */
#if 0 /* NEARMISS 86.7% cat=float-ops sub=sq-zero | see attempt (kX15 haiku best) | attempts=2 */
void func_4004C228(s32 a0, u128 *a1, u128 *a2, u128 *a3, u128 *t0, u8 *t1) {
    *a1 = *(u128 *)(t1 + 0x10);
    *a2 = *(u128 *)(t1 + 0x20);
    *a3 = *(u128 *)(t1 + 0x30);
    *t0 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C228);

/* NEARMISS-STUB func_4004C250 */
#if 0 /* NEARMISS 75.5% cat=bitops sub=sq-zero | see attempt (kX15 haiku best) | attempts=2 */
void func_4004C250(s32 a0, u128 *a1, u128 *a2, u128 *a3, u128 *t0, u8 *t1) {
    *a1 = *(u128 *)(t1 + 0x10);
    *a2 = *(u128 *)(t1 + 0x20);
    *a3 = All1Vector;
    *t0 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C250);

/* NEARMISS-STUB func_4004C280 */
#if 0 /* NEARMISS 20.5% cat=bitops sub=sq-zero | see attempt (kX15 haiku best) | attempts=2 */
extern s32 All1Vector;

void func_4004C280(void *a0, u128 *a1, u128 *a2, u128 *a3, u128 *a4, u8 *a5)
{
    *a1 = *(u128 *)(a5 + 0x10);
    *a2 = 0;
    *a3 = *(u128 *)&All1Vector;
    *a4 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C280);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", func_4004C2A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", InterPOrObjectAnimation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", SetTRS_Onake_From_ObjectAnimation);

/* NEARMISS-STUB GetMotionFrameDirectResource */
#if 0 /* NEARMISS 79.9% cat=regalloc sub=- | see attempt (kX15 haiku best) | attempts=1 */
s32 GetMotionFrameDirectResource(f32 f12, f32 f13, f32 *a0, f32 *a1, u8 *a2)
{
    f32 v;
    f32 limit;
    f32 t;
    s32 ret;
    s32 inside;
    s32 n;

    n = *(s16 *)(a2 + 0x4) - 1;
    limit = (f32)n;
    ret = 0;
    *a0 = *a0 + f13 * f12;
    *a1 = *a1 + f13 * f12;
    v = *a0;
    inside = limit <= v;
    if (inside)
    {
        if (n == 0)
        {
            *a0 = 0.0f;
        }
        else if (n < 0)
        {
            *a0 = 0.0f;
        }
        else
        {
            if (v <= limit)
            {
                return 1;
            }
            do
            {
                t = v - limit;
                v = t;
            } while (limit < t);
            *a0 = t;
        }
        ret = 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionFrameDirectResource);

void GetMotionOptionNodeFloatFrameDirectResource(s32 a0, s32 a1, s32 a2, u8 *res, s32 t0) {
    func_40044F58(a0, a1, a2, *(u8 **)(res + 0x1C) + (t0 << 4), *(s16 *)(res + 4));
}

s32 GetMotionOptionNodeParentId(u8 *a, s32 i) {
    return *(s32 *)(*(u8 **)(a + 0x24) + (i << 6) + 0x30);
}

s32 GetMotionResourceFrames() {
    return GetMotionResourceOriginalFrames() - 1;
}

void GetMotionNodeQuaternionPosToolCoord(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *t0) {
    func_40043360(a0, a1, 0, a2, a3, t0);
}

void GetMotionNodeQuaternionPos(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *t0) {
    func_40043360(a0, a1, 0, a2, a3, t0);
    ExchangeLWQuaternion(a0, a0);
}

void GetMotionNodePos(u8 *a1, u8 *a2, u8 *a3, u8 *t0) {
    u8 buf[16];

    func_40043360(buf, a1, 0, a2, a3, t0);
}

void GetMotionNodeGeoToolCoord() {
    func_40043360();
}

int GetMotionNodeIntFrameDirectResource(void *a, char *n, int i, int d)
{
    return func_40043588(a, *(unsigned char *)(*(char **)(n + 8) + i), (*(int **)(n + 0x10))[i], d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionFloatFrameWithLimitCaribration);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionOptionNodeFloatFrame);

s32 GetObjectAnimationParentNodeId(u8 *a, s32 i) {
    s32 *p = *(s32 **)(a + 8);

    if (p == NULL) {
        return -1;
    }
    return p[i];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionRootInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionRootShiftInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionFrame);

/* NEARMISS-STUB GetMotionFrameWithOutsideLimit */
#if 0 /* NEARMISS 93.6% cat=regalloc sub=wrap-loop | see attempt (kX15 haiku best) | attempts=2 */
s32 GetMotionFrameWithOutsideLimit(f32 f12, f32 f13, f32 *a0, f32 *a1, s32 a2)
{
    f32 v;
    f32 limit;
    f32 t;
    s32 ret;
    s32 inside;

    limit = (f32)a2;
    ret = 0;
    *a0 = *a0 + f13 * f12;
    *a1 = *a1 + f13 * f12;
    v = *a0;
    inside = limit <= v;
    if (inside)
    {
        if (a2 == 0)
        {
            *a0 = 0.0f;
        }
        else if (a2 < 0)
        {
            *a0 = 0.0f;
        }
        else
        {
            if (v <= limit)
            {
                return 1;
            }
            do
            {
                t = v - limit;
                v = t;
            } while (limit < t);
            *a0 = t;
        }
        ret = 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionFrameWithOutsideLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetInitialInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionBasePos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionNodeBasePos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0048_GetTRS_Onake_From_ObjectAnimation", GetMotionNodeBaseQuaternion);
