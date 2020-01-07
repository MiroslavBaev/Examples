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
$Id: ExampleTask1_Process.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Process.c
  Delegates packets to their packet handler
**************************************************************************************/
#include "ExampleTask1_Process.h"
#include "ExampleTask1_Functions.h"
#include "EcsV4_Public.h"
#include "OdV3_Public.h"

/** typedef to assign packet handler to specific command */
typedef struct{
  TLR_UINT32 ulCmd;
  void (*pfnPacketHandler)( EXAMPLETASK1_RSC_T* ptRsc, void* pvPck );
}COMMAND_HANDLER_T;


static void GenericPacketHandling( EXAMPLETASK1_RSC_T* ptRsc, void* pvPck )
{
  EXAMPLETASK1_PACKET_T* ptPck = pvPck;/*currently used for debugging purposes */
  TLS_QUE_PACKETDONE( ptRsc->tLoc.hPool, ptRsc->tLoc.hQue, ptPck );
}

static void HandleEndProccessReq( EXAMPLETASK1_RSC_T* ptRsc, void* pvPck )
{
  ptRsc->tLoc.eTskState = TLR_TASK_STATE_CANCELED;
}

/** Lookup table which assigns Packet handler to specific command */
static COMMAND_HANDLER_T s_CmdHandlerTable[] =
{
  { RCX_REGISTER_APP_CNF,             &ExampleTask1_HandleRcxRegisterAppCnf },
  { ECAT_SET_CONFIG_CNF,              &ExampleTask1_HandleEcatSetConfigCnf },
  { RCX_CHANNEL_INIT_CNF,             &ExampleTask1_HandleRcxChannelInitCnf },

  /** Packets which trigger next state of SiiProvider_SiiCreationFsm */
  { ECAT_ESM_SII_WRITE_CNF,           &ExampleTask1_HandleEcatEsmSiiWriteCnf },
  { ECAT_DPM_SET_STATION_ALIAS_CNF,   &ExampleTask1_HandleEcatDpmSetStationAliasCnf },
  { ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF, &ExampleTask1_HandleEcatEsmRegisterForSiiWriteIndicationsCnf },

  { ODV3_CREATE_OBJECT_CNF,           &ExampleTask1_HandleOdv3CreateObjectCnf },
  { ODV3_CREATE_SUBOBJECT_CNF,        &ExampleTask1_HandleOdv3CreateSubObjectCnf },

  { RCX_START_STOP_COMM_CNF,          &ExampleTask1_HandleRcxStartStopCommCnf },

  { ECAT_ESM_SII_WRITE_IND,           &ExampleTask1_HandleEcatEsmSiiWriteInd },
  { ECAT_ESM_ALSTATUS_CHANGED_IND,    &GenericPacketHandling },
  { ODV3_READ_OBJECT_IND,             &ExampleTask1_HandleOdv3ReadObjectInd },
  { ODV3_WRITE_OBJECT_IND,            &GenericPacketHandling },
  { EXAMPLETASK1_CMD_END_PROCESS_REQ, &HandleEndProccessReq },
};



/**********************************************************************************//**
- handles the task process
- wait for requests
- wait for confirmations
- wait for indications
- check task state
 @param[in,out] ptRsc  task resources
 @return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskProcess_ExampleTask1(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT  eRslt;
  TLR_HANDLE  hQue;
  TLR_UINT32  ulCurrCmd;
  TLR_UINT32  i;

  EXAMPLETASK1_PACKET_T* ptPck;

  /* initialize */
  eRslt = TLR_S_OK;
  TLR_TRACE_1("TaskProcess_ExampleTask1 start, eRslt = 0x%.8X\r\n", eRslt);
  ptRsc->tLoc.eTskState = TLR_TASK_STATE_RUNNING; /* startup process of task -> running */

  hQue  = ptRsc->tLoc.hQue; /**< shortcut for own queue */

  ExampleTask1_SendRcxRegisterAppReq(ptRsc);

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
          TaskCommand_ExampleTask1_Unknown( ptRsc, ptPck );
      }
    }
  }
  TLR_TRACE_3( "TaskProcess_ExampleTask1 end, eRslt = 0x%.8X, ulCntSend = %u, ulCntRecv = %u\r\n",
               eRslt,
               ptRsc->tLoc.ulCntSend,
               ptRsc->tLoc.ulCntRecv );
  return eRslt;
}
