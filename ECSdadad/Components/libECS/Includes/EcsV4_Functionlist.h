/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:

    @version $Id: EcsV4_Functionlist.h 44647 2014-04-07 08:03:35Z Sven $

   Description:

    EtherCAT Slave V4

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2012-04-12  UJ            fixed mantis #17926: cleanup target configuration: tEcatEsmSiiInitData
     2012-04-04  UJ            cleanup of FoE startup parameters
     2011-05-06  SB            cleaned up function prototypes
     2010-03-24  SB            Created
**************************************************************************************/

#if !defined(_ECS_FUNCTIONLIST_H) || defined(__ECS_ECLIPSE__)
#define _ECS_FUNCTIONLIST_H

#include "EcsV4_Public.h"

typedef struct ECS_STACK_PRIVATE_Ttag ECS_STACK_PRIVATE_T;

typedef enum ECS_STACK_COMPONENT_TYPE_Etag
{
  ECS_STACK_COMPONENT_INVALID             = 0,      /* internal use only */
  ECS_STACK_COMPONENT_BASE                = 1,
  ECS_STACK_COMPONENT_COE                 = 2,
  ECS_STACK_COMPONENT_EOE                 = 3,
  ECS_STACK_COMPONENT_EOE_TCPIP_CONNECTOR = 4,
  ECS_STACK_COMPONENT_FOE                 = 5,
  ECS_STACK_COMPONENT_SOE                 = 6,
  ECS_STACK_COMPONENT_CO_OBJDICTS         = 7,  /* object dictionary queues may be multiple depending on configuration */
  ECS_STACK_COMPONENT_AOE                 = 8,
  ECS_STACK_COMPONENT_FOE_FH              = 9,
} ECS_STACK_COMPONENT_TYPE_E;

typedef struct ECS_STACK_COMPONENT_Ttag ECS_STACK_COMPONENT_T;

extern const ECS_STACK_COMPONENT_T  g_tEcsStackAoE;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackCoE;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackEoE;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackFoE;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackFoE_FH;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackSoE;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackCO_ObjDicts;
extern const ECS_STACK_COMPONENT_T  g_tEcsStackEoETcpIpConnector;

typedef struct ECS_STACK_COMPONENT_PARAMETERS_HEADER_Ttag
{
  ECS_STACK_COMPONENT_TYPE_E                                eType;
} ECS_STACK_COMPONENT_PARAMETERS_HEADER_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_Ttag ECS_STACK_COMPONENT_QUEUES_T;


typedef struct ECS_STACK_COMPONENT_QUEUES_HEADER_Ttag ECS_STACK_COMPONENT_QUEUES_HEADER_T;

struct ECS_STACK_COMPONENT_QUEUES_HEADER_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T*                      ptNext;
  ECS_STACK_COMPONENT_TYPE_E                                eType;
  TLR_UINT32                                                ulNumQueues;
};

struct ECS_STACK_COMPONENT_QUEUES_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            atQueLinks[1];  /* variable number of elements */
};


typedef struct ECS_STACK_COMPONENT_QUEUES_COE_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueCoE;
  TLR_QUE_LINK_T                                            tQueSdo;
  TLR_QUE_LINK_T                                            tQueObjDict;
} ECS_STACK_COMPONENT_QUEUES_COE_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_AOE_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueAoE;
} ECS_STACK_COMPONENT_QUEUES_AOE_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_EOE_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueEoE;
} ECS_STACK_COMPONENT_QUEUES_EOE_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_FOE_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueFoE;
} ECS_STACK_COMPONENT_QUEUES_FOE_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_FOE_FH_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueFoE_FH;
} ECS_STACK_COMPONENT_QUEUES_FOE_FH_T;

typedef struct ECS_STACK_COMPONENT_QUEUES_SOE_Ttag
{
  ECS_STACK_COMPONENT_QUEUES_HEADER_T                       tCommon;
  TLR_QUE_LINK_T                                            tQueSoE_SSC;
  TLR_QUE_LINK_T                                            tQueSoE_IDN;
} ECS_STACK_COMPONENT_QUEUES_SOE_T;

