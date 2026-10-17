#include "common.h"
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

double _strtod_r(struct _reent *ptr, const char *s, char **endptr);

/* NEARMISS-STUB _strtod_r */
#if 0 /* NEARMISS 38.3% cat=branch-layout sub=- | frame 0xA0 vs 0x80, bigint correction loop control flow differs (first-draft whole function) | attempts=1 */
#include "common.h"
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

struct Bigint
{
    struct Bigint *next;
    int k;
    int maxwds;
    int sign;
    int wds;
    u32 x[1];
};

union mp_double
{
    double d;
    u32 L[2];
};

#define word0(x) ((x).L[1])
#define word1(x) ((x).L[0])

#define DBL_DIG 15
#define DBL_MAX_10_EXP 308
#define DBL_MAX_EXP 1024
#define Exp_msk1 0x100000
#define Exp_mask 0x7ff00000
#define P 53
#define Bias 1023
#define Ten_pmax 22

extern struct Bigint *_Balloc(struct _reent *ptr, int k);
extern void _Bfree(struct _reent *ptr, struct Bigint *v);
extern struct Bigint *_d2b(struct _reent *ptr, double d, int *e, int *bits);
extern double _b2d(struct Bigint *a, int *e);
extern double _ratio(struct Bigint *a, struct Bigint *b);
extern struct Bigint *_multadd(struct _reent *ptr, struct Bigint *b, int m, int a);
extern struct Bigint *_s2b(struct _reent *ptr, const char *s, int nd0, int nd, u32 y9);
extern struct Bigint *_i2b(struct _reent *ptr, int i);
extern struct Bigint *_pow5mult(struct _reent *ptr, struct Bigint *b, int k);
extern struct Bigint *_lshift(struct _reent *ptr, struct Bigint *b, int k);
extern struct Bigint *_multiply(struct _reent *ptr, struct Bigint *a, struct Bigint *b);
extern struct Bigint *__mdiff(struct _reent *ptr, struct Bigint *a, struct Bigint *b);
extern int __mcmp(struct Bigint *a, struct Bigint *b);
extern double _ulp(double x);
extern double dpadd(double a, double b);
extern double dpsub(double a, double b);
extern double dpmul(double a, double b);
extern double dpdiv(double a, double b);
extern s32 dpcmp(double a, double b);
extern double litodp(s32 a);
extern s32 dptoli(double a);
extern double D_00139C18[];
extern double D_00139C60[];
extern double D_00139D28[];
extern double D_00139D50[];
extern double D_00139E38[];
extern double D_00139E40[];
extern double D_00139E48[];
extern double D_00139E50[];
extern void *memcpy(void *d, const void *s, u32 n);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", _strtod_r);
double _strtod_r(struct _reent *ptr, const char *s00, char **se)
{
    int bb2, bb5, bbe, bbbits, bd2, bd5, bs2, c, dsign, esign, i, j, k, nd, nd0, nf, nz, nz0, sign;
    const char *s, *s0, *s1, *es;
    union mp_double rv;
    s64 e, e1;
    s64 L;
    u32 y, z;
    struct Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;
    union mp_double rv0;
    int scale;

    sign = nz0 = nz = 0;
    rv.d = 0.0;
    bb = bb1 = bd = bd0 = bs = delta = NULL;
    for (s = s00;; s++)
    {
        switch (*s)
        {
        case '-':
            sign = 1;
            // fallthrough 
        case '+':
            if (*++s == '\0')
            {
                goto ret0;
            }
            // fallthrough 
        default:
            goto break2;
        }
    }
break2:
    if (*s == '0')
    {
        nz0 = 1;
        while (*++s == '0')
        {
        }
        if (!*s)
        {
            goto ret;
        }
    }
    s0 = s;
    y = z = 0;
    for (nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
    {
        if (nd < 9)
        {
            y = 10 * y + c - '0';
        }
        else if (nd < 16)
        {
            z = 10 * z + c - '0';
        }
    }
    nd0 = nd;
    if (c == '.')
    {
        c = *++s;
        if (!nd)
        {
            for (; c == '0'; c = *++s)
            {
                nz++;
            }
            if (c > '0' && c <= '9')
            {
                s0 = s;
                nf += nz;
                nz = 0;
                goto have_dig;
            }
            goto dig_done;
        }
        for (; c >= '0' && c <= '9'; c = *++s)
        {
have_dig:
            nz++;
            if (c -= '0')
            {
                nf += nz;
                for (i = 1; i < nz; i++)
                {
                    if (nd++ < 9)
                    {
                        y *= 10;
                    }
                    else if (nd <= DBL_DIG + 1)
                    {
                        z *= 10;
                    }
                }
                if (nd++ < 9)
                {
                    y = 10 * y + c;
                }
                else if (nd <= DBL_DIG + 1)
                {
                    z = 10 * z + c;
                }
                nz = 0;
            }
        }
    }
dig_done:
    e = 0;
    if (c == 'e' || c == 'E')
    {
        if (!nd && !nz && !nz0)
        {
            goto ret0;
        }
        es = s;
        esign = 0;
        switch (c = *++s)
        {
        case '-':
            esign = 1;
            // fallthrough 
        case '+':
            c = *++s;
        }
        if (c >= '0' && c <= '9')
        {
            while (c == '0')
            {
                c = *++s;
            }
            if (c > '0' && c <= '9')
            {
                L = c - '0';
                s1 = s;
                while ((c = *++s) >= '0' && c <= '9')
                {
                    L = 10 * L + c - '0';
                }
                if (s - s1 > 8 || L > 19999)
                {
                    e = 19999;
                }
                else
                {
                    e = (s64)L;
                }
                if (esign)
                {
                    e = -e;
                }
            }
            else
            {
                e = 0;
            }
        }
        else
        {
            s = es;
        }
    }
    if (!nd)
    {
        if (!nz && !nz0)
        {
ret0:
            s = s00;
            sign = 0;
        }
        goto ret;
    }
    e1 = e -= nf;

    // Now we have nd0 digits, starting at s0, followed by a
     * decimal point, followed by nd-nd0 digits. 
    if (!nd0)
    {
        nd0 = nd;
    }
    k = nd < DBL_DIG + 2 ? nd : DBL_DIG + 2;
    rv.d = litodp(y);
    if (k > 9)
    {
        rv.d = D_00139C18[k] * rv.d + z;
    }
    bd0 = 0;

    // Get starting approximation = rv * 10**e1 
    if (e1 > 0)
    {
        if ((i = e1 & 15))
        {
            rv.d *= D_00139C60[i];
        }
        if (e1 &= ~15)
        {
            if (e1 > DBL_MAX_10_EXP)
            {
ovfl:
                rv.d = D_00139E50[0];
                goto ret;
            }
            e1 >>= 4;
            for (j = 0; e1 > 1; j++, e1 >>= 1)
            {
                if (e1 & 1)
                {
                    rv.d *= D_00139D28[j];
                }
            }
            word0(rv) -= P * Exp_msk1;
            rv.d *= D_00139D28[j];
            if ((z = word0(rv) & Exp_mask) > Exp_msk1 * (DBL_MAX_EXP + Bias - P))
            {
                goto ovfl;
            }
            if (z > Exp_msk1 * (DBL_MAX_EXP + Bias - P))
            {
                word0(rv) = 0x7fefffff;
                word1(rv) = 0xffffffff;
            }
            else
            {
                word0(rv) += P * Exp_msk1;
            }
        }
    }
    else if (e1 < 0)
    {
        e1 = -e1;
        if ((i = e1 & 15))
        {
            rv.d /= D_00139C60[i];
        }
        if (e1 >>= 4)
        {
            for (j = 0; e1 > 0; j++, e1 >>= 1)
            {
                if (e1 & 1)
                {
                    rv.d *= D_00139D50[j];
                }
            }
        }
    }
    // Need to compare to the correctly rounded value using bigints. 
    bd0 = _s2b(ptr, s0, nd0, nd, y);
    for (;;)
    {
        bd = _Balloc(ptr, bd0->k);
        memcpy(bd, bd0, sizeof(struct Bigint) + (bd0->wds - 1) * sizeof(u32));
        bb = _d2b(ptr, rv.d, &bbe, &bbbits);
        bs = _i2b(ptr, 1);
        if (e >= 0)
        {
            bb2 = bb5 = 0;
            bd2 = bd5 = e;
        }
        else
        {
            bb2 = bb5 = -e;
            bd2 = bd5 = 0;
        }
        if (bbe >= 0)
        {
            bb2 += bbe;
        }
        else
        {
            bd2 -= bbe;
        }
        bs2 = bb2;
        if (bb5 > 0)
        {
            bb = _pow5mult(ptr, bb, bb5);
        }
        if (bd5 > 0)
        {
            bd = _pow5mult(ptr, bd, bd5);
        }
        if (bb2 > 0)
        {
            bb = _lshift(ptr, bb, bb2);
        }
        if (bd2 > 0)
        {
            bd = _lshift(ptr, bd, bd2);
        }
        if (bs2 > 0)
        {
            bs = _lshift(ptr, bs, bs2);
        }
        delta = __mdiff(ptr, bb, bd);
        dsign = delta->sign;
        delta->sign = 0;
        i = __mcmp(delta, bs);
        if (i < 0)
        {
            break;
        }
        if (i == 0)
        {
            break;
        }
        rv.d = _ulp(rv.d);
        break;
    }
ret:
    if (se)
    {
        *se = (char *)s;
    }
    if (bb)
    {
        _Bfree(ptr, bb);
    }
    if (bd)
    {
        _Bfree(ptr, bd);
    }
    if (bs)
    {
        _Bfree(ptr, bs);
    }
    if (bd0)
    {
        _Bfree(ptr, bd0);
    }
    if (delta)
    {
        _Bfree(ptr, delta);
    }
    return sign ? dpsub(0.0, rv.d) : rv.d;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", strtod);
double strtod(const char *s, char **endptr)
{
    return _strtod_r(D_00135D60[0], s, endptr);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", strtodf);
f32 strtodf(const char *s, char **endptr)
{
    return strtod(s, endptr);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", _strtod_r);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", strtod);
double strtod(const char *s, char **endptr)
{
    return _strtod_r(D_00135D60[0], s, endptr);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strtod", strtodf);
f32 strtodf(const char *s, char **endptr)
{
    return strtod(s, endptr);
}
