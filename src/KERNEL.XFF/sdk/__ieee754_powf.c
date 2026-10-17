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
float scalbnf(float x, s32 n);
float nanf(const char *);

#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_IS_NAN(x) 0
#define FLT_UWORD_IS_INFINITE(x) 0
#define FLT_UWORD_IS_ZERO(x) ((x) < 0x00800000)
#define FLT_UWORD_IS_SUBNORMAL(x) 0
#define FLT_UWORD_EXP_MAX 0x43010000
#define FLT_UWORD_EXP_MIN 0x42fc0000

extern float D_40049530[]; /* bp */
extern float D_40049538[]; /* dp_h */
extern float D_40049540[]; /* dp_l */

extern float D_400495B4; /* huge*huge, folded by the compiler into .rodata */
#define zero ((float)0.0)
#define one ((float)1.0)
#define two ((float)2.0)
#define two24 ((float)16777216.0)
#define huge ((float)1.0e30)
#define tiny ((float)1.0e-30)
#define L1 ((float)6.0000002384e-01)
#define L2 ((float)4.2857143283e-01)
#define L3 ((float)3.3333334327e-01)
#define L4 ((float)2.7272811532e-01)
#define L5 ((float)2.3066075146e-01)
#define L6 ((float)2.0697501302e-01)
#define P1 ((float)1.6666667163e-01)
#define P2 ((float)-2.7777778450e-03)
#define P3 ((float)6.6137559770e-05)
#define P4 ((float)-1.6533901999e-06)
#define P5 ((float)4.1381369442e-08)
#define lg2 ((float)6.9314718246e-01)
#define lg2_h ((float)6.93145752e-01)
#define lg2_l ((float)1.42860654e-06)
#define ovt ((float)4.2995665694e-08)
#define cp ((float)9.6179670095e-01)
#define cp_h ((float)9.6179199219e-01)
#define cp_l ((float)4.7017383622e-06)
#define ivln2 ((float)1.4426950216e+00)
#define ivln2_h ((float)1.4426879883e+00)
#define ivln2_l ((float)7.0526075433e-06)

