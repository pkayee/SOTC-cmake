#include "common.h"

extern void constructor_double_spring_interp_cntrl(void *, float);
extern void GAMEUTIL_constructor_col_plane_info_filter(void *);
extern void func_400E1C58(void *);

void CAM_reset_slope_cntrl(char *c)
{
    constructor_double_spring_interp_cntrl(c, 0.0001f);
    *(int *)(c + 0x20) = 0;
    *(int *)(c + 0x24) = 0;
    *(int *)(c + 0x28) = 0;
    *(int *)(c + 0x2C) = 0;
    *(int *)(c + 0x30) = 0;
    *(int *)(c + 0x34) = 0;
    *(int *)(c + 0x38) = 0;
    GAMEUTIL_constructor_col_plane_info_filter(c + 0x40);
    GAMEUTIL_constructor_col_plane_info_filter(c + 0xC0);
    func_400E1C58(c);
}

float CAM_get_interp_slope_pitch_ofst(void *arg0)
{
    return -(*(float *)((char *)(arg0) + 0x1C));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2778);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2868);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2940);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2980);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E29E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2A48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2A68);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", doit_camera_target_approach);

void GAMEUTIL_reset_status_manager(void *a0, s32 a1);
void GAMEUTIL_constructor_position_filter(void *a0);
void CAM_init_aim_angle_rot(void *a0, s32 a1);

void constructor_camera_target_approach(char *p)
{
    GAMEUTIL_reset_status_manager(p, 0);
    GAMEUTIL_constructor_position_filter(p + 0x10);
    *(int *)(p + 0x40) = 0;
    CAM_init_aim_angle_rot(p + 0x44, 1);
}

extern int GAMEUTIL_get_cur_status_status_manager();

float get_upper_limit_clip_default_pitch_camera_target_approach(float fparg0)
{
    float var_f20;

    var_f20 = fparg0;
    if ((GAMEUTIL_get_cur_status_status_manager() == 1) && (var_f20 > -1.4835296f)) {
        var_f20 = -1.4835296f;
    }
    return var_f20;
}

extern int GAMEUTIL_is_status_change_status_manager(int);

int is_cut_default_pitch_interp_camera_target_approach(int arg0)
{
    int temp_v0;
    int var_v0;

    temp_v0 = GAMEUTIL_get_cur_status_status_manager();
    if ((temp_v0 != 1) || (var_v0 = GAMEUTIL_is_status_change_status_manager(arg0), (var_v0 != temp_v0))) {
        var_v0 = 0;
    }
    return var_v0;
}

extern int CAM_reset_aim_angle_rot();

int reset_pitch_rot_cntrl_camera_target_approach(int a, int b, int c, int d)
{
    return CAM_reset_aim_angle_rot(a + 68, b, c, d);
}

extern void CAM_set_interp_param_aim_rot_common(void *, float, float);
extern float CAM_doit_aim_angle_rot(void *, int, float, float, float, float, float, float, float, float, float);

float act_pitch_rot_camera_target_approach(char *c, float pitch, float aim, float dt)
{
    int on = GAMEUTIL_get_cur_status_status_manager(c) == 1;

    CAM_set_interp_param_aim_rot_common(c + 0x44, 0.0f, 0.3f);
    return CAM_doit_aim_angle_rot(c + 0x44, on, pitch, aim, 0.0f, 0.0f, 100.0f, 1.0f, 40.0f, 0.8f, dt);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", act_approach_judge_ray_check_camera_target_approach);

int get_status_camera_target_approach(int a, int b, int c, int d)
{
    return GAMEUTIL_get_cur_status_status_manager(a, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2FD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E3108);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", doit_camera_target_lost_angle);
