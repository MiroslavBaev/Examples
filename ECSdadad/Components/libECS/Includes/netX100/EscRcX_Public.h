/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:
   
    @version $Id: EscRcX_Public.h 57310 2015-11-09 14:15:28Z Sven $

   Description:

    EtherCAT Slave V4

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2010-03-24  SB            Created
**************************************************************************************/

#ifndef ESCRCX_PUBLIC_H_INCLUDED
#define ESCRCX_PUBLIC_H_INCLUDED

#include "Esc_Public.h"

typedef struct ESC_CONFIG_SET_Ttag
{
  /* timer number used for ECAT_PDWDG */
  UINT uTimerNo;
  /* Pdi Config word */
  UINT16 usPdiConfig;
  /* Sync Impulse Length word */
  UINT16 usSyncImpulseLength;
  /* netX100 extended Pdi Config word */
  UINT16 usExtPdiConfig;  /* upper 16 bits */
} ESC_CONFIG_SET_T;

/* usExtPdiConfig */
#define MSK_ESC_EXT_PDI_CONFIG_SYNC_PINS_CONTROLLED_BY_ARM    0x8000    /* only netX100/netX500 */
#define MSK_ESC_EXT_PDI_CONFIG_DC_DISABLED                    0x4000    /* only netX100/netX500 */

RX_FATAL Esc_RcX_Init(void* pvPer, UINT ulPer);

ESC_INTERFACE_HANDLE Esc_GetInterface(void);

#define ECS_PROCMEM_BYTE_SIZE 1792
#define ECS_MAX_CONFIGURABLE_MAILBOX_SIZE (ECS_PROCMEM_BYTE_SIZE / 2)
#define ECS_MAX_CONFIGURABLE_PROCESS_DATA_START_ADDRESS (ECS_PROCMEM_BYTE_SIZE + 0x1000 - 4)
#define ECS_DEFAULT_SM3_START_ADDRESS       0x1400

typedef UINT ESC_SM_LENGTH_TYPE_T;

#endif // ESCRCX_PUBLIC_H_INCLUDED
