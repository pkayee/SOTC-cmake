#include "common.h"

void iosDlPushLayer(s32);
void iosDlPopLayer(void);
void texResetVRAMRequest(s32);
void iosSetRootDC(void);
f32 GAMEUTIL_get_difference_value(s32, f32, f32);
s32 GAMEUTIL_is_nearly_equal_zero(f32, f32);
f32 GAMEUTIL_get_interp_value_interp_value_cntrl();

void func_4001E138(f32 *c, s32 r);
s32 func_4001E0F0(f32 *c, f32 a, f32 b);

void GAMEUTIL_set_param_extend_interp_ratio_cntrl(f32 p1, f32 p2, f32 p3, f32 *c)
{
    s32 r;

    if (p1 < 0.0f) {
        p1 = 0.0f;
    }
    r = func_4001E0F0(c, p1, p2);
    c[5] = p1;
    c[6] = p2;
    if (0.0f < p2 && 0.0f < p3) {
        c[7] = p2 / p3;
    } else {
        c[7] = 1.0f;
    }
    func_4001E138(c, r);
}

void GAMEUTIL_reset_interp_value_cntrl(f32 *c, f32 v) {
    c[0] = v;
    c[1] = v;
    c[2] = v;
    GAMEUTIL_get_interp_value_interp_value_cntrl(c);
}

