/******************************************************************************
 *
 * This file is provided under a dual license.  When you use or
 * distribute this software, you may choose to be licensed under
 * version 2 of the GNU General Public License ("GPLv2 License")
 * or BSD License.
 *
 * GPLv2 License
 *
 * Copyright(C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 *
 * BSD LICENSE
 *
 * Copyright(C) 2016 MediaTek Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
/*! \file   "radiotap.h"
 *    \brief  The declaration of the radiotap functions
 *
 */


#ifndef _RADIOTAP_H
#define _RADIOTAP_H

#ifdef CFG_SUPPORT_SNIFFER_RADIOTAP

/*******************************************************************************
 *                         C O M P I L E R   F L A G S
 *******************************************************************************
 */

/*******************************************************************************
 *                    E X T E R N A L   R E F E R E N C E S
 *******************************************************************************
 */

/*******************************************************************************
 *                              C O N S T A N T S
 *******************************************************************************
 */
#define PKTHDR_RADIOTAP_VERSION		0

#define IEEE80211_RADIOTAP_FIELD_TSFT       BIT(0)
#define IEEE80211_RADIOTAP_FIELD_FLAGS      BIT(1)
#define IEEE80211_RADIOTAP_FIELD_RATE       BIT(2)
#define IEEE80211_RADIOTAP_FIELD_CHANNEL    BIT(3)
#define IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL BIT(5)
#define IEEE80211_RADIOTAP_FIELD_ANTENNA    BIT(11)
#define IEEE80211_RADIOTAP_FIELD_MCS        BIT(19)
#define IEEE80211_RADIOTAP_FIELD_AMPDU      BIT(20)
#define IEEE80211_RADIOTAP_FIELD_VHT        BIT(21)
#define IEEE80211_RADIOTAP_FIELD_TIMESTAMP  BIT(22)
#define IEEE80211_RADIOTAP_FIELD_HE         BIT(23)
#define IEEE80211_RADIOTAP_FIELD_HE_MU      BIT(24)
#define IEEE80211_RADIOTAP_FIELD_NS         BIT(29)
#define IEEE80211_RADIOTAP_FIELD_VENDOR     BIT(30)
#define IEEE80211_RADIOTAP_FIELD_EXT        BIT(31)

#define IEEE80211_RADIOTAP_FIELD_PRESENT_LEGACY (\
			IEEE80211_RADIOTAP_FIELD_FLAGS | \
			IEEE80211_RADIOTAP_FIELD_RATE | \
			IEEE80211_RADIOTAP_FIELD_CHANNEL | \
			IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL | \
			IEEE80211_RADIOTAP_FIELD_ANTENNA | \
			IEEE80211_RADIOTAP_FIELD_TIMESTAMP | \
			IEEE80211_RADIOTAP_FIELD_VENDOR)

#define IEEE80211_RADIOTAP_FIELD_PRESENT_HT (\
			IEEE80211_RADIOTAP_FIELD_FLAGS | \
			IEEE80211_RADIOTAP_FIELD_CHANNEL | \
			IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL | \
			IEEE80211_RADIOTAP_FIELD_ANTENNA | \
			IEEE80211_RADIOTAP_FIELD_MCS | \
			IEEE80211_RADIOTAP_FIELD_AMPDU | \
			IEEE80211_RADIOTAP_FIELD_TIMESTAMP | \
			IEEE80211_RADIOTAP_FIELD_VENDOR)

#define IEEE80211_RADIOTAP_FIELD_PRESENT_VHT (\
			IEEE80211_RADIOTAP_FIELD_FLAGS | \
			IEEE80211_RADIOTAP_FIELD_CHANNEL | \
			IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL | \
			IEEE80211_RADIOTAP_FIELD_ANTENNA | \
			IEEE80211_RADIOTAP_FIELD_AMPDU | \
			IEEE80211_RADIOTAP_FIELD_VHT | \
			IEEE80211_RADIOTAP_FIELD_TIMESTAMP | \
			IEEE80211_RADIOTAP_FIELD_VENDOR)

