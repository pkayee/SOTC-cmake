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

/* NEARMISS-STUB func_40013160 */
#if 0 /* NEARMISS 93.54% cat=stack-frame sub=- | stack-resident 8-slot DMA addr table + jal epilogue in target | attempts=1 */
// kR39 best: func_40013160 93.54 (cause=regalloc/other: stack table variant 79.45, the target keeps lui/ori in table-init loop path and tail is jal+epilogue not j)
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_40013160);
void func_40015F58(void);

#define DMA_REG(a) (*(volatile u32 *)(a))

void func_40013160(void *arg0, void *arg1, u32 arg2)
{
    u32 dst;
    u32 src;
    u32 n;

    dst = (u32)arg0;
    src = (u32)arg1;
    n = arg2 >> 4;
    while (n > 0x400)
    {
        DMA_REG(0x1000E020) = 0xFFFFFC00;
        DMA_REG(0x1000E010) = 0x200;
        n -= 0x400;
        DMA_REG(0x1000D410) = src;
        src += 0x4000;
        DMA_REG(0x1000D420) = 0x400;
        DMA_REG(0x1000D480) = 0x70000000;
        DMA_REG(0x1000E020) |= 0x200;
        DMA_REG(0x1000D400) = 0x101;
        func_40015F58();
        DMA_REG(0x1000E020) = 0xFFFFFC00;
        DMA_REG(0x1000E010) = 0x100;
        DMA_REG(0x1000D010) = dst;
        dst += 0x4000;
        DMA_REG(0x1000D020) = 0x400;
        DMA_REG(0x1000D080) = 0x70000000;
        DMA_REG(0x1000E020) |= 0x100;
        DMA_REG(0x1000D000) = 0x100;
        func_40015F58();
    }
    DMA_REG(0x1000E020) = 0xFFFFFC00;
    DMA_REG(0x1000E010) = 0x200;
    DMA_REG(0x1000D410) = src;
    DMA_REG(0x1000D420) = n;
    DMA_REG(0x1000D480) = 0x70000000;
    DMA_REG(0x1000E020) |= 0x200;
    DMA_REG(0x1000D400) = 0x101;
    func_40015F58();
    DMA_REG(0x1000E020) = 0xFFFFFC00;
    DMA_REG(0x1000E010) = 0x100;
    DMA_REG(0x1000D010) = dst;
    DMA_REG(0x1000D020) = n;
    DMA_REG(0x1000D080) = 0x70000000;
    DMA_REG(0x1000E020) |= 0x100;
    DMA_REG(0x1000D000) = 0x100;
    func_40015F58();
}
#endif
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

/* NEARMISS-STUB func_400142E0 */
#if 0 /* NEARMISS 85.94% cat=regalloc sub=- | prev/next relink regs, class ladder slti order | attempts=1 */
// kR39 best: func_400142E0 85.94 (cause=regalloc: register choice in prev/next relink and class ladder; ladder structure matches)
static inline s32 PtnClassCnt(Ptn *ptn, s32 sz)
{
    s32 n;
    s32 v;
    s32 w;

    if ((void *)ptn == (void *)&rootPtn)
    {
        if (sz <= 0x400)
        {
            if (sz <= 0x80)
            {
                n = D_40045570[sz];
            }
            else
            {
                v = (sz <= 0xC0) ? 8 : ((sz <= 0x100) ? 9 : ((sz <= 0x200) ? 10 : 11));
                n = v;
            }
        }
        else
        {
            v = sz >> 10;
            if ((v & 0xFF00) == 0)
            {
                n = 0xC;
            }
            else
            {
                v = sz >> 18;
                n = 0x14;
            }
            v >>= 1;
            while (v != 0)
            {
                v >>= 1;
                n++;
            }
        }
    }
    else
    {
        w = (u32)sz >> 11;
        n = 1;
        while (w != 0)
        {
            w >>= 1;
            n++;
        }
    }
    return n;
}

