#include "common.h"

s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2CtrlSetTickTime(s32 time);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/chip", Sg2ChipSetDigitalOutputMode);
s32 Sg2ChipSetDigitalOutputMode(s32 mode)
{
    Sg2RemoteSend(5, 1, mode, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/chip", Sg2ChipInit);
s32 Sg2ChipInit()
{
    Sg2CtrlSetTickTime(0);
    Sg2RemoteSend(0x11, 0, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/chip", Sg2ChipInitHot);
s32 Sg2ChipInitHot()
{
    Sg2RemoteSend(0x11, 1, 0, 0);
    return 0;
}

void func_40030D00(void) {
}
