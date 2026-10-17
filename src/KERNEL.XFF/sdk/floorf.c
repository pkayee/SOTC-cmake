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

static const float huge = 1.0e30;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/floorf", floorf);
float floorf(float x)
{
    s32 i0;
    s32 i;
    u32 ix;
    s32 j0;

    GET_FLOAT_WORD(i0, x);
    ix = i0 & 0x7fffffff;
    j0 = (s32)(ix >> 23) - 0x7f;
    if (j0 < 23)
    {
        if (j0 < 0)
        {
            if (huge + x > 0.0f)
            {
                if (i0 >= 0)
                {
                    i0 = 0;
                }
                else if (ix > 0x7fffff)
                {
                    i0 = 0xbf800000;
                }
            }
        }
        else
        {
            i = 0x007fffff >> j0;
            if ((i0 & i) == 0)
            {
                return x;
            }
            if (huge + x > 0.0f)
            {
                if (i0 < 0)
                {
                    i0 += 0x00800000 >> j0;
                }
                i0 &= ~i;
            }
        }
    }
    else
    {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
