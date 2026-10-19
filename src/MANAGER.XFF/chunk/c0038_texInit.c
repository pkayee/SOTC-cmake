#include "common.h"

struct TexDeleteNode;
extern struct TexDeleteNode *D_4012A6A4;
void func_40040338(void);
void isysAddGroupWithLinkParam(void *, void *, s32, s32);

int strcmp(const char *, const char *);
void texScaleClut(void *mop, float *rgba);

extern s32 D_401AC5CC;
extern s32 *D_401AC5C4;
extern s32 *D_401AC5C8;
extern s32 D_4012A698;
extern float D_4012A69C;
extern float D_4012A6A0;
extern u8 D_401AC5C0[];
extern s32 rootPtn;
void isysInitGroup(void *);
void *iosMallocAlign(void *, s32, s32);
void *iosgluGetCameraContext(void);
s32 getDrawScreenWidth(void);
float iosGetATan2fExact(float, float);
void vramReset(void);

void func_40040E78(void *, float);

void texInit(s32 count)
{
    char *ctx;
    char *n;
    char *m;
    s32 i;

    D_401AC5CC = count;
    isysInitGroup(D_401AC5C0);
    D_401AC5C4 = iosMallocAlign(&rootPtn, D_401AC5CC << 2, 0x10);
    D_401AC5C8 = iosMallocAlign(&rootPtn, D_401AC5CC << 2, 0x10);
    ctx = iosgluGetCameraContext();
    if (ctx != 0)
    {
        float a;
        a = iosGetATan2fExact(*(float *)(ctx + 0xC), (float)getDrawScreenWidth() * 0.5f);
        D_4012A6A0 = a * D_4012A69C;
    }
    for (i = 0; i < D_401AC5CC; i++)
    {
        D_401AC5C4[i] = D_401AC5C8[i] = 0;
    }
    vramReset();
    n = (char *)D_4012A6A4;
    if (n != 0)
    {
        do
        {
            m = *(char **)(*(char **)(*(char **)(*(char **)(n + 4) + 0x28) + 0x20) + 0xC);
            *(s32 *)(m + 0x14) = 0;
            *(s32 *)(m + 0x10) = 0;
            *(s32 *)(m + 0x1C) = 0;
            *(s32 *)(m + 0x18) = 0;
            n = (char *)*(s32 *)(n + 0xC);
        } while (n != 0);
    }
    D_4012A698 = 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texScaleClutAlphaByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texScaleClut);

char *texName(char *o)
{
    char *t = *(char **)(o + 0x20);
    int off = 0;
    switch (*(int *)(t + 0x1C) & 0x3F) {
    case 0x13:
    case 0x1B:
        off = 0x400;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        off = 0x40;
        break;
    }
    return t + *(int *)(t + 0x18) + off;
}

extern const u8 D_40130D70[];

s32 texGetCSM1Idx(s32 index)
{
    return D_40130D70[index];
}

extern int D_4012A6B0[];

int texGetTexByteSize(int width, int height, int format)
{
    return (width * height >> D_4012A6B0[format * 3]) << 2;
}

int texGetTexTBPSize(int w, int h, int fmt)
{
    int n = w * h >> (D_4012A6B0[fmt * 3] + 6);
    return n < 1 ? 1 : n;
}

void texGetSize(void *arg0, s32 *arg1, s32 *arg2)
{
    void *temp_a3;

    temp_a3 = *(void **)((u8 *)arg0 + 0x20);
    if (temp_a3 != NULL) {
        if (*(s32 *)((u8 *)temp_a3 + 0) == 0x324F544E) {
            *arg1 = 1 << (*(u16 *)((u8 *)temp_a3 + 0x1E) & 0xF);
            *arg2 = 1 << ((*(u32 *)((u8 *)temp_a3 + 0x1C) >> 0x14) & 0xF);
        }
    } else {
        *arg2 = 0;
        *arg1 = 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texTransRequest);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texTransRequestMulti);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texResetVRAMRequest);

extern u8 D_401AC5C0[];

void *texGetTextureModuleGroup(void)
{
    return D_401AC5C0;
}

int texGetWorkSize(char *t)
{
    int off;

    if (t == 0)
    {
        return 0;
    }
    switch (*(int *)(t + 0x1C) & 0x3F)
    {
    case 0x13:
    case 0x1B:
        off = 0x400;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        off = 0x40;
        break;
    case 0x15 ... 0x1A:
    case 0x1C ... 0x23:
    case 0x25 ... 0x2B:
        off = 0;
        break;
    default:
        off = 0;
        break;
    }
    return off * 3 + 0x118;
}

void texInitialize(char *obj, char *cb)
{
    struct TexN
    {
        s32 used;
        s32 a;
        struct TexN *prev;
        struct TexN *next;
    } *n, *head;
    char *b;

    func_40040338();
    b = *(char **)(*(char **)(obj + 0x20) + 0xC);
    *(s32 *)(b + 0x34) = (s32)b;
    n = (struct TexN *)(b + 0x30);
    head = (struct TexN *)D_4012A6A4;
    n->used = 1;
    n->prev = 0;
    n->next = head;
    if (head != 0)
    {
        head->prev = n;
    }
    D_4012A6A4 = (struct TexDeleteNode *)n;
    isysAddGroupWithLinkParam(obj, D_401AC5C0, 0, 0);
    if (cb != 0)
    {
        *(char **)(cb + 0xC) = obj;
        *(s32 *)(cb + 0x10) = *(s32 *)(cb + 0x10) + 1;
    }
}

