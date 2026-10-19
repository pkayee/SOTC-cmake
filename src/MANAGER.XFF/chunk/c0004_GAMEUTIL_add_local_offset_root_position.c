#include "common.h"

s32 GAMEUTIL_is_between_yaw_and_yaw_extend_abs(f32 yaw, f32 a, f32 lo, f32 hi);

f32 GAMEUTIL_get_difference_yaw_and_yaw(f32 yaw1, f32 yaw2);

static inline s32 yawBetween(f32 value, f32 min, f32 max)
{
    f32 d = min - max;
    s32 wrap = 0;
    s32 ret;

    if ((d < 0.0f) ? (d < -3.1415926f) : (3.1415926f < d))
    {
        wrap = 1;
    }
    if ((min <= value && value <= max) || (max <= value && value <= min))
    {
        ret = wrap == 0;
    }
    else
    {
        ret = wrap != 0;
    }
    return ret;
}

static inline f32 yawDiff(f32 yaw1, f32 yaw2)
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

static inline s32 is_nearly_zero(f32 x, f32 eps)
{
    if (x < 0.0f)
    {
        if (-x <= eps)
        {
            goto yes;
        }
        else
        {
            goto no;
        }
    }
    else
    {
        if (x <= eps)
        {
            goto yes;
        }
        else
        {
            goto no;
        }
    }
yes:
    return 1;
no:
    return 0;
}

f32 GAMEUTIL_get_new_velocity(f32 vel, f32 min, f32 accel, f32 max, f32 dt)
{
    f32 v = min;
    f32 d = vel - min;

    if (d >= 0.0f || is_nearly_zero(d, 0.01f) == 1)
    {
        v = vel + accel * dt;
    }
    if (max < v)
    {
        v = max;
    }
    return v;
}

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

f32 GAMEUTIL_get_move_limit_position(f32 *ratio, f32 cur, f32 target, f32 speed, f32 dt)
{
    f32 diff = target - cur;
    f32 step;

    if (diff < 0.0f)
    {
        step = speed * dt;
        if (-diff <= step)
        {
            goto reach;
        }
        goto move;
    }
    step = speed * dt;
    if (diff <= step)
    {
reach:
        if (ratio != NULL)
        {
            if (dt != 0.0f)
            {
                speed = diff / dt;
                if (speed < 0.0f)
                {
                    speed = -speed;
                }
            }
            *ratio = speed;
        }
        return target;
    }
move:
    if (ratio != NULL)
    {
        *ratio = speed;
    }
    if (diff > 0.0f)
    {
        return cur + step;
    }
    return cur - step;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_get_move_limit_position3D);

f32 GAMEUTIL_get_vel_limit_position(f32 cur, f32 target, f32 vel, f32 scale)
{
    f32 diff;

    if (0.0f <= vel)
    {
        vel = vel * scale;
        diff = target - cur;
        if ((diff < 0.0f ? -diff : diff) <= vel)
        {
            return target;
        }
        if (0.0f <= diff)
        {
            return cur + vel;
        }
        return cur - vel;
    }
    return target;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_is_inverse_move_direction);

f32 GAMEUTIL_mul_ratio(s32 clamp, f32 a, f32 r)
{
    if (clamp != 0)
    {
        if (r <= 0.0f)
        {
            return 0.0f;
        }
        if (1.0f <= r)
        {
            return a;
        }
    }
    return r * a;
}

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

typedef union
{
    s128 q;
    f32 f[4];
    s32 i[4];
} Vec4;

extern void SetQuaternionByAxisRotate(Vec4 *, s16, f32, f32, f32);
extern void func_4001C2D0(void *, Vec4 *);

void GAMEUTIL_act_axis_rot_root_quaternion_abs(void *q, f32 *axis, f32 ang)
{
    Vec4 r;

    SetQuaternionByAxisRotate(&r, -(s32)(ang * 32768.0f / 3.1415926f), axis[0], axis[1], axis[2]);
    func_4001C2D0(q, &r);
}

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

f32 GAMEUTIL_increase_yaw(s32 *moved, f32 yaw, f32 delta);

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

extern f32 func_4001C350(f32);

f32 GAMEUTIL_increase_yaw(s32 *moved, f32 yaw, f32 delta)
{
    s32 m = 0;
    f32 y = yaw;

    if (is_nearly_zero(delta, 0.0001f) == 0)
    {
        y = func_4001C350(yaw + delta);
        m = 1;
    }
    if (moved != NULL)
    {
        *moved = m;
    }
    return y;
}

f32 GAMEUTIL_increase_yaw_limit_extend(s32 *moved, s32 min_clip, s32 max_clip, s32 mode, f32 yaw, f32 delta, f32 lo, f32 hi);

