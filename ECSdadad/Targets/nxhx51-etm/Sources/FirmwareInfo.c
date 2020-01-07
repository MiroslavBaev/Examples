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
$Id: FirmwareInfo.c 50855 2015-01-16 07:19:50Z mark $

Description:
  This file contains the structure of firmware identification

**************************************************************************************/
#include "rX_Includes.h"

#define TARGET_FIRMWARE_NAME                APPNAME
#define TARGET_FIRMWARE_NAME_LEN            (sizeof(APPNAME)-1)

const NETX_FW_IDENTIFICATION tFirmwareIdentification =
{
  .tFwVersion.usMajor    = VERSION_MAJOR,
  .tFwVersion.usMinor    = VERSION_MINOR,
  .tFwVersion.usBuild    = VERSION_BUILD,
  .tFwVersion.usRevision = VERSION_REVISION,

  .tFwName.bNameLength   = TARGET_FIRMWARE_NAME_LEN,
  .tFwName.abName        = TARGET_FIRMWARE_NAME,

  .tFwDate.usYear        = BUILDSTAMP_BUILD_DATE_YEAR,
  .tFwDate.bMonth        = BUILDSTAMP_BUILD_DATE_MONTH,
  .tFwDate.bDay          = BUILDSTAMP_BUILD_DATE_DAY,
};
