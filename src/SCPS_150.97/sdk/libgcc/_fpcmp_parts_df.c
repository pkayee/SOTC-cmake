#include "common.h"

typedef enum
{
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct fp_number_type
{
    fp_class_type class;
    s32 sign;
    s32 normal_exp;
    union
    {
        u64 ll;
        u32 l[4];
    } fraction;
} fp_number_type;

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_fpcmp_parts_df", __fpcmp_parts_d);
s32 __fpcmp_parts_d(fp_number_type *a, fp_number_type *b)
{
    if (a->class < CLASS_ZERO || b->class < CLASS_ZERO)
    {
        return 1;
    }
    if ((a->class ^ CLASS_INFINITY) == 0)
    {
        if ((b->class ^ CLASS_INFINITY) == 0)
        {
            return b->sign - a->sign;
        }
        return a->sign ? -1 : 1;
    }
    if ((b->class ^ CLASS_INFINITY) == 0)
    {
        return b->sign ? 1 : -1;
    }
    if ((a->class ^ CLASS_ZERO) == 0)
    {
        if ((b->class ^ CLASS_ZERO) == 0)
        {
            return 0;
        }
        return b->sign == 0 ? -1 : 1;
    }
    if ((b->class ^ CLASS_ZERO) == 0)
    {
        return a->sign ? -1 : 1;
    }
    if (a->sign != b->sign)
    {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp > b->normal_exp)
    {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp < b->normal_exp)
    {
        return a->sign ? 1 : -1;
    }
    if (a->fraction.ll > b->fraction.ll)
    {
        return a->sign ? -1 : 1;
    }
    if (a->fraction.ll < b->fraction.ll)
    {
        return a->sign ? 1 : -1;
    }
    return 0;
}
