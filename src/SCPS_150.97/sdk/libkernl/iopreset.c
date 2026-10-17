#include "common.h"
#include "common.h"
#include "sdk/ee/sif.h"
#include "sdk/ee/sifcmd.h"

extern s32 D_00147740[];

u32 sceSifGetReg(u32 n);
void sceSifSetReg(u32 n, u32 value);
void sceSifStopDma(void);
void sceSifExecNotifyHandler(s32 a, s32 b);
void sceSifWriteBackDCache(const void *p, s32 n);

/* NEARMISS-STUB sceSifResetIop */
#if 0 /* NEARMISS 82.9% cat=regalloc sub=- | jal delay-slot lui sched, pkt addiu reuse, regs off by one | attempts=1 */
s32 sceSifResetIop(const char *arg, u32 flag)
{
    sceSifCmdResetData *pkt;
    sceSifDmaData sdd;
    u32 sreg;
    s32 i;

    sceSifExecNotifyHandler(0, 0);
    sceSifExecNotifyHandler(1, 0);
    sceSifStopDma();
    sreg = sceSifGetReg(SIF_CMDI_SYSTEM);
    ((sceSifCmdResetData *)D_00147740)->flag = flag;
    i = 0;
    if (arg[0] != 0)
    {
        do
        {
            ((sceSifCmdResetData *)D_00147740)->arg[i] = arg[i];
            i++;
        } while (arg[i] != 0);
    }
    pkt = (sceSifCmdResetData *)D_00147740;
    pkt->chdr.daddr = 0;
    pkt->size = i;
    pkt->chdr.fcode = SIF_CMDC_RESET_CMD;
    pkt->chdr.dsize = 0;
    pkt->chdr.psize = 0x68;
    sdd.data = (u32)pkt;
    sdd.addr = sreg;
    sdd.size = 0x68;
    sdd.mode = 0x44;
    sceSifWriteBackDCache(pkt, 0x68);
    sceSifSetReg(4, 0x40000);
    if (sceSifSetDma(&sdd, 1) != 0)
    {
        sceSifSetReg(4, 0x10000);
        sceSifSetReg(4, 0x20000);
        sceSifSetReg(0x80000002, 0);
        sceSifSetReg(0x80000000, 0);
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopreset", sceSifResetIop);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopreset", sceSifIsAliveIop);
s32 sceSifIsAliveIop(void)
{
    u32 r = sceSifGetReg(4) & 0x10000;

    return r != 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopreset", sceSifSyncIop);
s32 sceSifSyncIop(void)
{
    if (sceSifGetReg(4) & 0x40000)
    {
        sceResetttyinit();
        sceSifExecNotifyHandler(1, 1);
        sceSifExecNotifyHandler(0, 1);
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB sceSifRebootIop */
#if 0 /* NEARMISS 73.0% cat=stack-frame sub=- | target frame 0x80 with s1=&D_001382A0, ours 0x70 | attempts=1 */
s32 sceSifRebootIop(const char *arg)
{
    char buf[80];
    const char *p;
    const char *q;
    char *d;

    q = D_001382A0;
    p = arg;
    while (*p != 0)
    {
        p++;
    }
    if ((p - (arg - 11)) >= 0x51)
    {
        scePrintf(D_001382B0, arg);
        return 0;
    }
    sceSifInitRpc(0);
    sceSifExitRpc();
    d = buf;
    while (*q != 0)
    {
        *d++ = *q;
        q++;
    }
    for (p = arg; *p != 0; p++)
    {
        *d++ = *p;
    }
    *d = 0;
    return sceSifResetIop(buf, 0);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopreset", sceSifRebootIop);
