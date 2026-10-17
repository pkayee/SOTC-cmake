#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__muldi3", __muldi3);

typedef union
{
    s64 ll;
    struct
    {
        s32 low;
        s32 high;
    } s;
} DWunion;

#define umul_ppmm(w1, w0, u, v) \
    asm("multu %2,%3" \
        : "=l"((u32)(w0)), "=h"((u32)(w1)) \
        : "d"((u32)(u)), "d"((u32)(v)))

#define __umulsidi3(u, v) \
    ({ \
        DWunion __w; \
        umul_ppmm(__w.s.high, __w.s.low, u, v); \
        __w.ll; \
    })

s64 __muldi3(s64 u, s64 v)
{
    DWunion w;
    DWunion uu, vv;

    uu.ll = u, vv.ll = v;

    w.ll = __umulsidi3(uu.s.low, vv.s.low);
    w.s.high += ((u32)uu.s.low * (u32)vv.s.high + (u32)uu.s.high * (u32)vv.s.low);

    return w.ll;
}
