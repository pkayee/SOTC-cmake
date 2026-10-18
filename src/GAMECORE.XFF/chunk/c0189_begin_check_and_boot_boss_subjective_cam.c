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
void CAM_destructor_target(u8* a0);
void CAM_init_camera_warp_cntrl(u8* a0, s32 a1, s32 a2, s32 a3);
void ReleaseCollisionFinder(u8* a0);
u8* GAMEUTIL_get_boss_obj(void);
u8* GetLayoutClass(void* chara);
u8* GetScriptCharacterClass(void* chara);

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

s32 get_boss_interest_position_game_camera(u128* out, u8* work)
{
    if (*(s32*)(work + 0x13C0) == 4 && *(s32*)(work + 0x2FC0) == 1)
    {
        *out = *(u128*)(work + 0x3010);
        return 1;
    }
    return 0;
}

s32 get_object_interest_position_game_camera(u128* out, u8* work)
{
    if (*(s32*)(work + 0x13C0) == 5 && *(s32*)(work + 0x30E0) == 1)
    {
        *out = *(u128*)(work + 0x3130);
        return 1;
    }
    return 0;
}

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

f32 get_view_angle_lws_anime_mode_base(u8* work)
{
    s32 exist = *(f32*)(work + 0x224) > 0.0f;

    if (exist == 1)
    {
        return *(f32*)(work + 0x254);
    }
    return -1.0f;
}

void add_camera_mode_common_param_segment(u8* work)
{
    if (work != NULL)
    {
        s32 count = *(s32*)(work + 0xC);
        u8* base = *(u8**)(work + 0x10);

        if (count > 0)
        {
            u8* p = base;
            s32 n = count;

            do
            {
                n--;
                *(u8**)(p + 0x14) = p + 0x10;
                *(u8**)(p + 0xAC) = p + 0xA8;
                *(u8**)(p + 0xB8) = p + 0xB4;
                p += 0x1B4;
            } while (n != 0);
        }
    }
}

void add_camera_mode_manager_segment(u8* work)
{
    if (work != NULL)
    {
        s32 count = *(s32*)(work + 0xC);
        u8* base = *(u8**)(work + 0x10);

        if (count > 0)
        {
            u8* p = base;
            s32 n = count;

            do
            {
                n--;
                *(u8**)(p + 0x14) = p + 0x10;
                *(u8**)(p + 0x1C) = p + 0x18;
                *(u8**)(p + 0x24) = p + 0x20;
                *(u8**)(p + 0x2C) = p + 0x28;
                *(u8**)(p + 0x34) = p + 0x30;
                *(u8**)(p + 0x3C) = p + 0x38;
                *(u8**)(p + 0x44) = p + 0x40;
                p += 0x48;
            } while (n != 0);
        }
    }
}

void free_camera_mode_manager_segment(void) {
}

s32 get_boss_subjective_camera_lws_animation_param(void)
{
    u8* boss = GAMEUTIL_get_boss_obj();

    if (boss != NULL)
    {
        return *(s32*)(GetScriptCharacterClass(boss) + 0x1144);
    }
    return 0;
}

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

u8* get_camera_obj(s32 a0);
u8* get_camera_position(void* a0);
s32 get_main_type_camera_lws_animation(u8* work);

s32 is_lws_movie_mode_game_camera(u8* work, s32 a1)
{
    s32 type = get_main_type_camera_lws_animation(get_camera_position(get_camera_obj(a1)));

    return func_400F4028(work, type);
}

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

void CAM_init_aim_angle_rot(u8* a0, s32 a1);

void func_400F4108(u8* work, s32 flag)
{
    if (flag == 1)
    {
        *(s32*)work = 0;
    }
    CAM_init_aim_angle_rot(work + 0x4, 0);
    CAM_init_aim_angle_rot(work + 0x48, 1);
    CAM_init_aim_angle_rot(work + 0x8C, 1);
    *(s32*)(work + 0xD0) = 0;
}

extern u128 ZUnitVector;

/* NEARMISS-STUB func_400F4160 */
#if 0 /* NEARMISS 99.9% cat=regalloc sub=- | only mismatch: target stores 0xB0 float, then sq 0xA0, then 0xB4 float; ours schedules both float stores after the sq (store order); reordering the stores gives | attempts=1 */
extern u128 ZUnitVector;