#define IEEE80211_RADIOTAP_FIELD_PRESENT_HE (\
			IEEE80211_RADIOTAP_FIELD_FLAGS | \
			IEEE80211_RADIOTAP_FIELD_CHANNEL | \
			IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL | \
			IEEE80211_RADIOTAP_FIELD_ANTENNA | \
			IEEE80211_RADIOTAP_FIELD_AMPDU | \
			IEEE80211_RADIOTAP_FIELD_TIMESTAMP | \
			IEEE80211_RADIOTAP_FIELD_HE | \
			IEEE80211_RADIOTAP_FIELD_VENDOR)

#define IEEE80211_RADIOTAP_FIELD_PRESENT_HE_MU (\
			IEEE80211_RADIOTAP_FIELD_FLAGS | \
			IEEE80211_RADIOTAP_FIELD_CHANNEL | \
			IEEE80211_RADIOTAP_FIELD_ANT_SIGNAL | \
			IEEE80211_RADIOTAP_FIELD_ANTENNA | \
			IEEE80211_RADIOTAP_FIELD_AMPDU | \
			IEEE80211_RADIOTAP_FIELD_TIMESTAMP | \
			IEEE80211_RADIOTAP_FIELD_HE | \
			IEEE80211_RADIOTAP_FIELD_HE_MU | \
			IEEE80211_RADIOTAP_FIELD_VENDOR)

/* Channel flags */
#define	IEEE80211_CHAN_TURBO    0x0010	/* Turbo channel */
#define	IEEE80211_CHAN_CCK      0x0020	/* CCK channel */
#define	IEEE80211_CHAN_OFDM     0x0040	/* OFDM channel */
#define	IEEE80211_CHAN_2GHZ     0x0080	/* 2 GHz spectrum channel. */
#define	IEEE80211_CHAN_5GHZ     0x0100	/* 5 GHz spectrum channel */
#define	IEEE80211_CHAN_PASSIVE  0x0200	/* Only passive scan allowed */
#define	IEEE80211_CHAN_DYN      0x0400	/* Dynamic CCK-OFDM channel */
#define	IEEE80211_CHAN_GFSK     0x0800	/* GFSK channel (FHSS PHY) */

/* For IEEE80211_RADIOTAP_FLAGS */
#define	IEEE80211_RADIOTAP_F_CFP        0x01
#define	IEEE80211_RADIOTAP_F_SHORTPRE	0x02
#define	IEEE80211_RADIOTAP_F_WEP        0x04
#define	IEEE80211_RADIOTAP_F_FRAG       0x08
#define	IEEE80211_RADIOTAP_F_FCS        0x10
#define	IEEE80211_RADIOTAP_F_DATAPAD    0x20
#define IEEE80211_RADIOTAP_F_BADFCS     0x40
#define IEEE80211_RADIOTAP_F_SHORTGI    0x80

/* For IEEE80211_RADIOTAP_RX_FLAGS */
#define IEEE80211_RADIOTAP_F_RX_BADPLCP	0x0002 /* bad PLCP */

/* For IEEE80211_RADIOTAP_TX_FLAGS */
#define IEEE80211_RADIOTAP_F_TX_FAIL    0x0001
#define IEEE80211_RADIOTAP_F_TX_CTS     0x0002	/* used cts 'protection' */
#define IEEE80211_RADIOTAP_F_TX_RTS     0x0004	/* used rts/cts handshake */

/* For IEEE80211_RADIOTAP_AMPDU_STATUS */
#define IEEE80211_RADIOTAP_AMPDU_REPORT_ZEROLEN     0x0001
#define IEEE80211_RADIOTAP_AMPDU_IS_ZEROLEN         0x0002
#define IEEE80211_RADIOTAP_AMPDU_LAST_KNOWN         0x0004
#define IEEE80211_RADIOTAP_AMPDU_IS_LAST            0x0008
#define IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_ERR      0x0010
#define IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_KNOWN    0x0020

