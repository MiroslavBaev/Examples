/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TlrTimer_Public.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR timer - public declaration of task

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_TIMER_PUBLIC_H
#define __TLR_TIMER_PUBLIC_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/***************************************************************************************/
/* Tlr Timer, constants */

#define TLR_TIMER_APPL_ONESHOT          (0)
#define TLR_TIMER_APPL_RELOAD           (1)



/***************************************************************************************/
/* Tlr Timer, packets */

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(TLR_TIMER_PUBLIC)
#endif

/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(TLR_TIMER_PUBLIC)
#endif



/***************************************************************************************/
/* Tlr Timer, extern function list */

/* interrupt timer */
TLR_RESULT  TlrTimerInterruptRegister  (TLR_UINT32 ulTimRld, TLR_VOID FAR* FAR* phTimIrq);
TLR_RESULT  TlrTimerInterruptUnregister(TLR_VOID FAR* hTimIrq);
TLR_RESULT  TlrTimerInterruptReset     (TLR_VOID FAR* hTimIrq);
TLR_UINT32  TlrTimerInterruptWait      (TLR_VOID FAR* hTimIrq);

/* application timer */
TLR_RESULT  TlrTimerApplicationCreate          (TLR_HANDLE hQue, TLR_UINT32 ulMode, TLR_UINT32 ulTimRld, TLR_VOID FAR* FAR* phTim);
TLR_RESULT  TlrTimerApplicationDelete          (TLR_VOID FAR* hTim);
TLR_RESULT  TlrTimerApplicationStart           (TLR_VOID FAR* hTim, TLR_VOID FAR* pvPck);
TLR_RESULT  TlrTimerApplicationStop            (TLR_VOID FAR* hTim);
TLR_RESULT  TlrTimerApplicationGetRemainingTime(TLR_VOID FAR* hTim, TLR_UINT32 FAR* ulMSecs);
TLR_RESULT  TlrTimerApplicationGetElapsedTime  (TLR_VOID FAR* hTim, TLR_UINT32 FAR* ulMSecs);
TLR_RESULT  TlrTimerApplicationRetrigger       (TLR_VOID FAR* hTim);
TLR_RESULT  TlrTimerApplicationReload          (TLR_VOID FAR* hTim, TLR_UINT32 ulTimRld);
TLR_RESULT  TlrTimerApplicationInitPacket      (TLR_VOID FAR* hTim, TLR_VOID FAR* pvPck);
TLR_RESULT  TlrTimerApplicationInitReload      (TLR_VOID FAR* hTim, TLR_UINT32 ulTimRld);
TLR_RESULT  TlrTimerApplicationGetPacket       (TLR_VOID FAR* hTim, TLR_VOID FAR* FAR* pvPck);

/* retry packet */
TLR_RESULT  TlrTimerPacketRetry(TLR_HANDLE hQue, TLR_VOID FAR* pvPck);



/***************************************************************************************/



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_TIMER_PUBLIC_H */
