#include "common.h"

typedef struct DlState
{
    s32 endAdrs[2]; // 0x0
    s32 createAdrs[2]; // 0x8
    s32 packetPtrPath1; // 0x10
    s32 layerNum;  // 0x14
    s32 workBufId; // 0x18
    s32 layer;     // 0x1C
    s32 lockLink[2]; // 0x20
    s32 lockCount[2]; // 0x28
} DlState;

typedef struct DmaTagBits { u64 qwc:16; u64 pad:10; u64 pce:2; u64 id:3; u64 irq:1; u64 addr:31; u64 spr:1; } DmaTagBits;
typedef union DmaTag { u64 w; DmaTagBits b; } DmaTag;
typedef struct DlPkt { u64 tag; u32 unk8; u32 unkC; DmaTag next; u32 unk18; u32 unk1C; } DlPkt;
typedef struct DlRec { DmaTag tag; u8 pad8[0x18]; u32 head; u32 tail; u8 pad28[8]; } DlRec;

extern DlState D_40092698;
extern s32 D_40092690;
extern s32 D_40045A1C;
extern s32 D_40045A10;
extern s32 D_40045A14;
extern char D_400475C0[];
extern char D_400475D8[];
extern s32 D_40045A20;
extern s32 D_400926C8[];

s32 LoaderSysPrintf(const char *format, ...);
void iosFree(s32);

s32 iosCreateSema(s32, s32, s32);
s32 SignalSema(s32);
s32 WaitSema(s32);
void iosDmaSendSChainPath1(s32);
void isysObjDeleteLock(s32);
s32 isysAddGroupWithLinkParamNoWait(s32, s32 *, s32, s32);
void func_40024FB0(void);
extern char D_40047600[];
void isysObjWaitSema();
void isysObjSignalSema();
s32 *isysGroupForFirstForce();
s32 *isysGroupForNextForce();
void isysObjDeleteUnLock();
void isysGroupForExit();
void isysDeleteGroupAllObj();
void func_40024B90(void);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024B90);

/* NEARMISS-STUB iosDlPopLayer */
#if 0 /* NEARMISS 86.68% cat=alias sub=rea-fixed | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=3 */
s32 iosDlPopLayer(void)
{
    s32 count = D_40045A20 - 1;
    s32 layer;

    D_40045A20 = count;
    if (count < 0)
    {
        LoaderSysPrintf(D_40047600, ((DlState *)&D_40092698)->layer, D_400926C8[count]);
    }
    layer = D_400926C8[D_40045A20];
    if (layer < 0)
    {
        LoaderSysPrintf(D_400475C0);
    }
    else if (layer >= ((DlState *)&D_40092698)->layerNum)
    {
        layer = ((DlState *)&D_40092698)->layerNum - 1;
    }
    ((DlState *)&D_40092698)->layer = layer;

    return D_400926C8[D_40045A20];
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPopLayer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024FB0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosUsedPacketBufferSize);
f32 iosUsedPacketBufferSize(void)
{
    DlState *dl = &D_40092698;
    u32 used = dl->packetPtrPath1 - dl->endAdrs[dl->workBufId];

    return used / (f32)(D_40045A1C << 4);
}

/* NEARMISS-STUB iosCreateIVArbitrationSema */
#if 0 /* NEARMISS 91.58% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosCreateIVArbitrationSema(void)
{
    s32 sema = iosCreateSema(0, 1, 0);
    s32 *dst = &D_40092690;

    *dst = sema;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosCreateIVArbitrationSema);

/* NEARMISS-STUB iosDlGetTransAdrs */
#if 0 /* NEARMISS 71.11% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosDlGetTransAdrs(void)
{
    s32 *base = (s32 *)&D_40092698;

    return base[2 + base[6]];
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetTransAdrs);

