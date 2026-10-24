/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 $Id: hd.h,v 1.21 2003/09/12 05:23:13 tokiwa Exp $
 */
/*
 * Copyright (C) 1999, 2000, 2002, 2003 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 *
 * format/sound/hd.h - .hd file format
 *
 *	See "sformat.pdf" or converted HTML file for more details.
 */

#ifndef _SCE_FORMAT_SOUND_HD_H
#define _SCE_FORMAT_SOUND_HD_H

/*
 * typedef char			S8;	  8bit   signed
 * typedef unsigned char	U8;	  8bit unsigned
 * typedef short		S16;	 16bit   signed
 * typedef unsigned short	U16;	 16bit unsigned
 * typedef int			S32;	 32bit   signed
 * typedef unsigned int		U32;	 32bit unsigned
 *
 *  �t�@�C���I�t�Z�b�g(�t�@�C���̐擪����̃o�C�g��)
 * typedef U32 FOFST;
 * #define NO_FOFST ((FOFST)-1)
 *  �`�����N�I�t�Z�b�g(�`�����N�̐擪����̃o�C�g��)
 * typedef U32 COFST;
 * #define NO_COFST ((COFST)-1)
 *  �`�����N��̃I�t�Z�b�g(�Y���`�����N�̐擪�����byte��)
 * typedef U32 SOFST;
 * #define NO_SOFST ((SOFST)-1)
 *  �|�W�V�����I�t�Z�b�g(�`�����N��̌��݂̈ʒu����̃o�C�g��)
 * typedef U32 POFST;
 * #define NO_POFST ((POFST)-1)
 *  �`�����N��̌��݂̈ʒu����̃I�t�Z�b�g
 * typedef U32 TOFST;
 * #define NO_TOFST ((TOFST)-1)
 *  �`�����N�C���f�b�N�X(�`�����N��̍\���̂ւ̃C���f�b�N�X�ԍ�)
 * typedef U16 CINDEX;
 * #define NO_CINDEX ((CINDEX)-1)
 *  �`�����N��̍\���̂ւ̃C���f�b�N�X�i���o�[
 * typedef U16 SINDEX;
 * #define NO_SINDEX ((SINDEX)-1)
 */

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthProgramParam.progAttr
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteAttr
 */
#define SCEHD_ROUND_PAN			0x01	/* �p���|�b�g�̑��Εω��ɂ����ċt�����	*/
#define SCEHD_REVERSE_PHASE_VOL		0x02	/* �t���{�����[���w��			*/

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthProgramParam.progLfoWave
 *	sceHardSynthProgramParam.progLfoWave2
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNotePitchLfoWave
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteAmpLfoWave
 */
#define SCEHD_LFO_NON			0	/* LFO �Ȃ�			*/
#define SCEHD_LFO_SAWUP			1	/* �E�オ�苘�g			*/
#define SCEHD_LFO_SAWDOWN		2	/* �E�����苘�g			*/
#define SCEHD_LFO_TRIANGLE		3	/* �O�p�g			*/
#define SCEHD_LFO_SQUEARE		4	/* ��`�g			*/
#define SCEHD_LFO_NOISE			5	/* �m�C�Y			*/
#define SCEHD_LFO_SIN			6	/* �����g			*/
#define SCEHD_LFO_USER			0x80	/* ���[�U��`			*/

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthSampleParam.sampleLfoAttr
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteLfoAttr
 */
/* PITCH LFO */
#define SCEHD_LFO_PITCH_KEYON		0x01	/* �g���K�[���L�[�I����			*/
#define SCEHD_LFO_PITCH_KEYOFF		0x02	/* �g���K�[���L�[�I�t��			*/
#define SCEHD_LFO_PITCH_BOTH		0x04	/* �g���K�[���L�[�I���ƃL�[�I�t��	*/
/* Amp. LFO */
#define SCEHD_LFO_AMP_KEYON		0x10	/* �g���K�[���L�[�I����			*/
#define SCEHD_LFO_AMP_KEYOFF		0x20	/* �g���K�[���L�[�I�t��			*/
#define SCEHD_LFO_AMP_BOTH		0x40	/* �g���K�[���L�[�I���ƃL�[�I�t��	*/

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthVagParam.vagAttribute
 */
