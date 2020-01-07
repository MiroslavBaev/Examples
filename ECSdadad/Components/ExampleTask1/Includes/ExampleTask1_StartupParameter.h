/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_StartupParameter.h 1715 2015-12-18 10:59:58Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_StartupParameter.h
  Typedef for task startup parameters is defined in this module.
**************************************************************************************/

#ifndef EXAMPLETASK1_STARTUPPARAMETER_H_
#define EXAMPLETASK1_STARTUPPARAMETER_H_

#include "TLR_Includes.h"
#include "EcsV4_Functionlist.h"
#include <stdbool.h>

/** Define for testing if parameters arrive into task */
#define EXAMPLETASK1_STARTUPPARAMETER_TEST ( 0x12345678 )
#define EXAMPLETASK1_IDENTIFIER    ( TLR_TASK_USER_AREA + 200 )
#define EXAMPLETASK1_STARTUPPARAMETER_VERSION3  ( 3 )

/** Startup parameter which is given to TaskEnter_ExampleTask1() */
typedef struct EXAMPLETASK1_STARTUPPARAMETER_Ttag
{
  TLR_TASK_PARAMETERHEADER;
  uint32_t ulVendorId;
  uint32_t ulRevisionNumber;
  uint32_t ulProductCode;
  const ECS_STACK_PARAMETERS_T* const ptEcsStackParameters;
  bool     fUseEoe;
  uint8_t* pabSiiImage;
  uint32_t ulSizeOfSiiImage;
} EXAMPLETASK1_STARTUPPARAMETER_T;

#endif /* EXAMPLETASK1_STARTUPPARAMETER_H_ */
