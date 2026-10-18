#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", ClipJudgeVolumeInfo);

extern char *GetCharacterClass(unsigned char *);
extern char *GetScriptAnimationClass(unsigned char *);

char *GetJudgeVolumeClass(unsigned char *p)
{
    char *r;
    switch (p[8]) {
    case 9:
    case 0x16:
        r = GetCharacterClass(p) + 0x2A0;
        break;
    case 0xD:
        r = *(char **)(GetScriptAnimationClass(p) + 0x33C);
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", InitJudgeVolumeClass);

extern void isysDeleteGroupAllObj(void *);
extern void iosFree(void *);

void FlushJudgeVolumeClassImmediate(int *v)
{
    int n;
    char *g = (char *)v[1];

    if (v[0] > 0) {
        n = v[0];
        do {
            isysDeleteGroupAllObj(g);
            g += 4;
        } while (--n);
    }
    if (v[1] != 0) {
        iosFree((void *)v[1]);
        v[1] = 0;
        v[0] = 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", FlushJudgeVolumeObjImmediate);

void FlushJudgeVolumeClass(void) {
}

void FlushJudgeVolumeObj(unsigned char *p)
{
    switch (p[8]) {
    case 9:
    case 0x16:
        GetCharacterClass(p);
        p = 0;
        break;
    case 0xD:
        GetScriptAnimationClass(p);
        p = 0;
        break;
    }
}

extern s32 DldSysUndefSymbol;

s32 GetJudgeVolumeClassWorkSize(s32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((char *)h - off) : 0;
    s32 n = (t != 0 && t != (s32 *)DldSysUndefSymbol) ? t[3] : 0;

    if (n != 0)
        return n * 4 + 0x33;
    return 0;
}

extern void isysAddGroupWithLinkParam(void *, void *, int, int);

int EntryJudgeVolumeClassObjectGroup(char *p, int i, void *g)
{
    int *t = *(int **)(p + 4);
    if (t != 0) {
        isysAddGroupWithLinkParam(g, t + i, 0, 0);
        return 1;
    }
    return 0;
}

void **GetJudgeVolumeClassObjectGroup(char *volume, unsigned int *attr)
{
    unsigned int index = (*attr >> 18) & 0xFFF;
    void **groups = *(void ***)(volume + 4);

    if (groups != 0) {
        return groups + index;
    }
    return 0;
}

int *GetJudgeVolumeClassObjectGroupById(char *p, int i)
{
    int *t = *(int **)(p + 0x4);

    if (t != 0) {
        return t + i;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", CheckPositionInsideOfJudgeVolumeObject);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", GetCenterPositionOfJudgeVolumeInfo);

typedef union {
    s128 q;
    float f[4];
    int i[4];
} Vec4;

typedef struct {
    Vec4 vectors[5];
    int type;
    float values[3];
} JudgeVolume;

void SetJudgeVolumeInfo(int address, int type, int vector0, int vector1,
                       float *vector4, float *vector2, float *vector3,
                       float x, float y, float z)
{
    JudgeVolume *volume = (JudgeVolume *)address;

    volume->type = type;
    volume->vectors[0].q = ((Vec4 *)vector0)->q;
    volume->vectors[1].q = ((Vec4 *)vector1)->q;
    volume->vectors[4].q = ((Vec4 *)vector4)->q;
    volume->vectors[2].q = ((Vec4 *)vector2)->q;
    volume->vectors[3].q = ((Vec4 *)vector3)->q;
    volume->values[0] = x;
    volume->values[1] = y;
    volume->values[2] = z;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", SearchJudgeVolumeByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", UpdateLayoutClassSimpleGeometry);
