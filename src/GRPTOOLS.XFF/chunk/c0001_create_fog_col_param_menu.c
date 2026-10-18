#include "common.h"

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", create_fog_col_param_menu);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", GetToolNewNameNum);
extern s32 D_40016098[];

s32 GetToolNewNameNum(s32 idx)
{
    return D_40016098[idx];
}

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", getSizeofElemType);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", calcOneElemLogBuffer);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", GetDispMaruB);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", func_40011D80);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", func_40011F50);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", func_40012130);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", func_400122D8);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0001_create_fog_col_param_menu", create_game_light_param_menu);
