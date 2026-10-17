#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

extern sceGsGParam D_00133A70;

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph001", sceGsResetGraph);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph001", sceGsGetGParam);
sceGsGParam *sceGsGetGParam(void)
{
    return &D_00133A70;
}
