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
$Id: Config_netX51.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file Config_netX51.c
  NXHX51-ETM specified configuration file for EtherCAT Slave LOM Example
**************************************************************************************/
#include "TLR_Includes.h"
#include "TlrTimer_Functionlist.h"
#include "ExampleTask1_Functionlist.h"
#include "mmio_config_nxhx51etm.h"
#include "EcsV4_Functionlist.h"
#include "EscRcX_Public.h"
#include "SiiImage.h"

#ifdef EOE_TCPIP_INTEGRATED
#include "TcpipTcpTask_Functionlist.h"
#include "TcpUdpApTask_Functionlist.h"
#endif

#define NETX_FREQUENCY_100MHZ 100000000  /**< CPU clock rate */
#define TSK_STACK_SIZE_EXAMPLEAPP  4096
#define TSK_STACK_SIZE_TCP_TASK    4096
#define TSK_STACK_SIZE_TLR_TIMER    512
#define ECS_SII_EEPROM_SIZE       65536  /**< Size of Slave Information Interface (SII)  */

const char* g_pszSiiDeviceName = "NETX 51 RE/ECS";
/**********************************************************************************//**
 * Task Stacks
 *************************************************************************************/
static UINT auTskStack_Task1[TSK_STACK_SIZE_EXAMPLEAPP];
static UINT auTskStack_Tlr_Timer[TSK_STACK_SIZE_TLR_TIMER];
#ifdef EOE_TCPIP_INTEGRATED
static UINT auTskStack_TcpUdpApTask[TCPUDPAPTASK_STACKSIZE];
#endif

/**********************************************************************************//**
 * Definition of the Hardware Timer Instances
 *************************************************************************************/
static const RX_HWTIMER_SET_T atrXHwTim[] =
{
  {
    .tCfgHd = {"SYSTIMER", RX_PERIPHERAL_TYPE_TIMER, 0}, /**< System Timer               */
    .uTimNum = 0,                                        /**< Use Timer 0                */
    .uMax = 1000,                                        /**< 1000 Microseconds = 1msec  */
    .fCont = TRUE,                                       /**< Continuous Mode            */
    .fInt = TRUE,                                        /**< Interrupt enabled          */
    .fExt = FALSE,                                       /**< No External Clock          */
    .eTrig = RX_HWTIMER_TRIGGER_NONE,                    /**< No Trigger                 */
    .uExtIoRef = 0,                                      /**< No I/O reference           */
    .uPscl = 0                                           /**< No Prescaler               */
  },
  {
    {"ECAT_PDWDG", RX_PERIPHERAL_TYPE_TIMER, 0},              /* ECAT Process Data Watchdog Timer */
    1,                                                        /* Use GPIO_counter1                */
    100000,                                                   /* 100000 Microseconds = 100msec    */
    FALSE,                                                    /* One-Shot Mode                    */
    TRUE,                                                     /* Interrupt enabled                */
    FALSE,                                                    /* No External Clock                */
    RX_HWTIMER_TRIGGER_NONE,                                  /* No Trigger                       */
    0,                                                        /* No I/O reference                 */
    0                                                         /* No Prescaler                     */
  }
};

/**********************************************************************************//**
 * Definition of the Interrupt-Instances
 *************************************************************************************/
