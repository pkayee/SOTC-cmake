#include "common.h"

typedef unsigned long long UDItype;
typedef double FLO_type;
typedef UDItype fractype;

#define NGARDS 8L
#define GARDROUND 0x7f
#define GARDMASK 0xff
#define GARDMSB 0x80
#define FRACBITS 52
#define EXPBIAS 1023
#define EXPMAX 0x7ff
#define IMPLICIT_1 ((fractype)1 << (FRACBITS + NGARDS))
#define IMPLICIT_2 ((fractype)1 << (FRACBITS + 1 + NGARDS))
#define FRAC_NBITS 64
#define FRACHIGH 0x8000000000000000LL
#define ROUND_TOWARDS_ZERO 1

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
    unsigned int sign;
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
} FLO_union_type;

#define __thenan_df D_00139338
extern const fp_number_type __thenan_df;

void __unpack_d(FLO_union_type *src, fp_number_type *dst);
FLO_type __pack_d(fp_number_type *src);

static inline fp_number_type *nan(void)
{
    return (fp_number_type *)(&__thenan_df);
}

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

static inline fp_number_type *_fpdiv_parts(fp_number_type *a, fp_number_type *b)
{
    UDItype bit;
    UDItype numerator;
    UDItype denominator;
    UDItype quotient;

    if (isnan(a))
    {
        return a;
    }
    if (isnan(b))
    {
        return b;
    }

    a->sign = a->sign ^ b->sign;

    if (isinf(a) || iszero(a))
    {
        if (a->class == b->class)
            return nan();
        return a;
    }

    if (isinf(b))
    {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero(b))
    {
        a->class = CLASS_INFINITY;
        return a;
    }

    /* Calculate the mantissa by multiplying both 64bit numbers to get a
       128 bit number */
    {
        /* quotient =
           ( numerator / denominator) * 2^(numerator exponent -  denominator exponent)
         */

        a->normal_exp = a->normal_exp - b->normal_exp;
        numerator = a->fraction.ll;
        denominator = b->fraction.ll;

        if (numerator < denominator)
        {
            /* Fraction will be less than 1.0 */
            numerator *= 2;
            a->normal_exp--;
        }
        bit = IMPLICIT_1;
        quotient = 0;
        /* ??? Does divide one bit at a time.  Optimize.  */
        while (bit)
        {
            if (numerator >= denominator)
            {
                quotient |= bit;
                numerator -= denominator;
            }
            bit >>= 1;
            numerator *= 2;
        }

        if (!ROUND_TOWARDS_ZERO && (quotient & GARDMASK) == GARDMSB)
        {
            if (quotient & (1 << NGARDS))
            {
                /* half way, so round to even */
                quotient += GARDROUND + 1;
            }
            else if (numerator)
            {
                /* but we really weren't half way, more bits exist */
                quotient += GARDROUND + 1;
            }
        }

        a->fraction.ll = quotient;
        return (a);
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_div_df", dpdiv);
FLO_type dpdiv(FLO_type arg_a, FLO_type arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type *res;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;

    __unpack_d(&au, &a);
    __unpack_d(&bu, &b);

    res = _fpdiv_parts(&a, &b);

    return __pack_d(res);
}
