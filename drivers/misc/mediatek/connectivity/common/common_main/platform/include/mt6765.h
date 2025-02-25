/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

/*! \file
 * \brief  Declaration of library functions
 *
 * Any definitions in this file will be shared among GLUE Layer and internal Driver Stack.
*/

#ifndef _MTK_MT6765_H_
#define _MTK_MT6765_H_

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

#define CONSYS_BT_WIFI_SHARE_V33	0
#define CONSYS_PMIC_CTRL_ENABLE		1
#define CONSYS_AHB_CLK_MAGEMENT		1
#define CONSYS_USE_PLATFORM_WRITE	1
#define CONSYS_PWR_ON_OFF_API_AVAILABLE	1
#define CONSYS_AFE_REG_SETTING		0

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/

/*tag start:new platform need to make sure these define */
#define PLATFORM_SOC_CHIP 0x6765
/*tag end*/

/*device tree mode*/
/* A-Die interface pinmux base */
#define CONSYS_IF_PINMUX_REG_BASE	0x10005000
#define CONSYS_IF_PINMUX_01_OFFSET	0x000003F0
#define CONSYS_IF_PINMUX_01_MASK	0xFFFFFF88
#define CONSYS_IF_PINMUX_01_VALUE	0x00000011
#define CONSYS_IF_PINMUX_02_OFFSET	0x000003E0
#define CONSYS_IF_PINMUX_02_MASK	0x8888888F
#define CONSYS_IF_PINMUX_02_VALUE	0x11111110

/* A-Die interface pinmux driving base */
#define CONSYS_IF_PINMUX_DRIVING_BASE	0x10002C00
#define CONSYS_IF_PINMUX_DRIVING_OFFSET_1	0x0
#define CONSYS_IF_PINMUX_DRIVING_MASK_1		0xc703ffff
#define CONSYS_IF_PINMUX_DRIVING_VALUE_1	0x8240000
#define CONSYS_IF_PINMUX_DRIVING_OFFSET_2	0x10
#define CONSYS_IF_PINMUX_DRIVING_MASK_2		0xfffffff8
#define CONSYS_IF_PINMUX_DRIVING_VALUE_2	0x1

/*TOPCKGEN_BASE*/
#define CONSYS_AP2CONN_OSC_EN_OFFSET	0x00000f00
#define CONSYS_EMI_MAPPING_OFFSET	0x00000380
#define CONSYS_EMI_PERI_MAPPING_OFFSET	0x00000388
/*AP_RGU_BASE*/
#define CONSYS_CPU_SW_RST_OFFSET	0x00000018
/*SPM_BASE*/
#define CONSYS_PWRON_CONFG_EN_OFFSET	0x00000000
#define CONSYS_TOP1_PWR_CTRL_OFFSET	0x0000032C
#define CONSYS_PWR_CONN_ACK_OFFSET	0x00000180
#define CONSYS_PWR_CONN_ACK_S_OFFSET	0x00000184
#define CONSYS_SPM_APSRC_OFFSET		0x000006f8
#define CONSYS_SPM_APSRC_VALUE		0x00000005
#define CONSYS_SPM_DDR_EN_OFFSET	0x000006fc
#define CONSYS_SPM_DDR_EN_VALUE		0x00050505
/*CONN_MCU_CONFIG_BASE*/
#define CONSYS_IP_VER_OFFSET		0x00000010
#define CONSYS_CONF_ID_OFFSET		0x0000001c
#define CONSYS_HW_ID_OFFSET		0x00000000
#define CONSYS_FW_ID_OFFSET		0x00000004
#define CONSYS_MCU_CFG_ACR_OFFSET	0x00000140
#define CONSYS_CPUPCR_OFFSET		0x00000104
#define CONSYS_SW_IRQ_OFFSET		0x00000150
#define CONSYS_MCU_ROM_DELSEL_OFFSET    0x00000114
#define CONSYS_MCU_ROM_DELSEL_VALUE     0x00000017
#define CONSYS_EMI_CTRL_VALUE           (1 << 0 | 1 << 15 | 1 << 21)
/*CONN_HIF_TOP*/
#define CONSYS_HIF_PDMA_AXI_RREADY      0x00000154

/*CONN_HIF_ON_BASE*/
#define CONN_HIF_ON_BASE_ADDR           (0x18007000)
#define CONSYS_BUSY_OFFSET              0x110
#define CONSYS_BUSY_BIT                 (0x1 << 27)
#define CONSYS_CLOCK_CHECK_VALUE        0x30000
#define CONSYS_HCLK_CHECK_BIT           (0x1 << 16)
#define CONSYS_OSCCLK_CHECK_BIT         (0x1 << 17)
#define CONSYS_SLEEP_CHECK_BIT          (0x1 << 18)

