/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

#ifndef _GL_P2P_OS_H
#define _GL_P2P_OS_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include <linux/netdevice.h>
#if CFG_ENABLE_WIFI_DIRECT_CFG_80211
#include <net/cfg80211.h>
#endif

#include "wlan_oid.h"

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/
#define OID_SET_GET_STRUCT_LENGTH		4096	/* For SET_STRUCT/GET_STRUCT */

#define MAX_P2P_IE_SIZE	5

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/
extern struct net_device *g_P2pPrDev;

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

struct _GL_P2P_INFO_T {

	/* Device handle */
	struct net_device *prDevHandler;

#if CFG_ENABLE_WIFI_DIRECT_CFG_80211
	/* cfg80211 */
	struct wireless_dev *prWdev;

	struct cfg80211_scan_request *prScanRequest;

	UINT_64 u8Cookie;

	/* Generation for station list update. */
	INT_32 i4Generation;

	UINT_32 u4OsMgmtFrameFilter;

#endif

	/* Device statistics */
	struct net_device_stats rNetDevStats;

	/* glue layer variables */
	UINT_32 u4FreqInKHz;	/* frequency */
	UINT_8 ucRole;		/* 0: P2P Device, 1: Group Client, 2: Group Owner */
	UINT_8 ucIntent;	/* range: 0-15 */
	UINT_8 ucScanMode;	/* 0: Search & Listen, 1: Scan without probe response */

	ENUM_PARAM_MEDIA_STATE_T eState;
	UINT_32 u4PacketFilter;
	PARAM_MAC_ADDRESS aucMCAddrList[MAX_NUM_GROUP_ADDR];

	/* connection-requested peer information */
	UINT_8 aucConnReqDevName[32];
	INT_32 u4ConnReqNameLength;
	PARAM_MAC_ADDRESS rConnReqPeerAddr;
	PARAM_MAC_ADDRESS rConnReqGroupAddr;	/* For invitation group. */
	UINT_8 ucConnReqDevType;
	INT_32 i4ConnReqConfigMethod;
	INT_32 i4ConnReqActiveConfigMethod;

	UINT_32 u4CipherPairwise;
	UINT_8 ucWSCRunning;

	UINT_8 aucWSCIE[3][400];	/* 0 for beacon, 1 for probe req, 2 for probe response */
	UINT_16 u2WSCIELen[3];

	UINT_8 aucP2PIE[MAX_P2P_IE_SIZE][400];
	UINT_16 u2P2PIELen[MAX_P2P_IE_SIZE];

#if CFG_SUPPORT_WFD
	UINT_8 aucWFDIE[400];
	UINT_16 u2WFDIELen;
	UINT_8 aucVenderIE[1024];	/* Save the other IE for prove resp */
	UINT_16 u2VenderIELen;
#endif

	UINT_8 ucOperatingChnl;
	UINT_8 ucInvitationType;

	UINT_32 u4InvStatus;

	/* For SET_STRUCT/GET_STRUCT */
	UINT_8 aucOidBuf[OID_SET_GET_STRUCT_LENGTH];

#if 1				/* CFG_SUPPORT_ANTI_PIRACY */
	UINT_8 aucSecCheck[256];
	UINT_8 aucSecCheckRsp[256];
#endif

	/*
	 * Hotspot Client Management
	 */
	/* TODO: It is better to maintain the black MAC address with a linked list. */
	PARAM_MAC_ADDRESS aucBlackMACList[10];
	UINT_8 ucMaxClients;

#if CFG_SUPPORT_HOTSPOT_OPTIMIZATION
	UINT_32 u4PsLevel;
#endif
};

#if CONFIG_NL80211_TESTMODE
typedef struct _NL80211_DRIVER_TEST_PRE_PARAMS {
	UINT_16 idx_mode;
	UINT_16 idx;
	UINT_32 value;
} NL80211_DRIVER_TEST_PRE_PARAMS, *P_NL80211_DRIVER_TEST_PRE_PARAMS;

typedef struct _NL80211_DRIVER_TEST_PARAMS {
	UINT_32 index;
	UINT_32 buflen;
} NL80211_DRIVER_TEST_PARAMS, *P_NL80211_DRIVER_TEST_PARAMS;

/* P2P Sigma*/
typedef struct _NL80211_DRIVER_P2P_SIGMA_PARAMS {
	NL80211_DRIVER_TEST_PARAMS hdr;
	UINT_32 idx;
	UINT_32 value;
} NL80211_DRIVER_P2P_SIGMA_PARAMS, *P_NL80211_DRIVER_P2P_SIGMA_PARAMS;

