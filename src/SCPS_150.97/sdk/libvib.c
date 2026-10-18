#include "common.h"

extern u8 D_0014EA80[];
extern u8 D_0014EB80[];
int sceSifCallRpc(void *, u32, u32, void *, int, void *, int, void *, void *);
int sceDbcReceiveData(int, u64, void *, void *);
int sceDbcSendData2(int, u64, void *, void *);
void *memcpy(void *, const void *, u32);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libvib", sceVibGetProfile);
int sceVibGetProfile(int port, u8 *profile)
{
    u64 cmd;
    s32 buf[2];
    s32 ret;

    cmd &= -0x4000;
    cmd |= 2;
    cmd &= ~0xC000;
    cmd |= 0x8000;
    cmd &= ~0xFF0000;
    cmd |= 0x30000;
    cmd &= ~(u64)0xFF000000;
    ret = sceDbcReceiveData(port, cmd | 0x1000000, buf, profile);
    if (ret >= 0)
    {
        ret = *(volatile s32 *)buf;
    }
    return ret;
}

/* NEARMISS-STUB sceVibSetActParam */
#if 0 /* NEARMISS 80.56% cat=sched sub=- | prologue sd save placement, arg-move and buf[0] store (delay slot) order differ | attempts=1 */
int sceVibSetActParam(int port, int n1, u8 *p1, int n2, u8 *p2)
{
    s32 buf[12];
    s32 size;
    u64 cmd;

    cmd &= -0x4000;
    cmd |= 0xB;
    cmd &= ~0xC000;
    cmd |= 0x4000;
    cmd &= ~0xFF0000;
    cmd |= 0x30000;
    cmd &= ~(u64)0xFF000000;
    cmd |= 0x1000000;
    size = 0x28;
    buf[1] = n2;
    memcpy((u8 *)buf + 8, p2, n2);
    memcpy((u8 *)buf + 8 + n2, p1, n1);
    buf[0] = n1;
    return sceDbcSendData2(port, cmd, &size, buf);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libvib", sceVibSetActParam);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libvib", func_00115B30);

s32 func_00115B30(void)
{
    sceSifCallRpc(D_0014EA80, 0x80001363, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    return *(s32 *)D_0014EB80;
}
