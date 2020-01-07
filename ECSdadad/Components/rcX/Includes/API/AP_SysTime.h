/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_SysTime.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Standardized definitions of SysTime Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_SYSTIME_H
#define __AP_SYSTIME_H

// Systime TimeStamp structure contains Nanoseconds and *Seconds*.
// The meaning of Seconds is influenced by the NETX_SYS_TIME_NS_BOR register.

typedef struct SYSTIME_TIMESTAMP_Ttag
{
  UINT32 ulTimeNs;
  UINT32 ulTimeS;
} SYSTIME_TIMESTAMP_T;


RX_RESULT             Drv_SysTimeSetTime                  (SYSTIME_TIMESTAMP_T FAR*         ptTimeStamp);
void                  Drv_SysTimeGetTime                  (SYSTIME_TIMESTAMP_T FAR*         ptTimeStamp);

void                  Drv_SysTimeSetSysTimeBorder         (UINT32                           ulSystimeBorder);
UINT32                Drv_SysTimeGetSysTimeBorder         (void);

void                  Drv_SysTimeSetSysTimeCountValue     (UINT32                           ulSystimeCountVal);
UINT32                Drv_SysTimeGetSysTimeCountValue     (void);

RX_RESULT             Drv_SysTimeAddTime                  (const SYSTIME_TIMESTAMP_T FAR*   ptTimestamp,
                                                           UINT32                           ulAddTime_s,
                                                           UINT32                           ulAddTime_ns,
                                                           SYSTIME_TIMESTAMP_T FAR*         ptTimestampSum);

int                   Drv_SysTimeCompareSystime           (SYSTIME_TIMESTAMP_T FAR*         ptTimestamp);

int                   Drv_SysTimeCompareTimestamps        (const SYSTIME_TIMESTAMP_T FAR*   ptTimestampA,
                                                           const SYSTIME_TIMESTAMP_T FAR*   ptTimestampB);

RX_RESULT             Drv_SysTimeGetTimestampDifference   (const SYSTIME_TIMESTAMP_T FAR*   ptTimestampA,
                                                           const SYSTIME_TIMESTAMP_T FAR*   ptTimestampB,
                                                           SYSTIME_TIMESTAMP_T FAR*         ptTimestampResult,
                                                           int *                            piCompareResult);

INLINE UINT64 Drv_SysTimeConvertTimestampToTime(SYSTIME_TIMESTAMP_T FAR* ptTimestamp)
{
  UINT64 ullTime = ptTimestamp->ulTimeS;
  ullTime *= (((UINT64)Drv_SysTimeGetSysTimeBorder())+1);
  return ullTime+ptTimestamp->ulTimeNs;
}

#endif  // __systime__

#ifdef __cplusplus
}
#endif
