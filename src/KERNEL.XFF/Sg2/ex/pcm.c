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
extern PcmInSlot D_40115958[];
extern PcmInSlot D_4011595C[];
extern PcmInSlot D_40115970[];
extern PcmInSlot D_40115B04[];
extern PcmInSlot D_40115B18[];
extern s32 D_401157AC;
s32 func_40040398(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
void Sg2ExPcmOutputCtrl(s32 arg0);
s32 DIntr(void);
void EIntr(void);
void free(void *p);
void func_40040710();

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F788);
void func_4003F788(s32 *arg0, s32 arg1)
{
    f32 *buf = (f32 *)arg0[1];
    s32 i = 0;

    while (i < arg1)
    {
        f32 v = (buf[i] + buf[i + 256]) * 0.5f;
        buf[i + 256] = v;
        buf[i] = v;
        i++;
        if (i & 0x100)
        {
            i += 0x100;
        }
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F7E8);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F8F0);
void func_4003F8F0(s32 *arg0, s32 *arg1, s32 arg2)
{
    f32 *a = (f32 *)arg0[1];
    f32 *b = (f32 *)arg1[1];

    if (arg2 > 0)
    {
        do
        {
            *a = *a + *b;
            b++;
            a++;
            arg2--;
        } while (arg2 != 0);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F928);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FAD0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FBD8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FC78);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FD60);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FF10);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400A0);
s32 func_400400A0(u8 *arg0)
{
    if (arg0[0] != 0x45 || arg0[1] != 0x51 || arg0[2] != 0x41 || arg0[3] != 0x54)
    {
        return -1;
    }
    return ((s32 *)arg0)[1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400F0);
void *func_400400F0(s32 *arg0, s32 arg1)
{
    return (char *)arg0 + (arg0[arg1 + 2] / 4) * 4;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040118);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040350);
s32 func_40040350(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        if (D_40115958[i].f[1] == 0)
        {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040398);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputOpenDoubleBuffer);
s32 Sg2ExPcmInputOpenDoubleBuffer(s32 arg0, s32 arg1, s32 arg2)
{
    return func_40040398(arg0, arg1, arg1 / 2, arg2, 1, 0, 0, 0);
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetVol);
void Sg2ExPcmInputSetVol(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B04[arg0].f[0] = arg1;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPan);
void Sg2ExPcmInputSetPan(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B18[arg0].f[0] = arg1;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPhase);
void Sg2ExPcmInputSetPhase(u32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 4)
    {
        PcmInSlot *p = &D_40115958[arg0];
        p->f[108] = arg1;
        p->f[109] = arg2;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetOutputMode);
void Sg2ExPcmInputSetOutputMode(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B00[arg0].f[0] = arg1;
    }
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterInit);
void Sg2ExPcmInputAutoFilterInit(u32 arg0)
{
    if (arg0 < 4)
    {
        func_4003FC78(&D_4011595C[arg0]);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilterDirect);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilter);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterCtrl);
void Sg2ExPcmInputAutoFilterCtrl(u32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 4)
    {
        *(s32 *)((u8 *)D_40115970 + arg1 * 196 + arg0 * 468) = arg2;
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputOpen);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputClose);
s32 Sg2ExPcmOutputClose(void)
{
    s32 intr;
    s32 buf;
    s32 *p;

    intr = DIntr();
    Sg2ExPcmOutputCtrl(2);
    p = &D_401157A0;
    buf = p[3];
    p[3] = 0;
    if (intr)
    {
        EIntr();
    }
    free((void *)buf);
    return 0;
}

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
void Sg2ExPcmCheckAutoFilterSeq(u8 *arg0)
{
    func_400400A0(arg0);
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmSetSignal);
void Sg2ExPcmSetSignal(s32 arg0)
{
    D_401160A8 = arg0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInit);
