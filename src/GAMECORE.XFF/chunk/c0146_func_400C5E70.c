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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C5E70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C5F98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6240);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6930);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6B60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6CB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C6F08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C70B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C71A8);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0146_func_400C5E70", func_400C7578);
