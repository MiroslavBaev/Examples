/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: VIC_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX VIC definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _VIC_STRUCT_H
#define _VIC_STRUCT_H


/*************************************************************************************/


/* structure map of netX VIC registers */

typedef struct NETX_VIC_BASE_Ttag
{
  volatile unsigned long ulIrqStatus;
  volatile unsigned long ulFiqStatus;
  volatile unsigned long ulRawIntr;
  volatile unsigned long ulIntSelect;
  volatile unsigned long ulIntEnable;
  volatile unsigned long ulIntEnclear;
  volatile unsigned long ulSoftint;
  volatile unsigned long ulSoftintClear;
  volatile unsigned long ulProtection;
  volatile unsigned long ulReserved[3];
  volatile unsigned long ulVectAddr;
  volatile unsigned long ulDefVectAddr;
  volatile unsigned long ulReservedB[50];
  volatile unsigned long aulVectAddr[16];
  volatile unsigned long ulReservedC[48];
  volatile unsigned long aulVectCntl[16];
} NETX_VIC_BASE_T;

#endif