#define SCEHD_VAG_1SHOT			0x00	/* No loop = 1 shot	*/
#define SCEHD_VAG_LOOP			0x01	/* Loop			*/

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthSplitBlock.splitRangeLow
 *	sceHardSynthSplitBlock.splitRangeHigh
 *	sceHardSynthSampleParam.velRangeLow
 *	sceHardSynthSampleParam.velRangeHigh
 */
#define SCEHD_CROSSFADE			0x80	/* �N���X�t�F�[�h�̎w�� */

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthSampleParam.sampleSpuAttr
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteSpuAttr
 */
#define SCEHD_SPU_DIRECTSEND_L		0x01	/* SPU2 [VMIXL0/1] ���W�X�^	*/
#define SCEHD_SPU_DIRECTSEND_R		0x02	/* SPU2 [VMIXR0/1] ���W�X�^	*/
#define SCEHD_SPU_EFFECTSEND_L		0x04	/* SPU2 [VMIXEL0/1] ���W�X�^	*/
#define SCEHD_SPU_EFFECTSEND_R		0x08	/* SPU2 [VMIXER0/1] ���W�X�^	*/
#define SCEHD_SPU_CORE_0		0x10	/* SPU2 CORE0�I��		*/
#define SCEHD_SPU_CORE_1		0x20	/* SPU2 CORE1�I��		*/

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthSampleSetParam.velCurve
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteVelCurve
 */
#define SCEHD_VEL_CURVE_B		0	/* B �J�[�u	*/
#define SCEHD_VEL_CURVE_B_REV		1
#define SCEHD_VEL_CURVE_A		2	/* A �J�[�u	*/
#define SCEHD_VEL_CURVE_A_REV		3
#define SCEHD_VEL_CURVE_C		4	/* C �J�[�u	*/
#define SCEHD_VEL_CURVE_C_REV		5

/*
 * �ȉ��̍\���̃����o�ŗ��p:
 *	sceHardSynthSampleParam.velFollowPitchVelCurve
 *	sceHardSynthSampleParam.velFollowAmpVelCurve
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteVelFollowPitchCurve
 *	sceHardSynthSeTimbreNoteBlock.seTimbreNoteVelFollowAmpCurve
 */
#define SCEHD_VELFOLLOW_CURVE_B		0	/* B �J�[�u	*/
#define SCEHD_VELFOLLOW_CURVE_B_REV	1
#define SCEHD_VELFOLLOW_CURVE_A		2	/* A �J�[�u	*/
#define SCEHD_VELFOLLOW_CURVE_A_REV	3
#define SCEHD_VELFOLLOW_CURVE_C		4	/* C �J�[�u	*/
#define SCEHD_VELFOLLOW_CURVE_C_REV	5
#define SCEHD_VELFOLLOW_CURVE_BB	6	/* �܂��	*/
#define SCEHD_VELFOLLOW_CURVE_BB_REV	7
#define SCEHD_VELFOLLOW_CURVE_CA	8	/* C+A �J�[�u	*/
#define SCEHD_VELFOLLOW_CURVE_AC	9	/* A+C �J�[�u	*/

/****************************************************************
 * VAGInfo Chunk
 ****************************************************************/
typedef struct {
    unsigned int   vagOffsetAddr;	/*FOFST �g�`�f�[�^�̈ʒu		*/
    unsigned short vagSampleRate;	/*U16 �T���v�����O���[�g		*/
    unsigned char  vagAttribute;	/*U8 ���[�v�t���O			*/
    unsigned char  dmy;			/*U8 �\��̈�				*/
} sceHardSynthVagParam;

