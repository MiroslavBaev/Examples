/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: rX_TagLists.h 198 2011-06-14 15:29:32Z sspies $

  Description:
    Tag lists support

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2012-02-29  NC            Added RCX_TAG_DPM_SETTINGS_T.
    2011-06-30  NC            Added RCX_TAG_DPM_COMM_CHANNEL_T, RCX_TAG_EIF_EDD_INSTANCE_T, and RCX_TAG_EIF_EDD_CONFIG_T.
    2010-08-27  NC            Redesign of group tags and entry tags for tasks and interrupts.
    2010-08-25  NC            Corrected type name of RCX_TAG_UART_T.
    2010-08-10  NC            Removed unused tag RCX_TAG_HIF_PARAMS.
    2010-07-07  NC            Re-added rX_TagFirstTag() and rX_TagNextTag() in backward compatibility section.
    2010-06-24  NC            File cleanup and consolidation of definitions.
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __RX_TAGLISTS_H
#define __RX_TAGLISTS_H



/*
*****************************************************************************
*   Include Files
*****************************************************************************
*/

#include "rX_Compiler.h"  /* basic data types */
#include "rX_Types.h"     /* basic data types */



/*
*****************************************************************************
*   Symbol Definitions
*****************************************************************************
*/

/* tag type code range offsets */
#define RCX_TAG_SPECIAL_START                   0x00000000
#define RCX_TAG_SPECIAL_END                     0x000007FF
#define RCX_TAG_GENERAL_START                   0x00000800
#define RCX_TAG_GENERAL_END                     0x00000FFF
#define RCX_TAG_NXO_START                       0x00001000
#define RCX_TAG_NXO_END                         0x0FFFFFFF
#define RCX_TAG_FACILITY_START                  0x10000000
#define RCX_TAG_FACILITY_END                    0x1FFFFFFF
#define RCX_TAG_USER_START                      0x20000000
#define RCX_TAG_USER_END                        0x2FFFFFFF
#define RCX_TAG_BSL_START                       0x40000000
#define RCX_TAG_BSL_END                         0x4FFFFFFF

/* tag type code modifiers */
#define RCX_TAG_IGNORE_FLAG                     0x80000000

/* tag type codes for special tags */
#define RCX_TAG_END_OF_LIST                     0x00000000

/* tag type codes for general tags */
#define RCX_TAG_MEMSIZE                         0x00000800
#define RCX_TAG_MIN_PERSISTENT_STORAGE_SIZE     0x00000801
#define RCX_TAG_MIN_OS_VERSION                  0x00000802
#define RCX_TAG_MAX_OS_VERSION                  0x00000803
#define RCX_TAG_MIN_CHIP_REV                    0x00000804
#define RCX_TAG_MAX_CHIP_REV                    0x00000805

/* tag type codes for firmware tags */
#define RCX_TAG_TASK_GROUP                      0x00001000
#define RCX_TAG_TASK                            0x00001003
#define RCX_TAG_INTERRUPT_GROUP                 0x00001020
#define RCX_TAG_INTERRUPT                       0x00001023
#define RCX_TAG_TIMER                           0x00001010
#define RCX_TAG_UART                            0x00001030
#define RCX_TAG_LED                             0x00001040
#define RCX_TAG_XC                              0x00001050
#define RCX_TAG_DPM_COMM_CHANNEL                0x00001060
#define RCX_TAG_DPM_SETTINGS                    0x00001061

/* tag type codes for the netX Diagnostics and Remote Access facility tags */
#define RCX_TAG_DIAG_IF_CTRL_UART               0x10820000
#define RCX_TAG_DIAG_IF_CTRL_USB                0x10820001
#define RCX_TAG_DIAG_IF_CTRL_TCP                0x10820002
#define RCX_TAG_DIAG_TRANSPORT_CTRL_CIFX        0x10820010
#define RCX_TAG_DIAG_TRANSPORT_CTRL_PACKET      0x10820011

/* tag type codes for the Ethernet Interface facility tags */
#define RCX_TAG_EIF_EDD_CONFIG                  0x105D0000
#define RCX_TAG_EIF_EDD_INSTANCE                0x105D0001



/* resource codes for LED tag */
#define RCX_LED_RESOURCE_TYPE_GPIO              1
#define RCX_LED_RESOURCE_TYPE_PIO               2
#define RCX_LED_RESOURCE_TYPE_HIFPIO            3

