#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegDemuxPssRing);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegDemuxPss);
s32 sceMpegDemuxPss(s32 a0, s32 a1, s32 a2)
{
    s32 ret;

    ret = sceMpegDemuxPssRing(a0, a1, a2, 0, -1);
    if (ret != 0)
    {
        return ret;
    }
    return ret;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", sceMpegAddStrCallback);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegType2id);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40104A28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegStopIpuDma);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegErrorBdec);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegError);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", _sceMpegError1);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40104C40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40104DC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_401054D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40105720);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0212_sceMpegDemuxPssRing", func_40105BA8);
