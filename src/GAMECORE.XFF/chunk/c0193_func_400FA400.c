#include "common.h"

/* GAMECORE c0193 PROVEN 100. Param-sheet table walk. KEY: output/source cells typed through union {float f; s32 a;} (float stores then alias tbl[] loads => the target reloads); plain float and s32 pointers give 30-55%. 8 args (a0-a3,t0-t2 + f12). */
typedef union { float f; s32 a; } UW410;

/* GAMECORE c0193 PROVEN 100. Entry = m->ents + idx*0x67C (m+4 = ents). KEY: access the float/int entry fields through a union {float f; s32 a;} ptr so the stores alias the reloaded m->ents (target reloads lw 4(m) per statement; plain float and s32 pointer stores get CSE'd = 70-82%); operand order 'off + ents' for the two stores, 'ents + off' for the call arg. */
extern void *get_best_mode_manager();
extern void func_400F6438();
typedef union { float f; s32 a; } UW;

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

void set_update_data_game_camera_param_update_data_manager(void *m, int idx, float f, s32 a, s32 b, s32 c)
{
    int off = idx * 0x67C;

    ((UW *)(off + *(s32 *)((u8 *)m + 4)))->f = f;
    ((UW *)(off + *(s32 *)((u8 *)m + 4) + 4))->a = a;
    func_400F6438(*(s32 *)((u8 *)m + 4) + off + 8, get_best_mode_manager(a, b, c));
}

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", get_mode_common_data_filter_base_dist_to_look_at);
float get_mode_common_data_filter_base_dist_to_look_at(CameraModeCommonData **mode)
{
    sceVu0FMATRIX m;
    float v[4];

    return (*mode)->filterBaseDist;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FAFA0);

/* GAMECORE c0193 PROVEN 100. Compare two camera-mode param blocks at +0x4C: nested ifs with direct 'return 1' and one trailing 'return 0' (early-return chain = 63%, result var r = 71%, the Ghidra literal r= chain = 81%). NOTE Ghidra misreads k==1: it returns 1. */
s32 func_400FB090(u8 *a, u8 *b)
{
    s32 k;

    if (b != 0)
    {
        a += 0x4C;
        b += 0x4C;
        k = *(s32 *)(a + 0xA0);
        if (k == *(s32 *)(b + 0xA0) && *(s32 *)(a + 0xBC) == *(s32 *)(b + 0xBC))
        {
            if (k == 1)
                return 1;
            if (*(s32 *)(a + 0xA4) == *(s32 *)(b + 0xA4) && (u32)(*(s32 *)(a + 0xA4) - 100) < 3)
            {
                if (k == 0 || k == 4 || k == 5 || k == 6)
                    return 1;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB130);

/* GAMECORE c0193 PROVEN 100. Picks the list entry (stride 0x67C) with the largest float at +0; outputs its +4 / +8 words. list[0]=count, list[1]=base ptr. */
void func_400FB300(s32 *o0, s32 *o1, s32 *list)
{
    s32 n = list[0];
    s32 a = 0;
    s32 b = 0;
    float best = -1.0f;

    if (n > 0)
    {
        float *p = (float *)list[1];

        do
        {
            n--;
            if (best < *p)
            {
                a = ((s32 *)p)[1];
                best = *p;
                b = ((s32 *)p)[2];
            }
            p = (float *)((u8 *)p + 0x67C);
        } while (n != 0);
    }
    *o0 = a;
    *o1 = b;
}

extern s32 DldSysUndefSymbol;
extern void fsEffectSetParamSheetSeg(void *);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB350);
void func_400FB350(void *arg0)
{
    u32 *h = *(u32 **)(*(char **)((char *)arg0 + 0x684) + 0x14);
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(char **)(t + 8) + 0xC) : 0;
    fsEffectSetParamSheetSeg(p + 0x1B0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0193_func_400FA400", func_400FB3D0);
void func_400FB3D0(s32 *p)
{
    *p = 0;
    if (p[1] != 0) {
        iosFree((void *)p[1]);
        p[1] = 0;
    }
}

void func_400FB410(float scale, UW410 *o0, s32 *o1, UW410 *o2, s32 *o3, s32 k, s32 dflt, s32 *tbl)
{
    if (k == 0)
    {
        o0->f = ((UW410 *)tbl[0])->f * scale;
        *o1 = tbl[0] + 8;
        o2->f = ((UW410 *)tbl[1])->f * scale;
        *o3 = tbl[1] + 8;
    }
    else
    {
        o0->f = 1.0f;
        *o1 = dflt;
        o2->f = ((UW410 *)tbl[k + 1])->f * scale;
        *o3 = tbl[k + 1] + 8;
    }
}
