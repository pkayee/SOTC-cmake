#include "common.h"

typedef struct fp_number_type
{
    s32 class;
    s32 sign;
    s32 normal_exp;
    union
    {
        u64 ll;
        u32 l[4];
    } fraction;
} fp_number_type;

void __unpack_d(double *src, fp_number_type *dst);
s32 __fpcmp_parts_d(fp_number_type *a, fp_number_type *b);

// INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_compare_df", dpcmp);
s32 dpcmp(double a, double b)
{
    fp_number_type a_in;
    fp_number_type b_in;

    __unpack_d(&a, &a_in);
    __unpack_d(&b, &b_in);
    return __fpcmp_parts_d(&a_in, &b_in);
}
