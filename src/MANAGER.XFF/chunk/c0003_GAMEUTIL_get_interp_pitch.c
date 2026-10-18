#include "common.h"

#define NEARABS(x) ((x) < 0.0f ? -(x) : (x))

extern s32 DldSysUndefSymbol;
s32 GetLayoutClass();
s32 GetCharacterClass();
s32 GetLayoutParentObj();
s32 GetParentCharColAttr();
s32 GetGeometryPointerSurfacePlane();
extern u128 XUnitVector;
extern u128 YUnitVector;
extern u128 ZUnitVector;
void GetOffsetPositionAxis();

static inline s32 nearlyZero3D(f32 eps, f32 *v) {
    if (NEARABS(v[0]) <= eps && NEARABS(v[1]) <= eps && NEARABS(v[2]) <= eps) {
        return 1;
    }
    return 0;
}

/* dld link word: bits 0..17 = byte distance back to a slot holding the target (or DldSysUndefSymbol) */
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

/* NEARMISS-STUB GAMEUTIL_get_interp_pitch */
#if 0 /* NEARMISS 54.0% cat=regalloc sub=constant-load-placement | best 54.0% (iter3 C: !(t<=0)&&!(1<=t) form, single exit r, eps/hi/lo as consts). diff: near-check bool materialization (addiu/daddu v0) and f-reg naming differ; | attempts=1 */
f32 GAMEUTIL_get_interp_pitch(f32 a, f32 b, f32 t)
{
    f32 d;
    f32 r;
    f32 nd;
    s32 near;

    r = a;
    if (!(t <= 0.0f) && !(1.0f <= t)) {
        d = t * (b - a);
        if (d < 0.0f) {
            nd = -d;
            near = nd <= 0.0001f;
        } else {
            near = d <= 0.0001f;
        }
        if (!near) {
            if (1.4835296f < a) {
                if (d < 0.0f) {
                    r = a + d;
                }
            } else if (a < -1.4835296f) {
                if (0.0f < d) {
                    r = a + d;
                }
            } else {
                r = a + d;
                if (1.4835296f < r) {
                    r = 1.4835296f;
                } else if (r < -1.4835296f) {
                    r = -1.4835296f;
                }
            }
        }
    }
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_interp_pitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_act_yaw_rot_region_check);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_act_pitch_rot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_act_pitch_rot_limit_clip);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_rot_dir_for_near_to_aim_yaw_dir);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_near_to_aim_pitch_dir);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_is_nearly_equal_zero);

s32 GAMEUTIL_is_nearly_equal_zero(f32 v, f32 eps) {
    if (NEARABS(v) <= eps) {
        return 1;
    }
    return 0;
}

s32 GAMEUTIL_is_nearly_equal_zero3D(f32 eps, f32 *v) {
    if (NEARABS(v[0]) <= eps && NEARABS(v[1]) <= eps && NEARABS(v[2]) <= eps) {
        return 1;
    }
    return 0;
}

