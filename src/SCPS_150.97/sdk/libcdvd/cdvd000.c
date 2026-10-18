#include "common.h"
#include "sdk/common/libcdvd.h"
#include "sdk/ee/sifrpc.h"
#include "sdk/ee/eekernel.h"

s32 sceCdLayerSearchFile(sceCdlFILE *fp, const char *name, s32 layer);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdDelayThread);
void sceCdDelayThread(s32 usec, ...)
{
}

/* NEARMISS-STUB sceCdCallback */
#if 0 /* NEARMISS 93.0% cat=no-c-form sub=- | stores gp to D_00150F84 | attempts=1 */
int *sceCdCallback(void (*func)(int))
{
    int ie;
    int *old;

    if (sceCdSync(1) != 0)
    {
        return NULL;
    }
    ie = DIntr();
    old = (int *)D_00150F80[0];
    D_00150F80[0] = (s32)func;
    D_00150F84[0] = 0; /* sw $gp: no C form for reading $gp */
    if (ie != 0)
    {
        EIntr();
    }
    return old;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdCallback);

/* NEARMISS-STUB _sceCd_cd_callback */
#if 0 /* NEARMISS 84.0% cat=branch-layout sub=- | epilogue/store placement: target puts sw B74 before lui/sw tail and ld ra in b delay slot; ours puts sw B74 in b delay slot (early return or if/else both 84) | attempts=2 */
extern s32 D_00133B54[];
extern s32 D_00133B60[];
extern s32 D_00133B68[];
extern s32 D_00133B74[];
extern volatile s32 D_00133BA0[];
extern volatile s32 D_00133BA4[];
extern s32 D_00150F80[];

void _sceCd_cd_callback(s32 *arg)
{
    D_00133BA0[0] = arg[0];
    D_00133BA4[0] = D_00133BA0[0];
    if (D_00133BA0[0] == 11)
    {
        D_00133BA0[0] = 0;
        D_00133B74[0] = 0;
        return;
    }
    iSignalSema(D_00133B68[0]);
    if (D_00133B54[0] != 0 && D_00150F80[0] != 0)
    {
        iSignalSema(D_00133B60[0]);
    }
    else
    {
        D_00133B74[0] = 0;
    }
    D_00133BA0[0] = 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCd_cd_callback);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCd_cbLoop);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdInitEeCB);
extern struct ThreadParam D_00150F98[];
extern s32 D_00133B54[];
extern char D_00138990[];
void _sceCd_cbLoop(void *arg);

s32 sceCdInitEeCB(s32 prio, void *stack, s32 stackSize)
{
    s32 ret;
    s32 thread;

    ret = 1;
    if (D_00133B54[0] == 0)
    {
        D_00150F98[0].stackSize = stackSize;
        D_00150F98[0].entry = _sceCd_cbLoop;
        D_00150F98[0].stack = stack;
        D_00150F98[0].initPriority = prio;
        D_00150F98[0].option = (u32)D_00138990;
        D_00150F98[0].gpReg = NULL;
        D_00133B54[0] = CreateThread(D_00150F98);
        StartThread(D_00133B54[0], NULL);
    }
    else
    {
        ChangeThreadPriority(D_00133B54[0], prio);
        ret = 0;
    }
    return ret;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCd_cd_read_intr);
typedef struct
{
    int size1;
    int size2;
    u8 *dest1;
    u8 *dest2;
    u8 buf1[64];
    u8 buf2[64];
} CdReadIntrData;

extern u8 D_00133BA0[];
void _sceCd_cd_callback(void *arg);

void _sceCd_cd_read_intr(CdReadIntrData *data)
{
    int i;
    u8 *dst;
    u8 *udst;

    data = (CdReadIntrData *)((u32)data | 0x20000000);
    if (data->size1 > 0)
    {
        udst = (u8 *)((u32)data->dest1 | 0x20000000);
        dst = data->dest1;
        for (i = 0; i < data->size1; i++)
        {
            dst[i] = udst[i] = data->buf1[i];
        }
    }
    if (data->size2 > 0)
    {
        udst = (u8 *)((u32)data->dest2 | 0x20000000);
        dst = data->dest2;
        for (i = 0; i < data->size2; i++)
        {
            dst[i] = udst[i] = data->buf2[i];
        }
    }
    _sceCd_cd_callback(D_00133BA0);
}

