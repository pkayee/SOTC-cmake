#include "common.h"

/* NEARMISS-STUB memcmp */
#if 0 /* NEARMISS 37.5% cat=vu0-mmi sub=- | MMI lq/pxor/pcpyud 16-byte fast path | attempts=1 */
#include "common.h"

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcmp", memcmp);
int memcmp(const void *m1, const void *m2, u32 n)
{
    const u8 *s1 = (const u8 *)m1;
    const u8 *s2 = (const u8 *)m2;

    while (n--)
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/memcmp", memcmp);
