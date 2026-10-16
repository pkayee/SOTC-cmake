#include "common.h"
#include "sdk/ee/sifrpc.h"

typedef struct
{
    s32 cmd;
    s32 arg1;
    s32 arg2;
    s32 arg3;
} Sg2RemoteCmd;

typedef struct
{
    s32 cmd;
    s32 arg1;
    s32 arg2;
    s32 arg3;
    s32 status;
} Sg2RemoteDmaCmd;

extern Sg2RemoteCmd D_4010C6C0[0x200];
extern s32 D_4010C680;
extern s32 D_4010C684;
extern Sg2RemoteDmaCmd D_401108C0[0x20];
extern s32 D_401108A8;
extern s32 D_401108AC;
extern s32 D_401108D0[][5];
extern s32 D_40110780[];
extern s32 D_40110840;
extern s32 D_401106C0[];
extern s32 D_40110848[];
extern sceSifClientData D_40110880;
extern Sg2RemoteCmd D_4010E6C0[];

void *memset(void *, int, unsigned int);
void Sg2RemoteTickProc();
void *memcpy(void *, const void *, unsigned int);
s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
s32 DIntr();
s32 EIntr();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteSend);
s32 Sg2RemoteSend(s32 cmd, s32 arg1, s32 arg2, s32 arg3)
{
    s32 idx = D_4010C680;
    s32 en;

    D_4010C6C0[idx].cmd = cmd;
    D_4010C6C0[idx].arg1 = arg1;
    D_4010C6C0[idx].arg2 = arg2;
    D_4010C6C0[idx].arg3 = arg3;
    en = DIntr();
    D_4010C680 = (D_4010C680 + 1) % 0x200;
    if (en)
    {
        EIntr();
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteSendDmaCom);
s32 Sg2RemoteSendDmaCom(s32 cmd, s32 arg1, s32 arg2, s32 arg3)
{
    s32 idx = D_401108A8;
    s32 en;

    D_401108C0[idx].status = -1;
    D_401108C0[idx].cmd = cmd;
    D_401108C0[idx].arg1 = arg1;
    D_401108C0[idx].arg2 = arg2;
    D_401108C0[idx].arg3 = arg3;
    en = DIntr();
    D_401108A8 = (D_401108A8 + 1) % 0x20;
    if (en)
    {
        EIntr();
    }
    return idx;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteDmaTransStatus);
s32 Sg2RemoteDmaTransStatus(s32 idx)
{
    return D_401108D0[idx][0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteGetAdpStmAdr);
s32 Sg2RemoteGetAdpStmAdr(s32 idx)
{
    return D_40110780[idx];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteGetPcmStmTransOffset);
s32 Sg2RemoteGetPcmStmTransOffset()
{
    return D_40110840;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteGetSlotReleaseLv);
s32 Sg2RemoteGetSlotReleaseLv(s32 idx)
{
    return D_401106C0[idx];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteGetDspChangeStatus);
s32 Sg2RemoteGetDspChangeStatus(s32 idx)
{
    return D_40110848[idx];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteSyncStatus);
s32 Sg2RemoteSyncStatus()
{
    return sceSifCheckStatRpc((sceSifRpcData *)&D_40110880);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteTickProc);
void Sg2RemoteTickProc()
{
    s32 idx;
    s32 wrap = 0;
    s32 n;
    s32 wr;
    s32 rd;

    if (D_401108C0[idx = D_401108AC].status == -1)
    {
        D_401108C0[idx].status = -2;
        D_401106C0[0x61] = 1;
        Sg2RemoteSend(D_401108C0[idx].cmd, D_401108C0[idx].arg1, D_401108C0[idx].arg2, D_401108C0[idx].arg3);
    }
    rd = D_4010C684;
    wr = D_4010C680;
    if (wr < rd)
    {
        wrap = wr;
        n = 0x200 - rd;
    }
    else
    {
        n = wr - rd;
    }
    if (n != 0)
    {
        memcpy(D_4010E6C0, &D_4010C6C0[D_4010C684], n * 16);
    }
    if (wrap != 0)
    {
        memcpy(&D_4010E6C0[n], D_4010C6C0, wrap * 16);
    }
    sceSifCallRpc(&D_40110880, 0, 1, D_4010E6C0, (n + wrap) * 16, D_401106C0, 0x190, 0, 0);
    D_4010C684 = D_4010C680;
    if (D_401108C0[D_401108AC].status == -2 && D_401106C0[0x61] == 0)
    {
        D_401108C0[D_401108AC].status = 0;
        D_401108AC = (D_401108AC + 1) % 0x20;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/remote", Sg2RemoteInit);
s32 Sg2RemoteInit()
{
    s32 i;

    memset(D_4010C6C0, 0, 0x2000);
    D_4010C680 = 0;
    D_4010C684 = 0;
    memset(D_401108C0, 0, 0x280);
    D_401108A8 = D_401108AC = 0;
    do
    {
        if (sceSifBindRpc(&D_40110880, 0x11223344, 0) < 0)
        {
            return -1;
        }
        i = 0x2710;
        do
        {
            i -= 0x271;
            asm("nop");
        } while (i > 0);
    } while (D_40110880.serve == 0);
    Sg2CtrlEntryTickProcById(4, Sg2RemoteTickProc);
    return 0;
}