/* NEARMISS-STUB iosGetPacketPtrPath1 */
#if 0 /* NEARMISS 82.78% cat=no-c-form sub=- | pref 0x00,0x40(a0) prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 82.78% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
s32 iosGetPacketPtrPath1(void)
{
    DlState *dl = &D_40092698;

    if (dl->packetPtrPath1 & 0xF)
    {
        dl->packetPtrPath1 = dl->packetPtrPath1 - (dl->packetPtrPath1 & 0xF) + 0x10;
    }

    return ((DlState *)&D_40092698)->packetPtrPath1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosGetPacketPtrPath1);

/* NEARMISS-STUB iosSetPacketPtrPath1 */
#if 0 /* NEARMISS 46.8% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosSetPacketPtrPath1(s32 arg0)
{
    s32 *base = (s32 *)&D_40092698 + 4;

    *base = arg0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosSetPacketPtrPath1);

/* NEARMISS-STUB iosAllocPacketPtrPath1 */
#if 0 /* NEARMISS 88.89% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 88.89% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
s32 iosAllocPacketPtrPath1(s32 arg0)
{
    DlState *dl = &D_40092698;
    s32 ret = dl->packetPtrPath1;

    dl->packetPtrPath1 = dl->packetPtrPath1 + arg0;

    return ret;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosAllocPacketPtrPath1);

/* NEARMISS-STUB iosDlChainHead */
#if 0 /* NEARMISS 10.27% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 10.27% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
void iosDlChainHead(s32 idx, s32 dc)
{
    DlState *dl = &D_40092698;
    DlRec *rec = (DlRec *)(dl->createAdrs[dl->workBufId] + idx * 0x30);
    DlPkt *pkt = (DlPkt *)dl->packetPtrPath1;
    DmaTag tag;

    dl->packetPtrPath1 = dl->packetPtrPath1 + 0x20;
    pkt->tag = ((u64)dc << 32) | 0x50000000;
    pkt->unk1C = 0;
    pkt->unk18 = 0;
    pkt->unkC = 0;
    pkt->unk8 = 0;
    pkt->next.w = ((u64)rec->head << 32) | 0x20000000;
    rec->head = (u32)pkt;
    rec->tag.b.addr = (u32)pkt;
    rec->tag.b.id = 5;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainHead);

/* NEARMISS-STUB iosDlChainTail */
#if 0 /* NEARMISS 42.2% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 42.20% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
void iosDlChainTail(s32 idx, s32 dc)
{
    DlState *dl = &D_40092698;
    DlRec *rec = (DlRec *)(dl->createAdrs[dl->workBufId] + idx * 0x30);
    DlPkt *pkt = (DlPkt *)dl->packetPtrPath1;
    u32 link;

    dl->packetPtrPath1 = dl->packetPtrPath1 + 0x20;
    pkt->tag = ((u64)dc << 32) | 0x50000000;
    pkt->unk1C = 0;
    pkt->unk18 = 0;
    pkt->unkC = 0;
    pkt->unk8 = 0;
    link = ((DlPkt *)rec->tail)->next.b.addr;
    pkt->next.w = ((u64)link << 32) | 0x20000000;
    ((DlPkt *)rec->tail)->next.b.addr = (u32)pkt;
    rec->tail = (u32)pkt;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainTail);

/* NEARMISS-STUB iosDlChainHeadCurrent */
#if 0 /* NEARMISS 17.28% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 17.28% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
void iosDlChainHeadCurrent(s32 dc)
{
    DlState *dl = &D_40092698;
    s32 idx = dl->layer;
    DlRec *rec = (DlRec *)(dl->createAdrs[dl->workBufId] + idx * 0x30);
    DlPkt *pkt = (DlPkt *)dl->packetPtrPath1;
    DmaTag tag;

    dl->packetPtrPath1 = dl->packetPtrPath1 + 0x20;
    pkt->tag = ((u64)dc << 32) | 0x50000000;
    pkt->unk1C = 0;
    pkt->unk18 = 0;
    pkt->unkC = 0;
    pkt->unk8 = 0;
    pkt->next.w = ((u64)rec->head << 32) | 0x20000000;
    rec->head = (u32)pkt;
    rec->tag.b.addr = (u32)pkt;
    rec->tag.b.id = 5;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainHeadCurrent);

