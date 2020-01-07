/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: PIO_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX PIO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _PIO_STRUCT_H
#define _PIO_STRUCT_H


/*************************************************************************************/


/* structure map of netX GPIO registers */

typedef struct NETX_PIO_REGISTERS_Ttag
{
  volatile unsigned long ulIn;
  volatile unsigned long ulOut;
  volatile unsigned long ulOutputEnable;
} NETX_PIO_REGISTERS_T;

#endif
