#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", QueueInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", QueuePeekWriteDone);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", QueuePeekReadDone);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyWrite);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyRead);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyInit);

void func_001129A0(s32 *a0, s32 *a1)
{
    ((s32 *)a1[7])[a0[4]] = a0[5];
}

void func_001129C0(s32 *a0, s32 *a1)
{
    a1[2] = a0[4];
}
