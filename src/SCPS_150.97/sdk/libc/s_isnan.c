#include "common.h"

/* NEARMISS-STUB isnan */
#if 0 /* NEARMISS 72.6% cat=cse-hoist sub=- | lui constant hoisting and lx/hx register choice | attempts=1 */
#include "common.h"

typedef union
{
    double value;
    struct
    {
        s32 lsw;
        s32 msw;
    } parts;
} IeeeDoubleShape;

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/s_isnan", isnan);
int isnan(double x)
{
    IeeeDoubleShape u;
    s32 hx, lx;

    u.value = x;
    lx = u.parts.lsw;
    hx = u.parts.msw;
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    return (int)((u32)(0x7ff00000 - hx) >> 31);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/s_isnan", isnan);
