/* [File] : wf_cr_sw_def.h */
/* [Copyright] : Copyright (C) 2018 Mediatek Incorportion. All rights reserved.
*/

/*******************************************************************************
* Copyright (c) 2009 MediaTek Inc.
*
* All rights reserved. Copying, compilation, modification, distribution
* or any other use whatsoever of this material is strictly prohibited
* except in accordance with a Software License Agreement with
* MediaTek Inc.
********************************************************************************
*/

/*******************************************************************************
* LEGAL DISCLAIMER
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
* AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK
* SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE
* PROVIDED TO BUYER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY
* DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE
* ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY
* WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK
* SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY
* WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE
* FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION OR TO
* CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL
* BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT
* ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY
* BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT
* OF LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING
* THEREOF AND RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN
* FRANCISCO, CA, UNDER THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE
* (ICC).
********************************************************************************
*/

#ifndef _WF_CR_SW_DEF_H
#define _WF_CR_SW_DEF_H

/*******************************************************************************
* M A C R O S
********************************************************************************
*/


/******************************************************************************
*
*                     MCU_SYSRAM SW CR Definitions
*
******************************************************************************
*/
#define WF_SW_DEF_CR_BASE                0x00400E00

#define WF_SW_DEF_CR_SER_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x000) /* E00 */
#define WF_SW_DEF_CR_PLE_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x004) /* E04 */
#define WF_SW_DEF_CR_PLE1_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x008) /* E08 */
#define WF_SW_DEF_CR_PLE_AMSDU_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x00C) /* E0C */
#define WF_SW_DEF_CR_PSE_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x010) /* E10 */
#define WF_SW_DEF_CR_PSE1_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x014) /* E14 */
#define WF_SW_DEF_CR_LAMC_WISR6_BN0_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x018) /* E18 */
#define WF_SW_DEF_CR_LAMC_WISR6_BN1_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x01C) /* E1C */
#define WF_SW_DEF_CR_LAMC_WISR7_BN0_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x020) /* E20 */
#define WF_SW_DEF_CR_LAMC_WISR7_BN1_STATUS_ADDR \
	(WF_SW_DEF_CR_BASE + 0x024) /* E24 */
#define WF_SW_DEF_CR_USB_MCU_EVENT_ADD \
	(WF_SW_DEF_CR_BASE + 0x028) /* E28 */
#define WF_SW_DEF_CR_USB_HOST_ACK_ADDR \
	(WF_SW_DEF_CR_BASE + 0x02C) /* E2C */
#define WF_SW_DEF_CR_ICAP_SPECTRUM_MODE_ADDR \
		(WF_SW_DEF_CR_BASE + 0x030) /* E30 */

#endif /* _WF_CR_SW_DEF_H */


