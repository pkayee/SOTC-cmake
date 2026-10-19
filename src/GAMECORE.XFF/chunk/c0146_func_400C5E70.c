#include "common.h"

typedef struct {
    float p00;
    float p04;
    float p08;
    float p0C;
    float p10;
    float p14;
    float p18;
    float p1C;
    float p20;
    float p24;
    float p28;
    float p2C;
    float p30;
    float p34;
    float p38;
    float p3C;
    float p40;
    float p44;
    float p48;
    float p4C;
    float p50;
    float p54;
    float p58;
    float p5C;
    float p60;
    float p64;
    float p68;
    float p6C;
    float p70;
    float p74;
    float p78;
    float p7C;
    float p80;
    float p84;
    float p88;
    float p8C;
    float p90;
    float p94;
    float p98;
    float p9C;
    float pA0;
    float pA4;
} AIParam;
typedef struct {
    char pad0[0xC];
    int fC;
    char pad10[0x20];
    float f30;
    char pad34[0x30];
    int f64;
    char pad68[0x20];
    float f88;
    char pad8C[0x24];
    float fB0;
    char padB4[0x34];
    float fE8;
    char padEC[0x28];
    float f114;
    char pad118[0x8];
    float f120;
    char pad124[0x34];
    int f158;
    char pad15C[0x14];
    int f170;
    char pad174[0x4];
    int f178;
    int f17C;
    char pad180[0x4];
    int f184;
    float f188;
    float f18C;
    float f190;
    float f194;
    float f198;
    float f19C;
    char pad1A0[0x70];
    float f210;
    float f214;
    float f218;
    char pad21C[0x14];
    float f230;
    float f234;
    float f238;
    float f23C;
    char pad240[0x20];
    float f260;
    float f264;
    int f268;
    float f26C;
    char pad270[0x30];
    float f2A0;
    float f2A4;
    float f2A8;
    float f2AC;
    float f2B0;
    float f2B4;
    float f2B8;
    float f2BC;
    float f2C0;
    float f2C4;
    float f2C8;
    float f2CC;
    char pad2D0[0x18];
    float f2E8;
    float f2EC;
    float f2F0;
    char pad2F4[0x4];
    float f2F8;
    float f2FC;
    float f300;
} AIChr;
extern float iosGetRandom();

void func_400C5E70(AIChr *o)
{
    int k;
    float a;
    float b;
    float v;

    k = o->f158;
    if (k != 2 && k != 6 && k != 8 && k != 9 && k != 10 && k != 11 && k != 13)
        return;
    k = o->f17C;
    if (k == 0x1E || k == 0x1F) {
        o->f210 = -o->f210;
        o->f218 = -o->f218;
    } else if (k == 0x1C || k == 0x1D) {
        a = o->f218;
        b = o->f210;
        if (a < 0.0f)
            a = -a;
        o->f210 = a;
        if (k == 0x1C)
            o->f218 = -b;
        else
            o->f218 = b;
    }
    o->f214 = 0.0f;
    v = o->f210;
    o->f264 = ((v < o->f214) ? -v : v) / ((AIParam *)o->f64)->p14
            + ((v < 0.0f) ? -v : v) * ((AIParam *)o->f64)->p30;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C5F98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6240);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6930);

int AI_UpdateVelocity(float *vel, float target, float accel);

static inline void aiFlyVelocity(AIChr *o, float v)
{
    float *vel = &o->f26C;
    float t = o->f18C;

    if (t <= o->f188)
        *vel = o->f2AC + o->f2A4 * 0.16666666f * t * t * t + o->f2A8 * 0.5f * t * t;
    else
        AI_UpdateVelocity(vel, v, ((AIParam *)o->f64)->p5C);
}

void func_400C6B60(AIChr *o, int a, int b)
{
    float v = o->f2A0;

    if (a == 0x13) {
        if (b == 0x11) {
            aiFlyVelocity(o, v);
        } else if (b == 0x12) {
            aiFlyVelocity(o, -v);
        }
    } else if (a == 0x14) {
        if (b == 0x11) {
            aiFlyVelocity(o, -v);
        } else if (b == 0x12) {
            aiFlyVelocity(o, v);
        }
    }
    return;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6CB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6F08);

