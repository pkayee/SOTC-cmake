#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_pack_df", __pack_d);

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
        u32 l[4];
    } fraction;
} fp_number_type;

DFtype __pack_d(const fp_number_type *src)
{
    union
    {
        DFtype value;
        fractype ll;
        struct
        {
            fractype fraction : 52;
            unsigned int exp : 11;
            unsigned int sign : 1;
        } bits;
    } u;
    fractype fraction;
    int sign;
    int exp;

    fraction = src->fraction.ll;
    sign = src->sign;
    exp = 0;
    if (src->class == CLASS_SNAN || src->class == CLASS_QNAN)
    {
        exp = 0x7FF;
        fraction |= (fractype) 1 << 51;
    }
    else if ((src->class ^ CLASS_INFINITY) == 0)
    {
        exp = 0x7FF;
        fraction = 0;
    }
    else if ((src->class ^ CLASS_ZERO) == 0)
    {
        fraction = 0;
    }
    else if (fraction != 0)
    {
        if (src->normal_exp < -0x3FE)
        {
            fraction = 0;
        }
        else if (src->normal_exp >= 0x400)
        {
            exp = 0x7FF;
            fraction = 0;
        }
        else
        {
            exp = src->normal_exp + 0x3FF;
            fraction >>= 8;
        }
    }

    u.bits.fraction = fraction;
    u.bits.exp = exp;
    u.bits.sign = sign;
    return u.value;
}
