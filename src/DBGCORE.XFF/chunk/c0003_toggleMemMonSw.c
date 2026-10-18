#include "common.h"

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", toggleMemMonSw);

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", getMemMonSw);

extern u8 D_40018FBC[];

void *getMemMonSw(void)
{
    return &D_40018FBC;
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", func_40015480);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", execPClog);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", func_40015850);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0003_toggleMemMonSw", dispPeakGraph);
