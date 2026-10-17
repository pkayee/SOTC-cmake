#include "common.h"

extern u8 D_401AD590[];
extern u8 D_4012B4E8[];
extern u8 D_4012B50C[];
extern s32 D_4012B560;
extern s32 D_4012B564;
extern s32 D_4012B570[];

void *get_particle_emitter_from_emitter_id(s32 id);
void *get_main_particle_effect_lod_from_sheet(void *sheet);
void init_particle_effect_lod(void *lod);
void iosUnitMatrix(void *m);
void *iosgluGetCameraContext(void);
float GetScreenRadiusParticle(void *cam, float radius, float scale);
void texTransRequest(void *tex, s32 a1, s32 a2);
void func_400D37D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

s32 end_particle_emitter(s32 unused, s32 emitter_id, s32 flag)
{
    u8 *emitter = get_particle_emitter_from_emitter_id(emitter_id);

    if (emitter != NULL)
    {
        *(s32 *)(emitter + 0x114) = 1;
        if (flag == 1)
        {
            *(s32 *)(emitter + 0xC4) = 0;
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", get_particle_effect_id_by_name);

s32 get_particle_effect_id_from_sheet(s32 sheet_id)
{
    return sheet_id;
}

void *get_particle_name_from_effect_id(void *effect)
{
    void *name = NULL;

    if (effect != NULL)
    {
        name = *(void **)((u8 *)effect + 0x24);
    }
    return name;
}

s32 get_particle_camera_follow_attr_from_effect_id(void *effect)
{
    if (effect != NULL)
    {
        return *(s32 *)((u8 *)get_main_particle_effect_lod_from_sheet(effect) + 0xBC);
    }
    return -1;
}


void *get_particle_emitter_from_emitter_id(s32 id)
{
    u8 *emitter = (u8 *)id;

    if (emitter != NULL)
    {
        return emitter + 0x10;
    }
    return NULL;
}


void *get_main_particle_effect_lod_from_sheet(void *sheet)
{
    return *(void **)((u8 *)sheet + 0x48);
}

void *get_sub_particle_effect_lod_from_sheet(void *sheet)
{
    return *(void **)((u8 *)sheet + 0x4C);
}

void *get_top_particle_effect_from_lod(void *lod)
{
    return *(void **)((u8 *)lod + 0xD4);
}

void *get_particle_effect_from_lod(void *lod, s32 level)
{
    s32 off;

    off = (level << 3) - level;
    off = off << 4;
    off = off - level;
    off = off << 2;
    return (u8 *)*(void **)((u8 *)lod + 0xD4) + off;
}

void reinit_particle_effect_lod(void *lod)
{
    init_particle_effect_lod(lod);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", quit_particle_texture_user_by_id);

void set_particle_texture_by_id(s32 id)
{
    texTransRequest(D_4012B570[id * 3], 0, 0);
}

void *getPtclDisp(void)
{
    return D_4012B50C;
}

void *get_particle_printf_disp_level(void)
{
    return D_4012B4E8;
}

void *get_particle_camera_data(void)
{
    return D_401AD590;
}

s32 is_proper_particle_texture_id(u32 id)
{
    if (id < 0x28)
    {
        if (D_4012B570[id * 3] != 0)
        {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", create_particle_effect_lod);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", set_except_npe_file_data_to_particle_effect_lod);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", init_particle_effect_lod);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", is_emitter_need_disp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", check_free_particle_effect_lod);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", recreate_particle_effects);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", particleGWorkPut);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", get_polygon_scale_rotation_matrix);

float get_radiate_range_coefficient(float x)
{
    return (2.0f - x) * 0.5f;
}

void constructor_particle_effect_lod_except_npe(void *lod)
{
    *(s32 *)((u8 *)lod + 0xD0) = 0;
    *(s32 *)((u8 *)lod + 0xD4) = 0;
    *(s32 *)((u8 *)lod + 0xD8) = 0;
    *(s32 *)((u8 *)lod + 0xDC) = 0;
    iosUnitMatrix((u8 *)lod + 0xE0);
}

void add_particle_texture_user(void *a0)
{
    *(s32 *)((u8 *)a0 + 4) += 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", create_and_init_particle_effect_lod);

float get_particle_lod_base_size(void *particle)
{
    return GetScreenRadiusParticle(iosgluGetCameraContext(), *(float *)((u8 *)particle + 0x130), 1.0f);
}

void set_act_particle_lod_select_flag(s32 flag)
{
    D_4012B560 = flag;
}

void set_disp_particle_collisin_debug_flag(s32 flag)
{
    D_4012B564 = flag;
}

void get_world_matrixSR(s32 a0, s32 a1, s32 a2, s32 a3)
{
    func_400D37D0(a0, a2 + 0xE0, a1, a2, a3);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", radiate_particle_collision_check_ray);
