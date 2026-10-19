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
extern s32 GetLayoutClass(s32);
extern void GetGeometryPointerPosition(void *, int);

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_Shoulder);
void nico_player_pendulum_Shoulder(void *o)
{
    s128 pos;
    s128 v;
    int cls = *(int *) o;
    if (D_40206DA4 != 0)
    {
        GetGeometryPointerPosition(&pos, GetLayoutClass(cls) + 0xC0);
        v = pos;
        D_40206DA0 = func_400A1830(o, &v, D_40206D50, (char *) &D_40206D90, (char *) &D_40206D80, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_FootEffector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", nico_player_pendulum_Leg);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", pendulum_test);

typedef union {
    u128 q;
    f32 f[4];
} AvoidVec;

s32 ClipCollisionFinderCallBack(void *res, AvoidVec *from, AvoidVec *to, void *col, void *filter, s32 arg);
s32 character_ikcolattrfilter();

void nico_player_avoid_ControlRootY(s32 *w)
{
    u8 *c = GetCharacterClass((void *)w[0]);
    u8 *m = (u8 *)(w[5] * 0x40 + w[2]);
    AvoidVec from;
    AvoidVec to;
    struct {
        u8 pad[0x44];
        f32 y;
        u8 pad2[0x8];
    } res;

    from.q = *(u128 *)(m + 0x30);
    to.q = from.q;
    from.f[1] = *(f32 *)(c + 0x44);
    to.f[1] = *(f32 *)(m + 0x34) + 0.15f;
    if (ClipCollisionFinderCallBack(&res, &from, &to, c + 0xD90, character_ikcolattrfilter, 0) != 0)
        *(f32 *)(c + 0x44) = *(f32 *)(c + 0x44) - (to.f[1] - res.y);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0118_nico_player_colfit_GetLower", player_updateSlipEffect);

/* NEARMISS-STUB player_initSlipEffect */
#if 0 /* NEARMISS 89.818184% cat=sched sub=- | gcc schedules sw 0x30 and sw 0x0(a1)/sd out of source order; target keeps REA order | attempts=1 */
extern s32 D_40206DA8[];

void player_initSlipEffect(void *actor, u64 *effect)
{
    s32 *slip = D_40206DA8;
    effect[1] = 0;
    *(s32 *)effect = 0;
    slip[7] = 1;
    slip[13] = 2;
    slip[14] = 0;
    slip[0] = 0;
    slip[1] = 0;
    slip[2] = 0;
    slip[3] = 0;
    slip[8] = 0;
    slip[4] = 0;
    slip[5] = 0;
    slip[6] = 0;
    slip[9] = 0;
    slip[10] = 0;
    slip[11] = 0;
    slip[12] = 0;
}
#endif
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
