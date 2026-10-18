#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", GetCollisionDBAttribute);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", GetCollisionDBAttributeAdr);

/* NEARMISS-STUB ClipCollisionDBDoubleSide */
#if 0 /* NEARMISS 83.7% cat=regalloc sub=- | extra s4 saved for 0/1 return; a2/a3 saved swapped (s1/s2); target returns v0 directly | attempts=1 */
s32 ClipCollisionDB();

s32 ClipCollisionDBDoubleSide(s32 a0, s32 a1, s32 a2, s32 a3)
{
    if (ClipCollisionDB(a0, a1, a2, a3) == 0)
    {
        if (ClipCollisionDB(a0, a2, a1, a3) == 0)
        {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionDBDoubleSide);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinder);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinder4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeep);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeep4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", NippingCheckCollisionFindetWithKeep4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeep_VWallOnly);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeepSlopeLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeepSlopeLimitCB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderFarPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderFarPlane4D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderFarPlaneWithKeep);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderFarPlaneWithKeep4D);
