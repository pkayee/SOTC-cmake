#include "common.h"

/* MPEG DMA/IPU reset: clear IPU, SPR DMA channels under DIntr, then sceIpuSync(0,0) tail call. c0208 needs cc=ee-gcc2.9-991111 (frameless tail jumps, see func_400FF4E8) */
s32 DIntr(void);
s32 EIntr(void);
void sceIpuSync(s32, s32);

/* MPEG ring buffer setup: IPU CTRL bit 23, then mode at c+0x87c selects SPR (0x7000xxxx) or main-memory (0x3000xxxx) buffers */
extern char D_40135820[];
void _sceMpegError(void *, char *);

/* sceMpegCreate(m, buf, size): zero the user buffer, align it to 4, carve the decoder context c (stored at m+0x40) and its allocator at c+0x118, init callback tables and ref buffers, assert alignment */
extern void *memset(void *, int, unsigned int);
extern char D_40135888[];
extern char D_40135838[];
extern char D_40135860[];
void _sceMpegError1(void *, char *, s32);
void _sceMpegAlalcInit(s32 *, s32, s32);
void _sceMpegAlalcSetDynamic(s32 *);
s32 _sceMpegAlalcAlloc(void *, s32 *, s32, s32);
s32 _sceMpegDefaultStopDMA(u8 *);
s32 _sceMpegDefaultRestartDMA(u8 *);
s32 sceMpegReset(u8 *);
s32 sceMpegClearRefBuff(u8 *);

void func_400FF4E8(u8 *c) {
    u32 v;
    u32 t;

    v = *(volatile u32 *)0x10002010;
    *(volatile u32 *)0x10002010 = (v & 0xFF7FFFFF) | 0x800000;
    if (*(s32 *)(c + 0x87C) == 0) {
        t = 0x70000000;
        *(u32 *)(c + 0x830) = 0x70003600;
        *(u32 *)(c + 0x5A0) = t;
        *(u32 *)(c + 0x5A4) = 0x70001800;
        *(u32 *)(c + 0x6E0) = 0x70001B00;
        *(u32 *)(c + 0x6E4) = 0x70003300;
        *(s32 *)(c + 0x820) = 0;
        return;
    }
    if (*(s32 *)(c + 0x87C) == 1) {
        *(u32 *)(c + 0x830) = (u32)(c + 0xE80);
        *(u32 *)(c + 0x5A4) = ((u32)(c + 0x880) & 0xFFFFFFF) | 0x30000000;
        *(u32 *)(c + 0x6E4) = ((u32)(c + 0xB80) & 0xFFFFFFF) | 0x30000000;
        *(u32 *)(c + 0x5A0) = 0;
        *(u32 *)(c + 0x6E0) = 0;
        *(s32 *)(c + 0x820) = 0;
        return;
    }
    _sceMpegError(c, D_40135820);
}

