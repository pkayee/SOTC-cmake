#include "common.h"
#include "sdk/ee/libvifpk.h"

void sceVif1PkAlign(sceVif1Packet *pPacket, u_int bit, u_int pos)
{
    u_int mask;
    u_int end;

    bit = (bit + 2) & 0x1F;
    mask = 0xFFFFFFFF >> (32 - bit);
    end = ((u_int)pPacket->pCurrent & ~mask) + pos * 4;
    if (end < (u_int)pPacket->pCurrent)
    {
        end += mask + 1;
    }
    while ((u_int)pPacket->pCurrent < end)
    {
        *pPacket->pCurrent++ = 0;
    }
}
