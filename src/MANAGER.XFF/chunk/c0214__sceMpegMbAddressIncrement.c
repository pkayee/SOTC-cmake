#include "common.h"

extern char D_40135B80[];
void _sceMpegError(void *, const char *);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegMbAddressIncrement);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegWaitIpuIdle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegWaitIpuIdle64);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegNextBit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegPeepBit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", _sceMpegFlushBuf);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401074C8);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0214__sceMpegMbAddressIncrement", func_401085E8);
