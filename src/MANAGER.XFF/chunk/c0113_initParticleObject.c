#include "common.h"

/* isys module object (KERNEL ios/isys/module.c ModObj, prefix only) */
typedef struct MgrModObj {
    /* 0x00 */ s32 partition;
    /* 0x04 */ void *sourceFunc;
    /* 0x08 */ u32 w8;
    /* 0x0C */ u8 pad0C[0x10];
    /* 0x1C */ s32 hdr; /* s32 so loads alias the s32 size counters (unloadCdNmo/Nso order) */
    /* 0x20 */ void *entry;
    /* 0x24 */ void *exp;
    /* 0x28 */ void *imports;
    /* 0x2C */ u32 flags;
} MgrModObj;

/* D_401AD480: object-manager running byte totals, 12 words, zeroed by InitBinarySize
   (AddObjectManager*Size add; unloadCd*File subtract sheetFileGetSize) */
typedef struct ObjMgrSizes {
    /* 0x00 */ s32 motion;          /* loadCdMotionFile/unloadCdMotionFile */
    /* 0x04 */ s32 colResCluster;   /* unloadCdColResFile (IsClusterCollision) */
    /* 0x08 */ s32 collisionBoss;   /* AddObjectManagerCollisionWorkSizeBoss */
    /* 0x0C */ s32 colRes;          /* unloadCdColResFile else arm */
    /* 0x10 */ s32 collisionStage;  /* AddObjectManagerCollisionWorkSizeStage */
    /* 0x14 */ s32 nmo;             /* unloadCdNmoFile */
    /* 0x18 */ s32 nso;             /* unloadCdNsoFile */
    /* 0x1C */ s32 tex;             /* unloadCdNtoFile / unloadCdWinTexFile */
    /* 0x20 */ s32 seamless;        /* AddObjectManagerSeamlessWorkSize */
    /* 0x24 */ s32 sheet;           /* AddObjectManagerSheetWorkSize */
    /* 0x28 */ s32 xff;             /* unloadCdXffFile */
    /* 0x2C */ s32 gameObject;      /* AddObjectManagerGameObjectSize */
} ObjMgrSizes;


extern ObjMgrSizes D_401AD480;
extern u8 *D_4012B040;
extern u8 D_4012B044[];
extern s32 rootPtn;
extern const char D_40133278[];

/* CreateGeoDispObj(c0095) param block, 6 words copied to obj+0xEC/0xD0/0xD4/0xD8/0xE0/0xE8 */
typedef struct GeoDispParam {
    /* 0x00 */ void *name;
    /* 0x04 */ void *disp;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ void *clip;
    /* 0x10 */ void *calcLight;
    /* 0x14 */ s32 unk14;
} GeoDispParam;
extern const GeoDispParam D_401332C8;
typedef struct DefSeg { /* animDef / lwsOriDef / skel segment header: count@0xC, array@0x10 */
    u8 pad0[0xC];
    s32 count;
    u8 *arr;
} DefSeg;
void initAnimDefSegOneElement(u8 *);
void func_40091BD8(u8 *);
void func_40091068(u8 *, s32 *);
void func_40091258(u8 *, u8 *);
extern s32 DldSysUndefSymbol;
typedef struct AmbLightSrc { /* initAmbientLightObj arg1 (script/resource node) */
    s32 unk0;
    u32 link;      /* +4: low 18 bits = distance back to a dld slot */
    s32 unk8;
    s32 unkC;
} AmbLightSrc;
typedef struct AmbLightParam { s32 a; s32 b; s32 c; } AmbLightParam;
u8 *CreateAmbientLightObj(s32 ptn, s32 sz, AmbLightParam *p);
/* dld cross-module link: *lp & 0x3FFFF = byte distance back from lp to a slot holding the resolved
   target (or DldSysUndefSymbol); the wanted value is a field of that target. */
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}
u8 *CreateGeoDispObj(s32 ptn, s32 arg1, GeoDispParam *param);

