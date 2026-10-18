#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texInit);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texInitialize);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texSearchMopByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texScaleClutAlpha);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0038_texInit", texScaleClutByName);
