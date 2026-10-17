#include "common.h"

typedef union
{
    u64 ll;
    struct
    {
        s32 low;
        s32 high;
    } s;
} UDWunion;

extern u8 D_00139138[];

#define COUNT_LEADING_ZEROS(count, x) \
    do { \
        u32 __xr = (x); \
        u32 __a; \
        __a = __xr < 0x10000 ? (__xr < 0x100 ? 0 : 8) : (__xr < 0x1000000 ? 16 : 24); \
        (count) = 32 - (D_00139138[__xr >> __a] + __a); \
    } while (0)

#define umul_ppmm(w1, w0, u, v) \
    asm("multu %2,%3" \
        : "=l"((u32)(w0)), "=h"((u32)(w1)) \
        : "d"((u32)(u)), "d"((u32)(v)))

#define UDIV_QRNND(q, r, n1, n0, d) \
    do { \
        u32 __d1 = (d) >> 16; \
        u32 __d0 = (d) & 0xFFFF; \
        u32 __q1, __q0, __r1, __r0, __m; \
        __r1 = (n1) % __d1; \
        __q1 = (n1) / __d1; \
        __m = __q1 * __d0; \
        __r1 = (__r1 << 16) | ((n0) >> 16); \
        if (__r1 < __m) \
        { \
            __q1--; \
            __r1 += (d); \
            if (__r1 >= (d)) \
            { \
                if (__r1 < __m) \
                { \
                    __q1--; \
                    __r1 += (d); \
                } \
            } \
        } \
        __r1 -= __m; \
        __r0 = __r1 % __d1; \
        __q0 = __r1 / __d1; \
        __m = __q0 * __d0; \
        __r0 = (__r0 << 16) | ((n0) & 0xFFFF); \
        if (__r0 < __m) \
        { \
            __q0--; \
            __r0 += (d); \
            if (__r0 >= (d)) \
            { \
                if (__r0 < __m) \
                { \
                    __q0--; \
                    __r0 += (d); \
                } \
            } \
        } \
        __r0 -= __m; \
        (q) = (__q1 << 16) | __q0; \
        (r) = __r0; \
    } while (0)

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__udivdi3", __udivdi3);
u64 __udivdi3(u64 u, u64 v)
{
    UDWunion nn, dd, ww;
    u32 d0, d1, n0, n1, n2;
    u32 q0, q1;
    u32 b, bm;
    u32 m0, m1;

    nn.ll = u;
    dd.ll = v;

    d0 = dd.s.low;
    d1 = dd.s.high;
    n0 = nn.s.low;
    n1 = nn.s.high;

    if (d1 == 0)
    {
        if (d0 > n1)
        {
            COUNT_LEADING_ZEROS(bm, d0);

            if (bm != 0)
            {
                d0 = d0 << bm;
                n1 = (n1 << bm) | (n0 >> (32 - bm));
                n0 = n0 << bm;
            }

            UDIV_QRNND(q0, n0, n1, n0, d0);
            q1 = 0;
        }
        else
        {
            if (d0 == 0)
            {
                d0 = 1 / d0;
            }

            COUNT_LEADING_ZEROS(bm, d0);

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

                UDIV_QRNND(q1, n1, n2, n1, d0);
            }

            UDIV_QRNND(q0, n0, n1, n0, d0);
        }
    }
    else
    {
        if (d1 > n1)
        {
            q0 = 0;
            q1 = 0;
        }
        else
        {
            COUNT_LEADING_ZEROS(bm, d1);
            if (bm == 0)
            {
                if (n1 > d1 || n0 >= d0)
                {
                    q0 = 1;
                    m0 = (n0 < d0);
                    n0 -= d0;
                    n1 = n1 - d1 - m0;
                }
                else
                {
                    q0 = 0;
                }
                q1 = 0;
            }
            else
            {
                b = 32 - bm;

                d1 = (d1 << bm) | (d0 >> b);
                d0 = d0 << bm;
                n2 = n1 >> b;
                n1 = (n1 << bm) | (n0 >> b);
                n0 = n0 << bm;

                UDIV_QRNND(q0, n1, n2, n1, d1);
                umul_ppmm(m1, m0, q0, d0);

                if (m1 > n1 || (m1 == n1 && m0 > n0))
                {
                    q0--;
                    m0 -= d0;
                    m1 = m1 - d1;
                }
                q1 = 0;
            }
        }
    }

    ww.s.low = q0;
    ww.s.high = q1;

    return ww.ll;
}
