#include "common.h"

/* NEARMISS-STUB sceCdReadIOPm */
#if 0 /* NEARMISS 91.88% cat=sched sub=- | 2.9 scheduling: arg regs and prologue match; cbfunc/c_cb_sem store order and &cbfunc arg setup differ, c_cb_sem store lands in jal delay slot on the error path | attempts=1 */
typedef struct
{
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
} sceCdRMode;

extern u32 _sceCd_ee_read_mode;
extern s32 _sceCd_ncmdsdata[];
extern char _sceCd_cd_ncmd[];
extern s32 _sceCd_rd_intr_data[];
extern s32 _sceCd_Read_cur_pos[];
extern s32 _sceCd_ncmd_semid;
extern s32 _sceCd_c_cb_sem;
extern s32 sceCdCbfunc_num;
extern s32 SCE_CD_debug;
extern char D_40049A48[];
extern void _sceCd_cd_callback(void *);
s32 sceCdNcmdDiskReady(void);
s32 _sceCd_ncmd_prechk(s32 arg);

s32 sceCdReadIOPm(u32 lsn, u32 sectors, void *buf, sceCdRMode *mode)
{
    u8 *cmd = (u8 *)_sceCd_ncmdsdata;

    if ((_sceCd_ee_read_mode & 1) == 0)
    {
        if (sceCdNcmdDiskReady() == 6)
        {
            return 0;
        }
    }
    if (_sceCd_ncmd_prechk(5) == 0)
    {
        return 0;
    }
    ((s32 *)cmd)[0] = lsn;
    ((s32 *)cmd)[1] = sectors;
    ((s32 *)cmd)[2] = (s32)buf;
    cmd[0xC] = mode->trycount;
    cmd[0xD] = mode->spindlctrl;
    cmd[0xE] = mode->datapattern;
    ((s32 *)cmd)[4] = (s32)_sceCd_rd_intr_data;
    ((s32 *)cmd)[5] = (s32)_sceCd_Read_cur_pos;
    sceSifWriteBackDCache(cmd, 0x18);
    sceCdCbfunc_num = 1;
    _sceCd_c_cb_sem = 1;
    if (sceSifCallRpc((sceSifClientData *)_sceCd_cd_ncmd, 0xD, 1, cmd, 0x18, 0, 0, _sceCd_cd_callback, &sceCdCbfunc_num) < 0)
    {
        sceCdCbfunc_num = 0;
        _sceCd_c_cb_sem = 0;
        SignalSema(_sceCd_ncmd_semid);
        return 0;
    }
    if (SCE_CD_debug > 0)
    {
        scePrintf(D_40049A48);
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/sceCdReadIOPm", sceCdReadIOPm);
