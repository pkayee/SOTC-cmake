#include "common.h"

typedef struct
{
    s32 vol;
    s32 type;
    s32 endAdr;
    s16 depthL;
    s16 depthR;
    s32 delay;
    s32 feedBack;
} Sg2DspCore;

extern Sg2DspCore D_400F8F48[];
extern s32 D_400F8F58[][6];
extern s32 D_400F8F5C[][6];

s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 DIntr();
s32 EIntr();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DmaInit);
s32 Sg2DmaInit()
{
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetEndAdr);
s32 Sg2DspEffectSetEndAdr(s32 core, s32 val)
{
    s32 intr = DIntr();
    s32 old = D_400F8F48[core].endAdr;
    D_400F8F48[core].endAdr = val;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetType);
s32 Sg2DspEffectSetType(s32 core, s32 val)
{
    s32 intr = DIntr();
    s32 old = D_400F8F48[core].type;
    D_400F8F48[core].type = val;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetDepth);
s32 Sg2DspEffectSetDepth(s32 core, s16 val)
{
    s32 intr = DIntr();
    s16 old = D_400F8F48[core].depthL;
    D_400F8F48[core].depthL = val;
    D_400F8F48[core].depthR = val;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetDepth2);
s32 Sg2DspEffectSetDepth2(s32 core, s16 l, s16 r)
{
    s32 intr = DIntr();
    s16 old = D_400F8F48[core].depthL;
    D_400F8F48[core].depthL = l;
    D_400F8F48[core].depthR = r;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetDelay);
s32 Sg2DspEffectSetDelay(s32 core, s32 val)
{
    s32 intr = DIntr();
    s32 old = D_400F8F58[core][0];
    D_400F8F58[core][0] = val;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetFeedBack);
s32 Sg2DspEffectSetFeedBack(s32 core, s32 val)
{
    s32 intr = DIntr();
    s32 old = D_400F8F5C[core][0];
    D_400F8F5C[core][0] = val;
    if (intr)
    {
        EIntr();
    }
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectChange);
s32 Sg2DspEffectChange(s32 core)
{
    s32 intr = DIntr();
    s32 l = D_400F8F48[core].depthL * 0x7FFF / 127;
    s32 r = D_400F8F48[core].depthR * 0x7FFF / 127;
    Sg2RemoteSend(11, core, D_400F8F48[core].endAdr, 0);
    Sg2RemoteSend(16, core, D_400F8F48[core].feedBack, 0);
    Sg2RemoteSend(15, core, D_400F8F48[core].delay, 0);
    Sg2RemoteSend(14, core, l, r);
    {
        s32 t = D_400F8F48[core].type;
        s32 n = t & ~0x100;
        D_400F8F48[core].type = n;
        Sg2RemoteSend((t & 0x100) ? 13 : 12, core, n, 0);
    }
    if (intr)
    {
        EIntr();
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspEffectSetSwitch);
s32 Sg2DspEffectSetSwitch(s32 arg0, s32 arg1)
{
    return Sg2RemoteSend(9, 0, arg0, arg1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspSetMasterVolume);
s32 Sg2DspSetMasterVolume(s32 core, s32 l, s32 r)
{
    s32 intr = DIntr();
    D_400F8F48[core].vol = l;
    Sg2RemoteSend(6, core, l, r);
    if (intr)
    {
        return EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspSetMasterVolumeMax);
s32 Sg2DspSetMasterVolumeMax()
{
    Sg2DspSetMasterVolume(0, 0x3FFF, 0x3FFF);
    return Sg2DspSetMasterVolume(1, 0x3FFF, 0x3FFF);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspGetMasterVolume);
s32 Sg2DspGetMasterVolume(s32 core)
{
    return D_400F8F48[core].vol;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dsp", Sg2DspInit);
s32 Sg2DspInit()
{
    s32 i;
    Sg2DspCore *p = D_400F8F48;
    for (i = 1; i >= 0; i--, p++)
    {
        p->vol = 0;
        p->type = 0;
        p->depthL = 0;
        p->depthR = 0;
        p->delay = 0;
        p->feedBack = 0;
    }
    return 0;
}
