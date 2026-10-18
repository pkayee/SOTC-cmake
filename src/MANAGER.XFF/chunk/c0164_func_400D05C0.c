#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", func_400D05C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", disp_particle_manager);

int get_top_emitter_list_from_particle_geodisp(int arg0)
{
    if (arg0 != 0) {
        return GetGeoDispClass() + 0xE8;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", create_and_boot_particle_geodisp);

extern void func_400CC1E8(int);
extern void isysRequestDeleteObj(int);

void check_free_particle_geodisp(int *arg0)
{
    int temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_400CC1E8(GetGeoDispClass(temp_v0) + 0xE8);
        isysRequestDeleteObj(*arg0);
        *arg0 = 0;
    }
}

extern void *GetGeoDispClass();
extern void isysRequestDeleteObj(int);

int auto_end_check_and_check_free_particle_geodisp(int *arg0)
{
    int temp_v0;

    temp_v0 = *arg0;
    if ((temp_v0 != 0) && ((*(int *)((char *)(GetGeoDispClass(temp_v0)) + 0xE8)) == 0)) {
        isysRequestDeleteObj(*arg0);
        *arg0 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", doit_particle_geodisp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", clip_particle_geodisp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", calc_light_particle_geodisp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0164_func_400D05C0", disp_particle_geodisp);

extern int func_400D20B8();
extern int get_main_particle_effect_lod_from_sheet(int);
extern void *get_top_particle_effect_from_lod(int);

int is_loop_particle(int arg0)
{
    if (arg0 != 0) {
        return (*(int *)((char *)(get_top_particle_effect_from_lod(get_main_particle_effect_lod_from_sheet(func_400D20B8()))) + 0x10)) == 1;
    }
    return 0;
}

extern int boot_particle_emitter_extend();

int boot_particle_emitter(int a, int b, int c, int d)
{
    return boot_particle_emitter_extend(a, b, c, d, 0);
}

extern int func_400D20C0();

int boot_particle_emitter_extend(int on, int a, int b, int c, int d)
{
    int r;
    if (on != 0) {
        r = func_400D20C0(func_400D20B8(on), a, b, c, d);
        if (r == 0)
            r = -1;
        return r;
    }
    return 0;
}

void *get_particle_emitter_from_emitter_id(s32 id);

int stop_particle_emitter_geometry_pointer_reference(void *a, int id)
{
    char *e = get_particle_emitter_from_emitter_id(id);

    if (e == 0) {
        return 0;
    }
    *(int *)(e + 0xC4) = 0;
    return 1;
}

int stop_particle_emitter_callback(void *a, int id)
{
    char *e = get_particle_emitter_from_emitter_id(id);

    if (e == 0) {
        return 0;
    }
    *(int *)(e + 0x158) = 0;
    return 1;
}

int set_generate_particle_flag(int a, int id, int flag)
{
    char *e = get_particle_emitter_from_emitter_id(id);

    if (e == 0) {
        return 0;
    }
    *(int *)(e + 0x168) = flag;
    return 1;
}

int set_npe_blend_ratio_particle_emitter(void *a, int id, float ratio)
{
    char *e = get_particle_emitter_from_emitter_id(id);

    if (e == 0) {
        return 0;
    }
    *(float *)(e + 0x16C) = ratio;
    return 1;
}
