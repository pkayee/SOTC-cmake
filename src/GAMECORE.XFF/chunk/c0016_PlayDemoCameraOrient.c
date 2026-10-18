#include "common.h"

/* NEARMISS-STUB PlayDemoCameraOrient */
#if 0 /* NEARMISS 90.03% cat=sched sub=store-order | store scheduling only: target stores 0x28(child) first then daddu a0 then lq/0x20/sq0x10 then jal isysInitGroup with 0x24 in delay slot; ours puts 0x28 in jal d | attempts=1 */
extern s32 rootPtn;
extern u8 D_40132DD0[];

void func_40026B10();
void *_gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, void *a7);
void *iosMallocAlign(void *, s32, s32);
void isysInitGroup(u8 *group);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);
void setScriptObjArgument(void *obj, void *arg);
void func_40027158(s32 a0, u8 *a1);

void *PlayDemoCameraOrient(s32 a0, s32 a1, u8 *a2, void *a3, s32 a4)
{
    void *child;
    u8 *obj;

    child = _gcCreateChildScriptObj(func_40026B10, 0, &rootPtn, 0x1800, 0x50, 1, D_40132DD0, a3);
    obj = iosMallocAlign(*(void **)child, 0x50, 0x10);
    *(void **)(obj + 0x28) = child;
    *(s32 *)(obj + 0x20) = a0;
    *(u128 *)(obj + 0x10) = *(u128 *)a2;
    *(s32 *)(obj + 0x24) = a1;
    isysInitGroup(obj);
    SetScriptObjDeleteCallBackFunc(child, func_40027158, obj);
    setScriptObjArgument(child, obj);
    *(s32 *)(obj + 0x34) = a4;
    *(s32 *)(obj + 0x40) = -1;
    *(s32 *)(obj + 0x2C) = -1;
    *(s32 *)(obj + 0x30) = 0;
    *(s32 *)(obj + 0x38) = 0;
    *(s32 *)(obj + 0x3C) = 0;
    return obj;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", PlayDemoCameraOrient);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", FinishDemoCameraOrient);

void *isysGroupForFirst(s32 group, s32 flag);
void *isysGroupForNext(void *link, s32 flag);
void isysGroupForExit(s32 obj, s32 flag);
void isysRequestDeleteObj(void *obj);

