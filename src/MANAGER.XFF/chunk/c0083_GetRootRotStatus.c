#include "common.h"

/* MANAGER c0083: this+0xD14 = linked flag, this+0xD60 = TwoWayLink node, this+0xD20 = geometry slot. No local for the node: write self+0xD60 twice (a named `link` local swaps s1/s2, 88.4). */
extern void *GetGeometryPointerObject(void *);
extern void *GetLayoutClass(void *);
extern void DeleteTwoWayLink(void *);
extern int AddTwoWayLinkNext(void *, void *);
extern void CopyGeometryPointer(void *, void *);

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

/* NEARMISS-STUB charrootdyn_setFallDownLandingOffset */
#if 0 /* NEARMISS 76.28% cat=regalloc sub=- | f0/f1 register swapped for temp copy; ld ra scheduled before last store | attempts=1 */
extern void charrootdyn_getLocalOffsetFromParentGPwithGPCoordinate(f32 *, char *, s32);

void charrootdyn_setFallDownLandingOffset(char *arg0, char *arg1)
{
    f32 temp[3];
    char *dst;
    s32 coord;

    coord = *(s32 *)((char *)(arg0) + 0x134);
    dst = (char *)(arg0) + 0xA70;
    charrootdyn_getLocalOffsetFromParentGPwithGPCoordinate(temp, arg1, coord);
    (*(f32 *)(dst + 0x4)) = temp[1];
    (*(f32 *)(dst)) = temp[0];
    (*(f32 *)(dst + 0x8)) = temp[2];
}
#endif
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

s32 func_40074BB8(void *arg0, void *arg1)
{
    void *s0 = *(void **)((char *)arg1 + 0x40);
    if (arg0 != s0) {
        if (*(void **)((char *)GetLayoutClass(arg0) + 0x194) != s0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", func_40074BF8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_checkParentGPPlaneDir);

extern u64 *GetCollisionDBAttributeAdr();

s32 func_40074EA8(void)
{
    u64 *temp_v0;

    temp_v0 = GetCollisionDBAttributeAdr();
    return (*temp_v0 & 0x7C000000) != 0x30000000;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0083_GetRootRotStatus", charrootdyn_memoryposition);

void charrootdyn_setChainFindStatus(char *self, void *geometry)
{
    char *layout = GetLayoutClass(GetGeometryPointerObject(geometry));
    if (*(int *)(self + 0xD14) != 0) {
        *(int *)(self + 0xD14) = 0;
        DeleteTwoWayLink(self + 0xD60);
    }
    AddTwoWayLinkNext(layout + 0x118, self + 0xD60);
    *(int *)(self + 0xD14) = 1;
    CopyGeometryPointer(self + 0xD20, geometry);
}