typedef struct {
    unsigned int   Creator;		/*U32 �쐬�҃R�[�h:   'SCEI'		*/
    unsigned int   Type;		/*U32 �`�����N�^�C�v: 'Vagi'		*/
    unsigned int   chunkSize;		/*U32 �`�����N�T�C�Y			*/
    unsigned int   maxVagInfoNumber;	/*U32 VagInfo�i���o�[�̍ő�l		*/

    unsigned int   vagInfoOffsetAddr[0];/*COFST VagInfo�e�[�u���ւ̃I�t�Z�b�g	*/
    /* sceHardSynthVagParam vagInfoParam[] */
} sceHardSynthVagInfoChunk;

/****************************************************************
 * Sample Chunk
 ****************************************************************/
typedef struct {
    unsigned short VagIndex;			/*CINDEX VagInfoChunk�ł̃C���f�b�N�X�i���o�[(NO_CINDEX:SPU�m�C�Y) */

    unsigned char  velRangeLow;			/*U8 ���������x���V�e�B(0-127)				*/
    unsigned char  velCrossFade;		/*U8 �N���X�t�F�C�h�J�n�x���V�e�B(0-127)		*/
    unsigned char  velRangeHigh;		/*U8 ��������x���V�e�B(0-127)				*/

    char	   velFollowPitch;		/*S8 �x���V�e�B�ɂ��s�b�`LFO�̕ω���(��1)(0-127)	*/
    unsigned char  velFollowPitchCenter;	/*U8 velFollowPitch�̌��ʂ�0�ɂȂ�x���V�e�B(0-127)	*/
    unsigned char  velFollowPitchVelCurve;	/*U8 �s�b�`LFO�ɑ΂���x���V�e�B�J�[�u			*/

    char	   velFollowAmp;		/*S8 �x���V�e�B�ɂ��A���vLFO�̕ω���			*/
    unsigned char  velFollowAmpCenter;		/*U8 velFollowAmp�̌��ʂ�0�ɂȂ�x���V�e�B(0-127)	*/
    unsigned char  velFollowAmpVelCurve;	/*U8 �A���vLFO�ɑ΂���x���V�e�B�J�[�u			*/

    unsigned char  sampleBaseNote;		/*U8 �x�[�X�ƂȂ�m�[�g�i���o�[(0-127)			*/
    char	   sampleDetune;		/*S8 �f�B�`���[��(��1)(0-127)				*/
    char	   samplePanpot;		/*S8 �p���|�b�g(0-64-127=��-����-�E;���͋t��)		*/
    unsigned char  sampleGroup;			/*U8 �O���[�v(0-127;0�̓O���[�v�Ȃ�)			*/
    unsigned char  samplePriority;		/*U8 �v���C�I���e�B(127�Ńv���C�I���e�B�ő�)		*/
    unsigned char  sampleVolume;		/*U8 �{�����[��(0-128)					*/
    unsigned char  dmy;				/*U8 �\��̈�						*/

    unsigned short sampleAdsr1;			/*U16 �G���x���[�v ADSR1				*/
    unsigned short sampleAdsr2;			/*U16 �G���x���[�v ADSR2				*/

    char	   keyFollowAr;			/*S8 AR��1�I�N�^�[�u���̕ω���				*/
    unsigned char  keyFollowArCenter;		/*U8 keyFollowAr�̌��ʂ�0�ɂȂ�m�[�g(0-127)		*/
    char	   keyFollowDr;			/*S8 DR��1�I�N�^�[�u���̕ω���				*/
    unsigned char  keyFollowDrCenter;		/*U8 keyFollowDr�̌��ʂ�0�ɂȂ�m�[�g(0-127)		*/
    char	   keyFollowSr;			/*S8 SR��1�I�N�^�[�u��R�̕ω���				*/
    unsigned char  keyFollowSrCenter;		/*U8 keyFollowSr�̌��ʂ�0�ɂȂ�m�[�g(0-127)		*/
    char	   keyFollowRr;			/*S8 RR��1�I�N�^�[�u���̕ω���				*/
    unsigned char  keyFollowRrCenter;		/*U8 keyFollowRr�̌��ʂ�0�ɂȂ�m�[�g(0-127)		*/
    char	   keyFollowSl;			/*S8 SL��1�I�N�^�[�u���̕ω���				*/
    unsigned char  keyFollowSlCenter;		/*U8 keyFollowSl�̌��ʂ�0�ɂȂ�m�[�g(0-127)		*/

    unsigned short samplePitchLfoDelay;		/*U16 Pitch LFO�f�B���C�^�C��(�P��:msec)		*/
    unsigned short samplePitchLfoFade;		/*U16 Pitch LFO�t�F�C�h�^�C��(�P��:msec)		*/
    unsigned short sampleAmpLfoDelay;		/*U16 Amp LFO�f�B���C�^�C��(�P��:msec)			*/
    unsigned short sampleAmpLfoFade;		/*U16 Amp LFO�t�F�C�h�^�C��(�P��:msec)			*/

    unsigned char  sampleLfoAttr;		/*U8 LFO�Ɋւ���Attribute				*/
    unsigned char  sampleSpuAttr;		/*U8 SPU�Ɋւ���Attribute				*/
} sceHardSynthSampleParam;
/* ��1: �P��: ������128���� */

