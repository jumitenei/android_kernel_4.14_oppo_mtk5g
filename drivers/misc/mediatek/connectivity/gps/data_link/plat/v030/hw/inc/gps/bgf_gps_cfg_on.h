/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#ifndef __BGF_GPS_CFG_ON_REGS_H__
#define __BGF_GPS_CFG_ON_REGS_H__

#define BGF_GPS_CFG_ON_BASE                                    0x80001000

#define BGF_GPS_CFG_ON_GPS_CLKGEN_CTL_ADDR                     (BGF_GPS_CFG_ON_BASE + 0x004)
#define BGF_GPS_CFG_ON_GPS_L1_SLP_PWR_CTL_ADDR                 (BGF_GPS_CFG_ON_BASE + 0x020)
#define BGF_GPS_CFG_ON_GPS_L5_SLP_PWR_CTL_ADDR                 (BGF_GPS_CFG_ON_BASE + 0x024)
#define BGF_GPS_CFG_ON_GPS_OFF_PWR_CTL_ADDR                    (BGF_GPS_CFG_ON_BASE + 0x02c)
#define BGF_GPS_CFG_ON_GPS_CLKGEN1_CTL_ADDR                    (BGF_GPS_CFG_ON_BASE + 0x03C)
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR                    (BGF_GPS_CFG_ON_BASE + 0x400)
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR                    (BGF_GPS_CFG_ON_BASE + 0x404)
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_ADDR                (BGF_GPS_CFG_ON_BASE + 0x408)
#define BGF_GPS_CFG_ON_GPS_ON_MET_START_ADDR_ADDR              (BGF_GPS_CFG_ON_BASE + 0x40c)
#define BGF_GPS_CFG_ON_GPS_ON_MET_END_ADDR_ADDR                (BGF_GPS_CFG_ON_BASE + 0x410)
#define BGF_GPS_CFG_ON_GPS_ON_MET_WRITE_PTR_ADDR               (BGF_GPS_CFG_ON_BASE + 0x414)
#define BGF_GPS_CFG_ON_GPS_ON_MET_READ_PTR_ADDR                (BGF_GPS_CFG_ON_BASE + 0x418)
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_ADDR                    (BGF_GPS_CFG_ON_BASE + 0x41c)
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_ADDR              (BGF_GPS_CFG_ON_BASE + 0x420)
#define BGF_GPS_CFG_ON_GPS_ON_MET_SWCTL_ADDR                   (BGF_GPS_CFG_ON_BASE + 0x424)
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_ADDR              (BGF_GPS_CFG_ON_BASE + 0x428)

#define GPS_CFG_ON_GPS_L1_SLP_PWR_CTL_GPS_L1_SLP_PWR_CTL_CS_ADDR BGF_GPS_CFG_ON_GPS_L1_SLP_PWR_CTL_ADDR
#define GPS_CFG_ON_GPS_L1_SLP_PWR_CTL_GPS_L1_SLP_PWR_CTL_CS_MASK 0x0000000F
#define GPS_CFG_ON_GPS_L1_SLP_PWR_CTL_GPS_L1_SLP_PWR_CTL_CS_SHFT 0

#define GPS_CFG_ON_GPS_L5_SLP_PWR_CTL_GPS_L5_SLP_PWR_CTL_CS_ADDR BGF_GPS_CFG_ON_GPS_L5_SLP_PWR_CTL_ADDR
#define GPS_CFG_ON_GPS_L5_SLP_PWR_CTL_GPS_L5_SLP_PWR_CTL_CS_MASK 0x0000000F
#define GPS_CFG_ON_GPS_L5_SLP_PWR_CTL_GPS_L5_SLP_PWR_CTL_CS_SHFT 0

#define BGF_GPS_CFG_ON_GPS_TOP_OFF_PWR_CTL_GPS_TOP_OFF_PWR_CTL_CS_ADDR BGF_GPS_CFG_ON_GPS_OFF_PWR_CTL_ADDR
#define BGF_GPS_CFG_ON_GPS_TOP_OFF_PWR_CTL_GPS_TOP_OFF_PWR_CTL_CS_MASK 0x0000000F
#define BGF_GPS_CFG_ON_GPS_TOP_OFF_PWR_CTL_GPS_TOP_OFF_PWR_CTL_CS_SHFT 0

#define GPS_CFG_ON_GPS_CLKGEN1_CTL_CR_GPS_DIGCK_DIV_EN_ADDR    BGF_GPS_CFG_ON_GPS_CLKGEN1_CTL_ADDR
#define GPS_CFG_ON_GPS_CLKGEN1_CTL_CR_GPS_DIGCK_DIV_EN_MASK    0x00000010
#define GPS_CFG_ON_GPS_CLKGEN1_CTL_CR_GPS_DIGCK_DIV_EN_SHFT    4

