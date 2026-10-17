#include "common.h"

typedef float FLO_type;
typedef double DFtype;
typedef u32 fractype_sf;
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
        fractype_sf ll;
    } fraction;
} fp_number_type;

void __unpack_f(FLO_type *src, fp_number_type *dst);
DFtype __make_dp(fp_class_type class, int sign, int exp, fractype frac);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_sf_to_df", fptodp);
DFtype fptodp(FLO_type a)
{
    fp_number_type in;

    __unpack_f(&a, &in);
    return __make_dp(in.class, in.sign, in.normal_exp, (fractype)in.fraction.ll << 30);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_sf_to_df", func_00125180);
