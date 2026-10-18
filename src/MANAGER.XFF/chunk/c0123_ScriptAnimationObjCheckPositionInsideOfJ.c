#include "common.h"

/* NEARMISS-STUB ScriptAnimationObjCheckPositionInsideOfJudgeVolumeObject */
#if 0 /* NEARMISS 91.35% cat=stack-frame sub=- | frame 0x80 vs 0x30 from local; target movz sp-select, a0 copy in delay slot | attempts=1 */
extern void CheckPositionInsideOfJudgeVolumeInfo(int, int);

void ScriptAnimationObjCheckPositionInsideOfJudgeVolumeObject(int arg0, int id, int arg2)
{
    LayoutClass *layout;
    int local;
    int obj = arg0;

    layout = GetLayoutClass(id);
    if (obj == 0) {
        obj = (int)&local;
    }
    if (layout != 0) {
        SetJudgeVolumeInfo(obj, *layout->unk138, layout->unk134, layout->unk13C, layout->v90, layout->v70,
                           layout->v60, layout->scale_x, layout->scale_y, layout->scale_z);
        CheckPositionInsideOfJudgeVolumeInfo(obj, arg2);
    }
}
#endif
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

extern void updateParticleGeo();
extern int kickParticle(int, int, int, int, int);
extern void func_400A0D38(void *, void *, void *, void *);

void func_400A09A8(void *a, void *b, void *c, void *d, void *e, void *f)
{
    updateParticleGeo(0, a, b, c, 0, d, f, 0, e, 1, kickParticle, 0);
    func_400A0D38(a, d, e, f);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0A40);
extern void updateParticleDissolveGeo();

void func_400A0A40(void *a, void *b, void *c, void *d, void *e, void *f)
{
    updateParticleDissolveGeo(0, a, b, c, 0, d, f, 0, e, 1, kickParticle, 0);
    func_400A0D38(a, d, e, f);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0AD8);
extern void SetGeometryPointerNodePosState(void *, void *, void *, void *, void *);
extern void SequenceKickCameraVibration(void *, void *);
extern u8 IdentityQuaternion[];
extern u8 ZeroPoint[];

void func_400A0AD8(void *a, void *b, void *c)
{
    u8 buf[64];

    SetGeometryPointerNodePosState(buf, b, c, IdentityQuaternion, ZeroPoint);
    SequenceKickCameraVibration(a, buf);
    return;
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0CB8);
extern void FlushScriptLayoutObj(void);
extern void FlushJudgeVolumeClass(s32);
extern void isysFlushISYSLetterObj();

void func_400A0CB8(s32 arg0)
{
    s32 p;
    s32 t;

    p = 0;
    if (*(u8 *)(arg0 + 8) == 0xD)
    {
        p = arg0 + 0x20;
    }
    FlushScriptLayoutObj();
    t = *(s32 *)(p + 0x33C);
    if (t != 0)
    {
        FlushJudgeVolumeClass(t);
        *(s32 *)(p + 0x33C) = 0;
    }
    isysFlushISYSLetterObj(arg0);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0D18);
extern void isysAddGroupWithLinkParam(void *, void *, int, int);

void func_400A0D18(void *a, void *b)
{
    isysAddGroupWithLinkParam(a, b, 0, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0D38);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0E48);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A0F78);

extern u64 *GetCollisionDBAttributeAdr();

s32 func_400A10A8(void)
{
    u64 *temp_v0;

    temp_v0 = GetCollisionDBAttributeAdr();
    return (*temp_v0 & 0xF80000000) != 0x800000000;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0123_ScriptAnimationObjCheckPositionInsideOfJ", func_400A10E8);
extern void seSetKeyOnOff(void);

void func_400A10E8(void)
{
    seSetKeyOnOff();
}
