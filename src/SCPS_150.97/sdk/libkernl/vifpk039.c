#include "common.h"
#include "sdk/ee/libvifpk.h"

void sceVif1PkOpenDirectCode(sceVif1Packet *pPacket, int stall)
{
    sceVif1PkAlign(pPacket, 2, 3);
    pPacket->pVifCode = pPacket->pCurrent;
    *pPacket->pCurrent++ = stall ? 0xD0000000 : 0x50000000;
}
