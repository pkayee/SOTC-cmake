#include "common.h"

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_40049790(void *character);
extern void func_400497C0(void *character);
extern void func_400497F0(void);

void SCRBirdStartBreath(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40049790);
}

void SCRBirdStopBreath(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400497C0);
}

void SCRBirdStartFlap(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400497F0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", SCRFuncBirdSetAttainNearPosForPathData);

extern void *GetSCRCharaAIWorkPtr(void *);

int SCRConditionBirdPassingEachOther(void *actor)
{
    int var_v1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    var_v1 = 1;
    if (!((*(float *)((char *)(temp_v0) + 0x41B8)) < (*(float *)((char *)(temp_v0) + 0x41B4)))) {
        var_v1 = 0;
    }
    return var_v1;
}

int SCRConditionBirdBeginningApproaching(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(*(float *)(w + 0x41B8) > *(float *)(w + 0x41B4)))
        r = 0;
    return r;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", func_40049790);
extern void _SCRStartLWS(s32, s32, s32, s32);

void func_40049790(void *character)
{
    _SCRStartLWS(*(s32 *)((u8 *)GetSCRCharaAIWorkPtr(character) + 0x4190), -1, 4, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", func_400497C0);
void func_400497C0(void *character)
{
    _SCRStartLWS(*(s32 *)((u8 *)GetSCRCharaAIWorkPtr(character) + 0x4190), -1, 1, 0);
}

void func_400497F0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", func_400497F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", st_mcBootChk);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0046_SCRBirdStartBreath", bootmccheck);

extern s32 ScriptSpriteMenuObjDef_SPRITE_BOOT_ALERT_LAYOUT;
extern void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

void bootmccheckscript(s32 a, s32 b)
{
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_BOOT_ALERT_LAYOUT, 0, 0, a, 0, b);
}

extern s32 D_40202DF8;

void bootmccheckscriptNoBoot(void)
{
    D_40202DF8 = 0;
}
