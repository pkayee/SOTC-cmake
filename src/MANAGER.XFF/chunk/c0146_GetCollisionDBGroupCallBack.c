#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", GetCollisionDBGroupCallBack);

extern int func_400AB528();

int GetCollisionDBLastPointOnCurrentPlane(int a, int b, int c)
{
    return func_400AB528(a, b, c, 1);
}

typedef struct
{
    u64 attr;
    s64 pad;
} CollAttr;

typedef struct
{
    u8 pad[0x30];
    s32 n;
    CollAttr *a;
} CollRes;

void ChangeCollisionResourceAttribute(CollRes *r, u64 m1, u64 v1, u64 m2, u64 v2, u64 clr, u64 set)
{
    s32 i = r->n;
    CollAttr *p = r->a;

    while (--i != -1)
    {
        u64 v = p->attr;

        if ((v & m1) == v1 && (v & m2) == v2)
        {
            p->attr = (v & ~clr) | set;
        }
        p++;
    }
}

s32 GetCollisionResource(void *arg0)
{
    return *(s32 *)((u8 *)(*(void **)((u8 *)(arg0) + 8)) + 0x20);
}

extern int objfilter(int a, int b);
extern int func_400B5E28();
extern int GetRayVolumeUncollisionPoint(int, int, int, int, int, void *, int, int, void *, int);

int GetRayVolumeUncollisionPointForCamera(int a, int b, int c, int d, int e, int f)
{
    return GetRayVolumeUncollisionPoint(a, b, c, d, e, objfilter, 0, 0, func_400B5E28, f);
}

s32 CollisionObjectJudgeCallbackExceptOneObj(s32 arg0, s32 arg1)
{
    return arg0 != arg1;
}

/* NEARMISS-STUB CollisionObjectJudgeCallbackExceptDescendOneObj */
#if 0 /* NEARMISS 70.37% cat=regalloc sub=- | loop ptr reg/branch layout: target keeps p in a0, obj in v0; arg1 check branch inverted | attempts=1 */
extern u8 *GetLayoutClass();
extern u8 *GetLayoutParentObj(u8 *);