/* Hotspot Client Management */
typedef struct _NL80211_DRIVER_HOTSPOT_BLOCK_PARAMS {
	NL80211_DRIVER_TEST_PARAMS hdr;
	UINT_8 ucblocked;
	UINT_8 aucBssid[MAC_ADDR_LEN];
} NL80211_DRIVER_HOTSPOT_BLOCK_PARAMS, *P_NL80211_DRIVER_HOTSPOT_BLOCK_PARAMS;

/* Hotspot Management set config */
struct NL80211_DRIVER_HOTSPOT_CONFIG_PARAMS {
	NL80211_DRIVER_TEST_PARAMS hdr;
	UINT_32 idx;
	UINT_32 value;
};

#if CFG_SUPPORT_WFD
typedef struct _NL80211_DRIVER_WFD_PARAMS {
	NL80211_DRIVER_TEST_PARAMS hdr;
	UINT_32 WfdCmdType;
	UINT_8 WfdEnable;
	UINT_8 WfdCoupleSinkStatus;
	UINT_8 WfdSessionAvailable;
	UINT_8 WfdSigmaMode;
	UINT_16 WfdDevInfo;
	UINT_16 WfdControlPort;
	UINT_16 WfdMaximumTp;
	UINT_16 WfdExtendCap;
	UINT_8 WfdCoupleSinkAddress[MAC_ADDR_LEN];
	UINT_8 WfdAssociatedBssid[MAC_ADDR_LEN];
	UINT_8 WfdVideoIp[4];
	UINT_8 WfdAudioIp[4];
	UINT_16 WfdVideoPort;
	UINT_16 WfdAudioPort;
	UINT_32 WfdFlag;
	UINT_32 WfdPolicy;
	UINT_32 WfdState;
	UINT_8 WfdSessionInformationIE[24 * 8];	/* Include Subelement ID, length */
	UINT_16 WfdSessionInformationIELen;
	UINT_8 aucReserved1[2];
	UINT_8 aucWfdPrimarySinkMac[MAC_ADDR_LEN];
	UINT_8 aucWfdSecondarySinkMac[MAC_ADDR_LEN];
	UINT_32 WfdAdvanceFlag;
	/* Group 1 64 bytes */
	UINT_8 aucWfdLocalIp[4];
	UINT_16 WfdLifetimeAc2;	/* Unit is 2 TU */
	UINT_16 WfdLifetimeAc3;	/* Unit is 2 TU */
	UINT_16 WfdCounterThreshold;	/* Unit is ms */
	UINT_8 aucReserved2[54];
	/* Group 3 64 bytes */
	UINT_8 aucReserved3[64];
	/* Group 3 64 bytes */
	UINT_8 aucReserved4[64];
} NL80211_DRIVER_WFD_PARAMS, *P_NL80211_DRIVER_WFD_PARAMS;
#endif
#endif

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

BOOLEAN p2pLaunch(P_GLUE_INFO_T prGlueInfo);

BOOLEAN p2pRemove(P_GLUE_INFO_T prGlueInfo);

VOID p2pSetMode(IN BOOLEAN fgIsAPMode);

BOOLEAN glRegisterP2P(P_GLUE_INFO_T prGlueInfo, const char *prDevName, BOOLEAN fgIsApMode);

VOID p2pEalySuspendReg(P_GLUE_INFO_T prGlueInfo, BOOLEAN fgIsEnable);

BOOLEAN glUnregisterP2P(P_GLUE_INFO_T prGlueInfo);

BOOLEAN p2pNetRegister(P_GLUE_INFO_T prGlueInfo, BOOLEAN fgIsRtnlLockAcquired);

BOOLEAN p2pNetUnregister(P_GLUE_INFO_T prGlueInfo, BOOLEAN fgIsRtnlLockAcquired);

BOOLEAN p2pStopImmediate(P_GLUE_INFO_T prGlueInfo);

BOOLEAN p2PFreeInfo(P_GLUE_INFO_T prGlueInfo);

BOOLEAN glP2pCreateWirelessDevice(P_GLUE_INFO_T prGlueInfo);


VOID glP2pDestroyWirelessDevice(VOID);

VOID p2pSetMulticastListWorkQueueWrapper(P_GLUE_INFO_T prGlueInfo);


int p2pHardStartXmit(IN struct sk_buff *prSkb, IN struct net_device *prDev);

#endif
