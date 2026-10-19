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

extern int get_fast_get_malloc_partition(void);
extern int *initParticleObject(int, int);
extern int func_400D24E8(int, int, int, int, int, int);

int *create_and_boot_particle_geodisp(int a, int b, int c, int d, int e)
{
    int *obj = initParticleObject(get_fast_get_malloc_partition(), 0x1F3);

    if (obj != 0) {
        char *gd = (char *)GetGeoDispClass(obj);
        *(int *)(gd + 0xE8) = func_400D24E8(*obj, a, b, c, d, e);
    }
    return obj;
}

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

extern void func_400CC510(int);

void doit_particle_geodisp(int arg0)
{
    int temp_v0;

    if (arg0 != 0) {
        temp_v0 = GetGeoDispClass() + 0xE8;
    } else {
        temp_v0 = 0;
    }
    func_400CC510(temp_v0);
}

typedef union {
    u128 q;
    f32 f[4];
} PgdVec4;

extern int func_400D2588(int);
extern int func_400D25F8(int);
extern char *iosgluGetCameraContext(void);
extern void getZ(PgdVec4 *, PgdVec4 *, char *);
extern void SetGeoDispClassLightColMan(char *);

void clip_particle_geodisp(int obj)
{
    int *lst;
    int e;
    char *gd;
    PgdVec4 p;
    PgdVec4 z;

    if (obj != 0) {
        lst = (int *)((char *)GetGeoDispClass() + 0xE8);
    } else {
        lst = 0;
    }
    e = *lst;
    gd = (char *)GetGeoDispClass(obj);
    if (func_400D2588(e) == 1) {
        p.q = *(u128 *)(e + 0x20);
        p.f[3] = 0.0f;
        *(f32 *)(gd + 0x30) = 0.0f;
        getZ(&z, &p, iosgluGetCameraContext() + 0x1A0);
        *(f32 *)(gd + 0x28) = z.f[2];
        *(f32 *)(gd + 0x24) = z.f[1];
        *(f32 *)(gd + 0x20) = z.f[0];
        if (*(f32 *)(gd + 0x20) <= 0.0f) {
            *(f32 *)(gd + 0x20) = 0.01f;
        }
    } else {
        *(f32 *)(gd + 0x30) = -1.0f;
    }
}

void calc_light_particle_geodisp(int obj)
{
    char *gd = (char *)GetGeoDispClass(obj);
    int *lst;
    int e;

    if (obj != 0) {
        lst = (int *)((char *)GetGeoDispClass(obj) + 0xE8);
    } else {
        lst = 0;
    }
    e = *lst;
    if (func_400D25F8(e) == 1) {
        ((PgdVec4 *)(gd + 0x10))->q = ((PgdVec4 *)(e + 0x20))->q;
        *(u64 *)(gd + 0xC0) &= ~1;
        ((PgdVec4 *)(gd + 0x10))->f[3] = 1.0f;
        SetGeoDispClassLightColMan(gd);
    }
}

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
