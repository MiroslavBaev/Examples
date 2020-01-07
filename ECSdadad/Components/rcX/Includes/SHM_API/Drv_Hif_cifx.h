/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Id: Drv_Hif_cifx.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX  : yes

   Description:
    Headerfile of Host Interface Module

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
      1        09.07.2011  MT       ported from rcX V2

**************************************************************************************/

#ifndef __DRV_HIF_H
#define __DRV_HIF_H

  #include "AP_Hif.h" /* Include Application definitions */
  #include "rcX_User.h"

  /* Stack size of the DPM-Driver Task */
  #define HAL_HIF_DPMTSK_STK_SIZE 256

  /* HOST flags written by the DEVICE */
  #define HAL_HIF_DPM_HOSTFLAG_HOSTCOM  0x0001
  #define HAL_HIF_DPM_HOSTFLAG_DEVACK   0x0002
  #define HAL_HIF_DPM_HOSTFLAG_PDACK    0x0004
  #define HAL_HIF_DPM_HOSTFLAG_STATECOM 0x0008
  #define HAL_HIF_DPM_HOSTFLAG_RESERVED 0x0010
  #define HAL_HIF_DPM_HOSTFLAG_COM      0x0020
  #define HAL_HIF_DPM_HOSTFLAG_RUN      0x0040
  #define HAL_HIF_DPM_HOSTFLAG_RDY      0x0080

  /* DEVICE flags written by the HOST */
  #define HAL_HIF_DPM_DEVFLAG_HOSTACK   0x0001
  #define HAL_HIF_DPM_DEVFLAG_DEVCOM    0x0002
  #define HAL_HIF_DPM_DEVFLAG_PDCOM     0x0004
  #define HAL_HIF_DPM_DEVFLAG_STATEACK  0x0008
  #define HAL_HIF_DPM_DEVFLAG_RESERVED  0x0010
  #define HAL_HIF_DPM_DEVFLAG_NOTREADY  0x0020
  #define HAL_HIF_DPM_DEVFLAG_INIT      0x0040
  #define HAL_HIF_DPM_DEVFLAG_RESET     0x0080

  /* System Area Handshake Bit definitions */
  #define HAL_HIF_MAX_NUM_IRQS_PER_BLOCK 16
  
  /*
  ***********************************************************
  *  Administrator Structure for one HIF
  ***********************************************************
  */

  typedef struct HIF_DMA_AREA_Ttag
  {
    struct
    {
      volatile UINT32  ulHostStart;
      volatile UINT32  ulNetxStart;
      volatile UINT32  ulDmaCtrl;
      volatile UINT32  ulMbxBase;
      volatile UINT32  ulBufferCtrl;
      volatile UINT32  aulNetxBuffers[3];
    } atDmaChannels[8];
    
    UINT32 aulReserved[32];
    
    struct
    {
      volatile UINT32 ulMemStart;
      volatile UINT32 ulMemEnd;
    } atWindows[4];
    
    volatile UINT32 ulPciIoBase;
    volatile UINT32 ulPciRomBase;
    volatile UINT32 ulPciArbiterCtrl;
    volatile UINT32 ulPciCtrl;
    
  } HIF_DMA_AREA_T;

  typedef struct RX_HIF_Ttag 
  {
    struct RCX_OBJECT_HEADER_T tObjHdr;                                         /* Header Data */
    
    RX_HIF_MODE_TYPE        eHifMod;                                            /* HIF general operation mode */
    UINT32                  ulMode0;                                            /* Configures Pins to be either IO or not */
    UINT32                  ulMode1;                                            /* Configures Pins to be either IO or not */
    UINT32                  ulDrvEn0;                                           /* Configures Pins to be either output or input */
    UINT32                  ulDrvEn1;                                           /* Configures Pins to be either output or input */
    UINT32                  ulConf0;                                            /* Configures the CPU specific configuration settings */
    UINT32                  ulConf1;                                            /* Configures the CPU specific configuration settings */
    UINT32                  ulIOMemTotSiz;                                      /* Total size of the optional Input/Output Memory */
    BOOLEAN                 fKeepHifRegisters;                                  /* keep HIF registers as set by ROM bootloader */
    UINT32                  uNumOfChannels;                                     /* Number of following AREAs in this Memory */
    BOOLEAN                 fAlwaysUseHandshakeBlock;                           /* select to use handshake block on any interface */
    RX_HIF_CHANNEL_T FAR*   patChannelBlk;                                      /* Channel configuration */

    DRV_HIF_PIO_DATA_T      tOutputs;                                           /* current output data */
    UINT                    auSrt[RX_HIF_MAX_SUPPORTED_CHANNELS];               /* Start-Offsets of the AREAs within the HIF */
    UINT                    auEnd[RX_HIF_MAX_SUPPORTED_CHANNELS];               /* Start-Offsets of the AREAs within the HIF */
    UINT                    auSiz[RX_HIF_MAX_SUPPORTED_CHANNELS];               /* Size of the AREAs within the HIF */
    void*                   apvArea[RX_HIF_MAX_SUPPORTED_CHANNELS];             /* Control block pointer to the different AREAs */
    UINT8*                  apabAreaAddress[RX_HIF_MAX_SUPPORTED_CHANNELS];     /* Pointer to 8 physical addresses within the ARM (virtual/physical) */
    UINT32                  aulPhysAreaAddress[RX_HIF_MAX_SUPPORTED_CHANNELS];  /* Pointer to 8 physical addresses within the ARM (physical) */
    BOOLEAN                 fHndshkInArea1;                                     /* is TRUE if the handshake area is allocated */
    UINT32                  ulPhysMemoryBase;                                   /* start of physical memory (RAM) allocated for HIF use */
    UINT32                  ulPhysMemorySize;                                   /* Current size the physical memory has for HIF use */
    UINT8*                  pbVirtMemoryBase;                                   /* start of physical memory address mapped in process data */
    HIF_DMA_AREA_T*         ptHifDma;                                           /* Pointer to DMA register */          
  } RX_HIF_T;
 
 /*
  ************************************************************
  *   Defines & Enums
  ************************************************************
  */
  enum HAL_HIFIRQVECT_ID_Ttag {
    HAL_HIFIRQVECT_ID_HANDSHAKE,
    HAL_HIFIRQVECT_ID_NETXDATADMA,
    HAL_HIFIRQVECT_ID_NETXMBOXDMA,
    HAL_HIFIRQVECT_ID_HOSTDATADMA,
    HAL_HIFIRQVECT_ID_HOSTMBOXDMA,
    HAL_HIFIRQVECT_ID_MEMLOCK,
    HAL_HIFIRQVECT_ID_WATCHDOG,
    HAL_HIFIRQVECT_ID_EXT
  };
  typedef int HAL_HIFIRQVECT_ID_T;
  
  /*
  ************************************************************
  *   Dualport Memory Physical Layout Structure
  ************************************************************
  */
  typedef struct HAL_HIF_NETX_SUBBLOCK_Ttag HAL_HIF_NETX_SUBBLOCK_T;
  
  typedef struct HAL_HIF_NETX_CHANNEL_Ttag 
  {
    struct RCX_OBJECT_HEADER_T   tObjHdr;             /* Header Data */
    RX_HIF_CHANNEL_T             tChannelCfg;         /* Configuration data for this Area */
    struct RCX_OBJECT_SENTINEL_T tHalHifSubblockSntl; /* Doubly linked list for the Subblock Control List */
  
    struct HAL_HIF_NETX_SUBBLOCK_Ttag FAR* aptHdshkToSubblock[RX_HIF_MAX_SUPPORTED_BLOCKS]; /* Conversion handshake to subblock */
    void FAR*                              apvPrmSubblock[RX_HIF_MAX_SUPPORTED_BLOCKS]; /* Parameter for each callback function per Subblock */
    struct RCX_TCB_T FAR*                  aptWaiter[RX_HIF_MAX_SUPPORTED_BLOCKS]; /* task waiting for Confirmation */
  
    PFN_HIF_HSKBIT_CBK afnHndshke[RX_HIF_MAX_SUPPORTED_FUNCTIONS]; /* Callback function for handshake */
    void FAR* apvPrmBitFunction[RX_HIF_MAX_SUPPORTED_FUNCTIONS]; /* Parameter for each callback function */
    RX_HIF_BITFUNCTION_TYPE aeTypeBitFunction[RX_HIF_MAX_SUPPORTED_FUNCTIONS]; /* Parameter for each callback function */
  
    UINT8 FAR* pabAreaMemory; /* Pointer to physical memory of AREA */
  
    void FAR* pvHndShk; /* Pointer where to read the Handshake cell from */
    void FAR* pvCopyHndShk;
    void FAR* pvHsHndShk; /* Pointer the Handshake cell from Host side*/
    volatile UINT uHstFlgsSav; /* Hostflags save value    */
    volatile UINT uDevFlgsSav; /* Deviceflags save value */
  
    PFN_HIF_APPCOS_CBK pfnCOSCallback;
    void FAR*          pvCOSParam;
    
    PFN_HIF_APPCOS_BIT_CBK pfnCosInitCallback;
    void*                  pvCosInitParam;
    
    PFN_HIF_APPCOS_BIT_CBK pfnCosLockConfigCallback;
    void*                  pvCosLockConfigParam;
    
    PFN_HIF_APPCOS_BIT_CBK pfnCosAppReadyCallback;
    void*                  pvCosAppReadyParam;
    
    PFN_HIF_APPCOS_BIT_CBK pfnCosBusOnCallback;
    void*                  pvCosBusOnParam;
    
    PFN_HIF_APPCOS_BIT_CBK pfnCosDMACallback;
    void*                  pvCosDMAParam;
  
    UINT32 ulCOSBuffer;
    UINT32 ulAppCOSBuffer;
  
    HAL_HIF_NETX_SUBBLOCK_T FAR* ptDevWdgBlk;
    HAL_HIF_NETX_SUBBLOCK_T FAR* ptHstWdgBlk;
  
    /* pointer to common status area */
    NETX_COMMON_STATUS_BLOCK FAR*     ptCommonState;
    /* pointer to control block */
    NETX_CONTROL_BLOCK FAR*           ptControlBlock;
  
    BOOLEAN fComCOSHanging;
  } HAL_HIF_NETX_CHANNEL_T;
  
  struct HAL_HIF_NETX_SUBBLOCK_Ttag {
    struct RCX_OBJECT_HEADER_T  tObjHdr; /* Header Data */
    RX_HIF_CHANNEL_BLOCK_T      tSubBlockCfg; /* Configuration data for this Subblock */
    HAL_HIF_NETX_CHANNEL_T FAR* ptPrntArea; /* Pointer to parent AREA */
    PFN_HIF_SUBBLOCK_CBK fnHndshke; /* Callback function for handshake */
    UINT uXorMskHandShk; /* Mask for handshaking */
    UINT uXorMskHandShkDirection; /* Mask for direction of handshaking (0 = host -> netx , 1<<x = netx -> host)      sb: added on 02.05.2006*/
    UINT8 FAR* pabPhyMemory; /* Physical memory pointer to that SUBBLOCK */
    UINT uMaxSiz; /* Maximum size of this block */
    
    struct RCX_QUEUE_T FAR* ptEptyQue; /* Handle to Empty Packet Queue */
    struct RCX_QUEUE_T FAR* ptPcktQue; /* Handle to Packet Packet Queue */
    UINT8 FAR*              pabQueElmts; /* Pointer to the Queue Elements themselves */
  };
  
  typedef void FAR (FAR* pfnHifIrqVect_t)(void FAR* pvPrm, UINT uVectorIndex);
  typedef void FAR (FAR* pfnIrq_t)(RX_HANDLE hInt, void FAR* pvPrm);
    
#endif /* __DRV_HIF_H */
