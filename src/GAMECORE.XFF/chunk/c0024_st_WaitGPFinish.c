#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0024_st_WaitGPFinish", st_WaitGPFinish);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0024_st_WaitGPFinish", func_4002F388);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0024_st_WaitGPFinish", st_jumphokoraflow);

extern int jumphokoraFlag;

int jumphokoraflowDemoStart(void)
{
    return jumphokoraFlag & 1;
}

void jumphokoraflowDemoEnd(int a)
{
    int *f = &jumphokoraFlag;

    f[1] = a;
    f[0] |= 2;
}

extern int D_40200EE0;
extern int D_40200EE4;

void jumphokoraGetDemoInfo(int *arg0, int *arg1)
{
    *arg0 = D_40200EE0;
    *arg1 = D_40200EE4;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0024_st_WaitGPFinish", func_4002FA60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0024_st_WaitGPFinish", loadObj);
