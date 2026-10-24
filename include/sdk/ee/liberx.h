/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0.2
 $Id: liberx.h,v 1.25 2004/06/25 13:47:26 kono Exp $
*/
/* 
 *                      Emotion Engine Library
 *                          Version 0.00
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-2003 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                       liberx - liberx.h
 *                     header file of liberx
 *
 *       Version        Date            assign      Log
 *  --------------------------------------------------------------------
 *      0.00          2002-11-29        kono        the first version
 *      0.01          2003-04-07        kono        add self stop-unload
 *      0.02          2003-04-15        kono        add async ver function and
 *                                                  load from buffer ver function
 *      0.03          2003-04-25        kono        apply to official error code
 *      0.04          2003-05-16        kono        add english comment
 *                                                  sorry my poor english
 *                                                  please read my native language
 *                                                  (i.e. japanese) comment...
 *                                                  I have no confidence.
 *      0.05          2003-09-02        kono        add SCE_ERX_ENCRYPT_DNAS_NOHDD
 *                                                  flag. for DNAS-inst(nohdd)
 *      0.06          2004-06-25        kono        add sceErxSelfStopUnloadLoadStartModuleFile()
 */

#ifndef _LIBERX_H
#define _LIBERX_H

#include <sys/types.h>
#include <eekernel.h>

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

/* ���W���[���̃G���g���֐����Ă΂ꂽ�Ƃ��̗��R�R�[�h */
#define SCE_ERX_REASON_START			(0)		/* ���W���[���̋N���� */
#define SCE_ERX_REASON_STOP				(1)		/* ���W���[���̒�~�� */
#define SCE_ERX_REASON_RESTART			(2)		/* ���W���[���̍ċN����(���T�|�[�g) */

/* ���W���[���̃G���g���֐��̕Ԃ�l���` */
#define SCE_ERX_RESIDENT_END			(0)		/* �풓�I�� */
#define SCE_ERX_NO_RESIDENT_END			(1)		/* ��풓�I�� */
#define SCE_ERX_FAREWELL_END			(1)		/* ��풓�I�� */
#define SCE_ERX_REMOVABLE_RESIDENT_END	(2)		/* �풓�I��(�A�����[�h�Ή�) */

/* �������A���P�[�g��p */
#define SCE_ERX_SMEM_LOW				(0x00000000U)		/* ���ʑ��A�h���X��胁�����m�� */
#define SCE_ERX_SMEM_HIGH				(0x00000001U)		/* ��ʑ��A�h���X��胁�����m�� */
#define SCE_ERX_SMEM_ADDR				(0x00000002U)		/* �A�h���X�w�肵�ă������m�� */
#define SCE_ERX_SMEM_LOWALIGNED			(0x00000004U)		/* ���ʑ��A�h���X���A���C�������g�w����������m�� */
#define SCE_ERX_SMEM_HIGHALIGNED		(0x00000005U)		/* ��ʑ��A�h���X���A���C�������g�w����������m�� */

/* ���W���[���t�@�C�����[�h���̃t�@�C���A�N�Z�X�w�� */
#define SCE_ERX_ACCESS_NOSEEK			(0x00000000U)		/* �V�[�N�Ȃ�,   ���[�N�������g�p�ʑ� */
#define SCE_ERX_ACCESS_SEEKFEW			(0x00000100U)		/* �V�[�N�񐔏�, ���[�N�������g�p�ʒ� */
#define SCE_ERX_ACCESS_SEEKMANY			(0x00000200U)		/* �V�[�N�񐔑�, ���[�N�������g�p�Ȃ� */

/* ���W���[���̈��k�w�� */
#define SCE_ERX_ENCODE_GZIP				(0x00001000U)		/* gzip���k�w�� */

/* ���W���[���̈Í����w�� */
#define SCE_ERX_ENCRYPT_DNAS			(0x00002000U)		/* DNAS(hdd)�Í����w�� */
#define SCE_ERX_ENCRYPT_DNAS_NOHDD		(0x00004000U)		/* DNAS(nohdd)�Í����w�� */

/* liberx library*/
int sceErxInit(int iPriority, void *pStart, u_int uiSize, int nMaxModules);
int sceErxExit(void);

/* sysmem library */
void *sceErxAllocSysMemory(int type, u_int size, void *addr);
int   sceErxFreeSysMemory(void *area);
int   sceErxRecordMemConsumption(int fEnable);
u_int sceErxQueryMemSize(void);
int   sceErxQueryFreeMemSize(u_int *puiTotalFree, u_int *puiMaxFree);
int   sceErxQueryFreeMemSticky(u_int *puiTotalFree, u_int *puiMaxFree);
int   sceErxQueryBlockInfo(const void *addr, void **ppBlkStart, u_int *puiSize);
int   sceErxQueryRegionType(const void *addr, u_int size);

