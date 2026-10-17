#include "common.h"

extern struct _reent *D_00135D60[];
void __malloc_lock();
void __malloc_unlock();
void *_malloc_r(struct _reent *ptr, u32 nbytes);
void _free_r(struct _reent *ptr, void *p);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", malloc);
void *malloc(u32 nbytes)
{
    void *ret;

    __malloc_lock(D_00135D60[0]);
    ret = _malloc_r(D_00135D60[0], nbytes);
    __malloc_unlock(D_00135D60[0]);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", free);
void free(void *p)
{
    __malloc_lock(D_00135D60[0]);
    _free_r(D_00135D60[0], p);
    __malloc_unlock(D_00135D60[0]);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", func_00127908);
