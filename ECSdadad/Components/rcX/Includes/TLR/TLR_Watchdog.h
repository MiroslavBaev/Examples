/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Watchdog.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR watchdog definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_WATCHDOG_H
#define __TLR_WATCHDOG_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



#define TLR_WATCHDOG_TIME_OFF     0x00000000L /* Watchdog supervision disabled          */
#define TLR_WATCHDOG_TIME_MIN     0x00000014L /* Minimum value for watchdog supervision */
#define TLR_WATCHDOG_TIME_MAX     0x0000ffffL /* Maximum value for watchdog supervision */

typedef struct TLR_WATCHDOG_Ttag
{
  /** Module initialized flag */
  TLR_BOOLEAN fInitialized;
  /** Control data block */
  NETX_CONTROL_BLOCK FAR* ptControlData;
  /** Common state block */
  NETX_COMMON_STATUS_BLOCK FAR* ptCommonState;
  /** Handle to watchdog timer */
  TLR_HANDLE hWdgTimer;
  /** Queue handle*/
  TLR_HANDLE hQue;  
  /** Packet for watchdog timeout */
  TLR_PACKET_HEADER_T tWatchdogPck;
  /** Retry send watchdog packet*/
  TLR_BOOLEAN fRetryWatchdogTimeout;
  
  /** Time Base for Watchdog*/
  TLR_UINT32  ulTimeBase;
  
  /** Watchdog supervision enabled */
  TLR_BOOLEAN fWatchdogEnabled;   
  /** Watchdog timeout detected    */
  TLR_BOOLEAN fWatchdogTimeout;  
  
  /** Watchdog start value */
  TLR_UINT32  ulWatchdogStart;   
  /** Remaining time for watchdog */
  TLR_UINT32  ulWatchdogTimer;   
  /** Value of device watchdog */
  TLR_UINT32  ulDeviceWatchdog;   
  /** Value of host watchdog */
  TLR_UINT32  ulHostWatchdog;     
  
}TLR_WATCHDOG_T;

/*------------------------------------------------------------------------------------*/
/* Functions                                                                          */
/*------------------------------------------------------------------------------------*/
TLR_RESULT
Tlr_Watchdog_Initialize
(
TLR_WATCHDOG_T FAR* ptWatchdog,              /** Watchdog structure                   */
NETX_CONTROL_BLOCK FAR* ptControlData,       /** Control data block                   */
NETX_COMMON_STATUS_BLOCK FAR* ptCommonState, /** Common state data block              */
TLR_UINT32 ulTimeBase,                       /** Time base for callback function      */
TLR_UINT32 ulCmd,                            /** Comand for watchdog packet           */
TLR_QUE_LINK_SOURCE_T  FAR* ptQueSrc,        /** Queue source for watchdog packet     */
TLR_HANDLE hQue                              /** Queue handle                         */
);

TLR_RESULT
Tlr_Watchdog_Deinitialize                    /** Watchdog structure                   */
(
TLR_WATCHDOG_T FAR* ptWatchdog
);

TLR_VOID CALLBACK FAR
Tlr_Watchdog_Callback
(
TLR_WATCHDOG_T FAR* ptWatchdog               /** Watchdog structure                   */
);

TLR_RESULT
Tlr_Watchdog_Activate
(
TLR_WATCHDOG_T FAR* ptWatchdog,              /** Watchdog structure                   */
TLR_UINT32 ulWatchdogTime                    /** Watchdog time in milliseconds        */
);

TLR_VOID
Tlr_Watchdog_SendTimeoutPacket
(
TLR_WATCHDOG_T FAR* ptWatchdog               /** Watchdog structure                   */
);

TLR_VOID
Tlr_Watchdog_HandleWatchdog
(
TLR_WATCHDOG_T FAR* ptWatchdog               /** Watchdog structure                   */
);



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_WATCHDOG_H */
