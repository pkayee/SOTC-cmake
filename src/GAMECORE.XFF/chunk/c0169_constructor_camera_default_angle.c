#include "common.h"

extern u128 ZUnitVector;
extern u128 IdentityQuaternion;
extern u128 ZeroPoint;
void GAMEUTIL_reset_status_manager(void *, s32);
void constructor_aim_angle_interp_cntrl(void *c, s32 v);
void GAMEUTIL_constructor_interp_ratio_cntrl(void *c);
void CAM_reset_slope_cntrl(void *c);
void func_400DF220(u8 *p);
void constructor_camera_target_visible_angle_manager(void *p);

/* GAMECORE c0169: default-angle camera per-frame step. rs = is_reset_or_lws_movie_or_cutout_game_camera result. p = default-angle work, cam = game camera (cam+0 attr block, cam+0xA0 attr copy, cam+0x710 pitch approach), a2+0x50 param manager. CAM_doit_slope_cntrl prototype puts dt LAST (float-first = 97.1, the f12 move lands before the a0 delay slot); func_400DF248 declared K&R since the tail call passes cam too */
s32 is_reset_or_lws_movie_or_cutout_game_camera(void *a);
void CAM_doit_slope_cntrl(void *c, void *cam, void *a3, f32 dt);
void func_400DE9F0(u8 *p, u8 *cam, void *a2, void *a3, s32 flag, f32 dt);
void GAMEUTIL_set_act_interp_flag_interp_ratio_cntrl(void *c, s32 v);
void reset_aim_angle_interp_cntrl(void *c, f32 v);
void doit_aim_angle_interp_cntrl(void *c, f32 a, f32 b, s32 flag, f32 dt);
void set_interp_param_aim_angle_interp_cntrl(void *c, f32 a, f32 b);
s32 is_base_default_dir_attr_change_game_camera_param_manager(void *m);
void GAMEUTIL_reset_interp_ratio_cntrl(void *c);
f32 get_interp_time_game_camera_param_manager(void *m);
void GAMEUTIL_set_param_interp_ratio_cntrl(void *c, f32 a, f32 b);
s32 GAMEUTIL_get_cur_status_status_manager();
s32 GAMEUTIL_is_status_change_status_manager(void *m);
s32 is_cut_default_pitch_interp_camera_target_approach(void *a);
void GAMEUTIL_forward_timer_still_one_ratio_time_interp_ratio_cntrl(void *c);
void GAMEUTIL_doit_interp_ratio_cntrl(void *c, f32 dt);
void func_400DF248();

/* GAMECORE c0169: node position of the default-angle focus object. mode 101..104 picks the object (jump table D_401370E0), 100 / out of range = NULL */
s32 GetSkeletonFocusNode(void *a);
void *CAM_get_target_obj(void *p);
s32 get_place_status_camera_place_status(void *p);
void *get_manage_obj_camera_place_status(void *p);
void *GAMEUTIL_get_parent_object(void *o);
void *GAMEUTIL_get_boss_obj();
void GAMEUTIL_get_node_posi_by_id(void *out, void *obj, s32 node);

/* GAMECORE c0169: default-angle camera yaw/pitch interp step. p+0x60 = interp ratio cntrl (state 1 = interpolating), p+0x38/0x3C cur yaw/pitch, p+0x1C/0x2C target yaw/pitch, p+0x40/0x44 out yaw/pitch. store order 38,3C,40,44 in source gives the target order 40,44,38,3C (permutation search) */
f32 GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(void *c);
f32 GAMEUTIL_get_interp_yaw(f32 a, f32 b, f32 t);
f32 GAMEUTIL_get_interp_pitch(f32 a, f32 b, f32 t);

/* GAMECORE c0169: default-angle focus object by mode (same switch as func_400DF098, jump table D_40137100) */
void *CAM_get_target_obj(void *p);

/* GAMECORE c0169: set the two aim-angle interps (p+0x358, p+0x368) from a/b with common c. a1 is an unused pass-through slot. the callee prototype order (cntrl, f32, f32, s32 flag, f32) gives the target arg-emit order and regalloc of f20-f22 (a plain f32,f32,f32,ptr,flag order = 62.87) */
void doit_aim_angle_interp_cntrl(void *c, f32 a, f32 b, s32 flag, f32 dt);

