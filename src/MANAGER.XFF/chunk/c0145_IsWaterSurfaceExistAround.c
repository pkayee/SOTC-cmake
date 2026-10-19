#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0145_IsWaterSurfaceExistAround", IsWaterSurfaceExistAround);

extern u8 *GetLayoutClass(s32 id);
extern void func_400A7AE0(void *out, s32 a, u8 *cls, u32 grp, u32 idx);
extern void func_400A8F78(void *out, s32 a, u8 *verts, s32 n, s32 b, u8 *groups, s32 c, s32 d);
extern s32 D_40133D98[];

static inline void collisionDBModelVertex(void *out, u8 *sub, u8 *d, u32 grp, u32 idx)
{
    func_400A8F78(out, 0, *(u8 **)(sub + 0x20) + 0x28, *(s32 *)(*(u8 **)(sub + 0x20) + 0x24), *(s32 *)(sub + 8),
                  *(u8 **)(d + 8), *(s32 *)(d + 0x14),
                  *(s32 *)(d + 0x18) + (*(s32 **)(*(u8 **)(d + 8) + grp * 0x90 + 0x54))[idx] * 0x40);
}

void GetCollisionEdgePointerVertexPoint(s32 *out, s32 *ref)
{
    s32 v[4];
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    s32 e = ref[2];
    u8 *cls = GetLayoutClass(ref[0]);

    if (ref[1] < 0)
    {
        func_400A7AE0(v, 0, cls, grp, idx);
    }
    else
    {
        collisionDBModelVertex(v, cls + 0x154, *(u8 **)(*(u8 **)(cls + 0x184) + 0x20), grp, idx);
    }
    out[0] = v[e];
    out[1] = v[D_40133D98[e]];
}

extern s32 D_40133DA8[];

void GetCollisionEdgePointerVertexPoint3(s32 *out, s32 *ref)
{
    s32 v[4];
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    s32 e = ref[2];
    u8 *cls = GetLayoutClass(ref[0]);

    if (ref[1] < 0)
    {
        func_400A7AE0(v, 0, cls, grp, idx);
    }
    else
    {
        collisionDBModelVertex(v, cls + 0x154, *(u8 **)(*(u8 **)(cls + 0x184) + 0x20), grp, idx);
    }
    out[0] = v[e];
    out[1] = v[D_40133D98[e]];
    out[2] = v[D_40133DA8[e]];
}

typedef struct
{
    s32 obj;
    s32 tri;
    s32 edge;
} CollEdgePtr;

extern s32 GetCollisionEdgePointerOtherSideDBData(CollEdgePtr *out, CollEdgePtr *in);

s32 GetCollisionEdgePointerOtherSideCollisionEdge(CollEdgePtr *out, CollEdgePtr *in)
{
    CollEdgePtr db;
    CollEdgePtr cand;
    CollEdgePtr other;
    CollEdgePtr *c;
    s32 i;

    if (GetCollisionEdgePointerOtherSideDBData(&db, in))
    {
        c = &cand;
        for (i = 0; i < 3; i++)
        {
            c->obj = db.obj;
            c->tri = db.tri;
            c->edge = i;
            if (GetCollisionEdgePointerOtherSideDBData(&other, c) && other.obj == in->obj && other.tri == in->tri)
            {
                out->obj = c->obj;
                out->tri = c->tri;
                out->edge = c->edge;
                return 1;
            }
        }
    }
    out->obj = in->obj;
    out->tri = in->tri;
    out->edge = in->edge;
    return 0;
}

void GetCollisionDBEdgeVertexPoint(s32 *out, s32 *ref, s32 e)
{
    s32 v[4];
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    u8 *cls = GetLayoutClass(ref[0]);

    if (ref[1] < 0)
    {
        func_400A7AE0(v, 0, cls, grp, idx);
    }
    else
    {
        collisionDBModelVertex(v, cls + 0x154, *(u8 **)(*(u8 **)(cls + 0x184) + 0x20), grp, idx);
    }
    out[0] = v[e];
    out[1] = v[D_40133D98[e]];
}

void GetCollisionDBEdgeVertexPoint3(s32 *out, s32 *ref, s32 e)
{
    s32 v[4];
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    u8 *cls = GetLayoutClass(ref[0]);

    if (ref[1] < 0)
    {
        func_400A7AE0(v, 0, cls, grp, idx);
    }
    else
    {
        collisionDBModelVertex(v, cls + 0x154, *(u8 **)(*(u8 **)(cls + 0x184) + 0x20), grp, idx);
    }
    out[0] = v[e];
    out[1] = v[D_40133D98[e]];
    out[2] = v[D_40133DA8[e]];
}

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

typedef struct
{
    s32 id;
    s32 code;
} CollDBRef;

static inline void collisionDBRefCall(void (*cb)(CollDBRef *ref, s32 arg), s32 id, s32 code, s32 arg)
{
    CollDBRef ref;

    ref.id = id;
    ref.code = code;
    cb(&ref, arg);
}

void GetCollisionDBOneObjCallBack(s32 id, void (*cb)(CollDBRef *ref, s32 arg), s32 arg)
{
    u8 *cls = GetLayoutClass(id);
    u8 *d;
    u8 *grp;
    s32 g;
    s32 j;
    s32 n;
    s32 k;

    if (*(s8 *)(cls + 0x1BB) != 0 && *(s8 *)(cls + 0x1B8) != 0)
    {
        d = *(u8 **)(*(u8 **)(cls + 0x184) + 0x20);
        grp = *(u8 **)(d + 8);
        for (g = 0; g < *(s32 *)(d + 4); g++, grp += 0x90)
        {
            if (*(s32 *)(grp + 4) == 0)
            {
                continue;
            }
            if (*(s32 *)(grp + 0x10) != 0)
            {
                for (j = 0; j < *(s32 *)(grp + 0x10); j++)
                {
                    collisionDBRefCall(cb, id, (g << 24) | j | 0x80000000, arg);
                }
            }
            n = *(s32 *)(grp + 0x50);
            if (n != 0)
            {
                for (k = 0; k < n; k++)
                {
                    collisionDBRefCall(cb, id, (g << 24) | k, arg);
                }
            }
        }
    }
}
