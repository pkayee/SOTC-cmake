#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

short sceGszbufaddr(short psm, short width, short height)
{
    sceGsGParam *gp;
    int w;
    int h;

    gp = sceGsGetGParam();
    w = (width + 63) / 64;
    if (psm & 2)
    {
        h = (height + 63) / 64;
    }
    else
    {
        h = (height + 31) / 32;
    }
    if (gp->sceGsInterMode == SCE_GS_INTERLACE && gp->sceGsFFMode == SCE_GS_FIELD)
    {
        return w * h;
    }
    return w * h * 2;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph005", sceGsSetDefClear);
