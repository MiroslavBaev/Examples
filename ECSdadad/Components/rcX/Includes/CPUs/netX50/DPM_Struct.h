/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: DPM_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX DPM definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _DPM_STRUCT_H
#define _DPM_STRUCT_H


/*************************************************************************************/


/* structure map of netX GPIO registers */

typedef struct NETX_DPM_IRQ_REGISTERS_Ttag
{
  volatile unsigned long aulIrqStatus[4];
  volatile unsigned long aulIrqEnable[4];
} NETX_DPM_IRQ_REGISTERS_T;

typedef struct NETX_DPM_MAPPING_BLOCK_Ttag
{
  volatile unsigned long ulEndAddress;
  volatile unsigned long ulMapAddress;
} NETX_DPM_MAPPING_BLOCK_T;

typedef struct NETX_DPM_ARM_GLOBAL_REG_BLOCK_Ttag
{
  volatile unsigned long ulReserved;
  volatile unsigned long ulClockOutReg;
  volatile unsigned long ulIfConf[2];
  volatile unsigned long ulExpBusReg;
  volatile unsigned long aulReserved[3];
  volatile unsigned long ulIoRegMode0;
  volatile unsigned long ulIoRegDriverEnable0;
  volatile unsigned long ulIoRegData0;
  volatile unsigned long ulIoRegReserved0;
  volatile unsigned long ulIoRegMode1;
  volatile unsigned long ulIoRegDriverEnable1;
  volatile unsigned long ulIoRegData1;
  volatile unsigned long ulIoRegReserved1;
  NETX_DPM_MAPPING_BLOCK_T  atBlockMap[8];
  volatile unsigned long ulHandshakeControl[16];
} NETX_DPM_ARM_GLOBAL_REG_BLOCK_T;

#endif
