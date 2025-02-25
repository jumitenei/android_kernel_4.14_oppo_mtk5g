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
#include "precomp.h"

uint32_t p2pCalculate_IEForAssocReq(IN struct ADAPTER *prAdapter,
		IN uint8_t ucBssIndex,
		IN struct STA_RECORD *prStaRec)
{
	struct P2P_ROLE_FSM_INFO *prP2pRoleFsmInfo =
		(struct P2P_ROLE_FSM_INFO *) NULL;
	struct BSS_INFO *prP2pBssInfo = (struct BSS_INFO *) NULL;
	struct P2P_CONNECTION_REQ_INFO *prConnReqInfo =
		(struct P2P_CONNECTION_REQ_INFO *) NULL;
	uint32_t u4RetValue = 0;

	do {
		ASSERT_BREAK((prStaRec != NULL) && (prAdapter != NULL));

		prP2pBssInfo = GET_BSS_INFO_BY_INDEX(prAdapter, ucBssIndex);

		prP2pRoleFsmInfo =
			P2P_ROLE_INDEX_2_ROLE_FSM_INFO(prAdapter,
				(uint8_t) prP2pBssInfo->u4PrivateData);

		prConnReqInfo = &(prP2pRoleFsmInfo->rConnReqInfo);

		u4RetValue = prConnReqInfo->u4BufLength;

		/* ADD WMM Information Element */
		u4RetValue += (ELEM_HDR_LEN + ELEM_MAX_LEN_WMM_INFO);

		/* ADD HT Capability */
		if ((prAdapter->rWifiVar.ucAvailablePhyTypeSet
			& PHY_TYPE_SET_802_11N)
			&& (prStaRec->ucPhyTypeSet & PHY_TYPE_SET_802_11N)) {
			u4RetValue += (ELEM_HDR_LEN + ELEM_MAX_LEN_HT_CAP);
		}
#if CFG_SUPPORT_802_11AC
		/* ADD VHT Capability */
		if ((prAdapter->rWifiVar.ucAvailablePhyTypeSet
			& PHY_TYPE_SET_802_11AC)
			&& (prStaRec->ucPhyTypeSet & PHY_TYPE_SET_802_11AC)) {
			u4RetValue += (ELEM_HDR_LEN + ELEM_MAX_LEN_VHT_CAP);
		}
#endif

#if CFG_SUPPORT_MTK_SYNERGY
		if (prAdapter->rWifiVar.ucMtkOui == FEATURE_ENABLED)
			u4RetValue += (ELEM_HDR_LEN + ELEM_MIN_LEN_MTK_OUI);
#endif
	} while (FALSE);

	return u4RetValue;
}				/* p2pCalculate_IEForAssocReq */

/*----------------------------------------------------------------------------*/
/*!
 * @brief This function is used to generate P2P IE for Beacon frame.
 *
 * @param[in] prMsduInfo             Pointer to the composed MSDU_INFO_T.
 *
 * @return none
 */
