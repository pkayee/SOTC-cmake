#include "common.h"

extern s32 D_40218B50;
extern s32 D_40218B54;
extern u8 D_4021DF58[];
f32 iosGetCosf(f32 x);
void DeleteTwoWayLink();
s32 getPathColiGroupByType(s32 type);
u8* getPassageWork(u8* work, s32 idx);
u8* GetLayoutClass(void* chara);
void AddTwoWayLinkNext();
u8* getLineData();
u8* getPathInfo(u8* work);

void delISysPathObj(void) {
}

void setBossPathColiGroup(s32 value)
{
    D_40218B50 = value;
}

void setHorsePathColiGroup(s32 value)
{
    D_40218B54 = value;
}

s32 getPathColiGroup(u8* work)
{
    return getPathColiGroupByType(*(s32*)(work + 0x3C30));
}

s32 getPathColiGroupByType(s32 type)
{
    if (type == 0)
    {
        return D_40218B50;
    }
    if (type == 1)
    {
        return D_40218B54;
    }
    return 0;
}

s32 getAimPosFromPathManager(u8* work, u128* out)
{
    u8* passage = getPassageWork(work, 0);
    if (passage == NULL)
    {
        return 0;
    }
    *out = *(u128*)passage;
    return 1;
}

u8* getPassageWork(u8* work, s32 idx)
{
    if (idx < 0x14 && (u32)idx < (u32)*(s32*)(work + 0x380))
    {
        return work + (idx << 5) + 0x100;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPassageNum);
s32 getPassageNum(u8* work)
{
    return *(s32*)(work + 0x380);
}

typedef struct { u64 q[3]; s16 f18; s16 f1A; s32 f1C; } PassageEnt;
typedef struct { u8 pad[0x100]; PassageEnt ent[20]; s32 count; } PassageWork;
void deletePassageWork(PassageWork *work, u32 idx)
{
    u32 i;

    if (work->count != 0) {
        for (i = idx; i < work->count - 1; i++) {
            work->ent[i] = work->ent[i + 1];
            work->ent[i].f18 = 0;
        }
        work->count--;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setDataHeaderFromAreaIdx);
s32 setDataHeaderFromAreaIdx(u8* work, s32 areaIdx)
{
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", resetUserPathWork);

void setRealColJudgeFunc(u8* work, s32 value)
{
    *(s32*)(work + 0x3C34) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getRealColJudgeFunc);
s32 getRealColJudgeFunc(u8* work)
{
    return *(s32*)(work + 0x3C34);
}

s32 setLockPassageWork(u8* work, s32 value)
{
    if (*(s32*)(work + 0x380) != 0)
    {
        u8* passage = getPassageWork(work, 0);
        *(s16*)(passage + 0x18) = value;
        return 1;
    }
    return 0;
}

void setStabilizeYPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xE8) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAngleStabilizeYPathWork);
void setAngleStabilizeYPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xEC) = value;
}

void setRayByRealColPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xF0) = value;
}

void setPassageWideRayPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xF4) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setExecRayChkPathWork);
void setExecRayChkPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x384) = value;
}

s32 setRayCutPassageWork(u8* work, u32 idx, s32 value)
{
    if (idx < *(u32*)(work + 0x380))
    {
        u8* passage = getPassageWork(work, idx);
        *(s16*)(passage + 0x1A) = value;
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setForceRouteAttrPathWork);
void setForceRouteAttrPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x38C) = value;
}

void setRouteColCheckPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x390) = value;
}

void setRouteLockPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x394) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setFollowModePathWork);
void setFollowModePathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x398) = value;
}

void setPassageCallBack(u8* work, s32 callback, s32 data)
{
    *(s32*)(work + 0x3C24) = data;
    *(s32*)(work + 0x3C28) = callback;
}

void deleteUserPathWork(u8* work)
{
    if (*(s32*)(work + 0xA4) != 0)
    {
        *(s32*)(work + 0xA4) = 0;
        DeleteTwoWayLink(work + 0x98);
    }
}

void setUserPathMode(u8* work, s32 value)
{
    *(s32*)(work + 0x39C) = value;
}

void setPassageRangeData(u8* work, f32 a, f32 b)
{
    *(f32*)(work + 0x3B8) = a;
    *(f32*)(work + 0x3BC) = b;
}

void setAttainRangeData(u8* work, u128* src, f32 a, f32 b, f32 c, f32 d)
{
    *(f32*)(work + 0x3DC) = d;
    *(f32*)(work + 0x3D0) = a;
    *(f32*)(work + 0x3D4) = b;
    *(f32*)(work + 0x3D8) = c;
    *(u128*)(work + 0x3C0) = *src;
}

