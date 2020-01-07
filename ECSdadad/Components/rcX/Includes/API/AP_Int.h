/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Int.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Interrupt Driver Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_INT_H
  #define __AP_INT_H
  
 /*
  **************************************************************************
  *   Size of one Interrupt Control Block a Task has to allocate memory for
  **************************************************************************
  */ 

  #define DRV_INTERRUPT_SIZE (80)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  
  typedef void(*APP_ISR_HANDLER)(RX_HANDLE hInt, void FAR* pvPrm); 
  
  RX_FATAL FAR DrvInterruptInit                 (const FAR void FAR*              pvCfg,
                                                 UINT                             uNum); 

  RX_RESULT FAR Drv_IntCreateInterrupt          (RX_HANDLE                        hInt,
                                                 const RX_INTERRUPT_SET_T FAR*    ptCfg); 
  
  RX_RESULT FAR Drv_IntIdentifyInterrupt        (const STRING FAR*                pszIdn,
                                                 UINT                             uInst,
                                                 RX_HANDLE FAR*                   phInt); 

  RX_RESULT FAR Drv_IntInitializeInterrupt      (RX_HANDLE                        hInt,
                                                 void (CALLBACK FAR*              fnAppISR)(RX_HANDLE hInt,void FAR* pvPrm),
                                                 void FAR*                        pvPrm); 

  RX_RESULT FAR Drv_IntUninitializeInterrupt    (RX_HANDLE                        hInt); /* Un-Installs a Hardware interrupt */
  
  RX_RESULT FAR Drv_IntDisableInterrupt         (RX_HANDLE                        hInt);
  
  RX_RESULT FAR Drv_IntEnableInterrupt          (RX_HANDLE                        hInt); 

  RX_RESULT FAR Drv_IntDeleteInterrupt          (RX_HANDLE                        hInt);

  RX_RESULT FAR Drv_IntEndOfInterrupt           (RX_HANDLE                        hInt); 

  RX_RESULT FAR Drv_IntGenerateInterrupt        (RX_HANDLE                        hInt); 

  RX_RESULT FAR Drv_IntConfirmInterrupt         (RX_HANDLE                        hInt); 
  
  RX_RESULT FAR Drv_IntSetCommonPriorityLevel   (BOOLEAN                          fDef,
                                                 UINT                             uPrio); 
    
#endif

#ifdef __cplusplus
}
#endif
