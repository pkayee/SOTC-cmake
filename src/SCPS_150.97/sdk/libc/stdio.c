#include "common.h"
#include <stdio.h>
#include <sys/reent.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/stdio", __sread);
int __sread(void *cookie, char *buf, int n)
{
    FILE *fp = (FILE *)cookie;
    long r;
    int ret;

    r = _read_r(fp->_data, fp->_file, buf, n);
    ret = r;
    if (ret >= 0)
    {
        fp->_offset += ret;
    }
    else
    {
        fp->_flags &= ~__SOFF;
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/stdio", __swrite);
int __swrite(void *cookie, char *buf, int n)
{
    FILE *fp = (FILE *)cookie;
    long r;
    int ret;

    if (fp->_flags & __SAPP)
    {
        _lseek_r(fp->_data, fp->_file, 0, 2);
    }
    fp->_flags &= ~__SOFF;
    r = _write_r(fp->_data, fp->_file, buf, n);
    ret = r;
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/stdio", __sseek);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/stdio", __sclose);
int __sclose(void *cookie)
{
    FILE *fp = (FILE *)cookie;

    return _close_r(fp->_data, fp->_file);
}
