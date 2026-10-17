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

float copysignf(float x, float y);

static const float huge = 1.0e30;
static const float tiny = 1.0e-30;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/scalbnf", scalbnf);
float scalbnf(float x, s32 n)
{
    s32 k;
    s32 hx;
    u32 ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    k = (s32)(ix >> 23);
    if (ix <= 0x7fffff)
    {
        return x;
    }
    k = k + n;
    if (k > 0xff)
    {
        return huge * copysignf(huge, x);
    }
    if (k > 0)
    {
        SET_FLOAT_WORD(x, (hx & 0x807fffff) | (k << 23));
        return x;
    }
    if (n > 50000)
    {
        return huge * copysignf(huge, x);
    }
    return tiny * copysignf(tiny, x);
}
