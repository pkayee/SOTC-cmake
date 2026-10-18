#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0151_playerlifebar_script", playerlifebar_script);

typedef struct {
    int active;
    float x;
    float y;
    float scale;
    float size;
    float rot;
    int visible;
    float alpha;
} WeaponSprite;

extern WeaponSprite D_402182E8[9];
extern int D_40131C9C;
extern int D_40131CA0;

typedef struct {
    char pad0[0x178];
    float time;
} GlobalVar;

extern GlobalVar gcGlobalVar;
extern void func_400CA080(int);

static inline void setState(int i, int st)
{
    D_402182E8[i].active = st;
    D_402182E8[i].alpha = gcGlobalVar.time;
}

void initWeaponSpriteStatus(void)
{
    int i;

    for (i = 0; i < 9; i++) {
        WeaponSprite *s = &D_402182E8[i];

        s->active = 0;
        s->x = s->y = 0.0f;
        s->scale = 0.5f;
        s->size = 64.0f;
        s->rot = 0.0f;
        s->visible = 1;
        s->alpha = 0.0f;
    }
    D_40131C9C = -1;
    D_40131CA0 = -1;
}

void setWeaponSpriteStatus(int cur, int next)
{
    int c = cur - 1;

    D_40131C9C = c;
    D_40131CA0 = next - 1;
    if (D_402182E8[c].active != 2)
        setState(c, 1);
    if (D_40131CA0 != D_40131C9C && D_402182E8[D_40131CA0].active != 0)
        setState(D_40131CA0, 3);
    func_400CA080(2);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0151_playerlifebar_script", func_400CCF70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0151_playerlifebar_script", func_400CD1D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0151_playerlifebar_script", func_400CD468);
