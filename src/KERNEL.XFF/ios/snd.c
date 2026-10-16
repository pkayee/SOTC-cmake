#include "common.h"

typedef struct
{
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ u64 unk8;
} SndSep;

s32 Sg2VabClose(s32 arg0);
s32 Sg2SlotTbl();
void Sg2SlotSetOutputMode(s32 arg0);

extern s32 D_40045EA4;
extern s32 D_40045EA8;
extern void *D_400F6D88;
extern void *D_400F6D8C;
extern s32 soundTickProcCnt;
extern s32 sg2NicoReverbMode;

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", func_4002F2A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepTickProc);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepReq);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPlayerSrh);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPlayerSrh2);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepStopReq);
void sndSepStopReq(SndSep *arg0)
{
    arg0->unk8 |= 0x100000000;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetVol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetPan);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetDefaultParam);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPauseAll);
void sndSepPauseAll(s32 arg0)
{
    if (arg0 != 0)
    {
        D_40045EA4 = 1;
    }
    else
    {
        D_40045EA4 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPause);
void sndSepPause(SndSep *arg0)
{
    arg0->unk8 |= 0x200000000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepCont);
void sndSepCont(SndSep *arg0)
{
    arg0->unk8 &= ~0x200000000;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepStopTypeAll);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepInitTickParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabCreate);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabDelete);
void sndVabDelete(u32 *arg0)
{
    *arg0 &= ~1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabHDOpen);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabHDClose);
s32 sndVabHDClose(s32 *arg0)
{
    return Sg2VabClose(arg0[1]);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndBDOpen);

void sndBDClose(void) {
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", initSound);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", tickProcSound);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", addAdpcmTickProcFunc);
void addAdpcmTickProcFunc(void *arg0)
{
    D_400F6D88 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", setPcmTickProcFunc);
void setPcmTickProcFunc(void *arg0)
{
    D_400F6D8C = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundGetTickProcCnt);
s32 soundGetTickProcCnt(void)
{
    return soundTickProcCnt;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundSetRevMode);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundGetRevMode);
s32 soundGetRevMode(void)
{
    return sg2NicoReverbMode;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", getSlotInfo);
s32 getSlotInfo()
{
    return Sg2SlotTbl();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", setSoundMode);
void setSoundMode(s32 arg0)
{
    D_40045EA8 = arg0 ? 1 : 2;
    Sg2SlotSetOutputMode(D_40045EA8);
}