f32 GAMEUTIL_increase_yaw_limit(s32 *a0, s32 a1, f32 yaw, f32 delta, f32 lo, f32 hi)
{
    return GAMEUTIL_increase_yaw_limit_extend(a0, 1, 1, a1, yaw, delta, lo, hi);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0004_GAMEUTIL_add_local_offset_root_position", GAMEUTIL_increase_yaw_region);

f32 GAMEUTIL_increase_yaw_limit_clip_extend(s32 *moved, s32 min_clip, s32 max_clip, s32 mode, f32 yaw, f32 delta, f32 lo, f32 hi);

f32 GAMEUTIL_increase_yaw_limit_clip(s32 *a0, s32 a1, f32 yaw, f32 delta, f32 lo, f32 hi)
{
    return GAMEUTIL_increase_yaw_limit_clip_extend(a0, 1, 1, a1, yaw, delta, lo, hi);
}

f32 GAMEUTIL_increase_yaw_limit_clip_extend(s32 *out, s32 min_clip, s32 max_clip, s32 mode, f32 yaw, f32 delta, f32 lo, f32 hi)
{
    s32 moved = 0;
    f32 r = GAMEUTIL_increase_yaw_limit_extend(&moved, min_clip, max_clip, mode, yaw, delta, lo, hi);

    if (GAMEUTIL_is_between_yaw_and_yaw(r, lo, hi) == 0)
    {
        f32 d1 = GAMEUTIL_get_difference_yaw_and_yaw(r, lo);
        f32 d2 = GAMEUTIL_get_difference_yaw_and_yaw(r, hi);

        if (d1 <= d2)
        {
            if (min_clip == 1)
            {
                moved = 1;
                r = lo;
            }
        }
        else if (max_clip == 1)
        {
            moved = 1;
            r = hi;
        }
    }
    if (out != NULL)
    {
        *out = moved;
    }
    return r;
}

f32 GAMEUTIL_get_limit_clip_yaw_abs(f32 yaw, f32 a, f32 lo, f32 hi, s32 *clipped)
{
    s32 flag = 0;
    f32 ret = yaw;

    if (GAMEUTIL_is_between_yaw_and_yaw_extend_abs(yaw, a, lo, hi) == 0)
    {
        f32 r = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(a, yaw);

        ret = lo;
        if (!(0.0f <= r))
        {
            ret = hi;
        }
        flag = 1;
    }
    if (clipped != NULL)
    {
        *clipped = flag;
    }
    return ret;
}

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

f32 GAMEUTIL_get_difference_yaw_and_yaw_extend(s32 *out, s32 mode, f32 yaw1, f32 yaw2, f32 test)
{
    s32 flag = 1;
    f32 d = yawDiff(yaw1, yaw2);

    if (mode == 1 && GAMEUTIL_is_between_yaw_and_yaw(test, yaw1, yaw2) == 0)
    {
        f32 a = yawDiff(yaw1, test);
        f32 b = yawDiff(yaw2, test);

        if (b < a)
        {
            a = b;
        }
        if (3.1415923f < d + a)
        {
            flag = 0;
            d = 6.2831846f - d;
        }
    }
    if (out != NULL)
    {
        *out = flag;
    }
    return d;
}

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

s32 GAMEUTIL_is_between_yaw_and_yaw(f32 value, f32 min, f32 max)
{
    f32 d = min - max;
    s32 wrap = 0;
    s32 ret;

    if ((d < 0.0f) ? (d < -3.1415926f) : (3.1415926f < d))
    {
        wrap = 1;
    }
    if ((min <= value && value <= max) || (max <= value && value <= min))
    {
        ret = wrap == 0;
    }
    else
    {
        ret = wrap != 0;
    }
    return ret;
}

s32 GAMEUTIL_is_between_yaw_and_yaw_extend_abs(f32 value, f32 min, f32 max1, f32 max2)
{
    if (yawBetween(value, min, max1) == 1 || yawBetween(value, min, max2) == 1)
    {
        return 1;
    }
    return 0;
}

s32 GAMEUTIL_is_between_pitch_and_pitch(f32 value, f32 min, f32 max)
{
    if ((min <= value && value <= max) || (max <= value && value <= min))
    {
        return 1;
    }
    return 0;
}

s32 GAMEUTIL_is_inside_of_region_yaw(f32 value, f32 center, f32 width, f32 *out_lo, f32 *out_hi)
{
    f32 half = width * 0.5f;
    f32 lo = center;
    f32 hi;
    f32 neg;

    if (is_nearly_zero(half, 0.0001f) == 0)
    {
        lo = func_4001C350(center + half);
    }
    neg = -half;
    hi = center;
    if (is_nearly_zero(neg, 0.0001f) == 0)
    {
        hi = func_4001C350(center + neg);
    }
    if (out_lo != NULL)
    {
        *out_lo = lo;
    }
    if (out_hi != NULL)
    {
        *out_hi = hi;
    }
    return yawBetween(value, lo, hi);
}
