#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

void sceGsPutDispEnv(sceGsDispEnv *disp)
{
    sceGsGParam *gp;

    gp = sceGsGetGParam();
    if (gp->sceGsVersion == 1)
    {
        *(volatile u_long *)0x12000000 = *(u_long *)&disp->pmode;
        *(volatile u_long *)0x12000070 = *(u_long *)&disp->dispfb;
        *(volatile u_long *)0x12000080 = *(u_long *)&disp->display;
        *(volatile u_long *)0x120000C0 = *(u_long *)&disp->bgcolor;
    }
    else
    {
        *(volatile u_long *)0x12000000 = *(u_long *)&disp->pmode;
        *(volatile u_long *)0x12000020 = *(u_long *)&disp->smode2;
        *(volatile u_long *)0x12000090 = *(u_long *)&disp->dispfb;
        *(volatile u_long *)0x120000A0 = *(u_long *)&disp->display;
        *(volatile u_long *)0x120000E0 = *(u_long *)&disp->bgcolor;
    }
}
