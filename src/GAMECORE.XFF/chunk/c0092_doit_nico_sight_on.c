#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0092_doit_nico_sight_on", doit_nico_sight_on);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0092_doit_nico_sight_on", func_4007F4E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0092_doit_nico_sight_on", func_4007F860);

/* NEARMISS-STUB get_object_local_merge_yaw_nico_sight_on */
#if 0 /* NEARMISS 92.0% cat=cse-hoist sub=- | zero-stores for yaw/pitch emitted before the lw of p+4; target loads first and fills jal delay slot with yaw store | attempts=1 */
extern void GAMEUTIL_get_local_directionZ(float *, int);
extern void GAMEUTIL_get_yaw_pitch_by_direction(float *, float *, float *);
extern float GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(float, float);
extern float GAMEUTIL_increase_yaw(int, float, float);

void get_object_local_merge_yaw_nico_sight_on(char *p)
{
    float dir[4];
    float yaw = 0.0f;
    float pitch = 0.0f;
    float radi;

    GAMEUTIL_get_local_directionZ(dir, *(s32 *)(p + 4));
    GAMEUTIL_get_yaw_pitch_by_direction(&yaw, &pitch, dir);
    radi = GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(yaw, *(float *)(p + 0x280));
    GAMEUTIL_increase_yaw(0, radi, *(float *)(p + 0x248));
    return;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0092_doit_nico_sight_on", get_object_local_merge_yaw_nico_sight_on);

extern float GAMEUTIL_increase_yaw(int, float, float);
extern float GAMEUTIL_increase_pitch(int, int, float, float, float, float);
extern void GAMEUTIL_get_direction_by_yaw_pitch(void *, float, float);

void get_radiate_direction_nico_sight_on(void *out, char *p)
{
    float yaw = GAMEUTIL_increase_yaw(0, *(float *)(p + 0x280), *(float *)(p + 0x248));
    float pitch = GAMEUTIL_increase_pitch(0, 0, *(float *)(p + 0x284), 0.0f, 1.4835296f, -1.4835296f);

    GAMEUTIL_get_direction_by_yaw_pitch(out, yaw, pitch);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0092_doit_nico_sight_on", set_parameter_nico_sight_on);

extern void set_pitch_parameter_effective_ratio_nico_yaw_pitch_cntrl(void *, float);
extern void set_reverse_input_pitch_flag_nico_yaw_pitch_cntrl(void *, int);
extern void set_reverse_input_yaw_flag_nico_yaw_pitch_cntrl(void *, int);
extern void set_yaw_parameter_effective_ratio_nico_yaw_pitch_cntrl(void *, float);

void set_option_parameter_nico_sight_on(void *work, int yaw, int pitch, float ratio)
{
    void *control;

    control = (char *)work + 0xC;
    set_reverse_input_yaw_flag_nico_yaw_pitch_cntrl(control, yaw);
    set_reverse_input_pitch_flag_nico_yaw_pitch_cntrl(control, pitch);
    set_yaw_parameter_effective_ratio_nico_yaw_pitch_cntrl(control, ratio);
    set_pitch_parameter_effective_ratio_nico_yaw_pitch_cntrl(control, ratio);
}
