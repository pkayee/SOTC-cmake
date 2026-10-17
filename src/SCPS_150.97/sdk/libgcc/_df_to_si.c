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
        u32 l[4];
    } fraction;
} fp_number_type;

void __unpack_d(DFtype *src, fp_number_type *dst);

#define FRACBITS 52
#define NGARDS 8

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_si", dptoli);
s32 dptoli(DFtype a)
{
    fp_number_type in;
    s32 i;

    __unpack_d(&a, &in);
    if ((in.class ^ CLASS_ZERO) == 0)
    {
        return 0;
    }
    if (in.class < CLASS_ZERO)
    {
        return 0;
    }
    if ((in.class ^ CLASS_INFINITY) == 0)
    {
        return in.sign ? (s32)0x80000000 : 0x7FFFFFFF;
    }
    if (in.normal_exp < 0)
    {
        return 0;
    }
    if (in.normal_exp >= 31)
    {
        return in.sign ? (s32)0x80000000 : 0x7FFFFFFF;
    }
    i = (s32)(in.fraction.ll >> ((FRACBITS + NGARDS) - in.normal_exp));
    if (in.sign)
    {
        i = -i;
    }
    return i;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_si", func_00131CAC);
