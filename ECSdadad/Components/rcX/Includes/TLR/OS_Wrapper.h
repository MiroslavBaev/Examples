/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: OS_Wrapper.h 1016 2012-07-26 11:03:39Z MichaelT $

  Description:
    Wrapper for operating systems to include in TLR

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-07-20  NC            Removed NULL pointer access in TLR_LCK_CREATE().
                              Corrected indirection level of packet pointer
                              in TLR_QUE_WAITFORPACKET and in TLR_POOL_PACKET_GET().

    2010-05-05  NC            Removed cpp comments and old excluded stuff

    2010-04-26  NC            Avoid (GNU) compilers warning "dereferencing
                              type-punned pointer will break strict-aliasing
                              rules" - change cast "TLR_VOID FAR* FAR* to
                              "TLR_VOID FAR*"

    2010-04-14  NC            Changed Parameter names corresponding to the
                              manual (uTicks --> uTimeout)
                              Added casts for TLR_SIG_xx macros

    2010-04-07  NC            Changed Parameter names corresponding to the
                              manual

    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __OS_WRAPPER_H
#define __OS_WRAPPER_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/

#ifdef __RCX__
  /* includes header files of OPERATING SYSTEM rcX */
  #include "rX_Includes.h"
  #include "stdlib.h"
  #include "OS_rX_Wrapper.h"
  #include "LIB_Wrapper.h"        /* wrapper for standard C library functions */
#endif

#ifdef __TLR_USE_LIBC_WRAPPER__
  #include "LIB_Wrapper.h"        /* wrapper for standard C library functions */
#endif

/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/

/* OPERATING SYSTEM rcX */
#ifdef __RCX__

  /* timeout */
  #define TLR_INFINITE              RX_INFINITE     /* infinite */
  #define TLR_FINITE                RX_FINITE       /* finite   */

  /* TLR_TSK_CREATE_INFO_FIELD_STRUCTURED: Pre-allocated memory for Parameter hTaskInfoBuffer! */
  #define TLR_DIA_INFORMATION_SIZE  RX_INFORMATION_SIZE

  /* TLR_TSK_CREATE: Parameter uStartMode */
  #define TLR_TASK_AUTO_START       RX_TASK_AUTO_START
  #define TLR_TASK_SUSPENDED        RX_TASK_AUTO_STOP

  /* TLR_TIM_CREATE: Parameter uMode */
  #define TLR_TIM_MODE_AUTOSTOP     RX_TIM_AUTO_STOP
  #define TLR_TIM_MODE_AUTORELOAD   RX_TIM_AUTO_RELOAD
  #define TLR_TIM_AUTO_DELETE       RX_TIM_AUTO_DELETE
  #endif

  /*****************************************************************************/
  /* Class, Type, and Structure Definitions                                    */
  /*****************************************************************************/


  /* none */



  /*****************************************************************************/
  /* Global Variables                                                          */
  /*****************************************************************************/


  /* none */



  /*****************************************************************************/
  /* Macros                                                                    */
  /*****************************************************************************/


  /* none */



  /*****************************************************************************/
  /* Functions                                                                 */
  /*****************************************************************************/

  /*************************************************************************************/
  /* OPERATING SYSTEM rcX */
  #ifdef __RCX__

  /*************************************************************************************/
  /* Timer Wrapper (Software timer!) ==> Renamed TLR_TIM_HW_ --> TLR_TIM_ */

  #define TLR_TIM_CREATE(fnCallback, pvCallbackParam, uMode, uReloadValue, uDelayValue, phTimer)  (TLR_RESULT)TLR_OS_HardTimerCreate((TLR_VOID FAR*)fnCallback, pvCallbackParam, uMode, uReloadValue, uDelayValue, phTimer)
  #define TLR_TIM_DELETE(hTimer)                (TLR_RESULT)TLR_OS_HardTimerDelete(hTimer)

  #define TLR_TIM_RELOAD(hTimer, uReloadValue)  (TLR_RESULT)rX_TimSetReload(hTimer, uReloadValue)
  #define TLR_TIM_STOP(hTimer)                  (TLR_RESULT)rX_TimStopTimer(hTimer)
  #define TLR_TIM_SET_TIME(hTimer, uCount)      (TLR_RESULT)rX_TimSetTime(hTimer, uCount)

  /*************************************************************************************/
  /* Time Wrapper */

  /*
   * NOTE
   *  rcX works with ticks
   *  the macro TLR_TIM_TIME_TO_TICK changes the time value into ticks
   */
  #define TLR_TIM_TIME_TO_TICK(ulMilliseconds)  TLR_OS_TimeToTick(ulMilliseconds)
  #define TLR_TIM_GET_SYSTEM_TICKS()            rX_SysGetSystemTicks()
  #define TLR_TIM_GET_SYSTEM_CYCLETIME()        rX_SysGetSystemCycletime()  /* in microseconds */


  /*************************************************************************************/
  /* Task Wrapper */

  #define TLR_TSK_IDENTIFY(pszTaskName, uInstance, phTask, pusToken, pusPriority) (TLR_RESULT)rX_SysIdentifyTask(pszTaskName, uInstance, phTask, (TLR_UINT16 FAR*)pusToken, (TLR_UINT16 FAR*)pusPriority)

