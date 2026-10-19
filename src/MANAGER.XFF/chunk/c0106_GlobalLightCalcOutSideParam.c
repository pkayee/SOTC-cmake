#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", GlobalLightCalcOutSideParam);

void ForceGlobalLightFlagEnvelope(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x110)) = (int) (((*(int *)((char *)(arg0) + 0x110)) | 0x20000) & 0xFFFEFFFF);
}

int IsEnvelopeGlobalLightType(char *p)
{
    if (*(int *)(p + 0x110) & 0x20000) {
        return 1;
    }
    return 0;
}

extern float iosCalcFColorToBrightness(float *);

void SetColorParamAmbientLight(void *arg0, void *arg1)
{
    float temp_f0;
    float temp_f1;
    float var_f0;

    (*(s128 *)((char *)(arg0) + 0x100)) = (s128) (*(s128 *)((char *)(arg1) + 0));
    (*(float *)((char *)(arg0) + 0x12C)) = (float) (*(float *)((char *)(arg1) + 0x24));
    temp_f0 = iosCalcFColorToBrightness((float *)((char *)arg0 + 0x100));
    temp_f1 = (*(float *)((char *)(arg0) + 0x12C));
    (*(float *)((char *)(arg0) + 0x140)) = temp_f0;
    if (temp_f1 < 0.0f) {
        var_f0 = -temp_f1 * temp_f0;
    } else {
        var_f0 = temp_f1 * temp_f0;
    }
    (*(float *)((char *)(arg0) + 0x130)) = var_f0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", UpdateGlobalLightInRange);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", UpdateGlobalLightOutRange);

void UpdateGlobalLightAmbient(void *light, void *parameter)
{
    float brightness;
    float power;
    float scaled_brightness;
    typedef union {s128 q; float f[4];} Color;

    parameter = (char *)parameter + 0x10;

    ((Color *)((char *)light + 0x100))->q = ((Color *)parameter)->q;
    (*(float *)((char *)(light) + 0x12C)) = (float) (*(float *)((char *)(parameter) + 0x24));
    brightness = iosCalcFColorToBrightness((float *)((char *)light + 0x100));
    power = (*(float *)((char *)(light) + 0x12C));
    (*(float *)((char *)(light) + 0x140)) = brightness;
    if (power < 0.0f) {
        scaled_brightness = -power * brightness;
    } else {
        scaled_brightness = power * brightness;
    }
    (*(float *)((char *)(light) + 0x130)) = scaled_brightness;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", UpdateGlobalLightDistant);

/* NEARMISS-STUB IsEnvelopeDistantLightType */
#if 0 /* NEARMISS 96.25% cat=cse-hoist sub=- | search loop: target recomputes found ptr l+(i<<6) (addu a0,a1) separately from the compare address; ours reuses it (move t0,a1) | attempts=1 */
typedef struct {
    u8 pad0[0x2C];
    u32 flags;
    s8 id;
    u8 pad31[0xF];
} DistantLight;

static inline DistantLight *globalLightFindDistant(DistantLight *l, s32 id)
{
    DistantLight *d = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (l[i].id == id) {
            d = (DistantLight *)((u8 *)l + i * 0x40);
            break;
        }
    }
    return d;
}

