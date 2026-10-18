#include "common.h"

/* GAMECORE c0180 PROVEN 100 (wt-rea-c0180). */
extern float GAMEUTIL_get_difference_yaw_and_yaw(float, float);
extern float GAMEUTIL_get_difference_pitch_and_pitch(float, float);

/* GAMECORE c0180 PROVEN 100 (wt-rea-c0180). */
extern int GAMEUTIL_inc_or_dec_for_near_to_aim_yaw(int, float, float, float);

s32 CAM_is_visible_now_target_visibility(void *param)
{
    return *(s32*)((u8*)param + 0x44) == 0;
}

s32 CAM_is_return_cam_posi_target_visibility(void *param)
{
    return *(s32*)((u8*)param + 0x130);
}

void CAM_reset_camera_warp_cntrl(void *param);

void CAM_init_camera_warp_cntrl(void *param, s32 a1, s32 a2, s32 a3)
{
    *(s32*)((u8*)param + 0x0) = a1;
    *(f32*)((u8*)param + 0x14) = 0x1.657182p-4f;
    *(s32*)((u8*)param + 0xC) = a2;
    *(s32*)((u8*)param + 0x1C) = a3;
    *(f32*)((u8*)param + 0x18) = 0x1.657182p-4f;
    CAM_reset_camera_warp_cntrl(param);
}

extern const f32 D_40137220;

void CAM_reset_camera_warp_cntrl(void *param)
{
    *(s32*)((u8*)param + 0x4) = 0;
    *(s32*)((u8*)param + 0x8) = 0;
    *(s32*)((u8*)param + 0x10) = 0;
    *(s32*)((u8*)param + 0x20) = 0;
    *(s32*)((u8*)param + 0x24) = 0;
    *(s32*)((u8*)param + 0x28) = 0;
    *(s32*)((u8*)param + 0x2C) = 0;
    *(f32*)((u8*)param + 0x30) = *(f32*)((u8*)param + 0x34) = *(f32*)((u8*)param + 0x38) = D_40137220;
    *(f32*)((u8*)param + 0x3C) = 1.0f;
}

void func_400EA298(void *, void *);
void func_400EA350(void *, void *, float);
void func_400EA3B8(void *, void *, float, float, float);
void func_400EA4A8(void *, void *, float, float);

void CAM_doit_camera_warp_cntrl(void *a, void *b, float p, float q, float r, float t)
{
    func_400EA298(a, b);
    func_400EA350(a, b, t);
    func_400EA3B8(a, b, p, q, t);
    func_400EA4A8(a, b, r, t);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_act_warp_camera_warp_cntrl);

void CAM_set_invisible_warp_apply_range_camera_warp_cntrl(f32 a, f32 b, void *param)
{
    *(f32*)((u8*)param + 0x14) = a;
    *(f32*)((u8*)param + 0x18) = b;
}

void CAM_act_warp_order_camera_warp_cntrl(void *param)
{
    *(s32*)((u8*)param + 0x28) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_reset_view_cut_avoid_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_get_update_yaw_by_view_cut_avoid_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_get_update_pitch_by_view_cut_avoid_cntrl);

s32 CAM_is_acting_view_cut_avoid_cntrl(s32 *param)
{
    return *param != 0;
}

void CAM_set_param_view_cut_avoid_cntrl(f32 a, f32 b, void *param)
{
    *(f32*)((u8*)param + 0x94) = a;
    *(f32*)((u8*)param + 0x98) = b;
}

void CAM_reset_obstacle_avoid_cntrl(s32 *param)
{
    param[0] = 0;
    param[1] = 0;
    param[2] = 0;
    param[3] = 0;
    param[4] = 0;
}

int get_game_camera_cur_mode(void);

int CAM_is_need_obstacle_avoid_ofst(char *p)
{
    int mode = get_game_camera_cur_mode();
    if (mode == 1 && *(int *)(*(char **)(p + 0x2D24) + 0xA8) == mode && *(int *)(p + 0x2BA8) == *(int *)(*(char **)(p + 0x2D24) + 0xA8))
        return 1;
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_act_avoid_rot_obstacle_avoid_cntrl);

s32 CAM_is_use_obstacle_target_ofst_interp_coe(f32 a, f32 b)
{
    return a < b;
}

extern u128 ZeroPoint;
extern u128 ZeroVector;

void CAM_constructor_base_look_at(void *param)
{
    *(u128*)((u8*)param + 0x0) = ZeroPoint;
    *(u128*)((u8*)param + 0x10) = ZeroPoint;
    *(u128*)((u8*)param + 0x20) = ZeroVector;
    *(u128*)((u8*)param + 0x30) = ZeroVector;
    *(f32*)((u8*)param + 0x40) = *(f32*)((u8*)param + 0x44) = 0.0f;
}

