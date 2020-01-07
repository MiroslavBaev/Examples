/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Pio.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Standardized definitions of RX PIOs

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_PIO_H
  #define __AP_PIO_H
  
  
 /*
  **************************************************************************
  *   Size of one PIO Control Block a Task has to allocate memory for
  **************************************************************************
  */ 

  #define DRV_PIO_SIZE (84)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
    
  RX_FATAL FAR    DrvPioInit            (const FAR void FAR*      pvCfg,
                                         UINT                     uNum); 

  RX_RESULT FAR   Drv_PioCreatePio      (RX_HANDLE                hPio,
                                         const RX_PIO_SET_T FAR*  ptCfg); 

  RX_RESULT FAR   Drv_PioIdentifyPio    (const STRING FAR*        pszIdn,
                                         UINT                     uInst,
                                         RX_HANDLE FAR*           phPio);

  RX_RESULT FAR   Drv_PioInitializePio  (RX_HANDLE                hPio);

  RX_RESULT FAR   Drv_PioSetOutputs     (RX_HANDLE                hPio,
                                         UINT                     uOutput);

  RX_RESULT FAR   Drv_PioClearOutputs   (RX_HANDLE                hPio,
                                         UINT                     uOutput);

  RX_RESULT FAR   Drv_PioGetInputs      (RX_HANDLE                hPio, 
                                         UINT FAR*                puInput);
  
#endif
  
#ifdef __cplusplus
}
#endif
