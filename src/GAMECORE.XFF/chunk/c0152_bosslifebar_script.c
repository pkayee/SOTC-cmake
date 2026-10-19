#include "common.h"

typedef struct PlayerStatusDispEntry {
    f32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC;
} PlayerStatusDispEntry;

extern PlayerStatusDispEntry D_40218270[];

typedef struct BossLifeBarWork {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} BossLifeBarWork;

extern BossLifeBarWork D_40131CA8;

/* c0152 boss life bar script thread: bossStatBootChk takes NO args (a0=thread set once, bc1f delay slot); gcGlobalVar base re-materialised per iteration via a local pointer g. Run _prelude_patch.py FIRST (typedefs PlayerStatusDispEntry/BossLifeBarWork move above this function). ev_57940bd82ff09d160c99cf6dafa51fa40608c30c50343ef48c0edb28b3922429 */
/* c0152 boss life bar script thread: bossStatBootChk takes NO args (a0=thread set once, bc1f delay slot); gcGlobalVar base re-materialised per iteration via a local pointer g. Run _prelude_patch.py FIRST (typedefs PlayerStatusDispEntry and BossLifeBarWork move above this function). ev_57940bd82ff09d160c99cf6dafa51fa40608c30c50343ef48c0edb28b3922429 */
extern u8 gcGlobalVar[];
extern s32 D_40131C48;
extern s32 D_40131C4C;
extern s32 D_40131CB8;
void *isysGetThisSubThread(void);
u8 *GetSpriteMenuClass(void *thread);
void ScrSpriteParamSetup(void *sp, void *param);
f32 getDemoBarFade(void);
f32 getFadeValue(void);
s32 bossStatBootChk(void);
void SpriteMenuSetDispFlag(void *thread, s32 layer, s32 flag);
void func_400CD468(s32 a0, f32 f12);
void scrRun(void);

extern s32 SeList_sword_test;
extern s32 D_40131D58[];
s32 sePlay3D(s32 a, s32 pos, s32 b, s32 c);
void seSetVol(s32 handle, f32 vol);
void seStop(s32 handle);

extern s32 SParticleSheetData_S_GLOW;
extern s32 SParticleSheetData_S_AURA;
extern s32 SParticleSheetData_S_FLARE;
extern s32 SParticleSheetData_S_LINE;
extern s32 SParticleSheetData_S_LINE_BOSS;
typedef struct PtclSlot {
    s32 id;
    s32 emitter;
} PtclSlot;
extern PtclSlot D_40131DA8[];
extern s32 D_40131E00;
s32 get_particle_effect_id_from_sheet(s32 sheet);
s32 boot_particle_emitter(s32 id, void *mtx, void *cb, void *slot);
s32 get_particle_emitter_from_emitter_id(s32 id);
void *memset(void *p, int c, unsigned int n);
void func_400D2958(s32 *a0);

extern s32 D_40131CD0;
s32 is_loop_particle(s32 id);
void end_particle_emitter(s32 id, s32 emitter, s32 flag);

u8 *GetSpriteClass(void *thread);
void func_400CD1D0(u8 *spr);
s32 getDrawScreenHeight(void);

void bosslifebar_script(void *param)
{
    void *thread;
    u8 *cls;
    s32 w4;
    struct {
        s32 pad;
        s32 *mode;
    } sp;

    thread = isysGetThisSubThread();
    cls = GetSpriteMenuClass(thread);
    w4 = *(s32 *)(cls + 4);
    ScrSpriteParamSetup(&sp, param);
    while (*sp.mode != 0) {
        s32 i;
        u8 *g;

        if ((getDemoBarFade() != 1.0f || getFadeValue() != 0.0f) && D_40131C4C == 0) {
            for (i = 0; i < 4; i++) {
                D_40218270[i].unk4 = 0;
                D_40218270[i].unkC = 0;
                D_40218270[i].unk8 = 0.0f;
                D_40218270[i].unk0 = 0.0f;
            }
        }
        SpriteMenuSetDispFlag(thread, 0, D_40131C48 != 0 && D_40131CA8.unk8 > 0.0f && bossStatBootChk() == 1);
        g = gcGlobalVar;
        ((void (*)(f32, void *, s32, s32, s32))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x180), thread, 0, 0, 0);
        D_40131CB8 = 0;
        if (D_40131C48 != 0) {
            func_400CD468(w4, *(f32 *)(g + 0x180));
        }
        scrRun();
    }
}