s32 sceMpegCreate(u8 *m, u8 *buf, s32 size) {
    u8 *c;
    s32 rest;
    s32 *al;
    s32 a;

    memset(buf, 0, size);
    c = (u8 *)((((u32)buf + 3) >> 2) << 2);
    rest = size - (s32)(c - buf);
    if (rest < 0x19A0) {
        _sceMpegError(c, D_40135888);
        return 0;
    }
    *(u8 **)(m + 0x40) = c;
    al = (s32 *)(c + 0x118);
    _sceMpegAlalcInit(al, (s32)(c + 0x19A0), rest - 0x19A0);
    *(s32 *)(m + 0) = 0;
    *(s32 *)(m + 4) = 0;
    *(s32 *)(m + 8) = 0;
    *(s64 *)(m + 0x10) = -1;
    *(s64 *)(m + 0x18) = -1;
    *(s64 *)(m + 0x20) = 0;
    *(s64 *)(m + 0x28) = -1;
    *(s64 *)(m + 0x30) = -1;
    *(s64 *)(m + 0x38) = 0;
    *(s32 *)(c + 0xC8) = 0;
    *(s32 *)(c + 0xCC) = 0;
    *(s32 *)(c + 0xD0) = 0;
    *(s32 *)(c + 0xD4) = 0;
    *(s32 *)(c + 0xD8) = 0;
    *(s32 *)(c + 0xDC) = 0;
    *(s32 *)(c + 0xE0) = 0;
    *(s32 *)(c + 0xE4) = 0;
    *(s32 *)(c + 0xE8) = 0;
    *(s32 *)(c + 0xEC) = 0;
    *(s32 *)(c + 0xF0) = 0;
    *(s32 *)(c + 0xF4) = 0;
    *(s32 *)(c + 0xF8) = 0;
    *(s32 *)(c + 0xFC) = 0;
    *(s32 *)(c + 0x108) = 0;
    *(s32 *)(c + 0xC) = 0;
    *(s32 *)(c + 0x18) = 0;
    *(s32 *)(c + 0x3C) = 0;
    *(s32 *)(c + 0x48) = 0;
    *(s32 *)(c + 0x54) = 0;
    *(s64 *)(c + 0x100) = -1;
    *(s32 *)(c + 0x24) = (s32)_sceMpegDefaultStopDMA;
    *(s32 *)(c + 0x30) = (s32)_sceMpegDefaultRestartDMA;
    *(s32 *)(c + 0x60) = _sceMpegAlalcAlloc(c, al, 0x800, 8);
    *(s32 *)(c + 0x64) = 0;
    *(s32 *)(c + 0x10C) = 0;
    *(s32 *)(c + 0x110) = 0;
    *(s32 *)(c + 0x114) = 0;
    *(s32 *)(c + 0x8C) = 0;
    *(s64 *)(c + 0x90) = 0;
    *(s32 *)(c + 0x98) = -1;
    *(s64 *)(c + 0xA0) = 0;
    *(s32 *)(c + 0x9C) = 0;
    *(s32 *)(c + 0xC0) = 0;
    *(s32 *)(c + 0xA8) = -1;
    *(s32 *)(c + 0xAC) = -1;
    *(s32 *)(c + 0xB0) = -1;
    *(u8 **)(c + 0x868) = m;
    *(s32 *)(c + 0xC4) = 1;
    func_400FF4E8(c);
    sceMpegReset(m);
    sceMpegClearRefBuff(m);
    *(u8 **)(c + 0x1C8) = c + 0x1F8;
    *(u8 **)(c + 0x1CC) = c + 0x260;
    *(u8 **)(c + 0x1D4) = c + 0x2C8;
    *(u8 **)(c + 0x1D8) = c + 0x330;
    *(u8 **)(c + 0x1DC) = c + 0x398;
    *(u8 **)(c + 0x1E4) = c + 0x400;
    *(u8 **)(c + 0x1E8) = c + 0x468;
    *(u8 **)(c + 0x1EC) = c + 0x4D0;
    *(u8 **)(c + 0x1F4) = c + 0x538;
    _sceMpegAlalcSetDynamic(al);
    *(s32 *)(c + 0x860) = -1;
    *(s32 *)(c + 0x85C) = 0;
    *(s32 *)(c + 0x864) = 0;
    a = (u32)(c + 0x840) & 0x3C;
    if (a != 0) {
        _sceMpegError1(c, D_40135838, a);
        return 0;
    }
    a = (u32)(c + 0x880) & 0x3C;
    if (a != 0) {
        _sceMpegError1(c, D_40135860, a);
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FF7F0);

void func_400FF8F0(u8 *c) {
    s32 intr;

    *(s32 *)(c + 0x828) = 1;
    *(s32 *)(c + 0x1C0) = 0;
    intr = DIntr();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000D400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (intr != 0) {
        EIntr();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000D420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
    sceIpuSync(0, 0);
}

extern char D_401358B0[];
extern char D_401358F0[];
extern char D_40135930[];
void scePrintf(char *, ...);
s32 _sceMpegNextHeader(u8 *);
s32 _sceMpegFlush(u8 *);
s32 func_40100540(u8 *, s32, s32);

s32 func_400FF9B8(u8 *m)
{
    u8 *c = *(u8 **)(m + 0x40);
    s32 r = 0;
    s32 h = 1;

    *(s32 *)c = 0;
    if (*(s32 *)(c + 0xEC) & 0x3F) {
        _sceMpegError1(c, D_401358B0, *(s32 *)(c + 0xEC));
        return -1;
    }
    if (*(s32 *)(c + 0x878) != 0) {
        scePrintf(D_401358F0);
        return -1;
    }
    *(s32 *)(c + 0x834) = 0;
    do {
        if (r != -1) {
            do {
                h = _sceMpegNextHeader(c);
                if (h < 0) {
                    return -1;
                }
            } while (h != 0 && *(s32 *)(c + 0x184) != *(s32 *)(c + 0xE8) && *(s32 *)(c + 0x858) != 0);
        }
        switch (h) {
        case 0:
            _sceMpegFlush(m);
            *(s32 *)c = 1;
            break;
        case 1:
            *(s32 *)(c + 0xBC) = 0;
            *(s32 *)(c + 0xB8) = 0;
            *(s32 *)(c + 0xB4) = 0;
            r = func_40100540(m, *(s32 *)(c + 0xB4), *(s32 *)(c + 0xA8));
            *(s32 *)(c + 0xB4) += 1;
            break;
        case 2:
            r = func_40100540(m, *(s32 *)(c + 0xB8), *(s32 *)(c + 0xAC));
            *(s32 *)(c + 0xB8) += 1;
            break;
        case 3:
        case 4:
            r = func_40100540(m, *(s32 *)(c + 0xBC), *(s32 *)(c + 0xB0));
            *(s32 *)(c + 0xBC) += 1;
            break;
        }
        if (*(s32 *)(c + 0x878) != 0) {
            scePrintf(D_40135930);
            return -1;
        }
        if (*(s32 *)(c + 0x834) != 0) {
            return 1;
        }
    } while (*(s32 *)c == 0);
    return 1;
}

/* NEARMISS-STUB func_400FFB70 */
#if 0 /* NEARMISS 99.94% cat=sched sub=- | d2 r92: full body exact incl. if/else r=1/r=0 (gives the xori/movn) and the t/o regs (decl order t,p,r,o,lim); only left: target schedules o=0 before the xori a | attempts=1 */
#define W208(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P208(p, o) (*(u8 **)((u8 *)(p) + (o)))

s32 func_400FFB70(u8 *c, s32 flag)
{
    s32 t = W208(c, 0x184);
    s32 p = W208(c, 0x160);
    s32 r = 0;
    u8 *o = 0;
    s32 lim = (t == 3) ? 2 : 4;

    if (p == 3) {
        W208(c, 0x1D0) = W208(c, 0x1D4);
        W208(c, 0x1E0) = W208(c, 0x1E4);
        W208(c, 0x1F0) = W208(c, 0x1F4);
        if (W208(c, 0xB4) + W208(c, 0xB8) >= lim) {
            W208(c, 0xFC) = 0;
            W208(c, 0x1B8) = 0;
            W208(c, 0x1B4) = 0;
        }
        if ((W208(c, 0xFC) != 0 || W208(c, 0x1B8) != 0) && W208(c, 0x1B4) == 0) {
            W208(P208(c, 0x1C8), 0x28) = 0;
            W208(P208(c, 0x1D8), 0x28) = 0;
            W208(P208(c, 0x1E8), 0x28) = 0;
            t = W208(c, 0x184);
        }
        W208(c, 0xFC) = 0;
        W208(c, 0x1B8) = 0;
        if (t == 3) {
            if (W208(P208(c, 0x1C8), 0x28) == 1 || W208(c, 0x1B4) != 0) {
                if (W208(P208(c, 0x1CC), 0x28) == 1) {
                    r = 1;
                } else {
                    r = 0;
                }
            }
        } else {
            if ((W208(P208(c, 0x1D8), 0x28) == 1 && W208(P208(c, 0x1E8), 0x28) == 1) || W208(c, 0x1B4) != 0) {
                if (W208(P208(c, 0x1DC), 0x28) == 1) {
                    if (W208(P208(c, 0x1EC), 0x28) == 1) {
                        r = 1;
                    } else {
                        r = 0;
                    }
                }
            }
        }
    } else {
        if (flag == 0) {
            u8 *a;

            a = P208(c, 0x1C8);
            P208(c, 0x1C8) = P208(c, 0x1CC);
            P208(c, 0x1CC) = a;
            a = P208(c, 0x1D8);
            P208(c, 0x1D8) = P208(c, 0x1DC);
            P208(c, 0x1DC) = a;
            a = P208(c, 0x1E8);
            P208(c, 0x1E8) = P208(c, 0x1EC);
            P208(c, 0x1EC) = a;
        }
        W208(c, 0x1D0) = W208(c, 0x1CC);
        W208(c, 0x1E0) = W208(c, 0x1DC);
        W208(c, 0x1F0) = W208(c, 0x1EC);
        if (t == 3) {
            if (p != 2 || W208(P208(c, 0x1C8), 0x28) == 1) {
                r = 1;
            }
        } else {
            u8 *q = (t == 1) ? P208(c, 0x1EC) : P208(c, 0x1DC);

            if (p != 2 || (flag != 0 && W208(q, 0x28) == 1) || (W208(P208(c, 0x1D8), 0x28) == 1 && W208(P208(c, 0x1E8), 0x28) == 1)) {
                r = 1;
            }
        }
    }
    switch (t) {
    case 1:
        o = P208(c, 0x1E0);
        break;
    case 2:
        o = P208(c, 0x1F0);
        break;
    case 3:
        o = P208(c, 0x1D0);
        break;
    }
    W208(o, 0x28) = 0;
    *(u64 *)(o + 0x18) = *(u64 *)(c + 0x838);
    W208(o, 0x2C) = W208(c, 0x160);
    *(u64 *)(o + 0x20) = *(u64 *)(c + 0x840);
    W208(o, 0x30) = W208(c, 0x184);
    W208(o, 0x34) = W208(c, 0x14C);
    W208(o, 0x38) = W208(c, 0x198);
    W208(o, 0x3C) = W208(c, 0x188);
    W208(o, 0x40) = W208(c, 0x194);
    W208(o, 0x44) = W208(c, 0x19C);
    W208(o, 0x48) = W208(c, 0x1A0);
    W208(o, 0x4C) = W208(c, 0x1A4);
    W208(o, 0x50) = W208(c, 0x1A8);
    W208(o, 0x54) = W208(c, 0x1AC);
    W208(o, 0x58) = W208(c, 0x1B0);
    W208(o, 0x5C) = W208(c, 0x158);
    W208(o, 0x60) = W208(c, 0x15C);
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFB70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFE28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFF98);
