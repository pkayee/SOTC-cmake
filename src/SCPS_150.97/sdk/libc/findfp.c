#include "common.h"
#include <stdio.h>
#include <sys/reent.h>

extern int _fwalk(struct _reent *ptr, int (*func)(FILE *));
void __sinit(struct _reent *s);

extern int __sread(void *cookie, char *buf, int n);
extern int __swrite(void *cookie, char *buf, int n);
extern _fpos_t __sseek(void *cookie, _fpos_t offset, int whence);
extern int __sclose(void *cookie);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", std);
void std(FILE *ptr, int flags, int file, struct _reent *data)
{
    ptr->_p = 0;
    ptr->_r = 0;
    ptr->_w = 0;
    ptr->_flags = flags;
    ptr->_file = file;
    ptr->_bf._base = 0;
    ptr->_bf._size = 0;
    ptr->_lbfsize = 0;
    ptr->_cookie = ptr;
    ptr->_read = __sread;
    ptr->_write = __swrite;
    ptr->_seek = __sseek;
    ptr->_close = __sclose;
    ptr->_data = data;
}

extern void *_malloc_r(struct _reent *ptr, size_t size);
extern void *memset(void *s, int c, size_t n);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", __sfmoreglue);
struct _glue *__sfmoreglue(struct _reent *d, int n)
{
    struct _glue *g;
    FILE *iobs;

    g = _malloc_r(d, n * sizeof(FILE) + sizeof(struct _glue));
    if (g == NULL)
    {
        return NULL;
    }
    g->_niobs = n;
    g->_next = NULL;
    iobs = (FILE *)(g + 1);
    g->_iobs = iobs;
    memset(iobs, 0, n * sizeof(FILE));
    return g;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", __sfp);
FILE *__sfp(struct _reent *d)
{
    struct _glue *g;
    FILE *fp;
    int n;

    if (d->__sdidinit == 0)
    {
        __sinit(d);
    }
    for (g = &d->__sglue;; g = g->_next)
    {
        fp = g->_iobs;
        for (n = g->_niobs; --n >= 0;)
        {
            if (fp->_flags == 0)
            {
                goto found;
            }
            fp++;
        }
        if (g->_next == NULL)
        {
            g->_next = __sfmoreglue(d, 4);
            if (g->_next == NULL)
            {
                d->_errno = 12;
                return NULL;
            }
        }
    }
found:
    fp->_flags = 1;
    fp->_file = -1;
    fp->_data = d;
    fp->_p = 0;
    fp->_w = 0;
    fp->_r = 0;
    fp->_bf._base = 0;
    fp->_bf._size = 0;
    fp->_lbfsize = 0;
    fp->_ub._base = 0;
    fp->_ub._size = 0;
    fp->_lb._base = 0;
    fp->_lb._size = 0;
    return fp;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", _cleanup_r);
void _cleanup_r(struct _reent *ptr)
{
    _fwalk(ptr, fflush);
}

extern struct _reent *D_00135D60[];

void _cleanup(void)
{
    _cleanup_r(D_00135D60[0]);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", _cleanup);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/findfp", __sinit);
