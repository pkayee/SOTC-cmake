#include "common.h"

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", create_global_light_param_menu);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40013E20);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40013F28);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40014048);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40014168);

extern u8 D_40017920[];
void createParamMenu(u8 *a0, s32 a1);

u8 *createLightParamMenu(void)
{
    u8 *p = D_40017920;

    if (*(s32 *)(p + 0x30) != 0) return NULL;
    createParamMenu(p, 0);
    return p + 0x30;
}
