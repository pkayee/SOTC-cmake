#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_get_weapon_release_position_of_player_obj);
u8 *GetLayoutClass(s32 o);
void GetMotionNodePos(void *out, s32 obj, s32 node, s32 a);
void *GetCharacterClass(void *obj);

static inline s32 GetObjKind(s32 obj)
{
    if (obj != 0) {
        u8 *cc = GetCharacterClass((void *)obj);
        if (cc != 0) {
            return *(s16 *)(cc + 0x360);
        }
    }
    return -1000000;
}

s32 GAMEUTIL_get_weapon_release_position_of_player_obj(u128 *out, s32 obj)
{
    s32 k = GetObjKind(obj) ^ 2;
    if (k == 0) {
        GetMotionNodePos(out, obj, 0x10000, 0);
        return 1;
    }
    *out = **(u128 **)(GetLayoutClass(obj) + 0x134);
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_get_player_look_around_direction);

/* NEARMISS-STUB GAMEUTIL_get_horse_obj */
#if 0 /* NEARMISS 84.8% cat=sched sub=- | same as get_boss_obj: gcc hoists the exit-call flag a1=0 above beqz v0 (target sets it in the exit jal delay slot) and orders a1 before addiu a0 for the first c | attempts=1 */
extern u8 gcGlobalVar[];
void *isysGroupForFirst(s32 group, s32 flag);
void isysGroupForExit(s32 obj, s32 flag);

