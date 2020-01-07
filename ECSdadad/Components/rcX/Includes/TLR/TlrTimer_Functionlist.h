/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TlrTimer_Functionlist.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR timer functionlist

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_TIMER_FUNCTIONLIST_H
#define __TLR_TIMER_FUNCTIONLIST_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/****************************************************************************************
* Tlr Timer, startup parameter type */

typedef struct TLR_TIMER_STARTUPPARAMETER_Ttag     TLR_TIMER_STARTUPPARAMETER_T;

struct TLR_TIMER_STARTUPPARAMETER_Ttag
{
  TLR_UINT32  ulTaskIdentifier; /* task identifier see TLR_TaskIdentifier.h */
  TLR_UINT32  ulParamVersion;   /* structure version                        */
  TLR_UINT32  ulMaxApp;         /* maximum number of application timers     */
  TLR_UINT32  ulMaxIrq;         /* maximum number of interrupt timers       */
  TLR_UINT32  ulMaxPck;         /* maximum number of retry packet resources */
};



/****************************************************************************************
* Tlr Timer, function list */

/* tasks */
TLR_RESULT  TaskExit_TlrTimer (TLR_VOID FAR* pvTskRsc);
TLR_RESULT  TaskLeave_TlrTimer(TLR_VOID FAR* pvTskRsc, TLR_VOID FAR* pvLeave);
TLR_RESULT  TaskEnter_TlrTimer(TLR_VOID FAR* pvInit);




/***************************************************************************************/



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_TIMER_FUNCTIONLIST_H */
