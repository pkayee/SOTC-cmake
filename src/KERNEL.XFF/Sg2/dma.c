#include "common.h"

s32 Sg2RemoteSendDmaCom(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2RemoteDmaTransStatus();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dma", Sg2DmaTransVoice);
s32 Sg2DmaTransVoice(s32 arg0, s32 arg1, s32 arg2)
{
    return Sg2RemoteSendDmaCom(0x13, arg0, arg1, arg2);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/dma", Sg2DmaTransStatus);
s32 Sg2DmaTransStatus()
{
    return Sg2RemoteDmaTransStatus();
}
