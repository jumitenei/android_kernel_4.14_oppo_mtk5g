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
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/include/nic/hif_tx.h#1
*/


#ifndef _HIF_TX_H
#define _HIF_TX_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/
/* Maximum buffer size for individual HIF TCQ Buffer */
#define HIF_TX_BUFF_MAX_SIZE                1552	/* Reserved field was not included */

/* Maximum buffer count for individual HIF TCQ */
#if 0
#define HIF_TX_BUFF_COUNT_TC0               3
#define HIF_TX_BUFF_COUNT_TC1               3
#define HIF_TX_BUFF_COUNT_TC2               3
#define HIF_TX_BUFF_COUNT_TC3               3
#define HIF_TX_BUFF_COUNT_TC4               2
#endif

#define TX_HDR_SIZE                         sizeof(HIF_TX_HEADER_T)

#define CMD_HDR_SIZE                        sizeof(WIFI_CMD_T)

#define CMD_PKT_SIZE_FOR_IMAGE              2048	/* !< 2048 Bytes CMD payload buffer */

/*! NIC_HIF_TX_HEADER_T (for short-header format) */
/* DW 0, Byte 0,1 */
#define HIF_TX_HDR_TX_BYTE_COUNT_MASK       BITS(0, 15)

/* DW 0, Byte 2 */
#define HIF_TX_HDR_ETHER_TYPE_OFFSET_MASK   BITS(0, 6)
#define HIF_TX_HDR_IP_CSUM                  BIT(7)

/* DW 0, Byte 3 */
#define HIF_TX_HDR_TCP_CSUM                 BIT(0)
#define HIF_TX_HDR_QUEUE_IDX_MASK           BITS(3, 6)
#define HIF_TX_HDR_QUEUE_IDX_OFFSET         3
#define HIF_TX_HDR_PORT_IDX_MASK            BIT(7)
#define HIF_TX_HDR_PORT_IDX_OFFSET          7

/*******************************************************************************
*                         D A T A   T Y P E S
********************************************************************************
*/
typedef struct _HIF_HW_TX_HEADER_T {
	UINT_16 u2TxByteCount;
	UINT_8 ucEtherTypeOffset;
	UINT_8 ucCSflags;
	UINT_8 aucBuffer[0];
} HIF_HW_TX_HEADER_T, *P_HIF_HW_TX_HEADER_T;

typedef struct _HIF_TX_HEADER_T {
	UINT_16 u2TxByteCount_UserPriority;
	UINT_8 ucEtherTypeOffset;
	UINT_8 ucResource_PktType_CSflags;
	UINT_8 ucWlanHeaderLength;
	UINT_8 ucPktFormtId_Flags;
	UINT_16 u2LLH;		/* for BOW */
	UINT_16 u2SeqNo;	/* for BOW */
	UINT_8 ucStaRecIdx;
	UINT_8 ucForwardingType_SessionID_Reserved;
	UINT_8 ucPacketSeqNo;
	UINT_8 ucAck_BIP_BasicRate;
	UINT_8 aucReserved[2];
} HIF_TX_HEADER_T, *P_HIF_TX_HEADER_T;

typedef enum _ENUM_HIF_OOB_CTRL_PKT_TYPE_T {
	HIF_OOB_CTRL_PKT_TYPE_LOOPBACK = 1,
	HIF_OOB_CTRL_PKT_TYP_NUM
} ENUM_HIF_OOB_CTRL_PKT_TYPE_T, *P_ENUM_HIF_OOB_CTRL_PKT_TYPE_T;

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/
#define TFCB_FRAME_PAD_TO_DW(u2Length)      ALIGN_4(u2Length)

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
/* Kevin: we don't have to call following function to inspect the data structure.
 * It will check automatically while at compile time.
 */
static __KAL_INLINE__ VOID hif_txDataTypeCheck(VOID);

static __KAL_INLINE__ VOID hif_txDataTypeCheck(VOID)
{
	DATA_STRUCT_INSPECTING_ASSERT(sizeof(HIF_TX_HEADER_T) == 16);
}

#endif /*_HIF_TX_H */
