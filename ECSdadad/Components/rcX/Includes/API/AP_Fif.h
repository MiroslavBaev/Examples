/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Fif.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Standardized definitions of Fifo Unit Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_FIF_H
  #define __AP_FIF_H

  /*
  ******************************************************************************
  *   Size of one FIFOCHANNEL Control Block a Task has to allocate memory for
  ******************************************************************************
  */
  
  #define DRV_FIF_SIZE (84)

 /*
  **************************************************************************
  *   Type declaration for LED driver
  **************************************************************************
  */ 
  
  enum DRV_FIF_FIFO_NUMtag {
    DRV_FIF_FIFO_NUM0,
    DRV_FIF_FIFO_NUM1,
    DRV_FIF_FIFO_NUM2,
    DRV_FIF_FIFO_NUM3,
    DRV_FIF_FIFO_NUM4,
    DRV_FIF_FIFO_NUM5,
    DRV_FIF_FIFO_NUM6,
    DRV_FIF_FIFO_NUM7
  };
  typedef int DRV_FIF_FIFO_NUM;

  /*
  **************************************************************************
  *   Declaration of FIFO driver functions
  **************************************************************************
  */
  
  RX_FATAL FAR    DrvFifInit                    (const FAR void FAR*                pvCfg,
                                                 UINT                               uNum);


  RX_RESULT FAR   Drv_FifCreateFifochannel      (RX_HANDLE                          hFifChn,
                                                 const RX_FIFOCHANNEL_SET_T FAR*    ptCfg);

  RX_RESULT FAR   Drv_FifIdentifyFifochannel    (const STRING FAR*                  pszIdn,
                                                 UINT                               uInst,
                                                 RX_HANDLE FAR*                     phFifChn);

  RX_RESULT FAR   Drv_FifInitializeFifochannel  (RX_HANDLE                          hFifChn);

  RX_RESULT FAR   Drv_FifWriteToFifo            (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum,
                                                 UINT32                             ulVlu);

  RX_RESULT FAR   Drv_FifReadFromFifo           (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum,
                                                 UINT32 FAR*                        pulVlu);

  RX_RESULT FAR   Drv_FifSetFifoReset           (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifClearFifoReset         (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifIsFifoUnderrun         (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifIsFifoOverflow         (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifIsFifoEmpty            (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifIsFifoFull             (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum);

  RX_RESULT FAR   Drv_FifGetFifoFillLevel       (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum,
                                                 UINT FAR*                          puLvl);

  RX_RESULT FAR   Drv_FifWriteMultipleToFifo    (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum,
                                                 UINT32                             ulNumValues,
                                                 const UINT32 FAR*                  pulValues);

 RX_RESULT FAR    Drv_FifReadMultipleFromFifo   (RX_HANDLE                          hFifChn,
                                                 DRV_FIF_FIFO_NUM                   eFifNum,
                                                 UINT32                             ulNumValues,
                                                 UINT32 FAR*                        pulValues);


#endif

#ifdef __cplusplus
}
#endif
