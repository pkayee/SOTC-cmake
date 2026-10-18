#include "common.h"

extern const char D_4012FEE8[];
extern const char D_4012FF08[];
extern const char D_4012FF28[];
extern const char D_4012FF48[];
extern const char D_4012FF58[];
extern const char D_4012FF60[];
extern const char D_4012FF70[];
extern const char D_4012FF80[];
extern const char D_4012FF90[];
extern const char D_4012FFA0[];
extern const char D_4012FFB0[];
extern const char D_4012FFC8[];
extern const char D_40130000[];
extern const char D_40130028[];
extern const char *D_40124458[];
extern const char *D_40124548[];
extern const char *D_401245C8[];
extern const char *D_40124710[];
extern const char *D_40124648[];
extern const char *D_401246F0[];
extern const char D_4012F170[];
extern char D_4012FFC0[];

extern u8 padManagerData[];
extern f32 D_40124440;
extern f32 D_40124448;
extern s32 D_40124444;

s32 GetParentCharColAttr();
u8 *GetLayoutClass();
u8 *GetLayoutParentObj(u8 *);
void iosSetKPrintfLocateContext(void *ctx, f32 x, f32 y);
void kprintfContext();
void kprintfContextCentering();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_collision_attribute_info);
f32 DEBUG_disp_collision_attribute_info(u64 attr, void *ctx, f32 x, f32 y, f32 dy) {
    s32 idx = (((attr & 0x3F800000000000UL) >> 47)) - 1;

    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FEE8, attr & 1, (attr & 2) >> 1);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF08, (attr & 4) >> 2, (attr & 8) >> 3);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF28, ((attr & 0x1F8000UL) >> 15), ((attr & 0x1E00000UL) >> 21));
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    if (idx < 0) {
        kprintfContext(ctx, D_4012FF48);
    } else {
        kprintfContext(ctx, D_4012FF58, idx);
    }
    y += dy;
    y += dy * 0.3f;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF60, D_40124458[(attr & 0x3F0) >> 4]);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF70, D_40124548[(attr & 0x7C00) >> 10]);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF80, D_401245C8[((attr & 0x7C000000UL) >> 26)]);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FF90, D_40124710[((attr & 0xF80000000UL) >> 31)]);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FFA0, D_40124648[((attr & 0x3F000000000UL) >> 36)]);
    y += dy;
    iosSetKPrintfLocateContext(ctx, x, y);
    kprintfContext(ctx, D_4012FFB0, D_401246F0[((attr & 0x3C0000000000UL) >> 42)]);
    return y + dy;
}


//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_center_collision_attribute_info);
void DEBUG_disp_center_collision_attribute_info(u64 attr, void *ctx) {
    kprintfContextCentering(ctx, D_4012FFC8, attr & 1, (attr & 2) >> 1, (attr & 4) >> 2, ((attr & 0x1E00000UL) >> 21), (attr & 8) >> 3, ((attr & 0x3F800000000000UL) >> 47));
    kprintfContextCentering(ctx, D_40130000, D_40124458[(attr & 0x3F0) >> 4], D_40124548[(attr & 0x7C00) >> 10], D_401245C8[((attr & 0x7C000000UL) >> 26)], D_40124710[((attr & 0xF80000000UL) >> 31)]);
    kprintfContextCentering(ctx, D_40130028, ((attr & 0x1F8000UL) >> 15), D_40124648[((attr & 0x3F000000000UL) >> 36)], D_401246F0[((attr & 0x3C0000000000UL) >> 42)]);
}


//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", doit_debug_utility);
void doit_debug_utility(f32 dt) {
    D_40124440 = dt;
    if (*(s32 *)(padManagerData + 0xFA0) & 0x800) {
        D_40124448 = 2.0f;
        D_40124444 = D_40124444 == 0;
    } else {
        D_40124448 = D_40124448 - dt;
    }
}


void func_40014A60(void);
extern f32 D_40124448;

void disp_debug_utility(void)
{
    if (0.0f < D_40124448)
    {
        func_40014A60();
    }
}

extern s32 D_4012444C;
extern s32 D_40124444;
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);

void DEBUG_set_update_position_method_pointer(s32 method)
{
    D_4012444C = method;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_is_locking_debug_camera);
s32 DEBUG_is_locking_debug_camera(void)
{
    return D_40124444;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_update_position);
s32 DEBUG_update_position(u128 *dst, u128 *src)
{
    if (D_40124444 != 0)
    {
        if (D_4012444C != 0)
        {
            return ((s32 (*)(u128 *, u128 *))D_4012444C)(dst, src);
        }
    }
    *dst = *src;
    return 0;
}