/* For IEEE80211_RADIOTAP_MCS */
#define IEEE80211_RADIOTAP_MCS_HAVE_BW		0x01
#define IEEE80211_RADIOTAP_MCS_HAVE_MCS		0x02
#define IEEE80211_RADIOTAP_MCS_HAVE_GI		0x04
#define IEEE80211_RADIOTAP_MCS_HAVE_FMT		0x08
#define IEEE80211_RADIOTAP_MCS_HAVE_FEC		0x10
#define IEEE80211_RADIOTAP_MCS_HAVE_STBC    0x20
#define IEEE80211_RADIOTAP_MCS_HAVE_NESS	0x40
#define IEEE80211_RADIOTAP_MCS_HAVE_ALL		0x7f

#define IEEE80211_RADIOTAP_MCS_BW_MASK	0x03
#define	IEEE80211_RADIOTAP_MCS_BW_20	0
#define	IEEE80211_RADIOTAP_MCS_BW_40	1
#define	IEEE80211_RADIOTAP_MCS_BW_20L	2
#define	IEEE80211_RADIOTAP_MCS_BW_20U	3
#define IEEE80211_RADIOTAP_MCS_SGI		0x04
#define IEEE80211_RADIOTAP_MCS_FMT_GF	0x08
#define IEEE80211_RADIOTAP_MCS_FEC_LDPC	0x10
#define IEEE80211_RADIOTAP_MCS_STBC		5
#define IEEE80211_RADIOTAP_MCS_NESS		0x80

/* For IEEE80211_RADIOTAP_VHT */
#define IEEE80211_RADIOTAP_VHT_KNOWN_STBC                   0x0001
#define IEEE80211_RADIOTAP_VHT_KNOWN_TXOP_PS_NA             0x0002
#define IEEE80211_RADIOTAP_VHT_KNOWN_GI                     0x0004
#define IEEE80211_RADIOTAP_VHT_KNOWN_SGI_NSYM_DIS           0x0008
#define IEEE80211_RADIOTAP_VHT_KNOWN_LDPC_EXTRA_OFDM_SYM	0x0010
#define IEEE80211_RADIOTAP_VHT_KNOWN_BEAMFORMED             0x0020
#define IEEE80211_RADIOTAP_VHT_KNOWN_BANDWIDTH              0x0040
#define IEEE80211_RADIOTAP_VHT_KNOWN_GROUP_ID               0x0080
#define IEEE80211_RADIOTAP_VHT_KNOWN_PARTIAL_AID            0x0100
#define IEEE80211_RADIOTAP_VHT_KNOWN_ALL                    0x01ff

#define IEEE80211_RADIOTAP_VHT_FLAG_STBC                0x01
#define IEEE80211_RADIOTAP_VHT_FLAG_TXOP_PS_NA          0x02
#define IEEE80211_RADIOTAP_VHT_FLAG_SGI                 0x04
#define IEEE80211_RADIOTAP_VHT_FLAG_SGI_NSYM_M10_9		0x08
#define IEEE80211_RADIOTAP_VHT_FLAG_LDPC_EXTRA_OFDM_SYM	0x10
#define IEEE80211_RADIOTAP_VHT_FLAG_BEAMFORMED			0x20

#define	IEEE80211_RADIOTAP_VHT_BW_20	0
#define	IEEE80211_RADIOTAP_VHT_BW_40	1
#define	IEEE80211_RADIOTAP_VHT_BW_80	4
#define	IEEE80211_RADIOTAP_VHT_BW_160	11

