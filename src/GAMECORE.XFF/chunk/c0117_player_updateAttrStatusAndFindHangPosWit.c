#include "common.h"

extern void DeleteTwoWayLink(char *);
extern void GetGeometryPointerPosition(float *, void *);

typedef struct
{
    char pad[0x18];
} AttrSt;

extern AttrSt D_40206CE8[];
extern int func_400A00A0(AttrSt *, int, int, int, int);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", player_updateAttrStatusAndFindHangPosWithFallDown);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", player_initHangPointWork);

void player_resetHangPointWork(char *p)
{
    if (*(int *)(p + 0x0) != 0) {
        *(int *)(p + 0x0) = 0;
        DeleteTwoWayLink(p + 0x50);
    }
}

int checkdist(float *d, void *g)
{
    float p[4];
    float y;

    GetGeometryPointerPosition(p, g);
    y = -p[1];
    if (y < *d) {
        *d = y;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", func_400A15F8);

int attrStatusUpdate(int a, int b, int c)
{
    int r = 0;
    AttrSt *p = D_40206CE8;
    int i = 4;

    do {
        r = func_400A00A0(p++, a, b, r, c);
    } while (--i);
    return r;
}

extern char *GetCharacterClass(void *);
extern void charrootdyn_setHColFindStatus(char *, char *, float);
extern void charrootdyn_setVColFindFlag(char *, char *, float);
extern void CopyGeometryPointer(char *, char *);
extern void charrootdyn_setFallDownLandingOffset(char *, char *);

static inline void setHang(char *c, char *g)
{
    float z = 0.0f;
    charrootdyn_setHColFindStatus(c, g, z);
    charrootdyn_setVColFindFlag(c, g, z);
    CopyGeometryPointer(c + 0xE50, g);
    *(int *)(c + 0xE30) = 1;
    charrootdyn_setFallDownLandingOffset(c, g);
}

void player_setEdgeHangPointGeometry(void *a, char *b)
{
    setHang(GetCharacterClass(a), b + 0x70);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", player_setGripHangPointGeometry);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", func_400A1830);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", nico_player_colfit_SetLower);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", nico_player_edgecolfit_Shoulder);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0117_player_updateAttrStatusAndFindHangPosWit", func_400A21E0);
