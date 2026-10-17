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

static inline fp_number_type *_fpmul_parts(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    fractype low = 0;
    fractype high = 0;

    if (isnan(a))
    {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isnan(b))
    {
        b->sign = a->sign != b->sign;
        return b;
    }
    if (isinf(a))
    {
        if (iszero(b))
            return nan();
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isinf(b))
    {
        if (iszero(a))
        {
            return nan();
        }
        b->sign = a->sign != b->sign;
        return b;
    }
    if (iszero(a))
    {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero(b))
    {
        b->sign = a->sign != b->sign;
        return b;
    }

    /* Calculate the mantissa by multiplying both 64bit numbers to get a
       128 bit number */
    {
        /* Doing a 64*64 to 128 */
        {
            UDItype nl = a->fraction.ll & 0xffffffff;
            UDItype nh = a->fraction.ll >> 32;
            UDItype ml = b->fraction.ll & 0xffffffff;
            UDItype mh = b->fraction.ll >> 32;
            UDItype pp_ll = ml * nl;
            UDItype pp_hl = mh * nl;
            UDItype pp_lh = ml * nh;
            UDItype pp_hh = mh * nh;
            UDItype res2 = 0;
            UDItype res0 = 0;
            UDItype ps_hh__ = pp_hl + pp_lh;
            if (ps_hh__ < pp_hl)
                res2 += 0x100000000LL;
            pp_hl = (ps_hh__ << 32) & 0xffffffff00000000LL;
            res0 = pp_ll + pp_hl;
            if (res0 < pp_ll)
                res2++;
            res2 += ((ps_hh__ >> 32) & 0xffffffffLL) + pp_hh;
            high = res2;
            low = res0;
        }
    }

    tmp->normal_exp = a->normal_exp + b->normal_exp + FRAC_NBITS - (FRACBITS + NGARDS);
    tmp->sign = a->sign != b->sign;
    while (high >= IMPLICIT_2)
    {
        tmp->normal_exp++;
        if (high & 1)
        {
            low >>= 1;
            low |= FRACHIGH;
        }
        high >>= 1;
    }
    while (high < IMPLICIT_1)
    {
        tmp->normal_exp--;

        high <<= 1;
        if (low & FRACHIGH)
            high |= 1;
        low <<= 1;
    }
    if (!ROUND_TOWARDS_ZERO && (high & GARDMASK) == GARDMSB)
    {
        if (high & (1 << NGARDS))
        {
            /* half way, so round to even */
            high += GARDROUND + 1;
        }
        else if (low)
        {
            /* but we really weren't half way */
            high += GARDROUND + 1;
        }
    }
    tmp->fraction.ll = high;
    tmp->class = CLASS_NUMBER;
    return tmp;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_mul_df", dpmul);
FLO_type dpmul(FLO_type arg_a, FLO_type arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type *res;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;

    __unpack_d(&au, &a);
    __unpack_d(&bu, &b);

    res = _fpmul_parts(&a, &b, &tmp);

    return __pack_d(res);
}
