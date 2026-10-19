#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", begin_nico_sight_on);

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    u8 cntrl[4];
} NicoSight;

void end_nico_yaw_pitch_cntrl(u8 *w);

void end_nico_sight_on(NicoSight *s)
{
    s->a = 0;
    s->b = 0;
    s->c = 0;
    end_nico_yaw_pitch_cntrl(s->cntrl);
}

s32 is_doing_nico_sight_on(s32 *arg0)
{
    return *arg0 != 0;
}

float get_ofst_yaw_nico_sight_on(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x248));
}

float get_ofst_pitch_nico_sight_on(void)
{
    return 0.0f;
}

float get_base_yaw_nico_sight_on(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x280));
}

extern void GAMEUTIL_get_local_directionZ(float *, s32);
extern void GAMEUTIL_get_yaw_pitch_by_direction(float *, float *, float *);
extern float GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(float, float);

float get_object_local_base_yaw_nico_sight_on(char *p)
{
    union { s32 i; float f; } *u = (void *)(p + 4);
    s32 arg = u->i;
    float dir[4];
    float yaw = 0.0f;
    float pitch = 0.0f;

    GAMEUTIL_get_local_directionZ(dir, arg);
    GAMEUTIL_get_yaw_pitch_by_direction(&yaw, &pitch, dir);
    return GAMEUTIL_get_move_radi_from_yaw1_to_yaw2(yaw, *(float *)(p + 0x280));
}

float get_base_pitch_nico_sight_on(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x284));
}

float GAMEUTIL_increase_yaw(s32 kind, float value1, float value2);

float get_merge_yaw_nico_sight_on(void *arg0)
{
    return GAMEUTIL_increase_yaw(0, (*(float *)((char *)(arg0) + 0x280)), (*(float *)((char *)(arg0) + 0x248)));
}

float GAMEUTIL_increase_pitch(s32 kind, s32 kind2, float value1, float value2, float value3, float value4);

float get_merge_pitch_nico_sight_on(char *p)
{
    return GAMEUTIL_increase_pitch(0, 0, *(float *)(p + 0x284), 0.0f, 1.483529567718505859375f, -1.483529567718505859375f);
}

float get_hope_yaw_nico_sight_on(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x208));
}

float get_hope_pitch_nico_sight_on(void *arg0)
{
    return (*(float *)((char *)(arg0) + 0x204));
}

void get_snipe_position_nico_sight_on(char *dst, char *src)
{
    *(s128 *)(dst + 0x0) = *(s128 *)(src + 0x1C0);
}

typedef union {
    s128 q;
    float f[4];
    s32 i[4];
} Vec4;

s32 get_predict_hit_position_nico_sight_on(Vec4 *out, char *p)
{
    out->q = ((Vec4 *)(p + 0x1D0))->q;
    return ((Vec4 *)(p + 0x1D0))[1].i[0];
}

void GAMEUTIL_get_direction_by_yaw_pitch(s32 arg0, float arg1, float arg2);
float get_base_pitch_nico_yaw_pitch_cntrl(u8 *p);
float get_base_yaw_nico_yaw_pitch_cntrl(u8 *p);

void get_hope_camera_direction_nico_sight_on(s32 arg0, u8 *arg1)
{
    float temp_f20;
    u8 *temp_s0;

    temp_s0 = arg1 + 0xC;
    temp_f20 = get_base_yaw_nico_yaw_pitch_cntrl(temp_s0);
    GAMEUTIL_get_direction_by_yaw_pitch(arg0, temp_f20, get_base_pitch_nico_yaw_pitch_cntrl(temp_s0));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_400801B0);
extern void GAMEUTIL_get_local_directionZ(float *, s32);
extern void GAMEUTIL_get_yaw_pitch_by_direction(float *, float *, float *);

float func_400801B0(s32 arg)
{
    float dir[4];
    float yaw = 0.0f;
    float pitch = 0.0f;

    GAMEUTIL_get_local_directionZ(dir, arg);
    GAMEUTIL_get_yaw_pitch_by_direction(&yaw, &pitch, dir);
    return yaw;
}

