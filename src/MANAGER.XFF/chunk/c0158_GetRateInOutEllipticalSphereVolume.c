#include "common.h"

void iosInverseMatrix(f32 *dst, void *src);
f32 GetRateInOutEllipticalSphereVolumeWithInverseMatrix(f32 *inverse, void *point, void *inner_radius, void *outer_radius);

f32 GetRateInOutEllipticalSphereVolume(void *matrix, void *point, void *inner_radius,
                                        void *outer_radius)
{
    f32 inverse[16] __attribute__((aligned(16)));
    iosInverseMatrix(inverse, matrix);
    return GetRateInOutEllipticalSphereVolumeWithInverseMatrix(inverse, point, inner_radius,
                                                              outer_radius);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", GetRateInOutEllipticalSphereVolumeWithInverseMatrix);

f32 GetRateInOutCubeVolumeWithInverseMatrix(f32 *inverse, void *point, void *inner_radius, void *outer_radius);

f32 GetRateInOutCubeVolume(void *matrix, void *point, void *inner_radius, void *outer_radius)
{
    f32 inverse[16] __attribute__((aligned(16)));
    iosInverseMatrix(inverse, matrix);
    return GetRateInOutCubeVolumeWithInverseMatrix(inverse, point, inner_radius, outer_radius);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", GetRateInOutCubeVolumeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", func_400C8FA0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", func_400C9300);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", func_400C94F8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0158_GetRateInOutEllipticalSphereVolume", func_400C9710);
