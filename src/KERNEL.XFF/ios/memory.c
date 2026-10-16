#include "common.h"

extern s32 D_4007CC78;
extern s32 D_40045560;
extern void *D_40045568;
extern s32 D_4004556C;

s32 WaitSema(s32);
s32 SignalSema(s32);
void func_400152B8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_400155C0(void *arg0, s32 arg1, s32 *arg2);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40013160);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400133C8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400135C8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40013A78);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocInGarbagePtn);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400142E0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014770);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014AF8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014D48);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014F88);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40015210);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400152B8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400155C0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosWaitMalloc);
void iosWaitMalloc(void)
{
    WaitSema(D_4007CC78);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosSignalMalloc);
void iosSignalMalloc(void)
{
    SignalSema(D_4007CC78);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocGarbageTickProc);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlign);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlignNoCheck);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocSetExecGarbageCallback);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosReallocAlign);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosFree);
void func_400142E0(void *arg0);

void iosFree(void *arg0)
{
    WaitSema(D_4007CC78);
    func_400142E0(arg0);
    SignalSema(D_4007CC78);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosFreeParts);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosCreatePartition);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosCreatePartitionWithPc);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosInitMallocSystem);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosGetMallocPtn);
u32 iosGetMallocPtn(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 - 4);

    return ((p[11] << 16) | (p[7] << 8) | p[3]) << 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosGetMallocRootPtnRemainSize);
u32 iosGetMallocRootPtnRemainSize(void)
{
    return D_40045560 << 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosFollowAllLink);
s32 iosFollowAllLink(void *arg0)
{
    s32 sp0 = 0;

    WaitSema(D_4007CC78);
    func_400155C0(arg0, 0, &sp0);
    SignalSema(D_4007CC78);
    return sp0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosDebugPartitionDump);
void iosDebugPartitionDump(void *arg0, s32 arg1)
{
    WaitSema(D_4007CC78);
    func_400152B8(arg0, 0, arg1, -1);
    SignalSema(D_4007CC78);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosDebugPartitionFileDump);
void iosDebugPartitionFileDump(void *arg0, s32 arg1, s32 arg2)
{
    WaitSema(D_4007CC78);
    func_400152B8(arg0, 0, arg1, arg2);
    SignalSema(D_4007CC78);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40015F18);
void func_40015F18(void *arg0, s32 arg1)
{
    func_400152B8(arg0, 0, arg1, -1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", addMemoryDebugCallback);
void addMemoryDebugCallback(void *arg0)
{
    D_40045568 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", getMemorySafetyLockFlag);
s32 *getMemorySafetyLockFlag(void)
{
    return &D_4004556C;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40015F58);
