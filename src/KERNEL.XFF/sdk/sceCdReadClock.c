#include "common.h"
#include "sdk/ee/sifrpc.h"
#include "sdk/ee/eekernel.h"

typedef struct
{
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
    u16 year;
} sceCdCLOCK;

extern char _sceCd_cd_scmd[];
extern s32 _sceCd_scmdrdata[];
extern s32 _sceCd_scmd_semid;
s32 _sceCd_scmd_prechk(s32 arg);

s32 sceCdReadClock(sceCdCLOCK *clock)
{
    s32 ret;

    if (_sceCd_scmd_prechk(0xF) == 0)
    {
        return 0;
    }
    if (sceSifCallRpc((sceSifClientData *)_sceCd_cd_scmd, 1, 0, 0, 0, _sceCd_scmdrdata, 0x10, 0, 0) < 0)
    {
        SignalSema(_sceCd_scmd_semid);
        return 0;
    }
    *clock = *(sceCdCLOCK *)(((u32)_sceCd_scmdrdata + 4) | 0x20000000);
    ret = *(s32 *)((u32)_sceCd_scmdrdata | 0x20000000);
    SignalSema(_sceCd_scmd_semid);
    return ret;
}