typedef struct {
    unsigned int   Creator;			/*U32 �쐬�҃R�[�h:   'SCEI'				*/
    unsigned int   Type;			/*U32 �`�����N�^�C�v: 'Smpl'				*/
    unsigned int   chunkSize;			/*U32 �`�����N�T�C�Y					*/
    unsigned int   maxSampleNumber;		/*U32 �T���v���i���o�[�̍ő�l				*/

    unsigned int   sampleOffsetAddr[0];		/*COFST �T���v���e�[�u���ւ̃I�t�Z�b�g			*/
    /* sceHardSynthSampleRaram sampleParam[] */
} sceHardSynthSampleChunk;

/****************************************************************
 * Sample Set Chunk
 ****************************************************************/
typedef struct {
    unsigned char  velCurve;			/*U8 �x���V�e�B�J�[�u�^�C�v(for AMP LEVEL)		*/
    unsigned char  velLimitLow;			/*U8 ��������x���V�e�B					*/
    unsigned char  velLimitHigh;		/*U8 ���������x���V�e�B					*/
    unsigned char  nSample;			/*U8 ���̃T���v���Z�b�g�ɑ�����T���v���̌�		*/

    unsigned short sampleIndex[0];		/*CINDEX �T���v���`�����N�ł̃C���f�b�N�X�i���o�[	*/
} sceHardSynthSampleSetParam;

typedef struct {
    unsigned int   Creator;			/*U32 �쐬�҃R�[�h:   'SCEI'				*/
    unsigned int   Type;			/*U32 �`�����N�^�C�v: 'Sset'				*/
    unsigned int   chunkSize;			/*U32 �`�����N�T�C�Y					*/
    unsigned int   maxSampleSetNumber;		/*U32 �T���v���Z�b�g�i���o�[�̍ő�l			*/

    unsigned int   sampleSetOffsetAddr[0];	/*COFST �T���v���Z�b�g�e�[�u���ւ̃I�t�Z�b�g		*/
    /* sceHardSynthSampleSetParam sampleSetParam[] */
} sceHardSynthSampleSetChunk;

/****************************************************************
 * Program Chunk
 ****************************************************************/
