#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph014", sceGsSetDefAlphaEnv);
int sceGsSetDefAlphaEnv(sceGsAlphaEnv *ap, short pabe)
{
    long *p;

    p = (long *)ap;
    p[1] = 0x42;
    p[0] = 0x44;
    p[3] = 0x49;
    p[2] = pabe;
    p[5] = 0x3B;
    p[4] = 0x810000807FL;
    p[7] = 0x4A;
    p[6] = 0;
    asm volatile("sync");
    return 4;
}
