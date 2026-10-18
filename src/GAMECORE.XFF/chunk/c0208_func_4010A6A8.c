#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010A6A8);

void deleteBirdCtrlWork(void) {
}

void getLandMotionOffset(char *p, s128 *out)
{
    *out = *(s128 *)(p + 0xF0);
}

void setParamBirdCtrlWork(u8 *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j)
{
    *(f32 *)(p + 0xA8) = j;
    *(f32 *)(p + 0x80) = a;
    *(f32 *)(p + 0x84) = b;
    *(f32 *)(p + 0x88) = c;
    *(f32 *)(p + 0x90) = d;
    *(f32 *)(p + 0x94) = e;
    *(f32 *)(p + 0x8C) = f;
    *(f32 *)(p + 0xA0) = i;
    *(f32 *)(p + 0x98) = __builtin_fabsf((g * 3.1415926f) / 180.0f);
    *(f32 *)(p + 0x9C) = __builtin_fabsf((h * 3.1415926f) / 180.0f);
}

void setRouteAttackBirdCtrlWork(char *p)
{
    *(int *)(p + 0x30) = 1;
    *(int *)(p + 0x154) = 1;
}

void resetRouteAttackBirdCtrlWork(char *p)
{
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x154) = 0;
}

void setFlapWingBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x34) = arg1;
}

void setHoveringBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x38) = arg1;
}

void setHoverAttackBirdCtrlWork(char *p, int arg1)
{
    *(int *)(p + 0x3C) = arg1;
}

/* NEARMISS-STUB func_4010AE58 */
#if 0 /* NEARMISS 89.0% cat=regalloc sub=- | a2/v1 swapped for constant 1 and load pointer; store order differs | attempts=1 */
u8 *GetCharacterClass(void *chara);
s32 _resetBaseMoveWork(void *arg0, void *arg1);
void func_4010AF80(void *arg0);
void func_4010AEC8(void *arg0);

void func_4010AE58(char *arg0, char *arg1)
{
    u8 *chara = GetCharacterClass(arg0);

    *(s32 *)(arg1 + 0x38) = 1;
    *(s32 *)(arg1 + 0x34) = 1;
    *(s128 *)(arg1 + 0x250) = *(s128 *)(*(u8 **)(chara + 0x13C));
    *(s32 *)(arg1 + 0x30) = 0;
    *(s32 *)(arg1 + 0x3C) = 0;
    *(s32 *)(arg1 + 0x154) = 0;
    _resetBaseMoveWork(arg0, arg1);
    func_4010AF80(arg1);
    func_4010AEC8(arg1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AE58);

/* NEARMISS-STUB func_4010AEC8 */
#if 0 /* NEARMISS 99.75% cat=sched sub=- | float stores 0x50/0x54/0x58 reordered by scheduler; target 58,50,54 | attempts=1 */
extern const f32 D_401375E4;

void func_4010AEC8(void *param)
{
    *(f32*)((u8*)param + 0x5C) = 1.0f;
    *(s32*)((u8*)param + 0x40) = 0;
    *(s32*)((u8*)param + 0x60) = 0;
    *(s32*)((u8*)param + 0x44) = 0;
    *(f32*)((u8*)param + 0x58) = D_401375E4;
    *(f32*)((u8*)param + 0x50) = D_401375E4;
    *(f32*)((u8*)param + 0x54) = D_401375E4;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AEC8);
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AEF8);

/* NEARMISS-STUB func_4010AF60 */
#if 0 /* NEARMISS 99.43% cat=regalloc sub=- | a1/a2 vs v0/v1 temporaries; load order and xor match | attempts=1 */
s32 func_4010AF60(char *p)
{
    s32 *a1 = *(s32 **)(p + 0x1C);
    return *(s32 *)((u8 *)(*(s32 **)(p + 0xCC)) + 0xBC) == *a1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AF60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AF80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", createFastLegCtrlWork);
