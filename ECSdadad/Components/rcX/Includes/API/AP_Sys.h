/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Sys.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

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

#ifndef __AP_SYS_H
#define __AP_SYS_H

#ifdef __cplusplus
  extern "C" {
#endif

  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a hook
  ***************************************************************************/
  #define RX_HOOK_SIZE (16)

  /*********************************************************************
  * Timeout Parameter
  *********************************************************************/
  //TODO: We should change this to INFINITE=~0 and FINITE=0,
  //      but this would break usage as drop-in replacement when using
  //      old compiled libraries
  #define RX_INFINITE ((UINT)0)    /* Wait forever till event occurs */
  #define RX_FINITE   ((UINT)~0)   /* Just check if event is present */

  /*
  ***********************************************************
  *   System status structure
  ***********************************************************
  */
  typedef struct RX_SYSTEM_STATUS_Ttag {
    BOOLEAN fRun;       /* System is running, no task has an error */
    BOOLEAN fCom;       /* System is communicating */
    BOOLEAN fRdy;       /* System is ready initialized */
    BOOLEAN fHstNotRdy; /* Assigned Host application is not ready */
  } RX_SYSTEM_STATUS_T;
  
  /*************************************************************
  *   Function Prototypes
  *************************************************************/

  typedef RX_RESULT(CALLBACK FAR* PFN_RX_HOOK)(void FAR* pvData, void FAR* pvParam);
  typedef RX_RESULT(FAR* PFN_RX_HOOK_NOTIFY)(void FAR*,void FAR*);
  typedef void(CALLBACK FAR* PFN_RX_FATAL_VECTOR)(UINT uiFatalCode);

  RX_RESULT FAR   rX_SysCreateHookSystemStatus  (RX_HANDLE            hHook,
                                                 PFN_RX_HOOK          pfnHook,
                                                 void FAR*            pvParam);

  RX_RESULT FAR   rX_SysCreateHookLeave         (RX_HANDLE            hHook,
                                                 PFN_RX_HOOK          pfnHook,
                                                 void FAR*            pvParam);

  UINT FAR        rX_SysGetSystemCycletime      (void);

  UINT32 FAR      rX_SysGetSystemTicks          (void);

  UINT32 FAR      rX_SysGetCPUClockRate         (void);

  void FAR        rX_SysShutdown                (UINT32               ulTime);

  void FAR        rX_SysSetSystemTicks          (UINT32               ulTicks);

  UINT32 FAR      rX_SysGetOSVersion            (void);

  UINT FAR        rX_GetJumpTableBase           (void FAR*FAR*FAR*    ppJmpTblBase);

  /* vector handling for hooking into scheduler fatal error */
  RX_RESULT FAR   rX_SchedSetFatalVector        (PFN_RX_FATAL_VECTOR  pfnFatal);

  RX_RESULT FAR   rX_SchedGetFatalVector        (PFN_RX_FATAL_VECTOR* ppfnFatal);

  UINT FAR        rX_SysLockIrq                 (void);

  void FAR        rX_SysUnlockIrq               (void);

  UINT FAR        rX_SysInterlockExchange       (UINT FAR*            puMem,
                                                 UINT                 uNewValue);

  void FAR        rX_SysSpinLock                (UINT FAR*            puSpn);

  void FAR        rX_SysSpinUnlock              (UINT FAR*            puSpn);

#ifdef __cplusplus
  }
#endif

#endif /* __AP_SYS_H */
