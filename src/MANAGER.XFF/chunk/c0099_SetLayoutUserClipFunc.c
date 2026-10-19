#include "common.h"

extern char *GetScriptLayoutClass(void *);
extern void *dynamic_cast_to_camera_obj(void *);
extern char *get_camera_obj_layout_class(void *);
extern char *GetLightClass(void *);

static inline char *layoutClass(unsigned char *o)
{
    switch (o[8]) {
    case 0xA:
        return (char *)o + 0x20;
    case 0xB:
        return GetScriptLayoutClass(o) + 0x70;
    case 0x11:
        return get_camera_obj_layout_class(dynamic_cast_to_camera_obj(o));
    case 0x13:
        return GetLightClass(o);
    case 9:
    case 0xD:
    case 0x16:
        return (char *)o + 0x90;
    default:
        return 0;
    }
}


void SetLayoutUserClipFunc(unsigned char *o, void *fn)
{
    char *p = *(char **)(layoutClass(o) + 0x140);

    if (p != 0)
        *(void **)(p + 0xDC) = fn;
}


extern int GetClothWorkSize(int);
extern int func_40084740(void *);
extern u8 *_isysCreateObj(void *, s32, s32, s32, void *, s32);
extern void isysSetObjImmediateDeleteFunc(void *, void *);
extern void InitLayoutObj(void *, void *);
extern void InitAliasLayoutObj(void *, void *, void *);
extern void func_40088500();
extern void func_400884E8();

u8 *CreateLayoutObj(void *heap, s32 size, void *def)
{
    s32 cw = 0;
    void *c = *(void **)((char *)def + 0xC);
    u8 *obj;

    if (c != 0) {
        cw = GetClothWorkSize(*(int *)((char *)*(void **)((char *)c + 8) + 0x20));
    }
    obj = _isysCreateObj(heap, 0xA, 0x1E0, size + (cw + func_40084740(def)), func_40088500, 0x10);
    if (obj != 0) {
        InitLayoutObj(obj, def);
        isysSetObjImmediateDeleteFunc(obj, func_400884E8);
    }
    return obj;
}

u8 *CreateAliasLayoutObj(void *heap, s32 size, void *def, void *src)
{
    s32 cw = 0;
    void *c = *(void **)((char *)def + 0xC);
    u8 *obj;

    if (c != 0) {
        cw = GetClothWorkSize(*(int *)((char *)*(void **)((char *)c + 8) + 0x20));
    }
    obj = _isysCreateObj(heap, 0xA, 0x1E0, size + cw, func_40088500, 0x10);
    if (obj != 0) {
        InitAliasLayoutObj(obj, def, src);
        isysSetObjImmediateDeleteFunc(obj, func_400884E8);
    }
    return obj;
}

int GetLayoutObjWorkSize(void *arg0)
{
    int var_s1;
    void *temp_v0;

    temp_v0 = (*(void **)((char *)(arg0) + 0xC));
    var_s1 = 0;
    if (temp_v0 != NULL) {
        var_s1 = GetClothWorkSize((*(int *)((char *)((*(void **)((char *)(temp_v0) + 8))) + 0x20)));
    }
    return var_s1 + func_40084740(arg0);
}

/* NEARMISS-STUB FlushCollisionWork */
#if 0 /* NEARMISS 99.69% cat=branch-layout sub=- | layoutClass switch inline + early returns match; only the bltz (id<0 -> return 0) target: target redirects past the ld ra it stole into the delay slot (0x314),  | attempts=1 */
extern int FlushCollisionWorkByWorkStruct(int, int, int, int);

