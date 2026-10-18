#include "common.h"

extern u128 ZUnitVector;
extern u128 ZeroPoint;

void constructor_camera_target_lost_angle(void *param)
{
    f32 zero = 0.0f;

    *(s32*)((u8*)param + 0x0) = 0;
    *(u128*)((u8*)param + 0x10) = ZUnitVector;
    *(f32*)((u8*)param + 0x24) = zero;
    *(f32*)((u8*)param + 0x20) = zero;
    *(u128*)((u8*)param + 0x30) = ZeroPoint;
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E33F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E3428);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E34D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", func_400E36A0);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", set_parameter_camera_target_visible_angle_manager);

/* NEARMISS-STUB reset_camera_target_visible_angle_manager */
#if 0 /* NEARMISS 69.0% cat=cse-hoist sub=- | in-TU: ZeroPoint reload per store inside loop vs hoisted u128 load | attempts=1 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u128 p0;
    u128 p1;
} VisibleAngleEntry;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    VisibleAngleEntry entries[20];
    s32 active;
    f32 angle0;
    f32 angle1;
} VisibleAngleManager;

void reset_camera_target_visible_angle_manager(VisibleAngleManager *mgr)
{
    VisibleAngleEntry *entry;
    s32 i;

    mgr->count = 0;
    entry = mgr->entries;
    for (i = 19; i >= 0; i--) {
        entry->a = 0;
        entry->c = 0;
        entry->b = 0;
        entry->d = 0;
        entry->p0 = ZeroPoint;
        entry->p1 = ZeroPoint;
        entry++;
    }
    mgr->active = 0;
    mgr->angle0 = mgr->angle1 = 0.0f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0174_constructor_camera_target_lost_angle", reset_camera_target_visible_angle_manager);
