#include "common.h"

typedef struct
{
    s32 quot;
    s32 rem;
} div_t;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/div", div);
div_t div(s32 num, s32 denom)
{
    div_t r;

    r.quot = num / denom;
    r.rem = num % denom;
    if (num >= 0)
    {
        if (r.rem < 0)
        {
            r.quot++;
            r.rem -= denom;
        }
    }
    else
    {
        if (r.rem > 0)
        {
            r.quot--;
            r.rem += denom;
        }
    }
    return r;
}
