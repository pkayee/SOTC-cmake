#include "common.h"

typedef float SFtype;
typedef double DFtype;
typedef u64 UDItype;
typedef u32 USItype;

s32 dpcmp(DFtype a, DFtype b);
DFtype fptodp(SFtype a);
DFtype dpmul(DFtype a, DFtype b);
DFtype dpadd(DFtype a, DFtype b);
DFtype dpsub(DFtype a, DFtype b);
USItype dptoul(DFtype a);

// INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__fixunssfdi", __fixunssfdi);
UDItype __fixunssfdi(SFtype original_a)
{
    DFtype a;
    DFtype b;
    UDItype v;

    a = fptodp(original_a);

    if (dpcmp(a, 0.0) < 0)
    {
        return 0;
    }

    b = a / 4294967296.0;
    v = dptoul(b);
    v <<= 32;

    a = dpsub(a, (DFtype)v);

    if (dpcmp(a, 0.0) < 0)
    {
        v -= dptoul(dpsub(0.0, a));
    }
    else
    {
        v += dptoul(a);
    }

    return v;
}
