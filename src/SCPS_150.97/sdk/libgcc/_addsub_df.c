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

void __unpack_d(DFtype *src, fp_number_type *dst);
DFtype __pack_d(const fp_number_type *src);
fp_number_type *func_00125180(fp_number_type *a, fp_number_type *b, fp_number_type *tmp);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_addsub_df", dpadd);
DFtype dpadd(DFtype a, DFtype b)
{
    fp_number_type a_in;
    fp_number_type b_in;
    fp_number_type tmp_in;
    fp_number_type *tmp;

    __unpack_d(&a, &a_in);
    __unpack_d(&b, &b_in);
    tmp = func_00125180(&a_in, &b_in, &tmp_in);
    return __pack_d(tmp);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_addsub_df", dpsub);
DFtype dpsub(DFtype a, DFtype b)
{
    fp_number_type a_in;
    fp_number_type b_in;
    fp_number_type tmp_in;
    fp_number_type *tmp;

    __unpack_d(&a, &a_in);
    __unpack_d(&b, &b_in);
    b_in.sign ^= 1;
    tmp = func_00125180(&a_in, &b_in, &tmp_in);
    return __pack_d(tmp);
}
