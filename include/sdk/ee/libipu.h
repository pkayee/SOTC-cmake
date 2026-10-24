/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 */
/* 
 *                      Emotion Engine Library
 *                          Version 0.30
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-1999 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                       libipu - libipu.h
 *                     header file of libipu 
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *      0.10            Mar.25.1999     umemura     the first version
 *      0.20            Feb.29.2000     umemura     inline -> define
 *      0.30            Sep.26.2003     hana        change comment
 */
#ifndef _LIBIPU_H_
#define _LIBIPU_H_

#include <eetypes.h>
#include <eeregs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************
 *  IPU_CTRL.IDP
 **********************************************************************/
#define SCE_IPU_CTRL_IDP_8BIT 		(0x00<<16)
#define SCE_IPU_CTRL_IDP_9BIT 		(0x01<<16)
#define SCE_IPU_CTRL_IDP_10BIT 		(0x02<<16)

/**********************************************************************
 *  IPU_CTRL.AS
 **********************************************************************/
#define SCE_IPU_CTRL_AS_ZIGZAG 		(0x00<<20)
#define SCE_IPU_CTRL_AS_ALTERNATE 	(0x01<<20)

/**********************************************************************
 *  IPU_CTRL.IVF
 **********************************************************************/
#define SCE_IPU_CTRL_IVF_SAME 		(0x00<<21)
#define SCE_IPU_CTRL_IVF_SWITCH		(0x01<<21)

/**********************************************************************
 *  IPU_CTRL.QST
 **********************************************************************/
#define SCE_IPU_CTRL_QST_LINEAR 	(0x00<<22)
#define SCE_IPU_CTRL_QST_NONLINEAR 	(0x01<<22)

/**********************************************************************
 *  IPU_CTRL.MP1
 **********************************************************************/
#define SCE_IPU_CTRL_MP1_NONCOMPATIBLE 	(0x00<<23)
#define SCE_IPU_CTRL_MP1_COMPATIBLE	(0x01<<23)

/**********************************************************************
 *  IPU_CTRL.PCT
 **********************************************************************/
#define SCE_IPU_CTRL_PCT_IPIC 		(0x01<<24)
#define SCE_IPU_CTRL_PCT_PPIC 		(0x02<<24)
#define SCE_IPU_CTRL_PCT_BPIC 		(0x03<<24)
#define SCE_IPU_CTRL_PCT_DPIC 		(0x04<<24)

/**********************************************************************
 *  IPU commands
 **********************************************************************/
#define SCE_IPU_BCLR	0x00000000
#define SCE_IPU_IDEC	0x10000000
#define SCE_IPU_BDEC	0x20000000
#define SCE_IPU_VDEC	0x30000000
#define SCE_IPU_FDEC	0x40000000
#define SCE_IPU_SETIQ	0x50000000
#define SCE_IPU_SETVQ	0x60000000
#define SCE_IPU_CSC	0x70000000
#define SCE_IPU_PACK	0x80000000
#define SCE_IPU_SETTH	0x90000000

/**********************************************************************
 *  IPU commands' arguments
 **********************************************************************/

/* for IDEC */
#define SCE_IPU_IDEC_NODTDECODE		0
#define SCE_IPU_IDEC_DTDECODE		1
#define SCE_IPU_IDEC_NOOFFSET		0
#define SCE_IPU_IDEC_OFFSET			1
#define SCE_IPU_IDEC_NODITHER		0
#define SCE_IPU_IDEC_DITHER			1
#define SCE_IPU_IDEC_RGB32			0
#define SCE_IPU_IDEC_RGB16			1

/* for BDEC */
#define SCE_IPU_BDEC_FRAMEDCT		0
#define SCE_IPU_BDEC_FIELDDCT		1
#define SCE_IPU_BDEC_NODCRESET		0
#define SCE_IPU_BDEC_DCRESET		1
#define SCE_IPU_BDEC_NONINTRA		0
#define SCE_IPU_BDEC_INTRA			1

