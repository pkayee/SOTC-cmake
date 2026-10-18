#include "common.h"

s32 ClipCollisionDirectCallBack();
s32 func_400C3C08();

s32 ClipCollisionDirectExceptObj(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    return ClipCollisionDirectCallBack(a0, a1, a2, a3, func_400C3C08, 0, 0, 0, a4);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", func_400C3C08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerPosition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerQuatPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerVirtualSurfacePlane);

void CopyGeometryPointer(void *arg0, void *arg1)
{
    (*(long *)((char *)(arg0) + 0)) = (long) (*(long *)((char *)(arg1) + 0));
    (*(long *)((char *)(arg0) + 8)) = (long) (*(long *)((char *)(arg1) + 8));
    (*(long *)((char *)(arg0) + 0x10)) = (long) (*(long *)((char *)(arg1) + 0x10));
    (*(long *)((char *)(arg0) + 0x18)) = (long) (*(long *)((char *)(arg1) + 0x18));
    (*(long *)((char *)(arg0) + 0x20)) = (long) (*(long *)((char *)(arg1) + 0x20));
    (*(long *)((char *)(arg0) + 0x28)) = (long) (*(long *)((char *)(arg1) + 0x28));
    (*(long *)((char *)(arg0) + 0x30)) = (long) (*(long *)((char *)(arg1) + 0x30));
    (*(long *)((char *)(arg0) + 0x38)) = (long) (*(long *)((char *)(arg1) + 0x38));
}

extern float YUnitVector[];
extern float *GetCollisionDBPlane(void *);
extern float GetPlaneSlopeDegree(float *);

float GetGeometryPointerSurfaceSlopeDegree(char *g)
{
    void *db;
    float *r;
    switch (*(unsigned int *)(g + 0x30)) {
    case 2:
    case 3:
    case 4:
    case 5:
        db = g;
        break;
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
        db = 0;
        break;
    default:
        db = 0;
        break;
    }
    r = YUnitVector;
    if (db != 0)
        r = GetCollisionDBPlane(db);
    return GetPlaneSlopeDegree(r);
}

float *GetGeometryPointerSurfacePlane(char *g)
{
    void *db;
    float *r;
    switch (*(unsigned int *)(g + 0x30)) {
    case 2:
    case 3:
    case 4:
    case 5:
        db = g;
        break;
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
        db = 0;
        break;
    default:
        db = 0;
        break;
    }
    r = YUnitVector;
    if (db != 0)
        r = GetCollisionDBPlane(db);
    return r;
}

extern u8 InitialGeometryPointer[];

void InitGeometryPointer(void *arg0)
{
    (*(long *)((char *)(arg0) + 0)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0));
    (*(long *)((char *)(arg0) + 8)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 8));
    (*(long *)((char *)(arg0) + 0x10)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x10));
    (*(long *)((char *)(arg0) + 0x18)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x18));
    (*(long *)((char *)(arg0) + 0x20)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x20));
    (*(long *)((char *)(arg0) + 0x28)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x28));
    (*(long *)((char *)(arg0) + 0x30)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x30));
    (*(long *)((char *)(arg0) + 0x38)) = (long) (*(long *)((char *)(InitialGeometryPointer) + 0x38));
}

typedef union { s128 q; float f[4]; int i[4]; } Vec4;

void SetGeometryPointerGlobalState(char *pa0, char *pa1, char *pa2)
{
    ((Vec4 *)(pa0 + 0x30))->i[0] = 0;
    ((Vec4 *)(pa0 + 0x0))->q = ((Vec4 *)(pa1 + 0x0))->q;
    ((Vec4 *)(pa0 + 0x10))->q = ((Vec4 *)(pa2 + 0x0))->q;
}

extern s128 All1Vector;
extern void GetMotionNodeGeoToolCoord(void *, void *, s128 *, int, int, int);

void GetGeometryPointerScale(s128 *out, int *g)
{
    s128 a, b;
    if (g[12] == 1)
        GetMotionNodeGeoToolCoord(&a, &b, out, g[0], g[1], 1);
    else
        *out = All1Vector;
}
