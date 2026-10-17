#include "common.h"

extern s32 D_00133A40[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", sceResetttyinit);
void sceResetttyinit(void)
{
    D_00133A40[0] = 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", VSync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", VSync2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", write);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", read);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", open);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", close);
s32 close(s32 fd)
{
    return -1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", ioctl);
s32 ioctl(s32 fd, s32 request, s32 arg)
{
    return -1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", lseek);
s32 lseek(s32 fd, s32 offset, s32 whence)
{
    return -1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", sbrk);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", isatty);
s32 isatty(s32 fd)
{
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", fstat);
s32 fstat(s32 fd, void *st)
{
    *(s64 *)((u8 *)st + 0x48) = 0;
    *(s32 *)((u8 *)st + 0x4) = 0x2000;
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", getpid);
s32 getpid(void)
{
    return 1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", kill);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", stat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/glue", unlink);
