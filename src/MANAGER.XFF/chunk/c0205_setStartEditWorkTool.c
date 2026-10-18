#include "common.h"

void Sg2ExPcmOutputSetVol(s32 arg0, s32 arg1);
void Sg2ExPcmOutputCtrl(s32 arg0);
void createYesNoDialog(u8* arg0, s32 arg1);
void iosFree(void* arg0);
void changeVolume(s32 arg0);
extern u8 D_4012EAA0[];
extern u8* D_4012E3C8;
extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);
void sheetFileRead(void *, void *, s32);

/* NEARMISS-STUB setStartEditWorkTool */
#if 0 /* NEARMISS 93.181816% cat=regalloc sub=- | target copies setEditWorkTool result to v1 (daddu v1,v0); ours uses v0 directly | attempts=1 */
void *setEditWorkTool(void *a, s32 b, s32 c, s32 d);
void func_400FC890(void *p);

void setStartEditWorkTool(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    u8 *r = (u8 *)setEditWorkTool(a, b, c, f);

    if (r != NULL)
    {
        if (f == 0)
        {
            *(s32 *)(r + 0x20C) = d;
            *(s32 *)(r + 0x210) = e;
            *(s32 *)(r + 0x218) = g;
        }
        func_400FC890(r);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", setStartEditWorkTool);

/* NEARMISS-STUB unsetEndEditWorkTool */
#if 0 /* NEARMISS 99.25% cat=regalloc sub=- | base ptr for EA68 folded or kept in reg; ref keeps v1 base, E468/EA38 need v0 base reg | attempts=1 */
extern u8 D_4012EA68[];
extern u8 D_4012E468[];
extern u8 D_4012EA38[];
void windowCloseRequest(s32 arg0);
void unsetEditWorkTool(void *arg0);

void unsetEndEditWorkTool(void *arg0)
{
    u8 *p = D_4012EA68;

    if (*(s32*)(p + 0x30) != 0)
    {
        windowCloseRequest(*(s32*)(*(u8**)(p + 0x2C) + 4));
    }
    if (*(s32*)(D_4012E468 + 0x20) != 0)
    {
        windowCloseRequest(*(s32*)(*(u8**)D_4012E468 + 4));
    }
    if (*(s32*)(D_4012EA38 + 0x20) != 0)
    {
        windowCloseRequest(*(s32*)(*(u8**)D_4012EA38 + 4));
    }
    unsetEditWorkTool(arg0);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", unsetEndEditWorkTool);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", openEditWorkTool);

/* NEARMISS-STUB func_400FC6C8 */
#if 0 /* NEARMISS 70.606064% cat=branch-layout sub=- | gcc hoists return-0 into shared epilogue (v0=0 at top); ours has split return blocks and bnezl/beqz order differs | attempts=1 */
s32 func_400FC6C8(u32 param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    s32 *piVar4;
    u32 uVar5;
    u32 uVar6;

    iVar3 = *(s32 *)D_4012E3C8;
    iVar1 = *(s32 *)(D_4012E3C8 + 4);
    if (iVar3 == 0)
    {
        return 0;
    }
    if (iVar1 == 0)
    {
        return 0;
    }
    uVar5 = 0;
    uVar6 = *(u32 *)(iVar1 + 4);
    if (uVar6 == 0)
    {
        return 0;
    }
    piVar4 = (s32 *)(iVar1 + 0x20);
    do
    {
        if (uVar5 == param_1)
        {
            return iVar3 + param_2 * 4;
        }
        if (*piVar4 == 2)
        {
            iVar2 = piVar4[1] << 4;
        }
        else
        {
            iVar2 = piVar4[1] << 2;
        }
        iVar3 = iVar3 + iVar2;
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 6;
    } while (uVar5 < uVar6);
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC6C8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC750);
extern u8 D_4012E468[];
extern u8 D_4012EA38[];

void func_400FC750(void)
{
    u8 *b = D_4012E468;

    if (*(s32 *)(b + 0x20) != 0)
    {
        u8 *p = *(u8 **)b;
        u8 *q = *(u8 **)(p + 4);

        *(u64 *)(q + 0x1B8) |= 0x20;
    }
    b = D_4012EA38;
    if (*(s32 *)(b + 0x20) != 0)
    {
        u8 *p = *(u8 **)b;
        u8 *q = *(u8 **)(p + 4);

        *(u64 *)(q + 0x1B8) |= 0x20;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC7A8);
extern u8 *D_401C4994;
s32 chkEtiInfoWork(void);
void windowCloseRequest(s32 arg0);

void func_400FC7A8(void *a0, void *a1, s32 *a2)
{
    if (chkEtiInfoWork() != 0)
    {
        s32 i = 0;

        D_4012E3C8 = D_401C4994;
        if (a2[1] > 0)
        {
            do
            {
                i++;
                D_4012E3C8 = *(u8 **)(D_4012E3C8 + 8);
            } while (i < a2[1]);
        }
    }
    else
    {
        windowCloseRequest(*(s32 *)(*(u8 **)D_4012EA38 + 4));
    }
    return;
}

void func_400FC830(u8* arg0)
{
    createYesNoDialog(D_4012EAA0, *(s32*)(arg0 + 0x94));
}

void func_400FC850(u8* arg0)
{
    u8* temp = D_4012E3C8;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))(temp + 0x218);

    if (fn != NULL)
    {
        fn(*(void**)temp, *(void**)(temp + 0x20C), *(void**)(*(u8**)(arg0 + 0x3E8) + 4));
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC890);

/* NEARMISS-STUB initEtiInfoWork */
#if 0 /* NEARMISS 88.45946% cat=regalloc sub=- | lui/addiu base, list copy (a2) and node/counter regs swapped vs target; final base reload | attempts=1 */
extern u8 D_401C4990[];
extern u8 D_401C1F60[];
extern s32 D_4012E3C4;

void initEtiInfoWork(void)
{
    u8 *base;
    u8 *list;
    u8 *node;
    u8 *cur;
    u32 i;

    if (D_4012E3C4 == 0)
    {
        base = D_401C4990;
        list = base + 0xC;
        *(s32 *)(base + 0x0) = 0;
        *(s32 *)(base + 0x4) = 0;
        *(s32 *)(base + 0x8) = 0;
        *(s32 *)(list + 0x0) = 0;
        *(u8 **)(list + 0x4) = NULL;
        *(u8 **)(list + 0x8) = NULL;
        i = 0;
        node = D_401C1F60;
        do
        {
            if (node != NULL)
            {
                if (*(u8 **)(list + 0x8) == NULL)
                {
                    *(u8 **)(list + 0x4) = node;
                }
                else
                {
                    *(u8 **)(*(u8 **)(list + 0x8) + 0x8) = node;
                }
                *(u8 **)(node + 0x8) = NULL;
                *(s32 *)(list + 0x0) = *(s32 *)(list + 0x0) + 1;
                *(u8 **)(list + 0x8) = node;
            }
            i++;
            node += 0x21C;
        } while (i < 0x14);
        D_4012E3C4 = 1;
        base = D_401C4990;
        *(s32 *)(base + 0x18) = 0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", initEtiInfoWork);

void *loadPathData(void *f, void *b, int size)
{
    void *p = iosMallocAlign(&rootPtn, size, 16);
    sheetFileRead(f, p, size);
    return p;
}

void delPathData(void *arg0, void *arg1, void *arg2)
{
    iosFree(arg2);
    return;
}

u8* getPointDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x8);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLineDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0xC);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

static inline u8* getConnectLinePoint(u8* t, s32 i)
{
    if (t == NULL || i < 0 || (u32)i >= *(u32*)t)
    {
        return NULL;
    }
    return t + i * 48 + 0x10;
}

u8* getConnectLineArray(u8* arg0, s32 arg1)
{
    u8* p = getConnectLinePoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x10) != 0)
        {
            return arg0 + *(s32*)(p + 0x14);
        }
    }
    return NULL;
}

