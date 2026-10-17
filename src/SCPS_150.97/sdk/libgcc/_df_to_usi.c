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

/* gcc 2.96 frame.c pieces (the split puts decode_uleb128 .. end_fde_sort here) */
typedef int sword __attribute__((mode(SI)));
typedef unsigned int uword __attribute__((mode(SI)));
typedef unsigned int uaddr __attribute__((mode(pointer)));
typedef int saddr __attribute__((mode(pointer)));
typedef unsigned int size_t;

struct dwarf_fde
{
    uword length;
    sword CIE_delta;
    void *pc_begin;
    uaddr pc_range;
} __attribute__((packed, aligned(__alignof__(void *))));

typedef struct dwarf_fde fde;

typedef struct fde_vector
{
    fde **array;
    size_t count;
} fde_vector;

typedef struct fde_accumulator
{
    fde_vector linear;
    fde_vector erratic;
} fde_accumulator;

/* Ordering function for FDEs.  Functions can't overlap, so we just compare
   their starting addresses.  */

static inline saddr fde_compare(fde *x, fde *y)
{
    return (saddr)x->pc_begin - (saddr)y->pc_begin;
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

/* gcc frame.c: fde_merge.  Merge V1 and V2, both sorted, and put the result into V1.  */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125B38);
void func_00125B38(fde_vector *v1, const fde_vector *v2)
{
    size_t i1, i2;
    fde *fde2;

    i2 = v2->count;
    if (i2 > 0)
    {
        i1 = v1->count;
        do
        {
            i2--;
            fde2 = v2->array[i2];
            while (i1 > 0 && fde_compare(v1->array[i1 - 1], fde2) > 0)
            {
                v1->array[i1 + i2] = v1->array[i1 - 1];
                i1--;
            }
            v1->array[i1 + i2] = fde2;
        } while (i2 > 0);
        v1->count += v2->count;
    }
}

void free(void *ptr);
void abort(void);

/* fde_split's `static fde *marker;` (libgcc was built -G0: it lives in .bss) */
extern fde *D_0016A10C[];
#define marker (*D_0016A10C)

/* Split LINEAR into a linear sequence with low values and an erratic
   sequence with high values, put the linear one (of longest possible
   length) into LINEAR and the erratic one into ERRATIC. This is O(N).  */
static inline void fde_split(fde_vector *linear, fde_vector *erratic)
{
    size_t count = linear->count;
    fde **chain_end = &marker;
    size_t i, j, k;

    /* This should optimize out, but it is wise to make sure this assumption
       is correct. Should these have different sizes, we cannot cast between
       them and the overlaying onto ERRATIC will not work.  */
    if (sizeof(fde *) != sizeof(fde **))
        abort();

    for (i = 0; i < count; i++)
    {
        fde **probe;

        for (probe = chain_end; probe != &marker && fde_compare(linear->array[i], *probe) < 0; probe = chain_end)
        {
            chain_end = (fde **)erratic->array[probe - linear->array];
            erratic->array[probe - linear->array] = NULL;
        }
        erratic->array[i] = (fde *)chain_end;
        chain_end = &linear->array[i];
    }

    /* Each entry in LINEAR which is part of the linear sequence we have
       discovered will correspond to a non-NULL entry in the chain we built in
       the ERRATIC array.  */
    for (i = j = k = 0; i < count; i++)
        if (erratic->array[i])
            linear->array[j++] = linear->array[i];
        else
            erratic->array[k++] = linear->array[i];
    linear->count = j;
    erratic->count = k;
}

/* This is O(n log(n)).  BSD/OS defines heapsort in stdlib.h, so we must
   use a name that does not conflict.  */
static inline void frame_heapsort(fde_vector *erratic)
{
    /* For a description of this algorithm, see:
       Samuel P. Harbison, Guy L. Steele Jr.: C, a reference manual, 2nd ed.,
       Prentice-Hall, Englewood Cliffs, NJ, 1987, p. 247f.  */
    fde **a = erratic->array;
    /* A portion of the array is called a "heap" if for all i>=0:
       If i and 2i+1 are valid indices, then a[i] >= a[2i+1].
       If i and 2i+2 are valid indices, then a[i] >= a[2i+2].  */
#define SWAP(x, y) do { fde *tmp = x; x = y; y = tmp; } while (0)
    size_t n = erratic->count;
    size_t m = n;
    size_t i;

    while (m > 0)
    {
        /* Invariant: a[m..n-1] is a heap.  */
        m--;
        for (i = m; 2 * i + 1 < n;)
        {
            if (2 * i + 2 < n && fde_compare(a[2 * i + 2], a[2 * i + 1]) > 0 && fde_compare(a[2 * i + 2], a[i]) > 0)
            {
                SWAP(a[i], a[2 * i + 2]);
                i = 2 * i + 2;
            }
            else if (fde_compare(a[2 * i + 1], a[i]) > 0)
            {
                SWAP(a[i], a[2 * i + 1]);
                i = 2 * i + 1;
            }
            else
                break;
        }
    }
    while (n > 1)
    {
        /* Invariant: a[0..n-1] is a heap.  */
        n--;
        SWAP(a[0], a[n]);
        for (i = 0; 2 * i + 1 < n;)
        {
            if (2 * i + 2 < n && fde_compare(a[2 * i + 2], a[2 * i + 1]) > 0 && fde_compare(a[2 * i + 2], a[i]) > 0)
            {
                SWAP(a[i], a[2 * i + 2]);
                i = 2 * i + 2;
            }
            else if (fde_compare(a[2 * i + 1], a[i]) > 0)
            {
                SWAP(a[i], a[2 * i + 1]);
                i = 2 * i + 1;
            }
            else
                break;
        }
    }
#undef SWAP
}

void func_00125B38(fde_vector *v1, const fde_vector *v2);

/* gcc frame.c: end_fde_sort */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/_df_to_usi", func_00125C30);
fde **func_00125C30(fde_accumulator *accu, size_t count)
{
    if (accu->linear.array && accu->linear.count != count)
        abort();

    if (accu->erratic.array)
    {
        fde_split(&accu->linear, &accu->erratic);
        if (accu->linear.count + accu->erratic.count != count)
            abort();
        frame_heapsort(&accu->erratic);
        func_00125B38(&accu->linear, &accu->erratic);
        free(accu->erratic.array);
    }
    else
    {
        /* We've not managed to malloc an erratic array, so heap sort in the
           linear one.  */
        frame_heapsort(&accu->linear);
    }
    return accu->linear.array;
}
