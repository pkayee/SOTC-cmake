#include "common.h"

s32 _sceMpegNextBit(void *, s32);
void func_40109428(void *);

extern char D_40135D10[];
void _sceMpegError(void *, const char *);

extern char D_40135D40[];

extern char D_40135D58[];

extern char D_40135D90[];

extern char D_40135C08[];
extern char D_40135C30[];
void func_40109630(void *c, s32 n);
void func_40109790(void *c);
void func_40109798(void *c);
u32 _sceMpegPeepBit(void *c, s32 n);
void _sceMpegError1(void *c, const char *fmt, s32 arg);
s32 _sceMpegMbAddressIncrement(void *c);

s32 _sceMpegSliceA0(u8 *c, s32 unused, s32 *mbaddr, s32 *inc, s32 *pmv) {
    u32 code;
    s32 n;

    *(s32 *)(c + 0x12C) = 0;
    func_40109798(c);
    while (_sceMpegPeepBit(c, 24) != 1 && *(s32 *)(c + 0x878) == 0) {
        func_40109630(c, 8);
    }
    code = _sceMpegPeepBit(c, 32);
    if (code - 0x101 >= 0xAF) {
        _sceMpegError1(c, D_40135C08, code);
        return 2;
    }
    func_40109790(c);
    *(s32 *)(c + 0x1C4) = _sceMpegNextBit(c, 5);
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegNextBit(c, 1);
        func_40109630(c, 7);
        while (_sceMpegNextBit(c, 1) != 0) {
            func_40109630(c, 8);
        }
    }
    n = _sceMpegMbAddressIncrement(c);
    *inc = n;
    if (*(s32 *)(c + 0x12C) != 0) {
        _sceMpegError(c, D_40135C30);
        return 1;
    }
    *mbaddr = ((code & 0xFF) - 1) * *(s32 *)(c + 0x13C) + n - 1;
    *inc = 1;
    *(s32 *)(c + 0x1C0) = 1;
    pmv[5] = 0;
    pmv[4] = 0;
    pmv[1] = 0;
    pmv[0] = 0;
    pmv[7] = 0;
    pmv[6] = 0;
    pmv[3] = 0;
    pmv[2] = 0;
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40108828);

extern char D_40135C58[];
extern u8 D_4012F000[];
extern u8 D_4012F040[];
void _sceMpegDispatchMpegCallback(void *, void *);
s32 DIntr(void);
s32 EIntr(void);
void func_401095F8(void *c);
void func_40109428(void *c);
void func_40108828(void *d);

/* NEARMISS-STUB func_40108B40 */
#if 0 /* NEARMISS 96.87% cat=volatile-alias sub=- | all HW writes volatile match except two that the target puts in delay slots (IPU_CMD=0 after jal, D4_CHCR=0x101 in beqz slot); non-volatile gives lui-at %lo for | attempts=1 */
typedef struct {
    s32 type;
    s32 pad[7];
} MpegCbData;

static inline void mpegLoadDefaultMatrix(u8 *c, u8 *mtx, u32 cmd) {
    MpegCbData cb;
    s32 intr;

    cb.type = 2;
    _sceMpegDispatchMpegCallback(*(void **)(c + 0x868), &cb);
    func_401095F8(c);
    *(volatile u32 *)0x10002000 = 0;
    func_401095F8(c);
    intr = DIntr();
    *(volatile u32 *)0x1000B410 = (u32)mtx & 0x0FFFFFFF;
    *(volatile u32 *)0x1000B420 = 4;
    *(volatile u32 *)0x1000B400 = 0x101;
    if (intr != 0) {
        EIntr();
    }
    *(volatile u32 *)0x10002000 = cmd;
    *(s32 *)(c + 0x82C) = 0x50000000;
    *(s32 *)(c + 0x828) = 1;
    func_401095F8(c);
    cb.type = 3;
    _sceMpegDispatchMpegCallback(*(void **)(c + 0x868), &cb);
}

