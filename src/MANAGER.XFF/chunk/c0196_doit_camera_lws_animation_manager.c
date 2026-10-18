#include "common.h"

typedef struct CamLwsSlot { /* D_401C16E0[10], stride 0xC0 */
    u8 *anim;
    u8 pad[0xBC];
} CamLwsSlot;
extern CamLwsSlot D_401C16E0[10];

void func_400F2588(void *, s32, s32, f32);
void end_camera_lws_animation_by_paramID();
void iosSetCameraMatrix();
void create_original_view_matrix();
void set_screen_size();
void update_clip_screen();
void update_transform_matrix_set();
void func_400F41A0();
void check_free_clip_screen();
void check_free_transform_matrix_set();
void isysFlushISYSLetterObj();
void *dynamic_cast_to_camera_obj();
s32 GetLayoutObjWorkSize(u8 *);
u8 *_isysCreateObj(s32, s32, s32, s32, void (*)(void *), s32);
s32 create_clip_screen(s32, s32, s32, f32);
s32 create_transform_matrix_set(s32);
void func_400F4558(void *o);
void update_camera_obj(u8 *c);
void set_camera_position(u8 *c, u128 *p);
void set_camera_direction(u8 *c, f32 *v);
void set_camera_up_direction(u8 *c, f32 *v);
u8 *GetCharacterClass(s32);
s32 GetCharacterClassCurAnimationFrameRate(u8 *);
void *memset(void *, s32, u32);

void doit_camera_lws_animation_manager(f32 dt, s32 a, s32 b) {
    s32 i = 9;
    CamLwsSlot *p = D_401C16E0;

    do {
        func_400F2588(p, a, b, dt);
        p++;
    } while (--i >= 0);
}

void add_camera_lws_animation_segment(void) {
}

/* NEARMISS-STUB free_camera_lws_animation_segment */
#if 0 /* NEARMISS 89.8% cat=regalloc sub=delay-slot-lw | target loads base into a0 then copies to s1; ours loads straight into s1 | attempts=2 */
void free_camera_lws_animation_segment(u8 *seg) {
    s32 n;
    u8 *p;

    if (seg != NULL) {
        n = *(s32 *)(seg + 0xC);
        p = *(u8 **)(seg + 0x10);
        if (n > 0) {
            do {
                u8 *cur = p;
                p += 0xC8;
                n--;
                end_camera_lws_animation_by_paramID(cur);
            } while (n != 0);
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", free_camera_lws_animation_segment);

f32 func_400F3B50(u8 *a, s32 c1, s32 c2) {
    f32 r = 30.0f;
    s32 w = *(s32 *)(a + 0xC);
    s32 who = 0;

    if (0.0f < (f32)w) {
        r = (f32)w;
    } else if (w == -1) {
        who = c1;
    } else if (w == -2) {
        who = c2;
    }
    if (who != 0) {
        r = (f32)GetCharacterClassCurAnimationFrameRate(GetCharacterClass(who));
        r *= *(f32 *)(GetCharacterClass(who) + 0x514);
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F3BF8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F3D28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F3E68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F3EF8);

s32 func_400F3F98(u8 *a) {
    if (*(s32 *)(a + 0x64) != 0 && 0.0f <= *(f32 *)(a + 0x68)) {
        return 1;
    }
    return 0;
}

CamLwsSlot *func_400F3FC8(s32 kind) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_401C16E0[i].anim != NULL && ((*(u32 *)(D_401C16E0[i].anim + 0x10) >> 3) & 7) == kind) {
            return &D_401C16E0[i];
        }
    }
    return NULL;
}

s32 func_400F4018(void) {
    s32 n = 0;
    s32 i;

    for (i = 9; i >= 0; i--) {
        if (D_401C16E0[9 - i].anim != NULL) {
            n++;
        }
    }
    return n;
}

u8 *create_camera_obj(s32 a, s32 b, s32 c, f32 d) {
    f32 pos[4];
    f32 dir[4];
    f32 up[4];
    u8 layout[0x80];
    u8 *obj;

    memset(pos, 0, 0x10);
    pos[3] = 1.0f;
    memset(dir, 0, 0x10);
    dir[2] = 1.0f;
    memset(up, 0, 0x10);
    up[1] = 1.0f;
    obj = _isysCreateObj(a, 0x11, 0x260, func_400F4518(layout), func_400F4558, 0x10);
    isysInitISYSLetterObj(obj);
    InitLayoutObj(obj, layout);
    set_camera_position(obj, (u128 *)pos);
    set_camera_direction(obj, dir);
    set_camera_up_direction(obj, up);
    *(s32 *)(obj + 0x250) = create_clip_screen(a, b, c, d);
    *(s32 *)(obj + 0x254) = create_transform_matrix_set(a);
    update_camera_obj(obj);
    return obj;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F41A0);

void set_camera_obj_screen_size(u8 *c) {
    set_screen_size(*(s32 *)(c + 0x250));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", dynamic_cast_to_camera_obj);

void update_camera_obj(u8 *c) {
    create_original_view_matrix(c + 0x210, c + 0x1E0, c + 0x1F0, c + 0x200);
    update_clip_screen(*(s32 *)(c + 0x250));
    update_transform_matrix_set(*(s32 *)(c + 0x254), c, *(s32 *)(c + 0x250));
    func_400F41A0(c);
}

void set_camera_position(u8 *c, u128 *p) {
    *(u128 *)(c + 0x1E0) = *p;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", set_camera_direction);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", set_camera_up_direction);

u8 *get_camera_position(u8 *c) {
    return c + 0x1E0;
}

u8 *get_camera_direction(u8 *c) {
    return c + 0x1F0;
}

u8 *get_camera_up_direction(u8 *c) {
    return c + 0x200;
}

u8 *get_camera_obj_layout_class(u8 *c) {
    return c + 0x20;
}

s32 get_clip_screen(u8 *c) {
    return *(s32 *)(c + 0x250);
}

s32 get_transform_matrix_set(u8 *c) {
    return *(s32 *)(c + 0x254);
}

void create_original_view_matrix() {
    iosSetCameraMatrix();
}

s32 func_400F4518(u8 *obj) {
    memset(obj, 0, 0x7C);
    *(s32 *)(obj + 4) = 1;
    *(s32 *)(obj + 0x3C) = -1;
    return GetLayoutObjWorkSize(obj);
}

void func_400F4558(void *o) {
    u8 *c = dynamic_cast_to_camera_obj(o);

    if (c != NULL) {
        isysFlushISYSLetterObj(c);
        check_free_clip_screen(c + 0x250);
        check_free_transform_matrix_set(c + 0x254);
    }
}

u8 *get_view_matrix(u8 *c) {
    return c + 0x210;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0196_doit_camera_lws_animation_manager", func_400F45B8);
