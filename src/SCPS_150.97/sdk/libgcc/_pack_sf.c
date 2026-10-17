#include "common.h"

typedef float FLO_type;
typedef unsigned int fractype;

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
    FLO_type value;
    fractype value_raw;
    struct
    {
        fractype fraction : 23;
        unsigned int exp : 8;
        unsigned int sign : 1;
    } bits;
} FLO_union_type;

#define NGARDS 7
#define FRACBITS 23
#define EXPBIAS 127
#define EXPMAX 0xff
#define NORMAL_EXPMIN (-(EXPBIAS) + 1)
#define IMPLICIT_1 ((fractype)1 << (FRACBITS + NGARDS))
#define IMPLICIT_2 ((fractype)1 << (FRACBITS + 1 + NGARDS))

static inline int iszero(fp_number_type *x)
{
    return x->class == CLASS_ZERO;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_pack_sf", __pack_f);
FLO_type __pack_f(fp_number_type *src)
{
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;

    if (iszero(src))
    {
        exp = 0;
        fraction = 0;
    }
    else if (fraction == 0)
    {
        exp = 0;
    }
    else
    {
        if (src->normal_exp < NORMAL_EXPMIN)
        {
            exp = 0;
            fraction = 0;
        }
        else if (src->normal_exp > EXPBIAS + 1
                 || (src->normal_exp == EXPBIAS + 1 && fraction >= IMPLICIT_2))
        {
            exp = EXPMAX;
            fraction = 0;
        }
        else
        {
            exp = src->normal_exp + EXPBIAS;
            fraction >>= NGARDS;
        }
    }

    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
