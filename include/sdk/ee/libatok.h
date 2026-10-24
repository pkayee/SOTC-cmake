/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 */
/* 
 *                      Emotion Engine Library
 *                          Version 1.0
 *                           Shift-JIS
 *
 *      Copyright (C) 2002 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                       libatok - atok_top.h
 *                           ATOK Library
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *      1.00            Nov,26,2001      kataoka     first ci
 */

#ifndef _LIBATOK_H_
#define _LIBATOK_H_

#if defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif	/* defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus) */

/* ATOK�̂��߂̃R���e�L�X�g���` */
#define SCE_ATOK_CONTEXT_SIZE (4*1024)
typedef unsigned char sceAtokContext[ SCE_ATOK_CONTEXT_SIZE ] __attribute__((aligned(64)));

/* ATOK�̊e��ݒ� */
typedef struct {
	int Size;     /* sizeof(sceAtokConfig)��ݒ肵�܂� */
	/* -----------------------------------------------------------------------*/
	int KanjiInput;     /* �������̓��[�h */
	                    /* 1= ���[�}������ */
	                    /* 2= ���ȓ��͊��� */
	                    /* 3= ���p�X���[   */

	int KanDspType;     /* ���͕�����̐ݒ� */
	                    /* 1= �Ђ炪��     */
	                    /* 2= �S�p�J�^�J�i */
	                    /* 3= �S�p���ϊ�   */
	                    /* 4= ���p�J�^�J�i */
	                    /* 5= ���p���ϊ�   */

	int FixMode;        /* �Œ���̓��[�h */
	                    /* 0= OFF              */
	                    /* 1= �Œ�Ђ炪��     */
	                    /* 2= �Œ�S�p�J�^�J�i */
	                    /* 3= �Œ�S�p���ϊ�   */
	                    /* 4= �Œ蔼�p�J�^�J�i */
	                    /* 5= �Œ蔼�p���ϊ�   */

	int HZCnvMode;      /* ���p�S�p�ϊ�����/���Ȃ� */
	                    /* bit 3: ��ϊ��P��ւ̓K�p       */
	                    /* bit 2: ���[�U�[�o�^�P��ւ̓K�p */
	                    /* bit 1: ���͒�������ւ̓K�p     */
	                    /* bit 0: ���p�S�p�ϊ�             */

	int HZCnvDetail;    /* ���p�S�p�ϊ��ڍ� */
	                    /* bit 6: ����    ���S�p */
	                    /* bit 5: �p��    ���S�p */
	                    /* bit 4: �J�^�J�i���S�p */
	                    /* bit 2: ����    �����p */
	                    /* bit 1: �p��    �����p */
	                    /* bit 0: �J�^�J�i�����p */

	char *HankakuCnvStr; /* ���p�ϊ�����L��������ւ̃|�C���^ */

	char *ZenkakuCnvStr; /* �S�p�ϊ�����L��������ւ̃|�C���^ */

	int FuriganaMode;   /* �ӂ肪�ȓ��̓��[�h */
	                    /* 0= �I�� */
	                    /* 1= �J�n */

	int MaxInputChars;  /* ���͕����� */

	int PutCursorMode;  /* ���m�蕶���񖖔��ɃJ�[�\��������ǉ�����/���Ȃ� */
	                    /* 0= ���Ȃ� */
	                    /* 1= ����   */

	int PreAnalyze;     /* ���͎��̎�����ǂ݂���/���Ȃ� */
	                    /* 0= ���Ȃ� */
	                    /* 1= ����   */

	/* -----------------------------------------------------------------------*/
	int ConvMode;       /* �ϊ����[�h */
	                    /* 0= �A���ߕϊ� */
	                    /* 1= �P���ߕϊ� */
	                    /* 2= �����ϊ�   */

	int LearningMode;   /* �w�K���[�h */
	                    /* 0= �w�K���Ȃ� */
	                    /* 1= �w�K����   */

	int KutouCharSet;   /* ��Ǔ_�g�ݍ��킹�p�^�[�� */
	                    /* 0= ",.[]/�"	(�J���}/ �s���I�h/ ������/   �X���b�V��/ ������) */
	                    /* 1= "������"	(�Ǔ_  / ��_    / ��������/ ����      / ������) */

	int OkuriMode;      /* ���肪�ȃ��[�h */
	                    /* 0= �{��(���������{��) */
	                    /* 1= �Ȃ�               */
	                    /* 2= ����               */

	int AutoRegKind;    /* �����o�^��� */
	                    /* bit 3: ���o�^��   */
	                    /* bit 2: ��ϊ�     */
	                    /* bit 1: ������     */
	                    /* bit 0: ���ߋ�؂� */

	int LearningKind;   /* �w�K��� */
	                    /* bit 3: ���o�^��         */
	                    /* bit 2: ��ϊ���         */
	                    /* bit 1: ������w�K��     */
	                    /* bit 0: ��؂蒼���w�K�� */

	int RomanRecover;   /* ���[�}���������肷��/���Ȃ� */
	                    /* 0= ���Ȃ� */
	                    /* 1= ����   */

	int AutoRecMode;    /* ���͎x������/���Ȃ� */
	                    /* 0= ���Ȃ� */
	                    /* 1= ����   */

	int AutoRecRoman;   /* ���͎x��(���[�}�����͎�)�̏ڍאݒ� */
	                    /* bit 2: [N]�̉ߕs��  */
	                    /* bit 1: �q���̒���   */
	                    /* bit 0: �ꉹ�̉ߕs�� */

	int AutoRecKana;    /* ���͎x��(���ȓ��͎�)�̏ڍאݒ� */
	                    /* bit 2: �u��v���u��v                 */
	                    /* bit 1: �u�v���u���v(�u�v��X����) */
	                    /* bit 0: �u�K�v���u�J�v(�����_����_��) */

	int AutoRecRep;     /* ���͎x��(�u��)�̏ڍאݒ� */
	                    /* bit 3: �u�B�v���u�D�v(��_��s���I�h��)   */
	                    /* bit 2: �u�A�v���u�C�v(�Ǔ_��J���}��)     */
	                    /* bit 1: �u�E�v���u�^�v(������X���b�V����) */
	                    /* bit 0: �u�[�v���u�|�v(��������n�C�t����) */

	int AppendAtoHen;   /* ��ϊ����̌�⃊�X�g�ւ̒ǉ������/���Ȃ� */
	                    /* bit 4: ���p���ϊ����   */
	                    /* bit 3: �S�p���ϊ����   */
	                    /* bit 2: ���p�J�^�J�i��� */
	                    /* bit 1: �S�p�J�^�J�i��� */
	                    /* bit 0: �Ђ炪�Ȍ��     */

	int KutouCnvMode;   /* ��Ǔ_�ϊ�����/���Ȃ� */
	                    /* 0= ���Ȃ� */
	                    /* 1= ����   */

	int KutouCnvDetail; /* ��Ǔ_�ϊ��̏ڍאݒ� */
	                    /* bit 3: [�I](���Q��)�ŕϊ� */
	                    /* bit 2: [�H](�^�╄)�ŕϊ� */
	                    /* bit 1: [�A](�Ǔ_)�ŕϊ�   */
	                    /* bit 0: [�B](��_)�ŕϊ�   */

	int RuledZenCnv;    /* �S�p�ϊ���O�K���̐ݒ� */
	                    /* bit 0: [~]��[�`]�ɕϊ� */
} sceAtokConfig;



