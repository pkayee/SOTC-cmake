#include "common.h"

/* NEARMISS-STUB sceVif1PkAlign */
#if 0 /* NEARMISS 70.48% cat=branch-layout sub=- | do-while loop shape and (pEnd+1)+mask add order differ; gcc reassociates to (mask+1)+pEnd, loop test layout differs, regalloc differs | attempts=1 */
void sceVif1PkAlign(sceVif1Packet *pPacket, u_int bit, u_int pos)
{
    u_int *pCurrent;
    u_int *pEnd;
    u_int mask;

    bit = (bit + 2) & 0x1F;
    mask = 0xFFFFFFFF >> (32 - bit);
    pCurrent = pPacket->pCurrent;
    pEnd = (u_int *)(((u_int)pCurrent & ~mask) + (pos << 2));
    if ((u_int)pEnd < (u_int)pCurrent)
    {
        pEnd = (u_int *)((u_int)pEnd + 1 + mask);
    }
    if (pCurrent < pEnd)
    {
        do
        {
            *pCurrent = 0;
            pCurrent++;
            pPacket->pCurrent = pCurrent;
        } while (pCurrent < pEnd);
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk044", sceVif1PkAlign);
