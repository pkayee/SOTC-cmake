#include "common.h"

typedef union { s128 q; float f[4]; int i[4]; } Vec4;

extern Vec4 ZeroVector;

typedef struct {
    int state;
    char pad4[0xC];
    Vec4 a;
    Vec4 b;
    int c;
    int d;
} NeckTurn;

void constructor_neck_turn(NeckTurn *n)
{
    n->state = 0;
    n->a.q = ZeroVector.q;
    n->b.q = ZeroVector.q;
    n->c = 0;
    n->d = 0;
}

void begin_neck_turn(NeckTurn *n)
{
    if (n->c == 0) {
        n->state = 0;
        n->a.q = ZeroVector.q;
        n->b.q = ZeroVector.q;
        n->c = 1;
    }
    n->d = 0;
}

void request_end_neck_turn(void *arg0)
{
    if ((*(int *)((char *)(arg0) + 0x30)) != 0) {
        (*(int *)((char *)(arg0) + 0x34)) = 1;
        return;
    }
    (*(int *)((char *)(arg0) + 0x34)) = 0;
}

int is_doit_neck_turn_need(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x30));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", doit_neck_turn);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", func_40050FC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", initGazeIKWork);

int getSizeGazeIKWork(void)
{
    return 0xC0;
}

u8 *GetCharacterClass();
u8 *GetScriptAnimationClass();

u8 *GetAnimationClass(u8 *o)
{
    switch (o[8])
    {
    case 9:
        return GetCharacterClass(o) + 0x1C0;
    case 0xD:
        return GetScriptAnimationClass(o) + 0x2E0;
    case 0x16:
        return o + 0x250;
    }
    return 0;
}

typedef struct {
    char *mot;
    int a;
    float b;
    float c;
    int pad10;
    int pad14;
    int d;
    float e;
    int f;
    int g;
    float ratio;
    float inv;
    char table[1];
} AnimClass;

extern float GetMotionStretchRatio(void *);
extern void ResetAnimeFrameTableInfo(void *, int, int);

static inline float stretchRatio(char *mot)
{
    if (mot != 0)
        return GetMotionStretchRatio(mot + 0x50);
    return 1.0f;
}

void InitAnimationClassWithFrame(AnimClass *a, char *mot, float frame)
{
    float ratio;

    a->mot = mot;
    a->a = 0;
    a->b = frame;
    a->c = frame;
    a->d = 0;
    a->e = 1.0f;
    a->f = 0;
    a->g = 0;
    ratio = stretchRatio(mot);
    a->ratio = ratio;
    a->inv = 1.0f / ratio;
    ResetAnimeFrameTableInfo(a->table, 0, 0);
}

void InitAnimationClass(AnimClass *a, char *mot)
{
    float ratio;

    a->mot = mot;
    a->a = 0;
    *(int *)&a->b = 0;
    *(int *)&a->c = 0;
    a->d = 0;
    a->e = 1.0f;
    a->f = 0;
    a->g = 0;
    ratio = stretchRatio(mot);
    a->ratio = ratio;
    a->inv = 1.0f / ratio;
    ResetAnimeFrameTableInfo(a->table, 0, 0);
}

extern int GetMotionFrame(void *, void *, int, float);

void GetAnimationClassCurrentInfo(void *arg0, int arg1, float fparg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = GetMotionFrame(arg0 + 8, arg0 + 0x18, arg1, fparg0 * (*(float *)((char *)(arg0) + 0x1C)) * (*(float *)((char *)(arg0) + 0x28)));
}

extern int GetMotionFrameWithOutsideLimit(void *, void *, int, float);

void GetAnimationClassCurrentInfoWithOutsideLimit(void *arg0, int arg1, float fparg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = GetMotionFrameWithOutsideLimit(arg0 + 8, arg0 + 0x18, arg1, fparg0 * (*(float *)((char *)(arg0) + 0x1C)));
}

extern void *GetObjectAnimationFloatFrame(void *, void *, void *, float, float);

void *GetAnimationClassObjectAnimation(void *obj, float *frame, void *b, void *c)
{
    return GetObjectAnimationFloatFrame(obj, b, c, frame[2], frame[3]);
}

void UpdateAnimationClassPastSimpleInfo(void *arg0)
{
    (*(float *)((char *)(arg0) + 0xC)) = (float) (*(float *)((char *)(arg0) + 8));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", GetAnimationClassCurrentInfoDirectResource);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", SetAnimationClassLastInfoDirectResource);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", func_40051478);

int GetAnimationDefObjLeaveType(int arg0)
{
    return arg0 != 3;
}

char *GetAnimationDefClass(u8 *p)
{
    if (p[0x8] != 0x12) {
        return 0;
    }
    return (char *)p + 0x1C;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0053_constructor_neck_turn", getAnimationDefByName);
extern s32 DldSysUndefSymbol;
s32 strcmp(const char *, const char *);

/* dld link word: bits 0..17 = byte distance back to a slot holding the target (or DldSysUndefSymbol) */
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

u8 *getAnimationDefByName(u32 *lp, const char *name)
{
    s32 n;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    n = cnt - 1;
    for (; n != -1; n--, p += 0x74) {
        if (strcmp(*(const char **)p, name) == 0) {
            return p;
        }
    }
    return NULL;
}
