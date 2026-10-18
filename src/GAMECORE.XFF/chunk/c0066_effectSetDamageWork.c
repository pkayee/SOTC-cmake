#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effectSetDamageWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_blood_init);

extern void iosFree(void *);

void effect_blood_free(void *allocation)
{
    iosFree(allocation);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_blood_frame);

extern u8 D_40203290[];
extern float D_401315D0;
extern u8 *GetCharacterClass(void *chara);
extern s32 *GetDamageClass(void *obj);
extern void GetGeometryPointerPosition(float *, void *);
extern void func_4005FAF8(void *, u8 *, s32, float *, s32, s32, float, float);

void effect_blood_set(void *obj, void *target, float scale)
{
    char *c = GetCharacterClass(obj);
    float pos[4] __attribute__((aligned(16)));

    if (*GetDamageClass(obj) == 3) {
        int **m;

        GetGeometryPointerPosition(pos, D_40203290);
        m = *(int ***)(c + 0x144);
        func_4005FAF8(target, c, *(int *)((char *)m[0] + 0x20), pos, *(int *)((char *)m[3] + 0x104),
                      *(short *)(c + 0x1B4), D_401315D0, scale);
    }
}

extern int D_40131770[];
extern void createParamMenu(void *, int);

void createBossBloodParamMenu(void)
{
    if (D_40131770[12] == 0)
        createParamMenu(D_40131770, 0);
}

int getEffectBloodWorkSize(int arg0)
{
    return (arg0 * 0x30) + 0x33;
}

typedef struct
{
    float v;
    u8 pad[0x74];
} WeakPointEffect;

extern WeakPointEffect D_402032E4[];

float getWeakPointEffectIntensity(int i)
{
    return D_402032E4[i].v;
}

float getTriggerPointEffectIntensity(int index)
{
    index += 3;
    return D_402032E4[index].v;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", boot_weakpoint_effect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", boot_weakpoint_hit_effect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", init_weakpoint_effect);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", fadeout_weakpoint_effect);
extern s32 D_402032D0[];

void fadeout_weakpoint_effect(void)
{
    s32 two = 2;
    s32 *p = D_402032D0;
    s32 i = 7;

    do {
        i--;
        p[4] = 0;
        p[1] = two;
        p += 0x1E;
    } while (i >= 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", end_weakpoint_effect);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_death);
extern u8 *GetLayoutClass();
extern void func_40060A68(u8 *, s32, float *, s32, s16);

void effect_death(void)
{
    float pos[4] __attribute__((aligned(16)));
    u8 *c = GetLayoutClass();
    int **m;

    GetGeometryPointerPosition(pos, D_40203290);
    m = *(int ***)(c + 0x144);
    func_40060A68(c, *(int *)((char *)m[0] + 0x20), pos, *(int *)((char *)m[3] + 0x104), *(short *)(c + 0x1B4));
    return;
}

extern int D_40203288;

void effectClearDamageWork(void)
{
    D_40203288 = 0;
}

extern unsigned char D_40202FE0[];

int effectGetDamageWork(void **arg0)
{
    *arg0 = D_40202FE0;
    return (*(int *)((char *)(D_40202FE0) + 0x2A8));
}

extern unsigned char D_401315F4[];

void *getBloodEffectEnableFlag(void)
{
    return D_401315F4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061720);
extern unsigned char D_401315E0[];

void *func_40061720(void)
{
    return D_401315E0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061730);
extern unsigned char D_401315E4[];

void *func_40061730(void)
{
    return D_401315E4;
}

extern unsigned char D_401315E8[];

void *func_40061740(void)
{
    return D_401315E8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061750);
void *func_40061750(void)
{
    return &D_401315D0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061760);
extern unsigned char D_401315D4[];

void *func_40061760(void)
{
    return D_401315D4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061770);
extern unsigned char D_401315D8[];

void *func_40061770(void)
{
    return D_401315D8;
}

extern unsigned char D_401317A4[];

void *getWeakGlowSpeed(void)
{
    return D_401317A4;
}

extern unsigned char D_401317A8[];

void *getWeakGlowTime(void)
{
    return D_401317A8;
}

extern unsigned char D_401317AC[];

void *getTrigGlowTime(void)
{
    return D_401317AC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400617B0);
void func_400617B0(u8 *p)
{
    u8 *v = *(u8 **)(p + 0x50);

    *(float *)(p + 0x28) = *(float *)(p + 0x28) * *(float *)(v + 0x70);
    *(float *)(p + 0x24) = *(float *)(p + 0x24) * (*(float *)(v + 0x74) * *(float *)(v + 0x14));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400617E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061888);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400619D8);
void func_400619D8(u8 *p)
{
    p += 0x5C;
    if (*(s32 *)p != 0) {
        *(s32 *)p = 0;
        *(s32 *)(p + 0x4) = 0;
        *(s32 *)(p + 0x8) = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061A00);
