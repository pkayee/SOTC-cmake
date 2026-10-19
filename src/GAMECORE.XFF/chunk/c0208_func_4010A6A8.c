#include "common.h"

/* GAMECORE c0208 func_4010AEC8: reset block of float/int fields; PROVEN 100. The Ghidra store order is NOT the source order:
 * 16-thread permutation search found 13 of 5040 orders that match; this is the plainest one. D_401375E4 is a rodata f32 (0x7fffffff bit pattern per Ghidra). */
extern const f32 D_401375E4;

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
#if 0 /* NEARMISS 92.3% cat=sched sub=- | d2 r90: union-member .q load (alias 0) + chained x34 = x38 = 1 give the target regs (ptr v1, 1 a2); left: target stores 0x38 before the sq and 0x34 after it (ou | attempts=3 */
u8 *GetCharacterClass(void *chara);
s32 _resetBaseMoveWork(void *arg0, void *arg1);
void func_4010AF80(void *arg0);
void func_4010AEC8(char *arg0);
typedef union { u128 q; f32 f[4]; } AE58Vec;

void func_4010AE58(char *arg0, char *arg1)
{
    u8 *chara = GetCharacterClass(arg0);

    ((AE58Vec *)(arg1 + 0x250))->q = (*(AE58Vec **)(chara + 0x13C))->q;
    *(s32 *)(arg1 + 0x34) = *(s32 *)(arg1 + 0x38) = 1;
    *(s32 *)(arg1 + 0x3C) = 0;
    *(s32 *)(arg1 + 0x30) = 0;
    *(s32 *)(arg1 + 0x154) = 0;
    _resetBaseMoveWork(arg0, arg1);
    func_4010AF80(arg1);
    func_4010AEC8(arg1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AE58);

void func_4010AEC8(char *p)
{
    *(s32 *)(p + 0x40) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x44) = 0;
    *(f32 *)(p + 0x50) = D_401375E4;
    *(f32 *)(p + 0x54) = D_401375E4;
    *(f32 *)(p + 0x5C) = 1.0f;
    *(f32 *)(p + 0x58) = D_401375E4;
}
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AEF8);

/* GAMECORE c0208 func_4010AF60: (*p->x) == p->b->v; PROVEN 100. Declare the 0xCC pointer BEFORE the 0x1C one
 * (a1/a2 regs + load order come out like the target; the other declaration order or a direct expression gives 94.4). */
s32 func_4010AF60(char *p)
{
    u8 *a2 = *(u8 **)(p + 0xCC);
    s32 *a1 = *(s32 **)(p + 0x1C);
    return *a1 == *(s32 *)(a2 + 0xBC);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", func_4010AF80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0208_func_4010A6A8", createFastLegCtrlWork);
