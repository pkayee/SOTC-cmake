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

float fabsf(float x);
extern s32 D_400495B8[];
extern s32 D_400498CC[];
s32 __kernel_rem_pio2f(float *x, float *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_rem_pio2f", __ieee754_rem_pio2f);
s32 __ieee754_rem_pio2f(float x, float *y)
{
    float z;
    float w;
    float r;
    float t;
    float fn;
    float tx[3];
    s32 e0;
    s32 i;
    s32 j;
    s32 nx;
    s32 n;
    s32 ix;
    s32 hx;
    u32 high;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fd8)
    {
        y[0] = x;
        y[1] = 0.0f;
        return 0;
    }
    if (ix <= 0x4016cbe3)
    {
        if (hx > 0)
        {
            z = x - 1.5707855225e+00f;
            if ((ix & 0xfffffff0) != 0x3fc90fd0)
            {
                y[0] = z - 1.0804333215e-05f;
                y[1] = (z - y[0]) - 1.0804333215e-05f;
            }
            else
            {
                z = z - 1.08042723e-05f;
                y[0] = z - 6.07710e-11f;
                y[1] = (z - y[0]) - 6.07710e-11f;
            }
            return 1;
        }
        z = x + 1.5707855225e+00f;
        if ((ix & 0xfffffff0) != 0x3fc90fd0)
        {
            y[0] = z + 1.0804333215e-05f;
            y[1] = (z - y[0]) + 1.0804333215e-05f;
        }
        else
        {
            z = z + 1.08042723e-05f;
            y[0] = z + 6.07710e-11f;
            y[1] = (z - y[0]) + 6.07710e-11f;
        }
        return -1;
    }
    if (ix <= 0x43490f80)
    {
        t = fabsf(x);
        n = (s32)(t * 6.3661981e-01f + 0.5f);
        fn = (float)n;
        r = t - fn * 1.5707855225e+00f;
        w = fn * 1.0804333215e-05f;
        if (n < 32 && (ix & 0xffffff00) != D_400498CC[n])
        {
            y[0] = r - w;
        }
        else
        {
            j = ix >> 23;
            y[0] = r - w;
            GET_FLOAT_WORD(high, y[0]);
            i = j - ((high >> 23) & 0xff);
            if (i > 8)
            {
                t = r;
                w = fn * 1.08042723e-05f;
                r = t - w;
                w = fn * 6.07710e-11f - ((t - r) - w);
                y[0] = r - w;
                GET_FLOAT_WORD(high, y[0]);
                i = j - ((high >> 23) & 0xff);
                if (i > 25)
                {
                    t = r;
                    w = fn * 6.0770944e-11f;
                    r = t - w;
                    w = fn * 6.1232336012e-17f - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0)
        {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        return n;
    }

    e0 = (ix >> 23) - 134;
    SET_FLOAT_WORD(z, ix - (e0 << 23));
    for (i = 0; i < 2; i++)
    {
        tx[i] = (float)((s32)z);
        z = (z - tx[i]) * 256.0f;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == 0.0f)
    {
        nx--;
    }
    n = __kernel_rem_pio2f(tx, y, e0, nx, 2, D_400495B8);
    if (hx < 0)
    {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
