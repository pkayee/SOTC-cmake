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

float __ieee754_sqrtf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_acosf", __ieee754_acosf);
float __ieee754_acosf(float x)
{
    float z;
    float p;
    float q;
    float r;
    float w;
    float s;
    float c;
    float df;
    s32 hx;
    s32 ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000)
    {
        if (hx > 0)
        {
            return 0.0f;
        }
        return 3.14159253f;
    }
    if (ix > 0x3f800000)
    {
        return (x - x) / (x - x);
    }
    if (ix <= 0x3effffff)
    {
        if (ix <= 0x23000000)
        {
            return 1.57079627f;
        }
        z = x * x;
        p = z * (z * (z * (z * (z * (z * 3.47933095e-05f + 7.91535022e-04f) + -0.0400555361f) + 0.201212527f) + -0.325565788f) + 0.166666658f);
        q = 1.0f + z * (z * (z * (z * 0.0770381473f + -0.688283927f) + 2.02094557f) + -2.40339472f);
        r = p / q;
        return 1.57079627f - (x - (7.54978949e-08f - x * r));
    }
    else if (hx < 0)
    {
        z = (1.0f + x) * 0.5f;
        p = z * (z * (z * (z * (z * (z * 3.47933095e-05f + 7.91535022e-04f) + -0.0400555361f) + 0.201212527f) + -0.325565788f) + 0.166666658f);
        q = 1.0f + z * (z * (z * (z * 0.0770381473f + -0.688283927f) + 2.02094557f) + -2.40339472f);
        s = __ieee754_sqrtf(z);
        r = p / q;
        w = r * s - 7.54978949e-08f;
        return 3.14159253f - 2.0f * (s + w);
    }
    else
    {
        z = (1.0f - x) * 0.5f;
        s = __ieee754_sqrtf(z);
        df = s;
        GET_FLOAT_WORD(ix, df);
        ix &= 0xfffff000;
        SET_FLOAT_WORD(df, ix);
        c = (z - df * df) / (s + df);
        p = z * (z * (z * (z * (z * (z * 3.47933095e-05f + 7.91535022e-04f) + -0.0400555361f) + 0.201212527f) + -0.325565788f) + 0.166666658f);
        q = 1.0f + z * (z * (z * (z * 0.0770381473f + -0.688283927f) + 2.02094557f) + -2.40339472f);
        r = p / q;
        w = r * s + c;
        return 2.0f * (df + w);
    }
}
