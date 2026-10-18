#include "common.h"

typedef struct { int p; } Group;
typedef struct { char pad[0x98]; Group g[3]; int a[128]; char pad2[0xC]; } FogColMan;
extern FogColMan D_401AC600;
extern void *memset(void *, int, unsigned int);
extern void isysInitGroup(Group *);

typedef union {
    float f;
    int i;
} Word;

typedef struct {
    char pad0[0x4E];
    unsigned char r;
    unsigned char g;
    unsigned char b;
    char pad51[7];
    float near;
    float far;
    float density;
    float min;
    float max;
} FogColClass;

void InitFogColMan(void)
{
    FogColMan *m = &D_401AC600;
    int i;
    memset(m, 0, 0x2B0);
    for (i = 127; i >= 0; i--)
        m->a[i] = 0;
    isysInitGroup(&m->g[0]);
    isysInitGroup(&m->g[1]);
    isysInitGroup(&m->g[2]);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", AddCollMan);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", DeleteCollMan);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", CreateFogColMan);

void SetInitFogColClassFromStageData(Word *data)
{
    FogColClass *fog = (FogColClass *)&D_401AC600;

    fog->near = data[1].f;
    fog->far = data[2].f;
    fog->min = data[3].f;
    fog->max = data[4].f;
    fog->density = data[6].i;
    fog->r = data[7].i;
    fog->g = data[8].i;
    fog->b = data[9].i;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", UpdateFogAnim);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", UpdateFogCol);

void SetFogColAvailableFlag(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x80)) = arg1;
}

int IsEnvelopeFogType(char *p)
{
    if (*(int *)(p + 0x40) & 0x800) {
        return 1;
    }
    return 0;
}

void *GetFogColMan(void)
{
    return &D_401AC600;
}

char *GetFogColClass(unsigned char *p)
{
    if (p[0x8] != 0x18) {
        return 0;
    }
    return (char *)p + 0x20;
}

void ForceFogColFlagEnvelope(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x40)) = (int) (((*(int *)((char *)(arg0) + 0x40)) | 0x800) & ~0x400);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", getOutSideVectorXYZSquare);

void func_400829D0(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", CheckCollisionColClass);

char *GetGeoDispClass(unsigned char *p)
{
    if (p[0x8] != 0x24) {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", CreateGeoDispObj);

void func_40082B70(void) {
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", func_40082B78);
s32 GetLayoutDispObjGroup(void);
void _isysDeleteGroup(s32 a, s32 b, s32 c);

void func_40082B78(s32 arg0)
{
    _isysDeleteGroup(arg0, GetLayoutDispObjGroup(), 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", CheckPositionInsideOfJudgeVolumeInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", func_40082EE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", func_400831E0);
