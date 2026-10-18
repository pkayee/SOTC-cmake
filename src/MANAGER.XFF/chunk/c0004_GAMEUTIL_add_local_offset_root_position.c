#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_add_local_offset_root_position);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_node_posi_by_id);

s32 GAMEUTIL_get_node_quaternion_posi_by_id_extend(void *pos0, void *pos1, void *chara, s32 node_id, s32 flag0, s32 flag1);

s32 GAMEUTIL_get_node_quaternion_posi_by_id(void *pos0, void *pos1, void *chara, s32 node_id)
{
    return GAMEUTIL_get_node_quaternion_posi_by_id_extend(pos0, pos1, chara, node_id, 0, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_node_quaternion_posi_by_id_extend);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inside_of_region_ratio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_new_velocity);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_new_velocity_by_brake);

f32 GAMEUTIL_get_new_velocity_by_brake_abs(f32 velocity, f32 brake, f32 min_velocity, f32 decel)
{
    f32 new_velocity = min_velocity;

    if (0.0f <= brake)
    {
        new_velocity = velocity - brake * decel;
        if (new_velocity < min_velocity)
        {
            new_velocity = min_velocity;
        }
    }
    return new_velocity;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_velocity_by_diff_move);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_velocity_by_diff_move3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_vector_velocity_by_diff_move3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_limit_position);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_limit_position3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_vel_limit_position);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inverse_move_direction);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_mul_ratio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_check_and_get_normalize_vector);

void *GetCharacterClass(void *obj);

void *GAMEUTIL_get_motion_kind(void *chara)
{
    u8 *cc = GetCharacterClass(chara);

    if (cc != NULL)
    {
        return *(void **)(cc + 0x568);
    }
    return cc;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_divide_vector_value);

void iosGetExceptAxisVector(void);

void GAMEUTIL_get_except_axis_vector(void)
{
    iosGetExceptAxisVector();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_convert_from_cos_to_linear_ratio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_act_axis_rot_root_quaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_act_axis_rot_root_quaternion_abs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_difference_value);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_increase_value);

s32 GAMEUTIL_is_between_yaw_and_yaw(f32 value, f32 min, f32 max);
s32 GAMEUTIL_is_between_pitch_and_pitch(f32 value, f32 min, f32 max);

s32 GAMEUTIL_is_between_value(s32 kind, f32 value, f32 min, f32 max)
{
    if (kind == 1)
    {
        return GAMEUTIL_is_between_yaw_and_yaw(value, min, max);
    }
    return GAMEUTIL_is_between_pitch_and_pitch(value, min, max);
}

s32 GAMEUTIL_is_max_input(f32 x, f32 y)
{
    return 0.98999995f < x * x + y * y;
}

void GAMEUTIL_convert_from_lw_to_game_coord(f32 *pos)
{
    pos[0] = -pos[0];
    pos[2] = -pos[2];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_yaw);

s32 GAMEUTIL_increase_yaw_limit_extend();

s32 GAMEUTIL_increase_yaw_limit(void *a0, void *a1)
{
    return GAMEUTIL_increase_yaw_limit_extend(a0, 1, 1, a1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_yaw_region);

s32 GAMEUTIL_increase_yaw_limit_clip_extend();

s32 GAMEUTIL_increase_yaw_limit_clip(void *a0, void *a1)
{
    return GAMEUTIL_increase_yaw_limit_clip_extend(a0, 1, 1, a1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_yaw_limit_clip_extend);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_limit_clip_yaw_abs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_pitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_pitch_limit_clip);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_difference_yaw_and_yaw);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_difference_yaw_and_yaw_extend);

f32 GAMEUTIL_get_difference_pitch_and_pitch(f32 pitch1, f32 pitch2)
{
    f32 diff = pitch2 - pitch1;

    if (diff < 0.0f)
    {
        diff = -diff;
    }
    return diff;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_radi_from_yaw1_to_yaw2);

f32 GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(f32 pitch1, f32 pitch2)
{
    return pitch2 - pitch1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_between_yaw_and_yaw);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_between_yaw_and_yaw_extend_abs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_between_pitch_and_pitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inside_of_region_yaw);
