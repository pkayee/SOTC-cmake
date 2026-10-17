#include "common.h"

extern s32 D_0014B4D8[];
extern s32 D_0014B4D4;
extern s32 D_00133A48;

unsigned int _sceSifSendCmd(unsigned int, int, void *, int, void *, void *, int);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifGetSreg);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSetSreg);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifGetDataTable);

void *sceSifGetDataTable(void)
{
    return D_0014B4D8;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifInitCmd);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifExitCmd);

void sceSifExitCmd(void)
{
    DisableDmac(5);
    RemoveDmacHandler(5, D_0014B4D4);
    D_00133A48 = 0;
}

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

/* NEARMISS-STUB _sceSifSendCmd */
#if 0 /* NEARMISS 99.45% cat=sched sub=- | andi v0 vs v1 on mode&4; sdd[0].addr store order | attempts=1 */
unsigned int _sceSifSendCmd(unsigned int fcode, int mode, void *pkt, int psize, void *dest, void *ddata, int dsize)
{
    sceSifDmaData sdd[2];
    u32 w;
    int n;

    if ((u32)(psize - 16) >= 0x61)
    {
        return 0;
    }

    n = 0;
    if (dsize > 0)
    {
        w = ((u8 *)pkt)[0] | (dsize << 8);
        ((u32 *)pkt)[1] = (u32)ddata;
        n = 1;
        sdd[0].data = (u32)dest;
        ((u32 *)pkt)[0] = w;
        sdd[0].addr = (u32)ddata;
        sdd[0].size = dsize;
        sdd[0].mode = 0;
        if (mode & 0x4)
        {
            sceSifWriteBackDCache(dest, dsize);
        }
    }
    else
    {
        w = ((u8 *)pkt)[0];
        ((u32 *)pkt)[1] = 0;
        ((u32 *)pkt)[0] = w;
    }
    sdd[n].data = (u32)pkt;
    sdd[n].addr = (u32)D_0014B4E0;
    sdd[n].size = psize;
    ((u32 *)pkt)[2] = fcode;
    ((u8 *)pkt)[0] = psize;
    sdd[n].mode = 0x44;
    sceSifWriteBackDCache(pkt, psize);
    n++;
    if (mode & 0x1)
    {
        return isceSifSetDma(sdd, n);
    }
    return sceSifSetDma(sdd, n);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", _sceSifSendCmd);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifSendCmd);

unsigned int sceSifSendCmd(unsigned int fcode, void *data, int size, void *dest, void *ddata, int dsize)
{
    return _sceSifSendCmd(fcode, 0, data, size, dest, ddata, dsize);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", isceSifSendCmd);

unsigned int isceSifSendCmd(unsigned int fcode, void *data, int size, void *dest, void *ddata, int dsize)
{
    return _sceSifSendCmd(fcode, 1, data, size, dest, ddata, dsize);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", _sceSifCmdIntrHdlr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", sceSifWriteBackDCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifcmd", func_00113174);