/* for VDEC */
#define SCE_IPU_VDEC_MBAI			0
#define SCE_IPU_VDEC_MBTYPE			1
#define SCE_IPU_VDEC_MOTIONCODE		2
#define SCE_IPU_VDEC_DMVECTOR		3

/* for SETIQ */
#define SCE_IPU_SETIQ_INTRA			0
#define SCE_IPU_SETIQ_NONINTRA		1

/* for CSC */
#define SCE_IPU_CSC_NODITHER		0
#define SCE_IPU_CSC_DITHER			1
#define SCE_IPU_CSC_RGB32			0
#define SCE_IPU_CSC_RGB16			1

/* for PACK */
#define SCE_IPU_PACK_NODITHER		0
#define SCE_IPU_PACK_DITHER			1
#define SCE_IPU_PACK_INDX4			0
#define SCE_IPU_PACK_RGB16			1

/**********************************************************************
 *  Structures
 **********************************************************************/
typedef struct {
    u_char y[16*16];
    u_char cb[8*8];
    u_char cr[8*8];
} sceIpuRAW8;

typedef struct {
    short y[16*16];
    short cb[8*8];
    short cr[8*8];
} sceIpuRAW16;

typedef struct {
    u_int pix[16*16];
} sceIpuRGB32;

typedef struct {
    u_short pix[16*16];
} sceIpuRGB16;

typedef struct {
    u_int pix[2*16];
} sceIpuINDX4;

typedef struct {
    u_int d4madr; /* ��~�����Ƃ��� D4_MADR ���W�X�^�̒l */
    u_int d4tadr; /* ��~�����Ƃ��� D4_TADR ���W�X�^�̒l */
    u_int d4qwc;  /* ��~�����Ƃ��� D4_QWC ���W�X�^�̒l */
    u_int d4chcr; /* ��~�����Ƃ��� D4_CHCR ���W�X�^�̒l */
    u_int d3madr; /* ��~�����Ƃ��� D3_MADR ���W�X�^�̒l */
    u_int d3qwc;  /* ��~�����Ƃ��� D3_QWC ���W�X�^�̒l */
    u_int d3chcr; /* ��~�����Ƃ��� D3_CHCR ���W�X�^�̒l */
    u_int ipubp;  /* ��~�����Ƃ��� IPU_BP ���W�X�^�̒l */
    u_int ipuctrl;/* ��~�����Ƃ��� IPU_CTRL ���W�X�^�̒l */
} sceIpuDmaEnv;

/**********************************************************************
 *  Functions
 **********************************************************************/

/* for erx */
void *sceIpuGetErxEntries(void);
	
/* ---------------------------------------------------------------------
 * sceIpuInit
 * ---------------------------------------------------------------------
 * [����] void sceIpuInit(void)
 * [����] �Ȃ�
 * [�Ԓl] �Ȃ�
 * [���] IPU ���̂���Z�b�g���AFIFO��N���A���܂��B
 */
void sceIpuInit(void);

/* ---------------------------------------------------------------------
 * sceIpuBCLR
 * ---------------------------------------------------------------------
 * [����] void sceIpuBCLR(int bp)
 * [����] bp   �ŏ��� 128 bit �̂���������J�n����r�b�g�ʒu
 * [�Ԓl] �Ȃ�
 * [���] BCLR �R�}���h����s���ē���FIFO��N���A���܂��B
 *        ���̊֐���Ăяo���O�ɁA����FIFO�ւ�DMA(toIPU:ch-4)��
 *        ��~���Ă����K�v������܂��B
 */
#define sceIpuBCLR(bp) DPUT_IPU_CMD(SCE_IPU_BCLR | (bp))

