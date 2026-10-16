#include "common.h"

typedef struct ShockVoiceSetHdr
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
} ShockVoiceSetHdr;

typedef struct ShockVoiceSet
{
    /* 0x0 */ ShockVoiceSetHdr* hdr;
    /* 0x4 */ u32* unk4;
    /* 0x8 */ u32* unk8;
    /* 0xC */ u32* unkC;
} ShockVoiceSet;

typedef struct ShockTable
{
    /* 0x0 */ u32 count;
    /* 0x4 */ ShockVoiceSet** table;
    /* 0x8 */ s32 unk8;
} ShockTable;

typedef struct ShockPlayer
{
    /* 0x0 */ s32 unk0;
    /* 0x4 */ void* unk4;
    /* 0x8 */ void* unk8;
    /* 0xC */ void* unkC;
} ShockPlayer;

typedef struct ShockCtrl
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} ShockCtrl;

typedef struct ShockObj
{
    /* 0x0 */ u8 unk0[0x3C];
    /* 0x3C */ u32* unk3C;
} ShockObj;

typedef struct ShockNode
{
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x2F];
    /* 0x30 */ struct ShockNode* unk30;
    /* 0x34 */ struct ShockNode* unk34;
} ShockNode;

typedef struct ShockList
{
    /* 0x0 */ ShockNode* head;
    /* 0x4 */ u8 pad4[4];
    /* 0x8 */ void (*unk8)(ShockNode*, void*);
    /* 0xC */ void* unkC;
} ShockList;

extern ShockTable* D_40045818;
extern ShockTable D_40081590;
extern ShockVoiceSet* D_400815A0[2];
extern ShockPlayer D_400815A8;
extern u8 D_400815B0[16][0x40];

s32 func_40019958();
s32 func_40019960();
void func_400199A8(u8* arg0);
s32 func_40019018(ShockNode* arg0, s32 arg1);
s32 func_40018D88(ShockNode* arg0, s32 arg1);
ShockObj* func_400192E0(void* arg0, u32* arg1, s64 arg2);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40018D88);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40019018);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_400192E0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_ShockVoiceSet);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_Shock);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_SetShockVoiceSet);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_Player);
void Init_Player(ShockPlayer* arg0)
{
    void* a = func_40019960;
    void* b = func_400199A8;
    void* c = &D_400815A8;

    arg0->unk0 = 0;
    if (a)
    {
        arg0->unk4 = a;
    }
    else
    {
        arg0->unk4 = func_40019958;
    }
    arg0->unk8 = b;
    arg0->unkC = c;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_Controler);
void Init_Controler(ShockCtrl* arg0)
{
    arg0->unk2 = 0;
    arg0->unk0 = 0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_Request);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_Decode);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_SetMotor);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40019958);
s32 func_40019958()
{
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40019960);
s32 func_40019960(s32* arg0)
{
    s32 i;
    u8* p = (u8*)arg0[1];

    for (i = 0; i < arg0[0]; i++, p += 0x40)
    {
        if (*p == 0)
        {
            return (s32)p;
        }
    }
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_400199A8);
void func_400199A8(u8* arg0)
{
    *arg0 = 0;
}

