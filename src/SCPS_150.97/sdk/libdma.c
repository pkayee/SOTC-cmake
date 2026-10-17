#include "common.h"
#include "sdk/ee/libdma.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", WaitDma);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", WatchDma);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", CheckAddress);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", memclr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaGetChan);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaReset);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPutEnv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaGetEnv);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPutStallAddr);
void *sceDmaPutStallAddr(void *addr)
{
    void *ret;
    volatile void **stall = (volatile void **)0x1000E060;

    ret = *stall;
    *stall = addr;
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSend);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSendN);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSendI);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecvN);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRecvI);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaSync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaWatch);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaPause);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdma", sceDmaRestart);
int sceDmaRestart(sceDmaChan *d, u_int chcr)
{
    u_int old;

    old = *(volatile u_int *)d;
    *(volatile u_int *)d = chcr;
    return (old >> 8) & 1;
}
