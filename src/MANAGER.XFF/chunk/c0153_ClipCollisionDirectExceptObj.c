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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", CopyGeometryPointer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerSurfaceSlopeDegree);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerSurfacePlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", InitGeometryPointer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", SetGeometryPointerGlobalState);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0153_ClipCollisionDirectExceptObj", GetGeometryPointerScale);
