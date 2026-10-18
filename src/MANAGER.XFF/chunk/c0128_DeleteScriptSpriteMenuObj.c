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

extern u8 padManagerData[];
extern int D_4012B2A8;

s32 spriteMenuCheckSelectPushPad(void)
{
    s8 *sel = *(s8 **)&D_4012B2A8;
    s32 pad = *(s32 *)(padManagerData + 0x8);
    s32 bit = 1;

    return (pad & (bit << sel[0])) ? 1 : ((pad & (bit << sel[1])) ? -1 : 0);
}

/* NEARMISS-STUB spriteMenuObjPadChangeHorse */
#if 0 /* NEARMISS 67.0% cat=bitops sub=- | target keeps sllv+and mask for 1<<sel; ours folds to srav+andi; return-2 tail differs | attempts=1 */
extern void mcGetCompleteTimeAttack(int *arg0, int *arg1);
extern u8 padManagerData[];
extern int D_4012B2A8;

s32 spriteMenuObjPadChangeHorse(void)
{
    s32 a;
    s32 b;

    mcGetCompleteTimeAttack(&a, &b);
    if (b == 0)
    {
        goto P;
    }
    if (a == 0)
    {
        goto Q;
    }
    if ((*(s32 *)padManagerData & (1 << *(s8 *)(*(s8 **)&D_4012B2A8 + 0xB))) != 0)
    {
        return 1;
    }
Q:
    if (b != 0)
    {
        goto L;
    }
P:
    if (a == 0)
    {
        return 0;
    }
L:
    if ((*(s32 *)padManagerData & (1 << *(s8 *)(*(s8 **)&D_4012B2A8 + 0xC))) == 0)
    {
        return 0;
    }
    return 2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", spriteMenuObjPadChangeHorse);

/* NEARMISS-STUB func_400A6A90 */
#if 0 /* NEARMISS 70.5% cat=branch-layout sub=- | target bne with hoisted v0=4 delay slot, bnel to shared epilogue; ours beql with lw in delay, b to epilogue | attempts=1 */
extern void func_400A2A10(unsigned char *, s32);

void func_400A6A90(unsigned char *p)
{
    s32 v;

    if (*(s32 *)(p + 0x4) == 1)
    {
        func_400A2A10(p, *(s32 *)(*(unsigned char **)p + 0xC));
        v = 2;
    }
    else
    {
        if (*(s32 *)(p + 0x4) != 4)
        {
            return;
        }
        func_400A2A10(p, *(s32 *)(*(unsigned char **)p + 0xC));
        v = 5;
    }
    *(s32 *)(p + 0x4) = v;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6A90);

/* NEARMISS-STUB func_400A6AF8 */
#if 0 /* NEARMISS 86.76% cat=regalloc sub=- | p/off/i get s2/s1/s3 vs target p=s2 off=s1 i=s3; ours shares wrong regs, stack save order differs | attempts=1 */
extern void func_400A4860(float, unsigned char *);

void func_400A6AF8(unsigned char *p)
{
    unsigned char *c;
    s32 off;
    s32 i;

    c = p[8] != 0x21 ? 0 : p + 0x90;
    i = 0;
    off = 0;
    if (*(s32 *)(c + 8) > 0)
    {
        do
        {
            if (*(s32 *)(*(unsigned char **)(c + 4) + off + 4) != 0)
            {
                func_400A4860(1.0f, p);
            }
            off += 0x68;
            i++;
        } while (i < *(s32 *)(c + 8));
    }
}
#endif
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", GetSpriteObjWorkSize);
int GetSpriteObjWorkSize(unsigned char *p)
{
    return *(s32 *)(p + 0x8) * 0xA7 + 0x33;
}

extern int GetScriptObjWorkSize(int *p);

int GetScriptSpriteObjWorkSize(unsigned char *p)
{
    s32 n = *(s32 *)(p + 0x8) * 0xA7;
    n = n + 0x43;
    return n + GetScriptObjWorkSize((int *)(p + 0x3C));
}

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
