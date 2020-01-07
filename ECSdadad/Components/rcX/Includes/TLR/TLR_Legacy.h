/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Legacy.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Compatible wrapper for old TLR headers

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-28  VD            Added struct TLR_TASK_PARAMETERHEADER_T

    2010-04-20  NC            File created.

******************************************************************************/


#ifndef __TLR_LEGACY_H
#define __TLR_LEGACY_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */

#ifdef __RCX__



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/

#include "TLR_Includes.h"



/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/

/* OPERATING SYSTEM rcX */
#define TLR_MAKE_USED(param)      (param = param)
#define TLR_MAX_CNT(t)            (sizeof(t)/sizeof(t[0]))

/* common TLR task parameter */
typedef struct TLR_TASK_PARAMETERHEADER_Ttag
{
  TLR_UINT32    ulTaskIdentifier; /* task identifier: see Tlr_TaskIdentifier.h            */
  TLR_UINT32    ulParamVersion;   /* param version: stating the version of the param set  */

} TLR_TASK_PARAMETERHEADER_T;

#define TLR_TASK_PARAMETERHEADER \
  TLR_UINT32    ulTaskIdentifier; \
  TLR_UINT32    ulParamVersion


/*
***********************************************************
*  Common definitions of a Queue-Packet Header
***********************************************************
*/

/* Destination for the packet as handle */
#define TLR_PACKET_DESTINATION    TLR_UINT32 ulDest

/* Source of the packet as handle, to be able to return a confirmation packet to this handle */
#define TLR_PACKET_SOURCE         TLR_UINT32 ulSrc

/* Destination Reference of the packet */
#define TLR_PACKET_DESTINATION_ID TLR_UINT32 ulDestId

/* Source Reference of the packet */
#define TLR_PACKET_SOURCE_ID      TLR_UINT32 ulSrcId

/* Length of the packet, needed if packet is leaving the inner CPU area */
#define TLR_PACKET_LENGTH         TLR_UINT32 ulLen

/* Unique Packet Identification */
#define TLR_PACKET_IDENTIFICATION TLR_UINT32 ulId

/* Status of the Packet, typically a result value */
#define TLR_PACKET_STATUS         TLR_UINT32 ulSta

/* Command Type of Packet, typically the command or function number */
#define TLR_PACKET_COMMAND        TLR_UINT32 ulCmd

/* Packet extension for general purpose */
#define TLR_PACKET_EXTENSION      TLR_UINT32 ulExt

/* Routing Identifier */
#define TLR_PACKET_ROUTER         TLR_UINT32 ulRout


/* TLR header for simple inclusion into a structure */
#define TLR_PACKET_HEADER               \
            TLR_PACKET_DESTINATION;     \
            TLR_PACKET_SOURCE;          \
            TLR_PACKET_DESTINATION_ID;  \
            TLR_PACKET_SOURCE_ID;       \
            TLR_PACKET_LENGTH;          \
            TLR_PACKET_IDENTIFICATION;  \
            TLR_PACKET_STATUS;          \
            TLR_PACKET_COMMAND;         \
            TLR_PACKET_EXTENSION;       \
            TLR_PACKET_ROUTER

/* array indices of the TLR_PACKET_HEADER_T DWORD */
#define TLR_PCK_DEST_VALUE_NO 0
#define TLR_PCK_SRC_VALUE_NO  1
#define TLR_PCK_DEST_ID_VALUE_NO 2
#define TLR_PCK_SRC_ID_VALUE_NO  3
#define TLR_PCK_LEN_VALUE_NO  4
#define TLR_PCK_ID_VALUE_NO   5
#define TLR_PCK_STA_VALUE_NO  6
#define TLR_PCK_CMD_VALUE_NO  7
#define TLR_PCK_EXT_VALUE_NO  8
#define TLR_PCK_ROUT_VALUE_NO 9


  
  /*****************************************************************************/
  /* Class, Type, and Structure Definitions                                    */
  /*****************************************************************************/
  
  

  
  
  
  /*****************************************************************************/
  /* Global Variables                                                          */
  /*****************************************************************************/
  
  
  /* none */
  
  
  
  /*****************************************************************************/
  /* Macros                                                                    */
  /*****************************************************************************/

