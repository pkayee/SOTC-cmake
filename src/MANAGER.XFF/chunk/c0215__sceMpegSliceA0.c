#include "common.h"

s32 _sceMpegNextBit(void *, s32);
void func_40109428(void *);

extern char D_40135D10[];
void _sceMpegError(void *, const char *);

extern char D_40135D40[];

extern char D_40135D58[];

extern char D_40135D90[];

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", _sceMpegSliceA0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40108828);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40108E90);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40108FD8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40109118);

void func_40109200(void *c) {
    _sceMpegError(c, D_40135D10);
}

void func_40109210(void *c) {
    _sceMpegError(c, D_40135D40);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40109220);

void func_40109408(void *c) {
    _sceMpegError(c, D_40135D58);
}

void func_40109418(void *c) {
    _sceMpegError(c, D_40135D90);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_40109428);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0215__sceMpegSliceA0", func_401095F8);

void func_40109630(void *c, s32 n) {
    _sceMpegFlushBuf(c, n);
}
