#include "common.h"

/* NEARMISS-STUB isinf */
#if 0 /* NEARMISS 71.1% cat=cse-hoist sub=- | lui 0x7ff0 hoist and lx register choice | attempts=1 */
#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sf_isinf", isinf);
int isinf(s64 x)
{
    s32 hx, lx;

    lx = (s32)x;
    hx = (s32)(x >> 32) & 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (int)((u32)(hx | (-hx)) >> 31);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sf_isinf", isinf);
