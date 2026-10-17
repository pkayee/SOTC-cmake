#include "common.h"
#include <stdlib.h>
#include <sys/reent.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atol", atol);
long atol(const char *s)
{
    return strtol(s, NULL, 10);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atol", func_0012C340);
typedef int Long;
typedef unsigned int ULong;
typedef struct _Bigint _Jv_Bigint;

#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
#define Sign_Extend(a, b) /*no-op*/

int __mcmp(_Jv_Bigint *a, _Jv_Bigint *b);
#define cmp __mcmp

int func_0012C340(_Jv_Bigint *b, _Jv_Bigint *S)
{
    int n;
    Long borrow, y;
    ULong carry, q, ys;
    ULong *bx, *bxe, *sx, *sxe;
    Long z;
    ULong si, zs;

    n = S->_wds;
    if (b->_wds < n)
        return 0;
    sx = S->_x;
    sxe = sx + --n;
    bx = b->_x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1); /* ensure q <= true quotient */
    if (q)
    {
        borrow = 0;
        carry = 0;
        do
        {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend(borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend(borrow, z);
            Storeinc(bx, z, y);
        } while (sx <= sxe);
        if (!*bxe)
        {
            bx = b->_x;
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    if (cmp(b, S) >= 0)
    {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->_x;
        sx = S->_x;
        do
        {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend(borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend(borrow, z);
            Storeinc(bx, z, y);
        } while (sx <= sxe);
        bx = b->_x;
        bxe = bx + n;
        if (!*bxe)
        {
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    return q;
}
