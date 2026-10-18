#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

/* NEARMISS-STUB sceGsPutDispEnv */
#if 0 /* NEARMISS 60.6% cat=volatile-alias sub=- | needs the banned qualifier: volatile stores force per-store lui at + sd off(at); plain/temp/base-ptr forms CSE the 0x12000000 lui and reorder loads (60.6/59.96/ | attempts=1 */
void sceGsPutDispEnv(sceGsDispEnv *disp)
{
    sceGsGParam *gp;

    gp = sceGsGetGParam();
    if (gp->sceGsVersion == 1)
    {
        *(u_long *)0x12000000 = *(u_long *)&disp->pmode;
        *(u_long *)0x12000070 = *(u_long *)&disp->dispfb;
        *(u_long *)0x12000080 = *(u_long *)&disp->display;
        *(u_long *)0x120000C0 = *(u_long *)&disp->bgcolor;
    }
    else
    {
        *(u_long *)0x12000000 = *(u_long *)&disp->pmode;
        *(u_long *)0x12000020 = *(u_long *)&disp->smode2;
        *(u_long *)0x12000090 = *(u_long *)&disp->dispfb;
        *(u_long *)0x120000A0 = *(u_long *)&disp->display;
        *(u_long *)0x120000E0 = *(u_long *)&disp->bgcolor;
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph004", sceGsPutDispEnv);
