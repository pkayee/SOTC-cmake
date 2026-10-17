#include "common.h"
#include <stdlib.h>
#include <malloc.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];
void __malloc_lock(struct _reent *ptr);
void __malloc_unlock(struct _reent *ptr);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", atoi);
int atoi(const char *s)
{
    return strtol(s, NULL, 10);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", __errno);
struct _reent *__errno(void)
{
    return D_00135D60[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", memalign);
void *memalign(size_t align, size_t nbytes)
{
    void *ret;

    __malloc_lock(D_00135D60[0]);
    ret = _memalign_r(D_00135D60[0], align, nbytes);
    __malloc_unlock(D_00135D60[0]);
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", _memalign_r);
