/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Sec.h 1313 2013-03-04 09:39:15Z MichaelT $

  Description:
    USER - Headerfile of Security EEPROM Driver Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_SEC_H
  #define __AP_SEC_H

  #include "Structs_Sec.h"

  /* Zone definitions to read/write raw area */
  #define SECMEM_ZONE1 0x00
  #define SECMEM_ZONE2 0x01
  #define SECMEM_ZONE3 0x02
  #define SECMEM_IDENT 0xFF

  RX_FATAL FAR    DrvSecInit            ();

  RX_RESULT       Drv_SecGetZone1Data       (AT_CM_AREA1_T* ptZone1Data);

  RX_RESULT       Drv_SecGetRawArea         (UINT8*     pabRawArea,
                                             UINT16     usInstance);

  RX_RESULT       Drv_SecSetRawArea         (UINT8*     pabNewRawArea,
                                             UINT16     usInstance);

  RX_RESULT       Drv_SecGetHardwareConfig  (PAT_CM_AREA1_T ptZone1);

  RX_RESULT       Drv_SecGetOsSettings      (UINT8* pabOsSettings);

  RX_RESULT       Drv_SecFlush              ();

  RX_RESULT       Drv_SecReadLicense        (UINT32*        pulLicenseFlags1, 
                                             UINT32*        pulLicenseFlags2, 
                                             UINT16*        pusNetxLicenseID, 
                                             UINT16*        pusNetxLicenseFlags);

  RX_RESULT       Drv_SecCheckLicense       (UINT           uInstance,
                                             UINT32         ulRng0,
                                             UINT32         ulRng1,
                                             UINT           uBit);

  /* With introduction of the data provider the following functions offered by the 
     Security EEPROM Driver are marked deprecated:
     - Drv_SecGetIdentificationData
     - Drv_SecGetDeviceInfo
     - Drv_SecGetMacAddress
     - Drv_SecSetMacAddress
     - Drv_SecSetMacAddressNonPersistent
     
     Please use the functions offered by the data provider instead:
     - Get/SetBaseDeviceData 
     - Get/SetExtendedDeviceData
  */
  RX_RESULT       Drv_SecGetIdentificationData      (AT_CM_IDENTIFICATION_T* ptIdentData)     __attribute__ ((deprecated));

  RX_RESULT       Drv_SecGetDeviceInfo              (UINT32*                 pulDeviceNumber,
                                                     UINT32*                 pulSerialNumber) __attribute__ ((deprecated));
                                                                             
  RX_RESULT       Drv_SecGetMacAddress              (UINT8*                  pabMacAddr, 
                                                     UINT32                  ulInstance)      __attribute__ ((deprecated));
                                                                             
  RX_RESULT       Drv_SecSetMacAddress              (UINT8*                  pabNewMacAddr)   __attribute__ ((deprecated));
                                                                             
  RX_RESULT       Drv_SecSetMacAddressNonPersistent (UINT8*                  pabNewMacAddr)   __attribute__ ((deprecated));

#endif

#ifdef __cplusplus
}
#endif