void isysMoveModuleObj();
void isysResolveOneModuleObj();
void modelReInitialize();
void shadowModelReInit();
void iosFree(void *);
s32 sheetFileGetSize(s32);
void isysRequestDeleteObj(void *);
void iosMallocSetExecGarbageCallback();
void texDelete();
void *iosMallocAlign(void *, s32, s32);
void sheetFileRead(s32, void *, s32);
void kSetTex(void *);
void *iosMallocInGarbagePtn(s32, s32);
void vschedSetNextFrameForceGarbage(void);
void sheetWait(void);
MgrModObj *isysCreateModuleObjExisted(void *, s32, void *, s32, s32, s32, void *);
s32 isysAddGroupWithLinkParam(void *, void *, s32, s32); /* int: the call_value keeps v0 busy, so the following flags test loads into v1 */
void iosJumpRecoverPoint(const char *);
u8 *sheetFileGetDataAdrs(s32);
s32 IsClusterCollision(void *);
u8 *isysGetXffEntryPointPreRelocation(void *);
s32 texGetWorkSize(u8 *);
void texInitialize(MgrModObj *, s32);
void windowSetTex(MgrModObj *);

void initParticleObject(s32 ptn, s32 arg1) {
    GeoDispParam param = D_401332C8;
    u8 *obj = CreateGeoDispObj(ptn, arg1, &param);

    if (obj == NULL) {
        obj = CreateGeoDispObj((s32)&rootPtn, arg1, &param);
    }
    *(s32 *)(obj + 0x108) = 0;
}

u8 *initAmbientLightObj(s32 ptn, AmbLightSrc *src) {
    u32 *lp = &src->link;
    u8 *slot;
    u8 *ref;
    u8 *obj;
    AmbLightParam param;
    AmbLightParam tmp;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    ref = (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + 0x10) : NULL;
    tmp.a = *(s32 *)(ref + 0xC);
    tmp.b = src->unk8;
    tmp.c = src->unkC;
    param = tmp;
    obj = CreateAmbientLightObj(ptn, 0x10, &param);
    if (obj != NULL) {
        isysAddGroupWithLinkParam(obj, D_4012B040 + 0x14, 0, 0);
    }
    return obj;
}

void InitBinarySize(void) {
    s32 i;
    s32 *p = &D_401AD480.motion;
    for (i = 11; i >= 0; i--) {
        p[i] = 0;
    }
}

void createBinaryMemoryInfoWindow(void) {
}

void AddObjectManagerCollisionWorkSizeBoss(s32 arg0) {
    D_401AD480.collisionBoss += arg0;
}

void AddObjectManagerCollisionWorkSizeStage(s32 arg0) {
    D_401AD480.collisionStage += arg0;
}

void AddObjectManagerSheetWorkSize(s32 arg0) {
    D_401AD480.sheet += arg0;
}

void AddObjectManagerGameObjectSize(s32 arg0) {
    D_401AD480.gameObject += arg0;
}

void AddObjectManagerSeamlessWorkSize(s32 arg0) {
    D_401AD480.seamless += arg0;
}

u8 *getObjInitMessageDebugSw(void) {
    return D_4012B044;
}

u8 *GetAmbientLightObjGroup(void) {
    return D_4012B040 + 0x14;
}

u8 *GetModelObjGroup(void) {
    return D_4012B040 + 4;
}

void skelSegInit(DefSeg *seg) {
    s32 n = seg->count;
    u8 *p = seg->arr;

    n--;

    for (; n != -1; n--, p += 0x24) {
        u8 *obj = *(u8 **)(*(u8 **)(p + 8) + 0x20);
        s32 *q = (s32 *)(p + 0x18);
        s32 j;

        for (j = 1; j != -1; j--) {
            func_40091068(obj, q);
            q++;
        }
        func_40091258(p + 0x20, obj);
    }
}

void skelSegDel(void) {
}

void debugCreateAnimObjSegmentDisp(void) {
}

void debugDeleteAnimObjSegmentDisp(void) {
}

void debugCreateAnimObjSegmentDefDisp(void) {
}