/* For IEEE80211_RADIOTAP_HE  */
#define IEEE80211_RADIOTAP_HE_KNOWN_BSS_COLOR       0x0004
#define IEEE80211_RADIOTAP_HE_KNOWN_BEAM_CHANGE     0x0008
#define IEEE80211_RADIOTAP_HE_KNOWN_UL_DL           0x0010
#define IEEE80211_RADIOTAP_HE_KNOWN_DATA_MCS        0x0020
#define IEEE80211_RADIOTAP_HE_KNOWN_DCM             0x0040
#define IEEE80211_RADIOTAP_HE_KNOWN_CODING          0x0080
#define IEEE80211_RADIOTAP_HE_KNOWN_LDPC_EXTRA      0x0100
#define IEEE80211_RADIOTAP_HE_KNOWN_STBC			0x0200
#define IEEE80211_RADIOTAP_HE_KNOWN_SPATIAL_REUSE1	0x0400
#define IEEE80211_RADIOTAP_HE_KNOWN_SPATIAL_REUSE2	0x0800
#define IEEE80211_RADIOTAP_HE_KNOWN_STAID           0x0800
#define IEEE80211_RADIOTAP_HE_KNOWN_SPATIAL_REUSE3	0x1000
#define IEEE80211_RADIOTAP_HE_KNOWN_SPATIAL_REUSE4	0x2000
#define IEEE80211_RADIOTAP_HE_KNOWN_BW_RU_ALLOC     0x4000
#define IEEE80211_RADIOTAP_HE_KNOWN_DOPPLER         0x8000

#define IEEE80211_RADIOTAP_HE_KNOWN_DATA1   (IEEE80211_RADIOTAP_HE_KNOWN_BSS_COLOR | \
			IEEE80211_RADIOTAP_HE_KNOWN_BEAM_CHANGE | \
			IEEE80211_RADIOTAP_HE_KNOWN_UL_DL | \
			IEEE80211_RADIOTAP_HE_KNOWN_DATA_MCS | \
			IEEE80211_RADIOTAP_HE_KNOWN_DCM | \
			IEEE80211_RADIOTAP_HE_KNOWN_CODING | \
			IEEE80211_RADIOTAP_HE_KNOWN_LDPC_EXTRA | \
			IEEE80211_RADIOTAP_HE_KNOWN_STBC | \
			IEEE80211_RADIOTAP_HE_KNOWN_BW_RU_ALLOC | \
			IEEE80211_RADIOTAP_HE_KNOWN_DOPPLER)

#define IEEE80211_RADIOTAP_HE_KNOWN_PRI_SEC         0x0001
#define IEEE80211_RADIOTAP_HE_KNOWN_GI              0x0002
#define IEEE80211_RADIOTAP_HE_KNOWN_NO_LTF_SYMBOL   0x0004
#define IEEE80211_RADIOTAP_HE_KNOWN_PRE_FEC_PAD     0x0080
#define IEEE80211_RADIOTAP_HE_KNOWN_TX_BF           0x0010
#define IEEE80211_RADIOTAP_HE_KNOWN_PE_DEC          0x0020
#define IEEE80211_RADIOTAP_HE_KNOWN_TXOP            0x0040
#define IEEE80211_RADIOTAP_HE_KNOWN_MID_PERIODICITY 0x0080
#define IEEE80211_RADIOTAP_HE_RU_ALLOC_OFFSET_MASK  0x3f00
#define IEEE80211_RADIOTAP_HE_RU_ALLOC_OFFSET_OFFSET 8
#define IEEE80211_RADIOTAP_HE_KNOWN_RU_ALLOC_OFFSET	0x4000

#define IEEE80211_RADIOTAP_HE_KNOWN_DATA2   (IEEE80211_RADIOTAP_HE_KNOWN_GI | \
			IEEE80211_RADIOTAP_HE_KNOWN_PRE_FEC_PAD | \
			IEEE80211_RADIOTAP_HE_KNOWN_TX_BF | \
			IEEE80211_RADIOTAP_HE_KNOWN_PE_DEC | \
			IEEE80211_RADIOTAP_HE_KNOWN_TXOP | \
			IEEE80211_RADIOTAP_HE_KNOWN_RU_ALLOC_OFFSET)

#define IEEE80211_RADIOTAP_HE_SU        0
#define IEEE80211_RADIOTAP_HE_EXT_SU    1
#define IEEE80211_RADIOTAP_HE_MU        2
#define IEEE80211_RADIOTAP_HE_TRIG      3

