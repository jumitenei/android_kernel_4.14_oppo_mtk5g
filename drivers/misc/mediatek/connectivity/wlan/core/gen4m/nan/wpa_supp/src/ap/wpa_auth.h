/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */

/*
 * Copyright (c) 2020 MediaTek Inc.
 */
/*
 * hostapd - IEEE 802.11i-2004 / WPA Authenticator
 * Copyright (c) 2004-2015, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef WPA_AUTH_H
#define WPA_AUTH_H

#include "wpa_supp/src/common/defs.h"
/*#include "../common/eapol_common.h"*/
#include "wpa_supp/src/common/wpa_common.h"
/*#include "../common/ieee802_11_defs.h"*/

#define MAX_OWN_IE_OVERRIDE 256

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif /* _MSC_VER */

/* IEEE Std 802.11r-2008, 11A.10.3 - Remote request/response frame definition
 */
struct ft_rrb_frame {
	u8 frame_type;      /* RSN_REMOTE_FRAME_TYPE_FT_RRB */
	u8 packet_type;     /* FT_PACKET_REQUEST/FT_PACKET_RESPONSE */
	le16 action_length; /* little endian length of action_frame */
	u8 ap_address[ETH_ALEN];
	/*
	 * Followed by action_length bytes of FT Action frame (from Category
	 * field to the end of Action Frame body.
	 */
} STRUCT_PACKED;

#define RSN_REMOTE_FRAME_TYPE_FT_RRB 1

#define FT_PACKET_REQUEST 0
#define FT_PACKET_RESPONSE 1
/* Vendor-specific types for R0KH-R1KH protocol; not defined in 802.11r */
#define FT_PACKET_R0KH_R1KH_PULL 200
#define FT_PACKET_R0KH_R1KH_RESP 201
#define FT_PACKET_R0KH_R1KH_PUSH 202

#define FT_R0KH_R1KH_PULL_DATA_LEN 44
#define FT_R0KH_R1KH_RESP_DATA_LEN 76
#define FT_R0KH_R1KH_PUSH_DATA_LEN 88
#define FT_R0KH_R1KH_PULL_NONCE_LEN 16

struct ft_r0kh_r1kh_pull_frame {
	u8 frame_type;    /* RSN_REMOTE_FRAME_TYPE_FT_RRB */
	u8 packet_type;   /* FT_PACKET_R0KH_R1KH_PULL */
	le16 data_length; /* little endian length of data (44) */
	u8 ap_address[ETH_ALEN];

	u8 nonce[FT_R0KH_R1KH_PULL_NONCE_LEN];
	u8 pmk_r0_name[WPA_PMK_NAME_LEN];
	u8 r1kh_id[FT_R1KH_ID_LEN];
	u8 s1kh_id[ETH_ALEN];
	u8 pad[4]; /* 8-octet boundary for AES key wrap */
	u8 key_wrap_extra[8];
} STRUCT_PACKED;

struct ft_r0kh_r1kh_resp_frame {
	u8 frame_type;    /* RSN_REMOTE_FRAME_TYPE_FT_RRB */
	u8 packet_type;   /* FT_PACKET_R0KH_R1KH_RESP */
	le16 data_length; /* little endian length of data (76) */
	u8 ap_address[ETH_ALEN];

	u8 nonce[FT_R0KH_R1KH_PULL_NONCE_LEN]; /* copied from pull */
	u8 r1kh_id[FT_R1KH_ID_LEN];	    /* copied from pull */
	u8 s1kh_id[ETH_ALEN];		       /* copied from pull */
	u8 pmk_r1[PMK_LEN];
	u8 pmk_r1_name[WPA_PMK_NAME_LEN];
	le16 pairwise;
	u8 pad[2]; /* 8-octet boundary for AES key wrap */
	u8 key_wrap_extra[8];
} STRUCT_PACKED;

struct ft_r0kh_r1kh_push_frame {
	u8 frame_type;    /* RSN_REMOTE_FRAME_TYPE_FT_RRB */
	u8 packet_type;   /* FT_PACKET_R0KH_R1KH_PUSH */
	le16 data_length; /* little endian length of data (88) */
	u8 ap_address[ETH_ALEN];

	/* Encrypted with AES key-wrap */
	u8 timestamp[4];
	/* current time in seconds since unix epoch, little endian */
	u8 r1kh_id[FT_R1KH_ID_LEN];
	u8 s1kh_id[ETH_ALEN];
	u8 pmk_r0_name[WPA_PMK_NAME_LEN];
	u8 pmk_r1[PMK_LEN];
	u8 pmk_r1_name[WPA_PMK_NAME_LEN];
	le16 pairwise;
	u8 pad[6]; /* 8-octet boundary for AES key wrap */
	u8 key_wrap_extra[8];
} STRUCT_PACKED;

#ifdef _MSC_VER
#pragma pack(pop)
#endif /* _MSC_VER */

