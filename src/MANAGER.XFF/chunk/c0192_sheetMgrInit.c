#include "common.h"

typedef struct SheetSkipInfo192 {
    int pad0;
    char *flags;
    char *bits;
} SheetSkipInfo192;
extern SheetSkipInfo192 D_401C1030;
extern char rootPtn[];
void *iosMallocAlign(void *, int, int);
void *memset(void *, int, int);

typedef struct SheetReq192 {
    int type;
    unsigned int flags;
    int arg8;
    int argC;
    int a10;
    int a14;
    int a18;
    int a1C;
    int a20;
    int a24;
    int *done;
    struct SheetReq192 *next;
} SheetReq192;
typedef struct SheetReqList192 {
    SheetReq192 *head;
    SheetReq192 *tail;
} SheetReqList192;
extern int D_401B53F4;
extern SheetReq192 D_401B53F8[];
extern int D_401B53D8[];
extern void *D_401B9028;
extern int D_401B9030[];
extern int D_4012E340;
int iosCreateSema(int, int, int);
void isysInitGroup(int *);
void *iosCreateThread(void *, void *, int, int, int);
void iosStartThread(void *, int);
void waitVscheduler(void);
void func_400EFB98(void);
extern SheetReqList192 D_401B8FF8;
extern SheetReqList192 D_401B9000[];
extern char D_40135310[];
int WaitSema(int);
int SignalSema(int);
static inline SheetReq192 *sheetGetReqEmpty192(void) /* inline helper */
{
    extern void iosJumpRecoverPoint(const char *, int);
    SheetReq192 *s = D_401B8FF8.head;
    SheetReq192 *r;

    if (s != 0) {
        D_401B8FF8.head = s->next;
        if (D_401B8FF8.head == 0)
            D_401B8FF8.tail = 0;
    }
    r = s;
    if (r == 0)
        ((void (*)(const char *))iosJumpRecoverPoint)(D_40135310);
    return r;
}
static inline void sheetPostAllReqWait192(int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 10;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

/* sheetMgrInit: 100 in scratch (rea-c0192). The request free list is a 320 entry array (stride 0x30, next at 0x2c) chained forward; write the chain as an ASCENDING index loop (gcc reverses it into the countdown with two givs), then head, tail, last next = 0 in that order (the other orders of those 3 stores give 80 to 99.6). */
static inline void sheetPostLoadSegmentIndex192(int a, int b, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 0;
    r->arg8 = a;
    r->argC = b;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

static inline void sheetPostMapDataLoad192(int a, int b, int c, int d, int e, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 2;
    r->arg8 = a;
    r->a10 = b;
    r->a18 = c;
    r->a14 = d;
    r->a1C = e;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

static inline void sheetPostMapDataUnloadOneBlock192(int a, int b, int c, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 3;
    r->arg8 = c;
    r->a10 = a;
    r->a14 = b;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

static inline void sheetPostNopSegmentIndex192(int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 9;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

static inline void sheetPostSpecialFsEnd192(int x, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 12;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

int sheetFsSrhSpecialFs(int);
static inline void sheetPostSpecialFsStart192(int a, int b, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;
    int v;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 0xb;
    v = sheetFsSrhSpecialFs(a);
    r->a14 = b;
    r->a18 = v;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

int sheetFsGetStageTexSegIndex(int, int);
int sheetFsAddStageTexSegIndex(int);
static inline void sheetPostStageTexLoad192(int a, int idx, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 4;
    r->arg8 = a;
    r->argC = idx;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

int sheetFsDecStageTexSegIndex(int);
static inline void sheetPostStageTexUnload192(int a, int idx, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 5;
    r->arg8 = a;
    r->argC = idx;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

static inline void sheetPostUnloadSegmentIndex192(int a, int b, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 1;
    r->arg8 = a;
    r->argC = b;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

void sheetMgrInit(void)
{
    int i;

    D_401B53F4 = iosCreateSema(1, 1, 0);
    isysInitGroup(D_401B53D8);
    for (i = 0; i < 0x13f; i++)
        D_401B53F8[i].next = &D_401B53F8[i + 1];
    D_401B8FF8.head = D_401B53F8;
    D_401B8FF8.tail = &D_401B53F8[0x13f];
    D_401B53F8[0x13f].next = 0;
    D_401B9028 = iosCreateThread(func_400EFB98, D_401B9030, 0x8000, 0x2b, 0);
    iosStartThread(D_401B9028, 0);
    while (D_4012E340 == 0)
        waitVscheduler();
}

extern int D_4012E334;

void iosSleepThread();

void sheetWait(void)
{
    D_4012E334 = 1;
    iosSleepThread();
}

extern char **D_4012E330;

int sheetIdToName(int i)
{
    return **(int **)(D_4012E330[i] + 0x38);
}

int sheetHeaderObjSearchSheetId(int i)
{
    return (int)D_4012E330[i];
}

typedef struct SheetDataObj {
    char pad0[0x38];
    int *header;
    char pad3C[0x18];
    struct SheetDataObj *next;
} SheetDataObj;

SheetDataObj *sheetMgrSheetHeaderSearchSheetDataObj(char *mgr, int id)
{
    SheetDataObj *obj = *(SheetDataObj **)(mgr + 0x40);

    while (obj != 0 && id != obj->header[1]) {
        obj = obj->next;
    }
    return obj;
}

extern void iosJumpRecoverPoint(const char *, int);
extern const char D_401351C8[];

char *sheetMgrSearchSheetDataObj(int idx, int hash)
{
    char *s = D_4012E330[idx];
    char *o;

    if (s == 0)
        iosJumpRecoverPoint(D_401351C8, **(int **)(s + 0x38));
    for (o = *(char **)(s + 0x40); o != 0; o = *(char **)(o + 0x54)) {
        if (hash == (*(int **)(o + 0x38))[1])
            break;
    }
    return o;
}

extern void *D_401B53DC;

void sheetMgrAddSegLoadList(void *arg0)
{
    (*(void **)((char *)(arg0) + 0x4C)) = (void *) D_401B53DC;
    D_401B53DC = arg0;
}

int sheetMgrGetSegLoadHeader(void)
{
    return (int)D_401B53DC;
}

extern char *D_401B53E4;
extern char *D_401B53E8;

void sheetMgrAddSegInitList(char *p)
{
    *(char **)(p + 0x50) = 0;
    if (D_401B53E4 != 0)
        *(char **)(D_401B53E8 + 0x50) = p;
    else
        D_401B53E4 = p;
    D_401B53E8 = p;
}

typedef struct SheetInitEntry {
    char pad[0x50];
    struct SheetInitEntry *next;
} SheetInitEntry;

int sheetMgrCheckSegInitList(SheetInitEntry *entry)
{
    SheetInitEntry *node = (SheetInitEntry *)D_401B53E4;
    int found = 0;

    while (node != 0) {
        if (node == entry) {
            found = 1;
            break;
        }
        node = node->next;
    }
    return found;
}

int sheetMgrGetSegInitHeader(void)
{
    return (int)D_401B53E4;
}

void *sheetMgrCreateStageIndexSkipInfo(int n)
{
    int sz = n - 1;
    int m;

    if (sz < 0)
        sz = n + 6;
    D_401C1030.flags = iosMallocAlign(rootPtn, n, 4);
    m = (sz >> 3) + 1;
    D_401C1030.bits = iosMallocAlign(rootPtn, m, 4);
    memset(D_401C1030.flags, 0, n);
    return memset(D_401C1030.bits, 0, m);
}

extern u8 *D_401C1038;

int sheetMgrChkStageIndexResolve(int i)
{
    return (D_401C1038[i / 8] >> (i & 7)) & 1;
}

/* sheetMgrLoadSegmentIndex: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 0 on queue 1. */
void sheetMgrLoadSegmentIndex(int a, int b, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostLoadSegmentIndex192(a, b, 1, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrUnloadSegmentIndex: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 1 on queue 1. */
void sheetMgrUnloadSegmentIndex(int a, int b, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostUnloadSegmentIndex192(a, b, 1, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrNopSegmentIndex: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 9 on queue 1. */
void sheetMgrNopSegmentIndex(int *done)
{
    WaitSema(D_401B53F4);
    sheetPostNopSegmentIndex192(1, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrMapDataLoad: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 2 on queue 3. */
void sheetMgrMapDataLoad(int a, int b, int c, int d, int e, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostMapDataLoad192(a, b, c, d, e, 3, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrMapDataUnloadOneBlock: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 3 on queue 1. */
void sheetMgrMapDataUnloadOneBlock(int a, int b, int c, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostMapDataUnloadOneBlock192(a, b, c, 1, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrStageTexLoad: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 4 on queue 2, skipped when the seg-index add reports nonzero. */
void sheetMgrStageTexLoad(int a, int b, int c, int *done)
{
    int idx;

    WaitSema(D_401B53F4);
    idx = sheetFsGetStageTexSegIndex(b, c);
    if (sheetFsAddStageTexSegIndex(idx) == 0)
        sheetPostStageTexLoad192(a, idx, 2, done);
    else if (done != 0)
        *done = 0xdeaf;
    SignalSema(D_401B53F4);
}

/* sheetMgrStageTexUnload: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 5 on queue 1, skipped when the seg-index dec reports nonzero. */
void sheetMgrStageTexUnload(int a, int b, int c, int *done)
{
    int idx;

    WaitSema(D_401B53F4);
    idx = sheetFsGetStageTexSegIndex(b, c);
    if (sheetFsDecStageTexSegIndex(idx) == 0)
        sheetPostStageTexUnload192(a, idx, 1, done);
    else if (done != 0)
        *done = 0xdeaf;
    SignalSema(D_401B53F4);
}

/* NEARMISS-STUB sheetMgrAdpcmIntLoad */
#if 0 /* NEARMISS 99.17% cat=regalloc sub=param-a-priority | d2 r89: same root as sheetMgrDirectFileLoad: target gives param a (a0 -> a10) the first free s-reg (s2) after done; ours gives it the last (a0's copy is 1 insn  | attempts=1 */
static inline void sheetPostAdpcmIntLoad192(int a, int b, int c, int d, int e, int f, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmpty192();
    r->flags = r->flags & ~1;
    r->type = 7;
    r->a10 = a;
    r->a14 = b;
    r->a18 = c;
    r->a1C = d;
    r->a20 = e;
    r->a24 = f;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

void sheetMgrAdpcmIntLoad(int a, int b, int c, int d, int e, int f, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostAdpcmIntLoad192(a, b, c, d, e, f, 0, done);
    SignalSema(D_401B53F4);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrAdpcmIntLoad);

/* NEARMISS-STUB sheetMgrDirectFileLoad */
#if 0 /* NEARMISS 99.81% cat=regalloc sub=- | d2 r84: -da greg: param a (pseudo 84) is 1 insn longer-lived than b/c/d because sched1 puts the WaitSema a0 load (insn 33) between the a and b copies, so a gets | attempts=1 */
static inline SheetReq192 *sheetGetReqEmptyDF192(void) /* inline helper */
{
    extern void iosJumpRecoverPoint(const char *, int);
    SheetReq192 *s = D_401B8FF8.head;
    SheetReq192 *r;

    if (s != 0) {
        D_401B8FF8.head = s->next;
        if (D_401B8FF8.head == 0)
            D_401B8FF8.tail = 0;
    }
    r = s;
    if (r == 0)
        ((void (*)(const char *))iosJumpRecoverPoint)(D_40135310);
    return r;
}

static inline void sheetPostDFL192(int a, int b, int c, int d, int k, int *done) /* inline helper */
{
    SheetReq192 *r;
    SheetReqList192 *q;

    r = sheetGetReqEmptyDF192();
    r->type = 8;
    r->a10 = a;
    r->flags = r->flags & ~1;
    r->a14 = b;
    r->a18 = c;
    r->a1C = d;
    q = &D_401B9000[k];
    r->done = done;
    if (done != 0)
        *done = 0xdead;
    r->next = 0;
    if (q->tail != 0) {
        q->tail->next = r;
        q->tail = r;
    } else {
        q->tail = r;
        q->head = r;
    }
}

void sheetMgrDirectFileLoad(int a, int b, int c, int d, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostDFL192(a, b, c, d, 0, done);
    SignalSema(D_401B53F4);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrDirectFileLoad);

/* sheetMgrAllReqWait: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 10 on queue 4. */
void sheetMgrAllReqWait(int *done)
{
    WaitSema(D_401B53F4);
    sheetPostAllReqWait192(4, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrSpecialFsStart: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 11 on queue 4. */
void sheetMgrSpecialFsStart(int a, int b, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostSpecialFsStart192(a, b, 4, done);
    SignalSema(D_401B53F4);
}

/* sheetMgrSpecialFsEnd: 100 in scratch (rea-c0192). Posts one request: WaitSema, pop the free list D_401B8FF8 through a COPY of head, fill the request, push on queue D_401B9000[k] (k is a helper PARAMETER so gcc keeps the unfolded lui/addiu/addiu), SignalSema. THE trick for the last 4 percent: the push is written with the tail store duplicated in both arms, and in the empty-queue arm the tail store comes BEFORE the head store (tail = r; head = r). WaitSema/SignalSema must be declared int (eekernel.h), void shifts the lui register. Request type 12 on queue 4. */
void sheetMgrSpecialFsEnd(int x, int *done)
{
    WaitSema(D_401B53F4);
    sheetPostSpecialFsEnd192(x, 4, done);
    SignalSema(D_401B53F4);
}

extern int D_4012E338;

void sheetMgrSetNoWaitMode(int arg0)
{
    D_4012E338 = arg0;
}
