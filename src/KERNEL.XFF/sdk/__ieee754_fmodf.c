#include "common.h"

extern float D_40049528[];

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_fmodf", __ieee754_fmodf);
float __ieee754_fmodf(float x, float y)
{
    s32 n;
    s32 hx;
    s32 hy;
    s32 hz;
    s32 ix;
    s32 iy;
    s32 sx;
    s32 i;

    GET_FLOAT_WORD(hx, x);
    GET_FLOAT_WORD(hy, y);
    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;

    if (hy <= 0x007fffff)
    {
        return (x * y) / (x * y);
    }
    if (hx < hy)
    {
        return x;
    }
    if (hx == hy)
    {
        return D_40049528[(u32)sx >> 31];
    }

    /* determine ix = ilogb(x) */
    if (FLT_UWORD_IS_SUBNORMAL(hx))
    {
        for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
        {
            ix -= 1;
        }
    }
    else
    {
        ix = (hx >> 23) - 127;
    }

    /* determine iy = ilogb(y) */
    if (FLT_UWORD_IS_SUBNORMAL(hy))
    {
        for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
        {
            iy -= 1;
        }
    }
    else
    {
        iy = (hy >> 23) - 127;
    }
    if (ix >= -126)
    {
        hx = 0x00800000 | (0x007fffff & hx);
    }
    else
    {
        n = -126 - ix;
        hx = hx << n;
    }

    if (iy >= -126)
    {
        hy = 0x00800000 | (0x007fffff & hy);
    }
    else
    {
        n = -126 - iy;
        hy = hy << n;
    }

    n = ix - iy;
    while (n--)
    {
        hz = hx - hy;
        if (hz < 0)
        {
            hx = hx + hx;
        }
        else
        {
            if (hz == 0)
            {
                return D_40049528[(u32)sx >> 31];
            }
            hx = hz + hz;
        }
    }
    hz = hx - hy;
    if (hz >= 0)
    {
        hx = hz;
    }

    if (hx == 0)
    {
        return D_40049528[(u32)sx >> 31];
    }
    while (hx < 0x00800000)
    {
        hx = hx + hx;
        iy -= 1;
    }
    if (iy >= -126)
    {
        hx = ((hx - 0x00800000) | ((iy + 127) << 23));
        SET_FLOAT_WORD(x, hx | sx);
    }
    else
    {
        n = -126 - iy;
        hx >>= n;
        SET_FLOAT_WORD(x, hx | sx);
    }
    return x;
}
