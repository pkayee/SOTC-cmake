#include "common.h"

/* MANAGER c0114 EntryInterestGroup(base, obj, lp): lp is a dld link word (bits 0..17 = distance back to the slot holding the target table, bits 18..29 = element index); the element is table->arr(+0x10) + idx * table->desc(+8)->elemSize(+0xC). Its 16 words at +0x34 are interest flags: for every non-zero flag k add obj to the group at base + 4 + 4*k. dldElem is the same helper as in c0112/c0113. */
extern int DldSysUndefSymbol;
extern void isysAddGroupWithLinkParam(void *, void *, int, int);
/* MANAGER c0114 createScriptObj(entry, startArg, rootPtn, threadArg, extraSize, prio, parent, flags): allocates a type-6 obj (0x90 B class + sub-thread work + extra + 0x33) with func_400975D0 as delete func and func_40097640 as immediate-delete func, then fills the 9-word create info on the stack (memset 0x24, words 0,1,2,3,4,5 = a0,a1,a3,t1,t2,t3) and calls initScriptObj(obj, info, *(int*)obj). */
extern unsigned char *_isysCreateObj(void *, int, int, int, void *, int);
extern void isysSetObjImmediateDeleteFunc(void *, void *);
extern void isysInitISYSLetterObj(void *);
extern int isysGetSubThreadWorkSize(int);
extern void *memset(void *, int, unsigned int);
extern void func_400975D0(int);
extern void func_40097640(int);
extern void initScriptObj(int, int *, int);

/* MANAGER c0114 flushScriptObjImmediate: run the two delete callbacks (cls+0x54/0x58 and cls+0x5C/0x60), request deletion of every obj in the child group at cls+0x30, then delete the group. func_40097640 is byte-identical. */
extern void *GetScriptClass(unsigned char *);
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysRequestDeleteObj(int);
extern void isysGroupForExit(int, int);
extern void isysDeleteGroupAllObj(void *);

/* MANAGER c0114 func_400970C8: per-priority-group script runner (execScript calls it for each group). For every obj in the group: apply a pending exec-env reset (cls+0x38 / +0x3C), then step the sub thread by state byte cls+0x28 (0 = start with cls+0x24, 1 = wake up, other = discard letters); when the thread finished call the finish callback (cls+0x4C/0x50), set state 2 and request delete unless cls+0x29 bit 0 is set. */
extern void *GetScriptClass(unsigned char *);
extern void isysInitSubThreadExecEnv(int, int);
extern int isysWakeupSubThread(int);
extern int isysStartSubThread(int, int);
extern void isysLetterObjDiscardLetterAll(int);

/* MANAGER c0114 func_400975D0: delete callback of a script obj: clear the cb arg at +0x60 (when set), free the class work buffer (+0x34), delete the sub thread (+0), then tail-call isysFlushISYSLetterObj. */
extern void *GetScriptClass(unsigned char *);
extern void isysFlushISYSLetterObj(int);

/* MANAGER c0114 objectmanager_mallocerrorfunc: when the memory-info mode D_4012B0F0 is set, walk the 14 words D_4012B0B8[0..13]; each is used as a divisor whose quotient is unused (gcc keeps only the divide-by-zero break 7 check). Debug-print remnants (the PARTS/MATERIAL/ACTION/ETC kprintf) were compiled out. */
extern unsigned char D_4012B0F0[];
extern int D_4012B0B8[];

/* MANAGER c0114 scriptIntrSignal(sig): sig is a script interrupt signal record (u64 mask at +0: low word = priority, bit 32 = notify, bit 33 = spawn; group of waiting objs at +8; group of spawn requests at +0x10). Bit 32: every obj in the +8 group whose class (+0x38) has no pending signal, or one with lower priority, gets class+0x38 = sig and class+0x3C = link[2]. Bit 33: for each spawn request cb = link[2] (cb[1] entry, cb[2] start arg, cb[4] parent) run createScriptObj(entry, startArg, rootPtn, 0x1000, 0, class(parent)+0x20, parent, 0). Alternate entry label func_40097720 sits at +8 of this fn. */
extern int rootPtn;