/* loadcore library */
typedef struct SceErxLibraryHeader {
	u_int	magic[4];		/* library header magic(0x41C00000) */
	const char *name;		/* ���C�u������(ASCIZ) */
	u_short	version;		/* ���C�u�����̃o�[�W���� */
	u_short	flags;
	u_int reserved[2];
} SceErxLibraryHeader;

typedef struct SceErxModuleStatus {
	char	name[56];		/* ���W���[���� */
	u_short	version;		/* ���W���[���̃o�[�W���� */
	u_short flags;			/* ���W���[���̏�� */
	int		id;				/* ���W���[������ʂ��� ID �ԍ� */
	u_int	entry_addr;		/* ���W���[���̎��s�J�n�A�h���X */
	u_int	gp_value;		/* ���W���[���� GP ���W�X�^�l */
	u_int	text_addr;		/* ���W���[���̐擪�A�h���X */
	u_int	text_size;		/* ���W���[���̃e�L�X�g�Z�O�����g�T�C�Y */
	u_int	data_size;		/* ���W���[���̃f�[�^�Z�O�����g�T�C�Y */
	u_int	bss_size;		/* ���W���[���̖��������f�[�^�Z�O�����g�T�C�Y */
	u_int   erx_lib_addr;	/* ERX���C�u�����G���g���̊J�n�A�h���X */
	u_int   erx_lib_size;	/* ERX���C�u�����G���g���̃T�C�Y */
	u_int   erx_stub_addr;	/* ERX���C�u�����X�^�u�̊J�n�A�h���X */
	u_int   erx_stub_size;	/* ERX���C�u�����X�^�u�̃T�C�Y */
} SceErxModuleStatus;

/* SceErxModuleStatus.flags */
#define SCE_ERX_MSTF_LOADED			(0x0001)		/* ���[�h���� */
#define SCE_ERX_MSTF_EXEC			(0x0002)		/* ���[�h��̃G���g�����[�`������s�� */
#define SCE_ERX_MSTF_RESIDENT		(0x0003)		/* �풓��� */
#define SCE_ERX_MSTF_STOPPING		(0x0004)		/* ��~�̂��߂ɃG���g�����[�`������s�� */
#define SCE_ERX_MSTF_SelfSTOPPING	(0x0005)		/* ���Ȓ�~�̂��߂ɃG���g�����[�`������s�� */
#define SCE_ERX_MSTF_STOPPED		(0x0006)		/* ��~��� */
#define SCE_ERX_MSTF_SelfSTOPPED	(0x0007)		/* ���Ȓ�~��� */
#define SCE_ERX_MSTF_MASK(x)		((x) & 0x000F)

#define SCE_ERX_MSTF_REMOVABLE		(0x0010)		/* �A�����[�h�Ή� */
#define SCE_ERX_MSTF_NOSYSALLOC		(0x0020)		/* sysmem�Ǘ��O�̃������Ƀ��[�h���ꂽ */
#define SCE_ERX_MSTF_CLEARMOD		(0x0040)		/* �A�����[�h���̃������N���A�ݒ� */

/* �풓���C�u�����̃G���g���e�[�u���o�^ */
int   sceErxRegisterLibraryEntries(SceErxLibraryHeader *lib);

/* �G���g���e�[�u���̓o�^���� */
int   sceErxReleaseLibraryEntries(SceErxLibraryHeader *lib);

/* �풓���C�u������g�p���Ă���N���C�A���g�̌���擾 */
int   sceErxGetLibraryClients(const SceErxLibraryHeader *pLibHead);

int   sceErxSearchModuleByName(const char *modulename);
int   sceErxSearchModuleByAddress(const void *addr);
int   sceErxGetModuleIdList(int *readbuf, int readbufsize, int *modulecount);
int   sceErxGetModuleIdListByName(const char *modulename, int *readbuf, int readbufsize, int *modulecount);
int   sceErxReferModuleStatus(int modid, SceErxModuleStatus *status);

int   sceErxSetModuleFlags(int modid, int flag);


/* modload library */
typedef struct {
	const char		*name;
	unsigned int	version;
} SceErxModuleInfo;

int   sceErxLoadModuleFile(const char *filename, u_int mode, void *addr);
int   sceErxLoadModuleFileAsync(const char *filename, u_int mode, void *addr);
int   sceErxLoadModuleBuffer(u_int *inbuf, u_int objsize, u_int mode, void *addr);
int   sceErxLoadModuleBufferAsync(u_int *inbuf, u_int objsize, u_int mode, void *addr);
int   sceErxLoadStartModuleFile(const char *filename, u_int mode, void *addr, int args, const char *argp, int *result);
int   sceErxLoadStartModuleFileAsync(const char *filename, u_int mode, void *addr, int args, const char *argp, int *result);
int   sceErxLoadStartModuleBuffer(u_int *inbuf, u_int objsize, u_int mode, void *addr,
									const char *filename, int args, const char *argp, int *result);