s32 IsEnvelopeDistantLightType(DistantLight *l, u8 *prm)
{
    DistantLight *d = globalLightFindDistant(l, *(s32 *)(prm + 0x24));

    if (d->flags & 0x20000) {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", IsEnvelopeDistantLightType);

s32 globalLightCalcLightNum(u8 *w, s32 type)
{
    s32 n = 4;

    switch (type) {
    case 0x19:
        n = 3;
        *(s32 *)(w + 0x110) |= 4;
        *(s32 *)(w + 0x124) = *(s32 *)(w + 0x120) + 1;
        break;
    case 0x1A:
        switch (*(s32 *)(w + 0x120)) {
        case 0:
            n = 0;
            *(s32 *)(w + 0x110) |= 8;
            break;
        case 1:
            n = 1;
            *(s32 *)(w + 0x110) |= 0x10;
            break;
        case 2:
            n = 2;
            *(s32 *)(w + 0x110) |= 0x20;
            break;
        }
        if (n != 4) {
            *(s32 *)(w + 0x120) += 1;
            *(s32 *)(w + 0x124) += 1;
        }
        break;
    }
    return n;
}

void CalcColorParamDistantLight(void *arg0)
{
    float temp_f0;
    float var_f1;

    temp_f0 = iosCalcFColorToBrightness((float *)((char *)arg0 + 0x10));
    var_f1 = temp_f0 * (*(float *)((char *)(arg0) + 0x24));
    (*(float *)((char *)(arg0) + 0x20)) = temp_f0;
    if (var_f1 < 0.0f) {
        var_f1 = -var_f1;
    }
    (*(float *)((char *)(arg0) + 0x28)) = var_f1;
}

void CalcColorParamAmbientLight(void *arg0)
{
    float temp_f0;
    float temp_f1;
    float var_f0;

    temp_f0 = iosCalcFColorToBrightness((float *)((char *)arg0 + 0x100));
    temp_f1 = (*(float *)((char *)(arg0) + 0x12C));
    (*(float *)((char *)(arg0) + 0x140)) = temp_f0;
    if (temp_f1 < 0.0f) {
        var_f0 = -temp_f1 * temp_f0;
    } else {
        var_f0 = temp_f1 * temp_f0;
    }
    (*(float *)((char *)(arg0) + 0x130)) = var_f0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", SetWorkFromGlobalLight);

char *GetNextWorkLightClass(char *c)
{
    char *r = 0;
    int n = *(int *)(c + 0x530);
    if (n < 3) {
        r = c + n * 64 + 0x450;
        ((int *)(c + 0x534))[n] = (int)r;
        *(int *)(c + 0x530) += 1;
    }
    return r;
}

typedef struct {
    char pad0[0x38];
    float impact;
} LightClass;

typedef struct {
    char pad0[0x530];
    int count;
    LightClass *lights[1];
} LightManager;

LightClass *GetImpactWorstWorkLightClass(LightManager *mgr)
{
    int n = mgr->count;
    LightClass *worst = mgr->lights[0];
    int i;

    for (i = 1; i < n; i++) {
        if (mgr->lights[i]->impact < worst->impact) {
            worst = mgr->lights[i];
        }
    }
    return worst;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", GetDirColorFromWorkLight);

typedef union {
    s128 q;
    float f[4];
    int i[4];
} ClVec4;

typedef struct {
    char pad0[0x1C0];
    int type;
    char pad1C4[0xC];
    ClVec4 color;
    ClVec4 dir;
    float range;
    float intensity;
} ClLightClass;

typedef struct {
    char pad0[8];
    unsigned char kind;
    char pad9[0x17];
    ClLightClass light;
} ClLightObj;

typedef struct {
    char pad0[0x7C];
    int type;
    ClVec4 color;
    ClVec4 dir;
    float range;
    float intensity;
} ClLightData;

extern int GetLayoutObjWorkSize(void *);
extern unsigned char *_isysCreateObj(void *, int, int, void *, void *, int);
extern void InitLayoutObj(void *, void *);
extern void func_4008E108(void);

ClLightObj *CreateLightObj(void *heap, int size, ClLightData *data)
{
    ClLightObj *obj = (ClLightObj *)_isysCreateObj(heap, 0x13, 0x220, (void *)(size + GetLayoutObjWorkSize(data)), func_4008E108, 0x10);
    ClLightClass *light;

    if (obj != 0) {
        InitLayoutObj(obj, data);
        light = (obj->kind == 0x13) ? &obj->light : 0;
        light->type = data->type;
        light->color.q = data->color.q;
        light->dir.q = data->dir.q;
        light->range = data->range;
        light->intensity = data->intensity;
    }
    return obj;
}

char *GetLightClass(unsigned char *p)
{
    if (p[0x8] != 0x13) {
        return 0;
    }
    return (char *)p + 0x20;
}

extern unsigned char *_isysCreateObj(void *, int, int, void *, void *, int);
extern void func_4008E1B0();

unsigned char *CreateAmbientLightObj(void *heap, void *parent, int *col)
{
    unsigned char *o = _isysCreateObj(heap, 0x14, 0x28, parent, func_4008E1B0, 0x10);
    int *l;
    if (o != 0) {
        l = o[8] != 0x14 ? 0 : (int *)(o + 0x1C);
        l[0] = col[0];
        l[1] = col[1];
        l[2] = col[2];
    }
    return o;
}

void FlushLayoutObj();

void func_4008E108(void)
{
    FlushLayoutObj();
}

extern void InitLayoutObj(void *, void *);

typedef union {
    s128 q;
    float f[4];
    int i[4];
} InitVec4;

typedef struct {
    char pad0[0x1C0];
    int type;
    char pad1C4[0xC];
    InitVec4 color;
    InitVec4 dir;
    float range;
    float intensity;
} InitLightClass;

typedef struct {
    char pad0[8];
    unsigned char kind;
    char pad9[0x17];
    InitLightClass light;
} InitLightObjRaw;

typedef struct {
    char pad0[0x7C];
    int type;
    InitVec4 color;
    InitVec4 dir;
    float range;
    float intensity;
} InitLightData;

int InitLightObj(InitLightObjRaw *obj, InitLightData *data)
{
    InitLightClass *light;

    InitLayoutObj(obj, data);
    light = (obj->kind == 0x13) ? &obj->light : 0;
    light->type = data->type;
    light->color.q = data->color.q;
    light->dir.q = data->dir.q;
    light->range = data->range;
    light->intensity = data->intensity;
    return 1;
}

char *GetAmbientLightClass(unsigned char *p)
{
    if (p[0x8] != 0x14) {
        return 0;
    }
    return (char *)p + 0x1C;
}

void func_4008E1B0(void) {
}

int InitAmbientLightObj(unsigned char *o, int *v)
{
    int *c = (int *)(o[8] == 0x14 ? o + 0x1C : 0);
    c[0] = v[0];
    c[1] = v[1];
    c[2] = v[2];
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0106_GlobalLightCalcOutSideParam", func_4008E1E8);
