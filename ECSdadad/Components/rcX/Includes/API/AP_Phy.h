/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Phy.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of PHY Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_PHY_H
  #define __AP_PHY_H

  /*
  ******************************************************************************
  *   Size of one PHY Control Block a Task has to allocate memory for
  ******************************************************************************
  */ 
  
  #define DRV_PHY_SIZE (316)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  RX_FATAL FAR    DrvPhyInit              (const FAR void FAR*      pvCfg,
                                           UINT                     uNum);


  RX_RESULT FAR   Drv_PhyCreatePhy        (RX_HANDLE                hPhy,
                                           const RX_PHY_SET_T FAR*  ptCfg);

  RX_RESULT FAR   Drv_PhyIdentifyPhy      (const STRING FAR*        pszIdn,
                                           UINT                     uInst,
                                           RX_HANDLE FAR*           phPhy);

  RX_RESULT FAR   Drv_PhyTestLoopback     (RX_HANDLE                hPhy);

  RX_RESULT FAR   Drv_PhyInitialize       (RX_HANDLE                hPhy);

  RX_RESULT FAR   Drv_PhyReadRegister     (RX_HANDLE                hPhy,
                                           UINT                     uRegAddr,
                                           UINT FAR*                puData);

  RX_RESULT FAR   Drv_PhyWriteRegister    (RX_HANDLE                hPhy,
                                           UINT                     uRegAddr,
                                           UINT                     uData);
#endif

#ifdef __cplusplus
}
#endif