s32 CollisionObjectJudgeCallbackExceptDescendOneObj(s32 arg0, s32 arg1)
{
    s32 ret;
    s32 obj;
    s32 p;

    ret = 1;
    if (arg1 == 0)
    {
        return ret;
    }
    p = arg0;
    while (p != 0)
    {
        ret = 0;
        if (p == arg1)
        {
            return ret;
        }
        obj = (s32)GetLayoutClass(p);
        if (obj == 0)
        {
            p = 0;
        }
        else
        {
            p = *(s32 *)(obj + 0x194);
            if (p == 0)
            {
                p = (s32)GetLayoutParentObj(obj);
            }
        }
        ret = 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", CollisionObjectJudgeCallbackExceptDescendOneObj);

typedef struct
{
    s32 a;
    s32 b[5];
} CollJudgeCallbackData;

void ConstructorCollisionObjectJudgeCallbackData(CollJudgeCallbackData *p)
{
    s32 i;

    p->a = 0;
    for (i = 4; i >= 0; i--)
    {
        p->b[i] = 0;
    }
}

s32 CollisionObjectJudgeCallbackExceptPluralObj(s32 obj, s32 *list)
{
    s32 i;

    for (i = 0; i < list[0]; i++)
    {
        if (obj == list[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

/* NEARMISS-STUB CollisionObjectJudgeCallbackExceptDescendPluralObj */
#if 0 /* NEARMISS 95.75% cat=regalloc sub=- | control flow matches with a static inline (target!=0 && p!=0 guard + do-while, if(cls==NULL) p=0 else ...); only cls lands in v1 (+move a0) where the target kee | attempts=1 */
static inline s32 collisionJudgeNotDescend(s32 p, s32 target)
{
    u8 *cls;

    if (target != 0 && p != 0)
    {
        do
        {
            if (p == target)
            {
                return 0;
            }
            cls = GetLayoutClass(p);
            if (cls == NULL)
            {
                p = 0;
            }
            else
            {
                p = *(s32 *)(cls + 0x194);
                if (p == 0)
                {
                    p = (s32)GetLayoutParentObj(cls);
                }
            }
        } while (p != 0);
    }
    return 1;
}
s32 CollisionObjectJudgeCallbackExceptDescendPluralObj(s32 obj, s32 *list)
{
    s32 i;

    for (i = 0; i < list[0]; i++)
    {
        if (!collisionJudgeNotDescend(obj, list[i + 1]))
        {
            return 0;
        }
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", CollisionObjectJudgeCallbackExceptDescendPluralObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", DebugDispCollisionDBColor);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", CheckCollisionInsideOfObjectBoundary);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", getBossDBInfo);

extern unsigned char D_4012B32C[];

void *getVolumeCollisionDebugMode(void)
{
    return D_4012B32C;
}

extern unsigned char D_4012B330[];

void *getCollisionDebugGraphMode(void)
{
    return D_4012B330;
}

extern unsigned char D_4012B334[];

void *getCollisionVirtualWallDispFlag(void)
{
    return D_4012B334;
}

typedef struct
{
    s32 idx : 31;
    s32 leaf : 1;
} CollTreeChild;

typedef struct
{
    s32 axis;
    float split;
    CollTreeChild child[2];
} CollTreeNode;

void func_400BB870(float *pos, u8 *tree, s32 idx, void (*cb)(u8 *q, u8 *tree, s32 idx), u8 *q)
{
    CollTreeNode *n = &(*(CollTreeNode **)(tree + 8))[idx];
    float r = pos[3];
    float p = pos[n->axis];

    if (p <= n->split * *(float *)(q + 0x10) + r)
    {
        if (n->child[0].leaf)
        {
            cb(q, tree, n->child[0].idx);
        }
        else
        {
            func_400BB870(pos, tree, n->child[0].idx, cb, q);
        }
    }
    if (n->split * *(float *)(q + 0x10) - r <= p)
    {
        if (n->child[1].leaf)
        {
            cb(q, tree, n->child[1].idx);
        }
        else
        {
            func_400BB870(pos, tree, n->child[1].idx, cb, q);
        }
    }
}

typedef struct
{
    float split;
    u32 axis : 2;
    u32 left : 14;
    u32 leftLeaf : 1;
    u32 right : 14;
    u32 rightLeaf : 1;
} CollTreeNode2;

void func_400BB998(float *pos, u8 *tree, s32 idx, void (*cb)(u8 *q, u8 *tree, s32 idx), u8 *q)
{
    CollTreeNode2 *n = &(*(CollTreeNode2 **)(tree + 8))[idx];
    float r = pos[3];
    float p = pos[n->axis];

    if (p <= n->split * *(float *)(q + 0x10) + r)
    {
        if (n->leftLeaf)
        {
            cb(q, tree, n->left);
        }
        else
        {
            func_400BB998(pos, tree, n->left, cb, q);
        }
    }
    if (n->split * *(float *)(q + 0x10) - r <= p)
    {
        if (n->rightLeaf)
        {
            cb(q, tree, n->right);
        }
        else
        {
            func_400BB998(pos, tree, n->right, cb, q);
        }
    }
}

void func_400BBAC8(float *pos, u8 *tree, s32 idx, void (*cb)(u8 *q, u8 *tree, s32 idx), u8 *q)
{
    CollTreeNode2 *n = &(*(CollTreeNode2 **)(tree + 8))[idx];
    float r = pos[3];
    float p = pos[n->axis];

    if (p <= n->split * *(float *)(q + 0x10) + r)
    {
        if (n->leftLeaf)
        {
            cb(q, tree, n->left);
        }
        else
        {
            func_400BBAC8(pos, tree, n->left, cb, q);
        }
    }
    if (n->split * *(float *)(q + 0x10) - r <= p)
    {
        if (n->rightLeaf)
        {
            cb(q, tree, n->right);
        }
        else
        {
            func_400BBAC8(pos, tree, n->right, cb, q);
        }
    }
}

s32 GetColMultiDepVtxInfoVertexNormal(void *arg0, void *arg1)
{
    s32 temp_a1;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((char *)(arg1) + 0));
    temp_a1 = (*(s32 *)((char *)(arg1) + 4));
    if (temp_v1 != -1) {
        return (*(s32 *)((char *)(((temp_v1 * 0x60) + (*(s32 *)((char *)((*(void **)((char *)(arg0) + 0x174))) + 0x24)))) + 0x2C)) + (temp_a1 * 0x10);
    }
    return (*(s32 *)((char *)((*(void **)((char *)(arg0) + 0x174))) + 0x54)) + (temp_a1 * 0x10);
}

void GetColMultiDepVtxInfoVertexNormalWork(void *arg0, void *arg1, void *arg2)
{
    int temp_a2;

    temp_a2 = (*(int *)((char *)(arg2) + 0));
    (*(int *)((char *)(arg0) + 0)) = (int) (*(int *)((char *)(arg2) + 4));
    if (temp_a2 != -1) {
        (*(void **)((char *)(arg0) + 4)) = (void *) ((*(int *)((char *)((*(void **)((char *)(arg1) + 0x174))) + 0x24)) + (temp_a2 * 0x60) + 0x18);
        return;
    }
    (*(void **)((char *)(arg0) + 4)) = (void *) ((*(void **)((char *)(arg1) + 0x174)) + 0x40);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", iasmCalcCollisionMultiDepSurfBoundarySub);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0146_GetCollisionDBGroupCallBack", CalcCollisionMultiDepSurfBoundary);
