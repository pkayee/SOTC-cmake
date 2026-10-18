#include "common.h"

void GAMEUTIL_destructor_record_info(void *info);
s32 GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(void *cntrl);
s32 GAMEUTIL_get_interp_timer_interp_ratio_cntrl(void *cntrl);
void GAMEUTIL_reset_interp_ratio_cntrl(void *cntrl);
void GAMEUTIL_set_param_interp_ratio_cntrl();
void GAMEUTIL_set_param_extend_interp_ratio_cntrl();
s32 GAMEUTIL_is_inside_of_region_yaw();
s32 GAMEUTIL_is_inside_of_region_pitch();
void GAMEUTIL_constructor_position_filter(void *a0);
void GAMEUTIL_reset_status_manager(void *a0, s32 a1);
void GAMEUTIL_reset_collision_info(void *a0);
void GAMEUTIL_constructor_interp_ratio_cntrl(void *a0);
void GAMEUTIL_forward_timer_still_one_ratio_time_interp_ratio_cntrl(void *a0);
s32 GAMEUTIL_is_horse_obj(void *a0);
void GAMEUTIL_get_horse_move_status(s32 *a0, void *a1);
void *GAMEUTIL_get_motion_kind(void *chara);
u8 *GetLayoutClass(void *chara);
void func_400E94F0(void *a0);
void func_400E94C0(void *param);
void GAMEUTIL_set_act_max_zero_clip_flag_interp_ratio_cntrl(void *a0, s32 a1);
extern u128 ZeroVector;

void *CAM_get_ground_contact_obj(u8 *a0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_camera_position_by_look_at);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_camera_space_axisXY);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_new_look_at_posi_from_camera_posi_and_rotXY);

f32 GAMEUTIL_get_cos_ratio(f32 a, f32 b, f32 c, f32 d);

f32 CAM_get_interp_ratio_by_time(s32 mode, f32 a, f32 b, f32 t, f32 bias)
{
    f32 r = 1.0f;

    if (0.0f < t)
    {
        r = GAMEUTIL_get_cos_ratio(a, b, 0.0f, t);
    }
    if (mode == 0)
    {
        r = 1.0f - r;
    }
    if (0.0f < bias)
    {
        r = r * (1.0f - bias) + bias;
    }
    return r;
}

s32 camera_collision_check_direct(void *a0, void *a1, void *a2, void *a3, void *a4, s32 a5, void *a6, s32 a7);
void ConvertFromCollisionPointToDynamics(void *a0, void *a1);

s32 CAM_act_ray_check_for_camera(void *out, void *a, void *b, void *c, void *d, void *e)
{
    u8 buf[0x50];
    s32 r;

    r = camera_collision_check_direct(buf, a, b, c, d, 0, e, 1) == 0;
    if (!r)
    {
        if (out != NULL)
        {
            ConvertFromCollisionPointToDynamics(out, buf);
        }
    }
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_add_plane_offset_in_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_mul_ratio_offset_per_axis);

typedef union { s128 q; f32 f[4]; s32 i[4]; } Vec4;

void CAM_set_all_camera_base_data(u8 *pa0, u8 *pa1, u8 *pa2, f32 f12, f32 f13, f32 f14)
{
    ((Vec4 *)(pa0 + 0x0))->q = ((Vec4 *)(pa1 + 0x0))->q;
    ((Vec4 *)(pa0 + 0x10))->q = ((Vec4 *)(pa2 + 0x0))->q;
    ((Vec4 *)(pa0 + 0x20))->f[0] = f12;
    ((Vec4 *)(pa0 + 0x24))->f[0] = f13;
    ((Vec4 *)(pa0 + 0x28))->f[0] = f14;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_interp_reset_aim_rot_common);
void CAM_interp_reset_aim_rot_common(u8 *a0)
{
    *(s32 *)(a0 + 0x20) = 1;
}

void CAM_set_clip_max_rot_vel_aim_rot_common(u8 *a0, f32 f12)
{
    *(f32 *)(a0 + 0xC) = f12 * 3.1415926f / 180.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_set_yaw_shortest_rot_flag_aim_rot_common);
void CAM_set_yaw_shortest_rot_flag_aim_rot_common(u8 *a0, s32 a1)
{
    *(s32 *)(a0 + 0x10) = a1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_set_interp_param_aim_rot_common);