static const RX_INTERRUPT_SET_T atrXInt[] =
{
  {
    .tCfgHd = {"SYSTIMER", RX_PERIPHERAL_TYPE_INTERRUPT, 0}, /**< System Timer Interrupt                            */
    .uIntNum = SRT_NX51_vic_irq_status_timer0,               /**< Use External Timer0 Interrupt                     */
    .uPrio = 29,                                             /**< Priority 29                                       */
    .eMod = RX_INTERRUPT_MODE_SYSTEM,                        /**< Allow interrupt to be nested                      */
    .eEoi = RX_INTERRUPT_EOI_AUTO,                           /**< EOI automatically by RX                           */
    .eTrig = RX_INTERRUPT_TRIGGER_RISING_EDGE,               /**< Edge Triggered                                    */
    .ePrio = RX_INTERRUPT_PRIORITY_STANDARD,                 /**< Normal Priority                                   */
    .eRntr = RX_INTERRUPT_REENTRANCY_DISABLED,               /**< Interrupt itself is not reentrant                 */
    .eTaskModePriority = 0,                                  /**< Not used, because .eMod != RX_INTERRUPT_MODE_TASK */
    .eTaskToken = 0,                                         /**< Not used, because .eMod != RX_INTERRUPT_MODE_TASK */
    .uTaskStackSize = 0,                                     /**< Not used, because .eMod != RX_INTERRUPT_MODE_TASK */
  },
  {
    {"ECAT_ESC", RX_PERIPHERAL_TYPE_INTERRUPT, 0},            /* Communication Channel 0, Instance 0            */
    SRT_NX51_vic_irq_status_com0,                             /* Use external communication channel 0 Interrupt */
    27,                                                       /* Priority 28                                    */
    RX_INTERRUPT_MODE_SYSTEM,                                 /* Allow interrupt to be a thread                 */
    RX_INTERRUPT_EOI_AUTO,                                    /* EOI automatically by RX                        */
    RX_INTERRUPT_TRIGGER_RISING_EDGE,                         /* Edge triggered                                 */
    RX_INTERRUPT_PRIORITY_STANDARD,                           /* Normal Priority                                */
    RX_INTERRUPT_REENTRANCY_DISABLED,                         /* Interrupt itself is not reentrant              */
  },
  {
    {"ECAT_PDWDG", RX_PERIPHERAL_TYPE_INTERRUPT, 0},          /* Process data Watchdog, Instance 0              */
    SRT_NX51_vic_irq_status_timer1,                           /* Use external Timer1 Interrupt                  */
    28,                                                       /* Priority 25                                    */
    RX_INTERRUPT_MODE_SYSTEM,                                 /* Allow interrupt to be a thread                 */
    RX_INTERRUPT_EOI_AUTO,                                    /* EOI automatically by RX                        */
    RX_INTERRUPT_TRIGGER_RISING_EDGE,                         /* Edge triggered                                 */
    RX_INTERRUPT_PRIORITY_STANDARD,                           /* Normal Priority                                */
    RX_INTERRUPT_REENTRANCY_ENABLED,                          /* Interrupt itself is reentrant                  */
  },
  {
    {"ECAT_ESC2", RX_PERIPHERAL_TYPE_INTERRUPT, 0},           /* EtherCAT Slave Controller, Instance 0              */
    SRT_NX51_vic_irq_status_msync0,                           /* Use synchronisation channel 0 Interrupt        */
    26,                                                       /* Priority 27                                    */
    RX_INTERRUPT_MODE_SYSTEM,                                 /* Allow interrupt to be a thread                 */
    RX_INTERRUPT_EOI_AUTO,                                    /* EOI automatically by RX                        */
    RX_INTERRUPT_TRIGGER_RISING_EDGE,                         /* Edge triggered                                 */
    RX_INTERRUPT_PRIORITY_STANDARD,                           /* Normal Priority                                */
    RX_INTERRUPT_REENTRANCY_DISABLED,                         /* Interrupt itself is not reentrant              */
  },
  {
    {"ECAT_SYNC", RX_PERIPHERAL_TYPE_INTERRUPT, 0},           /* Synchronization trigger, Instance 0              */
    SRT_NX51_vic_irq_status_trigger_lt,                       /* Use external Sync 3 Interrupt                  */
    25,                                                       /* Priority 26                                    */
    RX_INTERRUPT_MODE_SYSTEM,                                 /* Allow interrupt to be a thread                 */
    RX_INTERRUPT_EOI_AUTO,                                    /* EOI automatically by RX                        */
    RX_INTERRUPT_TRIGGER_RISING_EDGE,                         /* Edge triggered                                 */
    RX_INTERRUPT_PRIORITY_STANDARD,                           /* Normal Priority                                */
    RX_INTERRUPT_REENTRANCY_DISABLED,                         /* Interrupt itself is not reentrant              */
  },
};


/** Stack components EtherCAT slave stack task */
static const ECS_STACK_COMPONENT_T* s_atEcsComponents[] =
{
  /* Always use CoE FoE and Object Dictionary */
  &g_tEcsStackCoE,
  &g_tEcsStackFoE,
  &g_tEcsStackCO_ObjDicts,
#ifdef EOE_TCPIP_INTEGRATED
  &g_tEcsStackEoE,
  &g_tEcsStackEoETcpIpConnector,
#endif
  NULL,
};

ECS_COE_STACK_PARAMETERS_T s_tCoEParams =
{
  .tHead =
  {
    .eType = ECS_STACK_COMPONENT_COE                          /* Stack componente type CoE */
  },
  .tEcsCoE_CoETask =                                          /* CANopen over EtherCAT stack task */
  {
    .abName       = "ECAT_COE",                               /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_25,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_25                                /* Set Token ID                         */
  },
  .tEcsCoE_SdoTask =                                          /* SDO communications task inside the EtherCAT CoE stack */
  {
    .abName       = "ECAT_SDO",                               /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_24,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_24                                /* Set Token ID                         */
  },
  .ulDeviceType = 0                                           /* Device type */
};


/** Stack parameters File over EtherCAT stack task */
ECS_FOE_STACK_PARAMETERS_T s_tFoEParams =
{
  .tHead =
  {
    .eType = ECS_STACK_COMPONENT_FOE                          /* Stack componente type FoE */
  },
  .tEcsFoETask =                                              /* File over EtherCAT stack task */
  {
    .abName       = "ECAT_FOE",                               /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_26,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_26                                /* Set Token ID                         */
  },
};