/* ---------------------------------------------------------------------
 * sceIpuIDEC
 * ---------------------------------------------------------------------
 * [����]
 *      void sceIpuIDEC(
 *           int ofm,
 *           int dte,
 *           int sgn,
 *           int dtd,
 *           int qsc,
 *           int fb
 *      )
 * 
 * [����]
 *      ofm  Output Format
 *           SCE_IPU_IDEC_RGB32(0)      : RGB32
 *           SCE_IPU_IDEC_RGB16(1)      : RGB16
 *      dte  Dither Enable
 *           SCE_IPU_IDEC_NODITHER(0)   : �f�B�U�Ȃ�
 *           SCE_IPU_IDEC_DITHER(1)     : �f�B�U����
 *           (ofm = RGB16 �̂Ƃ��̂ݗL��)
 *      sgn  Pseudo Sign Offset
 *           SCE_IPU_IDEC_NOOFFSET(0)   : offset �Ȃ�
 *           SCE_IPU_IDEC_OFFSET(1)     : offset -128
 *      dtd  DT Decode
 *           SCE_IPU_IDEC_NODTDECODE(0) : Dct Type ��f�R�[�h���Ȃ�
 *           SCE_IPU_IDEC_DTDECODE(1)   : Dct Type ��f�R�[�h����
 *      qsc  Quantizer Step Code
 *      fb   Forward Bit
 * 
 * [�Ԓl] �Ȃ�
 * [���] IDEC �R�}���h����s���ăC���g��������s���܂��B
 */
#define sceIpuIDEC(ofm, dte, sgn, dtd, qsc, fb) \
    DPUT_IPU_CMD(SCE_IPU_IDEC \
    	| ((ofm) << 27) \
    	| ((dte) << 26) \
    	| ((sgn) << 25) \
    	| ((dtd) << 24) \
    	| ((qsc) << 16) \
	| (fb) \
    )

/* ---------------------------------------------------------------------
 * sceIpuBDEC
 * ---------------------------------------------------------------------
 * [����]
 *      void sceIpuBDEC(
 *           int mbi,
 *           int dcr,
 *           int dt,
 *           int qsc,
 *           int fb
 *      )
 * 
 * [����]
 *      mbi  Macroblock Intra
 *           SCE_IPU_BDEC_NONINTRA(0) : ��C���g���}�N���u���b�N
 *           SCE_IPU_BDEC_INTRA(1)    : �C���g���}�N���u���b�N
 *      dcr  DC Reset
 *           SCE_IPU_BDEC_NODCRESET(0): DC�\���l����Z�b�g���Ȃ�
 *           SCE_IPU_BDEC_DCRESET(1)  : DC�\���l����Z�b�g����
 *      dt   DCT Type
 *           SCE_IPU_BDEC_FRAMEDCT(0) : frame DCT
 *           SCE_IPU_BDEC_FIELDDCT(1) : field DCT
 *      qsc  Quantiser Step Code
 *      fb   Forward Bit
 * 
 * [�Ԓl] �Ȃ�
 * [���] BDEC �R�}���h����s���ău���b�N������s���܂��B
 */
#define sceIpuBDEC(mbi, dcr, dt, qsc, fb) \
    DPUT_IPU_CMD(SCE_IPU_BDEC \
    	| ((mbi) << 27) \
    	| ((dcr) << 26) \
    	| ((dt)  << 25) \
    	| ((qsc) << 16) \
	| (fb) \
    )

/* ---------------------------------------------------------------------
 * sceIpuVDEC
 * ---------------------------------------------------------------------
 * [����] void sceIpuVDEC(int tbl, int fb)
 * [����]
 *      tbl  VLC table
 *           SCE_IPU_VDEC_MBAI(0)      : Macroblock Address Increment
 *           SCE_IPU_VDEC_MBTYPE(1)    : Macroblock Type
 *           SCE_IPU_VDEC_MOTIONCODE(2): Motion Code
 *           SCE_IPU_VDEC_DMVECTOR(3)  : DMVector
 *      fb   Forward Bit
 * 
 * [�Ԓl] �Ȃ�
 * [���] VDEC �R�}���h����s���āAtbl �Ŏw�肳�ꂽ�V���{���𕜍�����
 *        ���B�������ʂ� sceIpuGetVdecResult() �Ŏ擾���邱�Ƃ��ł�
 *        �܂��B
 */
