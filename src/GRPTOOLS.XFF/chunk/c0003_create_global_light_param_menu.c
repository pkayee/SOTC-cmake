#include "common.h"

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", create_global_light_param_menu);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40013E20);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40013F28);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40014048);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", func_40014168);

/* NEARMISS-STUB createLightParamMenu */
#if 0 /* NEARMISS 88.125% cat=regalloc sub=- | ret var in a1 and cond in v1; target keeps ret=NULL in v0 and cond in a1 before bnez | attempts=1 */
extern u8 D_40017920[];
void createParamMenu(u8 *a0, s32 a1);

u8 *createLightParamMenu(void)
{
    u8 *ret = NULL;
    u8 *p = D_40017920;

    if (*(s32 *)(p + 0x30) == 0)
    {
        createParamMenu(p, 0);
        ret = p + 0x30;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", createLightParamMenu);