int   sceErxLoadStartModuleBufferAsync(u_int *inbuf, u_int objsize, u_int mode, void *addr,
									const char *filename, int args, const char *argp, int *result);

int   sceErxStartModule(int modid, const char *filename, int args, const char *argp, int *result);
int   sceErxStartModuleAsync(int modid, const char *filename, int args, const char *argp, int *result);
int   sceErxStopModule(int modid, int args, const char *argp, int *result);
int   sceErxStopModuleAsync(int modid, int args, const char *argp, int *result);
int   sceErxUnloadModule(int modid);
int   sceErxUnloadModuleAsync(int modid);
int   sceErxStopUnloadModule(int modid, int args, const char *argp, int *result);
int   sceErxStopUnloadModuleAsync(int modid, int args, const char *argp, int *result);

int   sceErxSelfStopUnloadModule(int args, const char *argp, int *result);
int   sceErxSelfStopUnloadLoadStartModuleFile(int stopargs, const char *stopargp, int *modresult,
												const char *filename, u_int mode, void *addr, int startargs, const char *startargp);

int   sceErxSync(int mode, int *result);

extern __inline__ void *sceErxQueryGp(void);		/* ���݂�$gp���W�X�^�l��擾 */
extern __inline__ void *sceErxSetGp(void *newgp);	/* $gp���W�X�^�ɐV�����l��ݒ�(�߂�l�͌��݂�$gp�l) */
void *sceErxGetModuleGp(void *target);				/* �w��A�h���X��܂ރ��W���[����_gp�A�h���X�l��擾 */
extern __inline__ void *sceErxSetModuleGp(void);	/* $gp���W�X�^�ɂ��̃��W���[���ł�_gp�A�h���X�l��ݒ�(�߂�l�͌��݂�$gp�l) */

/* ���݂�$gp���W�X�^�l��擾 */
extern __inline__ void *sceErxQueryGp(void)
{
	void *gp;
	__asm__ volatile (
		"move		%0, $28\n"
		: "=r"(gp)
		:
		: "memory"
	);
	return (gp);
}

/* $gp���W�X�^�ɐV�����l��ݒ�(�߂�l�͌��݂�$gp�l) */
extern __inline__ void *sceErxSetGp(void *newgp)
{
	void *oldgp;
	__asm__ volatile (
		"move		%0, $28\n"
		"move		$28, %1\n"
		: "=&r"(oldgp)
		: "r"(newgp)
		: "memory"
	);
	return (oldgp);
}

/* $gp���W�X�^�ɂ��̃��W���[���ł�_gp�l��ݒ�(�߂�l�͌��݂�$gp�l) */
extern __inline__ void *sceErxSetModuleGp(void)
{
	void *oldgp;
	__asm__ volatile (
		"move		%0, $28\n"
		"move		$28, %1\n"
		: "=&r"(oldgp)
		: "r"(&_gp)
		: "memory"
	);
	return (oldgp);
}


/* $gp���W�X�^�l�̕ۑ�,���A���֐��Ăяo�� */
/* �X�^�b�N�̃f�[�^��128�o�C�g�����Ƃ��ăR�s�[,�߂�l�̓|�C���^�^��z�� */
#if defined(SCE_ERX_USE_GPEXECHELPER)

/* �Ăяo����֐��|�C���^���܂܂�郂�W���[������_gp����肷�� */
void *sceErxExecModuleFunction(void (*pFunc)(), ...);

#if !defined(__GNUC__)

/* $gp���W�X�^�̒l�𖾎��I�Ɏw�肵�Ċ֐��Ăяo�� */
void *sceErxExecGpFunction(void *newgp, void (*pFunc)(), ...);

#else	/* !defined(__GNUC__) */

/* $gp���W�X�^�̒l�𖾎��I�Ɏw�肵�Ċ֐��Ăяo�� */
extern __inline__ void *sceErxExecGpFunction(void *newgp, void (*pFunc)(), ...);

extern __inline__ void *sceErxExecGpFunction(void *newgp, void (*pFunc)(), ...)
{
	void *oldgp;
	void *pReturn;

	/* $gp���W�X�^�̕ۑ��ƐV����$gp���W�X�^�l�ݒ� */
	oldgp = sceErxSetGp(newgp);

	/* �ԐړI�Ȋ֐��̌Ăяo�� */
	pReturn  = __builtin_apply(pFunc, __builtin_apply_args(), 128);

	/* $gp���W�X�^�l���A */
	sceErxSetGp(oldgp);
	__builtin_return (pReturn);
}
#endif	/* !defined(__GNUC__) */
#endif	/* SCE_ERX_USE_GPEXECHELPER */

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif	/* _LIBERX_H */
