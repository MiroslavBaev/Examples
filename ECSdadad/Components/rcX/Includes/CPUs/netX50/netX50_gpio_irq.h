/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: netX50_gpio_irq.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX50 GPIO Interrupt loss workaround

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-15  NC            File created.

******************************************************************************/


#ifndef __NETX50_TIMER_IRQ__H
#define __NETX50_TIMER_IRQ__H

typedef void(*PFN_GPIO_PRECLEAR_NOTIFICATION)(void* pvUser);
typedef void(*PFN_GPIO_POSTCLEAR_NOTIFICATION)(void* pvUser);

/* Callbacks that can be registered in global variables to insert a hook
   into the GPIO confirmation code. Chaining is not possible so only callback 
   can be registered */
extern PFN_GPIO_PRECLEAR_NOTIFICATION g_pfnConfirmGpioPreClear;
extern void*                          g_pvConfirmGpioPreClearUser;
extern PFN_GPIO_PRECLEAR_NOTIFICATION g_pfnConfirmGpioPostClear;
extern void*                          g_pvConfirmGpioPostClearUser;

/* GPIO confirmation function */
void netX50ConfirmGpioIrq(unsigned long ulConfirm, unsigned long ulMask);

#endif /* __NETX50_TIMER_IRQ__H */
