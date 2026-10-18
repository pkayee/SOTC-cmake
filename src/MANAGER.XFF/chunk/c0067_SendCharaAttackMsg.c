#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", SendCharaAttackMsg);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", SendCharaNodeParentSetMsg);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_40063078);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_40063180);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400633C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", ForceAcceptMotion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", ResetCharacterClassAnimeFrameTableInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_40063898);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400639B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400641E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0067_SendCharaAttackMsg", func_400643E0);
