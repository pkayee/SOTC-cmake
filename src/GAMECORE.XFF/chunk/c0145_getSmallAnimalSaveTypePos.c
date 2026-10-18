#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", getSmallAnimalSaveTypePos);

extern char D_40216E10[];
extern void func_400C2B60(void *, int, int);
extern void func_400C4A98(void *);

void initSmallManager(void)
{
    char *m = D_40216E10;
    func_400C2B60(m, 10, 0);
    func_400C2B60(m + 0x9E0, 20, 1);
    *(int *)(m + 0x13CC) = 0;
    *(int *)(m + 0x13D0) = 0;
}

void terminateSmallManager(void)
{
    char *m = D_40216E10;
    func_400C4A98(m);
    func_400C4A98(m + 0x9E0);
}

typedef struct {
    int id;
    int sub;
    char pad[0x58];
} SObjNode;

typedef struct {
    char pad[0x250];
    SObjNode node[20];
    int n;
    char pad2[0xC];
} SObjSet;

extern char D_402177F0[];

SObjNode *getSObjNode(int id)
{
    int j, i;
    for (j = 0; j < 2; j++) {
        SObjSet *s = (SObjSet *)(j == 0 ? D_40216E10 : D_402177F0);
        for (i = 0; i < s->n; i++) {
            if (id == s->node[i].id)
                return &s->node[i];
        }
    }
    return 0;
}

SObjNode *getSObjNodeBySubObj(int id)
{
    int j, i;
    for (j = 0; j < 2; j++) {
        SObjSet *s = (SObjSet *)(j == 0 ? D_40216E10 : D_402177F0);
        for (i = 0; i < s->n; i++) {
            if (id == s->node[i].sub)
                return &s->node[i];
        }
    }
    return 0;
}

void setSObjNodeLock(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x54)) = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", deleteRequestSObjNode);

extern void iosGetClock(void *);
extern long iosGetClockSecond(void *);
extern void _gameWorkSet(int, int);

void setTailCutTime(void)
{
    char clk[16] __attribute__((aligned(16)));
    long t;
    int hi, lo;

    iosGetClock(clk);
    t = iosGetClockSecond(clk);
    lo = t & 0xFFFFFFFF;
    hi = t >> 32;
    _gameWorkSet(9, hi);
    _gameWorkSet(10, lo);
}

extern int D_402181E0;

void setSmallManagerSystemLock(int arg0)
{
    D_402181E0 = arg0;
}

typedef struct {
    char *obj;
    char pad4[0x18];
} AnimalEnt;

typedef struct {
    int num;
    char pad4[0x14];
    AnimalEnt ent[1];
} AnimalTable;

extern int perceptionExec(void *, void *, float *, void *);

char *getNearInterestSmallAnimal(void *a, void *b)
{
    float buf[4];
    AnimalTable *t = (AnimalTable *)D_40216E10;
    int i;
    char *o;

    for (i = 0; i < t->num; i++) {
        o = t->ent[i].obj;
        if (o != 0 && perceptionExec(a, b, buf, o + 0x20))
            return o;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C49A0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4A98);
extern void func_400C2A98(void *);

void func_400C4A98(void *arg0)
{
    int i = 0x13;
    char *p = (char *)arg0 + 0x250;
    do {
        i--;
        func_400C2A98(p);
        p += 0x60;
    } while (i >= 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4AE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4B08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4BC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4C20);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4C60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4CA0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4D10);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4D60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4E08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5028);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5268);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C53B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5C70);
