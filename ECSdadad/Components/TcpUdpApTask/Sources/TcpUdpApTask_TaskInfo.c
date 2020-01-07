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
$Id: TcpUdpApTask_TaskInfo.c 1862 2016-01-27 10:56:55Z Ricky $:
 
Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_TaskInfo.c
  Creating of Task information into ptRsc->tTaskInfo happens in this module
**************************************************************************************/
#include "TcpUdpApTask_TaskInfo.h"

#include "TcpUdpApTask_Functions.h"

/**********************************************************************************//**
  Fills ptRsc->tTaskInfo with task information
  \param[in,out] ptRsc Pointer to task ressources
  \return TLR_S_OK if successful
**************************************************************************************/
TLR_RESULT TcpUdpApTaskInfo_Init( TCPUDPAPTASK_RSC_T* ptRsc )
{
  TLR_RESULT eRslt;
  TLR_DIA_TASK_INFO_T* ptTaskInfo = &ptRsc->tTaskInfo;

  ptTaskInfo->ulTskIdentifier          = TCPUDPAPTASK_IDENTIFIER;
  ptTaskInfo->usTskMajorVersion        = VERSION_MAJOR;
  ptTaskInfo->usTskMinorVersion        = VERSION_MINOR;
  ptTaskInfo->ulMaximumPacketSize      = sizeof(TCPUDPAPTASK_PACKET_T);
  ptTaskInfo->ulDefaultQue             = (TLR_UINT32)ptRsc->tLoc.hQue;
  ptTaskInfo->tTaskUid.usMajorVersion  = 1;
  ptTaskInfo->tTaskUid.usTaskType      = TLR_TASK_UID_TASK_TYPE_USER;
  ptTaskInfo->tTaskUid.ulProtocolType  = 1;
  ptTaskInfo->tTaskUid.ulLayerLevel    = 0;
  ptTaskInfo->tTaskUid.ulLayerSubTask  = 0;
  ptTaskInfo->pvRsc                    = (TLR_UINT32)ptRsc;

  eRslt = TLR_TSK_CREATE_INFO_FIELD( ptRsc->tLoc.hInformationField,
                                     (TLR_UINT)ptTaskInfo,
                                     sizeof(*ptTaskInfo) );
  if( eRslt != TLR_S_OK )
  {
    eRslt = TLR_DIAG_STA_INFO_FIELD_ZERO_CREATE_FAILED;
  }
  return eRslt;
}
