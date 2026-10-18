#include "common.h"

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlag);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagNoFade);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagByHash);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetDispFlagAll);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetLayer);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSpriteObjectValueByHash);

/* NEARMISS-STUB SpriteMenuSetLayerPriority */
#if 0 /* NEARMISS 84.6% cat=sched sub=- | compiler places the movn (p select) before the layer*104 final addu; expected places it between layer*12 and +layer; off-first, p-first, inline-offset variants  | attempts=1 */
void SpriteMenuSetLayerPriority(u8 *spriteMenu, s32 layer, s32 priority)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    s32 off = layer * 0x68;

    *(s32 *)(*(u8 **)(p + 4) + off + 0x38) = priority;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetLayerPriority);

/* NEARMISS-STUB SpriteMenuSetLayerPriorityAllLayer */
#if 0 /* NEARMISS 77.5% cat=regalloc sub=- | loop shape matches (movz/movn select, count reload, bnezl latch) but gcc allocates a3/a5 where expected uses a2/a5; base/type local variants 67-77 | attempts=1 */
void SpriteMenuSetLayerPriorityAllLayer(u8 *spriteMenu, s32 priority)
{
    s32 i;
    u8 *base = ((spriteMenu[8] ^ 0x21) == 0) ? spriteMenu + 0x90 : NULL;

    for (i = 0; i < *(s32 *)(base + 8); i++)
    {
        u8 *lay = ((spriteMenu[8] ^ 0x21) != 0) ? NULL : spriteMenu + 0x90;

        *(s32 *)(*(u8 **)(lay + 4) + i * 0x68 + 0x38) = priority;
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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetPartsDefByHash);

/* NEARMISS-STUB SpriteMenuGetMenuIdByPartsId */
#if 0 /* NEARMISS 99.0% cat=sched sub=- | index arithmetic order differs (lw/sll order, 2 insns) | attempts=1 */
s32 SpriteMenuGetMenuIdByPartsId(u8 *spriteMenu, s32 layer, s32 partsId)
{
    u8 *p;
    u8 *obj;
    u8 *parts;
    s32 id;

    p = (spriteMenu[8] == 0x21) ? spriteMenu + 0x90 : NULL;
    obj = *(u8 **)(p + 4) + layer * 0x68;
    if (partsId > 0)
    {
        if (partsId < *(s32 *)(obj + 0x18))
        {
            parts = *(u8 **)(obj + 0x14) + partsId * 0x10;
            id = *(s32 *)(*(u8 **)parts + 0x14);
            if (id != -1)
            {
                return id;
            }
        }
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetMenuIdByPartsId);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetMenuIdByHash);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetMenuDispFlag);

/* NEARMISS-STUB SpriteMenuGetSelectMenuIdBySpriteMenuClass */
#if 0 /* NEARMISS 97.0% cat=sched sub=- | addu/sll index arithmetic order (idx*12 expansion) | attempts=1 */
s32 SpriteMenuGetSelectMenuIdBySpriteMenuClass(u8 *spriteMenu)
{
    s32 layer = *(s32 *)(spriteMenu + 0xC);

    if (layer != -1)
    {
        return *(s32 *)(*(u8 **)(spriteMenu + 4) + layer * 0x68 + 0x60);
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuIdBySpriteMenuClass);

/* NEARMISS-STUB SpriteMenuGetSelectMenuId */
#if 0 /* NEARMISS 98.0% cat=sched sub=- | addu/sll index arithmetic order (idx*12 expansion) | attempts=1 */
s32 SpriteMenuGetSelectMenuId(u8 *spriteMenu)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    s32 layer = *(s32 *)(p + 0xC);

    if (layer != -1)
    {
        return *(s32 *)(*(u8 **)(p + 4) + layer * 0x68 + 0x60);
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuId);

/* NEARMISS-STUB SpriteMenuSetSelectMenuId */
#if 0 /* NEARMISS 98.0% cat=sched sub=- | addu order before sw 0x60 | attempts=1 */
void SpriteMenuSetSelectMenuId(u8 *spriteMenu, s32 menuId)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    s32 layer = *(s32 *)(p + 0xC);

    if (layer != -1)
    {
        *(s32 *)(*(u8 **)(p + 4) + layer * 0x68 + 0x60) = menuId;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectMenuId);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectSubMenuId);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectSubMenuId);

/* NEARMISS-STUB SpriteMenuSetCheckBoxByPartsId */
#if 0 /* NEARMISS 90.0% cat=branch-layout sub=- | beqz insert / addu placement | attempts=1 */
void SpriteMenuSetCheckBoxByPartsId(u8 *spriteMenu, s32 layer, s32 partsId, s32 flag)
{
    u8 *p = (((u8 *)spriteMenu)[8] == 0x21) ? (u8 *)spriteMenu + 0x90 : NULL;
    u8 *obj = *(u8 **)(p + 4) + layer * 0x68;
    u8 *parts;
    s32 ok;

    if (partsId > 0 && partsId < *(s32 *)(obj + 0x18))
    {
        ok = (u32)flag < 2;
        parts = *(u8 **)(obj + 0x14) + partsId * 0x10;
        if (ok)
        {
            *(s32 *)(*(u8 **)parts + 0xC) = flag;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetCheckBoxByPartsId);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetCheckBoxByHash);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuGetSelectMenuMode);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuSetSelectMenuMode);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckAllLayer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckSelectLayer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0127_func_400A5468", SpriteMenuIsFadeCheckLayer);

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
