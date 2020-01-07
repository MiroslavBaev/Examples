/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Task.h 1158 2012-12-21 10:12:02Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-12-21 11:12:02 +0100 (Fri, 21 Dec 2012) $
    $Revision: 1158 $

   Targets:
     rcX      : yes

   Description:
      rcX task function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_TASK_H
#define __AP_TASK_H

#ifdef __cplusplus
  extern "C" {
#endif
  
  /*************************************************************
  *   Task Startmode 
  *************************************************************/ 
  
  #define RX_TASK_AUTO_START 0           /* Task starts automatically         */
  #define RX_TASK_AUTO_STOP  1           /* Task is created in suspended mode */
  #define RX_TASK_AUTO_START_INIT_WAIT 2 /* Task starts automatically but blocks at rX_SysSetTaskInitialized until all other tasks with this mode reach this point */

  typedef void(FAR* PFN_RX_TASK_ENTER)(void FAR* pvParam);
  typedef void(FAR* PFN_RX_TASK_LEAVE)(void FAR* pvParam);
  
  /*************************************************************
  *   Function Prototypes
  *************************************************************/ 
  RX_RESULT FAR   rX_SysCreateTask              (const STRING FAR*  pszTskName,
                                                 PFN_RX_TASK_ENTER  pfnTaskEnter,
                                                 void FAR*          pvParam, 
                                                 void FAR*          pvStack,
                                                 UINT               uStackSize,
                                                 UINT               uStartMod,
                                                 UINT16             eThreshold,
                                                 UINT16             ePriority,
                                                 UINT16             eToken,
                                                 UINT               uInstance,
                                                 PFN_RX_TASK_LEAVE  pfnTaskLeave);

  RX_RESULT FAR   rX_SysCreateTaskEx            (const STRING FAR*  pszTskName,
                                                 PFN_RX_TASK_ENTER  pfnTaskEnter,
                                                 void FAR*          pvParam, 
                                                 void FAR*          pvStack,
                                                 UINT               uStackSize,
                                                 UINT               uStartMod,
                                                 UINT16             eThreshold,
                                                 UINT16             ePriority,
                                                 UINT16             eToken,
                                                 UINT               uInstance,
                                                 PFN_RX_TASK_LEAVE  pfnTaskLeave,
                                                 RX_HANDLE FAR*     phTask);
   
  RX_RESULT FAR   rX_SysIdentifyTask            (const STRING FAR*  pszTskName,
                                                 UINT               uInstance,
                                                 RX_HANDLE FAR*     phTask,
                                                 UINT16 FAR*        peToken,
                                                 UINT16 FAR*        pePriority); 

  RX_RESULT FAR   rX_SysDeleteTask              (RX_HANDLE          hTask,
                                                 UINT               uTicks); 

  RX_RESULT FAR   rX_SysWakeupTask              (RX_HANDLE          hTask); 
  
  RX_RESULT FAR   rX_SysResumeTask              (RX_HANDLE          hTask); 
  
  RX_RESULT FAR   rX_SysBlockTask               (RX_HANDLE          hTask); 
  
  RX_RESULT FAR   rX_SysChangePriority          (RX_HANDLE          hTask,
                                                 UINT16             eNewPriority); 

  RX_HANDLE FAR   rX_SysGetOwnTaskHandle        (void);
  UINT FAR        rX_SysGetOwnInstance          (void);  
  RX_RESULT       rX_SysGetTaskRuntime          (RX_HANDLE hTask, UINT64* pullRuntime);
  
  UINT32 FAR      rX_SysSleepTask               (UINT32             ulTicks);   
  UINT32 FAR      rX_SysDelayTaskUntil          (UINT32             uSysTick);
  
  void FAR        rX_SysLockScheduler           (void); 
  
  void FAR        rX_SysUnlockScheduler         (void);

  void FAR        rX_SysSetTaskInitialized      (void FAR*          pvInpt);

  void FAR        rX_SysTerminateTask           (UINT32             ulReasonCode);

  RX_RESULT FAR   rX_SysSetTimeSliceParameters  (RX_HANDLE          hTask,
                                                 UINT               uTssMaxQuantum,
                                                 UINT               uTssAutoSleepTime);
                                                 
  RX_RESULT FAR   rX_SysGetTimeSliceParameters  (RX_HANDLE          hTask,
                                                 UINT FAR*          puTssElapsedQuantum,
                                                 UINT FAR*          puTssMaxQuantum,
                                                 UINT FAR*          puTssAutoSleepTime);

#ifdef __cplusplus
  }
#endif

#endif /* __AP_TASK_H */
