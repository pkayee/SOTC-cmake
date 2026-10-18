#include "common.h"

/* NEARMISS-STUB sceVif1PkOpenDirectCode */
#if 0 /* NEARMISS 97.5% cat=regalloc sub=- | target keeps pCode in a1 and alt/code in v0/a0; ours assigns v1/a0/v0 (movn shape matches) | attempts=1 */
void sceVif1PkOpenDirectCode(sceVif1Packet *pPacket, int stall)
{
    u_int *pCode;
    u_int code;
    u_int alt;

    sceVif1PkAlign(pPacket, 2, 3);
    pCode = pPacket->pCurrent;
    alt = 0xD0000000;
    code = 0x50000000;
    pPacket->pCurrent = pCode + 1;
    pPacket->pVifCode = pCode;
    if (stall)
    {
        code = alt;
    }
    *pCode = code;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/vifpk039", sceVif1PkOpenDirectCode);