int FlushCollisionWork(unsigned char *o)
{
    char *l = layoutClass(o);
    char *p = *(char **)(l + 0x184);
    char *d;

    if (p == 0) {
        return 0;
    }
    if (*(int *)(l + 0x174) < 0) {
        return 0;
    }
    d = *(char **)(p + 0x20);
    return FlushCollisionWorkByWorkStruct(*(int *)(l + 0x174), *(int *)(d + 4), *(int *)(d + 0x10), *(int *)(d + 0xC));
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", FlushCollisionWork);

void SetLayoutObjSubDispFunc(unsigned char *o, void *a, void *b)
{
    char *l = layoutClass(o);
    char *p;

    if (l != 0) {
        p = *(char **)(l + 0x140);
        *(void **)(p + 0xD4) = a;
        *(void **)(p + 0xE4) = b;
    }
}

extern void DeleteTwoWayLink(void *);
extern void *GetLayoutClass(void *);
extern void *GetGeometryPointerObject(void *);
extern void CopyGeometryPointer(void *, void *);
extern int AddTwoWayLinkNext(int *, int *);
typedef union { s128 q; float f[4]; } PVec4;
extern void GetGeometryPointerQuaternion();
extern void DivQuaternion();

static inline int forceParentLayoutObj(void *object, void *geometry)
{
    char *layout;
    char *storedGeometry;
    void *newParent;
    void *oldParent;
    char *parentLayout;

    layout = GetLayoutClass(object);
    storedGeometry = layout + 0xC0;
    newParent = GetGeometryPointerObject(geometry);
    oldParent = GetGeometryPointerObject(storedGeometry);
    CopyGeometryPointer(storedGeometry, geometry);
    if ((*(int *)(layout + 0x124)) == 0) {
        (*(int *)(layout + 0x124)) = 1;
    } else {
        if (oldParent == newParent) {
            return 0;
        }
        DeleteTwoWayLink(layout + 0x100);
    }
    if (newParent != 0) {
        parentLayout = GetLayoutClass(newParent);
        AddTwoWayLinkNext((int *)(parentLayout + 0x10C), (int *)(layout + 0x100));
    }
    return 0;
}

int ParentLayoutObj(void *object, void *geometry)
{
    char *l;
    PVec4 q;

    l = GetLayoutClass(object);
    GetGeometryPointerQuaternion(&q, geometry);
    DivQuaternion(l + 0x60, *(void **)(l + 0x13C), &q);
    return forceParentLayoutObj(object, geometry);
}

extern void SetGeometryPointerGlobalState(void *, void *, void *);
extern u8 IdentityQuaternion[];
extern u8 ZeroPoint[];

void ForceUnparentLayoutObj(void *actor)
{
    void *temp_v0;

    temp_v0 = GetLayoutClass(actor);
    if ((*(int *)((char *)(temp_v0) + 0x124)) != 0) {
        (*(s128 *)((char *)(temp_v0) + 0x60)) = (s128) *(*(s128 **)((char *)(temp_v0) + 0x13C));
        SetGeometryPointerGlobalState(temp_v0 + 0xC0, IdentityQuaternion, ZeroPoint);
        DeleteTwoWayLink(temp_v0 + 0x100);
        (*(int *)((char *)(temp_v0) + 0x124)) = 0;
    }
}

extern void func_400884D0(void);
extern void DeleteAllTwoWayLink(void *, void (*)(void));

void ForceDeleteLayoutObjChildLink(unsigned char *o)
{
    DeleteAllTwoWayLink(layoutClass(o) + 0x10C, func_400884D0);
}

extern void *GetGeometryPointerObject(void *);
extern void CopyGeometryPointer(void *, void *);
extern int AddTwoWayLinkNext(int *, int *);

int ForceParentLayoutObj(void *object, void *geometry)
{
    char *layout;
    char *storedGeometry;
    void *newParent;
    void *oldParent;
    char *parentLayout;

    layout = GetLayoutClass(object);
    storedGeometry = layout + 0xC0;
    newParent = GetGeometryPointerObject(geometry);
    oldParent = GetGeometryPointerObject(storedGeometry);
    CopyGeometryPointer(storedGeometry, geometry);
    if ((*(int *)(layout + 0x124)) == 0) {
        (*(int *)(layout + 0x124)) = 1;
    } else {
        if (oldParent == newParent) {
            return 0;
        }
        DeleteTwoWayLink(layout + 0x100);
    }
    if (newParent != 0) {
        parentLayout = GetLayoutClass(newParent);
        AddTwoWayLinkNext((int *)(parentLayout + 0x10C), (int *)(layout + 0x100));
    }
    return 0;
}

extern void *GetSubLinkClass(void *);

void AddLayoutObjSubLink(void *a, void *b)
{
    char *l = GetLayoutClass(a);
    void *s = GetSubLinkClass(b);
    AddTwoWayLinkNext((int *)(l + 0x10C), s);
}

extern void func_400883C0(void);

void ForceUnparentLayoutObjChildLink(unsigned char *o)
{
    DeleteAllTwoWayLink(layoutClass(o) + 0x10C, func_400883C0);
}

typedef union { s128 q; float f[4]; int i[4]; } Vec4;
extern void GetGeometryPointerQuaternion(Vec4 *, char *);
extern void DivQuaternion(char *, Vec4 *, Vec4 *);

void SetLayoutClassRootQuaternion(char *l, Vec4 *q)
{
    Vec4 g;
    (*(Vec4 **)(l + 0x13C))->q = q->q;
    if (*(int *)(l + 0x124) != 0) {
        GetGeometryPointerQuaternion(&g, l + 0xC0);
        DivQuaternion(l + 0x60, q, &g);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", UpdateLayoutClassParentGeometry);

extern s32 D_40132420;
extern void *modelGetName(int);

void *GetLayoutClassObjectName(unsigned char *o)
{
    void **p = *(void ***)(o + 0x144);

    if (p != 0) {
        void *temp = *p;

        if (temp != 0) {
            return modelGetName(*(int *)((unsigned char *)temp + 0x20));
        }
    }
    return &D_40132420;
}

extern void CopyMultiMatrix(int, int, short);

void UpdateLayoutClassPastSimpleGeometry(void *arg0)
{
    *(*(s128 **)((char *)(arg0) + 0x138)) = *(*(s128 **)((char *)(arg0) + 0x134));
    (*(s128 *)((char *)(arg0) + 0xB0)) = (s128) (*(s128 *)((char *)(arg0) + 0xA0));
    if ((*(unsigned char *)((char *)(arg0) + 0x1BC)) & 0x20) {
        CopyMultiMatrix((*(int *)((char *)(arg0) + 0x168)), (*(int *)((char *)(arg0) + 0x164)), (*(short *)((char *)(arg0) + 0x1B4)));
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", UpdateLayoutClassParentSimpleGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", UpdateLayoutClassGeometry);
