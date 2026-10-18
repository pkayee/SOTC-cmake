#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackParticle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackArrow);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraMove);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraVisibility);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraLeave);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ClipEdgeLinkDBFinder);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ConstructorCollisionPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ConstructorCollisionDynamics);

void CopyGeometryPointer();

void CopyCollisionPoint(char *dst, char *src)
{
    CopyGeometryPointer(dst, src);
    *(s128 *)(dst + 0x40) = *(s128 *)(src + 0x40);
}

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