/*
 * sceAtokSetConfig()�֐��AsceAtokGetConfig()�֐���
 * sceAtokConfig�\���̓�̗L�������o�w��p�}�N����`
 */
#define SCE_ATOK_CONFIG_KANJIINPUT      (0x00000001UL)	/* �������̓��[�h */
#define SCE_ATOK_CONFIG_KANDSPTYPE      (0x00000002UL)	/* ���͕����� */
#define SCE_ATOK_CONFIG_FIXMODE         (0x00000004UL)	/* �Œ���̓��[�h */
#define SCE_ATOK_CONFIG_HZCNVMODE       (0x00000008UL)	/* ���p�S�p�ϊ�����/���Ȃ� */
#define SCE_ATOK_CONFIG_HZCNVDETAIL     (0x00000010UL)	/* ���p�S�p�ϊ��ڍ� */
#define SCE_ATOK_CONFIG_HANKAKUCNVSTR   (0x00000020UL)	/* ���p�ϊ�����L��������ւ̃|�C���^ */
#define SCE_ATOK_CONFIG_ZENKAKUCNVSTR   (0x00000040UL)	/* �S�p�ϊ�����L��������ւ̃|�C���^ */
#define SCE_ATOK_CONFIG_FURIGANAMODE    (0x00000080UL)	/* �ӂ肪�ȓ��̓��[�h */
#define SCE_ATOK_CONFIG_MAXINPUTCHARS   (0x00000100UL)	/* ���͕����� */
#define SCE_ATOK_CONFIG_PUTCURSORMODE   (0x00000200UL)	/* ���m�蕶���񖖔��ɃJ�[�\��������ǉ�����/���Ȃ� */
#define SCE_ATOK_CONFIG_PREANALYZE      (0x00000400UL)	/* ���͎��̎�����ǂ݂���/���Ȃ� */
#define SCE_ATOK_CONFIG_CONVMODE        (0x00010000UL)	/* �ϊ����[�h */
#define SCE_ATOK_CONFIG_LEARNINGMODE    (0x00020000UL)	/* �w�K���[�h */
#define SCE_ATOK_CONFIG_KUTOUCHARSET    (0x00040000UL)	/* ��Ǔ_�g�ݍ��킹�p�^�[�� */
#define SCE_ATOK_CONFIG_OKURIMODE       (0x00080000UL)	/* ���肪�ȃ��[�h */
#define SCE_ATOK_CONFIG_AUTOREGKIND     (0x00100000UL)	/* �����o�^��� */
#define SCE_ATOK_CONFIG_LEARNINGKIND    (0x00200000UL)	/* �w�K��� */
#define SCE_ATOK_CONFIG_ROMANRECOVER    (0x00400000UL)	/* ���[�}���������肷��/���Ȃ� */
#define SCE_ATOK_CONFIG_AUTORECMODE     (0x00800000UL)	/* ���͎x������/���Ȃ� */
#define SCE_ATOK_CONFIG_AUTORECROMAN    (0x01000000UL)	/* ���͎x��(���[�}�����͎�)�̏ڍאݒ� */
#define SCE_ATOK_CONFIG_AUTORECKANA     (0x02000000UL)	/* ���͎x��(���ȓ��͎�)�̏ڍאݒ� */
#define SCE_ATOK_CONFIG_AUTORECREP      (0x04000000UL)	/* ���͎x��(�u��)�̏ڍאݒ� */
#define SCE_ATOK_CONFIG_APPENDATOHEN    (0x08000000UL)	/* ��ϊ����̌�⃊�X�g�ւ̒ǉ������/���Ȃ� */
#define SCE_ATOK_CONFIG_KUTOUCNVMODE    (0x10000000UL)	/* ��Ǔ_�ϊ�����/���Ȃ� */
#define SCE_ATOK_CONFIG_KUTOUCNVDETAIL  (0x20000000UL)	/* ��Ǔ_�ϊ��̏ڍאݒ� */
#define SCE_ATOK_CONFIG_RULEDZENCNV     (0x40000000UL)	/* �S�p�ϊ���O�K���̐ݒ� */


