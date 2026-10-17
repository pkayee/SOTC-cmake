#include "common.h"
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_make_df", __make_dp);

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

DFtype __pack_d(const fp_number_type *src);

DFtype __make_dp(fp_class_type class, int sign, int exp, fractype frac)
{
    fp_number_type d;

    d.class = class;
    d.sign = sign;
    d.normal_exp = exp;
    d.fraction.ll = frac;
    return __pack_d(&d);
}
