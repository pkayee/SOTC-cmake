#include "common.h"

void func_40104A28(const char *);
void _sceMpegDispatchMpegCallback(void *, void *);

int sceSnprintf(char *, int, const char *, ...);

extern char D_40135A90[];
void scePrintf(const char *, ...);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegDemuxPssRing);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegDemuxPss);
s32 sceMpegDemuxPss(s32 a0, s32 a1, s32 a2)
{
    s32 ret;

    ret = sceMpegDemuxPssRing(a0, a1, a2, 0, -1);
    if (ret != 0)
    {
        return ret;
    }
    return ret;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegAddStrCallback);

/* NEARMISS-STUB _sceMpegType2id */
#if 0 /* NEARMISS 98.21% cat=regalloc sub=- | u64 switch on table mask (case FFFFFFFFFF first fixes layout); left: n copy a3 vs t0, idx a2 vs a3, const a0 vs a2 (target frees a0 after the sll). sceMpegAddSt | attempts=1 */
typedef struct {
    u64 id;
    u64 mask;
} MpegStrType;

extern MpegStrType D_4012EF18[];

u64 _sceMpegType2id(u32 type, u64 n) {
    u64 r = 0;
    s32 sh = 0;

    if (type < 10) {
        switch (D_4012EF18[type].mask) {
        case 0xFFFFFFFFFF:
            sh = 0;
            break;
        case 0xFFFF000000:
            sh = 24;
            break;
        case 0xFF00000000:
            sh = 32;
            break;
        default:
            return 0;
        }
        r = D_4012EF18[type].id | (n << sh);
    }
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegType2id);

void func_40104A28(const char *msg) {
    scePrintf(D_40135A90, msg);
}

s32 DIntr(void);
s32 EIntr(void);

void _sceMpegStopIpuDma(void) {
    s32 intr = DIntr();

    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (intr != 0) {
        EIntr();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
}

/* NEARMISS-STUB _sceMpegErrorBdec */
#if 0 /* NEARMISS 99.4% cat=regalloc sub=- | IPU_CTRL=0x40000000 between the two callbacks: target addr v1/value a1/3 in v0, ours addr v0; order swap 87.4, pointer local 99.4 | attempts=1 */
extern char D_40135A70[];
void _sceMpegError(u8 *c, const char *msg);

void _sceMpegErrorBdec(u8 *c) {
    s32 cb[8];
    s32 intr;

    _sceMpegError(c, D_40135A70);
    cb[0] = 2;
    _sceMpegDispatchMpegCallback(*(void **)(c + 0x868), cb);
    *(volatile u32 *)0x10002010 = 0x40000000;
    cb[0] = 3;
    _sceMpegDispatchMpegCallback(*(void **)(c + 0x868), cb);
    intr = DIntr();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (intr != 0) {
        EIntr();
    }
    *(volatile u32 *)0x1000B020 = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegErrorBdec);

void _sceMpegError(u8 *c, const char *msg) {
    s32 e[2];
    void *d = *(void **)(c + 0x868);

    if (d != 0 && c != 0 && *(s32 *)(c + 0xc) != 0) {
        e[1] = (s32)msg;
        e[0] = 0;
        _sceMpegDispatchMpegCallback(d, e);
    } else {
        func_40104A28(msg);
    }
}

/* NEARMISS-STUB _sceMpegError1 */
#if 0 /* NEARMISS 100.0% cat=linker-pad sub=- | objdiff 100 but module SHA1 red: reference keeps 8 trailing bytes after _sceMpegError1 (func_40104C40 at +0x48, C emits +0x40); layout shift to end of .text | attempts=1 */
void _sceMpegError1(void *c, const char *fmt, s32 arg) {
    char buf[256];

    sceSnprintf(buf, 0x100, fmt, arg);
    _sceMpegError(c, buf);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegError1);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40104C40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40104DC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_401054D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40105720);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40105BA8);
