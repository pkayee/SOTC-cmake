/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0.1
 $Id: sceerrno.h,v 1.31 2004/02/26 04:50:20 kaol Exp $
 */
/* 
 * Emotion Engine Library / I/O Processor Library
 *
 * Copyright (C) 2004 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 *
 * sceerrno.h - common error number definition and utilities
 *
 *      Date            Design      Log
 *  ----------------------------------------------------
 *      2002-09-11      style       initial draft
 *      2002-09-13      style       revised
 *      2002-09-17      style       official first version
 *      2002-10-15      style       solve EE/IOP diffs
 *      2002-10-18      style       lib. prefix BNNETCNF added
 *      2002-10-20      style       `SCE_ETIMER' is added
 *      2002-10-22      style       `SCE_' prefixed standard errno in sceerr.h
 *      2002-10-23      style       0x9004-9020 are added
 *      2003-04-03      style       `SCE_EHANDLER' is added
 *      2003-04-24      style       lib. prefix SDSQ, ERX TIMER added
 *      2003-04-24      style       `SCE_E{INT,DMA}_HANDLER' are added
 *      2003-04-25      style       0x9024-9039 are added
 *      2003-05-01      style       `SCE_E{ILLEGAL_CONTEXT, CPUDI}' are added
 *      2003-10-02      style       lib. prefix STDIO, MC are added
 *      2003-10-02      style       `SCE_EVERSION' is added
 *      2003-10-14      style       `SCE_ERPC' is added
 *      2003-12-01      style       `SCE_EUSB' is added
 *      2003-12-01      style       0x903a-903c are added
 *      2004-02-24      style       `SCE_EREGISTER' is added
 *      2004-02-24      style       `SCE_ERROR_PREFIX_SESQ2' is added
 *      2004-02-26      style       `SCE_E{CAN_NOT_PLAY,NOT_PLAYED}' are added
 */

#ifndef _SCE_ERRNO_H
#define _SCE_ERRNO_H

#include <errno.h>
#ifdef R3000
#include <kerror.h>		/* IOP kernel original error no. */
#endif

/*
 * ����`�G���[�ԍ��̒�`:
 *     errno.h �� EE/IOP �ɂ����鍷�ق�z��
 */
#ifndef EFORMAT
#define EFORMAT		47
#endif
#ifndef EUNSUP
#define EUNSUP		48
#endif
#ifndef ENOSHARE
#define ENOSHARE	136
#endif

/*
 * `SCE_' �v���t�B�b�N�X�t���W���G���[�ԍ�
 */
#include <sceerr.h>

/*
 * SCE �Ǝ���`�G���[�ԍ�:
 * errno.h/kerror.h ����`�G���[�ԍ� (���� 16 �r�b�g: SCE_EBASE..0xffff)
 *     errno.h:         0-1xx
 *     kerror.h(IOP): 100-4xx
 */

#define SCE_EBASE		0x8000		/* 32768 (decimal) */

/* �Ώۂ��ėp�ȃG���[ */
#define SCE_EINIT		0x8001		/* �������������s���Ă��Ȃ�	*/
#define SCE_EID			0x8002		/* ID �����݂��Ȃ�		*/
#define SCE_ESEMAPHORE		0x8003		/* �Z�}�t�H�������s���Ȃ�	*/
#define SCE_ESEMA		SCE_ESEMAPHORE
#define SCE_ETHREAD		0x8004		/* �X���b�h�������s���Ȃ�	*/
#define SCE_ETIMER		0x8005		/* �^�C�}�[/�A���[���������s���Ȃ� */
#define SCE_EHANDLER		0x8006		/* �n���h���o�^�������s���Ȃ�	*/
#define SCE_EILLEGAL_CONTEXT	0x8007		/* ��O�E���荞�݃n���h������̌Ăяo�� */
#define SCE_ECPUDI		0x8008		/* ���Ɋ��荞�݋֎~������	*/
#define	SCE_EVERSION		0x8009		/* ���W���[���̃o�[�W�����s���� */
#define	SCE_ERPC		0x800a		/* SIF RPC�̔��s���s���Ȃ� */
#define SCE_EUSB		0x800b		/* USB �ʐM���ُ�		*/
#define SCE_EREGISTER		0x800c		/* �o�^�������s���Ă��Ȃ�	*/

