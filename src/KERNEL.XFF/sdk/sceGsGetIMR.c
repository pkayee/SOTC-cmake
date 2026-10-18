#include "common.h"
#include "sdk/ee/libgraph.h"

u_long GsGetIMR(void);

u_long sceGsGetIMR(void)
{
    return GsGetIMR();
}
