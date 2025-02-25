/******************************************************************************
 *
 * This file is provided under a dual license.  When you use or
 * distribute this software, you may choose to be licensed under
 * version 2 of the GNU General Public License ("GPLv2 License")
 * or BSD License.
 *
 * GPLv2 License
 *
 * Copyright(C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 *
 * BSD LICENSE
 *
 * Copyright(C) 2016 MediaTek Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
/*
 * Id:
 */

/*! \file   "roaming_fsm.h"
 *    \brief  This file defines the FSM for Roaming MODULE.
 *
 *    This file defines the FSM for Roaming MODULE.
 */


#ifndef _ROAMING_FSM_H
#define _ROAMING_FSM_H

/*******************************************************************************
 *                         C O M P I L E R   F L A G S
 *******************************************************************************
 */

/*******************************************************************************
 *                    E X T E R N A L   R E F E R E N C E S
 *******************************************************************************
 */

/*******************************************************************************
 *                              C O N S T A N T S
 *******************************************************************************
 */
/* Roaming Discovery interval, SCAN result need to be updated */
#define ROAMING_DISCOVER_TIMEOUT_SEC                10	/* Seconds. */
#define ROAMING_INACTIVE_TIMEOUT_SEC                10	/* Seconds. */
#if CFG_SUPPORT_ROAMING_SKIP_ONE_AP
#define ROAMING_ONE_AP_SKIP_TIMES		3
#endif

/* #define ROAMING_NO_SWING_RCPI_STEP                  5 //rcpi */
/*******************************************************************************
 *                             D A T A   T Y P E S
 *******************************************************************************
 */
enum ENUM_ROAMING_FAIL_REASON {
	ROAMING_FAIL_REASON_CONNLIMIT = 0,
	ROAMING_FAIL_REASON_NOCANDIDATE,
	ROAMING_FAIL_REASON_NUM
};

/* events of roaming between driver and firmware */
enum ENUM_ROAMING_EVENT {
	ROAMING_EVENT_START = 0,
	ROAMING_EVENT_DISCOVERY,
	ROAMING_EVENT_ROAM,
	ROAMING_EVENT_FAIL,
	ROAMING_EVENT_ABORT,
	ROAMING_EVENT_THRESHOLD_UPDATE,
	ROAMING_EVENT_NUM
};

enum ENUM_ROAMING_REASON {
	ROAMING_REASON_POOR_RCPI = 0,
	ROAMING_REASON_TX_ERR, /*Lowest rate, high PER*/
	ROAMING_REASON_RETRY,
	ROAMING_REASON_IDLE,
	ROAMING_REASON_BEACON_TIMEOUT,
	ROAMING_REASON_INACTIVE,
	ROAMING_REASON_SAA_FAIL,
	ROAMING_REASON_UPPER_LAYER_TRIGGER,
	ROAMING_REASON_BTM,
	ROAMING_REASON_BTM_DISASSOC,
	ROAMING_REASON_NUM
};

struct CMD_ROAMING_TRANSIT {
	uint16_t u2Event;
	uint16_t u2Data;
	uint16_t u2RcpiLowThreshold;
	uint8_t ucIsSupport11B;
	uint8_t ucBssidx;
	enum ENUM_ROAMING_REASON eReason;
	uint32_t u4RoamingTriggerTime; /*sec in mcu*/
	uint16_t u2RcpiHighThreshold;
	uint8_t aucReserved2[6];
};


struct CMD_ROAMING_CTRL {
	uint8_t fgEnable;
	uint8_t ucRcpiAdjustStep;
	uint16_t u2RcpiLowThr;
	uint8_t ucRoamingRetryLimit;
	uint8_t ucRoamingStableTimeout;
	uint8_t aucReserved[2];
};

#if CFG_SUPPORT_ROAMING_SKIP_ONE_AP
struct CMD_ROAMING_SKIP_ONE_AP {
	uint8_t	  fgIsRoamingSkipOneAP;
	uint8_t	  aucReserved[3];
	uint8_t	  aucReserved2[8];
};
#endif

enum ENUM_ROAMING_STATE {
	ROAMING_STATE_IDLE = 0,
	ROAMING_STATE_DECISION,
	ROAMING_STATE_DISCOVERY,
	ROAMING_STATE_ROAM,
	ROAMING_STATE_NUM
};

struct ROAMING_EVENT_INFO {
	uint8_t ucStatus;
	uint8_t aucPrevBssid[MAC_ADDR_LEN];
	uint8_t aucCurrBssid[MAC_ADDR_LEN];
	uint8_t ucPrevChannel;
	uint8_t ucCurrChannel;
	uint8_t ucPrevRcpi;
	uint8_t ucCurrRcpi;
	uint8_t ucBw;
	uint16_t u2ApLoading;
	uint8_t ucSupportStbc;
};

struct ROAMING_INFO {
	u_int8_t fgIsEnableRoaming;

	enum ENUM_ROAMING_STATE eCurrentState;

	OS_SYSTIME rRoamingDiscoveryUpdateTime;
#if CFG_SUPPORT_DRIVER_ROAMING
	OS_SYSTIME rRoamingLastDecisionTime;
#endif

	u_int8_t fgDrvRoamingAllow;
	enum ENUM_ROAMING_REASON eReason;
	uint8_t ucPER;
	uint8_t ucRcpi;
	uint8_t ucThreshold;
	struct ROAMING_EVENT_INFO rEventInfo;
};

/*******************************************************************************
 *                            P U B L I C   D A T A
 *******************************************************************************
 */

/*******************************************************************************
 *                           P R I V A T E   D A T A
 *******************************************************************************
 */

/*******************************************************************************
 *                                 M A C R O S
 *******************************************************************************
 */


/*******************************************************************************
 *                  F U N C T I O N   D E C L A R A T I O N S
 *******************************************************************************
 */
void roamingFsmInit(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmUninit(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmSendCmd(IN struct ADAPTER *prAdapter,
	IN struct CMD_ROAMING_TRANSIT *prTransit);

void roamingFsmScanResultsUpdate(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmSteps(IN struct ADAPTER *prAdapter,
	IN enum ENUM_ROAMING_STATE eNextState,
	IN uint8_t ucBssIndex);

void roamingFsmRunEventStart(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmRunEventDiscovery(IN struct ADAPTER *prAdapter,
	IN struct CMD_ROAMING_TRANSIT *prTransit);

void roamingFsmRunEventRoam(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmRunEventFail(IN struct ADAPTER *prAdapter,
	IN uint8_t ucReason,
	IN uint8_t ucBssIndex);

void roamingFsmRunEventAbort(IN struct ADAPTER *prAdapter,
	IN uint8_t ucBssIndex);

void roamingFsmNotifyEvent(IN struct ADAPTER *adapter, IN uint8_t bssIndex,
	IN uint8_t ucFail, IN struct BSS_DESC *prBssDesc);

uint32_t roamingFsmProcessEvent(IN struct ADAPTER *prAdapter,
	IN struct CMD_ROAMING_TRANSIT *prTransit);

uint8_t roamingFsmInDecision(struct ADAPTER *prAdapter, uint8_t ucBssIndex);

#endif /* _ROAMING_FSM_H */
