#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_reset_record_info);
void GAMEUTIL_reset_record_info(u8 *r)
{
    *(s32 *)(r + 0xC) = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_add_data_record_info);
void *memcpy(void *d, const void *s, u32 n);
void GAMEUTIL_add_data_record_info(u8 *r, void *src)
{
    s32 n = *(s32 *)(r + 0xC);
    s32 max = *(s32 *)(r + 4);
    s32 size = *(s32 *)r;
    u8 *data = *(u8 **)(r + 8);
    s32 i;

    if (n < max) {
        *(s32 *)(r + 0xC) = n + 1;
    } else {
        *(s32 *)(r + 0xC) = max;
    }
    for (i = *(s32 *)(r + 0xC) - 1; i > 0; i--) {
        memcpy(data + i * size, data + (i - 1) * size, size);
    }
    memcpy(data, src, size);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_get_data_record_info);
u8 *GAMEUTIL_get_data_record_info(u8 *r, s32 idx)
{
    if (idx >= 0 && idx < *(s32 *)(r + 0xC)) {
        return *(u8 **)(r + 8) + idx * *(s32 *)r;
    }
    return NULL;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_reset_status_manager);
void GAMEUTIL_reset_status_manager(s32 *m, s32 st)
{
    m[2] = st;
    m[1] = st;
    m[0] = st;
    m[3] = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_doit_status_manager);
void GAMEUTIL_doit_status_manager(s32 *m, s32 st, f32 dt, s32 reset)
{
    s32 old;

    if (reset == 1) {
        m[2] = st;
        m[1] = st;
        m[0] = st;
        m[3] = 0;
        return;
    }
    old = m[0];
    if (old == st) {
        *(f32 *)&m[3] = *(f32 *)&m[3] + dt;
    } else {
        m[3] = 0;
        m[2] = old;
    }
    m[1] = old;
    m[0] = st;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_is_status_change_status_manager);
s32 GAMEUTIL_is_status_change_status_manager(s32 *m)
{
    return *(f32 *)&m[3] <= 0.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_get_status_continue_time_status_manager);
f32 GAMEUTIL_get_status_continue_time_status_manager(s32 *m)
{
    return *(f32 *)&m[3];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_get_cur_status_status_manager);
s32 GAMEUTIL_get_cur_status_status_manager(s32 *m)
{
    return m[0];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_get_pre_status_status_manager);
