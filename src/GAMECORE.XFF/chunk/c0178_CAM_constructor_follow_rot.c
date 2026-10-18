#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_constructor_follow_rot);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", func_400E70B0);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_get_yaw_velocity);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_get_pitch_velocity);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_near_to_aim_yaw);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0178_CAM_constructor_follow_rot", CAM_near_to_aim_pitch);
