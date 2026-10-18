#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", get_manage_obj_status_camera_place_status);

extern void GAMEUTIL_constructor_col_plane_info_filter(void *);
extern void func_400E1C40(void *);

void init_camera_place_status(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x10)) = -1;
    (*(int *)((char *)(arg0) + 0)) = 0;
    (*(int *)((char *)(arg0) + 4)) = 0;
    (*(int *)((char *)(arg0) + 8)) = 0;
    (*(int *)((char *)(arg0) + 0xC)) = 0;
    (*(int *)((char *)(arg0) + 0x14)) = 0;
    func_400E1C40(arg0);
    GAMEUTIL_constructor_col_plane_info_filter(arg0 + 0xD0);
    GAMEUTIL_constructor_col_plane_info_filter(arg0 + 0x150);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", doit_camera_place_status);

int get_place_status_camera_place_status(int *arg0)
{
    return *arg0;
}

int get_manage_obj_camera_place_status(void *arg0)
{
    return (*(int *)((char *)(arg0) + 4));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", get_mode_condition_segment_camera_place_status);

int get_hit_camera_region_camera_place_status(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0xC));
}

int GAMEUTIL_get_segment_num_and_data(int *num, u8 *lp);
u8 *GetLayoutClass(void *chara);

typedef struct {
    int type;
    void *obj;
    u8 pad8[4];
    u8 *mode;
} CutoutSrc;

int get_cutout_mode_manager_segment_camera_place_status(int *out, CutoutSrc *s)
{
    int n = 0;
    u8 **p;
    int t = s->type;

    *out = 0;
    if (t == 1) {
        n = GAMEUTIL_get_segment_num_and_data(out, *(u8 **)(s->mode + 0x14) + 0x1C);
    } else if (t == 2) {
        p = *(u8 ***)(GetLayoutClass(s->obj) + 0x1A8);
        if (p != 0 && *p != 0) {
            n = GAMEUTIL_get_segment_num_and_data(out, *p + 0x1C);
        }
    }
    return n;
}

typedef struct {
    int lo;
    int hi;
} __attribute__((aligned(8))) CamColAttr;

typedef struct {
    char pad0[8];
    int status;
    char padC[4];
    CamColAttr colAttr;
} CamPlaceStatus;

typedef struct {
    char pad0[0xD0];
    CamPlaceStatus placeStatus;
} CamRegion;

int get_cam_region_col_attr_camera_place_status(CamColAttr *attr, CamRegion *region)
{
    CamPlaceStatus *p = &region->placeStatus;

    *attr = p->colAttr;
    return p->status;
}

typedef struct {
    char pad0[0x150];
    CamPlaceStatus placeStatus;
} OnBossCamera;

int get_on_boss_camera_col_attr_camera_place_status(CamColAttr *attr, OnBossCamera *camera)
{
    CamPlaceStatus *p = &camera->placeStatus;

    *attr = p->colAttr;
    return p->status;
}

static inline int get_attr_kind(CamRegion *r, long *kind)
{
    CamPlaceStatus *p = &r->placeStatus;
    *kind = *(long *)&p->colAttr;
    if (p->status == 1)
    {
        *kind &= 0xF000L << 30;
        return 1;
    }
    return 0;
}

int is_approach_rise_ok_camera_place_status(CamRegion *r)
{
    long k;
    if (get_attr_kind(r, &k) == 1 && (k == (0xC000L << 28) || k == (0xC000L << 29)))
    {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", is_cliff_rise_ok_camera_place_status);

int act_local_vs_ofst_camera_place_status(CamRegion *r, char **o)
{
    long k;
    if (*(int *)(*o + 0x30) == 1) return 1;
    if (get_attr_kind(r, &k) == 1 && k == (0xA000L << 29)) return 1;
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", func_400E1C40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", func_400E1C58);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", CAM_doit_slope_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", func_400E1E98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0172_get_manage_obj_status_camera_place_statu", func_400E25E0);
