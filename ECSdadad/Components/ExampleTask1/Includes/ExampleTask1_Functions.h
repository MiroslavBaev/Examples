/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
  $Id: ExampleTask1_Functions.h 1760 2016-01-14 15:27:08Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Functions.h
**************************************************************************************/
#ifndef EXAMPLETASK1_FUNCTIONS_H_
#define EXAMPLETASK1_FUNCTIONS_H_

#include "ExampleTask1_Resources.h"
#include "ExampleTask1_Public.h"
#include "OdV3_Public.h"

/** Unification of every possible packet *********************************************/
typedef union EXAMPLETASK1_PACKETtag
{
  TLR_PACKET_HEADER_T         tHead;
  ECAT_SET_CONFIG_REQ_T       tEcatSetConfigReq;
  RCX_CHANNEL_INIT_REQ_T      tRcxChannelInitReq;
  ECAT_ESM_SII_WRITE_REQ_T    tEcatEsmSiiWriteReq;
  ODV3_CREATE_OBJECT_REQ_T    tOdv3CreateObjectReq;
  ODV3_CREATE_SUBOBJECT_REQ_T tOdv3CreateSubobjectReq;
  RCX_REGISTER_APP_REQ_T      tRcxRegisterAppReq;
  RCX_START_STOP_COMM_REQ_T   tRcXStartStopCommReq;
}EXAMPLETASK1_PACKET_T;

void ExampleTask1_SendRcxRegisterAppReq(EXAMPLETASK1_RSC_T* ptRsc);
void ExampleTask1_HandleRcxRegisterAppCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

void ExampleTask1_SendEcatSetConfigReq(EXAMPLETASK1_RSC_T* ptRsc);
void ExampleTask1_HandleEcatSetConfigCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

void ExampleTask1_SendRcxChannelInitReq(EXAMPLETASK1_RSC_T* ptRsc);
void ExampleTask1_HandleRcxChannelInitCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

/* SiiProvider_SiiCreationFsm() sends ECAT_ESM_SII_WRITE_REQ, ECAT_DPM_SET_STATION_ALIAS_REQ and ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ*/
void ExampleTask1_HandleEcatEsmSiiWriteCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);
void ExampleTask1_HandleEcatDpmSetStationAliasCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);
void ExampleTask1_HandleEcatEsmRegisterForSiiWriteIndicationsCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

/* ObjectDictionary_OdCreationFsm() sends ODV3_CREATE_OBJECT_REQ and ODV3_CREATE_SUBOBJECT_REQ */
void ExampleTask1_HandleOdv3CreateObjectCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);
void ExampleTask1_HandleOdv3CreateSubObjectCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

void ExampleTask1_HandleEcatEsmSiiWriteInd(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);
void ExampleTask1_HandleOdv3ReadObjectInd(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

void ExampleTask1_SendRcxStartStopCommReq(EXAMPLETASK1_RSC_T* ptRsc);
void ExampleTask1_HandleRcxStartStopCommCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);

TLR_RESULT TaskCommand_ExampleTask1_Unknown(EXAMPLETASK1_RSC_T* ptRsc, EXAMPLETASK1_PACKET_T* ptPck);

void GenericPacketSending(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck);
#endif /* EXAMPLETASK1_FUNCTIONS_H_ */
