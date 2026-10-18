#include "common.h"
#include "sdk/ee/libvifpk.h"

void sceVif1PkEnd(sceVif1Packet *pPacket, u_int flag)
{
    u_int *pCurrent;

    pPacket->pDmaTag = sceVif1PkTerminate(pPacket);
    pCurrent = pPacket->pCurrent;
    *pCurrent = flag | 0x70000000;
    pCurrent++;
    pPacket->pVifCode = NULL;
    pPacket->pCurrent = pCurrent + 1;
    *pCurrent = 0;
}
