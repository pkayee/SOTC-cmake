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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", func_4007C330);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0089_motrootdyn_startpendulum_nochange_parent", func_4007C378);
