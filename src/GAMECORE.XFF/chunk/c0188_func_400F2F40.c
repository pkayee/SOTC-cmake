#include "common.h"

typedef struct {
    s128 q;
} Vec4;

typedef struct {
    Vec4 pos;
    Vec4 target;
    Vec4 up;
    float roll;
    float fov_offset;
    float dist;
} ModeCommonCameraData;

extern Vec4 ZUnitVector;
extern Vec4 ZeroPoint;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", func_400F2F40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", func_400F3278);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", constructor_mode_common_camera_data);

void constructor_mode_common_camera_data(ModeCommonCameraData *d)
{
    d->pos = ZeroPoint;
    d->target = ZeroPoint;
    d->up = ZUnitVector;
    d->roll = d->fov_offset = 0.0f;
    d->dist = 4.5f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", copy_mode_common_camera_data);

typedef union { s128 q; float f[4]; } CameraWord;

void copy_mode_common_camera_data(CameraWord *d, CameraWord *s)
{
    d[0].q = s[0].q;
    d[1].q = s[1].q;
    d[2].q = s[2].q;
    d[3].f[0] = s[3].f[0];
    d[3].f[1] = s[3].f[1];
    d[3].f[2] = s[3].f[2];
}

extern void CAM_get_camera_position_by_look_at(void *, s32, void *, float);
extern void GAMEUTIL_get_direction_by_yaw_pitch(s32, float, float);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", update_by_yaw_pitch_mode_common_camera_data);

void update_by_yaw_pitch_mode_common_camera_data(ModeCommonCameraData *d)
{
    s32 temp_s1;

    temp_s1 = (s32)&d->up;
    GAMEUTIL_get_direction_by_yaw_pitch(temp_s1, d->roll, d->fov_offset);
    CAM_get_camera_position_by_look_at(d, temp_s1, &d->target, d->dist);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", update_by_cam_and_look_at_posi_mode_common_camera_data);

extern void func_400F4450(int);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", flush_game_camera);

void flush_game_camera(int arg0)
{
    func_400F4450(arg0 + 0x13d0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", doit_game_camera);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", reset_game_camera);

void reset_game_camera(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x2D20)) = 5;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_game_camera_cur_mode);

int get_game_camera_cur_mode(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x13c0));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_reset_or_lws_movie_game_camera);

int is_reset_or_lws_movie_game_camera(char *p)
{
    int m = *(int *)(p + 0x13c0);

    if (m == 0 || m == 8) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_reset_or_lws_movie_or_cutout_game_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_reset_or_lws_fixed_point_or_lws_movie_or_cutout_game_camera);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_cur_using_lws_anime_mode_base_class);

char *get_cur_using_lws_anime_mode_base_class(char *cam)
{
    int mode = *(int *)(cam + 0x13C0);

    if (mode == 7)
        return cam + 0x3350;
    if (mode == 8)
        return cam + 0x35C0;
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_look_at_position_game_camera);

void get_look_at_position_game_camera(char *dst, char *src)
{
    *(s128 *)(dst + 0x0) = *(s128 *)(src + 0x1440);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", jack_game_camera);

void jack_game_camera(s32 *arg0)
{
    *arg0 = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", end_jack_game_camera);

void end_jack_game_camera(int *arg0)
{
    *arg0 = 0;
    reset_game_camera(arg0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", begin_pause_rise_game_camera);

extern void init_camera_pause_rise(void *, void *, int);

void begin_pause_rise_game_camera(int *c, int a)
{
    if (c[0] == 2)
        return;
    c[0] = 2;
    init_camera_pause_rise((char *)c + 0x3830, c, a);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", request_end_pause_rise_game_camera);

extern int request_end_camera_pause_rise();

int request_end_pause_rise_game_camera(int a, int b, int c, int d)
{
    return request_end_camera_pause_rise(a + 0x3830, a, b, d);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_end_pause_rise_game_camera);

extern int is_end_camera_pause_rise();

int is_end_pause_rise_game_camera(int a, int b, int c, int d)
{
    return is_end_camera_pause_rise(a + 0x3830, b, c, d);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_game_camera_standby_ok);

int is_game_camera_standby_ok(void *arg0)
{
    return (*(int *)((char *)(arg0) + 4));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", reset_game_camera_standby_flag);

void reset_game_camera_standby_flag(void *arg0)
{
    (*(int *)((char *)(arg0) + 4)) = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", begin_object_interest_game_camera);

void begin_object_interest_game_camera(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x31f0)) = 1;
}

void end_object_interest_game_camera(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_proper_camera_target_game_camera);

extern void *get_cur_camera_target(void *);
extern void *GetCharacterClass(void *);

int is_proper_camera_target_game_camera(void *camera)
{
    void *target = get_cur_camera_target(camera);
    if (target && GetCharacterClass(target)) return 1;
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", is_playing_lws_movie_now_game_camera);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_look_lws_anime_camera_flag);

extern unsigned char D_401322B4[];

void *get_look_lws_anime_camera_flag(void)
{
    return D_401322B4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_cur_using_camera_mode_condition_param_game_camera);

extern int get_cur_base_mode_condition_game_camera_param_manager();

int get_cur_using_camera_mode_condition_param_game_camera(int a, int b, int c, int d)
{
    return get_cur_base_mode_condition_game_camera_param_manager(a + 80, b, c, d);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_cur_using_camera_mode_manager_param_game_camera);

extern int get_cur_base_mode_manager_game_camera_param_manager();

int get_cur_using_camera_mode_manager_param_game_camera(int a, int b, int c, int d)
{
    return get_cur_base_mode_manager_game_camera_param_manager(a + 80, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0188_func_400F2F40", get_snipe_position_decide_parameter_game_camera);