extern s32 D_00133B60[];
extern s32 D_00133B68[];
extern s32 D_00133B6C[];
extern s32 D_00133B70[];
extern s32 D_00133B74[];
extern char D_001389A8[];
extern char D_001389B8[];
extern char D_001389C8[];
extern char D_001389D8[];

/* NEARMISS-STUB func_001170B0 */
#if 0 /* NEARMISS 91.44% cat=regalloc sub=- | SemaParam: sw/lui scheduling (initCount delay-slot placement, D_00133B74 lui hoist); no reorder fixed it | attempts=2 */
extern s32 D_00133B60[];
extern s32 D_00133B68[];
extern s32 D_00133B6C[];
extern s32 D_00133B70[];
extern s32 D_00133B74[];
extern char D_001389A8[];
extern char D_001389B8[];
extern char D_001389C8[];
extern char D_001389D8[];

void func_001170B0(void)
{
    struct SemaParam sp;

    if (D_00133B68[0] != -1)
    {
        if (D_00133B6C[0] != -1)
        {
            if (D_00133B70[0] != -1)
            {
                return;
            }
        }
    }
    sp.maxCount = 1;
    sp.initCount = 1;
    sp.option = (u32)D_001389A8;
    D_00133B68[0] = CreateSema(&sp);
    sp.option = (u32)D_001389B8;
    D_00133B6C[0] = CreateSema(&sp);
    sp.option = (u32)D_001389C8;
    D_00133B70[0] = CreateSema(&sp);
    sp.option = (u32)D_001389D8;
    sp.initCount = 0;
    D_00133B60[0] = CreateSema(&sp);
    D_00133B74[0] = 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", func_001170B0);

/* NEARMISS-STUB func_00117198 */
#if 0 /* NEARMISS 90.75% cat=cse-hoist sub=- | store before SignalSema needs volatile; target has lui s0 B60 after the sw, ours hoists lui s0 above lui v1 BA0 (scheduling) | attempts=2 */
extern s32 D_00133B54[];
extern s32 D_00133B60[];
extern s32 D_00133B68[];
extern s32 D_00133B6C[];
extern s32 D_00133B70[];

void func_00117198(void)
{
    s32 ie;

    if (D_00133B54[0] != 0)
    {
        ((volatile s32 *)D_00133BA0)[0] = -1;
        SignalSema(D_00133B60[0]);
    }
    DeleteSema(D_00133B68[0]);
    DeleteSema(D_00133B6C[0]);
    DeleteSema(D_00133B70[0]);
    DeleteSema(D_00133B60[0]);
    ie = DIntr();
    sceSifRemoveCmdHandler(0x80000012);
    if (ie != 0)
    {
        EIntr();
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", func_00117198);

/* NEARMISS-STUB sceCdPOffCallback */
#if 0 /* NEARMISS 93.0% cat=no-c-form sub=- | stores gp to D_00150F8C | attempts=1 */
extern s32 D_00133B88[];
extern s32 D_00150F88[];
extern s32 D_00150F8C[];
extern s32 D_00150F90[];
s32 func_00117310(void);

int *sceCdPOffCallback(void (*func)(void *), void *addr)
{
    int ie;
    int *old;

    if (D_00133B88[0] < 0)
    {
        func_00117310();
    }
    ie = DIntr();
    old = (int *)D_00150F88[0];
    D_00150F90[0] = (s32)addr;
    D_00150F88[0] = (s32)func;
    D_00150F8C[0] = 0; /* sw $gp: no C form for reading $gp */
    if (ie != 0)
    {
        EIntr();
    }
    return old;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdPOffCallback);

/* NEARMISS-STUB func_001172B8 */
#if 0 /* NEARMISS 69.0% cat=no-c-form sub=- | needs gp swap around callback | attempts=1 */
extern s32 D_00150F88[];
extern s32 D_00150F8C[];
extern s32 D_00150F90[];
extern s32 D_00133B64[];

void func_001172B8(void)
{
    void (*cb)(s32);

    cb = (void (*)(s32))D_00150F88[0];
    if (cb != NULL && D_00133B64[0] == 0)
    {
        cb(D_00150F90[0]);
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", func_001172B8);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", func_00117310);
extern s32 D_00133B64[];
extern s32 D_00133B88[];
void func_001172B8(void);

s32 func_00117310(void)
{
    s32 ie;

    D_00133B64[0] = 1;
    ie = DIntr();
    sceSifAddCmdHandler(0x80000012, func_001172B8, NULL);
    if (ie != 0)
    {
        EIntr();
    }
    D_00133B64[0] = 0;
    D_00133B88[0] = 1;
    return 1;
}


/* NEARMISS-STUB sceCdLayerSearchFile */
#if 0 /* NEARMISS 77.72% cat=branch-layout sub=- | name-copy loop shape (bnel with delay-slot increment, D151000 base folded to D151024 in ours) and reg alloc (fp in s2 vs s3); 36-byte uncached struct copy via C | attempts=1 */
extern s32 D_00133B50[];
extern s32 D_00133B5C[];
extern s32 D_00133B68[];
extern s32 D_00133B8C[];
extern s32 D_00151000[];
extern s32 D_00151140[];
extern s32 D_00151180[];
extern char D_001389F0[];
extern char D_00138A10[];
extern char D_00138A28[];
extern char D_00138A38[];
extern char D_00138A48[];
extern char D_00151024[];
s32 func_001170B0(void);

typedef struct
{
    u8 raw[0x24];
} CdlFileBlk;

s32 sceCdLayerSearchFile(sceCdlFILE *fp, const char *name, s32 layer)
{
    s32 ret;
    s32 r;
    s32 n;
    s32 i;

    ret = 0;
    func_001170B0();
    r = PollSema(D_00133B68[0]);
    if (D_00133B68[0] != r)
    {
        return ret;
    }
    D_00133B5C[0] = 1;
    if (sceCdSync(1) != 0)
    {
        SignalSema(D_00133B68[0]);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_00133B8C[0] < 0)
    {
        for (;;)
        {
            r = sceSifBindRpc((sceSifClientData *)D_00151180, 0x80000597, 0);
            if (r < 0)
            {
                if (D_00133B50[0] > 0)
                {
                    scePrintf(D_001389F0);
                }
                n = 0x100000;
                do
                {
                    n--;
                } while (n != -1);
                continue;
            }
            if (((sceSifClientData *)D_00151180)->serve == NULL)
            {
                n = 0x10000;
                do
                {
                    n--;
                } while (n != -1);
                continue;
            }
            break;
        }
        D_00133B8C[0] = 0;
    }
    ((u8 *)D_00151000)[0x24] = name[0];
    i = 0;
    if (name[0] != 0)
    {
        i = 1;
        while (i < 0x100)
        {
            ((u8 *)D_00151000)[0x24 + i] = name[i];
            if (name[i] == 0)
            {
                break;
            }
            i++;
        }
    }
    if (i == 0x100)
    {
        ((u8 *)D_00151000)[0x123] = 0;
    }
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138A10, D_00151024);
    }
    D_00151000[0x4A] = layer;
    D_00151000[0x49] = (s32)D_00151000;
    sceSifWriteBackDCache(D_00151000, 0x12C);
    r = sceSifCallRpc((sceSifClientData *)D_00151180, 0, 0, D_00151000, 0x12C, D_00151140, 4, NULL, NULL);
    if (r < 0)
    {
        SignalSema(D_00133B68[0]);
        return 0;
    }
    *(CdlFileBlk *)fp = *(CdlFileBlk *)(((u32)D_00151000) | 0x20000000);
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138A28, (u8 *)fp + 8);
    }
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138A38, ((s32 *)fp)[1]);
    }
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138A48, ((s32 *)fp)[0]);
    }
    ret = *(s32 *)(((u32)D_00151140) | 0x20000000);
    SignalSema(D_00133B68[0]);
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdLayerSearchFile);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdSearchFile);
s32 sceCdSearchFile(sceCdlFILE *fp, const char *name)
{
    return sceCdLayerSearchFile(fp, name, 0);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCd_ncmd_prechk);
