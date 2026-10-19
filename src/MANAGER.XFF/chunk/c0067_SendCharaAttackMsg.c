#include "common.h"

u8 *GetLayoutClass();
void *GetDamageClass();
void SendDirectDamageLetter(s32, u8 *, s32, f32, s32);
u8 *GetGeometryPointerObject();

s32 SendCharaAttackMsg(f32 f, s32 from, u8 *obj, s32 a2, s32 a3)
{
    u8 *lc = GetLayoutClass(obj);
    u8 *next;

    if (GetDamageClass(obj) != NULL)
    {
        SendDirectDamageLetter(from, obj, a2, f, a3);
    }
    if (lc != NULL && *(s32 *)(lc + 0x124) != 0)
    {
        next = GetGeometryPointerObject(lc + 0xC0);
        if (next != NULL)
        {
            switch (obj[8])
            {
            case 10:
            case 11:
            case 13:
            case 0x16:
                return SendCharaAttackMsg(f, from, next, a2, a3);
            }
        }
    }
    return 0;
}

typedef struct { int arg; char pad[0x4C]; int type; char pad2[0xC]; } CharaMsg;
extern char *GetCharacterClass(void *);
extern void _isysSendSubMsg(void *, CharaMsg *, int);

int SendCharaControlChangeMsg(void *actor, int arg)
{
    CharaMsg m;
    char *c = GetCharacterClass(actor);
    if (c == 0)
        return 0;
    m.arg = arg;
    m.type = 1;
    _isysSendSubMsg(c + 0x1028, &m, sizeof(m));
    return 1;
}

typedef struct {
    char geo[0x40];
    void *from;
    int ctrl;
    int pad48;
    int pad4C;
    int type;
    char pad[0xC];
} CtrlMsg;

extern void CopyGeometryPointer(void *, void *);

int SendCharaControlledChangeMsg(void *a, void *b, void *geo)
{
    char *ca = GetCharacterClass(a);
    char *cb = GetCharacterClass(b);
    CtrlMsg msg;

    if (ca == 0)
        return 0;
    msg.from = b;
    msg.type = 2;
    CopyGeometryPointer(&msg, geo);
    msg.ctrl = *(int *)(cb + 0x744);
    _isysSendSubMsg(ca + 0x1028, (CharaMsg *)&msg, 0x60);
    return 1;
}

int SendCharaMotionSyncStartMsg(void *actor, int arg)
{
    CharaMsg m;
    char *c = GetCharacterClass(actor);
    if (c == 0)
        return 0;
    m.arg = arg;
    m.type = 3;
    _isysSendSubMsg(c + 0x1028, &m, sizeof(m));
    return 1;
}

int SendCharaAddMotionSyncStartMsg(void *actor, int arg)
{
    CharaMsg m;
    char *c = GetCharacterClass(actor);
    if (c == 0)
        return 0;
    m.arg = arg;
    m.type = 5;
    _isysSendSubMsg(c + 0x1028, &m, sizeof(m));
    return 1;
}

extern u128 ZeroPoint;
extern u128 IdentityQuaternion;
void SetGeometryPointerNodePosState();
void ForceParentLayoutObj();

s32 SendCharaNodeParentSetMsg(void *obj, s32 node, s32 pos)
{
    u8 gp[0x60];
    u8 *lc;

    if (GetCharacterClass(obj) == NULL)
    {
        return 0;
    }
    *(s32 *)(gp + 0x50) = 4;
    SetGeometryPointerNodePosState(gp, node, pos, &IdentityQuaternion, &ZeroPoint);
    ForceParentLayoutObj(obj, gp);
    lc = GetLayoutClass(obj);
    *(u128 *)(lc + 0x70) = ZeroPoint;
    *(u128 *)(lc + 0x60) = IdentityQuaternion;
    return 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_40063078);
extern s32 DldSysUndefSymbol;
extern void InitAnimationClass();
extern void ResetAnimeFrameTableInfo(void *, s32, s32);

void func_40063078(s32 obj, u8 *arg)
{
    u8 *q;
    u8 *q2;
    u32 word;
    s32 *p;
    s32 a;
    s32 b;

    InitAnimationClass(obj + 4);
    q = arg + 0x48;
    word = *(u32 *)q;
    if ((word & 0x3FFFF) != 0)
    {
        p = *(s32 **)(q - (word & 0x3FFFF));
    }
    else
    {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol)
    {
        a = p[4] + ((word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    }
    else
    {
        a = 0;
    }
    q2 = arg + 0x4C;
    word = *(u32 *)q2;
    if ((word & 0x3FFFF) != 0)
    {
        p = *(s32 **)(q2 - (word & 0x3FFFF));
    }
    else
    {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol)
    {
        b = p[4] + ((word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    }
    else
    {
        b = 0;
    }
    ResetAnimeFrameTableInfo((void *)(obj + 0x34), a, b);
    *(s32 *)(obj + 0x44) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_40063180);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400633C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", ForceAcceptMotion);

static inline s32 dldElem_c0067(u8 *q)
{
    u32 word = *(u32 *)q;
    s32 *p;

    if ((word & 0x3FFFF) != 0)
    {
        p = *(s32 **)(q - (word & 0x3FFFF));
    }
    else
    {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol)
    {
        return p[4] + ((word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    }
    return 0;
}

void ResetCharacterClassAnimeFrameTableInfo(s32 obj)
{
    u8 *arg = *(u8 **)(obj + 0x1C0);

    if (arg != 0)
    {
        ResetAnimeFrameTableInfo((void *)(obj + 0x1F0), dldElem_c0067(arg + 0x48), dldElem_c0067(arg + 0x4C));
    }
}

#define CF(o) (*(f32 *)(c + (o)))

void func_40063898(u8 *c, f32 dt)
{
    u8 *m;
    f32 lo;
    f32 hi;

    if (*(s32 *)(c + 0xC10) == 0)
    {
        return;
    }
    if (*(s8 *)(c + 0x5D2) != 0)
    {
        m = c + 0x1C0;
        lo = CF(0x5B8);
        hi = CF(0x5B4);
        switch (*(s32 *)(c + 0xC10))
        {
        case 1:
            *(f32 *)(m + 0x1C) += (hi - lo) * dt / CF(0x5BC) * CF(0x5D4);
            if (hi < *(f32 *)(m + 0x1C))
            {
                *(f32 *)(m + 0x1C) = hi;
            }
            break;
        case -1:
            *(f32 *)(m + 0x1C) -= (hi - lo) * dt / CF(0x5C0) * CF(0x5D4);
            if (*(f32 *)(m + 0x1C) < lo)
            {
                *(f32 *)(m + 0x1C) = lo;
            }
            break;
        case -2:
            *(f32 *)(m + 0x1C) -= (hi - lo) * dt / CF(0x5C4) * CF(0x5D4);
            if (*(f32 *)(m + 0x1C) < lo)
            {
                *(f32 *)(m + 0x1C) = lo;
            }
            break;
        }
        if (CF(0x5C8) >= *(f32 *)(m + 0x1C))
        {
            *(s8 *)(c + 0x5D0) = 1;
        }
        if (CF(0x5CC) <= *(f32 *)(m + 0x1C))
        {
            *(s8 *)(c + 0x5D1) = 1;
        }
    }
    *(s32 *)(c + 0xC10) = 0;
}

#undef CF

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400639B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400641E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400643E0);