void setAttainRangeStruct(u8* work, u64* src)
{
    *(u64*)(work + 0x3C0) = src[0];
    *(u64*)(work + 0x3C8) = src[1];
    *(u64*)(work + 0x3D0) = src[2];
    *(u64*)(work + 0x3D8) = src[3];
}

typedef union { u128 q; f32 f[4]; } TmpQVec;
void setTmpBasePos(u8* work, u8* dst)
{
    u8* layout = GetLayoutClass(work);
    u128 pos = (*(TmpQVec**)(layout + 0x134))->q;
    *(s32*)(dst + 0x40) = -1;
    ((TmpQVec*)(dst + 0x50))->q = pos;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setCreateTempAttain);
void setCreateTempAttain(u8* work, s32 value)
{
    *(s32*)(work + 0x3F4) = value;
}

void DeleteTwoWayLink();

void setAttainmentPos(u8* work, TmpQVec* pos)
{
    ((TmpQVec*)(work + 0x60))->q = pos->q;
    *(s32*)(work + 0x90) = 1;
    *(f32*)(work + 0x6C) = 1.0f;
    if (*(s32*)(work + 0xA4) != 0)
    {
        *(s32*)(work + 0xA4) = 0;
        DeleteTwoWayLink(work + 0x98);
    }
    *(s32*)(work + 0x94) = 0;
    *(s32*)(work + 0x3F0) = 0;
    *(s32*)(work + 0xA8) = 0;
    *(s32*)(work + 0xAC) = 0;
}


INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentPosAndDirPos);

void setAttainmentPosAndDir(u8* work, TmpQVec* pos, TmpQVec* dir)
{
    ((TmpQVec*)(work + 0x60))->q = pos->q;
    *(s32*)(work + 0x90) = 1;
    *(f32*)(work + 0x6C) = 1.0f;
    if (*(s32*)(work + 0xA4) != 0)
    {
        *(s32*)(work + 0xA4) = 0;
        DeleteTwoWayLink(work + 0x98);
    }
    *(s32*)(work + 0xA8) = 0;
    *(s32*)(work + 0x94) = 0;
    *(s32*)(work + 0x3F0) = 0;
    *(s32*)(work + 0xAC) = 0;
    ((TmpQVec*)(work + 0xC0))->q = ((TmpQVec*)(work + 0xB0))->q;
    ((TmpQVec*)(work + 0xB0))->q = dir->q;
    *(s32*)(work + 0xA8) = 1;
}

void setAttainmentPosAndDirAndLock(u8* work, TmpQVec* pos, TmpQVec* dir)
{
    ((TmpQVec*)(work + 0x60))->q = pos->q;
    *(s32*)(work + 0x90) = 1;
    *(f32*)(work + 0x6C) = 1.0f;
    if (*(s32*)(work + 0xA4) != 0)
    {
        *(s32*)(work + 0xA4) = 0;
        DeleteTwoWayLink(work + 0x98);
    }
    *(s32*)(work + 0xA8) = 0;
    *(s32*)(work + 0xAC) = 0;
    *(s32*)(work + 0x94) = 0;
    *(s32*)(work + 0x3F0) = 0;
    ((TmpQVec*)(work + 0xC0))->q = ((TmpQVec*)(work + 0xB0))->q;
    ((TmpQVec*)(work + 0xB0))->q = dir->q;
    *(s32*)(work + 0xA8) = 1;
    *(s32*)(work + 0xAC) = 1;
}


INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentObjAndDir);

/* NEARMISS-STUB setAttainmentObjAndOffset */
#if 0 /* NEARMISS 75.9% cat=sched sub=- | sched | attempts=1 */
u8* GetLayoutClass(void* chara);
void DeleteTwoWayLink();
void AddTwoWayLinkNext();

void setAttainmentObjAndOffset(u8* work, u8* obj, u128* offset)
{
    *(s32*)(work + 0x90) = 1;
    if (*(s32*)(work + 0xA4) != 0)
    {
        *(s32*)(work + 0xA4) = 0;
        DeleteTwoWayLink(work + 0x98);
    }
    *(u8**)(work + 0x94) = obj;
    if (obj != NULL)
    {
        u8* layout = GetLayoutClass(obj);
        AddTwoWayLinkNext(layout + 0x118, work + 0x98);
        *(s32*)(work + 0xA4) = 1;
    }
    *(s32*)(work + 0x3F0) = 0;
    *(s32*)(work + 0xA8) = 0;
    *(s32*)(work + 0xAC) = 0;
    *(u128*)(work + 0xD0) = *offset;
}
#endif
typedef union {
    s128 q;
    float f[4];
    int i[4];
} Vec4;

