#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", IsWaterSurfaceExistAround);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionEdgePointerVertexPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionEdgePointerVertexPoint3);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionEdgePointerOtherSideCollisionEdge);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionDBEdgeVertexPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionDBEdgeVertexPoint3);

void CopyCollisionEdgePointer(void *arg0, void *arg1)
{
    (*(int *)((char *)(arg0) + 0)) = (int) (*(int *)((char *)(arg1) + 0));
    (*(int *)((char *)(arg0) + 4)) = (int) (*(int *)((char *)(arg1) + 4));
    (*(int *)((char *)(arg0) + 8)) = (int) (*(int *)((char *)(arg1) + 8));
}

void CopyCollisionEdge(void *arg0, void *arg1)
{
    (*(int *)((char *)(arg0) + 0)) = (int) (*(int *)((char *)(arg1) + 0));
    (*(int *)((char *)(arg0) + 4)) = (int) (*(int *)((char *)(arg1) + 4));
    (*(int *)((char *)(arg0) + 8)) = (int) (*(int *)((char *)(arg1) + 8));
    (*(int *)((char *)(arg0) + 0xC)) = (int) (*(int *)((char *)(arg1) + 0xC));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionEdgePositionWithS);

void MakeCollisionEdgePointer(char *pa0, char *pa1, int xa2)
{
    *(int *)(pa0 + 0x0) = *(int *)(pa1 + 0x0);
    *(int *)(pa0 + 0x4) = *(int *)(pa1 + 0x4);
    *(int *)(pa0 + 0x8) = xa2;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionVariableXZSurfPosition);

int IsClusterCollision(void *arg0)
{
    return (*(int *)((char *)(arg0) + 4)) >= 2;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", MakeGeometryPointerCollisionInfo);

/* NEARMISS-STUB MakeGeometryPointerCollisionEdgeInfo */
#if 0 /* NEARMISS 0.0% cat=sched sub=- | swc1 scheduled early; target stores float after 0x8 store | attempts=1 */
void MakeGeometryPointerCollisionEdgeInfo(char *pa0, char *pa1, int xa2, float fa3)
{
    *(int *)(pa0 + 0x0) = *(int *)(pa1 + 0x0);
    *(int *)(pa0 + 0x4) = *(int *)(pa1 + 0x4);
    *(int *)(pa0 + 0x8) = *(int *)(pa1 + 0x8);
    *(int *)(pa0 + 0x30) = 4;
    *(int *)(pa0 + 0x10) = xa2;
    *(float *)(pa0 + 0xC) = fa3;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", MakeGeometryPointerCollisionEdgeInfo);

int CheckLegalCollisionGP(char *gp);

int GetGeometryPointerCollisionSurfSTPosition(float *arg0, float *arg1, void *arg2)
{
    if (CheckLegalCollisionGP(arg2) != 0) {
        *arg0 = (*(float *)((char *)(arg2) + 8));
        *arg1 = (*(float *)((char *)(arg2) + 0xC));
        return 0;
    }
    return -1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", GetCollisionDBOneObjCallBack);
