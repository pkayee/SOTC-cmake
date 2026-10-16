#include "common.h"

typedef struct
{
    void (*proc)(void);
    s32 count;
} Sg2TickEntry;

extern Sg2TickEntry D_400F8EC0[16];
extern s32 D_400F8F40;
extern s32 D_400F8F44;

void func_40030D00(void);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
s32 Sg2CtrlSetTickTime(s32 time);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlEntryTickProc);
s32 Sg2CtrlEntryTickProc(void (*proc)(void))
{
    s32 ret = -1;
    s32 intr = DIntr();
    s32 i;

    for (i = 0; i < 16; i++)
    {
        if (D_400F8EC0[i].proc == func_40030D00)
        {
            Sg2CtrlEntryTickProcById(i, proc);
            ret = 0;
            break;
        }
    }
    if (intr != 0)
    {
        EIntr();
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlEntryTickProcById);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void))
{
    if (D_400F8EC0[id].proc != func_40030D00) return -1;
    D_400F8EC0[id].proc = proc;
    D_400F8EC0[id].count = 0;
    return id;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlRemoveTickProc);
s32 Sg2CtrlRemoveTickProc(void (*proc)(void))
{
    s32 ret = -1;
    s32 intr = DIntr();
    s32 i;

    for (i = 0; i < 16; i++)
    {
        if (D_400F8EC0[i].proc == proc)
        {
            D_400F8EC0[i].count = 0;
            D_400F8EC0[i].proc = func_40030D00;
            ret = 0;
            break;
        }
    }
    if (intr != 0)
    {
        EIntr();
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlTickProc);
void Sg2CtrlTickProc(void)
{
    Sg2TickEntry *e = D_400F8EC0;
    s32 i;

    D_400F8F40++;
    for (i = 15; i >= 0; i--)
    {
        e->proc();
        e->count++;
        e++;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlSetTickMode);
s32 Sg2CtrlSetTickMode(s32 mode)
{
    s32 old = D_400F8F44;
    D_400F8F44 = mode;
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlGetTickMode);
s32 Sg2CtrlGetTickMode(void)
{
    return D_400F8F44;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlSetTickTime);
s32 Sg2CtrlSetTickTime(s32 time)
{
    s32 old = D_400F8F40;
    D_400F8F40 = time;
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlGetTickTime);
s32 Sg2CtrlGetTickTime(void)
{
    return D_400F8F40;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ctrl", Sg2CtrlInit);
s32 Sg2CtrlInit(void)
{
    s32 i;
    for (i = 0; i < 16; i++)
    {
        D_400F8EC0[i].proc = func_40030D00;
        D_400F8EC0[i].count = 0;
    }
    Sg2CtrlSetTickTime(0);
    return 0;
}