extern s32 D_00133B50[];
extern s32 D_00133B5C[];
extern s32 D_00133B68[];
extern s32 D_00133B7C[];
extern s32 D_00134D10[];
extern char D_00138A60[];
extern char D_00138A88[];
void func_001170B0(void);

s32 _sceCd_ncmd_prechk(s32 arg)
{
    s32 i;

    func_001170B0();
    if (*(volatile s32 *)D_00133B68 != PollSema(*(volatile s32 *)D_00133B68))
    {
        if (*(volatile s32 *)D_00133B50 > 0)
        {
            scePrintf(D_00138A60, arg, D_00133B5C[0]);
        }
        return 0;
    }
    D_00133B5C[0] = arg;
    if (sceCdSync(1) != 0)
    {
        SignalSema(*(volatile s32 *)D_00133B68);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_00133B7C[0] < 0)
    {
        while (1)
        {
            if (sceSifBindRpc((sceSifClientData *)D_00134D10, 0x80000595, 0) < 0)
            {
                if (*(volatile s32 *)D_00133B50 > 0)
                {
                    scePrintf(D_00138A88);
                }
                for (i = 0x100000; i != -1; i--)
                {
                }
                continue;
            }
            if (((sceSifClientData *)D_00134D10)->serve != NULL)
            {
                break;
            }
            for (i = 0x100000; i != -1; i--)
            {
            }
        }
        D_00133B7C[0] = 0;
    }
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdNcmdDiskReady);
extern s32 D_00133BC0[];
extern s32 D_00133B68[];
extern s32 D_00134D10[];
s32 _sceCd_ncmd_prechk(s32 mode);

