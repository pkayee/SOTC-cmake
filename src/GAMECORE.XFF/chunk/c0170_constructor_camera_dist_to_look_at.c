#include "common.h"

extern s128 ZeroPoint, ZUnitVector;
extern void constructor_double_spring_interp_cntrl(void *, float);
extern void reset_double_spring_interp_cntrl(void *, float);
extern void reset_time_interp_param_camera_dist_to_look_at(char *);

void constructor_camera_dist_to_look_at(char *c)
{
    char *p0;

    constructor_double_spring_interp_cntrl(c, 0.001f);
    reset_double_spring_interp_cntrl(c, 4.5f);
    *(float *)(c + 0x20) = 4.5f;
    p0 = c + 0x30;
    *(int *)(p0 + 0x0) = 0;
    *(float *)(p0 + 0x8) = 1.0f;
    *(int *)(p0 + 0x4) = 0;
    *(s128 *)(p0 + 0x10) = ZeroPoint;
    *(s128 *)(p0 + 0x20) = ZUnitVector;
    *(int *)(p0 + 0x30) = 0;
    reset_time_interp_param_camera_dist_to_look_at(c);
    *(int *)(c + 0x7C) = 0;
}

extern int GAMEUTIL_is_diff_nearly_equal_zero(float, float, float);
extern int is_leave_camera_dist_to_look_at(void **);
extern void set_param_double_spring_interp_common(char *, float, float, float, float);
extern void CAM_get_camera_position_by_look_at(void *, void *, void *, float);
extern void func_400DF850(void *, void **, int, int, float);
extern void doit_double_spring_interp_cntrl(signed char *, int, float, float);
extern float func_400DFEE8(signed char *, void **, int, float);
extern int is_reset_or_lws_movie_or_cutout_game_camera(int);

void doit_camera_dist_to_look_at(signed char *arg0, void **arg1, int arg2, int arg3, float fparg0)
{
    float temp_f0;
    void *temp_s3;
    void *temp_v0;

    temp_s3 = (char *)arg1 + 0xA0;
    (*(float *)((char *)(arg0) + 0x1C)) = (float)(*(float *)((char *)(temp_s3) + 0x38));
    (*(float *)((char *)(arg0) + 0x20)) = func_400DFEE8(arg0, arg1, arg2, fparg0);
    func_400DF850(arg0 + 0x30, arg1, arg2, arg3, fparg0);
    if (is_leave_camera_dist_to_look_at(arg1) == 1)
    {
        (*(float *)((char *)(arg0) + 0x20)) = (*(float *)((char *)(temp_s3) + 0x38));
    }
    else if ((*(int *)((char *)(arg0) + 0x30)) == 2)
    {
        (*(float *)((char *)(arg0) + 0x20)) = 0.1f;
    }
    temp_v0 = *arg1;
    set_param_double_spring_interp_common(arg0, (*(float *)((char *)(temp_v0) + 0x164)), (*(float *)((char *)(temp_v0) + 0x16C)), (*(float *)((char *)(temp_v0) + 0x168)), -1.0f);
    doit_double_spring_interp_cntrl(arg0, is_reset_or_lws_movie_or_cutout_game_camera(arg2), (*(float *)((char *)(arg0) + 0x20)), fparg0);
    if (GAMEUTIL_is_diff_nearly_equal_zero((*(float *)((char *)(temp_s3) + 0x38)), (*(float *)((char *)(arg0) + 0x1C)), 0.001f) == 0)
    {
        temp_f0 = (*(float *)((char *)(arg0) + 0x1C));
        (*(float *)((char *)(temp_s3) + 0x38)) = temp_f0;
        CAM_get_camera_position_by_look_at(temp_s3, temp_s3 + 0x20, temp_s3 + 0x10, temp_f0);
    }
}

void reset_time_interp_param_camera_dist_to_look_at(char *pa0)
{
    *(float *)(pa0 + 0x78) = 1.0f;
    *(int *)(pa0 + 0x74) = 0;
    *(int *)(pa0 + 0x70) = 0;
}

void begin_time_interp_camera_dist_to_look_at(void *arg0, float fparg0, float fparg1)
{
    (*(float *)((char *)(arg0) + 0x78)) = fparg1;
    (*(float *)((char *)(arg0) + 0x70)) = fparg0;
    (*(int *)((char *)(arg0) + 0x74)) = 0;
}

void set_stretch_phase_ratio_camera_dist_to_look_at(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x7C)) = fparg0;
}

float get_stretch_phase_ratio_camera_dist_to_look_at(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x7C));
}

int is_acting_rewind_camera_dist_to_look_at(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x30)) == 2;
}

float get_rewind_begin_dist_to_target_camera_dist_to_look_at(void *arg0, float fparg0)
{
    float var_f0;

    var_f0 = fparg0;
    if (((*(int *)((char *)(arg0) + 0x30)) ^ 2) == 0)
    {
        var_f0 = (*(float *)((char *)(arg0) + 0x38));
    }
    return var_f0;
}

void end_rewind_camera_dist_to_look_at(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x30)) = 0;
}

int is_leave_camera_dist_to_look_at(void **arg0)
{
    return (*(int *)((char *)(*arg0) + 0x160)) == 2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400DFC90);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400DFDC8);

/* NEARMISS-STUB func_400DFEC8 */
#if 0 /* NEARMISS 27.7% cat=regalloc sub=- | target adds 0x60 to a1 (addiu) and loads 0x10 into v0 first; compiler folds offsets and picks v1 | attempts=1 */
void func_400DFEC8(char *arg0, char *arg1)
{
    *(s128 *)(arg0 + 0x10) = *(s128 *)(arg1 + 0x70);
    *(s128 *)(arg0 + 0x20) = *(s128 *)(arg1 + 0x80);
    *(int *)(arg0 + 0x30) = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400DFEC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400DFEE8);

extern void func_400E0210();

void constructor_camera_etc_condition(void *arg0)
{
    func_400E0210();
    (*(int *)((char *)(arg0) + 8)) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", doit_camera_etc_condition);

extern int opflowAdvertiseDemoStat;
extern int GAMEUTIL_is_boss_booting(void);

typedef struct {
    int a;
    int b;
    int c;
    int d;
    int e;
} CameraEtcFlags;

int is_pass_camera_etc_condition(unsigned int cond, CameraEtcFlags *f)
{
    int r = 0;

    switch (cond) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = f->a;
        break;
    case 3:
        r = f->b;
        break;
    case 4:
        r = GAMEUTIL_is_boss_booting();
        break;
    case 5:
        r = f->c;
        break;
    case 6:
        r = f->d;
        break;
    case 7:
        r = f->d == 0;
        break;
    case 8:
        if (opflowAdvertiseDemoStat == 1)
            r = 1;
        break;
    case 9:
        if (opflowAdvertiseDemoStat == 2)
            r = 1;
        break;
    case 10:
        r = f->e;
        break;
    case 11:
        r = f->e == 0;
        break;
    }
    return r;
}

extern char *get_game_camera();

void set_post_boss_dead_playable_flag_camera_etc_condition(int a, int b)
{
    *(int *)(get_game_camera(a) + 0x18) = b;
}

void func_400E0210(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x10) = 0;
    *(s128 *)(p + 0x20) = ZeroPoint;
    *(int *)(p + 0x30) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400E0238);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", doit_camera_final_update);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0170_constructor_camera_dist_to_look_at", func_400E05F0);
