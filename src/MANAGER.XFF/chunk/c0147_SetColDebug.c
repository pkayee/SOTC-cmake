#include "common.h"

extern s32 D_4012B338;

void SetColDebug(int arg0)
{
    D_4012B338 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBDE8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBE40);

extern u64 *GetCollisionDBAttributeAdr();

s32 func_400BBE40(void)
{
    u64 *temp_v0;

    temp_v0 = GetCollisionDBAttributeAdr();
    return (*temp_v0 & 0xF80000000) != 0x280000000;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBE80);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF70);
s32 func_400BBF70(f32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4)
{
    return *arg4 <= arg0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF90);
s32 func_400BBF90(s32 arg0, s32 arg1)
{
    return arg0 != arg1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBFA0);

/* NEARMISS-STUB GetCollisionDBNextSurfLinkComp */
#if 0 /* NEARMISS 87.4% cat=struct-layout sub=- | regalloc: s0/s1 swapped and a0 copied to v1; ours loads field into s0 | attempts=1 */
extern u8 *GetLayoutClass(void *);

void *GetCollisionDBNextSurfLinkComp(u32 *arg0)
{
    u8 *layout;
    u8 *temp_v1;
    u8 *temp_a1;
    u32 s1;
    u32 s0;

    s1 = arg0[1];
    s0 = s1 >> 24;
    s1 &= 0xFFFFFF;
    layout = GetLayoutClass((void *)arg0[0]);
    s0 &= 0x7F;
    temp_a1 = *(u8 **)(*(u8 **)(layout + 0x184) + 0x20);
    temp_v1 = (u8 *)(*(u32 *)(temp_a1 + 0x8) + s0 * 0x90);
    return (void *)(*(u32 *)(temp_v1 + 0x14) + s1 * 20 + 8);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionDBNextSurfLinkComp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionDBNextSurfLink);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", MakeCollisionPointCollisionInfo);

void MakeGeometryPointerGlobalInfo(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x30)) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetSTPositionOfCollisionDB);

void MakeCollisionPointGlobalInfo(char *p, s128 *v)
{
    *(s128 *)(p + 0x40) = *v;
    *(int *)(p + 0x30) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BC558);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BC638);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionDynamicsProjectionFloatPosition);

extern void RelocateCollisionWork(void *, s32);

void func_400BC778(void *arg0, void *arg1)
{
    RelocateCollisionWork(arg1, *(s32 *)((char *)(*(s32 *)((char *)(arg0) + 0x184)) + 0x20));
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BC798);
void func_400BC798(u8* work)
{
    *(s32*)work = 0;
}

int objfilter(int arg0, int arg1)
{
    return arg0 != arg1;
}

void FlushCollisionEdgeLinkDBVWallFinder(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = 0;
}

int GetCollisionEdgeLinkDBWorkSize(int arg0)
{
    if (arg0 != 0) {
        return (arg0 * 0x14) + 0x96;
    }
    return 0;
}

/* NEARMISS-STUB InitCollisionEdgeLinkDB */
#if 0 /* NEARMISS 90.38461% cat=regalloc sub=- | hoisted v0=0 before branch; a0/v1 swapped for -1 and YUnitVector addr | attempts=1 */
extern s128 YUnitVector;
extern void *iosMallocAlign(void *, s32, s32);

void *InitCollisionEdgeLinkDB(void *arg0, s32 arg1)
{
    u8 *temp_s0;
    void *temp_v0;

    if (arg1 == 0) {
        return NULL;
    }
    temp_s0 = iosMallocAlign(arg0, 0x30, 4);
    temp_v0 = iosMallocAlign(arg0, arg1 * 0x14, 4);
    *(u8 *)(temp_s0 + 0x12) = 0;
    *(s32 *)(temp_s0 + 0x18) = 0;
    *(s32 *)(temp_s0 + 0x14) = -1;
    *(s32 *)(temp_s0 + 0x1C) = 0;
    *(s128 *)temp_s0 = YUnitVector;
    *(s32 *)(temp_s0 + 0x10) = arg1;
    *(s32 *)(temp_s0 + 0x20) = 0;
    *(void **)(temp_s0 + 0x24) = temp_v0;
    return temp_s0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", InitCollisionEdgeLinkDB);

void iosFree(void *);

void ReleaseCollisionEdgeLinkDB(void **arg0)
{
    void *temp_s0;

    temp_s0 = *arg0;
    if (temp_s0 != NULL) {
        iosFree((*(void **)((char *)(temp_s0) + 0x24)));
        iosFree(temp_s0);
        *arg0 = NULL;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionEdgeLinkDBVWallFinder);
