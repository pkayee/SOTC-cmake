#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", supplement_crt0);

extern s32 D_00132AA4[];

s32 __sceKernlGetEhSemaId(void)
{
    return D_00132AA4[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", Copy2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", kCopy2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FD40);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FD80);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", GetSystemCallEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FDC8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FEC8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", _InitSys);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF30);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF40);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF50);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF88);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF98);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", InitExecPS2);
