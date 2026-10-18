#include "common.h"

void _SetMultiCastLetterReceiverInfo(char *p, int a, void *src, unsigned int n)
{
    *(int *)p = a;
    memcpy(p + 0x10, src, n);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F8618);

void _SetLetterKindVariable(void *dst, const void *src, unsigned int n)
{
    memcpy(dst, src, n);
}

int GetLetterKindVariableData(int arg0)
{
    return arg0;
}

extern void *GetCharacterClass(void *);
extern void *GetScriptLayoutClass(unsigned char *);

void *getDamageEnableTargetLayoutClass(void *object)
{
    char *character = GetCharacterClass(object);
    char *found = 0;
    if (character != 0 && *(signed char *)(character + 0x522) != 0)
        found = character;
    if (found == 0) {
        char *layout = GetScriptLayoutClass(object);
        if (layout != 0 && *(int *)(layout + 0x2D0) != 0)
            found = layout + 0x70;
    }
    return found;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F86C0);

s32 func_400F86C0(void *object)
{
    u8 *layout = GetScriptLayoutClass(object);

    if (layout == NULL) {
        return 1;
    }
    return *(s32 *)(layout + 0x2D0) != 0;
}

extern s32 DldSysUndefSymbol;
s32 strcmp(const char *, const char *);

/* dld link word: bits 0..17 = byte distance back to a slot holding the target (or DldSysUndefSymbol),
   bits 18..29 = element index */
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetDamageDefByName);
u8 *GetDamageDefByName(u32 *lp, const char *name) {
    s32 n;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    n = cnt - 1;
    for (; n != -1; n--, p += 0x2C) {
        if (strcmp(*(const char **)p, name) == 0) {
            return p;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAttributeRelationEffectDefByName);

/* NEARMISS-STUB GetAnimationEffectDefByName */
#if 0 /* NEARMISS 93.33% cat=regalloc sub=- | extra cnt copy to s1 and nop; loop guard order differs | attempts=1 */
u8 *GetAnimationEffectDefByName(u32 *lp, const char *name) {
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    for (; cnt != 0; cnt--, p += 0x8) {
        if (strcmp(*(const char **)(p + 0x4), name) == 0) {
            return p;
        }
    }
    return NULL;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAnimationEffectDefByName);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetCollisionDetectEffectWaterOnlyDefByName);
u8 *GetCollisionDetectEffectWaterOnlyDefByName(u32 *lp, const char *name) {
    s32 i;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    if (cnt != 0) {
        p = dldRef(lp, 0x10);
        for (i = 0; i < cnt; i++, p += 0x8) {
            if (strcmp(*(const char **)(p + 0x4), name) == 0) {
                return p;
            }
        }
    }
    return NULL;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAnimationFogDefByName);
u8 *GetAnimationFogDefByName(u32 *lp, const char *name) {
    s32 i;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    if (cnt != 0) {
        p = dldRef(lp, 0x10);
        for (i = 0; i < cnt; i++, p += 0x8) {
            if (strcmp(*(const char **)p, name) == 0) {
                return p;
            }
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F8C58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F8EE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9178);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F94E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9950);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9BB0);
