#include "common.h"

/* NEARMISS-STUB memcpy */
#if 0 /* NEARMISS 82.1% cat=regalloc sub=dst0-copy-minus1-cse | EE newlib memcpy (2 quadword lq/sq big blocks, long middle, byte tail) structure identical 8->82; target copies dst0 to t0 and CSEs -1 into a0 | attempts=2 */
/* newlib memcpy.c EE variant: UNALIGNED mask 15 (u_long128), BIGBLOCKSIZE 32 = 2 quadwords (lq/sq), LITTLEBLOCKSIZE sizeof(long)=8, int len. Needs `typedef unsigned int size_t;`. 82.1: structure identical; target keeps dst0 in t0 and CSEs the -1 loop constant into a0 (ours rematerialises li -1 in the byte loop). */
/* newlib libc/string/memcpy.c, EE build: 128-bit (quadword) big blocks */
#define UNALIGNED(X, Y) \
    (((long)X & (sizeof(u_long128) - 1)) | ((long)Y & (sizeof(u_long128) - 1)))
#define BIGBLOCKSIZE (sizeof(u_long128) << 1)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)

void *memcpy(void *dst0, const void *src0, size_t len0)
{
    char *dst = dst0;
    const char *src = src0;
    u_long128 *aligned_dst;
    const u_long128 *aligned_src;
    long *ldst;
    const long *lsrc;
    int len = len0;

    /* If the size is small, or either SRC or DST is unaligned,
       then punt into the byte copy loop.  This should be rare.  */
    if (!TOO_SMALL(len) && !UNALIGNED(src, dst))
    {
        aligned_dst = (u_long128 *)dst;
        aligned_src = (u_long128 *)src;

        /* Copy 2X quad words at a time if possible.  */
        while (len >= BIGBLOCKSIZE)
        {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }

        /* Copy one long word at a time if possible.  */
        ldst = (long *)aligned_dst;
        lsrc = (const long *)aligned_src;
        while (len >= LITTLEBLOCKSIZE)
        {
            *ldst++ = *lsrc++;
            len -= LITTLEBLOCKSIZE;
        }

        /* Pick up any residual with a byte copier.  */
        dst = (char *)ldst;
        src = (char *)lsrc;
    }

    while (len--)
        *dst++ = *src++;

    return dst0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcpy", memcpy);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcpy", memmove);
