#include "common.h"
#include <sys/reent.h>

extern s32 D_0013A30C[];

void *sbrk(s32 incr);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sbrkr", _sbrk_r);
void *_sbrk_r(struct _reent *ptr, s32 incr)
{
    void *ret;

    D_0013A30C[0] = 0;
    ret = sbrk(incr);
    if (ret == (void *)-1)
    {
        if (D_0013A30C[0] != 0)
        {
            ptr->_errno = D_0013A30C[0];
        }
    }
    return ret;
}
