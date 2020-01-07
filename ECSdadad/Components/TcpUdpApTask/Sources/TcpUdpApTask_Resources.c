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
$Id: TcpUdpApTask_Resources.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_Resources.c
- Resources creation
- Resources initialisation
- Resources deinitialisation
**************************************************************************************/

#include "TcpUdpApTask_Functions.h"
#include "TcpUdpApTask_Public.h"
#include "TcpUdpApTask_TaskInfo.h"
#include "TLR_Includes.h"
#include "TcpUdpApTask_Resources.h"
#include "TlrTimer_Public.h"
#include "TLR_Results.h"

/**********************************************************************************//**
 Creates the resources of task via malloc() and memset() 0x00.
 \param[in]  ptInit  task initial data
 \param[out] pptRsc  pointer to task resources
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_TcpUdpApTask_Create( TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit,
                                             TCPUDPAPTASK_RSC_T** pptRsc )
{
  TLR_RESULT eRslt = TLR_S_OK;
  TCPUDPAPTASK_RSC_T*  ptRsc;
  *pptRsc = NULL;

  if( NULL == ptInit )
  {
    eRslt = TLR_E_INVALID_PARAMETER;
  }else
  {
    if( ptInit->ulTaskIdentifier != TCPUDPAPTASK_IDENTIFIER
        || ptInit->ulParamVersion != TCPUDPAPTASK_STARTUPPARAMETER_VERSION )
    {
      eRslt = TLR_E_INVALID_PARAMETER;
    }
  }

  if( eRslt == TLR_S_OK )
  {
    TLR_MEMALLOC( ptRsc, sizeof(*ptRsc) );
    if( NULL == ptRsc )
    {
      eRslt = TLR_E_OUTOFMEMORY;
    }
  }
  if( eRslt == TLR_S_OK )
  {
    TLR_MEMSET( ptRsc, 0x00, sizeof(*ptRsc) );
    *pptRsc = ptRsc;
  }
  return eRslt;
}

/**********************************************************************************//**
 Initializes the local task resources
 \param[in,out] ptRsc  pointer to task resources
 \param[in]     ptInit task initial data
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_TcpUdpApTask_InitLocal( TCPUDPAPTASK_RSC_T* ptRsc,
                                   TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit )
{
  TLR_RESULT eRslt = TLR_S_OK;

  TLR_TSK_GET_INSTANCE(ptRsc->tLoc.uTskInst);
  /** - Create task information by TLR_TSK_CREATE_INFO_FIELD */
  eRslt = TcpUdpApTaskInfo_Init( ptRsc );
  if(TLR_S_OK == eRslt)
  {
    /** - Create own process queue */
    eRslt = TLR_QUE_CREATE( "TCPAP_QUE",
                            TCPUDPAPTASK_QUEUE_MAX_ELEM,
                            &ptRsc->tLoc.hQue );
  }
  if(TLR_S_OK == eRslt)
  {
    /** - Create own resource pool for queue packets*/
    eRslt = TLR_POOL_CREATE( "TCPAP_PCK",
                             TCPUDPAPTASK_POOL_MAX_ELEM,
                             sizeof(TCPUDPAPTASK_PACKET_T),
                             &ptRsc->tLoc.hPool );
  }
  if(TLR_S_OK == eRslt)
  {
    /** - Setup cyclic packet for the Timer task */
    ptRsc->tLoc.tCycleEventPck.ulSrc = (TLR_UINT32)ptRsc->tLoc.hQue;
    ptRsc->tLoc.tCycleEventPck.ulCmd = TLR_CMD_CYCLE_EVENT_REQ;
    ptRsc->tLoc.tCycleEventPck.ulExt = TLR_PACKET_NOT_DELETE;
    ptRsc->tLoc.tCycleEventPck.ulId  = 0;

    eRslt = TlrTimerApplicationCreate( ptRsc->tLoc.hQue,
                                       TLR_TIMER_APPL_ONESHOT,
                                       1000/*Milliseconds*/,
                                       &ptRsc->tLoc.hCycleEvent);}

  if(TLR_S_OK == eRslt)
  {
    eRslt = TlrTimerApplicationInitPacket(ptRsc->tLoc.hCycleEvent, &ptRsc->tLoc.tCycleEventPck);
  }
  if(TLR_S_OK == eRslt)
  {
    eRslt = TlrTimerApplicationStart(ptRsc->tLoc.hCycleEvent,&ptRsc->tLoc.tCycleEventPck);
    ptRsc->tLoc.bTestSndData = 'A';
  }
  TaskInfo_SetInitResult( ptRsc, eRslt );
  return eRslt;
}

/**********************************************************************************//**
 Initializes the remote task resources
 \param[in,out] ptRsc  pointer to task resources
 \param[in]     ptInit task initial data
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_TcpUdpApTask_InitRemote( TCPUDPAPTASK_RSC_T* ptRsc,
                                    TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit )
{
  TLR_RESULT eRslt = TLR_S_OK;

  eRslt = TLR_TSK_IDENTIFY( TCP_TASK_NAME,                /* task name      */
                            ptRsc->tLoc.uTskInst,         /* task instance  */
                            &ptRsc->tRem.hTskTcpTask,     /* task handle    */
                            &ptRsc->tRem.uToknTcpTask,    /* task token     */
                            &ptRsc->tRem.uPrioTcpTask );  /* task priority  */

  if(TLR_S_OK == eRslt)
  {
    /** - Connect to queue of TCPIP stack */
    eRslt = TLR_QUE_IDENTIFY( EN_TCPUDP_PROCESS_QUEUE_NAME,
                              ptRsc->tLoc.uTskInst,
                              &ptRsc->tRem.tQueTcpTask );
  }

  if(TLR_S_OK == eRslt)
  {
    TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );  /* (tQueLink, _ulDestId) */
    TLS_QUE_LINK_SOURCE_SET( ptRsc->tLoc.tLnkSrc, ptRsc->tLoc.hQue, &ptRsc->tLoc );  /* (tQueSrc,hQue,_ulSrcId) */
  }

  TaskInfo_SetInitResult( ptRsc, eRslt );
  return eRslt;
}

/**********************************************************************************//**
 Deletes Task ressources
 \param[in,out] ptRsc  pointer to task resources
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_TcpUdpApTask_Delete( TCPUDPAPTASK_RSC_T* ptRsc )
{
  if(NULL != ptRsc)
  {
    if(NULL != ptRsc->tLoc.hPool)
    {
      /** - Deletes own Pool */
      TLR_POOL_DELETE(ptRsc->tLoc.hPool);
    }
    if(NULL != ptRsc->tLoc.hQue)
    {
      /** - Deletes own Queue */
      TLR_QUE_DELETE(ptRsc->tLoc.hQue);
    }
    /** - Deletes all task resources */
    TLR_MEMFREE(ptRsc);
  }
  return TLR_S_OK;
}