/* polarity codes for LED tag */
#define RCX_LED_POLARITY_NORMAL                 0
#define RCX_LED_POLARITY_INVERTED               1

/* maximum number of communication channels for DPM communication channels tag */
#define DPM_MAX_COMM_CHANNELS                   4


/* EDD type definitions for Ethernet Interface configuration tag */
#define RX_EIF_EDD_TYPE_VIRTUAL                 0   /* virtual EDD attached to TCP stack */
#define RX_EIF_EDD_TYPE_STD_MAC                 1   /* single-port standard Ethernet interface */
#define RX_EIF_EDD_TYPE_2PORT_SWITCH            2   /* 2-port switch */
#define RX_EIF_EDD_TYPE_2PORT_HUB               3   /* 2-port hub */


/* macro for setting DWORD alignment of a tag's beginning */
#define __DWORD_ALIGNED__   __attribute__ ((aligned (4)))

/* macro for forcing an instance of a tag list or single tag into a separate ".taglist" section (needed for NXFs) */
#define __SEC_TAGLIST__     __attribute__ ((section (".taglist")))



/*
*****************************************************************************
* Class, Type, and Structure Definitions
*****************************************************************************
*/

/* tag header with type code and length of following tag data */
typedef struct
{
  UINT32 ulTagType;
  UINT32 ulTagDataLength;
} RCX_TAG_HEADER_T __DWORD_ALIGNED__;


/* identifier string for named resources */
typedef struct
{
  STRING abName[16];
} RCX_TAG_IDENTIFIER_T;


/* End-of-list tag */
typedef struct
{
  RCX_TAG_HEADER_T tHeader;
} RCX_TAG_END_OF_LIST_T;


/* generic unsigned integer 32 tag used for RCX_TAG_MEMSIZE, RCX_TAG_MIN_PERSISTENT_STORAGE_SIZE, RCX_TAG_MIN_CHIP_REV, RCX_TAG_MAX_CHIP_REV */
typedef struct
{
  UINT32 ulValue;
} RCX_TAG_UINT32_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T      tHeader;
  RCX_TAG_UINT32_DATA_T tData;
} RCX_TAG_UINT32_T;


/* version information tag used for RCX_TAG_MIN_OS_VERSION and RCX_TAG_MAX_OS_VERSION */
typedef struct
{
  UINT16 usMajor;
  UINT16 usMinor;
  UINT16 usBuild;
  UINT16 usRevision;
} RCX_TAG_VERSION_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T       tHeader;
  RCX_TAG_VERSION_DATA_T tData;
} RCX_TAG_VERSION_T;


/* group of statically defined tasks: used to modify all RX_STATIC_TASK_T(s) with the same group reference number */
/* the priority and token values are ADDED to the statically defined values at system startup time, i.e. they serve as GROUP SPECIFIC OFFSETS */
typedef struct
{
  STRING szTaskListName[64];                /* group name, read-only */
  UINT32 ulBasePriority;                    /* base priority for the tasks in the group */
  UINT32 ulBaseToken;                       /* base token for the tasks in the group */
  UINT32 ulRange;                           /* number of tasks in the group, read-only */
  UINT32 ulTaskGroupRef;                    /* group reference number (common to all tasks in the group), read-only */
} RCX_TAG_TASK_GROUP_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T          tHeader;
  RCX_TAG_TASK_GROUP_DATA_T tData;
} RCX_TAG_TASK_GROUP_T;


/* task: used to modify an individual RX_STATIC_TASK_T */
/* the priority and token values REPLACE the statically defined values at system startup time, i.e. it serves as ABSOLUTE VALUES */
typedef struct
{
  RCX_TAG_IDENTIFIER_T  tIdentifier;        /* rcX task object identifier, read-only */
  UINT32                ulPriority;         /* task priority offset */
  UINT32                ulToken;            /* task token offset */
} RCX_TAG_TASK_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T      tHeader;
  RCX_TAG_TASK_DATA_T   tData;
} RCX_TAG_TASK_T;


