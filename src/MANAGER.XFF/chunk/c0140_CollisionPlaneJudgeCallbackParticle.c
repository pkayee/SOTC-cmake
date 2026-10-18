#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackParticle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackArrow);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraMove);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraVisibility);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraLeave);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ClipEdgeLinkDBFinder);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ConstructorCollisionPoint);

/* NEARMISS-STUB ConstructorCollisionDynamics */
#if 0 /* NEARMISS 85.28% cat=cse-hoist sub=- | dead float 1.0 stores to memset local dropped; const hoist and store order differ | attempts=1 */
void ConstructorCollisionDynamics(s64 *param_1)
{
    s64 local[6];
    float *fl;
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;
    s64 f;

    memset(local, 0, 0x30);
    fl = (float *)local;
    a = local[0];
    b = local[1];
    c = local[2];
    d = local[3];
    e = local[4];
    f = local[5];
    fl[5] = 1.0f;
    param_1[0] = a;
    param_1[1] = b;
    param_1[2] = c;
    param_1[3] = d;
    param_1[4] = e;
    param_1[5] = f;
    fl[3] = 1.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ConstructorCollisionDynamics);

void CopyGeometryPointer();

void CopyCollisionPoint(char *dst, char *src)
{
    CopyGeometryPointer(dst, src);
    *(s128 *)(dst + 0x40) = *(s128 *)(src + 0x40);
}

/* NEARMISS-STUB CopyCollisionDynamics */
#if 0 /* NEARMISS 38.09% cat=call-abi sub=- | target keeps src/dst+0x20 pointers in a2/a3 and loads first 16B into v1; ours uses a1/a0 offsets, v0 | attempts=1 */
void CopyCollisionDynamics(char *dst, char *src)
{
    *(s128 *)(dst + 0x0) = *(s128 *)(src + 0x0);
    *(s128 *)(dst + 0x10) = *(s128 *)(src + 0x10);
    *(s32 *)(dst + 0x20) = *(s32 *)(src + 0x20);
    *(s32 *)(dst + 0x24) = *(s32 *)(src + 0x24);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CopyCollisionDynamics);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", FilterCopyCollisionDynamics);

typedef union
{
    s128 q;
    float f[4];
    s32 i[4];
} Vec4;

float *GetGeometryPointerSurfacePlane(char *);

void ConvertFromCollisionPointToDynamics(char *out, char *point)
{
    Vec4 *plane;
    s32 *tail;

    ((Vec4 *)out)->q = ((Vec4 *)(point + 0x40))->q;
    plane = (Vec4 *)GetGeometryPointerSurfacePlane(point);
    tail = (s32 *)(out + 0x20);
    ((Vec4 *)(out + 0x10))->q = plane->q;

    tail[0] = *(s32 *)point;
    tail[1] = *(s32 *)(point + 4);
}

extern s32 D_4012B328;

void ResetCollisionDebug(void)
{
    D_4012B328 = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", DebugDispCollisionDB);

void triangleDispSetup(void);
void trianglePolyColor(s32, float, float, float, float);
void func_400B40C0(void *, s32, float, float, float, float, float, float, s32, float);

void DebugDispCollisionDBShine(void *db, float f)
{
    triangleDispSetup();
    trianglePolyColor(1, -1.0f, -1.0f, -1.0f, -1.0f);
    func_400B40C0(db, 0, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1, f);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", DebugDispCollisionFinderKeep);
