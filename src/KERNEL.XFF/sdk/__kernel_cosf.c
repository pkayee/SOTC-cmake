#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__kernel_cosf", __kernel_cosf);

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

#define SET_FLOAT_WORD(d, i)            \
    do                                  \
    {                                   \
        ieee_float_shape_type sf_u;     \
        sf_u.word = (i);                \
        (d) = sf_u.value;               \
    } while (0)

float __kernel_cosf(float x, float y)
{
    float a, hz, z, r, qx;
    s32 ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000)
    {
        if (((s32)x) == 0)
        {
            return 1.0000000000e+00f;
        }
    }
    z = x * x;
    r = z * (4.166666459981e-02f + z * (-1.388888819994e-03f + z * (2.48015858233e-05f + z * (-2.75573114550e-07f + z * (2.087572136048e-09f + z * -1.13596475976e-11f)))));
    if (ix <= 0x3e999999)
    {
        return 1.0000000000e+00f - (0.5f * z - (z * r - x * y));
    }
    else
    {
        if (ix > 0x3f480000)
        {
            qx = 0.28125f;
        }
        else
        {
            SET_FLOAT_WORD(qx, ix - 0x01000000);
        }
        hz = 0.5f * z - qx;
        a = 1.0000000000e+00f - qx;
        return a - (hz - (z * r - x * y));
    }
}
