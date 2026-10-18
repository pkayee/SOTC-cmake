#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", AddCollisionDBCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", AddCollisionDB);

extern int func_400AB528();

int GetCollisionDBCurrentPointOnLastPlane(int a, int b, int c)
{
    return func_400AB528(a, b, c, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBVertexPoint);

extern void func_400BBDE8(void *, float *);

void GetCollisionDBRegion(void *db, float *out, float base)
{
    float t[4];

    func_400BBDE8(db, t);
    *out = base + t[0];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPositionWithST);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPositionWithNodeLocalPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBOriginQuatPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBVectorPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPlane);