/*************************************************************************************/
/* double linked list, not synchronized */

/* types */
typedef struct TLR_DBLY_LST_Ttag      TLR_DBLY_LST_T;

struct TLR_DBLY_LST_Ttag              /* double linked list */
{
  TLR_DBLY_LST_T*   ptNxt;
  TLR_DBLY_LST_T*   ptPrv;
};

/* macros */

/* reset the base of list */
#define TLR_DBLY_RESET(pBs)             (pBs)->ptNxt = (TLR_DBLY_LST_T*)(pBs);\
                                        (pBs)->ptPrv = (TLR_DBLY_LST_T*)(pBs);

/* insert element to the top of list */
#define TLR_DBLY_INSERT_TOP(pBs, pNew)  (pNew)->ptPrv       = (TLR_DBLY_LST_T*)(pBs);\
                                        (pNew)->ptNxt       = (TLR_DBLY_LST_T*)(pBs)->ptNxt;\
                                        (pBs)->ptNxt->ptPrv = (TLR_DBLY_LST_T*)(pNew);\
                                        (pBs)->ptNxt        = (TLR_DBLY_LST_T*)(pNew);

/* insert element to the end of list */
#define TLR_DBLY_INSERT_END(pBs, pNew)  (pNew)->ptNxt       = (TLR_DBLY_LST_T*)(pBs);\
                                        (pNew)->ptPrv       = (TLR_DBLY_LST_T*)(pBs)->ptPrv;\
                                        (pBs)->ptPrv->ptNxt = (TLR_DBLY_LST_T*)(pNew);\
                                        (pBs)->ptPrv        = (TLR_DBLY_LST_T*)(pNew);

/* remove element from list */
#define TLR_DBLY_REMOVE(pElm)           (pElm)->ptPrv->ptNxt = (pElm)->ptNxt;\
                                        (pElm)->ptNxt->ptPrv = (pElm)->ptPrv;


/*
 * definition
 *  use only for constant and global defined arrays
 *  it is only for precompiler
 */
#if (CPU_FRMT == 1)                       /* INTEL */

/* split 16bit/32bit value into 2/4 8bit values */
#define TLR_CONST_16_TO_08(v)             (v)&0xFF, (v)>>8
#define TLR_CONST_32_TO_08(v)             (v)&0xFF, ((v)>>8)&0xFF, ((v)>>16)&0xFF, ((v)>>24)&0xFF

/* combine 2/4 8bit values into 16bit/32bit value */
#define TLR_CONST_08_TO_16(b1, b2)        ((b2 << 8) + b1)
#define TLR_CONST_08_TO_32(b1, b2, b3, b4)((b4 << 24) + (b3 << 16) + (b2 << 8) + b1)

#elif (CPU_FRMT == 0)                     /* MOTOROLA */

/* split 16bit/32bit value into 2/4 8bit values */
#define TLR_CONST_16_TO_08(v)             (v)>>8, (v)&0xFF
#define TLR_CONST_32_TO_08(v)             ((v)>>24)&0xFF, ((v)>>16)&0xFF, ((v)>>8)&0xFF, (v)&0xFF

/* combine 2/4 8bit values into 16bit/32bit value */
#define TLR_CONST_08_TO_16(b1, b2)        ((b1 << 8) + b2)
#define TLR_CONST_08_TO_32(b1, b2, b3, b4)((b1 << 24) + (b2 << 16) + (b3 << 8) + b4)

#endif /* #if (CPU_FRMT == 1) */

/*
 * example
 * STATIC CONST TLR_UINT8 g_abExample[] =
 * {
 *    0x01, 0x23, 0x45, 0x67,                   8bit values
 *    TLR_SET_16(0x0123), TLR_SET_16(0x4567),   16bit values
 *    TLR_SET_32(0x01234567),                   32bit value
 * };
*/
 
  
  
/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/

/* Memory Wrapper */

/* NB: TLR_MEMALLOC parameter 1 purposely cast to void FAR* to avoid gcc warning about 
 * dereferencing type-punned pointer.
 */
