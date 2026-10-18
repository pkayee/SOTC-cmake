#include "common.h"

extern s32 D_4012E390;
extern s32 D_4012E394;
extern s32 rootPtn;
extern const char D_40135488[];

void isysRequestDeleteObj();
void iosFree(void *);
void seStopLoopType();
u8 *GetSubLinkClass();
void stop_camera_lws_animation_callback();
void end_camera_lws_animation();
void stop_camera_lws_animation_geometry_pointer_reference();
void stop_wind_emitter_callback();
void end_wind_emitter();
void stop_wind_emitter_geometry_pointer_reference();
void sndSepCont();
void sndSepPause();
void stop_particle_emitter_callback();
void end_particle_emitter();
void stop_particle_emitter_geometry_pointer_reference();
void iosJumpRecoverPoint(const char *);
void *iosMallocAlign(void *, s32, s32);
void sheetFileRead(s32, void *, s32);
u8 *GetGeometryPointerObject();
u8 *GetLayoutClass();
u8 *CreateSubLinkObjByGeometryPointer();
s32 sePlay3D();
void SetSubLinkObjDeleteFuncInfo();
s32 boot_wind_emitter();
s32 boot_wind_emitter_by_box();
void func_400FAE50();
void func_400FAE38();
void func_400FB0B8();
void func_400FB080();
void func_400FAD00();
void func_400FAD48();
s32 boot_particle_emitter();
s32 boot_wind_emitter_by_judge_volume();
void func_400FAB58();
void func_400FAB90();
s32 boot_camera_lws_animation(s32, s32, f32, s32, s32, s32);
typedef struct WindKick { s32 id; s32 owner; } WindKick;

s32 *getSETriggerTestMode(void) {
    return &D_4012E394;
}

