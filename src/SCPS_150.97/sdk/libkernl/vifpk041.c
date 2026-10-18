#include "common.h"

/* NEARMISS-STUB sceVif1PkOpenGifTag */
#if 0 /* NEARMISS 65.67% cat=sched sub=- | target stores pGifTag (0x14) last in jr delay slot; gcc hoists the pGifTag store before sq and the pCurrent store into the delay slot | attempts=1 */
void sceVif1PkOpenGifTag(sceVif1Packet *pPacket, u_long128 gifTag)
{
    u_int *pCurrent;

    pCurrent = pPacket->pCurrent;
    *(u_long128 *)pCurrent = gifTag;
    pPacket->pCurrent = pCurrent + 4;
    pPacket->pGifTag = (u_long *)pCurrent;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk041", sceVif1PkOpenGifTag);
