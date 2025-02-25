/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
#ifndef __TEST_MAC_H__
#define __TEST_MAC_H__

#include "net_adaption.h"

/*****************************************************************************
 *	Function declaration
 *****************************************************************************/
s_int32 mt_test_mac_backup_and_set_cr(
	struct test_wlan_info *winfos,
	struct test_bk_cr *bks,
	u_char band_idx);
s_int32 mt_test_mac_restore_cr(
	struct test_wlan_info *winfos,
	struct test_bk_cr *bks,
	u_char band_idx);
s_int32 mt_test_mac_set_ampdu_ba_limit(
	struct test_wlan_info *winfos,
	struct test_configuration *configs,
	u_int8 agg_limit);
s_int32 mt_test_mac_set_sta_pause_cr(
	struct test_wlan_info *winfos);
s_int32 mt_test_mac_set_ifs_cr(
	struct test_wlan_info *winfos,
	struct test_configuration *configs,
	u_char band_idx);

#endif /* __TEST_MAC_H__ */
