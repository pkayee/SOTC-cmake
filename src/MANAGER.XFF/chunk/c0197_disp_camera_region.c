#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", disp_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", constructor_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", create_and_init_camera_region);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_manage_object_id_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", is_parent_obj_boss_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_priority_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_change_grace_time_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_hit_region_ofst_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_region_type_camera_region);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", is_have_region_camera_region);

/* NEARMISS-STUB func_400F4F00 */
#if 0 /* NEARMISS 32.3% cat=sched sub=- | compiler schedules p[4] store before sd; target has sd before jr and p[4] in delay slot | attempts=2 */
void func_400F4F00(s32 *p, s32 a1, s32 a2, s64 a3, s32 a4, s32 a5)
{
    p[0] = a1;
    p[1] = a2;
    p[5] = a5;
    *(s64 *)(p + 2) = a3;
    p[4] = a4;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", func_400F4F00);

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
