#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk026", sceVif1PkReset);
void sceVif1PkReset(sceVif1Packet *pPacket)
{
    pPacket->pCurrent = (u_int *)pPacket->pBase;
    pPacket->pDmaTag = NULL;
}