void func_400F4160(u8* work)
{
    u8* aim = work + 0x4;
    f32 zf;

    *(s32*)work = 0;
    CAM_init_aim_angle_rot(aim, 0);
    CAM_init_aim_angle_rot(work + 0x48, 1);
    *(s32*)(aim + 0x88) = 0;
    *(s32*)(aim + 0x8C) = 0;
    *(s32*)(work + 0x94) = 0;
    *(s32*)(work + 0x98) = 0;
    zf = 0.0f;
    *(u128*)(work + 0xA0) = ZUnitVector;
    *(f32*)(work + 0xB0) = zf;
    *(f32*)(work + 0xB4) = zf;
}
#endif
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

void func_400F4410(u8* work, s32 a1)
{
    *(s32*)(work + 0x13D0) = a1 + 0x4C;
    *(s32*)(work + 0x2D24) = a1 + 0x200;
    *(s32*)(work + 0x2E00) = a1 + 0x2CC;
    *(s32*)(work + 0x2EC0) = a1 + 0x350;
    *(s32*)(work + 0x2FB0) = a1 + 0x420;
    *(s32*)(work + 0x30D0) = a1 + 0x504;
    *(s32*)(work + 0x3200) = a1 + 0x5E8;
}

void func_400F4450(u8* work)
{
    CAM_destructor_target(work + 0x240);
    ReleaseCollisionFinder(work + 0x1880);
    ReleaseCollisionFinder(work + 0x1890);
}

u8* get_cur_camera_target(void);
u8* GetCharacterClass(void* chara);
s32 is_camera_target_change(s32 a0);

/* NEARMISS-STUB func_400F4488 */
#if 0 /* NEARMISS 92.67% cat=regalloc sub=- | target keeps result in v1 then copies to v0 at shared exit; C variants give v0 directly (early-return and shared-exit both 92.67) | attempts=1 */
u8* get_cur_camera_target(void);
u8* GetCharacterClass(void* chara);

s32 func_400F4488(void)
{
    u8* target = get_cur_camera_target();
    s32 result = 0;

    if (target != NULL)
    {
        u8* cc = GetCharacterClass(target);

        result = 1;
        if (cc != NULL)
        {
            return result;
        }
        result = 0;
    }
    return result;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4488);

void func_400F44C8(u8* work, s32 a1)
{
    if (is_camera_target_change(a1) == 1)
    {
        *(s32*)(work + 0x2D20) = 5;
    }
}

/* NEARMISS-STUB func_400F4508 */
#if 0 /* NEARMISS 75.4% cat=branch-layout sub=- | target keeps work+0x14C0 in s0 across calls and computes work+0x240 in the beqz delay slot before the type test (a2 flag polarity); early-return form gives addi | attempts=1 */
void GAMEUTIL_constructor_col_plane_info(u8* a0);
void* CAM_get_ground_contact_obj(u8* a0);
void GAMEUTIL_set_col_plane_info(u8* a0, void* a1);

void func_400F4508(u8* work, u8* cam)
{
    u8* col = work + 0x14C0;
    s32 type = *(s32*)(cam + 0x13C0);

    if (type == 0 || type == 8)
    {
        GAMEUTIL_constructor_col_plane_info(col);
        return;
    }
    GAMEUTIL_set_col_plane_info(col, CAM_get_ground_contact_obj(work + 0x240));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4508);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4578);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4608);
s32 func_400F4608(u8* a0, s32 a1, s32 a2)
{
    return func_400F2290(a0, a1, a2, 0);
}

s32 is_main_type_camera_lws_animation_update(void);

s32 func_400F4620(u8* a0, s32 a1, s32 a2)
{
    s32 v = is_main_type_camera_lws_animation_update();

    return func_400F2290(a0, a1, a2, v);
}

/* NEARMISS-STUB func_400F4670 */
#if 0 /* NEARMISS 92.3% cat=branch-layout sub=- | return-1 block falls through in target (beqz to RET1 at fallthrough); ours places return-0 as fallthrough with bnez to RET1; separate early returns/nested-if/mo | attempts=1 */
s32 func_400F4670(u8* work)
{
    s32 type = *(s32*)(work + 0x13C0);
    u8* p = work + 0x3350;

    if (type != 7)
    {
        p = NULL;
        if (type == 8)
        {
            p = work + 0x35C0;
        }
    }
    if (type != 0 && (p == NULL || ((*(s32*)(p + 0x8C) != 0 && *(s32*)(p + 0x8C) != 2) && *(s32*)(p + 0x98) == 0)))
    {
        return 0;
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4670);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F46D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F47C0);

