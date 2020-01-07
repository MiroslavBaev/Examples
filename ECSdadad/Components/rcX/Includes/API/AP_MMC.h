/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_MMC.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of SDMMC cards Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __AP_MMC_H
#define __AP_MMC_H

#ifdef __cplusplus
extern "C" {
#endif

  RX_RESULT FAR Drv_MMCMount(RX_HANDLE hVol);

#ifdef __cplusplus
}
#endif

#endif /* __AP_MMC_H */