s32 sceCdNcmdDiskReady(void)
{
    s32 *buf;
    s32 r;

    if (_sceCd_ncmd_prechk(2) == 0)
    {
        return 0;
    }
    buf = D_00133BC0;
    r = sceSifCallRpc((sceSifClientData *)D_00134D10, 0xE, 0, NULL, 0, buf, 4, NULL, NULL);
    if (r < 0)
    {
        SignalSema(D_00133B68[0]);
        return 0;
    }
    r = *(s32 *)((u32)buf | 0x20000000);
    SignalSema(D_00133B68[0]);
    return r;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdSync);
extern s32 D_00133B50[];
extern s32 D_00133B74[];
extern s32 D_00134D10[];
extern char D_00138AA0[];

int sceCdSync(int mode)
{
    if (mode == 0)
    {
        if (D_00133B50[0] > 0)
        {
            scePrintf(D_00138AA0);
        }
        while (D_00133B74[0] != 0 || sceSifCheckStatRpc((sceSifRpcData *)D_00134D10) != 0)
        {
            DelayThread(0xFA0);
        }
        return 0;
    }
    if (D_00133B74[0] != 0 || sceSifCheckStatRpc((sceSifRpcData *)D_00134D10) != 0)
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdSyncS);
extern s32 D_00133B50[];
extern char D_00138AB0[];
extern s32 D_001356C0[];

s32 sceCdSyncS(s32 mode)
{
    if (mode == 0)
    {
        if (D_00133B50[0] > 0)
        {
            scePrintf(D_00138AB0);
        }
        while (sceSifCheckStatRpc((sceSifRpcData *)D_001356C0) != 0)
        {
            DelayThread(0xFA0);
        }
        return 0;
    }
    return sceSifCheckStatRpc((sceSifRpcData *)D_001356C0);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCd_scmd_prechk);
