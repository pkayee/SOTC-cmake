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

typedef struct ShockParam
{
    /* 0x0 */ u8 set;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
} ShockParam;

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
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} ShockCtrl;

typedef struct ShockObj
{
    /* 0x0 */ u8 unk0[0x3C];
    /* 0x3C */ u32* unk3C;
} ShockObj;

typedef struct ShockNode
{
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8* unk4;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8* unk14;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ struct ShockNode* unk30;
    /* 0x34 */ struct ShockNode* unk34;
    /* 0x38 */ u8 unk38;
    /* 0x3C */ u32* unk3C;
} ShockNode;

typedef struct ShockList
{
    /* 0x0 */ struct ShockNode* head;
    /* 0x4 */ void* unk4;
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
ShockNode* func_400192E0(ShockList* arg0, u8* arg1, ShockParam arg2, s32 arg3, s32 arg4);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40018D88);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40019018);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_400192E0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_ShockVoiceSet);
void Init_ShockVoiceSet(ShockVoiceSet* arg0, ShockVoiceSetHdr* arg1)
{
    arg0->hdr = arg1;
    arg0->unkC = (u32*)arg1 + arg1->unkA;
    arg0->unk4 = (u32*)arg1 + arg1->unk2;
    arg0->unk8 = (u32*)arg1 + arg1->unk6;
}

static inline void Init_ShockTable(ShockTable* t, ShockVoiceSet** tbl, s32 n)
{
    s32 i;

    if (t != NULL && tbl != NULL)
    {
        t->table = tbl;
        t->count = n;
        D_40045818 = t;
        for (i = 0; i < n; i++)
        {
            D_40045818->table[i] = NULL;
        }
        D_40045818->unk8 = 0;
    }
}

static inline void Init_ShockPlayerBuf(ShockPlayer* p, u8 (*buf)[0x40], s32 n)
{
    s32 i;

    if (p != NULL && buf != NULL)
    {
        p->unk0 = n;
        p->unk4 = buf;
        for (i = 0; i < n; i++)
        {
            buf[i][0] = 0;
        }
    }
    else
    {
        p->unk0 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Init_Shock);
void Init_Shock(void)
{
    Init_ShockTable(&D_40081590, D_400815A0, 2);
    Init_ShockPlayerBuf(&D_400815A8, D_400815B0, 16);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_SetShockVoiceSet);
s32 Shock_SetShockVoiceSet(u32 id, ShockVoiceSet* vs)
{
    s32 ret = -1;
    if (id < D_40045818->count)
    {
        D_40045818->table[id] = vs;
        ret = id;
    }
    return ret;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_Decode);
void Shock_Decode(ShockList* arg0, u8* arg1, u8* arg2)
{
    s32 sum = 0;
    s32 flags = 0;
    ShockNode* n;
    ShockNode* p;

    if (arg0 != NULL)
    {
        n = arg0->head;
        if (n != NULL)
        {
            do
            {
                sum += func_40019018(n, D_40045818->unk8);
                flags |= func_40018D88(n, D_40045818->unk8);
                n = n->unk34;
            } while (n != NULL);
        }
        if (sum > 0xFF)
        {
            sum = 0xFF;
        }
        *arg2 = sum;
        *arg1 = flags;
        p = arg0->head;
        while (p != NULL)
        {
            if (p->unk0 == 0)
            {
                if (p->unk30 != NULL)
                {
                    p->unk30->unk34 = p->unk34;
                }
                else
                {
                    arg0->head = p->unk34;
                }
                n = p->unk34;
                if (n != NULL)
                {
                    n->unk30 = p->unk30;
                    n = p->unk34;
                }
                if (arg0->unk8 != NULL)
                {
                    arg0->unk8(p, arg0->unkC);
                }
                p = n;
            }
            else
            {
                p = p->unk34;
            }
        }
    }
}


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

