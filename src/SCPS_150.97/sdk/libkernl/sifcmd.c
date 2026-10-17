#include "common.h"

extern s32 D_0014B4D8[];

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifGetSreg);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSetSreg);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifGetDataTable);

void *sceSifGetDataTable(void)
{
    return D_0014B4D8;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifInitCmd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifExitCmd);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSetCmdBuffer);

s32 sceSifSetCmdBuffer(s32 buf, s32 size)
{
    s32 old = D_0014B4D8[5];
    D_0014B4D8[5] = buf;
    D_0014B4D8[6] = size;
    return old;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSetSysCmdBuffer);

s32 sceSifSetSysCmdBuffer(s32 buf, s32 size)
{
    s32 old = D_0014B4D8[3];
    D_0014B4D8[3] = buf;
    D_0014B4D8[4] = size;
    return old;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifAddCmdHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifRemoveCmdHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", _sceSifSendCmd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSendCmd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", isceSifSendCmd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", _sceSifCmdIntrHdlr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifWriteBackDCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", func_00113174);