#define bp D_40049530
#define dp_h D_40049538
#define dp_l D_40049540

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/__ieee754_powf", __ieee754_powf);
float __ieee754_powf(float x, float y)
{
    float z, ax, z_h, z_l, p_h, p_l;
    float y1, t1, t2, r, s, t, u, v, w;
    s32 i, j, k, yisint, n;
    s32 hx, hy, ix, iy, is;

    GET_FLOAT_WORD(hx, x);
    GET_FLOAT_WORD(hy, y);
    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    /* y==zero: x**0 = 1 */
    if (FLT_UWORD_IS_ZERO(iy))
    {
        return one;
    }

    /* x|y==NaN return NaN unless x==1 then return 1 */
    if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy))
    {
        if (ix == 0x3f800000)
        {
            return one;
        }
        else
        {
            return nanf("");
        }
    }

    /* determine if y is an odd int when x < 0 */
    yisint = 0;
    if (hx < 0)
    {
        if (iy >= 0x4b800000)
        {
            yisint = 2;
        }
        else if (iy >= 0x3f800000)
        {
            k = (iy >> 23) - 0x7f;
            j = iy >> (23 - k);
            if ((j << (23 - k)) == iy)
            {
                yisint = 2 - (j & 1);
            }
        }
    }

    /* special value of y */
    if (FLT_UWORD_IS_INFINITE(iy))
    {
        if (ix == 0x3f800000)
        {
            return one;
        }
        else if (ix > 0x3f800000)
        {
            return (hy >= 0) ? y : zero;
        }
        else
        {
            return (hy < 0) ? -y : zero;
        }
    }
    if (iy == 0x3f800000)
    {
        if (hy < 0)
        {
            return one / x;
        }
        else
        {
            return x;
        }
    }
    if (hy == 0x40000000)
    {
        return x * x;
    }
    if (hy == 0x3f000000)
    {
        if (hx >= 0)
        {
            return __ieee754_sqrtf(x);
        }
    }

    ax = fabsf(x);
    /* special value of x */
    if (FLT_UWORD_IS_INFINITE(ix) || FLT_UWORD_IS_ZERO(ix) || ix == 0x3f800000)
    {
        z = ax;
        if (hy < 0)
        {
            z = one / z;
        }
        if (hx < 0)
        {
            if (((ix - 0x3f800000) | yisint) == 0)
            {
                z = (z - z) / (z - z);
            }
            else if (yisint == 1)
            {
                z = -z;
            }
        }
        return z;
    }

    /* (x<0)**(non-int) is NaN */
    if (((((u32)hx >> 31) - 1) | yisint) == 0)
    {
        return (x - x) / (x - x);
    }

    /* |y| is huge */
    if (iy > 0x4d000000)
    {
        if (ix < 0x3f7ffff8)
        {
            return (hy < 0) ? D_400495B4 : tiny * tiny;
        }
        if (ix > 0x3f800007)
        {
            return (hy > 0) ? D_400495B4 : tiny * tiny;
        }
        t = x - 1;
        w = (t * t) * ((float)0.5 - t * ((float)0.333333333333 - t * (float)0.25));
        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;
        t1 = u + v;
        GET_FLOAT_WORD(is, t1);
        SET_FLOAT_WORD(t1, is & 0xfffff000);
        t2 = v - (t1 - u);
    }
    else
    {
        float s2, s_h, s_l, t_h, t_l;

        n = 0;
        /* take care subnormal number */
        if (FLT_UWORD_IS_SUBNORMAL(ix))
        {
            ax *= two24;
            n -= 24;
            GET_FLOAT_WORD(ix, ax);
        }
        n += ((ix) >> 23) - 0x7f;
        j = ix & 0x007fffff;
        /* determine interval */
        ix = j | 0x3f800000;
        if (j <= 0x1cc471)
        {
            k = 0;
        }
        else if (j < 0x5db3d7)
        {
            k = 1;
        }
        else
        {
            k = 0;
            n += 1;
            ix -= 0x00800000;
        }
        SET_FLOAT_WORD(ax, ix);

        /* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
        u = ax - bp[k];
        v = one / (ax + bp[k]);
        s = u * v;
        s_h = s;
        GET_FLOAT_WORD(is, s_h);
        SET_FLOAT_WORD(s_h, is & 0xfffff000);
        /* t_h=ax+bp[k] High */
        SET_FLOAT_WORD(t_h, ((ix >> 1) | 0x20000000) + 0x0040000 + (k << 21));
        t_l = ax - (t_h - bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);
        /* compute log(ax) */
        s2 = s * s;
        r = s2 * s2 * (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + s2 * L6)))));
        r += s_l * (s_h + s);
        s2 = s_h * s_h;
        t_h = (float)3.0 + s2 + r;
        GET_FLOAT_WORD(is, t_h);
        SET_FLOAT_WORD(t_h, is & 0xfffff000);
        t_l = r - ((t_h - (float)3.0) - s2);
        /* u+v = s*(1+...) */
        u = s_h * t_h;
        v = s_l * t_h + t_l * s;
        /* 2/(3log2)*(s+...) */
        p_h = u + v;
        GET_FLOAT_WORD(is, p_h);
        SET_FLOAT_WORD(p_h, is & 0xfffff000);
        p_l = v - (p_h - u);
        z_h = cp_h * p_h;
        z_l = cp_l * p_h + p_l * cp + dp_l[k];
        /* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
        t = (float)n;
        t1 = (((z_h + z_l) + dp_h[k]) + t);
        GET_FLOAT_WORD(is, t1);
        SET_FLOAT_WORD(t1, is & 0xfffff000);
        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    s = one; /* s (sign of result -ve**odd) = -1 else = 1 */
    if (((((u32)hx >> 31) - 1) | (yisint - 1)) == 0)
    {
        s = -one; /* (-ve)**(odd int) */
    }

    /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
    GET_FLOAT_WORD(is, y);
    SET_FLOAT_WORD(y1, is & 0xfffff000);
    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    GET_FLOAT_WORD(j, z);
    i = j & 0x7fffffff;
    if (j > 0)
    {
        if (i > FLT_UWORD_EXP_MAX)
        {
            return s * huge * huge;
        }
        else if (i == FLT_UWORD_EXP_MAX)
        {
            if (p_l + ovt > z - p_h)
            {
                return s * huge * huge;
            }
        }
    }
    else
    {
        if (i > FLT_UWORD_EXP_MIN)
        {
            return s * tiny * tiny;
        }
        else if (i == FLT_UWORD_EXP_MIN)
        {
            if (p_l <= z - p_h)
            {
                return s * tiny * tiny;
            }
        }
    }
    /* compute 2**(p_h+p_l) */
    k = (i >> 23) - 0x7f;
    n = 0;
    if (i > 0x3f000000)
    {
        n = j + (0x00800000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 23) - 0x7f;
        SET_FLOAT_WORD(t, n & ~(0x007fffff >> k));
        n = ((n & 0x007fffff) | 0x00800000) >> (23 - k);
        if (j < 0)
        {
            n = -n;
        }
        p_h -= t;
    }
    t = p_l + p_h;
    GET_FLOAT_WORD(is, t);
    SET_FLOAT_WORD(t, is & 0xfffff000);
    u = t * lg2_h;
    v = (p_l - (t - p_h)) * lg2 + t * lg2_l;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
    r = (z * t1) / (t1 - two) - (w + z * w);
    z = one - (r - z);
    GET_FLOAT_WORD(j, z);
    j += (n << 23);
    if ((j >> 23) <= 0)
    {
        z = scalbnf(z, n);
    }
    else
    {
        SET_FLOAT_WORD(z, j);
    }
    return s * z;
}
