/**********************************************************************************//**
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided  together with this
  project!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/
/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: fileheader.c 50855 2015-01-16 07:19:50Z mark $

Description:
  This file contains fileheader structure

**************************************************************************************/

#include "rX_Includes.h" /* Standard Includes */
#include "HilFileHeaderV3.h"


/* Symbols defined in the linker control file (*.ld) are provided in the form of addresses.            */
/* Use (<cast>) &<symbol> to retrieve the associated value in an integer initialization statement.     */

/* The .fileheader section is the first section copied into the linker output file.                    */
/* Please note that the variable g_tFileHeader does not include the Default Header portion (64 bytes). */
extern const unsigned char _fileheader_start;
extern const unsigned char _fileheader_end;
extern const unsigned char _fileheader_size;
extern const unsigned char _fileheader_offset;

/* The .modulestart section contains the copy code needed after downloading into a target via PCI/DPM. */
/* The .sec0 and .data sections make up the executable code and (initialized) data.                    */
extern const unsigned char _filedata_start;
extern const unsigned char _filedata_end;
extern const unsigned char _filedata_size;
extern const unsigned char _filedata_offset;

/* The .taglist section is used for reserving space for tagged extensions of the firmware header.      */
/* This must be the first section following the sections copied into the linker output file.           */
/* It is therefore the first NOLOAD section.                                                           */
/* The tag list data is optional and can be added by the bootblocker application after the build.      */
extern const unsigned char _taglist_start;
extern const unsigned char _taglist_end;
extern const unsigned char _taglist_size;
extern const unsigned char _taglist_offset;
extern const unsigned char _taglist_size_max;

/* Considering the Default Header, _file_size is defined as (_filedata_end - _fileheader_start + 64).  */
extern const unsigned char _file_size;


const HIL_FILE_BASIC_HEADER_V3_0 g_tFileHeader =
{
  /* Common Header substructure */
  .tCommonHeader.ulHeaderVersion       = HIL_VERSION_COMMON_HEADER_3_0,
  .tCommonHeader.ulHeaderLength        = sizeof (g_tFileHeader) + sizeof (HIL_FILE_BOOT_HEADER_V1_0),
  .tCommonHeader.ulDataSize            = (unsigned long) &_filedata_size,
  .tCommonHeader.ulDataStartOffset     = sizeof (g_tFileHeader) + sizeof (HIL_FILE_DEFAULT_HEADER_V1_0),
  .tCommonHeader.bNumModuleInfos       = 6,
  .tCommonHeader.bReserved             = 0,
  .tCommonHeader.usReserved            = 0,
  .tCommonHeader.aulMD5                = {0, 0, 0, 0},
  .tCommonHeader.ulTagListSize         = (unsigned long) &_taglist_size,
  .tCommonHeader.ulTagListOffset       = (unsigned long) &_taglist_offset,
  .tCommonHeader.ulTagListSizeMax      = (unsigned long) &_taglist_size_max,
  .tCommonHeader.aulReserved           = {0, 0, 0},
  .tCommonHeader.ulHeaderCRC32         = 0,  // must be calculated by Bootblocker (Boot Header + Common Header + Device Info + Module Infos)
  /* Device Info substructure */
  .tDeviceInfo.ulStructVersion         = HIL_VERSION_DEVICE_INFO_V1_0,
  .tDeviceInfo.usManufacturer          = RCX_MANUFACTURER_HILSCHER_GMBH,
  .tDeviceInfo.usDeviceClass           = TARGET_DEVICE_CLASS,
  .tDeviceInfo.bHwCompatibility        = 0,
  .tDeviceInfo.bChipType               = TARGET_CHIP_TYPE,
  .tDeviceInfo.usReserved              = 0,
  .tDeviceInfo.ausHwOptions            = {RCX_HW_ASSEMBLY_UNDEFINED,
                                          RCX_HW_ASSEMBLY_UNDEFINED,
                                          RCX_HW_ASSEMBLY_UNDEFINED,
                                          RCX_HW_ASSEMBLY_UNDEFINED
                                          },
  .tDeviceInfo.ulLicenseFlags1         = 0,
  .tDeviceInfo.ulLicenseFlags2         = 0,
  .tDeviceInfo.usNetXLicenseID         = 0,
  .tDeviceInfo.usNetXLicenseFlags      = 0,
  .tDeviceInfo.ausFwVersion            = {VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD, VERSION_REVISION},
  .tDeviceInfo.ulFwNumber              = 0,
  .tDeviceInfo.ulDeviceNumber          = 0,
  .tDeviceInfo.ulSerialNumber          = 0,
  .tDeviceInfo.aulReserved             = {0, 0, 0},

  /* Module Info substructures  is not used in this single-stack firmware */
  .tModuleInfo[0]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  .tModuleInfo[1]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  .tModuleInfo[2]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  .tModuleInfo[3]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  .tModuleInfo[4]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  .tModuleInfo[5]                      = {0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
};