/* �S�Ă̐ݒ���ꊇ���Ďw�肷��ꍇ�Ɏg�p */
#define SCE_ATOK_CONFIG_ALL  ( \
					SCE_ATOK_CONFIG_KANJIINPUT      | \
					SCE_ATOK_CONFIG_KANDSPTYPE      | \
					SCE_ATOK_CONFIG_FIXMODE         | \
					SCE_ATOK_CONFIG_HZCNVMODE       | \
					SCE_ATOK_CONFIG_HZCNVDETAIL     | \
					SCE_ATOK_CONFIG_HANKAKUCNVSTR   | \
					SCE_ATOK_CONFIG_ZENKAKUCNVSTR   | \
					SCE_ATOK_CONFIG_FURIGANAMODE    | \
					SCE_ATOK_CONFIG_MAXINPUTCHARS   | \
					SCE_ATOK_CONFIG_PUTCURSORMODE   | \
					SCE_ATOK_CONFIG_PREANALYZE      | \
					                                  \
					SCE_ATOK_CONFIG_CONVMODE        | \
					SCE_ATOK_CONFIG_LEARNINGMODE    | \
					SCE_ATOK_CONFIG_KUTOUCHARSET    | \
					SCE_ATOK_CONFIG_OKURIMODE       | \
					SCE_ATOK_CONFIG_AUTOREGKIND     | \
					SCE_ATOK_CONFIG_LEARNINGKIND    | \
					SCE_ATOK_CONFIG_ROMANRECOVER    | \
					SCE_ATOK_CONFIG_AUTORECMODE     | \
					SCE_ATOK_CONFIG_AUTORECROMAN    | \
					SCE_ATOK_CONFIG_AUTORECKANA     | \
					SCE_ATOK_CONFIG_AUTORECREP      | \
					SCE_ATOK_CONFIG_APPENDATOHEN    | \
					SCE_ATOK_CONFIG_KUTOUCNVMODE    | \
					SCE_ATOK_CONFIG_KUTOUCNVDETAIL  | \
					SCE_ATOK_CONFIG_RULEDZENCNV       \
					)