#if !defined( __RX_INC_H )
  #define TLR_TSK_CREATE(pszTaskName, pfnTask, pvStartParams, pvStack, uStackSize, uStartMode, usThreshold, usPriority, usToken, uInstance, pfnLeaveCallback, phTask) \
    rX_SysCreateTaskEx( pszTaskName, pfnTask, pvStartParams, pvStack, uStackSize, uStartMode, usThreshold, usPriority, usToken, uInstance, pfnLeaveCallback, phTask)
#endif /* #if !defined( __RX_INC_H ) */

  #define TLR_TSK_DELETE( hTask, uTicks )                       rX_SysDeleteTask( hTask, uTicks )

  #define TLR_TSK_INIT_DONE(pvLeaveParam, uStatusCode)          rX_SysSetTaskInitialized(pvLeaveParam)
  #define TLR_TSK_EXIT_DONE(uReasonCode)                        rX_SysTerminateTask(uReasonCode)

  #define TLR_TSK_SLEEP(uTicks)                                 (TLR_RESULT)rX_SysSleepTask(uTicks)

  #define TLR_TSK_SET_STATE(ulStatusCode)                       rX_DiaSetTaskStatus(ulStatusCode)

  #define TLR_TSK_GET_INSTANCE(uInstance)                       uInstance = rX_SysGetOwnInstance()

  #define TLR_TSK_CREATE_INFO_FIELD_STRUCTURED(hTaskInfoBuffer, uTaskInfoLen, pvTaskInfo, uTaskInfoDescriptionLen, pvTaskInfoDescription)     \
                                        (TLR_RESULT)rX_DiaCreateInformationFieldWithStructInfo((RX_HANDLE)hTaskInfoBuffer, \
                                                                  uTaskInfoLen, (TLR_VOID FAR*)pvTaskInfo, \
                                                                  uTaskInfoDescriptionLen, (TLR_VOID FAR*)pvTaskInfoDescription)


  /*************************************************************************************/
  /* Signal Wrapper, Event Wrapper */

  #define TLR_SIG_CREATE(pszSignalName, fReset, phSignal)   (TLR_RESULT)rX_SigCreateSignal(pszSignalName, (TLR_UINT FAR*)phSignal, (TLR_BOOLEAN)fReset)
  #define TLR_SIG_DELETE(hSignal)                     (TLR_RESULT)rX_SigDeleteSignal((TLR_UINT)hSignal)
  #define TLR_SIG_SET(hSignal)                        (TLR_RESULT)rX_SigSetSignal((TLR_UINT)hSignal)
  #define TLR_SIG_RESET(hSignal)                      (TLR_RESULT)rX_SigResetSignal((TLR_UINT)hSignal)
  #define TLR_SIG_WAIT(hSignal, uTimeout)             (TLR_RESULT)rX_SigWaitForSignal((TLR_UINT)hSignal, uTimeout)


  /*************************************************************************************/
  /* Semaphore Wrapper */

  #define TLR_SEM_CREATE(pszSemaphoreName, uMaxCount, phSemaphore)   (TLR_RESULT)TLR_OS_SemaphoreCreate(pszSemaphoreName, (UINT)uMaxCount, phSemaphore)
  #define TLR_SEM_DELETE(hSemaphore)                  (TLR_RESULT)TLR_OS_SemaphoreDelete(hSemaphore)
  #define TLR_SEM_ENTER(hSemaphore)                   (TLR_RESULT)rX_SemWaitForSemaphore(hSemaphore, TLR_INFINITE)
  #define TLR_SEM_ENTER_TIMEOUT(hSemaphore, uTimeout) (TLR_RESULT)rX_SemWaitForSemaphore(hSemaphore, uTimeout)
  #define TLR_SEM_LEAVE(hSemaphore)                   (TLR_RESULT)rX_SemPutSemaphore(hSemaphore)


  /*************************************************************************************/
  /* Mutex Wrapper */

  #define TLR_MTX_CREATE(pszMutexName, uMaxLocks, phMutex)  (TLR_RESULT)TLR_OS_MutexCreate(pszMutexName, (UINT)uMaxLocks, phMutex)
  #define TLR_MTX_DELETE(hMutex)                    (TLR_RESULT)TLR_OS_MutexDelete(hMutex)
  #define TLR_MTX_LOCK(hMutex)                      (TLR_RESULT)rX_MtxLockMutex(hMutex,TLR_INFINITE)
  #define TLR_MTX_UNLOCK(hMutex)                    (TLR_RESULT)rX_MtxUnlockMutex(hMutex)


  /*************************************************************************************/
  /* Atomic Wrapper */
  #define TLR_UINT_INTERLOCK_EXCHANGE(puMem, uNewValue)   (UINT)rX_SysInterlockExchange(puMem, uNewValue)


  /*************************************************************************************/
  /* TripleBuffer-Control-Block Wrapper */

  #define TLR_TBF_CREATE(pszTripleBufferName, phTripleBuffer, ptBufferSet) (TLR_RESULT)TLR_OS_TripleBufferCreate(pszTripleBufferName, phTripleBuffer, ptBufferSet)
  #define TLR_TBF_DELETE(hTripleBuffer) (TLR_RESULT)TLR_OS_TripleBufferDelete(hTripleBuffer)

  #define TLR_TBF_EXCHANGE(hTripleBuffer, ppabNextWriteBuffer) (TLR_RESULT)rX_MemExchangeBuffer(hTripleBuffer, ppabNextWriteBuffer)
  #define TLR_TBF_GETCURRENT(hTripleBuffer, ppabWriteBuffer) (TLR_RESULT)rX_MemExchangeGetCurrentBuffer(hTripleBuffer, ppabWriteBuffer)
  #define TLR_TBF_GETEXCHGED(hTripleBuffer, ppabReadBuffer) (TLR_RESULT)rX_MemGetExchangedBuffer(hTripleBuffer, ppabReadBuffer)
  #define TLR_TBF_CALLBACK_ENABLE(hTripleBuffer, pfnCallback, pvCallbackParam) (TLR_RESULT)rX_MemEnableTripleCallback(hTripleBuffer, pfnCallback, pvCallbackParam)
  #define TLR_TBF_CALLBACK_DISABLE(hTripleBuffer)      (TLR_RESULT)rX_MemDisableTripleCallback(hTripleBuffer)
  /* Changed all TLR names from TLR_TRIBUFF_ to TLR_TBF_ */


  /*************************************************************************************/
  /* IrqLock Wrapper */

  INLINE TLR_RESULT
  TLR_LCK_CREATE( TLR_HANDLE*  phLock )
  {
    if( NULL != phLock )
    {
      *phLock = (TLR_HANDLE) 0xDEADBEEF;
      return TLR_S_OK;
    }
    else
    {
      return TLR_E_FAIL;
    }
  }

  #define TLR_LCK_DELETE(hLock)   (hLock = NULL)
  #define TLR_LCK_ENTER(hLock)    (TLR_UINT)rX_SysLockIrq()
  #define TLR_LCK_LEAVE(hLock)    rX_SysUnlockIrq()


  /*************************************************************************************/
  /* Queue Wrapper */

  /* just the typedef for reducing warnings and errors */

  /*
   * NOTE:
   *  for rcX wrapper function for macro TLR_QUE_CREATE and TLR_QUE_DELETE is needed,
   *  because memory for queue will not allocated/deallocated by operating system
   */
  #define TLR_QUE_CREATE(pszQueueName, uMaxEntries, phQueue)          (TLR_RESULT)TLR_OS_MsgQueueCreate(pszQueueName, uMaxEntries, 0, 0, phQueue)
  #define TLR_QUE_DELETE(hQueue)                                      TLR_OS_MsgQueueDelete(hQueue)
  #define TLR_QUE_IDENTIFY_INTERN(pszQueueName, uInstance, phQueue)   (TLR_RESULT)rX_QueIdentifyQueue(pszQueueName, uInstance, phQueue)
  #define TLR_QUE_GET_LOAD(hQueue, ulNumEntries)                      (TLR_RESULT)rX_QueGetQueueLoad(hQueue, (UINT32*)&ulNumEntries)

  /* Standard packet handling */
  #define TLR_QUE_PEEKPACKET(hQueue, pptPacket)                       (TLR_RESULT)rX_QueWaitForPacket((TLR_VOID FAR*)hQueue, (TLR_VOID FAR*)pptPacket, RX_FINITE)
  #define TLR_QUE_POSTPACKET_INTERN(hQueue, ptPacket)                 (TLR_RESULT)rX_QuePostPacket((TLR_VOID FAR*)hQueue, ptPacket)
  #define TLR_QUE_SENDPACKET_FIFO_INTERN(hQueue, ptPacket, uTimeout)  (TLR_RESULT)rX_QueSendPacket((TLR_VOID FAR*)hQueue, ptPacket, uTimeout)
  #define TLR_QUE_SENDPACKET_LIFO_INTERN(hQueue, ptPacket, uTimeout)  (TLR_RESULT)rX_QueSendPriorityPacket((TLR_VOID FAR*)hQueue, ptPacket, uTimeout)
  #define TLR_QUE_WAITFORPACKET(hQueue, pptPacket, uTimeout)          (TLR_RESULT)rX_QueWaitForPacket((TLR_VOID FAR*)hQueue, (TLR_VOID FAR* FAR*)pptPacket, uTimeout)

  /* Miscellaneous, extended packet handling using the Header of a packet to get the destination of it */


  /*************************************************************************************/
  /* Resource Pool Wrapper */

  /*
   * NOTE:
   *  rcX supports no functionality for pools
   *  rcX uses queues
   */
  #define TLR_POOL_CREATE(pszPoolName, uNumEntries, uEntryLen, phPool) (TLR_RESULT)TLR_OS_MsgQueueCreate(pszPoolName, uNumEntries, uNumEntries, uEntryLen, phPool)

  #define TLR_POOL_DELETE(hPool)                      TLR_OS_MsgQueueDelete(hPool)

  #define TLR_POOL_PACKET_GET(hPool, pptPacket)       (TLR_RESULT)rX_QueWaitForPacket(hPool, (TLR_VOID FAR* FAR*)pptPacket, TLR_FINITE)
  #define TLR_POOL_PACKET_RELEASE(hPool, ptPacket)    (TLR_RESULT)rX_QueSendPacket(hPool, ptPacket, TLR_FINITE)

  #define TLR_POOL_GET_LOAD(hPool, ulNumEntries)      (TLR_RESULT)rX_QueGetQueueLoad(hPool, (UINT32*)&ulNumEntries)


