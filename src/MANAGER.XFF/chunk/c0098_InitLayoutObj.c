#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", InitLayoutObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", InitAliasLayoutObj);

extern u8 *GetScriptLayoutClass(u8 *);
extern u8 *dynamic_cast_to_camera_obj(u8 *);
extern u8 *get_camera_obj_layout_class(u8 *);
extern u8 *GetLightClass(u8 *);

static inline u8 *layoutClass(u8 *o)
{
    switch (o[8]) {
    case 0xA:
        return o + 0x20;
    case 0xB:
        return GetScriptLayoutClass(o) + 0x70;
    case 0x11:
        return get_camera_obj_layout_class(dynamic_cast_to_camera_obj(o));
    case 0x13:
        return GetLightClass(o);
    case 9:
    case 0xD:
    case 0x16:
        return o + 0x90;
    default:
        return 0;
    }
}

typedef int qword __attribute__((mode(TI)));

extern u8 IdentityQuaternion[];
extern u128 ZeroPoint;
extern u8 *GetLayoutClass(void *);
extern void SetGeometryPointerGlobalState(void *, void *, void *);
extern void DeleteTwoWayLink(void *);
extern void ReleaseCollisionWork(void *);

int FlushLayoutObj(u8 *o)
{
    u8 *l = layoutClass(o);
    u8 *c;

    if (*(s8 *)(l + 0x1BA) == 0) {
        c = GetLayoutClass(o);
        if (*(s32 *)(c + 0x124) != 0) {
            *(qword *)(c + 0x60) = **(qword **)(c + 0x13C);
            SetGeometryPointerGlobalState(c + 0xC0, IdentityQuaternion, &ZeroPoint);
            DeleteTwoWayLink(c + 0x100);
            *(s32 *)(c + 0x124) = 0;
        }
        if (*(s32 *)(l + 0x174) != 0)
            ReleaseCollisionWork(l + 0x174);
        l[0x1BA] = 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", FlushLayoutObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", FlushLayoutObjImmediate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", GetLayoutObjChildWithName);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", SaveLayoutObjGroupAllGeo);

extern void *GetLayoutObjGroup();
extern void **isysGroupForFirst(void *, int);
extern void **isysGroupForNext(void **, int);
extern void isysGroupForExit(void *, int);

void SaveLayoutObjGroupAllGeo(void)
{
    u8 *o = 0;
    void **g;
    u8 *l;

    for (g = isysGroupForFirst(GetLayoutObjGroup(), 0); g != 0; g = isysGroupForNext(g, 0)) {
        o = *g;
        l = layoutClass(o);
        if (l != 0 && *(void **)(l + 0x190) != 0)
            (*(void (**)(void *))(l + 0x190))(*(void **)(l + 0x1A4));
    }
    if (o != 0)
        isysGroupForExit(o, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", SetLayoutObjAccessSwitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", func_40086590);

extern void *GetLayoutObjGroup(void *);
extern void **isysGroupForFirst(void *, int);
extern void **isysGroupForNext(void **, int);
extern void isysGroupForExit(void *, int);

int GetLayoutObjNum(void *l)
{
    void *last = 0;
    int n = 0;
    void **e;
    for (e = isysGroupForFirst(GetLayoutObjGroup(l), 0); e != 0; e = isysGroupForNext(e, 0)) {
        last = *e;
        n++;
    }
    if (last != 0)
        isysGroupForExit(last, 0);
    return n;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", GetLayoutObjNum);

extern void *GetLayoutDispObjGroup(void *);

int GetLayoutDispObjNum(void *l)
{
    void *last = 0;
    int n = 0;
    void **e;
    for (e = isysGroupForFirst(GetLayoutDispObjGroup(l), 0); e != 0; e = isysGroupForNext(e, 0)) {
        last = *e;
        n++;
    }
    if (last != 0)
        isysGroupForExit(last, 0);
    return n;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", GetLayoutDispObjNum);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0098_InitLayoutObj", GetLayoutClass);

u8 *GetLayoutClass(void *o)
{
    switch (((u8 *)o)[8]) {
    case 0xA:
        return (u8 *)o + 0x20;
    case 0xB:
        return GetScriptLayoutClass(o) + 0x70;
    case 0x11:
        return get_camera_obj_layout_class(dynamic_cast_to_camera_obj(o));
    case 0x13:
        return GetLightClass(o);
    case 9:
    case 0xD:
    case 0x16:
        return (u8 *)o + 0x90;
    default:
        return 0;
    }
}