#ifdef __cplusplus
  #define TLR_MEMALLOC(pvMem, size)     rX_MemAllocateMemory((void HUGE* FAR*)&pvMem, size)
#else
  #define TLR_MEMALLOC(pvMem, size)     rX_MemAllocateMemory((void FAR*)&pvMem, size)
#endif
#define TLR_MEMFREE(pvMem)            rX_MemFreeMemory(pvMem)
#define TLR_MEMFREE_CHECK(pvMem)      if(NULL!=pvMem){TLR_MEMFREE(pvMem);}
#define TLR_MEMREALLOC(pvOldMem, pvNewMem, newSize)     rX_MemReAllocateMemory((void HUGE* FAR*)&pvOldMem,\
                                                        (void HUGE* FAR*)&pvNewMem, newSize)


#define TLR_MEMSET                    memset
#define TLR_MEMCMP                    memcmp
#define TLR_MEMCPY                    memcpy

#define TLR_MEMCPY_FAST               rX_BasMemCpyFast



/*************************************************************************************/
/* String Wrapper */

#define TLR_STRLEN                    strlen
#define TLR_STRUPR                    strupr
#define TLR_STRCMP                    strcmp
#define TLR_STRCPY                    strcpy
#define TLR_STRNCMP                   strncmp
#define TLR_STRNCPY                   strncpy

#define TLR_ULTOA(ulVal, pStr, uRdx)  ultoa(ulVal, pStr, uRdx)


/*************************************************************************************/
/* Hardware Timer Wrapper */

#define TLR_TIM_HW_CREATE(fnExp, pvInpt, uMod, timrld, timdly, phTim) (TLR_RESULT)TLR_OS_HardTimerCreate((void FAR*)fnExp, pvInpt, uMod, timrld, timdly, phTim)
#define TLR_TIM_HW_DELETE(hTim)                                       (TLR_RESULT)TLR_OS_HardTimerDelete(hTim)
#define TLR_TIM_HW_DELETE_CHECK(hTim)                                 if(NULL!=hTim){TLR_TIM_HW_DELETE(hTim);}

#define TLR_TIM_HW_MODE_AUTORELOAD      RX_TIM_AUTO_RELOAD

#define TLR_TIM_HW_RELOAD(hTim, uNewVal)                              (TLR_RESULT)rX_TimSetReload(hTim, uNewVal)
#define TLR_TIM_HW_STOP(hTim)                                         (TLR_RESULT)rX_TimStopTimer(hTim)
#define TLR_TIM_HW_HALT(hTim)                                         (TLR_RESULT)rX_TimHaltTimer(hTim)
#define TLR_TIM_HW_RESUME(hTim)                                       (TLR_RESULT)rX_TimResumeTimer(hTim)
#define TLR_TIM_HW_SET_TIME(hTim, uNewVal)                            (TLR_RESULT)rX_TimSetTime(hTim, uNewVal)


/*************************************************************************************/
/* Time Wrapper */

#define TLR_TIM_MICROTIME_TO_TICK(uMicroSecs) TLR_OS_MicroTimeToTick(uMicroSecs)


/*************************************************************************************/
/* Task Wrapper */

#define TLR_TSK_SET_LEAVE_CBF(fnLeave, pvUsr, ppvHook)        (TLR_RESULT)TLR_OS_TaskSetLeaveFunction((void FAR*)fnLeave, pvUsr, ppvHook)
#define TLR_TSK_GET_STARTMODE(ulMode)                         ulMode = rX_DevGetStartmode()
#define TLR_TSK_CREATE_INFO_FIELD(ptTskNfo, uLen, pvStr)      (TLR_RESULT)rX_DiaCreateInformationField((RX_HANDLE)ptTskNfo, uLen, (void FAR*)pvStr)

#ifdef _MID_SYS_ENABLE_
RX_RESULT FAR Mid_SysTskIdentify(UINT32 ulTskIdentifier, UINT uInst, RX_HANDLE FAR* phTsk);
#define TLR_TSK_ID_IDENTIFY(ulTskIdentifier, uInst, phTsk)  (TLR_RESULT)Mid_SysTskIdentify(ulTskIdentifier, uInst, phTsk)
#endif


