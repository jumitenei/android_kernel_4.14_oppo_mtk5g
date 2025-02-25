/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#ifndef __BGF_GPS_RGU_ON_REGS_H__
#define __BGF_GPS_RGU_ON_REGS_H__

#define BGF_GPS_RGU_ON_BASE                                    0x80000000

#define BGF_GPS_RGU_ON_GPS_L1_CR_ADDR                          (BGF_GPS_RGU_ON_BASE + 0x0014)
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0048)
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x004C)
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0050)
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0054)
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0058)
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x005C)
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_PDN_EN_ADDR            (BGF_GPS_RGU_ON_BASE + 0x0190)
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_SLP_EN_ADDR            (BGF_GPS_RGU_ON_BASE + 0x0194)
#define BGF_GPS_RGU_ON_GPS_L5_CR_ADDR                          (BGF_GPS_RGU_ON_BASE + 0x0214)
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0248)
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x024C)
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0250)
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0254)
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_PDN_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x0258)
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_SLP_EN_ADDR              (BGF_GPS_RGU_ON_BASE + 0x025C)
#define BGF_GPS_RGU_ON_GPS_L5_DLY_CHAIN_CTL_ADDR               (BGF_GPS_RGU_ON_BASE + 0x0360)


#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_SOFT_RST_B_ADDR    BGF_GPS_RGU_ON_GPS_L1_CR_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_SOFT_RST_B_MASK    0x00000020
#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_SOFT_RST_B_SHFT    5
#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_ON_ADDR            BGF_GPS_RGU_ON_GPS_L1_CR_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_ON_MASK            0x00000001
#define BGF_GPS_RGU_ON_GPS_L1_CR_RGU_GPS_L1_ON_SHFT            0

#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_PDN_EN_RGU_GPS_L1_PRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_PDN_EN_RGU_GPS_L1_PRAM_HWCTL_PDN_MASK 0x00003FFF
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_PDN_EN_RGU_GPS_L1_PRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_SLP_EN_RGU_GPS_L1_PRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_SLP_EN_RGU_GPS_L1_PRAM_HWCTL_SLP_MASK 0x00003FFF
#define BGF_GPS_RGU_ON_GPS_L1_DSPPRAM_SLP_EN_RGU_GPS_L1_PRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_PDN_EN_RGU_GPS_L1_XRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_PDN_EN_RGU_GPS_L1_XRAM_HWCTL_PDN_MASK 0x0000000F
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_PDN_EN_RGU_GPS_L1_XRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_SLP_EN_RGU_GPS_L1_XRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_SLP_EN_RGU_GPS_L1_XRAM_HWCTL_SLP_MASK 0x0000000F
#define BGF_GPS_RGU_ON_GPS_L1_DSPXRAM_SLP_EN_RGU_GPS_L1_XRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_MASK 0xFFFFFFFF
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_MASK 0xFFFFFFFF
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_M_ADDR \
	BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_M_MASK 0x0000001F
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_PDN_EN_RGU_GPS_L1_YRAM_HWCTL_PDN_M_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_M_ADDR \
	BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_M_MASK 0x0000001F
#define BGF_GPS_RGU_ON_GPS_L1_DSPYRAM_2_SLP_EN_RGU_GPS_L1_YRAM_HWCTL_SLP_M_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_SOFT_RST_B_ADDR    BGF_GPS_RGU_ON_GPS_L5_CR_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_SOFT_RST_B_MASK    0x00000020
#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_SOFT_RST_B_SHFT    5
#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_ON_ADDR            BGF_GPS_RGU_ON_GPS_L5_CR_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_ON_MASK            0x00000001
#define BGF_GPS_RGU_ON_GPS_L5_CR_RGU_GPS_L5_ON_SHFT            0

#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_PDN_EN_RGU_GPS_L5_PRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_PDN_EN_RGU_GPS_L5_PRAM_HWCTL_PDN_MASK 0x000003FF
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_PDN_EN_RGU_GPS_L5_PRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_SLP_EN_RGU_GPS_L5_PRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_SLP_EN_RGU_GPS_L5_PRAM_HWCTL_SLP_MASK 0x000003FF
#define BGF_GPS_RGU_ON_GPS_L5_DSPPRAM_SLP_EN_RGU_GPS_L5_PRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_PDN_EN_RGU_GPS_L5_XRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_PDN_EN_RGU_GPS_L5_XRAM_HWCTL_PDN_MASK 0x0000000F
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_PDN_EN_RGU_GPS_L5_XRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_SLP_EN_RGU_GPS_L5_XRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_SLP_EN_RGU_GPS_L5_XRAM_HWCTL_SLP_MASK 0x0000000F
#define BGF_GPS_RGU_ON_GPS_L5_DSPXRAM_SLP_EN_RGU_GPS_L5_XRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_PDN_EN_RGU_GPS_L5_YRAM_HWCTL_PDN_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_PDN_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_PDN_EN_RGU_GPS_L5_YRAM_HWCTL_PDN_MASK 0x000003FF
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_PDN_EN_RGU_GPS_L5_YRAM_HWCTL_PDN_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_SLP_EN_RGU_GPS_L5_YRAM_HWCTL_SLP_ADDR BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_SLP_EN_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_SLP_EN_RGU_GPS_L5_YRAM_HWCTL_SLP_MASK 0x000003FF
#define BGF_GPS_RGU_ON_GPS_L5_DSPYRAM_SLP_EN_RGU_GPS_L5_YRAM_HWCTL_SLP_SHFT 0

#define BGF_GPS_RGU_ON_GPS_L5_DLY_CHAIN_CTL_RGU_GPS_L5_MEM_PDN_DELAY_DUMMY_NUM_ADDR \
	BGF_GPS_RGU_ON_GPS_L5_DLY_CHAIN_CTL_ADDR
#define BGF_GPS_RGU_ON_GPS_L5_DLY_CHAIN_CTL_RGU_GPS_L5_MEM_PDN_DELAY_DUMMY_NUM_MASK 0x000F0000
#define BGF_GPS_RGU_ON_GPS_L5_DLY_CHAIN_CTL_RGU_GPS_L5_MEM_PDN_DELAY_DUMMY_NUM_SHFT 16

#endif /* __BGF_GPS_RGU_ON_REGS_H__ */

