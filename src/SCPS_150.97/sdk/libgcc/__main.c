#include "common.h"

typedef void (*func_ptr)(void);

extern func_ptr *D_00135A64[];
extern s32 D_00135A68[];
extern s32 D_0016A108[];
extern s32 D_001361E0[];

void __deregister_frame_info(void *begin);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __do_global_dtors);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __do_global_ctors);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __main);
void __main(void)
{
    if (D_0016A108[0])
    {
        return;
    }
    D_0016A108[0] = 1;
    __do_global_ctors();
}