/*************************************************************************************/
/* Signal Wrapper, Event Wrapper */

#define TLR_SIG_DELETE_CHECK(hSig)              if(NULL!=hSig){TLR_SIG_DELETE(hSig);}
#define TLR_SIG_IDENTIFY(pszIdn, uInst, phSig)  (TLR_RESULT)rX_SigIdentifySignal(pszIdn, (UINT)uInst, (UINT FAR*)phSig)

#define TLR_EVT_GROUP_CREATE(pszIdn,hEvt)               (TLR_RESULT)rX_EveCreateEventGroup(pszIdn,hEvt)
#define TLR_EVT_GROUP_SETUP(hEvt,ulMsk,uMode,pulCurEve) (TLR_RESULT)rX_EveSetupEventGroup(hEvt,(UINT32)ulMsk,(UINT)uMode,(UINT32 FAR*)pulCurEve)


/*************************************************************************************/
/* Semaphore Wrapper */

#define TLR_SEM_DELETE_CHECK(hSem)            if(NULL!=hSem){TLR_SEM_DELETE(hSem);}


/*************************************************************************************/
/* Mutex Wrapper */

#define TLR_MTX_IDENTIFY(pszIdn, uInst, phMtx) (TLR_RESULT)rX_MtxIdentifyMutex(pszIdn, (UINT)uInst, phMtx)


/*************************************************************************************/
/* TripleBuffer-Control-Block Wrapper */

#define TLR_TRIBUFF_CREATE(pszIdn, phTrp, ptBufPool) (TLR_RESULT)TLR_OS_TripleBufferCreate(pszIdn, phTrp, ptBufPool)
#define TLR_TRIBUFF_DELETE(hTrp) (TLR_RESULT)TLR_OS_TripleBufferDelete(hTrp)
#define TLR_TRIBUFF_IDENTIFY(pszIdn, uInst, phTrp) (TLR_RESULT)rX_MemIdentifyTripleBuffer(pszIdn, uInst, phTrp)
#define TLR_EXCHANGE_TRIBUFF(hTrp, ppabUsrBuf) (TLR_RESULT)rX_MemExchangeBuffer(hTrp, ppabUsrBuf)
#define TLR_GETEXCHGED_TRIBUFF(hTrp, ppabUsrBuf) (TLR_RESULT)rX_MemGetExchangedBuffer(hTrp, ppabUsrBuf)
#define TLR_GETCURRENT_TRIBUFF(hTrp, ppabUsrBuf) (TLR_RESULT)rX_MemExchangeGetCurrentBuffer(hTrp, ppabUsrBuf)
#define TLR_ENABLE_TRIBUFF_CALLBACK(hTrp, pfnCallback, pvPrm) (TLR_RESULT)rX_MemEnableTripleCallback(hTrp, pfnCallback, pvPrm)
#define TLR_DISABLE_TRIBUFF_CALLBACK(hTrp)      (TLR_RESULT)rX_MemDisableTripleCallback(hTrp)


/*************************************************************************************/
/* IrqLock Wrapper */

/* #define TLR_LCK_CREATE(phLck)                 (TLR_RESULT)TLR_S_OK  !!!! Behaviour changed !!!! Problem? */
#define TLR_LCK_DELETE_CHECK(hLck)            if(NULL!=hLck){TLR_LCK_DELETE(hLck);}


/*************************************************************************************/
/* Spin Wrapper */

#define TLR_SPN_LOCK(phSpn)                    rX_SysSpinLock(phSpn)
#define TLR_SPN_UNLOCK(phSpn)                  rX_SysSpinUnlock(phSpn)


/*************************************************************************************/
/* Hook Wrapper */

#define TLR_HOOK_DELETE(hHook)        TLR_OS_HookDelete(hHook)
#define TLR_HOOK_DELETE_CHECK(hHook)  if(NULL!=hHook){TLR_HOOK_DELETE(hHook);}


/*************************************************************************************/
/* Queue Wrapper */

#define TLR_QUE_DELETE_CHECK(hQue)                    if(NULL!=hQue){TLR_QUE_DELETE(hQue);}