/*************************************************************************************/
/* Trace Wrapper */

#ifdef TLR_TRACE_ON
#define TLR_TRACE(pszMsg, ...) rX_VbsPrintf(pszMsg, ...)
#else
#define TLR_TRACE(pszMsg, ...)
#endif /* #ifdef TLR_TRACE_ON */


/*************************************************************************************/
/* OPERATING SYSTEM: Custom  */
#elif defined(TLR_USE_CUSTOM_WRAPPER) /* #ifdef __RCX__ */

  /**************************************************************************/
  /* Use custom TLR Wrapper (e.g. is the O/S natively supports efficient
   * queues / triplebuffer, etc.)                                           */
  /**************************************************************************/
  #include <TLR_CustomOSWrapper.h>

/*************************************************************************************/
/* OPERATING SYSTEM: TLR Wrapper with OS Abstraction  */
#else

  /**************************************************************************/
  /* Use default TLR Emulation with additional O/S Abstraction layer        */
  /**************************************************************************/

  #include "OS_Dependent.h"

  TLR_RESULT  TLR_Init(TLR_VOID);
  TLR_VOID    TLR_Deinit(TLR_VOID);

  #define TLR_INFINITE                  OS_INFINITE
  #define TLR_FINITE                    OS_FINITE

  #if !defined(__TLR_USE_LIBC_WRAPPER__) /* Allow the use to use standard libc wrapper macros */
    #define LIB_MALLOC(size)              OS_Memalloc(size)
    #define LIB_FREE(pvMem)               OS_Memfree(pvMem)

    #define LIB_MEMSET                    OS_Memset
    #define LIB_MEMCMP                    OS_Memcmp
    #define LIB_MEMCPY                    OS_Memcpy

    #define LIB_STRLEN                    OS_Strlen
  #endif

  #define TLR_LCK_CREATE(phLock)          ((NULL != (*phLock = OS_CreateLock())) ? TLR_S_OK : TLR_E_OUTOFMEMORY)
  #define TLR_LCK_DELETE(hLock)           OS_DeleteLock(hLock)
  #define TLR_LCK_ENTER(hLock)            OS_EnterLock(hLock)
  #define TLR_LCK_LEAVE(hLock)            OS_LeaveLock(hLock)


  /*************************************************************************************/
  /* Semaphore Wrapper */

  #define TLR_SEM_CREATE(pszSemaphoreName, uMaxCount, phSemaphore)   ((NULL != (*phSemaphore = OS_CreateSemaphore(pszSemaphoreName, uMaxCount, uMaxCount))) ? TLR_S_OK : TLR_E_FAIL)
  #define TLR_SEM_DELETE(hSemaphore)                  OS_DeleteSemaphore(hSemaphore)
  #define TLR_SEM_ENTER(hSemaphore)                   (OS_WaitSemaphore(hSemaphore, OS_INFINITE) ? TLR_S_OK : TLR_E_FAIL)
  #define TLR_SEM_ENTER_TIMEOUT(hSemaphore, uTimeout) (OS_WaitSemaphore(hSemaphore, uTimeout) ? TLR_S_OK : TLR_E_FAIL)
  #define TLR_SEM_LEAVE(hSemaphore)                   (OS_ReleaseSemaphore(hSemaphore, 1) ? TLR_S_OK : TLR_E_FAIL)


  /*************************************************************************************/
  /* Atomic Wrapper */
  #define TLR_UINT_INTERLOCK_EXCHANGE(puMem, uNewValue)   OS_InterlockedExchange(puMem, uNewValue)

  #define TLR_TIM_GET_SYSTEM_TICKS()                      OS_GetSystemTicks()
  #define TLR_TIM_GET_SYSTEM_CYCLETIME()                  OS_GetSystemCycleTime()
  #define TLR_TIM_TIME_TO_TICK(uTime)   (uTime)


  /**************************************************************************/
  /* Queue Emulation                                                        */
  /**************************************************************************/
  #include <TLR_Queues.h>

  #define TLR_QUE_CREATE(pszQueueName, uMaxEntries, phQueue)          TLR_QueueCreate(pszQueueName, uMaxEntries, phQueue)
  #define TLR_QUE_DELETE(hQueue)                                      TLR_QueueDelete(hQueue)
  #define TLR_QUE_IDENTIFY_INTERN(pszQueueName, uInstance, phQueue)   TLR_QueueIdentify(pszQueueName, uInstance, phQueue)
  #define TLR_QUE_GET_LOAD(hQueue, ulNumEntries)                      TLR_QueueGetLoad(hQueue, &ulNumEntries)

  #define TLR_QUE_WAITFORPACKET(hQueue, pptPacket, uTimeout)          TLR_QueueGet(hQueue, pptPacket, uTimeout)
  #define TLR_QUE_SENDPACKET_FIFO_INTERN(hQueue, ptPacket, uTimeout)  TLR_QueuePut((TLR_HANDLE)hQueue, ptPacket, TLR_FALSE, uTimeout)
  #define TLR_QUE_SENDPACKET_LIFO_INTERN(hQueue, ptPacket, uTimeout)  TLR_QueuePut((TLR_HANDLE)hQueue, ptPacket, TLR_TRUE, uTimeout)
  #define TLR_QUE_POSTPACKET_INTERN(hQueue, ptPacket)                 TLR_QueuePut(hQueue, ptPacket, TLR_FALSE, TLR_INFINITE)

  #define TLR_POOL_CREATE(pszPoolName, uNumEntries, uEntryLen, phPool)   TLR_PoolCreate(pszPoolName, uNumEntries, uEntryLen, phPool)
  #define TLR_POOL_DELETE(hPool)                        TLR_QueueDelete(hPool)
  #define TLR_POOL_IDENTIFY(pszIdn, uInstance, phPool)  TLR_QueueIdentify(pszIdn, uInstance, phPool)

  #define TLR_POOL_PACKET_GET(hPool, pptPacket)         TLR_QueueGet(hPool, pptPacket, TLR_FINITE)
  #define TLR_POOL_PACKET_RELEASE(hPool, ptPacket)      TLR_QueuePut(hPool, ptPacket, TLR_FALSE, TLR_FINITE)

  #define TLR_POOL_GET_LOAD(hPool, ulNumEntries)        TLR_QueueGetLoad(hPool, &ulNumEntries)
  /**************************************************************************/


  /**************************************************************************/
  /* Triple Buffer Emulation                                                */
  /**************************************************************************/
  #include <TLR_TripleBuffer.h>

  #define TLR_TBF_CREATE(pszTripleBufferName, phTripleBuffer, ptBufferSet)         TLR_TripleBufferCreate(pszTripleBufferName, phTripleBuffer, ptBufferSet)
  #define TLR_TBF_DELETE(hTripleBuffer)                               TLR_TripleBufferDelete(hTripleBuffer);

  #define TLR_TBF_EXCHANGE(hTripleBuffer, ppabNextWriteBuffer)        TLR_TripleBufferExchange(hTripleBuffer, ppabNextWriteBuffer)
  #define TLR_TBF_GETEXCHGED(hTripleBuffer, ppabReadBuffer)           TLR_TripleBufferGetExchanged(hTripleBuffer, ppabReadBuffer)
  #define TLR_TBF_GETCURRENT(hTripleBuffer, ppabWriteBuffer)          TLR_TripleBufferGetActual(hTripleBuffer, ppabWriteBuffer)
  #define TLR_TBF_CALLBACK_ENABLE(hTripleBuffer, pfnCallback, pvCallbackParam)  TLR_TripleBufferCallback(hTripleBuffer, pfnCallback, pvCallbackParam)
  #define TLR_TBF_CALLBACK_DISABLE(hTripleBuffer)                     TLR_TripleBufferCallback(hTripleBuffer, NULL, NULL)
  /**************************************************************************/


  /**************************************************************************/
  /* Task Emulation                                                         */
  /**************************************************************************/
  #include <TLR_Task.h>

  #define TLR_TSK_INIT_DONE(pvLeaveParam, uStatusCode)            TLR_TaskInitDone(pvLeaveParam, uStatusCode)
  #define TLR_TSK_EXIT_DONE(uReasonCode)                          return uReasonCode
  #define TLR_TSK_GET_INSTANCE(uInstance)                         uInstance = TLR_TaskGetInstance()
  #define TLR_TSK_SET_STATE(ulStatusCode)                         TLR_TaskSetState(ulStatusCode)
  #define TLR_TSK_SET_LEAVE_CBF(fnLeave, pvUsr, ppvHook)          TLR_TaskSetLeave(fnLeave, pvUsr, ppvHook)

  #define TLR_TSK_CREATE(pszTaskName, pfnTask, pvStartParams, pvStack, uStackSize, uStartMode, usThreshold, usPriority, usToken, uInstance, pfnLeaveCallback, phTask) TLR_TaskCreate(pszTaskName, pfnTask, pvStartParams, uStackSize, uStartMode, usPriority, uInstance, pfnLeaveCallback, NULL, phTask)

/* #define TLR_TSK_IDENTIFY(pszTaskName, uInstance, phTask, pusToken, pusPriority)   TLR_TaskIdentify(pszTaskName, uInstance, phTask, pusToken, pusPriority) */

  #define TLR_TSK_SLEEP(uTicks)                                   OS_Sleep(uTicks)
  #define TLR_HOOK_DELETE(hHook)

  #define TLR_TSK_CREATE_INFO_FIELD_STRUCTURED(hTaskInfoBuffer, uTaskInfoLen, pvTaskInfo, uTaskInfoDescriptionLen, pvTaskInfoDescription)  TLR_TaskCreateInfoField((TLR_HANDLE)hTaskInfoBuffer, uTaskInfoLen, pvTaskInfo, uTaskInfoDescriptionLen, pvTaskInfoDescription)
  /**************************************************************************/

#endif /* #ifdef __RCX__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __OS_WRAPPER_H */
