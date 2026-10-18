#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/cache", _sceSDC);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/cache", SyncDCache);

void _sceSDC(u32 start, u32 end);
void iSyncDCache(u32 start, u32 end)
{
    _sceSDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/cache", _sceIDC);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/cache", InvalidDCache);

void _sceIDC(u32 start, u32 end);
void iInvalidDCache(u32 start, u32 end)
{
    _sceIDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}

