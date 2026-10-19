#include "common.h"

extern u8 *GetLayoutClass(u8 *);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA350);

void func_400EA350(f32 param_1, s32 *param_2, s32 param_3)
{
    f32 fVar1;

    if (param_2[0] == 0 || *(s32 *)(param_3 + 0x18ac) == 1)
    {
        fVar1 = *(f32 *)&param_2[2] - param_1 * 0.5f;
        *(f32 *)&param_2[2] = fVar1;
        if (fVar1 < 0.0f)
        {
            *(f32 *)&param_2[2] = 0.0f;
            return;
        }
    }
    else
    {
        *(f32 *)&param_2[1] = 1.0f;
        *(f32 *)&param_2[2] = *(f32 *)&param_2[2] + param_1;
    }
    return;
}

s32 func_400EA528(s32 param_1, s32 param_2);
extern s32 is_leave_camera_dist_to_look_at(u8 *);
extern s32 GAMEUTIL_is_nearly_equal_yaw(f32, f32, f32);
extern s32 GAMEUTIL_is_nearly_equal_pitch(f32, f32, f32);

void func_400EA3B8(u8 *w, u8 *cam, f32 yaw, f32 pitch, f32 dt)
{
    s32 hit = 0;

    if (*(s32 *)(w + 0xC) != 0 && func_400EA528((s32)w, (s32)cam) != 1) {
        if (is_leave_camera_dist_to_look_at(cam) == 1 || *(s32 *)(w + 0xC) == 1
            || (GAMEUTIL_is_nearly_equal_yaw(*(f32 *)(cam + 0x110), yaw, *(f32 *)(w + 0x14)) != 0
                && (*(s32 *)(w + 0xC) != 3
                    || GAMEUTIL_is_nearly_equal_pitch(*(f32 *)(cam + 0x114), pitch, *(f32 *)(w + 0x18)) != 0))) {
            hit = 1;
        }
    }
    if (hit == 1) {
        *(f32 *)(w + 0x10) += dt;
    } else {
        *(s32 *)(w + 0x10) = 0;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA4A8);

void func_400EA4A8(f32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    s32 bVar1;
    f32 fVar2;

    bVar1 = 0;
    *(s32 *)(param_3 + 0x24) = 0;
    if (*(s32 *)(param_3 + 0x1c) != 0 && 0.0f < param_1 && param_1 <= *(f32 *)(param_4 + 0x118))
    {
        *(s32 *)(param_3 + 0x24) = 1;
        if (*(s32 *)(param_4 + 0x18ac) == 0)
        {
            bVar1 = 1;
            *(f32 *)(param_3 + 0x20) = *(f32 *)(param_3 + 0x20) + param_2;
        }
    }
    if (bVar1 == 0)
    {
        fVar2 = *(f32 *)(param_3 + 0x20) - param_2;
        *(f32 *)(param_3 + 0x20) = fVar2;
        if (fVar2 < 0.0f)
        {
            *(f32 *)(param_3 + 0x20) = 0.0f;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA528);

s32 func_400EA528(s32 param_1, s32 param_2)
{
    return *(s32 *)(param_2 + 0x5d4) == 0;
}

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) C181Vec;
extern void GAMEUTIL_add_local_offset_root_position(f32, f32, f32, C181Vec *, u8 *);
extern void GAMEUTIL_get_local_quaternion(C181Vec *, u8 *);
extern f32 GAMEUTIL_is_inside_of_region_ratio(s32, C181Vec *, C181Vec *, C181Vec *, f32, f32, f32, f32, f32, f32);

f32 func_400EA538(u8 *obj, s32 unused, u8 *p, u8 *cam)
{
    C181Vec v;
    C181Vec pos;
    C181Vec q;
    f32 r;

    GAMEUTIL_add_local_offset_root_position(*(f32 *)(p + 0), *(f32 *)(p + 4), *(f32 *)(p + 8), &pos, obj);
    GAMEUTIL_get_local_quaternion(&q, obj);
    *(u128 *)&v = *(u128 *)(cam + 0xA0);
    v.y = *(f32 *)(*(u8 **)(GetLayoutClass(*(u8 **)(cam + 0x240)) + 0x134) + 4);
    r = GAMEUTIL_is_inside_of_region_ratio(*(s32 *)(p + 0xC), &v, &pos, &q,
                                           *(f32 *)(p + 0x10), *(f32 *)(p + 0x14), *(f32 *)(p + 0x18),
                                           *(f32 *)(p + 0x1C), *(f32 *)(p + 0x20), *(f32 *)(p + 0x24));
    if (r < 0.0f) {
        r = 0.0f;
    }
    return r;
}

extern u8 *GAMEUTIL_get_boss_obj(void);
extern u8 *GetLayoutClass(u8 *);

void func_400EA608(s32 *n, s32 *list)
{
    u8 *boss = GAMEUTIL_get_boss_obj();
    u8 *lay;

    *n = 0;
    if (boss != 0) {
        lay = GetLayoutClass(boss);
        if (*(u8 **)(lay + 0x1A8) != 0 && *(s32 *)(*(u8 **)(lay + 0x1A8) + 4) != 0) {
            list[*n] = (s32)boss;
            *n = *n + 1;
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA690);

/* NEARMISS-STUB func_400EA790 */
#if 0 /* NEARMISS 86.02% cat=regalloc sub=- | d2 r101: plain v[0..2] = (t+t)*cam[0x1070/0x1074/0xD8] after memset; target reaches 0x1070/0x1074 via addiu base cam+0x1030 (+0x40/+0x44) and allocates s-regs t | attempts=1 */
extern void *memset(void *, int, unsigned int);
extern f32 *doit_double_spring_interp_cntrl3D(f32, void *, f32 *, void *);

void func_400EA790(f32 dt, void *spring, u8 *cam, u8 *tgt, void *mode)
{
    f32 v[4];

    memset(v, 0, 0x10);
    v[0] = (*(f32 *)(tgt + 0x130) + *(f32 *)(tgt + 0x130)) * *(f32 *)(cam + 0x1070);
    v[1] = (*(f32 *)(tgt + 0x134) + *(f32 *)(tgt + 0x134)) * *(f32 *)(cam + 0x1074);
    v[2] = (*(f32 *)(tgt + 0x138) + *(f32 *)(tgt + 0x138)) * *(f32 *)(cam + 0xD8);
    doit_double_spring_interp_cntrl3D(dt, spring, v, mode);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA790);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA848);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA960);

f32 func_400EA960(f32 param_1, f32 param_2, f32 param_3)
{
    f32 fVar1;

    if (param_2 < 0.0f)
    {
        fVar1 = -param_2 / param_1;
    }
    else
    {
        fVar1 = param_2 / param_1;
    }
    if (fVar1 < param_3)
    {
        fVar1 = param_3;
    }
    return fVar1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9A8);

void GAMEUTIL_doit_interp_ratio_cntrl(f32 param_1, ...);

void func_400EA9A8(f32 param_1, s32 param_2, s32 param_3)
{
    if (*(s32 *)(param_3 + 0x5d4) != 0)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9C8);

void func_400EA9C8(f32 param_1, s32 param_2, s32 param_3)
{
    if (*(s32 *)(param_3 + 0x13c0) != 1)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1, param_2 + 0x20);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9F0);

void func_400EA9F0(f32 param_1, s32 param_2, s32 param_3)
{
    if ((((s32)((*(s64 *)(param_3 + 0x3d0) << 2) >> 32)) & 1) == 0)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1, param_2 + 0x40);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAA20);

