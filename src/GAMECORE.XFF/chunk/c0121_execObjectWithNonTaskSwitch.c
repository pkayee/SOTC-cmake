#include "common.h"

/* GAMECORE c0121 SCRSetDispFlag: 100 in scratch. Needs the 2-arg (obj, flag) pass-through to both callees (a2 temp for slti),
 * `!= 0xd` outer test with the else holding the jal call, and NESTED ifs (&& chain merges into sltiu range = 63%). */
extern void SetScriptAnimationObjAccessSwitch(u8 *, int);
extern void SetLayoutObjAccessSwitch(u8 *, int);

/* GAMECORE c0121 _initstage: 100 in scratch; relocatable-handle decode as in c0060 SCRSetMyOwnGameFlag; initlayout needs the real 6-arg decl for the tail-call j */
extern int DldSysUndefSymbol;
extern int D_40131BB8;
extern int D_40131BBC;
extern int D_40131BC0;
extern int D_40131BC4;
extern int D_40131BC8;
extern int D_40131BCC;
extern char *gcGetStageData(int);
extern void initlayout(int, char *, int, int, int, int);

extern u8 *GetCharacterClass(u8 *);
extern u8 *GetLayoutClass(u8 *);
extern s32 StageManagerCheckAreaExist(s32);
extern u8 *SCRGetGetGeometryPointerLegalParentObj(u8 *);
extern s32 ExecCharaGeometryPreprocess(u8 *, float, float, float);
extern s32 ExecCharaGeometry(u8 *, u8 *);
extern void ExecCharaGeometryPostprocess(u8 *);
static inline s32 isLegalGeoParent(u8 *obj) /* inline helper */
{
    u8 *lay = GetLayoutClass(obj);
    u8 *p;

    if (lay != 0 && *(s32 *)(lay + 0x124) != 0) {
        p = SCRGetGetGeometryPointerLegalParentObj(lay + 0xC0);
        if (p != 0) {
            switch (p[8]) {
            case 9:
            case 0xD:
            case 0x16:
                return 1;
            }
        }
    }
    return 0;
}

/* NEARMISS-STUB execObjectWithNonTaskSwitch */
#if 0 /* NEARMISS 97.81% cat=regalloc sub=- | d2 r85: switch with default FIRST (makes default j-sibcall and last case 0x16 jal, as target) + isLegalGeoParent inline; only regalloc left: target gc-base/r ps | attempts=1 */
/* needs the TU struct OrientationGlobalsView widened (0x178 f178, 0x1AC flag, 0x370 context) and moved above; existing extern of this fn is (int) */
struct OrientationGlobalsView {
    char pad00[0x178];
    float f178;
    char pad17C[0xC];
    float interval;
    char pad18C[0x20];
    s32 flag;
    char pad1B0[0x1C0];
    char context[0];
};
extern struct OrientationGlobalsView gcGlobalVar;
extern void ExecScriptLwsOrientClass(void *, void *, void *, float, float);
extern float ViewIntervalClip(void *, void *, float);
extern void *get_main_cameraman_camera_obj(void);
extern void FlushRequestViewIntervalClip(void);
extern void isysLetterObjDiscardLetterAll(u8 *);
extern void iosJumpRecoverPoint(void *);
extern u8 D_40135CD0[];

static inline void execLwsOriNonTaskSwitch(u8 *obj)
{
    float interval;

    if (gcGlobalVar.flag != 0) {
        FlushRequestViewIntervalClip();
        ViewIntervalClip(obj, get_main_cameraman_camera_obj(), gcGlobalVar.interval);
    } else {
        interval = ViewIntervalClip(obj, get_main_cameraman_camera_obj(), gcGlobalVar.interval);
        ExecScriptLwsOrientClass(obj, get_main_cameraman_camera_obj(), gcGlobalVar.context, interval, 1.0f / interval);
    }
    isysLetterObjDiscardLetterAll(obj);
}

