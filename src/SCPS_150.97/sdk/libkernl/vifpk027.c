#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk027", sceVif1PkTerminate);
u_long128 *sceVif1PkTerminate(sceVif1Packet *pPacket)
{
    u_int *pCurrent;
    u_long128 *pDmaTag;
    s32 n;

    pCurrent = pPacket->pCurrent;
    pDmaTag = pPacket->pDmaTag;
    if (((u_int)pCurrent & 0xC) != 0)
    {
        do
        {
            *pCurrent = 0;
            pCurrent++;
        } while (((u_int)pCurrent & 0xC) != 0);
    }

    if (pDmaTag != NULL)
    {
        n = ((s32)((u_int)pCurrent - (u_int)pDmaTag)) >> 4;
        n = n - 1;
        *(u_int *)pDmaTag += n;
    }

    pPacket->pCurrent = pCurrent;
    pPacket->pDmaTag = NULL;
    return (u_long128 *)pCurrent;
}
