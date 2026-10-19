#include "common.h"

typedef union { s128 q; float f[4]; int i[4]; } Vec4;

void SetGeometryPointerGlobalStatePointer(Vec4 *p, int a, int b, Vec4 *u, Vec4 *v)
{
    p[0].i[0] = a;
    p[3].i[0] = 6;
    p[0].i[1] = b;
    p[1].q = u->q;
    p[2].q = v->q;
}

void SetGeometryPointerGlobalStatePosPointer(Vec4 *p, int a, int b, Vec4 *u, Vec4 *v)
{
    p[0].i[0] = a;
    p[3].i[0] = 7;
    p[0].i[1] = b;
    p[1].q = u->q;
    p[2].q = v->q;
}

void *GetGeometryPointerObject(char *g)
{
    switch (*(unsigned int *)(g + 0x30)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
        return *(void **)g;
    case 6:
    case 7:
        break;
    }
    return 0;
}

int GetGeometryPointerObjectParentNodeId(char *p)
{
    if (*(int *)(p + 0x30) != 1) {
        return -1;
    }
    return *(int *)(p + 0x4);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", ConvertGeometryPointerZNormalMode);

extern void GetCollisionDBAttribute(s128 *, void *);

void GetGeometryPointerSurfaceAttribute(s128 *out, char *g)
{
    void *db;
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
    if (db != 0) {
        GetCollisionDBAttribute(out, db);
        return;
    }
    *out = 0;
}

extern float YUnitVector[];
extern float *GetCollisionDBPlane(char *);
extern void GetPlaneZTopYPlaneCoordQuaternion(void *, float *);

void GetGeometryPointerSurfaceZTopYPlaneCoordQuaternion(void *out, char *g)
{
    char *p;
    float *v;
    switch (*(int *)(g + 0x30)) {
    case 2:
    case 3:
    case 4:
    case 5:
        p = g;
        break;
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
    default:
        p = 0;
        break;
    }
    v = YUnitVector;
    if (p != 0)
        v = GetCollisionDBPlane(p);
    GetPlaneZTopYPlaneCoordQuaternion(out, v);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetGeometryPointerSurfaceYTopZMinusPlaneCoordQuaternion);

void SetGeometryPointerNodePosState(Vec4 *p, int a, int b, Vec4 *u, Vec4 *v)
{
    p[0].i[0] = a;
    p[3].i[0] = 1;
    p[0].i[1] = b;
    p[1].q = u->q;
    p[2].q = v->q;
}

void SetGeometryPointerNodePosStateGlobalRot(Vec4 *p, int a, int b, Vec4 *u, Vec4 *v)
{
    p[0].i[0] = a;
    p[3].i[0] = 8;
    p[0].i[1] = b;
    p[1].q = u->q;
    p[2].q = v->q;
}

void SetGeometryPointerChainPos(char *pa0, int xa1, int xa2, float f12)
{
    *(int *)(pa0 + 0x30) = 9;
    *(int *)(pa0 + 0x0) = xa1;
    *(int *)(pa0 + 0x4) = xa2;
    *(float *)(pa0 + 0x8) = f12;
}

void *GetGeometryPointerCollisionDB(char *g)
{
    switch (*(unsigned int *)(g + 0x30)) {
    case 2:
    case 3:
    case 4:
    case 5:
        return g;
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
        break;
    }
    return 0;
}

extern float ZeroPoint[];
extern void *GetLayoutObjCollisionDBWithTargetAttributeJudgeFunc(void *, void *, void *, void *);
extern void MakeGeometryPointerCollisionInfo(void *, float *, void *, float, float);

void *GetGeometryPointerWithCollisionAttributeJudgeFunc(void *g, void *a, void *b, void *c)
{
    char buf[0x10] __attribute__((aligned(16)));
    void *db = GetLayoutObjCollisionDBWithTargetAttributeJudgeFunc(buf, a, b, c);
    if (db != 0)
        MakeGeometryPointerCollisionInfo(g, ZeroPoint, buf, 0.0f, 0.0f);
    return db;
}

int CheckLegalCollisionGP(char *gp)
{
    int type = *(int *)(gp + 0x30);
    switch (type) {
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    }
    return 0;
}

typedef struct {
    u64 d[8];
} GpCopy;

extern s32 GetCollisionEdgePointerOtherSideCollisionEdge(void *, void *);
extern void MakeGeometryPointerCollisionEdgeInfo(void *, void *, s32, f32);

s32 ExchangeGeometryPointerCollisionEdgeOtherSideInfo(GpCopy *dst, GpCopy *src)
{
    u8 edge[16];

    if (GetCollisionEdgePointerOtherSideCollisionEdge(edge, src) != 0) {
        MakeGeometryPointerCollisionEdgeInfo(dst, edge, *(s32 *)((u8 *)src + 0x10) == 0, *(f32 *)((u8 *)src + 0xC));
        return 1;
    }
    *dst = *src;
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetMultiLocalizeMatrix);

typedef struct { float m[16]; } Mat;
void iosCopyMatrix(void *dst, void *src);

void CopyMultiMatrix(Mat *d, Mat *s, int n)
{
    while (n-- != 0) {
        iosCopyMatrix(d, s);
        d++;
        s++;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetMoveVectorOnWV);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetXZVectorOnWV);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", ClipPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetArbitraryDirectionMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0154_SetGeometryPointerGlobalStatePointer", GetArbitraryDirectionInverseMatrix);
