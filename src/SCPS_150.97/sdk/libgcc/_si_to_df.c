#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_si_to_df", litodp);

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

DFtype __pack_d(const fp_number_type *src);

#define FRACBITS 52
#define NGARDS 8
#define IMPLICIT_1 (1LL << (FRACBITS + NGARDS))

DFtype litodp(s32 a)
{
    fp_number_type in;

    in.class = CLASS_NUMBER;
    in.sign = a < 0;
    if (a == 0)
    {
        in.class = CLASS_ZERO;
    }
    else
    {
        in.normal_exp = FRACBITS + NGARDS;
        if (in.sign)
        {
            if (a == (s32)0x80000000)
            {
                return -2147483648.0;
            }
            in.fraction.ll = -a;
        }
        else
        {
            in.fraction.ll = a;
        }
        while (in.fraction.ll < IMPLICIT_1)
        {
            in.fraction.ll <<= 1;
            in.normal_exp--;
        }
    }
    return __pack_d(&in);
}
