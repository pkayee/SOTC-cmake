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

#define FLT_UWORD_IS_SUBNORMAL(x) 0

static const float one = 1.0, tiny = 1.0e-30;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_sqrtf", __ieee754_sqrtf);
float __ieee754_sqrtf(float x)
{
    float z;
    u32 r, hx;
    s32 ix, s, q, m, t, i;

    GET_FLOAT_WORD(ix, x);
    hx = ix & 0x7fffffff;

    /* take care of zero and -ves */
    if (hx < 0x00800000)
    {
        return x;
    }
    if (ix < 0)
    {
        return (x - x) / (x - x);
    }

    /* normalize x */
    m = (ix >> 23);
    if (FLT_UWORD_IS_SUBNORMAL(hx))
    {
        for (i = 0; (ix & 0x00800000) == 0; i++)
        {
            ix <<= 1;
        }
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffff) | 0x00800000;
    if (m & 1)
    {
        ix += ix;
    }
    m >>= 1;

    /* generate sqrt(x) bit by bit */
    ix += ix;
    q = s = 0;
    r = 0x01000000;

    while (r != 0)
    {
        t = s + r;
        if (t <= ix)
        {
            s = t + r;
            ix -= t;
            q += r;
        }
        ix += ix;
        r >>= 1;
    }

    /* use floating add to find out rounding direction */
    if (ix != 0)
    {
        z = one - tiny;
        if (z >= one)
        {
            z = one + tiny;
            if (z > one)
            {
                q += 2;
            }
            else
            {
                q += (q & 1);
            }
        }
    }
    ix = (q >> 1) + 0x3f000000;
    ix += (m << 23);
    SET_FLOAT_WORD(z, ix);
    return z;
}
