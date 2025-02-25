/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#ifndef __BGF_GPS_CFG_REGS_H__
#define __BGF_GPS_CFG_REGS_H__

#define BGF_GPS_CFG_BASE                                       0x80021000

#define BGF_GPS_CFG_IP_VERSION_ADDR                           (BGF_GPS_CFG_BASE + 0x0010)
#define BGF_GPS_CFG_CFG_VERSION_ADDR                          (BGF_GPS_CFG_BASE + 0x0014)


#define BGF_GPS_CFG_BGF_IP_VERSION_BGFSYS_VERSION_ADDR         BGF_GPS_CFG_IP_VERSION_ADDR
#define BGF_GPS_CFG_BGF_IP_VERSION_BGFSYS_VERSION_MASK         0xFFFFFFFF
#define BGF_GPS_CFG_BGF_IP_VERSION_BGFSYS_VERSION_SHFT         0

#define BGF_GPS_CFG_BGF_IP_CONFIG_BGFSYS_CONFIG_ADDR           BGF_GPS_CFG_CFG_VERSION_ADDR
#define BGF_GPS_CFG_BGF_IP_CONFIG_BGFSYS_CONFIG_MASK           0x000000FF
#define BGF_GPS_CFG_BGF_IP_CONFIG_BGFSYS_CONFIG_SHFT           0

#endif /* __BGF_GPS_CFG_REGS_H__ */

