#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0011_is_predict_to_acting_base_yaw_rot_nico_y", is_predict_to_acting_base_yaw_rot_nico_yaw_pitch_cntrl);

void reset_nico_yaw_pitch_cntrl(u8 *w)
{
    func_40023920(w);
    *(s32 *)(w + 0x2C) = 0;
    *(s32 *)(w + 0x30) = 0;
    *(s32 *)(w + 0x38) = 0;
    *(s32 *)(w + 0x34) = 0;
    *(s32 *)(w + 0x3C) = 0;
    *(s32 *)(w + 0x40) = 0;
    *(s32 *)(w + 0x48) = 0;
    *(s32 *)(w + 0x44) = 0;
    *(s32 *)(w + 0x4C) = 0;
    *(s32 *)(w + 0x50) = 0;
    *(s32 *)(w + 0x54) = 0;
    *(s32 *)(w + 0x58) = 0;
    *(s32 *)(w + 0x5C) = 0;
    *(s32 *)(w + 0x60) = 0;
    *(s32 *)(w + 0x64) = 0;
    *(s32 *)(w + 0x68) = 0;
}

void set_yaw_pitch_input_border_parameter_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b, f32 c, f32 d)
{
    *(f32 *)(w + 0x6C) = a;
    *(f32 *)(w + 0x70) = b;
    *(f32 *)(w + 0x74) = c;
    *(f32 *)(w + 0x78) = d;
}

/* NEARMISS-STUB set_offset_yaw_parameter_nico_yaw_pitch_cntrl */
#if 0 /* NEARMISS 96.92308% cat=sched sub=- | only diff: lwc1 of 10th (stack) float arg f23 from 0x60(sp) and 'daddu a0,zero,zero' (first call arg 0) are swapped; asm loads stack arg before a0 setup, C does | attempts=1 */
void GAMEUTIL_set_parameter_move_angle(u8 *w, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
f32 GAMEUTIL_increase_yaw(s32 kind, f32 value1, f32 value2);

void set_offset_yaw_parameter_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i)
{
    f32 fVar1;

    fVar1 = (a * 3.1415926f) / 180.0f;
    *(f32 *)(w + 0x7C) = fVar1;
    *(f32 *)(w + 0x80) = GAMEUTIL_increase_yaw(0, fVar1, (b * 3.1415926f) / 180.0f);
    *(f32 *)(w + 0x84) = GAMEUTIL_increase_yaw(0, *(f32 *)(w + 0x7C), (c * 3.1415926f) / 180.0f);
    GAMEUTIL_set_parameter_move_angle(w + 0x88, d, e, f, g, h, i);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0011_is_predict_to_acting_base_yaw_rot_nico_y", set_offset_yaw_parameter_nico_yaw_pitch_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0011_is_predict_to_acting_base_yaw_rot_nico_y", set_offset_pitch_parameter_nico_yaw_pitch_cntrl);

void set_base_yaw_parameter_nico_yaw_pitch_cntrl(u8 *w, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f)
{
    *(s32 *)(w + 0xcc) = flag;
    *(f32 *)(w + 0xd0) = a * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xd4) = b * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xd8) = c * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xdc) = d * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xe0) = e * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xe4) = f;
}

void set_base_pitch_parameter_nico_yaw_pitch_cntrl(u8 *w, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f)
{
    *(s32 *)(w + 0xe8) = flag;
    *(f32 *)(w + 0xec) = a * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xf0) = b * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xf4) = c * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xf8) = d * 3.14159274f / 180.0f;
    *(f32 *)(w + 0xfc) = e * 3.14159274f / 180.0f;
    *(f32 *)(w + 0x100) = f;
}

f32 GAMEUTIL_increase_yaw(s32 kind, f32 value1, f32 value2);

