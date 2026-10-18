#include "common.h"

typedef struct {
    char pad0[0x190];
    float speed;
} GlobalVar;

extern GlobalVar gcGlobalVar;

static inline void approach(float *v, float t, float a)
{
    float x = *v;

    if (x < t) {
        x += a * gcGlobalVar.speed;
        if (t < x)
            x = t;
    } else {
        x -= a * gcGlobalVar.speed;
        if (x < t)
            x = t;
    }
    *v = x;
}

void AI_UpdateVelocityXYZ(float *v, float *t, float *a)
{
    approach(&v[0], t[0], a[0]);
    approach(&v[1], t[1], a[1]);
    approach(&v[2], t[2], a[2]);
}

extern float iosGetRandom(void);
extern float iosGetTableCos(short);
extern float iosGetTableSin(short);

void AI_GetRandomSphereOfs(void *arg0, float fparg0, float fparg1)
{
    float temp_f20;
    float temp_f20_2;
    float temp_f20_3;
    float temp_f20_4;
    float temp_f21;
    float temp_f24;
    int temp_f0;
    int temp_f0_2;

    temp_f21 = 2.0f * iosGetRandom();
    temp_f20 = (2.0f * iosGetRandom()) - 1.0f;
    temp_f24 = fparg0 + ((fparg1 - fparg0) * iosGetRandom());
    temp_f0 = (int) ((temp_f20 * 3.14159265f * 32768.0f) / 3.14159265f);
    temp_f20_2 = iosGetTableSin((short) temp_f0);
    temp_f0_2 = (int) ((temp_f21 * 3.14159265f * 32768.0f) / 3.14159265f);
    (*(float *)((char *)(arg0) + 0)) = (float) (temp_f20_2 * iosGetTableSin((short) temp_f0_2) * temp_f24);
    (*(float *)((char *)(arg0) + 4)) = (float) (iosGetTableSin((short) temp_f0) * temp_f24);
    temp_f20_3 = iosGetTableSin((short) temp_f0);
    temp_f20_4 = temp_f20_3 * iosGetTableCos((short) temp_f0_2);
    (*(int *)((char *)(arg0) + 0xC)) = 0;
    (*(float *)((char *)(arg0) + 8)) = (float) (temp_f20_4 * temp_f24);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0124_AI_UpdateVelocityXYZ", AI_CalcIntersectionCircleXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0124_AI_UpdateVelocityXYZ", AI_GetGeometryPointerOfLayout);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0124_AI_UpdateVelocityXYZ", AI_CheckNoAngleVec);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0124_AI_UpdateVelocityXYZ", AI_GetQuaternionNodeDirTarget);
