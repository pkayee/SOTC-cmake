#include "common.h"
#include "sdk/ee/libgraph.h"

u_long iGsGetIMR(void);
u_long iGsPutIMR(u_long imr);

u_long isceGsPutIMR(u_long imr)
{
    u_long old;

    old = iGsGetIMR();
    iGsPutIMR(imr);
    return old;
}
