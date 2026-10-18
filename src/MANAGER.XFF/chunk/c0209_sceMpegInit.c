#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegInit);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDelete);
s32 sceMpegDelete(u8* mp)
{
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegAddBs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetPicture);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetPictureRAW8);

void sceMpegGetPictureAbort(u8 *m) {
    *(s32 *)(*(u8 **)(m + 0x40) + 0x878) = 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegReset);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetBuffType);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetPictureRAW8xy);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetDefaultPtsGap);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcAlloc);

s32 _sceMpegAlalcReset(s32 *a) {
    return (a[0] + a[1]) - a[2];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDefaultStopDMA);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDefaultRestartDMA);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_401008B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100B48);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100E08);
