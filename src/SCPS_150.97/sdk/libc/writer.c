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

/* NEARMISS-STUB _calloc_r */
#if 0 /* NEARMISS 38.0% cat=branch-layout sub=- | nclears ladder control-flow shape and arg/temp regs differ; db best 38 pct not reproduced | attempts=1 */
void *_calloc_r(struct _reent *ptr, s32 n, s32 size)
{
    u32 *d;
    u32 nclears;
    u32 csz;
    void *mem;

    mem = _malloc_r(ptr, n * size);
    if (mem == 0)
    {
        return 0;
    }
    csz = *(u32 *)((u8 *)mem - 4) & ~3;
    nclears = (csz - 4) / 4;
    d = mem;
    if (nclears > 9)
    {
        memset(mem, 0, csz - 4);
    }
    else
    {
        d[0] = 0;
        d[1] = 0;
        d[2] = 0;
        if (nclears > 4)
        {
            d[3] = 0;
            d[4] = 0;
            if (nclears > 6)
            {
                d[5] = 0;
                d[6] = 0;
                if (nclears > 8)
                {
                    d[7] = 0;
                    d[8] = 0;
                }
            }
        }
    }
    return mem;
}
#endif
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


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _read_r);
long _read_r(struct _reent *ptr, int fd, void *buf, unsigned int cnt)
{
    long ret;

    errno = 0;
    if ((ret = (long)read(fd, buf, cnt)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}


/* NEARMISS-STUB _realloc_r */
#if 0 /* NEARMISS 11.4% cat=regalloc sub=- | prologue saves s0-s6 with different register assignment for locals (arg_mism on sd/daddu); re-score 11.4 pct matches db | attempts=1 */
struct malloc_chunk
{
    u32 prev_size;
    u32 size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

extern s32 D_00135D68[];
void __malloc_lock(struct _reent *ptr);
void __malloc_unlock(struct _reent *ptr);
void *_malloc_r(struct _reent *ptr, u32 nbytes);
void _free_r(struct _reent *ptr, void *mem);

#define REALLOC_COPY_WORDS(d, s, n)                                         \
    if ((n) < 20)                                                           \
    {                                                                       \
        (d)[0] = (s)[0];                                                    \
        (d)[1] = (s)[1];                                                    \
        (d)[2] = (s)[2];                                                    \
    }                                                                       \
    else if ((n) < 28)                                                      \
    {                                                                       \
        (d)[0] = (s)[0];                                                    \
        (d)[1] = (s)[1];                                                    \
        (d)[2] = (s)[2];                                                    \
        (d)[3] = (s)[3];                                                    \
        (d)[4] = (s)[4];                                                    \
    }                                                                       \
    else if ((n) < 36)                                                      \
    {                                                                       \
        (d)[0] = (s)[0];                                                    \
        (d)[1] = (s)[1];                                                    \
        (d)[2] = (s)[2];                                                    \
        (d)[3] = (s)[3];                                                    \
        (d)[4] = (s)[4];                                                    \
        (d)[5] = (s)[5];                                                    \
        (d)[6] = (s)[6];                                                    \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        (d)[0] = (s)[0];                                                    \
        (d)[1] = (s)[1];                                                    \
        (d)[2] = (s)[2];                                                    \
        (d)[3] = (s)[3];                                                    \
        (d)[4] = (s)[4];                                                    \
        (d)[5] = (s)[5];                                                    \
        (d)[6] = (s)[6];                                                    \
        (d)[7] = (s)[7];                                                    \
        (d)[8] = (s)[8];                                                    \
    }

void *_realloc_r(struct _reent *ptr, void *oldmem, u32 bytes)
{
    s32 *av;
    s32 *top;
    struct malloc_chunk *oldp;
    struct malloc_chunk *newp;
    struct malloc_chunk *nxt;
    struct malloc_chunk *nn;
    struct malloc_chunk *prv;
    struct malloc_chunk *rem;
    struct malloc_chunk *chunk;
    void *newmem;
    u32 *d;
    u32 *s;
    u32 oldsize;
    u32 nb;
    u32 newsize;
    u32 nsz;
    u32 hdr;
    u32 psz;
    u32 cp;

    if (oldmem == 0)
    {
        return _malloc_r(ptr, bytes);
    }
    __malloc_lock(ptr);
    oldp = (struct malloc_chunk *)((u8 *)oldmem - 8);
    oldsize = oldp->size & ~3;
    if (bytes + 0x13 < 0x1F)
    {
        nb = 0x10;
    }
    else
    {
        nb = (bytes + 0x13) & ~0xF;
    }
    av = D_00135D68;
    newp = oldp;
    newsize = oldsize;
    newmem = (u8 *)oldp + 8;
    hdr = (u32)oldmem;
    nxt = 0;
    if (oldsize < nb)
    {
        nxt = (struct malloc_chunk *)((u8 *)oldp + oldsize);
        top = (s32 *)av[2];
        if (nxt == (struct malloc_chunk *)top)
        {
            nsz = nxt->size & ~3;
            if (oldsize + nsz >= nb + 0x10)
            {
                av[2] = (s32)((u8 *)oldp + nb);
                rem = (struct malloc_chunk *)av[2];
                rem->size = (oldsize + nsz - nb) | 1;
                oldp->size = (oldp->size & 1) | nb;
                __malloc_unlock(ptr);
                return (u8 *)oldp + 8;
            }
        }
        else
        {
            nn = (struct malloc_chunk *)((u8 *)nxt + (nxt->size & ~1));
            if (nn->size & 1)
            {
                nxt = 0;
            }
            else
            {
                nsz = nxt->size & ~3;
                if (oldsize + nsz >= nb)
                {
                    newsize = oldsize + nsz;
                    nxt->fd->bk = nxt->bk;
                    nxt->bk->fd = nxt->fd;
                    hdr = (u32)oldmem;
                    goto merged;
                }
            }
        }
        if (!(oldp->size & 1))
        {
            prv = (struct malloc_chunk *)((u8 *)oldp - oldp->prev_size);
            psz = prv->size & ~3;
            if (nxt != 0)
            {
                if (nxt != (struct malloc_chunk *)top)
                {
                    if (psz + nsz + oldsize >= nb)
                    {
                        newsize = psz + nsz + oldsize;
                        nxt->fd->bk = nxt->bk;
                        nxt->bk->fd = nxt->fd;
                        goto prev_merge;
                    }
                }
                else if (psz + nsz + oldsize >= nb + 0x10)
                {
                    newsize = psz + nsz + oldsize;
                    cp = oldsize - 4;
                    s = (u32 *)oldmem;
                    d = (u32 *)((u8 *)prv + 8);
                    prv->fd->bk = prv->bk;
                    prv->bk->fd = prv->fd;
                    if (cp > 36)
                    {
                        memcpy(d, s, cp);
                    }
                    else
                    {
                        REALLOC_COPY_WORDS(d, s, cp);
                    }
                    av[2] = (s32)((u8 *)prv + nb);
                    rem = (struct malloc_chunk *)av[2];
                    rem->size = (newsize - nb) | 1;
                    prv->size = (prv->size & 1) | nb;
                    __malloc_unlock(ptr);
                    return (u8 *)prv + 8;
                }
            }
            if (psz + oldsize >= nb)
            {
                newsize = psz + oldsize;
                goto prev_merge;
            }
        }
        goto to_malloc;
    }
    hdr = (u32)oldmem;
    goto merged;

prev_merge:
    prv = (struct malloc_chunk *)((u8 *)oldp - oldp->prev_size);
    prv->fd->bk = prv->bk;
    prv->bk->fd = prv->fd;
    newp = prv;
    newmem = (u8 *)prv + 8;
    hdr = prv->size;
    cp = oldsize - 4;
    s = (u32 *)oldmem;
    d = (u32 *)newmem;
    if (cp > 36)
    {
        memcpy(newmem, oldmem, cp);
    }
    else
    {
        REALLOC_COPY_WORDS(d, s, cp);
    }
    goto merged;

to_malloc:
    newmem = _malloc_r(ptr, bytes);
    if (newmem == 0)
    {
        __malloc_unlock(ptr);
        return 0;
    }
    chunk = (struct malloc_chunk *)((u8 *)newmem - 8);
    if (chunk == (struct malloc_chunk *)((u8 *)oldp + (oldp->size & ~1)))
    {
        newp = oldp;
        newmem = (u8 *)oldp + 8;
        newsize = oldsize + (chunk->size & ~3);
        hdr = oldp->size;
        goto merged;
    }
    cp = oldsize - 4;
    s = (u32 *)oldmem;
    d = (u32 *)newmem;
    if (cp > 36)
    {
        memcpy(newmem, oldmem, cp);
    }
    else
    {
        REALLOC_COPY_WORDS(d, s, cp);
    }
    _free_r(ptr, oldmem);
    __malloc_unlock(ptr);
    return newmem;

merged:
    if (newsize - nb < 16)
    {
        newp->size = (hdr & 1) | newsize;
        nn = (struct malloc_chunk *)((u8 *)newp + newsize);
        nn->size |= 1;
        __malloc_unlock(ptr);
        return newmem;
    }
    rem = (struct malloc_chunk *)((u8 *)newp + nb);
    newp->size = (hdr & 1) | nb;
    rem->size = (newsize - nb) | 1;
    nn = (struct malloc_chunk *)((u8 *)rem + (newsize - nb));
    nn->size |= 1;
    _free_r(ptr, (u8 *)rem + 8);
    __malloc_unlock(ptr);
    return newmem;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/writer", _realloc_r);
