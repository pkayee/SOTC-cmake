#include "common.h"
#include "sdk/ee/libdma.h"
#include "sdk/ee/eekernel.h"

void WaitDma(sceDmaChan *d);
void WatchDma(sceDmaChan *d, void *addr, int timeout);
u_int CheckAddress(u_int addr);
extern sceDmaChan *D_00133AB0[];
extern s32 D_00138608[];
extern sceDmaEnv D_0014B700[];
void memclr(void *ptr, int size);

/* NEARMISS-STUB WaitDma */
#if 0 /* NEARMISS 99.29% cat=regalloc sub=- | count preload and string hoist differ, const folded | attempts=1 */
void WaitDma(sceDmaChan *d)
{
    int count;

    count = 0x1000000;
    while (*(volatile u_int *)d & 0x100) {
        count--;
        if (count < 0) {
            scePrintf("libdma: sync timeout\n");
            sceDmaPause(d);
        }
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", WaitDma);

/* NEARMISS-STUB WatchDma */
#if 0 /* NEARMISS 79.24% cat=branch-layout sub=- | loop shape: target if+do-while with string hoist | attempts=1 */
void WatchDma(sceDmaChan *d, void *addr, int timeout)
{
    int count;

    count = timeout ? timeout : 0x1000000;
    while ((u_int)d->madr < (u_int)addr) {
        count--;
        if (count < 0) {
            scePrintf("libdma: sync timeout\n");
            sceDmaPause(d);
        }
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", WatchDma);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", CheckAddress);
u_int CheckAddress(u_int addr)
{
    if ((addr >> 28) == 7) {
        addr &= 0xFFFFFFF;
        addr |= 0x80000000;
    }
    return addr;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", memclr);
void memclr(void *ptr, int size)
{
    u8 *p = ptr;
    int i = size - 1;

    if (size != 0) {
        do {
            *p++ = 0;
            i--;
        } while (i != -1);
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaGetChan);
sceDmaChan *sceDmaGetChan(int id)
{
    if ((u_int)id < 10) {
        return D_00133AB0[id];
    }
    return 0;
}

/* NEARMISS-STUB sceDmaReset */
#if 0 /* NEARMISS 97.09% cat=sched sub=- | extra sw+nop at D_STAT/memclr join; target store in jal delay slot | attempts=1 */
int sceDmaReset(int mode)
{
    sceDmaEnv env;
    int i;
    int dmae;

    dmae = *(volatile u_int *)0x1000E000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_00138608[i]) {
            sceDmaChan *ch = D_00133AB0[i];
            volatile u_int *w;
            w = (volatile u_int *)ch;
            w[0x80 / 4] = 0;
            w[0x00 / 4] = 0;
            w[0x30 / 4] = 0;
            w[0x10 / 4] = 0;
            w[0x50 / 4] = 0;
            w[0x40 / 4] = 0;
        }
    }
    *(volatile u_int *)0x1000E010 = 0xFF1F;
    *(volatile u_int *)0x1000E010 &= 0xFF1F0000;
    memclr(&env, 0x14);
    sceDmaPutEnv(&env);
    if (mode == 1) {
        *(volatile u_int *)0x1000E000 |= 1;
    }
    return dmae;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaReset);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPutEnv);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaGetEnv);
sceDmaEnv *sceDmaGetEnv(sceDmaEnv *env)
{
    *env = *D_0014B700;
    return env;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPutStallAddr);
void *sceDmaPutStallAddr(void *addr)
{
    void *ret;
    volatile void **stall = (volatile void **)0x1000E060;

    ret = *stall;
    *stall = addr;
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSend);
void sceDmaSend(sceDmaChan *d, void *tag)
{
    u_int addr;

    addr = CheckAddress((u_int)tag);
    WaitDma(d);
    if (d->tadr != (void *)-1) {
        d->tadr = (sceDmaTag *)addr;
    }
    d->qwc = 0;
    d->chcr.MOD = 1;
    d->chcr.DIR = 1;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSendN);
void sceDmaSendN(sceDmaChan *d, void *addr, int size)
{
    u_int madr;

    madr = CheckAddress((u_int)addr);
    WaitDma(d);
    if (d->madr != (void *)-1) {
        d->madr = (void *)madr;
    }
    d->qwc = size;
    d->chcr.MOD = 0;
    d->chcr.DIR = 1;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSendI);
void sceDmaSendI(sceDmaChan *d, void *addr, int size)
{
    u_int madr;

    madr = CheckAddress((u_int)addr);
    WaitDma(d);
    if (d->madr != (void *)-1) {
        d->madr = (void *)madr;
    }
    d->qwc = size;
    d->chcr.MOD = 2;
    d->chcr.DIR = 1;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecv);
void sceDmaRecv(sceDmaChan *d)
{
    WaitDma(d);
    d->qwc = 0;
    d->chcr.MOD = 1;
    d->chcr.DIR = 0;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecvN);
void sceDmaRecvN(sceDmaChan *d, void *addr, int size)
{
    u_int madr;

    madr = CheckAddress((u_int)addr);
    WaitDma(d);
    if (d->madr != (void *)-1) {
        d->madr = (void *)madr;
    }
    d->qwc = size;
    d->chcr.MOD = 0;
    d->chcr.DIR = 0;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecvI);
void sceDmaRecvI(sceDmaChan *d, void *addr, int size)
{
    u_int madr;

    madr = CheckAddress((u_int)addr);
    WaitDma(d);
    if (d->madr != (void *)-1) {
        d->madr = (void *)madr;
    }
    d->qwc = size;
    d->chcr.MOD = 2;
    d->chcr.DIR = 0;
    d->chcr.STR = 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSync);
int sceDmaSync(sceDmaChan *d, int mode, int timeout)
{
    if (mode == 1) {
        return (*(volatile u_int *)d >> 8) & 1;
    }
    WaitDma(d);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaWatch);
int sceDmaWatch(sceDmaChan *d, void *addr, int mode, int timeout)
{
    if (mode == 1) {
        return (u_int)d->madr < (u_int)addr;
    }
    WatchDma(d, addr, timeout);
    return 0;
}

/* NEARMISS-STUB sceDmaPause */
#if 0 /* NEARMISS 85.97% cat=regalloc sub=- | enabler in a2/D_CTRL in a1 vs swapped | attempts=1 */
u_int sceDmaPause(sceDmaChan *d)
{
    u_int old;
    u_int enabler;
    int intr;

    intr = DIntr();
    enabler = *(volatile u_int *)0x1000F520;
    if (!(enabler & 0x10000)) {
        *(volatile u_int *)0x1000F590 = enabler | 0x10000;
    }
    *(volatile u_int *)0x1000E000;
    old = *(u_int *)d;
    *(u_int *)d = old & 0xFFFFFEFF;
    *(volatile u_int *)0x1000F590 = enabler;
    if (intr) {
        EIntr();
    }
    return old;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPause);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRestart);
int sceDmaRestart(sceDmaChan *d, u_int chcr)
{
    u_int old;

    old = *(volatile u_int *)d;
    *(volatile u_int *)d = chcr;
    return (old >> 8) & 1;
}
