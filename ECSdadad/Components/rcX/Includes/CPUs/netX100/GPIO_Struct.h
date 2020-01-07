/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: GPIO_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX GPIO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _GPIO_STRUCT_H
#define _GPIO_STRUCT_H


/*************************************************************************************/


/* structure map of netX GPIO registers */

typedef struct NETX_GPIO_REGISTERS_Ttag
{
  volatile unsigned long ulCfg[16];
  volatile unsigned long ulTc[16];
  volatile unsigned long ulCounterCtrl[5];
  volatile unsigned long ulCounterMax[5];
  volatile unsigned long ulCounter[5];
  volatile unsigned long ulIrqMaskSet;
  volatile unsigned long ulIrqMaskReset;
  volatile unsigned long ulSystimeCmp;
  volatile unsigned long ulLine;
  volatile unsigned long ulIn;
  volatile unsigned long ulIrq;
} NETX_GPIO_REGISTERS_T;

#endif