/* ���C�u�����ˑ��ȃG���[ */
#define SCE_EBASE_LIB		0x9000		/* 36864 (decimal) */

#define SCE_EDEVICE_BROKEN	0x9001		/* �f�o�C�X�j���̉\��		*/
#define SCE_EFILE_BROKEN	0x9002		/* �t�@�C���܂��̓f�B���N�g���j���̉\�� */
#define SCE_ENEW_DEVICE		0x9003		/* �V�K�f�o�C�X���o		*/
#define SCE_EMDEPTH		0x9004		/* �f�B���N�g�����[�߂���	*/

#define SCE_ENO_PROGRAM		0x9005		/* �v���O�����`�����N������	*/
#define SCE_ENO_SAMPLESET	0x9006		/* �T���v���Z�b�g�`�����N������	*/
#define SCE_ENO_SAMPLE		0x9007		/* �T���v���`�����N������	*/
#define SCE_ENO_VAGINFO		0x9008		/* VAGInfo�`�����N������	*/
#define SCE_ENO_SBADDR		0x9009		/* �X�v���b�g�u���b�N�̃A�h���X��񂪖��� */
#define SCE_EBAD_PNUM		0x9010		/* �v���O�����i���o�[�͔͈͊O	*/
#define SCE_ENO_PNUM		0x9011		/* �v���O�����i���o�[�͖��g�p	*/
#define SCE_EBAD_SSNUM		0x9012  	/* �T���v���Z�b�g�i���o�[�͔͈͊O */
#define SCE_ENO_SSNUM		0x9013  	/* �T���v���Z�b�g�i���o�[�͖��g�p */
#define SCE_EBAD_SPNUM		0x9014  	/* �T���v���i���o�[�͔͈͊O	*/
#define SCE_ENO_SPNUM		0x9015  	/* �T���v���i���o�[�͖��g�p	*/
#define SCE_EBAD_VAGNUM		0x9016  	/* VAGInfo�i���o�[�͔͈͊O	*/
#define SCE_ENO_VAGNUM		0x9017  	/* VAGInfo�i���o�[�͖��g�p	*/
#define SCE_EBAD_SBNUM		0x9018  	/* �X�v���b�g�u���b�N�i���o�[�͔͈͊O */
#define SCE_EVAGINFO_NOISE	0x9019  	/* VAGInfo���w������VAG�̓m�C�Y�ł��� */
#define SCE_ENO_SPLITNUM	0x9020  	/* �X�v���b�g�i���o�[�͖��g�p	*/

#define SCE_EINT_HANDLER	0x9021  	/* ���荞�݃n���h���������s��	*/
#define SCE_EDMA_HANDLER	0x9022  	/* DMA ���荞�݃n���h���������s�� */
/*				0x9023	*/ 	/* �V�X�e���\��			*/

#define SCE_ENO_MIDI            0x9024		/* Midi�`�����N������		*/
#define SCE_ENO_SONG            0x9025		/* Song�`�����N������		*/
#define SCE_ENO_MIDINUM         0x9026		/* Midi�f�[�^�u���b�N�i���o�[�͖��g�p */
#define SCE_ENO_SONGNUM         0x9027		/* Song�i���o�[�͖��g�p		*/
#define SCE_ENO_COMPTABLE       0x9028		/* ���k�e�[�u��������		*/
#define SCE_EBAD_COMPTABLEINDEX 0x9029		/* ���k�e�[�u���C���f�b�N�X�͔͈͊O */
#define SCE_EBAD_POLYKEYDATA    0x902a		/* �|���t�H�j�b�N�L�[�v���b�V���[�͕s�� */

