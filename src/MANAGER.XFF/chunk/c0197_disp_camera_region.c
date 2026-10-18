#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", disp_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", constructor_camera_region);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", create_and_init_camera_region);
void *iosMallocAlign(void *, s32, s32);
extern void func_400F4F00(void *, s32, s32, s32, s32, s32);

void *create_and_init_camera_region(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, void *a5)
{
    void *p;

    p = iosMallocAlign(a5, 0x30, 0x10);
    func_400F4F00(p, a0, a1, a2, a3, a4);
    return p;
}

extern void iosFree(void *);

void check_free_camera_region(void **arg0)
{
    void *temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0)
    {
        iosFree(temp_v0);
        *arg0 = 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", doit_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", is_clear_camera_region_condition);

typedef struct {
    s32 pad0;
    s32 manageObjId;
    s32 parentKind;
    s32 padC;
    s32 priority;
    f32 hitRegionOfst;
    f32 changeGraceTime;
} CameraRegionDef;

typedef struct {
    s32 regionType;
    s32 pad4[3];
    void *layout;
    CameraRegionDef *def;
} CameraRegion;

static inline s32 isValidCameraRegion(CameraRegion *r)
{
    if (r != 0 && r->def != 0) {
        return 1;
    }
    return 0;
}

s32 get_manage_object_id_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r)) {
        return r->def->manageObjId;
    }
    return -1;
}

s32 is_parent_obj_boss_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r) == 1) {
        if (r->def->parentKind == 1 || r->def->parentKind == 2) {
            return 1;
        }
    }
    return 0;
}

s32 get_priority_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r)) {
        return r->def->priority;
    }
    return 0;
}

f32 get_change_grace_time_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r)) {
        return r->def->changeGraceTime;
    }
    return 0.0f;
}

f32 get_hit_region_ofst_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r)) {
        return r->def->hitRegionOfst;
    }
    return 0.0f;
}

s32 get_region_type_camera_region(CameraRegion *r)
{
    if (isValidCameraRegion(r)) {
        return r->regionType;
    }
    return -1;
}

u8 *GetLayoutClass();
extern s32 GAMEUTIL_is_nearly_equal_zero3D(f32 eps, f32 *v);

s32 is_have_region_camera_region(CameraRegion *r)
{
    s32 type;

    if (isValidCameraRegion(r)) {
        type = r->regionType;
    } else {
        type = -1;
    }
    if (type == 0 && !GAMEUTIL_is_nearly_equal_zero3D(0.001f, (f32 *)(GetLayoutClass(r->layout) + 0x90))) {
        return 1;
    }
    return 0;
}

void func_400F4F00(void *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    ((s32 *)p)[0] = a1;
    ((s32 *)p)[1] = a2;
    *(s64 *)((s32 *)p + 2) = a3;
    ((s32 *)p)[4] = a4;
    ((s32 *)p)[5] = a5;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", init_col_attr_table_segment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", is_this_camera_region_alive);

extern char D_401C1E60[];
extern void *memset(void *, int, unsigned int);

void init_camera_region_manager(void)
{
    memset(D_401C1E60, 0, 0xC8);
}

extern void doit_camera_region(void *, void *, float);

void doit_camera_region_manager(void *actor, float interval)
{
    void **entry;
    void *region;
    int remaining;

    remaining = 0x31;
    entry = (void **)D_401C1E60;
    do
    {
        region = *entry;
        entry++;
        if (region != 0)
        {
            doit_camera_region(region, actor, interval);
        }
        remaining--;
    } while (remaining >= 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_camera_region_resource_id_by_name);
