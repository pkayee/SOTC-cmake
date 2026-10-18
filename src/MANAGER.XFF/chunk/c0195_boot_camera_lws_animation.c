#include "common.h"

typedef struct CamLwsSlot { /* D_401C16E0[10], stride 0xC0 */
    /* 0x00 */ u8 *anim;
    /* 0x04 */ u8 pad04[0x44];
    /* 0x48 */ s32 geomRef;
    /* 0x4C */ u8 pad4C[0x54];
    /* 0xA0 */ s32 callback;
    /* 0xA4 */ u8 padA4[0x1C];
} CamLwsSlot;
extern CamLwsSlot D_401C16E0[10];
extern s32 D_4012E358;
extern s32 InitialGeometryPointer;
extern u128 ZeroVector;
extern u128 ZeroPoint;
void InitAnimationClass();
void CopyGeometryPointer();

void *func_400F3FC8(s32);
void boot_camera_lws_animation(s32, s32 *, f32, s32, s32, s32);
extern s32 D_401C1780[];
extern s32 D_401C1728[];

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", boot_camera_lws_animation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", disp_camera_lws_animation_debug_info);

void constructor_camera_lws_anime_data(u8 *a)
{
    *(s32 *)(a + 4) = 0;
    *(s32 *)(a + 0) = -1;
    *(s32 *)(a + 8) = -1;
    *(u128 *)(a + 0x10) = ZeroVector;
    *(u128 *)(a + 0x20) = ZeroVector;
    *(u128 *)(a + 0x30) = ZeroPoint;
    *(u128 *)(a + 0x40) = ZeroPoint;
    *(s32 *)(a + 0x54) = -1;
    *(s32 *)(a + 0x50) = 0;
    *(u128 *)(a + 0x60) = ZeroPoint;
    *(u128 *)(a + 0x70) = ZeroPoint;
    *(f32 *)(a + 0x8C) = 1.0f;
    *(s32 *)(a + 0x84) = 0;
    *(s32 *)(a + 0x88) = 0;
    *(s32 *)(a + 0x80) = 0;
}

s32 get_camera_lws_animation_param(s32 *a)
{
    return *a;
}

s32 is_camera_lws_animation_using(s32 *a)
{
    return *a != 0;
}

/* NEARMISS-STUB get_camera_lws_animation_data */
#if 0 /* NEARMISS 64.4% cat=regalloc sub=- | frame/reg assignment: target saves s0-s4 with a5 kept in s4 from entry and obj in s2; ours different callee-saved set; constant 1 reuse and -1 in a3 vs t4; zero | attempts=1 */
typedef struct CamLwsVec4 {
    f32 x;
    f32 y;
    f32 z;
    s32 w;
} CamLwsVec4;

s32 func_400F3D28();
void func_400F3E68(u8 *, s32 *, s32);
void func_400F3EF8(u8 *, u8 *, s32 *, s32, s32, CamLwsVec4 *);

s32 get_camera_lws_animation_data(u8 *a, s32 *b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    s32 *obj;
    CamLwsVec4 tmp;
    CamLwsVec4 pos;

    *(s32 *)(a + 0) = -1;
    *(s32 *)(a + 4) = 0;
    *(s32 *)(a + 8) = -1;
    *(u128 *)(a + 0x10) = ZeroVector;
    *(u128 *)(a + 0x20) = ZeroVector;
    *(u128 *)(a + 0x30) = ZeroPoint;
    *(s32 *)(a + 0x54) = -1;
    *(u128 *)(a + 0x40) = ZeroPoint;
    *(s32 *)(a + 0x50) = 0;
    *(u128 *)(a + 0x60) = ZeroPoint;
    *(u128 *)(a + 0x70) = ZeroPoint;
    *(f32 *)(a + 0x8C) = 1.0f;
    *(s32 *)(a + 0x80) = 0;
    *(s32 *)(a + 0x84) = 0;
    *(s32 *)(a + 0x88) = 0;

    obj = (s32 *)b[0];
    if (obj == NULL)
    {
        return 0;
    }
    tmp.x = *(f32 *)((u8 *)obj + 0xBC);
    tmp.y = *(f32 *)((u8 *)obj + 0xC0);
    tmp.z = *(f32 *)((u8 *)obj + 0xC4);
    tmp.w = 0;
    pos = tmp;

    *(s32 *)(a + 4) = e;
    *(s32 *)(a + 0x50) = g;
    *(s32 *)(a + 0) = (*(s32 *)(((s32 *)b)[0x11] + 0x14) != 1);
    func_400F3D28();
    if (*(s32 *)(a + 0) == 1)
    {
        func_400F3E68(a, b, f);
    }
    *(u128 *)(a + 0x20) = *(u128 *)(a + 0x10);
    func_400F3EF8(a + 0x40, a + 0x30, obj, *(s32 *)(a + 4), *(s32 *)((u8 *)obj + 0x3C), &pos);
    func_400F3EF8(a + 0x70, a + 0x60, obj, *(s32 *)(a + 0x50), *(s32 *)((u8 *)obj + 0x4C), &pos);
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", get_camera_lws_animation_data);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", get_interest_type_camera_lws_animation_data);

