#include "common.h"
#include "sdk/ee/eekernel.h"

extern char D_00138B98[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd036", sceCdChgSys);
int sceCdChgSys(void)
{
    scePrintf(D_00138B98);
    return 2;
}