typedef struct {
    unsigned short sampleSetIndex;		/*CINDEX �T���v���Z�b�g�`�����N�ł̃C���f�b�N�X�i���o�[	*/

    unsigned char  splitRangeLow;		/*U8 ���������m�[�g�i���o�[(0-127)			*/
    unsigned char  splitCrossFade;		/*U8 �N���X�t�F�C�h�J�n�m�[�g�i���o�[(0-127)		*/
    unsigned char  splitRangeHigh;		/*U8 ��������m�[�g�i���o�[(0-127)			*/
    unsigned char  splitNumber;			/*U8 �X�v���b�g�i���o�[(0-127)				*/

    unsigned short splitBendRangeLow;		/*U16 �x���h�����W-(��1)				*/
    unsigned short splitBendRangeHigh;		/*U16 �x���h�����W+(��1)				*/

    char	   keyFollowPitch;		/*S8 1�I�N�^�[�u���ɕω�����s�b�`LFO�̕ω���(��1)	*/
    unsigned char  keyFollowPitchCenter;	/*U8 keyFollowPitch �ɂ����ʂ�0�ɂȂ�m�[�g(0-127)	*/
    char	   keyFollowAmp;		/*S8 1�I�N�^�[�u���ɕω�����A���vLFO�̕ω���		*/
    unsigned char  keyFollowAmpCenter;		/*U8 keyFollowAmp �ɂ����ʂ�0�ɂȂ�m�[�g(0-127)	*/
    char	   keyFollowPan;		/*S8 1�I�N�^�[�u���ɕω�����p���|�b�g�̕ω���		*/
    unsigned char  keyFollowPanCenter;		/*U8 keyFollowPan �ɂ����ʂ�0�ɂȂ�m�[�g(0-127)	*/

    unsigned char  splitVolume;			/*U8 �X�v���b�g�{�����[��(0-128)			*/
    char	   splitPanpot;			/*S8 �X�v���b�g�p���|�b�g(0-64-127=��-����-�E;���͋t��)	*/
    char	   splitTranspose;		/*S8 �g�����X�|�[�Y(�P��:�m�[�g)			*/
    char	   splitDetune;			/*S8 �f�B�`���[��(��1)					*/
} sceHardSynthSplitBlock;
/* ��1: �P��: ������128���� */

typedef struct {
    unsigned int   splitBlockAddr;		/*POFST �X�v���b�g�u���b�N�ւ̃I�t�Z�b�g		*/

    unsigned char  nSplit;			/*U8 ���̃v���O�����ɑ����� splitBlock �̌�		*/
    unsigned char  sizeSplitBlock;		/*U8 �ЂƂ� splitBlock �̃T�C�Y			*/

    unsigned char  progVolume;			/*U8 �v���O�����{�����[��(0-128)			*/
    char	   progPanpot;			/*S8 �v���O�����p���|�b�g(0-64-127=��-����-�E;���͋t��)	*/
    char	   progTranspose;		/*S8 �g�����X�|�[�Y(�P��:�m�[�g)			*/
    char	   progDetune;			/*S8 �f�B�`���[��(��1)					*/
    char	   keyFollowPan;		/*S8 1�I�N�^�[�u���ɕω�����p���|�b�g�̕ω���		*/
    unsigned char  keyFollowPanCenter;		/*U8 keyFollowPan �ɂ����ʂ�0�ɂȂ�m�[�g(0-127)	*/
    unsigned char  progAttr;			/*U8 �v���O�����A�g���r���[�g				*/
    unsigned char  dmy;				/*U8 �\��̈�						*/

    unsigned char  progLfoWave;			/*U8 LFO�g�`(�s�b�`)					*/
    unsigned char  progLfoWave2;		/*U8 LFO�g�`(�A���v)					*/
    unsigned char  progLfoStartPhase;		/*U8 LFO�X�^�[�g�ʑ�(�s�b�`)(0-255:0-359��)		*/
    unsigned char  progLfoStartPhase2;		/*U8 LFO�X�^�[�g�ʑ�(�A���v)(0-255:0-359��)		*/
    unsigned char  progLfoPhaseRandom;		/*U8 LFO�����_���X�^�[�g�ʑ�(�s�b�`)(0-255:0-359��)	*/
    unsigned char  progLfoPhaseRandom2;		/*U8 LFO�����_���X�^�[�g�ʑ�(�A���v)(0-255:0-359��)	*/
    unsigned short progLfoFreq;			/*U16 LFO����(�s�b�`)(�P��:msec)			*/
    unsigned short progLfoFreq2;		/*U16 LFO����(�A���v)(�P��:msec)			*/
    short	   progLfoPitchDepth;		/*S16 �s�b�`���W�����[�V�����U��+(��1)			*/
    short	   progLfoPitchDepth2;		/*S16 �s�b�`���W�����[�V�����U��-(��1)			*/
    short	   progLfoMidiPitchDepth;	/*S16 MIDI�s�b�`���W�����[�V�����ő�U��+(��1)		*/
    short	   progLfoMidiPitchDepth2;	/*S16 MIDI�s�b�`���W�����[�V�����ő�U��-(��1)		*/
    char	   progLfoAmpDepth;		/*S8 �A���v���W�����[�V�����U��+			*/
    char	   progLfoAmpDepth2;		/*S8 �A���v���W�����[�V�����U��-			*/
    char	   progLfoMidiAmpDepth;		/*S8 MIDI���W�����[�V�����ő�U��+			*/
    char	   progLfoMidiAmpDepth2;	/*S8 MIDI���W�����[�V�����ő�U��-			*/

    sceHardSynthSplitBlock splitBlock[0];	/* �X�v���b�g�u���b�N (����)				*/
} sceHardSynthProgramParam;
/* ��1: �P��: ������128���� */

