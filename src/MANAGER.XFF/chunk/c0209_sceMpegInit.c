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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetPictureAbort);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegIsEnd);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegIsRefBuffEmpty);
int sceMpegIsRefBuffEmpty(void *arg0)
{
    return (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 4)) == 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetDecodeMode);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetDecodeMode);
void sceMpegGetDecodeMode(void *arg0, void *arg1, void *arg2, void *arg3)
{
    (*(int *)((char *)(arg1) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xA8));
    (*(int *)((char *)(arg2) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xAC));
    (*(int *)((char *)(arg3) + 0)) = (int) (*(int *)((char *)((*(void **)((char *)(arg0) + 0x40))) + 0xB0));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegAddCallback);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetBuffType);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetBuffType);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDispatchMpegCallback);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDispatchMpegCbNodata);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100540);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegClearRefBuff);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegGetPictureRAW8xy);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetDefaultPtsGap);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegResetDefaultPtsGap);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegSetImageBuff);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDispWidth);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDispHeight);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDispCenterOffX);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", sceMpegDispCenterOffY);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegSetBrokenLink);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegSetPtm);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_401006D8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcInit);
void _sceMpegAlalcInit(s32 *m, s32 a1, s32 a2)
{
    m[0] = a1;
    m[1] = a2;
    m[2] = a1;
    m[3] = a1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcSetDynamic);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcFree);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcAlloc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegAlalcReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDefaultStopDMA);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", _sceMpegDefaultRestartDMA);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_401008B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100B48);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0209_sceMpegInit", func_40100E08);
