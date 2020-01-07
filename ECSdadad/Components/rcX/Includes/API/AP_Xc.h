/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Xc.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of XC Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/

#ifndef __AP_XC_H
#define __AP_XC_H

#ifdef __cplusplus
extern "C" {
#endif

  /*
  ******************************************************************************
  *   Size of one XC Control Block a Task has to allocate memory for
  ******************************************************************************
  */
  #define DRV_XC_SIZE (60)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  RX_FATAL FAR                DrvXcInit                       (const FAR void FAR*      pvCfg,
                                                               UINT                     uNum);


  RX_RESULT FAR               Drv_XcCreateXc                  (RX_HANDLE                hXc,
                                                               const RX_XC_SET_T FAR*   ptCfg);

  RX_RESULT FAR               Drv_XcIdentifyXc                (const STRING FAR*        pszIdn,
                                                               UINT                     uInst,
                                                               RX_HANDLE FAR*           phXc);

  RX_RESULT FAR               Drv_XcLoadXcProgram             (RX_HANDLE                hXc);

  RX_RESULT FAR               Drv_XcResetXc                   (RX_HANDLE                hXc);

  RX_RESULT FAR               Drv_XcVerifyXcProgram           (RX_HANDLE                hXc,
                                                               UINT32 FAR*              pulErr);

  RX_RESULT FAR               Drv_XcEnableXc                  (RX_HANDLE                hXc);

  RX_RESULT FAR               Drv_XcDisableXc                 (RX_HANDLE                hXc);

  RX_RESULT FAR               Drv_XcGetAddress                (RX_HANDLE                hXc,
                                                               UINT32 FAR* FAR*         pptAddr);

  RX_RESULT FAR               Drv_XcWriteXc                   (RX_HANDLE                hXc,
                                                               UINT                     uOffset,
                                                               UINT32                   ulValue);

  RX_RESULT FAR               Drv_XcReadXc                    (RX_HANDLE                hXc,
                                                               UINT                     uOffset,
                                                               UINT32 FAR*              pulValue);

  RX_RESULT                   Drv_XcGetIOMemory               (RX_HANDLE                hXc,
                                                               UINT8 FAR* FAR*          ppabIOMem,
                                                               UINT32 FAR*              pulSize);

  RX_RESULT FAR               Drv_XcGetXcAddress              (RX_HANDLE                hXc,
                                                               void FAR* FAR*           ppvDest);

  UINT32 FAR                  Drv_XcGetInterrupt              (RX_HANDLE                hXc);

  void FAR                    Drv_XcSetInterrupt              (RX_HANDLE                hXc,
                                                               UINT32                   ulIrq);

  RX_RESULT FAR               LoadXc                          (RX_XC_TYPE               eXcTyp,
                                                               UINT                     uInst,
                                                               const UINT32*            pulXCMicrocode);
                                                               
  RX_RESULT FAR               ResetXc                         (UINT                     uInst);
                                                               
  RX_RESULT                   DisableXc                       (RX_XC_TYPE               eXcTyp,
                                                               UINT                     uInst);

  RX_RESULT                   EnableXc                        (RX_XC_TYPE               eXcTyp,
                                                               UINT                     uInst);

  RX_RESULT                   GetAddressXc                    (RX_XC_TYPE               eXcTyp,
                                                               UINT                     uInst,
                                                               UINT32 FAR* FAR*         pptAddr);                                                               
#ifdef __cplusplus
}
#endif

#endif /* __AP_XC_H */
