#include "common.h"

extern s32 D_401322BC;
extern s32 D_401322C4;
extern s32 D_401322C8;

s32 GAMEUTIL_is_push_or_down_1p_button(s32 port, s32 button);
u8* get_game_camera(void);
s32 get_fixed_point_type_camera_lws_animation(u8* work);
s32 get_boss_subjective_camera_lws_animation_param(void);
void end_camera_lws_animation_by_paramID(s32 paramID);
s32 InitCollisionFinder(u8* a0, u8* a1, s32 size);
void reset_camera_collision_data_except_slide_move_ratio(u8* work);
void constructor_nico_yaw_pitch_cntrl(u8* work);
void func_400F1DD0(void);
s32 func_400F2290(u8* a0, s32 a1, s32 a2, s32 a3);

void begin_check_and_boot_boss_subjective_camera_lws_animation(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", end_check_and_boot_boss_subjective_camera_lws_animation);
void end_check_and_boot_boss_subjective_camera_lws_animation(void)
{
    s32 param = get_boss_subjective_camera_lws_animation_param();

    if (param != 0)
    {
        end_camera_lws_animation_by_paramID(param);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", begin_stream_lws_movie_playing_game_camera);
void begin_stream_lws_movie_playing_game_camera(u8* work)
{
    *(s32*)(work + 0x3654) = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", end_stream_lws_movie_playing_game_camera);
void end_stream_lws_movie_playing_game_camera(u8* work)
{
    *(s32*)(work + 0x3654) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", compel_end_lws_movie_mode_game_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", get_boss_interest_position_game_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", get_object_interest_position_game_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_boss_interest_mode_game_camera);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_mode_change_game_camera);
s32 is_mode_change_game_camera(void)
{
    u8* camera = get_game_camera();

    return *(s32*)(camera + 0x13C0) != *(s32*)(camera + 0x13C4);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_view_angle_zoom_game_camera);
s32 is_view_angle_zoom_game_camera(void)
{
    return GAMEUTIL_is_push_or_down_1p_button(0, D_401322C8) == 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_view_angle_exist_lws_anime_mode_base);
s32 is_view_angle_exist_lws_anime_mode_base(u8* work)
{
    return *(f32*)(work + 0x224) > 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", get_view_angle_lws_anime_mode_base);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", add_camera_mode_common_param_segment);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", add_camera_mode_manager_segment);

void free_camera_mode_manager_segment(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", get_boss_subjective_camera_lws_animation_param);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", getBossInterestKey);
s32 getBossInterestKey(void)
{
    return D_401322BC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", getInterestKey);
s32 getInterestKey(void)
{
    return D_401322C4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", getZoomKey);
s32 getZoomKey(void)
{
    return D_401322C8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", setBossInterestKey);
void setBossInterestKey(s32 key)
{
    D_401322BC = key;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", setInterestKey);
void setInterestKey(s32 key)
{
    D_401322C4 = key;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", setZoomKey);
void setZoomKey(s32 key)
{
    D_401322C8 = key;
}

/* NEARMISS-STUB func_400F4028 */
#if 0 /* NEARMISS 45.0% cat=branch-layout sub=- | target sw in bnez delay slot then lw/beq; C puts sw before branch or beqzl | attempts=1 */
s32 func_400F4028(u8* work, s32 flag) {
    *(s32*)(work + 0x90) = flag;
    if (flag != 0) return 1;
    if (*(s32*)(work + 0x8C) == 4) return 0;
    return 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4028);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_lws_fixed_point_mode);
s32 is_lws_fixed_point_mode(u8* work)
{
    s32 type = get_fixed_point_type_camera_lws_animation(work);

    return func_400F4028(work, type);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", is_lws_movie_mode_game_camera);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F40C0);
s32 func_400F40C0(void)
{
    return GAMEUTIL_is_push_or_down_1p_button(0, D_401322BC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F40E0);
s32 func_400F40E0(u8* work)
{
    return *(f32*)(work + 0x18A0) > 0.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4100);
void func_400F4100(u8* work)
{
    *(s32*)work = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4108);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4160);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F41D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4270);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4310);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F43C0);
void func_400F43C0(u8* work)
{
    *(s32*)work = 0;
    constructor_nico_yaw_pitch_cntrl(work + 4);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F43E0);
void func_400F43E0(void)
{
    func_400F1DD0();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F43F8);
void func_400F43F8(void)
{
    func_400F1DD0();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4410);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4450);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4488);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F44C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4508);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4578);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4608);
s32 func_400F4608(u8* a0, s32 a1, s32 a2)
{
    return func_400F2290(a0, a1, a2, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4620);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4670);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F46D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F47C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F48C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4938);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4A50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4B68);

void func_400F4BA0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4BA8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4BF0);
void func_400F4BF0(u8* a0, u8* a1)
{
    *(s32*)(a1 + 0x94) = 0;
    *(s32*)(a1 + 0x98) = 0;
}

void func_400F4C00(void) {
}

void func_400F4C08(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4C10);

void func_400F4CB8(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4CC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4D68);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4E10);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4EC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4F30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4FA8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5048);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5160);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5268);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F52B0);

/* NEARMISS-STUB func_400F52F8 */
#if 0 /* NEARMISS 0.0% cat=no-c-form sub=- | needs break 0 (no builtin trap in gcc2.96) | attempts=1 */
void func_400F52F8(void) { /* needs break 0 on v0==0 path: no C form */ }
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F52F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5320);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5358);
void func_400F5358(u8* work)
{
    *(s32*)(work + 0x1940) = 0;
    *(s32*)(work + 0x1944) = 0;
    *(s32*)(work + 0x1948) = 0;
    reset_camera_collision_data_except_slide_move_ratio(work + 0x1830);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5380);
