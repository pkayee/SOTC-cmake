#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", iosRotMatrixAxis);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", iosRotMatrixFromDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", iosGetMatrixFromDirPosi);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetSpaceTransformMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetSpaceTransformRotMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetVirtualVerticalPlane);

typedef union
{
    s128 q;
    f32 f[4];
    s32 i[4];
} Vec4;

void GetPlaneGlobalYFittingPoint(Vec4 *out, f32 *n, Vec4 *p)
{
    out->q = p->q;
    out->f[1] = -(n[0] * p->f[0] + n[2] * p->f[2] + n[3]) / n[1];
}

/* NEARMISS-STUB GetPointDistanceSquareFromUnnormalizedPlane */
#if 0 /* NEARMISS 47.0% cat=vu0-mmi sub=- | VU0 lqc2/vmul/vaddw/qmfc2 dot-product chain; C gives scalar FPU mul/add | attempts=1 */
f32 GetPointDistanceSquareFromUnnormalizedPlane(Vec4 *plane, Vec4 *point)
{
    f32 d = plane->f[0] * point->f[0] + plane->f[1] * point->f[1] + plane->f[2] * point->f[2] + plane->f[3];
    f32 n = plane->f[0] * plane->f[0] + plane->f[1] * plane->f[1] + plane->f[2] * plane->f[2];
    return (d * d) / n;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPointDistanceSquareFromUnnormalizedPlane);

/* NEARMISS-STUB GetPointDistanceFromPlane */
#if 0 /* NEARMISS 28.3% cat=vu0-mmi sub=- | VU0 macro dot-product chain (lqc2/vmul/vaddax/vmadd/qmfc2); C gives scalar lwc1/mul.s/add.s | attempts=1 */
f32 GetPointDistanceFromPlane(Vec4 *plane, Vec4 *point)
{
    return plane->f[0] * point->f[0] + plane->f[1] * point->f[1] + plane->f[2] * point->f[2] + plane->f[3];
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPointDistanceFromPlane);

/* NEARMISS-STUB MultiMatrixByPlane */
#if 0 /* NEARMISS 0.0% cat=vu0-mmi sub=- | VU0 lqc2/vmul/vmadd/vaddw/qmfc2 dot chain; C gives scalar FPU lwc1/mul.s/add.s | attempts=1 */
void MultiMatrixByPlane(Vec4 *out, Vec4 *m, Vec4 *v)
{
    f32 r[4];
    f32 d;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        r[i] = v->f[0] * m[0].f[i] + v->f[1] * m[1].f[i] + v->f[2] * m[2].f[i] + v->f[3] * m[3].f[i];
    }
    for (i = 0; i < 4; i++)
    {
        out->f[i] = r[i];
    }
    d = r[0] * m[3].f[0] + r[1] * m[3].f[1] + r[2] * m[3].f[2];
    out->f[3] = v->f[3] - d;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", MultiMatrixByPlane);

/* NEARMISS-STUB CompletePlaneD */
#if 0 /* NEARMISS 0.0% cat=vu0-mmi sub=- | VU0 macro chain (lqc2/vmul.xyz/vaddy/vaddz/vsubw/vsubx.w/sqc2); C gives scalar FPU, 0% | attempts=1 */
void CompletePlaneD(Vec4 *plane, Vec4 *point)
{
    f32 d = plane->f[0] * point->f[0] + plane->f[1] * point->f[1] + plane->f[2] * point->f[2];
    plane->f[3] = -1.0f - d;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", CompletePlaneD);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetSTPositionOfVectorPlane);

f32 GetYHeightOfPlaneXZProjection(f32 *arg0, f32 *arg1)
{
    return -(arg0[0] * arg1[0] + arg0[2] * arg1[2] + arg0[3]) / arg0[1];
}

f32 GetYDifferenceOfPlaneXZProjection(f32 *arg0, f32 *arg1)
{
    return -(arg0[0] * arg1[0] + arg0[2] * arg1[2] + arg0[3]) / arg0[1] - arg1[1];
}

/* NEARMISS-STUB GetPlaneFittingDiffVector */
#if 0 /* NEARMISS 12.8% cat=vu0-mmi sub=- | VU0 lqc2/vmul/vaddax/vmadd/qmfc2 dot chain; C gives scalar lwc1/mul.s/add.s | attempts=1 */
void GetPlaneFittingDiffVector(Vec4 *out, Vec4 *n, Vec4 *p)
{
    f32 d = n->f[0] * p->f[0] + n->f[1] * p->f[1] + n->f[2] * p->f[2] + n->f[3];
    out->f[0] = n->f[0] * -d;
    out->f[1] = n->f[1] * -d;
    out->f[2] = n->f[2] * -d;
    out->f[3] = 0.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneFittingDiffVector);
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneFittingPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneFittingPointForUnnormalizedPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneSlopeDegree);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneTopDir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneFittingVector);

extern void GetPlaneTopDir(f32 *, void *);
extern void GetQuaternionByAxisDirZY(void *, f32 *, void *);

void GetPlaneZTopYPlaneCoordQuaternion(void *q, void *plane)
{
    f32 dir[4] __attribute__((aligned(16)));
    GetPlaneTopDir(dir, plane);
    GetQuaternionByAxisDirZY(q, dir, plane);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneReflectionVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetNormalPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPlaneCrossPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetCrossPositionPlaneLine);
