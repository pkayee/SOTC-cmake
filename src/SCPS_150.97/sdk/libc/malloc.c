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

#include <sys/reent.h>

/* newlib libc/stdlib/mallocr.c (Doug Lea malloc 2.6.x, reentrant newlib build).
   libc was built -G0: the malloc statics are reached through their D_ symbols. */

typedef unsigned int size_t;
#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT 16 /* EE: 128-bit alignment */
#define MALLOC_ALIGN MALLOC_ALIGNMENT
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define MINSIZE (sizeof(struct malloc_chunk))

#define RARG struct _reent *reent_ptr,
#define RONEARG struct _reent *reent_ptr
#define RCALL reent_ptr,
#define RONECALL reent_ptr

#define MALLOC_LOCK __malloc_lock(reent_ptr)
#define MALLOC_UNLOCK __malloc_unlock(reent_ptr)

void __malloc_lock(struct _reent *);
void __malloc_unlock(struct _reent *);
void *_sbrk_r(struct _reent *, int);

#define MORECORE(size) _sbrk_r(RCALL(size))
#define MORECORE_FAILURE -1

#define malloc_getpagesize (4096)

struct malloc_chunk
{
    INTERNAL_SIZE_T prev_size; /* Size of previous chunk (if free). */
    INTERNAL_SIZE_T size;      /* Size in bytes, including overhead. */
    struct malloc_chunk *fd;   /* double links -- used only if free. */
    struct malloc_chunk *bk;
};

typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)

#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define set_head(p, s) ((p)->size = (s))

extern mbinptr D_00135D68[];
#define av_ D_00135D68
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define top (bin_at(0)->fd)

extern char *D_00136180[];
#define sbrk_base (*D_00136180)

struct mallinfo
{
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};
extern struct mallinfo D_00136198[];
#define current_mallinfo (*D_00136198)
#define sbrked_mem (current_mallinfo.arena)

#define check_chunk(P)

#define mem2chunk(mem) ((mchunkptr)((char *)(mem)-2 * SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size & PREV_INUSE)
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define check_inuse_chunk(P)

#define unlink(P, BK, FD) \
    { \
        BK = P->bk; \
        FD = P->fd; \
        FD->bk = BK; \
        BK->fd = FD; \
    }

#define last_remainder (bin_at(1))

#define link_last_remainder(P) \
    { \
        last_remainder->fd = last_remainder->bk = P; \
        P->fd = P->bk = last_remainder; \
    }

#define MAX_SMALLBIN (MAX_SMALLBIN_SIZE / SMALLBIN_WIDTH) - 1
#define MAX_SMALLBIN_SIZE 512
#define SMALLBIN_WIDTH 8
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
    (((((unsigned long)(sz)) >> 9) == 0) ? (((unsigned long)(sz)) >> 3) : \
     ((((unsigned long)(sz)) >> 9) <= 4) ? 56 + (((unsigned long)(sz)) >> 6) : \
     ((((unsigned long)(sz)) >> 9) <= 20) ? 91 + (((unsigned long)(sz)) >> 9) : \
     ((((unsigned long)(sz)) >> 9) <= 84) ? 110 + (((unsigned long)(sz)) >> 12) : \
     ((((unsigned long)(sz)) >> 9) <= 340) ? 119 + (((unsigned long)(sz)) >> 15) : \
     ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18) : \
                                              126)

#define BINBLOCKWIDTH 4 /* bins per block */
#define binblocks (bin_at(0)->size) /* bitvector of nonempty blocks */
#define idx2binblock(ix) ((unsigned long)1 << (ix / BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))

#define frontlink(P, S, IDX, BK, FD) \
    { \
        if (S < MAX_SMALLBIN_SIZE) \
        { \
            IDX = smallbin_index(S); \
            mark_binblock(IDX); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } \
        else \
        { \
            IDX = bin_index(S); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            if (FD == BK) \
                mark_binblock(IDX); \
            else \
            { \
                while (FD != BK && S < chunksize(FD)) \
                    FD = FD->fd; \
                BK = FD->bk; \
            } \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } \
    }

extern unsigned long D_00136170[];
#define trim_threshold (*D_00136170)
extern unsigned long D_00136178[];
#define top_pad (*D_00136178)

#define malloc_trim _malloc_trim_r
int _malloc_trim_r(RARG size_t pad);

