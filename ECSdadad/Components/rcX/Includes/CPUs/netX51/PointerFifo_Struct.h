/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: PointerFifo_Struct.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    netX Pointer FIFO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _POINTER_FIFO_STRUCT_H
#define _POINTER_FIFO_STRUCT_H

/*************************************************************************************/


/* structure map of netX GPIO registers */

typedef struct NETX_POINTER_FIFO_REGISTERS_Ttag
{
  volatile unsigned long aulData[32];
  volatile unsigned long aulBorder[32];
  volatile unsigned long ulReset;
  volatile unsigned long ulFull;
  volatile unsigned long ulEmpty;
  volatile unsigned long ulOverflow;
  volatile unsigned long ulUnderrun;
  volatile unsigned long aulReserved[27];
  volatile unsigned long aulFillLevel[32];
} NETX_POINTER_FIFO_REGISTERS_T;

typedef struct NETX_POINTER_FIFO_BASE_NO_DATA_Ttag
{
  volatile unsigned long aulBorder[32];
  volatile unsigned long ulReset;
  volatile unsigned long ulFull;
  volatile unsigned long ulEmpty;
  volatile unsigned long ulOverflow;
  volatile unsigned long ulUnderrun;
  volatile unsigned long aulReserved[27];
  volatile unsigned long aulFillLevel[32];
} NETX_POINTER_FIFO_BASE_NO_DATA_T;

#endif
