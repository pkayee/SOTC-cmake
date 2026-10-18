#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", GetLwsOrientWorkSize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", func_40090748);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", InitLwsOrientObj);

typedef struct {
    int type;
    int unused[2];
} Node;

typedef struct {
    char pad[16];
    Node *nodes;
    int count;
} Root;

int IsLwsOrientRootNode(Root *root)
{
    Node *nodes;
    int i;
    int found = 0;
    int *type;
    for (i = 0; i < root->count; i++) {
        nodes = root->nodes;
        type = &nodes[i].type;
        if (*type == 14) {
            found = 1;
            break;
        }
    }
    return found;
}

int GetLwsOrientNodeNum(Root *orient)
{
    int count = orient->count;
    int found = 0;
    int i;
    for (i = 0; i < count; ++i) {
        int offset = ((i << 1) + i) << 2;
        Node *node = (Node *)((char *)orient->nodes + offset);
        if (node->type == 14) {
            found = 1;
            break;
        }
    }
    return count - found;
}

extern int getAnimObjResource();

int GetLwsOrientInitMotionPtr(char *p, int a)
{
    return getAnimObjResource(*(char **)(p + 0x7C) + 0x50, a);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", GetMotKToMotP);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", ExecScriptLwsOrientClass);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", func_40091068);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0108_GetLwsOrientWorkSize", func_40091258);
