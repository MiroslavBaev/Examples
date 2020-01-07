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
$Id: TcpUdpApTask_Functions.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_Functions.c
  Contains packet handler
**************************************************************************************/
#include "TcpUdpApTask_Functions.h"

#include "TcpUdpApTask_DiagStatus.h"
#include "TLR_Results.h"
#include "TlrTimer_Public.h"
#include "TcpUdpApCommands.h"

/**************************************************************************************
 * Does generic Packet handling by adding diagnosis information via DiagStatus
 * @param ptRsc[in, out] Resources of Task
 * @param pvPck[in] packet to send and releas memory if failed
 */
static void GenericPacketSending(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt = TLR_S_OK;
  eRslt = TLR_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask, pvPck, TLR_FINITE );
  if(TLR_S_OK == eRslt)
  {
    DiagStatusIncreaseCounterOfOutstandingPackets(ptRsc);
  }
  else
  {
    DiagStatusSaveInfoOfFailedPacket(ptRsc, ptRsc->tRem.tQueTcpTask, eRslt);
    eRslt = TLR_POOL_PACKET_RELEASE(ptRsc->tLoc.hPool, pvPck);
    if(TLR_S_OK != eRslt)
    {
      DiagStatusSaveInfoOfFailedPacket(ptRsc, ptRsc->tRem.tQueTcpTask, eRslt);
    }
  }
}



/**************************************************************************************
 * Builds a ECAT_SET_CONFIG_REQ packet and sends it to EtherCAT stack
 * \param ptRsc [in, out] Resources of Task
 *************************************************************************************/
void TcpUdpApTask_SendTcpipPacketIpCmdGetConfigReq(TCPUDPAPTASK_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  TCPIP_PACKET_IP_CMD_GET_CONFIG_REQ_T *ptSetConfigReq = NULL;

  eRslt = TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptSetConfigReq );
  if(TLR_S_OK == eRslt)
  {
    ptSetConfigReq->tHead.ulSrc    = ( TLR_UINT32 )ptRsc->tLoc.hQue;
    ptSetConfigReq->tHead.ulLen    = 0;
    ptSetConfigReq->tHead.ulCmd    = TCPIP_IP_CMD_GET_CONFIG_REQ;

    GenericPacketSending(ptRsc, ptSetConfigReq);
  }
  else
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTlrCmdCycleEventReq(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;
  TLR_PACKET_HEADER_T* ptCycleEventPck = (TLR_PACKET_HEADER_T*)pvPck;

  eRslt = TlrTimerApplicationReload( ptRsc->tLoc.hCycleEvent, 500/*MilliSeconds*/ );
  ptCycleEventPck->ulId += 1;

  TcpUdpApTask_SendTcpipPacketIpCmdGetConfigReq(ptRsc);
}

void TcpUdpApTask_HandleTcpipPacketIpCmdGetConfigCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_T* ptCnf = pvPck;
  TCPIP_CONFIG_T* ptPckData = (TCPIP_CONFIG_T*) &ptCnf->tData;
  TCPIP_CONFIG_T* ptTaskData = &ptRsc->tLoc.tTcpIpConfig;

  if( (TLR_S_OK             == ptCnf->tHead.ulSta)&&
      (sizeof(ptCnf->tData) == ptCnf->tHead.ulLen) )
  {
    /* Compare if config changed */
    if( 0 != memcmp(ptPckData, ptTaskData, sizeof(*ptTaskData)) )
    {
      *ptTaskData = *ptPckData;

      if(0 == ptRsc->tLoc.ulSocket) /**< If connection has not been opened (socket is still NULL) */
      {
        ApTcpUdpCmdOpenReq(ptRsc);
      }
    }
  }

  TLR_QUE_PACKETDONE(ptRsc->tLoc.hPool,
                     ptRsc->tLoc.hQue,
                     ptCnf);
}


void TcpUdpApTask_HandleTcpipTcpUdpCmdOpenCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;

  eRslt = ApTcpUdpCmdOpenCnf(ptRsc, pvPck);
  if(TLR_S_OK == eRslt)
  {
    eRslt = ApTcpCmdWaitConnectReq(ptRsc);
  }
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTcpipTcpCmdWaitConnectCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;

  eRslt = ApTcpCmdWaitConnectCnf(ptRsc, pvPck);

  if(TLR_E_TCP_ERR_CONN_CLOSED == eRslt ||
      TLR_E_TCP_ERR_CONN_RESET  == eRslt )
  {
    /* These error codes are expected therefore reopen connection to listen for clients again
     * open is done in confirmation of ApTcpUdpCmdCloseReq */
    eRslt = ApTcpUdpCmdCloseReq(ptRsc);
  }
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveInd(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;

  TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_T* ptInd = pvPck;

  eRslt = ApTcpUdpCmdReceiveInd(ptRsc, pvPck);
  if(TLR_S_OK == eRslt)
  {
    ApTcpCmdSendReq(ptRsc, ptInd->tHead.ulLen);
  }
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTcpipTcpSendCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;

  eRslt = ApTcpCmdSendCnf(ptRsc, pvPck);
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTcpipTcpUdpCmdReceiveStopInd(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;

  eRslt = ApTcpUdpCmdReceiveStopInd(ptRsc, pvPck);
  if(TLR_E_TCP_ERR_CONN_CLOSED == eRslt ||
     TLR_E_TCP_ERR_CONN_RESET  == eRslt)
  {
    /* These error codes are expected therefore reopen connection to listen for clients again
     * open is done in confirmation of ApTcpUdpCmdCloseReq */
    eRslt = ApTcpUdpCmdCloseReq(ptRsc);
  }
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

void TcpUdpApTask_HandleTcpipTcpUdpCmdCloseCnf(TCPUDPAPTASK_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt;
  eRslt = ApTcpUdpCmdCloseCnf(ptRsc, pvPck);
  if(TLR_S_OK == eRslt)
  {
    eRslt = ApTcpUdpCmdOpenReq(ptRsc);
  }
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}

/***************************************************************************//**
 Handles an unknown packet
 \param[in,out] ptRsc  task resources
 \param[in]     ptPck  packet
 \return TLR_S_OK if succeeded
*******************************************************************************/
TLR_RESULT TaskCommand_TcpUdpApTask_Unknown(TCPUDPAPTASK_RSC_T* ptRsc, TCPUDPAPTASK_PACKET_T* ptPck)
{
  /* return packet */
  if((ptPck->tHead.ulCmd & 0x00000001) == 0x00000000)
	  ptPck->tHead.ulSta = TLR_E_EXAMPLETASK2_INVALID_COMMAND;
  TLR_QUE_PACKETDONE(ptRsc->tLoc.hPool, ptRsc->tLoc.hQue, ptPck);
  return TLR_E_EXAMPLETASK2_INVALID_COMMAND;
}

