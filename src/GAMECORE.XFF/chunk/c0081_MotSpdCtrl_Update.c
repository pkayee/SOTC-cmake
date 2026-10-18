#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", MotSpdCtrl_Update);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", SearchNearestObjByGroup);

typedef struct {
    s32 state;
    char pad4[0x60];
    f32 time;
} DamageClass;

u8 *GetDamageClass(s32 a0);
s32 GetDamagerClassDamageSheetType(DamageClass *d);

s32 IsDamaged(void *actor, s32 type)
{
    DamageClass *d = (DamageClass *)GetDamageClass((s32)actor);

    if (d->state == 1 && (type < 0 || GetDamagerClassDamageSheetType(d) == type) && d->time > 0.0f) {
        return 1;
    }
    return 0;
}

void ColCont_Reset(char *p)
{
    *(s32 *)(p + 0x8) = 0;
    *(s64 *)(p + 0x0) = 0;
}

typedef struct {
    char pad[0x180];
    float dt;
} GVar;

extern GVar gcGlobalVar;
u8 *GetLayoutClass(void *obj);
u8 *GetCharacterClass(void *obj);

void ColCont_Update(long *cc, void *obj, int keep)
{
    if (*(int *)(GetLayoutClass(obj) + 0x124) == 0) {
        float dt = gcGlobalVar.dt;

        *(float *)(cc + 1) += dt;
        if (keep == 0) {
            *(float *)(cc + 1) += gcGlobalVar.dt;
            if (0.5f < *(float *)(cc + 1)) {
                *(int *)(cc + 1) = 0;
                cc[0] = 0;
            }
        }
    } else {
        cc[0] = *(long *)(GetCharacterClass(obj) + 0x680);
    }
}

int ColCont_IsColStatus(long *p, long mask, long value)
{
    if (value != -1) {
        if ((*p & mask) == value)
            return 1;
    } else if (*p & mask)
        return 1;
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", ColCont2_Init);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", ColCont2_Release);

int ColCont2_IsColStatus(long *p, long mask, long value)
{
    if (value != -1) {
        if ((*p & mask) == value)
            return 1;
    } else if (*p & mask)
        return 1;
    return 0;
}

s32 ColCont2_IsParentObj(void *arg0, s32 arg1)
{
    s32 temp_v0;

    if (*(s32 *)((char *)arg0 + 0x18) != 0) {
        temp_v0 = *(s32 *)((char *)arg0 + 0x8);
        if (temp_v0 != 0) {
            return arg1 == *(s32 *)(GetLayoutClass((void *)temp_v0) + 0x1A4);
        }
    }
    return 0;
}

void MotSpdCtrl_Reset(char *p);

void MotSpdCtrl_Init(char *p, int a)
{
    MotSpdCtrl_Reset(p);
    *(int *)(p + 0x14) = a;
}

typedef struct {
    f32 rot;
    f32 start;
    f32 end;
    f32 spd;
    u8 active;
    u8 dir;
    char pad[2];
    f32 *rate;
} MotSpd;

s32 MotSpdCtrl_StartExt(s32 a, s32 b, s32 c, s32 d, f32 scale);

s32 MotSpdCtrl_Start(s32 a, s32 b, s32 c, s32 d)
{
    return MotSpdCtrl_StartExt(a, b, c, d, 1.0f);
}

s32 MotSpdCtrl_StartExt(s32 a, s32 b, s32 c, s32 d, f32 scale)
{
    MotSpd *m = (MotSpd *)a;

    if (m->rate == 0)
        return 0;
    m->spd = scale;
    if (m->rate[1] == 0.0f && m->rate[2] == 0.0f)
        return 0;
    if (m->active == 0) {
        m->active = 1;
        m->start = *(f32 *)(GetCharacterClass((void *)b) + 0x514);
        m->rot = 6.283185307179586f;
        m->dir = 0;
        return 1;
    }
    m->dir = 1;
    m->rot = 6.283185307179586f;
    m->end = *(f32 *)(GetCharacterClass((void *)b) + 0x514);
    return 0;
}

void MotSpdCtrl_Reset(char *p)
{
    *(char *)(p + 0x10) = 0;
    *(int *)(p + 0x0) = 0;
    *(char *)(p + 0x11) = 0;
}

s32 MotSpdCtrl_SetSpeed(void *work, void *actor, f32 speed)
{
    s32 result;
    s32 enabled;

    enabled = *(s32 *)((char *)work + 0x14) != 0;
    result = 0;
    if (enabled) {
        do {
            if (*(u8 *)((char *)work + 0x10) != 0) {
                return 0;
            }
            *(f32 *)((char *)GetCharacterClass(actor) + 0x514) = speed;
            result = 1;
        } while (0);
        return result;
    }
    return result;
}

void MotSpdCtrl_SetParam(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x14)) = arg1;
}

s32 IsColStatus(void *o, long mask, long value)
{
    if (o != 0) {
        u8 *l = GetLayoutClass(o);
        u8 *c = GetCharacterClass(o);

        if (*(int *)(l + 0x124) != 0 && (*(long *)(c + 0x680) & mask) == value)
            return 1;
    }
    return 0;
}

s32 IsColStatusCUP(void *o, long m1, long m2)
{
    if (o != 0) {
        u8 *lc = GetLayoutClass(o);
        u8 *cc = GetCharacterClass(o);

        if (*(int *)(lc + 0x124) != 0 && (*(long *)(cc + 0x680) & m1 & m2) != 0)
            return 1;
    }
    return 0;
}

s32 nico_GetGeometryPointerAttr(void *g);

s32 IsGeoColStatus(void *g, s32 mask, s32 value)
{
    return (nico_GetGeometryPointerAttr(g) & mask) == value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", func_40071C60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0081_MotSpdCtrl_Update", demo_battle);