static inline void UnlinkFreeBlk(Ptn *ptn, Bin *bins, Blk *x)
{
    Bin *bn;
    Blk *pp;
    Blk *nx;

    bn = &bins[PtnClassCnt(ptn, (x->w00 & 0xFFFFFF) << 2) - 1];
    pp = (Blk *)((x->w14 & 0xFFFFFF) << 2);
    nx = x->next;
    if (pp != NULL)
    {
        pp->next = nx;
    }
    else
    {
        bn->head = nx;
    }
    if (nx != NULL)
    {
        nx->w14 = (nx->w14 & 0xFF000000) | (x->w14 & 0xFFFFFF);
    }
    else
    {
        bn->tail = pp;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", func_400142E0);
void func_400142E0(void *user)
{
    Blk *blk;
    Blk *next;
    Blk *prev;
    Blk *nn;
    Ptn *ptn;
    Bin *bins;
    u32 own;

    blk = ((Blk **)user)[-1];
    own = ((u8 *)blk)[0xB] << 16;
    own |= ((u8 *)blk)[7] << 8;
    own |= ((u8 *)blk)[3];
    ptn = (Ptn *)(own << 2);
    next = (Blk *)((blk->w08 & 0xFFFFFF) << 2);
    prev = (Blk *)((blk->w0C & 0xFFFFFF) << 2);
    bins = (Bin *)((ptn->binsP24 & 0xFFFFFF) << 2);
    if ((void *)ptn == (void *)&rootPtn)
    {
        D_40045560 += blk->w00 & 0xFFFFFF;
    }
    if (prev != NULL && !((prev->w0C >> 24) & 1))
    {
        prev->w08 = (prev->w08 & 0xFF000000) | (blk->w08 & 0xFFFFFF);
        if (next != NULL)
        {
            next->w0C = (next->w0C & 0xFF000000) | (blk->w0C & 0xFFFFFF);
        }
        UnlinkFreeBlk(ptn, bins, prev);
        prev->w00 = (prev->w00 & 0xFF000000) | ((((u8 *)blk + ((blk->w00 & 0xFFFFFF) << 2) - (u8 *)prev) >> 2) & 0xFFFFFF);
        blk = prev;
    }
    if (next != NULL && !((next->w0C >> 24) & 1))
    {
        blk->w08 = (blk->w08 & 0xFF000000) | (next->w08 & 0xFFFFFF);
        blk->w00 = (blk->w00 & 0xFF000000) | ((((u8 *)next + ((next->w00 & 0xFFFFFF) << 2) - (u8 *)blk) >> 2) & 0xFFFFFF);
        nn = (Blk *)((next->w08 & 0xFFFFFF) << 2);
        if (nn != NULL)
        {
            nn->w0C = (nn->w0C & 0xFF000000) | (next->w0C & 0xFFFFFF);
        }
        UnlinkFreeBlk(ptn, bins, next);
    }
    blk->w0C &= 0xFEFFFFFF;
    func_400133C8(blk, bins, ptn->nbins, ptn);
}
#endif
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocGarbageTickProc);
void iosMallocGarbageTickProc(s32 (*cb)(void *), void *cbArg)
{
    Blk *blk;
    Blk *next;
    u32 w10;
    void *cbFn;
    void *arg;
    void *res;

    WaitSema(D_4007CC78);
    blk = (Blk *)((((Ptn *)gbPtn)->firstBlkP24 & 0xFFFFFF) << 2);
    while (blk != NULL)
    {
        if (cb(cbArg) == 0)
        {
            break;
        }
        next = (Blk *)((blk->w08 & 0xFFFFFF) << 2);
        if (!(((blk->w0C) >> 24) & 1) && next != NULL)
        {
            if (((next->w0C) >> 24) & 1)
            {
                w10 = next->w10 & 0xFFFFFF;
                if (w10 != 0xFFFFFF)
                {
                    cbFn = (void *)(w10 << 2);
                    arg = (void *)((next->w14 & 0xFFFFFF) << 2);
                    res = func_40013A78(blk, next, gbPtn);
                    if (cbFn != NULL)
                    {
                        ((void (*)(void *, void *))cbFn)(arg, res);
                    }
                    next = (Blk *)((blk->w08 & 0xFFFFFF) << 2);
                }
            }
        }
        blk = next;
    }
    SignalSema(D_4007CC78);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlign);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocAlignNoCheck);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosMallocSetExecGarbageCallback);
void iosMallocSetExecGarbageCallback(void *user, s32 cb, s32 arg)
{
    u32 *blk;

    WaitSema(D_4007CC78);
    blk = ((u32 **)user)[-1];
    blk[4] = (blk[4] & 0xFF000000) | ((cb >> 2) & 0xFFFFFF);
    blk[5] = (blk[5] & 0xFF000000) | ((arg >> 2) & 0xFFFFFF);
    SignalSema(D_4007CC78);
}

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/memory", iosCreatePartition);

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