/* sceAtokConfig�\���̓�̃����o�ݒ�p�}�N����`
*/
/* SCE_ATOK_CONFIG_KANJIINPUT : �������̓��[�h */
#define SCE_ATOK_KANJIINPUT_ROMAN      (1)		/* ���[�}������ */
#define SCE_ATOK_KANJIINPUT_KANA       (2)		/* ���ȓ��͊��� */
#define SCE_ATOK_KANJIINPUT_HANTHROUGH (3)		/* ���p�X���[   */
/* SCE_ATOK_CONFIG_KANDSPTYPE : ���͕�����*/
#define SCE_ATOK_KANDSPTYPE_HIRA      (1)		/* �Ђ炪�ȓ���     */
#define SCE_ATOK_KANDSPTYPE_ZENKANA   (2)		/* �S�p�J�^�J�i���� */
#define SCE_ATOK_KANDSPTYPE_ZENRAW    (3)		/* �S�p���ϊ�����   */
#define SCE_ATOK_KANDSPTYPE_HANKANA   (4)		/* ���p�J�^�J�i���� */
#define SCE_ATOK_KANDSPTYPE_HANRAW    (5)		/* ���p���ϊ�����   */
/* SCE_ATOK_CONFIG_CONVMODE : �ϊ����[�h*/
#define SCE_ATOK_CONVMODE_REN         (0)		/* �A���ߕϊ� */
#define SCE_ATOK_CONVMODE_TAN         (1)		/* �P���ߕϊ� */
#define SCE_ATOK_CONVMODE_AUTO        (2)		/* �����ϊ�   */
/* SCE_ATOK_CONFIG_LEARNINGMODE : �w�K���[�h*/
#define SCE_ATOK_LEARNINGMODE_OFF     (0)		/* �w�K���Ȃ� */
#define SCE_ATOK_LEARNINGMODE_ON      (1)		/* �w�K����   */
/* SCE_ATOK_CONFIG_FIXMODE : �Œ���̓��[�h*/
#define SCE_ATOK_FIXMODE_OFF          (0)		/* �Œ���     */
#define SCE_ATOK_FIXMODE_HIRAGANA     (1)		/* �Ђ炪��     */
#define SCE_ATOK_FIXMODE_ZENKANA      (2)		/* �S�p�J�^�J�i */
#define SCE_ATOK_FIXMODE_ZENRAW       (3)		/* �S�p���ϊ�   */
#define SCE_ATOK_FIXMODE_HANKANA      (4)		/* ���p�J�^�J�i */
#define SCE_ATOK_FIXMODE_HANRAW       (5)		/* ���p���ϊ�   */
/* SCE_ATOK_CONFIG_KUTOUCHARSET : ��Ǔ_�g�ݍ��킹�p�^�[��*/
#define SCE_ATOK_KUTOUCHARSET_SET0    (0)		/* �J���}/ �s���I�h/ ������/ �X���b�V��/ ������*/
#define SCE_ATOK_KUTOUCHARSET_SET1    (1)		/* �Ǔ_/ ��_/ ��������/ ����/ ������ */
/* SCE_ATOK_CONFIG_AUTOREGKIND : �����o�^���*/
#define SCE_ATOK_AUTOREGKIND_CLAUSEGAP    (0x00000001)	/* ���ߋ�؂�*/
#define SCE_ATOK_AUTOREGKIND_MULTI        (0x00000002)	/* ������*/
#define SCE_ATOK_AUTOREGKIND_CNVRAW       (0x00000004)	/* ��ϊ�*/
#define SCE_ATOK_AUTOREGKIND_NONREG       (0x00000008)	/* ���o�^��*/
/* SCE_ATOK_CONFIG_LEARNINGKIND : �w�K���*/
#define SCE_ATOK_LEARNINGKIND_CLAUSEGAP   (0x00000001)	/* ��؂�Ȃ����w�K��*/
#define SCE_ATOK_LEARNINGKIND_MULTI       (0x00000002)	/* ������w�K��*/
#define SCE_ATOK_LEARNINGKIND_CNVRAW      (0x00000004)	/* ��ϊ���*/
#define SCE_ATOK_LEARNINGKIND_NONREG      (0x00000008)	/* ���o�^��*/
/* SCE_ATOK_CONFIG_ROMANRECOVER : ���[�}���������肷��/���Ȃ� */
#define SCE_ATOK_ROMANRECOVER_OFF         (0)			/* ���Ȃ�*/
#define SCE_ATOK_ROMANRECOVER_ON          (1)			/* ����*/
/* SCE_ATOK_CONFIG_HZCNVMODE : ���p�S�p�ϊ�����/���Ȃ� */
#define SCE_ATOK_HZCNVMODE_CNVHANZEN      (1<<0)		/* ���p�S�p�ϊ�*/
#define SCE_ATOK_HZCNVMODE_INPUTCHARS     (1<<1)		/* ���͒�������ւ̓K�p*/
#define SCE_ATOK_HZCNVMODE_USERREG        (1<<2)		/* ���[�U�o�^�P��ւ̓K�p*/
#define SCE_ATOK_HZCNVMODE_RAWCNV         (1<<3)		/* ��ϊ��P��ւ̓K�p*/
/* SCE_ATOK_CONFIG_HZCNVDETAIL : ���p�S�p�ϊ��ڍ� */
#define SCE_ATOK_HZCNVDETAIL_KANA2HAN     (1<<0)		/* �J�^�J�i �� ���p */
#define SCE_ATOK_HZCNVDETAIL_ALPH2HAN     (1<<1)		/* �p��     �� ���p */
#define SCE_ATOK_HZCNVDETAIL_NUM2HAN      (1<<2)		/* ����     �� ���p */
#define SCE_ATOK_HZCNVDETAIL_KANA2ZEN     (1<<4)		/* �J�^�J�i �� �S�p */
#define SCE_ATOK_HZCNVDETAIL_ALPH2ZEN     (1<<5)		/* �p��     �� �S�p */
#define SCE_ATOK_HZCNVDETAIL_NUM2ZEN      (1<<6)		/* ����     �� �S�p */
/* SCE_ATOK_CONFIG_AUTORECMODE : ���͎x������/���Ȃ� */
#define SCE_ATOK_AUTORECMODE_OFF            (0) 		/* ���Ȃ� */
#define SCE_ATOK_AUTORECMODE_ON             (1) 		/* ����   */
/* SCE_ATOK_CONFIG_AUTORECROMAN : ���͎x���i���[�}�����͎��j�̏ڍאݒ�/�ǂݏo��*/
#define SCE_ATOK_AUTORECROMAN_BOIN          (1<<0)		/* �ꉹ�̉ߕs�� */
#define SCE_ATOK_AUTORECROMAN_SHIIN         (1<<1)		/* �q���̒���   */
#define SCE_ATOK_AUTORECROMAN_N             (1<<2)		/* [N]�̉ߕs��  */
/* SCE_ATOK_CONFIG_AUTORECKANA : ���͎x��(���ȓ��͎�)�̏ڍאݒ� */
#define SCE_ATOK_AUTORECKANA_HANDAKU2DAKU   (1<<0)		/* �u߁v ���u�J�v(�����_����_)  */
#define SCE_ATOK_AUTORECKANA_TSU            (1<<1)		/* �u�v���u���v(�u�v��X����)*/
#define SCE_ATOK_AUTORECKANA_WA2WO          (1<<2)		/* �u��v���u��v*/
/* SCE_ATOK_CONFIG_AUTORECREP : ���͎x��(�u��)�̏ڍאݒ� */
#define SCE_ATOK_AUTORECREP_ONBIKI2HYPHEN   (1<<0)		/* �u�[�v���u-�v(��������n�C�t����)*/
#define SCE_ATOK_AUTORECREP_NAKAGURO2SLASH  (1<<1)		/* �u�E�v���u/�v(������X���b�V����)*/
#define SCE_ATOK_AUTORECREP_DOKUTEN2COMMA   (1<<2)		/* �u�A�v���u,�v(�Ǔ_��J���}��)    */
#define SCE_ATOK_AUTORECREP_KUTEN2PERIOD    (1<<3)		/* �u�B�v���u.�v(��_��s���I�h��)  */
/* SCE_ATOK_CONFIG_APPENDATOHEN : ��ϊ����̌�⃊�X�g�ւ̒ǉ������/���Ȃ� */
#define SCE_ATOK_APPENDATOHEN_HIRAGANACAND    (1<<0)	/* �Ђ炪�Ȍ��     */
#define SCE_ATOK_APPENDATOHEN_ZENKATAKANACAND (1<<1)	/* �S�p�J�^�J�i��� */
#define SCE_ATOK_APPENDATOHEN_HANKATAKANACAND (1<<2)	/* ���p�J�^�J�i��� */
#define SCE_ATOK_APPENDATOHEN_ZENCNVRAWCAND   (1<<3)	/* �S�p���ϊ����   */
#define SCE_ATOK_APPENDATOHEN_HANCNVRAWCAND   (1<<4)	/* ���p���ϊ����   */
/* SCE_ATOK_CONFIG_KUTOUCNVMODE : ��Ǔ_�ϊ�����/���Ȃ� */
#define SCE_ATOK_KUTOUCNVMOD_OFF            (0)  		/* ���Ȃ� */
#define SCE_ATOK_KUTOUCNVMOD_ON             (1)  		/* ����   */
/* SCE_ATOK_CONFIG_KUTOUCNVDETAIL : ��Ǔ_�ϊ��̏ڍאݒ� */
#define SCE_ATOK_KUTOUCNVDETAIL_KUTEN       (1<<0)		/* �B(��_)�ŕϊ�   */
#define SCE_ATOK_KUTOUCNVDETAIL_DOKUTEN     (1<<1)		/* �A(�Ǔ_)�ŕϊ�   */
#define SCE_ATOK_KUTOUCNVDETAIL_GIMONFU     (1<<2)		/* �H(�^�╄)�ŕϊ� */
#define SCE_ATOK_KUTOUCNVDETAIL_KANTANFU    (1<<3)		/* �I(���Q��)�ŕϊ� */
/* SCE_ATOK_CONFIG_FURIGANAMODE : �ӂ肪�ȓ��̓��[�h */
#define SCE_ATOK_FURIGANAMODE_FINISH        (0)  		/* �I�� */
#define SCE_ATOK_FURIGANAMODE_START         (1)  		/* �J�n */
/* SCE_ATOK_CONFIG_PUTCURSORMODE : ���m�蕶���񖖔��ɃJ�[�\��������ǉ�����/���Ȃ� */
#define SCE_ATOK_PUTCURSORMODE_OFF          (0)  		/* ���Ȃ� */
#define SCE_ATOK_PUTCURSORMODE_ON           (1)  		/* ����   */
/* SCE_ATOK_CONFIG_PREANALYZE : ���͎��̎�����ǂ݂���/���Ȃ� */
#define SCE_ATOK_PREANALYZE_OFF             (0)
#define SCE_ATOK_PREANALYZE_ON              (1)
/* SCE_ATOK_CONFIG_OKURIMODE : ���肪�ȃ��[�h */
#define SCE_ATOK_OKURIMODE_HONSOKU          (0)  		/* 0= �{��(���������{��) */
#define SCE_ATOK_OKURIMODE_HABUKU           (1)  		/* 1= �Ȃ� */
#define SCE_ATOK_OKURIMODE_OKURU            (2)  		/* 2= ���� */
/* SCE_ATOK_CONFIG_RULEDZENCNV : �S�p�ϊ���O�K���̐ݒ� */
#define SCE_ATOK_RULEDZENCNV_TILDE          (1<<0)		/* �u~�v���u�`�v*/



