#include "common.h"
#include "sdk/ee/sifrpc.h"
#include "sdk/ee/eekernel.h"

extern char _sceCd_cd_scmd[];
extern s32 _sceCd_scmdrdata[];
extern s32 _sceCd_scmd_semid;
extern s32 SCE_CD_debug;
extern char D_40049A58[];
s32 _sceCd_scmd_prechk(s32 arg);

s32 sceCdStatus(void)
{
    s32 ret;

    if (_sceCd_scmd_prechk(2) == 0)
    {
        return -1;
    }
    if (sceSifCallRpc((sceSifClientData *)_sceCd_cd_scmd, 0xC, 0, 0, 0, _sceCd_scmdrdata, 4, 0, 0) < 0)
    {
        SignalSema(_sceCd_scmd_semid);
        return -1;
    }
    ret = *(s32 *)((u32)_sceCd_scmdrdata | 0x20000000);
    SignalSema(_sceCd_scmd_semid);
    if (SCE_CD_debug >= 2)
    {
        scePrintf(D_40049A58);
    }
    return ret;
}
