#include "common.h"

typedef struct {
    u8 pad0[0x70];
    u8 info[0x14]; /* 0x70 */
    u8 *cur;       /* 0x84 */
    u8 pad88[8];
    s32 cut;       /* 0x90 */
    f32 time;      /* 0x94 */
    u8 grp[4];     /* 0x98 */
} LwsDemoWork;

extern u8 *GetDemoOrientNext(u8 *);
extern s32 isysGroupForFirst(u8 *, s32);
extern s32 isysGroupForNext(s32, s32);
extern void isysRequestDeleteObj(s32);
extern void isysGroupForExit(s32, s32);
extern void isysDeleteGroupAllObj(u8 *);
extern void func_4008E1E8(u8 *, u8 *, u8 *, u8 *, s32, f32);
extern void initScriptObj(u8 *, u8 *, s32);
extern u8 *SetDemoMotionOrientInfo(u8 *, s32, s32);
extern void isysInitGroup(u8 *);
extern void flushScriptObjImmediate(u8 *);

void ExecLwsDemoOrientManagerObj(u8 *obj, f32 a, f32 dt)
{
    LwsDemoWork *w = (LwsDemoWork *)(obj + 0x20);
    u8 *info = obj + 0x90;
    s32 hit = 0;
    u8 *cur;
    s32 node;
    s32 item;
    f32 t;

    t = w->time + dt;
    w->time = t;
    cur = *(u8 **)(info + 0x14);
    if (w->cut != 0) {
        w->cut = 0;
        if (cur != 0 && *(f32 *)(cur + 4) != -2.0f) {
            do {
                cur = GetDemoOrientNext(info);
            } while (cur != 0 && *(f32 *)(cur + 4) != -2.0f);
        }
    } else if (!(0.0f < *(f32 *)(cur + 4) && *(f32 *)(cur + 4) < t)) {
        goto skip;
    }
    cur = GetDemoOrientNext(info);
    hit = 1;
skip:
    if (hit) {
        item = 0;
        for (node = isysGroupForFirst(w->grp, 0); node != 0; node = isysGroupForNext(node, 0)) {
            item = *(s32 *)node;
            isysRequestDeleteObj(item);
        }
        if (item != 0) {
            isysGroupForExit(item, 0);
        }
        isysDeleteGroupAllObj(w->grp);
        if (cur != 0) {
            func_4008E1E8(w->grp, cur, w->info, obj, *(f32 *)(cur + 4) < -2.0f ? 5 : 4, a);
            w->time = 0;
        }
    }
}

typedef union {
    u128 q;
    f32 v[4];
} LwsVec4;

void InitLwsDemoOrientManagerObj(u8 *obj, u8 *def)
{
    u8 *info = obj + 0x90;
    LwsDemoWork *w = (LwsDemoWork *)(obj + 0x20);
    u8 *grp = obj + 0xB8;
    u8 *r;

    initScriptObj(obj, def, *(s32 *)obj);
    r = SetDemoMotionOrientInfo(info, *(s32 *)(def + 0x24), *(s32 *)(def + 0x28));
    w->cut = 0;
    ((LwsVec4 *)info)->q = ((LwsVec4 *)*(s32 *)(def + 0x28))->q;
    w->time = 0;
    isysInitGroup(grp);
    func_4008E1E8(grp, r, info, obj, *(f32 *)(*(u8 **)(info + 0x14) + 4) < -2.0f ? 5 : 4, 0.0f);
}

extern int GetScriptObjWorkSize();
extern u8 *_isysCreateObj(u8 *, s32, s32, s32, void *, s32);
extern void isysInitISYSLetterObj(u8 *);
extern void isysSetObjImmediateDeleteFunc(u8 *, void *);
void func_4008E880(s32 arg0);
void func_4008E7F0(u8 *obj);

u8 *CreateLwsDemoOrientManagerObj(u8 *heap, s32 size, u8 *def)
{
    u8 *obj = _isysCreateObj(heap, 0x1D, 0xC0, size + GetScriptObjWorkSize(def) + 0x33, func_4008E880, 0x10);
    if (obj != 0) {
        isysInitISYSLetterObj(obj);
        InitLwsDemoOrientManagerObj(obj, def);
        isysSetObjImmediateDeleteFunc(obj, func_4008E7F0);
    }
    return obj;
}

void SetLwoDemoOrientManagerObjCutFinishFlag(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0xB0)) = arg1;
}

extern int flushScriptObj();

int FlushLwsDemoOrientManagerObj(int a, int b, int c, int d)
{
    return flushScriptObj(a, b, c, d);
}

void func_4008E7F0(u8 *obj)
{
    u8 *grp;
    s32 node;
    s32 item;

    flushScriptObjImmediate(obj);
    grp = obj + 0xB8;
    item = 0;
    for (node = isysGroupForFirst(grp, 0); node != 0; node = isysGroupForNext(node, 0)) {
        item = *(s32 *)node;
        isysRequestDeleteObj(item);
    }
    if (item != 0) {
        isysGroupForExit(item, 0);
    }
    isysDeleteGroupAllObj(grp);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008E880);
void isysFlushISYSLetterObj();

void func_4008E880(s32 arg0)
{
    flushScriptObj(arg0);
    isysFlushISYSLetterObj(arg0);
}

extern int GetScriptObjWorkSize();

int GetLwsDemoOrientManagerObjWorkSize(int a, int b, int c, int d)
{
    return GetScriptObjWorkSize(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008E8C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008EE08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F040);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F4A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F8E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008FC78);
