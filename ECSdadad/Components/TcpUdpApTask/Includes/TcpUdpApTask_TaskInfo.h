/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApTask_TaskInfo.h 1328 2015-09-17 13:06:32Z Ricky $:
 
Description:
 See doxygen 
***************************************************************************************
  \file TcpUdpApTask_TaskInfo.h
**************************************************************************************/
#ifndef TCPUDPAPTASK_TASKINFO_H_
#define TCPUDPAPTASK_TASKINFO_H_

#include "TcpUdpApTask_Resources.h"

TLR_RESULT TcpUdpApTaskInfo_Init( TCPUDPAPTASK_RSC_T* ptRsc );

static inline void TaskInfo_SetInitResult( TCPUDPAPTASK_RSC_T* ptRsc, TLR_RESULT eRslt )
{
  TLR_DIA_TASK_INFO_T* ptTaskInfo = &ptRsc->tTaskInfo; /**< only work with this pointer in this module! */
  ptTaskInfo->eInitRslt = eRslt;
}

#endif /* TCPUDPAPTASK_TASKINFO_H_ */
