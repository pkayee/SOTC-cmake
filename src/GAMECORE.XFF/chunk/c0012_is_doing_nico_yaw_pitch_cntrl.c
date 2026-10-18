#include "common.h"

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

f32 func_40024298(f32 a, f32 b, f32 c);

/* NEARMISS-STUB update_base_yaw_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 91.0% cat=regalloc sub=- | same as update_base_pitch: target copies v into f13 before mtc1 zero/bne, ours in the bne delay slot; early-zero return variant scores 73.6 | attempts=1 */
f32 update_base_yaw_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    f32 base;
    f32 nb;

    if (is_enable_base_yaw_rot_nico_yaw_pitch_cntrl(p) == 1) {
        base = *(f32 *)(p + 0x5C);
        nb = func_40024298(base, v, base);
        *(f32 *)(p + 0x5C) = nb;
        return GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(base, nb);
    }
    return 0.0f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", update_base_yaw_nico_yaw_pitch_cntrl);

f32 func_40024218(f32 a, f32 b, f32 c);

/* NEARMISS-STUB update_base_pitch_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 91.0% cat=regalloc sub=- | target copies v into f13 before the mtc1 zero/bne (ours copies in the bne delay slot); target keeps a0=p in the bne delay slot; tail jal layout otherwise identi | attempts=1 */
f32 update_base_pitch_nico_yaw_pitch_cntrl(f32 v, u8 *p)
{
    f32 base;
    f32 nb;
    f32 tv;

    tv = v;
    if (is_enable_base_pitch_rot_nico_yaw_pitch_cntrl(p) == 1) {
        base = *(f32 *)(p + 0x68);
        nb = func_40024218(base, tv, base);
        *(f32 *)(p + 0x68) = nb;
        return GAMEUTIL_get_move_radi_from_pitch1_to_pitch2(base, nb);
    }
    return 0.0f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", update_base_pitch_nico_yaw_pitch_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", get_max_min_clip_base_yaw_nico_yaw_pitch_cntrl);

f32 func_40023F88(f32 v, u8 *p);
f32 func_40023FC8(f32 v, u8 *p);
f32 GAMEUTIL_increase_pitch_limit_clip(f32 a, f32 b, f32 c, f32 d, s32 e, s32 f);

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

f32 GAMEUTIL_increase_yaw(s32 kind, f32 value);
f32 GAMEUTIL_increase_yaw_limit_clip_extend(f32 a, f32 b, f32 c, f32 d, s32 e, s32 f, s32 g, s32 h);

/* NEARMISS-STUB get_merge_yaw_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 69.2% cat=branch-layout sub=- | target branches on a2 (flag materialised in a2 via delay-slot a2=0) then reloads p+0x10C for the tail call; ours folds the flag into xori/sltiu (bool trick), an | attempts=1 */
f32 get_merge_yaw_nico_yaw_pitch_cntrl(u8 *p)
{
    s32 flag;

    if (*(s32 *)(p + 0x108) == 1) {
        flag = 1;
    } else {
        flag = 0;
        if (*(s32 *)(p + 0x10C) == 1) {
            flag = 1;
        }
    }
    if (flag == 1) {
        return GAMEUTIL_increase_yaw_limit_clip_extend(*(f32 *)(p + 0x5C), *(f32 *)(p + 0x40), *(f32 *)(p + 0x114), *(f32 *)(p + 0x118), 0, *(s32 *)(p + 0x108), *(s32 *)(p + 0x10C), 0);
    }
    return GAMEUTIL_increase_yaw(0, *(f32 *)(p + 0x5C));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", get_merge_yaw_nico_yaw_pitch_cntrl);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023948);

/* NEARMISS-STUB func_40023B28 */
#if 0 /* NEARMISS 89.4% cat=branch-layout sub=- | loop shape ok; regs swapped (target: count in v1, loop counter a1, ptr v0); a-store placement and b-store duplication in blezl slot differ | attempts=1 */
void func_40023B28(f32 a, f32 b, u8 *p)
{
    s32 count;
    s32 i;
    f32 *base;
    f32 *q;

    count = *(s32 *)p;
    if (count < 5) {
        count = count + 1;
        *(s32 *)p = count;
    }
    i = count - 1;
    if (i > 0) {
        base = (f32 *)(p + 4);
        q = base + i * 2;
        do {
            q[0] = q[-2];
            q[1] = q[-1];
            q -= 2;
            i--;
        } while (i > 0);
        *(f32 *)(p + 8) = b;
    } else {
        *(f32 *)(p + 8) = b;
    }
    *(f32 *)(p + 4) = a;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023B28);

/* NEARMISS-STUB func_40023B88 */
#if 0 /* NEARMISS 81.2% cat=regalloc sub=- | sum loop ok; target keeps p live and reloads p[0] after the avg1 store (not CSE'd), n in a3 and loop counter as copy in v1, pointer in v0; ours reuses n and a2  | attempts=1 */
void func_40023B88(f32 *avg1, f32 *avg2, u8 *p)
{
    s32 n;
    s32 i;
    f32 s1;
    f32 s2;
    f32 *e;

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
    *avg2 = s2 / (f32)*(s32 *)p;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023B88);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023BF0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023CF0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023E40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40023EE8);

f32 GAMEUTIL_increase_pitch_limit_clip(f32 a, f32 b, f32 c, f32 d, s32 e, s32 f);

f32 func_40023F88(f32 v, u8 *p)
{
    return GAMEUTIL_increase_pitch_limit_clip(*(f32 *)(p + 0x120), -*(f32 *)(p + 0xA8), 1.483529567718505859375f, v, 0, 0);
}

f32 func_40023FC8(f32 v, u8 *p)
{
    return GAMEUTIL_increase_pitch_limit_clip(*(f32 *)(p + 0x124), -*(f32 *)(p + 0xAC), v, -1.483529567718505859375f, 0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40024008);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40024218);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0012_is_doing_nico_yaw_pitch_cntrl", func_40024298);