void DEBUG_get_2d_font_disp_position(f32 scale_x, f32 scale_y, f32 *out_x, f32 *out_y)
{
    s32 w1;
    s32 w2;
    s32 h1;
    s32 h2;

    w1 = getDrawScreenWidth();
    w2 = getDrawScreenWidth();
    *out_x = (f32)(-w1) * 0.5f + (f32)w2 * scale_x;
    h1 = getDrawScreenHeight();
    h2 = getDrawScreenHeight();
    *out_y = (f32)(-h1) * 0.5f + (f32)h2 * scale_y;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_get_2d_font_default_height_offset);
f32 DEBUG_get_2d_font_default_height_offset(void)
{
    return (f32)getDrawScreenHeight() * 0.04f;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_get_cntrl_mode_name);
u8 *GetCharacterClass(s32);

s32 DEBUG_get_cntrl_mode_name(s32 obj, s32 mode)
{
    u8 *cc = GetCharacterClass(obj);

    if (cc != NULL)
    {
        return *(s32 *)(*(u8 **)(cc + 0x740) + 8);
    }
    return mode;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_get_latest_motion_name);
s32 DEBUG_get_latest_motion_name(s32 obj, s32 mode)
{
    u8 *cc = GetCharacterClass(obj);

    if (cc != NULL)
    {
        u8 *p = *(u8 **)(cc + 0x568);

        if (p != NULL)
        {
            return *(s32 *)p;
        }
    }
    return mode;
}

u32 strlen(const char *);

char *DEBUG_get_base_name(char *name)
{
    s32 i;
    char *p;

    for (i = strlen(name) - 2; i != -1; i--)
    {
        p = name + i;
        if (*p == '/')
        {
            return p + 1;
        }
    }
    return name;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_get_base_name_extention_cut);
char *strrchr(const char *, s32);

char *DEBUG_get_base_name_extention_cut(char *name)
{
    s32 i;
    char *p;

    p = strrchr(name, '.');
    if (p != NULL)
    {
        *p = '\0';
    }
    for (i = strlen(name) - 2; i != -1; i--)
    {
        p = name + i;
        if (*p == '/')
        {
            return p + 1;
        }
    }
    return name;
}

u8 *GetLayoutClass();
u8 *GetLayoutParentObj(u8 *);

s32 DEBUG_get_parent_layout_name(s32 obj, s32 mode)
{
    u8 *layout = GetLayoutClass(obj);
    u8 *parent = GetLayoutParentObj(layout);

    if (parent != NULL)
    {
        return *(s32 *)(GetLayoutClass(parent) + 0x130);
    }
    return mode;
}

f32 DEBUG_disp_sphere_object(s32, s32, s32, s32, f32, f32, f32);
f32 DEBUG_disp_cylinder_object(s32, s32, s32, s32, f32, f32, f32);
f32 DEBUG_disp_box_object(s32, s32, s32, s32, f32, f32, f32);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_region_object);
f32 DEBUG_disp_region_object(s32 kind, s32 a1, s32 a2, s32 a3, s32 a4, f32 x, f32 y, f32 z)
{
    if (kind == 0)
    {
        return DEBUG_disp_sphere_object(a1, a2, a3, a4, x, x, x);
    }
    if (kind == 1)
    {
        return DEBUG_disp_sphere_object(a1, a2, a3, a4, x, y, z);
    }
    if (kind == 2)
    {
        return DEBUG_disp_cylinder_object(a1, a2, a3, a4, x, y, z);
    }
    if (kind == 3)
    {
        return DEBUG_disp_box_object(a1, a2, a3, a4, x, y, z);
    }
    return x;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_sphere_object);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_box_object);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_collision_attribute_info_extend);
static inline char *parentLayoutName(s32 obj, char *def) {
    s32 parent = GetLayoutParentObj(GetLayoutClass(obj));

    if (parent != 0) {
        return *(char **)(GetLayoutClass(parent) + 0x130);
    }
    return def;
}

f32 DEBUG_disp_collision_attribute_info_extend(s32 obj, void *ctx, f32 x, f32 y, f32 dy) {
    u64 attr = 0;
    char *name;

    if (GetParentCharColAttr(&attr, obj) == 1) {
        iosSetKPrintfLocateContext(ctx, x, y);
        name = parentLayoutName(obj, D_4012FFC0);
        kprintfContext(ctx, D_4012F170, name);
        y = DEBUG_disp_collision_attribute_info(attr, ctx, x, y + dy * 1.2f, dy);
    }
    return y;
}


//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0001_DEBUG_disp_collision_attribute_info", DEBUG_disp_collision_name);
f32 DEBUG_disp_collision_name(s32 obj, void *ctx, f32 x, f32 y, f32 dy) {
    u64 attr = 0;
    char *name;

    if (GetParentCharColAttr(&attr, obj) == 1) {
        iosSetKPrintfLocateContext(ctx, x, y);
        name = parentLayoutName(obj, D_4012FFC0);
        kprintfContext(ctx, D_4012F170, name);
        y += dy * 1.2f;
    }
    return y;
}