f32 GAMEUTIL_get_dist_ratio(f32 value, f32 min, f32 max);

f32 func_400EAA20(s32 *param_1)
{
    return GAMEUTIL_get_dist_ratio(*(f32 *)((u8 *)param_1 + 0x1a0), 0.0f, *(f32 *)(*param_1 + 0x170));
}

extern f32 GAMEUTIL_get_hope_value_interp_value_cntrl(void *);
extern void GAMEUTIL_reset_interp_ratio_cntrl(void *);
extern void GAMEUTIL_set_param_interp_ratio_cntrl(void *, f32, f32);
extern void GAMEUTIL_doit_interp_value_cntrl(void *, void *, f32);

void func_400EAA48(void *ratio, void *val, f32 target, f32 rate)
{
    if (GAMEUTIL_get_hope_value_interp_value_cntrl(val) != target) {
        GAMEUTIL_reset_interp_ratio_cntrl(ratio);
        GAMEUTIL_set_param_interp_ratio_cntrl(ratio, 0.0f, 1.0f);
    }
    GAMEUTIL_doit_interp_ratio_cntrl(rate, ratio);
    GAMEUTIL_doit_interp_value_cntrl(val, ratio, target);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAAD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EABA8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAD60);

f32 GAMEUTIL_get_interp_value_interp_value_cntrl(s32 c);
f32 GAMEUTIL_mul_ratio(f32 a, f32 b, s32 c);

f32 func_400EAD60(f32 param_1, s32 param_2, s32 param_3)
{
    f32 fVar1;

    if (param_1 == 0.0f)
    {
        return 0.0f;
    }
    if (0.0f < param_1)
    {
        fVar1 = GAMEUTIL_get_interp_value_interp_value_cntrl(param_2);
    }
    else
    {
        fVar1 = GAMEUTIL_get_interp_value_interp_value_cntrl(param_3);
    }
    return GAMEUTIL_mul_ratio(param_1, fVar1, 1);
}

/* NEARMISS-STUB func_400EADD8 */
#if 0 /* NEARMISS 96.03% cat=regalloc sub=- | d2 r101: only the 0.0f regs differ: target holds 0 in f1 for the two field tests then copies it to f3 (mov.s f3,f1) for the xz/y tests and loads v[2] before v[0 | attempts=1 */
void func_400EADD8(f32 a, f32 b, f32 *outA, f32 *outB, f32 *v, u8 **pp)
{
    f32 xz;
    f32 y;

    if (!(*(f32 *)(*pp + 0x7C) > 0.0f) || !(*(f32 *)(*pp + 0x94) > 0.0f)) {
        return;
    }
    xz = v[0] * v[0] + v[2] * v[2];
    y = v[1] * v[1];
    if (!(xz > 0.0f) && !(y > 0.0f)) {
        return;
    }
    if (y < xz) {
        *outB = GAMEUTIL_get_dist_ratio(y / xz, 0.5f, 1.0f) * b;
    } else {
        *outA = GAMEUTIL_get_dist_ratio(xz / y, 0.5f, 1.0f) * a;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EADD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAEE0);
