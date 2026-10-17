#include "common.h"

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

float __kernel_sinf(float x, float y, s32 iy);
float __kernel_cosf(float x, float y);
s32 __ieee754_rem_pio2f(float x, float *y);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/cosf", cosf);
float cosf(float x)
{
    float y[2];
    float z = 0.0f;
    s32 n;
    s32 ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8)
    {
        return __kernel_cosf(x, z);
    }
    else
    {
        n = __ieee754_rem_pio2f(x, y);
        switch (n & 3)
        {
        case 0:
            return __kernel_cosf(y[0], y[1]);
        case 1:
            return -__kernel_sinf(y[0], y[1], 1);
        case 2:
            return -__kernel_cosf(y[0], y[1]);
        default:
            return __kernel_sinf(y[0], y[1], 1);
        }
    }
}
