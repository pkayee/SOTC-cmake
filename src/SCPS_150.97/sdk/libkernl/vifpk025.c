#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk025", sceVif1PkInit);
void sceVif1PkInit(sceVif1Packet *pPacket, u_long128 *pBase)
{
    pPacket->pBase = pBase;
    pPacket->pCurrent = (u_int *)pBase;
    pPacket->pDmaTag = NULL;
}
