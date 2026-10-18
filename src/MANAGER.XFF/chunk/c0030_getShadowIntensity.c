#include "common.h"

extern unsigned char D_4012A59C[];
extern unsigned char D_4012A5A0[];

void *getShadowIntensity(void)
{
    return D_4012A59C;
}

void *getShadowDebug(void)
{
    return D_4012A5A0;
}

void setShadowIntensity(int intensity)
{
    *(int *)D_4012A59C = intensity;
}

float GetShadowLength(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x18));
}

s32 shadowGetWorkSize(void)
{
    return 0x53;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0030_getShadowIntensity", shadowModelInit);

void shadowModelReInit(void *arg0)
{
    *(*(long **)((char *)(arg0) + 0x1C)) = ((int) (*(int *)((char *)(arg0) + 0x14)) >> 4) | 0x30000000 | ((long) (*(unsigned int *)((char *)(arg0) + 0x10)) << 0x20);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0030_getShadowIntensity", shadowReInit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0030_getShadowIntensity", shadowInit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0030_getShadowIntensity", shadowDisp);

extern unsigned char D_4012A594[];

void *getShadowDispFlag(void)
{
    return D_4012A594;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0030_getShadowIntensity", func_400366D0);