s32 GAMEUTIL_get_pre_status_status_manager(s32 *m)
{
    return m[1];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", GAMEUTIL_get_pre_changed_status_status_manager);
s32 GAMEUTIL_get_pre_changed_status_status_manager(s32 *m)
{
    return m[2];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getSightOnRevCntrlLR);
extern s32 D_40130690;
s32 *getSightOnRevCntrlLR(void)
{
    return &D_40130690;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getSightOnRevCntrlUD);
extern s32 D_40130694;
s32 *getSightOnRevCntrlUD(void)
{
    return &D_40130694;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getSightOnAngleVelRatio);
extern s32 D_40130698;
s32 *getSightOnAngleVelRatio(void)
{
    return &D_40130698;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getFreeModeRevControlLR);
extern s32 D_4013069C;
s32 *getFreeModeRevControlLR(void)
{
    return &D_4013069C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getFreeModeRevControlUD);
extern s32 D_401306A0;
s32 *getFreeModeRevControlUD(void)
{
    return &D_401306A0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", getFreeModeRevAngleVelRatio);
extern s32 D_401306A4;
s32 *getFreeModeRevAngleVelRatio(void)
{
    return &D_401306A4;
}

/* NEARMISS-STUB func_40020538 */
#if 0 /* NEARMISS 85.0% cat=branch-layout sub=- | target tests exit arg in a0 at join before separate s0 test; ours merges checks | attempts=1 */
s32 func_40020538(u128 *pos)
{
    s32 obj = 0;
    s32 flag;
    s32 ret;
    u32 *link;
    u8 *cc;

    link = isysGroupForFirst((s32)((u8 *)&gcGlobalVar + 0x2B8), 0);
    if (link != NULL) {
        obj = *(s32 *)link;
        if (obj != 0) {
            isysGroupForExit(obj, 0);
        }
    }
    if (obj != 0) {
        flag = bossStatBootChk() > 0;
        if (flag) {
            cc = GetCharacterClass(obj);
            ret = GAMEUTIL_get_node_posi_by_id(pos, (void *)obj,
                GetSkeletonFocusNode(*(s32 *)(cc + 0x740) + 0x14));
            if (ret == flag) {
                return ret;
            }
        }
    }
    *pos = ZeroPoint;
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", func_40020538);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", gamecore);
s32 initgc();
s32 initgcmain();
s32 initgcmaingp();
s32 initgcchartest();
s32 gamecore(void)
{
    initgc();
    initgcmain();
    initgcmaingp();
    initgcchartest();
    return 0;
}

extern s32 rootPtn;
extern s32 gcGlobalVar;
extern s32 D_40130A50;
extern s32 D_40130A54;
extern const char D_40132B78[];
void func_40021080(void);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
u8 *create_cameraman(s32 a0, f32 value, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2);
s32 gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void init_cameraman_manager(void);
s32 get_camera_obj(void *cam);
s32 get_clip_screen(s32 obj);
void set_scissor_screen_size(void *s, s32 idx, s32 x, s32 y);
void update_clip_screen(void *s);
s32 employ_cameraman(void *cam);
s32 change_main_cameraman(s32 cam);
s32 func_40020630(s32 arg)
{
    u8 *cam;
    s32 w;
    s32 h;
    u8 *g;
    u8 *z;
    s32 clip;

    w = getDrawScreenWidth();
    h = getDrawScreenHeight();
    cam = create_cameraman((s32)&rootPtn, 45.0f, (s32)((u8 *)&gcGlobalVar + 0x274), (s32)((u8 *)&gcGlobalVar + 0x22C), (s32)((u8 *)&gcGlobalVar + 0x230), (s32)((u8 *)&gcGlobalVar + 0x230), w, h);
    gcCreateScriptObj(func_40021080, 0, &rootPtn, 0x3000, 0, arg, D_40132B78);
    init_cameraman_manager();
    clip = get_clip_screen(get_camera_obj(cam));
    set_scissor_screen_size((void *)clip, 0, D_40130A50, D_40130A50);
    set_scissor_screen_size((void *)clip, 1, D_40130A54, D_40130A54);
    update_clip_screen((void *)clip);
    return change_main_cameraman(employ_cameraman(cam));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", func_40020730);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", func_40020948);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", st_playObjAnim);
void scrRun();
void st_playObjAnim(void)
{
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", st_defaultAI);
extern s32 gcGlobalVar;
void *isysGetThisSubThread();
void *GetLayoutClass();
void st_defaultAI(void)
{
    f32 prev = 0.0f;
    u8 *g;

    GetLayoutClass(isysGetThisSubThread());
    g = (u8 *)&gcGlobalVar;
    for (;;) {
        f32 now = *(f32 *)(g + 0x178);
        if (now - prev > 10.0f) {
            prev = now;
        }
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", testGetCamPos);
extern u128 ZeroVector;
void *get_main_cameraman_camera_obj();
void iosCopyMatrix(void *dst, void *src);
void *testGetCamPos(u128 *a0, void *a1)
{
    void *obj = get_main_cameraman_camera_obj();

    if (obj != NULL) {
        u8 *layout = (u8 *)GetLayoutClass(obj);
        iosCopyMatrix(a1, *(void **)(layout + 0x158));
        *a0 = *(u128 *)*(void **)(layout + 0x134);
    } else {
        *a0 = ZeroVector;
    }
    return obj;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", nico_parentSync);
void *GetGeometryPointerObject();
void SendCharaMotionSyncStartMsg(void *th, void *geo);
void SCRSimpleExecCharaGeometry(void *th);
void nico_parentSync(void)
{
    void *th;
    u8 *layout;
    void *geo;

    th = isysGetThisSubThread();
    layout = GetLayoutClass(th);
    geo = GetGeometryPointerObject(layout + 0xC0);
    if (geo != NULL) {
        SendCharaMotionSyncStartMsg(th, geo);
    }
    if (*(s32 *)(layout + 0x124) != 0) {
        SCRSimpleExecCharaGeometry(th);
        SCRSimpleExecCharaGeometry(th);
    }
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", nico_kimurateststart);
extern u8 padManagerData[];
void iosSetCurrentMatrix();
void iosRotCurrentMatrixZ(f32 a);
void iosGetCurrentMatrix();
void nico_kimurateststart(void)
{
    u8 *layout;
    u8 *pm;

    layout = GetLayoutClass(isysGetThisSubThread());
    scrRun();
    pm = padManagerData;
    while (1) {
        if (*(s32 *)(pm + 0xF98) & 2) {
            iosSetCurrentMatrix(*(s32 *)(layout + 0x158));
            iosRotCurrentMatrixZ(0.0034888885f);
            iosGetCurrentMatrix(*(s32 *)(layout + 0x158));
        }
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", func_40020E30);
extern s32 gcGlobalVar;
extern s32 __gameMode;
u64 iosGetTCountExtension();
f32 getFadeValue(void);
void *get_main_cameraman_camera_obj(void);
void DispDispObjGroupModel(void *obj);
void scrRun();
void func_40020E30(void)
{
    u8 *g = (u8 *)&gcGlobalVar;

    for (;;) {
        *(u64 *)(g + 0x30) = iosGetTCountExtension();
        if (getFadeValue() != 1.0f) {
            DispDispObjGroupModel(get_main_cameraman_camera_obj());
        }
        *(u64 *)(g + 0x38) = iosGetTCountExtension();
        while (__gameMode & 0x10) {
            scrRun();
        }
        scrRun();
    }
}

typedef struct {
    char pad0[0x180];
    float wind;
    float scale;
} GlobalVar;

void UpdateLayoutClassPastSimpleGeometry(char *c);
void UpdateLayoutClassParentGeometry(char *c, s32 a, s32 b);
void UpdateLayoutClassSimpleGeometry(char *c, f32 f);
void GetLayoutClassWindGeometry(char *c, void *p);
void GetClothDynamics(void *th, s32 a, s32 b, f32 wind, f32 scale);
void nico_clothdrive(void)
{
    void *th = isysGetThisSubThread();
    char *c = GetLayoutClass(th);
    GlobalVar *g = (GlobalVar *)&gcGlobalVar;

    for (;;) {
        if (*(s32 *)(c + 0x124) != 0) {
            UpdateLayoutClassPastSimpleGeometry(c);
            UpdateLayoutClassParentGeometry(c, 0, 0);
            UpdateLayoutClassSimpleGeometry(c, g->scale);
        }
        GetLayoutClassWindGeometry(c, c + 0x30);
        GetClothDynamics(th, 1, 0, g->wind, g->scale);
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0008_GAMEUTIL_reset_record_info", nico_individualClothOverSurfDetectFunc);
s32 CheckUnderVariableXZSurface();
s32 nico_individualClothOverSurfDetectFunc(u8 *a0, s32 a1)
{
    u8 buf[0x50];
    s32 v = *(s32 *)(*(u8 **)(a0 + 0xC) + 0x10);

    return CheckUnderVariableXZSurface(buf, v, v, a1) == 0;
}
