#include "common.h"
#include <ctype.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/_strtol_r", _strtol_r);
long _strtol_r(struct _reent *ptr, const char *nptr, char **endptr, int base)
{
    const char *s;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg;
    int any;
    int cutlim;

    neg = 0;
    s = nptr;
    do
    {
        c = *s++;
    } while (isspace(c));
    if (c == '-')
    {
        neg = 1;
        c = *s++;
    }
    else if (c == '+')
    {
        c = *s++;
    }
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
    {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
    {
        base = c == '0' ? 8 : 10;
    }
    cutoff = neg ? 0x8000000000000000UL : 0x7fffffffffffffffUL;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++)
    {
        if (isdigit(c))
        {
            c -= '0';
        }
        else if (isalpha(c))
        {
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        }
        else
        {
            break;
        }
        if (c >= base)
        {
            break;
        }
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
        {
            any = -1;
        }
        else
        {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0)
    {
        acc = neg ? 0x8000000000000000UL : 0x7fffffffffffffffUL;
        ptr->_errno = 34;
    }
    else if (neg)
    {
        acc = -acc;
    }
    if (endptr != 0)
    {
        *endptr = (char *)(any ? s - 1 : nptr);
    }
    return acc;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/_strtol_r", strtol);
