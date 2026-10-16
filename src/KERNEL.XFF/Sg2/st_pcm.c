#include "common.h"

s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2RemoteGetPcmStmTransOffset();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmStart);
s32 Sg2StPcmStart(s32 arg0, s32 arg1)
{
    Sg2RemoteSend(0x20, arg0, arg1, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmStop);
s32 Sg2StPcmStop()
{
    Sg2RemoteSend(0x21, 0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmSetVolume);
s32 Sg2StPcmSetVolume(s32 arg0, s32 arg1)
{
    Sg2RemoteSend(0x22, arg0, arg1, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmSetEffect);
s32 Sg2StPcmSetEffect(s32 arg0)
{
    Sg2RemoteSend(0x23, arg0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmIopTransOffset);
s32 Sg2StPcmIopTransOffset()
{
    return Sg2RemoteGetPcmStmTransOffset();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmInit);
s32 Sg2StPcmInit()
{
    Sg2RemoteSend(0x1E, 0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/st_pcm", Sg2StPcmQuit);
s32 Sg2StPcmQuit()
{
    Sg2RemoteSend(0x1F, 0, 0, 0);
    return 0;
}
