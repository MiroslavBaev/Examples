/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_SqiRom.h 1648 2013-12-02 16:11:27Z stephans $

  Description:
    USER - Headerfile of Serial Flash Disk on netX if SQI XiP is active

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_SQIROM_H
#define __AP_SQIROM_H

  RX_RESULT FAR   Drv_SqiRomMountFlash           (RX_HANDLE                              hVol);

  /*****************************************************************************/
  /*! Disable lock for write access (FALSE by default to use with xip firmware)*/
  /*****************************************************************************/
  extern BOOLEAN g_fSqiRomLockDisabled;
#endif

#ifdef __cplusplus
}
#endif
