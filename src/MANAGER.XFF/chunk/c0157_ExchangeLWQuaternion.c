#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", ExchangeLWQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetQuaternionAxisRot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetQuaternionFromDir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetTargetLocalDir);

/* NEARMISS-STUB CopyQuatPos */
#if 0 /* NEARMISS 27.27% cat=stack-frame sub=- | dead local copy: all loads and stores dropped, no frame; target keeps 4 stores in 0x40 frame | attempts=1 */
void CopyQuatPos(u64 *src)
{
    u64 dst[4];
    u64 pad[4];

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CopyQuatPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetPlaneDistance);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetDistanceSquare);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetDistanceSquareXZ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", ExchangeLWVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetOffsetPositionAxis);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", GetOffsetPositionQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", IsInsideOfRegion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckCubeVolumeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckCubeVolume);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalSphereVolumeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalSphereVolume);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalSphereVolumeShapeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalSphereVolumeShape);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalCylinderVolumeShapeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckEllipticalCylinderVolumeShape);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckCylinderVolumeWithInverseMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0157_ExchangeLWQuaternion", CheckCylinderVolume);
