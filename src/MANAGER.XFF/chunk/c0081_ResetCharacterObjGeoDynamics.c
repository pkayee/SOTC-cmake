#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", ResetCharacterObjGeoDynamics);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getvelocity);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_addWindDynamicsToRoot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getPlaneYFittingVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getLocalOffsetFromParentGP);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getCompleteFittingYQFromYDir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_findLocalYGeometryPoint);

typedef union
{
    s128 q;
    float f[4];
    int i[4];
} Vec4;

extern void ClipCollisionFinder(void *, Vec4 *, Vec4 *);

void charrootdyn_findGlobalYGeometryPoint(void *a, void *unused, Vec4 *p, float y)
{
    Vec4 t;

    t.q = p->q;
    t.f[1] += y;
    ClipCollisionFinder(a, p, &t);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_checkIYplane4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_checkIYplane3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_checkIYPlane3DWithPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getCompleteFittingYQFromStabGPWithSlopeLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getCompleteFittingPlaneFromStabGPWithSlopeLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getGPRelativePositionWithQ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0081_ResetCharacterObjGeoDynamics", charrootdyn_getLocalYGlobalXZOffsetFromParentGP);