/*************************************************************************************/
/* Resource Pool Wrapper */

#define TLR_POOL_CREATE_IO(pszIdn, pabIOMem, uMax, uLen, phPool) (TLR_RESULT)TLR_OS_MsgQueueCreateIo(pszIdn, pabIOMem,uMax, uMax, uLen, phPool)
#define TLR_POOL_DELETE_CHECK(hPool)                if(NULL!=hPool){TLR_POOL_DELETE(hPool);}
#define TLR_POOL_IDENTIFY(pszIdn, uInst, phPool)    (TLR_RESULT)rX_QueIdentifyQueue(pszIdn, uInst, phPool)


/*************************************************************************************/
/* EDD Wrapper */

#define TLR_EDD_IDENTIFY(pszIdn, uInst, phEdd)          (TLR_RESULT)Drv_EddIdentifyEdd((TLR_STR FAR*)pszIdn, uInst, phEdd)

#define TLR_EDD_PACKET_GET(hEdd, hApp, eBufType, ppvPack) (TLR_RESULT)Drv_EddGetFrameBuffer((RX_HANDLE)hEdd, (RX_HANDLE)hApp, (RX_EDD_BUF_TYPE_T)eBufType, (RX_EDD_FRAME_BUFFER_T FAR* FAR*)ppvPack)
#define TLR_EDD_PACKET_RELEASE(hEdd, hApp, pvPack)      (TLR_RESULT)Drv_EddFreeFrameBuffer((RX_HANDLE)hEdd, (RX_HANDLE)hApp, (RX_EDD_FRAME_BUFFER_T FAR*)pvPack)

#define TLR_EDD_REQUEST(hEdd, hApp, pvPack)             (TLR_RESULT)Drv_EddUserRequest(hEdd, hApp, pvPack)
#define TLR_EDD_SEND_PRIO(hEdd, hApp, fnClb, pvPack, uPrio) (TLR_RESULT)Drv_EddSendFrame(hEdd, hApp, fnClb, pvPack)

#ifndef TLR_EDD_SEND_SCHEDULE_ENABLE
#define TLR_EDD_SEND(hEdd, hApp, fnClb, pvPack, uPrio)  TLR_EDD_SEND_PRIO(hEdd, hApp, fnClb, pvPack, uPrio)
#else
TLR_RESULT TlrEddScheduleSend(TLR_HANDLE hEdd, RX_HANDLE hApp, TLR_EDD_CLB_SEND fnSnd, TLR_VOID FAR* pvPack);
#define TLR_EDD_SEND(hEdd, hApp, fnSnd, pvPack, uPrio)      TlrEddScheduleSend(hEdd, hApp, fnSnd, pvPack, uPrio)
#endif


/*************************************************************************************/
/* Swap Wrapper */

#define TLR_SWAP_16(n) (TLR_UINT16)((((n)<<8)&0xFF00)|(((n)>>8)&0x00FF)) /* ((((TLR_UINT8*)&n)[0] << 8) | ((TLR_UINT8*)&n)[1]) */
#define TLR_SWAP_32(n) (TLR_UINT32)SWAP_UINT32(n)

#if (CPU_FRMT == 1)
#define TLR_HTON16(n)     TLR_SWAP_16(n)
#define TLR_NTOH16(n)     TLR_SWAP_16(n)
#define TLR_HTON32(n)     TLR_SWAP_32(n)
#define TLR_NTOH32(n)     TLR_SWAP_32(n)
#else
#define TLR_HTON16(n)     (TLR_UINT16)(n)
#define TLR_NTOH16(n)     (TLR_UINT16)(n)
#define TLR_HTON32(n)     (TLR_UINT32)(n)
#define TLR_NTOH32(n)     (TLR_UINT32)(n)
#endif


/*************************************************************************************/
/* Trace Wrapper */

#ifdef TLR_TRACE_ON
#define TLR_TRACE_6(pszMsg, prm1, prm2, prm3, prm4, prm5, prm6) rX_VbsPrintf(pszMsg, prm1, prm2, prm3, prm4, prm5, prm6)
#else
#define TLR_TRACE_6(pszMsg, prm1, prm2, prm3, prm4, prm5, prm6)
#endif /* #ifdef TLR_TRACE_ON */