/** Stack parameters CANopen over EtherCAT stack task Object Dictonary */
ECS_CO_OBJDICTS_STACK_PARAMETERS_ENTRY_T s_tObjDictParamEntries =
{
  .tOdTask =
  {
    .abName       = "ECS_OBJDICT",                            /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_28,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_28                                /* Set Token ID                         */
  },
  .ulInstance     = 0,                                        /* Set Instance */
  .abQueName      = "QUE_ECS_OBJDICT",                        /* Queue name   */
  .abPoolName     = "PCK_ECS_OBJDICT"                         /* Pool name    */
};


/** Stack parameters CANopen over EtherCAT stack task Object Dictonary */
static const ECS_CO_OBJDICTS_STACK_PARAMETERS_T s_tObjDictParams =
{
  .tHead =
  {
    .eType = ECS_STACK_COMPONENT_CO_OBJDICTS                  /* Stack componente type CoE ODV3 */
  },
  .ulNumObjDicts = 1,                                         /* Number of object dictionaries  */
  .patObjDicts = &s_tObjDictParamEntries                      /* Stack parameters ODV3          */
};

#ifdef EOE_TCPIP_INTEGRATED
static const ECS_EOE_STACK_PARAMETERS_T g_tEoEStackParameters =
{
  .tHead =
  {
    .eType                 = ECS_STACK_COMPONENT_EOE
  },
  .tEcsEoETask =                                                   /* parameters for
creation of EoE task */
  {
    .abName                = "ECS_EOE",
    .ulThreshold           = 0,
    .ulPriority            = TSK_PRIO_31,
    .ulToken               = TSK_TOK_31
  },
  .fStartEddDevice         = TLR_TRUE,
  .abMacAddress            = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55}, /* initial value can be
overwritten from master */
  .ulInstanceMacAddress    = 0,                                    /* if in the range 0 ...
3, it tries to get the mac address from SECMEM */
  .abEddIdn                = "EOE_EDD",                            /* EDD name */
  .uEddInstance            = 0,                                    /* EDD instance */
  .fRsrcControl            = 0
};

static const EOE_TCPIP_CONNECTOR_STACK_PARAMETERS_T g_tEoETcpIpConnectorParameters =
{
  .tHead =
  {
    .eType                        = ECS_STACK_COMPONENT_EOE_TCPIP_CONNECTOR
  },
  .tEcsEoETcpIpConnectorTask = /**< parameters for creation of EoE task */
  {
    .abName                       = "ECS_EOE_TCPIP",
    .ulThreshold                  = 0,
    .ulPriority                   = TSK_PRIO_32,
    .ulToken                      = TSK_TOK_32
  },
  .ulInstanceOfTcpIpConnectorTask = 0,
  .ulInstanceOfTcpIpStackTask     = 0
};
#endif

/** Stack components parameter EtherCAT slave stack task */
static const ECS_STACK_COMPONENT_PARAMETERS_HEADER_T* s_atEcsComponentParameters[] =
{
  /* Always use CoE FoE and Object Dictionary */
  &s_tCoEParams.tHead,
  &s_tFoEParams.tHead,
  &s_tObjDictParams.tHead,
#ifdef EOE_TCPIP_INTEGRATED
  &g_tEoEStackParameters.tHead,
  &g_tEoETcpIpConnectorParameters.tHead,
#endif
  NULL
};

#ifdef EOE_TCPIP_INTEGRATED
static const TCPIP_TCP_TASK_STARTUPPARAMETER_T tTcpipTcpTaskParam =
{
  TLR_TASK_TCPUDP,                                                  /* ulTaskIdentifier TCPUDP task (TCP/IP stack)  */
  TCPIP_STARTUPPARAMETER_VERSION_6,                                 /* ulParamVersion (TLR_TASK_PARAMETERHEADER)    */
  .ulQueElemCntAp      = TCPIP_SRT_QUE_ELEM_CNT_AP_DEFAULT,         /* ulQueElemCntAp */
  .ulPoolElemCnt       = TCPIP_SRT_POOL_ELEM_CNT_DEFAULT,           /* ulPoolElemCnt */
  .ulStartFlags        = TCPIP_SRT_FLAG_FAST_START,                 /* ulStartFlags: Start flags (see TCPIP_SRT_FLAG_xx in TcpipTcpTask_Functionlist.h) */
  .ulTcpCycleEvent     = TCPIP_SRT_TCP_CYCLE_EVENT_DEFAULT,         /* ulTcpCycleEvent */
  .ulQueFreeElemCnt    = TCPIP_SRT_QUE_FREE_ELEM_CNT_DEFAULT,       /* ulQueFreeElemCnt */
  .ulSocketMaxCnt      = TCPIP_SRT_SOCKET_MAX_CNT_DEFAULT,          /* ulSocketMaxCnt */
  .ulArpCacheSize      = TCPIP_SRT_ARP_CACHE_SIZE_DEFAULT,          /* ulArpCacheSize */
  .pszEddName          = "EOE_EDD",                                 /* pszEddName: EDD name (see atrXEdd[])         */
  .ulEddQuePoolElemCnt = TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_DEFAULT,   /* ulEddQuePoolElemCnt */
  .ulEddOutBufMaxCnt   = TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_DEFAULT,     /* ulEddOutBufMaxCnt */
  .ptEif               = NULL,                                      /* ptEif */
  .ulArpTimeoutCache   = 180,                                        /* ARP cache timeout ( seconds)                  */
  .pszHwNameNetX       = NULL,                                      /* pszHwNameNetX, netX hardware name             */
  .ulNetLoadMaxFramesPerTick   = TCPIP_SRT_NETLOAD_MAXFRAMESPERTICK_DEFAULT,     /*  Maximum number of frames                        */
                                                                                 /* per systemtick the tcpip stack shall handle      */
  .ulNetLoadMaxPendingARP      = TCPIP_SRT_NETLOAD_MAXPENDING_ARP_DEFAULT,       /* Maximum number of received                      */
                                                                                 /* and still pending (not yet processed) ARP frames */
  .ulNetLoadMaxPendingMCastARP = TCPIP_SRT_NETLOAD_MAXPENDING_MCASTARP_DEFAULT,  /* Maximum number of received and still pending    */
                                                                                 /* (not yet processed) ARP multicast frames         */
  .ulNetLoadMaxPendingIP       = TCPIP_SRT_NETLOAD_MAXPENDING_IP_DEFAULT,        /* Maximum number of received                      */
                                                                                 /* and still pending (not yet processed) ip frames  */
  .ulNetLoadMaxPendingMCastIP  = TCPIP_SRT_NETLOAD_MAXPENDING_MCASTIP_DEFAULT,   /* Maximum number of received and still pending    */
                                                                                 /* (not yet processed) multicast ip frames          */
};
#endif

