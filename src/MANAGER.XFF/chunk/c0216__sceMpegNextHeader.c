#include "common.h"

s32 _sceMpegNextBit(void *, s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", _sceMpegNextHeader);

void func_40109790(void *c) {
    func_40109630(c, 0x20);
}

void func_401095F8(void *c);

void func_40109798(void *c) {
    u32 n;

    func_401095F8(c);
    n = -(*(volatile u32 *)0x10002020 & 7) & 7;
    if (n != 0) {
        func_40109630(c, n);
    }
}

void func_401097E8(u8 *c) {
    _sceMpegNextBit(c, 3);
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegNextBit(c, 8);
        _sceMpegNextBit(c, 8);
        *(s32 *)(c + 0x154) = _sceMpegNextBit(c, 8);
    }
    *(s32 *)(c + 0x158) = _sceMpegNextBit(c, 0xe);
    _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x15c) = _sceMpegNextBit(c, 0xe);
}

s32 func_40109878(void *c) {
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 8);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 7);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 0x14);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 0x16);
    _sceMpegNextBit(c, 1);
    return _sceMpegNextBit(c, 0x16);
}

/* NEARMISS-STUB func_40109910 */
#if 0 /* NEARMISS 54.84% cat=inline-unroll sub=- | branch part matches; the target loop is NOT strength-reduced (i, i<<2, two hoisted bases s5/s4, 0x70 frame); gcc 2.9 here reduces to a down-counter (0x40 frame) | attempts=1 */
void func_40109910(u8 *c) {
    s32 n;
    s32 i;

    if (*(s32 *)(c + 0x14C) != 0) {
        if (*(s32 *)(c + 0x194) != 0) {
            n = *(s32 *)(c + 0x188) != 0 ? 3 : 2;
        } else {
            n = 1;
        }
    } else if (*(s32 *)(c + 0x184) == 3) {
        n = *(s32 *)(c + 0x194) != 0 ? 3 : 2;
    } else {
        n = 1;
    }
    for (i = 0; i < n; i++) {
        ((s32 *)(c + 0x19C))[i] = _sceMpegNextBit(c, 16);
        _sceMpegNextBit(c, 1);
        ((s32 *)(c + 0x1A8))[i] = _sceMpegNextBit(c, 16);
        _sceMpegNextBit(c, 1);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109910);

extern s32 DIntr(void);
extern s32 EIntr(void);

void func_40109A08(u32 chcr) {
    s32 intr = DIntr();

    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = chcr;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (intr != 0) {
        EIntr();
    }
}

void func_40109A80(u32 chcr) {
    s32 intr = DIntr();

    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = chcr;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (intr != 0) {
        EIntr();
    }
}

typedef struct {
    u32 d4madr;
    u32 d4tadr;
    u32 d4qwc;
    u32 d4chcr;
    u32 d3madr;
    u32 d3qwc;
    u32 d3chcr;
    u32 ipubp;
    u32 ipuctrl;
} IpuDmaEnv;

void sceIpuStopDMA(IpuDmaEnv *env) {
    func_40109A80(1);
    env->d4madr = *(volatile u32 *)0x1000B410;
    env->d4tadr = *(volatile u32 *)0x1000B430;
    env->d4qwc = *(volatile u32 *)0x1000B420;
    env->d4chcr = *(volatile u32 *)0x1000B400;
    while (*(volatile u32 *)0x10002010 & 0xF0) {
    }
    func_40109A08(0);
    env->d3madr = *(volatile u32 *)0x1000B010;
    env->d3qwc = *(volatile u32 *)0x1000B020;
    env->d3chcr = *(volatile u32 *)0x1000B000;
    env->ipubp = *(volatile u32 *)0x10002020;
    env->ipuctrl = *(volatile u32 *)0x10002010;
}

void sceIpuRestartDMA(IpuDmaEnv *env) {
    u32 bp = env->ipubp;
    u32 ifc = (bp >> 8) & 0xF;
    u32 fp = (bp >> 16) & 3;
    u32 bpos = bp & 0x7F;
    u32 madr = env->d4madr - ((fp + ifc) << 4);
    u32 qwc = env->d4qwc + (fp + ifc);

    if (env->d3madr != 0 && env->d3qwc != 0) {
        *(volatile u32 *)0x1000B010 = env->d3madr;
        *(volatile u32 *)0x1000B020 = env->d3qwc;
        func_40109A08(env->d3chcr | 0x100);
    }
    while ((s32)*(volatile u32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = bpos;
    while ((s32)*(volatile u32 *)0x10002010 < 0) {
    }
    if (madr != 0 && qwc != 0) {
        *(volatile u32 *)0x1000B410 = madr;
        *(volatile u32 *)0x1000B430 = env->d4tadr;
        *(volatile u32 *)0x1000B420 = qwc;
        func_40109A80(env->d4chcr | 0x100);
    }
}

s32 sceIpuSync(s32 mode) {
    s32 r = 0;

    switch (mode) {
    case 0:
        while ((s32)*(volatile u32 *)0x10002010 < 0) {
        }
        r = 0;
        break;
    case 1:
        r = *(volatile u32 *)0x10002010 >> 31;
        break;
    }
    return r;
}

void func_40109D98(u32 chcr) {
    s32 intr = DIntr();

    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = chcr;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (intr != 0) {
        EIntr();
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", sceIpuInit);
