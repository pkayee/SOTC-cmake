#include "common.h"
#include <sys/reent.h>
#include <stdio.h>

void __sinit(struct _reent *s);
int _fwalk(struct _reent *ptr, int (*function)(FILE *));

extern struct _reent *D_00135D60[];
/* -G0 libc: _impure_ptr is reached through its unsized D_ symbol */
#define _impure_ptr (*D_00135D60)

/* Called by the main entry point fns to ensure stdio has been initialized.  */

#define CHECK_INIT(fp) \
    do \
    { \
        if ((fp)->_data == 0) \
            (fp)->_data = _REENT; \
        if (!(fp)->_data->__sdidinit) \
            __sinit((fp)->_data); \
    } while (0)

/* Flush a single file, or (if fp is NULL) all files.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/fflush", fflush);
int fflush(register FILE *fp)
{
    register unsigned char *p;
    register int n, t;

    if (fp == NULL)
        return _fwalk(_REENT, fflush);

    CHECK_INIT(fp);

    t = fp->_flags;
    if ((t & __SWR) == 0 || (p = fp->_bf._base) == NULL)
        return 0;
    n = fp->_p - p; /* write this much */

    /*
     * Set these immediately to avoid problems with longjmp
     * and to allow exchange buffering (via setvbuf) in user
     * write function.
     */
    fp->_p = p;
    fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;

    while (n > 0)
    {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0)
        {
            fp->_flags |= __SERR;
            return EOF;
        }
        p += t;
        n -= t;
    }
    return 0;
}
