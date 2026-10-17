#include "common.h"

typedef float FLO_type;
typedef u32 fractype;

typedef enum
{
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct
{
    fp_class_type class;
    int sign;
    int normal_exp;
    union
    {
        fractype ll;
    } fraction;
} fp_number_type;

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_unpack_sf", __unpack_f);
void __unpack_f(FLO_type *src, fp_number_type *dst)
{
    fractype frac;
    fractype bits;
    u32 exp;

    bits = *(fractype *)src;
    frac = bits & 0x007FFFFF;
    exp = (bits >> 23) & 0xFF;
    dst->sign = (s32)(bits >> 31);

    if (exp == 0)
    {
        dst->class = CLASS_ZERO;
        return;
    }

    dst->normal_exp = exp - 0x7F;
    dst->class = CLASS_NUMBER;
    dst->fraction.ll = (frac << 7) | 0x40000000;
}
