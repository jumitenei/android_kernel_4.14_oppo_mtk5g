/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
#include "rt_config.h"
#include "test_mac.h"

s_int32 mt_test_mac_backup_and_set_cr(
	struct test_wlan_info *winfos,
	struct test_bk_cr *bks,
	u_char band_idx)
{
	struct _RTMP_CHIP_OP *ops = hc_get_chip_ops(winfos->hdev_ctrl);
	RTMP_ADAPTER *ad = NULL;

	/* Get adapter from jedi driver first */
	GET_PAD_FROM_NET_DEV(ad, winfos->net_dev);
	if (ad == NULL)
		return SERV_STATUS_HAL_MAC_INVALID_PAD;

	if (ops->backup_reg_before_ate)
		ops->backup_reg_before_ate(ad);
	else
		return SERV_STATUS_HAL_MAC_INVALID_CHIPOPS;

#if 0
#ifndef MT7615
	if (!IS_MT7615(pAd)) {
		/* VHT20 MCS9 Support on LDPC Mode */
		net_ad_backup_cr(winfos, bks,
				WF_WTBLOFF_TOP_LUECR_ADDR, SERV_TEST_MAC_BKCR);
		MAC_IO_READ32(ad->hdev_ctrl, WF_WTBLOFF_TOP_LUECR_ADDR, &val);
		val = 0xFFFFFFFF;
		MAC_IO_WRITE32(ad->hdev_ctrl, WF_WTBLOFF_TOP_LUECR_ADDR, val);
	}
#endif /* !defined(MT7615) */
#endif

	return SERV_STATUS_SUCCESS;
}

s_int32 mt_test_mac_restore_cr(
	struct test_wlan_info *winfos,
	struct test_bk_cr *bks,
	u_char band_idx)
{
	struct _RTMP_CHIP_OP *ops = hc_get_chip_ops(winfos->hdev_ctrl);
	RTMP_ADAPTER *ad = NULL;

	/* Get adapter from jedi driver first */
	GET_PAD_FROM_NET_DEV(ad, winfos->net_dev);
	if (ad == NULL)
		return SERV_STATUS_HAL_MAC_INVALID_PAD;

	if (ops->restore_reg_after_ate)
		ops->restore_reg_after_ate(ad);
	else
		return SERV_STATUS_HAL_MAC_INVALID_CHIPOPS;

#if 0
#ifndef MT7615
	if (!IS_MT7615(pAd)) {
		/* VHT20 MCS9 Support on LDPC Mode backup */
		net_ad_restore_cr(winfos, WF_WTBLOFF_TOP_LUECR_ADDR);
	}
#endif /* defined(MT7663) */
#endif

	return SERV_STATUS_SUCCESS;
}

s_int32 mt_test_mac_set_ampdu_ba_limit(
	struct test_wlan_info *winfos,
	struct test_configuration *configs,
	u_int8 agg_limit)
{
	struct _RTMP_CHIP_OP *ops = hc_get_chip_ops(winfos->hdev_ctrl);
	RTMP_ADAPTER *ad = NULL;

	/* Get adapter from jedi driver first */
	GET_PAD_FROM_NET_DEV(ad, winfos->net_dev);
	if (ad == NULL)
		return SERV_STATUS_HAL_MAC_INVALID_PAD;

	if (ops->set_ba_limit)
		ops->set_ba_limit(ad, configs->wmm_idx, agg_limit);
	else
		return SERV_STATUS_HAL_MAC_INVALID_CHIPOPS;

	return SERV_STATUS_SUCCESS;
}

s_int32 mt_test_mac_set_sta_pause_cr(
	struct test_wlan_info *winfos)
{
	RTMP_ADAPTER *ad = NULL;
	struct _RTMP_CHIP_OP *ops = hc_get_chip_ops(winfos->hdev_ctrl);

	/* Get adapter from jedi driver first */
	GET_PAD_FROM_NET_DEV(ad, winfos->net_dev);
	if (ad == NULL)
		return SERV_STATUS_HAL_MAC_INVALID_PAD;

	if (ops->pause_ac_queue)
		ops->pause_ac_queue(ad, 0xf);
	else
		return SERV_STATUS_HAL_MAC_INVALID_CHIPOPS;

	return SERV_STATUS_SUCCESS;
}

s_int32 mt_test_mac_set_ifs_cr(
	struct test_wlan_info *winfos,
	struct test_configuration *configs,
	u_char band_idx)
{
	RTMP_ADAPTER *ad = NULL;
	struct _RTMP_CHIP_OP *ops = hc_get_chip_ops(winfos->hdev_ctrl);

	/* Get adapter from jedi driver first */
	GET_PAD_FROM_NET_DEV(ad, winfos->net_dev);
	if (ad == NULL)
		return SERV_STATUS_HAL_MAC_INVALID_PAD;

	if (ops->set_ifs)
		ops->set_ifs(ad, band_idx);
	else
		return SERV_STATUS_HAL_MAC_INVALID_CHIPOPS;

	return SERV_STATUS_SUCCESS;
}
