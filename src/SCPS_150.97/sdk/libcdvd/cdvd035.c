#include "common.h"
#include "sdk/common/libcdvd.h"
#include "sdk/ee/sifrpc.h"
#include "sdk/ee/sifcmd.h"
#include "sdk/ee/eekernel.h"

extern char D_001356C0[];
extern s32 D_00133B6C[];
extern char D_00134D40[];
extern s32 D_00135180[];
extern s32 D_001356E8[];
extern s32 D_001356EC[];
extern s32 D_001356F0[];
s32 _sceCd_scmd_prechk(s32 arg);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd035", sceCdPowerOff);
int sceCdPowerOff(int *stat)
{
    s32 ret;

    if (_sceCd_scmd_prechk(0x21) == 0)
    {
        return 0;
    }
    if (sceSifCallRpc((sceSifClientData *)D_001356C0, 0x21, 0, 0, 0, D_00134D40, 8, 0, 0) < 0)
    {
        SignalSema(D_00133B6C[0]);
        return 0;
    }
    *stat = *(s32 *)(((u32)D_00134D40 + 4) | 0x20000000);
    ret = *(s32 *)((u32)D_00134D40 | 0x20000000);
    SignalSema(D_00133B6C[0]);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd035", sceCdMmode);
int sceCdMmode(int media)
{
    s32 ret;
    s32 *buf;

    buf = D_00135180;
    if (_sceCd_scmd_prechk(0x22) == 0)
    {
        return 0;
    }
    D_00135180[0] = media;
    sceSifWriteBackDCache(buf, 4);
    ret = sceSifCallRpc((sceSifClientData *)D_001356C0, D_001356E8[0], 0, buf, D_001356EC[0], D_00134D40, D_001356F0[0], 0, 0);
    if (ret < 0)
    {
        SignalSema(D_00133B6C[0]);
        return 0;
    }
    ret = *(s32 *)((u32)D_00134D40 | 0x20000000);
    SignalSema(D_00133B6C[0]);
    return ret;
}
