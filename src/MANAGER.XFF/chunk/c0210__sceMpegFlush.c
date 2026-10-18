#include "common.h"

extern char D_401359F8[];
void _sceMpegError(void *, const char *);
void func_40100B48(u8 *, void *, s32);
void func_40100E08(u8 *, void *, void *, s32);

s32 _sceMpegFlush(u8 *m) {
    u8 *c = *(u8 **)(m + 0x40);
    s32 r = 0;
    s32 n;

    if (*(s32 *)(c + 4) != 0 && *(s32 *)(c + 8) != 0) {
        n = *(s32 *)(c + 0x128);
        if (*(s32 *)(c + 0x130) != 0) {
            _sceMpegError(c, D_401359F8);
        } else {
            if (*(s32 *)(c + 0x184) == 3) {
                func_40100B48(c, *(void **)(c + 0x1cc), n - 1);
            } else {
                func_40100E08(c, *(void **)(c + 0x1dc), *(void **)(c + 0x1ec), n - 1);
            }
        }
        r = 1;
        *(s32 *)(c + 0x130) = 0;
        *(s32 *)(m + 8) = *(s32 *)(c + 0x128) - *(s32 *)(c + 0xc0);
        *(s32 *)(c + 4) = 0;
    }
    return r;
}

void _sceMpegOutputFrame(u8 *c, s32 n, s64 flag) {
    void *a;
    void *b;

    if (flag != 0) {
        if (*(s32 *)(c + 0x184) == 3) {
            if (*(s32 *)(c + 0x160) == 3) {
                a = *(void **)(c + 0x1d4);
            } else {
                a = *(void **)(c + 0x1c8);
            }
            func_40100B48(c, a, n - 1);
        } else {
            if (*(s32 *)(c + 0x160) == 3) {
                a = *(void **)(c + 0x1e4);
                b = *(void **)(c + 0x1f4);
            } else {
                a = *(void **)(c + 0x1d8);
                b = *(void **)(c + 0x1e8);
            }
            func_40100E08(c, a, b, n - 1);
        }
    }
    if (*(s32 *)(c + 0x108) == 1) {
        *(s32 *)(c + 0x108) = 2;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0210__sceMpegFlush", func_40101378);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0210__sceMpegFlush", _sceMpegCscStoreRefImage);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0210__sceMpegFlush", func_40101A10);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0210__sceMpegFlush", func_40101B58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0210__sceMpegFlush", _sceMpegId2type);
