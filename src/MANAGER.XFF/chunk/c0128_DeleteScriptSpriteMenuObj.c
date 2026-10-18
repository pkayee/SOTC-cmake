#include "common.h"

extern void flushScriptObj(unsigned char *);

void DeleteScriptSpriteMenuObj(unsigned char *p)
{
    unsigned char *m = p[8] != 0x21 ? 0 : p + 0x20;
    void (*f)(unsigned char *);
    flushScriptObj(p);
    f = *(void (**)(unsigned char *))(m + 0xA0);
    if (f != 0)
        f(p);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", CreateScriptSpriteMenuObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", spriteMenuCheckSelectPushPad);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", spriteMenuObjPadChangeHorse);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6A90);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6AF8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", FlushScriptSpriteMenuObj);
s32 FlushScriptSpriteMenuObj(void) {
    return 0;
}

void flushScriptObjImmediate();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6B98);
void func_400A6B98(void)
{
    flushScriptObjImmediate();
}

extern int D_4012B2A8;
extern int MenuControlButtonContext_control_america;

void setDefaultMenuControlButton(void)
{
    D_4012B2A8 = MenuControlButtonContext_control_america;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6BC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", InitSpriteObj);

char *GetSpriteClass(unsigned char *p)
{
    if (p[0x8] != 0xE) {
        return 0;
    }
    return (char *)p + 0x90;
}

int FlushSpriteObj(char *obj)
{
    char *sprite = ((unsigned char *)obj)[8] == 0xE ? obj + 0x90 : 0;

    *(int *)(sprite + 0x4C) = 0;
    if (*(int *)(sprite + 0x50) == 0) {
        *(int *)(sprite + 0x50) = 1;
    }
    return 0;
}

void DeleteScriptSpriteObj(unsigned char *o)
{
    unsigned char *c = o[8] != 0xE ? 0 : o + 0x90;
    unsigned char *d = o[8] != 0xE ? 0 : o + 0x20;
    *(int *)(c + 0x4C) = 0;
    if (*(int *)(c + 0x50) == 0)
        *(int *)(c + 0x50) = 1;
    flushScriptObj(o);
    if (*(void (**)(unsigned char *))(d + 0xCC) != 0)
        (*(void (**)(unsigned char *))(d + 0xCC))(o);
}

char *GetScriptSpriteClass(unsigned char *p)
{
    if (p[0x8] != 0xE) {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", GetSpriteObjWorkSize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", GetScriptSpriteObjWorkSize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", CreateScriptSpriteObj);

void ExecScriptSpriteObj(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A7260);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A7360);
void func_400A7360(void)
{
    flushScriptObjImmediate();
}

char *GetSubLinkClass(unsigned char *p)
{
    if (p[0x8] != 0x15) {
        return 0;
    }
    return (char *)p + 0x1C;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", CreateSubLinkObj);

extern void *memcpy(void *, const void *, unsigned int);

void SetSubLinkObjDeleteFuncInfo(unsigned char *p, int func, void *data, int size)
{
    unsigned char *s = p[8] != 0x15 ? 0 : p + 0x1C;
    *(int *)(s + 0xC) = func;
    if (data != 0)
        memcpy(*(void **)(s + 0x10), data, size);
}