#define IEEE80211_RADIOTAP_HE_SPATIAL_REUSE1_SHFT	0
#define IEEE80211_RADIOTAP_HE_SPATIAL_REUSE2_SHFT	4
#define IEEE80211_RADIOTAP_HE_SPATIAL_REUSE3_SHFT	8
#define IEEE80211_RADIOTAP_HE_SPATIAL_REUSE4_SHFT	12

#define IEEE80211_RADIOTAP_HE_BSS_COLOR_MASK	0x003f
#define IEEE80211_RADIOTAP_HE_BEAM_CHANGE_MASK	0x0040
#define IEEE80211_RADIOTAP_HE_BEAM_CHANGE_SHFT	6
#define IEEE80211_RADIOTAP_HE_UL_DL_MASK		0x0080
#define IEEE80211_RADIOTAP_HE_UL_DL_SHFT		7
#define IEEE80211_RADIOTAP_HE_DATA_MCS_MASK		0x0f00
#define IEEE80211_RADIOTAP_HE_DATA_MCS_SHFT		8
#define IEEE80211_RADIOTAP_HE_DATA_DCM_MASK		0x1000
#define IEEE80211_RADIOTAP_HE_DATA_DCM_SHFT		12
#define IEEE80211_RADIOTAP_HE_CODING_MASK		0x2000
#define IEEE80211_RADIOTAP_HE_CODING_SHFT		13
#define IEEE80211_RADIOTAP_HE_LDPC_EXTRA_MASK	0x4000
#define IEEE80211_RADIOTAP_HE_LDPC_EXTRA_SHFT	14
#define IEEE80211_RADIOTAP_HE_STBC_MASK			0x8000
#define IEEE80211_RADIOTAP_HE_STBC_SHFT			15

#define IEEE80211_RADIOTAP_HE_RU_IDX_26_RU37    36
#define IEEE80211_RADIOTAP_HE_RU_IDX_52_RU16    52
#define IEEE80211_RADIOTAP_HE_RU_IDX_106_RU8    60
#define IEEE80211_RADIOTAP_HE_RU_IDX_242_RU4    64
#define IEEE80211_RADIOTAP_HE_RU_IDX_484_RU2    66
#define IEEE80211_RADIOTAP_HE_RU_IDX_996_RU1    67
#define IEEE80211_RADIOTAP_HE_RU_IDX_2x_996_RU1	68

#define IEEE80211_RADIOTAP_HE_GI_SHFT			4
#define IEEE80211_RADIOTAP_HE_LTF_SYMBO_SHFT	6
#define IEEE80211_RADIOTAP_HE_TX_BF_SHFT		14
#define IEEE80211_RADIOTAP_HE_PE_DISAMB_SHFT	15

#define IEEE80211_RADIOTAP_HE_DOPPLER_SHFT		4
#define IEEE80211_RADIOTAP_HE_TXOP_SHFT			8

#define IEEE80211_RADIOTAP_HE_MU_MCS_KNOWN_MASK		0x0010
#define IEEE80211_RADIOTAP_HE_MU_DCM_SHFT			5
#define IEEE80211_RADIOTAP_HE_MU_DCM_KNOWN_MASK		0x0040
#define IEEE80211_RADIOTAP_HE_MU_CH1_RU_KNOWN_MASK	0x0100
#define IEEE80211_RADIOTAP_HE_MU_CH2_RU_KNOWN_MASK	0x0200
#define IEEE80211_RADIOTAP_HE_MU_USER_KNOWN_MASK	0x8000

#define IEEE80211_RADIOTAP_HE_MU_BW_KNOWN_MASK		0x0004
#define IEEE80211_RADIOTAP_HE_MU_USER_MASK			0x00f0
#define IEEE80211_RADIOTAP_HE_MU_USER_SHFT			4

