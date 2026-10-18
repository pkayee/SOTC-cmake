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

/* NEARMISS-STUB get_manage_object_id_camera_region */
#if 0 /* NEARMISS 80.7% cat=branch-layout sub=- | compiler folds flag into sltu; target keeps beqz/bnez flag branches with v1 reloaded | attempts=1 */
s32 get_manage_object_id_camera_region(void *a0)
{
    s32 bVar1;

    bVar1 = 0;
    if (a0 != 0)
    {
        if (*(s32 *)((u8 *)a0 + 0x14) != 0)
        {
            bVar1 = 1;
        }
        else
        {
            bVar1 = 0;
        }
    }
    if (bVar1)
    {
        return *(s32 *)((u8 *)*(s32 *)((u8 *)a0 + 0x14) + 4);
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_manage_object_id_camera_region);

/* NEARMISS-STUB is_parent_obj_boss_camera_region */
#if 0 /* NEARMISS 84.7% cat=branch-layout sub=- | compiler folds bnez/addiu-v1 flag diamond into sltu; target keeps flag branch, a0 reloaded into a0 | attempts=1 */
s32 is_parent_obj_boss_camera_region(void *a0)
{
    s32 bVar1;

    bVar1 = 0;
    if (a0 != 0)
    {
        if (*(s32 *)((u8 *)a0 + 0x14) != 0)
        {
            bVar1 = 1;
        }
        else
        {
            bVar1 = 0;
        }
    }
    if (bVar1 == 1)
    {
        a0 = *(void **)((u8 *)a0 + 0x14);
        if ((u32)(*(s32 *)((u8 *)a0 + 0x8) - 1) < 2)
        {
            return 1;
        }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", is_parent_obj_boss_camera_region);

/* NEARMISS-STUB get_priority_camera_region */
#if 0 /* NEARMISS 80.7% cat=branch-layout sub=- | compiler folds flag diamond into sltu; target keeps bnez/addiu-v1 flag branches | attempts=1 */
s32 get_priority_camera_region(void *a0)
{
    s32 bVar1;

    bVar1 = 0;
    if (a0 != 0)
    {
        if (*(s32 *)((u8 *)a0 + 0x14) != 0)
        {
            bVar1 = 1;
        }
    }
    if (bVar1)
    {
        return *(s32 *)(*(s32 *)((u8 *)a0 + 0x14) + 0x10);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_priority_camera_region);

/* NEARMISS-STUB get_change_grace_time_camera_region */
#if 0 /* NEARMISS 82.0% cat=branch-layout sub=- | compiler folds flag diamond into sltu; target keeps bnez/addiu-v1 flag branches | attempts=1 */
f32 get_change_grace_time_camera_region(void *a0)
{
    s32 bVar1;

    bVar1 = 0;
    if (a0 == 0)
    {
        goto done;
    }
    bVar1 = 1;
    if (*(s32 *)((u8 *)a0 + 0x14) == 0)
    {
        bVar1 = 0;
    }
done:
    if (bVar1)
    {
        return *(f32 *)((u8 *)*(s32 *)((u8 *)a0 + 0x14) + 0x18);
    }
    return 0.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_change_grace_time_camera_region);

/* NEARMISS-STUB get_hit_region_ofst_camera_region */
#if 0 /* NEARMISS 82.0% cat=branch-layout sub=- | compiler folds flag diamond into sltu; target keeps bnez/addiu-v1 flag branches with beqz v1 join | attempts=1 */
f32 get_hit_region_ofst_camera_region(void *a0)
{
    s32 bVar1;

    bVar1 = 0;
    if (a0 != 0 && (bVar1 = 1, *(s32 *)((u8 *)a0 + 0x14) == 0))
    {
        bVar1 = 0;
    }
    if (bVar1)
    {
        return *(f32 *)((u8 *)*(s32 *)((u8 *)a0 + 0x14) + 0x14);
    }
    return 0.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_hit_region_ofst_camera_region);

/* NEARMISS-STUB get_region_type_camera_region */
#if 0 /* NEARMISS 76.4% cat=branch-layout sub=- | compiler folds v0!=0 flag into sltu; target keeps bnez v0 with v1=1 in delay slot | attempts=1 */
s32 get_region_type_camera_region(void *a0)
{
    s32 bVar1;
    s32 ret;

    bVar1 = 0;
    if (a0 == 0)
    {
        goto join;
    }
    if (*(s32 *)((u8 *)a0 + 0x14) != 0)
    {
        bVar1 = 1;
        goto join;
    }
    bVar1 = 0;
join:
    ret = -1;
    if (bVar1)
    {
        ret = *(s32 *)a0;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0197_disp_camera_region", get_region_type_camera_region);

/* NEARMISS-STUB is_have_region_camera_region */
#if 0 /* NEARMISS 45.0% cat=branch-layout sub=- | compiler folds flag v1 into sltu; target keeps bnez/addiu-v1 flag branches and lw v0 reload | attempts=1 */
u8 *GetLayoutClass();
extern s32 GAMEUTIL_is_nearly_equal_zero3D(f32 eps, f32 *v);

s32 is_have_region_camera_region(void *a0)
{
    s32 v0;
    u8 *lc;

    if (a0 == 0)
    {
        goto zero;
    }
    if (*(s32 *)((u8 *)a0 + 0x14) == 0)
    {
        goto zero;
    }
    v0 = *(s32 *)a0;
    goto check;
zero:
    v0 = -1;
check:
    if (v0 != 0)
    {
        return 0;
    }
    lc = GetLayoutClass(*(s32 *)((u8 *)a0 + 0x10));
    if (GAMEUTIL_is_nearly_equal_zero3D(0.001f, (f32 *)(lc + 0x90)))
    {
        return 0;
    }
    return 1;
}
#endif
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
