/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApTask_StartupParameter.h 1327 2015-09-16 17:04:24Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TCPUDPAPTASK_StartupParameter.h
- Prototypes for Task startup and shutdown
**************************************************************************************/

#ifndef TCPUDPAPTASK_STARTUPPARAMETER_H_
#define TCPUDPAPTASK_STARTUPPARAMETER_H_

#include "TLR_Includes.h"

#define TCPUDPAPTASK_STARTUPPARAMETER_VERSION  ( 1 )
#define TCPUDPAPTASK_IDENTIFIER                ( TLR_TASK_USER_AREA + 202 )
#define TCPUDPAPTASK_NAME                      "TCPUDP_AP"
#define TCPUDPAPTASK_STACKSIZE                 ( 4096 )

/** Startup parameter given to task at startup (TaskEnter_TcpUdpApTask()) by config file */
typedef struct TCPUDPAPTASK_STARTUPPARAMETER_Ttag
{
  TLR_TASK_PARAMETERHEADER;
} TCPUDPAPTASK_STARTUPPARAMETER_T;

#endif /* TCPUDPAPTASK_STARTUPPARAMETER_H_ */