void func_40108B40(u8 *c) {
    u32 v;

    *(s32 *)(c + 0xE8) = 0;
    v = _sceMpegNextBit(c, 32);
    *(u32 *)(c + 0x134) = v >> 20;
    *(s32 *)(c + 0x138) = (v >> 8) & 0xFFF;
    if (*(s32 *)(c + 0x138) > 0xAF0) {
        _sceMpegError(c, D_40135C58);
    }
    v = _sceMpegNextBit(c, 30);
    *(u32 *)(c + 0x144) = v >> 12;
    *(u32 *)(c + 0x148) = (v >> 1) & 0x3FF;
    if ((*(s32 *)(c + 0x850) = _sceMpegNextBit(c, 1)) != 0) {
        func_401095F8(c);
        *(volatile u32 *)0x10002000 = 0x50000000;
        *(s32 *)(c + 0x82C) = 0x50000000;
        *(s32 *)(c + 0x828) = 1;
        func_401095F8(c);
    } else {
        mpegLoadDefaultMatrix(c, D_4012F000, 0x50000000);
    }
    if ((*(s32 *)(c + 0x854) = _sceMpegNextBit(c, 1)) != 0) {
        func_401095F8(c);
        *(volatile u32 *)0x10002000 = 0x58000000;
        *(s32 *)(c + 0x82C) = 0x50000000;
        *(s32 *)(c + 0x828) = 1;
        func_401095F8(c);
    } else {
        mpegLoadDefaultMatrix(c, D_4012F040, 0x58000000);
    }
    func_40109428(c);
    func_40108828(*(void **)(c + 0x868));
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40108B40);

void func_40108DF0(u8 *c) {
    *(s32 *)(c + 0xfc) = 0;
    *(s32 *)(c + 0x864) = 1;
    *(s32 *)(c + 0x85c) = *(s32 *)(c + 0x860) + 1;
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 5);
    _sceMpegNextBit(c, 6);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 6);
    _sceMpegNextBit(c, 6);
    *(s32 *)(c + 0x1b4) = _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x1b8) = _sceMpegNextBit(c, 1);
    func_40109428(c);
}

void func_40109630(void *c, s32 n);

void func_40108E90(u8 *c) {
    s32 tr;
    s32 wrap;
    s32 last;
    s32 t;

    tr = _sceMpegNextBit(c, 10);
    *(s32 *)(c + 0x160) = _sceMpegNextBit(c, 3);
    _sceMpegNextBit(c, 16);
    if ((u32)(*(s32 *)(c + 0x160) - 2) < 2) {
        *(s32 *)(c + 0x164) = _sceMpegNextBit(c, 1);
        *(s32 *)(c + 0x168) = _sceMpegNextBit(c, 3);
    }
    if (*(s32 *)(c + 0x160) == 3) {
        *(s32 *)(c + 0x16C) = _sceMpegNextBit(c, 1);
        *(s32 *)(c + 0x170) = _sceMpegNextBit(c, 3);
    }
    while (_sceMpegNextBit(c, 1) != 0) {
        func_40109630(c, 8);
    }
    func_40109428(c);
    wrap = 0;
    last = 0;
    if (*(s32 *)(c + 0x160) != 3 && tr != 0) {
        if (tr < 0) {
            wrap = *(s32 *)(c + 0x864) == 0;
        }
        *(s32 *)(c + 0x864) = 0;
        last = tr;
    }
    t = *(s32 *)(c + 0x85C) + tr;
    *(s32 *)(c + 0x1BC) = t;
    if (wrap != 0 && last >= tr) {
        *(s32 *)(c + 0x1BC) = t + 0x400;
    }
    *(s32 *)(c + 0x860) = *(s32 *)(c + 0x860) < *(s32 *)(c + 0x1BC) ? *(s32 *)(c + 0x1BC) : *(s32 *)(c + 0x860);
}

extern char D_40135C70[];
extern char D_40135C98[];

void func_40108FD8(u8 *c) {
    u32 v;
    u32 a, b, d, t, e, w;

    *(s32 *)(c + 0x858) = 1;
    *(u32 *)0x10002010 &= 0xFF7FFFFF;
    v = _sceMpegNextBit(c, 28);
    a = (v >> 1) & 0xFFF;
    b = (v >> 13) & 3;
    d = (v >> 15) & 3;
    t = (v >> 17) & 3;
    *(u32 *)(c + 0x150) = t;
    if (t != 1) {
        _sceMpegError(c, D_40135C70);
    }
    *(u32 *)(c + 0x14C) = (v >> 19) & 1;
    e = v >> 20;
    w = (u32)_sceMpegNextBit(c, 16) >> 8;
    if (e != 0x48 && e != 0x58 && e != 0x44) {
        _sceMpegError(c, D_40135C98);
    }
    *(u32 *)(c + 0x134) = (d << 12) | (*(u32 *)(c + 0x134) & 0xFFF);
    *(u32 *)(c + 0x138) = (b << 12) | (*(u32 *)(c + 0x138) & 0xFFF);
    *(u32 *)(c + 0x144) += a << 18;
    *(u32 *)(c + 0x148) += w << 10;
}

extern char D_40135CB8[];
extern char D_40135CE0[];
void func_401095F8(void *c);

