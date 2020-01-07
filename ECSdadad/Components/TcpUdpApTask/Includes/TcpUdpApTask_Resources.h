/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApTask_Resources.h 1315 2015-09-14 14:43:13Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApTask_Resources.h
- Typedef of resources
- Prototypes for creation and initialization of resources
**************************************************************************************/

#ifndef __TCPUDPAPTASK_RESOURCES_H
#define __TCPUDPAPTASK_RESOURCES_H

#include "TcpUdpApTask_StartupParameter.h"
#include "TLR_Includes.h"
#include "TcpipTcpTask_Public.h"

#define ASSERT(success)

#define INCLUDE_TYPEDEF_ONLY  1
typedef struct TCPUDPAPTASK_RSC_Ttag TCPUDPAPTASK_RSC_T;
typedef struct TCPUDPAPTASK_RSC_Ttag TCPIP_AP_TASK_RSC_T;/**< to be compatible to <em>TCP IP - Packet Interface API 12 EN.pdf</em>*/
#include "TcpUdpApTask_DiagStatus.h"


#define TCPUDPAPTASK_QUEUE_MAX_ELEM      (16)
#define TCPUDPAPTASK_POOL_MAX_ELEM       (16)

typedef struct TCPIP_CONFIG_Ttag
{
  TLR_UINT32  ulFlags;
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulNetMask;
  TLR_UINT32  ulGateway;
  TLR_UINT8   abEthernetAddr[6];

}TCPIP_CONFIG_T;

/** Local resources of Example Task1   */
typedef struct TCPUDPAPTASK_RESOURCE_LOCALtag
{
  TLR_TASK_STATE        eTskState;          /**< task state                         */
  TLR_UINT              uTskInst;           /**< task instance                      */
  TLR_HANDLE            hQue;               /**< queue handle, process queue        */
  TLR_HANDLE            hPool;              /**< pool handle, resource pool         */
  TLR_HANDLE            hLeaveHook;         /**< task leave function hook handle    */
  TLR_PACKET_HEADER_T   tCycleEventPck;     /**< Packet which will be sent by timer */
  TLR_HANDLE            hCycleEvent;        /**< Handle for cyclic event              */
  TLR_PACKET_HEADER_T   tLeavePckt;         /**< Static packet used to leave task friendly */
  UINT32                ulSndTcpId;         /**< Packtet identification to TCP_UDP task */
  STATUS_DIAG_T         tStatusDiag;        /**< Status information of send packets */
  TCPIP_CONFIG_T        tTcpIpConfig;       /**< Mirrored IP configuration */
  TLR_UINT32            ulPort;             /**< Configured port */
  TLR_UINT32            ulProtocol;         /**< Configured protocol: UDP or TCP */
  TLR_UINT32            ulSocket;           /**< Configured socket */
  TLR_UINT32            ulRemoteIpAddr;     /**< Ip address of connected client*/
  TLR_UINT32            ulRemotePort;       /**< Port of connected client*/
  TLR_UINT8             abReceiveBuffer[TCPIP_MAX_TCP_UDP_DATA_CNT];
  TLR_UINT              uiReceiveBufferLen;
  TLR_UINT8             bTestSndData;
  TLR_QUE_LINK_SOURCE_T tLnkSrc;            /**< Source link  */
  TLR_UINT8             hInformationField[TLR_DIA_INFORMATION_SIZE]; /**< handle to information field */
}TCPUDPAPTASK_LOC_T;

/** Remote resources of Example Task1  */
typedef struct TCPUDPAPTASK_RESOURCE_REMOTEtag
{
  TLR_HANDLE      hTskTcpTask;   /**< Task process handle  */
  TLR_UINT        uToknTcpTask;  /**< Task ID number       */
  TLR_UINT        uPrioTcpTask;  /**< Task priority        */
  TLR_QUE_LINK_T  tQueTcpTask;   /**< Queue handle, process queue        */
}TCPUDPAPTASK_REM_T;

/** Resources of Example Task1         */
struct TCPUDPAPTASK_RSC_Ttag
{
  TCPUDPAPTASK_LOC_T    tLoc;           /**< local resources                    */
  TCPUDPAPTASK_REM_T    tRem;           /**< remote resources                   */
  TLR_DIA_TASK_INFO_T   tTaskInfo;      /**< task information data              */
};


TLR_RESULT TaskResource_TcpUdpApTask_Create( TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit,
                                             TCPUDPAPTASK_RSC_T** pptRsc );

TLR_RESULT TaskResource_TcpUdpApTask_InitLocal( TCPUDPAPTASK_RSC_T* ptRsc,
                                                TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit );

TLR_RESULT TaskResource_TcpUdpApTask_InitRemote( TCPUDPAPTASK_RSC_T* ptRsc,
                                                 TCPUDPAPTASK_STARTUPPARAMETER_T* ptInit );

TLR_RESULT TaskResource_TcpUdpApTask_Delete( TCPUDPAPTASK_RSC_T* ptRsc );

#undef INCLUDE_TYPEDEF_ONLY
#endif /* #ifndef __TCPUDPAPTASK_RESOURCES_H */