static const ECS_STACK_PARAMETERS_T s_tEcsStackParameters =
{
  .ulParameterVersion         = ECS_STACK_PARAMETER_VERSION,  /* Version of parameter data set                        */
  .ulInstance                 = 0,                            /* Instance                                             */
  .pptComponentTable          = s_atEcsComponents,            /* Stack components EtherCAT slave stack task           */
  .pptComponentParameterTable = s_atEcsComponentParameters,   /* Stack components parameter EtherCAT slave stack task */

  /* Base tasks EtherCAT MBX */
  .tEcsBase_MbxTask =
  {
    .abName       = "ECAT_MBX",                               /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_27,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_27                                /* Set Token ID                         */
  },

  /* Base tasks EtherCAT ESM */
  .tEcsBase_EsmTask =
  {
    .abName       = "ECAT_ESM",                               /* Set Identification                   */
    .ulThreshold  = 0,                                        /* Threshold to maximum possible value  */
    .ulPriority   = TSK_PRIO_20,                              /* Set Priority                         */
    .ulToken      = TSK_TOK_20                                /* Set Token ID                         */
  },

  /* Base Stack ESM parameters */
  .tReadyWaitBits =
  {

    .uReadyWaitBits = 0                                       /* Ready Wait bit (do not wait startup of task) */

  },

  .ulEepromSize = ECS_SII_EEPROM_SIZE,                        /* Size of Slave Informatione Interface (SII) */
  .usMailboxSize = 0,                                         /* 0 == default */
  .usBootstrapMailboxSize = 128,
};


static EXAMPLETASK1_STARTUPPARAMETER_T atTask1StartupParameter[]=
{
  {
    .ulTaskIdentifier = EXAMPLETASK1_IDENTIFIER,
    .ulParamVersion   = EXAMPLETASK1_STARTUPPARAMETER_VERSION3,
    .ulVendorId       = 0xE0000044,
    .ulRevisionNumber = 0x00020004,
    .ulProductCode    = 0x00000028,
    .ptEcsStackParameters = &s_tEcsStackParameters,
#ifdef EOE_TCPIP_INTEGRATED
    .fUseEoe          = TLR_TRUE,
#else
    .fUseEoe          = TLR_FALSE,
#endif
    .pabSiiImage      = &g_abSiiImage[0],
    .ulSizeOfSiiImage = sizeof(g_abSiiImage),
  }
};

#ifdef EOE_TCPIP_INTEGRATED
static TCPUDPAPTASK_STARTUPPARAMETER_T s_TcpUdpApTaskStartupParam =
{
    .ulTaskIdentifier = TCPUDPAPTASK_IDENTIFIER,
    .ulParamVersion = TCPUDPAPTASK_STARTUPPARAMETER_VERSION,
};
#endif

static const TLR_TIMER_STARTUPPARAMETER_T tTlrTimerPrm[] =
{
  {
    TLR_TASK_TIMER,                                           /* ulTaskIdentifier TLR Timer Task  */
    1,                                                        /* Version of parameter data set    */
    128,                                                      /* Max. number of application timer */
    10,                                                       /* Max. number of interrupt timer   */
    128,                                                      /* Max. number of retry packets     */
  }
};
/**********************************************************************************//**
 * Configuration of the Application Task-List
 *************************************************************************************/