/*AXI bus*/
#define CONSYS_AHBAXI_PROT_EN_OFFSET	0x220
#define CONSYS_AHBAXI_PROT_STA0_OFFSET	0x224
#define CONSYS_AHBAXI_PROT_STA1_OFFSET	0x228
#define CONSYS_AXI_TX_PROT_EN_OFFSET	0x250
#define CONSYS_AXI_TX_PROT_STA_OFFSET	0x258
#define CONSYS_PROT_MASK		((0x1<<13) | (0x1<<14))	/* bit 13, 14 */
#define CONSYS_TX_PROT_MASK		(0x1<<18)	/* bit 18 */
#define CONSYS_PDMA_AXI_RREADY_MASK	(0x1 << 1)	/* bit 1 */

/* INFRACFG_REG_BASE */
#define INFRAGCFG_REG_TOPAXI_SI3_STA_OFFSET	0x02C
#define INFRAGCFG_REG_TOPAXI_MI_STA_OFFSET	0x008

/*SPM clock gating control register */
#define CONSYS_PWRON_CONFG_EN_VALUE	(0x0b160001)
#define CONSYS_PWRON_CONFG_DIS_VALUE	(0x0b160000)

#if CONSYS_AFE_REG_SETTING
#define CONSYS_AFE_REG_BASE			(0x180B6000)
#define CONSYS_AFE_RG_WBG_PLL_03_OFFSET		(0x00000038)
#define CONSYS_AFE_RG_WBG_PLL_03_VALUE		(0x000C1DF0)
#define CONSYS_AFE_RG_WBG_GPS_02_OFFSET		(0x00000054)
#define CONSYS_AFE_RG_WBG_GPS_02_VALUE		(0x110A2000)
#endif

#define CONSYS_COCLOCK_STABLE_TIME_BASE		(0x180C1200)
#define CONSYS_COCLOCK_ACK_ENABLE_OFFSET	(0x4)
#define CONSYS_COCLOCK_ACK_ENABLE_BIT		(1 << 0)
#define CONSYS_COCLOCK_STABLE_TIME		(0x2223)
#define CONSYS_COCLOCK_STABLE_TIME_MASK		(0xffff0000)

/*CONSYS_CPU_SW_RST_REG*/
#define CONSYS_CPU_SW_RST_BIT		(0x1 << 12)
#define CONSYS_CPU_SW_RST_CTRL_KEY	(0x88 << 24)
#define CONSYS_SW_RST_BIT		(0x1 << 9)

/*CONSYS_TOP1_PWR_CTRL_REG*/
#define CONSYS_SPM_PWR_RST_BIT		(0x1 << 0)
#define CONSYS_SPM_PWR_ISO_S_BIT	(0x1 << 1)
#define CONSYS_SPM_PWR_ON_BIT		(0x1 << 2)
#define CONSYS_SPM_PWR_ON_S_BIT		(0x1 << 3)
#define CONSYS_CLK_CTRL_BIT		(0x1 << 4)
#define CONSYS_SRAM_CONN_PD_BIT		(0x1 << 8)

/*CONSYS_PWR_CONN_ACK_REG*/
#define CONSYS_PWR_ON_ACK_BIT		(0x1 << 1)

/*CONSYS_PWR_CONN_ACK_S_REG*/
#define CONSYS_PWR_ON_ACK_S_BIT		(0x1 << 1)

/*CONSYS_PWR_CONN_TOP2_ACK_REG*/
#define CONSYS_TOP2_PWR_ON_ACK_BIT	(0x1 << 30)

/*CONSYS_PWR_CONN_TOP2_ACK_S_REG*/
#define CONSYS_TOP2_PWR_ON_ACK_S_BIT	(0x1 << 30)

/*CONSYS_WD_SYS_RST_REG*/
#define CONSYS_WD_SYS_RST_CTRL_KEY	(0x88 << 24)
#define CONSYS_WD_SYS_RST_BIT		(0x1 << 9)

/*CONSYS_MCU_CFG_ACR_REG*/
#define CONSYS_MCU_CFG_ACR_MBIST_OFFSET	(0x10)
#define CONSYS_MCU_CFG_ACR_MBIST_MASK	(0xfffffffc)
#define CONSYS_MCU_CFG_ACR_MBIST_VAL	(0x3)

/*control app2cnn_osc_en*/
#define CONSYS_AP2CONN_OSC_EN_BIT	(0x1 << 10)
#define CONSYS_AP2CONN_WAKEUP_BIT	(0x1 << 9)

/* EMI part mapping & ctrl*/
#define CONSYS_EMI_COREDUMP_OFFSET	(0x68000)
#define CONSYS_EMI_AP_PHY_BASE		(0x80068000)
#define CONSYS_EMI_FW_PHY_BASE		(0xf0068000)
#define CONSYS_EMI_PAGED_TRACE_OFFSET	(0x400)
#define CONSYS_EMI_PAGED_DUMP_OFFSET	(0x8400)
#define CONSYS_EMI_FULL_DUMP_OFFSET	(0x10400)
#define CONSYS_EMI_MET_DATA_OFFSET	(0x2e500)

