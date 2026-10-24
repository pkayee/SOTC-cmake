/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 $Id: sdsq.h,v 1.38 2003/04/25 09:53:15 tokiwa Exp $
 */
/* 
 * Sound Data .SQ Library
 *
 * Copyright (C) 2003 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 *
 *      Date            Design      Log
 *  ----------------------------------------------------
 *      2003-02-28      toki        initial
 */

#ifndef _SCE_SDSQ_H
#define _SCE_SDSQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <format/sound/sq.h>

/* ���k���[�h */
#define SCESDSQ_COMPMODE_NOTCOMP   0  /* SceSdSqMidiData->compMode */
#define SCESDSQ_COMPMODE_COMP      1  /* SceSdSqMidiData->compMode */

/* ��ԃX�e�[�^�X */
#define SCESDSQ_READSTATUS_OK      0  /* �\���̎g�p�\ */
#define SCESDSQ_READSTATUS_END     1  /* ���[�h�|�W�V���������[�ɓ��B */
                                      /*�i�\���̎g�p�s�j */
#define SCESDSQ_READSTATUS_ERROR   2  /* ���[�h�G���[�i�\���̎g�p�s�j*/

#define SCESDSQ_MAXMIDIMESSAGELENGTH       8
#define SCESDSQ_MAXORIGINALMESSAGELENGTH   12
#define SCESDSQ_MAXSONGMESSAGELENGTH       3

/* MIDI�f�[�^���\���� */
typedef struct{
    u_int                 readStatus;
    u_int                 midiNumber;
    sceSeqMidiDataBlock   *midiData;
    u_int                 offset;
    u_int                 nextOffset;
    u_int                 division;
    u_int                 compMode;
    u_int                 compTableSize;
    u_int                 deltaTime;
    u_char                lastStatus;
    u_char                reserve[3];
    u_int                 messageLength;
    u_char                message[SCESDSQ_MAXMIDIMESSAGELENGTH];
    u_int                 originalMessageLength;
    u_char                originalMessage[SCESDSQ_MAXORIGINALMESSAGELENGTH];
} SceSdSqMidiData;

/* J
  readStatus            : ��ԃX�e�[�^�X
  midiNumber            : ���̍\���̂��g�p���Ă���MIDI�f�[�^�u���b�N�i���o�[
  midiData              : midiNumber���w���f�[�^�u���b�N�isceSeqMidiDataBlock�j
                          �̃A�h���X
  offset                : ���݂̃f�[�^�ւ̃I�t�Z�b�g
  nextOffset            : ���f�[�^�ւ̃I�t�Z�b�g
  division              : �S������������̕���\
  compMode              : ���k���[�h
  compTableSize         : ���k�e�[�u���̃T�C�Y�i�񈳏k���[�h�̏ꍇ�O�j
  deltaTime             : �R�Q�r�b�g�f�[�^�ɕϊ���̃f���^�^�C��
  lastStatus            : �����j���O�X�e�[�^�X
  reserve[3]            : �\��̈�
  messageLength         : �␳��̃f�[�^��
  message[8]            : �␳��̃f�[�^
  originalMessageLength : �␳�O�̃f�[�^��
  originalMessage[12]   : �␳�O�̃f�[�^�ideltaTime + message�j
*/
/* E

 */

/* Song�f�[�^�\���� */
typedef struct{
    u_int    readStatus;
    u_int    songNumber;
    void     *topAddr;
    u_int    offset;
    u_int    nextOffset;
    u_char   message[SCESDSQ_MAXSONGMESSAGELENGTH];
    u_char   reserve;
} SceSdSqSongData;

/*
  readStatus : ��ԃX�e�[�^�X
  songNumber : ���̍\���̂��g�p���Ă���MIDI�f�[�^�u���b�N�i���o�[
  topAddr    : songNumber���w��song�R�}���h�̐擪�A�h���X
  offset     : ���݂̃f�[�^�ւ̃I�t�Z�b�g
  nextOffset : ���f�[�^�ւ̃I�t�Z�b�g
  message[3] : Song�R�}���h�f�[�^
  reserve    : �\��̈�
 */

/* ���k�e�[�u���f�[�^�\���� */
/* �|���t�H�j�b�N�L�[�v���b�V���[���\���� */
typedef struct{
    u_char   status;  /* �X�e�[�^�X�o�C�g�f�[�^ */
    u_char   data;    /* �f�[�^ */
} SceSdSqCompTableData, SceSdSqPolyKeyData;

/* �𓀃m�[�g�I���f�[�^�\���� */
typedef struct{
    u_char   status;    /* �X�e�[�^�X�o�C�g�f�[�^ */
    u_char   note;      /* �m�[�g */
    u_char   velocity;  /* �x���V�e�B */
    u_char   reserve;
} SceSdSqCompTableNoteOnEvent;

int sceSdSqGetMaxMidiNumber(void *addr);
int sceSdSqGetMaxSongNumber(void *addr);
int sceSdSqInitMidiData(void *addr, u_int midiNumber, 
			SceSdSqMidiData *midiData);
int sceSdSqReadMidiData(SceSdSqMidiData *midiData);
int sceSdSqInitSongData(void *addr, u_int songNumber, 
			SceSdSqSongData *songData);
int sceSdSqReadSongData(SceSdSqSongData *songData);
int sceSdSqGetMaxCompTableIndex(void *addr, u_int midiNumber);
int sceSdSqGetCompTableOffset(void *addr, u_int midiNumber, u_int *offset);
int sceSdSqGetCompTableDataByIndex(void *addr, u_int midiNumber,
				   u_int compTableIndex,
				   SceSdSqCompTableData *data);
int sceSdSqGetNoteOnEventByPolyKeyPress(void *addr, u_int midiNumber,
					SceSdSqPolyKeyData *pData,
					SceSdSqCompTableNoteOnEvent *kData);
int sceSdSqCopyMidiData(SceSdSqMidiData *to, const SceSdSqMidiData *from);
int sceSdSqCopySongData(SceSdSqSongData *to, const SceSdSqSongData *from);

#ifdef __cplusplus
}
#endif

#endif /* !_SCE_SDSQ_H */
