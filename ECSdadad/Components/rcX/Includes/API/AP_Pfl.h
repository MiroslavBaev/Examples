/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Pfl.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Parallel FLASH Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_PFL_H
  #define __AP_PFL_H

  typedef struct RX_PARALLELFLASH_GEOMETRY_Ttag
  {
    UINT32                            ulNumSectors;
    UINT32                            ulSectorSize;
  } RX_PARALLELFLASH_GEOMETRY_T;

  /*
  ******************************************************************************
  *   Size of one Parallel FLASH Control Block a Task has to allocate memory for
  ******************************************************************************
  */
  #define DRV_PARFLASH_SIZE (128)

  RX_FATAL FAR    DrvPFlsInit                 (const FAR void FAR*                    pvCfg,
                                               UINT                                   uNum);

  RX_RESULT FAR   Drv_PflCreateFlash          (RX_HANDLE                              hFlash,
                                               const RX_PARALLELFLASH_SET_T FAR*      ptCfg);

  RX_RESULT FAR   Drv_PflIdentifyFlash        (const STRING FAR*                      pszIdn,
                                               UINT                                   uInst,
                                               RX_HANDLE FAR*                         phFlash);

  RX_RESULT       Drv_PflInitializeFlash      (RX_HANDLE                              hFlash);

  RX_RESULT FAR   Drv_PflEraseFlashSector     (RX_HANDLE                              hFlash,
                                               UINT32                                 ulSecNum);

  RX_RESULT       Drv_PflEraseFlash           (RX_HANDLE                              hFlash,
                                               UINT32                                 ulStartAddr,
                                               UINT32                                 ulLen);

  RX_RESULT FAR   Drv_PflEraseFlashDevice     (RX_HANDLE                              hFlash);

  RX_RESULT FAR   Drv_PflGetFlashInfo         (RX_HANDLE                              hFlash,
                                               RX_PARALLELFLASH_SET_T FAR* FAR*       pptCfg);

  RX_RESULT FAR   Drv_PflGetFlashGeometry     (RX_HANDLE                              hFls,
                                               UINT32 FAR*                            pulTotalFlashSize,
                                               RX_PARALLELFLASH_GEOMETRY_T FAR*       ptSecGeo,
                                               UINT32 FAR*                            pulNumSecGeo); /* Get the flash geometry */
                                                                                          /* [in] pulNumSecGeo = number of entries storable in pptSecGeo */
                                                                                          /* [out] pulNumSecGeo = number of entries available in flash */

  RX_RESULT       Drv_PflWriteFlash           (RX_HANDLE                              hFlash,
                                               UINT32                                 ulOffset,
                                               const UINT8 HUGE*                      pabSrc,
                                               UINT32                                 ulNum);

  RX_RESULT       Drv_PflReadFlash            (RX_HANDLE                              hFlash,
                                               UINT32                                 ulOffset,
                                               UINT8 HUGE*                            pabDest,
                                               UINT32                                 ulNum);

#endif

#ifdef __cplusplus
}
#endif
