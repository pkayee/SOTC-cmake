#include "common.h"

void deleteUserPathWork(u8* work);
u8* GetLayoutClass(void* chara);
s32 func_401033B0(u8* work, u8* layout, s32 a2, s32 a3, u8* chara);
s32 func_40103A70(u8* work, u8* layout, u8* chara, s32 a3, s32 ret);
s32 func_401034F0(u8* work, u8* layout, s32 a2, s32 a3);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0201_updateUserPathWorkEx", updateUserPathWorkEx);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0201_updateUserPathWorkEx", func_40102EE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0201_updateUserPathWorkEx", createUserPathWorkEx);

void deleteUserPathWorkEx(u8* work)
{
    deleteUserPathWork(work);
}

void setUserPathExMode(u8* work, s32 value)
{
    *(s32*)(work + 0x3C40) = value;
}

void setUserPathGroupID(u8* work, s32 groupId, s32 value)
{
    *(s32*)(work + 0x3C48) = groupId;
    *(s32*)(work + 0x3C4C) = value;
}

s32 getUserPathExMode(u8* work)
{
    return *(s32*)(work + 0x3C40);
}

s32 getPathExFinish(u8* work, s32 mode)
{
    switch (mode) {
    case 2:
    case 3:
    case 4:
        return *(s32*)(work + 0x3C88);
    case 5:
    case 6:
    case 7:
    case 8:
        return *(s32*)(work + 0x3C84);
    case 9:
        return *(s32*)(work + 0x3C8C);
    default:
        return 0;
    }
}

/* NEARMISS-STUB getPPointPasasgeNum */
#if 0 /* NEARMISS 80.0% cat=regalloc sub=- | in-TU: spurious daddu a1,a0,zero at entry; 2-arg signature (s32,u8*) conflicts with caller proto | attempts=1 */
s32 getPPointPasasgeNum(s32 unused, u8* work)
{
    if (*(s32*)(work + 0x3C40) != 9) {
        return 0;
    }
    return *(s32*)(work + 0x3C90);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0201_updateUserPathWorkEx", getPPointPasasgeNum);

void setGPSelectMode(u8* work, s32 value)
{
    *(s32*)(work + 0x3C58) = value;
}

void setForceInitPathEx(u8* work, s32 value)
{
    *(s32*)(work + 0x3C5C) = value;
}

void setGpReferencePathEx(u8* work, s32 value)
{
    *(s32*)(work + 0x3C60) = value;
}

s32 changedGPIndex(s32 a0, u8* work, s32 a2)
{
    u8* layout = GetLayoutClass((void*)a0);
    u8* chara = GetLayoutClass((void*)a2);
    s32 ret = func_401033B0(work, layout, *(s32*)(work + 0x3C68), *(s32*)(work + 0x3C6C), chara);
    return func_40103A70(work, layout, chara, *(s32*)(work + 0x3C70), ret);
}

s32 changedAPIndex(s32 a0, u8* work)
{
    u8* layout = GetLayoutClass((void*)a0);
    return *(s32*)(work + 0x3C78) != func_401034F0(work, layout, *(s32*)(work + 0x3C70), *(s32*)(work + 0x3C6C));
}

s32 changedDPGroupID(s32 a0, u8* work, s32 a2, s32 a3)
{
    s32 ret = 0;

    if (a2 == *(s32*)(work + 0x3C48)) {
        if (a3 != *(s32*)(work + 0x3C4C)) {
            ret = 1;
        }
    } else {
        ret = 1;
    }
    return ret;
}

void setGpCalcDist(u8* work, f32 value)
{
    *(f32*)(work + 0x3C64) = value;
}

extern int getGoalPointDataByAreaIdx(u8* context, int point, int area);
extern int getChildSubPointIdxArrayByAreaIdx(u8* context, int point, int area);
extern int getSubPointDataByAreaIdx(u8* context, int point, int area);

int getConnectPPointIdx(u8* context, int point, int area)
{
    int count = 0;
    u8* goal = (u8*)getGoalPointDataByAreaIdx(context, point, area);
    s16* indexAddress = (s16*)getChildSubPointIdxArrayByAreaIdx(context, point, area);

    if (goal == 0 || indexAddress == 0) {
        return 0;
    }
    {
        u32 i = 0;
        if (*(u32*)(goal + 0x14) != 0) {
            s16* indices = indexAddress;
            do {
                s32 subPoint = *indices++;
                u8* data = (u8*)getSubPointDataByAreaIdx(context, subPoint, area);
                if (*(s32*)(data + 0x10) & 2) {
                    count++;
                }
                i++;
            } while (i < *(u32*)(goal + 0x14));
        }
    }
    return count;
}
