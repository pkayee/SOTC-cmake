#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

/* NEARMISS-STUB sceGsSetDefAlphaEnv */
#if 0 /* NEARMISS 72.7% cat=no-c-form sub=- | sync instruction after the stores has no C form (scores as delete); rest of body is the 2.9 store order | attempts=1 */
int sceGsSetDefAlphaEnv(sceGsAlphaEnv *ap, short pabe)
{
    *(u_long *)&ap->alpha1 = 0x44;
    ap->alpha1addr = 0x42;
    *(u_long *)&ap->pabe = pabe;
    ap->pabeaddr = 0x49;
    *(u_long *)&ap->texa = 0x80FF;
    ap->texaaddr = 0x3B;
    *(u_long *)&ap->fba1 = 0;
    ap->fba1addr = 0x4A;
    return 4;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph014", sceGsSetDefAlphaEnv);
