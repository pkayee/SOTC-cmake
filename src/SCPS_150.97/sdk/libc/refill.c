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

int fflush(FILE *fp);
int _fwalk(struct _reent *ptr, int (*function)(FILE *));

/* lflush (static in refill.c; the split put it in another TU) */
#define lflush func_0012F900
int lflush(FILE *fp);

/*
 * Refill a stdio buffer.
 * Return EOF on eof or error, 0 otherwise.
 */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/refill", __srefill);
int __srefill(register FILE *fp)
{
    /* make sure stdio is set up */

    CHECK_INIT(fp);

    fp->_r = 0; /* largely a convenience for callers */

    /* SysV does not make this test; take it out for compatibility */
    if (fp->_flags & __SEOF)
        return EOF;

    /* if not already reading, have to be reading and writing */
    if ((fp->_flags & __SRD) == 0)
    {
        if ((fp->_flags & __SRW) == 0)
            return EOF;
        /* switch to reading */
        if (fp->_flags & __SWR)
        {
            if (fflush(fp))
                return EOF;
            fp->_flags &= ~__SWR;
            fp->_w = 0;
            fp->_lbfsize = 0;
        }
        fp->_flags |= __SRD;
    }
    else
    {
        /*
         * We were reading.  If there is an ungetc buffer,
         * we must have been reading from that.  Drop it,
         * restoring the previous buffer (if any).  If there
         * is anything in that buffer, return.
         */
        if (HASUB(fp))
        {
            FREEUB(fp);
            if ((fp->_r = fp->_ur) != 0)
            {
                fp->_p = fp->_up;
                return 0;
            }
        }
    }

    if (fp->_bf._base == NULL)
        __smakebuf(fp);

    /*
     * Before reading from a line buffered or unbuffered file,
     * flush all line buffered output files, per the ANSI C
     * standard.
     */

    if (fp->_flags & (__SLBF | __SNBF))
        (void)_fwalk(fp->_data, lflush);

    fp->_p = fp->_bf._base;
    fp->_r = (*fp->_read)(fp->_cookie, (char *)fp->_p, fp->_bf._size);
    fp->_flags &= ~__SMOD; /* buffer contents are again pristine */
    if (fp->_r <= 0)
    {
        if (fp->_r == 0)
            fp->_flags |= __SEOF;
        else
        {
            fp->_r = 0;
            fp->_flags |= __SERR;
        }
        return EOF;
    }
    return 0;
}
