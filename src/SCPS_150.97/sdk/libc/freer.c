#include "common.h"
#include <sys/reent.h>

/* newlib libc/stdlib/mallocr.c (Doug Lea malloc 2.6.x, reentrant newlib build).
   libc was built -G0: the malloc statics are reached through their D_ symbols. */

typedef unsigned int size_t;
#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT (SIZE_SZ + SIZE_SZ)
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

#define MAX_SMALLBIN 63
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

/* NEARMISS-STUB _free_r */
#if 0 /* NEARMISS 95.56% cat=sched sub=static-load-after-store | verbatim newlib free; top/head stores must precede the trim_threshold load (ours hoists it); same family as __do_global_dtors/__register_frame_info | attempts=2 */
/* newlib mallocr.c fREe verbatim (needs the freer.c mallocr header: idx2binblock with (unsigned long)1). 95.56: target stores top and the head before the trim_threshold ld; ours hoists the ld (strict aliasing); -fno-strict-aliasing orders them but shifts regs. */
void _free_r(RARG void *mem)
{
    mchunkptr p;            /* chunk corresponding to mem */
    INTERNAL_SIZE_T hd;     /* its head field */
    INTERNAL_SIZE_T sz;     /* its size */
    int idx;                /* its bin index */
    mchunkptr next;         /* next contiguous chunk */
    INTERNAL_SIZE_T nextsz; /* its size */
    INTERNAL_SIZE_T prevsz; /* size of previous contiguous chunk */
    mchunkptr bck;          /* misc temp for linking */
    mchunkptr fwd;          /* misc temp for linking */
    int islr;               /* track whether merging with last_remainder */

    if (mem == 0) /* free(0) has no effect */
        return;

    MALLOC_LOCK;

    p = mem2chunk(mem);
    hd = p->size;

    check_inuse_chunk(p);

    sz = hd & ~PREV_INUSE;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);

    if (next == top) /* merge with top */
    {
        sz += nextsz;

        if (!(hd & PREV_INUSE)) /* consolidate backward */
        {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -prevsz);
            sz += prevsz;
            unlink(p, bck, fwd);
        }

        set_head(p, sz | PREV_INUSE);
        top = p;
        if ((unsigned long)(sz) >= (unsigned long)trim_threshold)
            malloc_trim(RCALL top_pad);
        MALLOC_UNLOCK;
        return;
    }

    set_head(next, nextsz); /* clear inuse bit */

    islr = 0;

    if (!(hd & PREV_INUSE)) /* consolidate backward */
    {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -prevsz);
        sz += prevsz;

        if (p->fd == last_remainder) /* keep as last_remainder */
            islr = 1;
        else
            unlink(p, bck, fwd);
    }

    if (!(inuse_bit_at_offset(next, nextsz))) /* consolidate forward */
    {
        sz += nextsz;

        if (!islr && next->fd == last_remainder) /* re-insert last_remainder */
        {
            islr = 1;
            link_last_remainder(p);
        }
        else
            unlink(next, bck, fwd);
    }

    set_head(p, sz | PREV_INUSE);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);

    MALLOC_UNLOCK;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/freer", _free_r);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/freer", _malloc_trim_r);
int _malloc_trim_r(RARG size_t pad)
{
    long top_size;     /* Amount of top-most memory */
    long extra;        /* Amount to release */
    char *current_brk; /* address returned by pre-check sbrk call */
    char *new_brk;     /* address returned by negative sbrk call */

    unsigned long pagesz = malloc_getpagesize;

    MALLOC_LOCK;

    top_size = chunksize(top);
    extra = ((top_size - pad - MINSIZE + (pagesz - 1)) / pagesz - 1) * pagesz;

    if (extra < (long)pagesz) /* Not enough memory to release */
    {
        MALLOC_UNLOCK;
        return 0;
    }

    else
    {
        /* Test to make sure no one else called sbrk */
        current_brk = (char *)(MORECORE(0));
        if (current_brk != (char *)(top) + top_size)
        {
            MALLOC_UNLOCK;
            return 0; /* Apparently we don't own memory; must fail */
        }

        else
        {
            new_brk = (char *)(MORECORE(-extra));

            if (new_brk == (char *)(MORECORE_FAILURE)) /* sbrk failed? */
            {
                /* Try to figure out what we have */
                current_brk = (char *)(MORECORE(0));
                top_size = current_brk - (char *)top;
                if (top_size >= (long)MINSIZE) /* if not, we are very very dead! */
                {
                    sbrked_mem = current_brk - sbrk_base;
                    set_head(top, top_size | PREV_INUSE);
                }
                check_chunk(top);
                MALLOC_UNLOCK;
                return 0;
            }

            else
            {
                /* Success. Adjust top accordingly. */
                set_head(top, (top_size - extra) | PREV_INUSE);
                sbrked_mem -= extra;
                check_chunk(top);
                MALLOC_UNLOCK;
                return 1;
            }
        }
    }
}