/* newlib mallocr.c malloc_extend_top (static; the split names it func_00127908) */
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define initial_top ((mchunkptr)(bin_at(0)))
#define POINTER_UINT unsigned long
#define assert(x)

extern unsigned long D_00136188[];
#define max_sbrked_mem (*D_00136188)
extern unsigned long D_00136190[];
#define max_total_mem (*D_00136190)

void _free_r(struct _reent *, void *);
#define fREe _free_r

/* gcc: malloc_extend_top */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", func_00127908);
void func_00127908(RARG INTERNAL_SIZE_T nb)
{
    char *brk;                      /* return value from sbrk */
    INTERNAL_SIZE_T front_misalign; /* unusable bytes at front of sbrked space */
    INTERNAL_SIZE_T correction;     /* bytes for 2nd sbrk call */
    char *new_brk;                  /* return of 2nd sbrk call */
    INTERNAL_SIZE_T top_size;       /* new size of top chunk */

    mchunkptr old_top = top; /* Record state of old top */
    INTERNAL_SIZE_T old_top_size = chunksize(old_top);
    char *old_end = (char *)(chunk_at_offset(old_top, old_top_size));

    /* Pad request with top_pad plus minimal overhead */

    INTERNAL_SIZE_T sbrk_size = nb + top_pad + MINSIZE;
    unsigned long pagesz = malloc_getpagesize;

    /* If not the first time through, round to preserve page boundary */
    /* Otherwise, we need to correct to a page size below anyway. */
    /* (We also correct below if an intervening foreign sbrk call.) */

    if (sbrk_base != (char *)(-1))
        sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);

    brk = (char *)(MORECORE(sbrk_size));

    /* Fail if sbrk failed or if a foreign sbrk call killed our space */
    if (brk == (char *)(MORECORE_FAILURE) || (brk < old_end && old_top != initial_top))
        return;

    sbrked_mem += sbrk_size;

    if (brk == old_end) /* can just add bytes to current top */
    {
        top_size = sbrk_size + old_top_size;
        set_head(top, top_size | PREV_INUSE);
    }
    else
    {
        if (sbrk_base == (char *)(-1)) /* First time through. Record base */
            sbrk_base = brk;
        else /* Someone else called sbrk().  Count those bytes as sbrked_mem. */
            sbrked_mem += brk - (char *)old_end;

        /* Guarantee alignment of first new chunk made from this space */
        front_misalign = (POINTER_UINT)chunk2mem(brk) & MALLOC_ALIGN_MASK;
        if (front_misalign > 0)
        {
            correction = (MALLOC_ALIGNMENT)-front_misalign;
            brk += correction;
        }
        else
            correction = 0;

        /* Guarantee the next brk will be at a page boundary */
        correction += pagesz - ((POINTER_UINT)(brk + sbrk_size) & (pagesz - 1));

        /* Allocate correction */
        new_brk = (char *)(MORECORE(correction));
        if (new_brk == (char *)(MORECORE_FAILURE))
            return;

        sbrked_mem += correction;

        top = (mchunkptr)brk;
        top_size = new_brk - brk + correction;
        set_head(top, top_size | PREV_INUSE);

        if (old_top != initial_top)
        {

            /* There must have been an intervening foreign sbrk call. */
            /* A double fencepost is necessary to prevent consolidation */

            /* If not enough space to do this, then user did something very wrong */
            if (old_top_size < MINSIZE)
            {
                set_head(top, PREV_INUSE); /* will force null return from malloc */
                return;
            }

            /* Also keep size a multiple of MALLOC_ALIGNMENT */
            old_top_size = (old_top_size - 3 * SIZE_SZ) & ~MALLOC_ALIGN_MASK;
            set_head_size(old_top, old_top_size);
            chunk_at_offset(old_top, old_top_size)->size = SIZE_SZ | PREV_INUSE;
            chunk_at_offset(old_top, old_top_size + SIZE_SZ)->size = SIZE_SZ | PREV_INUSE;
            /* If possible, release the rest. */
            if (old_top_size >= MINSIZE)
                fREe(RCALL chunk2mem(old_top));
        }
    }

    if ((unsigned long)sbrked_mem > (unsigned long)max_sbrked_mem)
        max_sbrked_mem = sbrked_mem;
    if ((unsigned long)(sbrked_mem) > (unsigned long)max_total_mem)
        max_total_mem = sbrked_mem;

    /* We always land on a page boundary */
    assert(((unsigned long)((char *)top + top_size) & (pagesz - 1)) == 0);
}