s32 GAMEUTIL_get_horse_obj(void)
{
    s32 obj;
    void *link;

    obj = 0;
    link = isysGroupForFirst((s32)(gcGlobalVar + 0x2B4), 0);
    if (link != NULL)
    {
        obj = *(s32 *)link;
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
    return obj;
}
#endif
extern u8 gcGlobalVar[];
int *isysGroupForFirst(void *group, int flag);
int *isysGroupForNext(int *link, int flag);
void isysGroupForExit(void *obj, int flag);

void *GAMEUTIL_get_horse_obj(void)
{
    void *found = 0;
    void *o = 0;
    int *g;

    for (g = isysGroupForFirst(gcGlobalVar + 0x2B4, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        o = (void *)*g;
        found = o;
        break;
    }
    if (o != 0)
    {
        isysGroupForExit(o, 0);
    }
    return found;
}

void *GetCharacterClass(void *obj);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_is_horse_obj);
s32 GAMEUTIL_is_horse_obj(s32 obj)
{
    return GetObjKind(obj) == 3;
}

void *GetCharacterClass(void *obj);

void *GAMEUTIL_get_riding_horse_object(void *chara)
{
    u8 *cc;
    s32 horse;

    cc = GetCharacterClass(chara);
    if (cc != NULL)
    {
        horse = *(s32 *)(cc + 0x940);
        if (chara != (void *)horse)
        {
            return (void *)horse;
        }
    }
    return NULL;
}

/* NEARMISS-STUB GAMEUTIL_is_horse_obj_contact_ground */
#if 0 /* NEARMISS 74.8% cat=regalloc sub=- | two-stage class test: target keeps the ((obj != h) ? h : 0) select as a bne with delay-slot store, gcc emits xor+movn; second stage sentinel lui lands in v1 bef | attempts=1 */
s32 GAMEUTIL_is_horse_obj_contact_ground(s32 *out, void *obj)
{
    s32 found;
    s32 ret;
    s32 cls;
    u8 *cc;
    s32 h;

    found = 0;
    ret = 0;
    cc = GetCharacterClass(obj);
    if (cc != NULL)
    {
        h = *(s32 *)(cc + 0x940);
        if ((s32)obj != h)
        {
            found = h;
        }
        else
        {
            found = 0;
        }
    }
    if (found != 0)
    {
        ret = 1;
    }
    else
    {
        cc = NULL;
        if (obj != NULL)
        {
            cc = GetCharacterClass(obj);
        }
        if (cc != NULL)
        {
            cls = *(s16 *)(cc + 0x360);
        }
        else
        {
            cls = 0xFFF0BDC0;
        }
        if (cls == 3)
        {
            found = (s32)obj;
            ret = 1;
        }
    }
    if (out != NULL)
    {
        *out = found;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_is_horse_obj_contact_ground);

extern s32 ControlMode_HORSE_WALK;
extern s32 ControlMode_HORSE_TURN_WALK;
extern s32 ControlMode_HORSE_RUN_N;
extern s32 ControlMode_HORSE_TURN_RUN_N;
extern s32 ControlMode_HORSE_RUN;
extern s32 ControlMode_HORSE_TURN_RUN;

static inline s32 get_character_type(void *actor)
{
    u8 *c;
    if (actor != NULL)
    {
        c = GetCharacterClass(actor);
        if (c != NULL)
        {
            return *(s16 *)(c + 0x360);
        }
    }
    return -1000000;
}

static inline s32 is_horse_obj(void *actor)
{
    return get_character_type(actor) == 3;
}

s32 GAMEUTIL_get_horse_move_status(s32 *out, void *obj)
{
    s32 mode = 0;
    s32 moving = 0;

    if (is_horse_obj(obj))
    {
        s32 m = *(s32 *)((u8 *)GetCharacterClass(obj) + 0x740);

        if (m == ControlMode_HORSE_WALK || m == ControlMode_HORSE_TURN_WALK)
        {
            mode = 2;
            moving = 1;
        }
        else if (m == ControlMode_HORSE_RUN_N || m == ControlMode_HORSE_TURN_RUN_N)
        {
            mode = 3;
            moving = 1;
        }
        else if (m == ControlMode_HORSE_RUN || m == ControlMode_HORSE_TURN_RUN)
        {
            mode = 4;
            moving = 1;
        }
        else
        {
            mode = 1;
        }
    }
    if (out != NULL)
    {
        *out = mode;
    }
    return moving;
}

void *GAMEUTIL_get_boss_obj(void)
{
    void *found = 0;
    void *o = 0;
    int *g;

    for (g = isysGroupForFirst(gcGlobalVar + 0x2B8, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        o = (void *)*g;
        found = o;
        break;
    }
    if (o != 0)
    {
        isysGroupForExit(o, 0);
    }
    return found;
}

extern void *GAMEUTIL_get_parent_object(void *);

static inline int boss_get_character_type(void *actor)
{
    char *c;
    if (actor != 0) {
        c = GetCharacterClass(actor);
        if (c != 0)
            return *(short *)(c + 0x360);
    }
    return -1000000;
}

static inline int is_boss(void *actor)
{
    return boss_get_character_type(actor) == 4;
}

/* NEARMISS-STUB GAMEUTIL_is_boss_obj */
#if 0 /* NEARMISS 80.9% cat=regalloc sub=- | rule-13 reject: 100 only with permuter alias void **pp=&p (null check kept in loop); plain form 80.85 | attempts=3 */
s32 GAMEUTIL_is_boss_obj(s32 obj, s32 recursive)
{
    if (recursive == 0) {
        return GetObjKind(obj) == 4;
    }
    while (obj != 0) {
        if (GetObjKind(obj) == 4) {
            return 1;
        }
        obj = GAMEUTIL_get_parent_object(obj);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_is_boss_obj);

s32 GAMEUTIL_get_parent_collision_attribute(u64 *attr, void *obj);

s32 GAMEUTIL_is_parent_collision_attribute_boss(void *obj)
{
    u64 attr[2];
    s32 ret;

    ret = GAMEUTIL_get_parent_collision_attribute(attr, obj);
    if (ret != 1 || (attr[0] & 1) == 0)
    {
        return 0;
    }
    return 1;
}

s32 bossStatBootChk(void);

s32 GAMEUTIL_is_boss_booting(void)
{
    return bossStatBootChk() > 0;
}

extern s32 D_401306A8;

void GAMEUTIL_set_auto_get_flag_boss_interest_position(s32 value)
{
    D_401306A8 = value;
}

extern u128 D_401306B0;

void GAMEUTIL_set_custom_boss_interest_position(u128 *p)
{
    D_401306B0 = *p;
}

void GAMEUTIL_reset_move_angle(s32 *p);

void GAMEUTIL_constructor_move_angle(u8 *p)
{
    GAMEUTIL_reset_move_angle((s32 *)p);
    *(f32 *)(p + 0x04) = (50.0f * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x08) = (60.0f * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x0C) = (50.0f * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x10) = 0.8f;
    *(f32 *)(p + 0x14) = (100.0f * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x18) = (1.0f * 3.1415926f) / 180.0f;
}

void GAMEUTIL_reset_move_angle(s32 *p)
{
    *p = 0;
}

void GAMEUTIL_set_parameter_move_angle(u8 *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g)
{
    *(f32 *)(p + 0x4) = (a * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x8) = (b * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0xc) = (c * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x10) = d;
    *(f32 *)(p + 0x14) = (e * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x18) = (g * 3.1415926f) / 180.0f;
}

void GAMEUTIL_begin_move_angle(s32 *p)
{
    *p = 0;
}

/* NEARMISS-STUB GAMEUTIL_update_and_get_move_angle */
#if 0 /* NEARMISS 94.0% cat=regalloc sub=- | float math and call shapes match; target loads p[3] into fv1 and p[5] into fv0 (swapped vs gcc), keeps the p1<0 test as c.lt+bc1tl (gcc emits c.le with bc1fl),  | attempts=1 */
f32 GAMEUTIL_get_interp_value_ratio_pow(f32 a, f32 b, f32 c, f32 d);
f32 GAMEUTIL_get_new_velocity(f32 a, f32 b, f32 c, f32 d, f32 e);
f32 GAMEUTIL_get_velocity_by_diff_move(f32 a, f32 b, f32 c, f32 d, s32 e);

f32 GAMEUTIL_update_and_get_move_angle(f32 p1, f32 p2, f32 *p)
{
    f32 zero;
    f32 fabs;
    f32 v;
    f32 vel;
    f32 r;

    zero = 0.0f;
    fabs = p1;
    if (p1 < zero)
    {
        fabs = -p1;
    }
    v = p[5];
    if (fabs < p[3])
    {
        v = GAMEUTIL_get_interp_value_ratio_pow(p[5], p[6], fabs / p[3], p[4]);
    }
    vel = GAMEUTIL_get_new_velocity(p[0], p[1], p[2], v, p2);
    v = vel * p2;
    p[0] = vel;
    if (fabs <= v)
    {
        r = GAMEUTIL_get_velocity_by_diff_move(vel, zero, fabs, p2, 1);
        p[0] = r;
        return p1;
    }
    else if (p1 < zero)
    {
        return -v;
    }
    return v;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_update_and_get_move_angle);

f32 GAMEUTIL_get_cur_velocity_move_angle(f32 *p)
{
    return *p;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_constructor_look_at_vs_offset);
void GAMEUTIL_constructor_interp_ratio_cntrl(void *p);
void GAMEUTIL_set_act_max_zero_clip_flag_interp_ratio_cntrl(void *p, s32 f);
void GAMEUTIL_reset_look_at_vs_offset(u8 *p);

void GAMEUTIL_constructor_look_at_vs_offset(u8 *p)
{
    *(s32 *)(p + 0x18) = 0;
    GAMEUTIL_constructor_interp_ratio_cntrl(p + 0x1C);
    GAMEUTIL_set_act_max_zero_clip_flag_interp_ratio_cntrl(p + 0x1C, 1);
    *(f32 *)(p + 0x3C) = 0.174532910f;
    *(f32 *)(p + 0x40) = 0.174532910f;
    *(f32 *)(p + 0x44) = 0.698131623f;
    *(f32 *)(p + 0x48) = 0.8f;
    *(f32 *)(p + 0x4C) = 1.45f;
    *(f32 *)(p + 0x50) = 0.6108652f;
    *(s32 *)(p + 0) = 0;
    GAMEUTIL_reset_look_at_vs_offset(p);
}

void GAMEUTIL_set_parameter_look_at_vs_offset(f32 a, f32 b, f32 c, f32 d, f32 e, u8 *p)
{
    *(f32 *)(p + 0x4C) = e;
    *(f32 *)(p + 0x48) = d;
    *(f32 *)(p + 0x3C) = (a * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x40) = (b * 3.1415926f) / 180.0f;
    *(f32 *)(p + 0x44) = (c * 3.1415926f) / 180.0f;
}

void GAMEUTIL_set_need_dir_ratio_flag_look_at_vs_offset(u8 *p, s32 flag)
{
    *(s32 *)(p + 0x18) = flag;
}

void GAMEUTIL_set_enable_side_change_angle_look_at_vs_offset(f32 value, u8 *p)
{
    *(f32 *)(p + 0x50) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_reset_look_at_vs_offset);
void GAMEUTIL_reset_interp_ratio_cntrl(void *p);
void GAMEUTIL_set_param_interp_ratio_cntrl(void *p, f32 a, f32 b);

void GAMEUTIL_reset_look_at_vs_offset(u8 *p)
{
    f32 v = *(f32 *)p;
    s32 r;
    if (v == 0.0f || !(v * 0.0f <= 0.0f)) {
        r = 0;
    } else {
        r = 1;
    }
    if (r != 0) {
        *(s32 *)(p + 0x10) = 1;
    } else {
        *(s32 *)(p + 0x10) = 0;
    }
    *(s32 *)(p + 0) = 0;
    *(f32 *)(p + 0xC) = 1.0f;
    *(s32 *)(p + 4) = 0;
    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0x14) = 0;
    GAMEUTIL_reset_interp_ratio_cntrl(p + 0x1C);
    GAMEUTIL_set_param_interp_ratio_cntrl(p + 0x1C, 0.0f, 1.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_doit_look_at_vs_offset);

extern u128 YUnitVector;
extern u128 ZeroPoint;

void GAMEUTIL_constructor_col_plane_info(u8 *p)
{
    *(s32 *)(p + 0x00) = 0;
    *(s32 *)(p + 0x04) = 0;
    *(s32 *)(p + 0x08) = 0;
    *(u64 *)(p + 0x10) = 0;
    *(u128 *)(p + 0x20) = YUnitVector;
    *(u128 *)(p + 0x30) = ZeroPoint;
    *(u128 *)(p + 0x40) = ZeroPoint;
    *(s32 *)(p + 0x50) = 0;
}

void GAMEUTIL_init_col_plane_info_filter(u8 *p, f32 a, f32 b);

void GAMEUTIL_constructor_col_plane_info_filter(u8 *p)
{
    GAMEUTIL_init_col_plane_info_filter(p, 0.0f, 0.0f);
}


void GAMEUTIL_set_parameter_col_plane_info_filter(u8 *p, f32 a, f32 b);

void GAMEUTIL_init_col_plane_info_filter(u8 *p, f32 a, f32 b)
{
    *(s32 *)(p + 0x00) = 0;
    *(s32 *)(p + 0x04) = 0;
    *(s32 *)(p + 0x08) = 0;
    *(u64 *)(p + 0x10) = 0;
    *(u128 *)(p + 0x20) = YUnitVector;
    *(u128 *)(p + 0x30) = ZeroPoint;
    *(u128 *)(p + 0x40) = ZeroPoint;
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x64) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    GAMEUTIL_set_parameter_col_plane_info_filter(p, a, b);
}

void GAMEUTIL_set_parameter_col_plane_info_filter(u8 *p, f32 a, f32 b)
{
    *(f32 *)(p + 0x70) = a;
    *(f32 *)(p + 0x74) = b;
}

/* NEARMISS-STUB GAMEUTIL_disp_col_plane_info_filter_debug */
#if 0 /* NEARMISS 70.4% cat=regalloc sub=- | float args and fptodp/kPrintf call shape match; target keeps the int(a) value in s4 and the fmt pointer reloads in s0; gcc keeps int(a) in s3, moves fs1=a befor | attempts=1 */
extern const char D_40132B08[];
extern const char D_40132B28[];
f32 GAMEUTIL_disp_col_plane_info_debug(f32 a, f32 c, f32 b);
s32 fptodp(f32 x);
void kPrintf(s32 a, s32 b, const char *fmt, s32 c, s32 d);

f32 GAMEUTIL_disp_col_plane_info_filter_debug(u8 *p, f32 a, f32 c, f32 b)
{
    f32 t;
    s32 ib;
    s32 ia;
    s32 s2;
    s32 s3;
    s32 v;
    const char *fmt;

    fmt = D_40132B08;
    t = GAMEUTIL_disp_col_plane_info_debug(a, c, b);
    ia = (s32)a;
    ib = (s32)t;
    s2 = fptodp(*(f32 *)(p + 0x6C));
    t = t + b;
    kPrintf(ia, ib, fmt, s2, fptodp(*(f32 *)(p + 0x74)));
    ib = (s32)t;
    s3 = fptodp(*(f32 *)(p + 0x64));
    t = t + b;
    v = fptodp(*(f32 *)(p + 0x70));
    fmt = D_40132B28;
    kPrintf(ia, ib, fmt, s3, v);
    return t + b;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_disp_col_plane_info_filter_debug);

typedef union {
    u128 q;
    f32 f[4];
} QVec;

typedef struct {
    QVec first;
    QVec second;
    s32 count;
    f32 ratio;
} PositionFilter;

void GAMEUTIL_reset_position_filter(PositionFilter *filter, QVec *position);
void GAMEUTIL_set_parameter_position_filter(PositionFilter *filter, f32 value);

void GAMEUTIL_constructor_position_filter(PositionFilter *filter)
{
    GAMEUTIL_reset_position_filter(filter, (QVec *)&ZeroPoint);
    GAMEUTIL_set_parameter_position_filter(filter, 0.0f);
}

void GAMEUTIL_reset_position_filter(PositionFilter *filter, QVec *position)
{
    filter->first.q = position->q;
    filter->second.q = position->q;
    filter->count = 1;
}

void GAMEUTIL_set_parameter_position_filter(PositionFilter *filter, f32 value)
{
    filter->ratio = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_doit_position_filter);

void ConstructorCollisionDynamics(void *p);

extern u128 ZeroVector;

void GAMEUTIL_reset_collision_info(u8 *p)
{
    *(s32 *)(p + 0x00) = 0;
    ConstructorCollisionDynamics(p + 0x10);
    *(u128 *)(p + 0x40) = ZeroPoint;
    *(u128 *)(p + 0x50) = ZeroVector;
}

void ConvertFromCollisionPointToDynamics(void *out);
void GAMEUTIL_set_data_by_dynamics_collision_info(u8 *p, void *src, s32 flag);

void GAMEUTIL_set_data_by_point_collision_info(u8 *p)
{
    u8 buf[48];

    ConvertFromCollisionPointToDynamics(buf);
    GAMEUTIL_set_data_by_dynamics_collision_info(p, buf, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0007_GAMEUTIL_get_weapon_release_position_of_", GAMEUTIL_set_data_by_dynamics_collision_info);

void GAMEUTIL_constructor_record_info(s32 *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}

void iosFree(void *arg0);

void GAMEUTIL_destructor_record_info(s32 *p)
{
    if (p[2] != 0)
    {
        iosFree((void *)p[2]);
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}

void GAMEUTIL_init_record_info(s32 *p, s32 w, s32 h, s32 heap, s32 mode)
{
    s32 buf;

    if (mode == 1)
    {
        if (p[2] != 0)
        {
            iosFree((void *)p[2]);
        }
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
        p[1] = 0;
    }
    p[0] = w;
    p[1] = h;
    buf = (s32)iosMallocAlign(heap, w * h, 16);
    p[3] = 0;
    p[2] = buf;
}