void debugDeleteAnimObjSegmentDefDisp(void) {
}

MgrModObj *loadCdMotionFile(s32 sheet, s32 unused, s32 size) {
    void *buf;
    MgrModObj *obj;
    u8 *data;
    void *ptn = &rootPtn;
    s32 z = 0;

    while ((buf = iosMallocInGarbagePtn(size, 0x10)) == NULL) {
        vschedSetNextFrameForceGarbage();
        sheetWait();
    }
    sheetFileRead(sheet, buf, size);
    obj = isysCreateModuleObjExisted(buf, z, ptn, 1, z, 1, z ? 0 : ptn);
    if (obj != NULL) {
        isysAddGroupWithLinkParam(obj, D_4012B040, 0, 0);
        if ((obj->flags & 0x40000000) == 0) {
            iosJumpRecoverPoint(D_40133278);
        }
    }
    data = sheetFileGetDataAdrs(sheet);
    if (obj != NULL) {
        D_401AD480.motion += size;
    }
    *(MgrModObj **)(data + 0xC) = obj;
    return obj;
}

void unloadCdMotionFile(s32 sheet, s32 unused, MgrModObj *obj) {
    u8 *data = sheetFileGetDataAdrs(sheet);
    if (*(s32 *)(data + 0xC) != 0) {
        *(s32 *)(data + 0xC) = 0;
        D_401AD480.motion -= sheetFileGetSize(sheet);
        isysRequestDeleteObj(obj);
    }
}

void garbageNmoCallBack(MgrModObj *obj) {
    isysMoveModuleObj(obj);
    isysResolveOneModuleObj(obj);
    modelReInitialize(obj->partition, obj->entry);
}

void unloadCdNmoFile(s32 sheet, s32 unused, MgrModObj *obj) {
    if (obj != NULL) {
        D_401AD480.nmo -= sheetFileGetSize(sheet);
        iosMallocSetExecGarbageCallback(obj->hdr, -1, 0);
        isysRequestDeleteObj(obj);
    }
}

void garbageNsoCallBack(MgrModObj *obj) {
    isysMoveModuleObj(obj);
    isysResolveOneModuleObj(obj);
    shadowModelReInit(obj->entry);
}

void unloadCdNsoFile(s32 sheet, s32 unused, MgrModObj *obj) {
    if (obj != NULL) {
        D_401AD480.nso -= sheetFileGetSize(sheet);
        iosMallocSetExecGarbageCallback(obj->hdr, -1, 0);
        isysRequestDeleteObj(obj);
    }
}

void garbageNtoCallBack(MgrModObj *obj) {
    isysMoveModuleObj(obj);
    *(MgrModObj **)(*(u8 **)((u8 *)obj->entry + 0xC) + 0x28) = obj;
}

void unloadCdNtoFile(s32 sheet, s32 unused, MgrModObj *obj) {
    if (obj != NULL) {
        D_401AD480.tex -= sheetFileGetSize(sheet);
        texDelete(obj);
        iosMallocSetExecGarbageCallback(obj->hdr, -1, 0);
        isysRequestDeleteObj(obj);
    }
}

MgrModObj *loadCdWinTexFile(s32 sheet, s32 unused, s32 size) {
    MgrModObj *ret = NULL;
    void *buf = iosMallocAlign(&rootPtn, size, 0x10);

    if (buf != NULL) {
        sheetFileRead(sheet, buf, size);
        ret = isysCreateModuleObjExisted(buf, texGetWorkSize(isysGetXffEntryPointPreRelocation(buf)), &rootPtn, 1, 0, 1, &rootPtn);
        if (ret != NULL) {
            D_401AD480.tex += size;
            texInitialize(ret, 0);
            windowSetTex(ret);
        }
    }
    return ret;
}

void unloadCdWinTexFile(s32 sheet, s32 unused, MgrModObj *obj) {
    if (obj != NULL) {
        D_401AD480.tex -= sheetFileGetSize(sheet);
        isysRequestDeleteObj(obj);
    }
}

