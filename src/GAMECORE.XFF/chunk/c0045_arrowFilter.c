#include "common.h"

u64 *GetCollisionDBAttributeAdr(void *surface);

/* GAMECORE c0045 PROVEN 100. arrow obj +0x94 = layout id; GetLayoutClass then tail call (non-void-less void wrapper, no return statement). */
extern void UpdateLayoutClassPastGeometry();

/* GAMECORE c0045 PROVEN 100. 0x50-byte stack surface buffer; clip, copy into dst, return 1/0. */
extern s32 ClipCollisionVariableXZSurface();
extern void CopyGeometryPointer();

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

extern char *GetLayoutClass(void *);
extern void *GetGeometryPointerObject(void *);

int arrowObjThrustParent(void *parent)
{
    char *p = D_40202714;

    while (p != 0) {
        char *next = *(char **)(p + 0xC0);
        char *c = GetLayoutClass(*(void **)(p + 0x94));

        if (*(int *)(c + 0x124) != 0 && parent == GetGeometryPointerObject(c + 0xC0)) {
            short t = *(short *)(p + 0xA0);

            if (t == 2 || t == 5) {
                *(float *)(p + 0x98) = 180.0f;
                return 1;
            }
        }
        p = next;
    }
    return 0;
}

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

/* GAMECORE c0045 PROVEN 100. arrow obj: set flag halfword +0xAA = 1. */
void func_40048B50(u8 *p)
{
    *(s16 *)(p + 0xAA) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048B60);

void func_40048C50(u8 *p)
{
    UpdateLayoutClassPastGeometry(GetLayoutClass(*(void **)(p + 0x94)));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0045_arrowFilter", func_40048C70);

s32 func_40048D08(void *dst)
{
    u8 buf[0x50];

    if (ClipCollisionVariableXZSurface(buf) != 0)
    {
        CopyGeometryPointer(dst, buf);
        return 1;
    }
    return 0;
}

void SetLayoutObjAccessSwitchThisObjOnly(void *, s32);

void func_40048D48(u8 *w)
{
    s32 k;

    *(s32 *)(w + 0x98) = 0;
    SetLayoutObjAccessSwitchThisObjOnly(*(void **)(w + 0x94), 0);
    switch (*(s32 *)(w + 0x4C)) {
    case 0:
    case 2:
        *(s16 *)(w + 0xA0) = 1;
        break;
    case 1:
        k = *(s32 *)(w + 0x48);
        if (k == 4 || k == 6) {
            *(s16 *)(w + 0xA0) = 2;
        } else if (k == 7) {
            *(s16 *)(w + 0xA0) = 4;
        } else if (k == 5) {
            *(s16 *)(w + 0xA0) = 5;
        }
        break;
    }
}

/* NEARMISS-STUB nico_birdBossStart */
#if 0 /* NEARMISS 87.0% cat=vu0-mmi sub=- | sqc2 vf0 zero store vs sd pair; callee func_400490F8 is asm | attempts=1 */
extern s32 rootPtn;
void func_400490F8(s32 *a0);
s32 SCRGetSizeOfBossWork(void *thread);
void *iosCreatePartition(void *parent, s32 size);
u8 *GetScriptCharacterClass(void *thread);
void CharaCtrlResetCtrlStatus(void *chara);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void *_SCRMallocAlign(void *ptn, s32 size, s32 align);
void *SCRCharaInitBossWork(void *ptn, void *thread);
void SCRReleaseBossWork(void);
void SetScriptCharacterObjReleaseCallBackFunc(void *chara, void *func, void *arg);
void *GetScriptClass(void *chara);
void initScriptDataSystem(void *chara, void *data);
void isysJumpSubThread(void *func, void *arg);

void nico_birdBossStart(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(&rootPtn, size + 0x41F3);
    u8 *cls = GetScriptCharacterClass(thread);
    void *mem;
    void *boss;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x41C0, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    CharaCtrlResetCtrlStatus(thread);
    cls = GetScriptClass(thread);
    initScriptDataSystem(thread, *(void **)(cls + 0x48));
    *(s32 *)((u8 *)mem + 0x4194) = 0;
    *(s32 *)((u8 *)mem + 0x4198) = 0;
    *(u64 *)((u8 *)mem + 0x41A0) = 0;
    *(u64 *)((u8 *)mem + 0x41A8) = 0;
    *(s32 *)((u8 *)mem + 0x41B4) = 0;
    *(s32 *)((u8 *)mem + 0x41B8) = 0;
    isysJumpSubThread(func_400490F8, mem);
}
#endif
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