/* NEARMISS-STUB GAMEUTIL_doit_interp_value_cntrl */
#if 0 /* NEARMISS 95.9% cat=regalloc sub=- | FP reg naming (rate/c0 loads order and f-regs) + else-path store order (expected c2,c0,then c1 in jal delay); compare form c.le.s vs c.lt.s for rate<=0 branch | attempts=1 */
void GAMEUTIL_doit_interp_value_cntrl(f32 v, f32 *c, s32 *p)
{
    f32 r;
    f32 rate;

    if (p[0] == 1) {
        if (p[2] == 1) {
            c[0] = c[1];
        }
        c[2] = v;
        rate = ((f32 *)p)[4];
        r = c[0];
        if (rate <= 0.0f) {
            r = c[0];
        } else {
            r = v;
            if (rate < 1.0f && v != c[0]) {
                r = rate * v + (1.0f - rate) * c[0];
            }
        }
        c[1] = r;
    } else {
        c[2] = v;
        c[0] = v;
        c[1] = v;
        GAMEUTIL_get_interp_value_interp_value_cntrl(c);
    }
    GAMEUTIL_get_interp_value_interp_value_cntrl(c);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", GAMEUTIL_doit_interp_value_cntrl);

f32 GAMEUTIL_get_interp_value_interp_value_cntrl(f32 *c) {
    return c[1];
}

f32 GAMEUTIL_get_hope_value_interp_value_cntrl(f32 *c) {
    return c[2];
}

void set_param_double_spring_interp_common(f32 *c, f32 a, f32 b, f32 d, f32 e) {
    c[0] = a;
    c[1] = b;
    c[2] = d;
    c[3] = e;
}

void constructor_double_spring_interp_cntrl(f32 v, s32 *c)
{
    c[5] = 0;
    c[7] = 0;
    c[6] = 0;
    set_param_double_spring_interp_common((f32 *)c, 2.0f, -1.0f, 1.0f, -1.0f);
    ((f32 *)c)[4] = v;
}

void set_rot_radi_value_flag_double_spring_interp_cntrl(s32 *c, s32 v) {
    c[5] = v;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", reset_double_spring_interp_cntrl);

s32 is_reach_src_value_double_spring_interp_cntrl(f32 v, s32 *c)
{
    f32 d = GAMEUTIL_get_difference_value(c[5], ((f32 *)c)[7], v);

    return GAMEUTIL_is_nearly_equal_zero(d, ((f32 *)c)[4] * 3.0f);
}

/* NEARMISS-STUB constructor_double_spring_interp_cntrl3D */
#if 0 /* NEARMISS 99.5% cat=regalloc sub=- | loop address temps: ours puts off+p2 in a1 and off+p3 in v0 (expected a1=off+p3, v0=off+p2); stores/setup match; decl order and store order tried | attempts=1 */
void constructor_double_spring_interp_cntrl3D(f32 v1, f32 v2, s32 *c)
{
    s32 i;
    s32 *p3;
    s32 *p2;
    s32 *p1;

    p1 = &c[5];
    p2 = &c[8];
    p3 = &c[12];
    for (i = 0; i < 3; i++) {
        p1[i] = 0;
        p3[i] = 0;
        p2[i] = 0;
    }
    set_param_double_spring_interp_common((f32 *)c, 2.0f, -1.0f, 1.0f, -1.0f);
    ((f32 *)c)[4] = v1;
    ((f32 *)c)[15] = v2;
    ((f32 *)c)[11] = v2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", constructor_double_spring_interp_cntrl3D);

void set_rot_radi_value_flag_double_spring_interp_cntrl3D(s32 *c, s32 a, s32 b, s32 d) {
    c[5] = a;
    c[6] = b;
    c[7] = d;
}

f32 *reset_double_spring_interp_cntrl3D(f32 *c, f32 *src)
{
    s32 i;
    f32 v;
    f32 *d1;
    f32 *d2;

    d2 = &c[8];
    d1 = &c[12];
    for (i = 0; i < 3; i++) {
        v = src[i];
        d1[i] = v;
        d2[i] = v;
    }
    return d1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", doit_double_spring_interp_cntrl3D);

s32 is_reach_src_value_double_spring_interp_cntrl3D(void *control, f32 *target)
{
    char *state = control;
    s32 *mode = (s32 *)(state + 0x14);
    f32 *value = (f32 *)(state + 0x30);
    s32 i = 0;
    s32 reached = 1;

    do {
        f32 a = *value++;
        f32 b = *target++;
        s32 m = *mode++;
        f32 difference = GAMEUTIL_get_difference_value(m, a, b);

        if (!GAMEUTIL_is_nearly_equal_zero(difference, *(f32 *)(state + 0x10) * 3.0f)) {
            reached = 0;
            break;
        }
    } while (++i < 3);
    return reached;
}

void constructor_aim_angle_interp_cntrl(s32 *c, s32 v) {
    c[0] = v;
    ((f32 *)c)[1] = 4.0f;
    ((f32 *)c)[2] = 1.5707962f;
    c[3] = 0;
}

f32 reset_aim_angle_interp_cntrl(f32 *c, f32 v) {
    c[3] = v;
    return v;
}

f32 func_4001E1E8(u32 mode, f32 a, f32 b, f32 d);
f32 func_4001E3A8(u32 mode, f32 a, f32 b, f32 d);

/* NEARMISS-STUB doit_aim_angle_interp_cntrl */
#if 0 /* NEARMISS 66.3% cat=struct-layout sub=- | expected copies unused float param p3 (mov.s fa5,fa2) before the flag test and keeps p1/p2 in fv0/ft0; ours drops the dead p3 copy and reorders arg setup; flag/ | attempts=1 */
f32 doit_aim_angle_interp_cntrl(f32 p1, f32 p2, f32 p3, u32 *c, s32 flag)
{
    f32 val;
    u32 mode;

    val = p1;
    if (flag != 1) {
        if (((f32 *)c)[1] < 0.0f) {
            ((f32 *)c)[3] = val;
            return ((f32 *)c)[3];
        }
        if (((f32 *)c)[2] < 0.0f) {
            ((f32 *)c)[3] = val;
            return ((f32 *)c)[3];
        }
        mode = c[0];
        if (mode < 2) {
            val = func_4001E1E8(mode, ((f32 *)c)[3], p1, p2);
        } else if (mode == 2) {
            val = func_4001E3A8(mode, ((f32 *)c)[3], p1, p2);
        } else {
            return ((f32 *)c)[3];
        }
    }
    ((f32 *)c)[3] = val;
    return ((f32 *)c)[3];
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", doit_aim_angle_interp_cntrl);

void set_interp_param_aim_angle_interp_cntrl(f32 *c, f32 a, f32 b) {
    c[1] = a;
    c[2] = b;
}

s32 func_4001E0F0(f32 *c, f32 a, f32 b) {
    if (0.0f < c[3]) {
        if (c[5] != a || c[6] != b) {
            return 1;
        }
    }
    return 0;
}

/* NEARMISS-STUB func_4001E138 */
#if 0 /* NEARMISS 95.1% cat=regalloc sub=- | branch shape matches; expected reloads c[5] for the sum compare and holds rate in f6/1.0 in f7 (ours f4/f6); rate<1 test emitted as c.lt.s where expected has c. | attempts=1 */
void func_4001E138(f32 *c, s32 mode)
{
    f32 rate;
    f32 r;
    f32 sum;

    if (mode == 1) {
        rate = c[4];
        if (rate <= 0.0f) {
            if (c[5] < c[3]) {
                c[3] = c[5];
            }
            return;
        }
        if (1.0f <= rate) {
            c[3] = c[5] + c[6];
            return;
        }
        r = c[5];
        sum = c[5] + c[6];
        if (rate <= 0.0f) {
            r = c[5];
        } else {
            r = sum;
            if (rate < 1.0f) {
                if (sum == c[5]) {
                    c[3] = sum;
                    return;
                }
                r = rate * sum + (1.0f - rate) * c[5];
            }
        }
        c[3] = r;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", func_4001E138);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", func_4001E1E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", func_4001E3A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", bgEnd);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0008_GAMEUTIL_set_param_extend_interp_ratio_c", bgDraw);

void bgBegin(void) {
    iosDlPushLayer(1);
    texResetVRAMRequest(0x400);
    iosSetRootDC();
    iosDlPopLayer();
}
