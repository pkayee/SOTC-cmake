#include "common.h"

extern int sheetFsDataRead(int, int, int, int);

extern void iosJumpRecoverPoint(const char *);
extern const char D_401350B8[];

typedef struct SheetSym191 {
    int addr;
    int key;
    unsigned int flags;
} SheetSym191;
typedef struct SheetHdr191 {
    int w0;
    int k1;
    int k2;
    int wC;
    int w10;
    struct SheetObj191 *back14;
    int symNum;
    SheetSym191 *syms;
    int cnt20;
    int *tab24;
    int w28;
    struct SheetObj191 *back2c;
} SheetHdr191;
typedef struct SheetBits191 {
    unsigned int size:19;
    unsigned int loaded:1;
    int cnt:10;
    unsigned int top:2;
} SheetBits191;
typedef struct SheetObj191 {
    unsigned int **w0;
    int w[6];
    SheetHdr191 *hdrA;
    SheetHdr191 *hdrB;
    int w24[5];
    SheetHdr191 *hdr;
    struct SheetObj191 *owner;
    struct SheetObj191 *list40;
    SheetBits191 bits;
    int group[1];
    struct SheetObj191 *next4c;
    struct SheetObj191 *qnext;
    struct SheetObj191 *ownNext;
} SheetObj191;
typedef struct SheetLink191 {
    SheetObj191 *obj;
} SheetLink191;
extern int D_401B53D8[];
extern int rootPtn;
extern int DldSysUndefSymbol;
extern int sheetFsLanguageCode;
SheetLink191 *isysGroupForFirst(void *, int);
SheetLink191 *isysGroupForNext(SheetLink191 *, int);
void isysGroupForExit(void *, int);
void isysAddGroupWithLinkParam(void *, void *, int, int);
void isysDeleteGroupAllObj(void *);

extern SheetObj191 *D_401B53DC;
extern SheetObj191 *D_401B53E4;
extern int D_4012E338;
extern int D_4012E334;
extern const char D_401351A0[];
extern void func_400F10E8();
extern void iosSleepThread();
extern void _isysDeleteGroup();
extern void AddObjectManagerSheetWorkSize();
extern int isysGetModuleObjMallocSize();
extern void isysFlushModuleObj();
extern void isysRequestDeleteObj();
extern void sheetMgrResolve();

void sheetFileRead(void **arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;
    void *temp_s0;

    temp_s0 = *arg0;
    sheetFsDataRead((*(int *)((char *)(temp_s0) + 0)), arg1, arg2, arg3);
    temp_v0 = (*(int *)((char *)(temp_s0) + 8)) + arg2;
    (*(int *)((char *)(temp_s0) + 8)) = temp_v0;
    if ((*(int *)((char *)(temp_s0) + 4)) < temp_v0) {
        iosJumpRecoverPoint(D_401350B8);
    }
}

int sheetFileGetDataAdrs(void *arg0)
{
    int var_a1;
    void *temp_v0;

    temp_v0 = (*(void **)((char *)(arg0) + 4));
    var_a1 = (*(int *)((char *)(temp_v0) + 0x10));
    if (var_a1 != 0) {
        var_a1 += (*(int *)((char *)((*(void **)((char *)(temp_v0) + 8))) + 0xC)) * (*(int *)((char *)(arg0) + 8));
    }
    return var_a1;
}

int sheetFileGetSize(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x10));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", sheetFileLoadSegmentIndex);

extern void sheetFsLoadRootSegment(void (*cb)(int a, int b), int);
extern int D_401B53AC;
extern int D_401B53B0;
extern int func_400EE808(int a, int b, int c, int d);

void sheetFileLoadRootSegment(int arg0, int arg1)
{
    D_401B53AC = arg1;
    D_401B53B0 = arg0;
    sheetFsLoadRootSegment(func_400EE808, arg0);
}

extern void sheetFsLoadBootData(void (*cb)(int a, int b), int);
extern int D_401B53BC;
extern int D_401B53C0;
extern int D_401B53C4;
extern void func_400EE428(int a, int b);

void sheetFileLoadBootData(int arg0, int arg1, int arg2, int arg3)
{
    D_401B53C0 = arg1;
    D_401B53BC = arg2;
    D_401B53C4 = arg3;
    D_401B53B0 = arg0;
    sheetFsLoadBootData(&func_400EE428, arg0);
}

