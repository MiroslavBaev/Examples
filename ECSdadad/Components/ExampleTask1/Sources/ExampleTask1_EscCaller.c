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
$Id: ExampleTask1_EscCaller.c 1862 2016-01-27 10:56:55Z Ricky $:
 
Description:
 See doxygen
***********************************************************************************//**
  @file ExampleTask1_EscCaller.c
  Every function which works directly on EtherCAT HAL is implemented here.
**************************************************************************************/
#include "ExampleTask1_Resources.h"
#include "ExampleTask1_EscCaller.h"
#include "TLR_global_error.h"
#include "TLR_Diag.h"
#include <stddef.h>
#include <string.h>
#include "rX_Types.h" /* needed for EscRcx_Public.h */
#include "rX_ErrorCodes.h" /* needed for EscRcx_Public.h */
#include "EscRcx_Public.h"


void fnECSDemo_EcatSyncManCh2_clb( TLR_HANDLE hSM2,
                                   void* pvRsc )
{
  Esc_BufferPointer pRead;
  Esc_BufferPointer pWrite;
  uint16_t uLenRead;
  uint16_t uLenWrite;
  EXAMPLETASK1_RSC_T* ptRsc = pvRsc;
  TLR_HANDLE hSM3 = Esc_GetSyncManagerHandle( EscCaller_GetEscHandle(ptRsc), 3 );

  pRead = Esc_SmRequestBufferForReading(hSM2, &uLenRead);
  memcpy(ptRsc->tLoc.tEcsPd.aulOutData, pRead, uLenRead);
  Esc_SmReleaseBufferForReading(hSM2);

  pWrite = Esc_SmRequestBufferForWriting(hSM3, &uLenWrite);
  /** Simply copy outputs to inputs */
  memcpy(ptRsc->tLoc.tEcsPd.aulInData, ptRsc->tLoc.tEcsPd.aulOutData, MIN(uLenRead, uLenWrite));

  memcpy(pWrite, ptRsc->tLoc.tEcsPd.aulInData, uLenWrite);
  Esc_SmReleaseBufferForWriting(hSM3);
}

uint32_t EscCaller_Init(EXAMPLETASK1_RSC_T* ptRsc)
{
  uint32_t ulRslt = TLR_S_OK;
  ESC_CALLER_T* ptEscCaller = &ptRsc->tRem.tEscCaller;/**< only this pointer shall be used in this c module */
  TLR_HANDLE hSM2, hSM3;

  ptEscCaller->hEcatInterface = Esc_GetInterface();
  ulRslt = (ptEscCaller->hEcatInterface == NULL)? TLR_DIAG_STA_INIT_REMOTE_FAILED : TLR_S_OK;

  if( ulRslt == TLR_S_OK )
  {
    hSM2 = Esc_GetSyncManagerHandle( ptEscCaller->hEcatInterface, 2 );
    ulRslt = (hSM2 == NULL)? TLR_DIAG_STA_INIT_REMOTE_FAILED : TLR_S_OK;
  }
  if( ulRslt == TLR_S_OK )
  {
    hSM3 = Esc_GetSyncManagerHandle( ptEscCaller->hEcatInterface, 3 );
    ulRslt = (hSM3 == NULL)? TLR_DIAG_STA_INIT_REMOTE_FAILED : TLR_S_OK;
  }
  if( ulRslt == TLR_S_OK )
  {
    /* SYNC Manager interrupt initialization */
    Esc_SetupInterrupt( ptEscCaller->hEcatInterface, ESC_INT_SYNCMAN_CH_2, fnECSDemo_EcatSyncManCh2_clb, ptRsc );
    Esc_EnableIntSource( ptEscCaller->hEcatInterface, ESC_INT_SOURCE_SYNCMAN_CH_2 );
    /* SYNC Manager disable */
    Esc_SetSyncManDisByAl( hSM2, true );
    Esc_SetSyncManDisByAl( hSM3, true );
  }
  return ulRslt;
}
