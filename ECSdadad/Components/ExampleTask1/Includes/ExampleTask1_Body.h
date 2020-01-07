/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_Body.h 1617 2015-11-23 14:06:45Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Body.h
  Prototypes for Task startup and shutdown
**************************************************************************************/
#ifndef EXAMPLETASK1_BODY_H_
#define EXAMPLETASK1_BODY_H_

#include "TLR_Includes.h"

void TaskEnter_ExampleTask1( void* pvInit );

TLR_RESULT TaskLeave_ExampleTask1( void* pvTskRsc,
                                   void* pvLeave);

#endif /* EXAMPLETASK1_BODY_H_ */