#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_DATA_MASK_ADDR  BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_DATA_MASK_MASK  0xFFFF0000
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_DATA_MASK_SHFT  16
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_OSC_CNT_TARGET_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_OSC_CNT_TARGET_MASK 0x00007F00
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_OSC_CNT_TARGET_SHFT 8
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_EVENT_SEL_ADDR  BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_EVENT_SEL_MASK  0x000000F0
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_EVENT_SEL_SHFT  4
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_IRQ_B_ADDR      BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_IRQ_B_MASK      0x00000008
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_IRQ_B_SHFT      3
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_CLK_EN_ADDR     BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_CLK_EN_MASK     0x00000002
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_CLK_EN_SHFT     1
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_RECORD_EN_ADDR  BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_RECORD_EN_MASK  0x00000001
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL0_GPS_MET_RECORD_EN_SHFT  0
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DBG_CNT_EN_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DBG_CNT_EN_MASK 0x00020000
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DBG_CNT_EN_SHFT 17
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_MCUCK_INFO_MASK_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_MCUCK_INFO_MASK_MASK 0x00010000
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_MCUCK_INFO_MASK_SHFT 16
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DATA_CNT4IRQ_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DATA_CNT4IRQ_MASK 0x0000FF00
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_DATA_CNT4IRQ_SHFT 8
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_FULL_SEL_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_FULL_SEL_MASK 0x00000002
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_FULL_SEL_SHFT 1
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_MODE_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_MODE_MASK 0x00000001
#define BGF_GPS_CFG_ON_GPS_ON_MET_CTL1_GPS_MET_RING_BUF_MODE_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_POSEDGE_DET_EN_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_POSEDGE_DET_EN_MASK 0xFFFF0000
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_POSEDGE_DET_EN_SHFT 16
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_NEGEDGE_DET_EN_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_NEGEDGE_DET_EN_MASK 0x0000FFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_DEGE_DET_GPS_MET_NEGEDGE_DET_EN_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_START_ADDR_GPS_MET_START_ADDR_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_START_ADDR_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_START_ADDR_GPS_MET_START_ADDR_MASK 0xFFFFFFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_START_ADDR_GPS_MET_START_ADDR_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_END_ADDR_GPS_MET_END_ADDR_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_END_ADDR_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_END_ADDR_GPS_MET_END_ADDR_MASK 0xFFFFFFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_END_ADDR_GPS_MET_END_ADDR_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_WRITE_PTR_GPS_MET_WR_PTR_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_WRITE_PTR_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_WRITE_PTR_GPS_MET_WR_PTR_MASK 0xFFFFFFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_WRITE_PTR_GPS_MET_WR_PTR_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_READ_PTR_GPS_MET_RD_PTR_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_READ_PTR_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_READ_PTR_GPS_MET_RD_PTR_MASK 0xFFFFFFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_READ_PTR_GPS_MET_RD_PTR_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_MCUCK_INFO_ERR_FLAG_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_MCUCK_INFO_ERR_FLAG_MASK 0x00000008
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_MCUCK_INFO_ERR_FLAG_SHFT 3
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_AHB_ERR_FLAG_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_AHB_ERR_FLAG_MASK 0x00000004
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_AHB_ERR_FLAG_SHFT 2
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_WRAP_ERR_FLAG_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_WRAP_ERR_FLAG_MASK 0x00000002
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_WRAP_ERR_FLAG_SHFT 1
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_SLEEP_TIMER_OVERFLOW_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_SLEEP_TIMER_OVERFLOW_MASK 0x00000001
#define BGF_GPS_CFG_ON_GPS_ON_MET_FLAG_GPS_MET_SLEEP_TIMER_OVERFLOW_SHFT 0
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_GPS_EVENT_SEL_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_GPS_EVENT_SEL_MASK 0xFF000000
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_GPS_EVENT_SEL_SHFT 24
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_CFG_ON_EVENT_SEL_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_CFG_ON_EVENT_SEL_MASK 0x00030000
#define BGF_GPS_CFG_ON_GPS_ON_MET_EVENT_SEL0_GPS_MET_CFG_ON_EVENT_SEL_SHFT 16
#define BGF_GPS_CFG_ON_GPS_ON_MET_SWCTL_GPS_MET_SWCTL_ADDR     BGF_GPS_CFG_ON_GPS_ON_MET_SWCTL_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_SWCTL_GPS_MET_SWCTL_MASK     0x0000FFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_SWCTL_GPS_MET_SWCTL_SHFT     0
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_TEMP_SIGNAL_SEL_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_TEMP_SIGNAL_SEL_MASK 0xFFFF0000
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_TEMP_SIGNAL_SEL_SHFT 16
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_SIGNAL_SEL_ADDR BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_ADDR
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_SIGNAL_SEL_MASK 0x0000FFFF
#define BGF_GPS_CFG_ON_GPS_ON_MET_SIGNAL_SEL_GPS_MET_SIGNAL_SEL_SHFT 0
#endif /* __BGF_GPS_CFG_ON_REGS_H__ */

