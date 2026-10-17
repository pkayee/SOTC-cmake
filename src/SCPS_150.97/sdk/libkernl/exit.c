#include "common.h"

void InitTLB(void);
void _Exit(int status);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", func_001100B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", func_001100C0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", setup);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", SetArg);

void func_00110218(void)
{
    InitTLB();
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", ExecPS2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", LoadExecPS2);

void Exit(int status)
{
    func_00110218();
    _Exit(status);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", ExecOSD);
