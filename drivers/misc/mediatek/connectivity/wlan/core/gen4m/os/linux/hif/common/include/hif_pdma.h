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
 Module Name:
 hif_pdma.h
 */

#ifndef __HIF_PDMA_H__
#define __HIF_PDMA_H__

#include <linux/list_sort.h>
#include "mt66xx_reg.h"

/*******************************************************************************
 *                              C O N S T A N T S
 *******************************************************************************
 */
#define NUM_OF_WFDMA1_TX_RING			0
#define NUM_OF_WFDMA1_RX_RING			0

#if (CFG_SUPPORT_CONNAC2X == 1)

#undef NUM_OF_WFDMA1_TX_RING
#ifdef CONFIG_NUM_OF_WFDMA_TX_RING
#define NUM_OF_WFDMA1_TX_RING			(CONFIG_NUM_OF_WFDMA_TX_RING)
#else
#define NUM_OF_WFDMA1_TX_RING			1  /* WA CMD Ring */
#endif

#undef NUM_OF_WFDMA1_RX_RING
#ifdef CONFIG_NUM_OF_WFDMA_RX_RING
#define NUM_OF_WFDMA1_RX_RING			(CONFIG_NUM_OF_WFDMA_RX_RING)
#else
#define NUM_OF_WFDMA1_RX_RING			5
#endif

#endif /* CFG_SUPPORT_CONNAC2X == 1 */

/*
 * 3 data ring (ring0 + ring1[DBDC] + ring2[priority])
 * fwdl ring
 * cmd ring
 */
#define NUM_OF_TX_RING				(5+NUM_OF_WFDMA1_TX_RING)
#define NUM_OF_RX_RING				(2+NUM_OF_WFDMA1_RX_RING)

#ifdef CONFIG_MTK_WIFI_HE160
#define TX_RING_SIZE				1024
#define RX_RING_SIZE				1024 /* Max Rx ring size */
/* Data Rx ring */
#define RX_RING0_SIZE				1024
/* Event/MSDU_report Rx ring */
#define RX_RING1_SIZE				128
#define HIF_NUM_OF_QM_RX_PKT_NUM	4096
#define HIF_TX_MSDU_TOKEN_NUM		(TX_RING_SIZE * 4)
#elif defined(CONFIG_MTK_WIFI_HE80)
#define TX_RING_SIZE				1024
#define RX_RING_SIZE				1024 /* Max Rx ring size */
/* Data Rx ring */
#define RX_RING0_SIZE				1024
/* Event/MSDU_report Rx ring */
#define RX_RING1_SIZE				16
#define HIF_NUM_OF_QM_RX_PKT_NUM	2048
#define HIF_TX_MSDU_TOKEN_NUM		(TX_RING_SIZE * 2)
#elif defined(CONFIG_MTK_WIFI_VHT80)
#define TX_RING_SIZE				512
#define RX_RING_SIZE				512	/* Max Rx ring size */
/* Data Rx ring */
#define RX_RING0_SIZE				512
/* Event/MSDU_report Rx ring */
#define RX_RING1_SIZE				16
#define HIF_NUM_OF_QM_RX_PKT_NUM	2048
#define HIF_TX_MSDU_TOKEN_NUM		(TX_RING_SIZE * 3)
#else
#define TX_RING_SIZE				256
#define RX_RING_SIZE				256	/* Max Rx ring size */
/* Data Rx ring */
#define RX_RING0_SIZE				256
/* Event/MSDU_report Rx ring */
#define RX_RING1_SIZE				16
#define HIF_NUM_OF_QM_RX_PKT_NUM	2048
#define HIF_TX_MSDU_TOKEN_NUM		(TX_RING_SIZE * 3)
#endif

/* TXD_SIZE = TxD + TxInfo */
#define TXD_SIZE					16
#define RXD_SIZE					16

#define RX_BUFFER_AGGRESIZE			3840
#define RX_BUFFER_NORMSIZE			3840
#define TX_BUFFER_NORMSIZE			3840

#define HIF_TX_PREALLOC_DATA_BUFFER			1

#define HIF_IST_LOOP_COUNT					32
/* Min msdu count to trigger Tx during INT polling state */
#define HIF_IST_TX_THRESHOLD				1

#define HIF_TX_BUFF_COUNT_TC0				4096
#define HIF_TX_BUFF_COUNT_TC1				4096
#define HIF_TX_BUFF_COUNT_TC2				4096
#define HIF_TX_BUFF_COUNT_TC3				4096
#define HIF_TX_BUFF_COUNT_TC4				(TX_RING_SIZE - 1)
#define HIF_TX_BUFF_COUNT_TC5				4096

/* enable/disable TX resource control */
#define HIF_TX_RESOURCE_CTRL                1
/* enable/disable TX resource control PLE */
#define HIF_TX_RESOURCE_CTRL_PLE            0


#define HIF_TX_PAGE_SIZE_IN_POWER_OF_2		11
/* in unit of bytes */
#define HIF_TX_PAGE_SIZE					2048

#define HIF_EXTRA_IO_BUFFER_SIZE			0

#define HIF_TX_COALESCING_BUFFER_SIZE		(TX_BUFFER_NORMSIZE)
#define HIF_RX_COALESCING_BUFFER_SIZE		(RX_BUFFER_AGGRESIZE)

#define HIF_CR4_FWDL_SECTION_NUM			1
#define HIF_IMG_DL_STATUS_PORT_IDX			1

#define HIF_TX_INIT_CMD_PORT				TX_RING_FWDL_IDX_4

#define HIF_TX_PAYLOAD_LENGTH				72

#define HIF_MSDU_REPORT_RETURN_TIMEOUT		10	/* sec */
#define HIF_SER_TIMEOUT				10000	/* msec */
#define HIF_SER_POWER_OFF_RETRY_COUNT		100
#define HIF_SER_POWER_OFF_RETRY_TIME		10	/* msec */

#define MT_RINGREG_DIFF		0x10
#define MT_RINGREG_EXT_DIFF	0x04

#define MT_TX_RING_BASE		WPDMA_TX_RING0_CTRL0
#define MT_TX_RING_PTR		WPDMA_TX_RING0_CTRL0
#define MT_TX_RING_CNT		WPDMA_TX_RING0_CTRL1
#define MT_TX_RING_CIDX		WPDMA_TX_RING0_CTRL2
#define MT_TX_RING_DIDX		WPDMA_TX_RING0_CTRL3

#define MT_RX_RING_BASE		WPDMA_RX_RING0_CTRL0
#define MT_RX_RING_PTR		WPDMA_RX_RING0_CTRL0
#define MT_RX_RING_CNT		WPDMA_RX_RING0_CTRL1
#define MT_RX_RING_CIDX		WPDMA_RX_RING0_CTRL2
#define MT_RX_RING_DIDX		WPDMA_RX_RING0_CTRL3

#define DMA_LOWER_32BITS_MASK   0x00000000FFFFFFFF
#define DMA_HIGHER_4BITS_MASK   0x0000000F
#define DMA_BITS_OFFSET		32

#define DMA_DONE_WAITING_TIME   10
#define DMA_DONE_WAITING_COUNT  (100 * 1000)

#define MT_TX_RING_BASE_EXT WPDMA_TX_RING0_BASE_PTR_EXT
#define MT_RX_RING_BASE_EXT WPDMA_RX_RING0_BASE_PTR_EXT

#define PDMA_DUMMY_RESET_VALUE  0x0F
#define PDMA_DUMMY_MAGIC_NUM    0x13

#define TXD_DW1_RMVL            BIT(10)
#define TXD_DW1_VLAN            BIT(11)
#define TXD_DW1_ETYP            BIT(12)
#define TXD_DW1_AMSDU_C         BIT(20)

#define HIF_DEADFEED_VALUE      0xdeadfeed

#define HIF_DEFAULT_BSS_FREE_CNT	64

#define HIF_FLAG_SW_WFDMA_INT		BIT(0)
#define HIF_FLAG_SW_WFDMA_INT_BIT	(0)

#define SW_WFDMA_CMD_NUM		4
#define SW_WFDMA_CMD_PKT_SIZE		1600
#define SW_WFDMA_EMI_SIZE \
	(SW_WFDMA_CMD_NUM * SW_WFDMA_CMD_PKT_SIZE + 8)
#define SW_WFDMA_MAX_RETRY_COUNT	100
#define SW_WFDMA_RETRY_TIME		10

#define MSDU_TOKEN_HISTORY_NUM 5

#define LOG_DUMP_COUNT_PERIOD		5
#define LOG_DUMP_FULL_DUMP_TIMES	2

/*******************************************************************************
 *                                 M A C R O S
 *******************************************************************************
 */

#define INC_RING_INDEX(_idx, _RingSize)		\
{ \
	(_idx) = (_idx+1) % (_RingSize); \
}

#define RTMP_IO_READ32(_A, _R, _pV) \
{ \
	(*(_pV) = readl((void *)((_A)->CSRBaseAddress + (_R)))); \
}

#define RTMP_IO_WRITE32(_A, _R, _V) \
{ \
	writel(_V, (void *)((_A)->CSRBaseAddress + (_R))); \
}

#define RTMP_IO_MEM_COPY(_A, _D, _S, _N) \
{ \
	memcpy_toio((void *)((_A)->CSRBaseAddress + (_D)), (void *) _S, _N); \
}

/*******************************************************************************
 *                             D A T A   T Y P E S
 *******************************************************************************
 */

enum ENUM_TX_RING_IDX {
	TX_RING_DATA0_IDX_0 = 0,
	TX_RING_DATA1_IDX_1,
	TX_RING_DATA2_IDX_2,
	TX_RING_CMD_IDX_3,
	TX_RING_FWDL_IDX_4,
	TX_RING_WA_CMD_IDX_5,
};

enum ENUM_RX_RING_IDX {
	RX_RING_DATA_IDX_0 = 0,
	RX_RING_EVT_IDX_1,
	RX_RING_DATA1_IDX_2,
	RX_RING_TXDONE0_IDX_3,
	RX_RING_TXDONE1_IDX_4,
	RX_RING_WAEVT0_IDX_5,
	RX_RING_WAEVT1_IDX_6,
};

/* ============================================================================
 * PCI/RBUS TX / RX Frame Descriptors format
 *
 * Memory Layout
 *
 * 1. Tx Descriptor
 * TxD (12 bytes) + TXINFO (4 bytes)
 * 2. Packet Buffer
 * TXWI + 802.11
 * 31                                                                         0
 * +--------------------------------------------------------------------------+
 * |                                   SDP0[31:0]                             |
 * +-+--+---------------------+-+--+------------------------------------------+
 * |D |L0|       SDL0[13:0]              |B|L1|                    SDL1[13:0] |
 * +-+--+---------------------+-+--+------------------------------------------+
 * |                                   SDP1[31:0]                             |
 * +--------------------------------------------------------------------------+
 * |                                  TX / RX INFO                            |
 * +--------------------------------------------------------------------------+
 * =========================================================================
 */
/*
 *  TX descriptor format for Tx Data/Mgmt Rings
 */
struct TXD_STRUCT {
	/* Word 0 */
	uint32_t SDPtr0;

	/* Word 1 */
	uint32_t SDLen1:14;
	uint32_t LastSec1:1;
	uint32_t Burst:1;
	uint32_t SDLen0:14;
	uint32_t LastSec0:1;
	uint32_t DMADONE:1;

	/*Word2 */
	uint32_t SDPtr1;

	/*Word3 */
	uint16_t SDPtr0Ext;
	uint16_t SDPtr1Ext;
};

/*
 *  Rx descriptor format for Rx Rings
 */
struct RXD_STRUCT {
	/* Word 0 */
	uint32_t SDPtr0;

	/* Word 1 */
	uint32_t SDLen1:14;
	uint32_t LastSec1:1;
	uint32_t Burst:1;
	uint32_t SDLen0:14;
	uint32_t LastSec0:1;
	uint32_t DMADONE:1;

	/* Word 2 */
	uint32_t SDPtr1;

	/* Word 3 */
	uint32_t RXINFO;
};

/*
 *	Data buffer for DMA operation, the buffer must be contiguous
 *	physical memory Both DMA to / from CPU use the same structure.
 */
struct RTMP_DMABUF {
	unsigned long AllocSize;
	void *AllocVa;		/* TxBuf virtual address */
	phys_addr_t AllocPa;		/* TxBuf physical address */
};

/*
 *	Control block (Descriptor) for all ring descriptor DMA operation,
 *	buffer must be contiguous physical memory. NDIS_PACKET stored the
 *	binding Rx packet descriptor which won't be released, driver has to
 *	wait until upper layer return the packet before giveing up this rx
 *	ring descriptor to ASIC. NDIS_BUFFER is assocaited pair to describe
 *	the packet buffer. For Tx, NDIS_PACKET stored the tx packet descriptor
 *  which driver should ACK upper layer when the tx is physically done or
 *  failed.
 */
struct RTMP_DMACB {
	unsigned long AllocSize;	/* Control block size */
	void *AllocVa;			/* Control block virtual address */
	phys_addr_t AllocPa;	        /* Control block physical address */
	void *pPacket;
	void *pBuffer;
	phys_addr_t PacketPa;
	struct RTMP_DMABUF DmaBuf;	/* Associated DMA buffer structure */
	struct MSDU_TOKEN_ENTRY *prToken;
};

struct RTMP_TX_RING {
	struct RTMP_DMACB Cell[TX_RING_SIZE];
	uint32_t TxCpuIdx;
	uint32_t TxDmaIdx;
	uint32_t u4BufSize;
	uint32_t TxSwUsedIdx;
	uint32_t u4UsedCnt;
	uint32_t hw_desc_base;
	uint32_t hw_desc_base_ext;
	uint32_t hw_cidx_addr;
	uint32_t hw_didx_addr;
	uint32_t hw_cnt_addr;
};

struct RTMP_RX_RING {
	struct RTMP_DMACB Cell[RX_RING_SIZE];
	uint32_t RxCpuIdx;
	uint32_t RxDmaIdx;
	uint32_t u4BufSize;
	uint32_t u4RingSize;
	u_int8_t fgRxSegPkt;
	uint32_t hw_desc_base;
	uint32_t hw_desc_base_ext;
	uint32_t hw_cidx_addr;
	uint32_t hw_didx_addr;
	uint32_t hw_cnt_addr;
	bool fgIsDumpLog;
	uint32_t u4PendingCnt;
	void *pvPacket;
	uint32_t u4PacketLen;
};

struct PCIE_CHIP_CR_MAPPING {
	uint32_t u4ChipAddr;
	uint32_t u4BusAddr;
	uint32_t u4Range;
};

struct MSDU_TOKEN_ENTRY {
	uint32_t u4Token;
	u_int8_t fgInUsed;
	struct timespec64 rTs;	/* token tx timestamp */
	uint32_t u4CpuIdx;	/* tx ring cell index */
	struct MSDU_INFO *prMsduInfo;
	void *prPacket;
	phys_addr_t rDmaAddr;
	uint32_t u4DmaLength;
	phys_addr_t rPktDmaAddr;
	uint32_t u4PktDmaLength;
	uint16_t u2Port; /* tx ring number */
	uint8_t ucWlanIndex;
	uint8_t ucBssIndex;
};

struct TOKEN_HISTORY {
	uint32_t u4UsedCnt;
	uint32_t u4LongestId;
};

struct MSDU_TOKEN_HISTORY_INFO {
	struct TOKEN_HISTORY au4List[MSDU_TOKEN_HISTORY_NUM];
	uint32_t u4CurIdx;
};

struct MSDU_TOKEN_INFO {
	uint32_t u4UsedCnt;
	struct MSDU_TOKEN_ENTRY *aprTokenStack[HIF_TX_MSDU_TOKEN_NUM];
	spinlock_t rTokenLock;
	struct MSDU_TOKEN_ENTRY arToken[HIF_TX_MSDU_TOKEN_NUM];

	/* control bss index packet number */
	uint32_t u4TxBssCnt[MAX_BSSID_NUM];
	uint32_t u4MaxBssFreeCnt;

	struct MSDU_TOKEN_HISTORY_INFO rHistory;
};

struct TX_CMD_REQ {
	struct CMD_INFO *prCmdInfo;
	uint8_t ucTC;
	struct list_head list;
};

struct TX_DATA_REQ {
	struct MSDU_INFO *prMsduInfo;
	struct list_head list;
};

struct AMSDU_MAC_TX_DESC {
	uint16_t u2TxByteCount;
	uint16_t u2DW0;
	uint32_t u4DW1;
	uint32_t u4DW2:31;
	uint32_t u4FR:1;
	uint32_t u4DW3;
	uint32_t u4DW4;
	uint32_t u4DW5_1:9;
	uint32_t u4TXS:2;
	uint32_t u4DW5_2:21;
	uint32_t u4DW6;
	uint32_t u4DW7;
};

struct ERR_RECOVERY_CTRL_T {
	uint8_t eErrRecovState;
	uint32_t u4Status;
	uint32_t u4BackupStatus;
};

struct SW_WFDMA_INFO;

struct SW_WFDMAD {
	uint32_t u4DrvIdx;
	uint32_t u4FwIdx;
	uint8_t aucBuf[SW_WFDMA_CMD_NUM][SW_WFDMA_CMD_PKT_SIZE];
};

struct SW_WFDMA_OPS {
	void (*init)(struct GLUE_INFO *prGlueInfo);
	void (*uninit)(struct GLUE_INFO *prGlueInfo);
	void (*enable)(struct GLUE_INFO *prGlueInfo, bool fgEn);
	void (*reset)(struct SW_WFDMA_INFO *prSwWfdmaInfo);
	void (*backup)(struct GLUE_INFO *prGlueInfo);
	void (*restore)(struct GLUE_INFO *prGlueInfo);
	void (*getCidx)(IN struct GLUE_INFO *prGlueInfo, uint32_t *pu4Cidx);
	void (*setCidx)(IN struct GLUE_INFO *prGlueInfo, uint32_t u4Cidx);
	void (*getDidx)(IN struct GLUE_INFO *prGlueInfo, uint32_t *pu4Didx);
	bool (*writeCmd)(struct GLUE_INFO *prGlueInfo);
	bool (*processDmaDone)(struct GLUE_INFO *prGlueInfo);
	void (*triggerInt)(struct GLUE_INFO *prGlueInfo);
	void (*getIntSta)(struct GLUE_INFO *prGlueInfo,  uint32_t *pu4Sta);
	void (*dumpDebugLog)(struct GLUE_INFO *prGlueInfo);
};

struct SW_WFDMA_INFO {
	struct SW_WFDMA_OPS rOps;
	struct SW_WFDMAD *prDmad;
	struct SW_WFDMAD rBackup;
	bool fgIsEnSwWfdma;
	bool fgIsEnAfterFwdl;
	void *pucIoremapAddr;
	uint32_t u4PortIdx;
	uint32_t u4EmiOffsetAddr;
	uint32_t u4EmiOffsetBase;
	uint32_t u4EmiOffsetMask;
	uint32_t u4EmiOffset;
	uint32_t u4CcifStartAddr;
	uint32_t u4CcifTchnumAddr;
	uint32_t u4CcifChlNum;
	uint32_t u4CpuIdx;
	uint32_t u4DmaIdx;
	uint32_t u4CpuIdxBackup;
	uint32_t u4DmaIdxBackup;
	uint32_t u4MaxCnt;
	uint8_t aucCID[SW_WFDMA_CMD_NUM];
};

enum ENUM_DMA_INT_TYPE {
	DMA_INT_TYPE_MCU2HOST,
	DMA_INT_TYPE_TRX,
	DMA_INT_TYPE_NUM
};

/*******************************************************************************
*                   F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

void halHifRst(struct GLUE_INFO *prGlueInfo);
bool halWpdmaAllocRing(struct GLUE_INFO *prGlueInfo, bool fgAllocMem);
void halWpdmaFreeRing(struct GLUE_INFO *prGlueInfo);
void halWpdmaInitRing(struct GLUE_INFO *prGlueInfo, bool fgResetHif);
void halWpdmaInitTxRing(IN struct GLUE_INFO *prGlueInfo, bool fgResetHif);
void halWpdmaInitRxRing(IN struct GLUE_INFO *prGlueInfo);
void halWpdmaProcessCmdDmaDone(IN struct GLUE_INFO *prGlueInfo,
			       IN uint16_t u2Port);
void halWpdmaProcessDataDmaDone(IN struct GLUE_INFO *prGlueInfo,
				IN uint16_t u2Port);
uint32_t halWpdmaGetRxDmaDoneCnt(IN struct GLUE_INFO *prGlueInfo,
				 IN uint8_t ucRingNum);
void halInitMsduTokenInfo(IN struct ADAPTER *prAdapter);
void halUninitMsduTokenInfo(IN struct ADAPTER *prAdapter);
uint32_t halGetMsduTokenFreeCnt(IN struct ADAPTER *prAdapter);
struct MSDU_TOKEN_ENTRY *halGetMsduTokenEntry(IN struct ADAPTER *prAdapter,
					      uint32_t u4TokenNum);
struct MSDU_TOKEN_ENTRY *halAcquireMsduToken(IN struct ADAPTER *prAdapter,
					     uint8_t ucBssIdx);
void halReturnMsduToken(IN struct ADAPTER *prAdapter, uint32_t u4TokenNum);
void halReturnTimeoutMsduToken(struct ADAPTER *prAdapter);
void halTxUpdateCutThroughDesc(struct GLUE_INFO *prGlueInfo,
			       struct MSDU_INFO *prMsduInfo,
			       struct MSDU_TOKEN_ENTRY *prFillToken,
			       struct MSDU_TOKEN_ENTRY *prDataToken,
			       uint32_t u4Idx, bool fgIsLast);
u_int8_t halChipToStaticMapBusAddr(struct mt66xx_chip_info *prChipInfo,
				   uint32_t u4ChipAddr,
				   uint32_t *pu4BusAddr);
u_int8_t halGetDynamicMapReg(IN struct GLUE_INFO *prGlueInfo,
			     IN uint32_t u4ChipAddr,
			     OUT uint32_t *pu4Value);
u_int8_t halSetDynamicMapReg(IN struct GLUE_INFO *prGlueInfo,
			     IN uint32_t u4ChipAddr,
			     IN uint32_t u4Value);
void halConnacWpdmaConfig(struct GLUE_INFO *prGlueInfo, u_int8_t enable);
void halConnacEnableInterrupt(IN struct ADAPTER *prAdapter);
enum ENUM_CMD_TX_RESULT halWpdmaWriteCmd(struct GLUE_INFO *prGlueInfo,
		      struct CMD_INFO *prCmdInfo,
		      uint8_t ucTC);
bool halWpdmaWriteMsdu(struct GLUE_INFO *prGlueInfo,
		       struct MSDU_INFO *prMsduInfo,
		       struct list_head *prCurList);
bool halWpdmaWriteAmsdu(struct GLUE_INFO *prGlueInfo,
			struct list_head *prList,
			uint32_t u4Num, uint16_t u2Size);
void halWpdamFreeMsdu(struct GLUE_INFO *prGlueInfo,
		      struct MSDU_INFO *prMsduInfo,
		      bool fgSetEvent);

bool kalDevReadData(struct GLUE_INFO *prGlueInfo, uint16_t u2Port,
		    struct SW_RFB *prSwRfb);
bool kalDevKickCmd(struct GLUE_INFO *prGlueInfo);

/* SER functions */
void halSetDrvSer(struct ADAPTER *prAdapter);
#if KERNEL_VERSION(4, 15, 0) <= LINUX_VERSION_CODE
void halHwRecoveryTimeout(struct timer_list *timer);
#else
void halHwRecoveryTimeout(unsigned long arg);
#endif
void halHwRecoveryFromError(IN struct ADAPTER *prAdapter);

/* Debug functions */
int halTimeCompare(struct timespec64 *prTs1, struct timespec64 *prTs2);
void halShowPdmaInfo(IN struct ADAPTER *prAdapter);
bool halShowHostCsrInfo(IN struct ADAPTER *prAdapter);
void kalDumpTxRing(struct GLUE_INFO *prGlueInfo,
		   struct RTMP_TX_RING *prTxRing,
		   uint32_t u4Num, bool fgDumpContent);
void kalDumpRxRing(struct GLUE_INFO *prGlueInfo,
		   struct RTMP_RX_RING *prRxRing,
		   uint32_t u4Num, bool fgDumpContent);
void haldumpPhyInfo(struct ADAPTER *prAdapter);
int wf_ioremap_read(phys_addr_t addr, unsigned int *val);
int wf_ioremap_write(phys_addr_t addr, unsigned int val);
void halEnableSlpProt(struct GLUE_INFO *prGlueInfo);
void halDisableSlpProt(struct GLUE_INFO *prGlueInfo);

void halSwWfdmaInit(struct GLUE_INFO *prGlueInfo);
void halSwWfdmaUninit(struct GLUE_INFO *prGlueInfo);
void halSwWfdmaEn(struct GLUE_INFO *prGlueInfo, bool fgEn);
void halSwWfdmaReset(struct SW_WFDMA_INFO *prSwWfdmaInfo);
void halSwWfdmaBackup(struct GLUE_INFO *prGlueInfo);
void halSwWfdmaRestore(struct GLUE_INFO *prGlueInfo);
void halSwWfdmaGetCidx(struct GLUE_INFO *prGlueInfo, uint32_t *pu4Cidx);
void halSwWfdmaSetCidx(struct GLUE_INFO *prGlueInfo, uint32_t u4Cidx);
void halSwWfdmaGetDidx(struct GLUE_INFO *prGlueInfo, uint32_t *pu4Didx);
bool halSwWfdmaWriteCmd(struct GLUE_INFO *prGlueInfo);
bool halSwWfdmaProcessDmaDone(IN struct GLUE_INFO *prGlueInfo);
void halSwWfdmaDumpDebugLog(struct GLUE_INFO *prGlueInfo);

void halAddDriverLatencyCount(IN struct ADAPTER *prAdapter,
	uint32_t u4DriverLatency);
#endif /* HIF_PDMA_H__ */
