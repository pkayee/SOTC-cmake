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
s32 boot_camera_lws_animation(s32, s32 *, f32, s32, s32, s32);
extern s32 D_401C1780[];
extern s32 D_401C1728[];

/* READY MANAGER c0195 boot_camera_lws_animation: 100.0 (rea-mgr-c0195, 2026-10-19). Run _prelude_patch.py on the TU first: the TU declares it void, the target returns the slot index or -1 in v0. Key: type tests 2 and 3 are written (T ^ 2) == 0 (xori+bnezl; plain == 2 gives li+bnel 94.8), last two stores B0 then B4. */
u8 *initAnimationObjResource(u8 *);
void InitAnimationClassWithFrame(u8 *, s32, f32);
void GetGeometryPointerPosition(u8 *, u8 *);

/* READY MANAGER c0195 get_camera_lws_animation_parameter_by_name: 100.0 (rea-mgr-c0195, 2026-10-19). Array-index form a[i].name / &a[i] is the key: ptr-walk forms give 93.6 (p/e register swap). */
extern s32 DldSysUndefSymbol;
s32 strcmp(const char *, const char *);
typedef struct CamLwsParam {
    char *name;
    u8 pad[0xC4];
} CamLwsParam;
static inline u8 *dldRef(u32 *lp, s32 fld)
{
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

s32 boot_camera_lws_animation(s32 av, s32 *gp, f32 frame, s32 cb, s32 arg, s32 boot)
{
    s32 i;
    u8 *s;
    u8 *r;
    s32 isMain;
    u8 *a = (u8 *)av;

    if (a == NULL)
    {
        return -1;
    }
    isMain = ((*(u32 *)(a + 0x10) >> 3) & 7) == 0;
    if (((*(u32 *)(a + 0x10) >> 3) & 7) == 0)
    {
        if (func_400F3FC8(0) != 0)
        {
            return -1;
        }
    }
    if ((((*(u32 *)(a + 0x10) >> 3) & 7) ^ 2) == 0)
    {
        if (func_400F3FC8(2) != 0)
        {
            return -1;
        }
    }
    if ((((*(u32 *)(a + 0x10) >> 3) & 7) ^ 3) == 0)
    {
        if (func_400F3FC8(3) != 0)
        {
            return -1;
        }
    }
    s = (u8 *)D_401C16E0;
    for (i = 0; i < 10; i++, s += 0xC0)
    {
        if (*(s32 *)s == 0)
        {
            if (isMain == 1)
            {
                D_4012E358 = isMain;
            }
            r = initAnimationObjResource(a + 4);
            if (r != NULL)
            {
                *(u8 **)s = a;
                InitAnimationClassWithFrame(s + 4, 0, frame);
                *(s32 *)(s + 0x44) = *(s32 *)(r + 0x20);
                CopyGeometryPointer(s + 0x50, gp);
                *(s32 *)(s + 0x48) = 1;
                GetGeometryPointerPosition(s + 0x90, s + 0x50);
                *(s32 *)(s + 0xA0) = 1;
                *(s32 *)(s + 0xA4) = cb;
                *(s32 *)(s + 0xA8) = arg;
                *(s32 *)(s + 0xAC) = boot;
                *(s32 *)(s + 0xB0) = 0;
                *(s32 *)(s + 0xB4) = 0;
            }
            return i;
        }
    }
    return -1;
}

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

CamLwsParam *get_camera_lws_animation_parameter_by_name(u32 *lp, char *name)
{
    CamLwsParam *a;
    s32 i;

    if (lp != NULL)
    {
        a = (CamLwsParam *)dldRef(lp, 0x10);
        for (i = 0; i < (s32)dldRef(lp, 0xC); i++)
        {
            if (strcmp(a[i].name, name) == 0)
            {
                return &a[i];
            }
        }
    }
    return NULL;
}

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

/* READY MANAGER c0195 end_camera_lws_animation: 100.0 via try-score (rea-mgr-c0195, 2026-10-19). Needs the TU-top decls CamLwsSlot, D_401C16E0, InitialGeometryPointer, ZeroPoint, InitAnimationClass, CopyGeometryPointer which the TU already has. */
s32 end_camera_lws_animation(u32 i) {
    u8 *s;

    if (i < 10) {
        s = (u8 *)&D_401C16E0[i];
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
        *(u128 *)(s + 0x90) = ZeroPoint;
        *(s32 *)(s + 0xA0) = 0;
        *(s32 *)(s + 0xA4) = 0;
        *(s32 *)(s + 0xA8) = 0;
        *(s32 *)(s + 0xAC) = 0;
        *(s32 *)(s + 0xB0) = 0;
        *(s32 *)(s + 0xB4) = 0;
        return 1;
    }
    return 0;
}

/* READY MANAGER c0195 end_camera_lws_animation_by_paramID: 100.0 via try-score (rea-mgr-c0195, 2026-10-19). Needs the TU-top decls CamLwsSlot, D_401C16E0, InitialGeometryPointer, ZeroPoint, InitAnimationClass, CopyGeometryPointer which the TU already has. */
s32 end_camera_lws_animation_by_paramID(s32 id) {
    s32 i;
    u8 *s;

    for (i = 0; i < 10; i++) {
        s = (u8 *)&D_401C16E0[i];
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
            *(u128 *)(s + 0x90) = ZeroPoint;
            *(s32 *)(s + 0xA0) = 0;
            *(s32 *)(s + 0xA4) = 0;
            *(s32 *)(s + 0xA8) = 0;
            *(s32 *)(s + 0xAC) = 0;
            *(s32 *)(s + 0xB0) = 0;
            *(s32 *)(s + 0xB4) = 0;
            return 1;
        }
    }
    return 0;
}

/* READY MANAGER c0195 init_camera_lws_animation_manager: 100.0 via try-score (rea-mgr-c0195, 2026-10-19). Needs the TU-top decls CamLwsSlot, D_401C16E0, InitialGeometryPointer, ZeroPoint, InitAnimationClass, CopyGeometryPointer which the TU already has. */
void init_camera_lws_animation_manager(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        u8 *s = (u8 *)&D_401C16E0[i];
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
    }
}