void AnimeTableInfoDebugMode(s32 v) {
    D_4012E390 = v;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0203_getSETriggerTestMode", SequenceKickCameraVibration);

void func_400FAB58(s32 a, s32 *b) {
    stop_camera_lws_animation_callback(*b);
    end_camera_lws_animation(*b);
    stop_camera_lws_animation_geometry_pointer_reference(*b);
}

void func_400FAB90() {
    isysRequestDeleteObj();
}

/* NEARMISS-STUB getBootParent */
#if 0 /* NEARMISS 86.0% cat=branch-layout sub=loop-exit-likely | param geo walk: GetGeometryPointerObject(geo), geo=layout+0xC0 (arg was missing in the old attempt); structure exact; left: obj==NULL exit is beql (predicted ta | attempts=2 */
u8 *getBootParent(u8 *geo)
{
    u8 *parent = NULL;
    u8 *obj;
    u8 *layout;

    while ((obj = GetGeometryPointerObject(geo)) != NULL) {
        layout = GetLayoutClass(obj);
        if (layout == NULL) {
            break;
        }
        geo = layout + 0xC0;
        parent = obj;
        if (*(s32 *)(layout + 0x124) == 0) {
            break;
        }
    }
    return parent;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0203_getSETriggerTestMode", getBootParent);

u8 *SequenceKickParticle(s32 owner, s32 g) {
    u8 *obj = CreateSubLinkObjByGeometryPointer(g, 8);
    WindKick local;
    WindKick tmp;

    if (obj != NULL) {
        tmp.id = boot_particle_emitter(owner, g, func_400FAD48, obj);
        tmp.owner = owner;
        local = tmp;
        if (local.id != -1) {
            if (local.id == 0) {
                isysRequestDeleteObj(obj);
                obj = NULL;
            } else {
                SetSubLinkObjDeleteFuncInfo(obj, func_400FAD00, &local, 8);
            }
        } else {
            obj = NULL;
        }
    }
    return obj;
}

s32 KickParticleGetResourceId() {
    return **(s32 **)(GetSubLinkClass() + 0x10);
}

void func_400FAD00(s32 a, s32 *b) {
    stop_particle_emitter_callback(b[1], b[0]);
    end_particle_emitter(b[1], b[0], 1);
    stop_particle_emitter_geometry_pointer_reference(b[1], b[0]);
}

void func_400FAD48() {
    isysRequestDeleteObj();
}

u8 *SequenceKickSE(s32 a0, s32 a1) {
    u8 *obj = CreateSubLinkObjByGeometryPointer(a1, 4);
    s32 r = sePlay3D(a0, a1, obj, func_400FAE50);
    s32 local = r;

    if (r == 0) {
        isysRequestDeleteObj(obj);
        obj = NULL;
    } else {
        SetSubLinkObjDeleteFuncInfo(obj, func_400FAE38, &local, 4);
    }
    return obj;
}

void seSetKeyOnOff(s32 a, s32 on) {
    s32 *v = *(s32 **)(GetSubLinkClass() + 0x10);
    s32 id = *v;

    if (on != 0) {
        sndSepCont(id);
    } else {
        sndSepPause(id);
    }
}

void func_400FAE38(s32 a, s32 *b) {
    seStopLoopType(*b);
}

void func_400FAE50() {
    isysRequestDeleteObj();
}

u8 *SequenceKickWind(s32 owner, s32 g) {
    u8 *obj = CreateSubLinkObjByGeometryPointer(g + 0x10, 8);
    WindKick local;
    WindKick tmp;

    tmp.id = boot_wind_emitter(owner, g, func_400FB0B8, obj);
    tmp.owner = owner;
    local = tmp;
    if (local.id < 0) {
        isysRequestDeleteObj(obj);
        obj = NULL;
    } else {
        SetSubLinkObjDeleteFuncInfo(obj, func_400FB080, &local, 8);
    }
    return obj;
}

u8 *SequenceKickWindBox(s32 owner, s32 g) {
    u8 *obj = CreateSubLinkObjByGeometryPointer(g + 0x10, 8);
    WindKick local;
    WindKick tmp;

    tmp.id = boot_wind_emitter_by_box(owner, g, func_400FB0B8, obj);
    tmp.owner = owner;
    local = tmp;
    if (local.id < 0) {
        isysRequestDeleteObj(obj);
        obj = NULL;
    } else {
        SetSubLinkObjDeleteFuncInfo(obj, func_400FB080, &local, 8);
    }
    return obj;
}

u8 *SequenceKickWindVolumeShape(s32 owner, s32 g) {
    u8 *obj = CreateSubLinkObjByGeometryPointer(g + 0x10, 8);
    u8 *geo;
    WindKick local;
    WindKick tmp;

    geo = GetGeometryPointerObject(g + 0x10);
    tmp.id = boot_wind_emitter_by_judge_volume(owner, geo, func_400FB0B8, obj);
    tmp.owner = owner;
    local = tmp;
    if (local.id < 0) {
        isysRequestDeleteObj(obj);
        obj = NULL;
    } else {
        SetSubLinkObjDeleteFuncInfo(obj, func_400FB080, &local, 8);
    }
    return obj;
}

void func_400FB080(s32 a, s32 *b) {
    stop_wind_emitter_callback(*b);
    end_wind_emitter(*b);
    stop_wind_emitter_geometry_pointer_reference(*b);
}

void func_400FB0B8() {
    isysRequestDeleteObj();
}

void *initLoadObjEditWork(s32 sheet, s32 unused, s32 size) {
    void *p = iosMallocAlign(&rootPtn, size, 0x10);

    sheetFileRead(sheet, p, size);
    return p;
}

void delLoadObjEditWork(s32 a, s32 b, void *p) {
    iosFree(p);
    return;
}

s32 getEditWorkSize(s32 *a) {
    if (a != NULL) {
        if (a[0] == 0x53494442) {
            return a[1];
        }
        iosJumpRecoverPoint(D_40135488);
    }
    return 0;
}

u8 *getEditWorkInitData(u8 *a) {
    if (a != NULL) {
        return a + *(s32 *)(a + 8);
    }
    return NULL;
}

u8 *getEditWorkDebugHeader(u8 *a) {
    if (a != NULL) {
        s32 v = *(s32 *)(a + 0xC);

        if (v != 0) {
            return a + v;
        }
    }
    return NULL;
}

u8 *getEditWorkDebugData(u8 *a) {
    if (a != NULL && *(s32 *)(a + 0xC) != 0) {
        return a + *(s32 *)(a + 0xC) + 0x20;
    }
    return NULL;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0203_getSETriggerTestMode", chkEtiInfoWork);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0203_getSETriggerTestMode", setEditWorkTool);
