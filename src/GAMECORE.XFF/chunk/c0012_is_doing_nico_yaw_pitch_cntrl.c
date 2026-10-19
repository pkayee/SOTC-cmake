#include "common.h"

s32 GAMEUTIL_check_and_get_normalize_vector(f32 *in, s32 flag, f32 *out);

f32 func_40023CF0(s32 *out, u8 *buf, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);

extern u8 gcGlobalVar[];
f32 GAMEUTIL_get_dist_ratio(f32 a, f32 b, f32 c);
f32 GAMEUTIL_update_and_get_move_angle(u8 *buf, f32 a, f32 b);

f32 GAMEUTIL_increase_yaw_limit_clip(s32 e, s32 f, f32 a, f32 b, f32 c, f32 d);

f32 func_40023E40(f32 v, u8 *p);

f32 func_40023EE8(f32 v, u8 *p);
f32 GAMEUTIL_increase_yaw(s32 kind, f32 a, f32 b);

s32 is_enable_base_pitch_rot_nico_yaw_pitch_cntrl(u8 *p);
f32 func_40024218(f32 a, f32 b, f32 c, u8 *p);

s32 is_enable_base_yaw_rot_nico_yaw_pitch_cntrl(u8 *p);
f32 func_40024298(f32 a, f32 b, f32 c, u8 *p);

s32 is_doing_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(s32 *)(p + 0x2C);
}

void set_temp_stop_base_rot_flag_nico_yaw_pitch_cntrl(u8 *p, s32 flag)
{
    *(s32 *)(p + 0x30) = flag;
}

f32 GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(f32 a, f32 b);
f32 GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(f32 a, f32 b);

void update_offset_yaw_pitch_another_factor_nico_yaw_pitch_cntrl(f32 a, f32 b, u8 *p)
{
    *(f32 *)(p + 0x40) = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(*(f32 *)(p + 0x5C), a);
    *(f32 *)(p + 0x50) = GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(*(f32 *)(p + 0x68), b);
}


// c0012 REA: tail call arg order. func_40024298 declared (f32,f32,f32,u8 *p) with the pointer LAST in the call; p first = 95.9.
f32 update_base_yaw_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    f32 base;
    f32 nb;

    if (is_enable_base_yaw_rot_nico_yaw_pitch_cntrl(p) == 1) {
        base = *(f32 *)(p + 0x5C);
        nb = func_40024298(base, v, base, p);
        *(f32 *)(p + 0x5C) = nb;
        return GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(base, nb);
    }
    return 0.0f;
}


f32 update_base_pitch_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    f32 base;
    f32 nb;

    if (is_enable_base_pitch_rot_nico_yaw_pitch_cntrl(p) == 1) {
        base = *(f32 *)(p + 0x68);
        nb = func_40024218(base, v, base, p);
        *(f32 *)(p + 0x68) = nb;
        return GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(base, nb);
    }
    return 0.0f;
}

// c0012 REA: result in a local r and returned gives jal + common epilogue; a direct return of the call tail-calls with j (74).
f32 get_max_min_clip_base_yaw_nico_yaw_pitch_cntrl(f32 a, u8 *p)
{
    f32 v;
    f32 r1;
    f32 r2;
    f32 r;

    v = *(f32 *)(p + 0x110);
    if (*(s32 *)(p + 0x104) == 1) {
        if (*(s32 *)(p + 0x108) == 1) {
            r1 = func_40023E40(v, p);
        } else {
            r1 = GAMEUTIL_increase_yaw(0, v, *(f32 *)(p + 0x128));
        }
        if (*(s32 *)(p + 0x10C) == 1) {
            r2 = func_40023EE8(v, p);
        } else {
            r2 = GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x110), *(f32 *)(p + 0x12C));
        }
        r = GAMEUTIL_increase_yaw_limit_clip(0, 0, a, 0.0f, r1, r2);
    } else {
        r = GAMEUTIL_increase_yaw(0, a, 0.0f);
    }
    return r;
}

f32 func_40023F88(f32 v, u8 *p);
f32 func_40023FC8(f32 v, u8 *p);
f32 GAMEUTIL_increase_pitch_limit_clip(s32 e, s32 f, f32 a, f32 b, f32 c, f32 d);