typedef struct {
    unsigned int   Creator;			/*U32 �쐬�҃R�[�h:   'SCEI'		*/
    unsigned int   Type;			/*U32 �`�����N�^�C�v: 'Prog'		*/
    unsigned int   chunkSize;			/*U32 �`�����N�T�C�Y			*/
    unsigned int   maxProgramNumber;		/*U32 �v���O�����i���o�[�̍ő�l	*/

    unsigned int   programOffsetAddr[0];	/*COFST �v���O�����ւ̃I�t�Z�b�g�A�h���X */
} sceHardSynthProgramChunk;

/****************************************************************
 * SE Timbre Chunk
 ****************************************************************/
typedef struct {
    unsigned short VagIndex;				/*CINDEX VAGInfo �`�����N�̃C���f�b�N�X		*/

    unsigned char  seTimbreNoteVelCurve;		/*U8 �m�[�g�x���V�e�B�J�[�u�^�C�v(0-5)		*/
    unsigned char  seTimbreNoteVolume;			/*U8 �m�[�g�{�����[��(0-128)			*/
    char	   seTimbreNotePanpot;			/*S8 �m�[�g�p���|�b�g(0-64-127=��-����-�E;���͋t��) */
    char	   seTimbreNoteTranspose;		/*S8 �m�[�g�g�����X�|�[�Y(�P�ʃm�[�g)		*/
    char	   seTimbreNoteDetune;			/*S8 �m�[�g�f�B�`���[��(��1)			*/
    unsigned char  seTimbreNoteGroup;			/*U8 �m�[�g�O���[�v(0-127;0�̓O���[�v�Ȃ�)	*/
    unsigned char  seTimbreNoteGroupLimit;		/*U8 �m�[�g�O���[�v����������~�b�g(0-48;0�̓��~�b�g�Ȃ�) */
    unsigned char  seTimbreNotePriority;		/*U8 �m�[�g�v���C�I���e�B			*/
    unsigned char  dmy0;				/*U8 �\��̈�					*/
    unsigned char  dmy1;				/*U8 �\��̈�					*/
    unsigned char  seTimbreNoteAttr;			/*U8 �m�[�g�A�g���r���[�g			*/
    unsigned char  seTimbreNoteSpuAttr;			/*U8 SPU Attribute				*/
    unsigned short seTimbreNoteAdsr1;			/*U16 ADSR1					*/
    unsigned short seTimbreNoteAdsr2;			/*U16 ADSR2					*/

    unsigned char  seTimbreNotePitchLfoWave;		/*U8  LFO �g�`(�s�b�`)				*/
    unsigned char  seTimbreNoteAmpLfoWave;		/*U8  LFO �g�`(�A���v)				*/
    unsigned char  seTimbreNotePitchLfoStartPhase;	/*U8  LFO �X�^�[�g�ʑ�(�s�b�`)(0-255:0-359��)	*/
    unsigned char  seTimbreNoteAmpLfoStartPhase;	/*U8  LFO �X�^�[�g�ʑ�(�A���v)(0-255:0-359��)	*/
    unsigned char  seTimbreNotePitchLfoRandomPhase;	/*U8  LFO �����_���X�^�[�g�ʑ�(�s�b�`)(0-255:0-359��) */
    unsigned char  seTimbreNoteAmpLfoRandomPhase;	/*U8  LFO �����_���X�^�[�g�ʑ�(�A���v)(0-255:0-359��) */
    unsigned short seTimbreNotePitchLfoCycle;		/*U16 LFO ����(�s�b�`)(�P��:msec)		*/
    unsigned short seTimbreNoteAmpLfoCycle;		/*U16 LFO ����(�A���v)(�P��:msec)		*/
    short	   seTimbreNotePitchLfoDepth;		/*S16 LFO �U��+(�s�b�`)(��1)			*/
    short	   seTimbreNotePitchLfoDepth2;		/*S16 LFO �U��-(�s�b�`)(��1)			*/
    char	   seTimbreNoteAmpLfoDepth;		/*S8  LFO �U��+(�A���v)				*/
    char	   seTimbreNoteAmpLfoDepth2;		/*S8  LFO �U��-(�A���v)				*/

    unsigned short seTimbreNotePitchLfoDelay;		/*U16 LFO �f�B���C�^�C��(�P��:msec)(�s�b�`)	*/
    unsigned short seTimbreNoteAmpLfoDelay;		/*U16 LFO �f�B���C�^�C��(�P��:msec)(�A���v)	*/
    unsigned short seTimbreNotePitchLfoFade;		/*U16 LFO �t�F�C�h�^�C��(�P��:msec)(�s�b�`)	*/
    unsigned short seTimbreNoteAmpLfoFade;		/*U16 LFO �t�F�C�h�^�C��(�P��:msec)(�A���v)	*/
    char	   seTimbreNoteVelFollowPitch;		/*S8 �x���V�e�B�ɂ��s�b�`LFO�̕ω���(-127..0..127)(��1) */
    char	   seTimbreNoteVelFollowAmp;		/*S8 �x���V�e�B�ɂ��A���vLFO�̕ω���(-127..0..127)	*/
    unsigned char  seTimbreNoteVelFollowPitchCenter;	/*U8 seTimbreNoteVelFollowPitch�̌��ʂ�0�ɂȂ�x���V�e�B(1-127)	*/
    unsigned char  seTimbreNoteVelFollowAmpCenter;	/*U8 seTimbreNoteVelFollowAmp�̌��ʂ�0�ɂȂ�x���V�e�B(1-127)	*/
    unsigned char  seTimbreNoteVelFollowPitchCurve;	/*U8 seTimbreNoteVelFollowPitch�̌��ʗʂ��߂邽�߂̃x���V�e�B�J�[�u(0-9) */
    unsigned char  seTimbreNoteVelFollowAmpCurve;	/*U8 seTimbreNoteVelFollowAmp�̌��ʗʂ��߂邽�߂̃x���V�e�B�J�[�u(0-9) */
    unsigned char  dmy;					/*U8 �\��̈�					*/
    unsigned char  seTimbreNoteLfoAttr;			/*U8 LFO Attribute				*/
} sceHardSynthSeTimbreNoteBlock;
/* ��1: �P��:������128���� */

