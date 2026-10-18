#include "common.h"

extern void constructor_double_spring_interp_cntrl(void *, float);
extern void GAMEUTIL_constructor_col_plane_info_filter(void *);
extern void func_400E1C58(void *);

/* GAMECORE c0173: forwards to the water-surface collision check with the riding obj of (a3+0x240) and flag 1 (tail call). Arg types unsure. */
extern void *CAM_get_target_riding_obj(void *);
extern int player_collision_check_direct_water_surface_plus(void *, void *, void *, void *, void *, int);

/* GAMECORE c0173: camera distance scale: 1.0, 2.0 when the target rides a horse, +0.5 when mode == 1. */
extern void *CAM_get_target_obj(void *);
extern void *GAMEUTIL_get_riding_horse_object(void *);

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2940);
f32 GetPlaneSlopeDegree(void);

f32 func_400E2940(void)
{
    return (GetPlaneSlopeDegree() * 3.14159265f) / 180.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", func_400E2980);

int func_400E29E0(void *a, void *b, void *c, char *d, void *e)
{
    return player_collision_check_direct_water_surface_plus(a, b, c, e, CAM_get_target_riding_obj(d + 0x240), 1);
}

/* GAMECORE c0173: max(a - b, 0) * c (f12,f13,f14) */
float func_400E2A48(float a, float b, float c)
{
    float d = a - b;
    if (d < 0.0f) {
        d = 0.0f;
    }
    return c * d;
}

/* GAMECORE c0173: snap b to the grid of step c anchored by a (round-half-down of a/c), then wrap (b - t)/c.
 * the `float r = b; if (c != 0) body; return r;` form matches (early `return b` form = 98.3, f2/f1 regalloc swap). */
float func_400E2A68(float a, float b, float c)
{
    float r = b;
    float q;
    int i;
    float t;
    if (c != 0.0f) {
        q = a / c;
        i = (int)q;
        if (q - (float)i <= 0.5f) {
            t = c * (float)i;
        } else {
            t = c * (float)(i + 1);
        }
        r = t + (float)(int)((b - t) / c) * c;
    }
    return r;
}

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

float func_400E3108(void *c, int mode)
{
    float r = 1.0f;
    if (GAMEUTIL_get_riding_horse_object(CAM_get_target_obj(c)) != 0) {
        r = 2.0f;
    }
    if (mode == 1) {
        r += 0.5f;
    }
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0173_CAM_reset_slope_cntrl", doit_camera_target_lost_angle);
