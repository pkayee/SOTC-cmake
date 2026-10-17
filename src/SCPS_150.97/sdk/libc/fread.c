#include "common.h"
#include <sys/reent.h>
#include <string.h>
#include <stdio.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/fread", fread);
size_t fread(void *buf, size_t size, size_t count, FILE *fp)
{
    size_t resid;
    size_t total;
    char *p;
    int r;

    resid = count * size;
    if (resid == 0)
    {
        return 0;
    }
    if (fp->_r < 0)
    {
        fp->_r = 0;
    }
    total = resid;
    r = fp->_r;
    p = buf;
    while ((size_t)r < resid)
    {
        memcpy(p, fp->_p, r);
        fp->_p += r;
        resid -= r;
        p += r;
        if (__srefill(fp))
        {
            return (total - resid) / size;
        }
        r = fp->_r;
    }
    memcpy(p, fp->_p, resid);
    fp->_r -= resid;
    fp->_p += resid;
    return count;
}
