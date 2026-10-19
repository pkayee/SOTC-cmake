#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

extern char D_001383E8[];

int sceGsPutDrawEnv(sceGifTag *giftag)
{
    u_int i = 0;

    while (*(volatile u_int *)0x1000A000 & 0x100)
    {
        if (i++ > 0x1000000)
        {
            scePrintf(D_001383E8);
            return -1;
        }
    }
    *(volatile u_int *)0x1000A020 = giftag->NLOOP + 1;
    if (((u_int)giftag & 0x70000000) == 0x70000000)
    {
        *(volatile u_int *)0x1000A010 = ((u_int)giftag & 0xFFFFFFF) | 0x80000000;
    }
    else
    {
        *(volatile u_int *)0x1000A010 = (u_int)giftag & 0xFFFFFFF;
    }
    *(volatile u_int *)0x1000A000 = 0x101;
    return 0;
}