#define sceIpuVDEC(tbl, fb) \
    DPUT_IPU_CMD(SCE_IPU_VDEC | ((tbl) << 26) | (fb))

/* ---------------------------------------------------------------------
 * sceIpuFDEC
 * ---------------------------------------------------------------------
 * [����] void sceIpuFDEC(int fb)
 * [����] fb     Forward Bit
 * [�Ԓl] �Ȃ�
 * [���] FDEC �R�}���h����s���ČŒ蒷�f�[�^�𕜍����܂��B
 *        �������ʂ� sceIpuGetFdecResult() �Ŏ擾���邱�Ƃ��ł��܂��B
 */
#define sceIpuFDEC(fb) DPUT_IPU_CMD(SCE_IPU_FDEC | (fb))

/* ---------------------------------------------------------------------
 * sceIpuSETIQ
 * ---------------------------------------------------------------------
 * [����] void sceIpuSETIQ(int iqm, int fb)
 * [����]
 *      iqm  Intra IQ Matrix
 *           SCE_IPU_SETIQ_INTRA(0)    : �C���g���ʎq���}�g���N�X
 *           SCE_IPU_SETIQ_NONINTRA(1) : ��C���g���ʎq���}�g���N�X
 *      fb   Forward Bit
 * 
 * [�Ԓl] �Ȃ�
 * [���] SETIQ �R�}���h����s���� IQ �e�[�u����ݒ肵�܂��B
 */
#define sceIpuSETIQ(iqm,  fb) \
    DPUT_IPU_CMD(SCE_IPU_SETIQ | ((iqm) << 27) | (fb))

/* ---------------------------------------------------------------------
 * sceIpuSETVQ
 * ---------------------------------------------------------------------
 * [����] void sceIpuSETVQ(void)
 * [����] �Ȃ�
 * [�Ԓl] �Ȃ�
 * [���] SETVQ �R�}���h����s���� VQCLUT �e�[�u����ݒ肵�܂��B
 */
#define sceIpuSETVQ() DPUT_IPU_CMD(SCE_IPU_SETVQ)

/* ---------------------------------------------------------------------
 * sceIpuCSC
 * ---------------------------------------------------------------------
 * [����] void sceIpuCSC(int ofm, int dte, int mbc)
 * [����]
 *      ofm  Output Format
 *           SCE_IPU_CSC_RGB32(0)    : RGB32
 *           SCE_IPU_CSC_RGB16(1)    : RGB16
 *      dte  Dither Enable
 *           SCE_IPU_CSC_NODITHER(0) : �f�B�U�Ȃ�
 *           SCE_IPU_CSC_DITHER(1)   : �f�B�U����
 *           (ofm = RGB16 �̂Ƃ��̂ݗL��)
 *      mbc  Macroblock Count �ϊ�����}�N���u���b�N��
 * [�Ԓl] �Ȃ�
 * [���] CSC �R�}���h����s���ĐF��Ԃ̕ϊ���s���܂��B
 */
#define sceIpuCSC(ofm, dte, mbc) \
    DPUT_IPU_CMD(SCE_IPU_CSC | ((ofm) << 27) | ((dte) << 26) | (mbc))

