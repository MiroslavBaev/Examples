/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:
   
    @version $Id: EscRcX_Public.h 22508 2012-02-24 18:48:27Z Richard $

   Description:

    EtherCAT Slave V4

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2012-05-04  RW            Created (copied from ../Tasks/HAL/netX50/OSAL/Includes)
**************************************************************************************/

#ifndef ESCRCX_PUBLIC_H_INCLUDED
#define ESCRCX_PUBLIC_H_INCLUDED

#include <stdint.h>   /* ISO C: uint8_t/uint16_t/uint32_t definitions */
#include <stdbool.h>  /* ISO C: "bool" definition */

#include "Esc_Public.h"

typedef struct ESC_CONFIG_SET_Ttag
{
  /* timer number (not used for netX51) */
  UINT uTimerNo;
  /* Pdi Config word */
  UINT16 usPdiConfig;
  /* Sync Impulse Length word */
  UINT16 usSyncImpulseLength;

  uint8_t                   bDcCtrlType;
  uint8_t                   bRunErrLedType;
} ESC_CONFIG_SET_T;


RX_FATAL Esc_RcX_Init(void* pvPer, UINT ulPer);

ESC_INTERFACE_HANDLE Esc_GetInterface(void);

#define ECS_PROCMEM_BYTE_SIZE 6400
#define ECS_MAX_CONFIGURABLE_MAILBOX_SIZE (ECS_PROCMEM_BYTE_SIZE / 2)
#define ECS_MAX_CONFIGURABLE_PROCESS_DATA_START_ADDRESS (ECS_PROCMEM_BYTE_SIZE + 0x1000 - 3)
#define ECS_DEFAULT_SM3_START_ADDRESS       0x1D00

typedef uint16_t ESC_SM_LENGTH_TYPE_T;

#endif // ESCRCX_PUBLIC_H_INCLUDED
