#include "common.h"

void SetVTLBRefillHandler(s32 idx, void *handler);
void _kTLBException(void);
extern s32 D_00132768;

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", SetTLBHandler);
s32 SetTLBHandler(s32 arg)
{
    D_00132768 = arg;
    SetVTLBRefillHandler(1, _kTLBException);
    SetVTLBRefillHandler(2, _kTLBException);
    SetVTLBRefillHandler(3, _kTLBException);
    return arg;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", SetDebugHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", Copy);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", kCopy);
s32 kCopy(u32 *dst, u32 *src, u32 bytes)
{
    u32 i;
    u32 n;

    n = bytes >> 2;
    for (i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", GetEntryAddress);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", SetSyscall);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", InitTLBFunctions);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", PutTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", iPutTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", _SetTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", SetTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", iSetTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", GetTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", iGetTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", ProbeTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", iProbeTLBEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", ExpandScratchPad);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", InitTLB);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tlbfunc", InitTLB32MB);
