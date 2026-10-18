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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F86C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetDamageDefByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAttributeRelationEffectDefByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAnimationEffectDefByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetCollisionDetectEffectWaterOnlyDefByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", GetAnimationFogDefByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F8C58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F8EE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9178);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F94E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9950);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0201__SetMultiCastLetterReceiverInfo", func_400F9BB0);