/* group of statically defined interrupts: used to modify all RX_INTERRUPT_SET_T(s) with the same group reference number */
/* the priority and token values are ADDED to the statically defined values at system startup time, i.e. they serve as GROUP SPECIFIC OFFSETS */
typedef struct
{
  STRING szInterruptListName[64];           /* group name, read-only */
  UINT32 ulBaseIntPriority;                 /* base interrupt priority for the interrupts in the group */
  UINT32 ulRangeInt;                        /* number of interrupts in the group, read-only */
  UINT32 ulBaseTaskPriority;                /* base task priority if one of the handlers is configured to run in task mode */
  UINT32 ulBaseTaskToken;                   /* base task token if one of the handlers is configured to run in task mode */
  UINT32 ulRangeTask;                       /* number of interrupts in the group that execute in task mode, read-only */
  UINT32 ulInterruptGroupRef;               /* group reference number (common to all interrupts in the group), read-only */
} RCX_TAG_INTERRUPT_GROUP_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T               tHeader;
  RCX_TAG_INTERRUPT_GROUP_DATA_T tData;
} RCX_TAG_INTERRUPT_GROUP_T;


/* interrupt: used to modify an individual RX_INTERRUPT_SET_T */
/* the priority and token values REPLACE the statically defined values at system startup time, i.e. they serve as ABSOLUTE VALUES */
typedef struct
{
  RCX_TAG_IDENTIFIER_T  tIdentifier;        /* rcX interrupt object identifier, read-only */
  UINT32                ulInterruptPriority;/* interrupt priority offset */
  UINT32                ulTaskPriority;     /* interrupt handler task priority offset */
  UINT32                ulTaskToken;        /* interrupt handler task token offset */
} RCX_TAG_INTERRUPT_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T         tHeader;
  RCX_TAG_INTERRUPT_DATA_T tData;
} RCX_TAG_INTERRUPT_T;


/* timer: used to modify an RX_TIMER_SET_T */
/* the timer number value REPLACES the statically defined value at system startup time, i.e. it serves as an ABSOLUTE VALUE */
typedef struct
{
  RCX_TAG_IDENTIFIER_T tIdentifier;         /* rcX timer object identifier, read-only */
  UINT32               ulTimNum;            /* netX hardware timer number */
} RCX_TAG_TIMER_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T     tHeader;
  RCX_TAG_TIMER_DATA_T tData;
} RCX_TAG_TIMER_T;


/* UART: used to modify an RX_UART_SET_T */
/* the values REPLACE the statically defined values at system startup time, i.e. they serve as ABSOLUTE VALUES */
typedef struct
{
  RCX_TAG_IDENTIFIER_T tIdentifier;         /* rcX UART object identifier, read-only */
  UINT32               ulUrtNumber;         /* netX UART number (see rX_Config.h) */
  UINT32               ulBaudRate;          /* baud rate control code (see rX_Config.h) */
  UINT32               ulParity;            /* parity control code (see rX_Config.h) */
  UINT32               ulStopBits;          /* stop bits control code (see rX_Config.h) */
  UINT32               ulDataBits;          /* data bits control code (see rX_Config.h) */
  UINT32               ulRxFifoLevel;       /* "rx ready" trigger level for Rx FIFO (set to 0 to force immediate notification, set to 1..16 to enable FIFO) */
  UINT32               ulTxFifoLevel;       /* "tx empty" trigger level for Tx FIFO (set to 0 to force immediate send, set to 1..16 to enable FIFO */
  UINT32               ulRtsMode;           /* control code for RTS signal behavior (see rX_Config.h) */
  UINT32               ulRtsPolarity;       /* control code for RTS signal polarity (see rX_Config.h) */
  UINT32               ulRtsForerun;        /* RTS signal forerun with respect to TxD (in bits or in UART clock ticks depending on ulRtsMode) */
  UINT32               ulRtsTrail;          /* RTS signal trail with respect to TxD (in bits or in UART clock ticks depending on ulRtsMode) */
  UINT32               ulCtsMode;           /* control code for CTS signal behavior (see rX_Config.h) */
  UINT32               ulCtsPolarity;       /* control code for CTS signal polarity (see rX_Config.h) */
} RCX_TAG_UART_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T    tHeader;
  RCX_TAG_UART_DATA_T tData;
} RCX_TAG_UART_T;


