#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", bosslifebar_script);

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

typedef struct PlayerStatusDispEntry {
    f32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC;
} PlayerStatusDispEntry;

extern PlayerStatusDispEntry D_40218270[];

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", startGaugeMaxEffect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", startGaugeMaxAddEffect);

/* NEARMISS-STUB startAttackEffect */
#if 0 /* NEARMISS 99.0% cat=sched sub=- | in-TU: store order differs (target C,0,8,10,4; ours 4,0,C,10,8) | attempts=1 */
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
    D_402182C8.unkC = arg0;
    D_402182C8.unk8 = 0.5f;
    D_402182C8.unk10 = *(f32 *)(gcGlobalVar + 0x178);
    D_402182C8.unk4 = 0.5f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", startAttackEffect);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", playerlifebar_effect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", player_life_anim);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", spriteselweapon);

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

typedef struct BossLifeBarWork {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} BossLifeBarWork;

extern BossLifeBarWork D_40131CA8;
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", BossSprStatusBegin);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", BossSprStatusEnd);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE298);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE3D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE710);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CE968);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CEEC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CF0D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0152_bosslifebar_script", func_400CF2A8);