/* NEARMISS-STUB func_400F48C8 */
#if 0 /* NEARMISS 84.4% cat=regalloc sub=- | target saves a0 in s2 and work+0x140 in s1; ours swaps them (saved-register assignment); local-variable reorderings give the same 84.4 | attempts=1 */
void CAM_get_camera_space_axisXY(f32 f, s32 zero, f32* out, u8* vec);
f32 get_view_angle_camera_view_angle_cntrl(u8* a0);
void set_camera_parameter_cameraman(f32 f, u8* a0, u8* a1, u8* a2, f32* a3);

void func_400F48C8(u8* a0, u8* work)
{
    f32 axis[4];
    f32 angle;

    CAM_get_camera_space_axisXY(*(f32*)(work + 0x1C4), 0, axis, work + 0x140);
    angle = get_view_angle_camera_view_angle_cntrl(work + 0x1C8);
    set_camera_parameter_cameraman(angle, a0, work + 0x120, work + 0x140, axis);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F48C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4938);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4A50);

s32 func_400F4B68(u8* work)
{
    if (work != NULL)
    {
        return *(s32*)(GetLayoutClass(work) + 0x1AC);
    }
    return 1000000;
}

void func_400F4BA0(void) {
}

void CAM_init_aim_angle_rot(u8* a0, s32 a1);

void func_400F4BA8(u8* a0, u8* work)
{
    CAM_init_aim_angle_rot(work + 0x4, 0);
    CAM_init_aim_angle_rot(work + 0x48, 1);
    CAM_init_aim_angle_rot(work + 0x8C, 1);
    *(s32*)(work + 0xD0) = 0;
}

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

void CAM_init_aim_angle_rot(u8* a0, s32 a1);
void reset_pitch_rot_cntrl_camera_target_approach(u8* a0);

void func_400F4EC0(u8* a0, u8* a1)
{
    CAM_init_aim_angle_rot(a1 + 0x4, 0);
    CAM_init_aim_angle_rot(a1 + 0x48, 1);
    CAM_init_aim_angle_rot(a1 + 0x8C, 1);
    *(s32*)(a1 + 0xD0) = 0;
    CAM_init_camera_warp_cntrl(a0 + 0x18C0, 2, 3, 1);
    reset_pitch_rot_cntrl_camera_target_approach(a0 + 0x710);
}

void func_400F4F30(u8* a0, u8* a1)
{
    u8* aim = a1 + 0x4;

    CAM_init_aim_angle_rot(aim, 0);
    CAM_init_aim_angle_rot(a1 + 0x48, 1);
    *(s32*)(aim + 0x88) = 0;
    *(s32*)(aim + 0x8C) = 0;
    CAM_init_camera_warp_cntrl(a0 + 0x18C0, 2, 3, 0);
    *(s32*)(a1 + 0x94) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F4FA8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5048);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5160);

void func_400F1F90(u8* a0, u8* a1);

void func_400F5268(u8* a0, u8* a1)
{
    *(s32*)(a1 + 0x80) = 0;
    *(s32*)(a1 + 0x260) = 0;
    func_400F1F90(a1, a0);
    CAM_init_camera_warp_cntrl(a0 + 0x18C0, 0, 0, 0);
}

void func_400F52B0(u8* a0, u8* a1)
{
    *(s32*)(a1 + 0x80) = 0;
    *(s32*)(a1 + 0x260) = 0;
    func_400F1F90(a1, a0);
    CAM_init_camera_warp_cntrl(a0 + 0x18C0, 0, 0, 0);
}

/* NEARMISS-STUB func_400F52F8 */
#if 0 /* NEARMISS 0.0% cat=no-c-form sub=- | needs break 0 (no builtin trap in gcc2.96) | attempts=1 */
void func_400F52F8(void) { /* needs break 0 on v0==0 path: no C form */ }
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F52F8);

void func_400F5320(u8* work)
{
    *(s32*)(work + 0x18A8) = 0;
    *(s32*)(work + 0x18AC) = 0;
    *(s32*)(work + 0x18B0) = 0;
    CAM_init_camera_warp_cntrl(work + 0x18C0, 0, 0, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5358);
void func_400F5358(u8* work)
{
    *(s32*)(work + 0x1940) = 0;
    *(s32*)(work + 0x1944) = 0;
    *(s32*)(work + 0x1948) = 0;
    reset_camera_collision_data_except_slide_move_ratio(work + 0x1830);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0189_begin_check_and_boot_boss_subjective_cam", func_400F5380);
