#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk042", sceVif1PkCloseGifTag);
void sceVif1PkCloseGifTag(sceVif1Packet *pPacket)
{
    u_long *pGifTag;
    u_int *pCurrent;
    u_int *pFill;
    u_long tag;
    u_int flg;
    u_int nreg;
    u_int nloop;
    s32 n;

    pGifTag = pPacket->pGifTag;
    pCurrent = pPacket->pCurrent;
    tag = *pGifTag;
    n = ((s32)((u_int)pCurrent - (u_int)pGifTag)) >> 3;
    nloop = n - 2;
    flg = (u_int)(tag >> 58) & 3;
    if (flg != 1)
    {
        nloop = nloop >> 1;
    }
    if (flg != 2)
    {
        nreg = (u_int)(tag >> 60);
        if (nreg == 0)
        {
            nreg = 16;
        }
        nloop = (nloop + nreg - 1) / nreg;
    }
    pPacket->pGifTag = 0;
    *pGifTag = tag + nloop;
    pFill = pCurrent;
    if ((u_int)pFill & 0xC)
    {
        do
        {
            *pFill = 0;
            pFill++;
        } while ((u_int)pFill & 0xC);
    }
    pPacket->pCurrent = pFill;
}
