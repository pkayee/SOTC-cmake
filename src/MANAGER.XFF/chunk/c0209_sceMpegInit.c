#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegInit);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDelete);
s32 sceMpegDelete(u8* mp)
{
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegAddBs);

s32 func_400FF9B8(u8 *);

s32 sceMpegGetPicture(u8 *m, u32 buf, s32 n) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s32 *)(c + 0xC4) = 1;
    *(u32 *)(c + 0xEC) = (buf & 0xFFFFFFF) | 0x20000000;
    *(s32 *)(c + 0xF8) = n;
    *(s32 *)(c + 0xF4) = 0;
    *(s32 *)(c + 0xF0) = 0;
    return func_400FF9B8(m);
}

s32 func_400FF9B8(u8 *);

s32 sceMpegGetPictureRAW8(u8 *m, u32 buf, s32 n) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s32 *)(c + 0xF8) = n;
    *(u32 *)(c + 0xEC) = (buf & 0xFFFFFFF) | 0x20000000;
    *(s32 *)(c + 0xC4) = 0;
    *(s32 *)(c + 0xF4) = 0;
    *(s32 *)(c + 0xF0) = 0;
    return func_400FF9B8(m);
}

void sceMpegGetPictureAbort(u8 *m) {
    *(s32 *)(*(u8 **)(m + 0x40) + 0x878) = 1;
}

void func_400FF8F0(void *);

s32 sceMpegReset(u8 *m) {
    u8 *c = *(u8 **)(m + 0x40);
    u32 *ipu;

    *(s32 *)(c + 0x878) = 0;
    *(s32 *)(c + 0) = 0;
    *(s32 *)(c + 4) = 0;
    *(s32 *)(c + 8) = 0;
    *(s32 *)(m + 8) = 0;
    *(s32 *)(c + 0xC0) = 0;
    *(s32 *)(c + 0x98) = -1;
    func_400FF8F0(c);
    *(s32 *)(c + 0x128) = 0;
    *(s32 *)(c + 0x858) = 0;
    ipu = (u32 *)0x10002010;
    *ipu = (*ipu & 0xFF7FFFFF) | 0x800000;
    return 1;
}

s32 sceMpegIsEnd(u8 *m) {
    return **(s32 **)(m + 0x40);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegIsRefBuffEmpty);
int sceMpegIsRefBuffEmpty(void *arg0)
{
    return (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 4)) == 0;
}

void sceMpegSetDecodeMode(u8 *m, s32 a, s32 b, s32 c3) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s32 *)(c + 0xA8) = a;
    *(s32 *)(c + 0xAC) = b;
    *(s32 *)(c + 0xB0) = c3;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetDecodeMode);
void sceMpegGetDecodeMode(void *arg0, void *arg1, void *arg2, void *arg3)
{
    (*(int *)((char *)(arg1) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xA8));
    (*(int *)((char *)(arg2) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xAC));
    (*(int *)((char *)(arg3) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xB0));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegAddCallback);

void func_400FF4E8(u8 *);

s32 sceMpegSetBuffType(u8 *m, u32 type) {
    u8 *c = *(u8 **)(m + 0x40);

    if (type >= 2) {
        return -1;
    }
    *(u32 *)(c + 0x87C) = type;
    func_400FF4E8(c);
    return 1;
}

s32 sceMpegGetBuffType(u8 *m) {
    return *(s32 *)(*(u8 **)(m + 0x40) + 0x87C);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDispatchMpegCallback);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDispatchMpegCbNodata);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100540);

s32 sceMpegClearRefBuff(u8 *m) {
    u8 *c = *(u8 **)(m + 0x40);
    u8 *t;

    t = *(u8 **)(c + 0x1C8);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    t = *(u8 **)(c + 0x1D8);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    t = *(u8 **)(c + 0x1E8);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    t = *(u8 **)(c + 0x1CC);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    t = *(u8 **)(c + 0x1DC);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    t = *(u8 **)(c + 0x1EC);
    if (t != 0) {
        *(s32 *)(t + 0x28) = 0;
    }
    return 1;
}

s32 func_400FF9B8(u8 *);

s32 sceMpegGetPictureRAW8xy(u8 *m, u32 buf, s32 w, s32 h) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s32 *)(c + 0xF4) = h << 4;
    *(u32 *)(c + 0xEC) = (buf & 0xFFFFFFF) | 0x20000000;
    *(s32 *)(c + 0xF8) = w * h;
    *(s32 *)(c + 0xF0) = w << 4;
    *(s32 *)(c + 0xC4) = 0;
    return func_400FF9B8(m);
}

s32 sceMpegSetDefaultPtsGap(u8 *m, s64 gap) {
    *(s32 *)(*(u8 **)(m + 0x40) + 0x8C) = 1;
    *(s64 *)(*(u8 **)(m + 0x40) + 0x90) = gap;
    return 1;
}

s32 sceMpegResetDefaultPtsGap(u8 *m) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s32 *)(c + 0x8C) = 0;
    *(s64 *)(c + 0x90) = 0;
    return 1;
}

s32 sceMpegSetImageBuff(u8 *m, s32 buf) {
    *(s32 *)(*(u8 **)(m + 0x40) + 0xEC) = buf;
    return 1;
}

s32 sceMpegDispWidth(u8 *m) {
    return *(s32 *)(*(u8 **)(m + 0x40) + 0xE0);
}

s32 sceMpegDispHeight(u8 *m) {
    return *(s32 *)(*(u8 **)(m + 0x40) + 0xE4);
}

s32 sceMpegDispCenterOffX(u8 *m) {
    return *(s32 *)(m + 0x40) + 0xC8;
}

s32 sceMpegDispCenterOffY(u8 *m) {
    return *(s32 *)(m + 0x40) + 0xC8;
}

s32 _sceMpegSetBrokenLink(u8 *m, s32 v) {
    s32 old = *(s32 *)(*(u8 **)(m + 0x40) + 0xFC);

    *(s32 *)(*(u8 **)(m + 0x40) + 0xFC) = v;
    return old;
}

s32 _sceMpegSetPtm(u8 *m, s64 ptm) {
    u8 *c = *(u8 **)(m + 0x40);

    *(s64 *)(c + 0x100) = ptm;
    *(s32 *)(c + 0x108) = 1;
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_401006D8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcInit);
void _sceMpegAlalcInit(s32 *m, s32 a1, s32 a2)
{
    m[0] = a1;
    m[1] = a2;
    m[2] = a1;
    m[3] = a1;
}

void _sceMpegAlalcSetDynamic(s32 *a) {
    a[3] = a[2];
}

void _sceMpegAlalcFree(s32 *a) {
    a[2] = a[3];
}

void _sceMpegError(void *, const char *);
extern const char D_401359A8[];

s32 _sceMpegAlalcAlloc(void *m, s32 *a, u32 size, u32 align) {
    u32 p;

    p = ((a[2] + align - 1) / align) * align;
    if ((u32)(a[0] + a[1]) >= p + size) {
        a[2] = p + size;
        return p;
    }
    _sceMpegError(m, D_401359A8);
    return 0;
}

s32 _sceMpegAlalcReset(s32 *a) {
    return (a[0] + a[1]) - a[2];
}

void sceIpuStopDMA(void *);

s32 _sceMpegDefaultStopDMA(u8 *m) {
    sceIpuStopDMA(*(u8 **)(m + 0x40) + 0x68);
    return 1;
}

void sceIpuRestartDMA(void *);

s32 _sceMpegDefaultRestartDMA(u8 *m) {
    sceIpuRestartDMA(*(u8 **)(m + 0x40) + 0x68);
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_401008B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100B48);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100E08);
