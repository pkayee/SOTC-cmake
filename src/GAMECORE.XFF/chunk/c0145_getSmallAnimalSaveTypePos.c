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

/* NEARMISS-STUB func_400C4AE0 */
#if 0 /* NEARMISS 86.5% cat=branch-layout sub=- | store order: target sh 0x50 in jr delay slot; ours hoists it after first store (scheduler); one -1 reg matches | attempts=1 */
void func_400C4AE0(void *arg0)
{
    int m = -1;
    int *p = (int *)arg0;
    short *h = (short *)arg0;
    p[0] = 0;
    h[0x52 / 2] = m;
    p[1] = 0;
    p[2] = 0;
    p[3] = m;
    p[4] = 0;
    p[0x15] = 0;
    h[0x50 / 2] = m;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4AE0);
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4B08);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4BC0);
extern char SH_SmallAnimalTypeDEFAULT[];

int func_400C4BC0(void *arg0)
{
    int base = *(int *)(SH_SmallAnimalTypeDEFAULT + 0x10);
    if (*(int *)((char *)arg0 + 0x10) != 0) {
        return base + (*(short *)((char *)arg0 + 0x34) * 13) * 4 + 8;
    }
    return base + (*(short *)((char *)arg0 + 0x34) * 13) * 4 + 4;
}

int func_400C4C20(char *p, int arg1)
{
    p = *(char **)(p + 0x14);
    while (p != 0) {
        if (arg1 == *(int *)(p + 0xc)) return 1;
        p = *(char **)(p + 0x58);
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4C60);
int func_400C4C60(void *arg0)
{
    int count = 0;
    int n = *(int *)((char *)arg0 + 0x10);
    int i;
    char *p = *(char **)((char *)arg0 + 0x14);
    if (n > 0) {
        i = n;
        do {
            int v = *(int *)(p + 0x54);
            int c1 = count + 1;
            i--;
            p = *(char **)(p + 0x58);
            if (v != 0) {
                count = c1;
            }
        } while (i != 0);
    }
    return count;
}

/* NEARMISS-STUB func_400C4CA0 */
#if 0 /* NEARMISS 64.96% cat=regalloc sub=- | induction vars swapped: target countdown n in a3, offset a2; ours a4; count reload CSE'd; reg order off | attempts=1 */
typedef struct {
    int id;
    int cnt;
    char *head;
    char pad[0x14];
} SmallEnt;

typedef struct {
    int n;
    char pad[0xc];
    SmallEnt ent[1];
} SmallTable;

int func_400C4CA0(SmallTable *arg0)
{
    int count = 0;
    int n = arg0->n;
    int i;
    int k;
    int j;
    char *node;
    SmallEnt *e;
    if (n > 0) {
        i = n;
        k = 0;
        e = arg0->ent;
        do {
            if (arg0->ent[k].cnt > 0) {
                node = arg0->ent[k].head;
                j = e->cnt;
                do {
                    int c1 = count + 1;
                    int v = *(int *)(node + 0x54);
                    j--;
                    node = *(char **)(node + 0x58);
                    if (v != 0) {
                        count = c1;
                    }
                } while (j != 0);
            }
            i--;
            k++;
            e++;
        } while (i != 0);
    }
    return count;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4CA0);

/* NEARMISS-STUB func_400C4D10 */
#if 0 /* NEARMISS 68.0% cat=regalloc sub=- | loop shape differs: target walks ptr with id load in bnel delay slot, ours reorders ret/ptr regs; first insn mismatch | attempts=1 */
char *func_400C4D10(char *arg0, int arg1)
{
    char *ret = 0;
    if (arg1 != -1) {
        char *p = *(char **)(arg0 + 0x23C);
        if (p != 0) {
            do {
                if (arg1 == *(int *)(p + 0xC)) {
                    ret = p;
                    break;
                }
                p = *(char **)(p + 0x58);
            } while (p != 0);
        }
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4D10);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4D60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C4E08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5028);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5268);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C53B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0145_getSmallAnimalSaveTypePos", func_400C5C70);
