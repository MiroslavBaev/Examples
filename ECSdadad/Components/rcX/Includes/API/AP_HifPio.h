/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_HifPio.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Standardized definitions of RX HIFPIOs

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_HIFPIO_H
  #define __AP_HIFPIO_H

  /*
  ******************************************************************************
  *   Size of one HIFPIO Control Block a Task has to allocate memory for
  ******************************************************************************
  */
  
  #define DRV_HIFPIO_SIZE (72)

 /*
  **************************************************************************
  *   Type declarations
  **************************************************************************
  */
                             
  typedef struct DRV_HIFPIO_DATA_Ttag {
    UINT32 ulData0; 
    UINT32 ulData1; 
  } DRV_HIFPIO_DATA_T;

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */

  RX_FATAL FAR  DrvHifPioInit               (const FAR void FAR*              ptCfg,
                                             UINT                             uNum);

  RX_RESULT FAR Drv_HifPioCreateHifPio      (RX_HANDLE                        hHifPio, 
                                             const FAR RX_HIFPIO_SET_T FAR*   ptCfg);

  RX_RESULT FAR Drv_HifPioInitializeHifPio  (RX_HANDLE                        hHifPio);

  RX_RESULT FAR Drv_HifPioIdentifyHifPio    (const STRING FAR*                pszIdn,
                                             UINT                             uInst,
                                             RX_HANDLE FAR*                   phHifPio);

  RX_RESULT FAR Drv_HifPioGetInputs         (RX_HANDLE                        hHifPio,
                                             DRV_HIFPIO_DATA_T FAR*           ptData);

  RX_RESULT FAR Drv_HifPioSetOutputs        (RX_HANDLE                        hHifPio, 
                                             DRV_HIFPIO_DATA_T FAR*           ptData);

  RX_RESULT FAR Drv_HifPioGetOutputs        (RX_HANDLE                        hHifPio, 
                                             DRV_HIFPIO_DATA_T FAR*           ptData);

#endif
  
#ifdef __cplusplus
}
#endif