u8* getLineData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getRootDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x10);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getGoalDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x14);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getSubDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x18);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getRootPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getGoalPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getSubPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

static inline u8* getChildGoalPoint(u8* t, s32 i)
{
    if (t == NULL || i < 0 || (u32)i >= *(u32*)t)
    {
        return NULL;
    }
    return t + i * 48 + 0x10;
}

u8* getChildGoalPointIdxArray(u8* arg0, s32 arg1)
{
    u8* p = getChildGoalPoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x14) != 0)
        {
            return arg0 + *(s32*)(p + 0x18);
        }
    }
    return NULL;
}

u8* getChildSubPointIdxArray(u8* arg0, s32 arg1)
{
    u8* p = getChildGoalPoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x14) != 0)
        {
            return arg0 + *(s32*)(p + 0x18);
        }
    }
    return NULL;
}

u8* getInterestDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x20);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getInterestPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 32 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getDeadDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x24);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getDeadPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getLayoutDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x28);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLayoutPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecCreate);

s32 audioDecIsPreset(u8* arg0)
{
    if (*(s32*)(arg0 + 0x10) > 0x3FFFF)
    {
        Sg2ExPcmOutputCtrl(5);
        changeVolume(0x7F);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecReset);

void changeVolume(s32 arg0)
{
    s32 temp = arg0 * 129;

    Sg2ExPcmOutputSetVol(temp, temp);
}

void changeVolumeDirect(s32 arg0)
{
    Sg2ExPcmOutputSetVol(arg0, arg0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", spriteMovieImage);
