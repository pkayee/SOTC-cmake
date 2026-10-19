#include "common.h"

extern u8 D_40130F88[];

/* SetSeamlessZFogDist(a, b): cache (a,b), recompute fog z from the map size */
extern s32 D_40130F64;
extern s32 D_40130F68;
extern f32 D_40130FC8;
extern f32 D_40130FF8;
extern s32 D_40130FFC;
extern f32 D_40200F2C;

float getAreaSize(void)
{
    u8 *env = D_40130F88;

    return *(float *)(env + 0x40) * (float)*(s32 *)(env + 0x38);
}

/* NEARMISS-STUB getStageAreaID */
#if 0 /* NEARMISS 73.41% cat=regalloc sub=- | REA READY drop-in scored 73.41 in-TU (apply_ready) | attempts=1 */
/* getStageAreaID(pos, outX, outZ): area index from world pos; env = D_40130F88 */
void getStageAreaID(float *pos, int *outX, int *outZ)
{
    u8 *env = D_40130F88;
    int ix = (int)((-pos[0] - *(float *)(env + 0x50)) / *(float *)(env + 0x40)) / *(s32 *)(env + 0x38);
    int iz = *(s32 *)(env + 0x34) - (int)((-pos[2] - *(float *)(env + 0x54)) / *(float *)(env + 0x44)) / *(s32 *)(env + 0x3C) - 1;

    if (ix < 0 || ix > *(s32 *)(env + 0x30) - 1) {
        *outX = -1;
    } else {
        *outX = ix;
    }
    if (iz < 0 || iz > *(s32 *)(env + 0x34) - 1) {
        *outZ = -1;
    } else {
        *outZ = iz;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaID);

/* NEARMISS-STUB getStageAreaName */
#if 0 /* NEARMISS 60.08% cat=regalloc sub=- | REA READY drop-in scored 60.08 in-TU (apply_ready) | attempts=1 */
/* getStageAreaName(out, pos): 2-char area name (letter+digit) + NUL */
void getStageAreaName(char *out, float *pos)
{
    u8 *env = D_40130F88;
    int ix = (int)((-pos[0] - *(float *)(env + 0x50)) / *(float *)(env + 0x40)) / *(s32 *)(env + 0x38);
    int iz = *(s32 *)(env + 0x34) - (int)((-pos[2] - *(float *)(env + 0x54)) / *(float *)(env + 0x44)) / *(s32 *)(env + 0x3C) - 1;

    if (ix < 0 || ix > *(s32 *)(env + 0x30) - 1) {
        out[0] = ix + 0x3F;
    } else {
        out[0] = ix + 0x41;
    }
    if (iz < 0 || iz > *(s32 *)(env + 0x34) - 1) {
        out[1] = iz + 0x3F;
    } else {
        out[1] = iz + 0x30;
    }
    out[2] = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaName);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaNameUV);

void SetSeamlessZFogDist(s32 a, s32 b)
{
    if (D_40130F64 != a || D_40130F68 != b) {
        D_40130F64 = a;
        D_40130F68 = b;
        D_40200F2C = (D_40130FC8 * 0.5f + D_40130FC8 * (f32)(a + b - 1) - D_40130FF8) / 15.0f;
        D_40130FFC = 0xF;
    }
}

extern s32 D_40130F5C;

s32 *getSeamlessStageHighModelDispDist(void)
{
    return &D_40130F5C;
}

extern s32 D_40130F60;

s32 *getSeamlessStageMiddleModelDispDist(void)
{
    return &D_40130F60;
}

extern s32 D_40130F6C;

s32 *getSeamlessStageHighModelDispDistDefault(void)
{
    return &D_40130F6C;
}

extern s32 D_40130F70;

s32 *getSeamlessStageMiddleModelDispDistDefault(void)
{
    return &D_40130F70;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageChipIDReal);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageChipIDWithOffset);

void getStageNormalizePosition(float *pos, float *outX, float *outZ)
{
    u8 *env = D_40130F88;

    *outX = (-pos[0] - *(float *)(env + 0x50)) / *(float *)(env + 0x40);
    *outZ = (-pos[2] - *(float *)(env + 0x54)) / *(float *)(env + 0x44);
}

extern u8 gcGlobalVar[];

typedef union {
    s32 i;
    float f;
} Word;

typedef struct {
    char pad0[0x28];
    Word columns;
    Word rows;
    char pad30[0x20];
    float width;
    float depth;
} StageMap;

void getCameraPosOnMap(float *x, float *z)
{
    StageMap *map = (StageMap *)D_40130F88;
    float *cam = (float *)(gcGlobalVar + 0x340);

    *x = -cam[0] * map->columns.i / map->width;
    *z = -cam[2] * map->rows.i / map->depth;
}

typedef struct {
    char pad[0x40];
    float sx;
    float sz;
    char pad2[8];
    float ox;
    float oz;
} StageGrid;

void getSeamlessStageCenter(float *out, float *pos)
{
    StageGrid *grid = (StageGrid *)D_40130F88;
    int ix = (-pos[0] - grid->ox) / grid->sx;
    int iz = (-pos[2] - grid->oz) / grid->sz;

    out[0] = -((float)ix * grid->sx + grid->sx * 0.5f + grid->ox);
    out[2] = -((float)iz * grid->sz + grid->sz * 0.5f + grid->oz);
}

u8 *getSeamlessStageEnv(void)
{
    return D_40130F88;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageLayout);

extern u8 *D_40130F90;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageStat);

extern s32 D_40130F58;

s32 GetLoadAreaGroupData(void)
{
    return D_40130F58;
}

extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);

u8 *CreateLoadAreaGroupData(void)
{
    u8 *g = iosMallocAlign(&rootPtn, 0x24, 0x10);

    *(s32 *)(g + 0x1C) = 0;
    *(s32 *)(g + 0x4) = -1;
    *(s32 *)(g + 0x8) = -1;
    *(s32 *)(g + 0xC) = 0;
    *(s32 *)(g + 0x10) = 0;
    *(s32 *)(g + 0x20) = D_40130F58;
    D_40130F58 = (s32)g;
    return g;
}

void iosFree(void *p);

typedef struct Grp {
    char pad[0x20];
    struct Grp *next;
} Grp;

void DeleteLoadAreaGroupData(Grp *g)
{
    Grp **h = (Grp **)&D_40130F58;
    Grp *p = *h;

    if (p == g)
    {
        *h = g->next;
        iosFree(g);
        return;
    }
    while (p != NULL)
    {
        if (p->next == g)
        {
            p->next = g->next;
            iosFree(g);
            break;
        }
        p = p->next;
    }
}

extern s32 D_40130F74;

void forceLoadSeamlessStage(void)
{
    D_40130F74 = 1;
}

extern s32 D_40130FAC;

void SetSeamlessStageControlObject(s32 param_1)
{
    D_40130FAC = param_1;
}

void UpdateSeamlessStageLoad(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        *(s32 *)env = 1;
    }
}

s32 func_40033BD0(void *node);
void func_40034A00(s32 a, s32 b, s32 c);
extern s32 D_4013101C;
extern u8 *D_40130F90;

void DeleteAllSeamlessStageObject(void)
{
    s32 *cur;

    if (D_40130F90 != NULL)
    {
        cur = (s32 *)D_4013101C;
        if (cur != NULL)
        {
            do
            {
                if (func_40033BD0(cur))
                {
                    func_40034A00(cur[2], cur[0], cur[1]);
                }
            } while (cur != NULL);
        }
    }
}

void iosFree(void *p);

void DeleteSeamlessStageLoad(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        iosFree(*(void **)(env + 0x8));
        *(s32 *)(env + 0x8) = 0;
    }
}

s32 GetStageChipNum(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        return *(s32 *)(env + 0x58);
    }
    return 0;
}

/* NEARMISS-STUB DeleteSeamlessStageObject */
#if 0 /* NEARMISS 60.0% cat=regalloc sub=- | REA READY drop-in scored 58.56 in-TU (apply_ready) | attempts=2 */
s32 DeleteSeamlessStageObject(s32 layer, s32 chip, s32 *out)
{
    s32 *ent = *(s32 **)(D_40130F88.tbl + chip * 24 + layer * 4);
    s32 r = 0;
    s32 stat;
    if (ent != 0) {
        r = ent[3];
    }
    if (chip == -1) {
        stat = 7;
    } else {
        stat = *(u32 *)(D_40130F88.tbl + chip * 24 + layer * 4 + 8) & 0xF;
    }
    if (stat == 5) {
        *out = 0;
        return 0;
    }
    *out = *(u32 *)(D_40130F88.tbl + chip * 24 + layer * 4 + 8) >> 4;
    return r;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", DeleteSeamlessStageObject);

extern u8 D_40130FF4[];

u8 *GetSeamlessStageObjectGroup(void)
{
    return D_40130FF4;
}

extern s32 D_40130F8C;

void PauseSeamlessStageManager(s32 param_1)
{
    D_40130F8C = param_1;
    if (param_1 == 0)
    {
        D_40130F74 = 1;
    }
}

extern void func_400399A0(void);
extern void *createScriptObj(void (*)(void), void *, int, int, int, int, int, int);
extern int **isysGroupForFirst(void *, int);
extern int **isysGroupForNext(void *, int);
extern void isysGroupForExit(void *, int);
extern void isysSleepSubThread(void);

void UnloadAllSeamlessStageObject(int arg)
{
    int req[2];

    if (D_40130F90 == 0)
        return;
    req[1] = arg;
    req[0] = 1;
    createScriptObj(func_400399A0, req, *(int *)(gcGlobalVar + 0x308), 0x4000, 0, 1, 0, 0);
    for (;;) {
        int **g;
        int n = 0;
        int *last = 0;

        for (g = isysGroupForFirst(&D_40130FF4, 0); g != 0; g = isysGroupForNext(g, 0)) {
            last = *g;
            n++;
        }
        if (last != 0)
            isysGroupForExit(last, 0);
        if (n == 0 && req[0] == 0)
            break;
        isysSleepSubThread();
    }
}

typedef struct {
    char pad[0x48];
    int width;
    int height;
} MapSize;

int getChipNo(int x, int y)
{
    if (x < 0 || x >= ((MapSize *)D_40130F88)->width || y < 0 || y >= ((MapSize *)D_40130F88)->height)
        return -1;
    return y * ((MapSize *)D_40130F88)->width + x;
}

void getPosOnMap(const float *position, float *x, float *z)
{
    StageMap *map = (StageMap *)D_40130F88;

    *x = (-position[0] * (float)map->columns.i) / map->width;
    *z = (-position[2] * (float)map->rows.i) / map->depth;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageIDWithOffset);

extern u8 *D_40130F90;

typedef struct {
    s32 a;
    s32 b;
    s32 stat[4];
} ChipStat;

int getStageStatByChipNo(int chip, int k)
{
    if (chip != -1)
        return ((ChipStat *)D_40130F90)[chip].stat[k] & 0xF;
    return 7;
}