void func_40109118(u8 *c) {
    if ((*(s32 *)(c + 0x850) = _sceMpegNextBit(c, 1)) != 0) {
        func_401095F8(c);
        *(volatile u32 *)0x10002000 = 0x50000000;
        *(s32 *)(c + 0x82C) = 0x50000000;
        *(s32 *)(c + 0x828) = 1;
        func_401095F8(c);
    }
    if ((*(s32 *)(c + 0x854) = _sceMpegNextBit(c, 1)) != 0) {
        func_401095F8(c);
        *(volatile u32 *)0x10002000 = 0x58000000;
        *(s32 *)(c + 0x82C) = 0x50000000;
        *(s32 *)(c + 0x828) = 1;
        func_401095F8(c);
    }
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegError(c, D_40135CB8);
    }
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegError(c, D_40135CE0);
    }
}

void func_40109200(void *c) {
    _sceMpegError(c, D_40135D10);
}

void func_40109210(void *c) {
    _sceMpegError(c, D_40135D40);
}

/* NEARMISS-STUB func_40109220 */
#if 0 /* NEARMISS 87.73% cat=sched sub=- | IPU_CTRL RMW stores (non-volatile, at-form) land before the next NextBit a1 setup instead of the jal delay slot; final NextBit(c,8) becomes a sibcall (target ja | attempts=1 */
void func_40109220(u8 *c) {
    s32 v;

    *(s32 *)(c + 0x174) = _sceMpegNextBit(c, 4);
    *(s32 *)(c + 0x178) = _sceMpegNextBit(c, 4);
    *(s32 *)(c + 0x17C) = _sceMpegNextBit(c, 4);
    *(s32 *)(c + 0x180) = _sceMpegNextBit(c, 4);
    *(u32 *)0x10002010 = (*(u32 *)0x10002010 & 0xFFFCFFFF) | (_sceMpegNextBit(c, 2) << 16);
    v = _sceMpegNextBit(c, 2);
    *(s32 *)(c + 0x184) = v;
    if (*(s32 *)(c + 0xE8) == 0) {
        *(s32 *)(c + 0xE8) = v;
    }
    *(s32 *)(c + 0x188) = _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x18C) = _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x190) = _sceMpegNextBit(c, 1);
    *(u32 *)0x10002010 = (*(u32 *)0x10002010 & 0xFFBFFFFF) | (_sceMpegNextBit(c, 1) << 22);
    *(u32 *)0x10002010 = (*(u32 *)0x10002010 & 0xFFDFFFFF) | (_sceMpegNextBit(c, 1) << 21);
    *(u32 *)0x10002010 = (*(u32 *)0x10002010 & 0xFFEFFFFF) | (_sceMpegNextBit(c, 1) << 20);
    *(s32 *)(c + 0x194) = _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x198) = _sceMpegNextBit(c, 1);
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegNextBit(c, 1);
        _sceMpegNextBit(c, 3);
        _sceMpegNextBit(c, 1);
        _sceMpegNextBit(c, 7);
        _sceMpegNextBit(c, 8);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40109220);

void func_40109408(void *c) {
    _sceMpegError(c, D_40135D58);
}

void func_40109418(void *c) {
    _sceMpegError(c, D_40135D90);
}

typedef struct {
    void (*f[11])(void *);
} MpegExtTable;

extern MpegExtTable D_40135DC8;
void func_40109790(void *c);
void func_40109798(void *c);
u32 _sceMpegPeepBit(void *c, s32 n);

static inline void mpegNextStartCode(void *c) {
    func_40109798(c);
    while (_sceMpegPeepBit(c, 24) != 1 && *(s32 *)((u8 *)c + 0x878) == 0) {
        func_40109630(c, 8);
    }
}

void func_40109428(void *c) {
    MpegExtTable tbl = D_40135DC8;
    u32 code;
    u32 id;

    mpegNextStartCode(c);
    while ((code = _sceMpegPeepBit(c, 32)) == 0x1B5 || code == 0x1B2) {
        if (code == 0x1B5) {
            func_40109790(c);
            id = _sceMpegNextBit(c, 4);
            id = id > 10 ? 0 : id;
            tbl.f[id](c);
            mpegNextStartCode(c);
        } else {
            func_40109790(c);
            mpegNextStartCode(c);
        }
    }
}

void _sceMpegWaitIpuIdle(void *);

void func_401095F8(void *c) {
    if ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000) {
        _sceMpegWaitIpuIdle(c);
    }
}

void func_40109630(void *c, s32 n) {
    _sceMpegFlushBuf(c, n);
}