void execObjectWithNonTaskSwitch(int a)
{
    u8 *obj = (u8 *)a;
    u8 *cc;
    float interval;
    s32 r;

    switch (obj[8]) {
    default:
        iosJumpRecoverPoint(D_40135CD0);
        break;
    case 9:
        if (gcGlobalVar.flag != 0) {
            FlushRequestViewIntervalClip();
            ViewIntervalClip(obj, get_main_cameraman_camera_obj(), gcGlobalVar.interval);
        } else {
            cc = GetCharacterClass(obj);
            r = 0;
            interval = ViewIntervalClip(obj, get_main_cameraman_camera_obj(), gcGlobalVar.interval);
            if (*(s8 *)(cc + 0x524) != 0) {
                if (*(s32 *)(GetCharacterClass(obj) + 0x10C0) != 0
                    && StageManagerCheckAreaExist(*(s32 *)(GetLayoutClass(obj) + 0x134)) == 0
                    && *(s16 *)(cc + 0x360) != 4
                    && !isLegalGeoParent(obj)
                    && cc[0xD00] != 1
                    && *(s32 *)(cc + 0xFD0) != 1
                    && *(s16 *)(cc + 0x360) != 0xB) {
                } else {
                    r = ExecCharaGeometryPreprocess(obj, gcGlobalVar.f178, interval, 1.0f / interval);
                }
            }
            if (r != 0) {
                cc = GetCharacterClass(obj);
                ExecCharaGeometry(obj, gcGlobalVar.context);
                cc[0x529] = StageManagerCheckAreaExist(*(s32 *)(GetLayoutClass(obj) + 0x134));
            }
            ExecCharaGeometryPostprocess(obj);
        }
        isysLetterObjDiscardLetterAll(obj);
        break;
    case 0x16:
        execLwsOriNonTaskSwitch(obj);
        break;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", execObjectWithNonTaskSwitch);

extern int isysGetThisSubThread();
extern int func_400A4778();

int scrRun(void)
{
    return func_400A4778(isysGetThisSubThread());
}

void scrRunM(int n)
{
    void *t = isysGetThisSubThread();
    int i;
    for (i = 0; i < n; i++)
        func_400A4778(t);
}

void SCRSetDispFlag(u8 *p, int q)
{
    s32 t = p[8];
    if (t != 0xd) {
        if (t < 0xe) {
            if (t < 0xc) {
                if (8 < t) {
                    SetLayoutObjAccessSwitch(p, q);
                    return;
                }
            }
        }
    } else {
        SetScriptAnimationObjAccessSwitch(p, q);
    }
}

extern void *GetScriptCharacterClass(void *);

void *GetSCRCharaAIWorkPtr(void *actor)
{
    void *script;

    script = GetScriptCharacterClass(actor);
    return *(void **)((char *)script + 0x1150);
}

int CheckSCRCharaAIWorkPtr(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = (*(int *)((char *)(GetScriptCharacterClass((void *)arg0)) + 0x1150));
    }
    return var_v0;
}

extern void func_400A5440();
extern int D_40131BB4;

void SCRSimpleExecCharaGeometry(int arg0)
{
    D_40131BB4 = arg0;
    func_400A5440();
    D_40131BB4 = 0;
}

void scrInit(void) {
}

extern void ExecScriptLwsOrientClass(void *, void *, void *, float, float);
extern float ViewIntervalClip(void *, void *, float);
extern void *get_main_cameraman_camera_obj(void);
struct OrientationGlobalsView {
    char pad00[0x188];
    float interval;
    char pad18C[0x1E4];
    char context[0];
};
extern struct OrientationGlobalsView gcGlobalVar;

void __execScrLwsOri(void *actor)
{
    float interval;

    interval = ViewIntervalClip(actor, get_main_cameraman_camera_obj(),
                                gcGlobalVar.interval);
    ExecScriptLwsOrientClass(actor, get_main_cameraman_camera_obj(),
                            gcGlobalVar.context, interval, 1.0f / interval);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5088);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5148);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5228);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A52E8);

extern void func_400A5398();
extern void isysSleepSubThread();

