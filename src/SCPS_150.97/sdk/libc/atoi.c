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

/* NEARMISS-STUB _memalign_r */
#if 0 /* NEARMISS 78.5% cat=regalloc sub=- | callee-saved s2/s3/s4 assignment and arg-reg moves differ; alignment-branch layout (beqzl) differs; best 78.5% single-function attempt | attempts=1 */
void *_memalign_r(struct _reent *ptr, size_t alignment, size_t bytes)
{
    size_t nb;
    char *p;
    struct malloc_chunk *mem;
    struct malloc_chunk *brk;
    struct malloc_chunk *next;
    s32 remainder;
    s32 lead;

    if (alignment <= 16)
    {
        return _malloc_r(ptr, bytes);
    }
    if (alignment < 16)
    {
        alignment = 16;
    }
    if (bytes + 19 < 31)
    {
        nb = 16;
    }
    else
    {
        nb = (bytes + 19) & -16;
    }
    p = _malloc_r(ptr, nb + alignment + 16);
    if (p == NULL)
    {
        return p;
    }
    __malloc_lock(ptr);
    mem = (struct malloc_chunk *)(p - 8);
    if ((unsigned long)p % (unsigned long)alignment)
    {
        brk = (struct malloc_chunk *)((((size_t)p + alignment - 1) & -alignment) - 8);
        lead = (char *)brk - (char *)mem;
        brk = (struct malloc_chunk *)((char *)brk + (lead < 16) * alignment);
        lead = (char *)brk - (char *)mem;
        remainder = (mem->head & -4) - lead;
        brk->head = remainder | 1;
        next = (struct malloc_chunk *)((char *)brk + remainder);
        next->head |= 1;
        mem->head = (mem->head & 1) | lead;
        _free_r(ptr, p);
        mem = brk;
    }
    remainder = (mem->head & -4) - nb;
    if (remainder >= 16)
    {
        next = (struct malloc_chunk *)((char *)mem + nb);
        next->head = remainder | 1;
        mem->head = (mem->head & 1) | nb;
        _free_r(ptr, (char *)next + 8);
    }
    __malloc_unlock(ptr);
    return (char *)mem + 8;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", _memalign_r);
