#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

/* NEARMISS-STUB sceGsPutDrawEnv */
#if 0 /* NEARMISS 84.6% cat=branch-layout sub=- | spin loop with scePrintf timeout: 2.9 lays out the do-while with the timeout block inline (asm: timeout block at end, bnez to it, hoisted 0x1000000 in a registe | attempts=1 */
int sceGsPutDrawEnv(sceGifTag *giftag)
{
    u_int i;

    if (*(u_int *)0x1000A000 & 0x100)
    {
        i = 0;
        do
        {
            if (i > 0x1000000)
            {
                scePrintf(D_001383E8);
                return -1;
            }
            i++;
        } while (*(u_int *)0x1000A000 & 0x100);
    }
    *(u_int *)0x1000A020 = (*(u_long *)giftag & 0x7FFF) + 1;
    if (((u_int)giftag & 0x70000000) == 0x70000000)
    {
        *(u_int *)0x1000A010 = ((u_int)giftag & 0xFFFFFFF) | 0x80000000;
    }
    else
    {
        *(u_int *)0x1000A010 = (u_int)giftag & 0xFFFFFFF;
    }
    *(u_int *)0x1000A000 = 0x101;
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph008", sceGsPutDrawEnv);