int is_reset_or_lws_movie_or_cutout_game_camera(void *);
void func_400E6D98(void *, void *, int, float);
void func_400EA690(void *, void *, void *);

void CAM_doit_base_look_at(void *a, void *b, void *cam, void *d, float t)
{
    func_400E6D98(a, b, is_reset_or_lws_movie_or_cutout_game_camera(cam), t);
    func_400EA690(a, b, d);
}

typedef struct { f32 f[4]; } __attribute__((aligned(8))) V4;
extern V4 D_40137210;
void constructor_double_spring_interp_cntrl3D(char *, float, float);
void reset_double_spring_interp_cntrl3D(char *, V4 *);

void CAM_constructor_look_at_spring(char *c)
{
    V4 v = D_40137210;
    constructor_double_spring_interp_cntrl3D(c, 0x1.0624DCp-10f, 0.0f);
    constructor_double_spring_interp_cntrl3D(c + 0x40, 0x1.0624DCp-10f, 0.0f);
    reset_double_spring_interp_cntrl3D(c + 0x40, &v);
}

void func_400EA790(void *, int *, int, int, float);
void func_400EA848(void *, int *, int, float);

void CAM_doit_look_at_spring(void *a, int *b, void *c, float f)
{
    int r = is_reset_or_lws_movie_or_cutout_game_camera(c);
    func_400EA790(a, b, *b, r, f);
    func_400EA848(a, b, r, f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_reset_mode_ratio_follow_rot);

extern float func_400EA9A8(char *, float);
extern float func_400EA9C8(char *, void *, float);
extern float func_400EA9F0(char *, void *, float);
extern float func_400EAA20(void *, void *);
extern void func_400E70B0(char *, void *, float);
extern void func_400E7220(char *, void *, void *, float);

void CAM_doit_follow_rot(char *c, void *b, void *d, float t)
{
    *(float *)(c + 0x1A0) = func_400EA9A8(c, t);
    *(float *)(c + 0x1A4) = func_400EA9C8(c, d, t);
    *(float *)(c + 0x1A8) = func_400EA9F0(c, b, t);
    *(float *)(c + 0x1AC) = func_400EAA20(b, d);
    func_400E70B0(c, b, t);
    func_400E7220(c, b, d, t);
}

f32 func_400E9498(f32 a, f32 b)
{
    if (b <= a)
    {
        return 1.0f;
    }
    return a / b;
}

void func_400E94F0(void *param);
void GAMEUTIL_reset_interp_ratio_cntrl(void *cntrl);

void func_400E94C0(void *param)
{
    func_400E94F0(param);
    *(s32*)((u8*)param + 0x20) = 0;
    GAMEUTIL_reset_interp_ratio_cntrl((u8*)param + 0x24);
}

void func_400E94F0(void *param)
{
    *(s32*)((u8*)param + 0x4) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E94F8);

float func_400E9590(float a, float b, float c, int *p)
{
    float d1;
    float d2;
    if (*p == 0) {
        d1 = GAMEUTIL_get_difference_yaw_and_yaw(c, a);
        d2 = GAMEUTIL_get_difference_yaw_and_yaw(c, b);
    } else {
        d1 = GAMEUTIL_get_difference_pitch_and_pitch(c, a);
        d2 = GAMEUTIL_get_difference_pitch_and_pitch(c, b);
    }
    if (d1 < d2) {
        return a;
    }
    return b;
}

void func_400E9628(int *p, int flag, float a, float b)
{
    int r;
    if (p[0] == 1 || p[4] == 1) {
        p[1] = 1;
    } else if (p[1] == 1 || flag != 0) {
        r = GAMEUTIL_inc_or_dec_for_near_to_aim_yaw(0, a, 1.0f, b);
        if (r == 1) {
            p[1] = 2;
        } else if (r == -1) {
            p[1] = 3;
        } else {
            p[1] = 0;
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E96C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9730);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9900);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E99A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9B30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9DA0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9FF8);

s32 func_400EA0E8(s32 x)
{
    return (u32)(x - 3) < 2;
}

s32 func_400EA0F8(s32 x)
{
    return (u32)(x - 1) < 2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA108);

/* NEARMISS-STUB func_400EA1B0 */
#if 0 /* NEARMISS 99.0% cat=regalloc sub=- | loaded int uses v1 not v0; expected reuses v0 for lw and return | attempts=1 */
s32 func_400EA1B0(f32 x, void *param)
{
    if (*(s32*)((u8*)param + 0x5D4) != 0)
    {
        return 0;
    }
    return x <= *(f32*)((u8*)param + 0xD8);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA1B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA1D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA298);
