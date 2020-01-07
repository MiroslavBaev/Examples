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
$Id: TcpUdpApTask_Process.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_Process.c
  Delegates packets to their packet handler
**************************************************************************************/
#include "TcpUdpApTask_Process.h"

#include "TcpUdpApTask_Functions.h"

/** typedef to assign packet handler to specific command */
typedef struct{
  TLR_UINT32 ulCmd;
  void (*pfnPacketHandler)( TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck );
}COMMAND_HANDLER_T;


static void HandleEndProccessReq( TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck )
{
  ptRsc->tLoc.eTskState = TLR_TASK_STATE_CANCELED;
}

/** Lookup table which assigns Packet handler to specific command */
static COMMAND_HANDLER_T s_CmdHandlerTable[] =
{
  { TLR_CMD_CYCLE_EVENT_REQ,            &TcpUdpApTask_HandleTlrCmdCycleEventReq},
  { TCPIP_TCP_UDP_CMD_OPEN_CNF,         &TcpUdpApTask_HandleTcpipTcpUdpCmdOpenCnf},
  { TCPIP_TCP_CMD_WAIT_CONNECT_CNF,     &TcpUdpApTask_HandleTcpipTcpCmdWaitConnectCnf},
  { TCPIP_TCP_UDP_CMD_RECEIVE_IND,      &TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveInd},
  { TCPIP_TCP_CMD_SEND_CNF,             &TcpUdpApTask_HandleTcpipTcpSendCnf},
  { TCPIP_TCP_UDP_CMD_RECEIVE_STOP_IND, &TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveStopInd},
  { TCPIP_IP_CMD_GET_CONFIG_CNF,        &TcpUdpApTask_HandleTcpipPacketIpCmdGetConfigCnf },
  { TCPIP_TCP_UDP_CMD_CLOSE_CNF,        &TcpUdpApTask_HandleTcpipTcpUdpCmdCloseCnf},
  { EXAMPLETASK2_CMD_END_PROCESS_REQ,   &HandleEndProccessReq },
};



/***************************************************************************//**
- handles the task process
- wait for requests
- wait for confirmations
- wait for indications
- check task state
 @param[in,out] ptRsc  task resources
 @return TLR_S_OK if succeeded
********************************************************************************/
TLR_RESULT TaskProcess_TcpUdpApTask(TCPUDPAPTASK_RSC_T* ptRsc)
{
  TLR_RESULT  eRslt;
  TLR_HANDLE  hQue;
  TLR_UINT32  ulCurrCmd;
  TLR_UINT32  i;

  TCPUDPAPTASK_PACKET_T* ptPck;

  /* initialize */
  eRslt = TLR_S_OK;
  TLR_TRACE_1("TaskProcess_TcpUdpApTask start, eRslt = 0x%.8X\r\n", eRslt);
  ptRsc->tLoc.eTskState = TLR_TASK_STATE_RUNNING; /* startup process of task -> running */

  hQue  = ptRsc->tLoc.hQue; /**< shortcut for own queue */

  while( TLR_TASK_STATE_CANCELED != ptRsc->tLoc.eTskState )
  {
    eRslt = TLR_QUE_WAITFORPACKET(hQue, &ptPck, TLR_TIM_TIME_TO_TICK(TLR_INFINITE));
    if( TLR_S_OK == eRslt )
    {
      ulCurrCmd = ptPck->tHead.ulCmd;

      for( i=0; i<MAX_CNT(s_CmdHandlerTable); i++ )
      {
        if( s_CmdHandlerTable[i].ulCmd == ulCurrCmd )
        {
          s_CmdHandlerTable[i].pfnPacketHandler( ptRsc, ptPck );
          break;
        }
      }
      if( s_CmdHandlerTable[i].ulCmd != ulCurrCmd ) /* Command not found in lookup table */
      {
          TaskCommand_TcpUdpApTask_Unknown( ptRsc, ptPck );
      }
    }
  }
  TLR_TRACE_3( "TaskProcess_TcpUdpApTask end, eRslt = 0x%.8X, ulCntSend = %u, ulCntRecv = %u\r\n",
               eRslt,
               ptRsc->tLoc.ulCntSend,
               ptRsc->tLoc.ulCntRecv );
  return eRslt;
}
