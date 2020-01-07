/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Spi.h 1389 2013-04-03 10:10:29Z MichaelT $

  Description:
    Standardized definitions of SPI Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_SPI_H
  #define __AP_SPI_H

  /*
  **************************************************************************
  *   Size of one SPI Control Block a Task has to allocate memory for
  **************************************************************************
  */

  #define DRV_SPI_SIZE (68)

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */

  RX_FATAL FAR      DrvSpiInit            (const FAR void FAR*              pvCfg,
                                           UINT                             uNum);

  RX_RESULT FAR     Drv_SpiCreateSpi      (RX_HANDLE                        hSpi,
                                           const RX_SPISLAVE_SET_T FAR*     ptCfg);

  RX_RESULT FAR     Drv_SpiIdentifySpi    (const STRING FAR*                pszIdn,
                                           UINT                             uInst,
                                           RX_HANDLE FAR*                   phSpi);

  RX_RESULT FAR     Drv_SpiInitializeSpi  (RX_HANDLE                        hSpi);

  RX_RESULT FAR     Drv_SpiConfigure      (RX_HANDLE                        hSpi,
                                           RX_SPI_MODE                      eMode,
                                           RX_SPI_CLOCK                     eSpeed,
                                           UINT                             uBurstBlock,
                                           UINT                             uBurstDelay);

  RX_RESULT FAR     Drv_SpiGetConfig      (RX_HANDLE                        hSpi,
                                           RX_SPI_MODE*                     peMode,
                                           RX_SPI_CLOCK*                    peSpeed,
                                           UINT*                            puBurstBlk,
                                           UINT*                            puBurstDly);
                                           
  RX_RESULT FAR     Drv_SpiOpen           (RX_HANDLE                        hSpi,
                                           UINT                             uTimeout);

  RX_RESULT FAR     Drv_SpiSlaveSelect    (RX_HANDLE                        hSpi);

  RX_RESULT FAR     Drv_SpiSlaveDeselect  (RX_HANDLE                        hSpi);

  RX_RESULT FAR     Drv_SpiSendReceive    (RX_HANDLE                        hSpi,
                                           UINT                             uLen,
                                           const UINT8 *                    pSendBuf,
                                           UINT8 *                          pRecBuf);

  RX_RESULT FAR     Drv_SpiSend           (RX_HANDLE                        hSpi,
                                           UINT                             uLen,
                                           const UINT8 *                    pSendBuf);

  RX_RESULT FAR     Drv_SpiReceive        (RX_HANDLE                        hSpi,
                                           UINT                             uLen,
                                           UINT8 *                          pRecBuf,
                                           UINT8                            bIdleByte);

  RX_RESULT FAR     Drv_SpiSendIdle       (RX_HANDLE                        hSpi,
                                           UINT                             uLen,
                                           UINT8                            bIdleByte);

  RX_RESULT FAR     Drv_SpiClose          (RX_HANDLE                        hSpi);

  RX_RESULT FAR     Drv_SpiDeleteSpi      (RX_HANDLE                        hSpi);

  /* Internal function to allow seperating bus interrupts if multiple SPI busses share the same IRQ */
  typedef void(*PFN_SPI_IRQ_HANDLER)(void* pvParam);

  RX_RESULT         DrvSpiSetBusIrqHandler(UINT uPortIdx, PFN_SPI_IRQ_HANDLER pfnIsr, void* pvIsrParam);
  RX_RESULT         DrvSpiGetBusIrqHandler(UINT uPortIdx, PFN_SPI_IRQ_HANDLER* ppfnIsr, void** ppvIsrParam);

#endif

#ifdef __cplusplus
}
#endif
