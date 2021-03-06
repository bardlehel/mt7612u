/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology	5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved.	Ralink's source	code is	an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering	the source code	is stricitly prohibited, unless	the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	ral_nmac_pbf.h

	Abstract:
	Ralink Wireless Chip MAC related definition & structures

	Revision History:
	Who			When		  What
	--------	----------	  ----------------------------------------------
*/

#ifndef __RAL_NMAC_PBF_H__
#define __RAL_NMAC_PBF_H__



/* ================================================================================= */
/* Register format  for PBF                                                                                                                                                     */
/* ================================================================================= */


/* Most are for debug. Driver doesn't touch PBF register. */
#ifdef RT_BIG_ENDIAN
typedef union _RLT_PBF_SYS_CTRL_STRUC {
	struct {
		uint32_t rsv5:7; /* Reserved */
		uint32_t CSR_TEST_EN:1;
		uint32_t MAC_CLKSEL:2; /* MAC clock selection */
		uint32_t PWRSV_EN:2;
		uint32_t SHRM_SEL:1; /* Shared memory access selection */
		uint32_t PBF_MSEL:2; /* Packet buffer memory access selection */
		uint32_t rsv4:5;
		uint32_t PBF_CLK_EN:1; /* PBF clock enable */
		uint32_t MAC_CLK_EN:1; /* MAC clock enable */
		uint32_t rsv3:6;
		uint32_t PBF_RESET:1; /* PBF hardware reset */
		uint32_t MAC_RESET:1; /* MAC hardware reset */
		uint32_t rsv:2;
	} field;
	uint32_t word;
} RLT_PBF_SYS_CTRL_STRUC;
#else
typedef union _RLT_PBF_SYS_CTRL_STRUC{
	struct {
                uint32_t rsv5:7; /* Reserved */
                uint32_t CSR_TEST_EN:1;
                uint32_t MAC_CLKSEL:2; /* MAC clock selection */
                uint32_t PWRSV_EN:2;
                uint32_t SHRM_SEL:1; /* Shared memory access selection */
                uint32_t PBF_MSEL:2; /* Packet buffer memory access selection */
                uint32_t rsv4:5;
                uint32_t PBF_CLK_EN:1; /* PBF clock enable */
                uint32_t MAC_CLK_EN:1; /* MAC clock enable */
                uint32_t rsv3:6;
                uint32_t PBF_RESET:1; /* PBF hardware reset */
                uint32_t MAC_RESET:1; /* MAC hardware reset */
                uint32_t rsv:2;
	}field;
	uint32_t word;
} RLT_PBF_SYS_CTRL_STRUC;
#endif


#define RLT_PBF_CFG			0x0404
#define RX_DROP_MODE 		(1 << 8)
#define TX_MAX_PCNT			0x0408
#define RX_MAX_PCNT			0x040c
#define RXQ_STA				0x0430
#define TXQ_STA				0x0434

#define RLT_BCN_OFFSET0		0x041c
#define RLT_BCN_OFFSET1		0x0420
#define RLT_BCN_OFFSET2		0x0424
#define RLT_BCN_OFFSET3		0x0428


#define FCE_CTRL			0x0800
#define FCE_PARAM		0x0804
#define CHECKSUM_OFFLOAD	0x0808

#endif /* __RAL_NMAC_PBF_H__ */

