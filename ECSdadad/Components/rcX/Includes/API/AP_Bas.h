/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Bas.h 935 2012-05-09 13:34:16Z stephans $

  Description:
    USER - Headerfile of Basic Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/

#ifndef __AP_BAS_H
#define __AP_BAS_H

#ifdef __cplusplus
extern "C" {
#endif
  
  
/*
************************************************************
*   Function Prototypes
************************************************************
*/ 
  void FAR* FAR         rX_BasCopyString         (void FAR*          pbDest, 
                                                  const void FAR*    pvStr);

  UINT FAR              rX_BasGetStringLength    (const STRING FAR*  pvStr);
  
  const UINT8 FAR* FAR  rX_BasCompareMemory      (const UINT8 FAR*   pbDest,
                                                  const UINT8 FAR*   pbSrc,
                                                  UINT               uCnt);
                                            
  const UINT16 FAR* FAR rX_BasCompareMemoryWords (const UINT16 FAR*  pusDest,
                                                  const UINT16 FAR*  pusSrc,
                                                  UINT               uCnt);

  void FAR              rX_BasCopyMemory         (UINT8 FAR*         pbDest,
                                                  const UINT8 FAR*   pbSrc,
                                                  UINT               uCnt);

  void FAR              rX_BasCopyMemoryWords    (UINT16 FAR*        pusDest,
                                                  const UINT16 FAR*  pusSrc,
                                                  UINT               uCnt);

  void FAR              rX_BasSetMemory          (UINT8 FAR*         pbDest,
                                                  UINT8              bData,
                                                  UINT               uCnt);

  void FAR              rX_BasSetMemoryWords     (UINT16 FAR*        pusDest,
                                                  UINT16             usData,
                                                  UINT               uCnt);

  void FAR              rX_BasMemCpyFast         (void FAR*          pvDst,
                                                  const void FAR*    pvSrc,
                                                  UINT32             ulByteCnt);

#ifdef __cplusplus
}
#endif

#endif /* __AP_BAS_H */
