/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#ifndef __CONN_UART_PTA_REGS_H__
#define __CONN_UART_PTA_REGS_H__

#define CONN_UART_PTA_BASE                                     0x1800D000

#define CONN_UART_PTA_FCR_ADDR                                 (CONN_UART_PTA_BASE + 0x08)
#define CONN_UART_PTA_LCR_ADDR                                 (CONN_UART_PTA_BASE + 0x0C)
#define CONN_UART_PTA_DLL_ADDR                                 (CONN_UART_PTA_BASE + 0x00)
#define CONN_UART_PTA_DLM_ADDR                                 (CONN_UART_PTA_BASE + 0x04)
#define CONN_UART_PTA_HIGHSPEED_ADDR                           (CONN_UART_PTA_BASE + 0x24)
#define CONN_UART_PTA_SAMPLE_COUNT_ADDR                        (CONN_UART_PTA_BASE + 0x28)
#define CONN_UART_PTA_SAMPLE_POINT_ADDR                        (CONN_UART_PTA_BASE + 0x2c)
#define CONN_UART_PTA_VFIFO_EN_ADDR                            (CONN_UART_PTA_BASE + 0x4c)
#define CONN_UART_PTA_FRACDIV_L_ADDR                           (CONN_UART_PTA_BASE + 0x54)
#define CONN_UART_PTA_FRACDIV_M_ADDR                           (CONN_UART_PTA_BASE + 0x58)

#define CONN_UART_PTA_SAMPLE_COUNT_SAMPLE_COUNT_ADDR           CONN_UART_PTA_SAMPLE_COUNT_ADDR
#define CONN_UART_PTA_SAMPLE_COUNT_SAMPLE_COUNT_MASK           0x000000FF
#define CONN_UART_PTA_SAMPLE_COUNT_SAMPLE_COUNT_SHFT           0

#define CONN_UART_PTA_SAMPLE_POINT_SAMPLE_POINT_ADDR           CONN_UART_PTA_SAMPLE_POINT_ADDR
#define CONN_UART_PTA_SAMPLE_POINT_SAMPLE_POINT_MASK           0x000000FF
#define CONN_UART_PTA_SAMPLE_POINT_SAMPLE_POINT_SHFT           0

#define CONN_UART_PTA_HIGHSPEED_SPEED_ADDR                     CONN_UART_PTA_HIGHSPEED_ADDR
#define CONN_UART_PTA_HIGHSPEED_SPEED_MASK                     0x00000003
#define CONN_UART_PTA_HIGHSPEED_SPEED_SHFT                     0

#define CONN_UART_PTA_VFIFO_EN_RX_TIME_EN_ADDR                 CONN_UART_PTA_VFIFO_EN_ADDR
#define CONN_UART_PTA_VFIFO_EN_RX_TIME_EN_MASK                 0x00000080
#define CONN_UART_PTA_VFIFO_EN_RX_TIME_EN_SHFT                 7
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_FE_EN_ADDR               CONN_UART_PTA_VFIFO_EN_ADDR
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_FE_EN_MASK               0x00000008
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_FE_EN_SHFT               3
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_MODE_ADDR                CONN_UART_PTA_VFIFO_EN_ADDR
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_MODE_MASK                0x00000004
#define CONN_UART_PTA_VFIFO_EN_PTA_RX_MODE_SHFT                2

#define CONN_UART_PTA_FRACDIV_L_FRACDIV_L_ADDR                 CONN_UART_PTA_FRACDIV_L_ADDR
#define CONN_UART_PTA_FRACDIV_L_FRACDIV_L_MASK                 0x000000FF
#define CONN_UART_PTA_FRACDIV_L_FRACDIV_L_SHFT                 0

#define CONN_UART_PTA_FRACDIV_M_FRACDIV_M_ADDR                 CONN_UART_PTA_FRACDIV_M_ADDR
#define CONN_UART_PTA_FRACDIV_M_FRACDIV_M_MASK                 0x00000003
#define CONN_UART_PTA_FRACDIV_M_FRACDIV_M_SHFT                 0

#endif /* __CONN_UART_PTA_REGS_H__ */