static const RX_STATIC_TASK_T atrXStaticTasks[] =
{
  {
    .szTskNam = "TASK1",                                             /**< Set Identification                         */
    .ulPrio = TSK_PRIO_34,
    .ulTok = TSK_TOK_34,
    .ulInst = 0,
    .pvStck = &auTskStack_Task1[0],                                  /**< Pointer to Stack                           */
    .ulStckSiz = TSK_STACK_SIZE_EXAMPLEAPP,                          /**< Size of Task Stack                         */
    .ulThrhld = 0,                                                   /**< Threshold to maximum possible value        */
    .ulSrtMod = RX_TASK_AUTO_START,
    .fnTask = TaskEnter_ExampleTask1,                                /**< Task function to schedule                  */
    .fnTskLve = NULL,                                                /**< Function called when Task will be deleted, TLR_TSK_SET_LEAVE_CBF should be prefered */
    .ulInp = (UINT32)&atTask1StartupParameter[0],
    .aulRes = {0, 0, 0, 0, 0, 0, 0, 0},                              /**< Reserved Region                            */
  },
#ifdef EOE_TCPIP_INTEGRATED
  {
     .szTskNam = TCPUDPAPTASK_NAME,
     .ulPrio = TSK_PRIO_36,
     .ulTok = TSK_TOK_36,
     .ulInst = 0,
     .pvStck = &auTskStack_TcpUdpApTask[0],
     .ulStckSiz = TCPUDPAPTASK_STACKSIZE,
     .ulThrhld = 0,
     .ulSrtMod = RX_TASK_AUTO_START,
     .fnTask = &TaskEnter_TcpUdpApTask,
     .fnTskLve = &TaskLeave_TcpUdpApTask,
     .ulInp = (UINT32)&s_TcpUdpApTaskStartupParam,
     .aulRes ={0, 0, 0, 0, 0, 0, 0, 0},
  },
  {"TCP_UDP",                                                   /* Set Identification */
    TSK_PRIO_41, TSK_TOK_41,                                    /* Set Priority,and Token ID                  */
    0,                                                          /* Set Instance to 0 */
    0,                                                          /* Pointer to Stack */
    TSK_STACK_SIZE_TCP_TASK,                                    /* Size of Task Stack */
    0,                                                          /* Threshold to maximum possible value        */
    RX_TASK_AUTO_START,                                         /* Start task automatically */
    (void (*)(void*))TaskEnter_TcpipTcpTask,                    /* Task function to  schedule                  */
    (void (*)(void*))TaskExit_TcpipTcpTask,                     /* Function called when Task will be deleted  */
    (UINT32)&tTcpipTcpTaskParam,                                /* Startup Parameter */
    {0, 0, 0, 0, 0, 0, 0, 0}                                    /* Reserved Region */
  },
#endif
  {
    "TLR_TIMER",                                              /* Set Identification                         */
    TSK_PRIO_30, TSK_TOK_30,                                  /* Set Priority, and Token ID                 */
    0,                                                        /* Set Instance to 0                          */
    &auTskStack_Tlr_Timer[0],                                 /* Pointer to Stack                           */
    TSK_STACK_SIZE_TLR_TIMER,                                 /* Size of Task Stack                         */
    0,                                                        /* Threshold to maximum possible value        */
    RX_TASK_AUTO_START,                                       /* Start task automatically                   */
    (void (FAR*)(void FAR*))TaskEnter_TlrTimer,               /* Task function to schedule                  */
    (void (FAR*)(void FAR*))TaskExit_TlrTimer,                /* Function called when Task will be deleted  */
    (UINT32)&tTlrTimerPrm[0],                                 /* Startup Parameter                          */
    {0, 0, 0, 0, 0, 0, 0, 0}                                  /* Reserved Region                            */
  },
};

/**********************************************************************************//**
 * Peripheral Configuration List handed over to the ROM-Kernel
 *************************************************************************************/
static const RX_PERIPHERAL_CONFIG_T atrXCfgPre[] =
{
  {RX_PERIPHERAL_TYPE_TIMER,      atrXHwTim,  MAX_CNT(atrXHwTim)},
  {RX_PERIPHERAL_TYPE_INTERRUPT,  atrXInt,    MAX_CNT(atrXInt)},
};


/**********************************************************************************//**
 * Definition of the PHY-Instances
 *************************************************************************************/
