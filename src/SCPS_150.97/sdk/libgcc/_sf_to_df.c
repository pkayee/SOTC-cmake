#include "common.h"

typedef float FLO_type;
typedef double DFtype;
typedef u32 fractype_sf;
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
        fractype_sf ll;
    } fraction;
} fp_number_type;

void __unpack_f(FLO_type *src, fp_number_type *dst);
DFtype __make_dp(fp_class_type class, int sign, int exp, fractype frac);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_sf_to_df", fptodp);
DFtype fptodp(FLO_type a)
{
    fp_number_type in;

    __unpack_f(&a, &in);
    return __make_dp(in.class, in.sign, in.normal_exp, (fractype)in.fraction.ll << 30);
}


/* _fpadd_parts from fp-bit.c (double); the split puts it after fptodp. */
typedef long long intfrac;

typedef struct
{
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union
    {
        fractype ll;
    } fraction;
} df_number_type;

#define FRAC_NBITS 64
#define IMPLICIT_1 ((fractype)1 << (52 + 8))
#define IMPLICIT_2 ((fractype)1 << (52 + 1 + 8))
#define LSHIFT(a) { a = (a & 1) | (a >> 1); }

#define __thenan_df D_00139338
extern const df_number_type __thenan_df;

static inline df_number_type *nan(void)
{
    return (df_number_type *)(&__thenan_df);
}

static inline int isnan(df_number_type *x)
{
    return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

static inline int isinf(df_number_type *x)
{
    return x->class == CLASS_INFINITY;
}

static inline int iszero(df_number_type *x)
{
    return x->class == CLASS_ZERO;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_sf_to_df", func_00125180);
df_number_type *func_00125180(df_number_type *a, df_number_type *b, df_number_type *tmp)
{
    intfrac tfraction;

    /* Put commonly used fields in local variables.  */
    int a_normal_exp;
    int b_normal_exp;
    fractype a_fraction;
    fractype b_fraction;

    if (isnan(a))
    {
        return a;
    }
    if (isnan(b))
    {
        return b;
    }
    if (isinf(a))
    {
        /* Adding infinities with opposite signs yields a NaN.  */
        if (isinf(b) && a->sign != b->sign)
            return nan();
        return a;
    }
    if (isinf(b))
    {
        return b;
    }
    if (iszero(b))
    {
        if (iszero(a))
        {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (iszero(a))
    {
        return b;
    }

    /* Got two numbers. shift the smaller and increment the exponent till
       they're the same */
    {
        int diff;

        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction.ll;
        b_fraction = b->fraction.ll;

        diff = a_normal_exp - b_normal_exp;

        if (diff < 0)
            diff = -diff;
        if (diff < FRAC_NBITS)
        {
            /* ??? This does shifts one bit at a time.  Optimize.  */
            while (a_normal_exp > b_normal_exp)
            {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp)
            {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        }
        else
        {
            /* Somethings's up.. choose the biggest */
            if (a_normal_exp > b_normal_exp)
            {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            }
            else
            {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }

    if (a->sign != b->sign)
    {
        if (a->sign)
        {
            tfraction = -a_fraction + b_fraction;
        }
        else
        {
            tfraction = a_fraction - b_fraction;
        }
        if (tfraction >= 0)
        {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        }
        else
        {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        /* and renormalize it */

        while (tmp->fraction.ll < IMPLICIT_1 && tmp->fraction.ll)
        {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    }
    else
    {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;
    /* Now the fraction is added, we have to shift down to renormalize the
       number */

    if (tmp->fraction.ll >= IMPLICIT_2)
    {
        LSHIFT(tmp->fraction.ll);
        tmp->normal_exp++;
    }
    return tmp;
}