/* LED: used to modify an RX_LED_SET_T */
/* the values REPLACE the statically defined values at system startup time, i.e. they serve as ABSOLUTE VALUES */
typedef struct
{
  RCX_TAG_IDENTIFIER_T tIdentifier;         /* rcX LED object identifier, read-only */
  UINT32               ulUsesResourceType;  /* RX_PERIPHERAL_TYPE_PIO or RX_PERIPHERAL_TYPE_GPIO (see rX_Config.h) */
  UINT32               ulPinNumber;         /* PIO or GPIO index number */
  UINT32               ulPolarity;          /* control code for GPIO polarity (see rX_Config.h) */
} RCX_TAG_LED_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T   tHeader;
  RCX_TAG_LED_DATA_T tData;
} RCX_TAG_LED_T;


/* xC: used to modify an RX_XC_SET_T */
/* the value REPLACES the statically defined value at system startup time, i.e. it serves as an ABSOLUTE VALUE */
typedef struct
{
  RCX_TAG_IDENTIFIER_T tIdentifier;         /* rcX xC object identifier, read-only */
  UINT32               ulXcId;              /* netX xC unit number */
} RCX_TAG_XC_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T  tHeader;
  RCX_TAG_XC_DATA_T tData;
} RCX_TAG_XC_T;


/* DPM communication channels: used to modify the RX_HIF_CHANNEL_Ts and the RX_HIF_CHANNEL_BLOCK_Ts describing communication channels */
/* the I/O data size values REPLACE the statically defined values at system startup time, i.e. they serve as ABSOLUTE VALUES */
/* the values are also used for calculating the start offsets of the subsequent channels and blocks */
typedef struct
{
  UINT32 ulNumCommChannels;                 /* number of communication channels to be instantiated (1 .. DPM_MAX_COMM_CHANNELS) */
  struct
  { /* total communication channel size is (0x1000 + ulInDataSize + ulOutDataSize) */
    UINT32 ulInDataSize;                    /* total size of the normal priority input data area (area 0) in bytes */
    UINT32 ulOutDataSize;                   /* total size of the normal priority output data area (area 0) in bytes */
  } atCommChannelSizes[DPM_MAX_COMM_CHANNELS];
} RCX_TAG_DPM_COMM_CHANNEL_DATA_T;


typedef struct
{
  RCX_TAG_HEADER_T                  tHeader;
  RCX_TAG_DPM_COMM_CHANNEL_DATA_T   tData;
} RCX_TAG_DPM_COMM_CHANNEL_T;


/* global DPM settings: used to modify the RX_HIF_SET_T describing DPM location and access */
/* the values REPLACE the statically defined values at system startup time */
typedef struct
{
  UINT32 ulDpmMode;                         /* DPM mode, 2 (8-bit) / 3 (16-bit) / 5 (PCI), default: 5) */
  UINT32 ulDpmSize;                         /* DPM size in bytes, default: 16384 for comX, 32768 for other targets) */
  UINT32 ulDpmBaseAddress;                  /* DPM base address (in INTRAM), default: 0x00018000) */
} RCX_TAG_DPM_SETTINGS_DATA_T;


typedef struct
{
  RCX_TAG_HEADER_T            tHeader;
  RCX_TAG_DPM_SETTINGS_DATA_T tData;
} RCX_TAG_DPM_SETTINGS_T;


/* UART interface of netX Diagnostics and Remote Access component */
typedef struct
{
  UINT8 bEnableFlag;                        /* TRUE: activate this interface, FALSE: do not use this interface */
  UINT8 bIfNumber;                          /* netX UART number to use */
  UINT8 abReserved[2];
} RCX_TAG_DIAG_IF_CTRL_UART_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T                 tHeader;
  RCX_TAG_DIAG_IF_CTRL_UART_DATA_T tData;
} RCX_TAG_DIAG_IF_CTRL_UART_T;


/* USB interface of netX Diagnostics and Remote Access component */
typedef struct
{
  UINT8 bEnableFlag;                        /* TRUE: activate this interface, FALSE: do not use this interface */
  UINT8 bIfNumber;                          /* netX USB interface number to use (currently, 0 is the only valid value) */
  UINT8 abReserved[2];
} RCX_TAG_DIAG_IF_CTRL_USB_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T                tHeader;
  RCX_TAG_DIAG_IF_CTRL_USB_DATA_T tData;
} RCX_TAG_DIAG_IF_CTRL_USB_T;