/*******************************************************************************
 *                            P U B L I C   D A T A
 *******************************************************************************
 */
enum ENUM_IEEE80211_RADIOTAP_SUPPORT {
	IEEE80211_RADIOTAP_SUPPORT_FLAGS = 0,
	IEEE80211_RADIOTAP_SUPPORT_RATE,
	IEEE80211_RADIOTAP_SUPPORT_CHANNEL,
	IEEE80211_RADIOTAP_SUPPORT_ANT_SIGNAL,
	IEEE80211_RADIOTAP_SUPPORT_ANTENNA,
	IEEE80211_RADIOTAP_SUPPORT_MCS,
	IEEE80211_RADIOTAP_SUPPORT_AMPDU_STATUS,
	IEEE80211_RADIOTAP_SUPPORT_VHT,
	IEEE80211_RADIOTAP_SUPPORT_TIEMSTAMP,
	IEEE80211_RADIOTAP_SUPPORT_HE,
	IEEE80211_RADIOTAP_SUPPORT_HE_MU,
	IEEE80211_RADIOTAP_SUPPORT_VENDOR_NAMESPACE,
	IEEE80211_RADIOTAP_SUPPORT_NUM
};

enum ENUM_IEEE80211_RADIOTAP_HE_BW_RU {
	IEEE80211_RADIOTAP_HE_BW_20 = 0,
	IEEE80211_RADIOTAP_HE_BW_40,
	IEEE80211_RADIOTAP_HE_BW_80,
	IEEE80211_RADIOTAP_HE_BW_160,
	IEEE80211_RADIOTAP_HE_RU_26,
	IEEE80211_RADIOTAP_HE_RU_52,
	IEEE80211_RADIOTAP_HE_RU_106,
	IEEE80211_RADIOTAP_HE_RU_242,
	IEEE80211_RADIOTAP_HE_RU_484,
	IEEE80211_RADIOTAP_HE_RU_996,
	IEEE80211_RADIOTAP_HE_RU_2x_996
};

struct IEEE80211_RADIOTAP_HEADER {
	uint8_t ucItVersion;
	uint8_t ucItPad;
	uint16_t u2ItLen;
	uint32_t u4ItPresent;
} __KAL_ATTRIB_PACKED__;

/* TSFT
 * Bit Number 0
 * Required Alignment 8 bytes
 * Unit microseconds
 */
struct TSFT {
	uint64_t u8MacTime;
} __KAL_ATTRIB_PACKED__;

/* Flags
 * Bit Number 1
 */
struct FLAGS {
	uint8_t ucFlags;
} __KAL_ATTRIB_PACKED__;

/* Rate
 * Bit Number 2
 * Unit 500 Kbps
 */
struct RATE {
	uint8_t ucRate;
} __KAL_ATTRIB_PACKED__;

/* Channel
 * Bit Number 3
 * Required Alignment 2 bytes
 */
struct CHANNEL {
	uint16_t u2ChFrequency;
	uint16_t u2ChFlags;
} __KAL_ATTRIB_PACKED__;

/* Antenna signal
 * Bit Number 5
 * Unit dBm
 */
struct ANT_SIGNAL {
	int8_t i1AntennaSignal;
} __KAL_ATTRIB_PACKED__;

/* Antenna
 * Bit Number 11
 */
struct ANTENNA {
	uint8_t ucAntIdx;
} __KAL_ATTRIB_PACKED__;

/* MCS
 * Bit Number 19
 */
struct MCS {
	uint8_t ucMcsKnown;
	uint8_t ucMcsFlags;
	uint8_t ucMcsMcs;
} __KAL_ATTRIB_PACKED__;

/* A-MPDU
 * Bit Number 20
 * Required Alignment 4 bytes
 */
struct AMPDU {
	uint32_t u4AmpduRefNum;
	uint16_t u2AmpduFlags;
	uint8_t ucAmpduDelimiterCRC;
	uint8_t ucAmpduReserved;
} __KAL_ATTRIB_PACKED__;

