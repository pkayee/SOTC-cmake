#include "common.h"

/* newlib libm/common/fdlibm.h (little-endian) */
typedef union
{
    double value;
    struct
    {
        u32 lsw;
        u32 msw;
    } parts;
} ieee_double_shape_type;

#define EXTRACT_WORDS(ix0, ix1, d) \
    do \
    { \
        ieee_double_shape_type ew_u; \
        ew_u.value = (d); \
        (ix0) = ew_u.parts.msw; \
        (ix1) = ew_u.parts.lsw; \
    } while (0)

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/s_isnan", isnan);
int isnan(double x)
{
    s32 hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (int)(((u32)(hx)) >> 31);
}