#define TLR_TRACE_0(pszMsg)                                  TLR_TRACE_6(pszMsg, 0, 0, 0, 0, 0, 0)
#define TLR_TRACE_1(pszMsg, prm1)                            TLR_TRACE_6(pszMsg, prm1, 0, 0, 0, 0, 0)
#define TLR_TRACE_2(pszMsg, prm1, prm2)                      TLR_TRACE_6(pszMsg, prm1, prm2, 0, 0, 0, 0)
#define TLR_TRACE_3(pszMsg, prm1, prm2, prm3)                TLR_TRACE_6(pszMsg, prm1, prm2, prm3, 0, 0, 0)
#define TLR_TRACE_4(pszMsg, prm1, prm2, prm3, prm4)          TLR_TRACE_6(pszMsg, prm1, prm2, prm3, prm4, 0, 0)
#define TLR_TRACE_5(pszMsg, prm1, prm2, prm3, prm4, prm5)    TLR_TRACE_6(pszMsg, prm1, prm2, prm3, prm4, prm5, 0)


/*************************************************************************************/
/* Debug Wrapper */

#ifdef TLR_DEBUG_ON

#define TLR_ASSERT_4(exp, pszMsg, prm1, prm2, prm3, prm4)\
  {\
    if(!(exp))\
    {\
    }\
  }

#else

#define TLR_ASSERT_4(exp, pszMsg, prm1, prm2, prm3, prm4)

#endif /* #ifdef TLR_DEBUG_ON */

#define TLR_ASSERT_E(exp)                            TLR_ASSERT_4(exp, "CE_ASSERT", 0, 0, 0, 0)
#define TLR_ASSERT_0(exp, pszMsg)                    TLR_ASSERT_4(exp, pszMsg, 0, 0, 0, 0)
#define TLR_ASSERT_1(exp, pszMsg, prm1)              TLR_ASSERT_4(exp, pszMsg, prm1, 0, 0, 0)
#define TLR_ASSERT_2(exp, pszMsg, prm1, prm2)        TLR_ASSERT_4(exp, pszMsg, prm1, prm2, 0, 0)
#define TLR_ASSERT_3(exp, pszMsg, prm1, prm2, prm3)  TLR_ASSERT_4(exp, pszMsg, prm1, prm2, prm3, 0)


/*************************************************************************************/
/* Host Interface Wrapper */

#define TLR_DRV_HIF_IDENTIFY(pszIdn, uInst, phHif) (TLR_RESULT)Drv_HifIdentifyHif(pszIdn, uInst, phHif)
#define TLR_DRV_HIF_GET_INPUTS(hHif, ptData) (TLR_RESULT)Drv_HifGetInputs(hHif, ptData)
#define TLR_DRV_HIF_SET_OUTPUTS(hHif, ptData) (TLR_RESULT)Drv_HifSetOutputs(hHif, ptData)

/*************************************************************************************/
/* General Purpose I/O Wrapper */

#define TLR_DRV_GPIO_IDENTIFY(pszIdn, uInst, phGpio) (TLR_RESULT)Drv_GpioIdentifyGpio(pszIdn, uInst, phGpio)
#define TLR_DRV_GPIO_GET_INPUT(hGpio, pfInp) (TLR_RESULT)Drv_GpioGetInput(hGpio,pfInp)
#define TLR_DRV_GPIO_SET_OUTPUT(hGpio) (TLR_RESULT)Drv_GpioSetOutput(hGpio)
#define TLR_DRV_GPIO_CLEAR_OUTPUT(hGpio) (TLR_RESULT)Drv_GpioClearOutput(hGpio)
#define TLR_DRV_GPIO_INITIALIZE(hGpio) (TLR_RESULT)Drv_GpioInitializeGpio(hGpio)

/*************************************************************************************/
/* XC Wrapper */
#define TLR_DRV_XC_GET_IO_MEMORY(uInst, pabIOMem, puSiz) (TLR_RESULT) Drv_XcGetIOMemory(uInst,pabIOMem,puSiz)


