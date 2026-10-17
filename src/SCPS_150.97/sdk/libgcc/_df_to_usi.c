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

void __unpack_d(DFtype *src, fp_number_type *dst);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", dptoul);

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
