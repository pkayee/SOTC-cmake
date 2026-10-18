#include "common.h"

void constructor_double_spring_interp_cntrl3D(char *, float, float);
void set_param_double_spring_interp_common(char *, float, float, float, float);

void constructor_camera_final_update(char *c)
{
    *(int *)c = -1;
    c += 0x10;
    constructor_double_spring_interp_cntrl3D(c, 0.0001f, 0.0f);
    set_param_double_spring_interp_common(c, 6.0f, -1.0f, 3.0f, -1.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", func_400E0918);

extern char D_402184E8[];
extern void *memset(void *, int, unsigned int);

void reset_camera_vs_ofst_cntrl_param_segment_array(void)
{
    memset(D_402184E8, 0, 0x28);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", get_nearest_camera_vs_ofst_cntrl_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", disp_camera_vs_ofst_cntrl_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", add_camera_vs_ofst_cntrl_param_segment);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", free_camera_vs_ofst_cntrl_param_segment);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", doit_camera_pause_rise);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", func_400E10A0);

extern s128 ZeroPoint, ZeroVector;

void constructor_camera_pause_rise(char *work)
{
    *(int *)work = 0;
    *(int *)(work + 4) = 0;
    *(s128 *)(work + 0x10) = ZeroPoint;
    *(s128 *)(work + 0x20) = ZeroPoint;
    *(s128 *)(work + 0x30) = ZeroVector;
    *(float *)(work + 0x44) = 4.5f;
    *(float *)(work + 0x40) = 4.5f;
    *(float *)(work + 0x48) = 45.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", init_camera_pause_rise);

void request_end_camera_pause_rise(char *work)
{
    *(int *)(work + 4) = 0;
    *(int *)work = 2;
}

int is_end_camera_pause_rise(int *arg0)
{
    return *arg0 == 0;
}

extern const f32 D_40137188;

float get_begin_interp_finish_time_camera_pause_rise(void)
{
    return D_40137188;
}

extern const f32 D_401371C8;

float get_end_interp_finish_time_camera_pause_rise(void)
{
    return D_401371C8;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", func_400E12F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0171_constructor_camera_final_update", func_400E1498);