/*************************************************************************************/
/* fully-qualified addressed queue functions */

INLINE TLR_RESULT TLR_QUE_RETURNPACKET(TLR_VOID FAR* ptPck)
{
  (((TLR_UINT32 FAR*)ptPck)[TLR_PCK_CMD_VALUE_NO])|=1; /* make confirmation/response */
  return TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_UINT32 FAR*)ptPck)[TLR_PCK_SRC_VALUE_NO], ptPck, TLR_INFINITE);
}

INLINE TLR_RESULT TLR_QUE_RETURNPACKET_TIMEOUT(TLR_VOID FAR* ptPck, TLR_UINT uTimout)
{
  (((TLR_UINT32 FAR*)ptPck)[TLR_PCK_CMD_VALUE_NO])|=1; /* make confirmation/response */
  return TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_UINT32 FAR*)ptPck)[TLR_PCK_SRC_VALUE_NO], ptPck, uTimout);
}

#define TLR_QUE_RETURNPACKET_CMD_UNCHANGED(ptPck) \
  TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_UINT32 FAR*)ptPck)[TLR_PCK_SRC_VALUE_NO], ptPck, TLR_INFINITE);

#define TLR_QUE_LINK_GET_MTU(tQueLink, ulMtu) { ulMtu = (tQueLink).ulMTU; }

#ifdef _MID_SYS_ENABLE_
TLR_RESULT MidSysQueIdentify(TLR_STR FAR* pszIdn, TLR_UINT32 ulInstance, TLR_QUE_LINK_T FAR* ptQueLink);
#define TLR_QUE_IDENTIFY(pszIdn, uInst, ptQueLink) \
          MidSysQueIdentify(pszIdn, uInst, ptQueLink)
#else
#define TLR_QUE_IDENTIFY(pszIdn, uInst, ptQueLink) \
  TLR_QUE_IDENTIFY_INTERN(pszIdn, uInst, &(ptQueLink)->hQue)
#endif

INLINE TLR_RESULT TLR_QUE_SENDPACKET_FIFO(TLR_QUE_LINK_T FAR tQueLink, TLR_VOID FAR* ptPck, TLR_UINT uTick)
{
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_VALUE_NO] = tQueLink.ulDest;
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_ID_VALUE_NO] = tQueLink.ulDestId;
  return TLR_QUE_SENDPACKET_FIFO_INTERN(tQueLink.hQue, ptPck, uTick);
}

INLINE TLR_RESULT TLR_QUE_SENDPACKET_LIFO(TLR_QUE_LINK_T FAR tQueLink, TLR_VOID FAR* ptPck, TLR_UINT uTick)
{
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_VALUE_NO] = tQueLink.ulDest;
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_ID_VALUE_NO] = tQueLink.ulDestId;
  return TLR_QUE_SENDPACKET_LIFO_INTERN(tQueLink.hQue, ptPck, uTick);
}

INLINE TLR_RESULT TLR_QUE_POSTPACKET(TLR_QUE_LINK_T FAR tQueLink, TLR_VOID FAR* ptPck)
{
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_VALUE_NO] = tQueLink.ulDest;
  ((TLR_UINT32*)ptPck)[TLR_PCK_DEST_ID_VALUE_NO] = tQueLink.ulDestId;
  return TLR_QUE_POSTPACKET_INTERN(tQueLink.hQue, ptPck);
}

