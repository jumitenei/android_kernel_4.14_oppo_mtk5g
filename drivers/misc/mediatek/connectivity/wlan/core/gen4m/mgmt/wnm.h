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
 * Id: //Department/DaVinci/TRUNK/MT6620_5931_WiFi_Driver/include/mgmt/wnm.h#1
 */

/*! \file  wnm.h
 *    \brief This file contains the IEEE 802.11 family related 802.11v
 *		network management for MediaTek 802.11 Wireless LAN Adapters.
 */


#ifndef _WNM_H
#define _WNM_H

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

/*******************************************************************************
 *                         D A T A   T Y P E S
 *******************************************************************************
 */

struct TIMINGMSMT_PARAM {
	u_int8_t fgInitiator;
	uint8_t ucTrigger;
	uint8_t ucDialogToken;	/* Dialog Token */
	uint8_t ucFollowUpDialogToken;	/* Follow Up Dialog Token */
	uint32_t u4ToD;		/* Timestamp of Departure [10ns] */
	uint32_t u4ToA;		/* Timestamp of Arrival [10ns] */
};

struct BSS_TRANSITION_MGT_PARAM {
	/* for Query */
	uint8_t ucQueryDialogToken;
	uint8_t fgWaitBtmRequest;
	/* for Request */
	uint8_t ucDialogToken;
	uint8_t ucRequestMode;
	uint16_t u2DisassocTimer;
	uint16_t u2TermDuration;
	uint8_t aucTermTsf[8];
	uint8_t ucSessionURLLen;
	uint8_t aucSessionURL[255];
	/* for Respone */
	uint8_t fgPendingResponse:1;
	uint8_t fgIsMboPresent:1;
	uint8_t fgWaitBtmRespDone:1;
	u_int8_t fgReserved:5;
	uint8_t ucStatusCode;
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
#define WNM_MAX_NEIGHBOR_REPORT 10

/* IEEE 802.11v - BSS Transition Management Request - Request Mode */
#define WNM_BSS_TM_REQ_PREF_CAND_LIST_INCLUDED BIT(0)
#define WNM_BSS_TM_REQ_ABRIDGED BIT(1)
#define WNM_BSS_TM_REQ_DISASSOC_IMMINENT BIT(2)
#define WNM_BSS_TM_REQ_BSS_TERMINATION_INCLUDED BIT(3)
#define WNM_BSS_TM_REQ_ESS_DISASSOC_IMMINENT BIT(4)

/* IEEE Std 802.11-2012 - Table 8-253 */
enum BSS_TRANS_MGMT_STATUS_CODE {
	WNM_BSS_TM_ACCEPT = 0,
	WNM_BSS_TM_REJECT_UNSPECIFIED = 1,
	WNM_BSS_TM_REJECT_INSUFFICIENT_BEACON = 2,
	WNM_BSS_TM_REJECT_INSUFFICIENT_CAPABITY = 3,
	WNM_BSS_TM_REJECT_UNDESIRED = 4,
	WNM_BSS_TM_REJECT_DELAY_REQUEST = 5,
	WNM_BSS_TM_REJECT_STA_CANDIDATE_LIST_PROVIDED = 6,
	WNM_BSS_TM_REJECT_NO_SUITABLE_CANDIDATES = 7,
	WNM_BSS_TM_REJECT_LEAVING_ESS = 8
};

/* 802.11v Table 9-176: define Transtion and Transition Query reasons */
#define BSS_TRANSITION_LOAD_BALANCING                   5
#define BSS_TRANSITION_BETTER_AP_FOUND                  6
#define BSS_TRANSITION_LOW_RSSI                         16
#define BSS_TRANSITION_INCLUDE_PREFER_CAND_LIST         19
#define BSS_TRANSITION_LEAVING_ESS                      20

/*******************************************************************************
 *                  F U N C T I O N   D E C L A R A T I O N S
 *******************************************************************************
 */

void wnmWNMAction(IN struct ADAPTER *prAdapter,
		  IN struct SW_RFB *prSwRfb);

void wnmReportTimingMeas(IN struct ADAPTER *prAdapter,
			 IN uint8_t ucStaRecIndex, IN uint32_t u4ToD,
			 IN uint32_t u4ToA);

#if WNM_UNIT_TEST
void wnmTimingMeasUnitTest1(struct ADAPTER *prAdapter,
			    uint8_t ucStaRecIndex);
#endif

void wnmRecvBTMRequest(IN struct ADAPTER *prAdapter, IN struct SW_RFB *prSwRfb);

void wnmSendBTMQueryFrame(IN struct ADAPTER *prAdapter,
		 IN struct STA_RECORD *prStaRec, IN uint8_t ucQueryReason);

uint8_t wnmSendBTMResponse(IN struct ADAPTER *prAdapter,
	IN const uint8_t *aucBssid, IN uint8_t ucStatus,
	IN uint8_t ucReason, IN uint8_t ucBssIndex);

/*******************************************************************************
 *                              F U N C T I O N S
 *******************************************************************************
 */

#endif /* _WNM_H */
