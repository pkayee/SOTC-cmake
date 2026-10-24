/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 */
/*
 *                      Emotion Engine Library
 *                          Version 0.03
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-1999 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                        libdev - devfont.h
 *                         develop library
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       0.01           Mar,29,1999     shibuya
 *       0.02           Jun,11,1999     shibuya
 *       0.03           Sep,25,2003     hana        change comment
 */

#ifndef __devfont__
#define __devfont__

#include <eekernel.h>
#include <eetypes.h>
#include <eestruct.h>

#include <libdma.h>
#include <libgraph.h>
#include <libgifpk.h>

#ifdef __cplusplus
extern "C" {
#endif

/* �R���\�[�����C�u����������� */
void sceDevConsInit(void);

/* �R���\�[����I�[�v���B�i�P�����Ȃ��B�T�C�Y�̍ő��80 x 64�L�����N�^�j */
int sceDevConsOpen(u_int gs_x, u_int gs_y, u_int chr_w, u_int chr_h);

/* �R���\�[����N���[�Y */
void sceDevConsClose(int cd);


/* �R���\�[���̃C���[�W��p�P�b�g�ɂ���B */
void sceDevConsRef(int cd, sceGifPacket* pPacket);

/* �R���\�[���̃C���[�W��`�� */
void sceDevConsDraw(int cd);

/* �R���\�[���̃C���[�W��`��i�X�N���b�`�p�b�h�g�p�j */
void sceDevConsDrawS(int cd);

/* �R���\�[���N���A */
void sceDevConsClear(int cd);

/* �R���\�[���֕����\�� */
u_int sceDevConsPrintf(int cd, const char* str, ...);

/* �t�H���g�̃J���[�e�[�u���̕ύX */
void sceDevConsSetColor(int cd, u_char c, u_char r, u_char g, u_char b);


/* �J�[�\���ʒu��ύX */
void sceDevConsLocate(int cd, u_int lx, u_int ly);

/* �J�[�\���ʒu�ɂP�����o�� */
void sceDevConsPut(int cd, u_char c, u_char a);

/* �J�[�\���ʒu����P�����擾(��ʂW�r�b�g�ɂ̓A�g���r���[�g) */
u_short sceDevConsGet(int cd);

/* �A�g���r���[�g(�F)�ύX */
void sceDevConsAttribute(int cd, u_char col);


/* ��`�̈�N���A */
void sceDevConsClearBox(int cd, int x, int y, u_int w, u_int h);

/* ��`�̈�ړ� */
void sceDevConsMove(int cd, int dx, int dy, int sx, int sy, u_int w, u_int h);

/* ���[���A�b�v */
void sceDevConsRollup(int cd, u_int line);


/* �g�����b�Z�[�W�\�� */
void sceDevConsMessage(int cd, int x, int y, char const* str);

/* �t���[�� */
void sceDevConsFrame(int cd, int x, int y, u_int w, u_int h);

/* �����C�u�����T�|�[�g */
u_long128* sceDevFont(u_long128*, int, int, int, char *, int);
  /* packet, x, y, z(����), str, ctxt */

#ifdef __cplusplus
}
#endif

#endif /* __devfont__ */