static const FAR RX_PHY_SET_T atrXPhy[] =
{
  {
    {"ECAT_PHY", RX_PERIPHERAL_TYPE_PHY, 0},
    0,                                                        /* Physical port number of PHY (MDIO)         */
    0,                                                        /* Organizationally Unique Identifier         */
    0,                                                        /* Manufacturer specific Part Number          */
    0,                                                        /* Manufacturer Revision Number               */
    0,                                                        /* Number of following Registers to write to  */
    {
      {0x00, 0x0000},                                         /* Register set to write the values to        */
      {0x00, 0x0000}                                          /* Register set to write the values to        */
    },
    TLR_TRUE,                                                 /* Power down phy on init                     */
    TLR_FALSE,                                                /* Custom init                                */
    6,                                                        /* Custom init, Set PHY to powerdown          */
    TLR_FALSE,                                                /* Custom init, Use auto-crossover            */
    TLR_FALSE                                                 /* Custom init, Enable fiber optics           */
  },
  {
    {"ECAT_PHY", RX_PERIPHERAL_TYPE_PHY, 1},
    1,                                                        /* Physical port number of PHY  (MDIO)        */
    0,                                                        /* Organizationally Unique Identifier         */
    0,                                                        /* Manufacturer specific Part Number          */
    0,                                                        /* Manufacturer Revision Number               */
    0,                                                        /* Number of following Registers to write to  */
    {
      {0x00, 0x0000},                                         /* Register set to write the values to        */
      {0x00, 0x0000}                                          /* Register set to write the values to        */
    },
    TLR_TRUE,                                                 /* Power down phy on init                     */
    TLR_FALSE,                                                /* Custom init                                */
    6,                                                        /* Custom init, Set PHY to powerdown          */
    TLR_FALSE,                                                /* Custom init, Use auto-crossover            */
    TLR_FALSE                                                 /* Custom init, Enable fiber optics           */
  }
};


/**********************************************************************************//**
 * Configuration of the PIO Instances
 *************************************************************************************/
static const FAR RX_PIO_SET_T atrXPio[] =
{
  {
    {"SYSPIO", RX_PERIPHERAL_TYPE_PIO, 0},
    {RX_PIO_VALUE_TYPE_ACTIVE_HIGH, Adr_NX51_pio_oe, 0xFF},   /* Register to make PIO Pin to output at startup    */
    {RX_PIO_VALUE_TYPE_NONE, 0, 0x00000000},                  /* Unused                                           */
    {RX_PIO_VALUE_TYPE_ACTIVE_LOW, Adr_NX51_pio_out},         /* PIO Register to set PIOs                         */
    {RX_PIO_VALUE_TYPE_ACTIVE_LOW, Adr_NX51_pio_out},         /* PIO Register to clear PIOs                       */
    {RX_PIO_VALUE_TYPE_ABSOLUTE, Adr_NX51_pio_in},            /* Register to get current input value of the PIOs  */
  }
};

/**********************************************************************************//**
 * Configuration of the XC-Instances
 *************************************************************************************/
extern UINT32 XcCode_rpu_ecat0;
extern UINT32 XcCode_tpu_ecat0;
extern UINT32 XcCode_rpu_ecat1;
extern UINT32 XcCode_tpu_ecat1;
extern UINT32 XcCode_rpec_ecat_proc_rpec0;
extern UINT32 XcCode_tpec_ecat_proc_tpec0;
extern UINT32 XcCode_rpec_ecat_frwd_rpec1;
extern UINT32 XcCode_tpec_ecat_frwd_tpec1;

static const FAR RX_XC_SET_T atrXXc[] =
{
  {
    {"RPEC", RX_PERIPHERAL_TYPE_XC, 0},                       /* Instance 0                     */
    RX_XC_TYPE_RPEC,                                          /* Type of XC unit is RPEC        */
    0,                                                        /* XC channel 0                   */
    (UINT32 FAR*)&XcCode_rpec_ecat_proc_rpec0,                /* ECAT Slave RPEC start address  */
  },
  {
    {"TPEC", RX_PERIPHERAL_TYPE_XC, 0},                       /* Instance 0                     */
    RX_XC_TYPE_TPEC,                                          /* Type of XC unit is TPEC        */
    0,                                                        /* XC channel 0                   */
    (UINT32 FAR*)&XcCode_tpec_ecat_proc_tpec0,                /* ECAT Slave TPEC start address  */
  },
  {
    {"XMACRPU", RX_PERIPHERAL_TYPE_XC, 0},                    /* Instance 0                     */
    RX_XC_TYPE_XMACRPU,                                       /* Type of XC unit is xMAC        */
    0,                                                        /* XC channel 0                   */
    (UINT32 FAR*)&XcCode_rpu_ecat0,                           /* ECAT Slave xRPU start address  */
  },
  {
    {"XMACTPU", RX_PERIPHERAL_TYPE_XC, 0},                    /* Instance 0                     */
    RX_XC_TYPE_XMACTPU,                                       /* Type of XC unit is xMAC        */
    0,                                                        /* XC channel 0                   */
    (UINT32 FAR*)&XcCode_tpu_ecat0,                           /* ECAT Slave xTPU start address  */
  },

  {
    {"RPEC", RX_PERIPHERAL_TYPE_XC, 1},                       /* Instance 1                     */
    RX_XC_TYPE_RPEC,                                          /* Type of XC unit is RPEC        */
    1,                                                        /* XC channel 1                   */
    (UINT32 FAR*)&XcCode_rpec_ecat_frwd_rpec1,                /* ECAT Slave RPEC start address  */
  },
  {
    {"TPEC", RX_PERIPHERAL_TYPE_XC, 1},                       /* Instance 1                     */
    RX_XC_TYPE_TPEC,                                          /* Type of XC unit is TPEC        */
    1,                                                        /* XC channel 1                   */
    (UINT32 FAR*)&XcCode_tpec_ecat_frwd_tpec1,                /* ECAT Slave TPEC start address  */
  },
  {
    {"XMACRPU", RX_PERIPHERAL_TYPE_XC, 1},                    /* Instance 1                     */
    RX_XC_TYPE_XMACRPU,                                       /* Type of XC unit is xMAC        */
    1,                                                        /* XC channel 1                   */
    (UINT32 FAR*)&XcCode_rpu_ecat1,                           /* ECAT Slave xRPU start address  */
  },
  {
    {"XMACTPU", RX_PERIPHERAL_TYPE_XC, 1},                    /* Instance 1                     */
    RX_XC_TYPE_XMACTPU,                                       /* Type of XC unit is xMAC        */
    1,                                                        /* XC channel 1                   */
    (UINT32 FAR*)&XcCode_tpu_ecat1,                           /* ECAT Slave xTPU start address  */
  }
};


