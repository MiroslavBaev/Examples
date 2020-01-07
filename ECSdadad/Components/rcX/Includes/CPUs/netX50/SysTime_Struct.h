/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: SysTime_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX SYSTIME definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _SYSTIME_STRUCT_H
#define _SYSTIME_STRUCT_H


/*************************************************************************************/


/* structure map of netX GPIO registers */

typedef struct NETX_SYS_TIME_REGISTERS_Ttag
{
  volatile unsigned long ulSystimeNs;
  volatile unsigned long ulSystimeS;
  volatile unsigned long ulSystimeBorder;
  volatile unsigned long ulSystimeNsAddUp;
  volatile unsigned long ulSystimeSCompare;
  volatile unsigned long ulSystimeSCompareEnable;
  volatile unsigned long ulSystimeSCompareIrq;
} NETX_SYS_TIME_REGISTERS_T;

#endif
