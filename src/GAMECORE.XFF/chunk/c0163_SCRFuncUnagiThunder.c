#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", SCRFuncUnagiThunder);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", func_400D8C40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", func_400D8EC8);

extern char D_40131EC0[];
extern char D_40131ED8[];
extern char D_40131EF0[];
extern char D_40131F08[];
extern char D_40131F20[];
extern char D_40131F38[];
extern void *isysGetThisSubThread(void);
void bootTexAlphaAnim(void *, void *, f32, f32);

void nico_eelAllTexEnd(void)
{
    void *th = isysGetThisSubThread();

    bootTexAlphaAnim(th, D_40131EC0, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131ED8, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131EF0, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131F08, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131F20, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131F38, 0.0f, -0.05f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", func_400D9188);

extern void *GetSCRCharaAIWorkPtr(void *);
extern void GAMEUTIL_set_custom_boss_interest_position(s128 *v);
extern void GAMEUTIL_set_auto_get_flag_boss_interest_position(int arg0);

void SCRFuncUnagiSetPlayerGazePos(void *actor)
{
    GAMEUTIL_set_custom_boss_interest_position((s128 *)((char *)GetSCRCharaAIWorkPtr(actor) + 0x5AB0));
    GAMEUTIL_set_auto_get_flag_boss_interest_position(0);
}

typedef struct {
    char pad[0x5A70];
    float unk5A70;
    float unk5A74;
    float unk5A78;
    float unk5A7C;
} UnagiWork;

void SCRFuncUnagiSetAttackParam0(void *actor, float a, float b, float c, float d)
{
    UnagiWork *w = ((UnagiWork *)GetSCRCharaAIWorkPtr(actor));

    w->unk5A70 = a;
    w->unk5A74 = b;
    w->unk5A78 = c;
    w->unk5A7C = d;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", SCRFuncUnagiSetAttackParam1);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", SCRConditionUnagiSelectAttackLine);

int SCRConditionUnagiDamageCheck(void *arg0, int arg1)
{
    void *temp_v1;

    temp_v1 = GetSCRCharaAIWorkPtr(arg0);
    switch (arg1) {
    case 1:
        return (*(int *)((char *)(temp_v1) + 0x5A50));
    case 0:
        return (*(int *)((char *)(temp_v1) + 0x5A4C));
    case 2:
        return (*(int *)((char *)(temp_v1) + 0x5A54));
    default:
        return 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", SCRConditionUnagiCheckAttackLine);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", SCRFuncUnageSetAttackPos);

void SCRFuncUnageIncTblIdx(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(int *)((char *)(temp_v0) + 0x5A88)) = (int) (((*(int *)((char *)(temp_v0) + 0x5A88)) + 0x11) & 0x1F);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0163_SCRFuncUnagiThunder", spriteweaponsight);
