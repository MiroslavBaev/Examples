/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Vol.h 1350 2013-03-18 11:12:47Z MichaelT $

  Description:
    Standardized definitions of for Volume handling

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_VOL_H
  #define __AP_VOL_H

 /*
  **************************************************************************
  *   Size of one Volume Control Block a Task has to allocate memory for
  **************************************************************************
  */

  #define DRV_VOLUME_SIZE (176)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  
  typedef RX_RESULT(FAR* APP_VOL_HANDLER)(RX_HANDLE hVol); 

  RX_FATAL FAR    DrvVolInit              (const FAR void FAR*              pvCfg,
                                           UINT                             uNum);

  RX_RESULT FAR   Drv_VolCreateVolume     (RX_HANDLE                        hVol,
                                           const FAR RX_VOLUME_SET_T FAR*   ptCfg);

  RX_RESULT FAR   Drv_VolDeleteVolume     (RX_HANDLE                        hVol);

  RX_RESULT FAR   Drv_VolIdentifyVolume   (const STRING FAR*                pszIdn,
                                           RX_HANDLE FAR*                   phVol);

  RX_RESULT FAR   Drv_VolMountVolume      (RX_HANDLE                        hVol,
                                           APP_VOL_HANDLER                  pfnFilInit);

  RX_RESULT FAR   Drv_VolReadVolume       (RX_HANDLE                        hVol,
                                           UINT32                           ulSec,
                                           UINT32                           ulSecNum,
                                           UINT8 FAR*                       pabBuf,
                                           UINT32 FAR*                      pulSecInCache);

  RX_RESULT FAR   Drv_VolWriteVolume      (RX_HANDLE                        hVol,
                                           UINT32                           ulSec,
                                           UINT32                           ulSecNum,
                                           UINT8 FAR*                       pabBuf);
  
  RX_RESULT FAR   Drv_VolFormatVolume     (RX_HANDLE                        hVol);
  
  RX_RESULT FAR   Drv_VolUnmountVolume    (RX_HANDLE                        hVol,
                                           APP_VOL_HANDLER                  pfnFilDeinit);

  RX_RESULT FAR   Drv_VolLockVolume       (RX_HANDLE                        hVol,
                                           UINT                             uTimeoutOpt);

  RX_RESULT FAR   Drv_VolUnlockVolume     (RX_HANDLE                        hVol);
  
  RX_RESULT FAR   Drv_VolGetName          (UINT32                           ulIndex, 
                                           STRING FAR*                      pszName, 
                                           UINT                             ulBufferLen);

  RX_RESULT FAR   Drv_VolGetCount         (UINT32 FAR*                      pulCount);

#endif

#ifdef __cplusplus
}
#endif
