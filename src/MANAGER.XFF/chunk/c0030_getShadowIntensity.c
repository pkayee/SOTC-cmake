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

/* NEARMISS-STUB shadowModelInit */
#if 0 /* NEARMISS 42.33% cat=sched sub=- | scheduler hoists arg1 field stores above or-chain; target stores them last | attempts=1 */
void shadowModelInit(void *arg0, void *arg1, float arg2)
{
    long *p;
    long v;

    p = iosMallocAlign(arg0, 0x20, 0x10);
    v = ((int) (*(int *)((char *)(arg1) + 0x14)) >> 4) | 0x30000000 | ((long) (*(unsigned int *)((char *)(arg1) + 0x10)) << 0x20);
    *(long *)((char *)(p) + 0x10) = 0x60000000;
    *(long *)(p) = v;
    *(int *)((char *)(p) + 0x8) = 0;
    *(int *)((char *)(p) + 0xC) = 0;
    *(int *)((char *)(p) + 0x18) = 0;
    *(int *)((char *)(p) + 0x1C) = 0;
    *(void **)((char *)(arg1) + 0x1C) = p;
    *(float *)((char *)(arg1) + 0x18) = arg2;
    return;
}
#endif
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