/* NEARMISS-STUB get_max_min_clip_base_pitch_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 48.2% cat=stack-frame sub=- | target is a non-tail jal to GAMEUTIL_increase_pitch_limit_clip with frame 0x20 (p kept in s0, ra saved); ours sibcalls j with frame 0x30 (extra spills) | attempts=1 */
f32 get_max_min_clip_base_pitch_nico_yaw_pitch_cntrl(f32 a, u8 *p)
{
    f32 r1;
    f32 r2;

    r1 = func_40023F88(0.0f, p);
    r2 = func_40023FC8(0.0f, p);
    return GAMEUTIL_increase_pitch_limit_clip(a, 0.0f, r1, r2, 0, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", get_max_min_clip_base_pitch_nico_yaw_pitch_cntrl);

f32 get_offset_yaw_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x40);
}

f32 get_offset_pitch_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x50);
}

s32 is_enable_base_yaw_rot_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(s32 *)(p + 0xCC);
}

s32 is_enable_base_pitch_rot_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(s32 *)(p + 0xE8);
}

f32 get_base_yaw_move_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x58);
}

f32 get_base_pitch_move_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x64);
}

void set_base_yaw_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    *(f32 *)(p + 0x5C) = v;
}

void set_base_pitch_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    *(f32 *)(p + 0x68) = v;
}

f32 get_base_yaw_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x5C);
}

f32 get_base_pitch_nico_yaw_pitch_cntrl(u8 *p)
{
    return *(f32 *)(p + 0x68);
}

f32 GAMEUTIL_increase_yaw(s32 kind, f32 a, f32 b);
f32 GAMEUTIL_increase_yaw_limit_clip_extend(f32 a, f32 b, f32 c, s32 e, s32 f, s32 g, f32 d, s32 h);

f32 get_merge_yaw_nico_yaw_pitch_cntrl(u8 *p)
{
    s32 flag;

    if (*(s32 *)(p + 0x108) == 1 || *(s32 *)(p + 0x10C) == 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag == 1) {
        return GAMEUTIL_increase_yaw_limit_clip_extend(*(f32 *)(p + 0x5C), *(f32 *)(p + 0x40), *(f32 *)(p + 0x114), 0, *(s32 *)(p + 0x108), *(s32 *)(p + 0x10C), *(f32 *)(p + 0x118), 0);
    }
    return GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x5C), *(f32 *)(p + 0x40));
}

f32 GAMEUTIL_increase_pitch(f32 a, f32 b, f32 c, f32 d, s32 e, s32 f);

f32 get_merge_pitch_nico_yaw_pitch_cntrl(u8 *p)
{
    return GAMEUTIL_increase_pitch(*(f32 *)(p + 0x68), *(f32 *)(p + 0x50), *(f32 *)(p + 0x120), *(f32 *)(p + 0x124), 0, 0);
}

void *memset(void *p, int c, unsigned n);

void *func_40023920(s32 *p)
{
    *p = 0;
    return memset(p + 1, 0, 0x28);
}

void func_40023948(f32 *outA, f32 *outB, f32 x, f32 y)
{
    f32 v[4];
    f32 m;

    v[0] = x;
    v[1] = y;
    v[2] = 0.0f;
    v[3] = 0.0f;
    if (GAMEUTIL_check_and_get_normalize_vector(v, 0, v) == 1) {
        m = v[0] < 0.0f ? -v[0] : v[0];
        if (m < (v[1] < 0.0f ? -v[1] : v[1])) {
            m = v[1] < 0.0f ? -v[1] : v[1];
        }
        m = 1.0f / m;
        *outA = m * x;
        *outB = m * y;
        if (*outA < 0.0f ? *outA < -1.0f : 1.0f < *outA) {
            if (0.0f <= *outA) {
                *outA = 1.0f;
            } else {
                *outA = -1.0f;
            }
        }
        if (*outB < 0.0f ? *outB < -1.0f : 1.0f < *outB) {
            if (0.0f <= *outB) {
                *outB = 1.0f;
            } else {
                *outB = -1.0f;
            }
        }
    } else {
        *outA = x;
        *outB = y;
    }
}