extern s32 D_00133B50[];
extern s32 D_00133B58[];
extern s32 D_00133B6C[];
extern s32 D_00133B94[];
extern s32 D_001356C0[];
extern char D_00138AC0[];
extern char D_00138AE8[];
void func_001170B0(void);

s32 _sceCd_scmd_prechk(s32 arg)
{
    s32 i;

    func_001170B0();
    if (*(volatile s32 *)D_00133B6C != PollSema(*(volatile s32 *)D_00133B6C))
    {
        if (*(volatile s32 *)D_00133B50 > 0)
        {
            scePrintf(D_00138AC0, arg, D_00133B58[0]);
        }
        return 0;
    }
    D_00133B58[0] = arg;
    if (sceCdSyncS(1) != 0)
    {
        SignalSema(*(volatile s32 *)D_00133B6C);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_00133B94[0] < 0)
    {
        while (1)
        {
            if (sceSifBindRpc((sceSifClientData *)D_001356C0, 0x80000593, 0) < 0)
            {
                if (*(volatile s32 *)D_00133B50 > 0)
                {
                    scePrintf(D_00138AE8);
                }
                for (i = 0x100000; i != -1; i--)
                {
                }
                continue;
            }
            if (((sceSifClientData *)D_001356C0)->serve != NULL)
            {
                break;
            }
            for (i = 0x100000; i != -1; i--)
            {
            }
        }
        D_00133B94[0] = 0;
    }
    return 1;
}

/* NEARMISS-STUB _sceCdSC */
#if 0 /* NEARMISS 0.0% cat=branch-layout sub=- | beq chain: target bodies out of line (beq to shared store), our compile inverts to bnel and uses a0 for the 0x8011 base; no mechanical fix found | attempts=2 */
extern s32 D_00133B68[];
extern s32 D_00133B6C[];
extern s32 D_00133BC0[];
extern char D_00133C40[];
extern s32 D_00134D10[];
extern char D_00134D40[];
extern char D_00135180[];
extern s32 D_001356C0[];

