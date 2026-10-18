#include "common.h"

/* NEARMISS-STUB SetLayoutUserClipFunc */
#if 0 /* NEARMISS 99.75% cat=rodata-const sub=- | in-TU: jump-table reloc names .rodata instead of D_401329B0; all insns match | attempts=1 */

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
#endif
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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", SetLayoutUserClipFunc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", CreateLayoutObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", CreateAliasLayoutObj);

extern int GetClothWorkSize(int);
extern int func_40084740(void *);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0099_SetLayoutUserClipFunc", ParentLayoutObj);

extern void DeleteTwoWayLink(void *);
extern void *GetLayoutClass(void *);
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
