#include "common.h"

typedef struct SmLayer
{
    s32 unk0;
    s32 status;
    u8 pad8[0xC];
    u8 *parts;
    s32 numParts;
    u8 pad1C[0x1C];
    s32 priority;
    u8 pad3C[0x8];
    s32 active;
    s32 padCallback;
    s32 subPadCallback;
    u8 pad50[0xC];
    s32 mode;
    s32 menuId;
    s32 subMenuId;
} SmLayer;

static inline u8 *smClass(u8 *spriteMenu)
{
    return (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
}

static inline SmLayer *smLayer(u8 *p, s32 layer)
{
    SmLayer *l = *(SmLayer **)(p + 4);

    return &l[layer];
}


/* NEARMISS-STUB func_400A5468 */
#if 0 /* NEARMISS 77.37% cat=regalloc sub=- | nested dld-ref loop sums (155/163/67/95 weights); regalloc of ent/sub/t2 (category inferred) (77.37) | attempts=1 */
extern s32 DldSysUndefSymbol;

/* dld cross-module link: *lp & 0x3FFFF = byte distance back from lp to a slot holding the resolved
   target (or DldSysUndefSymbol); the wanted value is a field of that target. */
static inline u8 *dldRef(u32 *lp, s32 fld)
{
    u8 *slot;
    u32 off = *(volatile u32 *)lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

s32 func_400A5468(u8 *obj)
{
    s32 count;
    s32 total;
    s32 i;
    s32 j;
    s32 c2;
    s32 t2;
    u8 *arr;
    u8 *ent;
    u8 *sub;
    u32 *lp;

    lp = *(u32 **)(obj + 8);
    arr = dldRef(lp, 0x10);
    count = (s32)dldRef(lp, 0xC);
    total = count * 155;
    if (count > 0)
    {
        ent = arr;
        for (i = count; i != 0; i--)
        {
            sub = dldRef((u32 *)ent, 0x10);
            c2 = (s32)dldRef((u32 *)ent, 0xC);
            total += c2 * 163;
            total += c2 * 67;
            t2 = 0;
            if (c2 > 0)
            {
                for (j = c2; j != 0; j--)
                {
                    if (*(s32 *)(sub + 0x14) >= 0)
                    {
                        t2++;
                    }
                    sub += 0x80;
                }
            }
            total += t2 * 95;
            ent += 0x18;
        }
    }
    return total + 0x40;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", func_400A5468);
/* NEARMISS-STUB GetSpriteMenuClass */
#if 0 /* NEARMISS 77.1% cat=regalloc sub=- | gcc emits xori v1,v1,0x21 (immediate); expected keeps 0x21 in a0 (addiu a0,zero,0x21) and uses xor v1,v1,a0; no C form tried (ternary, s32 key, ==, ^) changed i | attempts=1 */
void *GetSpriteMenuClass(void *spriteMenu)
{
    s32 type = ((u8 *)spriteMenu)[8];
    s32 key = 0x21;

    return (type == key) ? (u8 *)spriteMenu + 0x90 : NULL;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", GetSpriteMenuClass);

/* NEARMISS-STUB GetScriptSpriteMenuClass */
#if 0 /* NEARMISS 77.1% cat=regalloc sub=- | same as GetSpriteMenuClass: gcc emits xori v1,v1,0x21; expected addiu a0,zero,0x21 + xor v1,v1,a0 | attempts=1 */
void *GetScriptSpriteMenuClass(void *spriteMenu)
{
    s32 type = ((u8 *)spriteMenu)[8];
    s32 key = 0x21;

    return (type == key) ? (u8 *)spriteMenu + 0x20 : NULL;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", GetScriptSpriteMenuClass);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuEnableExtOkButton);

extern s32 D_4012B2AC;

void SpriteMenuEnableExtOkButton(void)
{
    D_4012B2AC = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuDisableExtOkButton);

void SpriteMenuDisableExtOkButton(void)
{
    D_4012B2AC = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", setSpriteMenuAnimParam);

void setSpriteMenuAnimParam(u8 *spriteMenu, s32 a1, s32 a2, s32 a3, f32 f12)
{
    s32 v0;

    if (spriteMenu != NULL)
    {
        v0 = *(s32 *)(spriteMenu + 0x18);
        if (v0 == 0 || a3 != 0)
        {
            if (v0 != a1)
            {
                *(f32 *)(spriteMenu + 0x20) = f12;
            }
            *(s32 *)(spriteMenu + 0x18) = a1;
            *(s32 *)(spriteMenu + 0x1C) = a2;
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetNumPartsFormat);

void SpriteMenuSetNumPartsFormat(u8 *spriteMenu, s32 format)
{
    spriteMenu[0xF] = format;
}

/* NEARMISS-STUB SpriteMenuSetDispFlag */
#if 0 /* NEARMISS 76.0% cat=branch-layout sub=- | expected signed bltz/slti chain for [4,5] test, gcc sltiu range | attempts=1 */
void SpriteMenuSetDispFlag(u8 *spriteMenu, s32 layer, s32 flag)
{
    s32 state;
    u8 *p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;

    if (flag != 0)
    {
        state = *(s32 *)(obj + 4);
        if (state == 0)
        {
            *(s32 *)(obj + 4) = 1;
        }
        else if (!(state < 0 || state >= 6 || state < 4))
        {
            *(s32 *)(obj + 4) = 1;
        }
    }
    else
    {
        state = *(s32 *)(obj + 4);
        if ((u32)(state - 1) < 3)
        {
            *(s32 *)(obj + 4) = 4;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlag);

/* NEARMISS-STUB SpriteMenuSetDispFlagNoFade */
#if 0 /* NEARMISS 52.0% cat=branch-layout sub=- | expected non-tail jal in flag==0 path; gcc tail-calls; sltiu vs bltz/slti | attempts=1 */
void func_400A6A90(u8 *obj);

void SpriteMenuSetDispFlagNoFade(u8 *spriteMenu, s32 layer, s32 flag)
{
    u8 *p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;
    s32 state;

    if (flag != 0)
    {
        state = *(s32 *)(obj + 4);
        if (state == 0 || (state >= 4 && state < 6))
        {
            *(s32 *)(obj + 4) = 3;
            func_400A6A90(obj);
        }
    }
    else
    {
        state = *(s32 *)(obj + 4);
        if (state > 0 && state < 4)
        {
            *(s32 *)(obj + 4) = 0;
            func_400A6A90(obj);
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagNoFade);

/* NEARMISS-STUB SpriteMenuSetDispFlagByHash */
#if 0 /* NEARMISS 62.18% cat=branch-layout sub=- | layer search peeled at element 0; state test branch order (==0 / 4..5 / 1..3) (62.18) | attempts=1 */
void SpriteMenuSetDispFlagByHash(u8 *spriteMenu, s32 hash, s32 flag)
{
    s32 i;
    s32 count;
    s32 layer;
    s32 state;
    u8 *base;
    u8 *obj;
    u8 *p;

    p = smClass(spriteMenu);
    count = *(s32 *)(p + 8);
    base = *(u8 **)(p + 4);
    layer = -1;
    if (count > 0)
    {
        if (*(s32 *)(*(u8 **)base + 4) == hash)
        {
            layer = 0;
        }
        else
        {
            for (i = 1; i < count; i++)
            {
                if (*(s32 *)(*(u8 **)(base + i * 0x68) + 4) == hash)
                {
                    layer = i;
                    break;
                }
            }
        }
    }
    obj = base + layer * 0x68;
    if (flag != 0)
    {
        state = *(s32 *)(obj + 4);
        if (state == 0 || (state >= 4 && state < 6))
        {
            *(s32 *)(obj + 4) = 1;
        }
    }
    else
    {
        state = *(s32 *)(obj + 4);
        if ((u32)(state - 1) < 3)
        {
            *(s32 *)(obj + 4) = 4;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagByHash);

/* NEARMISS-STUB SpriteMenuSetDispFlagAll */
#if 0 /* NEARMISS 70.07% cat=branch-layout sub=- | pointer-walk loop with combined i++/obj+=0x68; state test branch layout (70.07) | attempts=1 */
void SpriteMenuSetDispFlagAll(u8 *spriteMenu, s32 flag)
{
    s32 i;
    s32 state;
    u8 *p;
    u8 *obj;

    p = smClass(spriteMenu);
    obj = *(u8 **)(p + 4);
    for (i = 0; i < *(s32 *)(p + 8); i++, obj += 0x68)
    {
        state = *(s32 *)(obj + 4);
        if (flag != 0)
        {
            if (state == 0 || (state >= 4 && state < 6))
            {
                *(s32 *)(obj + 4) = 1;
                func_400A6A90(obj);
            }
        }
        else
        {
            if (state > 0 && state < 4)
            {
                *(s32 *)(obj + 4) = 4;
                func_400A6A90(obj);
            }
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagAll);

void func_400A2800(u8 *obj);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetLayer);

void SpriteMenuSetLayer(u8 *spriteMenu, s32 layer)
{
    u8 *p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + *(s32 *)(p + 0xC) * 0x68;

    *(s32 *)(obj + 0x44) = 0;
    func_400A2800(obj);
    *(s32 *)(p + 0xC) = layer;
    obj = *(u8 **)(p + 4) + layer * 0x68;
    *(s32 *)(obj + 0x44) = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetLayerStatus);

s32 SpriteMenuGetLayerStatus(u8 *spriteMenu, s32 layer)
{
    s32 off = layer * 0x68;
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    return *(s32 *)(*(u8 **)(p + 4) + off + 4);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSpriteObject);

s32 SpriteMenuGetSpriteObject(u8 *spriteMenu, s32 layer, s32 index)
{
    s32 off = layer * 0x68;
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + off;

    return *(s32 *)(*(u8 **)(obj + 0x14) + index * 0x10 + 4);
}

/* NEARMISS-STUB SpriteMenuGetSpriteObjectByHash */
#if 0 /* NEARMISS 52.78% cat=bitops sub=- | bitops tag per decomper; layer search + parts walk index math (52.78) | attempts=1 */
s32 SpriteMenuGetSpriteObjectByHash(u8 *spriteMenu, s32 layerHash, s32 partHash)
{
    s32 i;
    s32 count;
    SmLayer *base;
    SmLayer *layer;
    u8 *p;
    u8 *parts;

    p = smClass(spriteMenu);
    count = *(s32 *)(p + 8);
    base = *(SmLayer **)(p + 4);
    layer = base;
    if (count > 0)
    {
        for (i = 0; i < count; i++)
        {
            layer = &base[i];
            if (*(s32 *)(*(u8 **)layer + 4) == layerHash)
            {
                break;
            }
        }
    }
    count = layer->numParts;
    parts = layer->parts;
    for (i = 0; i < count; i++)
    {
        if (*(s32 *)(*(u8 **)(parts + i * 0x10) + 4) == partHash)
        {
            return *(s32 *)(parts + i * 0x10 + 4);
        }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSpriteObjectByHash);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSpriteObjectValue);

void spriteSetValue(u8 *sprite, s32 value);

void SpriteMenuSetSpriteObjectValue(u8 *spriteMenu, s32 layer, s32 index, s32 value)
{
    s32 off = layer * 0x68;
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + off;

    spriteSetValue(*(u8 **)(*(u8 **)(obj + 0x14) + index * 0x10 + 4), value);
}

/* NEARMISS-STUB SpriteMenuSetSpriteObjectValueByHash */
#if 0 /* NEARMISS 64.53% cat=branch-layout sub=- | layer-search peel plus parts[0] special case before loop; sprite select branch order (64.53) | attempts=1 */
void SpriteMenuSetSpriteObjectValueByHash(u8 *spriteMenu, s32 layerHash, s32 partHash, s32 value)
{
    s32 i;
    s32 count;
    SmLayer *layer;
    u8 *parts;
    u8 *entry;
    u8 *sprite;
    u8 *p;

    p = smClass(spriteMenu);
    count = *(s32 *)(p + 8);
    layer = NULL;
    if (count > 0)
    {
        layer = *(SmLayer **)(p + 4);
        if (*(s32 *)(*(u8 **)layer + 4) != layerHash)
        {
            for (i = 1; i < count; i++)
            {
                layer++;
                if (*(s32 *)(*(u8 **)layer + 4) == layerHash)
                {
                    break;
                }
            }
        }
    }
    count = layer->numParts;
    sprite = NULL;
    if (count > 0)
    {
        parts = layer->parts;
        if (*(s32 *)(*(u8 **)parts + 4) == partHash)
        {
            sprite = *(u8 **)(parts + 4);
        }
        else
        {
            for (i = 1; i < count; i++)
            {
                entry = parts + i * 0x10;
                if (*(s32 *)(*(u8 **)entry + 4) == partHash)
                {
                    sprite = *(u8 **)(entry + 4);
                    break;
                }
            }
        }
    }
    spriteSetValue(sprite, value);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSpriteObjectValueByHash);

/* NEARMISS-STUB SpriteMenuSetLayerPriority */
#if 0 /* NEARMISS 84.6% cat=sched sub=- | addu(+layer*13) hoisted before lw 4(p) (expected lw right after movn, addu after lw); base-local 83.1, inline 83.1, obj-local 84.6; scheduling idea needed | attempts=2 */
void SpriteMenuSetLayerPriority(u8 *spriteMenu, s32 layer, s32 priority)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    s32 off = layer * 0x68;

    *(s32 *)(*(u8 **)(p + 4) + off + 0x38) = priority;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetLayerPriority);

/* NEARMISS-STUB SpriteMenuSetLayerPriorityAllLayer */
#if 0 /* NEARMISS 89.0% cat=regalloc sub=- | gcc allocs a3/a5 vs expected a2/a5 in movz/movn loop; p hoisted, smClass re-read in body (89.0) | attempts=2 */
void SpriteMenuSetLayerPriorityAllLayer(u8 *spriteMenu, s32 priority)
{
    u8 *p = smClass(spriteMenu);
    s32 i;

    for (i = 0; i < *(s32 *)(p + 8); i++)
    {
        smLayer(smClass(spriteMenu), i)->priority = priority;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetLayerPriorityAllLayer);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSpriteMenuClassParam);

s32 SpriteMenuGetSpriteMenuClassParam(u8 *spriteMenu)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    return *(s32 *)(p + 0x20);
}

/* NEARMISS-STUB SpriteMenuGetLayerByHash */
#if 0 /* NEARMISS 47.0% cat=branch-layout sub=- | loop shape differs from original (while/latch layout, 47%) | attempts=1 */
void *SpriteMenuGetLayerByHash(u8 *spriteMenu, s32 hash)
{
    s32 i;
    s32 count;
    u8 *layer;
    u8 *p;

    p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    count = *(s32 *)(p + 8);
    if (count <= 0)
    {
        return NULL;
    }
    layer = *(u8 **)(p + 4);
    i = 0;
    while (*(s32 *)(*(u8 **)layer + 4) != hash)
    {
        i++;
        if (i >= count)
        {
            break;
        }
        layer += 0x68;
    }
    return layer;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetLayerByHash);

/* NEARMISS-STUB SpriteMenuGetLayerNoByHash */
#if 0 /* NEARMISS 38.0% cat=branch-layout sub=- | loop shape differs from original (38%) | attempts=1 */
s32 SpriteMenuGetLayerNoByHash(u8 *spriteMenu, s32 hash)
{
    s32 i;
    s32 count;
    u8 *base;
    u8 *p;

    p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    count = *(s32 *)(p + 8);
    if (count > 0)
    {
        base = *(u8 **)(p + 4);
        if (*(s32 *)(*(u8 **)base + 4) == hash)
        {
            return 0;
        }
        for (i = 1; i < count; i++)
        {
            if (*(s32 *)(*(u8 **)(base + i * 0x68) + 4) == hash)
            {
                return i;
            }
        }
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetLayerNoByHash);

/* NEARMISS-STUB SpriteMenuGetSpriteMenuPartsByHash */
#if 0 /* NEARMISS 39.0% cat=branch-layout sub=- | loop shape differs from original (39%) | attempts=1 */
void *SpriteMenuGetSpriteMenuPartsByHash(u8 *spriteMenu, s32 hash)
{
    s32 i;
    s32 count;
    u8 *parts;

    count = *(s32 *)(spriteMenu + 0x18);
    parts = *(u8 **)(spriteMenu + 0x14);
    for (i = 0; i < count; i++)
    {
        if (*(s32 *)(*(u8 **)(parts + i * 0x10) + 4) == hash)
        {
            return parts + i * 0x10;
        }
    }
    return NULL;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSpriteMenuPartsByHash);

/* NEARMISS-STUB SpriteMenuGetPartsDefByHash */
#if 0 /* NEARMISS 42.39% cat=branch-layout sub=- | layer-search loop peeled at element 0 vs original loop shape; parts walk (42.39) | attempts=1 */
s32 SpriteMenuGetPartsDefByHash(u8 *spriteMenu, s32 layerHash, s32 partHash)
{
    s32 i;
    s32 count;
    SmLayer *layer;
    u8 *parts;
    u8 *entry;
    u8 *p;

    p = smClass(spriteMenu);
    count = *(s32 *)(p + 8);
    layer = NULL;
    if (count > 0)
    {
        layer = *(SmLayer **)(p + 4);
        if (*(s32 *)(*(u8 **)layer + 4) != layerHash)
        {
            for (i = 1; i < count; i++)
            {
                layer++;
                if (*(s32 *)(*(u8 **)layer + 4) == layerHash)
                {
                    break;
                }
            }
        }
    }
    count = layer->numParts;
    entry = NULL;
    if (count > 0)
    {
        parts = layer->parts;
        for (i = 0; i < count; i++)
        {
            if (*(s32 *)(*(u8 **)(parts + i * 0x10) + 4) == partHash)
            {
                entry = parts + i * 0x10;
                break;
            }
        }
    }
    return (entry != NULL) ? *(s32 *)entry : 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetPartsDefByHash);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetMenuIdByPartsId);
s32 SpriteMenuGetMenuIdByPartsId(u8 *spriteMenu, s32 layer, s32 partsId)
{
    SmLayer *obj = smLayer(smClass(spriteMenu), layer);
    s32 id;

    if (partsId > 0)
    {
        if (partsId < obj->numParts)
        {
            id = *(s32 *)(*(u8 **)(obj->parts + partsId * 0x10) + 0x14);
            if (id != -1)
            {
                return id;
            }
        }
    }
    return -1;
}

/* NEARMISS-STUB SpriteMenuGetMenuIdByHash */
#if 0 /* NEARMISS 82.0% cat=branch-layout sub=- | nested search loop shape: peeled element 0, count>0 guard | attempts=1 */
s32 SpriteMenuGetMenuIdByHash(u8 *spriteMenu, s32 layerHash, s32 hash)
{
    u8 *p;
    u8 *layer;
    u8 *entry;
    u8 *arr;
    s32 count;
    s32 menuId;
    s32 i;

    p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    menuId = -1;
    count = *(s32 *)(p + 8);
    layer = *(u8 **)(p + 4);
    for (i = 0; i < count; i++)
    {
        layer = *(u8 **)(p + 4) + i * 0x68;
        if (*(s32 *)(*(u8 **)layer + 4) == layerHash)
        {
            break;
        }
    }
    count = *(s32 *)(layer + 0x18);
    arr = *(u8 **)(layer + 0x14);
    for (i = 0; i < count; i++)
    {
        entry = *(u8 **)(arr + i * 0x10);
        if (*(s32 *)(entry + 4) == hash)
        {
            menuId = *(s32 *)(entry + 0x14);
            break;
        }
    }
    return menuId;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetMenuIdByHash);

/* NEARMISS-STUB SpriteMenuSetMenuDispFlag */
#if 0 /* NEARMISS 66.0% cat=branch-layout sub=- | loop pointer-walk +0x10 stride/i++ early; movz vs and/ori | attempts=1 */
void SpriteMenuSetMenuDispFlag(u8 *spriteMenu, s32 layer, s32 id, s32 flag)
{
    s32 i;
    u8 *p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;
    u8 *base = *(u8 **)(obj + 0x14);
    u8 *parts;
    s32 flags;

    for (i = 0; i < *(s32 *)(obj + 0x18); i++)
    {
        parts = *(u8 **)(base + i * 0x10);
        flags = *(s32 *)(parts + 0x10);
        if ((flags & 2) && *(s32 *)(parts + 0x14) == id)
        {
            if (flag)
            {
                flags &= ~0x800;
            }
            else
            {
                flags |= 0x800;
            }
            *(s32 *)(parts + 0x10) = flags;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetMenuDispFlag);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuIdBySpriteMenuClass);
s32 SpriteMenuGetSelectMenuIdBySpriteMenuClass(u8 *spriteMenu)
{
    s32 layer = *(s32 *)(spriteMenu + 0xC);

    if (layer != -1)
    {
        return smLayer(spriteMenu, layer)->menuId;
    }
    return -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuId);
s32 SpriteMenuGetSelectMenuId(u8 *spriteMenu)
{
    u8 *p = smClass(spriteMenu);
    s32 layer = *(s32 *)(p + 0xC);

    if (layer != -1)
    {
        return smLayer(p, layer)->menuId;
    }
    return -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectMenuId);
void SpriteMenuSetSelectMenuId(u8 *spriteMenu, s32 menuId)
{
    u8 *p = smClass(spriteMenu);
    s32 layer = *(s32 *)(p + 0xC);

    if (layer != -1)
    {
        smLayer(p, layer)->menuId = menuId;
    }
}

/* NEARMISS-STUB SpriteMenuSetDefaultSelectMenu */
#if 0 /* NEARMISS 84.0% cat=sched sub=- | addu placement vs original | attempts=1 */
void SpriteMenuSetDefaultSelectMenu(u8 *spriteMenu, s32 layer, s32 menu)
{
    s32 off = layer * 0x68;
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    *(s32 *)(*(u8 **)(p + 4) + off + 0x60) = menu;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDefaultSelectMenu);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectSubMenuId);
s32 SpriteMenuGetSelectSubMenuId(u8 *spriteMenu)
{
    u8 *p = smClass(spriteMenu);
    s32 layer = *(s32 *)(p + 0xC);

    return (layer == -1) ? -1 : smLayer(p, layer)->subMenuId;
}

/* NEARMISS-STUB SpriteMenuSetSelectSubMenuId */
#if 0 /* NEARMISS 22.73% cat=bitops sub=- | bitops tag per decomper; flag tests (&2, &0x100) and entry search shape (22.73) | attempts=1 */
void SpriteMenuSetSelectSubMenuId(u8 *spriteMenu, s32 subMenuId)
{
    u8 *p;
    SmLayer *obj;
    u8 *entry;
    s32 cur;
    s32 count;
    u8 *parts;
    s32 i;

    p = NULL;
    if (spriteMenu[8] == 0x21)
    {
        p = spriteMenu + 0x90;
    }
    cur = *(s32 *)(p + 0xC);
    if (cur == -1)
    {
        return;
    }
    obj = smLayer(p, cur);
    count = obj->numParts;
    parts = obj->parts;
    entry = NULL;
    for (i = 0; i < count; i++)
    {
        u8 *def = *(u8 **)(parts + i * 0x10);

        if ((*(s32 *)(def + 0x10) & 2) != 0 && *(s32 *)(def + 0x14) == obj->menuId)
        {
            entry = parts + i * 0x10;
            break;
        }
    }
    if (entry == NULL)
    {
        return;
    }
    if ((*(s32 *)(*(u8 **)entry + 0x10) & 0x100) != 0)
    {
        spriteSetValue(*(u8 **)(entry + 4), subMenuId);
        return;
    }
    obj->subMenuId = subMenuId;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectSubMenuId);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetCheckBoxByPartsId);
void SpriteMenuSetCheckBoxByPartsId(u8 *spriteMenu, s32 layer, s32 partsId, s32 flag)
{
    SmLayer *obj = smLayer(smClass(spriteMenu), layer);
    u8 *parts;
    s32 ok;

    if (partsId > 0 && partsId < obj->numParts)
    {
        ok = (u32)flag < 2;
        parts = *(u8 **)(obj->parts + partsId * 0x10);
        if (ok)
        {
            *(s32 *)(parts + 0xC) = flag;
        }
    }
}

/* NEARMISS-STUB SpriteMenuSetCheckBoxByHash */
#if 0 /* NEARMISS 74.25% cat=branch-layout sub=- | layer-search loop peeled at element 0; flag<2 test inside parts loop; branch layout differs (74.25) | attempts=1 */
s32 SpriteMenuSetCheckBoxByHash(u8 *spriteMenu, s32 layerHash, s32 partHash, s32 flag)
{
    s32 i;
    s32 count;
    s32 index;
    s32 ok;
    SmLayer *layer;
    u8 *parts;
    u8 *entry;
    u8 *p;

    p = smClass(spriteMenu);
    count = *(s32 *)(p + 8);
    layer = NULL;
    if (count > 0)
    {
        layer = *(SmLayer **)(p + 4);
        if (*(s32 *)(*(u8 **)layer + 4) != layerHash)
        {
            for (i = 1; i < count; i++)
            {
                layer++;
                if (*(s32 *)(*(u8 **)layer + 4) == layerHash)
                {
                    break;
                }
            }
        }
    }
    index = -1;
    count = layer->numParts;
    if (count > 0)
    {
        parts = layer->parts;
        for (i = 0; i < count; i++)
        {
            entry = parts + i * 0x10;
            if (*(s32 *)(*(u8 **)entry + 4) == partHash)
            {
                index = i;
                ok = (u32)flag < 2;
                if (ok)
                {
                    *(s32 *)(*(u8 **)entry + 0xC) = flag;
                }
                break;
            }
        }
    }
    return index;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetCheckBoxByHash);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuMode);
s32 SpriteMenuGetSelectMenuMode(u8 *spriteMenu)
{
    u8 *p = smClass(spriteMenu);
    s32 layer = *(s32 *)(p + 0xC);

    return (layer == -1) ? -1 : smLayer(p, layer)->mode;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectMenuMode);
void SpriteMenuSetSelectMenuMode(u8 *spriteMenu, s32 mode)
{
    u8 *p = smClass(spriteMenu);
    s32 layer = *(s32 *)(p + 0xC);

    if (layer != -1)
    {
        smLayer(p, layer)->mode = mode;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectLayer);

s32 SpriteMenuGetSelectLayer(u8 *spriteMenu)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    return *(s32 *)(p + 0xC);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetPadEvent);

s32 SpriteMenuGetPadEvent(u8 *spriteMenu)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    return *(s32 *)(p + 0x10);
}

/* NEARMISS-STUB SpriteMenuIsFadeCheckAllLayer */
#if 0 /* NEARMISS 66.0% cat=branch-layout sub=- | gcc if-converts type==0x21 select to movz; expected bne; s1/s2 swap | attempts=1 */
s32 SpriteMenuIsFadeCheckLayer(u8 *spriteMenu, s32 layer);

s32 SpriteMenuIsFadeCheckAllLayer(u8 *spriteMenu)
{
    s32 i;
    u8 *p;

    if (spriteMenu[8] == 0x21)
    {
        p = spriteMenu + 0x90;
    }
    else
    {
        p = NULL;
    }
    for (i = 0; i < *(s32 *)(p + 8); i++)
    {
        if (SpriteMenuIsFadeCheckLayer(spriteMenu, i))
        {
            return 1;
        }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckAllLayer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckSelectLayer);

/* NEARMISS-STUB SpriteMenuIsFadeCheckLayer */
#if 0 /* NEARMISS 95.0% cat=rodata-const sub=- | switch jump table references %hi(D_40133C50) sub-table of blob D_40133C30; bc1t vs bc1f | attempts=1 */
s32 SpriteMenuIsFadeCheckLayer(u8 *spriteMenu, s32 layer)
{
    u8 *p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;
    f32 *fade = NULL;

    switch (*(s32 *)(*(u8 **)obj + 0xC))
    {
    case 0:
        fade = (f32 *)(obj + 0x34);
        break;
    case 1:
    case 2:
        fade = (f32 *)(obj + 0x1C);
        break;
    case 3:
    case 4:
        fade = (f32 *)(obj + 0x20);
        break;
    }
    return *(f32 *)(obj + 8) == *fade;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckLayer);

/* NEARMISS-STUB SpriteMenuGetFadeByLayer */
#if 0 /* NEARMISS 96.7% cat=rodata-const sub=- | jump-table reloc: expected lui/lw %hi/%lo(D_40133C70) named blob table, gcc emits local .rodata table (blocker %hi(sym+off)); also beqz vs beql bounds check and | attempts=1 */
f32 SpriteMenuGetFadeByLayer(u8 *spriteMenu, s32 layer)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;
    s32 type = *(s32 *)(*(u8 **)obj + 0xC);
    f32 *fade = NULL;

    switch (type)
    {
    case 0:
        fade = (f32 *)(obj + 0x34);
        break;
    case 1:
    case 2:
        fade = (f32 *)(obj + 0x1C);
        break;
    case 3:
    case 4:
        fade = (f32 *)(obj + 0x20);
        break;
    }
    return *fade;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetFadeByLayer);

/* NEARMISS-STUB SpriteMenuSetPadEventCallback */
#if 0 /* NEARMISS 84.0% cat=sched sub=- | addu placement vs original | attempts=1 */
void SpriteMenuSetPadEventCallback(u8 *spriteMenu, s32 layer, s32 callback)
{
    s32 off = layer * 0x68;
    u8 *p = NULL;

    if (spriteMenu[8] == 0x21)
    {
        p = spriteMenu + 0x90;
    }
    *(s32 *)(*(u8 **)(p + 4) + off + 0x48) = callback;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetPadEventCallback);

/* NEARMISS-STUB SpriteSubMenuSetPadEventCallback */
#if 0 /* NEARMISS 84.0% cat=sched sub=- | addu placement vs original | attempts=1 */
void SpriteSubMenuSetPadEventCallback(u8 *spriteMenu, s32 layer, s32 callback)
{
    s32 off = (layer * 13) << 3;
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;

    *(s32 *)(*(u8 **)(p + 4) + off + 0x4C) = callback;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteSubMenuSetPadEventCallback);
