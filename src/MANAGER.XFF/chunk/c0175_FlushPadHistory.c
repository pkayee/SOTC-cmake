#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", FlushPadHistory);

s32 iosCreateSema(s32, s32, s32);

extern s32 D_401B179C;
extern s32 D_4012DAD0;

void InitPadHistory(void)
{
    D_401B179C = iosCreateSema(1, 1, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", shockRequestCalcVol);

void setVibrationEnableWorkAdrs(s32 arg0)
{
    D_4012DAD0 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", shockRequest);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", svdLoadFile);

extern u8 D_401B17A4[];

void *usbdevMouseGetStatus(void)
{
    return D_401B17A4;
}

typedef struct
{
    s32 status;
    s32 a;
    s32 b;
} Keybd;

extern Keybd D_401B1800[];

s32 usbdevKeybdGetStatus(s32 i, s32 mask, s32 mod)
{
    s32 r = 0;
    if (D_401B1800[i].status & mask) {
        s32 m = ((s32 *)D_401B1800)[-1];
        r = (m & mod) == m;
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", usbdevAddCallbackFunc);

extern void iosKeybdSetCallBackFunc(void *);
extern void iosMouseSetCallBackFunc(void *);
extern void kbGetStatus(void *, void *);
extern void kbInit();
extern void mouseGetStatus(void *);
extern void mouseInit();
extern u8 D_401B17A0[];
extern int func_400DD140(void *status);
extern int func_400DD198(void *status);

void usbdevInit(void)
{
    (*(int *)((char *)(D_401B17A0) + 0)) = 0;
    (*(int *)((char *)(D_401B17A0) + 0x58)) = 0;
    iosMouseSetCallBackFunc(&func_400DD140);
    iosKeybdSetCallBackFunc(&func_400DD198);
    mouseInit();
    kbInit();
    mouseGetStatus(D_401B17A0 + 4);
    kbGetStatus(D_401B17A0 + 0x60, D_401B17A0 + 0x5C);
}

void usbdevFrameInit(void)
{
    mouseGetStatus(D_401B17A4);
    kbGetStatus(D_401B17A4 + 0x5C, D_401B17A4 + 0x58);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", func_400DD140);
typedef void (*FlushCb)(void *);

int func_400DD140(void *status)
{
    s32 *node;

    node = *(s32 **)D_401B17A0;
    if (node != NULL) {
        do {
            ((FlushCb)node[0])(status);
            node = (s32 *)node[1];
        } while (node != NULL);
    }
    return 1;
}

extern s32 *D_401B17F8;

int func_400DD198(void *status)
{
    s32 *node;

    node = D_401B17F8;
    if (node != NULL) {
        do {
            ((FlushCb)node[0])(status);
            node = (s32 *)node[1];
        } while (node != NULL);
    }
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", func_400DD1F0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0175_FlushPadHistory", func_400DD890);
