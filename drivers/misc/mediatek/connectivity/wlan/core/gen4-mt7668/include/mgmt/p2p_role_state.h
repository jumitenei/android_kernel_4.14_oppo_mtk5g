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
#ifndef _P2P_ROLE_STATE_H
#define _P2P_ROLE_STATE_H

VOID
p2pRoleStateInit_IDLE(IN P_ADAPTER_T prAdapter,
		      IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN P_BSS_INFO_T prP2pBssInfo);

VOID
p2pRoleStateAbort_IDLE(IN P_ADAPTER_T prAdapter,
		       IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN P_P2P_CHNL_REQ_INFO_T prP2pChnlReqInfo);

VOID p2pRoleStateInit_SCAN(IN P_ADAPTER_T prAdapter, IN UINT_8 ucBssIndex, IN P_P2P_SCAN_REQ_INFO_T prScanReqInfo);

VOID p2pRoleStateAbort_SCAN(IN P_ADAPTER_T prAdapter, IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo);

VOID
p2pRoleStateInit_REQING_CHANNEL(IN P_ADAPTER_T prAdapter, IN UINT_8 ucBssIdx, IN P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

VOID
p2pRoleStateAbort_REQING_CHANNEL(IN P_ADAPTER_T prAdapter,
				 IN P_BSS_INFO_T prP2pRoleBssInfo,
				 IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN ENUM_P2P_ROLE_STATE_T eNextState);

VOID
p2pRoleStateInit_AP_CHNL_DETECTION(IN P_ADAPTER_T prAdapter,
				   IN UINT_8 ucBssIndex,
				   IN P_P2P_SCAN_REQ_INFO_T prScanReqInfo,
				   IN P_P2P_CONNECTION_REQ_INFO_T prConnReqInfo);

VOID
p2pRoleStateAbort_AP_CHNL_DETECTION(IN P_ADAPTER_T prAdapter,
				    IN UINT_8 ucBssIndex,
				    IN P_P2P_CONNECTION_REQ_INFO_T prP2pConnReqInfo,
				    IN P_P2P_CHNL_REQ_INFO_T prChnlReqInfo,
				    IN P_P2P_SCAN_REQ_INFO_T prP2pScanReqInfo, IN ENUM_P2P_ROLE_STATE_T eNextState);

VOID
p2pRoleStateInit_GC_JOIN(IN P_ADAPTER_T prAdapter,
			 IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

VOID
p2pRoleStateAbort_GC_JOIN(IN P_ADAPTER_T prAdapter,
			  IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo,
			  IN P_P2P_JOIN_INFO_T prJoinInfo, IN ENUM_P2P_ROLE_STATE_T eNextState);

#if (CFG_SUPPORT_DFS_MASTER == 1)
VOID
p2pRoleStateInit_DFS_CAC(IN P_ADAPTER_T prAdapter, IN UINT_8 ucBssIdx, IN P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

VOID
p2pRoleStateAbort_DFS_CAC(IN P_ADAPTER_T prAdapter,
				 IN P_BSS_INFO_T prP2pRoleBssInfo,
				 IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN ENUM_P2P_ROLE_STATE_T eNextState);

VOID
p2pRoleStateInit_SWITCH_CHANNEL(IN P_ADAPTER_T prAdapter, IN UINT_8 ucBssIdx, IN P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

VOID
p2pRoleStateAbort_SWITCH_CHANNEL(IN P_ADAPTER_T prAdapter,
				 IN P_BSS_INFO_T prP2pRoleBssInfo,
				 IN P_P2P_ROLE_FSM_INFO_T prP2pRoleFsmInfo, IN ENUM_P2P_ROLE_STATE_T eNextState);

VOID
p2pRoleStatePrepare_To_DFS_CAC_STATE(IN P_ADAPTER_T prAdapter,
					    IN P_BSS_INFO_T prBssInfo,
					    IN ENUM_CHANNEL_WIDTH_T rChannelWidth,
					    IN P_P2P_CONNECTION_REQ_INFO_T prConnReqInfo,
					    OUT P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

#endif

VOID
p2pRoleStatePrepare_To_REQING_CHANNEL_STATE(IN P_ADAPTER_T prAdapter,
					    IN P_BSS_INFO_T prBssInfo,
					    IN P_P2P_CONNECTION_REQ_INFO_T prConnReqInfo,
					    OUT P_P2P_CHNL_REQ_INFO_T prChnlReqInfo);

#endif