/* �ҏW�p�L�[�R�[�h�̒l���`
 * sceAtokEditConv()�֐��̈����Ƃ��Ďg�p���܂�
 */
#define SCE_ATOK_EDIT_BACKSPACE     (0x0100)	/* ������1�����폜(BACKSPACE) */
#define SCE_ATOK_EDIT_DELETE        (0x0101)	/* �J�[�\���ʒu��1�����폜(DELETE) */
#define SCE_ATOK_EDIT_CURRIGHT      (0x0102)	/* �J�[�\���ړ�(�E) */
#define SCE_ATOK_EDIT_CURLEFT       (0x0103)	/* �J�[�\���ړ�(��) */
#define SCE_ATOK_EDIT_CUREND        (0x0104)	/* �J�[�\���ړ�(����) */
#define SCE_ATOK_EDIT_CURTOP        (0x0105)	/* �J�[�\���ړ�(����) */
#define SCE_ATOK_EDIT_CONVFORWARD   (0x0107)	/* �ϊ��A����⏇���擾 */
#define SCE_ATOK_EDIT_CONVBACKWARD  (0x0108)	/* �ϊ��A����⏇���擾 */
#define SCE_ATOK_EDIT_1ONKAKUTEI    (0x010A)	/* 1���m�� */
#define SCE_ATOK_EDIT_POSTCONVHIRA  (0x010B)	/* ��ϊ�:�Ђ炪�� */
#define SCE_ATOK_EDIT_POSTCONVKANA  (0x010C)	/* ��ϊ�:�J�^�J�i */
#define SCE_ATOK_EDIT_POSTCONVHALF  (0x010D)	/* ��ϊ�:���p */
#define SCE_ATOK_EDIT_POSTCONVRAW   (0x010E)	/* ��ϊ�:���ϊ� */
#define SCE_ATOK_EDIT_DICCONV       (0x010F)	/* �����w��ϊ� */
#define SCE_ATOK_EDIT_KAKUTEIPART   (0x0110)	/* �����m�� */
#define SCE_ATOK_EDIT_KAKUTEIALL    (0x0111)	/* �S���m�� */
#define SCE_ATOK_EDIT_DELETEALL     (0x0112)	/* �S�����폜 */
#define SCE_ATOK_EDIT_KAKUTEIREP    (0x0113)	/* �m�胊�s�[�g */
#define SCE_ATOK_EDIT_KAKUTEIUNDO   (0x0114)	/* �m��A���h�D */
#define SCE_ATOK_EDIT_KAKUTEIHEAD   (0x0115)	/* ���������m�� */
#define SCE_ATOK_EDIT_KAKUTEITAIL   (0x0116)	/* ���������m�� */
#define SCE_ATOK_EDIT_CONVCANCEL    (0x0117)	/* �ϊ��L�����Z��(���ڕ��߈ȍ~) */
#define SCE_ATOK_EDIT_CANCELALL     (0x0118)	/* �S�ϊ������� */
#define SCE_ATOK_EDIT_FOCUSRIGHT    (0x0119)	/* ���ڕ��ߋ�؂��1�����̂΂� */
#define SCE_ATOK_EDIT_FOCUSLEFT     (0x011A)	/* ���ڕ��ߋ�؂��1�����k�߂� */
#define SCE_ATOK_EDIT_MOVFOCUSCLAUS (0x011B)	/* ���ڕ��߈ړ� ���ߋ�؂蒼�����ɂ͎g���܂��� */
#define SCE_ATOK_EDIT_SELECTCAND    (0x011E)	/* ���I��ړ� */


