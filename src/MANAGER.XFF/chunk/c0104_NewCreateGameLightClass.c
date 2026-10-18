#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0104_NewCreateGameLightClass", NewCreateGameLightClass);

void deleteGameLightObj(void) {
}

char *GetGameLightClass(unsigned char *p)
{
    if (p[0x8] != 0x1A) {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0104_NewCreateGameLightClass", AddGaLightMan);

void ForceGameLightFlagEnvelope(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x2C)) = (int) (((*(int *)((char *)(arg0) + 0x2C)) | 0x20000) & 0xFFFEFFFF);
}

int IsEnvelopeGameLightType(char *p)
{
    if (*(int *)(p + 0x2C) & 0x20000) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0104_NewCreateGameLightClass", UpdateGameLight);

typedef struct {
    char pad0[0x20];
    int color;
    float scale;
    char pad28[0x10];
    unsigned char brightness;
    char pad39[3];
    int color_copy;
    float intensity;
} GameLight;

extern unsigned char iosCalcIcolorToBrightness(int);

void CalcColorParamGameLight(GameLight *light)
{
    float f;

    light->color_copy = light->color;
    light->brightness = iosCalcIcolorToBrightness(light->color);
    f = light->brightness * light->scale;
    if (f < 0.0f) {
        f = -f;
    }
    light->intensity = f;
}

void GameLightCalcOutSideParam(void *arg0)
{
    float temp_f0;

    temp_f0 = (*(float *)((char *)(arg0) + 0x28));
    (*(float *)((char *)(arg0) + 0x34)) = (float) (temp_f0 * temp_f0);
}

extern char *GetLightColMan(unsigned char *);
extern void isysAddGroupWithLinkParam(void *, void *, int, int);
extern void _isysDeleteGroup(void *, void *, int);

void ForceDelGameLighObj(unsigned char *o)
{
    char *m = GetLightColMan(o);
    unsigned char *l = o[8] != 0x1A ? 0 : o + 0x20;
    *(int *)(l + 0x2C) = 0;
    isysAddGroupWithLinkParam(o, m + 0x524, 0, 0);
    _isysDeleteGroup(o, m + 0x528, 0);
}

void SetGameLightUserParam(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x50)) = arg1;
}

void SetGameLightUserFunc(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x54)) = arg1;
}

void InitGameLightClass(void) {
}

float GameLightCalcImpact(void *arg0, float fparg0)
{
    float var_f0;

    var_f0 = (*(float *)((char *)(arg0) + 0x40)) * (1.0f - (fparg0 / (*(float *)((char *)(arg0) + 0x28))));
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    return var_f0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0104_NewCreateGameLightClass", func_4008C5A0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0104_NewCreateGameLightClass", AddGlLightMan);