/* per STA state machine data */

struct wpa_authenticator;
struct wpa_state_machine;
struct rsn_pmksa_cache_entry;
struct eapol_state_machine;

struct ft_remote_r0kh {
	struct ft_remote_r0kh *next;
	u8 addr[ETH_ALEN];
	u8 id[FT_R0KH_ID_MAX_LEN];
	size_t id_len;
	u8 key[16];
};

struct ft_remote_r1kh {
	struct ft_remote_r1kh *next;
	u8 addr[ETH_ALEN];
	u8 id[FT_R1KH_ID_LEN];
	u8 key[16];
};

struct wpa_auth_config {
	int wpa;
	int wpa_key_mgmt;
	int wpa_pairwise;
	int wpa_group;
	int wpa_group_rekey;
	int wpa_strict_rekey;
	int wpa_gmk_rekey;
	int wpa_ptk_rekey;
	int rsn_pairwise;
	int eapol_version;
	int tx_status;
#ifdef CONFIG_IEEE80211W
	enum mfp_options ieee80211w;
	int group_mgmt_cipher;
#endif /* CONFIG_IEEE80211W */
	int disable_gtk;
	int ap_mlme;
};

enum { LOGGER_DEBUG, LOGGER_INFO, LOGGER_WARNING };

enum { WPA_EAPOL_portEnabled,
	WPA_EAPOL_portValid,
	WPA_EAPOL_authorized,
	WPA_EAPOL_portControl_Auto,
	WPA_EAPOL_keyRun,
	WPA_EAPOL_keyAvailable,
	WPA_EAPOL_keyDone,
	WPA_EAPOL_inc_EapolFramesTx };

struct wpa_auth_callbacks {
	void *ctx;
	void (*logger)(void *ctx, const u8 *addr, int level, const char *txt);
	void (*disconnect)(void *ctx, const u8 *addr, u16 reason);
	int (*mic_failure_report)(void *ctx, const u8 *addr);
	void (*psk_failure_report)(void *ctx, const u8 *addr);
	void (*set_eapol)(void *ctx, const u8 *addr, int var, int value);
	int (*get_eapol)(void *ctx, const u8 *addr, int var);
	const u8 *(*get_psk)(void *ctx, const u8 *addr, const u8 *p2p_dev_addr,
			     const u8 *prev_psk);
	int (*get_msk)(void *ctx, const u8 *addr, u8 *msk, size_t *len);
	int (*set_key)(void *ctx, int vlan_id, enum wpa_alg alg, const u8 *addr,
		       int idx, u8 *key, size_t key_len);
	int (*get_seqnum)(void *ctx, const u8 *addr, int idx, u8 *seq);
	int (*send_eapol)(void *ctx, const u8 *addr, const u8 *data,
			  size_t data_len, int encrypt);
	int (*for_each_sta)(void *ctx,
			    int (*cb)(struct wpa_state_machine *sm, void *ctx),
			    void *cb_ctx);
	int (*for_each_auth)(void *ctx,
			     int (*cb)(struct wpa_authenticator *a, void *ctx),
			     void *cb_ctx);
	int (*send_ether)(void *ctx, const u8 *dst, u16 proto, const u8 *data,
			  size_t data_len);
};

struct wpa_authenticator *wpa_init(const u8 *addr, struct wpa_auth_config *conf,
				   struct wpa_auth_callbacks *cb, int u1BssIdx);
int wpa_init_keys(struct wpa_authenticator *wpa_auth);
void wpa_deinit(struct wpa_authenticator *wpa_auth);
int wpa_reconfig(struct wpa_authenticator *wpa_auth,
		 struct wpa_auth_config *conf);

enum { WPA_IE_OK,
	WPA_INVALID_IE,
	WPA_INVALID_GROUP,
	WPA_INVALID_PAIRWISE,
	WPA_INVALID_AKMP,
	WPA_NOT_ENABLED,
	WPA_ALLOC_FAIL,
	WPA_MGMT_FRAME_PROTECTION_VIOLATION,
	WPA_INVALID_MGMT_GROUP_CIPHER,
	WPA_INVALID_MDIE,
	WPA_INVALID_PROTO };

int wpa_validate_wpa_ie(struct wpa_authenticator *wpa_auth,
			struct wpa_state_machine *sm, const u8 *wpa_ie,
			size_t wpa_ie_len, const u8 *mdie, size_t mdie_len);
int wpa_validate_osen(struct wpa_authenticator *wpa_auth,
		      struct wpa_state_machine *sm, const u8 *osen_ie,
		      size_t osen_ie_len);
int wpa_auth_uses_mfp(struct wpa_state_machine *sm);
struct wpa_state_machine *wpa_auth_sta_init(struct wpa_authenticator *wpa_auth,
					    const u8 *addr,
					    const u8 *p2p_dev_addr);
