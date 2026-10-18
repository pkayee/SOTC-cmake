#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", motrootdyn_startpendulum_nochange_parent);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", motrootdyn_startpendulum);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", swim);

void ForceUnparentLayoutObj(void *actor);

void motrootdyn_startswim(void *actor, char *m)
{
    ForceUnparentLayoutObj(actor);
    *(float *)(m + 0xAC0) = *(float *)(m + 0x34) * 0.5f;
}

/* NEARMISS-STUB func_4007C330 */
#if 0 /* NEARMISS 65.0% cat=regalloc sub=- | ret var and sltu reg alloc differ; compiler adds s32 sign-ext, target none | attempts=1 */
s64 *GetCollisionDBAttributeAdr(void);

s32 func_4007C330(void)
{
    u64 attr = *(u64 *)GetCollisionDBAttributeAdr();
    s32 ret = 0;

    if ((attr & 0x7C00) != 0x3C00)
    {
        ret = (attr & 0x7C000000) != 0x14000000;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", func_4007C330);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", func_4007C378);