/* NEARMISS-STUB func_400C70B8 */
#if 0 /* NEARMISS 98.0% cat=sched sub=- | only lw o->f64 hoisted above sw zero,0x184 (target keeps source order: store, store, then param load) | attempts=1 */
int AI_UpdateVelocity(float *vel, float target, float accel);

void func_400C70B8(AIChr *o)
{
    float t;

    o->f184 = 0;
    o->f260 = 1.0f;
    AI_UpdateVelocity(&o->f264, 1.0f, ((AIParam *)o->f64)->p20);
    o->f230 = 0.0f;
    t = o->f18C;
    if (t <= ((AIParam *)o->f64)->pA4) {
        o->f210 = o->f2F0 + o->f2E8 * 0.5f * t * t + o->f2EC * t;
    } else {
        AI_UpdateVelocity(&o->f210, o->f230, 1.0f);
    }
    AI_UpdateVelocity(&o->f238, ((AIParam *)o->f64)->p40, ((AIParam *)o->f64)->p3C);
    AI_UpdateVelocity(&o->f218, 0.0f, o->f238);
    AI_UpdateVelocity(&o->f23C, 0.0f, ((AIParam *)o->f64)->p44);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C70B8);

int AI_UpdateVelocity(float *vel, float target, float accel);

void func_400C71A8(AIChr *o)
{
    AI_UpdateVelocity(&o->f23C, 0.0f, ((AIParam *)o->f64)->p44);
    o->f260 = ((AIParam *)o->f64)->pA0;
    AI_UpdateVelocity(&o->f264, o->f260, ((AIParam *)o->f64)->p9C);
    {
        float r = o->f260;
        AIParam *p = (AIParam *)o->f64;
        o->f230 = p->p14 * r;
        AI_UpdateVelocity(&o->f234, p->p94, p->p98);
    }
    AI_UpdateVelocity(&o->f210, o->f230, o->f234);
    AI_UpdateVelocity(&o->f238, ((AIParam *)o->f64)->p40, ((AIParam *)o->f64)->p3C);
    AI_UpdateVelocity(&o->f218, 0.0f, o->f238);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C7270);

int func_400C7408(AIChr *o)
{
    int k;
    int far;
    int low;
    float r;

    far = (o->f114 <= o->f30 * 0.8f);
    if (!far) {
        far = (o->f120 < -0.98480768f);
    } else {
        far = 0;
    }
    if (far) {
        k = 0x11;
        if (!(0.0f <= o->fE8)) {
            k = 0x12;
        }
        low = o->f120 < -0.2f;
        if (low) {
            return (k == 0x11) ? 0x1E : 0x1F;
        }
    } else if (far = (o->f114 <= o->f30 * 0.8f), !far) {
        k = 0x12;
        if (0.0f <= o->fE8) {
            k = 0x11;
        }
    } else {
        r = iosGetRandom();
        k = o->f170;
        if (o->f190 < o->f194) {
            if (r < 0.5f) {
                k = 0x11;
            } else if (r < 1.0f) {
                k = 0x12;
            } else {
                k = 0x10;
            }
        }
    }
    return (k == 0x11) ? 0x1C : 0x1D;
}

/* NEARMISS-STUB func_400C7578 */
#if 0 /* NEARMISS 95.85% cat=branch-layout sub=- | last k==0x18 test if-converted to movn (target bnel v0=0x1A / b v0=0x1F); up flag v1 vs v0. switch = binary tree 89.7, r-var chain 93.4 | attempts=1 */
void *isysGetThisSubThread(void);

int func_400C7578(AIChr *o)
{
    int k;
    int near;
    int up;

    isysGetThisSubThread();
    near = (o->f114 <= o->f30 * 0.79999998f);
    if (near) {
        if (o->fB0 < 8.0f) {
            k = 0x15;
            if (0.0f <= o->f88) {
                k = 0x16;
            }
        } else {
            k = 0x16;
            if (!(0.0f <= o->f88)) {
                k = 0x15;
            }
        }
        if (k == 0x15) {
            return 0x1C;
        }
        if (k == 0x16) {
            return 0x1D;
        }
        if (k == 0x17) {
            return 0x1E;
        }
        if (k == 0x18) {
            return 0x1F;
        }
        return 0x1A;
    }
    up = (0.70710665f <= o->f120);
    if (up) {
        return 0x1A;
    }
    return func_400C7408(o);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C7578);