s32 get_motion_data_camera_lws_animation(u8 *a)
{
    if (a == NULL)
    {
        return 0;
    }
    return *(s32 *)(a + 0x44);
}

u8 *get_animation_class_camera_lws_animation(u8 *a)
{
    return a + 4;
}

s32 get_boot_obj_camera_lws_animation(u8 *a)
{
    return *(s32 *)(a + 0xAC);
}

s32 is_loop_camera_lws_animation(u8 *a)
{
    return (*(u32 *)(a + 0x10) & 7) != 0;
}

s32 is_main_type_camera_lws_animation(u8 *a)
{
    return ((*(u32 *)(a + 0x10) >> 3) & 7) == 0;
}

s32 is_sub_type_camera_lws_animation(u8 *a)
{
    return ((*(u32 *)(a + 0x10) >> 3) & 7) == 1;
}

s32 is_interest_type_camera_lws_animation(u8 *a)
{
    return ((*(u32 *)(a + 0x10) >> 3) & 7) == 2;
}

s32 is_fixed_point_type_camera_lws_animation(u8 *a)
{
    return ((*(u32 *)(a + 0x10) >> 3) & 7) == 3;
}

s32 is_main_type_camera_lws_animation_update(void)
{
    return D_4012E358;
}

void reset_main_type_camera_lws_animation_update_flag(void)
{
    D_4012E358 = 0;
}

