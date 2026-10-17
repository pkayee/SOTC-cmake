#include "common.h"

/* NEARMISS-STUB memset */
#if 0 /* NEARMISS 33.7% cat=no-c-form sub=- | target uses MMI pcpyh/pcpyld to replicate byte then sq from reg; ee-gcc2.96 C emits mul + stack union spill; 5 variants tried | attempts=2 */
void *memset(void *s, s32 c, u32 n)
{
    u8 *p;
    u8 b;
    u64 pat;
    union
    {
        u128 q;
        u64 d[2];
    } v;

    p = s;
    b = (u8)c;
    if (n >= 8 && ((u32)s & 0xF) == 0)
    {
        pat = (u64)b * 0x0101010101010101UL;
        v.d[0] = pat;
        v.d[1] = pat;
        while (n >= 0x20)
        {
            *(u128 *)p = v.q;
            p += 16;
            *(u128 *)p = v.q;
            p += 16;
            n -= 32;
        }
        while (n >= 8)
        {
            *(u64 *)p = pat;
            p += 8;
            n -= 8;
        }
    }
    while (n != 0)
    {
        *p++ = b;
        n--;
    }
    return s;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memset", memset);