s32 GAMEUTIL_is_diff_nearly_equal_zero(f32 a, f32 b, f32 eps) {
    f32 d = a - b;

    if (NEARABS(d) <= eps) {
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB GAMEUTIL_is_diff_nearly_equal_zero3D */
#if 0 /* NEARMISS 63.8% cat=vu0-mmi sub=- | VU0 vsub.xyz on 16-byte vectors via lqc2/sqc2 + stack round-trip; C float sub gives per-component sub.s/lwc1 and different load/branch layout (arg_mism all over | attempts=1 */
s32 GAMEUTIL_is_diff_nearly_equal_zero3D(f32 eps, f32 *a, f32 *b)
{
    f32 x;

    x = a[0] - b[0];
    if (x < 0.0f) {
        if (!(-x <= eps)) {
            return 0;
        }
    } else {
        if (!(x <= eps)) {
            return 0;
        }
    }
    x = a[1] - b[1];
    if (x < 0.0f) {
        if (!(-x <= eps)) {
            return 0;
        }
    } else {
        if (!(x <= eps)) {
            return 0;
        }
    }
    x = a[2] - b[2];
    if (x < 0.0f) {
        if (!(-x <= eps)) {
            return 0;
        }
    } else {
        if (!(x <= eps)) {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_is_diff_nearly_equal_zero3D);

/* NEARMISS-STUB GAMEUTIL_get_answer_of_2jihouteishiki */
#if 0 /* NEARMISS 0.0% cat=no-c-form sub=- | sqrt.s inline (c1 funct 4, fd=f3) needed; ee-gcc 2.96 emits c.eq.s NaN check + jal sqrtf for sqrtf(); only inline sqrt.s matches (banned) | attempts=1 */
f32 sqrtf(f32);

s32 GAMEUTIL_get_answer_of_2jihouteishiki(f32 a, f32 b, f32 c, f32 *x0, f32 *x1)
{
    f32 d = b * b - a * 4.0f * c;
    f32 s = sqrtf(d);
    f32 t;

    *x0 = (s - b) / (a + a);
    *x1 = (-b - s) / (a + a);
    t = *x0;
    if (t < *x1) {
        *x0 = *x1;
        *x1 = t;
    }
    return 0.0f <= d;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_answer_of_2jihouteishiki);

/* NEARMISS-STUB GAMEUTIL_get_cross_position_coefficient_t_by_dist_factor */
#if 0 /* NEARMISS 45.08% cat=no-c-form sub=- | target is a leaf with inline sqrt.s (no call); C sqrtf() gives jal sqrtf + c.eq.s NaN check and a stack frame (45%); no C form emits inline sqrt.s under ee-gcc  | attempts=1 */
f32 sqrtf(f32);

s32 GAMEUTIL_get_cross_position_coefficient_t_by_dist_factor(f32 r, f32 *out0, f32 *out1, f32 *pa, f32 *pb, f32 *pc)
{
    f32 sa = 0.0f;
    f32 sb = 0.0f;
    f32 sc = 0.0f;
    f32 d3;
    f32 d4;
    f32 disc;
    f32 s;
    f32 x0;
    f32 x1;
    f32 t;
    s32 i;

    for (i = 0; i < 3; i++) {
        d4 = pc[i] - pb[i];
        d3 = pb[i] - pa[i];
        sa = sa + d3 * d3;
        sb = sb + d4 * d4;
        sc = sc + (d4 + d4) * d3;
    }
    disc = sc * sc - sb * 4.0f * (sa - r * r);
    s = sqrtf(disc);
    x0 = (s - sc) / (sb + sb);
    x1 = (-sc - s) / (sb + sb);
    *out0 = x0;
    *out1 = x1;
    t = *out0;
    if (t < x1) {
        *out0 = x1;
        *out1 = t;
    }
    return 0.0f <= disc;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_cross_position_coefficient_t_by_dist_factor);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_xyz_axis_from_quaternion);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_segment_num_and_data);

s32 GAMEUTIL_get_segment_num_and_data(s32 *num, u32 *lp) {
    if (num != 0) {
        *num = (s32)dldRef(lp, 0xC);
    }
    return (s32)dldRef(lp, 0x10);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_check_parent_flag);

s32 GAMEUTIL_check_parent_flag(s32 obj) {
    u8 *lc = (u8 *)GetLayoutClass(obj);

    if (lc != 0 && *(s32 *)(lc + 0x124) != 0) {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_parent_collision_attribute);

s32 GAMEUTIL_get_parent_collision_attribute(void *a, s32 b) {
    return GetParentCharColAttr(a, b);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_parent_object);

s32 GAMEUTIL_get_parent_object(s32 obj) {
    s32 lc = GetLayoutClass(obj);

    if (lc != 0) {
        return GetLayoutParentObj(lc);
    }
    return lc;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_parent_plane);

u8 *GAMEUTIL_get_parent_plane(s32 obj, s32 flag) {
    u8 *lc = (u8 *)GetLayoutClass(obj);
    u8 *cc;

    if (lc != 0 && *(s32 *)(lc + 0x124) != 0) {
        if (flag != 0) {
            cc = (u8 *)GetCharacterClass(obj);
            if (cc != 0) {
                return cc + 0x690;
            }
        }
        return (u8 *)GetGeometryPointerSurfacePlane(lc + 0xC0);
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_local_quaternion);

void GAMEUTIL_get_local_quaternion(u128 *out, s32 obj) {
    u8 *cc = (u8 *)GetCharacterClass(obj);

    if (cc != 0) {
        *out = *(u128 *)(cc + 0x460);
    } else {
        *out = **(u128 **)(GetLayoutClass(obj) + 0x13C);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_local_directionX);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_local_directionY);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_local_directionZ);

s32 GAMEUTIL_get_offset_position_by_option_space(u128 *out, u128 *in, f32 *vec, s32 mode, u128 *ax, u128 *ay, u128 *az) {
    u128 axes[3];

    if (!nearlyZero3D(0.001f, vec)) {
        if (mode == 1) {
            axes[0] = *ax;
            axes[1] = *ay;
            axes[2] = *az;
        } else {
            axes[0] = XUnitVector;
            axes[1] = YUnitVector;
            axes[2] = ZUnitVector;
        }
        GetOffsetPositionAxis(out, in, vec, &axes[0], &axes[1], &axes[2]);
        return 1;
    }
    *out = *in;
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0003_GAMEUTIL_get_interp_pitch", GAMEUTIL_get_offset_position_by_option_space);