extern void sheetFsLoadMap(int, int, int, int, int, void *, int);
extern int D_401B53B4;
extern int D_401B53B8;
extern void func_400EE1C8();

void sheetFileLoadMap(int a, int b, int c, int d, int e, int f, int g)
{
    D_401B53AC = g;
    D_401B53B0 = f;
    D_401B53B4 = b;
    D_401B53B8 = e;
    sheetFsLoadMap(a, b, c, d, e, func_400EE1C8, f);
}

extern void sheetFsLoadStageTex(int, void (*cb)(int a, int b), int);
extern void func_400EE820(int a, int b);

void sheetFileLoadStageTex(int a, int b, int c)
{
    D_401B53AC = c;
    D_401B53B0 = b;
    sheetFsLoadStageTex(a, func_400EE820, b);
}

extern int sheetFsInit();

int sheetfileInit(int a, int b, int c, int d)
{
    return sheetFsInit(a, b, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE7F0);

extern int func_400EDBC8();

int func_400EE7F0(int a, int b, int c, int d)
{
    return func_400EDBC8(a, 1, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE808);

int func_400EE808(int a, int b, int c, int d)
{
    return func_400EDBC8(a, 1, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE820);

void func_400EE820(int a, int b)
{
    func_400EDBC8(a, 0);
}

void func_400EE838(SheetObj191 *mod)
{
    SheetObj191 *cur = 0;
    SheetObj191 *in;
    SheetLink191 *l;
    SheetLink191 *il;
    SheetHdr191 *h;
    SheetSym191 *s;
    int found;
    int n;
    int i;
    int id;
    int *g;

    l = isysGroupForFirst(mod->group, 0);
    if (l != 0) {
    g = D_401B53D8;
    do {
        cur = l->obj;
        found = 0;
        in = 0;
        for (il = isysGroupForFirst(g, 0); il != 0; il = isysGroupForNext(il, 0)) {
            in = il->obj;
            if (cur == in) {
                found = 1;
                break;
            }
        }
        if (in != 0)
            isysGroupForExit(in, 0);
        if (!found)
            isysAddGroupWithLinkParam(cur, g, 0, 1);
        h = cur->hdr;
        n = h->symNum;
        id = mod->hdr->k1;
        s = h->syms;
        for (i = 0; i < n; i++) {
            if (s[i].key == id)
                s[i].addr = DldSysUndefSymbol;
        }
        l = isysGroupForNext(l, 0);
    } while (l != 0);
    }
    if (cur != 0)
        isysGroupForExit(cur, 0);
    isysDeleteGroupAllObj(mod->group);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", sheetMgrResolve);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EEC40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EEE08);

void func_400EEF78(void)
{
    SheetObj191 *o;
    SheetObj191 *next;
    SheetObj191 *owner;
    SheetObj191 *prev;
    SheetObj191 *cur;
    int n;

    for (o = D_401B53E4; o != 0; o = o->qnext)
        func_400F10E8(o);
    if (D_4012E338 == 0) {
        D_4012E334 = 1;
        iosSleepThread();
    }
    o = D_401B53DC;
    n = 0x32;
    if (o != 0) {
        for (;;) {
            next = o->next4c;
            if (o->bits.cnt == 0) {
                prev = 0;
                _isysDeleteGroup(o, D_401B53D8, 1);
                func_400EE838(o);
                owner = o->owner;
                cur = owner->list40;
                while (cur != 0 && o != cur) {
                    prev = cur;
                    cur = cur->ownNext;
                }
                if (cur == 0)
                    iosJumpRecoverPoint(D_401351A0);
                if (prev != 0)
                    prev->ownNext = o->ownNext;
                else
                    owner->list40 = o->ownNext;
                n--;
                AddObjectManagerSheetWorkSize(-((*o->w0[-1] & 0xffffff) << 2));
                AddObjectManagerSheetWorkSize(-isysGetModuleObjMallocSize(o));
                isysFlushModuleObj(o);
                isysRequestDeleteObj(o);
                if (n < 1) {
                    if (D_4012E338 == 0) {
                        D_4012E334 = 1;
                        iosSleepThread();
                    }
                    n = 0x32;
                }
            }
            o = next;
            if (o == 0)
                break;
        }
    }
    sheetMgrResolve(1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF138);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF3A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF630);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF940);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EFAB8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EFB98);