extern s32 D_40131C48;

void setPlayerStatusSwitch(s32 arg0)
{
    D_40131C48 = arg0;
}

extern s32 D_40131C4C;

void setPlayerStatusDisableFadeCompareSwitch(s32 arg0)
{
    D_40131C4C = arg0;
}

extern void func_400CA080(s32 arg0);


void SetPlayerStatusDispSw(s32 arg0)
{
    s32 i;

    if (arg0 != 0) {
        func_400CA080(4);
        return;
    }
    for (i = 0; i < 4; i++) {
        if (D_40218270[i].unkC != 3) {
            D_40218270[i].unkC = 3;
            D_40218270[i].unk8 = -0.04999999888241291f;
            D_40218270[i].unk0 = 5.0f;
        }
    }
}

/* NEARMISS-STUB startGaugeMaxEffect */
#if 0 /* NEARMISS 60.67% cat=regalloc sub=- | float consts regalloc swapped (gcGlobal lwc1 wants f0, 0.5 wants f4); store order differs | attempts=1 */
extern u8 gcGlobalVar[];
typedef struct GaugeMaxEffectWork {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} GaugeMaxEffectWork;

extern GaugeMaxEffectWork D_402182B0;

void startGaugeMaxEffect(void)
{
    func_400CA080(4);
    D_402182B0.unk4 = 0.6f;
    D_402182B0.unk10 = *(f32 *)(gcGlobalVar + 0x178);
    D_402182B0.unk0 = 1;
    D_402182B0.unk8 = 0.5f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", startGaugeMaxEffect);

/* NEARMISS-STUB startGaugeMaxAddEffect */
#if 0 /* NEARMISS 60.67% cat=regalloc sub=- | float consts regalloc swapped (gcGlobal lwc1 wants f0, 0.5 wants f4); stores/ld ra scheduled differently | attempts=1 */
extern u8 gcGlobalVar[];

typedef struct GaugeMaxAddEffectWork {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} GaugeMaxAddEffectWork;

extern GaugeMaxAddEffectWork D_402182B0;

void startGaugeMaxAddEffect(void)
{
    func_400CA080(4);
    D_402182B0.unk4 = 0.6f;
    D_402182B0.unk10 = *(f32 *)(gcGlobalVar + 0x178);
    D_402182B0.unk0 = 1;
    D_402182B0.unk8 = 0.5f;
    return;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", startGaugeMaxAddEffect);

extern u8 gcGlobalVar[];

typedef struct StartAttackEffectWork {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} StartAttackEffectWork;

extern StartAttackEffectWork D_402182C8;

void startAttackEffect(f32 arg0)
{
    D_402182C8.unk0 = 1;
    D_402182C8.unk4 = 0.5f;
    D_402182C8.unk8 = 0.5f;
    D_402182C8.unk10 = *(f32 *)(gcGlobalVar + 0x178);
    D_402182C8.unkC = arg0;
}


extern u8 gcGlobalVar[];
extern s32 D_40131C54;
extern f32 D_40131C58;

typedef struct SetGripWork {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} SetGripWork;

extern SetGripWork D_40131C60;

void setgrip(f32 arg0)
{
    if (arg0 != D_40131C60.unk0) {
        if (arg0 < D_40131C60.unk0) {
            if (D_40131C54 == 0) {
                D_40131C58 = *(f32 *)(gcGlobalVar + 0x178);
            }
            D_40131C54 = 1;
        } else {
            D_40131C54 = 0;
        }
        D_40131C60.unk4 = D_40131C60.unk8;
        D_40131C60.unk0 = arg0;
        D_40131C60.unk8 = arg0;
        func_400CA080(0);
        return;
    }
    D_40131C60.unk4 = D_40131C60.unk8;
    D_40131C54 = 0;
    return;
}

/* NEARMISS-STUB playerlifebar_effect */
#if 0 /* NEARMISS 80.0% cat=branch-layout sub=- | ld ra restore scheduled right after jal, target puts it after lui/addiu | attempts=1 */
extern s32 D_40131C98;

void playerlifebar_effect(void)
{
    func_400CA080(4);
    D_40131C98 = 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", playerlifebar_effect);

extern s32 D_40131C98;
extern void setSpriteMenuAnimParam(u8 *spriteMenu, s32 a1, s32 a2, s32 a3, f32 f12);

void player_life_anim(s32 *arg0)
{
    if (D_40131C98 != 0) {
        return setSpriteMenuAnimParam((u8 *)arg0[2], 2, 0, 1, 0.0f);
    }
    return;
}

/* c0152 weapon sprite script: the tab pointer must be assigned INSIDE the loop (loop-invariant hoist puts lui in the beqz delay slot and keeps the full address in s3, lwc1 0x24(s3)); outside the loop or as sym+0x24 gives 92-96. Run _prelude_patch.py FIRST. */
/* c0152 weapon sprite script: the tab pointer must be assigned INSIDE the loop (loop-invariant hoist puts lui in the beqz delay slot and keeps the full address in s3, lwc1 0x24(s3)); outside the loop or as sym+0x24 gives 92-96. Run _prelude_patch.py FIRST. */
void spriteselweapon(void *param)
{
    void *thread;
    u8 *spr;
    u8 *tab;
    struct {
        s32 pad;
        s32 *mode;
    } sp;

    thread = isysGetThisSubThread();
    spr = GetSpriteClass(thread);
    ScrSpriteParamSetup(&sp, param);
    while (*sp.mode != 0) {
        func_400CD1D0(spr);
        tab = (u8 *)D_40218270;
        *(f32 *)(spr + 0x30) = *(f32 *)(tab + 0x24);
        if (D_40131C48 != 0) {
            *(f32 *)(spr + 0x18) = (f32)-((0x1C0 - getDrawScreenHeight()) >> 1);
            ((void (*)(void *, s32))(*(void **)(spr + 0x54)))(thread, -1);
        }
        scrRun();
    }
}

extern f32 D_40131CC0;
extern f32 D_40131CB0;

s32 bosslifebar_display(void)
{
    s32 var_v1;

    var_v1 = 0;
    if ((D_40131CC0 > 0.0f) || (D_40131CB0 > 0.0f)) {
        var_v1 = 1;
    }
    return var_v1;
}

extern f32 D_40131CBC;

void bosslifebar_resethp(f32 arg0, f32 arg1)
{
    BossLifeBarWork *bar = &D_40131CA8;
    f32 ratio = arg1 / arg0;

    bar->unkC = 0;
    D_40131CBC = arg0 * 0.01f;
    bar->unk8 = ratio;
    bar->unk4 = ratio;
    bar->unk0 = ratio;
}

extern s32 D_40131CB8;

typedef struct BossLifeBarHp {
    f32 cur;
    f32 prev;
    f32 last;
    f32 step;
} BossLifeBarHp;

void bosslifebar_sethp(f32 hp)
{
    BossLifeBarHp *b = (BossLifeBarHp *)&D_40131CA8;

    if (hp == b->cur) {
        return;
    }
    if (hp < b->cur) {
        D_40131CB8 = 1;
    }
    b->prev = b->last;
    b->cur = hp;
    b->step = 0.1f;
    func_400CA080(3);
}

extern void setSpriteMenuAnimParam(u8 *spriteMenu, s32 a1, s32 a2, s32 a3, f32 f12);

void boss_life_anim(s32 *arg0)
{
    if (D_40131CB8 != 0) {
        return setSpriteMenuAnimParam((u8 *)arg0[2], 2, 0, 1, 0.0f);
    }
    return;
}

extern s32 D_40131CC4;
extern s32 ScriptSpriteObjDef_SPRITE_WEAPON_SIGHT;
extern s32 ScriptSpriteObjDef_SPRITE_WEAPON;
extern s32 ScriptSpriteMenuObjDef_SPRITE_PLAYER_LIFE_LAYOUT;
extern void _SCRStartSpriteAnim(s32, s32, s32, s32, s32 *, s32);
extern void _SCRStartSpriteMenuAnim(s32, s32, s32, s32, s32 *, s32);

void PlayerSprStatusBegin(void)
{
    if (D_40131CC4 != 0) {
        return;
    }
    D_40131CC4 = 1;
    _SCRStartSpriteAnim(ScriptSpriteObjDef_SPRITE_WEAPON_SIGHT, 0, 0, 0, &D_40131CC4, 0);
    _SCRStartSpriteAnim(ScriptSpriteObjDef_SPRITE_WEAPON, 0, 0, 0, &D_40131CC4, 0);
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_PLAYER_LIFE_LAYOUT, 0, 0, 0, &D_40131CC4, 0);
}

void PlayerSprStatusEnd(void)
{
    D_40131CC4 = 0;
}

extern s32 D_40131CC8;
extern s32 ScriptSpriteMenuObjDef_SPRITE_BOSS_LIFE_LAYOUT;

void BossSprStatusBegin(void)
{
    if (D_40131CC8 != 0) {
        return;
    }
    D_40131CC8 = 1;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_BOSS_LIFE_LAYOUT, 0, 0, 0, &D_40131CC8, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", BossSprStatusEnd);
void BossSprStatusEnd(void)
{
    D_40131CC8 = 0;
}

/* c0152 sword-glow se handle toggler: D_40131D58 is an s32 array (pos, base, h1, h2); reference the global array directly (a local pointer p=D_40131D58 scores 72 and 64). */
void func_400CE298(s32 arg0, s32 arg1, s32 arg2)
{
    if (D_40131D58[1] == 0) {
        D_40131D58[0] = arg2;
        D_40131D58[1] = sePlay3D(SeList_sword_test, arg2, 0, 0);
    }
    if (arg0 != 0 && D_40131D58[2] == 0) {
        D_40131D58[2] = sePlay3D(arg0, arg2, 0, 0);
        seSetVol(D_40131D58[2], 0.0f);
    } else {
        if (D_40131D58[2] != 0) {
            seStop(D_40131D58[2]);
        }
        D_40131D58[2] = 0;
    }
    if (arg1 != 0 && D_40131D58[3] == 0) {
        D_40131D58[3] = sePlay3D(arg1, arg2, 0, 0);
        seSetVol(D_40131D58[3], 0.0f);
    } else {
        if (D_40131D58[3] != 0) {
            seStop(D_40131D58[3]);
        }
        D_40131D58[3] = 0;
    }
    seSetVol(D_40131D58[1], 0.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE3D8);

/* c0152 particle emitter start: the 11-entry sheet table is an s32 array INITIALIZER with eight separate boss ? LINE_BOSS : LINE ternaries (gcc builds it in a temp at sp+0x30 and copies with ldl/ldr); mtx[3] then mtx[7] store order. */
void func_400CE710(s32 boss)
{
    s32 sheets[11] = {
        SParticleSheetData_S_GLOW,
        SParticleSheetData_S_AURA,
        SParticleSheetData_S_FLARE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE
    };
    f32 mtx[16];
    s32 i;

    memset(mtx, 0, 0x40);
    mtx[3] = 1.0f;
    mtx[7] = 1.0f;
    for (i = 0; i < 11; i++) {
        if (D_40131DA8[i].id == 0) {
            s32 id = boot_particle_emitter(get_particle_effect_id_from_sheet(sheets[i]), mtx, func_400D2958, &D_40131DA8[i]);
            D_40131DA8[i].id = id;
            D_40131E00++;
            D_40131DA8[i].emitter = get_particle_emitter_from_emitter_id(id);
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE968);

/* c0152 particle emitter end: same initializer table; loop counts 11 slots (id, emitter) at D_40131DA8 stride 8. */
void func_400CEEC0(s32 boss)
{
    s32 sheets[11] = {
        SParticleSheetData_S_GLOW,
        SParticleSheetData_S_AURA,
        SParticleSheetData_S_FLARE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE,
        boss ? SParticleSheetData_S_LINE_BOSS : SParticleSheetData_S_LINE
    };
    s32 i;

    for (i = 0; i < 11; i++) {
        if (D_40131DA8[i].id != 0) {
            if (is_loop_particle(get_particle_effect_id_from_sheet(sheets[i])) != 0) {
                end_particle_emitter(get_particle_effect_id_from_sheet(sheets[i]), D_40131DA8[i].id, 0);
            }
        }
    }
    D_40131CD0 = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CF0D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CF2A8);
