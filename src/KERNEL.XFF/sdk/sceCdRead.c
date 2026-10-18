#include "common.h"

/* NEARMISS-STUB sceCdRead */
#if 0 /* NEARMISS 87.0% cat=regalloc sub=- | 2.9 regalloc: cmd/mode/ee-hi land in s0/s1/s6 (expected s2/s0/s5, frame 0x80 vs 0x90); size block uses bne ladder not slti form; tail sceCdCbfunc store and stac | attempts=1 */
typedef struct
{
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
} sceCdRMode;

extern u32 _sceCd_ee_read_mode;
extern s32 _sceCd_ncmdsdata[];
extern s32 _sceCd_Read_cur_pos;
extern s32 _sceCd_rd_intr_data[];
extern char _sceCd_cd_ncmd[];
extern s32 _sceCd_ncmd_semid;
extern s32 _sceCd_c_cb_sem;
extern s32 sceCdCbfunc_num;
extern s32 SCE_CD_debug;
extern char D_40049A20[];
extern char D_40049A38[];
void _sceCd_cd_read_intr(void *);
s32 sceCdNcmdDiskReady(void);
s32 _sceCd_ncmd_prechk(s32 arg);

s32 sceCdRead(u32 lsn, u32 sectors, void *buf, sceCdRMode *mode)
{
    u8 *cmd = (u8 *)_sceCd_ncmdsdata;
    s32 size;

    if ((_sceCd_ee_read_mode & 1) == 0)
    {
        if (sceCdNcmdDiskReady() == 6)
        {
            return 0;
        }
    }
    if (_sceCd_ncmd_prechk(4) == 0)
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
    ((s32 *)cmd)[5] = (s32)&_sceCd_Read_cur_pos;
    switch (mode->datapattern)
    {
    case 1:
        size = sectors * 0x918;
        break;
    case 2:
        size = sectors * 0x924;
        break;
    default:
        size = sectors << 11;
        break;
    }
    _sceCd_Read_cur_pos = 0;
    if ((_sceCd_ee_read_mode & 2) == 0)
    {
        sceSifWriteBackDCache(buf, size);
    }
    sceSifWriteBackDCache(_sceCd_rd_intr_data, 0x90);
    sceSifWriteBackDCache(cmd, 0x18);
    sceSifWriteBackDCache(&_sceCd_Read_cur_pos, 4);
    if (SCE_CD_debug > 0)
    {
        scePrintf(D_40049A20);
    }
    sceCdCbfunc_num = 1;
    _sceCd_c_cb_sem = 1;
    if (sceSifCallRpc((sceSifClientData *)_sceCd_cd_ncmd, 1, 1, cmd, 0x18, 0, 0, _sceCd_cd_read_intr, _sceCd_rd_intr_data) < 0)
    {
        sceCdCbfunc_num = 0;
        _sceCd_c_cb_sem = 0;
        SignalSema(_sceCd_ncmd_semid);
        return 0;
    }
    if (SCE_CD_debug > 0)
    {
        scePrintf(D_40049A38);
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/sceCdRead", sceCdRead);
