#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_CheckSightOn);

void AI_InitAnimalOptimize(char *pa0)
{
    *(int *)(pa0 + 0x0) = 1;
    *(float *)(pa0 + 0x4) = 3e+01f;
    *(int *)(pa0 + 0x8) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_OptFloatFrameSample);

extern s128 ZeroVector;

typedef struct {
    s128 pos;
    int a;
    int b;
} AnimalLayout;

void AI_InitAnimalLayout(AnimalLayout *layout)
{
    layout->pos = ZeroVector;
    layout->a = 0;
    layout->b = 0;
}

void AI_SetAnimalLayout(char *p, s128 *v, float a, float b)
{
    *(s128 *)p = *v;
    *(float *)(p + 0x10) = a;
    *(float *)(p + 0x14) = b;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_CheckInAnimalLayout);

void AI_InitAnimalWork(char *pa0, int xa1)
{
    *(int *)(pa0 + 0x0) = xa1;
    *(int *)(pa0 + 0x10) = 0;
    *(int *)(pa0 + 0x4) = -1;
    *(int *)(pa0 + 0xC) = 0;
    *(int *)(pa0 + 0x8) = -1;
}

void AI_SetAnimalWorkParam(char *pa0, int xa1)
{
    *(int *)(pa0 + 0x10) = xa1;
}

void AI_InitGexCommonWork(char *p)
{
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0xC) = 0;
}

void AI_InitSurpriseArrow(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
}

void AI_SetSurprisedArea(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 4)) = fparg0;
}

extern int chkNearStickArrow(int, int, float *, float);

int AI_CheckNearArrow(int a, int b, float *c)
{
    return chkNearStickArrow(a, b, c, c[1]);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_GetSmallAnimalAIParam);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_GetYRotQuaternion);

extern u8 gcGlobalVar[];

int AI_UpdateVelocity(float *vel, float target, float accel)
{
    float v = *vel;
    int moving = 1;

    if (v < target) {
        v += accel * *(float *)(gcGlobalVar + 0x190);
        if (target < v) {
            v = target;
            moving = 0;
        }
    } else {
        v -= accel * *(float *)(gcGlobalVar + 0x190);
        if (v < target) {
            v = target;
            moving = 0;
        }
    }
    *vel = v;
    return moving;
}

extern float iosGetRandom();

void AI_GetRandomVelocity(float *arg0, float *arg1, float *arg2, float fparg0, float fparg1, float fparg2, float fparg3)
{
    if (*arg1 <= *arg2) {
        *arg0 = (fparg0 + ((fparg1 - fparg0) * iosGetRandom())) * fparg2;
        *arg1 = fparg3;
        *arg2 = 0.0f;
    }
}

float AI_GetRandomRange(float fparg0, float fparg1)
{
    return fparg0 + ((fparg1 - fparg0) * iosGetRandom());
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_GetMotionBasicVelocity);

float AI_GetAccelB(float x0, float x1, float d, float dt)
{
    float t = (dt < 0.0333667f) ? 0.0333667f : dt;

    return 2.0f * ((x0 - x1) - (x0 - d / t) * 3.0f) / t;
}

float AI_GetAccelA(float x0, float x1, float dt, float v0)
{
    float t = (dt < 0.0333667f) ? 0.0333667f : dt;

    return 2.0f * ((x1 - x0) - v0 * t) / (t * t);
}

float AI_GetAccelA_at0(float x0, float x1, float dt)
{
    dt = (dt < 0.0333667f) ? 0.0333667f : dt;
    return (x1 - x0) * -2.0f / (dt * dt);
}

float AI_GetAccelB_at0(float a, float b, float t)
{
    float step;

    b -= a;
    b += b;
    step = (t < 0.0333667f) ? 0.0333667f : t;
    return b / step;
}

float AI_GetAccelA3(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    float temp_f3;
    float var_f16;

    var_f16 = fparg4;
    if (var_f16 < 0.0333667f) {
        var_f16 = 0.0333667f;
    }
    temp_f3 = var_f16 * var_f16;
    return (-2.0f / temp_f3) * (((((6.0f / temp_f3) * (fparg2 - fparg1)) - (2.0f * fparg5)) - ((6.0f / var_f16) * fparg0)) - fparg3);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0125_AI_CheckSightOn", AI_GetAccelA3XYZ);

float AI_GetAccelB3(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    float var_f16;

    var_f16 = fparg4;
    if (var_f16 < 0.0333667f) {
        var_f16 = 0.0333667f;
    }
    return (6.0f / (var_f16 * var_f16)) * (((((4.0f / var_f16) * (fparg3 - fparg2)) - fparg1) - (fparg0 * 3.0f)) - (fparg5 * var_f16));
}