#define SCE_ELINKERROR		0x902b		/* ���[�h�������W���[�����K�v�Ƃ���풓���C�u���������݂��Ȃ� */
#define SCE_ELINKERR		SCE_ELINKERROR
#define SCE_EILLEGAL_OBJECT	0x902c		/* �I�u�W�F�N�g�t�@�C���̌`�����������Ȃ� */
#define SCE_EUNKNOWN_MODULE 	0x902d		/* �w�肵�����W���[����������Ȃ� */
#define SCE_EMEMINUSE 		0x902e		/* �w�肵���A�h���X�͊��Ɏg�p��	*/
#define SCE_EALREADY_STARTED	0x902f		/* �w�肵�����W���[���͊��ɃX�^�[�g���Ă��� */
#define SCE_ENOT_STARTED	0x9030		/* �w�肵�����W���[���̓X�^�[�g���Ă��Ȃ� */
#define SCE_EALREADY_STOPPING	0x9031		/* �w�肵�����W���[���̓X�g�b�v������ */
#define SCE_EALREADY_STOPED	0x9032		/* �w�肵�����W���[���͊��ɃX�g�b�v���Ă��� */
#define SCE_ENOT_STOPPED 	0x9033		/* �w�肵�����W���[���̓X�g�b�v���Ă��Ȃ� */
#define SCE_ECAN_NOT_STOP	0x9034		/* ���W���[���̒�~�͏o���Ȃ����� */
#define SCE_ENOT_REMOVABLE	0x9035		/* �w�肵�����W���[���͍폜�\�ł͂Ȃ� */
#define SCE_ELIBRARY_FOUND 	0x9036		/* ���C�u�����͊��ɓo�^����Ă��� */
#define SCE_ELIBRARY_NOTFOUND 	0x9037		/* ���C�u�����͓o�^����Ă��Ȃ�	*/
#define SCE_ELIBRARY_INUSE	0x9038		/* ���C�u�����͎g�p��		*/
#define SCE_EILLEGAL_LIBRARY 	0x9039		/* ���C�u�����w�b�_���ُ�	*/

#define SCE_EBAD_FRAME		0x903a		/* ���݂̃t���[���͕s��		*/
#define SCE_ENO_STREAM		0x903b		/* �J�������X�g���[����ԂłȂ�	*/
#define SCE_ENO_CAMERA		0x903c		/* �J�������ڑ�����Ă��Ȃ�	*/

#define SCE_ECAN_NOT_PLAY	0x903d		/* ���t���s���Ȃ�		*/
#define SCE_ECANT_PLAY		SCE_ECAN_NOT_PLAY
#define SCE_ENOT_PLAYED		0x903e		/* ���t����Ă��Ȃ�		*/

/* 0xa000-0xa0ff */ /* DNAS�\�� */


/*
 * �ėp����I���}�N��
 */
#define SCE_OK	0

/*
 * ���C�u�������ʃv���t�B�b�N�X
 */

/* �G���[���ʃr�b�g */
#define SCE_ERROR_PREFIX_ERROR		0x80000000

/* �v���t�B�b�N�X�E�V�t�g�� */
#define SCE_ERROR_PREFIX_SHIFT		16

/* �G���[�E�r�b�g�}�X�N */
#define SCE_ERROR_MASK_LIBRARY_PREFIX	0x7fff0000
#define SCE_ERROR_MASK_ERRNO		0x0000ffff

/* ���C�u�������ʃv���t�B�b�N�X�l */
#define SCE_ERROR_PREFIX_MC2	  0x01010000 /* �������[�J�[�h        libmc2  */
#define SCE_ERROR_PREFIX_BNNETCNF 0x01020000 /* PS BB Navi. Net conf. bnnetcf */
#define SCE_ERROR_PREFIX_SDHD	  0x01030000 /* Sound Data .HD        libsdhd */
#define SCE_ERROR_PREFIX_SDSQ	  0x01040000 /* Sound Data .SQ        sdsq    */
#define SCE_ERROR_PREFIX_ERX	  0x01050000 /* ERX		      liberx  */
#define SCE_ERROR_PREFIX_TIMER	  0x01060000 /* Timer                 libtimer */
#define SCE_ERROR_PREFIX_STDIO	  0x01070000 /* �W�����o��            libkernl */
#define SCE_ERROR_PREFIX_MC	  0x01080000 /* �������[�J�[�h        libmc   */
#define SCE_ERROR_PREFIX_SESQ2	  0x01090000 /* SESQ2                 modsesq2 */

/*
 * ���[�e�B���e�B
 */ 

/* for library author */
#define SCE_ERROR_ENCODE(prefix,err) (SCE_ERROR_PREFIX_ERROR | (prefix) | (err))

/* for user */
#define SCE_ERROR_ERRNO(err)      ((err) & SCE_ERROR_MASK_ERRNO)
#define SCE_ERROR_LIB_PREFIX(err) ((err) & SCE_ERROR_MASK_LIBRARY_PREFIX)

#endif /* _SCE_ERRNO_H */
