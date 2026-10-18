#include "common.h"

extern s32 D_4012B338;

void SetColDebug(int arg0)
{
    D_4012B338 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBDE8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBE40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBE80);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF90);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBFA0);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BC778);

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
