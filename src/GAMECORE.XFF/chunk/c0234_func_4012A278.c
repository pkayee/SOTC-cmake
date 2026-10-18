#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0234_func_4012A278", func_4012A278);

s32 getSizeBeardIKWork(void)
{
    return 0x3D0;
}

void initBeardIKWork(void *a, void *b, char *w)
{
    int i;
    char *p = w + 0x3B0;

    for (i = 9; i >= 0; i--) {
        *(int *)p = 0;
        p -= 0x60;
    }
}

void nico_BeardTest(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0234_func_4012A278", nico_Meet2Main);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0234_func_4012A278", func_4012AC10);

extern int GetCharacterClassInitParamNbOptionNodes();
extern void iosJumpRecoverPoint(void *);
extern unsigned char D_401378D0[];

s32 getSizeBuriesIKWork(void)
{
    s32 temp_v0;

    temp_v0 = GetCharacterClassInitParamNbOptionNodes();
    if (temp_v0 < 0) {
        iosJumpRecoverPoint(D_401378D0);
        return 0;
    }
    return (temp_v0 << 5) + 0x10;
}

typedef struct {
    char pad0[0x10];
    int a;
    int c;
    int b;
    char pad1C[4];
} BuriesIKNode;

typedef struct {
    int nodes;
    int n;
} BuriesIKWork;

extern int GetCharacterClassInitParamNbOptionNodes(void *);

void initBuriesIKWork(void *obj, void *param, BuriesIKWork *w)
{
    int i = 0;

    w->nodes = (int)(w + 2);
    w->n = GetCharacterClassInitParamNbOptionNodes(param);
    for (; i < w->n; i++) {
        ((BuriesIKNode *)w->nodes)[i].a = 0;
        ((BuriesIKNode *)w->nodes)[i].b = 0;
        ((BuriesIKNode *)w->nodes)[i].c = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0234_func_4012A278", func_4012AD18);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0234_func_4012A278", func_4012AF88);
