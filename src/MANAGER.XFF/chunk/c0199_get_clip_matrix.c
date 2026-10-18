#include "common.h"

void iosFree(void *);
void *iosMallocAlign(s32, s32, s32);
void *memset(void *, s32, u32);
u8 *GetCharacterClass();
u8 *GetScriptLayoutClass();
u8 *GetScriptAnimationClass();
s32 func_400F6698();
s32 func_400F6A60();
s32 func_400F7388();

s32 func_400F6DD8(u8 *, u8 *);
s32 func_400F7240(u8 *, u8 *);
s32 func_400F7720(u8 *, u8 *);

u8 *get_clip_matrix(u8 *m) {
    return m + 0x10;
}

u8 *get_clip_matrix128(u8 *m) {
    return m + 0x50;
}

u8 *get_clip_matrix256(u8 *m) {
    return m + 0x90;
}

u8 *get_screen_matrix(u8 *m) {
    return m + 0xD0;
}

u8 *get_screen_matrix128(u8 *m) {
    return m + 0x110;
}

u8 *get_screen_matrix256(u8 *m) {
    return m + 0x150;
}

u8 *get_scissor_clip_matrix(u8 *m, s32 i) {
    return m + (i << 6) + 0x1A0;
}

u8 *get_WV_matrix(u8 *m) {
    return m;
}

u8 *get_VC_matrix(u8 *m) {
    return m + 0x40;
}

u8 *get_CS_matrix(u8 *m) {
    return m + 0x80;
}

u8 *get_WVC_matrix(u8 *m) {
    return m + 0xC0;
}

u8 *get_VCS_matrix(u8 *m) {
    return m + 0x100;
}

u8 *get_WVCS_matrix(u8 *m) {
    return m + 0x1C0;
}

u8 *get_scissor_VC_matrix(u8 *m) {
    return m + 0x200;
}

u8 *get_scissor_WVC_matrix(u8 *m) {
    return m + 0x240;
}

void *create_transform_matrix_set(s32 ptn) {
    void *p = iosMallocAlign(ptn, 0x280, 0x10);

    memset(p, 0, 0x280);
    return p;
}

