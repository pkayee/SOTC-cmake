#include "common.h"

typedef union
{
    float value;
    u32 word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i, d)            \
    do                                  \
    {                                   \
        ieee_float_shape_type gf_u;     \
        gf_u.value = (d);               \
        (i) = gf_u.word;                \
    } while (0)

float fabsf(float x);

extern float D_40049428[];
extern float D_40049438[];
extern float D_40049448[];
extern float D_40049434;
extern float D_40049444;

#define FLT_UWORD_IS_NAN(x) 0

#define atanhi D_40049428
#define atanlo D_40049438
#define aT D_40049448
#define one ((float)1.0)
#define huge ((float)1.0e30)

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/atanf", atanf);
float atanf(float x)
{
    float w, s1, s2, z;
    s32 ix, hx, id;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) /* if |x| >= 2^34 */
    {
        if (FLT_UWORD_IS_NAN(ix))
        {
            return x + x; /* NaN */
        }
        if (hx > 0)
        {
            return D_40049434 + D_40049444; /* atanhi[3] + atanlo[3] */
        }
        else
        {
            return -D_40049434 - D_40049444;
        }
    }
    if (ix < 0x3ee00000) /* |x| < 0.4375 */
    {
        if (ix < 0x31000000) /* |x| < 2^-29 */
        {
            if (huge + x > one)
            {
                return x; /* raise inexact */
            }
        }
        id = -1;
    }
    else
    {
        x = fabsf(x);
        if (ix < 0x3f980000) /* |x| < 1.1875 */
        {
            if (ix < 0x3f300000) /* 7/16 <= |x| < 11/16 */
            {
                id = 0;
                x = ((float)2.0 * x - one) / ((float)2.0 + x);
            }
            else /* 11/16 <= |x| < 19/16 */
            {
                id = 1;
                x = (x - one) / (x + one);
            }
        }
        else
        {
            if (ix < 0x401c0000) /* |x| < 2.4375 */
            {
                id = 2;
                x = (x - (float)1.5) / (one + (float)1.5 * x);
            }
            else /* 2.4375 <= |x| < 2^66 */
            {
                id = 3;
                x = -(float)1.0 / x;
            }
        }
    }
    /* end of argument reduction */
    z = x * x;
    w = z * z;
    /* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0)
    {
        return x - x * (s1 + s2);
    }
    else
    {
        z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
        return (hx < 0) ? -z : z;
    }
}
