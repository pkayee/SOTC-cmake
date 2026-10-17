#include "common.h"
#include <sys/reent.h>
#include <stdio.h>
#include <sys/stat.h>

int _fstat_r(struct _reent *ptr, int fd, struct stat *st);
void *_malloc_r(struct _reent *ptr, size_t size);
void _cleanup_r(struct _reent *ptr);
int isatty(int fd);
fpos_t __sseek(void *cookie, fpos_t offset, int whence);
#define _isatty isatty

/*
 * Allocate a file buffer, or switch to unbuffered I/O.
 * Per the ANSI C standard, ALL tty devices default to line buffered.
 *
 * As a side effect, we set __SOPT or __SNPT (en/dis-able fseek
 * optimisation) right after the _fstat() that finds the buffer size.
 */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/makebuf", __smakebuf);
void __smakebuf(register FILE *fp)
{
    register size_t size, couldbetty;
    register void *p;
    struct stat st;

    if (fp->_flags & __SNBF)
    {
        fp->_bf._base = fp->_p = fp->_nbuf;
        fp->_bf._size = 1;
        return;
    }
    if (fp->_file < 0 || _fstat_r(fp->_data, fp->_file, &st) < 0)
    {
        couldbetty = 0;
        size = BUFSIZ;
        /* do not try to optimise fseek() */
        fp->_flags |= __SNPT;
    }
    else
    {
        couldbetty = (st.st_mode & S_IFMT) == S_IFCHR;
        size = BUFSIZ;
        /*
         * Optimize fseek() only if it is a regular file.
         * (The test for __sseek is mainly paranoia.)
         */
        if ((st.st_mode & S_IFMT) == S_IFREG && fp->_seek == __sseek)
        {
            fp->_flags |= __SOPT;
            fp->_blksize = 1024;
        }
        else
            fp->_flags |= __SNPT;
    }
    if ((p = _malloc_r(fp->_data, size)) == NULL)
    {
        fp->_flags |= __SNBF;
        fp->_bf._base = fp->_p = fp->_nbuf;
        fp->_bf._size = 1;
    }
    else
    {
        fp->_data->__cleanup = _cleanup_r;
        fp->_flags |= __SMBF;
        fp->_bf._base = fp->_p = (unsigned char *)p;
        fp->_bf._size = size;
        if (couldbetty && _isatty(fp->_file))
            fp->_flags |= __SLBF;
    }
}
