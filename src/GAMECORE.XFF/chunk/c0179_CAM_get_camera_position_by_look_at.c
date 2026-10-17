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
extern u128 ZeroVector;

void *CAM_get_ground_contact_obj(u8 *a0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_camera_position_by_look_at);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_camera_space_axisXY);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_new_look_at_posi_from_camera_posi_and_rotXY);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_interp_ratio_by_time);

/* NEARMISS-STUB CAM_act_ray_check_for_camera */
#if 0 /* NEARMISS 84.1% cat=regalloc sub=- | dead a5-a7 moves at entry, bnezl vs bnez | attempts=1 */
s32 camera_collision_check_direct(void *info);
void ConvertFromCollisionPointToDynamics(void *a0, void *a1);

s32 CAM_act_ray_check_for_camera(void *a0)
{
    u8 info[0x50];
    s32 ret;

    ret = (camera_collision_check_direct(info) == 0);
    if (ret != 0)
    {
        return ret;
    }
    if (a0 != NULL)
    {
        ConvertFromCollisionPointToDynamics(a0, info);
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_act_ray_check_for_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_add_plane_offset_in_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_mul_ratio_offset_per_axis);

/* NEARMISS-STUB CAM_set_all_camera_base_data */
#if 0 /* NEARMISS 41.1% cat=sched sub=- | u128 copy order and f12-f14 store placement | attempts=1 */
void CAM_set_all_camera_base_data(u8 *a0, u128 *a1, u128 *a2, f32 f12, f32 f13, f32 f14)
{
    *(u128 *)a0 = *a1;
    *(f32 *)(a0 + 0x20) = f12;
    *(f32 *)(a0 + 0x24) = f13;
    *(f32 *)(a0 + 0x28) = f14;
    *(u128 *)(a0 + 0x10) = *a2;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_set_all_camera_base_data);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_init_aim_angle_rot);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_constructor_target);

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

/* NEARMISS-STUB CAM_get_motion_kind_follow_rot_axis_attr_target */
#if 0 /* NEARMISS 62.2% cat=branch-layout sub=- | null-check chain shape vs beql delay-slot | attempts=1 */
s32 CAM_get_motion_kind_follow_rot_axis_attr_target(u8 *a0)
{
    void *obj = CAM_get_ground_contact_obj(a0);
    void *motion;

    if (obj == NULL)
    {
        return 1;
    }
    motion = GAMEUTIL_get_motion_kind(obj);
    if (motion == NULL)
    {
        return 1;
    }
    return *(s32 *)((u8 *)motion + 0x6C) & 0xF;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_get_motion_kind_follow_rot_axis_attr_target);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_is_mode_lock_target);
u32 CAM_motion_kind_is_mode_lock_target(u8 *a0)
{
    return (u32)(*(u64 *)(a0 + 0x190) >> 37) & 1;
}

/* NEARMISS-STUB CAM_motion_kind_get_interest_dir_reset_attr_target */
#if 0 /* NEARMISS 85.7% cat=regalloc sub=- | obj kept in v1 vs v0, v0=0 hoist | attempts=1 */
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
    if (obj == NULL)
    {
        return 0;
    }
    if (GAMEUTIL_get_motion_kind(obj) == NULL)
    {
        return 0;
    }
    motion = GAMEUTIL_get_motion_kind(*(void **)(a0 + 0x33C));
    return (*(u32 *)((u8 *)motion + 0x6C) >> 7) & 3;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_motion_kind_get_interest_dir_reset_attr_target);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0179_CAM_get_camera_position_by_look_at", CAM_is_target_float);

/* NEARMISS-STUB CAM_is_target_fast_moving */
#if 0 /* NEARMISS 39.8% cat=branch-layout sub=- | horse status branch structure and bit extract | attempts=1 */
s32 CAM_is_target_fast_moving(u8 *a0)
{
    void *obj = *(void **)(a0 + 0x33C);
    s32 status = 0;

    if (obj == NULL)
    {
        obj = *(void **)a0;
    }
    if (GAMEUTIL_is_horse_obj(obj) == 1)
    {
        GAMEUTIL_get_horse_move_status(&status, obj);
        return status >= 3 && status < 5;
    }
    return (u32)(*(u64 *)(a0 + 0x190) >> 36) & 1;
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
