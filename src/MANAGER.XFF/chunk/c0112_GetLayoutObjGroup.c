#include "common.h"

extern u8 *D_4012B040;
extern s32 DldSysUndefSymbol;
void isysInitGroup(u8 *);
s32 strcmp(const char *, const char *);
s32 GetSkeletonFocusNodeDirect(u8 *e);

/* dld link word: bits 0..17 = byte distance back to a slot holding the target (or DldSysUndefSymbol),
   bits 18..29 = element index */
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

/* element = table->arr(+0x10) + idx * table->desc(+8)->elemSize(+0xC) */
static inline u8 *dldElem(u32 *lp) {
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}

u8 *GetLayoutObjGroup(void) {
    return D_4012B040 + 0xC;
}

u8 *GetLayoutDispObjGroup(void) {
    return D_4012B040 + 0x10;
}

void InitObjectManagerResourceInfo(u8 *p) {
    D_4012B040 = p;
    isysInitGroup(p + 4);
    isysInitGroup(D_4012B040);
    isysInitGroup(D_4012B040 + 8);
    isysInitGroup(D_4012B040 + 0xC);
    isysInitGroup(D_4012B040 + 0x10);
    isysInitGroup(D_4012B040 + 0x14);
    isysInitGroup(D_4012B040 + 0x18);
}

s32 initSkelObjResource(u32 *lp) {
    if (lp == NULL) {
        return 0;
    }
    return *(s32 *)(dldElem(lp) + 8);
}

s32 initDispObjResource(u32 *lp) {
    u8 *e = dldElem(lp);
    if (e == NULL) {
        return 0;
    }
    return *(s32 *)(e + 8);
}

s32 initShadowObjResource(u32 *lp) {
    u8 *e = dldElem(lp);
    if (e == NULL) {
        return 0;
    }
    return *(s32 *)(e + 8);
}

s32 initColObjResource(u32 *lp) {
    u8 *e = dldElem(lp);
    if (e == NULL) {
        return 0;
    }
    return *(s32 *)(e + 8);
}

s32 initAnimationObjResource(u32 *lp) {
    u8 *e = dldElem(lp);
    if (e == NULL) {
        return 0;
    }
    return *(s32 *)(e + 8);
}

s32 initClothObjResource(u32 *lp) {
    u8 *e = dldElem(lp);
    if (e == NULL) {
        return 0;
    }
    return *(s32 *)(e + 8);
}

s32 GetSkeletonFocusNode(u32 *lp) {
    return GetSkeletonFocusNodeDirect(dldElem(lp));
}

s32 GetSkeletonFocusNodeDirect(u8 *e) {
    if (e == NULL) {
        return -1;
    }
    return *(s32 *)(e + 8);
}

u8 *SearchLayoutObjDefByName(u32 *lp, const char *name) {
    s32 n;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    n = cnt - 1;
    for (; n != -1; n--, p += 0x18) {
        if (strcmp(*(const char **)p, name) == 0) {
            return p;
        }
    }
    return NULL;
}

u8 *SearchScriptLayoutObjDefByName(u32 *lp, const char *name) {
    s32 n;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    n = cnt - 1;
    for (; n != -1; n--, p += 0x34) {
        if (strcmp(*(const char **)p, name) == 0) {
            return p;
        }
    }
    return NULL;
}