typedef struct { f32 a; f32 b; } B28Pair;
void func_40023B28(f32 a, f32 b, u8 *p)
{
    s32 count;
    s32 i;
    B28Pair *e;

    count = *(s32 *)p;
    if (count < 5) {
        *(s32 *)p = count + 1;
        count = *(s32 *)p;
    }
    i = count - 1;
    if (i > 0) {
        e = (B28Pair *)(p + 4);
        for (; i > 0; i--) {
            e[i].a = e[i - 1].a;
            e[i].b = e[i - 1].b;
        }
        *(f32 *)(p + 8) = b;
    } else {
        *(f32 *)(p + 8) = b;
    }
    *(f32 *)(p + 4) = a;
}

void func_40023B88(f32 *avg1, f32 *avg2, u8 *p)
{
    s32 n;
    s32 i;
    f32 s1;
    f32 s2;
    f32 *e;
    union { s32 i; f32 f; } *u;

    s1 = 0.0f;
    s2 = 0.0f;
    n = *(s32 *)p;
    if (n > 0) {
        e = (f32 *)(p + 4);
        i = n;
        do {
            s1 = s1 + e[0];
            s2 = s2 + e[1];
            e += 2;
            i--;
        } while (i != 0);
    }
    *avg1 = s1 / (f32)n;
    u = (void *)p;
    *avg2 = s2 / (f32)u->i;
}

void func_40023BF0(f32 v, u8 *p)
{
    f32 lo;
    f32 hi;
    f32 r;
    f32 x;

    x = *(f32 *)(p + 0x68);
    hi = *(f32 *)(p + 0xAC);
    lo = *(f32 *)(p + 0xA8);
    if (*(f32 *)(p + 0x120) < x + lo) {
        lo = *(f32 *)(p + 0x120) - x;
        if (lo < 0.0f) {
            lo = 0.0f;
        }
    }
    if (x + hi < *(f32 *)(p + 0x124)) {
        hi = *(f32 *)(p + 0x124) - x;
        if (0.0f < hi) {
            hi = 0.0f;
        }
    }
    r = func_40023CF0((s32 *)(p + 0x4C), p + 0xB0, *(f32 *)(p + 0x74), *(f32 *)(p + 0x78), v, *(f32 *)(p + 0x50), *(f32 *)(p + 0xA4), lo, hi);
    *(s32 *)(p + 0x48) = 0;
    *(f32 *)(p + 0x50) = r;
    *(s32 *)(p + 0x44) = 0;
    if (lo - 0.017453292f <= r) {
        *(s32 *)(p + 0x44) = 1;
    } else if (r <= hi + 0.017453292f) {
        *(s32 *)(p + 0x48) = 1;
    }
}

f32 func_40023CF0(s32 *out, u8 *buf, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g)
{
    f32 ratio;
    f32 t;
    f32 diff;
    f32 fc;

    fc = c;
    if (c < 0.0f) {
        fc = -c;
    }
    ratio = GAMEUTIL_get_dist_ratio(fc, a, b);
    if (0.0f <= c) {
        if (f <= e) {
            t = f;
        } else {
            t = e + ratio * (f - e);
        }
    } else {
        if (e <= g) {
            t = g;
        } else {
            t = e + ratio * (g - e);
        }
    }
    diff = t - d;
    if (diff < 0.0f ? (-0.0017453289f < diff) : (diff < 0.0017453289f)) {
        *out = 0;
    } else {
        if (0.0f < diff) {
            *out = 1;
        } else {
            *out = -1;
        }
    }
    return d + GAMEUTIL_update_and_get_move_angle(buf, diff, *(f32 *)(gcGlobalVar + 0x180));
}

f32 func_40023E40(f32 v, u8 *p)
{
    s32 flag;

    if (*(s32 *)(p + 0x108) == 1) {
        if (GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(*(f32 *)(p + 0x110), v) >= 0.0f) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag == 1) {
            return GAMEUTIL_increase_yaw_limit_clip(0, 0, *(f32 *)(p + 0x114), -*(f32 *)(p + 0x80), *(f32 *)(p + 0x114), v);
        }
    }
    return GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x114), -*(f32 *)(p + 0x80));
}

// c0012 REA: GAMEUTIL_increase_yaw_limit_clip declared ints first (s32,s32,f32 x4); floats first = 86.5. flag = 0.0f <= radi as an expression.
f32 func_40023EE8(f32 v, u8 *p)
{
    if (*(s32 *)(p + 0x10C) == 1) {
        s32 flag;
        f32 radi;

        radi = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(*(f32 *)(p + 0x110), v);
        flag = 0.0f <= radi;
        if (flag == 0) {
            return GAMEUTIL_increase_yaw_limit_clip(0, 0, *(f32 *)(p + 0x118), -*(f32 *)(p + 0x84), *(f32 *)(p + 0x118), v);
        }
    }
    return GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x118), -*(f32 *)(p + 0x84));
}

