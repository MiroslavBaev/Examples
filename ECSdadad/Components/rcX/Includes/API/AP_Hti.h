/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Hti.h 1058 2012-08-17 09:43:48Z stephans $

  Description:
    USER - Headerfile of Hardware-Timer Driver Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_HTI_H
  #define __AP_HTI_H
  
 /*
  ******************************************************************************
  *   Size of one Hardware Timer Control Block a Task has to allocate memory for
  ******************************************************************************
  */ 
  
  #define DRV_HWTIMER_SIZE (64)
  
  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  
  RX_FATAL FAR    DrvTimerInit                  (const FAR void FAR*          pvCfg,
                                                 UINT                         uNum); 

  RX_RESULT FAR   Drv_TimCreateTimer            (RX_HANDLE                    hTimer,
                                                 const RX_HWTIMER_SET_T FAR*  ptCfg); 

  RX_RESULT FAR   Drv_TimIdentifyTimer          (const STRING FAR*            pszIdn,
                                                 UINT                         uInst,
                                                 RX_HANDLE FAR*               phTimer);

  RX_RESULT FAR   Drv_TimInitializeTimer        (RX_HANDLE                    hTimer); 

  RX_RESULT FAR   Drv_TimGetTime                (RX_HANDLE                    hTimer,
                                                 UINT32 FAR*                  pulTime);

  RX_RESULT FAR   Drv_TimGetConfig              (RX_HANDLE                    hTimer,
                                                 RX_HWTIMER_SET_T FAR*        ptCfg);
                                     
  RX_RESULT FAR   Drv_TimStartTimer             (RX_HANDLE                    hTimer);
    
  RX_RESULT FAR   Drv_TimStopTimer              (RX_HANDLE                    hTimer); 
  
  RX_RESULT FAR   Drv_TimReleaseTimerInterrupt  (RX_HANDLE                    hTimer); 

  RX_RESULT FAR   Drv_TimDeleteTimer            (RX_HANDLE                    hTimer); 
  
  RX_RESULT FAR   Drv_TimSetPeriod              (RX_HANDLE                    hTimer,
                                                 UINT                         uPeriod);
#endif
  
#ifdef __cplusplus
}
#endif