/* VHT
 * Bit Number 21
 * Required Alignment 2 bytes
 */
struct VHT {
	uint16_t u2VhtKnown;
	uint8_t ucVhtFlags;
	uint8_t ucVhtBandwidth;
	uint8_t aucVhtMcsNss[4];
	uint8_t ucVhtCoding;
	uint8_t ucVhtGroupId;
	uint16_t u2VhtPartialAid;
} __KAL_ATTRIB_PACKED__;

/* TIMESTAMP
 * Bit Number 22
 * Required Alignment 8 bytes
 */
struct TIMESTAMP {
	uint64_t u8Timestamp;
	uint16_t u2Accuracy;
	uint8_t ucUnit;
	uint8_t ucFlags;
} __KAL_ATTRIB_PACKED__;

/* HE
 * Bit Number 23
 * Required Alignment 2 bytes
 */
struct HE {
	uint16_t u2Data1;
	uint16_t u2Data2;
	uint16_t u2Data3;
	uint16_t u2Data4;
	uint16_t u2Data5;
	uint16_t u2Data6;
} __KAL_ATTRIB_PACKED__;

/* HE MU
 * Bit Number 24
 * Required Alignment 2 bytes
 */
struct HE_MU {
	uint16_t u2Flag1;
	uint16_t u2Flag2;
	uint8_t aucRuChannel1[4];
	uint8_t aucRuChannel2[4];
} __KAL_ATTRIB_PACKED__;

/* Vendor Namespace
 * Bit Number 30
 * Required Alignment 2 bytes
 */
struct VENDOR_NAMESPACE {
	uint8_t aucOUI[3];
	uint8_t ucSubNamespace;
	uint16_t u2DataLen;
} __KAL_ATTRIB_PACKED__;

struct IEEE80211_RADIOTAP_INFO {
	/* common */
	uint8_t ucFcsErr;
	uint8_t ucFrag;
	uint8_t ucTxMode;
	uint8_t ucFrMode;
	uint8_t ucShortGI;
	uint8_t ucLDPC;
	uint8_t ucSTBC;
	uint8_t ucNess;
	uint8_t ucMcs;
	uint8_t ucRcpi0;
	uint8_t ucTxopPsNotAllow;
	uint8_t ucLdpcExtraOfdmSym;
	uint8_t ucNsts;
	uint8_t ucBeamFormed;
	uint8_t ucSubNamespace;
	uint8_t ucChanNum;
	uint8_t ucRfBand;
	uint16_t u2VendorLen;
	uint32_t u4AmpduRefNum;
	uint32_t u4Timestamp;
	/* VHT */
	uint8_t ucVhtGroupId;
	/* HE */
	uint8_t ucPeDisamb;
	uint8_t ucNumUser;
	uint8_t ucSigBRU0;
	uint8_t ucSigBRU1;
	uint8_t ucSigBRU2;
	uint8_t ucSigBRU3;
	uint16_t u2VhtPartialAid;
	uint16_t u2BssClr;
	uint16_t u2BeamChange;
	uint16_t u2UlDl;
	uint16_t u2DataDcm;
	uint16_t u2SpatialReuse1;
	uint16_t u2SpatialReuse2;
	uint16_t u2SpatialReuse3;
	uint16_t u2SpatialReuse4;
	uint16_t u2RuAllocation;
	uint16_t u2Ltf;
	uint16_t u2Doppler;
	uint16_t u2Txop;
};

struct IEEE80211_RADIOTAP_FIELD_FUNC {
	uint16_t offset;
	void (*radiotap_fill_func)(
		struct IEEE80211_RADIOTAP_INFO *p_radiotap_info,
		uint8_t *p_data);
};

/*******************************************************************************
 *                   F U N C T I O N   D E C L A R A T I O N S
 *******************************************************************************
 */
void radiotapFillRadiotap(IN struct ADAPTER *prAdapter,
		IN OUT struct SW_RFB *prSwRfb);

#endif
#endif /* _RADIOTAP_H */
