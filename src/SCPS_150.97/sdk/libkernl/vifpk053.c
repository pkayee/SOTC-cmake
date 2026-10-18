#include "common.h"
#include "sdk/ee/libvifpk.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk053", sceVif1PkAddGsData);
void sceVif1PkAddGsData(sceVif1Packet *pPacket, u_long data)
{
    s64 val;
    s32 lo;
    s32 hi;
    u_int *pCur;
    u_int *pNext;

    val = (s64)data;
    lo = (s32)val;
    hi = (s32)(val >> 32);
    pCur = pPacket->pCurrent;
    pCur[0] = lo;
    pCur++;
    pNext = pCur + 1;
    pCur[0] = hi;
    pPacket->pCurrent = pNext;
}
