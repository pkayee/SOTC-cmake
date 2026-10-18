#include "common.h"

extern s32 D_40130690;
extern s32 D_40130694;
extern s32 D_40130698;
extern s32 D_4013069C;
extern s32 D_401306A0;
extern s32 D_401306A4;
extern s32 All1Vector;
extern s32 DldSysUndefSymbol;
extern s32 padManagerData;
extern s32 gcGlobalVar;
u8* GetCharacterClass(s32 chr);
u32* isysGroupForFirst(s32 group, s32 flag);
void isysGroupForExit(s32 group, s32 flag);
void GAMEUTIL_get_1p_left_analog_input_extend(f32 *arg0, f32 *arg1, s32 arg2, f32 arg3);
u8 *GetLayoutClass(void *chara);
void *get_main_cameraman_camera_obj(void);
void *get_camera_position(void *arg0);
s32 GAMEUTIL_is_player_obj(s32 chr);
u8 *GetScriptCharacterClass(void *chara);
void iosPadGetXZInputR(f32 *arg0, void *arg1);
void iosPadGetXZInputLwithThreshold(f32 *arg0, void *arg1, f32 arg2);
void iosPadGetXZInputLwithThresholdIndepAxis(f32 *arg0, void *arg1, f32 arg2);
void GAMEUTIL_get_node_posi_by_id(u128 *arg0, void *arg1, s32 arg2);
extern s32 ControlMode_PLAYER_SWIM;
extern s32 ControlMode_PLAYER_SWIM_MOVE;
extern s32 ControlMode_PLAYER_SWIM_DASH;
void GetStageCenter(void *arg0, void *arg1);
f32 GAMEUTIL_get_dist_ratio(f32 value, f32 min, f32 max);
f32 GAMEUTIL_get_interp_value(f32 a, f32 b, f32 t);
s32 GAMEUTIL_is_horse_obj_contact_ground(s32 *arg0, s32 arg1);
s32 GAMEUTIL_get_horse_move_status(void *arg0, s32 arg1);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_doit_col_plane_info_filter);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", convert_from_button_value_to_bool);
s32 convert_from_button_value_to_bool(s32 value)
{
    return value != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", convert_from_slide_bar_value_to_ratio);
f32 convert_from_slide_bar_value_to_ratio(s32 value, f32 arg1, f32 arg2)
{
    f32 ratio;

    if (value == 8)
    {
        return 1.0f;
    }
    if (value < 8)
    {
        ratio = GAMEUTIL_get_dist_ratio((f32)value, 0.0f, 8.0f);
        return GAMEUTIL_get_interp_value(1.0f, arg1, ratio);
    }
    ratio = GAMEUTIL_get_dist_ratio((f32)value, 8.0f, 15.0f);
    return GAMEUTIL_get_interp_value(arg2, 1.0f, ratio);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_sight_on_reverse_cntrlLR);
void GAMEUTIL_set_sight_on_reverse_cntrlLR(s32 value)
{
    D_40130690 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_reverse_cntrlLR_int);
s32 GAMEUTIL_get_sight_on_reverse_cntrlLR_int(void)
{
    return D_40130690;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_reverse_cntrlLR_bool);
s32 GAMEUTIL_get_sight_on_reverse_cntrlLR_bool(void)
{
    return D_40130690 != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_sight_on_reverse_cntrlUD);
void GAMEUTIL_set_sight_on_reverse_cntrlUD(s32 value)
{
    D_40130694 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_reverse_cntrlUD_int);
s32 GAMEUTIL_get_sight_on_reverse_cntrlUD_int(void)
{
    return D_40130694;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_reverse_cntrlUD_bool);
s32 GAMEUTIL_get_sight_on_reverse_cntrlUD_bool(void)
{
    return D_40130694 != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_sight_on_angle_vel_ratio);
void GAMEUTIL_set_sight_on_angle_vel_ratio(s32 value)
{
    D_40130698 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_angle_vel_ratio_int);
s32 GAMEUTIL_get_sight_on_angle_vel_ratio_int(void)
{
    return D_40130698;
}

/* NEARMISS-STUB GAMEUTIL_get_sight_on_angle_vel_ratio_float */
#if 0 /* NEARMISS 81.5% cat=regalloc sub=- | same 1.0f temp issue | attempts=1 */
f32 GAMEUTIL_get_sight_on_angle_vel_ratio_float(void)
{
    s32 value;
    f32 ret;
    f32 ratio;

    ret = 1.0f;
    value = D_40130698;
    if (value != 8)
    {
        if (value < 8)
        {
            ratio = GAMEUTIL_get_dist_ratio((f32)value, 0.0f, 8.0f);
            ret = GAMEUTIL_get_interp_value(1.0f, 0.5f, ratio);
        }
        else
        {
            ratio = GAMEUTIL_get_dist_ratio((f32)value, 8.0f, 15.0f);
            ret = GAMEUTIL_get_interp_value(2.0f, 1.0f, ratio);
        }
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_sight_on_angle_vel_ratio_float);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_game_camera_free_mode_reverse_cntrlLR);
void GAMEUTIL_set_game_camera_free_mode_reverse_cntrlLR(s32 value)
{
    D_4013069C = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_reverse_cntrlLR_int);
s32 GAMEUTIL_get_game_camera_free_mode_reverse_cntrlLR_int(void)
{
    return D_4013069C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_reverse_cntrlLR_bool);
s32 GAMEUTIL_get_game_camera_free_mode_reverse_cntrlLR_bool(void)
{
    return D_4013069C != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_game_camera_free_mode_reverse_cntrlUD);
void GAMEUTIL_set_game_camera_free_mode_reverse_cntrlUD(s32 value)
{
    D_401306A0 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_reverse_cntrlUD_int);
s32 GAMEUTIL_get_game_camera_free_mode_reverse_cntrlUD_int(void)
{
    return D_401306A0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_reverse_cntrlUD_bool);
s32 GAMEUTIL_get_game_camera_free_mode_reverse_cntrlUD_bool(void)
{
    return D_401306A0 != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_set_game_camera_free_mode_angle_vel_ratio);
void GAMEUTIL_set_game_camera_free_mode_angle_vel_ratio(s32 value)
{
    D_401306A4 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_angle_vel_ratio_int);
s32 GAMEUTIL_get_game_camera_free_mode_angle_vel_ratio_int(void)
{
    return D_401306A4;
}

/* NEARMISS-STUB GAMEUTIL_get_game_camera_free_mode_angle_vel_ratio_float */
#if 0 /* NEARMISS 81.5% cat=regalloc sub=- | 1.0f temp held across call / tail calls | attempts=1 */
f32 GAMEUTIL_get_game_camera_free_mode_angle_vel_ratio_float(void)
{
    s32 value;
    f32 ret;
    f32 ratio;

    ret = 1.0f;
    value = D_401306A4;
    if (value != 8)
    {
        if (value < 8)
        {
            ratio = GAMEUTIL_get_dist_ratio((f32)value, 0.0f, 8.0f);
            ret = GAMEUTIL_get_interp_value(1.0f, 0.5f, ratio);
        }
        else
        {
            ratio = GAMEUTIL_get_dist_ratio((f32)value, 8.0f, 15.0f);
            ret = GAMEUTIL_get_interp_value(2.0f, 1.0f, ratio);
        }
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_game_camera_free_mode_angle_vel_ratio_float);

/* NEARMISS-STUB GAMEUTIL_get_first_obj */
#if 0 /* NEARMISS 93.7% cat=regalloc sub=- | s0 vs a0 reg choice around isysGroupForExit call | attempts=1 */
s32 GAMEUTIL_get_first_obj(s32 group)
{
    s32 obj;
    u32* p;

    obj = 0;
    p = isysGroupForFirst(group, 0);
    if (p != 0)
    {
        obj = *p;
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
    return obj;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_first_obj);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_camera_target_look_at_position);
void GAMEUTIL_get_camera_target_look_at_position(u128 *arg0, void *arg1)
{
    u8 *chara;
    u8 *layout;

    chara = GetScriptCharacterClass(arg1);
    if (chara != 0)
    {
        GAMEUTIL_get_node_posi_by_id(arg0, arg1, *(s32 *)(chara + 0x1140));
        return;
    }
    layout = GetLayoutClass(arg1);
    *arg0 = *(u128 *)*(u8 **)(layout + 0x134);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_obj_from_stagelayout_sheet);
s32 GAMEUTIL_get_obj_from_stagelayout_sheet(s32 *arg0)
{
    s32 word;
    s32 *p;
    u8 *r;

    word = *arg0;
    if ((word & 0x3FFFF) != 0)
    {
        p = *(s32 **)((u8 *)arg0 - (word & 0x3FFFF));
    }
    else
    {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol)
    {
        r = (u8 *)(p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3]);
    }
    else
    {
        r = 0;
    }
    return *(s32 *)(r + 0x48);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_object_scale);
void GAMEUTIL_get_object_scale(u128 *arg0, void *arg1)
{
    u8 *layout;

    if (arg1 != NULL)
    {
        layout = GetLayoutClass(arg1);
        if (layout != NULL)
        {
            *arg0 = *(u128 *)(layout + 0x90);
            return;
        }
    }
    *arg0 = *(u128 *)&All1Vector;
}

/* NEARMISS-STUB GAMEUTIL_is_push_or_down_1p_button */
#if 0 /* NEARMISS 54.12% cat=rodata-const sub=- | %hi(padManagerData+off) addend fold: expected lui %hi(sym+8)+lw %lo(sym+8); plus sllv/branch-tail shape differs | attempts=1 */
s32 GAMEUTIL_is_push_or_down_1p_button(s32 arg0, s32 arg1)
{
    if (arg0 == 1)
    {
        if ((((s32 *)&padManagerData)[2]) & (1 << arg1))
        {
            return 1;
        }
    }
    else if (arg0 == 2)
    {
        if ((((s32 *)&padManagerData)[3]) & (1 << arg1))
        {
            return 1;
        }
    }
    else if (arg0 == 3)
    {
        if ((((s32 *)&padManagerData)[4]) & (1 << arg1))
        {
            return 1;
        }
    }
    else
    {
        if (padManagerData & (1 << arg1))
        {
            return 1;
        }
        return 0;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_push_or_down_1p_button);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_1p_left_analog_input);
void GAMEUTIL_get_1p_left_analog_input(f32 *arg0, f32 *arg1)
{
    GAMEUTIL_get_1p_left_analog_input_extend(arg0, arg1, 1, 0.4f);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_1p_left_analog_input_extend);
void GAMEUTIL_get_1p_left_analog_input_extend(f32 *arg0, f32 *arg1, s32 arg2, f32 arg3)
{
    f32 out[4];

    if (arg2 == 1)
    {
        iosPadGetXZInputLwithThreshold(out, &padManagerData, arg3);
    }
    else
    {
        iosPadGetXZInputLwithThresholdIndepAxis(out, &padManagerData, arg3);
    }
    *arg0 = out[0];
    *arg1 = out[2];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_1p_right_analog_input);
void GAMEUTIL_get_1p_right_analog_input(f32 *arg0, f32 *arg1)
{
    f32 out[4];

    iosPadGetXZInputR(out, &padManagerData);
    *arg0 = out[0];
    *arg1 = out[2];
}

/* NEARMISS-STUB GAMEUTIL_is_overtake_aim_position */
#if 0 /* NEARMISS 10.9% cat=vu0-mmi sub=- | VU0 vsub/vmul/ACC dot | attempts=1 */
s32 GAMEUTIL_is_overtake_aim_position(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3)
{
    f32 v1[4];
    f32 v2[4];
    f32 dot;

    v1[0] = arg1[0] - arg0[0];
    v1[1] = arg1[1] - arg0[1];
    v1[2] = arg1[2] - arg0[2];
    v2[0] = arg2[0] - arg0[0];
    v2[1] = arg2[1] - arg0[1];
    v2[2] = arg2[2] - arg0[2];
    if (arg3 != 0)
    {
        v1[1] = 0.0f;
        v2[1] = 0.0f;
    }
    dot = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    if (dot <= 0.0f)
    {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_overtake_aim_position);

/* NEARMISS-STUB GAMEUTIL_is_advance_near_dir_to_aim_position */
#if 0 /* NEARMISS 10.9% cat=vu0-mmi sub=- | VU0 vsub/dot | attempts=1 */
s32 GAMEUTIL_is_advance_near_dir_to_aim_position(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3)
{
    f32 v1[4];
    f32 v2[4];
    f32 dot;

    v1[0] = arg1[0] - arg0[0];
    v1[1] = arg1[1] - arg0[1];
    v1[2] = arg1[2] - arg0[2];
    v2[0] = arg2[0] - arg1[0];
    v2[1] = arg2[1] - arg1[1];
    v2[2] = arg2[2] - arg1[2];
    if (arg3 != 0)
    {
        v1[1] = 0.0f;
        v2[1] = 0.0f;
    }
    dot = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    if (dot <= 0.0f)
    {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_advance_near_dir_to_aim_position);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_character_type);
s32 GAMEUTIL_get_character_type(s32 chr)
{
    u8* chara;

    if (chr != 0)
    {
        chara = GetCharacterClass(chr);
        if (chara != 0)
        {
            return *(s16*)(chara + 0x360);
        }
    }
    return 0xFFF0BDC0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_object_move_noise);
f32 GAMEUTIL_get_object_move_noise(s32 arg0)
{
    s32 status;
    s32 contact;
    f32 noise;

    status = 0;
    contact = GAMEUTIL_is_horse_obj_contact_ground(&status, arg0);
    noise = 0.5f;
    if (contact == 1)
    {
        noise = 0.3f;
        if (GAMEUTIL_get_horse_move_status(0, status) != contact)
        {
            noise = 1.0f;
        }
    }
    return noise;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_swimming_now);
s32 GAMEUTIL_is_swimming_now(s32 arg0)
{
    u8 *chara;
    s32 mode;

    if (GAMEUTIL_is_player_obj(arg0) == 1)
    {
        chara = GetCharacterClass(arg0);
        mode = *(s32*)(chara + 0x740);
        if (mode == ControlMode_PLAYER_SWIM || mode == ControlMode_PLAYER_SWIM_MOVE || mode == ControlMode_PLAYER_SWIM_DASH)
        {
            return 1;
        }
    }
    return 0;
}

s32 GAMEUTIL_check_parent_flag(s32 chr);

static inline s32 is_swimming_inl(s32 chr)
{
    s32 mode;

    if (GAMEUTIL_is_player_obj(chr) == 1)
    {
        mode = *(s32 *)(GetCharacterClass(chr) + 0x740);
        if (mode == ControlMode_PLAYER_SWIM || mode == ControlMode_PLAYER_SWIM_MOVE || mode == ControlMode_PLAYER_SWIM_DASH)
        {
            return 1;
        }
    }
    return 0;
}

s32 GAMEUTIL_is_floating_now(s32 arg0)
{
    if (GAMEUTIL_check_parent_flag(arg0) == 0 && !is_swimming_inl(arg0))
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_sign_change);
s32 GAMEUTIL_is_sign_change(f32 a, f32 b)
{
    if (a == b)
    {
        return 0;
    }
    if (a * b <= 0.0f)
    {
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB GAMEUTIL_get_add_cur_stage_ofst_position */
#if 0 /* NEARMISS 49.14% cat=vu0-mmi sub=- | VU0 lqc2/vadd.xyz/sqc2 block; C float version gives 49% | attempts=1 */
void GAMEUTIL_get_add_cur_stage_ofst_position(f32 *arg0, f32 *arg1)
{
    f32 center[4] __attribute__((aligned(16)));

    GetStageCenter(center, get_camera_position(get_main_cameraman_camera_obj()));
    arg0[0] = arg1[0] + center[0];
    arg0[1] = arg1[1] + center[1];
    arg0[2] = arg1[2] + center[2];
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_add_cur_stage_ofst_position);

/* NEARMISS-STUB GAMEUTIL_get_player_obj */
#if 0 /* NEARMISS 84.76% cat=sched sub=- | a1=0 flag scheduled before jal, s0/a0 test reg differs (beqz s0 vs a0 copy) | attempts=1 */
s32 GAMEUTIL_get_player_obj(void)
{
    s32 obj;
    u32 *p;

    obj = 0;
    p = isysGroupForFirst((s32)&gcGlobalVar + 0x2B0, 0);
    if (p != 0)
    {
        obj = *p;
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
    return obj;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_get_player_obj);

static inline s32 get_character_type_inl(s32 chr)
{
    u8 *chara;

    if (chr != 0)
    {
        chara = GetCharacterClass(chr);
        if (chara != 0)
        {
            return *(s16 *)(chara + 0x360);
        }
    }
    return 0xFFF0BDC0;
}

s32 GAMEUTIL_is_player_obj(s32 chr)
{
    return get_character_type_inl(chr) == 2;
}

/* NEARMISS-STUB GAMEUTIL_is_player_obj_standing_on_horse */
#if 0 /* NEARMISS 54.5% cat=regalloc sub=- | frame 0x20 vs 0x10, mode ladder layout | attempts=1 */
extern s32 ControlMode_PLAYER_RIDING_STAND;
extern s32 ControlMode_PLAYER_RIDING_STAND_END;
extern s32 ControlMode_PLAYER_RIDINGSTAND_WEAPON;
extern s32 ControlMode_PLAYER_RIDING_STD_BOW;
extern s32 ControlMode_PLAYER_RIDING_STD_BOW_NO_SYNC;
extern s32 ControlMode_PLAYER_RIDING_STD_BOW_CANCEL;
s32 GAMEUTIL_is_player_obj_standing_on_horse(s32 arg0)
{
    u8 *chara;
    s32 type;
    s32 mode;

    type = 0xFFF0BDC0;
    if (arg0 != 0)
    {
        chara = GetCharacterClass(arg0);
        if (chara != 0)
        {
            type = *(s16*)(chara + 0x360);
        }
    }
    if (type != 2)
    {
        return 0;
    }
    chara = GetCharacterClass(arg0);
    mode = *(s32*)(chara + 0x740);
    if (mode == ControlMode_PLAYER_RIDING_STAND || mode == ControlMode_PLAYER_RIDING_STAND_END || mode == ControlMode_PLAYER_RIDINGSTAND_WEAPON || mode == ControlMode_PLAYER_RIDING_STD_BOW || mode == ControlMode_PLAYER_RIDING_STD_BOW_NO_SYNC || mode == ControlMode_PLAYER_RIDING_STD_BOW_CANCEL)
    {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0006_GAMEUTIL_doit_col_plane_info_filter", GAMEUTIL_is_player_obj_standing_on_horse);
