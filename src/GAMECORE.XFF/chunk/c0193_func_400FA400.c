#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FA400);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", get_game_camera_mode_local_parameter);

extern void func_400F5D68(void *);

void constructor_game_camera_param_manager(void *arg0)
{
    (*(int *)((char *)(arg0) + 0)) = 0;
    (*(int *)((char *)(arg0) + 4)) = 0;
    (*(int *)((char *)(arg0) + 8)) = 0;
    (*(int *)((char *)(arg0) + 0xC)) = 0;
    func_400F5D68(arg0 + 0x10);
    func_400F5D68(arg0 + 0x684);
    func_400F5D68(arg0 + 0xCF8);
    (*(int *)((char *)(arg0) + 0x136C)) = 0;
}

int get_cur_base_mode_condition_game_camera_param_manager(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x136C));
}

int get_cur_base_mode_manager_game_camera_param_manager(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x684));
}

int is_base_mode_manager_update_game_camera_param_manager(int *arg0)
{
    return *arg0;
}

int get_interp_game_camera_param_game_camera_param_manager(int arg0)
{
    return arg0 + 0xCF8;
}

typedef struct {
    char pad0[0x20];
    float interpTime;
    char pad24[0x690 - 0x24];
    float defaultInterpTime;
} CameraParamManager;

float get_interp_time_game_camera_param_manager(CameraParamManager *manager)
{
    if (manager->interpTime < 0.0f) {
        return manager->defaultInterpTime;
    }
    return manager->interpTime;
}

extern float CAM_get_interp_ratio_by_time(int, float, float, float, float);

float get_interp_ratio_game_camera_param_manager(char *m)
{
    float t = *(float *)(m + 0x20);

    return CAM_get_interp_ratio_by_time(1, t < 0.0f ? *(float *)(m + 0x68C) : 1.0f, *(float *)(m + 0x4),
                                        t < 0.0f ? *(float *)(m + 0x690) : t, 0.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", is_base_default_dir_attr_change_game_camera_param_manager);

int act_camera_cutout_game_camera_param_manager(int *param, char *camera)
{
    int mode = param[2];

    if (mode == 1 && *(int *)(camera + 0x13C0) == mode) {
        return 1;
    }
    return 0;
}

void drop_camera_cutout_flag_game_camera_param_manager(void *arg0)
{
    (*(int *)((char *)(arg0) + 8)) = 0;
}

void constructor_game_camera_param_update_data_manager(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
}

extern s32 rootPtn;
extern void iosFree(void *p);
extern void *iosMallocAlign(s32, s32, s32);

typedef struct {
    int num;
    char *ents;
} UpdManager;

void reset_game_camera_param_update_data_manager(UpdManager *m, int n)
{
    int i;
    char *e;

    m->num = 0;
    if (m->ents != 0) {
        iosFree(m->ents);
        m->ents = 0;
    }
    m->num = n;
    m->ents = iosMallocAlign((s32)&rootPtn, n * 0x67C, 0x10);
    for (i = 0; i < n; i++) {
        e = (char *)(i * 0x67C + (int)m->ents);
        *(int *)(e + 0) = 0;
        *(int *)(e + 4) = 0;
        func_400F5D68(e + 8);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", set_update_data_game_camera_param_update_data_manager);

int is_already_set_game_camera_param_update_data_manager(void *arg0, int arg1)
{
    return (*(int *)((char *)(((arg1 * 0x67C) + (*(int *)((char *)(arg0) + 4)))) + 4)) != 0;
}

typedef struct {
    int unk0[8];
    float dist;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float fov;
    float unk40;
} CameraModeLocal;

void constructor_game_camera_mode_local_parameter(CameraModeLocal *p)
{
    p->unk0[0] = 0;
    p->unk0[1] = 0;
    p->unk0[2] = 0;
    p->unk0[3] = 0;
    p->unk0[4] = 0;
    p->unk0[5] = 0;
    p->unk0[6] = 0;
    p->unk0[7] = 0;
    p->dist = 4.5f;
    p->unk24 = 2.0f;
    p->unk28 = 2.0f;
    p->unk2C = 2.0f;
    p->unk30 = 0.5f;
    p->unk34 = 0.5f;
    p->unk38 = 0.5f;
    p->fov = 45.0f;
    p->unk40 = 1.0f;
}

typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

typedef struct {
    char pad0[0x170];
    float filterBaseDist;
} CameraModeCommonData;

/* NEARMISS-STUB get_mode_common_data_filter_base_dist_to_look_at */
#if 0 /* NEARMISS 99.6% cat=stack-frame sub=- | in-TU: frame -0x40 vs exp -0x50 (16 B extra local only a dummy gives) | attempts=1 */

typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

typedef struct {
    char pad0[0x170];
    float filterBaseDist;
} CameraModeCommonData;

float get_mode_common_data_filter_base_dist_to_look_at(CameraModeCommonData **mode)
{
    sceVu0FMATRIX unused;

    return (*mode)->filterBaseDist;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", get_mode_common_data_filter_base_dist_to_look_at);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FAFA0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB090);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB130);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB300);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB350);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB3D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB410);
