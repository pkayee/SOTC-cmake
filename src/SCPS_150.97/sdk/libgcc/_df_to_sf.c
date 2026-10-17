#include "common.h"

typedef double DFtype;
typedef float FLO_type;
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

void __unpack_d(DFtype *src, fp_number_type *dst);
FLO_type __make_fp(fp_class_type class, int sign, int exp, u32 frac);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_sf", dptofp);
FLO_type dptofp(DFtype a)
{
    fp_number_type in;
    u32 frac;

    __unpack_d(&a, &in);
    frac = (u32)(in.fraction.ll >> 30);
    if (in.fraction.ll & 0x3FFFFFFF)
    {
        frac |= 1;
    }
    return __make_fp(in.class, in.sign, in.normal_exp, frac);
}
