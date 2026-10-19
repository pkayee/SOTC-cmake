#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_constructor_follow_rot);

void *CAM_get_ground_contact_obj(u8 *);
void *GAMEUTIL_get_motion_kind(void *);
void func_400EAA48(void *ratio, void *val, f32 target, f32 rate);

void func_400E70B0(u8 *w, u8 *cam, f32 rate)
{
    s32 kind;
    void *obj;
    u8 *m;
    f32 t;

    obj = CAM_get_ground_contact_obj(cam + 0x240);
    if (obj != 0 && (m = GAMEUTIL_get_motion_kind(obj)) != 0)
        kind = *(s32 *)(m + 0x6C) & 0xF;
    else
        kind = 1;
    t = 0.0f;
    if (kind == 1 || kind == 2)
        t = 1.0f;
    func_400EAA48(w + 0x60, w + 0x80, t, rate);
    t = 0.0f;
    if (kind == 1 || kind == 3)
        t = 1.0f;
    func_400EAA48(w + 0x8C, w + 0xAC, t, rate);
    t = 0.0f;
    if (kind == 1 || kind == 4)
        t = 1.0f;
    func_400EAA48(w + 0xB8, w + 0xD8, t, rate);
    t = 0.0f;
    if (kind == 1 || kind == 5)
        t = 1.0f;
    func_400EAA48(w + 0xE4, w + 0x104, t, rate);
    t = 0.0f;
    if (kind == 1 || kind == 6)
        t = 1.0f;
    func_400EAA48(w + 0x110, w + 0x130, t, rate);
    t = 0.0f;
    if (kind == 1 || kind == 7)
        t = 1.0f;
    func_400EAA48(w + 0x13C, w + 0x15C, t, rate);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", func_400E7220);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", func_400E7470);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", func_400E75F0);

s32 _optionWorkChk(s32 idx);
s32 getDrawScreenHeight(void);
s32 getDrawScreenWidth(void);
void *get_camera_obj(void *);
s32 get_main_cameraman(void);
s32 set_camera_obj_screen_size(s8 *, s32, s32);
void set_screen_wide_and_progressive(s32, s32);
void update_camera_obj(void *);

void setAspect(void)
{
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s8 *temp_v0_2;

    temp_s0 = _optionWorkChk(2);
    set_screen_wide_and_progressive(temp_s0, _optionWorkChk(6));
    temp_v0 = get_main_cameraman();
    if (temp_v0 != 0)
    {
        temp_v0_2 = get_camera_obj((void *)temp_v0);
        if (temp_v0_2 != NULL)
        {
            temp_s0_2 = getDrawScreenWidth();
            set_camera_obj_screen_size(temp_v0_2, temp_s0_2, getDrawScreenHeight());
            update_camera_obj(temp_v0_2);
        }
    }
}

void *get_cur_camera_target(void *);
void *GAMEUTIL_get_boss_obj(void);
void *getBossCloudObj(void);
void *GAMEUTIL_get_obj_from_stagelayout_sheet(void *);

void *CAM_get_parent_obj_by_base_space(int type, void *sheet, void *obj, void *cam)
{
    void *o;

    if (type == 1)
        return 0;
    if (type == 2 || type == 8)
        return get_cur_camera_target(cam);
    if (type == 3)
        return GAMEUTIL_get_boss_obj();
    if (type == 4)
        return getBossCloudObj();
    if (type == 7) {
        o = GAMEUTIL_get_boss_obj();
        if (o != 0)
            return o;
        return getBossCloudObj();
    }
    if (type == 5)
        return GAMEUTIL_get_obj_from_stagelayout_sheet(sheet);
    if (type == 6)
        return obj;
    return 0;
}

float iosGetRandom(void);
extern int D_40132210;

void CAM_shuffle_lws_base_space_target_boss_interest_axis_X(void)
{
    if (iosGetRandom() < 0.5f) {
        D_40132210 = 1;
        return;
    }
    D_40132210 = 0;
}

f32 GAMEUTIL_get_difference_yaw_and_yaw(f32, f32);
f32 GAMEUTIL_get_difference_pitch_and_pitch(f32, f32);
f32 func_400E9498(f32, f32);
f32 powf(f32, f32);

