#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", constructor_camera_default_angle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", doit_camera_default_angle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DE9F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", get_base_default_direction);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF098);

extern s32 GAMEUTIL_get_cur_status_status_manager();

s32 get_cur_attr_camera_default_angle(s32 a, s32 b, s32 c, s32 d)
{
    return GAMEUTIL_get_cur_status_status_manager(a, b, c, d);
}

s32 is_safety_camera_default_angle(void)
{
    return GAMEUTIL_get_cur_status_status_manager() != 1;
}

void *CAM_get_ground_contact_obj(void *);
int GAMEUTIL_is_boss_obj(void *, int);

int is_must_reach_normal_default_angle(char *c)
{
    if (GAMEUTIL_is_boss_obj(CAM_get_ground_contact_obj(c + 0x240), 1) == 1 || *(int *)(*(char **)c + 4) == 2) return 1;
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF220);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF248);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF2D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF408);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF518);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF5E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF6A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF728);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF850);
