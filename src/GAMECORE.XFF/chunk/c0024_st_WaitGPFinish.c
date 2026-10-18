#include "common.h"

/* NEARMISS-STUB st_WaitGPFinish */
#if 0 /* NEARMISS 71.72% cat=call-abi sub=- | compiler CSEs one *p load; target has two loads of gpfinishctr via a1 before daddu | attempts=1 */
extern u64 gpfinishctr;
extern void scrRun(void);

void st_WaitGPFinish(s64 arg)
{
    u64 *p = &gpfinishctr;
    s64 target = arg + (s64)*p;

    while ((s64)*p < target)
    {
        scrRun();
    }
}
#endif
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
