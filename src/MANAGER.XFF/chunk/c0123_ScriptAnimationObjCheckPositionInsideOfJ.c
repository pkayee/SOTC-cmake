#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", ScriptAnimationObjCheckPositionInsideOfJudgeVolumeObject);

typedef struct {
    char pad0[0x40];
    float scale_y;
    float scale_x;
    float scale_z;
    char pad4C[0x14];
    float v60[4];
    float v70[4];
    char pad80[0x10];
    float v90[4];
    char padA0[0x94];
    int unk134;
    int *unk138;
    int unk13C;
} LayoutClass;

extern LayoutClass *GetLayoutClass(int);
extern void SetJudgeVolumeInfo(int, int, int, int, float *, float *, float *, float, float, float);

int ScriptAnimationObjOfJudgeVolumeObject(int arg0, int id)
{
    LayoutClass *layout = GetLayoutClass(id);

    if (layout == 0) {
        return 0;
    }
    SetJudgeVolumeInfo(arg0, *layout->unk138, layout->unk134, layout->unk13C, layout->v90, layout->v70,
                       layout->v60, layout->scale_x, layout->scale_y, layout->scale_z);
    return 1;
}

typedef struct {
    int type;
    int words[2];
} SubObjectType;

typedef struct {
    void *object;
    int value;
} SubObject;

typedef struct {
    int count;
    char pad[0x14];
    SubObjectType *types;
} AnimationResource;

typedef struct {
    char pad[0x328];
    AnimationResource *resource;
    char pad32c[0xc];
    SubObject *children;
} ScriptAnimation;

void GetScriptAnimationSubObjectWithTypeFiltering(unsigned char *object, int type, void (*callback)(void *, void *), void *context)
{
    ScriptAnimation *animation = object[8] == 13 ? (ScriptAnimation *)(object + 0x20) : 0;
    AnimationResource *resource = animation->resource;
    SubObject *child = animation->children;
    SubObjectType *entry = resource->types;
    int remaining;

    for (remaining = resource->count; --remaining != -1; ++entry, ++child) {
        if ((type < 0 || entry->type == type) && child->object != 0) {
            callback(child->object, context);
        }
    }
}

void SetScariptAnimationObjMotSyncSlotId(unsigned char *p, int a)
{
    char *c = p[8] != 0xD ? 0 : (char *)p + 0x20;

    *(int *)(c + 0x360) = a;
}

typedef union {
    float values[4];
    long words[2];
} DebugColor;

extern DebugColor D_401338D0;
extern void DebugDispVolumeShapeColor(void *, float *);

void DebugDispVolumeShape(void *shape)
{
    DebugColor color = D_401338D0;

    DebugDispVolumeShapeColor(shape, color.values);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", DebugDispVolumeAll);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", DebugDispVolumeAllColor);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", DeleteAllActiveScriptAnimationObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A08A0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A09A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0A40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0AD8);

extern unsigned char D_4012B1D4[];

void *getLWSDebugMode2(void)
{
    return D_4012B1D4;
}

extern unsigned char D_4012B1D8[];

void *getExternalLWSFlag(void)
{
    return D_4012B1D8;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0B40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0CB8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0D18);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0D38);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0E48);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0F78);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A10A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A10E8);
