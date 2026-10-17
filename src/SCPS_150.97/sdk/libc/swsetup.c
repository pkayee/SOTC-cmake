#include "common.h"
#include <sys/reent.h>
#include <stdio.h>

void __sinit(struct _reent *s);
void __smakebuf(FILE *fp);
void _free_r(struct _reent *ptr, void *mem);

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

#define HASUB(fp) ((fp)->_ub._base != NULL)
#define FREEUB(fp) \
    { \
        if ((fp)->_ub._base != (fp)->_ubuf) \
            _free_r(fp->_data, (char *)(fp)->_ub._base); \
        (fp)->_ub._base = NULL; \
    }

/*
 * Various output routines call wsetup to be sure it is safe to write,
 * because either _flags does not include __SWR, or _buf is NULL.
 * _wsetup returns 0 if OK to write, nonzero otherwise.
 */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/swsetup", __swsetup);
int __swsetup(register FILE *fp)
{
    /* Make sure stdio is set up.  */

    CHECK_INIT(fp);

    /*
     * If we are not writing, we had better be reading and writing.
     */

    if ((fp->_flags & __SWR) == 0)
    {
        if ((fp->_flags & __SRW) == 0)
            return EOF;
        if (fp->_flags & __SRD)
        {
            /* clobber any ungetc data */
            if (HASUB(fp))
                FREEUB(fp);
            fp->_flags &= ~(__SRD | __SEOF);
            fp->_r = 0;
            fp->_p = fp->_bf._base;
        }
        fp->_flags |= __SWR;
    }

    /*
     * Make a buffer if necessary, then set _w.
     */
    if (fp->_bf._base == NULL)
        __smakebuf(fp);

    if (fp->_flags & __SLBF)
    {
        /*
         * It is line buffered, so make _lbfsize be -_bufsize
         * for the putc() macro.  We will change _lbfsize back
         * to 0 whenever we turn off __SWR.
         */
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf._size;
    }
    else
        fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;
    return 0;
}
