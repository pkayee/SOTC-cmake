#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", SlideCollisionFinder4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", SlideCollisionFinder4DCB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", ClipCollisionVariableXZSurface);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", ClipCollisionVariableXZSurfaceNoBottomCheck);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", CheckUnderVariableXZSurface);

extern f32 GetWaterSurfacePositionYExtend(s32, s32, s32, s32, f32, f32, f32);

f32 GetWaterSurfacePositionY(s32 a, s32 b, s32 c, f32 x, f32 y)
{
    return GetWaterSurfacePositionYExtend(a, b, c, 0, x, y, 0.0f);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0144_SlideCollisionFinder4D", GetWaterSurfacePositionYExtend);
