#include "common.h"
#include "sdk/ee/libgraph.h"

u_long GsGetIMR(void);
u_long GsPutIMR(u_long imr);

u_long sceGsPutIMR(u_long imr)
{
    u_long old;

    old = GsGetIMR();
    GsPutIMR(imr);
    return old;
}