int wpa_auth_sta_associated(struct wpa_authenticator *wpa_auth,
			    struct wpa_state_machine *sm);
void wpa_auth_sta_no_wpa(struct wpa_state_machine *sm);
void wpa_auth_sta_deinit(struct wpa_state_machine *sm);
void wpa_receive(struct wpa_authenticator *wpa_auth,
		 struct wpa_state_machine *sm, u8 *data, size_t data_len);
enum wpa_event {
	WPA_AUTH,
	WPA_ASSOC,
	WPA_DISASSOC,
	WPA_DEAUTH,
	WPA_REAUTH,
	WPA_REAUTH_EAPOL,
	WPA_ASSOC_FT
};
void wpa_remove_ptk(struct wpa_state_machine *sm);
int wpa_auth_sm_event(struct wpa_state_machine *sm, enum wpa_event event);
void wpa_auth_sm_notify(struct wpa_state_machine *sm);
void wpa_gtk_rekey(struct wpa_authenticator *wpa_auth);
int wpa_get_mib(struct wpa_authenticator *wpa_auth, char *buf, size_t buflen);
int wpa_get_mib_sta(struct wpa_state_machine *sm, char *buf, size_t buflen);
void wpa_auth_countermeasures_start(struct wpa_authenticator *wpa_auth);
int wpa_auth_pairwise_set(struct wpa_state_machine *sm);
int wpa_auth_get_pairwise(struct wpa_state_machine *sm);
int wpa_auth_sta_key_mgmt(struct wpa_state_machine *sm);
int wpa_auth_sta_wpa_version(struct wpa_state_machine *sm);
int wpa_auth_sta_clear_pmksa(struct wpa_state_machine *sm,
			     struct rsn_pmksa_cache_entry *entry);
struct rsn_pmksa_cache_entry *
wpa_auth_sta_get_pmksa(struct wpa_state_machine *sm);
void wpa_auth_sta_local_mic_failure_report(struct wpa_state_machine *sm);
const u8 *wpa_auth_get_wpa_ie(struct wpa_authenticator *wpa_auth, size_t *len);
int wpa_auth_pmksa_add(struct wpa_state_machine *sm, const u8 *pmk,
		       int session_timeout, struct eapol_state_machine *eapol);
int wpa_auth_pmksa_add_preauth(struct wpa_authenticator *wpa_auth,
			       const u8 *pmk, size_t len, const u8 *sta_addr,
			       int session_timeout,
			       struct eapol_state_machine *eapol);
int wpa_auth_pmksa_add_sae(struct wpa_authenticator *wpa_auth, const u8 *addr,
			   const u8 *pmk);
void wpa_auth_pmksa_remove(struct wpa_authenticator *wpa_auth,
			   const u8 *sta_addr);
int wpa_auth_sta_set_vlan(struct wpa_state_machine *sm, int vlan_id);
void wpa_auth_eapol_key_tx_status(struct wpa_authenticator *wpa_auth,
				  struct wpa_state_machine *sm, int ack);

void wpa_wnmsleep_rekey_gtk(struct wpa_state_machine *sm);
void wpa_set_wnmsleep(struct wpa_state_machine *sm, int flag);
int wpa_wnmsleep_gtk_subelem(struct wpa_state_machine *sm, u8 *pos);
int wpa_wnmsleep_igtk_subelem(struct wpa_state_machine *sm, u8 *pos);

int wpa_auth_uses_sae(struct wpa_state_machine *sm);
int wpa_auth_uses_ft_sae(struct wpa_state_machine *sm);

int wpa_auth_get_ip_addr(struct wpa_state_machine *sm, u8 *addr);

struct radius_das_attrs;
int wpa_auth_radius_das_disconnect_pmksa(struct wpa_authenticator *wpa_auth,
					 struct radius_das_attrs *attr);
void wpa_auth_reconfig_group_keys(struct wpa_authenticator *wpa_auth);

#ifdef CFG_SUPPORT_NAN
struct wpa_group *wpa_group_init(struct wpa_authenticator *wpa_auth,
				 int vlan_id, int delay_init);
void wpa_rekey_gmk(void *eloop_ctx, void *timeout_ctx);
void wpa_rekey_gtk(void *eloop_ctx, void *timeout_ctx);
int wpa_use_aes_cmac(struct wpa_state_machine *sm);
int wpa_receive_error_report(struct wpa_authenticator *wpa_auth,
			     struct wpa_state_machine *sm, int group);
void wpa_request_new_ptk(struct wpa_state_machine *sm);
int wpa_sm_step(struct wpa_state_machine *sm);
void wpa_send_eapol_timeout(void *eloop_ctx, void *timeout_ctx);
void wpa_auth_set_eapol(struct wpa_authenticator *wpa_auth, const u8 *addr,
			int var, int value);
#endif

#endif /* WPA_AUTH_H */
