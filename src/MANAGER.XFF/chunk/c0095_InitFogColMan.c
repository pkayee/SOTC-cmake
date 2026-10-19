#include "common.h"

typedef struct { int p; } Group;
typedef struct { char pad[0x90]; s32 flags; char pad94[4]; Group g[3]; int a[128]; char pad2[0xC]; } FogColMan;
extern FogColMan D_401AC600;
extern void *memset(void *, int, unsigned int);
extern void isysInitGroup(Group *);
extern s32 _isysCreateObj(s32, s32, s32, s32, void (*)(void), s32);
extern void isysAddGroupWithLinkParam(s32, s32, s32, s32);
void func_400829D0(void);

static inline u8 *fogColClass(s32 obj)
{
    if (*(u8 *)(obj + 8) != 0x18) {
        return 0;
    }
    return (u8 *)obj + 0x20;
}

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
    float f6C;
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

/* NEARMISS-STUB AddCollMan */
#if 0 /* NEARMISS 92.41% cat=sched sub=- | fogColClass static inline fixes the hoisted 0x18; only the group-select (lui/addiu/movn) and obj=0 order before First differ | attempts=1 */
extern Group D_401AC698;
extern Group D_401AC69C;
extern s32 func_40082178(u8 *, s32, s32, s32, s32, s32);

u8 *AddCollMan(s32 a0, s32 a1, s32 a2)
{
    s32 i;
    s32 found = 0;
    u8 *c = 0;

    for (i = 0; i < 2; i++) {
        if (!found) {
            s32 obj = 0;
            s32 *it;

            for (it = isysGroupForFirst(i ? &D_401AC698 : &D_401AC69C, 0); it != NULL; it = isysGroupForNext(it, 0)) {
                obj = *it;
                c = fogColClass(obj);
                if (c != NULL && func_40082178(c, a0, a1, i, obj, a2) != 0) {
                    found = 1;
                    break;
                }
            }
            if (obj != 0) {
                isysGroupForExit(obj, 0);
            }
        }
    }
    D_401AC600.flags |= 1;
    return found ? c : 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", AddCollMan);

extern s32 *isysGroupForFirst(void *, s32);
extern s32 *isysGroupForNext(s32 *, s32);
extern void isysGroupForExit(s32, s32);
extern void _isysDeleteGroup(s32 a, s32 b, s32 c);

s32 DeleteCollMan(u8 *cls)
{
    FogColMan *m = &D_401AC600;
    s32 obj = 0;
    s32 *it;

    for (it = isysGroupForFirst(&m->g[2], 0); it != NULL; it = isysGroupForNext(it, 0)) {
        u8 *c;
        obj = *it;
        c = fogColClass(obj);
        if (c != NULL && c == cls) {
            FogColMan *fm = &D_401AC600;

            *(s32 *)(c + 0x40) = 0;
            isysAddGroupWithLinkParam(obj, (s32)&fm->g[0], 0, 0);
            _isysDeleteGroup(obj, (s32)&fm->g[2], 0);
            break;
        }
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
    m->flags |= 2;
    return 0;
}

void CreateFogColMan(s32 work)
{
    FogColMan *m = &D_401AC600;
    s32 i;

    for (i = 0; i < 0x80; i++) {
        s32 obj = _isysCreateObj(work, 0x18, 0xB0, 0xB0, func_400829D0, 0x10);
        if (obj != 0) {
            u8 *c = fogColClass(obj);
            if (c != NULL) {
                memset(c, 0, 0x90);
            }
            *(s16 *)(c + 0x4C) = i;
            isysAddGroupWithLinkParam(obj, (s32)&m->g[0], 0, 0);
        }
    }
}

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

void UpdateFogCol(FogColClass *fog, float *p)
{
    fog->r = (u32)p[0];
    fog->g = (u32)p[1];
    fog->b = (u32)p[2];
    fog->near = p[4];
    fog->far = p[5];
    fog->density = p[6];
    fog->min = p[8];
    fog->max = p[9];
    fog->f6C = p[10];
}

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

/* NEARMISS-STUB CheckCollisionColClass */
#if 0 /* NEARMISS 95.71% cat=regalloc sub=- | goto-end form: result r lands in f1 (mov.s f1,f0 after each call), target keeps it in f0 and zero in f1; tried decl order, field compare, return-expr | attempts=1 */
extern void GetInverseMatrixFromQuaternionPos(void *, void *, void *);
extern float GetRateInOutEllipticalSphereVolumeWithInverseMatrix(void *, void *, void *, void *);
extern float GetRateInOutCubeVolumeWithInverseMatrix(void *, void *, void *, void *);

s32 CheckCollisionColClass(void *pos, u8 *cls)
{
    u8 mat[64];
    float r;
    s32 ret = 0;

    GetInverseMatrixFromQuaternionPos(mat, cls + 0x10, cls);
    if (*(s32 *)(cls + 0x40) & 1) {
        r = GetRateInOutEllipticalSphereVolumeWithInverseMatrix(mat, pos, cls + 0x20, cls + 0x30);
    } else if (*(s32 *)(cls + 0x40) & 2) {
        r = GetRateInOutCubeVolumeWithInverseMatrix(mat, pos, cls + 0x20, cls + 0x30);
    } else {
        goto end;
    }
    *(float *)(cls + 0x70) = r;
    if (0.0f <= r) {
        ret = 1;
    }
end:
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0095_InitFogColMan", CheckCollisionColClass);

char *GetGeoDispClass(unsigned char *p)
{
    if (p[0x8] != 0x24) {
        return 0;
    }
    return (char *)p + 0x20;
}

extern void InitSortObj(u8 *, s32);
extern void isysSetObjImmediateDeleteFunc(s32, void (*)(s32));
void func_40082B70(void);
void func_40082B78(s32 arg0);
s32 GetLayoutDispObjGroup(void);

s32 CreateGeoDispObj(s32 work, s32 size, s32 *prm)
{
    s32 obj = _isysCreateObj(work, 0x24, 0x110, size + 0x1000, func_40082B70, 0x10);
    if (obj != 0) {
        u8 *c = 0;
        if (*(u8 *)(obj + 8) == 0x24) {
            c = (u8 *)obj + 0x20;
        }
        isysAddGroupWithLinkParam(obj, GetLayoutDispObjGroup(), 0, 0);
        *(s32 *)(c + 0xEC) = prm[0];
        *(s32 *)(c + 0xD0) = prm[1];
        *(s32 *)(c + 0xD4) = prm[2];
        *(s32 *)(c + 0xD8) = prm[3];
        *(s32 *)(c + 0xE0) = prm[4];
        *(s32 *)(c + 0xE8) = prm[5];
        InitSortObj(c, obj);
        isysSetObjImmediateDeleteFunc(obj, func_40082B78);
    }
    return obj;
}

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
