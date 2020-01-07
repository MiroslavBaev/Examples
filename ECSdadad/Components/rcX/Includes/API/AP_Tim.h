/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Tim.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX software timer function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_TIM_H
#define __AP_TIM_H

#ifdef __cplusplus
  extern "C" {
#endif

  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a timer / cycle
  ***************************************************************************/
  #define RX_TIMER_SIZE (80)
  #define RX_CYCLIC_SIZE (80)

  /*************************************************************
  *  Timer Function Definition
  *************************************************************/
  #define RX_TIM_AUTO_STOP    (1)
  #define RX_TIM_AUTO_RELOAD  (2)
  #define RX_TIM_AUTO_DELETE  (3)

  /*************************************************************
  *   Function Prototypes
  *************************************************************/
  typedef void(CALLBACK FAR* PFN_RX_TIMER_CBK)(void FAR* pvParam);
  
  RX_FATAL  FAR rXTimerInit         (UINT uTimerTaskPriority,
                                     UINT uTimerTaskStackSize,
                                     UINT uTimerWheelSize);

  int       FAR rXTimerSize         (void);
                                       
  RX_RESULT FAR rX_TimCreateTimer   (RX_HANDLE              hTimer,
                                     PFN_RX_TIMER_CBK       pfnCallback,
                                     void FAR*              pvParam,
                                     INT                    iTimeFunc,
                                     UINT                   uTimeTickReload,
                                     UINT                   uStartTickDelay);

  RX_RESULT FAR rX_TimWaitForCycle  (RX_HANDLE              hCycle);

  RX_RESULT FAR rX_TimResetTimer    (RX_HANDLE              hTimer);

  RX_RESULT FAR rX_TimStopTimer     (RX_HANDLE              hTimer);

  RX_RESULT FAR rX_TimHaltTimer     (RX_HANDLE              hTimer);

  RX_RESULT FAR rX_TimResumeTimer   (RX_HANDLE              hTimer);

  RX_RESULT FAR rX_TimDeleteTimer   (RX_HANDLE              hTimer);

  RX_RESULT FAR rX_TimGetTime       (RX_HANDLE              hTimer,
                                     UINT FAR*              puCurVal);

  RX_RESULT FAR rX_TimSetTime       (RX_HANDLE              hTimer,
                                     UINT                   uNewVal);

  RX_RESULT FAR rX_TimSetReload     (RX_HANDLE              hTimer,
                                     UINT                   uNewReloadTicks);


  RX_RESULT FAR rX_TimCreateCycle   (const STRING FAR*      pszIdn,
                                     RX_HANDLE              hCycle,
                                     UINT                   uTime);

  RX_RESULT FAR rX_TimDeleteCycle   (RX_HANDLE              hCycle);

  RX_RESULT FAR rX_TimResetCycle    (RX_HANDLE              hCycle);


#ifdef __cplusplus
  }
#endif

#endif /* __AP_TIM_H */
