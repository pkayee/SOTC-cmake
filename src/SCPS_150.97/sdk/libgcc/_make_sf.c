#include "common.h"

typedef s32 fp_class_type;
typedef u32 fractype;
typedef float FLO_type;

typedef struct
{
    fp_class_type class;
    s32 sign;
    s32 normal_exp;
    union
    {
        fractype ll;
    } fraction;
} fp_number_type;

FLO_type __pack_f(fp_number_type *);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_make_sf", __make_fp);
FLO_type __make_fp(fp_class_type class, u32 sign, s32 exp, fractype frac)
{
    fp_number_type in;

    in.class = class;
    in.sign = sign;
    in.normal_exp = exp;
    in.fraction.ll = frac;
    return __pack_f(&in);
}
