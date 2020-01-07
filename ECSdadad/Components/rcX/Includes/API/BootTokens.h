/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: BootTokens.h 1585 2013-08-22 12:23:28Z MichaelT $

  Description:
    Definition of boottokens passed by second stage loader

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2012-12-12  MT            Added 2nd Stage version information
                              Updated to use TLR_Types.h
    2012-04-19  MT            Added serial flash token
                              Added custom mmio mapping to hardware flags
    2010-03-23  NC            File created.

******************************************************************************/

#ifndef BOOTTOKENS_H_
#define BOOTTOKENS_H_

#include "rcX_Public.h"
#include "TLR_Types.h"

#define BOOTTOKEN_COOKIE  0xAA5511EE

#define BOOTTOKEN_FLASHDISK     0x01
#define BOOTTOKEN_RAMDISK       0x02
#define BOOTTOKEN_LICENSE       0x03
#define BOOTTOKEN_RAMSIZE       0x04
#define BOOTTOKEN_HARDWARE      0x05
#define BOOTTOKEN_SFLASHPARAMS  0x06
#define BOOTTOKEN_BSLINFO       0x07

#define BOOTTOKEN_ENDOFLIST   0x00

typedef __TLR_PACKED_PRE struct BOOTTOKEN_HEADER_Ttag 
{
  TLR_UINT8 bToken;
  TLR_UINT8 bLength;
  
} __TLR_PACKED_POST BOOTTOKEN_HEADER_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_FLASHDISK_DATA_Ttag
{
  TLR_UINT32 ulSpiSlave;
  TLR_UINT32 ulBlockSize;
  TLR_UINT32 ulOffset;
  TLR_UINT32 ulDiskSize;
  
} __TLR_PACKED_POST BOOTTOKEN_FLASHDISK_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_FLASHDISK_Ttag
{
  BOOTTOKEN_HEADER_T          tHeader;
  BOOTTOKEN_FLASHDISK_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_FLASHDISK_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_RAMDISK_DATA_Ttag
{
  TLR_UINT32 ulBlockSize;
  TLR_UINT32 ulOffset;
  TLR_UINT32 ulDiskSize;
  
} __TLR_PACKED_POST BOOTTOKEN_RAMDISK_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_RAMDISK_Ttag
{
  BOOTTOKEN_HEADER_T        tHeader;
  BOOTTOKEN_RAMDISK_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_RAMDISK_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_LICENSE_DATA_Ttag
{
  TLR_UINT32 ulLicenseFlags1;
  TLR_UINT32 ulLicenseFlags2;
  TLR_UINT16 usNetxLicenseId;
  TLR_UINT16 usNetxLicenseFlags;
  
} __TLR_PACKED_POST BOOTTOKEN_LICENSE_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_LICENSE_Ttag
{
  BOOTTOKEN_HEADER_T        tHeader;
  BOOTTOKEN_LICENSE_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_LICENSE_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_RAMSIZE_DATA_Ttag
{
  TLR_UINT32 ulRamSize;
  
} __TLR_PACKED_POST BOOTTOKEN_RAMSIZE_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_RAMSIZE_Ttag
{
  BOOTTOKEN_HEADER_T        tHeader;
  BOOTTOKEN_RAMSIZE_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_RAMSIZE_T;

#define BOOTTOKEN_HARDWARE_FLAGS_DEVICEDATA           0x00000001  /* Device data valid (Mfg,sDeviceClass, DeviceNr, SerialNr) */
#define BOOTTOKEN_HARDWARE_FLAGS_HWOPTIONS            0x00000002  /* Hardware options are valid                               */
#define BOOTTOKEN_HARDWARE_FLAGS_SLOTNUMBER           0x00000004  /* Slot number switch valid                                 */
#define BOOTTOKEN_HARDWARE_FLAGS_CUSTOM_MMIO_MAPPING  0x00000010  /* Custom MMIO mapping set up in 2nd Stage Loader           */
#define BOOTTOKEN_HARDWARE_FLAGS_HW_ASSEMBLY_FEATURES 0x00000020  /* HW assembly features available                           */
#define BOOTTOKEN_HARDWARE_FLAGS_SECMEM               0x80000000  /* Security Memory is available                             */

#define BOOTTOKEN_HARDWARE_BUSTYPE_PCI        1
#define BOOTTOKEN_HARDWARE_BUSTYPE_DPM        2
#define BOOTTOKEN_HARDWARE_BUSTYPE_ISA        3

typedef __TLR_PACKED_PRE struct BOOTTOKEN_HARDWARE_DATA_Ttag
{
  TLR_UINT32 ulFlags;
  TLR_UINT16 usManufacturer;
  TLR_UINT16 usProductionDate;
  TLR_UINT16 usDeviceClass;
  TLR_UINT8  bHwRevision;
  TLR_UINT8  bHwCompatibility;
  TLR_UINT32 ulDeviceNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT16 ausHwOptions[4]; 
  TLR_UINT8  bSlotNumber;
  TLR_UINT8  bBusType;
  TLR_UINT8  bHwAssemblyFeatures;
    
} __TLR_PACKED_POST BOOTTOKEN_HARDWARE_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_HARDWARE_Ttag
{
  BOOTTOKEN_HEADER_T         tHeader;
  BOOTTOKEN_HARDWARE_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_HARDWARE_T;

#define BOOTTOKEN_SFLASHPARAMS_ADRMODE_LINEAR             0 /* linear addressing */
#define BOOTTOKEN_SFLASHPARAMS_ADRMODE_PAGESIZE_BITSHIFT  1 /* bitshift derived from the pagesize */

#define BOOTTOKEN_SFLASHPARAMS_FEATURES_NONE              0
#define BOOTTOKEN_SFLASHPARAMS_FEATURES_WINBOND_QUADSPI   1

typedef __TLR_PACKED_PRE struct BOOTTOKEN_SFLASHPARAMS_DATA_Ttag
{
  TLR_UINT8   szName[16];              /* name of the flash, 0 terminated */
  TLR_UINT32  ulSize;                  /* size of the flash memory in bytes */
  TLR_UINT32  ulClock;                 /* maximum speed in kHz */
  TLR_UINT32  ulPageSize;              /* size of one page in bytes */
  TLR_UINT32  ulSectorPages;           /* size of one sector in pages */
  TLR_UINT8   bAdrMode;                /* addressing mode */
  TLR_UINT8   bReadOpcode;             /* opcode for 'continuous array read' command */
  TLR_UINT8   bReadOpcodeDCBytes;      /* don't care bytes after readOpcode and address */
  TLR_UINT8   bWriteEnableOpcode;      /* opcode for 'write enable' command, 0x00 means no write protect mechanism */
  TLR_UINT8   bErasePageOpcode;        /* opcode for 'erase page' */
  TLR_UINT8   bEraseSectorOpcode;      /* opcode for 'erase sector' */
  TLR_UINT8   bEraseChipCmdLen;        /* length of the 'erase chip' command, 0 means not available */
  TLR_UINT8   abEraseChipCmd[4];       /* command to erase the complete chip */
  TLR_UINT8   bPageProgOpcode;         /* opcode for 'page program (without buildin erase)' */
  TLR_UINT8   bBufferFill;             /* opcode for 'fill buffer with data' */
  TLR_UINT8   bBufferWriteOpcode;      /* opcode for 'write buffer to flash' */
  TLR_UINT8   bEraseAndPageProgOpcode; /* opcode for 'page program with buildin erase' */
  TLR_UINT8   bReadStatusOpcode;       /* opcode for 'read status register' */
  TLR_UINT8   bStatusReadyMask;        /* the bitmask indicating device busy */
  TLR_UINT8   bStatusReadyValue;       /* eor bitmask for device busy */
  TLR_UINT8   bInitCmd0_length;        /* length of the first init command in bytes */
  TLR_UINT8   abInitCmd0[3];           /* first command string to init the device */
  TLR_UINT8   bInitCmd1_length;        /* length of the second init command in bytes */
  TLR_UINT8   abInitCmd1[3];           /* second command string to init the device */
  TLR_UINT8   bIdLength;               /* length in bytes of the id_send, id_mask and id_magic fields */
  TLR_UINT8   abIdSend[9];             /* command string to request the id */
  TLR_UINT8   abIdMask[9];             /* mask for the device id. the data received from the id_send command will be anded with this field */
  TLR_UINT8   abIdMagic[9];            /* magic sequence of this device */
  TLR_UINT32  ulFeatures;              /* special features of this chip */

} __TLR_PACKED_POST BOOTTOKEN_SFLASHPARAMS_DATA_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_SFLASHPARAMS_Ttag
{
  BOOTTOKEN_HEADER_T             tHeader;
  BOOTTOKEN_SFLASHPARAMS_DATA_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_SFLASHPARAMS_T;

typedef __TLR_PACKED_PRE struct BOOTTOKEN_BSLINFO_Ttag
{
  BOOTTOKEN_HEADER_T       tHeader;
  RCX_FW_IDENTIFICATION_T  tData;
} __TLR_PACKED_POST BOOTTOKEN_BSLINFO_T;

#endif /*BOOTTOKENS_H_*/