/* ---------------------------------------------------------------------
 * sceIpuPACK
 * ---------------------------------------------------------------------
 * [����] void sceIpuPACK(int ofm, int dte, int mbc)
 * [����]
 *      ofm  Output Format
 *           SCE_IPU_PACK_INDX4(0)    : INDX4
 *           SCE_IPU_PACK_RGB16(1)    : RGB16
 *      dte  Dither Enable
 *           SCE_IPU_PACK_NODITHER(0) : �f�B�U�Ȃ�
 *           SCE_IPU_PACK_DITHER(1)   : �f�B�U����
 *      mbc  Macroblock Count �ϊ�����}�N���u���b�N��
 * [�Ԓl] �Ȃ�
 * [���] PACK �R�}���h����s���ăt�H�[�}�b�g�ϊ���s���܂��B
 */
#define sceIpuPACK(ofm, dte, mbc) \
    DPUT_IPU_CMD(SCE_IPU_PACK | ((ofm) << 27) | ((dte) << 26) | (mbc))

/* ---------------------------------------------------------------------
 * sceIpuSETTH
 * ---------------------------------------------------------------------
 * [����] void sceIpuSETTH(int th1, int th0)
 * [����]
 *      th1  �������X���V�����h
 *      th0  �����X���V�����h
 * [�Ԓl] �Ȃ�
 * [���] SETTH �R�}���h����s���ăX���V�����h�l��ݒ肵�܂��B
 *        ���̃X���V�����h�l�� CSC �R�}���h�ŐF�ϊ���s���ۂɎg�p����
 *        �܂��B
 */
#define sceIpuSETTH(th1, th0) \
    DPUT_IPU_CMD(SCE_IPU_SETTH | ((th1) << 16) | (th0))

/* ---------------------------------------------------------------------
 * sceIpuGetFVdecResult
 * ---------------------------------------------------------------------
 * [����] u_int sceIpuGetFVdecResult(void)
 * [����] �Ȃ�
 * [�Ԓl] ���O�� FDEC �R�}���h�܂��� VDEC �R�}���h�ŕ������ꂽ�f�[�^
 * [���] ���O�Ɏ��s���ꂽ FDEC �R�}���h�܂��� VDEC �R�}���h�̎��s����
 *        ��ǂݏo���܂��B
 */
#define sceIpuGetFVdecResult() DGET_IPU_CMD()

/* ---------------------------------------------------------------------
 * sceIpuReset
 * ---------------------------------------------------------------------
 * [����] void sceIpuReset(void)
 * [����] �Ȃ�
 * [�Ԓl] �Ȃ�
 * [���] IPU ����Z�b�g���܂��B
 */
#define sceIpuReset() DPUT_IPU_CTRL(IPU_CTRL_RST_M)

/* ---------------------------------------------------------------------
 * sceIpuIsBusy
 * ---------------------------------------------------------------------
 * [����] int sceIpuIsBusy(void)
 * [����] �Ȃ�
 * [�Ԓl]
 *      0 : ��~��
 *      ���̑� : ���쒆
 * [���] IPU �����쒆���ǂ�����Ԃ��܂��B
 */
#define sceIpuIsBusy() ((int)((int)DGET_IPU_CTRL() < 0))

/* ---------------------------------------------------------------------
 * sceIpuIsError
 * ---------------------------------------------------------------------
 * [����] int sceIpuIsError(void)
 * [����] �Ȃ�
 * [�Ԓl]
 *      0 : �G���[�Ȃ�
 *      ���̑� : �G���[����
 * [���] IPU �̏����r���ŃG���[�������������ǂ�����Ԃ��܂��B
 *        ���̒l�� IPU �R�}���h����s���邽�тɎ����I�ɃN���A����܂��B
 */
#define sceIpuIsError() ((int)(DGET_IPU_CTRL() & IPU_CTRL_ECD_M))

