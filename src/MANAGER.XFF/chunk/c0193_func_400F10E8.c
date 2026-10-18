#include "common.h"

void func_400EEE08(void *param, void (*func)(void));
void func_400F14E0(void);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F10E8);
void func_400F10E8(void *chara)
{
    func_400EEE08(chara, func_400F14E0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1108);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1148);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F11E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F12D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F13C8);

extern unsigned char D_4012E32C[];

void *getSheetDebugNoLoadMode(void)
{
    return D_4012E32C;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F14E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecMake);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecCommit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecUpdate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecClean);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinSw);

extern int D_4012E348;

int GetDebPcWinSw(void)
{
    return D_4012E348;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinType);

extern int D_4012E34C;

int GetDebPcWinType(void)
{
    return D_4012E34C;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinCategory);

extern int D_4012E350;

int GetDebPcWinCategory(void)
{
    return D_4012E350;
}

void toggleDebPcWinWindow(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1868);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", update_camera_context);
