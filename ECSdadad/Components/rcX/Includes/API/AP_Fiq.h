/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Fiq.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Fast Interrupt Driver Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_FIQ_H
  #define __AP_FIQ_H
  
 /*
  **************************************************************************
  *   Size of one Interrupt Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  #define DRV_FIQ_SIZE (52)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */

  typedef void(CALLBACK FAR* APP_FIQ_HANDLER)(void); 
  
  RX_FATAL FAR    DrvFiqInit                  (const FAR void FAR*      pvCfg,
                                               UINT                     uNum); 

  RX_RESULT FAR   Drv_FiqCreateInterrupt      (RX_HANDLE                hFiq,
                                               const RX_FIQ_SET_T FAR*  ptCfg); 
  
  RX_RESULT FAR   Drv_FiqIdentifyInterrupt    (STRING FAR*              pszIdn,
                                               UINT                     uInst,
                                               RX_HANDLE FAR*           phInt); 

  RX_RESULT FAR   Drv_FiqInitializeInterrupt  (RX_HANDLE                hFiq,
                                               APP_FIQ_HANDLER          fnAppISR); 
                                           
  RX_RESULT FAR   Drv_FiqEnableInterrupt      (RX_HANDLE                hFiq);
  RX_RESULT FAR   Drv_FiqDisableInterrupt     (RX_HANDLE                hFiq);
  
#endif

#ifdef __cplusplus
}
#endif
