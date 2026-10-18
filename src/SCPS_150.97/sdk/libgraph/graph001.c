#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

extern sceGsGParam D_00133A70;

/* NEARMISS-STUB sceGsResetGraph */
#if 0 /* NEARMISS 93.0% cat=call-abi sub=- | mode-5 case: gcc emits jal SetGsCrt + epilogue instead of tail j (mode-0 case tail-calls fine); VSC stores order fixed | attempts=1 */
void sceGsResetGraph(short mode, short inter, short omode, short ffmode)
{
    sceGsGParam *gp;

    switch (mode)
    {
    case 0:
        gp = sceGsGetGParam();
        *(u_long *)0x12001000 = 0x200;
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        gp->sceGsVersion = (*(u_long *)0x12001000 >> 16) & 0xFF;
        GsPutIMR(0xFF00);
        gp->sceGsFFMode = ffmode != 0;
        if (gp->sceGsVSCfunc != 0)
        {
            DisableIntc(2);
            RemoveIntcHandler(2, gp->sceGsVSCid);
            gp->sceGsVSCfunc = 0;
            gp->sceGsVSCid = 0;
        }
        SetGsCrt(inter & 1, omode & 0xFF, ffmode & 1);
        return;
    case 1:
        *(u_long *)0x12001000 = 0x100;
        return;
    case 5:
        gp = sceGsGetGParam();
        gp->sceGsFFMode = ffmode != 0;
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        gp->sceGsVersion = (*(u_long *)0x12001000 >> 16) & 0xFF;
        SetGsCrt(inter & 1, omode & 0xFF, ffmode & 1);
        return;
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph001", sceGsResetGraph);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph001", sceGsGetGParam);
sceGsGParam *sceGsGetGParam(void)
{
    return &D_00133A70;
}
