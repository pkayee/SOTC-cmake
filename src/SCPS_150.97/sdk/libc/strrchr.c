#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/strrchr", strrchr);
char *strrchr(const char *s, int c)
{
    const char *last = NULL;
    char ch = c;

    while (*s)
    {
        if (*s == ch)
        {
            last = s;
        }
        s++;
    }

    if (*s == ch)
    {
        return (char *)s;
    }
    return (char *)last;
}
