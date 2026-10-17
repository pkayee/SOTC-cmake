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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/fabsf", fabsf);
float fabsf(float x)
{
    u32 ix;

    GET_FLOAT_WORD(ix, x);
    SET_FLOAT_WORD(x, ix & 0x7fffffff);
    return x;
}
