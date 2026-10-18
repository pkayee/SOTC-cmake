#include "common.h"

/* clip/screen object (get_screen_width / get_screen_height / set_screen_size / get_aspect_ratio) */
typedef struct CamScreen {
    /* 0x00 */ s32 wide;
    /* 0x04 */ s32 height;
    /* 0x08 */ f32 aspect;
    /* 0x0C */ f32 viewAngle;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} CamScreen;

void iosFree(void *p);
extern f32 D_4012E36C;
extern f32 D_4012E370;
extern s32 D_4012E374;
f32 func_400F5E40(s32 height, f32 angle);
void func_400F5EC8(CamScreen *s, f32 v);
void func_400F5FD0(CamScreen *s, f32 v);
void func_400F5F80(CamScreen *s);
void func_400F6180(u8 *obj, s32 a, s32 b);
void check_free_camera_region(void **slot);
extern void *D_401C1E60[];
extern s32 D_4012E35C;
extern void *D_4012E360;
CamScreen *func_400F5808(CamScreen *s);
void *iosMallocAlign(s32, s32, s32);
s32 getDispScreenWidth(void);
s32 getDispScreenHeight(void);
s32 getDrawScreenHeight(void);
void set_screen_size(CamScreen *s, s32 w, s32 h);
void set_view_angle(CamScreen *s, f32 angle);
void set_scissor_screen_size(CamScreen *s, s32 idx, s32 x, s32 y);
void update_clip_screen(CamScreen *s);

void *create_and_init_camera_region();
extern s32 rootPtn;

s32 add_object_animation_camera_region(void *obj, void *arg, s32 c)
{
    s32 i;
    void **p;

    if (obj != NULL && arg != NULL)
    {
        p = D_401C1E60;
        for (i = 0; i < 0x32; i++, p++)
        {
            if (*p == NULL)
            {
                *p = create_and_init_camera_region(0, c, 0, obj, arg, &rootPtn);
                return 1;
            }
        }
    }
    return 0;
}

