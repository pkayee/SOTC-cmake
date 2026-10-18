#include "common.h"

extern s32 motdebugprint;
extern s32 D_4012AA00;
extern s32 D_4012AA04;
extern s32 D_4012AA08;
extern s32 D_4012AA0C;
extern s32 D_4012AA10;
extern s32 D_4012AA1C;
u8 *GetCharacterClass();

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", GetCharacterClassMotionInterpNodePosition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", GetCharacterClassMotionInterpNodeLastPosition);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", GetCharacterClassMotionPhysicalNodeID);

s32 GetOptionNodePhysicalNodeId();

s32 GetCharacterClassMotionPhysicalNodeID(u8 *obj, s32 arg) {
    s32 ret = -1;
    s32 p = *(s32 *)(obj + 0x1C0);
    s32 node = *(s32 *)(obj + 0x354);

    if (p != 0) {
        s32 q = p + 0x50;

        if (q != 0) {
            ret = GetOptionNodePhysicalNodeId(node, q, arg);
        }
    }
    return ret;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterClassRootQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterClassRootQuaternionWithInterpolationGeometry);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", GetCharacterObjMotionShiftCallBackMaxEntry);

s32 GetCharacterObjMotionShiftCallBackMaxEntry(void) {
    u8 *cc = GetCharacterClass();

    if (cc == NULL) {
        return -1;
    }
    return *(s32 *)(cc + 0x2C4);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", ResetCharacterObjMotionShiftCallBackEntryAll);

s32 ResetCharacterObjMotionShiftCallBackEntryAll(void) {
    u8 *slot = GetCharacterClass();
    s32 n;
    s32 *p;

    if (slot != NULL) {
        slot += 0x2C4;
        n = *(s32 *)slot;
        p = *(s32 **)(slot + 4);
        if (n > 0) {
            do {
                n--;
                p[0] = 0;
                p[1] = 0;
                p[2] = 0;
                p[3] = 0;
                p += 4;
            } while (n != 0);
        }
        return 0;
    }
    return -1;
}

/* NEARMISS-STUB SetCharacterObjMotionShiftCallBackEntry */
#if 0 /* NEARMISS 88.4% cat=regalloc sub=- | saved arg regs s1..s4 assigned in different order (target s1=t1,s2=a2,s3=a3,s4=t0); draft return shape worse (67.8) | attempts=1 */
/* best C for SetCharacterObjMotionShiftCallBackEntry (MANAGER.XFF c0061), 88.36% (early-return form) */
s32 SetCharacterObjMotionShiftCallBackEntry(void *obj, s32 idx, s32 p2, s32 p3, s32 p4, s32 p5) {
    u8 *cc = GetCharacterClass();
    s32 *e;

    if (cc == NULL) {
        return -1;
    }
    e = (s32 *)(idx * 0x10 + *(s32 *)(cc + 0x2C8));
    e[3] = p5;
    e[0] = p2;
    e[1] = p3;
    e[2] = p4;
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjMotionShiftCallBackEntry);

/* NEARMISS-STUB SetCharacterObjParentPlaneDiscontinuousJudgeFunc */
#if 0 /* NEARMISS 55.0% cat=regalloc sub=- | xor-register+movz vs xori; obj+0x90 computed before branch | attempts=1 */
/* best partial shape (none at 100%), MANAGER.XFF c0061, scratch only */

/* SetCharacterObjParentPlaneDiscontinuousJudgeFunc: 55.8% (best of the setters) */
static inline u8 *CharacterObjJudgeSlot(u8 *obj) {
    u8 t = obj[8];

    if (t != 9 && t != 0x16) {
        return NULL;
    }
    return obj + 0x90;
}

void SetCharacterObjParentPlaneDiscontinuousJudgeFunc(u8 *obj, s32 val) {
    u8 *p = CharacterObjJudgeSlot(obj);

    *(s32 *)(p + 0xBB0) = val;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjParentPlaneDiscontinuousJudgeFunc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjParentPointXZFitGpChangeJudgeFunc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjColSphereOverrideFunc);

/* NEARMISS-STUB SetInertiaRotInterpMode */
#if 0 /* NEARMISS 69.0% cat=regalloc sub=- | xor-reg+movz slot select vs xori+movn; store order | attempts=1 */
/* SetInertiaRotInterpMode best: 69.9% (MANAGER.XFF c0061). Remaining diff: target selects the judge slot with xor+movz (a0 = t^0x16 via register); ours uses xori+movn. Body order matches. */
void SetInertiaRotInterpMode(u8 *obj) {
    u8 *p = obj + 0x90;
    u8 t = obj[8];
    u64 a;
    u64 b;
    u64 c;
    u64 d;

    if (t != 9 && t != 0x16) {
        p = NULL;
    }
    if (*(s8 *)(p + 0xA16) != 0) {
        a = *(u64 *)(p + 0xA20);
        b = *(u64 *)(p + 0xA28);
        c = *(u64 *)(p + 0xA30);
        d = *(u64 *)(p + 0xA38);
        *(s8 *)(p + 0xA19) = 1;
        *(u64 *)(p + 0xA58) = d;
        *(u64 *)(p + 0xA40) = a;
        *(u64 *)(p + 0xA48) = b;
        *(u64 *)(p + 0xA50) = c;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetInertiaRotInterpMode);
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", DebugDispCharacterStatus);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", CallMotShiftCallBackElemLeaveFunc);
typedef void (*MotShiftCallBackFunc)(void *ctx, s32 id, s32 index, s32 arg);

typedef struct MotShiftCallBackElem {
    s32 id;
    s32 unk04;
    MotShiftCallBackFunc func;
    s32 arg;
} MotShiftCallBackElem;

typedef struct MotShiftCallBackList {
    s32 count;
    MotShiftCallBackElem *elems;
} MotShiftCallBackList;

s32 CallMotShiftCallBackElemLeaveFunc(MotShiftCallBackList *list, s32 id, void *ctx) {
    s32 i = 0;
    s32 n = list->count;
    MotShiftCallBackElem *e = list->elems;

    if (n > 0) {
        do {
            if (e->id == id && e->func != NULL) {
                e->func(ctx, id, i, e->arg);
                return 0;
            }
            i++;
            e++;
        } while (i < n);
    }
    return -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", CallMotShiftCallBackElemEntryFunc);
typedef struct MotShiftCallBackElemEntry {
    s32 id;
    MotShiftCallBackFunc func;
    s32 unk08;
    s32 arg;
} MotShiftCallBackElemEntry;

typedef struct MotShiftCallBackListEntry {
    s32 count;
    MotShiftCallBackElemEntry *elems;
} MotShiftCallBackListEntry;

s32 CallMotShiftCallBackElemEntryFunc(MotShiftCallBackListEntry *list, s32 id, void *ctx) {
    s32 i;
    s32 n = list->count;
    MotShiftCallBackElemEntry *e;

    if (n != 0) {
        e = list->elems;
        for (i = 0; i < n; i++, e++) {
            if (e->id == id && e->func != NULL) {
                e->func(ctx, id, i, e->arg);
                return 0;
            }
        }
    }
    return -1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjScriptKeyEnableFlagOnDemoOrient);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", getMotionDebugPrintMode);

s32 *getMotionDebugPrintMode(void) {
    return &motdebugprint;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", getAddMotionEnableFlag);

s32 *getAddMotionEnableFlag(void) {
    return &D_4012AA00;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", getIkControlEnableFlag);

s32 *getIkControlEnableFlag(void) {
    return &D_4012AA04;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", getRootMoveDisableFlag);

s32 *getRootMoveDisableFlag(void) {
    return &D_4012AA08;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", dispCollisionFinderFlag);

s32 *dispCollisionFinderFlag(void) {
    return &D_4012AA10;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", dispCollisionKeepAreaFlag);

s32 *dispCollisionKeepAreaFlag(void) {
    return &D_4012AA0C;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", getCollisionDisableAtDirectPlayFlag);

s32 *getCollisionDisableAtDirectPlayFlag(void) {
    return &D_4012AA1C;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", GetCharacterClassMotionBaseQ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", fittingwithrot);