typedef struct {
    s8 pad0[0x90];
    s32 active;
    s32 target;
    s8 link[0xC];
    s32 linked;
    s32 unkA8;
    s32 unkAC;
    s8 padB0[0x20];
    Vec4 offset;
    s8 padE0[0x310];
    s32 unk3F0;
} Attainment;

void setAttainmentObjAndOffset(Attainment *a, s32 target, Vec4 *offset)
{
    a->active = 1;
    if (a->linked != 0)
    {
        a->linked = 0;
        DeleteTwoWayLink(a->link);
    }
    a->target = target;
    if (target != 0)
    {
        AddTwoWayLinkNext(GetLayoutClass((void*)target) + 0x118, a->link);
        a->linked = 1;
    }
    a->unk3F0 = 0;
    a->unkA8 = 0;
    a->unkAC = 0;
    a->offset.q = offset->q;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainModePathWork);
void setAttainModePathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xE0) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainRadPathWork);
void setAttainRadPathWork(u8* work, f32 rad)
{
    *(f32*)(work + 0xE4) = rad;
}

u8* getPathInfo(u8* work)
{
    return D_4021DF58 + *(s32*)(work + 0x3C30) * 0x98;
}

s32 getWayFinish(u8* work)
{
    s32 ret = 0;
    if (*(s32*)(work + 0x3E8) != 0)
    {
        ret = *(s32*)(work + 0x380) == 0;
    }
    return ret;
}

s32 getPathStatus(u8 *work)
{
    switch (*(s32 *)(work + 0x39C))
    {
    case 0:
        if (*(s32 *)(work + 0x380) != 0 || *(s32 *)(work + 0x3E8) != 0)
        {
            return 1;
        }
        break;
    case 1:
        if (*(s32 *)(work + 0x380) != 0)
        {
            return 1;
        }
        break;
    case -1:
        return 1;
    }
    return 0;
}

s32 useTempAttain(u8 *work)
{
    if (*(s32 *)(work + 0x39C) == 0 && *(s32 *)(work + 0x3F0) != 0)
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getWayForRoute);
s32 getWayForRoute(u8* work)
{
    return *(s32*)(work + 0x3EC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastAttainUpdate);
s32 getLastAttainUpdate(u8* work)
{
    return *(s32*)(work + 0x90);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastPassagePointIdx);
s32 getLastPassagePointIdx(u8* work)
{
    return *(s32*)(work + 0x404);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastPassageAreaIdx);
s32 getLastPassageAreaIdx(u8* work)
{
    return *(s32*)(work + 0x408);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getNowPassagePointIdx);
s32 getNowPassagePointIdx(u8* work)
{
    return *(s32*)(work + 0x40C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getNowPassageAreaIdx);
s32 getNowPassageAreaIdx(u8* work)
{
    return *(s32*)(work + 0x410);
}

void setRouteMinAngle(u8* work, f32 angle)
{
    *(f32*)(work + 0x3AC) = iosGetCosf(angle);
}

void setSearchRouteMaxAngle(u8* work, f32 angle)
{
    *(f32*)(work + 0x3B0) = iosGetCosf(angle);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setSearchRadius);

void setPathRayWideParam(u8* work, f32 rad, s32 value)
{
    *(f32*)(work + 0x3C1C) = rad;
    *(s32*)(work + 0x3C20) = value;
}

typedef struct {
    s8 *data;
    s32 *point;
    s32 *line;
    s32 *root;
    s32 f10;
    s32 f14;
    s8 pad[0xC];
} PathE;

typedef struct {
    PathE e[4];
    s32 n;
    s32 pad;
} PathSet;

void setEventLineAttr(u8* work, s32 id, s32 attr)
{
    PathSet *s = (PathSet *)getPathInfo(work);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++)
    {
        s32 *arr = s->e[i].line;

        if (arr == 0)
        {
            continue;
        }
        for (j = 0; j < *arr; j++)
        {
            u8* l = getLineData(arr, j);

            if (id == *(s16*)(l + 0x10) || id == *(s16*)(l + 0x12))
            {
                *(s32*)(l + 8) |= attr;
            }
        }
    }
}

void unsetEventLineAttr(u8* work, s32 id, s32 attr)
{
    PathSet *s = (PathSet *)getPathInfo(work);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++)
    {
        s32 *arr = s->e[i].line;

        if (arr == 0)
        {
            continue;
        }
        for (j = 0; j < *arr; j++)
        {
            u8* l = getLineData(arr, j);

            if (id == *(s16*)(l + 0x10) || id == *(s16*)(l + 0x12))
            {
                *(s32*)(l + 8) &= ~attr;
            }
        }
    }
}
