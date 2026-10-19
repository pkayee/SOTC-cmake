#include "common.h"
#include "sdk/ee/libvifpk.h"

void sceVif1PkOpenGifTag(sceVif1Packet *pPacket, u_long128 gifTag)
{
    pPacket->pGifTag = (u_long *)pPacket->pCurrent;
    *(u_long128 *)pPacket->pCurrent = gifTag;
    pPacket->pCurrent += 4;
}