/* TCP interface of netX Diagnostics and Remote Access component */
typedef struct
{
  UINT8 bEnableFlag;                        /* TRUE: activate this interface, FALSE: do not use this interface */
  UINT8 bReserved;
  UINT16 usPortNumber;                      /* TCP port number, typically HIL_TRANSPORT_IP_PORT (50111, see HilTransport.h) */
} RCX_TAG_DIAG_IF_CTRL_TCP_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T                tHeader;
  RCX_TAG_DIAG_IF_CTRL_TCP_DATA_T tData;
} RCX_TAG_DIAG_IF_CTRL_TCP_T;


/* cifX transport interface of netX Diagnostics and Remote Access component */
typedef struct
{
  UINT8 bEnableFlag;                        /* TRUE: activate support for this transport type, FALSE: do not use this transport type */
  UINT8 abReserved[3];
} RCX_TAG_DIAG_TRANSPORT_CTRL_CIFX_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T                        tHeader;
  RCX_TAG_DIAG_TRANSPORT_CTRL_CIFX_DATA_T tData;
} RCX_TAG_DIAG_TRANSPORT_CTRL_CIFX_T;


/* packet transport interface of netX Diagnostics and Remote Access component */
typedef struct
{
  UINT8 bEnableFlag;                        /* TRUE: activate support for this transport type, FALSE: do not use this transport type */
  UINT8 abReserved[3];
} RCX_TAG_DIAG_TRANSPORT_CTRL_PACKET_DATA_T;

typedef struct
{
  RCX_TAG_HEADER_T                          tHeader;
  RCX_TAG_DIAG_TRANSPORT_CTRL_PACKET_DATA_T tData;
} RCX_TAG_DIAG_TRANSPORT_CTRL_PACKET_T;


/* Ethernet Interface component when used with run-time linking to an RTE communication stack */
typedef struct
{
  UINT32 ulEddInstanceNo;                   /* instance number of the EDD (0 .. (DPM_MAX_COMM_CHANNELS - 1)) */
} RCX_TAG_EIF_EDD_INSTANCE_DATA_T;


typedef struct
{
  RCX_TAG_HEADER_T                  tHeader;
  RCX_TAG_EIF_EDD_INSTANCE_DATA_T   tData;
} RCX_TAG_EIF_EDD_INSTANCE_T;


/* Ethernet Interface component when used without run-time linking to an RTE communication stack */
typedef struct
{
  UINT32 ulEddType;                         /* type of the EDD (see EDD type definitions for Ethernet Interface configuration) */
  UINT32 ulFirstXcNumber;                   /* number of the first (or the only) xC used */
} RCX_TAG_EIF_EDD_CONFIG_DATA_T;


typedef struct
{
  RCX_TAG_HEADER_T                  tHeader;
  RCX_TAG_EIF_EDD_CONFIG_DATA_T     tData;
} RCX_TAG_EIF_EDD_CONFIG_T;



/*
*****************************************************************************
*   Global Variables
*****************************************************************************
*/

/* none */



/*
*****************************************************************************
*   Macros
*****************************************************************************
*/

/* none */



/*
*****************************************************************************
*   Functions
*****************************************************************************
*/

/* none */



/*
*****************************************************************************
*   Backward Compatibility Definitions
*****************************************************************************
*/

/* tag type code modifiers */
#define RCX_MOD_TAG_IGNORE_FLAG                     RCX_TAG_IGNORE_FLAG

/* tag type codes for special tags */
#define RCX_MOD_TAG_END                             RCX_TAG_END_OF_LIST

/* tag type codes for general tags */
#define RCX_MOD_TAG_NUM_COMM_CHANNEL                0x00000806

/* tag type codes for NXO specific tags */
#define RCX_MOD_TAG_IT_STATIC_TASKS                 RCX_TAG_TASK_GROUP
#define RCX_MOD_TAG_IT_STATIC_TASK_PARAMETER_BLOCK  0x00001001
#define RCX_MOD_TAG_IT_STATIC_TASK_ENTRY            0x00001002
#define RCX_MOD_TAG_IT_TIMER                        RCX_TAG_TIMER
#define RCX_MOD_TAG_IT_INTERRUPT                    RCX_TAG_INTERRUPT_GROUP
#define RCX_MOD_TAG_IT_LED                          RCX_TAG_LED
#define RCX_MOD_TAG_IT_XC                           RCX_TAG_XC

