#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", SetCharacterClassGazeAdditionChannelInfo);

s32 GetMotionVersion(void *motion);
s32 GetMotionNbOptionNodes(void *motion);
s32 GetMotionOptionNodePhysicalId(void *motion, s32 node);

s32 GetOptionNodePhysicalNodeId(void *options, void *motion, s32 node)
{
    s32 result = -1;
    if (*(s32 *)options <= 0 || GetMotionVersion(motion) < 5) {
        if (node < GetMotionNbOptionNodes(motion))
            result = node;
    } else {
        result = GetMotionOptionNodePhysicalId(motion, node);
    }
    return result;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", AddCharacterClassOptionNodeSubGeometries);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", AddSubGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", func_4005CDF0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", AddCharacterClassSubGeometriesOfMatrix);

void func_4005C730(void *a, void *m, char *e);

void GetCharacterClassGazeAddMotions(void *a, char *c)
{
    int n = *(int *)(c + 0x40C);
    char *e;
    void *m;

    if (n != 0) {
        m = *(void **)(c + 0x354);
        e = *(char **)(c + 0x330);
        do {
            func_4005C730(a, m, e);
            e += 0x10;
        } while (--n);
    }
}

s32 getAnimObjResource(s32 res);

void InitGazeAddChannelDef(s32 *g, s32 res)
{
    g[2] = getAnimObjResource(res);
    g[3] = res;
    g[1] = 0;
    g[0] = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", func_4005D228);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", func_4005D3E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", func_4005D6F8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0064_SetCharacterClassGazeAdditionChannelInfo", func_4005E098);