f32 CAM_get_yaw_velocity(f32 yaw, f32 aim, f32 max_vel, f32 min_vel, f32 range, f32 exp)
{
    f32 half = (range * 0.5f * 3.14159253f) / 180.0f;
    f32 vmax = (max_vel * 3.14159253f) / 180.0f;
    f32 vmin = (min_vel * 3.14159253f) / 180.0f;
    f32 r;

    r = func_400E9498(GAMEUTIL_get_difference_yaw_and_yaw(yaw, aim), half);
    return vmin + (vmax - vmin) * powf(r, exp);
}


f32 CAM_get_pitch_velocity(f32 pitch, f32 aim, f32 max_vel, f32 min_vel, f32 range, f32 exp)
{
    f32 vmin = (min_vel * 3.14159253f) / 180.0f;
    f32 half = (range * 0.5f * 3.14159253f) / 180.0f;
    f32 vmax = (max_vel * 3.14159253f) / 180.0f;
    f32 d = GAMEUTIL_get_difference_pitch_and_pitch(pitch, aim);
    f32 r;

    if (d >= half)
        r = 1.0f;
    else
        r = d / half;
    return vmin + (vmax - vmin) * powf(r, exp);
}

int CAM_is_reach_aim_yaw(float *out, int dir, float a, float b, float c, float d)
{
    int r = 0;
    float t;

    if (a == d || c == d) {
        c = d;
        r = 1;
    } else if (dir == 1) {
        t = d;
        if (d < a)
            t = d + 6.283185307179586f;
        if (t < a + b) {
            c = d;
            r = 1;
        }
    } else if (dir == -1) {
        t = d;
        if (a < d)
            t = d - 6.283185307179586f;
        if (a - b < t) {
            c = d;
            r = 1;
        }
    }
    if (out != 0)
        *out = c;
    return r;
}

int CAM_is_reach_aim_pitch(float *out, int dir, float start, float unused, float pitch, float aim)
{
    int reached = 0;

    if (start == aim || pitch == aim) {
        pitch = aim;
        reached = 1;
    } else if (dir == 1) {
        if (aim < pitch) {
            pitch = aim;
            reached = 1;
        }
    } else if (dir == -1) {
        if (pitch < aim) {
            pitch = aim;
            reached = 1;
        }
    }
    if (out != 0) {
        *out = pitch;
    }
    return reached;
}

static inline int reachAimYaw(float *out, int dir, float a, float b, float c, float d)
{
    int r = 0;
    float t;

    if (a == d || c == d) {
        c = d;
        r = 1;
    } else if (dir == 1) {
        t = d;
        if (d < a)
            t = d + 6.283185307179586f;
        if (t < a + b) {
            c = d;
            r = 1;
        }
    } else if (dir == -1) {
        t = d;
        if (a < d)
            t = d - 6.283185307179586f;
        if (a - b < t) {
            c = d;
            r = 1;
        }
    }
    if (out != 0)
        *out = c;
    return r;
}

static inline int reachAimPitch(float *out, int dir, float start, float unused, float pitch, float aim)
{
    int reached = 0;

    if (start == aim || pitch == aim) {
        pitch = aim;
        reached = 1;
    } else if (dir == 1) {
        if (aim < pitch) {
            pitch = aim;
            reached = 1;
        }
    } else if (dir == -1) {
        if (pitch < aim) {
            pitch = aim;
            reached = 1;
        }
    }
    if (out != 0) {
        *out = pitch;
    }
    return reached;
}

s32 GAMEUTIL_inc_or_dec_for_near_to_aim_yaw(f32 *, f32, f32, f32);
s32 GAMEUTIL_inc_or_dec_for_near_to_aim_pitch(f32 *, f32, f32, f32);

f32 CAM_near_to_aim_yaw(s32 *dir_out, f32 yaw, f32 vel, f32 aim)
{
    f32 v = 0.0f;
    s32 dir = GAMEUTIL_inc_or_dec_for_near_to_aim_yaw(&v, yaw, vel, aim);

    reachAimYaw(&v, dir, yaw, vel, v, aim);
    if (dir_out != 0)
        *dir_out = dir;
    return v;
}


f32 CAM_near_to_aim_pitch(s32 *dir_out, f32 pitch, f32 vel, f32 aim)
{
    f32 v = 0.0f;
    s32 dir = GAMEUTIL_inc_or_dec_for_near_to_aim_pitch(&v, pitch, vel, aim);

    reachAimPitch(&v, dir, pitch, vel, v, aim);
    if (dir_out != 0)
        *dir_out = dir;
    return v;
}
