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
$Id: ExampleTask1_Resources.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Resources.c
- Resources creation
- Resources initialisation
- Resources deinitialisation
*************************************************************************************/

#include "TLR_Includes.h"
#include "ExampleTask1_Public.h"
#include "ExampleTask1_Functions.h"
#include "ExampleTask1_Resources.h"
#include "ExampleTask1_TaskInfo.h"
#include "ExampleTask1_EscCaller.h"
#include "ExampleTask1_ProcessData.h"
#include "ExampleTask1_ObjectDictionary.h"
#include "ExampleTask1_SiiProvider.h"

/**********************************************************************************//**
 Creates the resources of task via malloc() and memset() 0x00.
 \param[in]  ptInit  task initial data
 \param[out] pptRsc  pointer to task resources
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_ExampleTask1_Create( EXAMPLETASK1_STARTUPPARAMETER_T* ptInit,
                                             EXAMPLETASK1_RSC_T** pptRsc )
{
  TLR_RESULT eRslt = TLR_S_OK;
  EXAMPLETASK1_RSC_T*  ptRsc;
  *pptRsc = NULL;

  if( NULL == ptInit )
  {
    eRslt = TLR_E_INVALID_PARAMETER;
  }else
  {
    if( ptInit->ulTaskIdentifier != EXAMPLETASK1_IDENTIFIER
        || ptInit->ulParamVersion != EXAMPLETASK1_STARTUPPARAMETER_VERSION3 )
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
    ptRsc->tLoc.ptStartup = ptInit;
  }
  return eRslt;
}

/**********************************************************************************//**
- Initializes the local task resources
- Creates own Queue
- Creates own Pool
 \param[in,out] ptRsc  pointer to task resources
 \param[in]     ptInit task initial data
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_ExampleTask1_InitLocal( EXAMPLETASK1_RSC_T* ptRsc,
                                                EXAMPLETASK1_STARTUPPARAMETER_T* ptInit )
{
  TLR_RESULT eRslt = TLR_S_OK;
  ECS_STACK_T* ptStack;

  TLR_TSK_GET_INSTANCE(ptRsc->tLoc.uTskInst);

  eRslt = TaskInfo_Init( ptRsc );
  if(TLR_S_OK == eRslt)
  {
    /** Create process queue */
    eRslt = TLR_QUE_CREATE( "TASK1_QUE",
                          EXAMPLETASK1_QUEUE_MAX_ELEM,
                          &ptRsc->tLoc.hQue );
  }
  if(TLR_S_OK == eRslt)
  {
	  /** Create resource pool for queue packets*/
    eRslt = TLR_POOL_CREATE( "TASK1_PCK",
                             EXAMPLETASK1_POOL_MAX_ELEM,
                             sizeof(EXAMPLETASK1_PACKET_T),
                             &ptRsc->tLoc.hPool );
  }
  if(TLR_S_OK == eRslt)
  {
    eRslt = Ecs_StackInitialize( ptInit->ptEcsStackParameters, &ptStack );
  }
  if(TLR_S_OK == eRslt)
  {
    Ecs_Stack_EnableDpmStyleHandling( ptStack, ptRsc->tLoc.hQue );
    eRslt = ProcessDataInit(ptRsc,
                            ECS_PROCESS_DATA_MAX_OUTPUT_SIZE,
                            ECS_PROCESS_DATA_MAX_INPUT_SIZE);
  }
  if(TLR_S_OK == eRslt)
  {
    eRslt = ObjectDictionary_Init(ptRsc);
  }
  if(TLR_S_OK == eRslt)
  {
    eRslt = SiiProvider_Init(ptRsc,
                             ptRsc->tLoc.ptStartup->pabSiiImage,
                             ptRsc->tLoc.ptStartup->ulSizeOfSiiImage);
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
TLR_RESULT TaskResource_ExampleTask1_InitRemote( EXAMPLETASK1_RSC_T* ptRsc,
                                                 EXAMPLETASK1_STARTUPPARAMETER_T* ptInit )
{
  TLR_RESULT eRslt = TLR_S_OK;

  eRslt = EscCaller_Init( ptRsc );
  if(eRslt == TLR_S_OK)
  {
    eRslt = TLR_QUE_IDENTIFY( ECAT_ESM_PROCESS_QUEUE_NAME,
                              ptRsc->tLoc.uTskInst,
                              &ptRsc->tRem.hQueEsm );
  }

  TaskInfo_SetInitResult( ptRsc, eRslt );
  return eRslt;
}

/**********************************************************************************//**
- Deletes all task resources
- Deletes own Queue
- Deletes own Pool
 \param[in,out] ptRsc  pointer to task resources
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskResource_ExampleTask1_Delete( EXAMPLETASK1_RSC_T* ptRsc )
{
  if(NULL != ptRsc)
  {
    if(NULL != ptRsc->tLoc.hPool)
    {
      TLR_POOL_DELETE(ptRsc->tLoc.hPool);
    }
    if(NULL != ptRsc->tLoc.hQue)
    {
      TLR_QUE_DELETE(ptRsc->tLoc.hQue);
    }
    TLR_MEMFREE(ptRsc);
  }
  return TLR_S_OK;
}