typedef struct TexDeleteNode
{
    s32 used;
    s32 a;
    struct TexDeleteNode *prev;
    struct TexDeleteNode *next;
} TexDeleteNode;

extern TexDeleteNode *D_4012A6A4;

void texDelete(char *t)
{
    TexDeleteNode *n;

    if (t == 0)
    {
        return;
    }
    n = (TexDeleteNode *)(*(char **)(*(char **)(t + 0x20) + 0xC) + 0x30);
    if (D_4012A6A4 == n)
    {
        if (n->next != 0)
        {
            n->next->prev = n->prev;
        }
        D_4012A6A4 = n->next;
    }
    else
    {
        if (n->next != 0)
        {
            n->next->prev = n->prev;
        }
        if (n->prev != 0)
        {
            n->prev->next = n->next;
        }
    }
    n->used = 0;
}

void texReset(s32 flag, float f)
{
    char *ctx;
    TexDeleteNode *n;
    char *m;
    char *o;
    s32 i;

    ctx = iosgluGetCameraContext();
    if (ctx != 0)
    {
        float a;
        a = iosGetATan2fExact(*(float *)(ctx + 0xC), (float)getDrawScreenWidth() * 0.5f);
        D_4012A6A0 = a * D_4012A69C;
    }
    for (i = 0; i < D_401AC5CC; i++)
    {
        D_401AC5C4[i] = D_401AC5C8[i] = 0;
    }
    vramReset();
    n = D_4012A6A4;
    if (n != 0)
    {
        do
        {
            o = *(char **)((char *)n->a + 0x28);
            m = *(char **)(*(char **)(o + 0x20) + 0xC);
            *(s32 *)(m + 0x14) = 0;
            *(s32 *)(m + 0x10) = 0;
            *(s32 *)(m + 0x1C) = 0;
            *(s32 *)(m + 0x18) = 0;
            if (flag != 0)
            {
                func_40040E78(o, f);
            }
            n = n->next;
        } while (n != 0);
    }
}

char *texSearchMopByName(char *name)
{
    TexDeleteNode *n;
    char *r;
    char *o;
    char *t;
    int off;

    r = 0;
    for (n = D_4012A6A4; n != 0; n = n->next)
    {
        o = *(char **)((char *)n->a + 0x28);
        t = *(char **)(o + 0x20);
        off = 0;
        switch (*(int *)(t + 0x1C) & 0x3F)
        {
        case 0x13:
        case 0x1B:
            off = 0x400;
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            off = 0x40;
        }
        if (strcmp(name, t + *(int *)(t + 0x18) + off) == 0)
        {
            r = o;
            break;
        }
    }
    return r;
}

/* NEARMISS-STUB texScaleClutAlpha */
#if 0 /* NEARMISS 83.65% cat=regalloc sub=- | REA READY drop-in scored 83.65 in-TU (apply_ready) | attempts=1 */
void texScaleClutAlpha(char *mop, float alpha)
{
    u8 *t;
    u8 *s;
    u8 *d;
    int cnt;
    int i;
    int v;
    int j;
    u8 *sp;
    u8 *dp;

    t = *(u8 **)(mop + 0x20);
    cnt = 0;
    d = *(u8 **)(*(u8 **)(t + 0xC) + 0x40);
    s = t + *(int *)(t + 0x18);
    switch (*(int *)(t + 0x1C) & 0x3F)
    {
    case 0x13:
    case 0x1B:
        cnt = 0x100;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        cnt = 0x10;
    }
    if (cnt != 0)
    {
        i = 0;
        j = 0;
        do
        {
            sp = s + j;
            dp = d + j;
            v = (int)((float)sp[3] * alpha);
            if (v < 0x100)
            {
                if (v < 0)
                {
                    v = 0;
                }
                dp[3] = v;
            }
            else
            {
                dp[3] = 0xFF;
            }
            i++;
            j = i * 4;
        } while (i < cnt);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texScaleClutAlpha);

void texScaleClutByName(char *name, float *rgba)
{
    TexDeleteNode *n;
    char *r;
    char *o;
    char *t;
    int off;

    r = 0;
    for (n = D_4012A6A4; n != 0; n = n->next)
    {
        o = *(char **)((char *)n->a + 0x28);
        t = *(char **)(o + 0x20);
        off = 0;
        switch (*(int *)(t + 0x1C) & 0x3F)
        {
        case 0x13:
        case 0x1B:
            off = 0x400;
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            off = 0x40;
        }
        if (strcmp(name, t + *(int *)(t + 0x18) + off) == 0)
        {
            r = o;
            break;
        }
    }
    if (r != 0)
    {
        texScaleClut(r, rgba);
    }
}
