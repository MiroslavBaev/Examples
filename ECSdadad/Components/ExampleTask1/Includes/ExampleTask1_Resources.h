/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_Resources.h 1711 2015-12-17 12:57:15Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Resources.h
- Typedef of resources
- Prototypes for creation and initialization of resources
**************************************************************************************/

#ifndef __EXAMPLETASK1_RESOURCES_H
#define __EXAMPLETASK1_RESOURCES_H

#include "TLR_Includes.h"
#include "ExampleTask1_StartupParameter.h"

#define ASSERT(success)

#define INCLUDE_TYPEDEF_ONLY  1
typedef struct EXAMPLETASK1_RSC_Ttag EXAMPLETASK1_RSC_T;

#include "ExampleTask1_DiagStatus.h"
#include "ExampleTask1_EscCaller.h"
#include "ExampleTask1_ProcessData.h"
#include "ExampleTask1_ObjectDictionary.h"
#include "ExampleTask1_SiiProvider.h"

#define EXAMPLETASK1_QUEUE_MAX_ELEM      (16)
#define EXAMPLETASK1_POOL_MAX_ELEM       (16)

/** Local resources of Example Task1   */
typedef struct EXAMPLETASK1_RESOURCE_LOCALtag
{
  TLR_TASK_STATE                   eTskState;          /**< task state                         */
  TLR_UINT                         uTskInst;           /**< task instance                      */
  TLR_HANDLE                       hQue;               /**< queue handle, process queue        */
  TLR_HANDLE                       hPool;              /**< pool handle, resource pool         */
  TLR_HANDLE                       hLeaveHook;         /**< task leave function hook handle    */
  EXAMPLETASK1_STARTUPPARAMETER_T* ptStartup;          /**< Start up parameters given by static task list in this case atTask1StartupParameter */
  TLR_PACKET_HEADER_T              tLeavePckt;         /**< static packet used to leave task friendly */
  STATUS_DIAG_T                    tStatusDiag; /**< status information of send packets */
  TLR_UINT8                        hInformationField[TLR_DIA_INFORMATION_SIZE]; /**< handle to information field */
  OBJECT_DICTIONARY_T              tObjDict;
  SII_PROVIDER_T                   tSiiProv;
  ECS_PROCESS_DATA_T               tEcsPd;             /**< Process image and depending information */
}EXAMPLETASK1_LOC_T;

/** Remote resources of Example Task1  */
typedef struct EXAMPLETASK1_RESOURCE_REMOTEtag
{
  TLR_QUE_LINK_T      hQueEsm;        /**< queue handle, process queue        */
  ESC_CALLER_T        tEscCaller;     /**< EtherCAT Interface handle for callback SM2/SM3 handling */
}EXAMPLETASK1_REM_T;

/** Resources of Example Task1         */
struct EXAMPLETASK1_RSC_Ttag
{
  EXAMPLETASK1_LOC_T    tLoc;           /**< local resources                    */
  EXAMPLETASK1_REM_T    tRem;           /**< remote resources                   */
  TLR_DIA_TASK_INFO_T   tTaskInfo;      /**< task information data              */
};


TLR_RESULT TaskResource_ExampleTask1_Create( EXAMPLETASK1_STARTUPPARAMETER_T* ptInit,
                                             EXAMPLETASK1_RSC_T** pptRsc );

TLR_RESULT TaskResource_ExampleTask1_InitLocal( EXAMPLETASK1_RSC_T* ptRsc,
                                                EXAMPLETASK1_STARTUPPARAMETER_T* ptInit );

TLR_RESULT TaskResource_ExampleTask1_InitRemote( EXAMPLETASK1_RSC_T* ptRsc,
                                                 EXAMPLETASK1_STARTUPPARAMETER_T* ptInit );

TLR_RESULT TaskResource_ExampleTask1_Delete( EXAMPLETASK1_RSC_T* ptRsc );

#undef INCLUDE_TYPEDEF_ONLY
#endif /* #ifndef __EXAMPLETASK1_RESOURCES_H */
