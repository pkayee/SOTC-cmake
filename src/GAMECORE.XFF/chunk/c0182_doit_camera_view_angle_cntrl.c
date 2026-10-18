#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_camera_view_angle_cntrl);
/* NEARMISS-STUB doit_camera_view_angle_cntrl */
#if 0 /* NEARMISS 75.2% cat=regalloc sub=- | s3/s0 allocation, ctx+0x13D0 slot | attempts=1 */
u8 *get_cur_using_lws_anime_mode_base_class(u8 *ctx);
s32 is_view_angle_exist_lws_anime_mode_base(u8 *work);
f32 func_400EB278(s32 mode, u8 *obj, void *p);
f32 func_400EB2A8(s32 mode, u8 *obj, u8 *cam);
void reset_double_spring_interp_cntrl(u8 *obj, f32 value);
void set_param_double_spring_interp_common(u8 *obj, f32 a, f32 b, f32 c, f32 d);
void doit_double_spring_interp_cntrl(u8 *obj, f32 x, s32 zero, f32 value);

void doit_camera_view_angle_cntrl(u8 *cam, u8 *ctx, s32 mode, f32 value)
{
    u8 *base;
    u8 *cc;
    s32 exist;
    f32 f20;
    f32 f21;

    base = get_cur_using_lws_anime_mode_base_class(ctx);
    exist = 0;
    if (base != 0)
    {
        exist = is_view_angle_exist_lws_anime_mode_base(base);
    }
    f21 = func_400EB278(exist, ctx + 0x13D0, base);
    if (mode == 1)
    {
        reset_double_spring_interp_cntrl(cam, f21);
        reset_double_spring_interp_cntrl(cam + 0x20, 1.0f);
    }
    else
    {
        f20 = func_400EB2A8(exist, ctx, base);
        cc = *(u8 **)(ctx + 0x13D0);
        if (exist == 1)
        {
            set_param_double_spring_interp_common(cam + 0x20, *(f32 *)(cc + 0x174), *(f32 *)(cc + 0x17C), *(f32 *)(cc + 0x178), -1.0f);
            doit_double_spring_interp_cntrl(cam + 0x20, f20, 0, value);
            reset_double_spring_interp_cntrl(cam, *(f32 *)(cam + 0x3C) * f21);
        }
        else
        {
            set_param_double_spring_interp_common(cam, *(f32 *)(cc + 0x174), *(f32 *)(cc + 0x17C), *(f32 *)(cc + 0x178), -1.0f);
            doit_double_spring_interp_cntrl(cam, f20 * f21, 0, value);
            reset_double_spring_interp_cntrl(cam + 0x20, 1.0f);
        }
    }
    if (*(f32 *)(cam + 0x1C) < 1.0f)
    {
        reset_double_spring_interp_cntrl(cam, 1.0f);
        return;
    }
    if (179.0f < *(f32 *)(cam + 0x1C))
    {
        reset_double_spring_interp_cntrl(cam, 179.0f);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_camera_view_angle_cntrl);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", constructor_camera_view_angle_cntrl);
void constructor_double_spring_interp_cntrl(u8 *obj, f32 value);
void reset_double_spring_interp_cntrl(u8 *obj, f32 value);

void constructor_camera_view_angle_cntrl(u8 *obj)
{
    u8 *cam = obj + 0x20;

    constructor_double_spring_interp_cntrl(obj, 0.0009999999310821295f);
    reset_double_spring_interp_cntrl(obj, 45.0f);
    constructor_double_spring_interp_cntrl(cam, 9.999999747378752e-05f);
    reset_double_spring_interp_cntrl(cam, 1.0f);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_view_angle_camera_view_angle_cntrl);
f32 get_view_angle_camera_view_angle_cntrl(u8 *cam)
{
    return *(f32 *)(cam + 0x1C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EB278);
f32 get_view_angle_lws_anime_mode_base(void *p);

f32 func_400EB278(s32 mode, u8 *obj, void *p)
{
    if (mode == 1)
    {
        return get_view_angle_lws_anime_mode_base(p);
    }
    return *(f32 *)(obj + 0x50);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EB2A8);
s32 is_view_angle_zoom_game_camera(void *obj);

f32 func_400EB2A8(s32 mode, u8 *obj, u8 *cam)
{
    s32 zoom = is_view_angle_zoom_game_camera(obj);

    if (zoom == 1)
    {
        if (mode == 1)
        {
            return *(f32 *)(cam + 0xB4);
        }
        return *(f32 *)(obj + 0x1424);
    }
    return 1.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EB310);
/* NEARMISS-STUB func_400EB310 */
#if 0 /* NEARMISS 88.3% cat=sched sub=- | 6-float call arg setup order | attempts=1 */
extern u8 gcGlobalVar[];
extern f32 D_40137370[];
extern u8 D_40137358[];
void iosDlPushLayer(void);
void iosDlPopLayer(void);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
u8 *GetCharacterClass(s32 obj);
u8 *GetLayoutClass(s32 obj);
void iosInitKPrintfContext(void *ctx, s32 a, s32 b, f32 x, f32 y, f32 c, f32 d, f32 e, f32 f);
void iosSetKPrintfLocateContext(void *ctx, f32 x, f32 y);
void kprintfContext(void *ctx, u8 *fmt, s32 arg);

void func_400EB310(u8 *obj, s32 flag)
{
    u8 ctx[0x40];
    u8 *cc;
    f32 x;
    f32 y;

    if (flag != 0)
    {
        *(f32 *)(obj + 0x38A4) = 2.0f;
    }
    else
    {
        *(f32 *)(obj + 0x38A4) = *(f32 *)(obj + 0x38A4) - *(f32 *)(gcGlobalVar + 0x170);
    }
    if (!(0.0f < *(f32 *)(obj + 0x38A4)))
    {
        return;
    }
    iosDlPushLayer();
    x = (f32)getDrawScreenWidth() * -0.2f;
    y = (f32)getDrawScreenHeight() * D_40137370[0];
    cc = GetCharacterClass(*(s32 *)(obj + 0x1C));
    if (cc != 0)
    {
        iosInitKPrintfContext(ctx, 0, 1, x, y, 0.6f, 0.6f, 1.0f, 1.0f);
    }
    else
    {
        iosInitKPrintfContext(ctx, 0, 1, x, y, 1.0f, 0.6f, 0.6f, 1.0f);
    }
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_40137358, *(s32 *)(GetLayoutClass(*(s32 *)(obj + 0x1C)) + 0x130));
    iosDlPopLayer();
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EB310);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", create_cameraman);
void *iosMallocAlign(s32, s32, s32);
s32 create_camera_obj(s32 a, s32 b, s32 c, f32 value);
void constructor_game_camera(u8 *cam, s32 a);
void iosUnitMatrix(void *m);

u8 *create_cameraman(s32 a0, f32 value, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2)
{
    u8 *cam;

    cam = iosMallocAlign(a0, 0x38F0, 0x10);
    *(s32 *)cam = create_camera_obj(a0, t1, t2, value);
    *(s32 *)(cam + 0x8) = a1;
    *(s32 *)(cam + 0xC) = a2;
    *(s32 *)(cam + 0x10) = a3;
    *(s32 *)(cam + 0x14) = t0;
    *(s32 *)(cam + 0x4) = 0;
    *(s32 *)(cam + 0x18) = 0;
    *(s32 *)(cam + 0x1C) = 0;
    constructor_game_camera(cam + 0x20, a0);
    *(s32 *)(cam + 0x38A0) = 0;
    *(s32 *)(cam + 0x38A4) = 0;
    iosUnitMatrix(cam + 0x38B0);
    return cam;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_cameraman);
/* NEARMISS-STUB doit_cameraman */
#if 0 /* NEARMISS 84.3% cat=regalloc sub=- | gcGlobalVar hi reg and load/store sched | attempts=1 */
extern u8 gcGlobalVar[];
void *DebugFindPlayer(s32 id);
s32 GAMEUTIL_get_first_obj(s32 group);
void SetSeamlessStageControlObject(s32 obj);
s32 func_400EB9A0(u8 *cam);
void func_400EBA38();
void func_400EBA40(void);
void func_400EBA48(f32 value, u8 *cam);
void func_400EBAC0();
void update_camera_obj(s32 obj);

void doit_cameraman(f32 value, u8 *cam)
{
    s32 obj;
    s32 *mode = (s32 *)(cam + 0x4);

    f32 angle = *(f32 *)(cam + 0x38A0);

    *(s32 *)(cam + 0x18) = *(s32 *)(cam + 0x1C);
    *(f32 *)(cam + 0x38A0) = angle - *(f32 *)(gcGlobalVar + 0x170);
    func_400EBA40();
    if (func_400EB9A0(cam) == 0)
    {
        obj = (s32)DebugFindPlayer(*(s32 *)(cam + 0x8));
        *(s32 *)(cam + 0x1C) = obj;
        if (obj == 0)
        {
            obj = GAMEUTIL_get_first_obj(*(s32 *)(cam + 0x8));
            *(s32 *)(cam + 0x1C) = obj;
            if (obj == 0 && *mode != 2)
            {
                return;
            }
        }
    }
    func_400EBA38(cam);
    SetSeamlessStageControlObject(*(s32 *)(cam + 0x1C));
    func_400EBA48(value, cam);
    update_camera_obj(*(s32 *)cam);
    func_400EBAC0(cam);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_cameraman);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_obj);