typedef ECS_STACK_COMPONENT_QUEUES_T ECS_STACK_COMPONENTS_QUEUES_CO_OBJDICTS_T;

/******************************************************************************
 * Structure returned by Esc_StackInitialize
 */
typedef struct ECS_STACK_Ttag
{
  /* Esc interface */
  TLR_HANDLE                                                hEscInterface;

  /* Base Stack */
  TLR_QUE_LINK_T                                            tQueEsm;
  TLR_QUE_LINK_T                                            tQueMbx;

  /* only used for optional components */
  ECS_STACK_COMPONENT_QUEUES_T*                             aptComponentQueuesTable;
} ECS_STACK_T;

/******************************************************************************
 * Common Stack parameters
 */

typedef struct ECS_STACK_PARAMETERS_TASK_Ttag
{
  TLR_STR                                                   abName[16];
  TLR_UINT32                                                ulThreshold;
  TLR_UINT32                                                ulPriority;
  TLR_UINT32                                                ulToken;
} ECS_STACK_PARAMETERS_TASK_T;

/******************************************************************************
 * CoE Stack parameters
 */
typedef struct ECS_COE_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* CoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsCoE_CoETask;
  ECS_STACK_PARAMETERS_TASK_T                               tEcsCoE_SdoTask;
  TLR_UINT32                                                ulDeviceType;
} ECS_COE_STACK_PARAMETERS_T;

/******************************************************************************
 * CoE Stack parameters
 */
typedef struct ECS_CO_OBJDICTS_STACK_PARAMETERS_ENTRY_Ttag
{
  ECS_STACK_PARAMETERS_TASK_T                               tOdTask;
  TLR_UINT32                                                ulInstance;
  TLR_STR                                                   abQueName[16];
  TLR_STR                                                   abPoolName[16];
} ECS_CO_OBJDICTS_STACK_PARAMETERS_ENTRY_T;

typedef struct ECS_CO_OBJDICTS_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  TLR_UINT32                                                ulNumObjDicts;
  const ECS_CO_OBJDICTS_STACK_PARAMETERS_ENTRY_T*           patObjDicts;
} ECS_CO_OBJDICTS_STACK_PARAMETERS_T;

/******************************************************************************
 * AoE Stack parameters
 */
typedef struct ECS_AOE_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* AoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsAoETask;
  TLR_UINT16                                                usModuleOdStartPort;  /* parameter used for additional object dictionaries via ECS_CO_OBJDICTS_STACK_PARAMETERS_T */
} ECS_AOE_STACK_PARAMETERS_T;

/******************************************************************************
 * EoE Stack parameters
 */
typedef struct ECS_EOE_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* EoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsEoETask;

  TLR_BOOLEAN                                               fStartEddDevice;
  TLR_UINT8                                                 abMacAddress[6];
  TLR_UINT32                                                ulInstanceMacAddress;
  TLR_STR                                                   abEddIdn[16];
  TLR_UINT                                                  uEddInstance;
  TLR_BOOLEAN                                               fRsrcControl;
} ECS_EOE_STACK_PARAMETERS_T;

/******************************************************************************
 * EoE TcpIp Connector parameters (only rcX)
 */
typedef struct EOE_TCPIP_CONNECTOR_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;

  /* EoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsEoETcpIpConnectorTask;

  TLR_UINT32                                                ulInstanceOfTcpIpConnectorTask;
  TLR_UINT32                                                ulInstanceOfTcpIpStackTask;
} EOE_TCPIP_CONNECTOR_STACK_PARAMETERS_T;

/******************************************************************************
 * FoE Stack parameters
 */
typedef struct ECS_FOE_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* FoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsFoETask;
} ECS_FOE_STACK_PARAMETERS_T;

typedef struct ECS_FOE_FH_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* FoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsFoEFHTask;
} ECS_FOE_FH_STACK_PARAMETERS_T;

/******************************************************************************
 * SoE Stack parameters
 */