void constructor_camera_default_angle(u8 *p)
{
    f32 z;
    GAMEUTIL_reset_status_manager(p, 0);
    constructor_aim_angle_interp_cntrl(p + 0x10, 1);
    constructor_aim_angle_interp_cntrl(p + 0x20, 2);
    z = 0.0f;
    *(f32 *)(p + 0x34) = z;
    *(f32 *)(p + 0x30) = z;
    *(f32 *)(p + 0x3C) = z;
    *(f32 *)(p + 0x38) = z;
    *(f32 *)(p + 0x44) = z;
    *(f32 *)(p + 0x40) = z;
    *(u128 *)(p + 0x50) = ZUnitVector;
    GAMEUTIL_constructor_interp_ratio_cntrl(p + 0x60);
    *(s32 *)(p + 0x80) = 0;
    CAM_reset_slope_cntrl(p + 0x90);
    *(f32 *)(p + 0x354) = z;
    *(f32 *)(p + 0x350) = z;
    constructor_aim_angle_interp_cntrl(p + 0x358, 0);
    constructor_aim_angle_interp_cntrl(p + 0x368, 2);
    func_400DF220(p);
    constructor_camera_target_visible_angle_manager(p + 0x390);
    *(s32 *)(p + 0x780) = 0;
    *(u128 *)(p + 0x790) = IdentityQuaternion;
    *(u128 *)(p + 0x7A0) = ZeroPoint;
    *(s32 *)(p + 0x7B0) = 0;
    *(u128 *)(p + 0x7C0) = ZeroPoint;
    *(u128 *)(p + 0x7D0) = ZeroPoint;
    *(u128 *)(p + 0x7E0) = ZeroPoint;
}

void doit_camera_default_angle(u8 *p, u8 *cam, u8 *a2, void *a3, f32 dt)
{
    s32 rs;
    s32 st;
    s32 chg;
    u8 *ir;
    u8 *ca;
    u8 *cb;

    rs = is_reset_or_lws_movie_or_cutout_game_camera(a2);
    if (rs == 1) {
        CAM_reset_slope_cntrl(p + 0x90);
    } else {
        CAM_doit_slope_cntrl(p + 0x90, cam, a3, dt);
    }
    func_400DE9F0(p, cam, a2, a3, rs, dt);
    if (rs == 1) {
        GAMEUTIL_set_act_interp_flag_interp_ratio_cntrl(p + 0x60, 0);
        reset_aim_angle_interp_cntrl(p + 0x10, *(f32 *)(p + 0x30));
        reset_aim_angle_interp_cntrl(p + 0x20, *(f32 *)(p + 0x34));
    } else {
        ir = p + 0x60;
        GAMEUTIL_set_act_interp_flag_interp_ratio_cntrl(ir, 1);
        ca = cam + 0xA0;
        chg = 0;
        st = 0;
        if (is_base_default_dir_attr_change_game_camera_param_manager(a2 + 0x50) == 1) {
            GAMEUTIL_reset_interp_ratio_cntrl(ir);
            GAMEUTIL_set_param_interp_ratio_cntrl(ir, 0.0f, get_interp_time_game_camera_param_manager(a2 + 0x50));
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x40);
            *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x44);
        }
        cb = p + 0x10;
        set_interp_param_aim_angle_interp_cntrl(cb, *(f32 *)(*(s32 *)cam + 0xCC), *(f32 *)(*(s32 *)cam + 0xD0) * 3.1415927f / 180.0f);
        a2 = p + 0x20;
        set_interp_param_aim_angle_interp_cntrl(a2, *(f32 *)(*(s32 *)cam + 0xD4), *(f32 *)(*(s32 *)cam + 0xD8) * 3.1415927f / 180.0f);
        if (GAMEUTIL_get_cur_status_status_manager(p) == 2) {
            if (GAMEUTIL_is_status_change_status_manager(p) == 1) {
                st = 1;
                chg = 1;
            }
        }
        if (chg == 1 || *(s32 *)(cam + 0xFA8) == 0) {
            reset_aim_angle_interp_cntrl(cb, *(f32 *)(p + 0x30));
        } else {
            doit_aim_angle_interp_cntrl(cb, *(f32 *)(p + 0x30), *(f32 *)(ca + 0x30), 0, dt);
        }
        if (is_cut_default_pitch_interp_camera_target_approach(cam + 0x710) == 1) {
            st = 1;
        }
        if (st == 1 || *(s32 *)(cam + 0xFAC) == 0) {
            reset_aim_angle_interp_cntrl(a2, *(f32 *)(p + 0x34));
        } else {
            doit_aim_angle_interp_cntrl(a2, *(f32 *)(p + 0x34), *(f32 *)(ca + 0x34), 0, dt);
        }
        if (*(s32 *)(*(s32 *)cam + 0xC8) == 0 || GAMEUTIL_get_cur_status_status_manager(p) == 2) {
            GAMEUTIL_forward_timer_still_one_ratio_time_interp_ratio_cntrl(ir);
        }
        GAMEUTIL_doit_interp_ratio_cntrl(ir, dt);
    }
    func_400DF248(p, cam);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DE9F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", get_base_default_direction);

