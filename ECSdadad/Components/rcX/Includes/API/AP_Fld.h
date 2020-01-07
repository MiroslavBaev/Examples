/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Fld.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Serial Flash Disk (No Wear-Levelling) Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_FLD_H
  #define __AP_FLD_H

  RX_RESULT FAR   Drv_FldMountFlash           (RX_HANDLE                              hVol);

#endif

#ifdef __cplusplus
}
#endif
