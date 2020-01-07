/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
  $Id: TcpUdpApTask_Functions.h 1328 2015-09-17 13:06:32Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_Functions.h
**************************************************************************************/
#ifndef TCPUDPAPTASK_FUNCTIONS_H_
#define TCPUDPAPTASK_FUNCTIONS_H_

#include "TcpUdpApTask_Public.h"
#include "TcpUdpApTask_Resources.h"
#include "TcpipTcpTask_Public.h"

/**********************************************************************************//**
 * Unification of every possible packet
 *************************************************************************************/
typedef union TCPUDPAPTASK_PACKETtag
{
  TLR_PACKET_HEADER_T                  tHead;
  TCPIP_PACKET_IP_CMD_GET_CONFIG_REQ_T tTcpipPacketIpCmdGetConfigReq;
  TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_T tTcpipPacketIpCmdGetConfigCnf;
}TCPUDPAPTASK_PACKET_T;

void TcpUdpApTask_HandleTlrCmdCycleEventReq(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);

void TcpUdpApTask_SendTcpipPacketIpCmdGetConfigReq(TCPUDPAPTASK_RSC_T* ptRsc);
void TcpUdpApTask_HandleTcpipPacketIpCmdGetConfigCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);

void TcpUdpApTask_HandleTcpipTcpUdpCmdOpenCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);
void TcpUdpApTask_HandleTcpipTcpCmdWaitConnectCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);

void TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveInd(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);
void TcpUdpApTask_HandleTcpipTcpSendCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);

void TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveStopInd(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);
void TcpUdpApTask_HandleTcpipTcpUdpCmdCloseCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck);

TLR_RESULT TaskCommand_TcpUdpApTask_Unknown(TCPUDPAPTASK_RSC_T* ptRsc, TCPUDPAPTASK_PACKET_T* ptPck);

#endif /* TCPUDPAPTASK_FUNCTIONS_H_ */
