#include "common.h"

typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
typedef unsigned long long UDItype;
typedef float SFtype;
typedef double DFtype;

#define WORD_SIZE (sizeof(SItype) * 8)
#define HIGH_HALFWORD_COEFF (((UDItype)1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((UDItype)1) << WORD_SIZE)

#define DI_SIZE (sizeof(DItype) * 8)
#define DF_SIZE 53
#define SF_SIZE 24

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__floatdisf", __floatdisf);
SFtype __floatdisf(DItype u)
{
    /* Do the calculation in DFmode
       so that we don't lose any of the precision of the high word
       while multiplying it.  */
    DFtype f;

    /* Protect against double-rounding error.  */
    if (DF_SIZE < DI_SIZE && DF_SIZE > (DI_SIZE - DF_SIZE + SF_SIZE))
    {
#define REP_BIT ((UDItype)1 << (DI_SIZE - DF_SIZE))
        if (!(-((DItype)1 << DF_SIZE) < u && u < ((DItype)1 << DF_SIZE)))
        {
            if ((UDItype)u & (REP_BIT - 1))
                u |= REP_BIT;
        }
    }
    f = (SItype)(u >> WORD_SIZE);
    f *= HIGH_HALFWORD_COEFF;
    f *= HIGH_HALFWORD_COEFF;
    f += (USItype)(u & (HIGH_WORD_COEFF - 1));

    return (SFtype)f;
}
