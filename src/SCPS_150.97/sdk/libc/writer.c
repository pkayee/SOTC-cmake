#include "common.h"
#include <sys/reent.h>

extern s32 D_0013A30C[];
#define errno (*D_0013A30C)

int write(int fd, const void *buf, unsigned int cnt);
int read(int fd, void *buf, unsigned int cnt);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _write_r);
long _write_r(struct _reent *ptr, int fd, const void *buf, unsigned int cnt)
{
    long ret;

    errno = 0;
    if ((ret = (long)write(fd, buf, cnt)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _calloc_r);
/* newlib mallocr.c cALLOc (no MORECORE_CLEARS, no mmap) */
typedef unsigned int INTERNAL_SIZE_T;
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
struct malloc_chunk
{
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};
typedef struct malloc_chunk *mchunkptr;
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define mem2chunk(mem) ((mchunkptr)((char *)(mem)-2 * SIZE_SZ))
#define MALLOC_ZERO(charp, nbytes) \
    do \
    { \
        INTERNAL_SIZE_T mzsz = (nbytes); \
        if (mzsz <= 9 * sizeof(mzsz)) \
        { \
            INTERNAL_SIZE_T *mz = (INTERNAL_SIZE_T *)(charp); \
            if (mzsz >= 5 * sizeof(mzsz)) \
            { \
                *mz++ = 0; \
                *mz++ = 0; \
                if (mzsz >= 7 * sizeof(mzsz)) \
                { \
                    *mz++ = 0; \
                    *mz++ = 0; \
                    if (mzsz >= 9 * sizeof(mzsz)) \
                    { \
                        *mz++ = 0; \
                        *mz++ = 0; \
                    } \
                } \
            } \
            *mz++ = 0; \
            *mz++ = 0; \
            *mz = 0; \
        } \
        else \
            memset((charp), 0, mzsz); \
    } while (0)

void *_malloc_r(struct _reent *, unsigned int);
void *memset(void *, int, unsigned int);

void *_calloc_r(struct _reent *reent_ptr, unsigned int n, unsigned int elem_size)
{
    mchunkptr p;
    INTERNAL_SIZE_T csz;

    INTERNAL_SIZE_T sz = n * elem_size;

    void *mem;

    mem = _malloc_r(reent_ptr, sz);

    if (mem == 0)
    {
        return 0;
    }
    else
    {
        p = mem2chunk(mem);

        csz = chunksize(p);

        MALLOC_ZERO(mem, csz - SIZE_SZ);
        return mem;
    }
}

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


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _read_r);
long _read_r(struct _reent *ptr, int fd, void *buf, unsigned int cnt)
{
    long ret;

    errno = 0;
    if ((ret = (long)read(fd, buf, cnt)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _realloc_r);
/* newlib mallocr.c rEALLOc (EE config, no mmap; MALLOC_COPY ladder) */
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define MINSIZE (sizeof(struct malloc_chunk))
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define next_chunk(p) ((mchunkptr)(((char *)(p)) + ((p)->size & ~PREV_INUSE)))
#define prev_chunk(p) ((mchunkptr)(((char *)(p)) - ((p)->prev_size)))
#define inuse(p) ((((mchunkptr)(((char *)(p)) + ((p)->size & ~PREV_INUSE)))->size) & PREV_INUSE)
#define prev_inuse(p) ((p)->size & PREV_INUSE)
#define set_head(p, s) ((p)->size = (s))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define long_sub_size_t(x, y) (sizeof(long) > sizeof(INTERNAL_SIZE_T) && x < y ? -(long)(y - x) : (long)(x - y))
#define request2size(req) \
    (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
      (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
     (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define unlink(P, BK, FD) \
    { \
        BK = P->bk; \
        FD = P->fd; \
        FD->bk = BK; \
        BK->fd = FD; \
    }
#define check_inuse_chunk(P)
#define MALLOC_COPY(dest, src, nbytes) \
    do \
    { \
        INTERNAL_SIZE_T mcsz = (nbytes); \
        if (mcsz <= 9 * sizeof(mcsz)) \
        { \
            INTERNAL_SIZE_T *mcsrc = (INTERNAL_SIZE_T *)(src); \
            INTERNAL_SIZE_T *mcdst = (INTERNAL_SIZE_T *)(dest); \
            if (mcsz >= 5 * sizeof(mcsz)) \
            { \
                *mcdst++ = *mcsrc++; \
                *mcdst++ = *mcsrc++; \
                if (mcsz >= 7 * sizeof(mcsz)) \
                { \
                    *mcdst++ = *mcsrc++; \
                    *mcdst++ = *mcsrc++; \
                    if (mcsz >= 9 * sizeof(mcsz)) \
                    { \
                        *mcdst++ = *mcsrc++; \
                        *mcdst++ = *mcsrc++; \
                    } \
                } \
            } \
            *mcdst++ = *mcsrc++; \
            *mcdst++ = *mcsrc++; \
            *mcdst = *mcsrc; \
        } \
        else \
            memcpy(dest, src, mcsz); \
    } while (0)

typedef struct malloc_chunk *mbinptr;
extern mbinptr D_00135D68[];
#define av_ D_00135D68
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define top (bin_at(0)->fd)

void __malloc_lock(struct _reent *);
void __malloc_unlock(struct _reent *);
void _free_r(struct _reent *, void *);
void *memcpy(void *, const void *, unsigned int);
#define MALLOC_LOCK __malloc_lock(reent_ptr)
#define MALLOC_UNLOCK __malloc_unlock(reent_ptr)

void *_realloc_r(struct _reent *reent_ptr, void *oldmem, unsigned int bytes)
{
    INTERNAL_SIZE_T nb; /* padded request size */

    mchunkptr oldp;          /* chunk corresponding to oldmem */
    INTERNAL_SIZE_T oldsize; /* its size */

    mchunkptr newp;          /* chunk to return */
    INTERNAL_SIZE_T newsize; /* its size */
    void *newmem;            /* corresponding user mem */

    mchunkptr next;           /* next contiguous chunk after oldp */
    INTERNAL_SIZE_T nextsize; /* its size */

    mchunkptr prev;           /* previous contiguous chunk before oldp */
    INTERNAL_SIZE_T prevsize; /* its size */

    mchunkptr remainder;    /* holds split off extra space from newp */
    INTERNAL_SIZE_T remainder_size; /* its size */

    mchunkptr bck; /* misc temp for linking */
    mchunkptr fwd; /* misc temp for linking */

    /* realloc of null is supposed to be same as malloc */
    if (oldmem == 0)
        return _malloc_r(reent_ptr, bytes);

    MALLOC_LOCK;

    newp = oldp = mem2chunk(oldmem);
    newsize = oldsize = chunksize(oldp);

    nb = request2size(bytes);

    check_inuse_chunk(oldp);

    if ((long)(oldsize) < (long)(nb))
    {

        /* Try expanding forward */

        next = chunk_at_offset(oldp, oldsize);
        if (next == top || !inuse(next))
        {
            nextsize = chunksize(next);

            /* Forward into top only if a remainder */
            if (next == top)
            {
                if ((long)(nextsize + newsize) >= (long)(nb + MINSIZE))
                {
                    newsize += nextsize;
                    top = chunk_at_offset(oldp, nb);
                    set_head(top, (newsize - nb) | PREV_INUSE);
                    set_head_size(oldp, nb);
                    MALLOC_UNLOCK;
                    return chunk2mem(oldp);
                }
            }

            /* Forward into next chunk */
            else if (((long)(nextsize + newsize) >= (long)(nb)))
            {
                unlink(next, bck, fwd);
                newsize += nextsize;
                goto split;
            }
        }
        else
        {
            next = 0;
            nextsize = 0;
        }

        /* Try shifting backwards. */

        if (!prev_inuse(oldp))
        {
            prev = prev_chunk(oldp);
            prevsize = chunksize(prev);

            /* try forward + backward first to save a later consolidation */

            if (next != 0)
            {
                /* into top */
                if (next == top)
                {
                    if ((long)(nextsize + prevsize + newsize) >= (long)(nb + MINSIZE))
                    {
                        unlink(prev, bck, fwd);
                        newp = prev;
                        newsize += prevsize + nextsize;
                        newmem = chunk2mem(newp);
                        MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                        top = chunk_at_offset(newp, nb);
                        set_head(top, (newsize - nb) | PREV_INUSE);
                        set_head_size(newp, nb);
                        MALLOC_UNLOCK;
                        return newmem;
                    }
                }

                /* into next chunk */
                else if (((long)(nextsize + prevsize + newsize) >= (long)(nb)))
                {
                    unlink(next, bck, fwd);
                    unlink(prev, bck, fwd);
                    newp = prev;
                    newsize += nextsize + prevsize;
                    newmem = chunk2mem(newp);
                    MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                    goto split;
                }
            }

            /* backward only */
            if (prev != 0 && (long)(prevsize + newsize) >= (long)nb)
            {
                unlink(prev, bck, fwd);
                newp = prev;
                newsize += prevsize;
                newmem = chunk2mem(newp);
                MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                goto split;
            }
        }

        /* Must allocate */

        newmem = _malloc_r(reent_ptr, bytes);

        if (newmem == 0) /* propagate failure */
        {
            MALLOC_UNLOCK;
            return 0;
        }

        /* Avoid copy if newp is next chunk after oldp. */
        /* (This can only happen when new chunk is sbrk'ed.) */

        if ((newp = mem2chunk(newmem)) == next_chunk(oldp))
        {
            newsize += chunksize(newp);
            newp = oldp;
            goto split;
        }

        /* Otherwise copy, free, and exit */
        MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
        _free_r(reent_ptr, oldmem);
        MALLOC_UNLOCK;
        return newmem;
    }

split: /* split off extra room in old or expanded chunk */

    if (newsize - nb >= MINSIZE) /* split off remainder */
    {
        remainder = chunk_at_offset(newp, nb);
        remainder_size = newsize - nb;
        set_head_size(newp, nb);
        set_head(remainder, remainder_size | PREV_INUSE);
        set_inuse_bit_at_offset(remainder, remainder_size);
        _free_r(reent_ptr, chunk2mem(remainder)); /* let free() deal with it */
    }
    else
    {
        set_head_size(newp, newsize);
        set_inuse_bit_at_offset(newp, newsize);
    }

    check_inuse_chunk(newp);
    MALLOC_UNLOCK;
    return chunk2mem(newp);
}