void FinishDemoCameraOrient(u8 *a0)
{
    void *link;
    s32 obj = 0;

    link = isysGroupForFirst((s32)a0, 0);
    while (link != NULL)
    {
        obj = *(s32 *)link;
        link = isysGroupForNext(link, 0);
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
    isysRequestDeleteObj(*(void **)(a0 + 0x28));
}

void SkipCutDemoCameraOrient(u8 *a0)
{
    *(s32 *)(a0 + 0x30) = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", CheckDemoCameraOrientFinished);

s32 CheckDemoCameraOrientFinished(u8 *a0)
{
    return *(s32 *)(a0 + 0x38);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", getDemoEnableFlag);

extern u8 D_40130C34[];

void *getDemoEnableFlag(void)
{
    return D_40130C34;
}

s32 end_camera_lws_animation();
void isysDeleteGroupAllObj();

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", func_40027158);

void func_40027158(s32 a0, u8 *a1)
{
    *(s32 *)(a1 + 0x34) = 0;
    if (*(s32 *)(a1 + 0x2C) >= 0)
    {
        s32 *p = (s32 *)(a1 + 0x2C);

        end_camera_lws_animation(*(s32 *)(a1 + 0x2C));
        *p = -1;
    }
    isysDeleteGroupAllObj(a1);
}

/* NEARMISS-STUB func_400271A8 */
#if 0 /* NEARMISS 42.77% cat=struct-layout sub=- | frame 0xB0 with 52-byte param copied to sp+0 via ldl/ldr pairs; ours sp 0x80 and different callee-saved save set; jtbl table0 entry0 not normalised (idx0 is tai | attempts=1 */

extern s32 D_40130C38;
extern s32 D_40130C40;
extern u8 gcGlobalVar[];

void iosDlPushLayer(s32 layer);
void iosDlPopLayer(void);
void iosSetRootDC(void);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
void texTransRequest(void *tex, s32 a1, s32 a2);
void gsRegBegin(void);
void gsRegEnd(void);
void gsReg(s32 reg, u64 val);
void scrRun(void);

typedef struct CamOrientLocal
{
    s32 tex;
    s32 *list;
    s32 state;
    s32 unk0C;
    s32 unk10;
    s32 layer;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    s32 unk2C;
    s32 unk30;
} CamOrientLocal;

void func_400271A8(u8 *a0)
{
    CamOrientLocal c;
    s32 cont;
    s32 w;
    s32 h;
    s32 sx;
    s32 sy;
    f32 gc180;
    f32 f;

    c = *(CamOrientLocal *)a0;
    cont = 1;
    if (D_40130C38 != 0)
    {
        do
        {
            gc180 = *(f32 *)(gcGlobalVar + 0x180);
            if (*c.list == 0)
            {
                c.f28 = c.f28 + gc180;
                switch (c.state)
                {
                case 0:
                    break;
                case 1:
                    f = c.f24 + gc180 / c.f1C;
                    c.f24 = f;
                    if (1.0f <= f)
                    {
                        c.f24 = 1.0f;
                        c.state = 2;
                    }
                    break;
                case 2:
                    if (c.f18 - c.f20 < c.f28 || D_40130C40 != 0)
                    {
                        c.state = 3;
                    }
                    break;
                case 3:
                    f = c.f24 - gc180 / c.f20;
                    c.f24 = f;
                    if (f <= 0.0f)
                    {
                        c.f24 = 0.0f;
                        c.state = 4;
                    }
                    break;
                case 4:
                    cont = 0;
                    break;
                }

                iosDlPushLayer(c.layer);
                w = getDrawScreenWidth();
                h = getDrawScreenHeight();
                sx = (w >> 1) << 4;
                sy = h >> 1;
                iosSetRootDC();
                texTransRequest((void *)c.tex, 0, 0);
                gsRegBegin();
                gsReg(0x4A, 0);
                gsReg(0x3B, 0x0000008000000080ULL);
                gsReg(0x47, 0x31001);
                gsReg(0x42, 0x44);
                gsReg(0x14, 0);
                gsReg(0x08, 5);
                gsReg(0x00, 0x156);
                gsReg(0x01, 0x3F80000000000000ULL | 0x80 | 0x808000 | ((u64)(s32)(c.f24 * 128.0f) << 24));
                gsReg(0x03, ((u64)((c.unk0C << 10) + 8) << 16) | 8);
                gsReg(0x04, ((u64)(s32)(0x8000 - sx)) | ((u64)(((sy - c.unk10 - 0x40) << 4) + 0x8000) << 16) | 0x00FFFFFF00000000ULL);
                gsReg(0x03, ((u64)((c.unk0C << 10) + 0x400 + 8) << 16) | (0x2000 + 8));
                gsReg(0x04, ((u64)(s32)(0xA000 - sx)) | ((u64)(((sy - c.unk10) << 4) + 0x8000) << 16) | 0x00FFFFFF00000000ULL);
                gsReg(0x47, 0x50000);
                gsRegEnd();
                iosDlPopLayer();
            }
            else
            {
                f = c.f24 - gc180 / c.f20;
                c.f24 = f;
                if (f <= 0.0f)
                {
                    c.f24 = 0.0f;
                }
                c.state = 1;
            }
            scrRun();
        } while (D_40130C38 != 0 && cont != 0);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", func_400271A8);

/* NEARMISS-STUB func_400275D8 */
#if 0 /* NEARMISS 77.15% cat=stack-frame sub=- | frame 0xA0 with sp locals (cnt@0 childArg@4 dest@8 mask@0xC flagp@0x10) and s0-s7+fp save set; ours frame 0x80 with s8 used as a general reg; dld deref chain an | attempts=1 */
extern s32 DldSysUndefSymbol;
extern s32 D_40130C38;
extern s32 D_40130C3C;
extern void *D_40130C44;
extern s32 sheetFsLanguageCode;
extern u8 gcGlobalVar[];
extern s32 rootPtn;
extern const char D_40132E08[];
void *iosMallocAlign(void *, s32, s32);
void *_gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6, void *a7);
void *gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);
void scrRun(void);
void func_400271A8(void);
void func_40027ED8(void);

/* dld cross-module link: *lp & 0x3FFFF = byte distance back from lp to a slot holding the resolved
   target (or DldSysUndefSymbol); the wanted value is a field of that target. */
static inline u8 *dldRef(u32 *lp, s32 fld)
{
    u8 *slot;
    u32 off = *(volatile u32 *)lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

void func_400275D8(u8 *a0)
{
    u32 *lp;
    u8 *p;
    s32 count;
    s32 cnt;
    s32 childArg;
    s32 *dest;
    f32 acc;

    lp = *(u32 **)a0;
    p = NULL;
    {
        u32 off = *lp & 0x3FFFF;
        u8 *slot = off ? *(u8 **)((u8 *)lp - off) : NULL;

        if (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
        {
            p = *(u8 **)(slot + 0x10) + ((*lp >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC);
        }
    }
    count = (s32)dldRef(lp, 0xC);
    cnt = 0;
    childArg = ((s32 *)a0)[1];
    dest = (s32 *)((s32 *)a0)[2];
    acc = 0.0f;
    if (D_40130C38 != 0)
    {
        do
        {
            u8 *best = NULL;
            s32 bestKey = -1;
            s32 flag = 1;
            u8 *node;

            if (D_40130C3C == 0)
            {
                node = D_40130C44;
                if (node != NULL)
                {
                    s32 key = *(s32 *)(node + 0xC);

                    for (;;)
                    {
                        if (key < bestKey)
                        {
                            node = *(u8 **)(node + 0x18);
                        }
                        else
                        {
                            best = node;
                            bestKey = key;
                            node = *(u8 **)(node + 0x18);
                        }
                        if (node == NULL)
                        {
                            break;
                        }
                        key = *(s32 *)(node + 0xC);
                    }
                }
                flag = (best != a0);
            }
            *(s32 *)(a0 + 0x14) = flag;
            if (flag == 0)
            {
                acc = acc + *(f32 *)(gcGlobalVar + 0x180);
            }
            if (count > 0 && *(f32 *)(p + 0x8) < acc)
            {
                u8 *ref = dldRef((u32 *)p, 0x10);

                if (ref != NULL)
                {
                    u32 *lp2 = (u32 *)(ref + sheetFsLanguageCode * 4 - 4);
                    u8 *obj;
                    void *child;
                    void *fn;
                    void *cb;
                    s32 uVar4;
                    u8 bVar1;
                    u16 uVar2;
                    f32 f20;
                    f32 f21;
                    f32 f22;

                    uVar4 = *(s32 *)(dldRef(lp2, 0x10) + 0xC);
                    bVar1 = p[5];
                    uVar2 = *(u16 *)(p + 6);
                    f21 = *(f32 *)(p + 0x10);
                    if (f21 < 0.0f)
                    {
                        f21 = 0.25f;
                    }
                    f20 = *(f32 *)(p + 0x14);
                    if (f20 < 0.0f)
                    {
                        f20 = 0.25f;
                    }
                    f22 = *(f32 *)(p + 0xC) - *(f32 *)(p + 0x8);
                    obj = iosMallocAlign(&rootPtn, 0x34, 0x10);
                    *(s32 *)(obj + 0x0) = uVar4;
                    *(s32 **)(obj + 0x4) = (s32 *)(a0 + 0x14);
                    *(s32 *)(obj + 0x8) = 1;
                    *(s32 *)(obj + 0xC) = bVar1;
                    *(s32 *)(obj + 0x10) = uVar2;
                    *(s32 *)(obj + 0x14) = *(s32 *)(a0 + 0x10);
                    *(f32 *)(obj + 0x18) = f22;
                    *(f32 *)(obj + 0x1C) = f21;
                    *(f32 *)(obj + 0x20) = f20;
                    *(s32 *)(obj + 0x24) = 0;
                    *(s32 *)(obj + 0x28) = 0;
                    *(s32 *)(obj + 0x2C) = 0;
                    *(s32 **)(obj + 0x30) = &cnt;
                    cb = func_400271A8;
                    fn = func_40027ED8;
                    cnt++;
                    if (childArg != 0)
                    {
                        child = _gcCreateChildScriptObj(cb, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E08, (void *)childArg);
                    }
                    else
                    {
                        child = gcCreateScriptObj(cb, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E08);
                    }
                    if (fn != NULL)
                    {
                        SetScriptObjDeleteCallBackFunc(child, fn, obj);
                    }
                }
                p += 0x18;
                count--;
            }
            if (cnt == 0 && count == 0)
            {
                break;
            }
            scrRun();
        } while (D_40130C38 != 0);
    }
    if (dest != NULL)
    {
        *dest = 1;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", func_400275D8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", SetCaptionPauseFlag);

extern s32 D_40130C3C;

void SetCaptionPauseFlag(s32 a0)
{
    D_40130C3C = a0;
}

/* NEARMISS-STUB DisplayCaptionTable */
#if 0 /* NEARMISS 91.8% cat=regalloc sub=- | regalloc: target has &rootPtn in s2, fn in s1, 0x1A hoisted into s1 in the malloc jal delay slot, child in s2; ours swaps s1/s2 and loads 0x1A after the call; p | attempts=1 */
extern s32 rootPtn;
extern const char D_40132E18[];
extern void *D_40130C44;
extern s32 D_40130C48;
void *gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void *iosMallocAlign(void *, s32, s32);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);
void func_400275D8(void);
void func_40027F20(void);

void *DisplayCaptionTable(s32 a0, s32 a1)
{
    u8 *obj;
    void *child;
    void *fn;

    obj = iosMallocAlign(&rootPtn, 0x1C, 0x10);
    fn = func_40027F20;
    *(s32 *)(obj + 0x10) = 0x1A;
    *(s32 *)(obj + 0x0) = a0;
    *(s32 *)(obj + 0xC) = a1;
    *(s32 *)(obj + 0x4) = 0;
    *(s32 *)(obj + 0x8) = 0;
    *(s32 *)(obj + 0x14) = 0;
    *(void **)(obj + 0x18) = D_40130C44;
    D_40130C48++;
    D_40130C44 = obj;
    child = gcCreateScriptObj(func_400275D8, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E18);
    if (fn != NULL)
    {
        SetScriptObjDeleteCallBackFunc(child, fn, obj);
    }
    return child;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", DisplayCaptionTable);

/* NEARMISS-STUB DisplayCaptionTableChild */
#if 0 /* NEARMISS 80.1% cat=branch-layout sub=- | target hoists the call-argument setup (a3=0x1000, t0=0, t1=10, t2=str, a2=&rootPtn, a7=a1) and the lui/addiu of D_40130C44/D_40130C48 above the beqz on a1; ours | attempts=1 */
extern s32 rootPtn;
extern void *D_40130C44;
extern s32 D_40130C48;
extern const char D_40132E30[];
void func_400275D8(void);
void func_40027F20(void);
void *gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void *_gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6, void *a7);
void *iosMallocAlign(void *, s32, s32);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);

void *DisplayCaptionTableChild(s32 a0, s32 a1, s32 a2)
{
    u8 *obj;
    void *child;
    void *fn;

    obj = iosMallocAlign(&rootPtn, 0x1C, 0x10);
    *(s32 *)(obj + 0x0) = a0;
    *(s32 *)(obj + 0x4) = a1;
    *(s32 *)(obj + 0xC) = a2;
    *(s32 *)(obj + 0x10) = 0x1A;
    *(s32 *)(obj + 0x8) = 0;
    *(s32 *)(obj + 0x14) = 0;
    *(void **)(obj + 0x18) = D_40130C44;
    D_40130C44 = obj;
    D_40130C48++;
    fn = func_40027F20;
    if (a1 != 0)
    {
        child = _gcCreateChildScriptObj(func_400275D8, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E30, (void *)a1);
    }
    else
    {
        child = gcCreateScriptObj(func_400275D8, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E30);
    }
    if (fn != NULL)
    {
        SetScriptObjDeleteCallBackFunc(child, fn, obj);
    }
    return child;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", DisplayCaptionTableChild);
/* NEARMISS-STUB DisplayCaptionTableBlock */
#if 0 /* NEARMISS 90.0% cat=sched sub=- | address materialization/store scheduling: target hoists lui/addiu of D_40130C48, func_40027F20 and D_40132E58 above the obj stores and the beqz on a1; ours mate | attempts=1 */
extern s32 rootPtn;
extern void *D_40130C44;
extern s32 D_40130C48;
extern const char D_40132E58[];
void func_400275D8(void);
void func_40027F20(void);
void *gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void *_gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6, void *a7);
void *iosMallocAlign(void *, s32, s32);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);

void *DisplayCaptionTableBlock(s32 a0, s32 a1, s32 a2, s32 *a3)
{
    u8 *obj;
    void *child;
    void *fn;
    void *cb;
    const char *name;

    obj = iosMallocAlign(&rootPtn, 0x1C, 0x10);
    cb = func_400275D8;
    name = D_40132E58;
    *(s32 *)(obj + 0x0) = a0;
    *(s32 *)(obj + 0x4) = a1;
    *(s32 **)(obj + 0x8) = a3;
    if (a3 != NULL)
    {
        *a3 = 0;
    }
    *(s32 *)(obj + 0xC) = a2;
    *(s32 *)(obj + 0x10) = 0x1A;
    *(s32 *)(obj + 0x14) = 0;
    *(void **)(obj + 0x18) = D_40130C44;
    D_40130C44 = obj;
    D_40130C48++;
    fn = func_40027F20;
    if (a1 != 0)
    {
        child = _gcCreateChildScriptObj(cb, (s32)obj, &rootPtn, 0x1000, 0, 10, name, (void *)a1);
    }
    else
    {
        child = gcCreateScriptObj(cb, (s32)obj, &rootPtn, 0x1000, 0, 10, name);
    }
    if (fn != NULL)
    {
        SetScriptObjDeleteCallBackFunc(child, fn, obj);
    }
    return child;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0016_PlayDemoCameraOrient", DisplayCaptionTableBlock);

extern s32 rootPtn;
extern void *D_40130C44;
extern s32 D_40130C48;
extern const char D_40132E58[];
void func_400275D8(void);
void func_40027F20(void);
void *gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void *iosMallocAlign(void *, s32, s32);
void SetScriptObjDeleteCallBackFunc(void *obj, void *fn, void *arg);

void *DisplayCaptionTableBlockWithDlLayer(s32 a0, s32 a1, u8 *a2, void *a3, s32 *a4)
{
    u8 *obj;
    void *child;
    void *fn;

    obj = iosMallocAlign(&rootPtn, 0x1C, 0x10);
    *(s32 *)(obj + 0x0) = a0;
    *(s32 *)(obj + 0x4) = a1;
    *(s32 **)(obj + 0x8) = a4;
    if (a4 != NULL)
    {
        *a4 = 0;
    }
    *(u8 **)(obj + 0xC) = a2;
    *(void **)(obj + 0x10) = a3;
    *(s32 *)(obj + 0x14) = 0;
    *(void **)(obj + 0x18) = D_40130C44;
    D_40130C44 = obj;
    D_40130C48++;
    fn = func_40027F20;
    child = gcCreateScriptObj(func_400275D8, (s32)obj, &rootPtn, 0x1000, 0, 10, D_40132E58);
    if (fn != NULL)
    {
        SetScriptObjDeleteCallBackFunc(child, fn, obj);
    }
    return child;
}