#define CONSYS_EMI_RAM_BT_BUILDTIME_OFFSET	(0x68300)
#define CONSYS_EMI_RAM_WIFI_BUILDTIME_OFFSET	(0x68310)
#define CONSYS_EMI_RAM_MCU_BUILDTIME_OFFSET	(0x68320)
#define CONSYS_EMI_PATCH_MCU_BUILDTIME_OFFSET	(0x68330)

/*CONSYS_MCU_CFG_DBG_LP_INFO*/
#define CONN_CFG_ON_CONN_ON_HOST_MAILBOX_MCU_ADDR           (conn_reg.mcu_cfg_on_base + 0x104)
#define CONN_CFG_ON_CONN_ON_MON_CTL_ADDR                    (conn_reg.mcu_top_misc_on_base + 0x320)
#define CONN_CFG_ON_CONN_ON_DBGSEL_ADDR                     (conn_reg.mcu_top_misc_on_base + 0x310)
#define CONN_CFG_ON_CONN_ON_MON_FLAG_RECORD_ADDR            (conn_reg.mcu_top_misc_on_base + 0x340)
#define CONN_CFG_ON_CONN_ON_MON_FLAG_RECORD_MAPPING_AP_ADDR (0x180c1340)

/* default coex wmt ant_sel cr address */
#define DEFAULT_COEX_WMT_ANTSEL_0_POLARITY_CR 0x80025310
#define DEFAULT_COEX_WMT_ANTSEL_1_POLARITY_CR 0x80025310
#define DEFAULT_COEX_WMT_ANTSEL_2_POLARITY_CR 0x80025314
#define DEFAULT_COEX_WMT_ANTSEL_3_POLARITY_CR 0x80025314
#define DEFAULT_COEX_WMT_ANTSEL_4_POLARITY_CR 0x80025318
#define DEFAULT_COEX_WMT_ANTSEL_5_POLARITY_CR 0x80025318
#define DEFAULT_COEX_WMT_ANTSEL_6_POLARITY_CR 0x8002531C
#define DEFAULT_COEX_WMT_ANTSEL_7_POLARITY_CR 0x8002531C

/* default coex wmt ant_sel cr bit */
#define DEFAULT_COEX_WMT_ANTSEL_0_POLARITY_BIT 8
#define DEFAULT_COEX_WMT_ANTSEL_1_POLARITY_BIT 24
#define DEFAULT_COEX_WMT_ANTSEL_2_POLARITY_BIT 8
#define DEFAULT_COEX_WMT_ANTSEL_3_POLARITY_BIT 24
#define DEFAULT_COEX_WMT_ANTSEL_4_POLARITY_BIT 8
#define DEFAULT_COEX_WMT_ANTSEL_5_POLARITY_BIT 24
#define DEFAULT_COEX_WMT_ANTSEL_6_POLARITY_BIT 8
#define DEFAULT_COEX_WMT_ANTSEL_7_POLARITY_BIT 24

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

#ifdef CONSYS_BT_WIFI_SHARE_V33
struct bt_wifi_v33_status {
	UINT32 counter;
	UINT32 flags;
	spinlock_t lock;
};

extern struct bt_wifi_v33_status gBtWifiV33;
#endif

/*******************************************************************************
*                            P U B L I C   D A T A
*******************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
extern INT32 dump_conn_debug_dump_mt6765(const char *trg_str);
extern INT32 dump_conn_mcu_debug_flag_mt6765(const char *trg_str);
extern INT32 dump_conn_mcu_apb0_bus_mt6765(const char *trg_str);
extern INT32 dump_conn_mcu_apb1_bus_mt6765(const char *trg_str);
extern INT32 dump_conn_bus_timeout_mt6765(const char *trg_str);
extern INT32 dump_conn_mcu_pc_log_mt6765(const char *trg_str);
extern INT32 dump_conn_cfg_on_debug_signal_mt6765(const char *trg_str);
extern INT32 dump_conn_cfg_on_register_mt6765(const char *trg_str);
extern INT32 dump_conn_cmdbt_debug_signal_mt6765(const char *trg_str);
extern INT32 dump_conn_emi_detect_mt6765(const char *trg_str);
extern INT32 dump_conn_slp_protect_debug_mt6765(const char *trg_str);
extern INT32 dump_conn_spm_r13_mt6765(const char *trg_str);
extern INT32 dump_conn_bus_timeout_debug_mt6765(const char *trg_str);
extern INT32 dump_conn_ILM_corrupt_issue_debug_mt6765(const char *trg_str);

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _MTK_MT6765_H_ */
