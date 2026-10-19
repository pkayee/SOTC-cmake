#include "common.h"

extern char D_40135B80[];
void _sceMpegError(void *, const char *);

/* IPU flush: arg typed void* with local u8 *c so func_40107500 keeps its void* prototype */
void func_401074C8(u8 *);
s64 _sceMpegWaitIpuIdle64(u8 *);

/* MPEG macroblock address increment: IPU CMD 0x10002000 volatile hw store, switch on (u32)(s16) VLC result, PeepBit result in a temp, k temp holds 0x30000000 (stops lui/ori hoist) */
extern char D_40135BD0[];
u32 _sceMpegPeepBit(u8 *, s32);
void func_40107500(void *, s32);
void _sceMpegError1(void *, const char *, s32);

/* statement order B E A C D (found by permutation search): w load, shift, 0x84c store, cmd store, 82c store */
void func_401074C8(u8 *);

/* IPU peek-bit, IPU_CMD hw store through volatile pointer cast (hardware register) */
void func_401074C8(u8 *);

/* IPU idle wait loop: _sceMpegDispatchMpegCbNodata must be declared s32 (void picks v0 for the 0x878 load: 99.78) */
s32 _sceMpegDispatchMpegCbNodata(void *);
void _sceMpegStopIpuDma(void);

/* 64-bit IPU CMD idle wait: while-loop (rotated entry copy) plus s32 Dispatch decl and break out to the shared 0x82c store */
s32 _sceMpegDispatchMpegCbNodata(void *);

s32 _sceMpegMbAddressIncrement(u8 *c) {
    s32 sum = 0;
    s32 more;
    s64 r;
    s64 top;
    u32 bp;
    s32 s;
    u32 k;
    u32 pk;

    do {
        func_401074C8(c);
        k = 0x30000000;
        *(volatile u32 *)0x10002000 = k;
        *(s32 *)(c + 0x82c) = k;
        *(s32 *)(c + 0x828) = 0;
        r = _sceMpegWaitIpuIdle64(c);
        bp = *(volatile u32 *)0x10002020;
        top = *(volatile s64 *)0x10002030;
        *(s32 *)(c + 0x848) = (s32)top;
        if (top < 0) {
            *(s32 *)(c + 0x84c) = (0x20 - (bp & 0x1F)) & 0x1F;
        } else {
            *(s32 *)(c + 0x84c) = 0x20;
        }
        *(s32 *)(c + 0x12c) = (s32)r == 0;
        s = (s16)r;
        switch ((u32)s) {
        case 0x22:
            more = 1;
            break;
        case 0x23:
            more = 1;
            sum += 0x21;
            break;
        case 0:
            pk = _sceMpegPeepBit(c, 0xB);
            if (*(s32 *)(c + 0x858) != 0 && pk == 0xF) {
                func_40107500(c, 0xB);
                more = 1;
                break;
            }
            _sceMpegError1(c, D_40135BD0, s);
            *(s32 *)(c + 0x12c) = 1;
            return 1;
        default:
            sum += s;
            more = 0;
            break;
        }
    } while (more);
    return sum;
}

void _sceMpegWaitIpuIdle(u8 *c) {
    s32 cnt = 0;
    u32 bp;
    u32 fifo;
    u32 st;

    if ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            bp = *(volatile u32 *)0x10002020;
            fifo = ((bp & 0xFF00) >> 1) + ((bp & 0x30000) >> 9) - (bp & 0x7F);
            st = *(u32 *)(c + 0x82c);
            if ((st == 0x20000000 || st == 0x30000000 || st == 0x40000000) && fifo < 0x20 &&
                *(volatile u32 *)0x1000B420 == 0) {
                _sceMpegDispatchMpegCbNodata(*(void **)(c + 0x868));
                cnt = 0;
                if (*(s32 *)(c + 0x878) != 0) {
                    _sceMpegStopIpuDma();
                    break;
                }
            }
            if (cnt++ >= 0x1389) {
                _sceMpegDispatchMpegCbNodata(*(void **)(c + 0x868));
                cnt = 0;
                if (*(s32 *)(c + 0x878) != 0) {
                    _sceMpegStopIpuDma();
                    break;
                }
            }
        } while ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000);
    }
    *(s32 *)(c + 0x82c) = 0;
}

s64 _sceMpegWaitIpuIdle64(u8 *c) {
    s32 cnt = 0;
    s64 v;
    u32 bp;
    u32 fifo;
    u32 st;

    v = *(volatile u64 *)0x10002000;
    while (v < 0 && (*(volatile u32 *)0x10002010 & 0x4000) == 0) {
        bp = *(volatile u32 *)0x10002020;
        fifo = ((bp & 0xFF00) >> 1) + ((bp & 0x30000) >> 9) - (bp & 0x7F);
        st = *(u32 *)(c + 0x82c);
        if ((st == 0x20000000 || st == 0x30000000 || st == 0x40000000) && fifo < 0x20 &&
            *(volatile u32 *)0x1000B420 == 0) {
            _sceMpegDispatchMpegCbNodata(*(void **)(c + 0x868));
            cnt = 0;
            if (*(s32 *)(c + 0x878) != 0) {
                _sceMpegStopIpuDma();
                break;
            }
        }
        if (cnt++ >= 0x1F5) {
            _sceMpegDispatchMpegCbNodata(*(void **)(c + 0x868));
            cnt = 0;
            if (*(s32 *)(c + 0x878) != 0) {
                _sceMpegStopIpuDma();
                break;
            }
        }
        v = *(volatile u64 *)0x10002000;
    }
    *(s32 *)(c + 0x82c) = 0;
    return v;
}

