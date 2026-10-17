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
float fabsf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_asinf", __ieee754_asinf);
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_asinf", __ieee754_asinf);
float __ieee754_asinf(float x)
{
    float t;
    float w;
    float p;
    float q;
    float c;
    float r;
    float s;
    s32 hx;
    s32 ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000)
    {
        return x * 1.5707962513e+00f + x * 7.54978942e-08f;
    }
    if (ix > 0x3f800000)
    {
        return (x - x) / (x - x);
    }
    if (ix < 0x3f000000)
    {
        if (ix < 0x32000000)
        {
            if (1.0e30f + x > 1.0f)
            {
                return x;
            }
        }
        else
        {
            t = x * x;
            p = t * (t * (t * (t * (t * (t * 3.47933095e-05f + 7.91535022e-04f) + -0.0400555361f) + 0.201212527f) + -0.325565788f) + 0.166666658f);
            q = 1.0f + t * (t * (t * (t * 0.0770381473f + -0.688283927f) + 2.02094557f) + -2.40339472f);
            w = p / q;
            return x + x * w;
        }
    }
    w = 1.0f - fabsf(x);
    t = w * 0.5f;
    p = t * (t * (t * (t * (t * (t * 3.47933095e-05f + 7.91535022e-04f) + -0.0400555361f) + 0.201212527f) + -0.325565788f) + 0.166666658f);
    q = 1.0f + t * (t * (t * (t * 0.0770381473f + -0.688283927f) + 2.02094557f) + -2.40339472f);
    s = __ieee754_sqrtf(t);
    if (ix > 0x3F799999)
    {
        w = p / q;
        t = 1.5707962513e+00f - (2.0f * (s + s * w) - 7.54978942e-08f);
    }
    else
    {
        w = s;
        GET_FLOAT_WORD(ix, w);
        SET_FLOAT_WORD(w, ix & 0xfffff000);
        c = (t - w * w) / (s + w);
        r = p / q;
        p = 2.0f * s * r - (7.54978942e-08f - 2.0f * c);
        q = 7.8539812565e-01f - 2.0f * w;
        t = 7.8539812565e-01f - (p - q);
    }
    if (hx > 0)
    {
        return t;
    }
    return -t;
}