typedef struct {
    unsigned int   seTimbreNoteBlockAddr;	/*POFST ���ʉ��e�B���o�[�m�[�g�̐擪�ւ̃I�t�Z�b�g	*/
    unsigned char  seTimbreNoteBlockSize;	/*U8 �ЂƂ̌��ʉ��h�����m�[�g�u���b�N�̃T�C�Y		*/
    unsigned char  seTimbreNoteStart;		/*U8 ���ʉ��e�B���o�[�X�^�[�g�m�[�g�i���o�[		*/
    unsigned char  seTimbreNoteEnd;		/*U8 ���ʉ��e�B���o�[�G���h�m�[�g�i���o�[		*/
    unsigned char  dmy;				/*U8 �\��̈�	*/

    sceHardSynthSeTimbreNoteBlock seTimbreNoteBlock[0];	/* ���ʉ��e�B���o�[�m�[�g�u���b�N(����)	*/
} sceHardSynthSeTimbreBlock;

typedef struct {
    unsigned int   maxSeTimbreNumber;	/*U32 ���ʉ��e�B���o�[�Z�b�g�ɑ�����
					  ���ʉ��e�B���o�[�i���o�[�̍ő�l	*/
    unsigned int   seTimbreOffsetAddr[0];/*COFST ���ʉ��e�B���o�[�ւ̃I�t�Z�b�g	*/
} sceHardSynthSeTimbreSetBlock;