/* ---------------------------------------------------------------------
 * sceIpuSync
 * ---------------------------------------------------------------------
 * [����] int sceIpuSync(int mode, u_short timeout)
 * [����]
 *     mode:
 * 	0: IPU �����쒆�ł���ԃu���b�N���܂��B
 * 	1: �����ɏI�����A���̂Ƃ��̃X�e�[�^�X��Ԃ��܂��B
 *	   ����́AsceIpuIsBusy() �Ɠ�������ƂȂ�܂��B
 * 
 *     timeout:
 * 	mode = 0 �̂Ƃ��̃^�C���A�E�g�l��w�肵�܂��B
 * 	�w�肷��l�̒P�ʂ� Horizontal line �J�E���g�ŁA
 *      �L���Ȓl�͈̔͂�
 *             0 <= timeout <= 65535 
 *      �ł��B
 * 
 * 	timeout = 0: ���C�u�����Ńf�t�H���g�̃^�C���A�E�g�l��
 * 		     �g�p���܂��B
 * 	timeout > 0: �w�肳���l��^�C���A�E�g�l�Ƃ��Ďg�p���܂��B
 *
 * [�Ԓl]
 *    mode = 0 �̂Ƃ�
 *       0 �ȏ�̒l: ����I��
 *       ���̒l:     �ُ�I��(�^�C���A�E�g����)
 *
 *    mode = 1 �̂Ƃ�
 *       0: IPU �����쒆�łȂ�
 *       ���̒l: IPU �����쒆
 *
 * [���] IPU �����쒆���ǂ����𔻒f���AIPU �̓���I����҂�����A
 *        IPU �̏�Ԃ�Ԃ����肵�܂��B
 */
int sceIpuSync(int mode, u_short timeout);

/* ---------------------------------------------------------------------
 * sceIpuStopDMA
 * ---------------------------------------------------------------------
 * [����] void sceIpuStopDMA(sceIpuDmaEnv *env)
 * [����] env  �����Ԃ�ۑ�����\���̕ϐ��ւ̃|�C���^
 *
 *     typedef struct {
 *         u_int d4madr; // ��~�����Ƃ��� D4_MADR ���W�X�^�̒l
 *         u_int d4tadr; // ��~�����Ƃ��� D4_TADR ���W�X�^�̒l
 *         u_int d4qwc;  // ��~�����Ƃ��� D4_QWC ���W�X�^�̒l
 *         u_int d4chcr; // ��~�����Ƃ��� D4_CHCR ���W�X�^�̒l
 *         u_int d3madr; // ��~�����Ƃ��� D3_MADR ���W�X�^�̒l
 *         u_int d3qwc;  // ��~�����Ƃ��� D3_QWC ���W�X�^�̒l
 *         u_int d3chcr; // ��~�����Ƃ��� D3_CHCR ���W�X�^�̒l
 *         u_int ipubp;  // ��~�����Ƃ��� IPU_BP ���W�X�^�̒l
 *         u_int ipuctrl;// ��~�����Ƃ��� IPU_CTRL ���W�X�^�̒l
 *     } sceIpuDmaEnv;
 *
 * [�Ԓl] �Ȃ�
 * [���] toIPU(ch-4) ����� fromIPU(ch-3) �� DMA ����S�ɒ�~���A
 *        ������ DMA�̏�Ԃ���� IPU �̓����Ԃ�ۑ����܂��B
 */
void sceIpuStopDMA(sceIpuDmaEnv *env);

/* ---------------------------------------------------------------------
 * sceIpuRestartDMA
 * ---------------------------------------------------------------------
 * [����] void sceIpuRestartDMA(sceIpuDmaEnv *env)
 * [����] env  DMA ����� IPU �̏�Ԃ�ۑ������\���̕ϐ��̃|�C���^
 * [�Ԓl] �Ȃ�
 * [���] �ۑ����ꂽ DMA ����� IPU �̏�Ԃɏ]���āAtoIPU(ch-4) �����
 *        fromIPU(ch-3) �� DMA ��ĊJ����B
 */
void sceIpuRestartDMA(sceIpuDmaEnv *env);

#ifdef __cplusplus
}
#endif

#endif /* _LIBIPU_H_ */