void st_motionsyncanimation(void)
{
    for (;;) {
        func_400A5398();
        isysSleepSubThread();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5398);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5440);

/* GAMECORE c0121 simpleExecCharaGeometry: 100 in scratch. Relies on the TU decls above it: ViewIntervalClip(void *, void *, float), get_main_cameraman_camera_obj and the struct gcGlobalVar (OrientationGlobalsView, interval at 0x188). (1) the 0x9/0xD/0x16 test is a switch inside a static inline helper (gives the slti/beql tree). (2) gcGlobalVar address: g1 = &gcGlobalVar AFTER the camera call and a SEPARATE g2 = &gcGlobalVar at the Preprocess call give one hoisted lui in s3 plus two addiu (a shared g or struct-field/constant offset folding gives 76-95 percent). (3) the camera result in its own local, then g1, then ViewIntervalClip. (4) offset 0x370 is the folded constant (u8 *)&gcGlobalVar + 0x370 with its own lui. */
void simpleExecCharaGeometry(u8 *obj)
{
    s32 did = 0;
    u8 *cc;
    float iv;
    u8 *g1;
    u8 *g2;
    void *cam;

    cc = GetCharacterClass(obj);
    cam = get_main_cameraman_camera_obj();
    g1 = (u8 *)&gcGlobalVar;
    iv = ViewIntervalClip(obj, cam, *(float *)(g1 + 0x188));
    if (*(s8 *)(cc + 0x524) != 0) {
        if (*(s32 *)(GetCharacterClass(obj) + 0x10C0) == 0
            || StageManagerCheckAreaExist(*(s32 *)(GetLayoutClass(obj) + 0x134)) != 0
            || *(s16 *)(cc + 0x360) == 4
            || isLegalGeoParent(obj)
            || cc[0xD00] == 1 || *(s32 *)(cc + 0xFD0) == 1 || *(s16 *)(cc + 0x360) == 0xB) {
            g2 = (u8 *)&gcGlobalVar;
            did = ExecCharaGeometryPreprocess(obj, *(float *)(g2 + 0x178), iv, 1.0f / iv);
        }
    }
    if (did != 0) {
        cc = GetCharacterClass(obj);
        ExecCharaGeometry(obj, (u8 *)&gcGlobalVar + 0x370);
        cc[0x529] = StageManagerCheckAreaExist(*(s32 *)(GetLayoutClass(obj) + 0x134));
    }
    ExecCharaGeometryPostprocess(obj);
}

extern char D_40216E08[];
extern int isysAddGroupWithLinkParam();

int AddDefaultAIGroup(int a, int b, int c, int d)
{
    return isysAddGroupWithLinkParam(a, (int)D_40216E08, 0, 0);
}

extern char D_40135D48[];
extern char rootPtn[];
extern void isysInitGroup();
extern s32 gcCreateScriptObj();
void func_400A58C0();

s32 initdefaultaitask(void)
{
    isysInitGroup(D_40216E08);
    return gcCreateScriptObj(func_400A58C0, 0, rootPtn, 0x1000, 0, 4, D_40135D48);
}

void _initstage(void)
{
    unsigned int *h = (unsigned int *)(gcGetStageData(D_40131BBC) + 4);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = 0;
    if (t != 0 && t != (char *)DldSysUndefSymbol)
        p = *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC);
    initlayout(D_40131BB8, p, D_40131BC0, D_40131BC4, D_40131BC8, D_40131BCC);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", initstage);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A58C0);
extern void func_400A58E8();

void func_400A58C0(void)
{
    int uVar1;

    for (;;) {
        func_400A58E8();
        uVar1 = isysGetThisSubThread();
        func_400A4778(uVar1);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A58E8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5960);
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysGroupForExit(int, int);
extern void execObjectWithNonTaskSwitch(int);

void func_400A5960(void)
{
    int m = 0;
    int *g;

    for (g = isysGroupForFirst(D_40216E08, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        m = *g;
        execObjectWithNonTaskSwitch(m);
    }
    if (m != 0)
        isysGroupForExit(m, 0);
}
