#include "common.h"

extern s32 rootPtn;
void nicosysdSendDataStart(void *, s32, void *, s32);
void nicosysdSendDataWrite(void *, void *, s32);
void nicosysdExec(void *, void *, void *);
s32 nicosysdRecvDataRead(s32, void *, s32);
void func_400EC3F0(void *, s32 *);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", nicosysdForceEchoReadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", nicosysdEchoDdebugPrintReadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", nicosysdInit);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", func_400EC3F0);

void func_400EC3F0(void *arg0, s32 *arg1)
{
    s32 size = arg1[2];
    u8 buf[size];

    nicosysdRecvDataRead((s32)arg0, buf, size);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", csvMakeOpen);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", csvMakeBlockWriteData);

s32 csvMakeClose(s32 id)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd = 2000;
    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, 8);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &id, 4);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", csvMakeDeleteSegment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", csvMakeCreateNewSegment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", func_400EC808);