/**********************************************************************************//**
 * Definition of the LED-Instances
 *************************************************************************************/
static const FAR RX_LED_SET_T atrXLed[] =
{
  {
    {"READY", RX_PERIPHERAL_TYPE_LED, 0},                     /* READY LED Object Configuration                         */
    {"RDYRUN", RX_PERIPHERAL_TYPE_LED, 0},                    /* RDYRUN LED Object Configuration                        */
    {0, 0, 0},                                                /* Optional Register to make LED Pin to output at startup */
    {0, 0, 0},                                                /* Optional Register to make LED Pin to output at startup */
    {RX_LED_VALUE_TYPE_OR, 1, 0x01},                          /* LED Enable Register and Value                          */
    {RX_LED_VALUE_TYPE_OR, 1, 0x01},                          /* LED Disable Register and Value                         */
    NULL,                                                     /* Set of LED functions                                   */
  },
  {
    {"RUN", RX_PERIPHERAL_TYPE_LED, 0},                       /* RUN LED Object Configuration                           */
    {"RDYRUN", RX_PERIPHERAL_TYPE_LED, 0},                    /* RDYRUN LED Object Configuration                        */
    {0, 0, 0},                                                /* Optional Register to make LED Pin to output at startup */
    {0, 0, 0},                                                /* Optional Register to make LED Pin to output at startup */
    {RX_LED_VALUE_TYPE_OR, 2, 0x02},                          /* LED Enable Register and Value                          */
    {RX_LED_VALUE_TYPE_OR, 2, 0x02},                          /* LED Disable Register and Value                         */
    NULL,                                                     /* Set of LED functions                                   */
  },
  {
    {"ECAT_STATUS", RX_PERIPHERAL_TYPE_LED, 0},               /* ECAT_STATUS LED Object Configuration                   */
    {"SYSPIO", RX_PERIPHERAL_TYPE_PIO, 0},                    /* Register Destination Definition                        */
    {(RX_LED_VALUE_TYPE)0, 0, 0},                             /* Optional Register to make LED Pin to output at startup */
    {(RX_LED_VALUE_TYPE)0, 0, 0},                             /* Optional Register to make LED Pin to output at startup */
    {RX_LED_VALUE_TYPE_NONE, 0, 0x01},                        /* LED Enable Register and Value                          */
    {RX_LED_VALUE_TYPE_NONE, 0, 0x01},                        /* LED Disable Register and Value                         */
    Drv_PioSetupLedOperations,                                /* Set of LED functions                                   */
  },
  {
    {"ECAT_ERROR", RX_PERIPHERAL_TYPE_LED, 0},                /* ECAT_ERROR LED Object Configuration                    */
    {"SYSPIO", RX_PERIPHERAL_TYPE_PIO, 0},                    /* Register Destination Definition                        */
    {(RX_LED_VALUE_TYPE)0, 0, 0},                             /* Optional Register to make LED Pin to output at startup */
    {(RX_LED_VALUE_TYPE)0, 0, 0},                             /* Optional Register to make LED Pin to output at startup */
    {RX_LED_VALUE_TYPE_NONE, 0, 0x08},                        /* LED Enable Register and Value                          */
    {RX_LED_VALUE_TYPE_NONE, 0, 0x08},                        /* LED Disable Register and Value                         */
    Drv_PioSetupLedOperations,                                /* Set of LED functions                                   */
  }
};

/**********************************************************************************//**
 * Peripheral Driver Configuration loaded after the Kernel has been started
 *************************************************************************************/