u32 _sceMpegNextBit(u8 *c, s32 n) {
    u32 r;
    u32 cmd;
    u32 w;
    u32 t;

    func_401074C8(c);
    if (*(s32 *)(c + 0x828) != 0 || *(s32 *)(c + 0x84c) < n) {
        *(volatile u32 *)0x10002000 = 0x40000000;
        *(s32 *)(c + 0x828) = 0;
        *(s32 *)(c + 0x82c) = 0x40000000;
        *(s32 *)(c + 0x848) = (s32)_sceMpegWaitIpuIdle64(c);
    }
    w = *(u32 *)(c + 0x848);
    r = w >> (0x20 - n);
    *(s32 *)(c + 0x84c) = 0x20;
    cmd = n | 0x40000000;
    *(volatile u32 *)0x10002000 = cmd;
    t = cmd & 0xF0000000;
    *(u32 *)(c + 0x82c) = t;
    if (t == 0x20000000 || t == 0x30000000 || t == 0x40000000) {
        *(s32 *)(c + 0x828) = 0;
    } else {
        *(s32 *)(c + 0x828) = 1;
    }
    *(s32 *)(c + 0x848) = (s32)_sceMpegWaitIpuIdle64(c);
    return r;
}

u32 _sceMpegPeepBit(u8 *c, s32 n) {
    if (*(s32 *)(c + 0x828) != 0 || n > *(s32 *)(c + 0x84c)) {
        func_401074C8(c);
        *(volatile u32 *)0x10002000 = 0x40000000;
        *(s32 *)(c + 0x828) = 0;
        *(s32 *)(c + 0x82c) = 0x40000000;
        *(s32 *)(c + 0x848) = (s32)_sceMpegWaitIpuIdle64(c);
        *(s32 *)(c + 0x84c) = 0x20;
    }
    return *(u32 *)(c + 0x848) >> -n;
}

void _sceMpegFlushBuf(void *m, s32 n) {
    u8 *c = m;
    u32 cmd;

    func_401074C8(c);
    cmd = n | 0x40000000;
    *(volatile u32 *)0x10002000 = cmd;
    cmd &= 0xF0000000;
    *(u32 *)(c + 0x82c) = cmd;
    if (cmd == 0x20000000 || cmd == 0x30000000 || cmd == 0x40000000) {
        *(s32 *)(c + 0x828) = 0;
    } else {
        *(s32 *)(c + 0x828) = 1;
    }
    *(s32 *)(c + 0x848) = (s32)_sceMpegWaitIpuIdle64(c);
    *(s32 *)(c + 0x84c) = 0x20;
}

void func_401074C8(u8 *c) {
    if ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000) {
        _sceMpegWaitIpuIdle(c);
    }
}

void func_40107500(void *c, s32 n) {
    _sceMpegFlushBuf(c, n);
}

s32 func_40107508(u8 *c, s32 *p2, s32 *p3, s32 *p4, s32 *p5) {
    s32 r = 1;
    s32 t;

    *(s32 *)(c + *(s32 *)(c + 0x820) * 0x140 + 0x6dc) = 1;
    *(s32 *)(c + 0x1c0) = 1;
    if (*(s32 *)(c + 0x160) == 2) {
        p2[5] = 0;
        p2[4] = 0;
        p2[1] = 0;
        p2[0] = 0;
    }
    if (*(s32 *)(c + 0x184) == 3) {
        *p3 = 2;
    } else {
        *p3 = 1;
        t = *(s32 *)(c + 0x184) == 2;
        p4[1] = t;
        p4[0] = t;
    }
    if (*(s32 *)(c + 0x160) == 1) {
        _sceMpegError(c, D_40135B80);
        r = 0;
    }
    *p5 &= ~1;
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401075C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401076B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107760);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107778);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401078F8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107970);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107A08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107AC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107B90);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107C40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107CF8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107DF0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107EF0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40107F90);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40108040);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40108120);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_40108208);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401082E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401083B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401084D0);

/* IPU_to DMA kick (D4 regs 0x1000B000..B020) under DIntr/EIntr; addr &= then |= in place (100 vs 99.75 for the one-expression form) */
void func_401085E8(u32 addr, s32 len) {
    s32 old = DIntr();

    if ((addr >> 28) == 7) {
        addr &= 0xFFFFFFF;
        addr |= 0x80000000;
    } else {
        addr &= 0xFFFFFFF;
    }
    *(volatile u32 *)0x1000B010 = addr;
    *(volatile u32 *)0x1000B020 = len >> 4;
    *(volatile u32 *)0x1000B000 = 0x100;
    if (old != 0) {
        EIntr();
    }
}
