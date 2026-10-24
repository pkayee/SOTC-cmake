/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0
 $Id: bnnetcnf.h,v 1.8 2003/04/11 10:07:06 ksh Exp $
 */
/* 
 * Emotion Engine Library
 *
 * Copyright (C) 2002 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 *
 * bnnetcnf - bnnetcnf.h
 *	"PlayStation BB Navigator" Network Configuration Read Library
 *	header
 *
 *      Date            Design      Log
 *  ----------------------------------------------------
 *      2002-07-17      morita      first version
 *      2002-10-07      tetsu       rewrite bnnetcnf.h
 *      2002-10-12      tetsu       correspond to style-guide
 *      2002-10-15      tetsu       change path of sceerrno.h
 *      2002-10-19      tetsu       correspond to code-review
 */

#ifndef _SCE_BNNETCNF_H
#define _SCE_BNNETCNF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <sceerrno.h>

#define SCEBNNETCNF_STR_SIZE_MAX (256)

enum
{
    SCEBNNETCNF_DATA_TYPE_NO_SET = -1, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_TYPE_ETH = 1,     /* type eth */
    SCEBNNETCNF_DATA_TYPE_PPP,         /* type ppp */
    SCEBNNETCNF_DATA_TYPE_NIC          /* type nic */
};

enum
{
    SCEBNNETCNF_DATA_MTU_NO_SET = -1,   /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_MTU_DEFAULT = 1454 /* mtu 1454 */
};

enum
{
    SCEBNNETCNF_DATA_IDLE_TIMEOUT_NO_SET = -1 /* �ݒ肵�Ȃ� */
};

enum
{
    SCEBNNETCNF_DATA_PHY_CONFIG_NO_SET = -1, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_PHY_CONFIG_AUTO = 1,    /* phy_config auto */
    SCEBNNETCNF_DATA_PHY_CONFIG_10,          /* phy_config 10 */
    SCEBNNETCNF_DATA_PHY_CONFIG_10_FD,       /* phy_config 10_fd */
    SCEBNNETCNF_DATA_PHY_CONFIG_TX = 5,      /* phy_config tx */
    SCEBNNETCNF_DATA_PHY_CONFIG_TX_FD        /* phy_config tx_fd */
};

enum
{
    SCEBNNETCNF_DATA_DIALING_TYPE_NO_SET = -1, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_DIALING_TYPE_TONE = 0,    /* dialing_type tone */
    SCEBNNETCNF_DATA_DIALING_TYPE_PULSE        /* dialing_type pulse */
};

enum
{
    SCEBNNETCNF_DATA_DHCP_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_DHCP_NO_USE = 0,    /* -dhcp */
    SCEBNNETCNF_DATA_DHCP_USE            /* dhcp */
};

enum
{
    SCEBNNETCNF_DATA_DNS_NEGO_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_DNS_NEGO_ON = 1         /* want.dns1_nego/want.dns2_nego */
};

enum
{
    SCEBNNETCNF_DATA_F_AUTH_OFF, /* allow.auth chap/pap ��ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_F_AUTH_ON   /* allow.auth chap/pap ��ݒ肷�� */
};

enum
{
    SCEBNNETCNF_DATA_AUTH_CHAP_PAP = 4 /* allow.auth chap/pap */
};

enum
{
    SCEBNNETCNF_DATA_PPPOE_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_PPPOE_USE = 1        /* pppoe */
};

enum
{
    SCEBNNETCNF_DATA_PRC_NEGO_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_PRC_NEGO_OFF = 0        /* -want.prc_nego */
};

enum
{
    SCEBNNETCNF_DATA_ACC_NEGO_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_ACC_NEGO_OFF = 0        /* -want.acc_nego */
};

enum
{
    SCEBNNETCNF_DATA_ACCM_NEGO_NO_SET = 0xff, /* �ݒ肵�Ȃ� */
    SCEBNNETCNF_DATA_ACCM_NEGO_OFF = 0        /* -want.accm_nego */
};

