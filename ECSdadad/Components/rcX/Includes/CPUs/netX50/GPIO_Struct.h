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

#define GPIO_COUNT  32
#define TIMER_COUNT 5

/* structure map of netX GPIO registers */

typedef struct NETX_GPIO_REGISTERS_Ttag
{
  volatile unsigned long ulCfg[GPIO_COUNT];
  volatile unsigned long ulTc[GPIO_COUNT];
  volatile unsigned long ulCounterCtrl[TIMER_COUNT];
  volatile unsigned long ulCounterMax[TIMER_COUNT];
  volatile unsigned long ulCounter[TIMER_COUNT];
  volatile unsigned long ulSystimeCmp;
  volatile unsigned long ulLine;
  volatile unsigned long ulIn;
  volatile unsigned long ulGpioIrqRaw;
  volatile unsigned long ulGpioIrqMasked;
  volatile unsigned long ulGpioIrqMaskSet;
  volatile unsigned long ulGpioIrqMaskReset;
  volatile unsigned long ulCntIrqRaw;
  volatile unsigned long ulCntIrqMasked;
  volatile unsigned long ulCntIrqMaskSet;
  volatile unsigned long ulCntIrqMaskReset;
} NETX_GPIO_REGISTERS_T;

#endif
