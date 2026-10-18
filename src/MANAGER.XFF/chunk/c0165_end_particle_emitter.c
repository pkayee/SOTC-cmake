#include "common.h"

extern u8 D_401AD590[];
extern u8 D_4012B4E8[];
extern u8 D_4012B50C[];
extern s32 D_4012B560;
extern s32 D_4012B564;
extern s32 D_4012B570[];
extern u8 D_40134130[];
extern u8 D_40134140[];

void iosFree(void *p);

void *malloc_from_root_partition(s32 size, const char *name);
void *get_particle_emitter_from_emitter_id(s32 id);
void *get_main_particle_effect_lod_from_sheet(void *sheet);
void init_particle_effect_lod(void *lod);
void iosUnitMatrix(void *m);
void *iosgluGetCameraContext(void);
float GetScreenRadiusParticle(void *cam, float radius, float scale);
void texTransRequest(void *tex, s32 a1, s32 a2);
void func_400D37D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 func_400CCC28(void);

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

/* NEARMISS-STUB quit_particle_texture_user_by_id */
#if 0 /* NEARMISS 87.4% cat=regalloc sub=- | target uses a1 entry and v1 flag; mine a0/a1 swapped; sltiu scheduled before addu | attempts=1 */
void quit_particle_texture_user_by_id(u32 id)
{
    s32 off = id * 12;
    s32 *entry = (s32 *)((u8 *)g_ainParticleTextureStore + off);
    s32 flag = 1;

    if (id > 0x27 || *(s32 *)((u8 *)D_4012B570 + off) == 0)
    {
        flag = 0;
    }
    if (flag == 1)
    {
        entry[1] = entry[1] - 1;
        if (entry[1] <= 0)
        {
            entry[2] = 0;
            entry[1] = 0;
            entry[0] = (s32)g_sPtclNullName;
        }
    }
}
#endif
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

void *create_particle_effect_lod(void)
{
    u8 *p = malloc_from_root_partition(0x140, D_40134140);

    *(s32 *)(p + 0xD0) = 0;
    *(s32 *)(p + 0xD4) = 0;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    iosUnitMatrix(p + 0xE0);
    return p;
}

/* NEARMISS-STUB set_except_npe_file_data_to_particle_effect_lod */
#if 0 /* NEARMISS 44.0% cat=regalloc sub=- | loop-carried off/D4 pointer: target reloads D4 each iter (addu v0,a2,v0 then sw 8(v0)); ours strength-reduces to a2=D4+8; also regs a4/a5 vs t0/a2 | attempts=1 */
s32 set_except_npe_file_data_to_particle_effect_lod(u8 *lod, s32 a1, s32 a2, s32 a3)
{
    s32 i = 0;
    s32 off = 0;
    s32 count = *(s32 *)(lod + 0xD0);

    for (i = 0; i < count; i++)
    {
        *(s32 *)((u8 *)*(void **)(lod + 0xD4) + off + 8) = -1;
        count = *(s32 *)(lod + 0xD0);
        off += 0x1BC;
    }
    if (count < 1)
    {
        *(s32 *)(lod + 0xD8) = a3;
    }
    else
    {
        *(s32 *)(*(u8 **)(lod + 0xD4) + 8) = a1;
        *(s32 *)(lod + 0xD8) = a3;
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", set_except_npe_file_data_to_particle_effect_lod);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", init_particle_effect_lod);

s32 is_emitter_need_disp(void *e)
{
    if (e != NULL && *(s32 *)((u8 *)e + 0x124) > 0 && func_400CCC28() == 0 && *(float *)((u8 *)e + 0x140) > 0.0f)
    {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0165_end_particle_emitter", check_free_particle_effect_lod);

s32 recreate_particle_effects(void *arg0, s32 arg1)
{
    void *temp_v0;
    void *temp_v0_2;

    temp_v0_2 = *(void **)((u8 *)arg0 + 0xD4);
    if (temp_v0_2 != NULL)
    {
        iosFree(temp_v0_2);
    }
    *(s32 *)((u8 *)arg0 + 0xD0) = arg1;
    temp_v0 = malloc_from_root_partition(arg1 * 0x1BC, D_40134130);
    *(void **)((u8 *)arg0 + 0xD4) = temp_v0;
    return temp_v0 != NULL;
}

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
