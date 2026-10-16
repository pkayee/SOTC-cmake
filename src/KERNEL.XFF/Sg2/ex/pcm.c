#include "common.h"

typedef struct { s32 f[117]; } PcmInSlot;
typedef struct { s32 f[49]; } PcmAfSlot;
extern PcmInSlot D_4011596C[];
extern PcmInSlot D_40115B28[];
extern PcmInSlot D_40115B00[];
extern PcmAfSlot D_401157BC[];
extern s32 D_401157B8;
extern s32 D_401157A0;
extern s32 D_401157A8[];
extern s32 D_401160A8;
s32 Sg2StPcmSetVolume(s32 arg0, s32 arg1);
s32 Sg2StPcmSetEffect(s32 arg0);
void *memset(void *s, int c, unsigned long n);
void func_4003FC78();
void func_400400A0();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F3C8);
void func_4003F3C8(s32 *arg0, s32 arg1)
{
    memset((void *)arg0[1], 0, arg1 * 4);
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F3E8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F468);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F528);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F5D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F6A0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F788);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F7E8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F8F0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F928);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FAD0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FBD8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FC78);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FD60);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FF10);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400A0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400F0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040118);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040350);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040398);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputOpenDoubleBuffer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputOpen);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputClose);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputCtrl);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputGetLipFrame);
s32 Sg2ExPcmInputGetLipFrame(u32 arg0)
{
    s32 ret;
    if (arg0 >= 4)
    {
        return -1;
    }
    ret = D_4011596C[arg0].f[0];
    return ret;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputGetRealPlayFrameCount);
s32 Sg2ExPcmInputGetRealPlayFrameCount(u32 arg0)
{
    s32 ret;
    if (arg0 >= 4)
    {
        return -1;
    }
    ret = D_40115B28[arg0].f[0];
    return ret;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040710);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetVol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPan);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPhase);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetOutputMode);
void Sg2ExPcmInputSetOutputMode(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B00[arg0].f[0] = arg1;
    }
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilterDirect);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilter);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterCtrl);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputOpen);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputClose);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputBufferClear);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetVol);
void Sg2ExPcmOutputSetVol(s32 arg0, s32 arg1)
{
    Sg2StPcmSetVolume(arg0, arg1);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetEffect);
void Sg2ExPcmOutputSetEffect(s32 arg0)
{
    Sg2StPcmSetEffect(arg0);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetOutputMode);
void Sg2ExPcmOutputSetOutputMode(s32 arg0)
{
    D_401157A0 = arg0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputCtrl);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputGetLipFrame);
s32 Sg2ExPcmOutputGetLipFrame(void)
{
    return D_401157B8;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputAutoFilterInit);
void Sg2ExPcmOutputAutoFilterInit(s32 arg0)
{
    func_4003FC78(D_401157A8, arg0);
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetAutoFilterDirect);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetAutoFilter);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputAutoFilterCtrl);
void Sg2ExPcmOutputAutoFilterCtrl(s32 arg0, s32 arg1)
{
    D_401157BC[arg0].f[0] = arg1;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmCheckAutoFilterSeq);
void Sg2ExPcmCheckAutoFilterSeq(void)
{
    func_400400A0();
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmSetSignal);
void Sg2ExPcmSetSignal(s32 arg0)
{
    D_401160A8 = arg0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInit);
