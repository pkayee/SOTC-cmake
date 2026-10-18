#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0094_func_40080D90", func_40080D90);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0094_func_40080D90", demo_op2);

s32 gStatGetHorseDemoISYSObj(void);
void nico_resetHorseRidingStatusForHorse(s32 obj);

void demo_op2_resetHorseBridle(void)
{
    s32 o = gStatGetHorseDemoISYSObj();

    if (o != 0) {
        nico_resetHorseRidingStatusForHorse(o);
    }
}

extern u8 gcGlobalVar[];
extern s32 *SkelFocusDef_PLAYER_HAND_A_L;
extern s32 *SkelFocusDef_PLAYER_HAND_A_R;
extern f32 D_40134240[];
extern f32 D_40134250[];
u8 *SCRGetFirstObj(void *table);
void nico_setHorseRidingStatusForHorseIndep(s32 a, s32 b, s32 c, f32 *d, s32 e, f32 *f);

void demo_op2_setHorseBridle(void)
{
    s32 h = gStatGetHorseDemoISYSObj();

    if (h != 0) {
        nico_setHorseRidingStatusForHorseIndep(h, (s32)SCRGetFirstObj(gcGlobalVar + 0x2B0), SkelFocusDef_PLAYER_HAND_A_L[2],
                                               D_40134240, SkelFocusDef_PLAYER_HAND_A_R[2], D_40134250);
    }
}

extern void *isysGetThisSubThread(void);
extern char D_40131970[];
void bootTexAlphaAnim(void *, void *, f32, f32);

void nico_SmokemanBodyTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131970, 0.0f, -0.0075f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0094_func_40080D90", optionMenuParamSetDefault);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0094_func_40080D90", optionMenuParamSetLoadData);