extern void *GAMEUTIL_get_riding_horse_object(void *chara);
extern void GAMEUTIL_act_axis_rot_root_quaternion_abs(void *q, f32 ang, f32 *axis);
extern f32 YUnitVector[];

void func_400801F0(u8 *arg0, f32 arg1)
{
    void *obj;

    obj = GAMEUTIL_get_riding_horse_object(*(void **)(arg0 + 4));
    if (obj == 0)
    {
        obj = *(void **)(arg0 + 4);
    }
    GAMEUTIL_act_axis_rot_root_quaternion_abs(obj, arg1, YUnitVector);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_40080240);
extern s32 ScriptCtrlDef_SCRPlayerSightOnTurnLeft;
extern s32 ScriptCtrlDef_SCRHorseSightOnTurnLeft;
s32 func_400803C0(s32 a, s32 b, s32 c);

s32 func_40080240(s32 a)
{
    return func_400803C0(a, ScriptCtrlDef_SCRPlayerSightOnTurnLeft, ScriptCtrlDef_SCRHorseSightOnTurnLeft);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_40080268);
extern s32 ScriptCtrlDef_SCRPlayerSightOnTurnRight;
extern s32 ScriptCtrlDef_SCRHorseSightOnTurnRight;
s32 func_400803C0(s32 a, s32 b, s32 c);

s32 func_40080268(s32 a)
{
    return func_400803C0(a, ScriptCtrlDef_SCRPlayerSightOnTurnRight, ScriptCtrlDef_SCRHorseSightOnTurnRight);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_40080290);

extern s32 ScriptCtrlDef_SCRHorseSightOnTurnNone;
s32 func_400803C0(s32 a, s32 b, s32 c);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_400803A0);
s32 func_400803A0(s32 a)
{
    return func_400803C0(a, 0, ScriptCtrlDef_SCRHorseSightOnTurnNone);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_400803C0);
extern s32 GAMEUTIL_is_player_obj(s32 chr);
extern void *GAMEUTIL_get_riding_horse_object(void *chara);
extern s32 setHorseForceScriptKey(void *actor, s32 key);
extern s32 SCRRequestMotionDirect(s32 obj, s32 motion);

s32 func_400803C0(s32 a, s32 b, s32 c)
{
    s32 r;
    void *horse;

    r = GAMEUTIL_is_player_obj(*(s32 *)(a + 4));
    if (r != 1) {
        return r;
    }
    horse = GAMEUTIL_get_riding_horse_object(*(void **)(a + 4));
    if (horse != NULL) {
        return setHorseForceScriptKey(horse, c);
    }
    return SCRRequestMotionDirect(*(s32 *)(a + 4), b);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", nico_getOmakeItem);

extern s32 D_40131968;
void isysRequestDeleteObj(s32);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", nico_delOmakeItem);
void nico_delOmakeItem(void) {
    isysRequestDeleteObj(D_40131968);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", func_400806E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0093_begin_nico_sight_on", demo_op1);

extern u8 gcGlobalVar[];
s32 SCRGetFirstObj();
s32 nico_resetHorseRidingStatusForHorse(s32 obj);

s32 demo_op1_resetHorseBridle(void)
{
    return nico_resetHorseRidingStatusForHorse(SCRGetFirstObj((s32)(gcGlobalVar + 0x2B4)));
}

extern int *SkelFocusDef_PLAYER_HAND_A_L, *SkelFocusDef_PLAYER_HAND_A_R;
extern f32 D_40134220[], D_40134230[];
void nico_setHorseRidingStatusForHorseIndep(void *, void *, s32, f32 *, s32, f32 *);

void demo_op1_setHorseBridle(void)
{
    void *p = (void *)SCRGetFirstObj(gcGlobalVar + 0x2B4);
    nico_setHorseRidingStatusForHorseIndep(p, (void *)SCRGetFirstObj(gcGlobalVar + 0x2B0),SkelFocusDef_PLAYER_HAND_A_L[2], D_40134220, SkelFocusDef_PLAYER_HAND_A_R[2], D_40134230);
}