s32 _sceCdSC(s32 code, s32 *out)
{
    s32 v;

    if (code == 0x8001)
    {
        v = D_00133B68[0];
    }
    else if (code == 0x8003)
    {
        v = (s32)D_00133BC0;
    }
    else if (code == 0x8002)
    {
        v = (s32)D_00133C40;
    }
    else if (code == 0x8004)
    {
        v = (s32)D_00134D10;
    }
    else if (code == 0x8011)
    {
        *out = D_00133B6C[0];
        return 1;
    }
    else if (code == 0x8013)
    {
        v = (s32)D_00134D40;
    }
    else if (code == 0x8012)
    {
        v = (s32)D_00135180;
    }
    else if (code == 0x8014)
    {
        v = (s32)D_001356C0;
    }
    else
    {
        v = 0;
    }
    *out = v;
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", _sceCdSC);

/* NEARMISS-STUB sceCdInit */
#if 0 /* NEARMISS 64.92% cat=regalloc sub=- | bind-loop shape now matches (while(1), 0x100000 delays); remaining: mode kept in s8 not s3, per-global lui hoists (s5 B9C, s4 B98) not kept live across function | attempts=2 */
extern s32 D_00133B50[];
extern s32 D_00133B60[];
extern s32 D_00133B64[];
extern s32 D_00133B68[];
extern s32 D_00133B6C[];
extern s32 D_00133B78[];
extern s32 D_00133B7C[];
extern s32 D_00133B84[];
extern s32 D_00133B88[];
extern s32 D_00133B8C[];
extern s32 D_00133B90[];
extern s32 D_00133B94[];
extern s32 D_00133B98[];
extern s32 D_00133B9C[];
extern s32 D_00151200[];
extern s32 D_001511A8[];
extern s32 D_00134D40[];
extern char D_00138B00[];
extern char D_00138B20[];
s32 func_001170B0(void);
void func_00117198(void);
s32 func_00117310(void);

s32 sceCdInit(s32 mode)
{
    s32 ret;
    s32 r;
    s32 n;
    s32 a0;
    s32 a1;
    s32 a2;

    ret = 0;
    if (sceCdSyncS(1) != 0)
    {
        return ret;
    }
    sceSifInitRpc(0);
    D_00133B64[0] = 1;
    D_00133B88[0] = -1;
    D_00133B8C[0] = -1;
    D_00133B7C[0] = -1;
    D_00133B94[0] = -1;
    D_00133B90[0] = -1;
    D_00133B78[0] = 0;
    D_00133B9C[0] = D_00133B9C[0] + 1;
    D_00133B98[0] = -1;
    for (;;)
    {
        r = sceSifBindRpc((sceSifClientData *)D_001511A8, 0x80000592, 0);
        if (r < 0)
        {
            if (D_00133B50[0] > 0)
            {
                scePrintf(D_00138B00, D_00133B9C[0]);
            }
            n = 0x10000;
            do
            {
                n--;
            } while (n != -1);
            continue;
        }
        if (((sceSifClientData *)D_001511A8)->serve == NULL)
        {
            n = 0x10000;
            do
            {
                n--;
            } while (n != -1);
            continue;
        }
        break;
    }
    D_00133B98[0] = 0;
    D_00151200[0] = mode;
    sceSifWriteBackDCache(D_00151200, 4);
    r = sceSifCallRpc((sceSifClientData *)D_001511A8, 0, 0, D_00151200, 4, D_00134D40, 16, NULL, NULL);
    if (r < 0)
    {
        D_00133B64[0] = 0;
        return 0;
    }
    a2 = *(s32 *)(((u32)D_00134D40 + 0xC) | 0x20000000);
    a1 = *(s32 *)(((u32)D_00134D40 + 0x4) | 0x20000000);
    a0 = *(s32 *)(((u32)D_00134D40 + 0x8) | 0x20000000);
    ret = 1;
    if (a2 == 0xFF)
    {
    }
    else if (a2 == 0xFE)
    {
        D_00133B50[0] = ret;
    }
    else if (((a2 < a1 ? a1 : a1 + 0xFF) >> 8) < 2)
    {
        ret = 2;
    }
    else if (((a2 < a0 ? a0 : a0 + 0xFF) >> 8) < 2)
    {
        ret = 2;
    }
    D_00133B64[0] = 0;
    if (mode == 5)
    {
        if (D_00133B50[0] > 0)
        {
            scePrintf(D_00138B20);
        }
        func_00117198();
        D_00133B68[0] = -1;
        D_00133B6C[0] = -1;
        D_00133B60[0] = -1;
        D_00133B84[0] = 0;
    }
    else
    {
        func_001170B0();
        func_00117310();
        D_00133B84[0] = 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdInit);

/* NEARMISS-STUB sceCdDiskReady_old */
#if 0 /* NEARMISS 66.98% cat=regalloc sub=- | regalloc: target keeps mode in s2, B6C lui in s3, B50 lui s6 kept across function, D134D40 in s7; ours shifts all of them by one reg and saves 8 regs | attempts=1 */
extern s32 D_00133B50[];
extern s32 D_00133B6C[];
extern s32 D_00133B80[];
extern s32 D_00133B90[];
extern s32 D_001511D0[];
extern s32 D_00151210[];
extern s32 D_00134D40[];
extern char D_00138B30[];
extern char D_00138B48[];
extern char D_00138B68[];
s32 func_001170B0(void);

s32 sceCdDiskReady_old(s32 mode)
{
    s32 r;
    s32 n;
    s32 ie;
    s32 ret;

    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138B30);
    }
    ie = DIntr();
    D_00133B80[0] = 1;
    if (ie != 0)
    {
        EIntr();
    }
    func_001170B0();
    r = PollSema(D_00133B6C[0]);
    if (D_00133B6C[0] != r)
    {
        return (mode == 8) ? -1 : 6;
    }
    if (sceCdSyncS(1) != 0)
    {
        SignalSema(D_00133B6C[0]);
        return (mode == 8) ? -1 : 6;
    }
    sceSifInitRpc(0);
    if (D_00133B90[0] < 0)
    {
        for (;;)
        {
            while (sceSifBindRpc((sceSifClientData *)D_001511D0, 0x8000059A, 0) < 0)
            {
                if (D_00133B50[0] > 0)
                {
                    scePrintf(D_00138B48);
                }
                n = 0x100000;
                do
                {
                    n--;
                } while (n != -1);
            }
            if (((sceSifClientData *)D_001511D0)->serve != NULL)
            {
                D_00133B90[0] = 0;
                break;
            }
            n = 0x10000;
            do
            {
                n--;
            } while (n != -1);
        }
    }
    D_00151210[0] = mode;
    sceSifWriteBackDCache(D_00151210, 4);
    r = sceSifCallRpc((sceSifClientData *)D_001511D0, 0, 0, D_00151210, 4, D_00134D40, 4, NULL, NULL);
    if (r < 0)
    {
        SignalSema(D_00133B6C[0]);
        return (mode == 8) ? -1 : 6;
    }
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138B68);
    }
    ret = *(s32 *)((u32)D_00134D40 | 0x20000000);
    SignalSema(D_00133B6C[0]);
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdDiskReady_old);

