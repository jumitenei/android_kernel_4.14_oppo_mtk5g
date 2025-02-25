/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#ifndef __CONN_HOST_CSR_TOP_REGS_H__
#define __CONN_HOST_CSR_TOP_REGS_H__

#define CONN_HOST_CSR_TOP_BASE                                 0x18060000

#define CONN_HOST_CSR_TOP_HOST2GPS_DEGUG_SEL_ADDR              (CONN_HOST_CSR_TOP_BASE + 0x00B0)
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_AO_DEBUGSYS_ADDR    (CONN_HOST_CSR_TOP_BASE + 0x0128)
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_ADDR (CONN_HOST_CSR_TOP_BASE + 0x0148)
#define CONN_HOST_CSR_TOP_CONN_SLP_PROT_CTRL_ADDR              (CONN_HOST_CSR_TOP_BASE + 0x0184)
#define CONN_HOST_CSR_TOP_CONN_INFRA_WAKEPU_GPS_ADDR           (CONN_HOST_CSR_TOP_BASE + 0x01AC)
#define CONN_HOST_CSR_TOP_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_ADDR (CONN_HOST_CSR_TOP_BASE + 0x01D0)
#define CONN_HOST_CSR_TOP_GPS_CFG2HOST_DEBUG_ADDR              (CONN_HOST_CSR_TOP_BASE + 0x0240)


#define CONN_HOST_CSR_TOP_HOST2GPS_DEGUG_SEL_HOST2GPS_DEGUG_SEL_ADDR CONN_HOST_CSR_TOP_HOST2GPS_DEGUG_SEL_ADDR
#define CONN_HOST_CSR_TOP_HOST2GPS_DEGUG_SEL_HOST2GPS_DEGUG_SEL_MASK 0x000000FF
#define CONN_HOST_CSR_TOP_HOST2GPS_DEGUG_SEL_HOST2GPS_DEGUG_SEL_SHFT 0

#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_AO_DEBUGSYS_CONN_INFRA_DEBUG_CTRL_AO_DEBUGSYS_CTRL_ADDR \
	CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_AO_DEBUGSYS_ADDR
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_AO_DEBUGSYS_CONN_INFRA_DEBUG_CTRL_AO_DEBUGSYS_CTRL_MASK 0xFFFFFFFF
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_AO_DEBUGSYS_CONN_INFRA_DEBUG_CTRL_AO_DEBUGSYS_CTRL_SHFT 0

#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_ADDR \
	CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_ADDR
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_MASK 0xFFFFFFFF
#define CONN_HOST_CSR_TOP_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_CONN_INFRA_DEBUG_CTRL_AO2SYS_OUT_SHFT 0

#define CONN_HOST_CSR_TOP_CONN_SLP_PROT_CTRL_CONN_INFRA_ON2OFF_SLP_PROT_ACK_ADDR \
	CONN_HOST_CSR_TOP_CONN_SLP_PROT_CTRL_ADDR
#define CONN_HOST_CSR_TOP_CONN_SLP_PROT_CTRL_CONN_INFRA_ON2OFF_SLP_PROT_ACK_MASK 0x00000020
#define CONN_HOST_CSR_TOP_CONN_SLP_PROT_CTRL_CONN_INFRA_ON2OFF_SLP_PROT_ACK_SHFT 5

#define CONN_HOST_CSR_TOP_CONN_INFRA_WAKEPU_GPS_CONN_INFRA_WAKEPU_GPS_ADDR CONN_HOST_CSR_TOP_CONN_INFRA_WAKEPU_GPS_ADDR
#define CONN_HOST_CSR_TOP_CONN_INFRA_WAKEPU_GPS_CONN_INFRA_WAKEPU_GPS_MASK 0x00000001
#define CONN_HOST_CSR_TOP_CONN_INFRA_WAKEPU_GPS_CONN_INFRA_WAKEPU_GPS_SHFT 0

#define CONN_HOST_CSR_TOP_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_ADDR \
	CONN_HOST_CSR_TOP_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_ADDR
#define CONN_HOST_CSR_TOP_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_MASK 0x000FFFFF
#define CONN_HOST_CSR_TOP_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_CONN2AP_REMAP_GPS_EMI_BASE_ADDR_SHFT 0

#define CONN_HOST_CSR_TOP_GPS_CFG2HOST_DEBUG_GPS_CFG2HOST_DEBUG_ADDR CONN_HOST_CSR_TOP_GPS_CFG2HOST_DEBUG_ADDR
#define CONN_HOST_CSR_TOP_GPS_CFG2HOST_DEBUG_GPS_CFG2HOST_DEBUG_MASK 0x0000FFFF
#define CONN_HOST_CSR_TOP_GPS_CFG2HOST_DEBUG_GPS_CFG2HOST_DEBUG_SHFT 0

#endif /* __CONN_HOST_CSR_TOP_REGS_H__ */

