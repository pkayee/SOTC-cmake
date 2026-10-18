#include "common.h"

extern int GetSCRCharaAIWorkPtr(int);

void nico_restartWormGenealogicalNodeFromDemo(int *arg0)
{
    (*(signed char *)((char *)(((GetSCRCharaAIWorkPtr(*arg0) + 0x4193) & ~0xF)) + 0x1278)) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeNext);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeTail);

extern void nico_calcWormGenealogicalNodeTailBase(int *);

void nico_calcWormGenealogicalNodeDownTail(int *a)
{
    char *w = (char *)((GetSCRCharaAIWorkPtr(*a) + 0x4193) & ~0xF);
    int ok;
    int i;

    nico_calcWormGenealogicalNodeTailBase(a);
    ok = 1;
    for (i = 1; i < *(int *)(w + 0x1274) - 2; i++) {
        if (((signed char *)(w + 0xEC0))[i] == 0)
            ok = 0;
    }
    if (ok)
        w[0x127A] = 1;
}

extern void nico_calcWormGenealogicalNodeDownNext();

void nico_calcWormGenealogicalNodeDownNextLast(void)
{
    nico_calcWormGenealogicalNodeDownNext();
}

char *getEventScriptClass(unsigned char *p)
{
    if (p[0x8] != 0x20) {
        return 0;
    }
    return (char *)p + 0x20;
}

extern int flushScriptObjImmediate();

int flushEventScriptObjImmediate(int a, int b, int c, int d)
{
    return flushScriptObjImmediate(a, b, c, d);
}

extern int flushScriptObj();

int flushEventScriptObj(int a, int b, int c, int d)
{
    return flushScriptObj(a, b, c, d);
}

extern s32 D_40132460[];
extern void initScriptObj();

void initEventScriptObj(unsigned char *o, int *a)
{
    unsigned char *s;
    D_40132460[4] = a[0];
    initScriptObj(o, D_40132460);
    s = o[8] != 0x20 ? 0 : o + 0x20;
    *(int *)(s + 0x70) = a[1];
    *(int *)(s + 0x74) = a[2];
}

extern s32 D_40132460[];
s32 GetScriptObjWorkSize();

s64 getEventScriptObjWorkSize(s32 *a0)
{
    D_40132460[4] = *a0;
    return GetScriptObjWorkSize(D_40132460);
}

typedef struct {
    char pad0[0x10];
    int x10;
} ScriptDesc;

extern unsigned char *_isysCreateObj(void *, int, int, int, void *, int);
extern void isysSetObjImmediateDeleteFunc(void *, void (*)(void));
extern void func_4012FE60(void);
extern void func_4012FE78(void);

static inline ScriptDesc *setupDesc(int *desc)
{
    ((ScriptDesc *)D_40132460)->x10 = desc[0];
    return (ScriptDesc *)D_40132460;
}

unsigned char *createEventScriptObj(void *parent, int extra, int *desc)
{
    unsigned char *o;
    char *c;
    int w;

    o = _isysCreateObj(parent, 0x20, 0xA0, extra + GetScriptObjWorkSize(setupDesc(desc)) + 0x33, func_4012FE78, 4);
    isysSetObjImmediateDeleteFunc(o, func_4012FE60);
    w = *(int *)o;
    initScriptObj(o, setupDesc(desc), w);
    c = o[8] == 0x20 ? (char *)o + 0x20 : 0;
    *(int *)(c + 0x70) = desc[1];
    *(int *)(c + 0x74) = desc[2];
    return o;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_4012FE60);
void func_4012FE60(void)
{
    flushScriptObjImmediate();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_4012FE78);
void func_4012FE78(void)
{
    flushScriptObj();
}

void SCRFuncSoundSetDepth(void) {
}

extern int DldSysUndefSymbol;
extern void activeDemoStandby(char *);

void SCRFuncActiveDemoStandby(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoStandby((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

extern void activeDemoCancel(char *);

void SCRFuncActiveDemoCancel(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoCancel((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

extern int DldSysUndefSymbol;
extern void activeDemoStart(char *);

void SCRFuncActiveDemoStart(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoStart((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

extern char *bgmAutoStart(void *, int, void *, int);
extern void func_40130070();

void SCRFuncSoundPlay(void *a, int b, int c, int d, int e, int f, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *r = bgmAutoStart((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0, 0, func_40130070, 0);
    *(char **)(r + 0x30) = r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_40130070);

extern int bgmScriptRecvSoundSignal();

int SCRConditionSoundSignal(int a, int b, int c, int d)
{
    return bgmScriptRecvSoundSignal(b, b, c, d);
}

extern int *getSScriptWork(void *);
extern void *getPlayerColCont2(int);
extern int ColCont2_IsParentObj(void *, void *);
extern int ColCont2_IsColStatus(void *, long, long);

static inline int *dldTable(unsigned int *h)
{
    int off = *h & 0x3FFFF;

    return off != 0 ? *(int **)((char *)h - off) : 0;
}

int SCRSoundConditionPlayerParentColAttr(void *actor, int a1, int a2, int a3, long type, long val, int a6,
                                         unsigned int *h)
{
    int *w = getSScriptWork(actor);
    int *t = dldTable(h);
    void *o = (t != 0 && t != (int *)DldSysUndefSymbol) ? (void *)t[4] : 0;
    int ok;

    if (*w == 0)
        return 0;
    if (o != 0) {
        ok = 0;
        if (ColCont2_IsParentObj(getPlayerColCont2(*w), o))
            ok = 1;
    } else
        ok = dldTable(h) == 0;
    if (!ok)
        return 0;
    return ColCont2_IsColStatus(getPlayerColCont2(*w), type, val) != 0;
}

extern void *nico_GetPlayerCharacterRidingHorseObject(int);

int SCREventConditionPlayerRidingHorse(void *actor)
{
    int p = *getSScriptWork(actor);
    if (p == 0)
        return 0;
    return nico_GetPlayerCharacterRidingHorseObject(p) != 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionOverDistanceToPlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionLessDistanceToPlayerWorldXZ);

extern int D_4021E2C0[];

int *getSScriptWork(void *a)
{
    return D_4021E2C0;
}

extern int scrRunM();

int initSScriptSystem(int a, int b, int c, int d)
{
    return scrRunM(1, b, c, d);
}

extern char gcGlobalVar[];
typedef struct {
    void *obj;
    void *layout;
} SScript;
extern void *SCRGetFirstObj(void *);
extern void *GetLayoutClass(void *);
extern void soundScriptTickProc(void *);

void updateSScriptSystem(void *a)
{
    SScript *s = (SScript *)D_4021E2C0;
    void *o = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    s->obj = o;
    if (o != 0) {
        s->layout = GetLayoutClass(o);
        soundScriptTickProc(a);
    }
}

/* NEARMISS-STUB difftime */
#if 0 /* NEARMISS 73.78% cat=call-abi sub=- | gcc sibcalls dpsub (j dpsub); target jal dpsub then frame restore | attempts=1 */
extern double __floatdidf(s64 value);
extern double dpsub();

double difftime(s64 time1, s64 time0)
{
    double d1 = __floatdidf(time1);
    double d0 = __floatdidf(time0);

    double r = dpsub(d1, d0);

    return r;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", difftime);
