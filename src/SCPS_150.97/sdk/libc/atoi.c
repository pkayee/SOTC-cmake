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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atoi", _memalign_r);
/* newlib mallocr.c mEMALIGn (EE: MALLOC_ALIGNMENT 16, no mmap) */
typedef unsigned int INTERNAL_SIZE_T;
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
struct malloc_chunk
{
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};
typedef struct malloc_chunk *mchunkptr;
#define MINSIZE (sizeof(struct malloc_chunk))
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define mem2chunk(mem) ((mchunkptr)((char *)(mem)-2 * SIZE_SZ))
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define long_sub_size_t(x, y) (sizeof(long) > sizeof(INTERNAL_SIZE_T) && x < y ? -(long)(y - x) : (long)(x - y))
#define request2size(req) \
    (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
      (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
     (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define check_inuse_chunk(P)
#define assert(x)

void _free_r(struct _reent *, void *);

void *_memalign_r(struct _reent *reent_ptr, unsigned int alignment, unsigned int bytes)
{
    INTERNAL_SIZE_T nb;       /* padded  request size */
    char *m;                  /* memory returned by malloc call */
    mchunkptr p;              /* corresponding chunk */
    char *brk;                /* alignment point within p */
    mchunkptr newp;           /* chunk to return */
    INTERNAL_SIZE_T newsize;  /* its size */
    INTERNAL_SIZE_T leadsize; /* leading space befor alignment point */
    mchunkptr remainder;      /* spare room at end to split off */
    long remainder_size;      /* its size */

    /* If need less alignment than we give anyway, just relay to malloc */

    if (alignment <= MALLOC_ALIGNMENT)
        return _malloc_r(reent_ptr, bytes);

    /* Otherwise, ensure that it is at least a minimum chunk size */

    if (alignment < MINSIZE)
        alignment = MINSIZE;

    /* Call malloc with worst case padding to hit alignment. */

    nb = request2size(bytes);
    m = (char *)(_malloc_r(reent_ptr, nb + alignment + MINSIZE));

    if (m == 0)
        return 0; /* propagate failure */

    __malloc_lock(reent_ptr);

    p = mem2chunk(m);

    if ((((unsigned long)(m)) % alignment) == 0) /* aligned */
    {
    }
    else /* misaligned */
    {
        brk = (char *)mem2chunk(((unsigned long)(m + alignment - 1)) & -alignment);
        if ((long)(brk - (char *)(p)) < (long)MINSIZE)
            brk = brk + alignment;

        newp = (mchunkptr)brk;
        leadsize = brk - (char *)(p);
        newsize = chunksize(p) - leadsize;

        /* give back leader, use the rest */

        set_head(newp, newsize | PREV_INUSE);
        set_inuse_bit_at_offset(newp, newsize);
        set_head_size(p, leadsize);
        _free_r(reent_ptr, chunk2mem(p));
        p = newp;

        assert(newsize >= nb && (((unsigned long)(chunk2mem(p))) % alignment) == 0);
    }

    /* Also give back spare room at the end */

    remainder_size = long_sub_size_t(chunksize(p), nb);

    if (remainder_size >= (long)MINSIZE)
    {
        remainder = chunk_at_offset(p, nb);
        set_head(remainder, remainder_size | PREV_INUSE);
        set_head_size(p, nb);
        _free_r(reent_ptr, chunk2mem(remainder));
    }

    check_inuse_chunk(p);
    __malloc_unlock(reent_ptr);
    return chunk2mem(p);
}
