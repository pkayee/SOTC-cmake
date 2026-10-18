#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011A2F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011A608);

extern void *getSCRDataCtrlWork(void *);
extern void resetAttackWork(void *);

void createAttackWork(void *actor)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;
    *(s32 *)(w + 0x0) = 0;
    *(s32 *)(w + 0x14) = 0;
    resetAttackWork(actor);
}

extern char *GetCharacterClass(void *);
extern int SetCharacterObjMotionShiftCallBackEntry(void *, int, int, int, int, int);

void resetAttackWork(void *obj)
{
    int i = 0;
    char *w = getSCRDataCtrlWork(obj) + 0x40A0;
    int n = *(int *)(GetCharacterClass(obj) + 0x2C4);

    *(int *)(w + 0x4) = 0;
    *(int *)(w + 0x8) = 0;
    *(int *)(w + 0x10) = 0;
    *(int *)(w + 0xC) = 0;
    for (; i < n; i++)
        SetCharacterObjMotionShiftCallBackEntry(obj, i, 0, 0, 0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", setAttackHeadDataFormNewMode);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", setAttackHeadDataFormNowMode);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AA38);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AA80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011ABD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AC08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AC80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AD88);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncCheckBoneColAndSendDamage);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncDamageSendFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncSetNextRouteMaxAngle);

extern void *getSCRDataCtrlWork(void *);
extern void setEventLineAttr(void *, int, int);
extern void unsetEventLineAttr(void *, int, int);
extern void setEventLinePrio(void *, int, int);

void SCRFuncLineCut(void *actor, int line)
{
    setEventLineAttr(getSCRDataCtrlWork(actor), line, 4);
}

void SCRFuncLineConnect(void *actor, int line)
{
    unsetEventLineAttr(getSCRDataCtrlWork(actor), line, 4);
}

void SCRFuncLineSetRoute(void *actor, int line)
{
    setEventLineAttr(getSCRDataCtrlWork(actor), line, 2);
}

void SCRFuncLineUnsetRoute(void *actor, int line)
{
    unsetEventLineAttr(getSCRDataCtrlWork(actor), line, 2);
}

void SCRFuncLineSetForcePrio(void *actor, int line)
{
    setEventLinePrio(getSCRDataCtrlWork(actor), line, 0x81);
}

extern int allResetLineAttr();

int SCRFuncLineAllReset(void *actor)
{
    return allResetLineAttr(((int)getSCRDataCtrlWork(actor)));
}

extern int getDPGroupID(void *, int);
extern void setUserPathGroupID(char *, int, int);

void SCRFuncSetDPGroupID(void *a, int b, int c, int d, int e, int name)
{
    void *w = getSCRDataCtrlWork(a);
    int id = getDPGroupID(a, name);
    if (id != -1) {
        setUserPathGroupID(w, id, -1);
    }
    return;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncSetAttainPlayer);

typedef union { s128 q; f32 f[4]; s32 i[4]; } Vec4;
extern void setAttainmentPos(void *, Vec4 *);

void SCRFuncSetAttainNowPlayerPos(void *actor, f32 y)
{
    char *w = getSCRDataCtrlWork(actor);
    Vec4 t;

    t.q = (*(Vec4 **)(*(char **)(w + 0x405C) + 0x134))->q;
    t.f[1] += y;
    setAttainmentPos(w, &t);
}

void SCRFuncSetAttainLostPlayerPos(void *actor, f32 y)
{
    char *w = getSCRDataCtrlWork(actor);
    Vec4 t;

    t.q = ((Vec4 *)(w + 0x4010))->q;
    t.f[1] += y;
    setAttainmentPos(w, &t);
}

extern u8 *GetLayoutClass(void *chara);

void SCRFuncSetAttainMyselfPosAndGlobalY(void *a, f32 y)
{
    char *w = getSCRDataCtrlWork(a);
    Vec4 p;

    p.q = (*(Vec4 **)(GetLayoutClass(a) + 0x134))->q;
    p.f[1] = y;
    setAttainmentPos(w, &p);
}

void SCRFuncSetAttainPlayerPosAndGlobalY(void *actor, f32 y)
{
    char *w = getSCRDataCtrlWork(actor);
    Vec4 t;

    t.q = (*(Vec4 **)(*(char **)(w + 0x405C) + 0x134))->q;
    t.f[1] = y;
    setAttainmentPos(w, &t);
}

extern char gcGlobalVar[];
extern int playerPlaneJudgeFunc();
extern int ClipCollisionDirectCallBack(void *, void *, void *, void *, int, int, int, int (*)(), int);

void SCRFuncSetAttainPlayerGroundPos(void *obj, f32 h)
{
    char *w = getSCRDataCtrlWork(obj);
    Vec4 res[5];
    Vec4 to;

    to.q = **(s128 **)(*(char **)(w + 0x405C) + 0x134);
    to.f[1] = to.f[1] - h;
    if (ClipCollisionDirectCallBack(res, *(void **)(*(char **)(w + 0x405C) + 0x134), &to, gcGlobalVar + 0x230, 0, 0, 0,
                                    playerPlaneJudgeFunc, 0)) {
        res[4].f[1] = res[4].f[1] + 1.5f;
        setAttainmentPos(w, &res[4]);
    } else {
        setAttainmentPos(w, *(void **)(*(char **)(w + 0x405C) + 0x134));
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncSetAttainMyselfFrontPos);
