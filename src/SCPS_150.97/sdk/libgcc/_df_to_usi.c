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
    } fraction;
} fp_number_type;

typedef union
{
    DFtype value;
    fractype value_raw;
} FLO_union_type;

typedef unsigned int USItype;
#define MAX_USI_INT ((USItype)~0)
#define FRACBITS 52
#define NGARDS 8

void __unpack_d(FLO_union_type *src, fp_number_type *dst);

static inline int isnan(fp_number_type *x)
{
    return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

static inline int isinf(fp_number_type *x)
{
    return x->class == CLASS_INFINITY;
}

static inline int iszero(fp_number_type *x)
{
    return x->class == CLASS_ZERO;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", dptoul);
USItype dptoul(DFtype arg_a)
{
    fp_number_type a;
    FLO_union_type au;

    au.value = arg_a;
    __unpack_d(&au, &a);

    if (iszero(&a))
        return 0;
    if (isnan(&a))
        return 0;
    /* it is a negative number */
    if (a.sign)
        return 0;
    /* get reasonable MAX_USI_INT...  */
    if (isinf(&a))
        return MAX_USI_INT;
    /* it is a number, but a small one */
    if (a.normal_exp < 0)
        return 0;
    if (a.normal_exp > 31)
        return MAX_USI_INT;
    else if (a.normal_exp > (FRACBITS + NGARDS))
        return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
    else
        return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125A98);
u8 *func_00125A98(u8 *p, u32 *out)
{
    u32 result;
    u32 shift;
    u8 b;

    b = *p++;
    result = b & 0x7F;
    shift = 0;
    if (b & 0x80)
    {
        do
        {
            b = *p++;
            shift += 7;
            result |= (b & 0x7F) << shift;
        } while (b & 0x80);
    }
    *out = result;
    return p;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125AE0);
u8 *func_00125AE0(u8 *p, s32 *out)
{
    u8 b;
    u32 shift;
    u32 result;

    shift = 0;
    result = 0;
    do
    {
        b = *p++;
        result |= (b & 0x7F) << shift;
        shift += 7;
    } while (b & 0x80);
    if (shift < 32)
    {
        if (b & 0x40)
        {
            result |= -1 << shift;
        }
    }
    *out = result;
    return p;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125B38);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125C30);
