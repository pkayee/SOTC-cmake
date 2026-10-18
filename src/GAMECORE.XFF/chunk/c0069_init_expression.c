#include "common.h"

typedef struct {
    int id;
    int x4;
    int x8;
    union {
        int i;
        float f;
    } xC;
    char interp0[0xC];
    char interp1[0xC];
    char interp2[0xC];
    int x34;
} ExprNode;

typedef struct {
    char pad0[0x9C];
    int n;
    ExprNode node[30];
} ExprWork;

extern void GAMEUTIL_reset_interp_value_cntrl(void *, float);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", init_expression);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", doit_expression);

static inline void resetInterp(void *p)
{
    GAMEUTIL_reset_interp_value_cntrl(p, 0.0f);
}

/* Each access recomputes the node address, which gives the original
   (n * size) + w operand order. */
#define NODE (&w->node[n])

void add_node_expression(ExprWork *w, int id)
{
    int n = w->n;

    if (n >= 30)
        return;
    NODE->xC.i = 0;
    NODE->id = 0;
    NODE->x8 = 0;
    NODE->x4 = 0;
    GAMEUTIL_reset_interp_value_cntrl(NODE->interp0, NODE->xC.f);
    resetInterp(NODE->interp1);
    resetInterp(NODE->interp2);
    NODE->x34 = 0;
    NODE->id = id;
    w->n++;
}

extern int GAMEUTIL_doit_status_manager();

int update_type_expression(int a, int b, int c, int d)
{
    return GAMEUTIL_doit_status_manager(a + 4, b, 0, d);
}

void set_root_node_data_expression(int arg0, float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    void *temp_a0;

    temp_a0 = (void *)(arg0 + 0x34);
    (*(float *)((char *)(temp_a0) + 0x40)) = fparg5;
    (*(float *)((char *)(temp_a0) + 4)) = fparg0;
    (*(float *)((char *)(temp_a0) + 8)) = fparg1;
    (*(float *)((char *)(temp_a0) + 0xC)) = fparg2;
    (*(float *)((char *)(temp_a0) + 0x38)) = fparg3;
    (*(float *)((char *)(temp_a0) + 0x3C)) = fparg4;
    (*(int *)((char *)(temp_a0) + 0x34)) = 0;
}

void set_node_data_expression(ExprWork *w, int id, int mode, float x, float y, float z)
{
    ExprNode *e;
    int n;
    int i;

    if (id == 0) {
        return;
    }
    n = w->n;
    i = 0;
    if (n > 0) {
        e = w->node;
        do {
            if (e->id == id) {
                *(float *)&e->x4 = x;
                *(float *)&e->x8 = y;
                e->xC.f = z;
                e->x34 = mode;
                return;
            }
            i++;
            e++;
        } while (i < n);
    }
}

extern int GAMEUTIL_get_cur_status_status_manager();

int get_cur_type_expression(int a, int b, int c, int d)
{
    return GAMEUTIL_get_cur_status_status_manager(a + 4, b, c, d);
}

extern int GAMEUTIL_get_pre_changed_status_status_manager();

int get_pre_type_expression(int a, int b, int c, int d)
{
    return GAMEUTIL_get_pre_changed_status_status_manager(a + 4, b, c, d);
}

extern int GAMEUTIL_get_interp_ratio_interp_ratio_cntrl();

int GAMEUTIL_get_cur_interp_ratio_expression(int a, int b, int c, int d)
{
    return GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(a + 20, b, c, d);
}

typedef struct {
    int type;
    float start;
    float end;
    int time;
    float speed;
    int flag;
} ExpressionChangeEntry;

typedef struct {
    int count;
    ExpressionChangeEntry entries[5];
} ExpressionChange;

void constructor_expression_change(ExpressionChange *self)
{
    ExpressionChangeEntry *entry = self->entries;
    int i;

    self->count = 0;
    for (i = 4; i >= 0; --i, ++entry) {
        entry->type = 0;
        entry->start = 0.0f;
        entry->speed = 0.0f;
        entry->end = 0.0f;
        entry->flag = 0;
        entry->time = 0;
    }
}

/* NEARMISS-STUB add_element_expression_change */
#if 0 /* NEARMISS 100.0% cat=-alias sub=- | 100 only with list ptr and casts on every store (rule 13 REVIEW) | attempts=1 */
void add_element_expression_change(int *list, int type, int time, int flag, float start, float end, float speed)
{
    int count;
    void *base;
    void *element;

    count = *list;
    base = (void *)((count * 0x18) + (int)list);
    if (count < 5) {
        element = base + 4;
        (*(int *)((char *)(element) + 0x14)) = flag;
        (*(int *)((char *)(base) + 4)) = type;
        (*(float *)((char *)(element) + 4)) = start;
        (*(float *)((char *)(element) + 8)) = end;
        (*(int *)((char *)(element) + 0xC)) = time;
        (*(float *)((char *)(element) + 0x10)) = speed;
        *list += 1;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", add_element_expression_change);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", doit_expression_change);

extern void *isysGetThisSubThread(void);
extern char *GetLayoutClass(void *);
extern void scrRunM(int);

void fallenRockMain(s128 *p)
{
    char *l = GetLayoutClass(isysGetThisSubThread());
    for (;;) {
        if (((int *)p)[4] != 0)
            **(s128 **)(l + 0x134) = *p;
        scrRunM(1);
    }
}

typedef struct {
    s128 pos;
    int flag;
} RockWork;

extern u8 rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScrLwsOriClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern char *GetLayoutClass(void *);
extern void scrRunM(int);

void fallenRockStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x53);
    char *c;
    RockWork *w;
    char *l;

    *(int *)(GetScrLwsOriClass(th) + 0x1154) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScrLwsOriClass(th);
    w = (RockWork *)_SCRMallocAlign(part, 0x20, 0x10);
    *(RockWork **)(c + 0x1158) = w;
    w->flag = 0;
    scrRunM(2);
    w->pos = **(s128 **)(GetLayoutClass(th) + 0x134);
    l = GetLayoutClass(isysGetThisSubThread());
    for (;;) {
        if (w->flag != 0)
            **(s128 **)(l + 0x134) = w->pos;
        scrRunM(1);
    }
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_40064BF8(void *character);

void SCRRockFall(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40064BF8);
}

extern void func_40064C20(void *character);

void SCRRockReset(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40064C20);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40064BF8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40064C20);

void func_40064C20(void *character)
{
    void *temp_v0;

    temp_v0 = GetScrLwsOriClass(character);
    (*(int *)((char *)(*(int *)((char *)(temp_v0) + 0x1158)) + 0x10)) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40064C48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40064DB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40064FF0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40065298);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40065578);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_40065708);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0069_init_expression", func_400658B0);
