#include "common.h"
#include <sys/reent.h>

extern s32 D_0013A30C[];

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _write_r);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _calloc_r);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _close_r);
int close(s32 fd);

s32 _close_r(struct _reent *ptr, s32 fd)
{
    s32 ret;

    D_0013A30C[0] = 0;
    ret = close(fd);
    if (ret == -1 && D_0013A30C[0] != 0)
    {
        ptr->_errno = D_0013A30C[0];
    }
    return ret;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _fstat_r);
int fstat(s32 fd, void *st);

s32 _fstat_r(struct _reent *ptr, s32 fd, void *st)
{
    s32 ret;

    D_0013A30C[0] = 0;
    ret = fstat(fd, st);
    if (ret == -1 && D_0013A30C[0] != 0)
    {
        ptr->_errno = D_0013A30C[0];
    }
    return ret;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _lseek_r);
long lseek(s32 fd, long offset, s32 whence);

long _lseek_r(struct _reent *ptr, s32 fd, long offset, s32 whence)
{
    long ret;

    D_0013A30C[0] = 0;
    ret = lseek(fd, offset, whence);
    if (ret == -1 && D_0013A30C[0] != 0)
    {
        ptr->_errno = D_0013A30C[0];
    }
    return ret;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _read_r);


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _realloc_r);
