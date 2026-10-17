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


/* NEARMISS-STUB func_40018D88 */
#if 0 /* NEARMISS 17.0% cat=branch-layout sub=- | structural: target has early bnezl/beql exits and fewer blocks, ours restructures the loop; 17 pct, needs control-flow rewrite | attempts=2 */
s32 func_40018D88(ShockNode* arg0, s32 arg1)
{
    s32 ret = 0;
    u8* base;
    s32 dur;
    u16 pc;
    s32 op;
    s32 low;
    s32 lvl;
    s32 tgt;
    s32 diff;
    s32 counter;
    s32 hi;
    s32 d;
    s32 rem;

    if (!(arg0->unk0 & 0x1))
    {
        return ret;
    }
    base = arg0->unk4;
    if (base == NULL)
    {
        arg0->unk0 &= 0xFE;
        return ret;
    }
    pc = arg0->unk8;
    dur = arg0->unk12;

L_check:
    op = base[pc];
    if ((u16)dur != 0)
    {
        goto L_counter;
    }

L_dispatch:
    if (op == 0x80)
    {
        arg0->unk0 &= 0xFE;
        return ret;
    }
    if (!(op & 0x80))
    {
        lvl = arg0->unkA + (op & 0x3F);
        arg0->unkA = lvl;
        counter = arg0->unk10;
        arg0->unkC = counter;
        tgt = (arg0->unk3 * lvl) >> 6;
        arg0->unkE = tgt;
        diff = tgt - counter;
        arg0->unk12 = diff;
        dur = diff;
        if ((s16)diff <= 0)
        {
            arg0->unkE = counter + 1;
            arg0->unk12 = 1;
            dur = 1;
        }
    }
    else
    {
        low = op & 0x3F;
        switch (low)
        {
        case 1:
            pc = pc + (s8)base[pc + 1];
            arg0->unk8 = pc;
            break;
        case 2:
            arg0->unk26 = base[pc + 1];
            pc += 2;
            arg0->unk8 = pc;
            break;
        case 3:
            if (arg0->unk26 == 0)
            {
                pc += 2;
            }
            else
            {
                arg0->unk26--;
                pc = pc + (s8)base[pc + 1];
            }
            arg0->unk8 = pc;
            break;
        case 0x3F:
            pc = pc + (s8)base[pc + 1] + 2;
            arg0->unk8 = pc;
            if (arg1 != 0)
            {
                ((void (*)(ShockNode*, u8*))arg1)(arg0, base + pc);
                base = arg0->unk4;
                pc = arg0->unk8;
                dur = arg0->unk12;
            }
            break;
        default:
            break;
        }
    }
    goto L_check;

L_counter:
    counter = (u16)(arg0->unk10 + 1);
    arg0->unk10 = counter;
    op = base[pc];
    if (op & 0x40)
    {
        hi = arg0->unk2;
        if (hi & 0x80)
        {
            d = (hi >> 4) - 5;
            if (d != 0)
            {
                rem = (s16)counter % d;
                if (rem != 0)
                {
                    ret = 1;
                }
                else
                {
                    ret = ((hi >> 4) == 0xF);
                }
            }
        }
        else
        {
            d = 9 - (hi >> 4);
            rem = (s16)counter % d;
            ret = (rem == 0);
        }
    }
    if ((s16)counter < (s32)(u16)arg0->unkE)
    {
        return ret;
    }
    arg0->unk12 = 0;
    pc = pc + 1;
    arg0->unk8 = pc;
    if (base[pc] == 0x80)
    {
        arg0->unk0 &= 0xFE;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", func_40018D88);

/* NEARMISS-STUB func_40019018 */
#if 0 /* NEARMISS 43.9% cat=branch-layout sub=- | control flow shape differs (target branch-likely beql/bnezl chains around s3=0x80 compare; ours extra blocks); 43.9 pct | attempts=2 */
s32 func_40019018(ShockNode* arg0, s32 arg1)
{
    s32 ret = 0;
    u8* base;
    u16 pc;
    s32 dur;
    s32 op;
    s32 low;
    s32 lvl;
    s32 tgt;
    s32 diff;
    s32 counter;
    s32 step;
    s32 mix;
    s32 cnt = 0;
    s32 sum = 0;

    if (!(arg0->unk0 & 0x10))
    {
        return ret;
    }
    base = arg0->unk14;
    if (base == NULL)
    {
        arg0->unk0 &= 0xEF;
        return ret;
    }
    pc = arg0->unk18;
    dur = (s16)arg0->unk22;

    for (;;)
    {
        if (dur == 0)
        {
            op = base[pc];
            if (op == 0x80)
            {
                arg0->unk0 &= 0xEF;
                return ret;
            }
            if (op & 0x80)
            {
                low = op & 0x3F;
                switch (low)
                {
                case 1:
                    arg0->unk27 = base[pc + 1];
                    pc += 2;
                    arg0->unk18 = pc;
                    break;
                case 0:
                    pc = pc + (s8)base[pc + 1];
                    arg0->unk18 = pc;
                    break;
                case 2:
                    if (arg0->unk27 == 0)
                    {
                        pc += 2;
                    }
                    else
                    {
                        arg0->unk27--;
                        pc = pc + (s8)base[pc + 1];
                    }
                    arg0->unk18 = pc;
                    break;
                case 0x3F:
                    arg0->unk8 = arg0->unk8 + (s8)base[pc + 1] + 2;
                    if (arg1 != 0)
                    {
                        ((void (*)(ShockNode*, u8*))arg1)(arg0, base + pc);
                        base = arg0->unk14;
                        pc = arg0->unk18;
                        dur = (s16)arg0->unk22;
                    }
                    break;
                default:
                    break;
                }
                continue;
            }

            step = op & 0x3F;
            lvl = arg0->unk1A + step;
            arg0->unk25 = base[pc + 1];
            counter = arg0->unk20;
            arg0->unk1C = counter;
            arg0->unk1A = lvl;
            tgt = (arg0->unk3 * lvl) >> 6;
            arg0->unk1E = tgt;
            diff = tgt - counter;
            arg0->unk22 = diff;
            if ((s16)diff > 0)
            {
                if (cnt == 0)
                {
                    dur = diff;
                }
                else
                {
                    pc -= 2;
                    arg0->unk18 = pc;
                    arg0->unk1E = counter + 1;
                    arg0->unk1A = lvl - step;
                    dur = 1;
                    arg0->unk22 = 1;
                    arg0->unk25 = sum / cnt;
                    sum = 0;
                    cnt = 0;
                }
            }
            else
            {
                pc += 2;
                arg0->unk18 = pc;
                cnt++;
                sum += arg0->unk25;
                arg0->unk22 = 0;
                dur = 0;
            }
            if (dur == 0)
            {
                continue;
            }
        }

        counter = (u16)(arg0->unk20 + 1);
        arg0->unk20 = counter;
        mix = arg0->unk24 * (arg0->unk1E - (s16)counter) + arg0->unk25 * ((s16)counter - arg0->unk1C);
        ret = ((mix / dur) * arg0->unk2) / 0xFF;
        if ((s16)counter < (s32)arg0->unk1E)
        {
            return ret;
        }
        pc += 2;
        arg0->unk18 = pc;
        arg0->unk24 = arg0->unk25;
        arg0->unk22 = 0;
        if (base[pc] == 0x80)
        {
            arg0->unk0 &= 0xEF;
        }
        return ret;
    }
}
#endif
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


/* NEARMISS-STUB Shock_Request */
#if 0 /* NEARMISS 75.0% cat=inline-unroll sub=- | static inline GetShockVoiceSet/GetShockData: ours loads D_40045818 and table count early and reuses a5; target loads table/count later, index shift order differ | attempts=2 */
static inline ShockVoiceSet* Shock_GetShockVoiceSet(u32 id)
{
    ShockVoiceSet* ret = NULL;
    if (id < D_40045818->count)
    {
        ret = D_40045818->table[id];
    }
    return ret;
}

static inline u32* Shock_GetShockData(ShockVoiceSet* set, u32 no)
{
    u32* ret = NULL;
    if (set != NULL && no < set->hdr->unk8)
    {
        ret = set->unkC + no;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/shock", Shock_Request);
ShockObj* Shock_Request(void* arg0, u32 arg1, ShockParam arg2, s32 arg3, s32 arg4)
{
    u32* ptr;
    ShockObj* ret;

    ptr = Shock_GetShockData(Shock_GetShockVoiceSet(arg2.set), arg1);
    if (ptr == NULL)
    {
        return NULL;
    }
    ret = func_400192E0(arg0, ptr, arg2, arg3, arg4);
    if (ret != NULL)
    {
        ret->unk3C = ptr;
    }
    return ret;
}
#endif
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


/* NEARMISS-STUB Shock_SetMotor */
#if 0 /* NEARMISS 97.59% cat=regalloc sub=alloc-priority | register choice (decomper2 notes); best 97.59 attempts stored | attempts=2 */
void Shock_SetMotor(s32 arg0, s32 arg1, ShockCtrl* arg2, s32 arg3, s32 arg4)
{
    s32 prev = arg2->unk0;
    s32 m1 = arg1 & 0xFF;
    s32 m0 = arg0 & 0xFF;
    s32 diff = m1 - prev;
    s32 val = m1;
    s32 t;
    s32 n;
    s32 cur;
    u8 v8;

    if (diff > 0)
    {
        if (diff < 0x29)
        {
            if (m1 < 0x3D && prev < 0x3D)
            {
                if (prev < 0x33)
                {
                    val = 0xFF;
                    goto L;
                }
                t = 0x3C - m1;
                t = (t * t * 0xFF) / 100;
            }
            else
            {
                t = (diff * 0xFF) / 0x28;
            }
            if (prev < t)
            {
                val = t;
            }
        }
        else
        {
            val = 0xFF;
        }
    }
    else if (diff < 0)
    {
        val = 0;
        if (diff >= -0x1E)
        {
            t = 0xFF + (diff * 0xFF) / 0x1E;
            val = (t < prev) ? t : m1;
        }
    }
L:
    v8 = val;
    n = (u16)arg2->unk2 + v8;
    arg2->unk2 = n;
    n = (s16)n;
    if (n > 0x40A)
    {
        arg2->unk2 = 0x40A;
    }
    else if (n < 0)
    {
        arg2->unk2 = 0;
    }
    cur = arg2->unk2;
    t = (u32)(cur << 8) / 0x40B;
    arg2->unk4 = m0;
    arg2->unk5 = v8;
    arg2->unk0 = t;
    arg2->unk2 = (u32)(cur * 3) >> 2;
}
#endif
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

