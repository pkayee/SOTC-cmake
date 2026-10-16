#include "common.h"

s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2RemoteGetAdpStmAdr();

typedef struct
{
    /* 0x00 */ u8 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
} Sg2StAdpcmOpenArg;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmOpen);
s32 Sg2StAdpcmOpen(Sg2StAdpcmOpenArg *arg0)
{
    s32 a1;
    s32 a2;
    s32 a3;

    a1 = (arg0->unk0 << 24) | (arg0->unk4 & 0xFF0000);
    a1 |= arg0->unk14 & 0xFF00;
    a1 |= (arg0->unk10 & 0xFF0000) >> 16;
    a2 = (arg0->unk10 << 16) | ((arg0->unkC >> 8) & 0xFFFF);
    a3 = (arg0->unkC << 24) | (arg0->unk8 & 0xFFFFFF);
    Sg2RemoteSend(0x18, a1, a2, a3);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmClose);
s32 Sg2StAdpcmClose(s32 arg0)
{
    Sg2RemoteSend(0x19, arg0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmSetVolume);
s32 Sg2StAdpcmSetVolume(u64 arg0, u32 arg1, s32 arg2)
{
    if (arg1 < 0x4000 && arg2 >= 0 && arg2 < 0x4000 && arg0 != 0)
    {
        Sg2RemoteSend(0x1A, arg0 & 0xFFFFFF, (arg0 >> 24) & 0xFFFFFF, (arg1 << 16) | arg2);
        return 0;
    }
    return -1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmSetPitch);
s32 Sg2StAdpcmSetPitch(u64 arg0, u32 arg1)
{
    if (arg1 <= 0x2EE00 && arg0 != 0)
    {
        Sg2RemoteSend(0x1B, arg0 & 0xFFFFFF, (arg0 >> 24) & 0xFFFFFF, arg1);
        return 0;
    }
    return -1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmPlay);
s32 Sg2StAdpcmPlay(u64 arg0)
{
    if (arg0 != 0)
    {
        Sg2RemoteSend(0x1C, arg0 & 0xFFFFFF, (arg0 >> 24) & 0xFFFFFF, 0);
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmStop);
s32 Sg2StAdpcmStop(u64 arg0)
{
    if (arg0 != 0)
    {
        Sg2RemoteSend(0x1D, arg0 & 0xFFFFFF, (arg0 >> 24) & 0xFFFFFF, 0);
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmIopReadAdr);
s32 Sg2StAdpcmIopReadAdr(void)
{
    return Sg2RemoteGetAdpStmAdr();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmInit);
s32 Sg2StAdpcmInit(void)
{
    Sg2RemoteSend(0x16, 0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_adpcm", Sg2StAdpcmQuit);
s32 Sg2StAdpcmQuit(void)
{
    Sg2RemoteSend(0x17, 0, 0, 0);
    return 0;
}