/* NEARMISS-STUB iosDlChainTailCurrent */
#if 0 /* NEARMISS 47.42% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 47.42% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
void iosDlChainTailCurrent(s32 dc)
{
    DlState *dl = &D_40092698;
    s32 idx = dl->layer;
    DlRec *rec = (DlRec *)(dl->createAdrs[dl->workBufId] + idx * 0x30);
    DlPkt *pkt = (DlPkt *)dl->packetPtrPath1;
    u32 link;

    dl->packetPtrPath1 = dl->packetPtrPath1 + 0x20;
    pkt->tag = ((u64)dc << 32) | 0x50000000;
    pkt->unk1C = 0;
    pkt->unk18 = 0;
    pkt->unkC = 0;
    pkt->unk8 = 0;
    link = ((DlPkt *)rec->tail)->next.b.addr;
    pkt->next.w = ((u64)link << 32) | 0x20000000;
    ((DlPkt *)rec->tail)->next.b.addr = (u32)pkt;
    rec->tail = (u32)pkt;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainTailCurrent);

/* NEARMISS-STUB iosDlSwap */
#if 0 /* NEARMISS 82.58% cat=alias sub=rea-fixed | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=2 */
void iosDlSwap(void)
{
    s32 *group;
    s32 idx;
    s32 *link;
    s32 obj = 0;
    s32 *sema = &D_40092690;

    WaitSema(*sema);
    ((DlState *)&D_40092698)->workBufId ^= 1;
    idx = ((DlState *)&D_40092698)->workBufId;
    group = (s32 *)((DlState *)&D_40092698)->lockLink + idx;
    isysObjWaitSema();
    link = isysGroupForFirstForce(group, 0);
    while (link != 0)
    {
        obj = *link;
        isysObjDeleteUnLock(obj);
        ((DlState *)&D_40092698)->lockCount[idx]--;
        link = isysGroupForNextForce(link, 0);
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
    isysDeleteGroupAllObj(group);
    isysObjSignalSema();
    func_40024B90();
    SignalSema(*sema);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlSwap);

/* NEARMISS-STUB iosDlTrans */
#if 0 /* NEARMISS 80.5% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosDlTrans(void)
{
    DlState *dl;
    s32 *sema = &D_40092690;
    s32 *adrs;

    WaitSema(*sema);
    dl = &D_40092698;
    adrs = dl->createAdrs;
    iosDmaSendSChainPath1(adrs[!dl->workBufId]);
    D_40045A14++;
    SignalSema(*sema);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTrans);

void iosDlLockObj(s32 arg0)
{
    isysObjDeleteLock(arg0);
    isysAddGroupWithLinkParamNoWait(arg0, &((DlState *)&D_40092698)->lockLink[((DlState *)&D_40092698)->workBufId], 0, 0);
    ((DlState *)&D_40092698)->lockCount[((DlState *)&D_40092698)->workBufId]++;
}

/* NEARMISS-STUB iosDlGetWorkBufId */
#if 0 /* NEARMISS 46.8% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosDlGetWorkBufId(void)
{
    s32 *w = &D_40092698.workBufId;

    return *w;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetWorkBufId);

/* NEARMISS-STUB iosDlGetTransBufId */
#if 0 /* NEARMISS 78.8% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosDlGetTransBufId(void)
{
    DlState *dl = &D_40092698;
    s32 *w = &dl->workBufId;

    return *w == 0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetTransBufId);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetEndAdrs);
s32 iosDlGetEndAdrs(void)
{
    DlState *dl = &D_40092698;

    return dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;
}

/* NEARMISS-STUB iosDlGetLayer */
#if 0 /* NEARMISS 46.8% cat=alias sub=- | needs the banned qualifier: qualifier-free forms (plain DlState* local, split assign, u32 base cast, register local) all leave lui+lw folded as %lo(D+0x1c), expecte | attempts=1 */
s32 iosDlGetLayer(void)
{
    DlState *dl = &D_40092698;

    return dl->layer;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayer);

