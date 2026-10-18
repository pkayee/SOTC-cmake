#include "common.h"

extern void isysRequestDeleteObj(void *);
extern void *GetCharacterClass(void *);
extern void nico_IK_getAddSubPosition(s128 *, int, s128 *);
extern s128 D_40206D70;
extern s128 D_40206D80;
extern s128 D_40206D90;
extern s128 ZeroPoint;
extern char D_40206D50[];
extern float D_40206DA0;
extern int D_40206DA4;
extern int func_400A21E0(s128 *, void *, char *);
extern float func_400A1830(void *, s128 *, char *, char *, char *, int);

void nico_player_colfit_GetLower(int arg0)
{
    nico_IK_getAddSubPosition(&D_40206D70, arg0, &D_40206D70);
    D_40206D80 = D_40206D70;
}

void nico_player_colfit_GetUpper(int arg0)
{
    nico_IK_getAddSubPosition(&D_40206D90, arg0, &ZeroPoint);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_edgecolfit_HandEffector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_colfit_HandEffector);

void nico_player_colfit_Shoulder(void *o)
{
    s128 v;
    int r = func_400A21E0(&v, o, D_40206D50);
    D_40206DA4 = r;
    if (r != 0)
        D_40206DA0 = func_400A1830(o, &v, D_40206D50, (char *) &D_40206D90, (char *) &D_40206D80, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_HandEffector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_Shoulder);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_FootEffector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_Leg);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", pendulum_test);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_avoid_ControlRootY);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", player_updateSlipEffect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", player_initSlipEffect);

void player_resetSlipEffect(void *actor, void **effect)
{
    if (*effect != 0) {
        isysRequestDeleteObj(*effect);
        *effect = 0;
    }
}

float SCRGetPlayerTiredParam(void *actor)
{
    char *character = GetCharacterClass(actor);
    float *velocity;
    if ((!character) || (!(*((int *) (character + 0x124)))))
    {
        return 0.0f;
    }
    velocity = (float *) ((*((char **) (character + 0x19C))) + 0x88);
    {
        float value0 = *velocity;
        if ((value0 < 0.0f) ? (value0 < (-10.0f)) : (value0 > 10.0f))
        {
            return 0.1f;
        }
    }
    {
        float value1 = *((float *) ((*((char **) (character + 0x19C))) + 0x88));
        if ((value1 < 0.0f) ? (value1 < (-3.0f)) : (value1 > 3.0f))
        {
            return 0.03f;
        }
    }
    {
        float value2 = *((float *) ((*((char **) (character + 0x19C))) + 0x88));
        if ((value2 < 0.0f) ? (value2 < (-1.0f)) : (1.0f < value2))
        {
            return 0.01f;
        }
    }
    return 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", func_400A3228);
