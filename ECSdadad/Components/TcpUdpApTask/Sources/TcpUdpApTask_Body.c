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
$Id: TcpUdpApTask_Body.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TCPUDPAPTASK_Body.c
- Task entry point
- Task leave point
**************************************************************************************/

#include "TcpUdpApTask_Body.h"

#include "TcpUdpApTask_Process.h"
#include "TcpUdpApTask_Resources.h"

/**********************************************************************************//**
 Changes the task state to force a friendly shutdown of task
 \param[in,out] pvRsc    Pointer to resources of task
 \param[in]     pvLeave  Pointer to data defined by installing leave callback
 \return TLR_S_OK if succeeded
**************************************************************************************/
void TaskLeave_TcpUdpApTask(void* pvRsc)
{
  TCPUDPAPTASK_RSC_T*  ptRsc;

  TLR_TRACE_1("TaskLeave_TcpUdpApTask, pvRsc = 0x%.8X\r\n", pvRsc);

  ptRsc = (TCPUDPAPTASK_RSC_T*)pvRsc;           /* get task resources         */

  /* send packet to own task, shutdown task friendly */
  ptRsc->tLoc.tLeavePckt.ulCmd = (ULONG)EXAMPLETASK2_CMD_END_PROCESS_REQ;
  ptRsc->tLoc.tLeavePckt.ulExt = TLR_PACKET_NOT_DELETE;
  TLR_QUE_SENDPACKET_FIFO_INTERN(ptRsc->tLoc.hQue,
                                 &ptRsc->tLoc.tLeavePckt,
                                 TLR_TIM_TIME_TO_TICK(100));
}

/**********************************************************************************//**
 Task entry point.
 \param[in] pvInit Pointer to initial data of task given in Config*.c file
                   via RX_STATIC_TASK_T.ulInp
**************************************************************************************/
void TaskEnter_TcpUdpApTask(void* pvInit)
{
  TLR_RESULT  eRslt;
  TCPUDPAPTASK_RSC_T*  ptRsc;
  TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit = NULL != pvInit ? *(TCPUDPAPTASK_STARTUPPARAMETER_T**)pvInit : NULL;

  /** - Initialize local resources. */
  eRslt = TaskResource_TcpUdpApTask_Create(ptInit, &ptRsc);

  if(TLR_S_OK == eRslt)
  {
    eRslt = TaskResource_TcpUdpApTask_InitLocal(ptRsc, ptInit);
  }
  TLR_TSK_INIT_DONE(ptRsc, eRslt);

  /** - Initialize remote resources. */
  if(TLR_S_OK == eRslt)
  {
    eRslt = TaskResource_TcpUdpApTask_InitRemote(ptRsc, ptInit);
  }
  TLR_TSK_SET_STATE(eRslt);

  /** - Set leave callback function of task for friendly shutdown. */
  if(TLR_S_OK == eRslt)
  {
    eRslt = TLR_TSK_SET_LEAVE_CBF( TaskLeave_TcpUdpApTask,
                                   NULL,
                                   &ptRsc->tLoc.hLeaveHook );
  }

  /** - Start the process. */
  if(TLR_S_OK == eRslt)
  {
    eRslt = TaskProcess_TcpUdpApTask(ptRsc);
  }

  /** - Delete task resources and define the end of task (exit). */
  TaskResource_TcpUdpApTask_Delete(ptRsc);
  TLR_TSK_EXIT_DONE(eRslt);
}
