#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5468);
/* GAMECORE c0190 func_400F5530: 100 in scratch; Ghidra param order is wrong (dst a0, arr a1, n a2, float val f12); `for (i=0;i<n;i++) arr[i]=val` is what makes gcc copy a1/a2 for the loop */
extern void *memset(void *, int, unsigned int);
extern f32 D_401322B0;

/* GAMECORE c0190 func_400F5A68: 100 in scratch; `dst->q = src->q` on the Q4 union keeps lq/sq (whole-union assign gives ld/sd); return via if/return 1/return 0 (lay != 0 gives sltu) */
typedef union { s128 q; float f[4]; } Q4;
extern u8 *GetLayoutClass(s32);

/* GAMECORE c0190 func_400F5AB0: 100 in scratch; re-read *(p+0x80) in the while test and the if, do -=/+= on memory (local-var form got 90.2: CSE removed the reload) */
extern void gameModeSet(u32);
extern void gameModeCls(u32);

extern void boot_camera_lws_animation_by_script(s32);
extern void *get_camera_obj(void *);
extern void *get_camera_position(void *);
extern s32 get_main_type_camera_lws_animation(void *);

f32 func_400F5468(u8 *p)
{
    return *(f32 *)(p + 0x250);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5470);
f32 func_400F5470(u8 *p)
{
    return *(f32 *)(p + 0x258);
}

extern s32 act_camera_cutout_game_camera_param_manager(u8 *, u8 *);

static inline s32 isCutoutMode(u8 *cam)
{
    if (*(s32 *)(cam + 0x13C0) == 0 || *(s32 *)(cam + 0x13C0) == 8) {
        return 1;
    }
    return 0;
}

static inline s32 isCutout(u8 *cam)
{
    if (isCutoutMode(cam) == 1 || act_camera_cutout_game_camera_param_manager(cam + 0x50, cam) == 1) {
        return 1;
    }
    return 0;
}

void func_400F5478(u8 *w, u8 *cam)
{
    s32 cut = isCutout(cam);

    if (cut == 1) {
        *(s32 *)(w + 0x18A4) = 0;
    } else if (*(s32 *)(w + 0x18B0) == 1) {
        *(s32 *)(w + 0x18A4) = 0;
    } else if (*(s32 *)(w + 0x18B0) == 2) {
        *(s32 *)(w + 0x18A4) += 1;
    }
    if (*(s32 *)(w + 0x18A4) >= 10) {
        *(s32 *)(cam + 0x2D20) = 5;
    }
}

void *func_400F5530(void *dst, float *arr, s32 n, float val)
{
    void *r = memset(dst, 0, n << 2);
    s32 i; for (i = 0; i < n; i++) arr[i] = val;
    return r;
}

extern s32 GAMEUTIL_is_nearly_equal_zero(f32, f32);

s32 func_400F55A8(f32 *out, s32 n, f32 *vals, f32 *ids, f32 def)
{
    s32 i;
    f32 max = vals[0];

    *out = ids[0];
    for (i = 1; i < n; i++) {
        if (max < vals[i]) {
            max = vals[i];
            *out = ids[i];
        }
    }
    if (GAMEUTIL_is_nearly_equal_zero(max, 0.0001f) == 1) {
        *out = def;
        return 0;
    }
    return 1;
}