static inline unsigned char *dldElem(unsigned int *lp) {
    unsigned char *slot;
    unsigned int w = *lp;
    unsigned int off = w & 0x3FFFF;

    slot = off ? *(unsigned char **)((unsigned char *)lp - off) : 0;
    return (slot != 0 && slot != (unsigned char *)DldSysUndefSymbol)
               ? *(unsigned char **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(int *)(*(unsigned char **)(slot + 8) + 0xC)
               : 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", EntryObjectManagerCollisionGroup);

void EntryInterestGroup(int base, void *obj, unsigned int *lp)
{
    unsigned char *e = dldElem(lp);
    int g = base + 4;
    int *flag = (int *)(e + 0x34);
    int i;

    for (i = 15; i >= 0; i--) {
        if (*flag++ != 0) {
            isysAddGroupWithLinkParam(obj, (void *)g, 0, 0);
        }
        g += 4;
    }
}

void deleteAmbientLightObj(void) {
}

extern unsigned char D_4012B0F0[];

void *getMemoryInfoMode(void)
{
    return D_4012B0F0;
}

extern unsigned char D_4012B0F4[];

void *getMemoryInfoLightSw(void)
{
    return D_4012B0F4;
}

void objectmanager_mallocerrorfunc(void)
{
    int i;
    int x;

    if (*(int *)D_4012B0F0 != 0) {
        for (i = 0; i < 14; i++) {
            x = 1 / D_4012B0B8[i];
        }
    }
}

extern void *GetScriptLayoutClass(unsigned char *);
extern char *GetScriptCharacterClass(unsigned char *);
extern char *GetWindowClass(unsigned char *);
extern char *GetScriptAnimationClass(unsigned char *);
extern char *GetScriptSpriteClass(unsigned char *);
extern char *GetScriptSpriteMenuClass(unsigned char *);

void *GetScriptClass(unsigned char *object)
{
    switch (object[8]) {
    case 11: return GetScriptLayoutClass(object);
    case 9: return GetScriptCharacterClass(object);
    case 12: return GetWindowClass(object);
    case 13: return GetScriptAnimationClass(object);
    case 14: return GetScriptSpriteClass(object);
    case 33: return GetScriptSpriteMenuClass(object);
    case 6:
    case 22:
    case 29: return object + 0x20;
    case 32: return object + 0x1C;
    default: return 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", initScriptObj);

void func_400970C8(int *group)
{
    int obj = 0;
    int *link;
    char *s;
    int done;

    for (link = isysGroupForFirst(group, 0); link != 0; link = isysGroupForNext(link, 0)) {
        {
            obj = *link;
            s = GetScriptClass((unsigned char *)obj);
            if (*(int *)(s + 0x38) != 0) {
                *(unsigned char *)(s + 0x28) = 0;
                isysInitSubThreadExecEnv(obj, *(int *)(*(int *)(s + 0x3C) + 4));
                *(int *)(s + 0x38) = 0;
            }
            if (*(unsigned char *)(s + 0x28) == 1) {
                done = isysWakeupSubThread(obj);
            } else if (*(unsigned char *)(s + 0x28) == 0) {
                *(unsigned char *)(s + 0x28) = 1;
                done = isysStartSubThread(obj, *(int *)(s + 0x24));
            } else {
                done = 0;
                isysLetterObjDiscardLetterAll(obj);
            }
            if (done != 0) {
                if (*(void (**)(int, int))(s + 0x4C) != 0) {
                    (*(void (**)(int, int))(s + 0x4C))(obj, *(int *)(s + 0x50));
                }
                *(unsigned char *)(s + 0x28) = 2;
                if ((*(unsigned char *)(s + 0x29) & 1) == 0) {
                    isysRequestDeleteObj(obj);
                }
            }
        }
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
}

extern int execScriptGroup[];
extern void isysInitGroup(int *);

void initScriptSystem(void)
{
    int i;
    int *g = execScriptGroup;
    for (i = 15; i >= 0; i--)
        isysInitGroup(g++);
}

unsigned char *createScriptObj(int entry, int startArg, void *rootPtn, int threadArg, int extra, int prio, int parent, int flags)
{
    int info[9];
    unsigned char *obj;

    obj = _isysCreateObj(rootPtn, 6, 0x90, extra + isysGetSubThreadWorkSize(threadArg) + 0x33, (void *)func_400975D0, 4);
    isysSetObjImmediateDeleteFunc(obj, (void *)func_40097640);
    isysInitISYSLetterObj(obj);
    memset(info, 0, 0x24);
    info[0] = entry;
    info[1] = startArg;
    info[2] = threadArg;
    info[3] = prio;
    info[4] = parent;
    info[5] = flags;
    initScriptObj((int)obj, info, *(int *)obj);
    return obj;
}

extern void iosFree(void *);
extern void isysDeleteSubThread(int);

void flushScriptObj(int arg0)
{
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = GetScriptClass((unsigned char *)arg0);
    temp_v0_2 = (*(int *)((char *)(temp_v0) + 0x34));
    if (temp_v0_2 != 0) {
        iosFree((void *)temp_v0_2);
    }
    if ((*(int *)((char *)(temp_v0) + 0)) != 0) {
        isysDeleteSubThread(arg0);
    }
}

extern void func_400970C8(int *);

void execScript(void)
{
    int i;
    int *g = execScriptGroup;
    for (i = 15; i >= 0; i--)
        func_400970C8(g++);
}

void flushScriptObjImmediate(int arg0)
{
    char *s = GetScriptClass((unsigned char *)arg0);
    int obj;
    int *link;
    void *grp;

    if (*(void (**)(int, int))(s + 0x54) != 0) {
        (*(void (**)(int, int))(s + 0x54))(arg0, *(int *)(s + 0x58));
    }
    if (*(void (**)(int, int))(s + 0x5C) != 0) {
        (*(void (**)(int, int))(s + 0x5C))(arg0, *(int *)(s + 0x60));
    }
    grp = s + 0x30;
    obj = 0;
    link = isysGroupForFirst(grp, 0);
    if (link != 0) {
        obj = *link;
        while (1) {
            isysRequestDeleteObj(obj);
            link = isysGroupForNext(link, 0);
            if (link == 0) break;
            obj = *link;
        }
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
    isysDeleteGroupAllObj(grp);
}

extern int isysGetSubThreadWorkSize(int);

int GetScriptObjWorkSize(int *p)
{
    return isysGetSubThreadWorkSize(p[2]);
}

void SetScriptObjDeleteCallBackFunc(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x54) = func;
    *(int *)(s + 0x58) = arg;
}

void SetScriptObjDeleteCallBackFunc2(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x5C) = func;
    *(int *)(s + 0x60) = arg;
}

void SetScriptObjFinishCallBackFunc(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x4C) = func;
    *(int *)(s + 0x50) = arg;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", GetScriptPriorityGroup);
s32 *GetScriptPriorityGroup(s32 idx)
{
    return &execScriptGroup[idx];
}

void setScriptObjArgument(void *actor, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x24) = arg;
}

void func_400975D0(int arg0)
{
    int temp_v0_2;
    void *temp_v0;

    if (*(int *)(arg0 + 0x60) != 0) {
        *(int *)(arg0 + 0x60) = 0;
    }
    temp_v0 = GetScriptClass((unsigned char *)arg0);
    temp_v0_2 = (*(int *)((char *)(temp_v0) + 0x34));
    if (temp_v0_2 != 0) {
        iosFree((void *)temp_v0_2);
    }
    if ((*(int *)((char *)(temp_v0) + 0)) != 0) {
        isysDeleteSubThread(arg0);
    }
    isysFlushISYSLetterObj(arg0);
}

void func_40097640(int arg0)
{
    char *s = GetScriptClass((unsigned char *)arg0);
    int obj;
    int *link;
    void *grp;

    if (*(void (**)(int, int))(s + 0x54) != 0) {
        (*(void (**)(int, int))(s + 0x54))(arg0, *(int *)(s + 0x58));
    }
    if (*(void (**)(int, int))(s + 0x5C) != 0) {
        (*(void (**)(int, int))(s + 0x5C))(arg0, *(int *)(s + 0x60));
    }
    grp = s + 0x30;
    obj = 0;
    link = isysGroupForFirst(grp, 0);
    if (link != 0) {
        obj = *link;
        while (1) {
            isysRequestDeleteObj(obj);
            link = isysGroupForNext(link, 0);
            if (link == 0) break;
            obj = *link;
        }
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
    isysDeleteGroupAllObj(grp);
}

extern unsigned char D_4012B188[];

void *getStackViewFlag(void)
{
    return D_4012B188;
}

void scriptIntrSignal(unsigned char *sig)
{
    int *link;
    int obj;
    unsigned char *cls;
    int *cb;
    int *link2;

    if ((int)(*(long *)sig >> 32) & 1) {
        obj = 0;
        for (link = isysGroupForFirst(sig + 8, 0); link != 0; link = isysGroupForNext(link, 0)) {
            obj = *link;
            cls = GetScriptClass((unsigned char *)obj);
            if (*(int **)(cls + 0x38) == 0 || **(int **)(cls + 0x38) < *(int *)sig) {
                *(int *)(cls + 0x38) = (int)sig;
                *(int *)(cls + 0x3C) = link[2];
            }
        }
        if (obj != 0) {
            isysGroupForExit(obj, 0);
        }
    }
    if ((int)(*(unsigned long *)sig >> 33) & 1) {
        obj = 0;
        for (link2 = isysGroupForFirst(sig + 0x10, 0); link2 != 0; link2 = isysGroupForNext(link2, 0)) {
            cb = (int *)link2[2];
            obj = *link2;
            createScriptObj(cb[1], cb[2], &rootPtn, 0x1000, 0, *(int *)((char *)GetScriptClass((unsigned char *)cb[4]) + 0x20), cb[4], 0);
        }
        if (obj != 0) {
            isysGroupForExit(obj, 0);
        }
    }
}
