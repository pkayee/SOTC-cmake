/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0.1
 */
/*
 * Emotion Engine / I/O Processor Common Header
 *
 * Copyright (C) 1998-2001 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 *
 * csl.h
 *	Component Sound Library
 */
#ifndef _csl_h_
#define _csl_h_
typedef struct {
    int  	sema;	
    void	*buff;
} sceCslBuffCtx;

typedef struct {
    int    system[48];
} sceCslIdMonitor;  /* for sesq2 */


typedef struct {
	int				buffNum;
	sceCslBuffCtx	*buffCtx;
} sceCslBuffGrp;

typedef struct {
	int			buffGrpNum;	/* �o�b�t�@�O���[�v���@�@�@�@�@�F�K�{ */
	sceCslBuffGrp*		buffGrp;	/* �o�b�t�@�O���[�v�ւ̃|�C���^�F�K�{ */
	void*			conf;		/* ���W���[���ݒ�\���́@�@�@�@�F�C�� */
	void*			callBack;	/* �R�[���o�b�N�֐��@�@�@�@�@�@�F�C�� */
	char**			extmod;		/* �O�����W���[���̃G���g���@�@�F�C�� */
} sceCslCtx;

#define sceCslNoError	0
#define sceCslError	(-1)
#define sceCslWarning	1

#endif /* !_csl_h_ */
