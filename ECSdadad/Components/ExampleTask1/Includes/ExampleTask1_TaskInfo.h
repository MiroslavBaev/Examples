/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_TaskInfo.h 1617 2015-11-23 14:06:45Z Ricky $:
 
Description:
 See doxygen 
***************************************************************************************
  \file ExampleTask1_TaskInfo.h
**************************************************************************************/
#ifndef EXAMPLETASK1_TASKINFO_H_
#define EXAMPLETASK1_TASKINFO_H_

#include "ExampleTask1_Resources.h"

TLR_RESULT TaskInfo_Init( EXAMPLETASK1_RSC_T* ptRsc );

static inline void TaskInfo_SetInitResult( EXAMPLETASK1_RSC_T* ptRsc, TLR_RESULT eRslt )
{
  TLR_DIA_TASK_INFO_T* ptTaskInfo = &ptRsc->tTaskInfo; /**< only work with this pointer in this module! */
  ptTaskInfo->eInitRslt = eRslt;
}

#endif /* EXAMPLETASK1_TASKINFO_H_ */