/* resource codes for LED tag */
#define RCX_MOD_TAG_IT_LED_RESOURCE_TYPE_PIO        RCX_LED_RESOURCE_TYPE_PIO
#define RCX_MOD_TAG_IT_LED_RESOURCE_TYPE_GPIO       RCX_LED_RESOURCE_TYPE_GPIO
#define RCX_MOD_TAG_IT_LED_RESOURCE_TYPE_HIFPIO     RCX_LED_RESOURCE_TYPE_HIFPIO

/* polarity codes for LED tag */
#define RCX_MOD_TAG_IT_LED_POLARITY_NORMAL          RCX_LED_POLARITY_NORMAL
#define RCX_MOD_TAG_IT_LED_POLARITY_INVERTED        RCX_LED_POLARITY_INVERTED


/* tag header with type code and length of following tag data */
typedef RCX_TAG_HEADER_T                            RCX_MODULE_TAG_ENTRY_HEADER_T;

/* identifier string for named resources */
typedef RCX_TAG_IDENTIFIER_T                        RCX_MOD_TAG_IDENTIFIER_T;

/* generic unsigned integer 32 tag */
typedef RCX_TAG_UINT32_T                            RCX_MODULE_TAG_ENTRY_UINT32_T;

/* group of statically defined tasks: used to modify all RX_STATIC_TASK_T(s) with the same group reference number */
typedef RCX_TAG_TASK_GROUP_DATA_T                   RCX_MOD_TAG_IT_STATIC_TASKS_T;
typedef RCX_TAG_TASK_GROUP_T                        RCX_MOD_TAG_IT_STATIC_TASKS_TAG_T;

/* entry in a group of statically defined tasks: used to modify an RX_STATIC_TASK_T(s) within the group referenced by the group reference number */
typedef struct RCX_MOD_TAG_IT_STATIC_TASK_ENTRY_Ttag
{
  STRING szTaskName[16]; /* task name, read-only */
  UINT32 ulTaskGroupRef; /* group reference number (common to all tasks in the group), read-only */
  UINT32 ulPriority;     /* task priority (offset) relative to task group's base task priority */
  UINT32 ulToken;        /* task token (offset) relative to task group's base task token */
} RCX_MOD_TAG_IT_STATIC_TASK_ENTRY_T;

typedef struct RCX_MOD_TAG_IT_STATIC_TASK_ENTRY_TAG_Ttag
{
  RCX_MODULE_TAG_ENTRY_HEADER_T      tHeader;
  RCX_MOD_TAG_IT_STATIC_TASK_ENTRY_T tData;
} RCX_MOD_TAG_IT_STATIC_TASK_ENTRY_TAG_T;

/* generic task parameter block / substructure referenced by index */
typedef struct
{
  UINT32 ulSubstructureIdx;  /* read-only */
  UINT32 ulTaskIdentifier;   /* read-only, Task identifier as specified in TLR_TaskIdentifier.h */
  UINT32 ulParameterVersion; /* read-only, parameter version as specified by particular task */
} RCX_MOD_TAG_IT_STATIC_TASK_PARAMETER_BLOCK_T;

/* group of statically defined interrupts: used to modify all RX_INTERRUPT_SET_T(s) */
typedef RCX_TAG_INTERRUPT_GROUP_DATA_T              RCX_MOD_TAG_IT_INTERRUPT_T;
typedef RCX_TAG_INTERRUPT_GROUP_T                   RCX_MOD_TAG_IT_INTERRUPT_TAG_T;

/* timer: used to modify an RX_TIMER_SET_T */
typedef RCX_TAG_TIMER_DATA_T                        RCX_MOD_TAG_IT_TIMER_T;
typedef RCX_TAG_TIMER_T                             RCX_MOD_TAG_IT_TIMER_TAG_T;

/* LED: used to modify an RX_LED_SET_T */
typedef RCX_TAG_LED_DATA_T                          RCX_MOD_TAG_IT_LED_T;
typedef RCX_TAG_LED_T                               RCX_MOD_TAG_IT_LED_TAG_T;