#define TLR_QUE_LINK_FROM_PACKET(ptPck, ptQueLink) \
    { \
      (ptQueLink)->hQue=(TLR_HANDLE)((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrc; \
      (ptQueLink)->ulDestId=((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrcId; \
      (ptQueLink)->ulDest=((TLR_PACKET_HEADER_T FAR*)ptPck)->ulRout; \
      (ptQueLink)->ulMTU=0; \
    }

#define TLR_QUE_LINK_SET_PACKET_DEST(ptPck, tQueLink) \
  { \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulDest=(tQueLink).ulDest; \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulDestId=(tQueLink).ulDestId; \
  }

#define TLR_QUE_LINK_VALID(tQueLink) \
  (0!=(tQueLink).hQue)

#define TLR_QUE_LINK_INVALID(tQueLink) \
  (0==(tQueLink).hQue)

#define TLR_QUE_LINK_INVALIDATE(tQueLink) \
    { \
      (tQueLink).hQue=0; \
      (tQueLink).ulDest=0; \
    }

#define TLR_QUE_LINK_SET_PACKET_SRC(ptPck, tQueSrc) \
  { \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrc=(tQueSrc).ulSrc; \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrcId=(tQueSrc).ulSrcId; \
  }

#define TLR_QUE_LINK_SOURCE_SET(tQueSrc,hQue,_ulSrcId) \
  { \
    (tQueSrc).ulSrc=(TLR_UINT32)(hQue); \
    (tQueSrc).ulSrcId=(TLR_UINT32)(_ulSrcId); \
  }

INLINE TLR_RESULT TLR_QUE_PACKETDONE(TLR_HANDLE hPool, TLR_HANDLE hQue, TLR_VOID FAR* pvPck)
{
  if(((TLR_PACKET_HEADER_T FAR*)pvPck)->ulSrc!=(TLR_UINT32)hQue)
    return TLR_QUE_RETURNPACKET(pvPck);
  else if(!(((TLR_PACKET_HEADER_T FAR*)pvPck)->ulExt & TLR_PACKET_NOT_DELETE))
    return TLR_POOL_PACKET_RELEASE(hPool, pvPck);
  else
    return RX_OK;
}

INLINE TLR_RESULT TLR_QUE_PACKETDONE_TIMEOUT(TLR_HANDLE hPool, TLR_HANDLE hQue, TLR_VOID FAR* pvPck, TLR_UINT uTimout)
{
  if(((TLR_PACKET_HEADER_T FAR*)pvPck)->ulSrc!=(TLR_UINT32)hQue)
    return TLR_QUE_RETURNPACKET_TIMEOUT(pvPck, uTimout);
  else if(!(((TLR_PACKET_HEADER_T FAR*)pvPck)->ulExt & TLR_PACKET_NOT_DELETE))
    return TLR_POOL_PACKET_RELEASE(hPool, pvPck);
  else
    return RX_OK;
}

#define TLR_QUE_LINK_IS_PACKET_FROM_SOURCE(ptPck, tQueLink) \
    ( ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrc==(TLR_UINT32)(tQueLink).hQue && \
      ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulSrcId==(TLR_UINT32)(tQueLink).ulDestId && \
      ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulRout == (tQueLink).ulDest \
    )

/* this one requires that ulRout is set to zero on packet creation */
#define TLR_QUE_LINK_IS_SAME(tQueLink1, tQueLink2) \
  ((tQueLink1).hQue==(tQueLink2).hQue && \
   (tQueLink1).ulDest==(tQueLink2).ulDest && \
   (tQueLink1).ulDestId==(tQueLink2).ulDestId)

#define TLR_QUE_LINK_SET_NEW_DESTID(tQueLink, _ulDestId) \
  ((tQueLink).ulDestId = (_ulDestId))

/************************ prepared indication packet functions ***************************/

#define TLR_QUE_IND_PACKET_SET_DEST(ptPck, tQueLink) \
  { \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulDest=(TLR_UINT32)(tQueLink).ulDest; \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulDestId=(TLR_UINT32)(tQueLink).ulDestId; \
    ((TLR_PACKET_HEADER_T FAR*)ptPck)->ulRout=(TLR_UINT32)(tQueLink).hQue; \
  }

#define TLR_QUE_IND_SENDPACKET_FIFO(ptPck, uTim) \
  TLR_QUE_SENDPACKET_FIFO_INTERN((TLR_HANDLE)((TLR_PACKET_HEADER_T FAR*)ptPck)->ulRout, ptPck, uTim)

#define TLR_QUE_IND_SENDPACKET_LIFO(ptPck, uTim) \
  TLR_QUE_SENDPACKET_LIFO_INTERN((TLR_HANDLE)((TLR_PACKET_HEADER_T FAR*)ptPck)->ulRout, ptPck, uTim)


#endif /* #ifdef __RCX__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_LEGACY_H */
