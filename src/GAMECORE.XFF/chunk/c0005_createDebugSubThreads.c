#include "common.h"

extern s32 rootPtn;
extern const char D_40132A30[];
extern const char D_40132A40[];
extern void func_4001BA48(void);
extern void func_4001DE08(void);
extern void DebugGlobalMoveWith2ndController(void);
s32 gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void DEBUG_set_update_position_method_pointer(void *fn);

void createDebugSubThreads(void)
{
    gcCreateScriptObj(func_4001BA48, 0, &rootPtn, 0x2000, 0, 8, D_40132A30);
    gcCreateScriptObj(func_4001DE08, 0, &rootPtn, 0x1000, 0, 8, D_40132A40);
    DEBUG_set_update_position_method_pointer(DebugGlobalMoveWith2ndController);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", func_4001DC30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", DebugGetCameraWithPursue2);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", func_4001DE08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", GAMEUTIL_get_boss_interest_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", GAMEUTIL_doit_look_at_vs_offset_vec);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", GAMEUTIL_set_col_plane_info);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0005_createDebugSubThreads", GAMEUTIL_disp_col_plane_info_debug);
