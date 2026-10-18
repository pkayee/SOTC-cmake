#include "common.h"

extern int texGetCSM1Idx(int);

void SpriteInitStatusClut(unsigned char *palette)
{
    int end0;
    int end1;
    int end2;
    int end3;
    int start0;
    int start1;
    int start2;
    int start3;
    int destination0;
    int destination1;
    int destination2;
    int destination3;
    int alphaNumerator;
    int entry;
    unsigned char steps;

    entry = 1;
    steps = palette[texGetCSM1Idx(0xFF) * 4 + 3];
    palette[texGetCSM1Idx(0) * 4] =
        palette[texGetCSM1Idx(0) * 4 + 1] =
        palette[texGetCSM1Idx(0) * 4 + 2] =
        palette[texGetCSM1Idx(0) * 4 + 3] = 0;
    if (steps != 0) {
        do {
            destination0 = texGetCSM1Idx(entry);
            start0 = texGetCSM1Idx(0xFC);
            end0 = texGetCSM1Idx(0xFD);
            palette[destination0 * 4] = palette[start0 * 4] + ((int) ((palette[end0 * 4] - palette[texGetCSM1Idx(0xFC) * 4]) * entry) / (int) steps);
            destination1 = texGetCSM1Idx(entry);
            start1 = texGetCSM1Idx(0xFC);
            end1 = texGetCSM1Idx(0xFD);
            palette[destination1 * 4 + 1] = (palette[start1 * 4 + 1] + ((int) ((palette[end1 * 4 + 1] - palette[texGetCSM1Idx(0xFC) * 4 + 1]) * entry) / (int) steps));
            destination2 = texGetCSM1Idx(entry);
            start2 = texGetCSM1Idx(0xFC);
            end2 = texGetCSM1Idx(0xFD);
            palette[destination2 * 4 + 2] = (palette[start2 * 4 + 2] + ((int) ((palette[end2 * 4 + 2] - palette[texGetCSM1Idx(0xFC) * 4 + 2]) * entry) / (int) steps));
            destination3 = texGetCSM1Idx(entry);
            start3 = texGetCSM1Idx(0xFC);
            end3 = texGetCSM1Idx(0xFD);
            alphaNumerator = (palette[end3 * 4 + 3] - palette[texGetCSM1Idx(0xFC) * 4 + 3]) * entry;
            entry += 1;
            palette[destination3 * 4 + 3] = (palette[start3 * 4 + 3] + (alphaNumerator / (int) steps));
        } while ((int) steps >= entry);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0080_SpriteInitStatusClut", SpriteSetStatusClut);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0080_SpriteInitStatusClut", initbar);

typedef struct {
    char pad[0x30];
    float k30;
    float k34;
    float k38;
    float pad3C;
    float max;
    float prev;
    float cur;
    float r4C;
    float r50;
    float r54;
} Bar;

void setbar(Bar *b, float v)
{
    if (b->cur == v)
        return;
    b->cur = v;
    b->prev = b->max;
    if (v < b->max) {
        if (0.0f < v)
            b->r4C = (b->max - v) / b->k38 * b->k30;
        b->r54 = (b->prev - b->cur) / b->k38 * b->k34 + 1.0f;
    }
    b->r50 = (b->prev - b->cur) * 0.03f;
}

int SpriteSetStatus(void *arg0, int arg1)
{
    float temp_f0;
    float temp_f0_2;
    float temp_f1;
    float var_f2;
    int var_v0;

    var_f2 = (*(float *)((char *)(arg0) + 8));
    temp_f1 = (*(float *)((char *)(arg0) + 0));
    var_v0 = arg1 + 1;
    if (temp_f1 < var_f2) {
        temp_f0 = var_f2 - 0.01f;
        var_f2 = temp_f1;
        (*(float *)((char *)(arg0) + 8)) = temp_f0;
        if (temp_f0 <= temp_f1) {
            (*(float *)((char *)(arg0) + 8)) = temp_f1;
            var_v0 = 0;
        } else {
            var_f2 = temp_f0;
        }
    }
    if (var_f2 < temp_f1) {
        temp_f0_2 = var_f2 + 0.01f;
        (*(float *)((char *)(arg0) + 8)) = temp_f0_2;
        if (temp_f1 <= temp_f0_2) {
            (*(float *)((char *)(arg0) + 8)) = temp_f1;
            var_v0 = 0;
        }
    }
    return var_v0;
}

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
} TimeFloatInter;

void Init_TimeFloatInter(TimeFloatInter *t, float a, float b, float c, float d)
{
    t->f0 = c;
    t->f4 = b;
    t->f8 = a;
    t->fC = b;
    t->f10 = d;
}

extern u8 gcGlobalVar[];

void Update_TimeFloatInter(TimeFloatInter *t)
{
    float temp_f0;
    float temp_f0_2;
    float temp_f1;
    float temp_f4;
    float temp_f5;

    temp_f0 = t->f10;
    if (temp_f0 > 0.0f) {
        temp_f4 = t->f0;
        temp_f1 = temp_f0 - *(float *)(gcGlobalVar + 0x180);
        temp_f5 = t->f8;
        t->f10 = temp_f1;
        temp_f0_2 = (temp_f4 - temp_f1) / temp_f4;
        t->fC = (float)((temp_f5 * temp_f0_2) + (t->f4 * (1.0f - temp_f0_2)));
        if (temp_f1 <= 0.0f) {
            t->fC = temp_f5;
        }
    }
}

typedef union {
    u128 q;
    float f[4];
} Vec4;

void Init_TimeFVECTORInter(Vec4 *p, Vec4 *a, Vec4 *b, float x, float y)
{
    p[0].q = b->q;
    p[1].q = a->q;
    p[2].q = b->q;
    p[3].f[0] = x;
    p[3].f[1] = y;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0080_SpriteInitStatusClut", Update_TimeFVECTORInter);

void Init_TimeFloatSpeed(char *p, float f1, float f2, float f3)
{
    *(float *)(p + 0x4) = f1;
    *(float *)(p + 0x0) = f2;
    *(float *)(p + 0x8) = f2;
    *(float *)(p + 0xC) = f3;
}

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
} TimeFloatSpeed;

void Update_TimeFloatSpeed(TimeFloatSpeed *t)
{
    float target = t->f4;
    float dir = 1.0f;

    if (target < t->f0) {
        dir = -1.0f;
    }
    t->f8 += t->fC * dir * *(float *)(gcGlobalVar + 0x180);
    if (dir > 0.0f) {
        if (target < t->f8) {
            t->f8 = target;
        }
    } else if (t->f8 < target) {
        t->f8 = target;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0080_SpriteInitStatusClut", ColCont2_Update);