static const FAR RX_DRIVER_PERIPHERAL_CONFIG_T atrXDrvCfgPost[] =
{

  {&DrvPhyInit, RX_PERIPHERAL_TYPE_PHY,    atrXPhy, MAX_CNT(atrXPhy)},
  {&DrvPioInit, RX_PERIPHERAL_TYPE_PIO,    atrXPio, MAX_CNT(atrXPio)},
  {&DrvXcInit,  RX_PERIPHERAL_TYPE_XC,     atrXXc,  MAX_CNT(atrXXc)}, /**< Communication Channel (XC) Driver */
  {&DrvLedInit, RX_PERIPHERAL_TYPE_LED,    atrXLed, MAX_CNT(atrXLed)},
  {&DrvSecInit}
};
/**********************************************************************************//**
 *  Middleware Configuration loaded after the Kernel has been started
 *************************************************************************************/
ESC_CONFIG_SET_T tEscConfig =
{
  1,      /**< Timer number from ECAT_PDWDG */
  0xCC00, /**< PDI config word              */
  1000    /**< Sync impulse length          */
};
static const FAR RX_MIDDLEWARE_CONFIG_T atrXMidCfgPost[] =
{
  {&MidLedInit},                   /**< Initialize application middleware led                */
  {&MidSysInit},                   /**< Initialize application middleware sys                */
  {&Esc_RcX_Init, &tEscConfig, 1}, /**< Initialize EtherCAT HAL and Hardwaretimer ECAT_PDWDG */
};
/**********************************************************************************//**
 * Provides access to the rX_FltFatalError call
 *************************************************************************************/
RX_FAULT_FATAL_VECTOR_RETURN fatalErrorCallback( RX_FATAL eFat )
{
  for( ; ; );
  return RX_FAULT_FATAL_HOLD;
}


/**********************************************************************************//**
 * Provides access to the rX_FltFatalError call
 *************************************************************************************/
RX_FAULT_FATAL_VECTOR_RETURN driverFaultCallback( RX_PERIPHERAL_TYPE ePerType,
                                                  const void* pvCfg,
                                                  RX_RESULT erXRes,
                                                  void* pvPrm )
{
  for( ; ; );
  return RX_FAULT_FATAL_HOLD;
}


/**********************************************************************************//**
 * Early callback initialization, this callback is called before the memory
 *  allocation capability has been set up
 *************************************************************************************/
static void EarlyCallback( void )
{
  rX_FltSetFatalVector( fatalErrorCallback );
  rX_FltSetDriverFaultVector( driverFaultCallback, NULL );
}

/**********************************************************************************//**
 * Kernel parameters
 *************************************************************************************/
const RX_ENTERKERNEL_PARAM_T trXEnterKernelParam =
{
  .ulCpuClkRate = NETX_FREQUENCY_100MHZ,                           /**< CPU clock rate */
  .tTimerTaskConfig = {TSK_PRIO_DEF_RX_TIMER, 768},                /**< Timer interrupt task priority */
  .tStaticTasks = {atrXStaticTasks, MAX_CNT(atrXStaticTasks)},     /**< Pointer to static Task-List */
  .tKernelModules = {NULL, 0},                                     /**< Pointer to rx kernel modules list */
  .tPeripherals = {atrXCfgPre, MAX_CNT(atrXCfgPre)},               /**< Pointer to the Peripherals-List */
  .tDriverPeripherals = {atrXDrvCfgPost, MAX_CNT(atrXDrvCfgPost)}, /**< Pointer to the Post Peripherals-List / LoadDrivers included into */
  .tJumpTable = {NULL, 0},                                         /**< Pointer to optional Jump Table */
  .pfnCallBack = NULL,                                             /**< Callback for special initialization */
  .tMiddleware = {atrXMidCfgPost, MAX_CNT(atrXMidCfgPost)},        /**< Pointer to the Middleware List */
  .ptScheduler = (void*)&g_tMLQueueScheduler,                      /**< Scheduler component (if another scheduler is desired) */
  .tCacheConfig = {FALSE, FALSE},                                  /**< Cache enable flags netX51/52 have none */
  .tMeasureIdlePerformance = {TRUE},
  .pfnEarlyCallback = EarlyCallback,
  .tMMU = {0}                                                      /**< MMU TTB start address, netX 51/52 have none therefore 0 */
};


/**********************************************************************************//**
 * Enters the RX-kernel mode forever
 *************************************************************************************/
int main( void )
{
  /* Fatal Error value, in case funtion would return */
  volatile RX_FATAL erXFat = RX_OK;

  /* Configure MMIO pin multiplexer */
  mmio_config_nxhx51etm();

  if( RX_OK == erXFat )
  {
    /* Boot the Kernel by using the set Call-Pointer and hand over the static Task-List and the Peripherals-List */
    erXFat = rX_SysEnterKernelExt( &trXEnterKernelParam );
  }

  /* Loop forever here, to keep the "erXFat" variable debugable */
  while( erXFat != RX_OK );

  /* Prevent the compiler warning because of non-void returning main-function */
  return( 0 );
}