s32 get_camera_obj(s32 *cam)
{
    return *cam;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", set_camera_mode);
void set_camera_mode(u8 *cam, s32 mode)
{
    *(s32 *)(cam + 0x4) = mode;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_cur_camera_mode);
s32 get_cur_camera_mode(u8 *cam)
{
    return *(s32 *)(cam + 0x4);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_mode_name);
extern u8 D_40137248[];
extern u8 D_40137268[];
extern u8 D_40137288[];
extern u8 D_401372A8[];
extern u8 D_401372D0[];
extern u8 D_401372F8[];
extern u8 D_40137328[];
extern u8 D_40137348[];

u8 *get_camera_mode_name(s32 mode)
{
    if (mode == 0)
    {
        return D_40137248;
    }
    if (mode == 1)
    {
        return D_40137268;
    }
    if (mode == 2)
    {
        return D_40137288;
    }
    if (mode == 3)
    {
        return D_401372A8;
    }
    if (mode == 4)
    {
        return D_401372D0;
    }
    if (mode == 5)
    {
        return D_401372F8;
    }
    if (mode == 6)
    {
        return D_40137328;
    }
    return D_40137348;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_target_group);
s32 get_camera_target_group(u8 *cam)
{
    return *(s32 *)(cam + 0x8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_move_collision_group);
s32 get_camera_move_collision_group(u8 *cam)
{
    return *(s32 *)(cam + 0xC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_visible_collision_group);
s32 get_camera_visible_collision_group(u8 *cam)
{
    return *(s32 *)(cam + 0x10);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_player_collision_group_cameraman);
s32 get_player_collision_group_cameraman(u8 *cam)
{
    return *(s32 *)(cam + 0x14);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_lws_animation_collision_group_cameraman);
s32 get_lws_animation_collision_group_cameraman(u8 *cam)
{
    return *(s32 *)(cam + 0x14);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_game_camera);
u8 *get_game_camera(u8 *cam)
{
    return cam + 0x20;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_cur_camera_target);
s32 get_cur_camera_target(u8 *cam)
{
    return *(s32 *)(cam + 0x1C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_game_camera_WV_matrix);
u8 *get_game_camera_WV_matrix(u8 *cam)
{
    return cam + 0x38B0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", is_game_camera_mode_now);
s32 is_game_camera_mode_now(u8 *cam)
{
    return *(u32 *)(cam + 0x4) < 2;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", is_camera_target_change);
s32 is_camera_target_change(u8 *cam)
{
    return *(s32 *)(cam + 0x1C) != *(s32 *)(cam + 0x18);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", is_camera_target_debug_move);
u64 is_camera_target_debug_move(void)
{
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", change_camera_target);
s32 change_camera_target(u8 *cam, s32 target)
{
    if (target != 0)
    {
        *(s32 *)(cam + 0x1C) = target;
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", change_to_player_camera_target);
void *DebugFindPlayer(s32 id);

s32 change_to_player_camera_target(u8 *cam)
{
    s32 player = (s32)DebugFindPlayer(*(s32 *)(cam + 0x8));

    if (player != 0)
    {
        *(s32 *)(cam + 0x1C) = player;
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", set_camera_parameter_cameraman);
void set_camera_position(s32 obj);
void set_camera_direction(s32 obj, void *dir);
void set_camera_up_direction(s32 obj, void *up);
s32 get_clip_screen(s32 obj);
void set_view_angle(f32 value, s32 clip);

void set_camera_parameter_cameraman(f32 value, s32 *cam, s32 unused, void *dir, void *up)
{
    set_camera_position(*cam);
    set_camera_direction(*cam, dir);
    set_camera_up_direction(*cam, up);
    set_view_angle(value, get_clip_screen(*cam));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", set_camera_parameter_and_update_cameraman);
void update_camera_obj(s32 obj);

void set_camera_parameter_and_update_cameraman(f32 value, s32 *cam, s32 unused, void *dir, void *up)
{
    set_camera_position(*cam);
    set_camera_direction(*cam, dir);
    set_camera_up_direction(*cam, up);
    set_view_angle(value, get_clip_screen(*cam));
    update_camera_obj(*cam);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_parameter_cameraman);
/* NEARMISS-STUB get_camera_parameter_cameraman */
#if 0 /* NEARMISS 78.4% cat=sched sub=- | sq placement vs jal delay slot | attempts=1 */
void *get_camera_position(s32 obj);
void *get_camera_direction(s32 obj);
void *get_camera_up_direction(s32 obj);
f32 get_view_angle(s32 clip);

void get_camera_parameter_cameraman(u128 *pos, u128 *dir, u128 *up, f32 *angle, s32 *cam)
{
    *pos = *(u128 *)get_camera_position(*cam);
    *dir = *(u128 *)get_camera_direction(*cam);
    *up = *(u128 *)get_camera_up_direction(*cam);
    *angle = get_view_angle(get_clip_screen(*cam));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", get_camera_parameter_cameraman);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", check_free_cameraman);
void isysRequestDeleteObj(void *obj);
void flush_game_camera(u8 *cam);
void iosFree(void *p);

void check_free_cameraman(s32 *cam)
{
    if (*cam != 0)
    {
        isysRequestDeleteObj(*(void **)*cam);
        flush_game_camera((u8 *)*cam + 0x20);
        iosFree((void *)*cam);
        *cam = 0;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EB9A0);
void *isysGroupForFirst(s32 group, s32 flag);
void *isysGroupForNext(void *group, s32 flag);
void isysGroupForExit(s32 obj, s32 flag);

s32 func_400EB9A0(u8 *obj)
{
    s32 ret = 0;
    s32 val;
    s32 *grp;

    if (*(s32 *)(obj + 0x1C) != 0)
    {
        val = 0;
        for (grp = isysGroupForFirst(*(s32 *)(obj + 0x8), 0); grp != 0; grp = isysGroupForNext(grp, 0))
        {
            val = *grp;
            if (*(s32 *)(obj + 0x1C) == val)
            {
                ret = 1;
                break;
            }
        }
        if (val != 0)
        {
            isysGroupForExit(val, 0);
        }
    }
    return ret;
}

void func_400EBA38(void) {
}

void func_400EBA40(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", func_400EBA48);
void *get_camera_position(s32 obj);
void *get_camera_direction(s32 obj);
void *get_camera_up_direction(s32 obj);
void doit_game_camera(u8 *a, u8 *b, f32 value);

void func_400EBA48(f32 value, u8 *cam)
{
    s32 obj = *(s32 *)cam;
    u128 volatile pos = *(u128 *)get_camera_position(obj);
    u128 volatile dir = *(u128 *)get_camera_direction(obj);
    u128 volatile up = *(u128 *)get_camera_up_direction(obj);

    doit_game_camera(cam + 0x20, cam, value);
}

void func_400EBAC0(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", init_cameraman_manager);
extern s32 D_40218510[];
extern u8 D_40218530[];
void init_camera_lws_animation_manager(void);
void init_camera_region_manager(void);
void constructor_camera_context(u8 *ctx);
void push_camera_context(u8 *ctx);
void reset_camera_vs_ofst_cntrl_param_segment_array(void);

void init_cameraman_manager(void)
{
    s32 i = 4;
    s32 *p;

    D_40218510[1] = 0;
    D_40218510[0] = -1;
    p = &D_40218510[6];
    do
    {
        i--;
        *p = 0;
        p--;
    } while (i >= 0);
    init_camera_lws_animation_manager();
    init_camera_region_manager();
    constructor_camera_context(D_40218530);
    push_camera_context(D_40218530);
    reset_camera_vs_ofst_cntrl_param_segment_array();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_cameraman_manager);
/* NEARMISS-STUB doit_cameraman_manager */
#if 0 /* NEARMISS 95.7% cat=branch-layout sub=- | loop bgezl with delay slot load | attempts=1 */
void doit_camera_lws_animation_manager(s32 player, s32 boss, f32 value);
void doit_cameraman(f32 value, u8 *cam);
void doit_camera_region_manager(s32 boss, f32 value);
void reset_main_type_camera_lws_animation_update_flag(void);
s32 get_main_cameraman(void);
s32 get_main_cameraman_camera_obj(void);
void gluUpdateCameraContext(s32 obj);
void update_camera_context(u8 *ctx, s32 obj);
void camdebug_for_monitortest(void);
s32 GAMEUTIL_get_player_obj(void);
s32 GAMEUTIL_get_boss_obj(void);

void doit_cameraman_manager(f32 value)
{
    s32 i;
    s32 *p;
    s32 *base;
    s32 v;
    s32 player;
    s32 boss;

    player = GAMEUTIL_get_player_obj();
    boss = GAMEUTIL_get_boss_obj();
    doit_camera_lws_animation_manager(player, boss, value);
    boss = GAMEUTIL_get_boss_obj();
    doit_camera_region_manager(boss, value);
    base = D_40218510;
    p = base + 2;
    v = *p;
    i = 4;
    do
    {
        p++;
        if (v != 0)
        {
            doit_cameraman(value, (u8 *)v);
        }
        i--;
        v = *p;
    } while (i >= 0);
    reset_main_type_camera_lws_animation_update_flag();
    if (get_main_cameraman() != 0)
    {
        gluUpdateCameraContext(get_main_cameraman_camera_obj());
        update_camera_context(D_40218530, get_main_cameraman_camera_obj());
    }
    camdebug_for_monitortest();
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0182_doit_camera_view_angle_cntrl", doit_cameraman_manager);
