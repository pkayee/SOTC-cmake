#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__kernel_sinf", __kernel_sinf);

typedef union
{
    float value;
    u32 word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i, d)            \
    do                                  \
    {                                   \
        ieee_float_shape_type gf_u;     \
        gf_u.value = (d);               \
        (i) = gf_u.word;                \
    } while (0)

float __kernel_sinf(float x, float y, s32 iy)
{
    float z, r, v;
    s32 ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000)
    {
        if (((s32)x) == 0)
        {
            return x;
        }
    }
    z = x * x;
    v = z * x;
    r = 8.333334e-03f + z * (-1.98412702e-04f + z * (2.7557313e-06f + z * (-2.505076e-08f + z * 1.5896909e-10f)));
    if (iy == 0)
    {
        return x + v * (-1.6666666e-01f + z * r);
    }
    else
    {
        return x - ((z * (0.5f * y - v * r) - y) - v * -1.6666666e-01f);
    }
}