void CAM_set_interp_param_aim_rot_common(u8 *a0)
{
    if (*(s32 *)(a0 + 0x20) == 0)
    {
        GAMEUTIL_set_param_interp_ratio_cntrl(a0 + 0x24);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_set_interp_param_extend_aim_rot_common);
void CAM_set_interp_param_extend_aim_rot_common(u8 *a0)
{
    if (*(s32 *)(a0 + 0x20) == 0)
    {
        GAMEUTIL_set_param_extend_interp_ratio_cntrl(a0 + 0x24);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_is_inside_of_stop_region_aim_rot_common);
s32 CAM_is_inside_of_stop_region_aim_rot_common(u8 *a0)
{
    return *(s32 *)(a0 + 0x8);
}

typedef struct
{
    s32 target;
    s32 a;
    s32 b;
    f32 c;
    s32 d;
    f32 max;
    f32 min;
    s32 e;
    s32 f;
    u8 interp[1];
} AimRot;

void CAM_init_aim_angle_rot(AimRot *r, s32 target)
{
    r->target = 0;
    r->a = 0;
    r->b = 0;
    r->c = -1.0f;
    r->d = 1;
    r->max = 1.48352957f;
    r->min = -1.48352957f;
    r->e = 1;
    r->f = 0;
    GAMEUTIL_constructor_interp_ratio_cntrl(r->interp);
    GAMEUTIL_set_act_max_zero_clip_flag_interp_ratio_cntrl(r->interp, 1);
    r->target = target;
    func_400E94C0(r);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_reset_aim_angle_rot);
void CAM_reset_aim_angle_rot(u8 *a0)
{
    func_400E94F0(a0);
    *(s32 *)(a0 + 0x20) = 0;
    GAMEUTIL_reset_interp_ratio_cntrl(a0 + 0x24);
}

s32 CAM_is_inside_of_region_aim_angle_rot(void *a0, void *a1, s32 *a2)
{
    if (*a2 == 0)
    {
        return GAMEUTIL_is_inside_of_region_yaw(a0, a1, a2);
    }
    return GAMEUTIL_is_inside_of_region_pitch(a0, a1, a2);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_constructor_target);
void GAMEUTIL_reset_interp_value_cntrl(void *a0, f32 f12);
void GAMEUTIL_init_record_info(void *a0, s32 a1, s32 a2, s32 a3, s32 a4);

void CAM_constructor_target(u8 *a0, s32 a1)
{
    *(s32 *)(a0 + 0x4) = 0xFF676980;
    *(s32 *)(a0 + 0x8) = 0xFF676980;
    *(s32 *)(a0 + 0x0) = 0;
    *(s32 *)(a0 + 0xC) = 0;
    GAMEUTIL_constructor_interp_ratio_cntrl(a0 + 0x10);
    *(s32 *)(a0 + 0x30) = 0;
    *(s32 *)(a0 + 0x124) = 0;
    *(s32 *)(a0 + 0x218) = 0;
    *(u128 *)(a0 + 0x310) = ZeroVector;
    *(u128 *)(a0 + 0x320) = ZeroVector;
    GAMEUTIL_reset_interp_value_cntrl(a0 + 0x330, 0.0f);
    *(s32 *)(a0 + 0x33C) = 0;
    GAMEUTIL_init_record_info(a0 + 0x340, 4, 0x1E, a1, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_destructor_target);
void CAM_destructor_target(u8 *a0)
{
    GAMEUTIL_destructor_record_info(a0 + 0x340);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_is_motion_kind_change_target);
s32 CAM_is_motion_kind_change_target(u8 *a0)
{
    return *(s32 *)(a0 + 0xC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_motion_kind_target_offset_target);
void CAM_get_motion_kind_target_offset_target(u128 *a0, u8 *a1)
{
    if (*(s32 *)(a1 + 0x124) != 0 && *(s32 *)(a1 + 0x8) != (s32)0xFF676980)
    {
        *a0 = *(u128 *)(a1 + 0x320);
        return;
    }
    *a0 = ZeroVector;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_motion_kind_interp_timer_target);
s32 CAM_get_motion_kind_interp_timer_target(u8 *a0)
{
    return GAMEUTIL_get_interp_timer_interp_ratio_cntrl(a0 + 0x10);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_motion_kind_interp_ratio_target);
s32 CAM_get_motion_kind_interp_ratio_target(u8 *a0)
{
    return GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(a0 + 0x10);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_is_look_around_motion_target);
u32 CAM_motion_kind_is_look_around_motion_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 27) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_act_auto_yaw_rot_target);
u32 CAM_motion_kind_act_auto_yaw_rot_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 28) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_is_accept_auto_rot_motion_target);
u32 CAM_motion_kind_is_accept_auto_rot_motion_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 29) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_is_accept_follow_rot_motion_target);
u32 CAM_motion_kind_is_accept_follow_rot_motion_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 30) & 1;
}

int CAM_get_motion_kind_follow_rot_axis_attr_target(int *camera)
{
    int temp_v0_2;
    void *temp_v0;

    temp_v0_2 = CAM_get_ground_contact_obj(camera);
    if (temp_v0_2 != 0)
    {
        temp_v0 = GAMEUTIL_get_motion_kind(temp_v0_2);
        if (temp_v0 != NULL)
        {
            return (*(int *)((char *)(temp_v0) + 0x6C)) & 0xF;
        }
    }
    return 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_is_mode_lock_target);