s32 delete_object_animation_camera_region(void *obj)
{
    s32 i;
    void **p;

    if (obj != NULL)
    {
        p = D_401C1E60;
        for (i = 0; i < 0x32; i++, p++)
        {
            if (*p != NULL && *(void **)((u8 *)*p + 0x10) == obj)
            {
                check_free_camera_region(p);
                return 1;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", get_apply_camera_region);

void disp_camera_region(f32 scale, void *obj, s32 flag, s32 arg);

/* NEARMISS-STUB disp_object_animation_camera_region_group */
#if 0 /* NEARMISS 79.98% cat=branch-layout sub=- | loop flag (i!=1) kept in its own reg s2 (target: xori/sltu on s2), and i==0||mode==1 branch/loop layout differs | attempts=1 */
void disp_object_animation_camera_region_group(s32 mode, s32 arg)
{
    s32 i;
    s32 n;
    void **p;
    void *obj;
    f32 scale;

    for (i = 0; i < 2; i++)
    {
        if (i == 0 || mode == 1)
        {
            scale = 1.0f;
            if (i == 1)
            {
                scale = 0.2f;
            }
            p = D_401C1E60;
            obj = *p;
            n = 0x31;
            while (1)
            {
                p++;
                if (obj != NULL)
                {
                    disp_camera_region(scale, obj, i != 1, arg);
                }
                n--;
                if (n < 0)
                {
                    break;
                }
                obj = *p;
            }
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", disp_object_animation_camera_region_group);
s32 get_max_object_animation_camera_region(void)
{
    return 0x32;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", get_cur_total_object_animation_camera_region);
s32 get_cur_total_object_animation_camera_region(void) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 50; i++) {
        if (D_401C1E60[i] != 0) {
            n++;
        }
    }
    return n;
}

extern s32 D_4012E364;
extern s32 D_4012E368;

s32 *get_col_attr_cam_region_select_flag(void)
{
    return &D_4012E364;
}

s32 *get_col_attr_cam_region_select_index(void)
{
    return &D_4012E368;
}

CamScreen *func_400F5788(s32 mode, u64 key)
{
    s32 i;

    if (mode == 1)
    {
        key &= 0x3F000000000ULL;
        for (i = 0; i < D_4012E35C; i++)
        {
            u8 *e = (u8 *)((void **)D_4012E360)[i];

            if (key == *(u64 *)(e + 8))
            {
                return func_400F5808((CamScreen *)e);
            }
        }
    }
    return NULL;
}

CamScreen *func_400F5808(CamScreen *s)
{
    if (s != NULL && s->unk14 != 0)
    {
        return s;
    }
    return NULL;
}

/* NEARMISS-STUB create_clip_screen */
#if 0 /* NEARMISS 99.88% cat=call-abi sub=- | only reloc symbol names of 4 callees differ | attempts=1 */
CamScreen *create_clip_screen(s32 heap, s32 w, s32 h, f32 angle)
{
    CamScreen *s;
    s32 i;

    s = iosMallocAlign(heap, 0x220, 0x10);
    set_screen_size(s, w, h);
    set_view_angle(s, angle);
    for (i = 0; i < 2; i++)
    {
        set_scissor_screen_size(s, i, w, h);
    }
    update_clip_screen(s);
    return s;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", create_clip_screen);

void check_free_clip_screen(void **buf)
{
    if (*buf != NULL)
    {
        iosFree(*buf);
        *buf = NULL;
    }
}

void set_screen_size(CamScreen *s, s32 w, s32 h)
{
    f32 *scale = &D_4012E370;
    s32 dispW;
    s32 dispH;
    s32 drawH;

    s->wide = w;
    s->height = h;
    s->aspect = ((f32)w / (f32)h) / 0.90909f;
    dispW = getDispScreenWidth();
    dispH = getDispScreenHeight();
    drawH = getDrawScreenHeight();
    *scale = (((f32)s->wide / (f32)dispW) / ((f32)h / (f32)dispH)) * (f32)drawH / 448.0f;
}

/* NEARMISS-STUB set_screen_wide_and_progressive */
#if 0 /* NEARMISS 65.08% cat=branch-layout sub=- | target branch order: beqz wide to else arm, delay slots filled with lui v0 and single swc1 at the join | attempts=1 */
void set_screen_wide_and_progressive(s32 wide, s32 progressive)
{
    if (wide != 0)
    {
        if (progressive != 0)
        {
            D_4012E36C = 1.0f;
        }
        else
        {
            D_4012E36C = 1.3333333f;
        }
    }
    else
    {
        if (progressive != 0)
        {
            D_4012E36C = 0.75f;
        }
        else
        {
            D_4012E36C = 1.0f;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", set_screen_wide_and_progressive);

void set_view_angle(CamScreen *s, f32 angle)
{
    s->viewAngle = angle;
}

/* NEARMISS-STUB set_scissor_screen_size */
#if 0 /* NEARMISS 74.0% cat=regalloc sub=- | target copies computed element ptr v0 into a0 (daddu a0,v0,0) before the two stores; C keeps it in one reg | attempts=1 */
void set_scissor_screen_size(CamScreen *s, s32 idx, s32 x, s32 y)
{
    s32 *p = (s32 *)((u8 *)s + 0x190 + idx * 4);

    p[0] = x;
    p[2] = y;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", set_scissor_screen_size);

s32 get_screen_width(CamScreen *s)
{
    return s->wide;
}

s32 get_screen_height(CamScreen *s)
{
    return s->height;
}

f32 get_aspect_ratio(CamScreen *s)
{
    return s->aspect * D_4012E36C / D_4012E370;
}

f32 get_view_angle(CamScreen *s)
{
    return s->viewAngle;
}

/* NEARMISS-STUB get_dist_from_eye_to_screen */
#if 0 /* NEARMISS 61.88% cat=stack-frame sub=- | target is frameless-looking tail call with sd ra/ld ra frame then j func_400F5E40; C gives frameless j | attempts=1 */
f32 get_dist_from_eye_to_screen(CamScreen *s)
{
    return func_400F5E40(s->height, s->viewAngle);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", get_dist_from_eye_to_screen);

f32 get_near_clip_z_clip_screen(void)
{
    return 0.05f;
}

f32 get_far_clip_z_clip_screen(void)
{
    return 65535.0f;
}

f32 get_z_buf_min_clip_screen(void)
{
    return 255.0f;
}

f32 get_z_buf_max_clip_screen(void)
{
    return 16700000.0f;
}

f32 iosGetTanf(f32 x);
void iosUnitMatrix(u8 *m);

/* NEARMISS-STUB create_original_clip_matrix */
#if 0 /* NEARMISS 77.96% cat=regalloc sub=- | fVar2 in f24 not f21 and int->float cvt.s.w hoisted above jal (target after jal); 0.5 mul placed after call | attempts=1 */
void create_original_clip_matrix(f32 fov, f32 aspect, f32 nearZ, f32 farZ, u8 *m)
{
    f32 *p = (f32 *)m;
    f32 k500 = 500.0f;
    s32 scaled;
    f32 fVar3;
    f32 fVar2;

    scaled = (s32)(aspect * 1000.0f);
    fVar2 = iosGetTanf(fov * 0.5f * 3.1415926f / 180.0f);
    fVar2 = (k500 / fVar2) / D_4012E36C;
    fVar3 = fVar2 / ((f32)scaled * 0.5f);
    fVar2 = (((fVar2 / k500) * D_4012E36C) / 0.90909f) / D_4012E370;
    iosUnitMatrix(m);
    p[0] = fVar3;
    p[0xB] = 1.0f;
    *(s32 *)&p[0xF] = 0;
    p[5] = fVar2;
    p[10] = (farZ + nearZ) / (farZ - nearZ);
    p[0xE] = (farZ * nearZ * -2.0f) / (farZ - nearZ);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", create_original_clip_matrix);

/* NEARMISS-STUB update_clip_screen */
#if 0 /* NEARMISS 80.71% cat=call-abi sub=- | float arg lwc1 f12 scheduled after jal in target; callee relocs to not-yet-C func_400F5E40/EC8 | attempts=1 */
void update_clip_screen(CamScreen *s)
{
    f32 angle;
    s32 h = s->height;
    f32 v = s->viewAngle;

    angle = func_400F5E40(h, v);
    func_400F5EC8(s, angle);
    func_400F5F80(s);
    func_400F5FD0(s, angle);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", update_clip_screen);

f32 iosGetTanf(f32 x);
void iosUnitMatrix(u8 *m);

void create_directX_projection_matrix(f32 fov, f32 aspect, f32 nearZ, f32 farZ, u8 *m)
{
    f32 *p = (f32 *)m;
    f32 sx;
    f32 sy;
    f32 farDiv;

    sx = 1.0f / iosGetTanf(fov * 0.5f * aspect * 3.1415926f / 180.0f);
    sy = 1.0f / iosGetTanf(fov * 0.5f * 3.1415926f / 180.0f);
    farDiv = farZ / (farZ - nearZ);
    iosUnitMatrix(m);
    p[0] = sx;
    p[0xB] = 1.0f;
    p[10] = farDiv;
    *(s32 *)&p[0xF] = 0;
    p[5] = sy;
    p[0xE] = -farDiv * nearZ;
}

s32 *get_screen_size_scale_screen_matrix(void)
{
    return &D_4012E374;
}

f32 iosGetTanf(f32 x);

f32 func_400F5E40(s32 height, f32 angle)
{
    f32 tanv = iosGetTanf(angle * 0.5f * 3.1415926f / 180.0f);

    return ((height * 0.5f) / tanv) / D_4012E36C;
}

void func_400F6080(u8 *p, f32 x, f32 y, f32 z, f32 nearZ, f32 farZ);

void func_400F5EC8(CamScreen *s, f32 v)
{
    func_400F6080((u8 *)s + 0x10, (f32)s->wide, (f32)s->height, v, 0.05f, 65535.0f);
    func_400F6080((u8 *)s + 0x50, 128.0f, 128.0f, v, 0.05f, 65535.0f);
    func_400F6080((u8 *)s + 0x90, 256.0f, 256.0f, v, 0.05f, 65535.0f);
}

void func_400F5F80(CamScreen *s)
{
    func_400F6180((u8 *)s + 0xD0, s->wide, s->height);
    func_400F6180((u8 *)s + 0x110, 0x80, 0x80);
    func_400F6180((u8 *)s + 0x150, 0x100, 0x100);
}

void func_400F5FD0(CamScreen *s, f32 v)
{
    s32 i;
    u8 *obj;
    s32 off;
    u8 *q;

    off = 0x190;
    q = (u8 *)s + 8;
    obj = (u8 *)s + 0x1A0;
    i = 1;
    do
    {
        i--;
        func_400F6080(obj, (f32)*(s32 *)((u8 *)s + off), (f32)*(s32 *)(q + off), v, 0.05f, 65535.0f);
        off += 4;
        obj += 0x40;
    } while (i >= 0);
}

void iosUnitMatrix(u8 *m);

void func_400F6080(u8 *p, f32 x, f32 y, f32 z, f32 nearZ, f32 farZ)
{
    f32 *m = (f32 *)p;
    f32 fVar1;
    f32 fVar2;

    fVar2 = z / (x * 0.5f);
    fVar1 = (((z / (y * 0.5f)) * D_4012E36C) / 0.90909f) / D_4012E370;
    iosUnitMatrix(p);
    m[0] = fVar2;
    m[0xB] = 1.0f;
    *(s32 *)&m[0xF] = 0;
    m[5] = fVar1;
    m[10] = (farZ + nearZ) / (farZ - nearZ);
    m[0xE] = (farZ * nearZ * -2.0f) / (farZ - nearZ);
}

/* NEARMISS-STUB func_400F6180 */
#if 0 /* NEARMISS 99.42% cat=regalloc sub=- | FP constants (2048/0xCAFED161/0x4AFED35F/1.0) assigned to different fpr than target; store order search best 99.42 | attempts=1 */
void func_400F6180(u8 *obj, s32 a, s32 b)
{
    f32 *m = (f32 *)obj;
    f32 fVar1;
    f32 fVar2;

    fVar2 = (f32)b * 0.5f * *(f32 *)&D_4012E374;
    fVar1 = (f32)a * 0.5f * *(f32 *)&D_4012E374;
    iosUnitMatrix(obj);
    m[0xD] = 2048.0f;
    m[0xC] = 2048.0f;
    m[5] = -fVar2;
    m[10] = -8349872.5f;
    m[0xE] = 8350127.5f;
    m[0] = fVar1;
    m[0xF] = 1.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0198_add_object_animation_camera_region", func_400F6180);
