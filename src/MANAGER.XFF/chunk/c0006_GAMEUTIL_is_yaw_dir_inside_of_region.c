#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_yaw_dir_inside_of_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_pitch_dir_inside_of_region);

/* NEARMISS-STUB GAMEUTIL_get_difference_radi_yaw_dir */
#if 0 /* NEARMISS 27.0% cat=vu0-mmi sub=- | VU0 dot product (lqc2/vmul/vmadd) then tail call | attempts=1 */
f32 GAMEUTIL_get_difference_radi_yaw_dir(f32 *a, f32 *b)
{
    return iosGetACosfExact(a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_get_difference_radi_yaw_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_get_difference_radi_pitch_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_get_move_radi_yaw_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_get_move_radi_pitch_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_get_rot_dir_for_near_to_aim_pitch_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_reach_aim_yaw_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_reach_aim_pitch_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_near_to_aim_yaw_dir);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_nearly_equal_yaw);
s32 GAMEUTIL_is_nearly_equal_yaw(f32 a, f32 b, f32 c)
{
    f32 d = b - a;

    if (d < 0.0f)
    {
        d = -d;
    }
    if (3.1415926f < d)
    {
        d = 6.2831852f - d;
    }
    return d <= c;
}

s32 GAMEUTIL_is_nearly_equal_pitch(f32 a, f32 b, f32 c)
{
    f32 d = b - a;

    if (d < 0.0f)
    {
        d = -d;
    }
    return d <= c;
}

typedef union
{
    s128 q;
    f32 f[4];
    s32 i[4];
} Vec4;

void GAMEUTIL_set_inside_check_method(Vec4 *p, s32 m, Vec4 *v)
{
    p[0].i[0] = m;
    p[1].q = v->q;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", GAMEUTIL_is_inside);

u8 *GetCharacterClass();
u8 *GetLayoutClass();
void SetCharacterClassRootQuaternionWithInterpolationGeometry();
void SetLayoutClassRootQuaternion();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", func_4001C2D0);
void func_4001C2D0(u8 *a0, s32 a1)
{
    u8 *cls;

    cls = GetCharacterClass(a0);
    if (cls != NULL)
    {
        SetCharacterClassRootQuaternionWithInterpolationGeometry(cls, a1);
        return;
    }
    cls = GetLayoutClass(a0);
    if (cls != NULL)
    {
        SetLayoutClassRootQuaternion(cls, a1);
        return;
    }
}

/* NEARMISS-STUB func_4001C350 */
#if 0 /* NEARMISS 95.25% cat=regalloc sub=- | wrap-to-pi: float reg choice differs (pi/-pi consts in fv1 vs f0 in target; result in fa0 vs f1 then mov); r=a variant 94.4 | attempts=1 */
/* func_4001C350 best attempt: 95.25% (iteration 2). Residual: register choice (constant loads into fv1 vs ft0, return value in fa0 vs f1). */
f32 func_4001C350(f32 a)
{
    f32 r;

    if (a <= 3.1415925f && -3.1415925f <= a)
    {
        return a;
    }
    r = a - (f32)(s32)(a / 6.283185f) * 6.283185f;
    if (3.1415925f < r)
    {
        r = r - 6.283185f;
    }
    else if (r < -3.1415925f)
    {
        r = r + 6.283185f;
    }
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", func_4001C350);

static inline s32 is_nearly_zero_inl(f32 v, f32 eps)
{
    if ((v < 0.0f ? -v : v) <= eps)
    {
        return 1;
    }
    return 0;
}
f32 func_4001C3F0(f32 v)
{
    if (is_nearly_zero_inl(v, 0.0001f))
    {
        return 1.0f;
    }
    return v;
}
//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", func_4001C3F0);

f32 func_4001C450(f32 a, f32 b, f32 c)
{
    if (is_nearly_zero_inl(c, 0.0001f))
    {
        return b;
    }
    return a;
}
//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0006_GAMEUTIL_is_yaw_dir_inside_of_region", func_4001C450);
