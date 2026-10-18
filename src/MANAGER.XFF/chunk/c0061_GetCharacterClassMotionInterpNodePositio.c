#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

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
#if 0 /* NEARMISS 89.09% cat=regalloc sub=- | saved-arg regs order, v0=0 set before beqz in target | attempts=2 */

s32 SetCharacterObjMotionShiftCallBackEntry(void *obj, s32 idx, s32 p2, s32 p3, s32 p4, s32 p5) {
    u8 *cc = GetCharacterClass(obj);
    s32 *e;

    if (cc == NULL) {
        return -1;
    }
    e = (s32 *)(idx * 0x10 + *(s32 *)(cc + 0x2C8));
    e[0] = p2;
    e[1] = p3;
    e[2] = p4;
    e[3] = p5;
    return 0;
}
#endif
s32 SetCharacterObjMotionShiftCallBackEntry(void *object, s32 index, s32 id, s32 entry, s32 leave, s32 arg) {
    u8 *character = GetCharacterClass(object);

    if (character) {
        s32 *element = (s32 *)(index * 16 + (s32)*(u8 **)(character + 0x2C8));

        element[0] = id;
        element[1] = entry;
        element[2] = leave;
        element[3] = arg;
        return 0;
    }
    return -1;
}

void SetCharacterObjParentPlaneDiscontinuousJudgeFunc(u8 *obj, s32 val) {
    u8 *cc = chrClass(obj);

    *(s32 *)(cc + 0xBB0) = val;
}
//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjParentPlaneDiscontinuousJudgeFunc);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjParentPointXZFitGpChangeJudgeFunc);

void SetCharacterObjParentPointXZFitGpChangeJudgeFunc(u8 *obj, s32 a1, s32 a2) {
    u8 *cc = chrClass(obj);

    *(s32 *)(cc + 0xA7C) = a1;
    *(u8 *)(cc + 0xA80) = a2;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjColSphereOverrideFunc);

void SetCharacterObjColSphereOverrideFunc(u8 *obj, s32 a1, s32 a2) {
    u8 *cc = chrClass(obj);

    *(s32 *)(cc + 0x574) = a1;
    *(s32 *)(cc + 0x570) = a2;
}

/* NEARMISS-STUB SetInertiaRotInterpMode */
#if 0 /* NEARMISS 89.78% cat=regalloc sub=- | four u64 temps plus const 1 allocated in different order | attempts=2 */

void SetInertiaRotInterpMode(u8 *obj) {
    u8 *cc = chrClass(obj);
    u64 a;
    u64 b;
    u64 c;
    u64 d;

    if (*(s8 *)(cc + 0xA16) != 0) {
        a = *(u64 *)(cc + 0xA20);
        b = *(u64 *)(cc + 0xA28);
        c = *(u64 *)(cc + 0xA30);
        d = *(u64 *)(cc + 0xA38);
        *(s8 *)(cc + 0xA19) = 1;
        *(u64 *)(cc + 0xA58) = d;
        *(u64 *)(cc + 0xA40) = a;
        *(u64 *)(cc + 0xA48) = b;
        *(u64 *)(cc + 0xA50) = c;
    }
}
#endif
typedef struct {
    long a, b, c, d;
} Quad;

void SetInertiaRotInterpMode(void *o)
{
    char *obj = o;
    char *cls;

    switch ((unsigned char)obj[8]) {
    case 9:
        cls = obj + 0x90;
        break;
    case 0x16:
        cls = obj + 0x90;
        break;
    default:
        cls = 0;
    }

    if (*(signed char *)(cls + 0xA16) != 0) {
        cls[0xA19] = 1;
        *(Quad *)(cls + 0xA40) = *(Quad *)(cls + 0xA20);
    }
}
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0061_GetCharacterClassMotionInterpNodePositio", SetCharacterObjScriptKeyEnableFlagOnDemoOrient);

void SetCharacterObjScriptKeyEnableFlagOnDemoOrient(u8 *obj, s32 a1) {
    u8 *cc = chrClass(obj);

    *(u8 *)(cc + 0x527) = a1;
}

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