/* ATOK �L�[���͏�Ԃ̒�`
 * sceAtokGetInputState()�֐��̖߂�l
 */
#define SCE_ATOK_ISTATE_BEFOREINPUT     (0)		/* ������ */
#define SCE_ATOK_ISTATE_BEFORECONVERT   (1)		/* �ϊ��O */
#define SCE_ATOK_ISTATE_CONVERTING      (2)		/* �ϊ��� */
#define SCE_ATOK_ISTATE_CANDEMPTY       (3)		/* ���؂�(���Ȃ�) */
#define SCE_ATOK_ISTATE_POSTCONVKANA    (4)		/* ��ϊ�(�J�^�J�i) */
#define SCE_ATOK_ISTATE_POSTCONVHALF    (5)		/* ��ϊ�(���p) */
#define SCE_ATOK_ISTATE_POSTCONVRAW     (6)		/* ��ϊ�(���ϊ�) */
#define SCE_ATOK_ISTATE_CANDIDATES      (7)		/* ���ꗗ */
#define SCE_ATOK_ISTATE_MOVECLAUSEGAP   (8)		/* ���ߋ�؂蒼�� */




/* �v���g�^�C�v�錾 */
/*erx���p*/
void *sceAtokGetErxEntries(void);

/* ATOK�̏����� */
int sceAtokInit(sceAtokContext *context, const char *sysdic, const char *userdic ,const char *sysconf, const void *loadaddr);
/* ATOK�̃��Z�b�g */
int sceAtokReset(sceAtokContext *context);
/* ATOK�̉�� */
int sceAtokExit(sceAtokContext *context);