u8 *SearchLwsOrientObjDefByName(u32 *lp, const char *name) {
    s32 n;
    u8 *p;
    s32 cnt = (s32)dldRef(lp, 0xC);

    p = dldRef(lp, 0x10);
    n = cnt - 1;
    for (; n != -1; n--, p += 0x18) {
        if (strcmp(*(const char **)p, name) == 0) {
            return p;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0112_GetLayoutObjGroup", initScriptAnimationObj);

/* NEARMISS-STUB initLightObj */
#if 0 /* NEARMISS 77.2% cat=regalloc sub=- | 0xB0 tmp+dst struct copy: target keeps obj in s3 and loads a2/a1 fields in different order; frame needs 4th saved reg | attempts=1 */
extern u8 D_401332B0[];
void CreateLightObj(u8 *, s32, void *);
void *memset(void *, s32, u32);

typedef struct LightObjSrcA {
    s32 unk00;
    s32 unk04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} LightObjSrcA;

typedef struct LightObjSrcB {
    u8 pad00[0x14];
    s32 unk14;
    f32 f18;
    u8 pad1C[0x8];
    s32 unk24;
} LightObjSrcB;

typedef struct LightObjDef {
    void *vt;
    s32 kind;
    u8 pad08[0x44];
    s32 unk4C;
    f32 f50;
    s32 unk54;
    u8 pad58[0x24];
    s32 unk7C;
    f32 f80;
    f32 f84;
    f32 f88;
    s32 unk8C;
    f32 f90;
    f32 f94;
    f32 f98;
    s32 unk9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x8];
} LightObjDef;

void initLightObj(u8 *obj, LightObjSrcA *a1, LightObjSrcB *a2) {
    LightObjDef dst;
    LightObjDef tmp;

    memset(&tmp, 0, 0x7C);
    tmp.vt = D_401332B0;
    tmp.kind = 1;
    tmp.unk4C = a2->unk14;
    tmp.f50 = a2->f18;
    tmp.unk54 = a2->unk24;
    tmp.unk7C = a1->unk04;
    tmp.f80 = a1->f08;
    tmp.f84 = a1->f0C;
    tmp.f88 = a1->f10;
    tmp.unk8C = 0;
    tmp.f90 = a1->f14;
    tmp.f94 = a1->f18;
    tmp.f98 = a1->f1C;
    tmp.unk9C = 0;
    tmp.fA0 = a1->f20;
    tmp.fA4 = a1->f24;
    dst = tmp;
    CreateLightObj(obj, 0x10, &dst);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0112_GetLayoutObjGroup", initLightObj);
/* NEARMISS-STUB initScriptSpriteObj */
#if 0 /* NEARMISS 80.8% cat=sched sub=load-order | frame and struct copy loop match; only order of the 14 pre-store loads differs | attempts=1 */
void initScriptSpriteObj(s32 ptn, SpriteSrc *src, s32 a2, s32 a3, s32 a4, s32 a5) {
    SpriteParam param2;
    SpriteParam param;

    param.unk0 = src->unk0;
    param.link = &src->link;
    param.res = (s32)dldRef(&src->link, 0xC);
    param.f0C = src->f18;
    param.f10 = src->f1C;
    param.f14 = src->f20;
    param.f18 = src->f24;
    param.f1C = src->f28;
    param.unk20 = src->unk2C;
    param.f24 = src->f30;
    param.f28 = src->f34;
    param.f2C = src->f38;
    param.f30 = src->f3C;
    param.unk34 = src->unk40;
    param.unk38 = src->unk14;
    param.unk3C = src->unk8;
    param.a2 = a2;
    param.unk44 = src->unkC;
    param.a4 = a4;
    param.a3 = a3;
    param.a5 = a5;
    param.z54 = 0;
    param.z58 = 0;
    param.z5C = 0;
    param2 = param;
    CreateScriptSpriteObj(ptn, src->unk10, &param2);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0112_GetLayoutObjGroup", initScriptSpriteObj);

/* NEARMISS-STUB initScriptSpriteMenuObj */
#if 0 /* NEARMISS 72.96% cat=regalloc sub=struct-copy-frame | 0x170 frame, 0x50 param struct copy loop and dld link match; target loads f32 fields in order f18,f1C,f20,f24,f28,f2C with other regs (f3/f4 swapped) and loads  | attempts=1 */
extern s32 sheetFsLanguageCode;
void CreateScriptSpriteMenuObj(s32, s32, void *);

typedef struct MenuObjSrc {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    s32 unk30;
} MenuObjSrc;

typedef struct MenuObjParam {
    s32 unk00;
    s32 res;
    u32 *link;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 a2;
    s32 unk34;
    s32 a4;
    s32 a3;
    s32 a5;
    s32 z44;
    s32 z48;
    s32 z4C;
} MenuObjParam;

void initScriptSpriteMenuObj(s32 ptn, MenuObjSrc *src, s32 a2, s32 a3, s32 a4, s32 a5) {
    MenuObjParam param2;
    MenuObjParam param;

    param.unk00 = src->unk00;
    param.link = (u32 *)src + sheetFsLanguageCode;
    param.res = (s32)dldRef(param.link, 0xC);
    param.f0C = src->f18;
    param.f10 = src->f1C;
    param.f14 = src->f20;
    param.f18 = src->f24;
    param.f1C = src->f28;
    param.f20 = src->f2C;
    param.unk24 = src->unk30;
    param.unk28 = src->unk14;
    param.unk2C = src->unk08;
    param.a2 = a2;
    param.unk34 = src->unk0C;
    param.a4 = a4;
    param.a3 = a3;
    param.a5 = a5;
    param.z44 = 0;
    param.z48 = 0;
    param.z4C = 0;
    param2 = param;
    CreateScriptSpriteMenuObj(ptn, src->unk10, &param2);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0112_GetLayoutObjGroup", initScriptSpriteMenuObj);