void check_free_transform_matrix_set(s32 *s) {
    if (*s != 0) {
        iosFree((void *)*s);
        *s = 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", update_transform_matrix_set);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F6698);

/* NEARMISS-STUB func_400F6900 */
#if 0 /* NEARMISS 84.6% cat=branch-layout sub=class-pick-then-early-returns | class-type switch (9,0xB,0xD,0x16 -> +0x200/+0x230/+0x290) matches exactly; remaining: early-return  /  use likely branches with ret=0 in delay slot, flag byte  | attempts=2 */
s32 func_400F6900(u8 *obj, u8 *set) {
    u8 *cls = NULL;
    u8 *r;
    u8 *cc;
    s32 ok;
    s32 (*fn)(u8 *);

    switch (obj[8]) {
    case 9:
        cls = GetCharacterClass() + 0x200;
        break;
    case 0xB:
        cls = GetScriptLayoutClass() + 0x230;
        break;
    case 0xD:
        cls = GetScriptAnimationClass() + 0x230;
        break;
    case 0x16:
        cls = obj + 0x290;
        break;
    default:
        cls = NULL;
        break;
    }
    if (obj == *(u8 **)set) {
        return 0;
    }
    if (cls == NULL) {
        return 0;
    }
    r = NULL;
    cc = GetCharacterClass(obj);
    if (cc != NULL) {
        r = cc;
        if (*(char *)(cc + 0x522) == 0) {
            r = NULL;
        }
    }
    if (r == NULL) {
        u8 *sl = GetScriptLayoutClass(obj);

        if (sl != NULL && *(s32 *)(sl + 0x2D0) != 0) {
            r = sl + 0x70;
        }
        if (r == NULL) {
            return 0;
        }
    }
    if (func_400F6698(set, cls, r, obj) == 0) {
        return 0;
    }
    fn = *(s32 (**)(u8 *))(*(u8 **)(set + 0x14) + 4);
    ok = 1;
    if (fn != NULL) {
        ok = 0;
        if (fn(obj) != 0) {
            ok = 1;
        }
    }
    if (ok != 0) {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F6900);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F6A60);

/* NEARMISS-STUB func_400F6DD8 */
#if 0 /* NEARMISS 71.09% cat=branch-layout sub=- | no cause recorded | attempts=1 */
s32 func_400F6A60();

s32 func_400F6DD8(u8 *p, s32 *ctx)
{
    s32 base;
    s32 cls;
    s32 c;
    s32 lay;
    s32 ret;
    s32 obj;
    s32 fn;
    u8 type;

    type = p[8];
    if (type != 0xB)
    {
        if (type < 0xC)
        {
            cls = 0;
            if (type == 9)
            {
                cls = GetCharacterClass(p) + 0x200;
            }
        }
        else if (type == 0xD)
        {
            cls = GetScriptAnimationClass(p) + 0x230;
        }
        else
        {
            cls = 0;
            if (type == 0x16)
            {
                cls = (s32)p + 0x290;
            }
        }
    }
    else
    {
        cls = GetScriptLayoutClass(p) + 0x230;
    }
    if ((s32)p == ctx[0])
    {
        return 0;
    }
    if (cls == 0)
    {
        return 0;
    }
    base = 0;
    c = GetCharacterClass(p);
    if (c != 0)
    {
        base = c;
        if (*(s8 *)(c + 0x522) == 0)
        {
            base = 0;
        }
    }
    if (base == 0)
    {
        lay = GetScriptLayoutClass(p, cls);
        if (lay != 0 && *(s32 *)(lay + 0x2D0) != 0)
        {
            base = lay + 0x70;
        }
        if (base == 0)
        {
            return 0;
        }
    }
    ret = func_400F6A60(ctx, cls, base, (s32)p);
    if (ret == 0)
    {
        return 0;
    }
    obj = ctx[10];
    fn = *(s32 *)(obj + 4);
    if (fn != 0)
    {
        if (((s32 (*)(u8 *))fn)(p) == 0)
        {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F6DD8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F6F38);

/* NEARMISS-STUB func_400F7240 */
#if 0 /* NEARMISS 70.56% cat=branch-layout sub=- | no cause recorded | attempts=1 */
s32 GetCharacterClass();
s32 GetScriptLayoutClass();
s32 GetScriptAnimationClass();
s32 func_400F6F38();

s32 func_400F7240(u8 *p, s32 *ctx)
{
    s32 base;
    s32 cls;
    s32 ret;
    s32 obj;
    s32 fn;
    u8 type;

    type = p[8];
    if (type != 0xB)
    {
        if (type < 0xC)
        {
            cls = 0;
            if (type == 9)
            {
                cls = GetCharacterClass(p) + 0x200;
            }
        }
        else if (type == 0xD)
        {
            cls = GetScriptAnimationClass(p) + 0x230;
        }
        else
        {
            cls = 0;
            if (type == 0x16)
            {
                cls = (s32)p + 0x290;
            }
        }
    }
    else
    {
        cls = GetScriptLayoutClass(p) + 0x230;
    }
    if ((s32)p == ctx[0])
    {
        return 0;
    }
    if (cls == 0)
    {
        return 0;
    }
    base = GetCharacterClass(p);
    if (base == 0)
    {
        s32 lay = GetScriptLayoutClass(p, cls);
        if (lay != 0 && *(s32 *)(lay + 0x2D0) != 0)
        {
            base = lay + 0x70;
        }
        if (base == 0)
        {
            return 0;
        }
    }
    ret = func_400F6F38(ctx, cls, base, (s32)p);
    if (ret == 0)
    {
        return 0;
    }
    obj = ctx[13];
    fn = *(s32 *)(obj + 4);
    if (fn != 0)
    {
        if (((s32 (*)(u8 *))fn)(p) == 0)
        {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F7240);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F7388);

/* NEARMISS-STUB func_400F7720 */
#if 0 /* NEARMISS 71.09% cat=branch-layout sub=- | no cause recorded | attempts=1 */
s32 func_400F7388();

s32 func_400F7720(u8 *p, s32 *ctx)
{
    s32 base;
    s32 cls;
    s32 c;
    s32 lay;
    s32 ret;
    s32 obj;
    s32 fn;
    u8 type;

    type = p[8];
    if (type != 0xB)
    {
        if (type < 0xC)
        {
            cls = 0;
            if (type == 9)
            {
                cls = GetCharacterClass(p) + 0x200;
            }
        }
        else if (type == 0xD)
        {
            cls = GetScriptAnimationClass(p) + 0x230;
        }
        else
        {
            cls = 0;
            if (type == 0x16)
            {
                cls = (s32)p + 0x290;
            }
        }
    }
    else
    {
        cls = GetScriptLayoutClass(p) + 0x230;
    }
    if ((s32)p == ctx[0])
    {
        return 0;
    }
    if (cls == 0)
    {
        return 0;
    }
    base = 0;
    c = GetCharacterClass(p);
    if (c != 0)
    {
        base = c;
        if (*(s8 *)(c + 0x522) == 0)
        {
            base = 0;
        }
    }
    if (base == 0)
    {
        lay = GetScriptLayoutClass(p, cls);
        if (lay != 0 && *(s32 *)(lay + 0x2D0) != 0)
        {
            base = lay + 0x70;
        }
        if (base == 0)
        {
            return 0;
        }
    }
    ret = func_400F7388(ctx, cls, base, (s32)p);
    if (ret == 0)
    {
        return 0;
    }
    obj = ctx[11];
    fn = *(s32 *)(obj + 4);
    if (fn != 0)
    {
        if (((s32 (*)(u8 *))fn)(p) == 0)
        {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F7720);

/* NEARMISS-STUB func_400F7880 */
#if 0 /* NEARMISS 64.8% cat=branch-layout sub=- | no cause recorded | attempts=1 */
extern s32 D_4012E380;
s32 GetCharacterClass();
s32 GetScriptLayoutClass();
s32 GetScriptAnimationClass();
void CopyGeometryPointer();

void func_400F7880(u8 *p, u8 *q)
{
    s32 *piVar3;
    s32 iVar2;
    f32 fVar4;
    f32 fVar5;
    u8 bVar1;

    bVar1 = p[8];
    piVar3 = NULL;
    if (bVar1 != 0xB)
    {
        if (bVar1 < 0xC)
        {
            if (bVar1 == 9)
            {
                iVar2 = GetCharacterClass(p);
                piVar3 = (s32 *)(iVar2 + 0x200);
            }
        }
        else if (bVar1 == 0xD)
        {
            iVar2 = GetScriptAnimationClass(p);
            piVar3 = (s32 *)(iVar2 + 0x230);
        }
        else if (bVar1 == 0x16)
        {
            piVar3 = (s32 *)((s32)p + 0x290);
        }
    }
    else
    {
        iVar2 = GetScriptLayoutClass(p);
        piVar3 = (s32 *)(iVar2 + 0x230);
    }
    iVar2 = *piVar3;
    if (iVar2 < 2 && iVar2 > -1 &&
        (piVar3[0x15] < 0 || piVar3[0x15] < *(s16 *)(*(s32 *)(q + 4) + 8)))
    {
        CopyGeometryPointer(piVar3 + 4, q + 0x10);
        piVar3[0] = 1;
        fVar5 = ((f32 *)piVar3)[0x1A];
        piVar3[0x14] = *(s32 *)(q + 4);
        fVar4 = *(f32 *)(D_4012E380 * 8 + *(s32 *)(q + 4) + 0x14);
        ((f32 *)piVar3)[0x1A] = fVar4;
        ((f32 *)piVar3)[0x19] = ((f32 *)piVar3)[0x19] + (fVar4 - fVar5);
        piVar3[0x15] = *(s16 *)(*(s32 *)(q + 4) + 8);
        ((f32 *)piVar3)[0x16] = *(f32 *)(*(s32 *)(q + 4) + 0xC) * 0.033333335f;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0199_get_clip_matrix", func_400F7880);
