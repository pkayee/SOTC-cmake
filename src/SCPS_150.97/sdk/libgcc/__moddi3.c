#include "common.h"

typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
typedef unsigned long long UDItype;
typedef unsigned char UQItype;
typedef int word_type;

extern const UQItype D_00139038[];
#define __clz_tab D_00139038

struct DIstruct
{
    SItype low, high;
};

typedef union
{
    struct DIstruct s;
    DItype ll;
} DIunion;

#define __ll_B ((USItype)1 << 16)
#define __ll_lowpart(t) ((USItype)(t) & (__ll_B - 1))
#define __ll_highpart(t) ((USItype)(t) >> 16)

#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
    do { \
        USItype __x; \
        __x = (al) - (bl); \
        (sh) = (ah) - (bh) - (__x > (al)); \
        (sl) = __x; \
    } while (0)

#define umul_ppmm(w1, w0, u, v) \
    asm("multu %2,%3" \
        : "=l"((USItype)(w0)), "=h"((USItype)(w1)) \
        : "d"((USItype)(u)), "d"((USItype)(v)))

#define __udiv_qrnnd_c(q, r, n1, n0, d) \
    do { \
        USItype __d1, __d0, __q1, __q0; \
        USItype __r1, __r0, __m; \
        __d1 = __ll_highpart(d); \
        __d0 = __ll_lowpart(d); \
\
        __r1 = (n1) % __d1; \
        __q1 = (n1) / __d1; \
        __m = (USItype)__q1 * __d0; \
        __r1 = __r1 * __ll_B | __ll_highpart(n0); \
        if (__r1 < __m) \
        { \
            __q1--, __r1 += (d); \
            if (__r1 >= (d)) \
                if (__r1 < __m) \
                    __q1--, __r1 += (d); \
        } \
        __r1 -= __m; \
\
        __r0 = __r1 % __d1; \
        __q0 = __r1 / __d1; \
        __m = (USItype)__q0 * __d0; \
        __r0 = __r0 * __ll_B | __ll_lowpart(n0); \
        if (__r0 < __m) \
        { \
            __q0--, __r0 += (d); \
            if (__r0 >= (d)) \
                if (__r0 < __m) \
                    __q0--, __r0 += (d); \
        } \
        __r0 -= __m; \
\
        (q) = (USItype)__q1 * __ll_B | __q0; \
        (r) = __r0; \
    } while (0)

#define udiv_qrnnd __udiv_qrnnd_c

#define count_leading_zeros(count, x) \
    do { \
        USItype __xr = (x); \
        USItype __a; \
\
        __a = __xr < ((USItype)1 << 2 * 8) \
                  ? (__xr < ((USItype)1 << 8) ? 0 : 8) \
                  : (__xr < ((USItype)1 << 3 * 8) ? 2 * 8 : 3 * 8); \
\
        (count) = 32 - (__clz_tab[__xr >> __a] + __a); \
    } while (0)

static inline DItype __negdi2(DItype u)
{
    DIunion w;
    DIunion uu;

    uu.ll = u;

    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((USItype)w.s.low > 0);

    return w.ll;
}

static inline UDItype __udivmoddi4(UDItype n, UDItype d, UDItype *rp)
{
    DIunion ww;
    DIunion nn, dd;
    DIunion rr;
    USItype d0, d1, n0, n1, n2;
    USItype q0, q1;
    USItype b, bm;

    nn.ll = n;
    dd.ll = d;

    d0 = dd.s.low;
    d1 = dd.s.high;
    n0 = nn.s.low;
    n1 = nn.s.high;

    if (d1 == 0)
    {
        if (d0 > n1)
        {
            /* 0q = nn / 0D */

            count_leading_zeros(bm, d0);

            if (bm != 0)
            {
                d0 = d0 << bm;
                n1 = (n1 << bm) | (n0 >> (32 - bm));
                n0 = n0 << bm;
            }

            udiv_qrnnd(q0, n0, n1, n0, d0);
            q1 = 0;
        }
        else
        {
            /* qq = NN / 0d */

            if (d0 == 0)
                d0 = 1 / d0; /* Divide intentionally by zero.  */

            count_leading_zeros(bm, d0);

            if (bm == 0)
            {
                n1 -= d0;
                q1 = 1;
            }
            else
            {
                b = 32 - bm;

                d0 = d0 << bm;
                n2 = n1 >> b;
                n1 = (n1 << bm) | (n0 >> b);
                n0 = n0 << bm;

                udiv_qrnnd(q1, n1, n2, n1, d0);
            }

            udiv_qrnnd(q0, n0, n1, n0, d0);
        }

        if (rp != 0)
        {
            rr.s.low = n0 >> bm;
            rr.s.high = 0;
            *rp = rr.ll;
        }
    }
    else
    {
        if (d1 > n1)
        {
            /* 00 = nn / DD */

            q0 = 0;
            q1 = 0;

            if (rp != 0)
            {
                rr.s.low = n0;
                rr.s.high = n1;
                *rp = rr.ll;
            }
        }
        else
        {
            /* 0q = NN / dd */

            count_leading_zeros(bm, d1);
            if (bm == 0)
            {
                if (n1 > d1 || n0 >= d0)
                {
                    q0 = 1;
                    sub_ddmmss(n1, n0, n1, n0, d1, d0);
                }
                else
                    q0 = 0;

                q1 = 0;

                if (rp != 0)
                {
                    rr.s.low = n0;
                    rr.s.high = n1;
                    *rp = rr.ll;
                }
            }
            else
            {
                USItype m1, m0;

                b = 32 - bm;

                d1 = (d1 << bm) | (d0 >> b);
                d0 = d0 << bm;
                n2 = n1 >> b;
                n1 = (n1 << bm) | (n0 >> b);
                n0 = n0 << bm;

                udiv_qrnnd(q0, n1, n2, n1, d1);
                umul_ppmm(m1, m0, q0, d0);

                if (m1 > n1 || (m1 == n1 && m0 > n0))
                {
                    q0--;
                    sub_ddmmss(m1, m0, m1, m0, d1, d0);
                }

                q1 = 0;

                if (rp != 0)
                {
                    sub_ddmmss(n1, n0, n1, n0, m1, m0);
                    rr.s.low = (n1 << b) | (n0 >> bm);
                    rr.s.high = n1 >> bm;
                    *rp = rr.ll;
                }
            }
        }
    }

    ww.s.low = q0;
    ww.s.high = q1;
    return ww.ll;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__moddi3", __moddi3);
DItype __moddi3(DItype u, DItype v)
{
    word_type c = 0;
    DIunion uu, vv;
    DItype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c,
        uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        vv.ll = __negdi2(vv.ll);

    (void)__udivmoddi4(uu.ll, vv.ll, &w);
    if (c)
        w = __negdi2(w);

    return w;
}