void func_400DF098(void *out, s32 mode, void *a2, u8 *cam)
{
    s32 node = GetSkeletonFocusNode(a2);
    u8 *ps = cam + 0x12F0;
    void *obj = 0;
    switch (mode) {
    case 100:
        break;
    case 101:
        obj = CAM_get_target_obj(cam + 0x240);
        break;
    case 102:
        if (get_place_status_camera_place_status(ps) == 2) {
            obj = get_manage_obj_camera_place_status(ps);
        } else {
            obj = GAMEUTIL_get_parent_object(CAM_get_target_obj(cam + 0x240));
        }
        break;
    case 103:
        obj = get_manage_obj_camera_place_status(ps);
        break;
    case 104:
        obj = GAMEUTIL_get_boss_obj();
        break;
    }
    GAMEUTIL_get_node_posi_by_id(out, obj, node);
}

extern s32 GAMEUTIL_get_cur_status_status_manager();

s32 get_cur_attr_camera_default_angle(s32 a, s32 b, s32 c, s32 d)
{
    return GAMEUTIL_get_cur_status_status_manager(a, b, c, d);
}

s32 is_safety_camera_default_angle(void)
{
    return GAMEUTIL_get_cur_status_status_manager() != 1;
}

void *CAM_get_ground_contact_obj(void *);
int GAMEUTIL_is_boss_obj(void *, int);

int is_must_reach_normal_default_angle(char *c)
{
    if (GAMEUTIL_is_boss_obj(CAM_get_ground_contact_obj(c + 0x240), 1) == 1 || *(int *)(*(char **)c + 4) == 2) return 1;
    return 0;
}

void GAMEUTIL_reset_status_manager(void *, s32);

void func_400DF220(u8 *p)
{
    *(s32 *)(p + 0x378) = 1;
    GAMEUTIL_reset_status_manager(p + 0x37c, 1);
}

void func_400DF248(u8 *p)
{
    f32 t;
    if (*(s32 *)(p + 0x60) == 1) {
        t = GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(p + 0x60);
        *(f32 *)(p + 0x40) = GAMEUTIL_get_interp_yaw(*(f32 *)(p + 0x38), *(f32 *)(p + 0x1C), t);
        *(f32 *)(p + 0x44) = GAMEUTIL_get_interp_pitch(*(f32 *)(p + 0x3C), *(f32 *)(p + 0x2C), t);
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x1C);
        *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x2C);
        *(f32 *)(p + 0x40) = *(f32 *)(p + 0x1C);
        *(f32 *)(p + 0x44) = *(f32 *)(p + 0x2C);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF2D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF408);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF518);

void *func_400DF5E0(s32 mode, u8 *cam)
{
    u8 *ps = cam + 0x12F0;
    void *obj = 0;
    switch (mode) {
    case 100:
        break;
    case 101:
        obj = CAM_get_target_obj(cam + 0x240);
        break;
    case 102:
        if (get_place_status_camera_place_status(ps) == 2) {
            obj = get_manage_obj_camera_place_status(ps);
        } else {
            obj = GAMEUTIL_get_parent_object(CAM_get_target_obj(cam + 0x240));
        }
        break;
    case 103:
        obj = get_manage_obj_camera_place_status(ps);
        break;
    case 104:
        obj = GAMEUTIL_get_boss_obj();
        break;
    }
    return obj;
}

void func_400DF6A8(u8 *p, void *unused, s32 flag, f32 a, f32 b, f32 c)
{
    *(f32 *)(p + 0x350) = a;
    *(f32 *)(p + 0x354) = b;
    doit_aim_angle_interp_cntrl(p + 0x358, a, 0.0f, flag, c);
    doit_aim_angle_interp_cntrl(p + 0x368, b, 0.0f, flag, c);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF728);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0169_constructor_camera_default_angle", func_400DF850);
