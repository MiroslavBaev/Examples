/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: Miimu_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX MIIMU definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _MIIMU_STRUCT_H
#define _MIIMU_STRUCT_H


/*************************************************************************************/


/* structure map of netX MIIMU registers */

typedef struct NETX_MIIMU_REGISTERS_Ttag
{
  volatile unsigned long ulData;
  volatile unsigned long ulSoftwareModeEnable;
  volatile unsigned long ulSoftwareMdc;
  volatile unsigned long ulSoftwareMdo;
  volatile unsigned long ulSoftwareMdoe;
  volatile unsigned long ulSoftwareMdi;
} NETX_MIIMU_REGISTERS_T;

#endif
