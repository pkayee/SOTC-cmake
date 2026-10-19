#include "common.h"

extern void flushScriptObj(unsigned char *);

s32 func_400A5468();
s32 GetScriptObjWorkSize();
void *_isysCreateObj(void *, s32, s32, s32, void (*)(void), s32);
void isysSetObjImmediateDeleteFunc();
void initScriptObj();
void func_400A4CE0();
void func_400A6B98(void);

void InitTwoWayLink();
void *iosMallocAlign();
void func_400A75E8(void);
extern void *memcpy(void *, const void *, unsigned int);

extern s32 DldSysUndefSymbol;
extern s32 sheetFsLanguageCode;
void *spriteCreateObject();
void spriteSetValue(void *, s32);
void spriteSetPosition(void *, float, float);
void spriteSetTextureCoordinateUV(void *, float, float, float, float);
void spriteSetColor(void *, s32, s32, s32, s32);
void spriteSetScale(void *, float, float);
void spriteSetRotation(void *, float);
void spriteSetPriority(void *, s32);
void spriteSetBlendMode(void *, s32, u32, u32);
void spriteSetIdentifier(void *, s32);
/* dld link word: bits 0..17 = byte distance back to a slot holding the target (or DldSysUndefSymbol), wanted value = field of that target */
static inline u8 *dldRef(u32 *lp, s32 fld) /* inline helper */
{
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

void spriteDrawSprite(void *, s32, float, float, float, float, float, float, s32, s32);

void DeleteScriptSpriteMenuObj(unsigned char *p)
{
    unsigned char *m = p[8] != 0x21 ? 0 : p + 0x20;
    void (*f)(unsigned char *);
    flushScriptObj(p);
    f = *(void (**)(unsigned char *))(m + 0xA0);
    if (f != 0)
        f(p);
}

/* c0128 CreateScriptSpriteMenuObj: isys obj tag 0x21 size 0xD0; script block at +0x20 gets desc script area desc+0x2C; delete cb desc[0x28] stored at script block +0xA0 */
u8 *CreateScriptSpriteMenuObj(void *grp, s32 extra, u8 *desc)
{
    u8 *s = desc + 0x2C;
    s32 a = func_400A5468(desc);
    s32 b = GetScriptObjWorkSize(s);
    u8 *o = _isysCreateObj(grp, 0x21, 0xD0, extra + a + b, (void (*)(void))DeleteScriptSpriteMenuObj, 0x10);
    u8 *c;

    if (o != 0) {
        isysSetObjImmediateDeleteFunc(o, func_400A6B98);
        initScriptObj(o, s, *(s32 *)o);
        func_400A4CE0(o, desc);
        c = o[8] != 0x21 ? 0 : o + 0x20;
        *(s32 *)(c + 0xA0) = *(s32 *)(desc + 0x28);
    }
    return o;
}

extern u8 padManagerData[];
extern int D_4012B2A8;

s32 spriteMenuCheckSelectPushPad(void)
{
    s8 *sel = *(s8 **)&D_4012B2A8;
    s32 pad = *(s32 *)(padManagerData + 0x8);
    s32 bit = 1;

    return (pad & (bit << sel[0])) ? 1 : ((pad & (bit << sel[1])) ? -1 : 0);
}

/* NEARMISS-STUB spriteMenuObjPadChangeHorse */
#if 0 /* NEARMISS 67.0% cat=bitops sub=- | target keeps sllv+and mask for 1<<sel; ours folds to srav+andi; return-2 tail differs | attempts=1 */
extern void mcGetCompleteTimeAttack(int *arg0, int *arg1);
extern u8 padManagerData[];
extern int D_4012B2A8;

s32 spriteMenuObjPadChangeHorse(void)
{
    s32 a;
    s32 b;

    mcGetCompleteTimeAttack(&a, &b);
    if (b == 0)
    {
        goto P;
    }
    if (a == 0)
    {
        goto Q;
    }
    if ((*(s32 *)padManagerData & (1 << *(s8 *)(*(s8 **)&D_4012B2A8 + 0xB))) != 0)
    {
        return 1;
    }
Q:
    if (b != 0)
    {
        goto L;
    }
P:
    if (a == 0)
    {
        return 0;
    }
L:
    if ((*(s32 *)padManagerData & (1 << *(s8 *)(*(s8 **)&D_4012B2A8 + 0xC))) == 0)
    {
        return 0;
    }
    return 2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", spriteMenuObjPadChangeHorse);

/* NEARMISS-STUB func_400A6A90 */
#if 0 /* NEARMISS 70.5% cat=branch-layout sub=- | target bne with hoisted v0=4 delay slot, bnel to shared epilogue; ours beql with lw in delay, b to epilogue | attempts=1 */
extern void func_400A2A10(unsigned char *, s32);

void func_400A6A90(unsigned char *p)
{
    s32 v;

    if (*(s32 *)(p + 0x4) == 1)
    {
        func_400A2A10(p, *(s32 *)(*(unsigned char **)p + 0xC));
        v = 2;
    }
    else
    {
        if (*(s32 *)(p + 0x4) != 4)
        {
            return;
        }
        func_400A2A10(p, *(s32 *)(*(unsigned char **)p + 0xC));
        v = 5;
    }
    *(s32 *)(p + 0x4) = v;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6A90);

/* NEARMISS-STUB func_400A6AF8 */
#if 0 /* NEARMISS 86.76% cat=regalloc sub=- | p/off/i get s2/s1/s3 vs target p=s2 off=s1 i=s3; ours shares wrong regs, stack save order differs | attempts=1 */
extern void func_400A4860(float, unsigned char *);

void func_400A6AF8(unsigned char *p)
{
    unsigned char *c;
    s32 off;
    s32 i;

    c = p[8] != 0x21 ? 0 : p + 0x90;
    i = 0;
    off = 0;
    if (*(s32 *)(c + 8) > 0)
    {
        do
        {
            if (*(s32 *)(*(unsigned char **)(c + 4) + off + 4) != 0)
            {
                func_400A4860(1.0f, p);
            }
            off += 0x68;
            i++;
        } while (i < *(s32 *)(c + 8));
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6AF8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", FlushScriptSpriteMenuObj);
s32 FlushScriptSpriteMenuObj(void) {
    return 0;
}

void flushScriptObjImmediate();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A6B98);
void func_400A6B98(void)
{
    flushScriptObjImmediate();
}

extern int D_4012B2A8;
extern int MenuControlButtonContext_control_america;

void setDefaultMenuControlButton(void)
{
    D_4012B2A8 = MenuControlButtonContext_control_america;
}

/* c0128 func_400A6BC8(heap, obj, cls, ent): creates cls[1] sprites from 0x54-byte entries (obj is unused here); cls[0] = sprite ptr array, cls[2] = max value+1 */
void func_400A6BC8(void *heap, void *obj, s32 *cls, u32 *e)
{
    s32 i = 0;
    s32 bm;
    s32 mx;
    s32 id;
    u8 *sp;
    u32 *lp;

    if (cls[1] > 0) {
        for (;;) {
            lp = (u32 *)(dldRef(e, 0x10) + sheetFsLanguageCode * 4 - 4);
            id = *(s32 *)(dldRef(lp, 0x10) + 0xC);
            bm = 0;
            mx = e[2] + 1;
            if (cls[2] < mx)
                cls[2] = mx;
            sp = spriteCreateObject(heap, id);
            ((u32 *)cls[0])[i] = (u32)sp;
            e[0x14] = (u32)sp;
            spriteSetValue(sp, e[2]);
            spriteSetPosition(sp, ((float *)e)[3], ((float *)e)[4]);
            spriteSetTextureCoordinateUV(sp, ((float *)e)[7], ((float *)e)[8], ((float *)e)[9], ((float *)e)[10]);
            spriteSetColor(sp, (u32)((float *)e)[11] & 0xFF, (u32)((float *)e)[12] & 0xFF, (u32)((float *)e)[13] & 0xFF, (u32)((float *)e)[14] & 0xFF);
            spriteSetScale(sp, ((float *)e)[5], ((float *)e)[6]);
            spriteSetRotation(sp, ((float *)e)[15]);
            spriteSetPriority(sp, 1);
            switch (e[0x10]) {
            case 0: bm = 0; break;
            case 1: bm = 1; break;
            case 2: bm = 2; break;
            case 3: bm = 3; break;
            case 4: bm = 4; break;
            case 5: bm = 5; break;
            case 6: bm = 6; break;
            }
            i++;
            spriteSetBlendMode(sp, bm, e[0x11], e[0x12]);
            spriteSetIdentifier(sp, e[0x13]);
            e += 0x15;
            if (i >= cls[1])
                break;
        }
    }
}

/* NEARMISS-STUB InitSpriteObj */
#if 0 /* NEARMISS 60.71% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
/* c0128 InitSpriteObj(obj, desc): tag 0xE class at obj+0x90 (+0 sprite array, +4 count, +8 max id, +0x54 draw callback); desc[1] = dld link whose target+0x10 = entry table; returns 1 */
s32 InitSpriteObj(u8 *obj, u8 *desc)
{
    u8 *c = obj[8] != 0xE ? 0 : obj + 0x90;
    void *heap = *(void **)obj;
    u32 *lp;
    u8 *slot;
    u8 *ent;
    u32 off;

    *(s32 *)(c + 0x54) = (s32)func_400A7260;
    *(s32 *)c = (s32)iosMallocAlign(heap, *(s32 *)(desc + 8) << 2, 0x10);
    *(s32 *)(c + 8) = 0;
    *(s32 *)(c + 4) = *(s32 *)(desc + 8);
    *(float *)(c + 0xC) = *(float *)(desc + 0xC);
    *(s32 *)(c + 0x1C) = 0xFFFFFF;
    *(float *)(c + 0x10) = *(float *)(desc + 0x10);
    *(s32 *)(c + 0x14) = 0;
    *(s32 *)(c + 0x18) = 0;
    *(float *)(c + 0x20) = *(float *)(desc + 0x14);
    *(float *)(c + 0x24) = *(float *)(desc + 0x18);
    *(s32 *)(c + 0x2C) = *(s32 *)(desc + 0x20);
    *(s32 *)(c + 0x34) = 0;
    *(float *)(c + 0x30) = *(float *)(desc + 0x24);
    *(float *)(c + 0x3C) = *(float *)(desc + 0x28);
    *(float *)(c + 0x40) = *(float *)(c + 0x3C) + *(float *)(desc + 0x2C);
    *(float *)(c + 0x44) = *(float *)(c + 0x40) + *(float *)(desc + 0x30);
    *(float *)(c + 0x28) = *(float *)(desc + 0x1C);
    *(s32 *)(c + 0x4C) = 1;
    *(s32 *)(c + 0x48) = *(s32 *)(desc + 0x34);
    *(s32 *)(c + 0x50) = 0;
    slot = 0;
    ent = 0;
    lp = *(u32 **)(desc + 4);
    off = *lp & 0x3FFFF;
    if (off)
        slot = *(u8 **)((u8 *)lp - off);
    if (slot != 0 && slot != (u8 *)DldSysUndefSymbol)
        ent = *(u8 **)(slot + 0x10);
    func_400A6BC8(heap, obj, c, ent);
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", InitSpriteObj);

char *GetSpriteClass(unsigned char *p)
{
    if (p[0x8] != 0xE) {
        return 0;
    }
    return (char *)p + 0x90;
}

int FlushSpriteObj(char *obj)
{
    char *sprite = ((unsigned char *)obj)[8] == 0xE ? obj + 0x90 : 0;

    *(int *)(sprite + 0x4C) = 0;
    if (*(int *)(sprite + 0x50) == 0) {
        *(int *)(sprite + 0x50) = 1;
    }
    return 0;
}

void DeleteScriptSpriteObj(unsigned char *o)
{
    unsigned char *c = o[8] != 0xE ? 0 : o + 0x90;
    unsigned char *d = o[8] != 0xE ? 0 : o + 0x20;
    *(int *)(c + 0x4C) = 0;
    if (*(int *)(c + 0x50) == 0)
        *(int *)(c + 0x50) = 1;
    flushScriptObj(o);
    if (*(void (**)(unsigned char *))(d + 0xCC) != 0)
        (*(void (**)(unsigned char *))(d + 0xCC))(o);
}

char *GetScriptSpriteClass(unsigned char *p)
{
    if (p[0x8] != 0xE) {
        return 0;
    }
    return (char *)p + 0x20;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", GetSpriteObjWorkSize);
int GetSpriteObjWorkSize(unsigned char *p)
{
    return *(s32 *)(p + 0x8) * 0xA7 + 0x33;
}

extern int GetScriptObjWorkSize(int *p);

int GetScriptSpriteObjWorkSize(unsigned char *p)
{
    s32 n = *(s32 *)(p + 0x8) * 0xA7;
    n = n + 0x43;
    return n + GetScriptObjWorkSize((int *)(p + 0x3C));
}

/* NEARMISS-STUB CreateScriptSpriteObj */
#if 0 /* NEARMISS 99.64% cat=regalloc sub=- | REA READY drop-in scored 99.64 in-TU (apply_ready) | attempts=1 */
/* c0128 CreateScriptSpriteObj: isys obj tag 0xE size 0xF0; desc[2]*0xA7+0x43 + script area size (desc+0x3C); delete cb desc[0x38] -> script block +0xCC */
u8 *CreateScriptSpriteObj(void *grp, s32 extra, u8 *desc)
{
    u8 *s = desc + 0x3C;
    s32 n = *(s32 *)(desc + 0x8) * 0xA7;
    u8 *o;
    u8 *c;

    n = n + 0x43;
    o = _isysCreateObj(grp, 0xE, 0xF0, extra + (n + GetScriptObjWorkSize(s)), (void (*)(void))DeleteScriptSpriteObj, 0x10);
    if (o != 0) {
        isysSetObjImmediateDeleteFunc(o, func_400A7360);
        InitSpriteObj(o, desc);
        initScriptObj(o, s, *(s32 *)o);
        c = o[8] != 0xE ? 0 : o + 0x20;
        *(s32 *)(c + 0xCC) = *(s32 *)(desc + 0x38);
    }
    return o;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", CreateScriptSpriteObj);

void ExecScriptSpriteObj(void) {
}

/* c0128 func_400A7260(obj, key): sprite-obj (tag 0xE) draw callback; class at obj+0x90, draws sprites by layer 1..3 (sprite+0x5C) whose value (sprite+4) equals key, or all when key == -1 */
void func_400A7260(u8 *obj, s32 key)
{
    u8 *c = obj[8] != 0xE ? 0 : obj + 0x90;
    s32 layer;
    s32 i;
    u8 *spr;

    if (*(s32 *)(c + 0x4C) != 0) {
        for (layer = 1; layer < 4; layer++) {
            for (i = 0; i < *(s32 *)(c + 4); i++) {
                spr = *(u8 **)(*(u8 **)c + i * 4);
                if (*(s32 *)(spr + 0x5C) == layer) {
                    if (*(s32 *)(spr + 4) == key || key == -1) {
                        spriteDrawSprite(spr, *(s32 *)(c + 0x1C),
                                         *(float *)(c + 0xC) + *(float *)(c + 0x14), *(float *)(c + 0x10) + *(float *)(c + 0x18),
                                         *(float *)(c + 0x20), *(float *)(c + 0x24), *(float *)(c + 0x28), *(float *)(c + 0x30), *(s32 *)(c + 0x48), -1);
                    }
                }
            }
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0128_DeleteScriptSpriteMenuObj", func_400A7360);
void func_400A7360(void)
{
    flushScriptObjImmediate();
}

char *GetSubLinkClass(unsigned char *p)
{
    if (p[0x8] != 0x15) {
        return 0;
    }
    return (char *)p + 0x1C;
}

/* c0128 CreateSubLinkObj(grp, deleteFn, data, size): isys obj tag 0x15 size 0x30, link block at +0x1C (+0xC delete fn, +0x10 copy of data) */
u8 *CreateSubLinkObj(void *grp, s32 func, void *data, s32 size)
{
    u8 *o = _isysCreateObj(grp, 0x15, 0x30, size + 0x20, 0, 0x10);
    u8 *l;
    u8 *s;

    if (o != 0) {
        isysSetObjImmediateDeleteFunc(o, func_400A75E8);
        l = o[8] != 0x15 ? 0 : o + 0x1C;
        InitTwoWayLink(l, o);
        *(void **)(l + 0x10) = iosMallocAlign(*(void **)o, size, 0x10);
        s = o[8] != 0x15 ? 0 : o + 0x1C;
        *(s32 *)(s + 0xC) = func;
        if (data != 0)
            memcpy(*(void **)(s + 0x10), data, size);
    }
    return o;
}

extern void *memcpy(void *, const void *, unsigned int);

void SetSubLinkObjDeleteFuncInfo(unsigned char *p, int func, void *data, int size)
{
    unsigned char *s = p[8] != 0x15 ? 0 : p + 0x1C;
    *(int *)(s + 0xC) = func;
    if (data != 0)
        memcpy(*(void **)(s + 0x10), data, size);
}
