#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", CreateScriptLwsOri);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A1EA0);

u8 *GetScrLwsOriClass(u8 *p)
{
    if (p[0x8] != 0x16) {
        return 0;
    }
    return p + 0x20;
}

typedef struct {
    void (*fn)(int);
    int arg;
} LwsCb;

void flushScriptObj();
void FlushCharacterObj();
void FlushChildGroupManagerObj();
void iosFree();

void FlushScriptLwsOri(u8 *o)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    LwsCb *cb = (LwsCb *)(c + 0x115C);

    if (cb->fn != 0) {
        cb->fn(cb->arg);
    }
    flushScriptObj(o);
    FlushCharacterObj(o);
    FlushChildGroupManagerObj(o);
    if (*(void **)(c + 0x1154) != 0) {
        iosFree(*(void **)(c + 0x1154));
    }
}

void SetScrLwsOriObjReleaseCallBackFunc(u8 *o, s32 a, s32 b)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    s32 *f = (s32 *)(c + 0x115C);

    f[0] = a;
    f[1] = b;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", InitScriptLwsOrientObj);

s32 GetLwsOrientWorkSize();
s32 GetScriptObjWorkSize();

s32 GetScriptLwsOrientObjWorkSize(s32 arg0)
{
    s32 temp_s1;

    temp_s1 = GetLwsOrientWorkSize();
    return temp_s1 + GetScriptObjWorkSize(arg0 + 0x134);
}

extern int D_4012B2A4;

void SetScriptLwsOrientObjDefaultScriptFunc(int arg0)
{
    D_4012B2A4 = arg0;
}

void func_400A24A0(void);
void func_400A1EA0(int **, void *, void *);
void *_isysCreateObj(void *, s32, s32, s32, void (*)(void), s32);
int GetLwsOrientNodeNum(int);

void *CreateScriptLwsOrientDefObj(void *grp, int size, int **res)
{
    int n = GetLwsOrientNodeNum(*(int *)((char *)*res + 0x20)) * 12 + 0x33;
    void *o = _isysCreateObj(grp, 0x17, 0x80, size + n, func_400A24A0, 0x10);

    func_400A1EA0(res, o, grp);
    return o;
}

char *GetScriptLwsOrientDefinfo(unsigned char *p)
{
    if (p[0x8] != 0x17) {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2338);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", DeleteScriptLwsOrientObjSubObjects);

void func_400A24A0(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", AddSortObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", GetNextSortObj);

typedef struct {
    int *items;
    int count;
    int unused[2];
    int current;
} SortList;

void *GetFirstSortObj(SortList *list)
{
    int i = 0;
    void *found = 0;
    if (list->count > 0) {
        list->current = 0;
        for (; i < list->count; i++) {
            list->current = i;
            if (list->items[i]) {
                found = (void *)list->items[i];
                break;
            }
        }
    }
    return found;
}

void InitSortObj(char *p, int a1)
{
    *(int *)(p + 0x0) = a1;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x8) = 0;
}

void ClearSortList(void *list)
{
    int *words = list;
    int i;

    for (i = 0; i < words[1]; i++) {
        ((int *)words[0])[i] = 0;
    }
    words[4] = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", CreateSortList);

void DeleteSortList(void **list)
{
    iosFree(list[0]);
    iosFree(list);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2800);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A28D8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2A10);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2BD8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2D58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A3058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A33D8);
