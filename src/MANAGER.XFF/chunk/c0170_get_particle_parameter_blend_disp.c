#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", get_particle_parameter_blend_disp);

//INCLUDE_ASM(...);
void *func_400D7598(s32 p0, u8 *p1, s32 p2, s32 p3)
{
    s32 n = *(s32 *)(p1 + 0xD0);

    if (n - 1 < p3)
    {
        return (void *)(*(s32 *)(p1 + 0xD4) + n * 0x1BC - 0x1BC);
    }
    return (void *)(*(s32 *)(p1 + 0xD4) + p3 * 0x1BC);
}

//INCLUDE_ASM(...);
void func_400D75F8(float p0, float *p1, float *p2)
{
    if (p0 < 0.0f)
    {
        *p1 = p0 + 1.0f;
        *p2 = 0.0f;
        return;
    }
    if (p0 < 1.0f)
    {
        *p1 = 1.0f - p0;
        *p2 = p0;
        return;
    }
    *p1 = 0.0f;
    *p2 = p0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", func_400D7650);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", func_400D78A0);

//INCLUDE_ASM(...);
void *dynamic_cast_to_wind_emitter_sphere(int *emitter)
{
    if (emitter == 0 || *emitter != 0) {
        return 0;
    }
    return emitter;
}

//INCLUDE_ASM(...);
int *dynamic_cast_to_wind_emitter_box(int *p)
{
    if (p != 0 && *p == 1) {
        return p;
    }
    return 0;
}

//INCLUDE_ASM(...);
int *dynamic_cast_to_wind_emitter_judge_volume(int *p)
{
    if (p != 0 && *p == 2) {
        return p;
    }
    return 0;
}

extern char D_401AD640[], D_401AD780[];
extern char *g_asWindEffectDataName[50];
extern char D_4012BA68[];
extern void *memset(void *, int, unsigned int);

//INCLUDE_ASM(...);
void init_wind_manager(void)
{
    int i;
    char **p;
    memset(D_401AD640, 0, 0x140);
    memset(D_401AD780, 0, 0xC8);
    p = g_asWindEffectDataName;
    for (i = 49; i >= 0; i--)
        p[i] = D_4012BA68;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", doit_wind_manager);

extern s32 DldSysUndefSymbol;
extern int strcmp(const char *, const char *);

static inline u8 *dldRef_c0170(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

u8 *get_wind_effect_data(u32 *lp, const char *name)
{
    s32 i;
    s32 cnt;
    u8 *p;

    if (lp != NULL) {
        cnt = (s32)dldRef_c0170(lp, 0xC);
        p = dldRef_c0170(lp, 0x10);
        for (i = 0; i < cnt; i++) {
            if (strcmp(*(const char **)(p + i * 0x18 + 0x14), name) == 0) {
                return p + i * 0x18;
            }
        }
    }
    return NULL;
}

int is_eternal_wind(void *arg0)
{
    int var_v0;

    var_v0 = 1;
    if (!((*(float *)((char *)(arg0) + 0xC)) < 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", boot_wind_emitter);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", boot_wind_emitter_by_box);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0170_get_particle_parameter_blend_disp", boot_wind_emitter_by_judge_volume);