/* ATOK�̊e��R���t�B�M�����[�V�����̓ǂݏo������ѐݒ� */
int sceAtokGetConfig(sceAtokContext *context, sceAtokConfig *config, unsigned long bits);
int sceAtokSetConfig(sceAtokContext *context, const sceAtokConfig *config, unsigned long bits);


/* ATOK�ɃR�}���h�𔭍s����֐� */
int sceAtokEditConv(sceAtokContext *context, int cmd, int param);  /* �ҏW,�ϊ����� */
int sceAtokKanjiOn(sceAtokContext *context);                       /* �������[�hON */
int sceAtokKanjiOff(sceAtokContext *context);                      /* �������[�hOFF */
int sceAtokUndoClear(sceAtokContext *context);                     /* �m��A���h�D�̖����� */
int sceAtokConvAll(sceAtokContext *context, const char *str, int mode); /* �ꊇ�ǂݕϊ����� */


/* ATOK�R���e�L�X�g��̃��[�N����擾����֐� */
int sceAtokGetKanjiState(sceAtokContext *context);     /* ATOK���Ԃ�擾 */
int sceAtokGetInputState(sceAtokContext *context);     /* ���͏�Ԃ�擾   */

int sceAtokGetFocusClauseTop(sceAtokContext *context);    /* �t�H�[�J�X(�J�[�\��)�擪�ʒu�̎擾 */
int sceAtokGetFocusClauseLen(sceAtokContext *context);    /* �t�H�[�J�X�I��o�C�g���̎擾(0:�Ȃ�) */
int sceAtokGetFocusClauseIndex(sceAtokContext *context);  /* �t�H�[�J�X�����镶�ߔԍ��𓾂� */

