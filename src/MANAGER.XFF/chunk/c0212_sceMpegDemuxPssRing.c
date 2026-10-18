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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegType2id);

void func_40104A28(const char *msg) {
    scePrintf(D_40135A90, msg);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegStopIpuDma);

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
