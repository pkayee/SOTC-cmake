#include "common.h"

/* func_4011A2F8: walk attack rows (stride 0x54); first row whose cond, list and volume pass drives the script status and pin IK target */
extern s32 DldSysUndefSymbol;
extern char *GetCharacterClass(void *);

extern f32 iosGetRandom();

static inline u8 *dldElem(u32 *lp) {
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}
static inline s32 dldCnt(u32 *lp) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(s32 *)(slot + 0xC) : 0;
}
extern void *getSCRDataCtrlWork(void *);
extern u8 *GetLayoutClass(void *chara);
extern s32 execCondition();
extern s32 func_4011A608();
extern u32 *func_4011AD88();
extern s32 func_4011AC08();
extern s32 CheckPositionInsideOfJudgeVolumeObject();
extern void CharaCtrlSetScriptCtrlStatus();
extern void SCRSetCharacterObjPinAttackIKTargetInfo();

void func_4011A2F8(void *actor, void *target)
{
    u8 *lay = GetLayoutClass(target);
    u8 *row = *(u8 **)((u8 *)getSCRDataCtrlWork(actor) + 0x40A0);
    u8 vol[0x60];

    for (; dldElem((u32 *)(row + 0x24)) != NULL; row += 0x54) {
        if (dldElem((u32 *)(row + 0x24)) != NULL && execCondition(actor, row + 0x1C) && func_4011A608(actor, row + 0xC) &&
            CheckPositionInsideOfJudgeVolumeObject(vol, actor, func_4011AD88(actor, row), *(void **)(lay + 0x134)) &&
            func_4011AC08(actor, row)) {
            u8 *a = dldElem((u32 *)(row + 0x34));
            u8 *b = dldElem((u32 *)(row + 0x38));

            if (a != NULL) {
                CharaCtrlSetScriptCtrlStatus(actor, *(s32 *)(a + 4));
            }
            if (b != NULL) {
                CharaCtrlSetScriptCtrlStatus(actor, *(s32 *)(b + 4));
            }
            if (dldElem((u32 *)(row + 0x40)) != NULL) {
                SCRSetCharacterObjPinAttackIKTargetInfo(actor, *(s32 *)(dldElem((u32 *)(row + 0x40)) + 8), *(void **)(lay + 0x134), row + 0x44, 0);
            }
            return;
        }
    }
}

/* func_4011A608: returns 1 if the dld list at lp is absent or contains the character class +0x740 entry */
s32 func_4011A608(void *actor, u32 *lp)
{
    u8 *cc = (u8 *)GetCharacterClass(actor);
    u32 *tab = (u32 *)dldElem(lp);
    s32 n;
    s32 i;

    if (tab == NULL) {
        return 1;
    }
    n = dldCnt(lp);
    for (i = 0; i < n; i++) {
        if (*(u8 **)(cc + 0x740) == dldElem(&tab[i])) {
            return 1;
        }
    }
    return 0;
}

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

/* setAttackHeadDataFormNewMode: attack work +0x40A0 = element 0x10 of the dld element at ctrl+0x4080, +0x40B0 = 0 */
void setAttackHeadDataFormNewMode(void *actor)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;
    u8 *e = dldElem(*(u32 **)((u8 *)getSCRDataCtrlWork(actor) + 0x4080));

    *(u8 **)w = dldElem((u32 *)(e + 0x10));
    *(s32 *)(w + 0x10) = 0;
}

/* setAttackHeadDataFormNowMode: as NewMode but the head pointer is at ctrl+0x407C */
void setAttackHeadDataFormNowMode(void *actor)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;
    u8 *e = dldElem(*(u32 **)((u8 *)getSCRDataCtrlWork(actor) + 0x407C));

    *(u8 **)w = dldElem((u32 *)(e + 0x10));
    *(s32 *)(w + 0x10) = 0;
}

void func_4011AA38(void *actor, int a1, int a2, void *a3)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;

    *(s32 *)(w + 0x10) = 0;
    *(s32 *)(w + 0x8) = *(s32 *)(w + 0x8) + 1;
    if (a3 != 0) {
        *(f32 *)(w + 0x14) = *(f32 *)((u8 *)a3 + 0x4C);
    }
}

/* func_4011AA80: attack work +4 = candidate row; chance (+8 percent) passed -> work+0 = its element. lp assigned inside the row test (T-c0221) */
void func_4011AA80(void *actor)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;
    u8 *row = *(u8 **)(w + 4);
    u32 *lp;
    s32 ok;

    if (row != NULL) {
        lp = (u32 *)(row + 4);
        if (dldElem(lp) != NULL) {
            ok = 1;
            if (*(f32 *)(row + 8) < 100.0f) {
                if (*(f32 *)(row + 8) < iosGetRandom() * 100.0f) {
                    ok = 0;
                }
            }
            if (ok) {
                *(u8 **)w = dldElem(lp);
            }
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011ABD0);
void func_4011ABD0(void *actor, int a1, int a2, void *a3)
{
    u8 *w = (u8 *)getSCRDataCtrlWork(actor) + 0x40A0;

    if (a3 != 0) {
        *(f32 *)(w + 0x14) = *(f32 *)((u8 *)a3 + 0x4C);
    }
}

/* NEARMISS-STUB func_4011AC08 */
#if 0 /* NEARMISS 66.5% cat=regalloc sub=- | ret var in v1 not v0; const 1 hoisted to a2; compiler tail shape differs | attempts=1 */
u32 func_4011AC08(void *actor, void *a1)
{
    u8 *w;
    s32 type;
    u32 ret = 0;

    w = (u8 *)getSCRDataCtrlWork(actor) + 0x4010;
    if (a1 != 0) {
        type = *(s32 *)((u8 *)a1 + 0x18);
        if (type == 1) {
            ret = *(u32 *)(w + 0x2C);
        } else if (type < 2) {
            ret = 1;
            if (type != 0) {
                ret = 0;
            }
        } else if (type == 2) {
            ret = *(u32 *)(w + 0x30) | *(u32 *)(w + 0x34);
        } else {
            ret = 0;
        }
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", func_4011AC08);

/* func_4011AC80: row dld refs at +0x28 and +0x2C both resolve and the condition at +0x2C holds */
s32 func_4011AC80(void *actor, u8 *row)
{
    if (dldElem((u32 *)(row + 0x28)) != NULL) {
        if (dldElem((u32 *)(row + 0x2C)) != NULL && execCondition(actor, row + 0x2C)) {
            return 1;
        }
    }
    return 0;
}

/* func_4011AD88: pick the lock pointer: row+0x28 if refs resolve and condition at +0x2C holds, else row+0x24 (flag set by if/else, T-c0221) */
u32 *func_4011AD88(void *actor, u8 *row)
{
    u32 *lp = (u32 *)(row + 0x28);
    s32 ok;

    if (dldElem(lp) != NULL && dldElem((u32 *)(row + 0x2C)) != NULL && execCondition(actor, row + 0x2C)) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok != 0) {
        return lp;
    }
    return (u32 *)(row + 0x24);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncCheckBoneColAndSendDamage);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncDamageSendFunc);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0221_func_4011A2F8", SCRFuncSetNextRouteMaxAngle);
extern void setRouteMinAngle(void *, f32);

void SCRFuncSetNextRouteMaxAngle(void *actor, f32 deg)
{
    setRouteMinAngle(getSCRDataCtrlWork(actor), (180.0f - deg) * 3.1415926f / 180.0f);
}

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
