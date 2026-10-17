#include "common.h"

typedef double DFtype;
typedef u64 fractype;

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_unpack_df", __unpack_d);
void __unpack_d(DFtype *src, fp_number_type *dst)
{
    fractype frac;
    fractype bits;
    u32 exp;

    bits = *(fractype *)src;
    frac = bits & 0x000FFFFFFFFFFFFFLL;
    exp = (u32)(bits >> 52) & 0x7FF;
    dst->sign = (s32)(bits >> 63);

    if (exp == 0)
    {
        dst->class = CLASS_ZERO;
        return;
    }

    if (exp == 0x7FF)
    {
        dst->normal_exp = 0x3FF;
        if (frac == 0)
        {
            dst->class = CLASS_INFINITY;
            dst->fraction.ll = 0x1000000000000000LL;
            return;
        }
        if (frac & 0x0008000000000000LL)
        {
            dst->class = CLASS_QNAN;
        }
        else
        {
            dst->class = CLASS_SNAN;
        }
        dst->fraction.ll = frac;
        return;
    }

    dst->normal_exp = exp - 0x3FF;
    dst->class = CLASS_NUMBER;
    dst->fraction.ll = (frac << 8) | 0x1000000000000000LL;
}
