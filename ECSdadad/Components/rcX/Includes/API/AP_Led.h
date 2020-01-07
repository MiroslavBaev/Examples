/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Led.h 1317 2013-03-04 15:49:03Z stephans $

  Description:
    Standardized definitions of RX LEDs

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_LED_H
  #define __AP_LED_H

 /*
  **************************************************************************
  *   Size of one LED Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  
  #define DRV_LED_SIZE (124)
                        
 /*
  **************************************************************************
  *   Type declarations
  **************************************************************************
  */ 

  enum LED_MODEtag {
  
    LED_MODE_OFF = 1,
    LED_MODE_ON,
    LED_MODE_BLINKING,
    LED_MODE_ONCE,
    LED_MODE_SCRIPT, /* not be set by other means than Mid_LedSetScript */
  };
  typedef int LED_MODE_T;

  typedef struct LED_SCRIPT_ENTRY_Ttag
  {
    BOOLEAN fLedEnable;
    UINT32 ulMillisecs; /* last entry must be zero */
  } LED_SCRIPT_ENTRY_T;

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  
  RX_FATAL FAR    DrvLedInit                    (const FAR void FAR*        pvCfg, 
                                                 UINT                       uNum);
                                                 
  RX_RESULT FAR   Drv_LedCreateLed              (RX_HANDLE                  hLed,
                                                 const RX_LED_SET_T FAR*    ptCfg);
                                                 
  RX_RESULT FAR   Drv_LedIdentifyLed            (const STRING FAR*          pszIdn,
                                                 UINT                       uInst,
                                                 RX_HANDLE FAR*             phLed);
                                                 
  RX_RESULT FAR   Drv_LedSetLed                 (RX_HANDLE                  hLed);
                                                 
  RX_RESULT FAR   Drv_LedClearLed               (RX_HANDLE                  hLed);
                                                 
  RX_RESULT FAR   Drv_LedInvertLed              (RX_HANDLE                  hLed);
                                                 
  RX_RESULT FAR   Drv_LedInitializeLed          (RX_HANDLE                  hLed);
                                                 
  /* Middleware Led component */                 
  RX_RESULT FAR   MidLedInit                    (void FAR*                  pvPar,
                                                 UINT                       uPar);
                                                 
  RX_RESULT FAR   Mid_LedCreateLed              (const STRING FAR*          pszIdn,
                                                 UINT                       uInst,
                                                 RX_HANDLE  FAR*            hLed);
                                                 
  RX_RESULT FAR   Mid_LedGetState               (RX_HANDLE                  hLed,
                                                 LED_MODE_T FAR*            peMode,
                                                 BOOL FAR*                  pfLedIsOn);
                                                 
  RX_RESULT FAR   Mid_LedSetState               (RX_HANDLE                  hLed,
                                                 LED_MODE_T                 eMode,
                                                 UINT                       uiCycleTime,
                                                 UINT                       uiOnOffRatio);
                                                 
  RX_RESULT FAR   Mid_LedSetScript              (RX_HANDLE                     hLed,
                                                 const LED_SCRIPT_ENTRY_T FAR* ptLedScript,
                                                 UINT                          uiEntries);
                                                 
  RX_RESULT FAR   Mid_LedReleaseLed             (RX_HANDLE                  hLed);

  /* Driver LED function set functions */

  RX_RESULT       Drv_GpioSetupLedOperations    (RX_LED_FUNCTION_SET_T FAR* ptSet);

  RX_RESULT       Drv_PioSetupLedOperations     (RX_LED_FUNCTION_SET_T FAR* ptSet);

  RX_RESULT       Drv_HifPioSetupLedOperations  (RX_LED_FUNCTION_SET_T FAR* ptSet);

  RX_RESULT       Drv_IOSetupLedOperations      (RX_LED_FUNCTION_SET_T FAR* ptSet);

#endif

#ifdef __cplusplus
}
#endif