void *loadCdNfbFile(s32 sheet, s32 unused, s32 size) {
    void *buf = iosMallocAlign(&rootPtn, size, 0x10);
    if (buf != NULL) {
        sheetFileRead(sheet, buf, size);
        kSetTex(buf);
    }
    return buf;
}

void unloadCdNfbFile(s32 a0, s32 a1, void *buf) {
    if (buf != NULL) {
        iosFree(buf);
    }
}

MgrModObj *loadCdXffFile(s32 sheet, s32 unused, s32 size) {
    void *buf;
    MgrModObj *obj;
    void *ptn = &rootPtn;
    s32 z = 0;
    MgrModObj *ret;

    while ((buf = iosMallocInGarbagePtn(size, 0x10)) == NULL) {
        vschedSetNextFrameForceGarbage();
        sheetWait();
    }
    sheetFileRead(sheet, buf, size);
    obj = isysCreateModuleObjExisted(buf, z, ptn, 1, z, 1, z ? 0 : ptn);
    if (obj != NULL) {
        isysAddGroupWithLinkParam(obj, D_4012B040, 0, 0);
        if ((obj->flags & 0x40000000) == 0) {
            iosJumpRecoverPoint(D_40133278);
        }
    }
    ret = obj;
    if (ret != NULL) {
        D_401AD480.xff += size;
    }
    return ret;
}

void unloadCdXffFile(s32 sheet, s32 unused, MgrModObj *obj) {
    D_401AD480.xff -= sheetFileGetSize(sheet);
    if (obj != NULL) {
        isysRequestDeleteObj(obj);
    }
}

void garbageColResCallBack(MgrModObj *obj) {
    isysMoveModuleObj(obj);
}

void unloadCdColResFile(s32 sheet, s32 unused, MgrModObj *obj) {
    if (IsClusterCollision(obj->entry) != 0) {
        D_401AD480.colResCluster -= sheetFileGetSize(sheet);
    } else {
        D_401AD480.colRes -= sheetFileGetSize(sheet);
    }
    isysRequestDeleteObj(obj);
}

void initAnimDefSeg(DefSeg *seg) {
    s32 n = seg->count;
    u8 *p = seg->arr;

    n--;

    for (; n != -1; n--) {
        u8 *cur = p;
        p += 0x74;
        initAnimDefSegOneElement(cur);
    }
}

void deleteAnimDefSeg(DefSeg *seg) {
    s32 n = seg->count;
    u8 *p = seg->arr;

    n--;

    for (; n != -1; n--, p += 0x74) {
        if (*(void **)(p + 0x6C) != NULL) {
            isysRequestDeleteObj(*(void **)(p + 0x6C));
            *(s32 *)(p + 0x6C) = 0;
        }
    }
}

void initLwsOriDefSeg(DefSeg *seg) {
    s32 n = seg->count;
    u8 *p = seg->arr;

    n--;

    for (; n != -1; n--) {
        u8 *cur = p;
        p += 0x18;
        func_40091BD8(cur);
    }
}

/* NEARMISS-STUB deleteLwsOriDefSeg */
#if 0 /* NEARMISS 97.31% cat=-alias sub=- | 100 only with `*(u32 *)lp` in dldRef (two link-word loads); is not used (human, 2026-10-18) | attempts=1 */
void deleteLwsOriDefSeg(DefSeg *seg) {
    s32 n = seg->count;
    u8 *p = seg->arr;

    n--;
    for (; n != -1; n--, p += 0x18) {
        u32 *lp = (u32 *)(p + 0x10);
        u8 *sub;
        u8 *cnt;
        s32 m;

        sub = dldRef(lp, 0x10);
        cnt = dldRef(lp, 0xC);
        m = (s32)cnt - 1;
        for (; m != -1; m--, sub += 0x2C) {
            if (*(void **)(sub + 0x28) != NULL) {
                isysRequestDeleteObj(*(void **)(sub + 0x28));
                *(s32 *)(sub + 0x28) = 0;
            }
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0113_initParticleObject", deleteLwsOriDefSeg);