/* NEARMISS-STUB func_400F5650 */
#if 0 /* NEARMISS 92.33% cat=regalloc sub=- | d2 r101: 0x3F4CCCCC needs literal 0.79999998f (0.79999995f parses to ...CB); left: yaw ptr/w+0x44 s3/s4 swapped and the w->0x88 reload is hoisted above the *yaw | attempts=1 */
extern void CAM_set_interp_param_aim_rot_common(void *, f32, f32);
extern f32 CAM_doit_aim_angle_rot(void *, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

typedef struct {
    u8 yaw[0x44];
    u8 pitch[0x44];
    s32 mode;
} C190Aim;

void func_400F5650(f32 *yaw, f32 *pitch, C190Aim *w, u8 *p, u8 *cam)
{
    f32 a, b, c, d;

    if (w->mode == 0) {
        a = *(f32 *)(p + 0x30);
        b = *(f32 *)(p + 0x34);
        c = *(f32 *)(p + 0x38);
        d = *(f32 *)(p + 0x3C);
    } else {
        a = *(f32 *)(p + 0x40);
        b = *(f32 *)(p + 0x44);
        c = *(f32 *)(p + 0x48);
        d = *(f32 *)(p + 0x4C);
    }
    CAM_set_interp_param_aim_rot_common(w->yaw, 0.0f, 0.79999998f);
    *yaw = CAM_doit_aim_angle_rot(w->yaw, *(s32 *)(p + 0x18), *(f32 *)(cam + 0xD0), *(f32 *)(p + 0x10),
                                  *(f32 *)(p + 0x24), *(f32 *)(p + 0x28), a, b, c, d, D_401322B0);
    if (w->mode == 0) {
        a = *(f32 *)(p + 0x5C);
        b = *(f32 *)(p + 0x60);
        c = *(f32 *)(p + 0x64);
        d = *(f32 *)(p + 0x68);
    } else {
        a = *(f32 *)(p + 0x6C);
        b = *(f32 *)(p + 0x70);
        c = *(f32 *)(p + 0x74);
        d = *(f32 *)(p + 0x78);
    }
    CAM_set_interp_param_aim_rot_common(w->pitch, 0.0f, 0.79999998f);
    *pitch = CAM_doit_aim_angle_rot(w->pitch, *(s32 *)(p + 0x1C), *(f32 *)(cam + 0xD4), *(f32 *)(p + 0x14),
                                    *(f32 *)(p + 0x50), *(f32 *)(p + 0x54), a, b, c, d, D_401322B0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5650);

extern s32 GAMEUTIL_is_inside_of_region_yaw(f32, f32, f32, s32, s32);
extern s32 GAMEUTIL_is_inside_of_region_pitch(f32, f32, f32, s32, s32);

void func_400F57D8(u8 *w, u8 *cam, u8 *p)
{
    f32 pitch;

    if (*(s32 *)(w + 0x88) == 0) {
        pitch = *(f32 *)(p + 0x14);
        if (GAMEUTIL_is_inside_of_region_yaw(*(f32 *)(cam + 0x110), *(f32 *)(p + 0x10), *(f32 *)(p + 0x2C), 0, 0) != 0
            && GAMEUTIL_is_inside_of_region_pitch(*(f32 *)(cam + 0x114), pitch, *(f32 *)(p + 0x58), 0, 0) != 0) {
            *(f32 *)(w + 0x8C) += D_401322B0;
            if (*(f32 *)(p + 0x20) <= *(f32 *)(w + 0x8C)) {
                *(s32 *)(w + 0x88) = 1;
            }
        } else {
            *(s32 *)(w + 0x8C) = 0;
        }
    }
}

extern void set_param_double_spring_interp_common(u8 *, f32, f32, f32, f32);
extern void reset_double_spring_interp_cntrl3D(u8 *, Q4 *);
extern void doit_double_spring_interp_cntrl3D(f32, u8 *, u8 *, s32);

void func_400F5890(u8 *w, f32 *prm, s32 flag, Q4 *v)
{
    set_param_double_spring_interp_common(w + 0x20, prm[0], prm[2], prm[1], -1.0f);
    if (*(s32 *)w == 0) {
        if (flag == 1) {
            *(s32 *)w = 1;
            ((Q4 *)(w + 0x10))->q = v->q;
            reset_double_spring_interp_cntrl3D(w + 0x20, v);
        }
    } else {
        if (flag == 1) {
            ((Q4 *)(w + 0x10))->q = v->q;
        }
        doit_double_spring_interp_cntrl3D(D_401322B0, w + 0x20, w + 0x10, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5978);

s32 func_400F5A68(Q4 *dst, u8 *obj)
{
    u8 *lay = GetLayoutClass(*(s32 *)(obj + 0x124));
    if (lay != 0) {
        dst->q = (*(Q4 **)(lay + 0x134))->q;
        return 1;
    }
    return 0;
}

void func_400F5AB0(u8 *p)
{
    while (*(s32 *)(p + 0x80) != 0) { if (*(s32 *)(p + 0x80) > 0) { gameModeCls(1); *(s32 *)(p + 0x80) -= 1; } else { gameModeSet(1); *(s32 *)(p + 0x80) += 1; } }
}

s32 func_400F5B20(u8 *p, void *cam)
{
    if (*(s32 *)(p + 0x90) == 0 && *(s32 *)(p + 0xf8) != 0) {
        boot_camera_lws_animation_by_script(*(s32 *)(p + 0xf8));
        *(s32 *)(p + 0x90) = get_main_type_camera_lws_animation(get_camera_position(get_camera_obj(cam)));
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5B90);
int func_400F5B90(int t)
{
    switch (t) {
    case 2 ... 3:
    case 7 ... 8:
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB func_400F5BD0 */
#if 0 /* NEARMISS 99.58% cat=regalloc sub=- | d2 r101: seg != 0 first gives the layout (seg==0 first 91.8); only regs left: target const 1 in v0 and the 0x90 load in a0, ours v1/v0. storing mode vs 1: same | attempts=1 */
extern s32 get_camera_lws_animation_param();
extern s32 GAMEUTIL_get_segment_num_and_data(s32, s32);
extern s32 bgmDemoPackagePreload(s32);
extern void bgmDemoPackagePlay(s32);
extern void scriptIntrSignal();
extern s32 ScrIntrDef_DEMO_CONTINUE;
extern s32 ScrIntrDef_DEMO_PAUSE;

void func_400F5BD0(u8 *w, s32 mode)
{
    s32 seg;

    if (mode == 1) {
        *(s32 *)(w + 0x88) = mode;
    }
    if (*(s32 *)(w + 0x90) == 0) {
        *(s32 *)(w + 0x88) = 0;
    }
    if (*(s32 *)(w + 0x88) == 1) {
        seg = GAMEUTIL_get_segment_num_and_data(0, get_camera_lws_animation_param() + 0x14);
        if (seg != 0) {
            if (bgmDemoPackagePreload(seg) == 1) {
                bgmDemoPackagePlay(seg);
                *(s32 *)(w + 0x88) = 0;
                if (mode == 0) {
                    scriptIntrSignal(ScrIntrDef_DEMO_CONTINUE);
                }
            } else if (mode == 1) {
                scriptIntrSignal(ScrIntrDef_DEMO_PAUSE);
            }
        } else {
            *(s32 *)(w + 0x88) = 0;
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5BD0);

typedef struct {
    u8 pad[0x40];
    Q4 pos;
} C190ColRes;
extern s32 camera_collision_check_direct(void *, Q4 *, Q4 *, void *, s32, s32, void *, s32);

void func_400F5CC0(void *out, Q4 *from, Q4 *to, void *col, void *e)
{
    C190ColRes res;
    Q4 v;

    if (camera_collision_check_direct(&res, from, to, col, 1, 1, e, 0) == 1) {
        v.q = res.pos.q;
    } else {
        v.q = to->q;
    }
    camera_collision_check_direct(out, &v, from, col, 1, 1, e, 0);
}

void *func_400F5D68(u8 *p)
{
    *(s32 *)p = 0;
    memset(p + 0x4, 0, 0x48);
    memset(p + 0x4c, 0, 0x1b4);
    memset(p + 0x200, 0, 0xcc);
    memset(p + 0x2cc, 0, 0x84);
    memset(p + 0x350, 0, 0xd0);
    memset(p + 0x420, 0, 0xe4);
    memset(p + 0x504, 0, 0xe4);
    return memset(p + 0x5e8, 0, 0x8c);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5E08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F6438);
