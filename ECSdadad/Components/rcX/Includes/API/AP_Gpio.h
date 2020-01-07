/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Gpio.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Standardized definitions of RX GPIOs 

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_GPIO_H
  #define __AP_GPIO_H
  
  
  /*
  ******************************************************************************
  *   Size of one GPIO Control Block a Task has to allocate memory for
  ******************************************************************************
  */ 
  
  #define DRV_GPIO_SIZE (68)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
   
  RX_FATAL FAR    DrvGpioInit             (const FAR void FAR*      pvCfg,
                                           UINT                     uNum); 

  RX_RESULT FAR   Drv_GpioCreateGpio      (RX_HANDLE                hGpio,
                                           const RX_GPIO_SET_T FAR* ptCfg); 

  RX_RESULT FAR   Drv_GpioIdentifyGpio    (const STRING FAR*        pszIdn,
                                           UINT                     uInst,
                                           RX_HANDLE FAR*           phGpio);

  RX_RESULT FAR   Drv_GpioInitializeGpio  (RX_HANDLE                hGpio);

  RX_RESULT FAR   Drv_GpioSetOutput       (RX_HANDLE                hGpio); 

  RX_RESULT FAR   Drv_GpioClearOutput     (RX_HANDLE                hGpio); 

  RX_RESULT FAR   Drv_GpioGetInput        (RX_HANDLE                hGpio,
                                           BOOLEAN FAR*             pfInp); 
  
#endif
  
#ifdef __cplusplus
}
#endif
