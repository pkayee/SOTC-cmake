#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", player_collision_check_direct);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", is_hit_cam_opt_leave_collision_attribute);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", create_camera_collisionDB);

float get_camera_collision_data_base_filter_radius(float r, float a, float b)
{
    if (a < b)
        a = b;
    a += 0.1f;
    if (r < a)
        r = a;
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", camera_collision_check_with_keep);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", check_camera_position_float_by_collision);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", get_camera_position_float_by_hit_collision);

extern int reset_camera_collision_data_except_slide_move_ratio();

void constructor_camera_collision_data(void *arg0)
{
    reset_camera_collision_data_except_slide_move_ratio();
    (*(float *)((char *)(arg0) + 0x40)) = -1.0f;
    (*(float *)((char *)(arg0) + 0x44)) = 1.0f;
}

extern int ConstructorCollisionDynamics();

int reset_camera_collision_data_except_slide_move_ratio(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return ConstructorCollisionDynamics(p + 4);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE1E0);

extern int GAMEUTIL_is_horse_obj();
extern int CollisionObjectJudgeCallbackExceptPluralObj();

int func_400DE1E0(int arg0, int arg1)
{
    int temp_v0;
    int var_v0;

    temp_v0 = GAMEUTIL_is_horse_obj();
    if ((temp_v0 != 1) || (var_v0 = CollisionObjectJudgeCallbackExceptPluralObj(arg0, arg1), (var_v0 != temp_v0))) {
        var_v0 = 0;
    }
    return var_v0;
}

u8 *GetCharacterClass(void *chara);

s32 func_400DE240(void *actor)
{
    return GetCharacterClass(actor) == 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE240);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE260);

extern int GAMEUTIL_is_boss_obj(void *obj, int flag);

float func_400DE260(void *arg0, float *arg1)
{
    float f20;
    float f21;

    f20 = arg1[1];
    f21 = arg1[0];
    if (GAMEUTIL_is_boss_obj(arg0, 1) == 1)
    {
        return f20;
    }
    else
    {
        return f21;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE2A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE438);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE588);

float func_400DE588(float *arg0, float *arg1, s32 arg2)
{
    float temp_f0;

    temp_f0 = arg0[arg2] - arg1[arg2];
    return temp_f0 * temp_f0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE5A8);

float func_400DE5A8(float *arg0, float *arg1, float *arg2, s32 arg3)
{
    float temp_f0;
    float temp_f1;

    temp_f0 = arg0[arg3] - arg1[arg3];
    temp_f1 = arg1[arg3] - arg2[arg3];
    temp_f0 = temp_f0 + temp_f0;
    return temp_f0 * temp_f1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE5D8);

float func_400DE5D8(float *arg0, float *arg1, s32 arg2)
{
    float temp_f0;

    temp_f0 = arg0[arg2] - arg1[arg2];
    return temp_f0 * temp_f0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0168_player_collision_check_direct", func_400DE5F8);

s32 func_400DE5F8(float arg0)
{
    if (0.0f <= arg0 && arg0 < 1.0f)
    {
        return 1;
    }
    return 0;
}
