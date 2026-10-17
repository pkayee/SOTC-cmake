#include "common.h"
#include <stdlib.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atol", atol);
long atol(const char *s)
{
    return strtol(s, NULL, 10);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atol", func_0012C340);
