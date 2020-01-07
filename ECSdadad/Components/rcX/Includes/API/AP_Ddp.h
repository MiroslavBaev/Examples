/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Ddp.h 1326 2013-03-06 12:02:28Z MichaelT $

  Description:
    Standardized definitions of RX DeviceDataProvider

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2013-03-06  MT            File created.

******************************************************************************/

#ifndef __AP_DDP__H
#define __AP_DDP__H

typedef struct DEVICE_DATA_Ttag
{
  /* Vital device data used for unique identification */
  UINT32  ulDeviceNumber;
  UINT32  ulSerialNumber;
  UINT16  usManufacturer;
  UINT16  usDeviceClass;
  UINT8   bSlotNumber;
  UINT32  ulLicenseFlags1;
  UINT32  ulLicenseFlags2;
  UINT16  usNetxLicenseID;
  UINT16  usNetxLicenseFlags;

  /* Production / HW Options */
  UINT16  usProductionDate;
  UINT8   bHwRevision;
  UINT8   bHwCompatibility;
  UINT8   bHwAssemblyFeatures;
  UINT16  ausHwOptions[4];
  
} DEVICE_DATA_T;

#define EXT_DEVICE_DATA_TYPE_MACADDR      (1)
#define EXT_DEVICE_DATA_TYPE_MRAM         (2)
#define EXT_DEVICE_DATA_TYPE_SECMEM       (3)
#define EXT_DEVICE_DATA_TYPE_SECMEM_DATA  (4)

typedef struct GET_EXT_DEVICE_DATA_MAC_IN_Ttag
{
  UINT32  ulPort;
} GET_EXT_DEVICE_DATA_MAC_IN_T;

typedef struct GET_EXT_DEVICE_DATA_MAC_OUT_Ttag
{
  UINT8  abMAC[6];
} GET_EXT_DEVICE_DATA_MAC_OUT_T;

typedef struct SET_EXT_DEVICE_DATA_MAC_IN_Ttag
{
  UINT32 ulPort;
  UINT32 ulFlags;
  UINT8  abMAC[6];
} SET_EXT_DEVICE_DATA_MAC_IN_T;

typedef struct GET_EXT_DEVICE_DATA_MRAM_OUT_Ttag
{
  UINT8  bMemoryType;
  UINT8  bChipSelect;
  UINT8  bAccess;
  UINT32 ulSize;
  UINT32 ulTiming;
} GET_EXT_DEVICE_DATA_MRAM_OUT_T;

typedef struct GET_EXT_DEVICE_DATA_SECMEM_OUT_Ttag
{
  int      fAvailable;
  int      fValid;
} GET_EXT_DEVICE_DATA_SECMEM_OUT_T;

typedef struct SET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_IN_Ttag
{
  UINT32  ulZoneId;
  UINT32  ulWriteSize;
  void*     pvWriteData;
} SET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_IN_T;

typedef struct GET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_IN_Ttag
{
  UINT32  ulZoneId;
  UINT32  ulSize;
} GET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_IN_T;

typedef struct GET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_OUT_Ttag
{
  void* pvReadData;
} GET_EXT_DEVICE_DATA_TYPE_SECMEM_DATA_OUT_T;

#define DEVICEDATAPROVIDER_NOTIFICATION_PRE_DRIVER      0
#define DEVICEDATAPROVIDER_NOTIFICATION_POST_DRIVER     1
#define DEVICEDATAPROVIDER_NOTIFICATION_PRE_MIDDLEWARE  2

RX_RESULT      rX_DdpInitDeviceDataProvider(UINT32 ulNotification);
DEVICE_DATA_T* rX_DdpGetBaseDeviceData(void);
RX_RESULT      rX_DdpGetExtendedDeviceData(UINT32 ulDataType, UINT32 ulInSize, void* pvIn, UINT32 ulOutSize, void* pvOut);

void           rX_DdpSetBaseDeviceData(DEVICE_DATA_T* ptDeviceData);
RX_RESULT      rX_DdpSetExtendedDeviceData(UINT32 ulDataType, UINT32 ulInSize, void* pvIn);

#endif /* __AP_DDP__H */
