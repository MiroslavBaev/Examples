/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Rrd.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of RRD Module (Resident Ram Disk)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_RRD_H
  #define __AP_RRD_H
    
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
  RX_RESULT FAR Drv_RrdMountRamdisk         (RX_HANDLE            hVol); /* Initializes a Resident RAM Disk , parameter for config file */


#endif

#ifdef __cplusplus
}
#endif

