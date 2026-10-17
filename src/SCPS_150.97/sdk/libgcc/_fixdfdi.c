#include "common.h"

typedef double DFtype;
typedef s64 DItype;
typedef u64 UDItype;

s32 dpcmp(DFtype a, DFtype b);
DFtype dpsub(DFtype a, DFtype b);
UDItype __fixunsdfdi(DFtype a);

// INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_fixdfdi", __fixdfdi);
DItype __fixdfdi(DFtype a)
{
    if (dpcmp(a, 0.0) < 0)
    {
        return -__fixunsdfdi(dpsub(0.0, a));
    }

    return __fixunsdfdi(a);
}