int sceAtokGetCurrentCandidateIndex(sceAtokContext *context); /* ���݂̑I����ԍ�       */
int sceAtokGetCandidateCount(sceAtokContext *context);        /* ��⃊�X�g��擾         */
int sceAtokGetCandidateListSize(sceAtokContext *context);     /* ��⃊�X�g�̃T�C�Y��擾 */
int sceAtokGetCandidateList(sceAtokContext *context, char *buf, int size); /* ��⃊�X�g�̎擾 */


/* �m�蕶����Ɗm��ǂݕ������t���b�V������ */
int sceAtokFlushConverted(sceAtokContext *context);
/* �m�蕶����̕���o�b�t�@�Ɏ󂯎�� */
int sceAtokGetConvertedStr(sceAtokContext *context, char *buf, unsigned int size);
/* �m��ǂݕ�����̕���o�b�t�@�Ɏ󂯎�� */
int sceAtokGetConvertedReadStr(sceAtokContext *context, char *buf, unsigned int size);

/* ���m�蕶����̕���o�b�t�@�Ɏ󂯎�� */
int sceAtokGetConvertingStr(sceAtokContext *context, char *buf, unsigned int size);
/* ����ǂݕ�����̕���o�b�t�@�Ɏ󂯎�� */
int sceAtokGetConvertingReadStr(sceAtokContext *context, char *buf, unsigned int size);

/* ���m�蕶����̕��ߐ���擾 */
int sceAtokGetConvertingClauseCount(sceAtokContext *context);
/* ���m�蕶����𕶐߂��ƂɎ擾 */
int sceAtokGetConvertingClause(sceAtokContext *context, char *buf, unsigned int size, int index );

int sceAtokDicDelWord(sceAtokContext *p, int p1, int p2, const char *pszWord, const char *pszReading, int iMode);
int sceAtokFlushDic(sceAtokContext *context);
int sceAtokDicExpand(sceAtokContext *p, void *work, size_t size);
int sceAtokDicRegWord(sceAtokContext *p, int iHinshi, const char *pszWord, const char *pszReading);
int sceAtokDicRegWordAndExpand(sceAtokContext *p, int iHinshi, const char *pszWord, const char *pszReading, void *work, size_t size);

#if defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
}
#endif	/* defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus) */

#endif	/* _LIBATOK_H_ */

