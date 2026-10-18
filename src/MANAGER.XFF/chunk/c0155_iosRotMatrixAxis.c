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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPointDistanceSquareFromUnnormalizedPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", GetPointDistanceFromPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0155_iosRotMatrixAxis", MultiMatrixByPlane);

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