typedef struct ECS_SOE_STACK_PARAMETERS_Ttag
{
  ECS_STACK_COMPONENT_PARAMETERS_HEADER_T                   tHead;
  /* SoE Tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsSoE_SSCTask;
  ECS_STACK_PARAMETERS_TASK_T                               tEcsSoE_IDNTask;
} ECS_SOE_STACK_PARAMETERS_T;


/******************************************************************************
 * Stack parameters
 */
#define ECS_STACK_PARAMETER_VERSION     1

typedef struct ECS_STACK_PARAMETERS_Ttag
{
  TLR_UINT32                                                ulParameterVersion;

  TLR_UINT32                                                ulInstance;

  const ECS_STACK_COMPONENT_T**                             pptComponentTable;           /* NULL-terminated array */
  const ECS_STACK_COMPONENT_PARAMETERS_HEADER_T**           pptComponentParameterTable;  /* NULL-terminated array */

  /* Base tasks */
  ECS_STACK_PARAMETERS_TASK_T                               tEcsBase_MbxTask;
  ECS_STACK_PARAMETERS_TASK_T                               tEcsBase_EsmTask;

  /* Base Stack ESM parameters */
  ECAT_READYWAIT_STATUS_T                                   tReadyWaitBits;

  TLR_UINT32                                                ulEepromSize;

  TLR_UINT16                                                usMailboxSize;       /* 0 == default value, minimum configurable is 128 byte (1.. 127 will be increased to 128) (additionally, must be dword aligned) */
  TLR_UINT16                                                usBootstrapMailboxSize; /* 0 == disabled, minimum configurable is 128 byte (1.. 127 will be increased to 128) (additionally, must be dword aligned) */
} ECS_STACK_PARAMETERS_T;

TLR_RESULT Ecs_StackInitialize(const ECS_STACK_PARAMETERS_T* ptStackParameters, ECS_STACK_T** pptStack);
TLR_RESULT Ecs_StackDeinitialize(ECS_STACK_T* ptStack);


ECS_STACK_COMPONENT_QUEUES_HEADER_T*
Ecs_Stack_Common_GetComponentQueues(ECS_STACK_T* ptStack, ECS_STACK_COMPONENT_TYPE_E eType);

/******************************************************************************
 * Helper functions
 */
static inline
ECS_STACK_COMPONENT_QUEUES_COE_T*
Ecs_Stack_Common_GetCoEComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_COE_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_COE);
}

static inline
ECS_STACK_COMPONENT_QUEUES_AOE_T*
Ecs_Stack_Common_GetAoEComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_AOE_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_AOE);
}

static inline
ECS_STACK_COMPONENT_QUEUES_EOE_T*
Ecs_Stack_Common_GetEoEComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_EOE_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_EOE);
}

static inline
ECS_STACK_COMPONENT_QUEUES_FOE_T*
Ecs_Stack_Common_GetFoEComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_FOE_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_FOE);
}

static inline
ECS_STACK_COMPONENT_QUEUES_FOE_FH_T*
Ecs_Stack_Common_GetFoEFHComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_FOE_FH_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_FOE_FH);
}

static inline
ECS_STACK_COMPONENT_QUEUES_SOE_T*
Ecs_Stack_Common_GetSoEComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENT_QUEUES_SOE_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_SOE);
}

static inline
ECS_STACK_COMPONENTS_QUEUES_CO_OBJDICTS_T*
Ecs_Stack_Common_GetCO_ObjDictsComponent(ECS_STACK_T* ptStack)
{
  return (ECS_STACK_COMPONENTS_QUEUES_CO_OBJDICTS_T*) Ecs_Stack_Common_GetComponentQueues(ptStack, ECS_STACK_COMPONENT_CO_OBJDICTS);
}

void
Ecs_Stack_EnableDpmStyleHandling(ECS_STACK_T* ptStack,
                                 TLR_HANDLE   hQue);

/******************************************************************************
 * Packet routing function
 */
TLR_RESULT
Ecs_Stack_RoutePacket(ECS_STACK_T*  ptStack,
                      void*         pvPck,
                      TLR_UINT32    ulTimeout);

#endif //_ECS_FUNCTIONLIST_H
