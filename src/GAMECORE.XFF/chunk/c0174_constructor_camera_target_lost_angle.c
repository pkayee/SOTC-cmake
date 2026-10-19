#include "common.h"

extern u128 ZUnitVector;
typedef union {
    u128 q;
    f32 f[4];
} QVec;

extern QVec ZeroPoint;

void constructor_camera_target_lost_angle(void *param)
{
    *(s32*)((u8*)param + 0x0) = 0;
    *(u128*)((u8*)param + 0x10) = ZUnitVector;
    *(f32*)((u8*)param + 0x20) = *(f32*)((u8*)param + 0x24) = 0.0f;
    *(u128*)((u8*)param + 0x30) = ZeroPoint.q;
}

typedef struct
{
    union
    {
        s32 state;
        f32 f;
    } u;
    u8 pad4[0x1C];
    f32 yaw;
    f32 pitch;
} LostTarget;

extern void func_400E3900(f32 *, f32 *, LostTarget *, void *);

int get_yaw_pitch_camera_target_lost_angle(f32 *yaw, f32 *pitch, LostTarget *t, void *d, f32 y, f32 p)
{
    f32 tmp[4];

    *yaw = y;
    *pitch = p;
    if (t->u.state == 1)
    {
        func_400E3900(yaw, tmp, t, d);
        return 1;
    }
    if (t->u.state == 2)
    {
        *yaw = t->yaw;
        if (t->pitch < *pitch)
        {
            *pitch = t->pitch;
        }
        return 1;
    }
    return 0;
}

int get_attr_camera_target_lost_angle(int *arg0)
{
    return *arg0;
}

int is_exist_camera_target_lost_angle(int *arg0)
{
    return *arg0 != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E33F0);
int func_400E33F0(s32 *param)
{
    if (param[0] == 2 && *(f32*)((u8*)param + 0x24) <= -1.0471975f)
    {
        return 1;
    }
    return 0;
}

extern f32 GAMEUTIL_get_difference_yaw_and_yaw(f32, f32);
extern f32 GAMEUTIL_get_difference_pitch_and_pitch(f32, f32);

int func_400E3428(s32 *w, u8 *cam)
{
    if (w[0] != 0) {
        u8 *p = cam + 0x60;

        if (w[0] == 1) {
            if (GAMEUTIL_get_difference_yaw_and_yaw(*(f32 *)(p + 0x30), *(f32 *)&w[8]) <= 0.034906584f) {
                return 1;
            }
        } else if (GAMEUTIL_get_difference_yaw_and_yaw(*(f32 *)(p + 0x30), *(f32 *)&w[8]) <= 0.034906584f
                   && GAMEUTIL_get_difference_pitch_and_pitch(*(f32 *)(p + 0x34), *(f32 *)&w[9]) <= 0.034906584f) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E34D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E36A0);

/* NEARMISS-STUB func_400E36D0 */
#if 0 /* NEARMISS 96.55% cat=sched sub=- | d2 r103: clamp pitch to +-1.4835296f (0x3FBDE44C), stores *dir,*pitch,*yaw give the target s0=pitch/s1=yaw but store pitch first; target loads y,p and stores ya | attempts=1 */
extern s32 GAMEUTIL_check_and_get_normalize_vector(u128 *, s32, void *);
extern s32 GAMEUTIL_get_yaw_pitch_by_direction(f32 *, f32 *, u128 *);
extern void GAMEUTIL_get_direction_by_yaw_pitch(f32, f32, u128 *);

int func_400E36D0(f32 defYaw, u128 *dir, f32 *yaw, f32 *pitch, void *src)
{
    u128 v;
    f32 y;
    f32 p;

    if (GAMEUTIL_check_and_get_normalize_vector(&v, 0, src) == 1) {
        if (GAMEUTIL_get_yaw_pitch_by_direction(&y, &p, &v) == 0) {
            y = defYaw;
        }
        if (p > 1.4835296f) {
            p = 1.4835296f;
        }
        if (p < -1.4835296f) {
            p = -1.4835296f;
        }
        GAMEUTIL_get_direction_by_yaw_pitch(y, p, &v);
        *dir = v;
        *pitch = p;
        *yaw = y;
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E36D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E37C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E3900);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E3A68);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", begin_and_update_get_yaw_pitch_camera_target_visible_angle_manager);

int is_exist_camera_target_visible_angle(int *arg0)
{
    return *arg0;
}

extern void reset_camera_target_visible_angle_manager(void *);
extern void set_parameter_camera_target_visible_angle_manager(void *, int, f32, f32);

void constructor_camera_target_visible_angle_manager(void *p)
{
    reset_camera_target_visible_angle_manager(p);
    set_parameter_camera_target_visible_angle_manager(p, 0xF, 180.0f, 2.0f);
}

void set_parameter_camera_target_visible_angle_manager(void *p, int n, f32 deg, f32 t)
{
    u8 *w = p;
    f32 a;

    *(s32 *)(w + 0x3DC) = n;
    if (n / 2 * 2 == n - 1) {
        *(s32 *)(w + 0x3DC) = n + 1;
    }
    if (*(s32 *)(w + 0x3DC) > 20) {
        *(s32 *)(w + 0x3DC) = 20;
    }
    *(f32 *)(w + 0x3E4) = t;
    a = (deg * 3.14159253f) / 180.0f;
    *(f32 *)(w + 0x3E0) = a;
    *(f32 *)(w + 0x3E8) = a / (f32)*(s32 *)(w + 0x3DC);
}


typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    QVec p0;
    QVec p1;
} VisibleAngleEntry;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    VisibleAngleEntry entries[20];
    s32 active;
    f32 angle0;
    f32 angle1;
} VisibleAngleManager;

void reset_camera_target_visible_angle_manager(void *arg)
{
    VisibleAngleManager *mgr = arg;
    VisibleAngleEntry *entry;
    s32 i;

    mgr->count = 0;
    entry = mgr->entries;
    for (i = 19; i >= 0; i--) {
        entry->a = 0;
        entry->c = 0;
        entry->b = 0;
        entry->d = 0;
        entry->p0.q = ZeroPoint.q;
        entry->p1.q = ZeroPoint.q;
        entry++;
    }
    mgr->active = 0;
    mgr->angle0 = mgr->angle1 = 0.0f;
}