/* NEARMISS-STUB sceCdDiskReady */
#if 0 /* NEARMISS 65.31% cat=branch-layout sub=- | regalloc+frame: target keeps mode in s2, pointer-less D_00151210 sw/addiu s0 base; ours keeps mode in s3 and 7 saved regs; pointer-local buffers tried 64.09 (wo | attempts=1 */
extern s32 D_00133B50[];
extern s32 D_00133B70[];
extern s32 D_00133B80[];
extern s32 D_00133B90[];
extern s32 D_001511D0[];
extern s32 D_00151210[];
extern s32 D_001355C0[];
extern char D_00138B48[];
extern char D_00138B68[];
extern char D_00138B80[];
s32 func_001170B0(void);
s32 sceCdDiskReady_old(s32 mode);

s32 sceCdDiskReady(s32 mode)
{
    s32 r;
    s32 n;
    s32 retry;
    s32 ie;
    s32 ret;

    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138B80);
    }
    func_001170B0();
    r = PollSema(D_00133B70[0]);
    if (D_00133B70[0] != r)
    {
        return (mode == 8) ? -1 : 6;
    }
    sceSifInitRpc(0);
    retry = 0;
    if (D_00133B90[0] < 0)
    {
        for (;;)
        {
            while (sceSifBindRpc((sceSifClientData *)D_001511D0, 0x8000059C, 0) < 0)
            {
                if (D_00133B50[0] > 0)
                {
                    scePrintf(D_00138B48);
                }
                n = 0x100000;
                do
                {
                    n--;
                } while (n != -1);
            }
            if (((sceSifClientData *)D_001511D0)->serve != NULL)
            {
                D_00133B90[0] = 0;
                break;
            }
            if (retry >= 17)
            {
                SignalSema(D_00133B70[0]);
                return sceCdDiskReady_old(mode);
            }
            retry++;
            n = 0x10000;
            do
            {
                n--;
            } while (n != -1);
        }
    }
    ie = DIntr();
    D_00133B80[0] = 0;
    if (ie != 0)
    {
        EIntr();
    }
    D_00151210[0] = mode;
    sceSifWriteBackDCache(D_00151210, 4);
    r = sceSifCallRpc((sceSifClientData *)D_001511D0, 0, 0, D_00151210, 4, D_001355C0, 4, NULL, NULL);
    if (r < 0)
    {
        SignalSema(D_00133B70[0]);
        return (mode == 8) ? -1 : 6;
    }
    if (D_00133B50[0] > 0)
    {
        scePrintf(D_00138B68);
    }
    ret = *(s32 *)((u32)D_001355C0 | 0x20000000);
    SignalSema(D_00133B70[0]);
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libcdvd/cdvd000", sceCdDiskReady);
