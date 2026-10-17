#include "common.h"
#include <sys/reent.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mbtowc_r", _mbtowc_r);
int _mbtowc_r(struct _reent *ptr, s32 *pwc, const char *s, size_t n)
{
    s32 tmp;
    s32 *p;

    p = (pwc != NULL) ? pwc : &tmp;
    if (s == NULL)
    {
        return 0;
    }
    if (n == 0)
    {
        return -1;
    }
    *p = (u8)*s;
    return (u8)*s != 0;
}
