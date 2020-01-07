/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApTask_Body.h 1328 2015-09-17 13:06:32Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TCPUDPAPTASK_Body.h
  Prototypes for Task startup and shutdown
**************************************************************************************/
#ifndef TCPUDPAPTASK_BODY_H_
#define TCPUDPAPTASK_BODY_H_

#include "TLR_Includes.h"

void TaskEnter_TcpUdpApTask( void* pvInit );

void TaskLeave_TcpUdpApTask(void* pvRsc);

#endif /* TCPUDPAPTASK_BODY_H_ */
