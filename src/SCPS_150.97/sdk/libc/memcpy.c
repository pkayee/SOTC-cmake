#include "common.h"

/* NEARMISS-STUB memcpy */
#if 0 /* NEARMISS 8.0% cat=inline-unroll sub=- | target is 16-byte unrolled ld/sd pipeline with different alignment-test and tail branch order; ours 32-byte do-while + scalar tail; re-score 8.5% (db 8.0) | attempts=1 */

typedef struct
{
    u64 lo;
    u64 hi;
} Chunk16;

void *memcpy(void *dst, const void *src, size_t n)
{
    void *ret = dst;
    u8 *d = dst;
    const u8 *s = src;

    if (n >= 0x20 && !(((u32)s | (u32)d) & 0xF))
    {
        Chunk16 *dc = (Chunk16 *)d;
        const Chunk16 *sc = (const Chunk16 *)s;

        do
        {
            *dc++ = *sc++;
            *dc++ = *sc++;
            n -= 0x20;
        } while (n >= 0x20);
        d = (u8 *)dc;
        s = (const u8 *)sc;
    }

    while (n >= 8)
    {
        *(u64 *)d = *(const u64 *)s;
        d += 8;
        s += 8;
        n -= 8;
    }

    while (n-- != 0)
    {
        *d++ = *s++;
    }

    return ret;
}

#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcpy", memcpy);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcpy", memmove);
