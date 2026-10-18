#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", GetRootRotStatus);

extern void *GetCharacterClass(void *);

void EnableCharacterObjMotionRootRotDynamics(void *actor)
{
    void *temp_a1;
    void *temp_v0;

    temp_v0 = GetCharacterClass(actor);
    temp_a1 = (*(void **)((char *)(temp_v0) + 0x19C));
    (*(unsigned char *)((char *)(temp_v0) + 0x519)) = (unsigned char) (*(unsigned char *)((char *)(temp_v0) + 0xA16));
    (*(long *)((char *)(temp_a1) + 0x40)) = (long) (*(long *)((char *)(temp_v0) + 0xA20));
    (*(long *)((char *)(temp_a1) + 0x48)) = (long) (*(long *)((char *)(temp_v0) + 0xA28));
    (*(long *)((char *)(temp_a1) + 0x50)) = (long) (*(long *)((char *)(temp_v0) + 0xA30));
    (*(long *)((char *)(temp_a1) + 0x58)) = (long) (*(long *)((char *)(temp_v0) + 0xA38));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_detectCharEdge);

int charrootdyn_isParentToEdge(void *arg0)
{
    int var_v1;

    var_v1 = 0;
    if ((*(int *)((char *)(arg0) + 0x124)) != 0) {
        var_v1 = (*(int *)((char *)(arg0) + 0xF0)) == 4;
    }
    return var_v1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_getGPPlaneInfoByCollisionDBData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_updateCharacterClassParentGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_getLocalOffsetFromParentGPwithGPCoordinate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_setFallDownLandingOffset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_getEdgeEffectivityCheckRayPosition);

extern unsigned char D_4012AF30[];

void *getEdgeHangDebugFlag(void)
{
    return D_4012AF30;
}

extern unsigned char D_4012AF34[];

void *getAirResistEnableFlag(void)
{
    return D_4012AF34;
}

extern unsigned char D_4012AF38[];

void *getDisableExtendWallFlag(void)
{
    return D_4012AF38;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", func_40074BB8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", func_40074BF8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_checkParentGPPlaneDir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", func_40074EA8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_memoryposition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_setChainFindStatus);
