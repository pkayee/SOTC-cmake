#include "common.h"

/* MANAGER c0207 PROVEN 100. Dead 0x28-byte header copy from *(p+8) onto the stack (ldl/ldr/sdl/sdr = u8[0x28] struct, alignment 1). */
typedef struct { u8 b[0x28]; } MpgHdr207;

/* MANAGER c0207 PROVEN 100. PSS stream state struct at D_401C4A00 (u32 f[11]); f[8]=run flag cleared, f[10]=closed-ack polled with isysSleepSubThread. */
typedef struct { s32 f[11]; } StrFile207;
extern StrFile207 D_401C4A00;
extern void isysSleepSubThread();

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", playPss);

void DebugPrintMpgHeader(s32 *p)
{
    MpgHdr207 h;

    h = *(MpgHdr207 *)p[2];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", func_400FE1B8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", func_400FE2B8);
s32 func_400FE2B8(void)
{
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", func_400FE2C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", func_400FE2E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", func_400FE4B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", strFileOpen);

s32 strFileClose(void)
{
    D_401C4A00.f[8] = 0;
    while (D_401C4A00.f[10] == 0)
    {
        isysSleepSubThread();
    }
    return 1;
}

void func_400FE4B0(void);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", strFileRead);
void strFileRead(void)
{
    func_400FE4B0();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", clipVectorPlaneVolume);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0207_playPss", qsort);