/* xC: used to modify an RX_XC_SET_T */
typedef RCX_TAG_XC_DATA_T                           RCX_MOD_TAG_IT_XC_T;
typedef RCX_TAG_XC_T                                RCX_MOD_TAG_IT_XC_TAG_T;


/******************************************************************************
 * Function:  rX_TagNextTag
 *
 *              Advances to the next tag
 *
 * Input:       ptTagEntry                  - pointer to current tag entry
 *              pulRemainingTagListLength   - actual length of tag list left starting from current tag in bytes
 *
 * Result:      pointer to next tag or NULL
 */
static inline
const RCX_MODULE_TAG_ENTRY_HEADER_T*
rX_TagNextTag(const RCX_MODULE_TAG_ENTRY_HEADER_T* ptTagEntry, UINT32* pulRemainingTagListLength)
{
  UINT32 ulTagEntryLength;
  UINT32 ulPaddedTagEntryLength;

  while((ptTagEntry->ulTagType & (~RCX_MOD_TAG_IGNORE_FLAG)) != RCX_MOD_TAG_END)
  {
    ulTagEntryLength = ptTagEntry->ulTagDataLength + sizeof(RCX_MODULE_TAG_ENTRY_HEADER_T);

    ulPaddedTagEntryLength = ulTagEntryLength;

    ulPaddedTagEntryLength = (ulPaddedTagEntryLength + 3) & (~3);

    /* decrease remaining size of tag list */
    if(ulTagEntryLength < *pulRemainingTagListLength)
      *pulRemainingTagListLength -= ulTagEntryLength;
    else
    {
      *pulRemainingTagListLength = 0;
      ptTagEntry = NULL;
      break;
    }

    /* advance to next tag */
    ptTagEntry = (const RCX_MODULE_TAG_ENTRY_HEADER_T*) (((const UINT8*) ptTagEntry) + ulPaddedTagEntryLength);

    /* check if enough bytes are available */
    if(sizeof(RCX_MODULE_TAG_ENTRY_HEADER_T) > *pulRemainingTagListLength)
    {
      ptTagEntry = NULL;
      break;
    }

    /* check if entire tag can be considered valid */
    if(sizeof(RCX_MODULE_TAG_ENTRY_HEADER_T) + ptTagEntry->ulTagDataLength > *pulRemainingTagListLength)
    {
      ptTagEntry = NULL;
      break;
    }

    if(!(ptTagEntry->ulTagType & RCX_MOD_TAG_IGNORE_FLAG))
      break;
  }

  if(NULL != ptTagEntry)
  {
    /* end of list tag will set ptTagEntry to NULL */
    if((ptTagEntry->ulTagType & (~RCX_MOD_TAG_IGNORE_FLAG)) == RCX_MOD_TAG_END)
      ptTagEntry = NULL;
  }

  return ptTagEntry;
}


/******************************************************************************
 * Function:  rX_TagFirstTag
 *
 *              Start parsing of a tag list
 *
 * Input:       ptTagList                   - pointer to tag list
 *              pulRemainingTagListLength   - actual length of tag list in bytes
 *
 * Result:      pointer to next tag or NULL
 */
static inline
const RCX_MODULE_TAG_ENTRY_HEADER_T*
rX_TagFirstTag(const RCX_MODULE_TAG_ENTRY_HEADER_T* ptTagList, UINT32* pulRemainingTagListLength)
{
  const RCX_MODULE_TAG_ENTRY_HEADER_T* ptTagEntry = ptTagList;

  /* check if enough bytes are available */
  if(sizeof(RCX_MODULE_TAG_ENTRY_HEADER_T) > *pulRemainingTagListLength)
  {
    ptTagEntry = NULL;
  }

  /* check if entire tag can be considered valid */
  if(sizeof(RCX_MODULE_TAG_ENTRY_HEADER_T) + ptTagEntry->ulTagDataLength > *pulRemainingTagListLength)
  {
    ptTagEntry = NULL;
  }

  if(NULL != ptTagEntry)
  {
    if(ptTagEntry->ulTagType & RCX_MOD_TAG_IGNORE_FLAG)
      ptTagEntry = rX_TagNextTag(ptTagEntry, pulRemainingTagListLength);
  }

  return ptTagEntry;
}



#endif  /* __RX_TAGLISTS_H */
