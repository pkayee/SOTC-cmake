#include "common.h"

u64 *GetCollisionDBAttributeAdr(void *surface);

s32 arrowFilter(void *surface)
{
    u64 attribute = *GetCollisionDBAttributeAdr(surface);
    u64 flags = attribute & (0xF800UL << 20);
    u64 material = attribute & 0x7C000000UL;
    u64 mode = attribute & (0xF000UL << 30);

    if (material == 0x04000000UL || material == 0x64000000UL || material == 0x68000000UL ||
        material == 0x6C000000UL)
    {
        return 0;
    }
    if (material == 0x24000000UL || flags == (0x8000UL << 18) || flags == (0xB800UL << 20) ||
        flags == (0xC000UL << 18) || flags == (0xA000UL << 19) || flags == (0xE000UL << 18) ||
        flags == (0xA000UL << 18) || mode == (0x8000UL << 28))
    {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", getSoundBowPos);

extern void *isysGetThisSubThread(void);
extern char *D_40202714;

int existSoundBow(void)
{
    char *e;
    char *next;

    isysGetThisSubThread();
    for (e = D_40202714; e != 0; e = next) {
        next = *(char **)(e + 0xC0);
        if (*(int *)(e + 0x48) == 6) {
            if (*(short *)(e + 0xA0) == 0)
                return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", chkNearStickArrow);

extern void func_40045D88(void *);

void allArrowRelease(void)
{
    void *temp_s0;
    void *var_a0;

    var_a0 = D_40202714;
    if (var_a0 != 0) {
        do {
            temp_s0 = *(void **)((char *)var_a0 + 0xC0);
            func_40045D88(var_a0);
            var_a0 = temp_s0;
        } while (var_a0 != 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", arrowObjThrustParent);

extern char *GetLayoutClass(void *);
extern void *GetGeometryPointerObject(void *);

int getArrowObjParent(void *parent)
{
    char *p = D_40202714;
    int n = 0;

    while (p != 0) {
        char *next = *(char **)(p + 0xC0);
        char *c = GetLayoutClass(*(void **)(p + 0x94));

        if (*(int *)(c + 0x124) != 0 && parent == GetGeometryPointerObject(c + 0xC0)) {
            short t = *(short *)(p + 0xA0);

            if (t == 2 || t == 5)
                n++;
        }
        p = next;
    }
    return n;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048B50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048B60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048C50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048C70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048D08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048D48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", nico_birdBossStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", SCRFuncBirdSetAttainPosForPathData);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_400490F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", SCRFuncBirdSetLandingPos);

extern void *GetSCRCharaAIWorkPtr(void *);

void SCRFuncBirdInitRotMode(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B0)) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", SCRFuncBirdInputRotateMotionKey);
