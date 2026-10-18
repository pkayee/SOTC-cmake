#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_add_local_offset_root_position);

u8 *GetLayoutClass(void *chara);
s32 GetMotionNodePos(void *pos, void *chara, s32 node_id, s32 flag);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_node_posi_by_id);
s32 GAMEUTIL_get_node_posi_by_id(void *pos, void *chara, s32 node_id)
{
    u8 *layout;
    s32 result = 0;

    if (chara != NULL)
    {
        if (node_id == -1)
        {
            layout = GetLayoutClass(chara);
            *(u128 *)pos = *(u128 *)(*(u8 **)(layout + 0x134));
        }
        else
        {
            GetMotionNodePos(pos, chara, node_id, 1);
        }
        result = 1;
    }
    return result;
}

s32 GAMEUTIL_get_node_quaternion_posi_by_id_extend(void *pos0, void *pos1, void *chara, s32 node_id, s32 flag0, s32 flag1);

s32 GAMEUTIL_get_node_quaternion_posi_by_id(void *pos0, void *pos1, void *chara, s32 node_id)
{
    return GAMEUTIL_get_node_quaternion_posi_by_id_extend(pos0, pos1, chara, node_id, 0, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_node_quaternion_posi_by_id_extend);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inside_of_region_ratio);

/* NEARMISS-STUB GAMEUTIL_get_new_velocity */
#if 0 /* NEARMISS 53.0% cat=branch-layout sub=- | diff<0 check order, folded -0.01 compare | attempts=1 */
f32 GAMEUTIL_get_new_velocity(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    f32 result = b;
    f32 diff = a - b;

    if (0.0f <= diff || ((diff < 0.0f) ? -diff : diff) <= 0.01f)
    {
        result = a + c * e;
    }
    if (d < result)
    {
        result = d;
    }
    return result;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_new_velocity);

f32 GAMEUTIL_get_new_velocity_by_brake_abs(f32 velocity, f32 brake, f32 min_velocity, f32 decel);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_new_velocity_by_brake);
f32 GAMEUTIL_get_new_velocity_by_brake(f32 velocity, f32 brake, f32 min_velocity, f32 decel)
{
    f32 result;
    f32 abs_velocity = velocity;

    if (velocity < 0.0f)
    {
        abs_velocity = -velocity;
    }
    result = GAMEUTIL_get_new_velocity_by_brake_abs(abs_velocity, brake, min_velocity, decel);
    if (0.0f <= velocity)
    {
        return result;
    }
    return -result;
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_velocity_by_diff_move);
f32 GAMEUTIL_get_velocity_by_diff_move(s32 flag, f32 velocity, f32 value1, f32 value2, f32 time)
{
    f32 result = velocity;

    if (time != 0.0f)
    {
        result = (value2 - value1) / time;
        if (flag != 0 && result < 0.0f)
        {
            result = -result;
        }
    }
    return result;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_velocity_by_diff_move3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_vector_velocity_by_diff_move3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_limit_position);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_limit_position3D);

/* NEARMISS-STUB GAMEUTIL_get_vel_limit_position */
#if 0 /* NEARMISS 61.0% cat=branch-layout sub=- | gcc shares return epilogue / hoists mov.s into delay slot; target separate copy | attempts=1 */
f32 GAMEUTIL_get_vel_limit_position(f32 cur, f32 target, f32 vel, f32 scale)
{
    f32 diff;

    if (0.0f <= vel)
    {
        vel = vel * scale;
        diff = target - cur;
        if (diff < 0.0f)
        {
            if (-diff <= vel)
            {
                return target;
            }
        }
        else if (diff <= vel)
        {
            return target;
        }
        if (0.0f <= diff)
        {
            return cur + vel;
        }
        return cur - vel;
    }
    else
    {
        return target;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_vel_limit_position);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inverse_move_direction);

/* NEARMISS-STUB GAMEUTIL_mul_ratio */
#if 0 /* NEARMISS 89.0% cat=regalloc sub=- | result in f1/1.0f in f0 vs target f0/f1 with beqzl to shared jr ra | attempts=1 */
f32 GAMEUTIL_mul_ratio(s32 kind, f32 value, f32 ratio)
{
    f32 result;

    if (kind != 0)
    {
        if (ratio <= 0.0f)
        {
            result = 0.0f;
        }
        else if (1.0f <= ratio)
        {
            result = value;
        }
        else
        {
            result = ratio * value;
        }
    }
    else
    {
        result = ratio * value;
    }
    return result;
}
#endif
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

f32 iosGetACosfExact(f32 x);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_convert_from_cos_to_linear_ratio);
f32 GAMEUTIL_convert_from_cos_to_linear_ratio(f32 cos)
{
    return 1.0f - iosGetACosfExact(cos) / 3.14159265f;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_act_axis_rot_root_quaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_act_axis_rot_root_quaternion_abs);

f32 GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(f32 yaw1, f32 yaw2);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_difference_value);
f32 GAMEUTIL_get_difference_value(s32 kind, f32 value1, f32 value2)
{
    if (kind == 1)
    {
        return GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(value1, value2);
    }
    return value2 - value1;
}

f32 GAMEUTIL_increase_yaw(s32 kind, f32 value1, f32 value2);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_increase_value);
f32 GAMEUTIL_get_increase_value(s32 kind, f32 value1, f32 value2)
{
    if (kind == 1)
    {
        return GAMEUTIL_increase_yaw(0, value1, value2);
    }
    return value1 + value2;
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_difference_yaw_and_yaw);
f32 GAMEUTIL_get_difference_yaw_and_yaw(f32 yaw1, f32 yaw2)
{
    f32 diff = yaw2 - yaw1;

    if (diff < 0.0f)
    {
        diff = -diff;
    }
    if (3.1415926f < diff)
    {
        diff = 6.2831852f - diff;
    }
    return diff;
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_radi_from_yaw1_to_yaw2);
f32 GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(f32 yaw1, f32 yaw2)
{
    f32 diff = yaw2 - yaw1;
    s32 flag;

    if (diff < 0.0f)
    {
        diff = -diff;
    }
    flag = 1;
    if (yaw2 < yaw1)
    {
        flag = 0;
    }
    if (3.1415926f < diff)
    {
        diff = 6.2831852f - diff;
        flag = !flag;
    }
    if (flag != 0)
    {
        return diff;
    }
    return -diff;
}

f32 GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(f32 pitch1, f32 pitch2)
{
    return pitch2 - pitch1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_between_yaw_and_yaw);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_between_yaw_and_yaw_extend_abs);

s32 GAMEUTIL_is_between_pitch_and_pitch(f32 value, f32 min, f32 max)
{
    if ((min <= value && value <= max) || (max <= value && value <= min))
    {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inside_of_region_yaw);
