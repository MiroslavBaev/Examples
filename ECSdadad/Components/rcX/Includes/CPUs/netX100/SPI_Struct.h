/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: SPI_Struct.h 1553 2013-08-06 06:31:14Z MichaelT $

  Description:
    netX SPI definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef __SPI_STRUCT_H__
#define __SPI_STRUCT_H__

typedef struct NETX_SPI_REGISTERS_Ttag {
  volatile unsigned long ulData;
  volatile unsigned long ulStatus;
  volatile unsigned long ulControl;
  volatile unsigned long ulInterruptControl;
} NETX_SPI_REGISTERS_T, *PNETX_SPI_REGISTERS_T;

#endif /* __SPI_STRUCT_H__ */

/*************************************************************************************/