/* NEARMISS-STUB get_camera_lws_animation_parameter_by_name */
#if 0 /* NEARMISS 93.5% cat=sched sub=- | DLD cond: target uses if-chain for arr/count lookups and branch-likely beql on DldSysUndefSymbol; ours combined ternary; lui s6 hoist and extra s0/s2 pointer or | attempts=1 */
static inline u8 *dldRef(u32 *lp, s32 fld)
{
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

u8 *get_camera_lws_animation_parameter_by_name(u32 *lp, char *name)
{
    u8 *e;
    u8 *p;
    s32 i;

    if (lp == NULL)
    {
        return NULL;
    }
    e = dldRef(lp, 0x10);
    p = e;
    for (i = 0; i < (s32)dldRef(lp, 0xC); i++, e += 0xC8)
    {
        if (strcmp(*(char **)p, name) == 0)
        {
            return e;
        }
        p += 0xC8;
    }
    return NULL;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", get_camera_lws_animation_parameter_by_name);

s32 is_same_camera_lws_animation(u32 i, u8 *a)
{
    if (i < 10 && a != NULL && D_401C16E0[i].anim == a)
    {
        return 1;
    }
    return 0;
}

void *get_main_type_camera_lws_animation(void)
{
    return func_400F3FC8(0);
}

void *get_interest_type_camera_lws_animation(void)
{
    return func_400F3FC8(2);
}

void *get_fixed_point_type_camera_lws_animation(void)
{
    return func_400F3FC8(3);
}

void boot_camera_lws_animation_by_script(s32 a0)
{
    boot_camera_lws_animation(a0, &InitialGeometryPointer, 0.0f, 0, 0, 0);
}

s32 stop_camera_lws_animation_geometry_pointer_reference(u32 i)
{
    if (i < 10)
    {
        D_401C1728[i * 0x30] = 0;
        return 1;
    }
    return 0;
}

s32 stop_camera_lws_animation_callback(u32 i)
{
    if (i < 10)
    {
        D_401C1780[i * 0x30] = 0;
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB end_camera_lws_animation */
#if 0 /* NEARMISS 99.96% cat=sched sub=reset-store-order | store order: target emits sw 0xB0 last in branch delay slot, ours hoists it first; lq/sq placement differs | attempts=2 */
s32 end_camera_lws_animation(u32 i) {
    u8 *s;

    if (i < 10) {
        s = (u8 *)D_401C16E0 + i * 0xC0;
        if (*(s32 *)(s + 0xA0) != 0) {
            void (*fn)(s32) = *(void (**)(s32))(s + 0xA4);

            if (fn != NULL) {
                fn(*(s32 *)(s + 0xA8));
            }
        }
        *(s32 *)s = 0;
        InitAnimationClass(s + 4, 0);
        *(s32 *)(s + 0x44) = 0;
        *(s32 *)(s + 0x48) = 0;
        CopyGeometryPointer(s + 0x50, &InitialGeometryPointer);
        *(s32 *)(s + 0xA0) = 0;
        *(s32 *)(s + 0xA4) = 0;
        *(s32 *)(s + 0xB4) = 0;
        *(u128 *)(s + 0x90) = ZeroPoint;
        *(s32 *)(s + 0xAC) = 0;
        *(s32 *)(s + 0xB0) = 0;
        *(s32 *)(s + 0xA8) = 0;
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", end_camera_lws_animation);

/* NEARMISS-STUB end_camera_lws_animation_by_paramID */
#if 0 /* NEARMISS 99.58% cat=sched sub=reset-store-order | lui/addiu register assignment swapped for D_401C16E0 vs ZeroPoint; store order of sw 0xA0/0xB4 differs | attempts=2 */
s32 end_camera_lws_animation_by_paramID(s32 id) {
    s32 i;
    u8 *s = (u8 *)D_401C16E0;

    for (i = 0; i < 10; i++, s += 0xC0) {
        if (*(s32 *)s == id) {
            if (*(s32 *)(s + 0xA0) != 0) {
                void (*fn)(s32) = *(void (**)(s32))(s + 0xA4);

                if (fn != NULL) {
                    fn(*(s32 *)(s + 0xA8));
                }
            }
            *(s32 *)s = 0;
            InitAnimationClass(s + 4, 0);
            *(s32 *)(s + 0x44) = 0;
            *(s32 *)(s + 0x48) = 0;
            CopyGeometryPointer(s + 0x50, &InitialGeometryPointer);
            *(s32 *)(s + 0xB4) = 0;
            *(u128 *)(s + 0x90) = ZeroPoint;
            *(s32 *)(s + 0xA4) = 0;
            *(s32 *)(s + 0xA8) = 0;
            *(s32 *)(s + 0xAC) = 0;
            *(s32 *)(s + 0xB0) = 0;
            *(s32 *)(s + 0xA0) = 0;
            return 1;
        }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", end_camera_lws_animation_by_paramID);

/* NEARMISS-STUB init_camera_lws_animation_manager */
#if 0 /* NEARMISS 99.49% cat=regalloc sub=reset-store-order | lui register swap: target loads D_401C16E0 into v1 and ZeroPoint into v0, ours the reverse | attempts=2 */
void init_camera_lws_animation_manager(void) {
    s32 i;
    u8 *s = (u8 *)D_401C16E0;

    for (i = 9; i >= 0; i--) {
        *(s32 *)s = 0;
        InitAnimationClass(s + 4, 0);
        *(s32 *)(s + 0x44) = 0;
        *(s32 *)(s + 0x48) = 0;
        CopyGeometryPointer(s + 0x50, &InitialGeometryPointer);
        *(u128 *)(s + 0x90) = ZeroPoint;
        *(s32 *)(s + 0xA0) = 0;
        *(s32 *)(s + 0xA4) = 0;
        *(s32 *)(s + 0xA8) = 0;
        *(s32 *)(s + 0xAC) = 0;
        *(s32 *)(s + 0xB0) = 0;
        *(s32 *)(s + 0xB4) = 0;
        s += 0xC0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0195_boot_camera_lws_animation", init_camera_lws_animation_manager);
