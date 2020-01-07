/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_SramBus.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    Standardized definitions of SRAM Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef AP_SRAMBUS_H_INCLUDED
#define AP_SRAMBUS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

RX_FATAL FAR SramBusInit(RX_SRAMBUS_SET_T* patSramCfg, UINT uEntries);

#ifdef __cplusplus
}
#endif

#endif // AP_SRAMBUS_H_INCLUDED
