#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", initMcManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", func_400DBD38);

int mcReqSync(int *arg0)
{
    return *arg0 == 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", mouseDrawCursor);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", func_400DC028);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", mouseGetStatus);

struct CursorPosition {
    float x;
    float y;
};

extern struct CursorPosition D_401B1748;

void mouseSetCursorPosition(float x, float y)
{
    D_401B1748.x = x;
    D_401B1748.y = y;
}

typedef struct {
    char pad0[8];
    float x;
    float y;
    float z;
    int dx;
    int dy;
    int wheel;
    int press[3];
    int release[3];
    int hold[3];
} MouseStatus;

void mouseClearStatus(MouseStatus *m)
{
    m->release[0] = m->release[1] = m->release[2] = m->press[0] = m->press[1] = m->press[2] = m->hold[0] = m->hold[1] = m->hold[2] = m->dx = m->dy = 0;
    m->x = m->y = m->z = 0.0f;
    m->wheel = 0;
}

extern s64 iosGetTCountExtension();
extern f32 iosGetSecondFromTCount(u64 arg0);
extern float D_4012BB54;

void mouseDispCursor(void)
{
    D_4012BB54 = iosGetSecondFromTCount(iosGetTCountExtension());
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", mouseInit);

void mouseMoveCursorPosition(float dx, float dy)
{
    struct CursorPosition *cursor = &D_401B1748;

    cursor->x += dx;
    cursor->y += dy;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0174_initMcManager", EntryPadHistory);