void set_max_min_yaw_parameter_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b, f32 c, s32 d, s32 e, s32 f)
{
    f32 fVar1;
    f32 fVar2;

    *(s32 *)(w + 0x104) = d;
    *(s32 *)(w + 0x108) = e;
    *(s32 *)(w + 0x10C) = f;
    fVar1 = (a * 3.1415926f) / 180.0f;
    *(f32 *)(w + 0x110) = fVar1;
    if (b > 89.0f)
    {
        b = 89.0f;
    }
    if (c < -89.0f)
    {
        c = -89.0f;
    }
    fVar2 = GAMEUTIL_increase_yaw(0, fVar1, (b * 3.1415926f) / 180.0f);
    *(f32 *)(w + 0x114) = fVar2;
    fVar2 = GAMEUTIL_increase_yaw(0, *(f32 *)(w + 0x110), (c * 3.1415926f) / 180.0f);
    *(f32 *)(w + 0x118) = fVar2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0011_is_predict_to_acting_base_yaw_rot_nico_y", set_max_min_yaw_parameter_extend_nico_yaw_pitch_cntrl);

f32 GAMEUTIL_increase_pitch_limit_clip(f32 a, f32 b, f32 c, f32 d, s32 e, s32 f);

void set_max_min_pitch_parameter_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b)
{
    *(f32 *)(w + 0x11C) = 0.0f;
    *(f32 *)(w + 0x120) = GAMEUTIL_increase_pitch_limit_clip(*(f32 *)(w + 0x11C), a * 3.14159274f / 180.0f, 1.483529567718505859375f, -1.483529567718505859375f, 0, 0);
    *(f32 *)(w + 0x124) = GAMEUTIL_increase_pitch_limit_clip(*(f32 *)(w + 0x11C), b * 3.14159274f / 180.0f, 1.483529567718505859375f, -1.483529567718505859375f, 0, 0);
}

void *memset(void *d, s32 c, u32 n);
void set_reverse_input_yaw_flag_nico_yaw_pitch_cntrl(u8 *w, s32 flag)
{
    if (*(s32 *)(w + 0x130) != flag) {
        *(s32 *)w = 0;
        memset(w + 4, 0, 0x28);
        *(s32 *)(w + 0x130) = flag;
    }
}

void set_reverse_input_pitch_flag_nico_yaw_pitch_cntrl(u8 *w, s32 flag)
{
    if (*(s32 *)(w + 0x134) != flag) {
        *(s32 *)w = 0;
        memset(w + 4, 0, 0x28);
        *(s32 *)(w + 0x134) = flag;
    }
}

void set_yaw_parameter_effective_ratio_nico_yaw_pitch_cntrl(u8 *w, f32 r)
{
    *(f32 *)(w + 0x138) = r;
}

void set_pitch_parameter_effective_ratio_nico_yaw_pitch_cntrl(u8 *w, f32 r)
{
    *(f32 *)(w + 0x13C) = r;
}

void set_base_vel_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b)
{
    *(f32 *)(w + 0x54) = a;
    *(f32 *)(w + 0x60) = b;
}

void GAMEUTIL_begin_move_angle(u8 *p);
void begin_nico_yaw_pitch_cntrl(u8 *w, f32 a, f32 b)
{
    func_40023920(w);
    *(s32 *)(w + 0x2C) = 1;
    *(f32 *)(w + 0x40) = *(f32 *)(w + 0x7C);
    *(f32 *)(w + 0x50) = *(f32 *)(w + 0xA4);
    *(f32 *)(w + 0x5C) = a;
    *(f32 *)(w + 0x68) = b;
    *(s32 *)(w + 0x30) = 0;
    *(s32 *)(w + 0x38) = 0;
    *(s32 *)(w + 0x34) = 0;
    *(s32 *)(w + 0x3C) = 0;
    *(s32 *)(w + 0x48) = 0;
    *(s32 *)(w + 0x44) = 0;
    *(s32 *)(w + 0x4C) = 0;
    *(s32 *)(w + 0x54) = 0;
    *(s32 *)(w + 0x58) = 0;
    *(s32 *)(w + 0x60) = 0;
    *(s32 *)(w + 0x64) = 0;
    GAMEUTIL_begin_move_angle(w + 0x88);
    GAMEUTIL_begin_move_angle(w + 0xB0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0011_is_predict_to_acting_base_yaw_rot_nico_y", doit_nico_yaw_pitch_cntrl);

void end_nico_yaw_pitch_cntrl(u8 *w)
{
    func_40023920(w);
    *(s32 *)(w + 0x2C) = 0;
    *(s32 *)(w + 0x30) = 0;
    *(s32 *)(w + 0x38) = 0;
    *(s32 *)(w + 0x34) = 0;
    *(s32 *)(w + 0x3C) = 0;
    *(s32 *)(w + 0x40) = 0;
    *(s32 *)(w + 0x48) = 0;
    *(s32 *)(w + 0x44) = 0;
    *(s32 *)(w + 0x4C) = 0;
    *(s32 *)(w + 0x50) = 0;
    *(s32 *)(w + 0x54) = 0;
    *(s32 *)(w + 0x58) = 0;
    *(s32 *)(w + 0x5C) = 0;
    *(s32 *)(w + 0x60) = 0;
    *(s32 *)(w + 0x64) = 0;
    *(s32 *)(w + 0x68) = 0;
}