typedef struct SceBnnetcnfData {
    char attach_ifc[SCEBNNETCNF_STR_SIZE_MAX];      /* �ڑ��v���o�C�_�ݒ�t�@�C����(net) */
    char attach_dev[SCEBNNETCNF_STR_SIZE_MAX];      /* �ڑ��@��ݒ�t�@�C����(net) */
    char dhcp_host_name[SCEBNNETCNF_STR_SIZE_MAX];  /* DHCP�p�z�X�g��(ifc) */
    char address[SCEBNNETCNF_STR_SIZE_MAX];         /* IP�A�h���X(ifc) */
    char netmask[SCEBNNETCNF_STR_SIZE_MAX];         /* �l�b�g�}�X�N(ifc) */
    char gateway[SCEBNNETCNF_STR_SIZE_MAX];         /* �f�t�H���g���[�^(ifc) */
    char dns1_address[SCEBNNETCNF_STR_SIZE_MAX];    /* �v���C�}��DNS(ifc) */
    char dns2_address[SCEBNNETCNF_STR_SIZE_MAX];    /* �Z�J���_��DNS(ifc) */
    char phone_numbers1[SCEBNNETCNF_STR_SIZE_MAX];  /* �ڑ���d�b�ԍ�1(ifc) */
    char phone_numbers2[SCEBNNETCNF_STR_SIZE_MAX];  /* �ڑ���d�b�ԍ�2(ifc) */
    char phone_numbers3[SCEBNNETCNF_STR_SIZE_MAX];  /* �ڑ���d�b�ԍ�3(ifc) */
    char auth_name[SCEBNNETCNF_STR_SIZE_MAX];       /* ���[�UID(ifc) */
    char auth_key[SCEBNNETCNF_STR_SIZE_MAX];        /* �p�X���[�h(ifc) */
    char peer_name[SCEBNNETCNF_STR_SIZE_MAX];       /* �ڑ���̔F�ؖ�(ifc) */
    char vendor[SCEBNNETCNF_STR_SIZE_MAX];          /* �x���_��(dev) */
    char product[SCEBNNETCNF_STR_SIZE_MAX];         /* �v���_�N�g��(dev) */
    char chat_additional[SCEBNNETCNF_STR_SIZE_MAX]; /* �ǉ�AT�R�}���h(dev) */
    char outside_number[SCEBNNETCNF_STR_SIZE_MAX];  /* �O�����M�ԍ��ݒ�(�ԍ��ݒ蕔��)(dev) */
    char outside_delay[SCEBNNETCNF_STR_SIZE_MAX];   /* �O�����M�ԍ��ݒ�(�x���ݒ蕔��)(dev) */
    int ifc_type;                                   /* �f�o�C�X���C���̎��(ifc) */
    int mtu;                                        /* MTU�̐ݒ�(ifc) */
    int ifc_idle_timeout;                           /* ����ؒf�ݒ�(ifc) */
    int dev_type;                                   /* �f�o�C�X���C���̎��(dev) */
    int phy_config;                                 /* �C�[�T�l�b�g�ڑ��@��̓��샂�[�h(dev) */
    int dialing_type;                               /* �_�C�A�����@(dev) */
    int dev_idle_timeout;                           /* ����ؒf�ݒ�(dev) */
    int p0;                                         /* �\��̈�0 */
    unsigned char dhcp;                             /* DHCP�g�p�E�s�g�p(ifc) */
    unsigned char dns1_nego;                        /* DNS�T�[�o�A�h���X������擾����E���Ȃ�(ifc) */
    unsigned char dns2_nego;                        /* DNS�T�[�o�A�h���X������擾����E���Ȃ�(ifc) */
    unsigned char f_auth;                           /* �F�ؕ��@�̎w��L��(ifc) */
    unsigned char auth;                             /* �F�ؕ��@(ifc) */
    unsigned char pppoe;                            /* PPPoE�g�p�E�s�g�p(ifc) */
    unsigned char prc_nego;                         /* PFC�l�S�V�G�[�V�����̋֎~(ifc) */
    unsigned char acc_nego;                         /* ACFC�l�S�V�G�[�V�����̋֎~(ifc) */
    unsigned char accm_nego;                        /* ACCM�l�S�V�G�[�V�����̋֎~(ifc) */
    unsigned char p1;                               /* �\��̈�1 */
    unsigned char p2;                               /* �\��̈�2 */
    unsigned char p3;                               /* �\��̈�3 */
    int p4[5];                                      /* �\��̈�4 */
} SceBnnetcnfData __attribute__((aligned(64)));

int sceBnnetcnfRead(const char *fsname, SceBnnetcnfData *data,
		    void *(*func_malloc)(size_t), void (*func_free)(void *));

void *sceBnnetcnfGetErxEntries(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SCE_BNNETCNF_H */
