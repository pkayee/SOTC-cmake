#include "common.h"
#include "gcc/sys/types.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/libgraph.h"

int sceGsSwapDBuff(sceGsDBuff *db, int id)
{
    int i;
    int ret;

    i = id & 1;
    sceGsPutDispEnv(&db->disp[i]);
    if (i != 0)
    {
        ret = sceGsPutDrawEnv(&db->giftag1);
    }
    else
    {
        ret = sceGsPutDrawEnv(&db->giftag0);
    }
    return ret;
}
