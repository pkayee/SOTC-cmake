#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", SetCharacterClassWindDynamics);

void charrootdyn_setEdgeUpperPlaneInfoFlag(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = 1;
}

void charrootdyn_resetEdgeUpperPlaneInfoFlag(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_setVColFindFlag);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_resetHColFindFlag);

extern void DeleteTwoWayLink(void *);

void charrootdyn_resetVColFindFlag(char *p)
{
    if (*(int *)(p + 0xDB0) != 0) {
        *(int *)(p + 0xDB0) = 0;
        DeleteTwoWayLink(p + 0xEB0);
    }
}

void charrootdyn_resetVColEdgeFindFlag(char *p)
{
    if (*(int *)(p + 0xE30) != 0) {
        *(int *)(p + 0xE30) = 0;
        DeleteTwoWayLink(p + 0xEC0);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_resetChainFindStatus);

void charrootdyn_resetkeepcolhitstatus(void *arg0)
{
    if ((*(int *)((char *)(arg0) + 0xF50)) != 0) {
        (*(int *)((char *)(arg0) + 0xF50)) = 0;
        DeleteTwoWayLink(arg0 + 0xF70);
    }
    (*(int *)((char *)(arg0) + 0xF54)) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_restoreposition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_getCharaFront_PlaneTopDifferenceXZAngle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_getRegularColFinderPosition);

void GetGeometryPointerSurfaceAttribute();

u64 charrootdyn_getCollisionAttribute(s32 a0)
{
    u64 attr[2];

    GetGeometryPointerSurfaceAttribute(attr, a0);
    return attr[0];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_getOffsetGlobalPos);

typedef union { s128 q; float f[4]; int i[4]; } Vec4;

void charrootdyn_getForceLimitMode(char *pa0, char *pa1)
{
    ((Vec4 *)(pa0 + 0x0))->i[0] = 2;
    ((Vec4 *)(pa0 + 0x4))->f[0] = 1.5707962f;
    ((Vec4 *)(pa0 + 0x8))->i[0] = ((Vec4 *)(pa1 + 0xBB0))->i[0];
}

void charrootdyn_getNoLimitMode(void *arg0, void *arg1)
{
    (*(int *)((char *)(arg0) + 0)) = 0;
    (*(int *)((char *)(arg0) + 4)) = 0;
    (*(int *)((char *)(arg0) + 8)) = (int) (*(int *)((char *)(arg1) + 0xBB0));
}

void charrootdyn_getForceNoLimitMode(int *p)
{
    p[0] = 3;
    p[1] = 0;
    p[2] = 0;
}

void charrootdyn_getLimitMode(Vec4 *m, char *c)
{
    if (*(signed char *)(c + 0x51D) != 0) {
        m->i[0] = 1;
        m->f[1] = *(float *)(c + 0x3F0);
        m->i[2] = *(int *)(c + 0xBB0);
    } else {
        m->i[2] = 0;
        m->f[1] = 0.0f;
        m->i[0] = 3;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_checkSlopeLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_getMotionRootInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0082_SetCharacterClassWindDynamics", charrootdyn_getCyclicCollisionDetectZYOneWayCB);