/* NEARMISS-STUB iosDlSetLayer */
#if 0 /* NEARMISS 78.96% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosDlSetLayer(s32 arg0)
{
    s32 layer = arg0;

    if (layer < 0)
    {
        LoaderSysPrintf(D_400475C0);
    }
    else if (layer >= ((DlState *)&D_40092698)->layerNum)
    {
        layer = ((DlState *)&D_40092698)->layerNum - 1;
    }
    ((DlState *)&D_40092698)->layer = layer;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlSetLayer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPushLayer);

/* NEARMISS-STUB iosDlGetLayerNum */
#if 0 /* NEARMISS 46.8% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosDlGetLayerNum(void)
{
    s32 *base = (s32 *)&D_40092698 + 5;

    return *base;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayerNum);

/* NEARMISS-STUB iosDlRelease */
#if 0 /* NEARMISS 79.73% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosDlRelease(void)
{
    DlState *dl = &D_40092698;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        s32 *createAdrs = dl->createAdrs;
        s32 *endAdrs = dl->endAdrs;

        if (createAdrs[i] != 0)
        {
            iosFree(createAdrs[i]);
        }
        if (endAdrs[i] != 0)
        {
            iosFree(endAdrs[i]);
        }
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlRelease);

/* NEARMISS-STUB InitDL */
#if 0 /* NEARMISS 76.44% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void InitDL(void)
{
    s32 *sema;
    s32 *dst;

    func_40024FB0();
    sema = &D_40092690;
    SignalSema(*sema);
    dst = &D_40045A10;
    *dst = 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", InitDL);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckAdrs);
s32 iosDlCheckAdrs(s32 arg0)
{
    DlState *dl = &D_40092698;
    u32 end = dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;

    return (u32)arg0 < end;
}

/* NEARMISS-STUB iosDlCheckSize */
#if 0 /* NEARMISS 88.08% cat=no-c-form sub=- | pref prefetch has no C form | attempts=1 */
// kR39 asm-free attempt: 88.08% (missing: pref 0x00,0x40 prefetch has no gcc 2.96 C form; register/addr-load arg_mism and extra/missing insns follow from it)
s32 iosDlCheckSize(void)
{
    DlState *dl = &D_40092698;
    s32 end = dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;

    if (dl->packetPtrPath1 & 0xF)
    {
        dl->packetPtrPath1 = dl->packetPtrPath1 - (dl->packetPtrPath1 & 0xF) + 0x10;
    }

    return end - ((DlState *)&D_40092698)->packetPtrPath1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckSize);

/* NEARMISS-STUB iosDlGetCreateAdrs */
#if 0 /* NEARMISS 71.0% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosDlGetCreateAdrs(void)
{
    DlState *dl = &D_40092698;
    s32 *w = &dl->workBufId;

    return dl->createAdrs[*w == 0 ? 1 : 0];
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetCreateAdrs);

/* NEARMISS-STUB iosAllocPacketPtrPath1UnCachedA */
#if 0 /* NEARMISS 64.0% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
s32 iosAllocPacketPtrPath1UnCachedA(s32 arg0)
{
    DlState *dl = &D_40092698;
    s32 ret = dl->packetPtrPath1 | 0x30000000;

    dl->packetPtrPath1 = dl->packetPtrPath1 + arg0;

    return ret;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosAllocPacketPtrPath1UnCachedA);

/* NEARMISS-STUB iosDlTransNow */
#if 0 /* NEARMISS 69.96% cat=alias sub=- | needs the banned qualifier: gcc folds %lo/merges reads without it | attempts=1 */
void iosDlTransNow(void)
{
    DlState *dl;
    s32 *sema = &D_40092690;
    s32 *adrs;

    WaitSema(*sema);
    dl = &D_40092698;
    adrs = dl->createAdrs;
    iosDmaSendSChainPath1(adrs[dl->workBufId == 0 ? 1 : 0]);
    SignalSema(*sema);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTransNow);
