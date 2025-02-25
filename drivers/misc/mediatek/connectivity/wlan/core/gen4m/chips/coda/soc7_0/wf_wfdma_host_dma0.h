/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */

#ifndef __WF_WFDMA_HOST_DMA0_REGS_H__
#define __WF_WFDMA_HOST_DMA0_REGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define WF_WFDMA_HOST_DMA0_BASE				\
	(0x18024000 + CONN_INFRA_REMAPPING_OFFSET)

#define WF_WFDMA_HOST_DMA0_WPDMA_DBG_IDX_ADDR	\
	(WF_WFDMA_HOST_DMA0_BASE + 0x124)
#define WF_WFDMA_HOST_DMA0_WPDMA_DBG_PROBE_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x128)
#define WF_WFDMA_HOST_DMA0_HOST_INT_STA_ADDR	\
	(WF_WFDMA_HOST_DMA0_BASE + 0x200)
#define WF_WFDMA_HOST_DMA0_HOST_INT_ENA_ADDR	\
	(WF_WFDMA_HOST_DMA0_BASE + 0X204)
#define WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_ADDR	\
	(WF_WFDMA_HOST_DMA0_BASE + 0x208)
#define WF_WFDMA_HOST_DMA0_WPDMA_RST_DTX_PTR_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x20C)
#define WF_WFDMA_HOST_DMA0_HOST_INT_ENA_SET_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0X228)
#define WF_WFDMA_HOST_DMA0_HOST_INT_ENA_CLR_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0X22C)
#define WF_WFDMA_HOST_DMA0_WPDMA_PAUSE_RX_Q_TH10_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x260)
#define WF_WFDMA_HOST_DMA0_WPDMA_RST_DRX_PTR_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x280)
#define WF_WFDMA_HOST_DMA0_WPDMA_INT_RX_PRI_SEL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x298)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING0_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x300)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING0_CTRL1_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x304)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING0_CTRL2_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x308)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING0_CTRL3_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x30c)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING1_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x310)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING2_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x320)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING3_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x330)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING4_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x340)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING5_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x350)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING6_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x360)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING7_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x370)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING8_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x380)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING9_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x390)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING10_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x3a0)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING14_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x3e0)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING15_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x3f0)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING16_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x400)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING17_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x410)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING18_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x420)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x500)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL1_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x504)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL2_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x508)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_CTRL3_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x50c)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x510)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING2_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x520)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING3_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x530)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x540)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x550)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING6_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x560)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING7_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x570)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING8_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x580)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING9_CTRL0_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x590)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING0_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x600)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING1_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x604)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING2_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x608)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING3_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x60C)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING4_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x610)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING5_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x614)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING6_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x618)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING7_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x61C)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING8_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x620)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING9_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x624)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING10_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x628)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING11_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x62C)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING12_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x630)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING13_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x634)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING14_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x638)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING15_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x63C)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING16_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x640)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING17_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x644)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING18_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x648)
#define WF_WFDMA_HOST_DMA0_WPDMA_TX_RING19_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x64C)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING0_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x680)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING1_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x684)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING2_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x688)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING3_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x68C)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING4_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x690)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING5_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x694)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING6_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x698)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING7_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x69C)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING8_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x6A0)
#define WF_WFDMA_HOST_DMA0_WPDMA_RX_RING9_EXT_CTRL_ADDR \
	(WF_WFDMA_HOST_DMA0_BASE + 0x6A4)
#define WF_WFDMA_HOST_DMA0_PDA_CONFG_ADDR	\
	(WF_WFDMA_HOST_DMA0_BASE + 0x80C)

#define WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_CSR_DISP_BASE_PTR_CHAIN_EN_ADDR \
	WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_ADDR
#define WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_CSR_DISP_BASE_PTR_CHAIN_EN_MASK \
	0x00008000
#define WF_WFDMA_HOST_DMA0_WPDMA_GLO_CFG_CSR_DISP_BASE_PTR_CHAIN_EN_SHFT 15

#ifdef __cplusplus
}
#endif

#endif
