/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Sfl.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Serial FLASH Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-03-14  MT            Removed non-implemented function prototypes
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_SFL_H
  #define __AP_SFL_H
  
  /*
  ******************************************************************************
  *   Size of one Serial FLASH Control Block a Task has to allocate memory for
  ******************************************************************************
  */ 
  #define DRV_SERFLASH_SIZE (152)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
    
  RX_FATAL FAR    DrvSFlsInit                 (const FAR void FAR*                pvCfg,
                                               UINT                               uNum); 

  RX_RESULT FAR   Drv_SflCreateFlash          (RX_HANDLE                          hFlash,
                                               const RX_SERIALFLASH_SET_T FAR*    ptCfg); 

  RX_RESULT FAR   Drv_SflIdentifyFlash        (const STRING FAR*                  pszIdn,
                                               UINT                               uInst,
                                               RX_HANDLE FAR*                     phFlash); 

  RX_RESULT       Drv_SflInitializeFlash      (RX_HANDLE                          hFlash); 

  RX_RESULT       Drv_SflWriteFlash           (RX_HANDLE                          hFlash,
                                               UINT32                             ulOffset,
                                               const UINT8 HUGE*                  pabSrc,
                                               UINT32                             ulNum);

  RX_RESULT       Drv_SflReadFlash            (RX_HANDLE                          hFlash,
                                               UINT32                             ulOffs,
                                               UINT8 HUGE*                        pabDest,
                                               UINT32                             ulNum);

  RX_RESULT       Drv_SflEraseFlash           (RX_HANDLE                          hFlash,
                                               UINT32                             ulStartAddr,
                                               UINT32                             ulLen);

  RX_RESULT       Drv_SflEraseFlashPage       (RX_HANDLE                          hFlash,
                                               UINT32                             ulPage);

  RX_RESULT FAR   Drv_SflEraseFlashDevice     (RX_HANDLE                          hFlash);

#endif  

#ifdef __cplusplus
}
#endif
