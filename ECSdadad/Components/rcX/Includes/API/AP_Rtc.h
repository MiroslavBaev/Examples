/******************************************************************************

  Copyright (C) 2011 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http:  www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Rtc.h 932 2012-05-09 08:17:13Z stephans $

  Description:
    Interface definition of the RTC driver module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2012-05-09  SS            Error flag added to signal unexpected RTC reset
    2011-12-07  NC            Differentiate between RX_RTC_STATUS_VALID and RX_RTC_STATUS_UPDATED.
    2011-12-06  NC            Added RX_RTC_STATUS_xxx flag definitions.
    2011-12-01  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifndef __AP_RTC_H
#define __AP_RTC_H

#include "sys/time.h"
#include "time.h"

/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/


/* RTC status flags */
#define RX_RTC_STATUS_INITIALIZED 0x00000001  /* RTC driver has been initialized */
#define RX_RTC_STATUS_VALID       0x00000002  /* RTC time found valid at init time */
#define RX_RTC_STATUS_UPDATED     0x00000004  /* RTC time has been set at least once */
#define RX_RTC_STATUS_ERROR       0x00000008  /* RTC hardware error (e.g. reset due to power failure) */

/* Prominent time stamps */
#define RX_RTC_TIME_MIN             0U          /* Thursday, 1970-01-01, 00:00:00 */
#define RX_RTC_TIME_MAX             4102444799U /* Thursday, 2099-12-31, 23:59:59 */
#define RX_RTC_TIME_1980_01_01      315532800U  /* FAT file system: Tuesday, 1980-01-01, 00:00:00 */
#define RX_RTC_TIME_2000_01_01      946684800U  /* millennium change: Saturday, 2000-01-01, 00:00:00 */


/*****************************************************************************/
/* Class, Type, and Structure Definitions                                    */
/*****************************************************************************/


typedef struct
{
  UINT32 ulStatus;  /* see RX_RTC_STATUS_xxx definitions above */
  UINT32 ulType;    /* see RX_RTC_TYPE_xxx definitions in rX_Config.h */
} RX_RTC_INFO_T;

/* Callback declaration for change of state notifications */
typedef VOID (*PFN_RTC_CALLBACK) (RX_RTC_INFO_T* ptInfo, void* pvUser);

/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/

RX_FATAL  MidRtcInit              (void FAR*        pvPar, 
                                   UINT             uPar);

RX_RESULT Mid_RtcSetTime          (struct timeval*  ptTime);

RX_RESULT Mid_RtcGetTime          (struct timeval*  ptTime);

RX_RESULT Mid_RtcGetInfo          (RX_RTC_INFO_T*   ptInfo);

RX_RESULT Mid_RtcLocalTime        (struct tm*       ptTimeStruct, 
                                   struct timeval*  ptTime);

RX_RESULT Mid_RtcMkTime           (struct timeval*  ptTime,
                                   struct tm*       ptTimeStruct);

RX_RESULT Mid_RtcRegisterCallback (PFN_RTC_CALLBACK pfnCallback, 
                                   void*            pvUser);

/*****************************************************************************/
/* RTC initialization routines                                               */
/*****************************************************************************/
RX_RESULT Pcf8563Init    (RX_HANDLE               hRtcDevice, 
                          RX_PERIPHERAL_HEADER_T* ptI2cCfg);

RX_RESULT nX500RtcInit   (RX_HANDLE               hRtcDevice, 
                          RX_PERIPHERAL_HEADER_T* ptCfg);

#endif  /* __AP_RTC_H */


#ifdef __cplusplus
}
#endif /* __cplusplus */
