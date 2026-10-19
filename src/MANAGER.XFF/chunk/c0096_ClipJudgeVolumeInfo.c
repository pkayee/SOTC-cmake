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

extern s32 DldSysUndefSymbol;
extern s32 iosMallocAlign(s32, s32, s32);
extern void isysInitGroup(s32);

void InitJudgeVolumeClass(s32 *v, s32 *h, s32 heap)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((char *)h - off) : 0;
    s32 n = (t != 0 && t != (s32 *)DldSysUndefSymbol) ? t[3] : 0;
    s32 i;

    v[0] = n;
    v[1] = n != 0 ? iosMallocAlign(heap, n << 2, 4) : 0;
    for (i = 0; i < n; i++) {
        isysInitGroup(v[1] + i * 4);
    }
}

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

/* NEARMISS-STUB FlushJudgeVolumeObjImmediate */
#if 0 /* NEARMISS 95.92% cat=sched sub=- | GetJudgeVolumeClass switch inline + FlushJudgeVolumeClassImmediate inline as for(i<n) with locals g,n; target loads v[1] (a0) BEFORE v[0] and the skip branch re | attempts=1 */
static inline char *judgeVolumeClass(unsigned char *p)
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

static inline void flushJudgeVolumeClassImmediate(int *v)
{
    int i;
    int *g = (int *)v[1];
    int n = v[0];

    for (i = 0; i < n; i++) {
        isysDeleteGroupAllObj(&g[i]);
    }
    if (v[1] != 0) {
        iosFree((void *)v[1]);
        v[1] = 0;
        v[0] = 0;
    }
}

void FlushJudgeVolumeObjImmediate(unsigned char *p)
{
    flushJudgeVolumeClassImmediate((int *)judgeVolumeClass(p));
}
#endif
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

static inline char *judgeVolumeClass(unsigned char *p)
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

static inline void **judgeVolumeClassObjectGroup(char *volume, unsigned int *attr)
{
    unsigned int index = (*attr >> 18) & 0xFFF;
    void **groups = *(void ***)(volume + 4);

    if (groups != 0) {
        return groups + index;
    }
    return 0;
}

extern int isysGroupForFirst(void **, int);
extern int isysGroupForNext(int, int);
extern void isysGroupForExit(int, int);
extern int ScriptAnimationObjCheckPositionInsideOfJudgeVolumeObject(void *, int, int);

int CheckPositionInsideOfJudgeVolumeObject(void *pos, unsigned char *obj, unsigned int *attr, int arg)
{
    char *v = judgeVolumeClass(obj);
    int r = 0;
    int node;
    int item;

    if (v != 0) {
        void **grp = judgeVolumeClassObjectGroup(v, attr);
        item = 0;
        for (node = isysGroupForFirst(grp, 0); node != 0; node = isysGroupForNext(node, 0)) {
            item = *(int *)node;
            if (ScriptAnimationObjCheckPositionInsideOfJudgeVolumeObject(pos, item, arg) != 0) {
                r = 1;
                break;
            }
        }
        if (item != 0) {
            isysGroupForExit(item, 0);
        }
    }
    return r;
}

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

static inline u8 *jvDldElem(u32 *lp)
{
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}

extern int strcmp(const char *, const char *);

s32 SearchJudgeVolumeByName(u32 *h, char *name)
{
    u32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((char *)h - off) : 0;
    s32 n = (t != 0 && t != (s32 *)DldSysUndefSymbol) ? t[3] : 0;
    char **e = (char **)jvDldElem(h);
    s32 i;

    for (i = 0; i < n; i++) {
        if (strcmp(e[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0096_ClipJudgeVolumeInfo", UpdateLayoutClassSimpleGeometry);
