/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Rdk.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of RDK Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_RDK_H
  #define __AP_RDK_H
 
  /*
  ************************************************************
  *   Module Definitions
  ************************************************************
  */  

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  RX_RESULT FAR Drv_RdkMountRamdisk         (RX_HANDLE            hVol); /* Initializes a RAM Disk , parameter for config file */

#endif

#ifdef __cplusplus
}
#endif