/*----------------------------------------------------------------------------*/
void p2pGenerate_IEForAssocReq(IN struct ADAPTER *prAdapter,
		IN struct MSDU_INFO *prMsduInfo)
{
	struct BSS_INFO *prBssInfo = (struct BSS_INFO *) NULL;
	struct P2P_ROLE_FSM_INFO *prP2pRoleFsmInfo =
		(struct P2P_ROLE_FSM_INFO *) NULL;
	struct P2P_CONNECTION_REQ_INFO *prConnReqInfo =
		(struct P2P_CONNECTION_REQ_INFO *) NULL;
	uint8_t *pucIEBuf = (uint8_t *) NULL;

	do {
		ASSERT_BREAK((prAdapter != NULL) && (prMsduInfo != NULL));

		prBssInfo =
			GET_BSS_INFO_BY_INDEX(prAdapter,
				prMsduInfo->ucBssIndex);

		prP2pRoleFsmInfo =
			P2P_ROLE_INDEX_2_ROLE_FSM_INFO(prAdapter,
				(uint8_t) prBssInfo->u4PrivateData);

		prConnReqInfo = &(prP2pRoleFsmInfo->rConnReqInfo);

		pucIEBuf = (uint8_t *) ((unsigned long) prMsduInfo->prPacket
			+ (unsigned long) prMsduInfo->u2FrameLength);

		kalMemCopy(pucIEBuf, prConnReqInfo->aucIEBuf,
			prConnReqInfo->u4BufLength);

		prMsduInfo->u2FrameLength += prConnReqInfo->u4BufLength;

		/* Add WMM IE */
		mqmGenerateWmmInfoIE(prAdapter, prMsduInfo);

		/* Add HT IE */
		rlmReqGenerateHtCapIE(prAdapter, prMsduInfo);

#if CFG_SUPPORT_802_11AC
		/* Add VHT IE */
		rlmReqGenerateVhtCapIE(prAdapter, prMsduInfo);
#endif

#if CFG_SUPPORT_MTK_SYNERGY
		rlmGenerateMTKOuiIE(prAdapter, prMsduInfo);
#endif
	} while (FALSE);

	return;

}				/* p2pGenerate_IEForAssocReq */

uint32_t
wfdFuncAppendAttriDevInfo(IN struct ADAPTER *prAdapter,
		IN u_int8_t fgIsAssocFrame,
		IN uint16_t *pu2Offset,
		IN uint8_t *pucBuf,
		IN uint16_t u2BufSize)
{
	uint32_t u4AttriLen = 0;
	uint8_t *pucBuffer = NULL;
	struct WFD_DEVICE_INFORMATION_IE *prWfdDevInfo =
		(struct WFD_DEVICE_INFORMATION_IE *) NULL;
	struct WFD_CFG_SETTINGS *prWfdCfgSettings =
		(struct WFD_CFG_SETTINGS *) NULL;

	do {
		ASSERT_BREAK((prAdapter != NULL)
			&& (pucBuf != NULL) && (pu2Offset != NULL));

		prWfdCfgSettings = &(prAdapter->rWifiVar.rWfdConfigureSettings);

		ASSERT_BREAK((prWfdCfgSettings != NULL));

		if ((prWfdCfgSettings->ucWfdEnable == 0) ||
			((prWfdCfgSettings->u4WfdFlag
			& WFD_FLAGS_DEV_INFO_VALID) == 0)) {
			break;
		}

		pucBuffer = (uint8_t *) ((unsigned long) pucBuf
			+ (unsigned long) (*pu2Offset));

		ASSERT_BREAK(pucBuffer != NULL);

		prWfdDevInfo = (struct WFD_DEVICE_INFORMATION_IE *) pucBuffer;

		prWfdDevInfo->ucElemID = WFD_ATTRI_ID_DEV_INFO;

		WLAN_SET_FIELD_BE16(&prWfdDevInfo->u2WfdDevInfo,
			prWfdCfgSettings->u2WfdDevInfo);

		WLAN_SET_FIELD_BE16(&prWfdDevInfo->u2SessionMgmtCtrlPort,
			prWfdCfgSettings->u2WfdControlPort);

		WLAN_SET_FIELD_BE16(&prWfdDevInfo->u2WfdDevMaxSpeed,
			prWfdCfgSettings->u2WfdMaximumTp);

		WLAN_SET_FIELD_BE16(&prWfdDevInfo->u2Length,
			WFD_ATTRI_MAX_LEN_DEV_INFO);

		u4AttriLen = WFD_ATTRI_MAX_LEN_DEV_INFO + WFD_ATTRI_HDR_LEN;

	} while (FALSE);

	(*pu2Offset) += (uint16_t) u4AttriLen;

	return u4AttriLen;
}

/* wfdFuncAppendAttriDevInfo */
