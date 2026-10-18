#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400EC878);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400ECCA8);

extern void GAMEUTIL_get_yaw_pitch_by_direction(void *, void *, int);
extern unsigned char D_40132220[];
extern unsigned char D_40132224[];

void update_debug_camera_yaw_pitch(int arg0)
{
    GAMEUTIL_get_yaw_pitch_by_direction(D_40132220, D_40132224, arg0);
}

extern float D_401322A0;

float get_debug_camera_view_angle(void)
{
    return D_401322A0;
}

void *get_debug_camera_view_angle_pointer(void)
{
    return &D_401322A0;
}

extern int D_401322A4;

int is_disp_game_camera_model_ok(void)
{
    return D_401322A4;
}

void *is_disp_game_camera_model_ok_pointer(void)
{
    return &D_401322A4;
}

extern unsigned char D_401322A8[];

void *get_debug_camera_dist_to_look_at_pointer(void)
{
    return D_401322A8;
}

extern float D_40132228;
extern float D_4013222C;

void set_debug_camera_move_diff(float fparg0, float fparg1)
{
    D_40132228 = fparg0;
    D_4013222C = fparg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", check_and_boot_boss_subjective_camera_lws_animation);

extern void constructor_camera_etc_condition(void *);
extern void constructor_game_camera_param_manager(void *);
extern void func_400EE648(void *, void *);
extern void func_400F4100(void *);
extern void func_400F4108(void *, int);
extern void func_400F4160(void *);
extern void func_400F41D8(void *);
extern void func_400F4270(void *);
extern void func_400F4310(void *, int);
extern void func_400F43C0(void *);
extern void func_400F43E0(void *);
extern void func_400F43F8(void *);
extern void constructor_camera_pause_rise(void *);
extern void *get_interp_game_camera_param_game_camera_param_manager(void *);
extern void func_400F4410(void *, void *);

void constructor_game_camera(char *g, void *arg)
{
    *(int *)(g + 0x0) = 0;
    *(int *)(g + 0x4) = 0;
    constructor_camera_etc_condition(g + 0x10);
    constructor_game_camera_param_manager(g + 0x50);
    *(int *)(g + 0x13C0) = -1;
    *(int *)(g + 0x13C4) = -1;
    func_400EE648(g + 0x13D0, arg);
    func_400F4100(g + 0x2D20);
    func_400F4108(g + 0x2D24, 1);
    func_400F4160(g + 0x2E00);
    func_400F41D8(g + 0x2EC0);
    func_400F4270(g + 0x2FB0);
    func_400F4310(g + 0x30D0, 1);
    func_400F43C0(g + 0x3200);
    func_400F43E0(g + 0x3350);
    func_400F43F8(g + 0x35C0);
    constructor_camera_pause_rise(g + 0x3830);
    func_400F4410(g, get_interp_game_camera_param_game_camera_param_manager(g + 0x50));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400ED1B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400ED430);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400ED778);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400ED9E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400EDC40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0184_func_400EC878", func_400EDF18);
