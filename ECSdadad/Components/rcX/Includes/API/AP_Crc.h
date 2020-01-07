/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Crc.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of RRD Module (Resident Ram Disk)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_CRC_H
  #define __AP_CRC_H
 
  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  
  UINT32 Crc32(UINT32           ulCrc, 
               const UINT8 FAR* pbBuffer, 
               UINT32           ulLength);

  UINT8  CalcCrc7(UINT8 bCrc,
                  UINT8 bByte);

  UINT16 CalcCrc16CCIT(const unsigned char* pbData,
                       unsigned long        ulDataLen);
                         
#endif

#ifdef __cplusplus
}
#endif

