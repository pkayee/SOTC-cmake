#include "common.h"
#include <stdarg.h>

extern s32 D_4007CC78;
extern s32 D_40045560;
extern void *D_40045568;
extern s32 D_4004556C;

s32 WaitSema(s32);
s32 SignalSema(s32);
void func_400152B8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_40015F18(void *arg0, s32 arg1);
void iosDebugPartitionDump(void *arg0, s32 arg1);
void func_400155C0(void *arg0, void *arg1, s32 *arg2);
void *func_40013A78(void *arg0, void *arg1, s32 arg2);
void *func_400135C8(void *arg0, s32 arg1, s32 arg2, void *arg3);
void *func_40014AF8(void *arg0, void *arg1, s32 arg2, s32 arg3);
s32 func_40014770(void *arg0, u32 arg1, s32 arg2);
s32 func_40014D48(void *arg0, s32 arg1, void *arg2);
s32 func_40014F88(void *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 iosCreateSema(s32, s32, s32);
extern s32 rootPtn;
extern s32 mallocStartAdrs;
extern char D_40046708[];
extern char D_400465B8[];
extern char D_400465E8[];
extern char D_40046618[];
extern char D_40046628[];
extern s32 gbPtn;
extern s32 D_400455F4;
extern char D_40046668[];
extern char D_40046690[];
extern s32 iosDefaultPadData[];
extern char D_40046828[];
extern char D_40046878[];
extern char D_400468C0[];
extern char D_40046908[];
extern char D_40046948[];

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40013160);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400133C8);
typedef struct Blk Blk;
typedef struct Bin Bin;
typedef struct Ptn Ptn;

struct Blk
{
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0C;
    u32 w10;
    u32 w14;
    u32 w18;
    Blk *next;
};

struct Bin
{
    Blk *head;
    Blk *tail;
};

struct Ptn
{
    u32 binsP24;
    u16 nbins;
    u16 pad;
    u32 firstBlkP24;
};

extern s8 D_40045570[];

static inline s32 PtnClass(Ptn *ptn, s32 sz)
{
    s32 cls;
    s32 base;
    s32 v;

    if ((void *)ptn == (void *)&rootPtn)
    {
        if (sz <= 0x400)
        {
            v = (sz <= 0x80) ? D_40045570[sz] : ((sz <= 0xC0) ? 8 : ((sz <= 0x100) ? 9 : ((sz <= 0x200) ? 10 : 11)));
            cls = v - 1;
        }
        else
        {
            v = sz >> 10;
            if (v & 0xFF00)
            {
                v = sz >> 18;
                base = 0x14;
            }
            else
            {
                base = 0xC;
            }
            v >>= 1;
            if (v == 0)
            {
                cls = base - 1;
            }
            else
            {
                do
                {
                    v >>= 1;
                    base++;
                } while (v != 0);
                cls = base - 1;
            }
        }
    }
    else
    {
        v = (u32)sz >> 11;
        cls = 0;
        if (v != 0)
        {
            cls = 1;
            do
            {
                v >>= 1;
                cls++;
            } while (v != 0);
            cls--;
        }
    }
    return cls;
}



INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400135C8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40013A78);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocInGarbagePtn);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400142E0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014770);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014AF8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014D48);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40014F88);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40015210);
s32 func_40015210(s32 fd, char *fmt, ...)
{
    char buf[0x100];
    va_list args;

    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    if (fd < 0)
    {
        LoaderSysPrintf(D_40046708, buf);
    }
    else
    {
        LoaderSysFWrite(fd, buf, strlen(buf));
    }
    return strlen(buf);
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlign);
void *iosMallocAlign(void *ptn, s32 size, s32 align)
{
    void *p;
    void *pc;
    register void *ra asm("ra");

    pc = ra;
    WaitSema(D_4007CC78);
    p = func_400135C8(ptn, size, align, pc);
    if (!p)
    {
        LoaderSysPrintf(D_400465B8, ptn, size, pc);
        func_40015F18(ptn, 1);
        LoaderSysPrintf(D_400465E8, &rootPtn, gbPtn);
    }
    SignalSema(D_4007CC78);
    if (!p)
    {
        LoaderSysPrintf(D_40046618, D_40045568);
        if (D_40045568)
        {
            ((void (*)(void))D_40045568)();
        }
        iosJumpRecoverPoint(D_40046628, ptn, size, pc);
    }
    return p;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlignNoCheck);
void *iosMallocAlignNoCheck(void *ptn, s32 size, s32 align)
{
    void *r;
    void *pc;
    register void *ra asm("ra");

    pc = ra;
    WaitSema(D_4007CC78);
    r = func_400135C8(ptn, size, align, pc);
    SignalSema(D_4007CC78);
    return r;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocSetExecGarbageCallback);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosReallocAlign);
void *iosReallocAlign(void *ptn, void *oldUser, s32 size, s32 align)
{
    void *r;

    WaitSema(D_4007CC78);
    r = func_40014AF8(ptn, oldUser, size, align);
    SignalSema(D_4007CC78);
    return r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosFree);
void func_400142E0(void *arg0);

void iosFree(void *arg0)
{
    WaitSema(D_4007CC78);
    func_400142E0(arg0);
    SignalSema(D_4007CC78);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosFreeParts);
s32 iosFreeParts(void *ptn, u32 addr, s32 mode)
{
    s32 r;

    WaitSema(D_4007CC78);
    r = func_40014770(ptn, addr, mode);
    SignalSema(D_4007CC78);
    return r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosCreatePartition);
s32 iosCreatePartition(void *parent, s32 size)
{
    s32 r;
    void *pc;
    register void *ra asm("ra");

    pc = ra;
    WaitSema(D_4007CC78);
    r = func_40014D48(parent, size, pc);
    SignalSema(D_4007CC78);
    return r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosCreatePartitionWithPc);
s32 iosCreatePartitionWithPc(void *parent, s32 size, void *pc)
{
    s32 r;

    WaitSema(D_4007CC78);
    r = func_40014D48(parent, size, pc);
    SignalSema(D_4007CC78);
    return r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosInitMallocSystem);
s32 iosInitMallocSystem(void *start, s32 a1, s32 a2)
{
    s32 sema;

    sema = iosCreateSema(1, 1, 0);
    D_4007CC78 = sema;
    mallocStartAdrs = (s32)start;
    return func_40014F88(&rootPtn, (s32)start, a1, a2);
}

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
