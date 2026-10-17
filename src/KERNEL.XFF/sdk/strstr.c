#include "common.h"

char *strstr(const char *s1, const char *s2)
{
    const signed char *p;
    s32 i;

    if (*s1 == 0)
    {
        return (*s2 == 0) ? (char *)s1 : NULL;
    }
    p = (const signed char *)s1;
    do
    {
        for (i = 0;; i++)
        {
            if (s2[i] == 0)
            {
                return (char *)p;
            }
            if (s2[i] != p[i])
            {
                break;
            }
        }
        p++;
    } while (*p != 0);
    return NULL;
}