typedef struct {
    unsigned int   Creator;		/*U32 �쐬�҃R�[�h:   'SCEI'	*/
    unsigned int   Type;		/*U32 �`�����N�^�C�v: 'Setb'	*/
    unsigned int   chunkSize;		/*U32 �`�����N�T�C�Y		*/
    unsigned int   maxSeTimbreSetNumber;/*U32 ���ʉ��e�B���o�[�Z�b�g�i���o�[�̍ő�l */

    unsigned int   seTimbreSetOffsetAddr[0];/*COFST ���ʉ��e�B���o�[�Z�b�g�ւ̃I�t�Z�b�g */
} sceHardSynthSeTimbreChunk;

/****************************************************************
 * Header Chunk
 ****************************************************************/
typedef struct {
    unsigned int   Creator;		/*U32 �쐬�҃R�[�h:   'SCEI'	*/
    unsigned int   Type;		/*U32 �`�����N�^�C�v: 'Head'	*/
    unsigned int   chunkSize;		/*U32 �`�����N�T�C�Y		*/
    unsigned int   headerSize;		/*U32 �w�b�_�t�@�C���T�C�Y	*/
    unsigned int   bodySize;		/*U32 �{�f�B�t�@�C���T�C�Y	*/

    unsigned int   programChunkAddr;	/*FOFST �I�t�Z�b�g�A�h���X: �v���O�����`�����N		*/
    unsigned int   sampleSetChunkAddr;	/*FOFST �I�t�Z�b�g�A�h���X: �T���v���Z�b�g�`�����N	*/
    unsigned int   sampleChunkAddr;	/*FOFST �I�t�Z�b�g�A�h���X: �T���v���`�����N		*/
    unsigned int   vagInfoChunkAddr;	/*FOFST �I�t�Z�b�g�A�h���X: VagInfo�`�����N		*/
    unsigned int   seTimbreChunkAddr;	/*FOFST �I�t�Z�b�g�A�h���X: ���ʉ��e�B���o�[�`�����N	*/
} sceHardSynthHeaderChunk;

/****************************************************************
 * Version Chunk
 ****************************************************************/
typedef struct {
    unsigned int   Creator;		/*U32 �쐬�҃R�[�h:   'SCEI'	*/
    unsigned int   Type;		/*U32 �`�����N�^�C�v: 'Vers'	*/
    unsigned int   chunkSize;		/*U32 �`�����N�T�C�Y		*/
    unsigned short reserved;		/*U16 �\��̈�			*/
    unsigned char  versionMajor;	/*U8 ���W���[�o�[�W����		*/
    unsigned char  versionMinor;	/*U8 �}�C�i�[�o�[�W����		*/
} sceHardSynthVersionChunk;

#endif /* _SCE_FORMAT_SOUND_HD_H */
