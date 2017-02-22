/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	rtmp_mcu.c

	Abstract:

	Revision History:
	Who         When          What
	--------    ----------    ----------------------------------------------
*/


#include	"rt_config.h"

INT MCUBurstWrite(struct rtmp_adapter *pAd, uint32_t Offset, uint32_t *Data, uint32_t Cnt)
{
#ifdef RTMP_USB_SUPPORT
	RTUSBMultiWrite_nBytes(pAd, Offset, (UCHAR *)Data, Cnt * 4, 64);
#endif /* RTMP_USB_SUPPORT */
	return 0;
}


INT MCURandomWrite(struct rtmp_adapter *pAd, RTMP_REG_PAIR *RegPair, uint32_t Num)
{
	uint32_t Index;

	for (Index = 0; Index < Num; Index++)
		RTMP_IO_WRITE32(pAd, RegPair->Register, RegPair->Value);

	return 0;
}


INT mcu_sys_init(struct rtmp_adapter *pAd)
{
	int Status;

	/* Load MCU firmware*/
	MCU_CTRL_INIT(pAd);

	Status = load_patch(pAd);

	if (Status != NDIS_STATUS_SUCCESS)
	{
		DBGPRINT_ERR(("load patch failed, Status[=0x%08x]\n", Status));
		return FALSE;
	}

	Status = NICLoadFirmware(pAd);
	if (Status != NDIS_STATUS_SUCCESS)
	{
		DBGPRINT_ERR(("NICLoadFirmware failed, Status[=0x%08x]\n", Status));
		return FALSE;
	}

	return TRUE;
}


VOID ChipOpsMCUHook(struct rtmp_adapter *pAd, enum MCU_TYPE MCUType)
{
	RTMP_CHIP_OP *pChipOps = &pAd->chipOps;



#ifdef CONFIG_ANDES_SUPPORT
	if (MCUType == ANDES)
	{
		RTMP_CHIP_CAP *pChipCap = &pAd->chipCap;


#ifdef RTMP_USB_SUPPORT
		if (pChipCap->need_load_rom_patch) {
			pChipOps->load_rom_patch = andes_usb_load_rom_patch;
		}

		if (pChipCap->need_load_fw) {
			pChipOps->loadFirmware = andes_usb_loadfw;
		}

		pChipOps->fw_init = andes_usb_fw_init;
#endif /* RTMP_USB_SUPPORT */

		if (pChipCap->need_load_fw)
		{
			//pChipOps->sendCommandToMcu = andes_send_cmd_msg;
			pChipOps->MCUCtrlInit = andes_ctrl_init;
			pChipOps->MCUCtrlExit = andes_ctrl_exit;
			pChipOps->Calibration = (void (*)(struct rtmp_adapter *, uint32_t, ANDES_CALIBRATION_PARAM *))andes_calibration;		
			pChipOps->RandomWrite = andes_random_write;
			pChipOps->PwrSavingOP = andes_pwr_saving;
		}
	}
#endif /* CONFIG_ANDES_SUPPORT */
}

