/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: OS_rX_Wrapper.h 654 2011-03-14 11:13:02Z MichaelT $

  Description:
    Wrapper for operating system rcX - realtime communication-system for netX

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-14  NC            Re-added define TLR_BUFFERPOOL_T

    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __OS_RX_WRAPPER_H
#define __OS_RX_WRAPPER_H

#ifdef __cplusplus
  extern "C" {
#endif



/*************************************************************************************/
/* TLR prototypes for rcX */

#define   TLR_BUFFERPOOL_T    RX_BUFFERPOOL_T
#define   TLR_MEM_NO_UPDATE   RX_MEM_NO_UPDATE

/* Time functions */
UINT32 FAR TLR_OS_TimeToTick(UINT32 ulMSec);
UINT32 FAR TLR_OS_MicroTimeToTick(UINT32 uMicroSecs);
UINT32 FAR TLR_OS_TickToTime(UINT32 ulTicks);

UINT FAR  TLR_OS_HardTimerCreate(void FAR* fnExp, void FAR* pvInpt, UINT uMod, UINT uTimRld, UINT uTimDly, void FAR* FAR* phTim);
UINT FAR  TLR_OS_HardTimerDelete(void FAR* hTim);

/* semaphore functions */
UINT FAR  TLR_OS_SemaphoreCreate(STRING FAR* pszIdn, UINT uMax, void FAR* FAR* hSem);
UINT FAR  TLR_OS_SemaphoreDelete(void FAR* hSem);

/* mutex functions */
UINT FAR  TLR_OS_MutexCreate(STRING FAR* pszIdn,UINT uMaxPrc, void FAR* FAR* phMtx);
UINT FAR  TLR_OS_MutexDelete(void FAR* hMtx);

/* TripleBuffer-Control-Block functions */
UINT FAR TLR_OS_TripleBufferCreate(STRING FAR* pszIdn, TLR_HANDLE FAR* phTrp, TLR_BUFFERPOOL_T FAR* ptBufPool);
UINT FAR TLR_OS_TripleBufferDelete(TLR_HANDLE hTrp);

/* Task Control functions */
UINT FAR TLR_OS_TaskSetLeaveFunction(void FAR*          fnLeave,
                                     void FAR*          pvUsr,
                                     void FAR* FAR*     phHook);

/* Packet Queue functions */
UINT FAR TLR_OS_MsgQueueCreate(STRING FAR* pszIdn,
                               UINT uDep,
                               UINT uNumOfElmt,
                               UINT uElmtSiz,
                               void FAR* FAR* ppvQue);

#if !defined( _CONSOLE_32_ )
UINT FAR TLR_OS_MsgQueueCreateIo(STRING FAR* pszIdn,
                                 UINT8 FAR* pabIOMem,
                                 UINT uDep,
                                 UINT uNumOfElmt,
                                 UINT uElmtSiz,
                                 void FAR* FAR* ppvQue);
#endif

UINT FAR TLR_OS_MsgQueueDelete(void FAR* hQue);

/* Hook */
void FAR  TLR_OS_HookDelete(void FAR* hHook);

#ifndef __BORLANDC__
char *ultoa (unsigned long value, char *string, int radix);
#endif

/*************************************************************************************/



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __OS_RX_WRAPPER_H */
