#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk040", sceVif1PkCloseDirectCode);
void sceVif1PkCloseDirectCode(sceVif1Packet *pPacket)
{
    u_int *pCode;
    s32 size;

    pCode = pPacket->pVifCode;
    size = (u_int)pPacket->pCurrent - 4;
    pPacket->pVifCode = 0;
    size = size - (u_int)pCode;
    *pCode += (u_int)(size >> 2) >> 2;
}
