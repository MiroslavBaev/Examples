/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Dev.h 1037 2012-08-03 08:38:31Z MichaelT $

  Description:
    USER - Headerfile of Device Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_DEV_H
#define __AP_DEV_H

  /*
  ************************************************************
  *   System Start options
  ************************************************************
  */

  enum RX_DEV_RESETMODEtag {
    RX_MODE_NONE          = 0,
    RX_MODE_POWERON       = 0,
    RX_MODE_COLDSTART     = 1,
    RX_MODE_WARMSTART     = 2,
    RX_MODE_BOOTSTART     = 3,
    RX_MODE_CFGSTART      = 4,
    RX_MODE_NOT_SUPPORTED = -1
  };
  typedef UINT32 RX_DEV_RESETMODE;

  /*
  ************************************************************
  *   Boot type methods
  ************************************************************
  */
  enum RX_DEV_BOOT_TYPEtag {
    RX_DEV_BOOT_TYPE_PFLASH_SRAMBUS,
    RX_DEV_BOOT_TYPE_PFLASH_EXTBUS,
    RX_DEV_BOOT_TYPE_DUALPORT,
    RX_DEV_BOOT_TYPE_RSRVD1,          /* reserved for internal use */
    RX_DEV_BOOT_TYPE_MMC,
    RX_DEV_BOOT_TYPE_I2C,
    RX_DEV_BOOT_TYPE_SFLASH
  };
  typedef UINT32 RX_DEV_BOOT_TYPE;
  
  /*
  ************************************************************
  *   Chip type return codes
  ************************************************************
  */
  enum RX_DEV_CHIP_TYPEtag {
    RX_DEV_CHIP_TYPE_UNKNOWN,
    RX_DEV_CHIP_TYPE_NETX500,
    RX_DEV_CHIP_TYPE_NETX100,
    RX_DEV_CHIP_TYPE_NETX50,
    RX_DEV_CHIP_TYPE_NETX10,
    RX_DEV_CHIP_TYPE_NETX51,
    RX_DEV_CHIP_TYPE_NETX52,
  };
  typedef UINT32 RX_DEV_CHIP_TYPE;
  


  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  void FAR              rX_DevReset         (UINT               uTcks,
                                             RX_DEV_RESETMODE   eMod);

  RX_DEV_RESETMODE FAR  rX_DevGetStartmode  (void);

  RX_DEV_BOOT_TYPE FAR  rX_DevGetBoottype   (void);
  
  void FAR*             rX_DevGetBootblock  (void);

  void FAR              rX_DevSetStartcode  (RX_STATUSCODE eStatusCode);      /* sets the current status code of the rcX Init */

  void FAR              rX_DevSetStartFault (void);                           /* sets the current init status to fault state */

  RX_DEV_CHIP_TYPE FAR  rX_DevGetChiptype   (void);
  UINT32                rX_DevGetChipstep(void);
  UINT32                rX_DevGetRomcodeRevision(void);
  
#endif

#ifdef __cplusplus
}
#endif