f32 GAMEUTIL_increase_pitch_limit_clip(s32 e, s32 f, f32 a, f32 b, f32 c, f32 d);

f32 func_40023F88(f32 v, u8 *p)
{
    return GAMEUTIL_increase_pitch_limit_clip(0, 0, *(f32 *)(p + 0x120), -*(f32 *)(p + 0xA8), 1.483529567718505859375f, v);
}

f32 func_40023FC8(f32 v, u8 *p)
{
    return GAMEUTIL_increase_pitch_limit_clip(0, 0, *(f32 *)(p + 0x124), -*(f32 *)(p + 0xAC), v, -1.483529567718505859375f);
}

f32 func_400241A0(f32 x, f32 y, f32 z, s32 i0, s32 i1, s32 i2, s32 i3);
f32 GAMEUTIL_get_new_velocity(f32 a, f32 b, f32 c, f32 d, f32 e);
f32 GAMEUTIL_get_new_velocity_by_brake_abs(f32 a, f32 b, f32 c, f32 d);
s32 GAMEUTIL_is_nearly_equal_zero(f32 a, f32 b);
f32 func_40024008(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 *out, s32 i1, s32 i2, s32 i3, s32 i4, s32 i5, f32 s1, f32 s2)
{
    f32 ac;
    f32 r;
    f32 v;
    f32 sign;
    f32 t;
    u8 *g1;
    u8 *g2;
    u8 *g3;

    ac = c;
    if (c < 0.0f) {
        ac = -c;
    }
    r = func_400241A0(a, b, g, i1, i2, i3, i4);
    if (ac <= r) {
        g1 = gcGlobalVar;
        v = GAMEUTIL_get_new_velocity(ac, d, e, r, *(f32 *)(g1 + 0x180));
    } else {
        g2 = gcGlobalVar;
        v = GAMEUTIL_get_new_velocity_by_brake_abs(ac, f, r, *(f32 *)(g2 + 0x180));
    }
    if (r <= 0.0f && 0.0f < ac) {
        sign = c;
    } else {
        sign = b;
    }
    if (!GAMEUTIL_is_nearly_equal_zero(s1, 0.0001f)) {
        if (0.0f <= sign * s1) {
            t = s2 * g;
            if (t < v) {
                v = t;
            }
        }
    }
    *out = v;
    if (sign < 0.0f) {
        *out = -v;
    }
    g3 = gcGlobalVar;
    return *out * *(f32 *)(g3 + 0x180);
}

f32 GAMEUTIL_get_dist_ratio(f32 a, f32 b, f32 c);

f32 func_400241A0(f32 x, f32 y, f32 z, s32 i0, s32 i1, s32 i2, s32 i3)
{
    if (i0 == 1 && i1 == 0 && (i2 == i0 || i3 == i0)) {
        f32 ay = y;

        if (ay < 0.0f) {
            ay = -ay;
        }
        return GAMEUTIL_get_dist_ratio(ay, x, 1.0f) * z;
    }
    return 0.0f;
}

f32 func_40024218(f32 a, f32 b, f32 c, u8 *p)
{
    f32 r1;
    f32 r2;

    r1 = func_40023F88(c, p);
    r2 = func_40023FC8(c, p);
    return GAMEUTIL_increase_pitch_limit_clip(0, 0, a, b, r1, r2);
}

f32 func_40024298(f32 a, f32 b, f32 c, u8 *p)
{
    f32 r1;
    f32 r2;

    if (*(s32 *)(p + 0x104) == 1) {
        if (*(s32 *)(p + 0x108) == 1) {
            r1 = func_40023E40(c, p);
        } else {
            r1 = GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x110), *(f32 *)(p + 0x128));
        }
        if (*(s32 *)(p + 0x10C) == 1) {
            r2 = func_40023EE8(c, p);
        } else {
            r2 = GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x110), *(f32 *)(p + 0x12C));
        }
        return GAMEUTIL_increase_yaw_limit_clip(0, 0, a, b, r1, r2);
    }
    return GAMEUTIL_increase_yaw(0, a, b);
}