u32 CAM_motion_kind_is_mode_lock_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 37) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_get_interest_dir_reset_attr_target);
s32 CAM_motion_kind_get_interest_dir_reset_attr_target(u8 *a0)
{
    u32 v = (u32)(*(u64 *)(a0 + 0x190) >> 39) & 3;
    void *obj;
    void *motion;

    if (v != 0)
    {
        return v;
    }
    obj = *(void **)(a0 + 0x33C);
    if (obj != NULL)
    {
        if (GAMEUTIL_get_motion_kind(obj) != NULL)
        {
            motion = GAMEUTIL_get_motion_kind(*(void **)(a0 + 0x33C));
            return (*(u32 *)((u8 *)motion + 0x6C) >> 7) & 3;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_set_target_display_flag);
void CAM_set_target_display_flag(u8 *a0, s32 a1)
{
    void *chara = *(void **)a0;

    if (chara != NULL)
    {
        u8 *layout = GetLayoutClass(chara);
        u8 *obj = *(u8 **)(layout + 0x144);

        *(u64 *)(obj + 0x280) = (*(u64 *)(obj + 0x280) & ~0x10UL) | ((a1 & 1) << 4);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_target_obj);
void *CAM_get_target_obj(u8 *a0)
{
    return *(void **)a0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_target_riding_obj);
void *CAM_get_target_riding_obj(u8 *a0)
{
    return *(void **)(a0 + 0x33C);
}

void *CAM_get_ground_contact_obj(u8 *a0)
{
    void *obj = *(void **)(a0 + 0x33C);

    if (obj != NULL)
    {
        return obj;
    }
    return *(void **)a0;
}

/* NEARMISS-STUB CAM_is_target_float */
#if 0 /* NEARMISS 78.97% cat=branch-layout sub=- | inner clamp if becomes bnel not beqz+b; return-1 bounces via extra branch | attempts=1 */
u8 *GAMEUTIL_get_data_record_info(u8 *r, s32 idx);

s32 CAM_is_target_float(u8 *a0, s32 a1)
{
    s32 i;
    s32 n;
    s32 next;
    u8 *p;

    n = a1;
    if (0 < n)
    {
        if (*(s32 *)(a0 + 0x34C) < n)
        {
            n = *(s32 *)(a0 + 0x34C);
        }
    }
    else
    {
        n = *(s32 *)(a0 + 0x34C);
    }
    i = 0;
    if (0 < n)
    {
        do
        {
            next = i + 1;
            p = GAMEUTIL_get_data_record_info(a0 + 0x340, i);
            if (*(s32 *)p == 1)
            {
                return 1;
            }
            i = next;
        } while (next < n);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_is_target_float);

/* NEARMISS-STUB CAM_is_target_fast_moving */
#if 0 /* NEARMISS 86.32% cat=branch-layout sub=- | movn for ret/ early-return shape differs; target has branch-based status clamp | attempts=2 */
u64 CAM_is_target_fast_moving(u8 *a0)
{
    u32 status;
    void *target;
    void *obj;
    u64 ret;

    obj = *(void **)(a0 + 0x33C);
    if (obj != NULL)
    {
        target = obj;
    }
    else
    {
        target = *(void **)a0;
    }
    if (GAMEUTIL_is_horse_obj(target) == 1)
    {
        status = 0;
        GAMEUTIL_get_horse_move_status((s32 *)&status, target);
        if (status >= 5)
        {
            return 0;
        }
        ret = 1;
        if (status < 3)
        {
            return 0;
        }
        return ret;
    }
    ret = (*(u64 *)(a0 + 0x190) >> 36) & 1;
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_is_target_fast_moving);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_constructor_target_visibility);
void CAM_constructor_target_visibility(u8 *a0)
{
    u8 *s1;

    GAMEUTIL_constructor_position_filter(a0);
    s1 = a0 + 0x110;
    *(s32 *)(a0 + 0x30) = 0;
    GAMEUTIL_reset_status_manager(a0 + 0x34, 0);
    *(s32 *)(a0 + 0x44) = 0;
    GAMEUTIL_reset_collision_info(a0 + 0x50);
    GAMEUTIL_reset_collision_info(a0 + 0xB0);
    GAMEUTIL_constructor_interp_ratio_cntrl(s1);
    ((void (*)(void *, f32, f32))GAMEUTIL_set_param_interp_ratio_cntrl)(s1, 0.0f, 1.5f);
    GAMEUTIL_forward_timer_still_one_ratio_time_interp_ratio_cntrl(s1);
    *(s32 *)(a0 + 0x130) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_doit_objective_target_visibility);
