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

#define SET_FLOAT_WORD(d, i)            \
    do                                  \
    {                                   \
        ieee_float_shape_type sf_u;     \
        sf_u.word = (i);                \
        (d) = sf_u.value;               \
    } while (0)

float atanf(float x);
float fabsf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_atan2f", __ieee754_atan2f);
float __ieee754_atan2f(float y, float x)
{
    float z;
    u32 zw;
    s32 hx;
    s32 hy;
    s32 ix;
    s32 iy;
    s32 k;
    s32 m;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    GET_FLOAT_WORD(hy, y);
    iy = hy & 0x7fffffff;
    if (hx == 0x3f800000)
    {
        return atanf(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
    if (iy <= 0x7fffff)
    {
        switch (m)
        {
            case 0:
            case 1:
                return y;
            case 2:
                return 3.1415926536f;
            case 3:
                return -3.1415926536f;
        }
    }
    if (ix <= 0x7fffff)
    {
        if (hy < 0)
        {
            return -1.5707963268f;
        }
        return 1.5707963268f;
    }
    k = (iy - ix) >> 23;
    if (k > 60)
    {
        z = 1.5707963268f;
    }
    else if (hx < 0 && k < -60)
    {
        z = 0.0f;
    }
    else
    {
        z = atanf(fabsf(y / x));
    }
    switch (m)
    {
        case 0:
            return z;
        case 1:
            GET_FLOAT_WORD(zw, z);
            SET_FLOAT_WORD(z, zw ^ 0x80000000);
            return z;
        case 2:
            return 3.1415926536f - (z - 1.5099579e-07f);
        default:
            return (z - 1.5099579e-07f) - 3.1415926536f;
    }
}
