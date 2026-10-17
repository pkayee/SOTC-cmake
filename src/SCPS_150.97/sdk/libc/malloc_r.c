#include "common.h"

/* NEARMISS-STUB _malloc_r */
#if 0 /* NEARMISS 99.9% cat=struct-layout sub=splat-interior-symbol | newlib mALLOc instruction-identical; objdiff differs only in 7 reloc names: target D_00135D70 (splat interior symbol av_+8) vs ours D_00135D68+8; fix = symbol_a | attempts=3 */
/* newlib mallocr.c mALLOc verbatim (EE: MALLOC_ALIGNMENT 16, newlib long_sub_size_t). Instruction-identical to the target: the only objdiff differences are 7 reloc names, target %lo(D_00135D70) (splat interior symbol = av_+8) vs ours D_00135D68+8. Becomes 100 when D_00135D68 gets size 0x408 in symbol_addrs. Needs the freer.c mallocr header. */
#define request2size(req) \
    (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
      (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
     (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define is_small_request(nb) (nb < MAX_SMALLBIN_SIZE - SMALLBIN_WIDTH)
#define next_bin(b) ((mbinptr)((char *)(b) + 2 * sizeof(mbinptr)))
#define prev_bin(b) ((mbinptr)((char *)(b)-2 * sizeof(mbinptr)))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define long_sub_size_t(x, y) (sizeof(long) > sizeof(INTERNAL_SIZE_T) && x < y ? -(long)(y - x) : (long)(x - y))
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define check_malloced_chunk(P, N)

#define malloc_extend_top func_00127908
void malloc_extend_top(RARG INTERNAL_SIZE_T nb);

void *_malloc_r(RARG size_t bytes)
{
    mchunkptr victim;          /* inspected/selected chunk */
    INTERNAL_SIZE_T victim_size; /* its size */
    int idx;                   /* index for bin traversal */
    mbinptr bin;               /* associated bin */
    mchunkptr remainder;       /* remainder from a split */
    long remainder_size;       /* its size */
    int remainder_index;       /* its bin index */
    unsigned long block;       /* block traverser bit */
    int startidx;              /* first bin of a traversed block */
    mchunkptr fwd;             /* misc temp for linking */
    mchunkptr bck;             /* misc temp for linking */
    mbinptr q;                 /* misc temp */

    INTERNAL_SIZE_T nb = request2size(bytes); /* padded request size; */

    MALLOC_LOCK;

    /* Check for exact match in a bin */

    if (is_small_request(nb)) /* Faster version for small requests */
    {
        idx = smallbin_index(nb);

        /* No traversal or size check necessary for small bins.  */

        q = bin_at(idx);
        victim = last(q);

#if MALLOC_ALIGN != 16
        /* Also scan the next one, since it would have a remainder < MINSIZE */
        if (victim == q)
        {
            q = next_bin(q);
            victim = last(q);
        }
#endif
        if (victim != q)
        {
            victim_size = chunksize(victim);
            unlink(victim, bck, fwd);
            set_inuse_bit_at_offset(victim, victim_size);
            check_malloced_chunk(victim, nb);
            MALLOC_UNLOCK;
            return chunk2mem(victim);
        }

        idx += 2; /* Set for bin scan below. We've already scanned 2 bins. */
    }
    else
    {
        idx = bin_index(nb);
        bin = bin_at(idx);

        for (victim = last(bin); victim != bin; victim = victim->bk)
        {
            victim_size = chunksize(victim);
            remainder_size = long_sub_size_t(victim_size, nb);

            if (remainder_size >= (long)MINSIZE) /* too big */
            {
                --idx; /* adjust to rescan below after checking last remainder */
                break;
            }

            else if (remainder_size >= 0) /* exact fit */
            {
                unlink(victim, bck, fwd);
                set_inuse_bit_at_offset(victim, victim_size);
                check_malloced_chunk(victim, nb);
                MALLOC_UNLOCK;
                return chunk2mem(victim);
            }
        }

        ++idx;
    }

    /* Try to use the last split-off remainder */

    if ((victim = last_remainder->fd) != last_remainder)
    {
        victim_size = chunksize(victim);
        remainder_size = long_sub_size_t(victim_size, nb);

        if (remainder_size >= (long)MINSIZE) /* re-split */
        {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | PREV_INUSE);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | PREV_INUSE);
            set_foot(remainder, remainder_size);
            check_malloced_chunk(victim, nb);
            MALLOC_UNLOCK;
            return chunk2mem(victim);
        }

        clear_last_remainder;

        if (remainder_size >= 0) /* exhaust */
        {
            set_inuse_bit_at_offset(victim, victim_size);
            check_malloced_chunk(victim, nb);
            MALLOC_UNLOCK;
            return chunk2mem(victim);
        }

        /* Else place in bin */

        frontlink(victim, victim_size, remainder_index, bck, fwd);
    }

    /*
       If there are any possibly nonempty big-enough blocks,
       search for best fitting chunk by scanning bins in blockwidth units.
    */

    if ((block = idx2binblock(idx)) <= binblocks)
    {

        /* Get to the first marked block */

        if ((block & binblocks) == 0)
        {
            /* force to an even block boundary */
            idx = (idx & ~(BINBLOCKWIDTH - 1)) + BINBLOCKWIDTH;
            block <<= 1;
            while ((block & binblocks) == 0)
            {
                idx += BINBLOCKWIDTH;
                block <<= 1;
            }
        }

        /* For each possibly nonempty block ... */
        for (;;)
        {
            startidx = idx; /* (track incomplete blocks) */
            q = bin = bin_at(idx);

            /* For each bin in this block ... */
            do
            {
                /* Find and use first big enough chunk ... */

                for (victim = last(bin); victim != bin; victim = victim->bk)
                {
                    victim_size = chunksize(victim);
                    remainder_size = long_sub_size_t(victim_size, nb);

                    if (remainder_size >= (long)MINSIZE) /* split */
                    {
                        remainder = chunk_at_offset(victim, nb);
                        set_head(victim, nb | PREV_INUSE);
                        unlink(victim, bck, fwd);
                        link_last_remainder(remainder);
                        set_head(remainder, remainder_size | PREV_INUSE);
                        set_foot(remainder, remainder_size);
                        check_malloced_chunk(victim, nb);
                        MALLOC_UNLOCK;
                        return chunk2mem(victim);
                    }

                    else if (remainder_size >= 0) /* take */
                    {
                        set_inuse_bit_at_offset(victim, victim_size);
                        unlink(victim, bck, fwd);
                        check_malloced_chunk(victim, nb);
                        MALLOC_UNLOCK;
                        return chunk2mem(victim);
                    }
                }

                bin = next_bin(bin);

#if MALLOC_ALIGN == 16
                if (idx < MAX_SMALLBIN)
                {
                    bin = next_bin(bin);
                    ++idx;
                }
#endif
            } while ((++idx & (BINBLOCKWIDTH - 1)) != 0);

            /* Clear out the block bit. */

            do /* Possibly backtrack to try to clear a partial block */
            {
                if ((startidx & (BINBLOCKWIDTH - 1)) == 0)
                {
                    binblocks &= ~block;
                    break;
                }
                --startidx;
                q = prev_bin(q);
            } while (first(q) == q);

            /* Get to the next possibly nonempty block */

            if ((block <<= 1) <= binblocks && (block != 0))
            {
                while ((block & binblocks) == 0)
                {
                    idx += BINBLOCKWIDTH;
                    block <<= 1;
                }
            }
            else
                break;
        }
    }

    /* Try to use top chunk */

    /* Require that there be a remainder, ensuring top always exists  */
    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
    {
        /* Try to extend */
        malloc_extend_top(RCALL nb);
        remainder_size = long_sub_size_t(chunksize(top), nb);
        if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
        {
            MALLOC_UNLOCK;
            return 0; /* propagate failure */
        }
    }

    victim = top;
    set_head(victim, nb | PREV_INUSE);
    top = chunk_at_offset(victim, nb);
    set_head(top, remainder_size | PREV_INUSE);
    check_malloced_chunk(victim, nb);
    MALLOC_UNLOCK;
    return chunk2mem(victim);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc_r", _malloc_r);
