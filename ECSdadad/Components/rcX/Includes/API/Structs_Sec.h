/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: Structs_Sec.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    User header file of Security EEPROM Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-12-16  NC            Added new configuration zone members bHostInterfaceType and bHwAssemblyFeatures.
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __STRUCTS_SEC_H
#define __STRUCTS_SEC_H

/*****************************************************************************/
/*!  \ingroup RCX_DRV_SEC
*    \{                                                                      */
/*****************************************************************************/

/*! Layout identification zone */
typedef __PACKED_PRE struct 
{
  unsigned short usManufacturer;      /*!< Manufacturer */
  unsigned long  ulDeviceNumber;      /*!< Device Number */
  unsigned long  ulSerialNumber;      /*!< Serial Number */
  unsigned char  bHwRevision;         /*!< Hardware Revision */
  unsigned short usProductionDate;    /*!< Production Date */
  unsigned short usDeviceClass;       /*!< netX Device Class */
  unsigned char  bHwCompatibility;    /*!< Hardware Compatibility */
  unsigned char  bHostInterfaceType;  /* host interface type (0=autodetect, 1=PCI, 2=DPM, 3=ISA) */
  unsigned char  bHwAssemblyFeatures; /* hardware assembly feature flags (presence and types of RTC and MRAM) */
} __PACKED_POST AT_CM_IDENTIFICATION_T, *PAT_CM_IDENTIFICATION_T;


/*! Layout zone 1 */
typedef __PACKED_PRE struct 
{
    unsigned char abMacAddress[6];    /*!< MAC address */
    unsigned long ulSdramGeneralCtrl; /*!< SDRAM control register value */
    unsigned long ulSdramTimingCtrl;  /*!< SDRAM timing register value */
    unsigned char bSdramSizeExp;      /*!< SDRAM size in 2 Exp. SdramSizeExp Bytes */
    unsigned short ausHwOptions[4];   /*!< Hardware Assembly Option */
    unsigned char bBootOption;        /*!< Boot Option */
    unsigned char abReserved[6];      /*!< Reserved 15 Bytes */
    unsigned char bZone1Revision;     /*!< Revision Structure of Zone 1 */
    unsigned char bZone1Checksum;     /*!< CRC8-ATM Byte 0 till 30 */
} __PACKED_POST AT_CM_AREA1_T, *PAT_CM_AREA1_T;

/*! Layout zone 3 (user specific) */
typedef struct 
{
  unsigned char abBytes[32];  /*!< User specific data */
} AT_CM_AREA3_T, *PAT_CM_AREA3_T;

/*****************************************************************************/
/*!  \}                                                                      */
/*****************************************************************************/

#endif /* #ifndef __STRUCTS_SEC_H */
