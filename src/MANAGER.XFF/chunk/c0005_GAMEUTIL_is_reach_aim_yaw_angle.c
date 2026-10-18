#include "common.h"

#define NEARABS(x) ((x) < 0.0f ? -(x) : (x))

extern u128 ZUnitVector;
f32 iosGetACosfExact(f32);
void iosRotMatrixY(void *, f32);
void iosRotMatrixX(void *, f32);
void iosApplyRotMatrix();
f32 func_4001C350(f32);

static inline s32 nearZero(f32 v, f32 eps) {
    if (NEARABS(v) <= eps) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_is_reach_aim_yaw_angle);

/* NEARMISS-STUB GAMEUTIL_is_reach_aim_pitch_angle */
#if 0 /* NEARMISS 72.5% cat=regalloc sub=float-reg-swap | fuzzy |c-b|<=eps: sub.s/zero land f1/f0 swapped vs target (d in f0); D-test (c<=a) branch sense bc1f over body in target, ours bc1tl; between-chain matches | attempts=1 */
s32 GAMEUTIL_is_reach_aim_pitch_angle(f32 a, f32 b, f32 c, f32 *out)
{
    s32 inside;
    f32 d;

    if (a <= c && c <= b)
    {
        inside = 1;
    }
    else
    {
        inside = 0;
        if (b <= c && c <= a)
        {
            inside = 1;
        }
    }
    if (inside != 1)
    {
        d = c - b;
        if (d < 0.0f)
        {
            d = -d;
        }
        if (d < 0.0f)
        {
            d = -d;
        }
        if (d <= 0.0001f)
        {
            inside = 1;
        }
        else
        {
            inside = 0;
        }
    }
    if (inside == 1)
    {
        if (out != NULL)
        {
            *out = c;
        }
        return 1;
    }
    if (out != NULL)
    {
        *out = b;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_is_reach_aim_pitch_angle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_near_to_aim_yaw_angle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_near_to_aim_pitch_angle);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_yaw_matrix);

void GAMEUTIL_get_yaw_matrix(void *m, f32 yaw) {
    iosRotMatrixY(m, yaw);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_pitch_matrix);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_direction_by_yaw);

void GAMEUTIL_get_direction_by_yaw(u128 *out, f32 yaw) {
    u128 m[4];

    iosRotMatrixY(m, yaw);
    iosApplyRotMatrix(out, m, &ZUnitVector);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_direction_by_yaw_pitch);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_yaw_by_direction);

f32 GAMEUTIL_get_yaw_by_direction(f32 *v) {
    f32 a = iosGetACosfExact(v[2]);

    if (v[0] < 0.0f) {
        a = -a;
    }
    return a;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_yaw_pitch_by_direction);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_is_yaw_pitch_get_direction);

s32 GAMEUTIL_is_yaw_pitch_get_direction(f32 *v) {
    if (NEARABS(v[1]) <= 0.9999f) {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_interp_yaw);

f32 GAMEUTIL_get_interp_yaw(f32 a, f32 b, f32 t) {
    f32 d;
    f32 s;
    f32 ret;
    s32 dir;

    if (t <= 0.0f) {
        return a;
    }
    if (1.0f <= t) {
        return b;
    }
    d = NEARABS(b - a);
    dir = 1;
    if (b < a) {
        dir = 0;
    }
    if (3.1415927f < d) {
        d = 3.1415927f * 2.0f - d;
        dir = !dir;
    }
    if (dir) {
        s = d;
    } else {
        s = -d;
    }
    t = t * s;
    ret = a;
    if (!nearZero(t, 0.0001f)) {
        ret = func_4001C350(a + t);
    }
    return ret;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_pitch_radi);

f32 GAMEUTIL_get_pitch_radi(f32 *v) {
    f32 a = iosGetACosfExact(v[2]);
    f32 lo = -1.4835296f;
    f32 hi = 1.4835296f;

    if (v[1] < 0.0f) {
        a = -a;
    }
    if (hi < a) {
        a = hi;
    } else if (a < lo) {
        a = lo;
    }
    return a;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_pitch_dir);

void GAMEUTIL_get_pitch_dir(u128 *out, f32 pitch) {
    u128 m[4];

    if (nearZero(pitch, 0.0001f) == 1) {
        *out = ZUnitVector;
        return;
    }
    if (1.4835296f < pitch) {
        pitch = 1.4835296f;
    } else if (pitch < -1.4835296f) {
        pitch = -1.4835296f;
    }
    iosRotMatrixX(m, -pitch);
    iosApplyRotMatrix(out, m, &ZUnitVector);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_divide_yaw_pitch_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_get_yaw_pitch_merge_dir);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_act_yaw_rot);

s32 GAMEUTIL_act_yaw_rot(f32 yaw, u128 *out, u128 *in) {
    u128 m[4];

    if (nearZero(yaw, 0.0001f) == 1) {
        *out = *in;
        return 0;
    }
    iosRotMatrixY(m, yaw);
    iosApplyRotMatrix(out, m, in);
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_is_yaw_dir_sandwich);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0005_GAMEUTIL_is_reach_aim_yaw_angle", GAMEUTIL_is_pitch_dir_sandwich);
