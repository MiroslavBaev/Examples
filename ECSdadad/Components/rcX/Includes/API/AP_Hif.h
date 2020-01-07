/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Hif.h 1128 2012-11-27 13:44:29Z MichaelT $

  Description:
    Headerfile of Host Interface Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_HIF_H
  #define __AP_HIF_H

  /*
  ******************************************************************************
  *   Size of one XC Control Block a Task has to allocate memory for
  ******************************************************************************
  */
  #define DRV_HIF_SIZE (180)

  typedef struct DRV_HIF_PIO_DATA_Ttag {
    UINT32 ulData0;
    UINT32 ulData1;
  } DRV_HIF_PIO_DATA_T;

  /** \brief LED states of the System Channel LEDs
   * These definitions define LED status of the LEDs represented in the System Channel.
   * The LEDs are controlled by the function \ref Drv_HifSetAppLedState and \ref Drv_HifSetComLedState.
   */
  enum DRV_HIF_LED_STATEtag
  {
    DRV_HIF_LED_STATE_OFF,
    DRV_HIF_LED_STATE_SOLID_ON,
    DRV_HIF_LED_STATE_FLICKER,
    DRV_HIF_LED_STATE_SINGLE_FLICKER,
    DRV_HIF_LED_STATE_FLASHING_CYCLIC,
    DRV_HIF_LED_STATE_FLASHING_CYCLIC_FAST,
    DRV_HIF_LED_STATE_SINGLE_FLASH,
    DRV_HIF_LED_STATE_DOUBLE_FLASH,
    DRV_HIF_LED_STATE_QUADRUPLE_FLASH,
    DRV_HIF_LED_STATE_FLASHING_NON_CYCLIC,
    DRV_HIF_LED_STATE_TRIPLE_FLASH,
  };
  typedef int DRV_HIF_LED_STATE;

  enum DRV_HIF_LED_TYPEtag
  {
    DRV_HIF_LED_TYPE_NOT_USED,
    DRV_HIF_LED_TYPE_SINGLE,
    DRV_HIF_LED_TYPE_DUO
  };
  typedef int DRV_HIF_LED_TYPE;

  enum DRV_HIF_LED_COLORtag
  {
    DRV_HIF_LED_COLOR_NOT_USED,
    DRV_HIF_LED_COLOR_RED,
    DRV_HIF_LED_COLOR_YELLOW,
    DRV_HIF_LED_COLOR_GREEN,
    DRV_HIF_LED_COLOR_BLUE,
    DRV_HIF_LED_COLOR_RED_GREEN,
    DRV_HIF_LED_COLOR_RED_YELLOW,
    DRV_HIF_LED_COLOR_GREEN_YELLOW
  };
  typedef int DRV_HIF_LED_COLOR;

  typedef struct DRV_HIF_CHANNEL_INFO_DATA_Ttag
  {
    UINT16 usStructLength;                                      /* fill in with sizeof(DRV_HIF_SYSTEM_INFO_DATA_T) */
    UINT16 usCommunicationClass;                                /* Communication Class (Master, Slave...) */
    UINT16 usProtocolClass;                                     /* Protocol Class (PROFIBUS, PROFINET....) */
    UINT16 usProtocolConformanceClass;                          /* Protocol Conformance Class (DPV1, DPV2...) */
  } DRV_HIF_CHANNEL_INFO_DATA_T;

  typedef void(CALLBACK* PFN_HIF_CHANNEL_CBK)(RX_HANDLE hArea);
  typedef void(CALLBACK* PFN_HIF_SUBBLOCK_CBK)(RX_HANDLE hSubblock, void FAR* pvPrm);
  typedef void(CALLBACK* PFN_HIF_HSKBIT_CBK)(void* pvParam, UINT uValue);
  typedef void(CALLBACK* PFN_HIF_APPCOS_BIT_CBK)(BOOLEAN fValue, void* pvParam);
  typedef void(CALLBACK* PFN_HIF_APPCOS_CBK)(RX_HANDLE hChannel, UINT32 ulAppCOS, void* pvParam);
  typedef void(CALLBACK* PFN_HIF_DMA_CBK)(void* pvPrm, UINT uVectIdx);

  /*! \brief Initialize the Drv_Hif
   * This function initializes the Drv_Hif. It will take up to one \ref RX_HIF_SET_T structure as
   * configuration parameter.
   *
   * \param pvCfg pointer to \ref RX_HIF_SET_T
   * \param uNum number of \ref RX_HIF_SET_T elements (allowed values 0 to 1)
   *
   * \return
   * <UL>
   * <LI><B>RX_OK</B>The driver initialization completed successfully</LI>
   * </UL>
   */
  RX_FATAL DrvHifInit                           (const void*                      pvCfg,
                                                 UINT                             uNum);

  /* Internally used function for RX_SYSTEM Task */
  RX_RESULT DrvHifGetHandshakeValues            (RX_HANDLE                        hChannel,
                                                 UINT32 FAR*                      pulHostToNetxFlags,
                                                 UINT32 FAR*                      pulNetxToHostFlags);
  RX_RESULT DrvHifGetCommCOSFlags               (RX_HANDLE hChannel, 
                                                 UINT32* pulCommCOS);

  /*! \brief Creates explicitly a HIF instance
   * This function creates a HIF instance. Only one instance is allowed to be created.
   * The \ref RX_HIF_SET_T parameter determines the layout and configuration of the HIF instance.
   *
   * \param hHif pointer to pre-allocated handle storage space with the size \ref DRV_HIF_SIZE in bytes
   * \param ptCfg pointer to \ref RX_HIF_SET_T defining the configuration of the HIF instance.
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifCreateHif                    (RX_HANDLE                        hHif,
                                                 const RX_HIF_SET_T*              ptCfg);

  /*! \brief Identifies a HIF instance
   * This function lookups a previously created HIF instance with the identifier pszIdn and the instance uInst.
   * On success, the function returns the handle in phHif.
   *
   * \param pszIdn name of the HIF instance to be looked up
   * \param uInst instance of the HIF instance to be looked up
   * \param phHif pointer to variable receiving the handle to the HIF instance
   *
   * \return
   * <UL>
   * <LI>  RX_OK The function completed successfully. The handle in the return variable is valid.  </LI>
   * <LI>  DRV_HIF_NAME The identifier and the instance specify a HIF instance that does not exist.       </LI>
   * </UL>
   */
  RX_RESULT Drv_HifIdentifyHif                  (const STRING*                    pszIdn,
                                                 UINT                             uInst,
                                                 RX_HANDLE*                       phHif);

  /*! \brief Initializes a HIF instance
   * This function initializes a HIF instance.
   *
   * \param hHif handle to the HIF instance
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifInitializeHif                (RX_HANDLE                        hHif);

  RX_RESULT Drv_HifGetInputs                    (RX_HANDLE                        hHif,
                                                 DRV_HIF_PIO_DATA_T*              ptData);

  RX_RESULT Drv_HifSetOutputs                   (RX_HANDLE                        hHif,
                                                 const DRV_HIF_PIO_DATA_T*        ptData);

  RX_RESULT Drv_HifGetOutputs                   (RX_HANDLE                        hHif,
                                                 DRV_HIF_PIO_DATA_T*              ptData);

  RX_RESULT Drv_HifCommitChannelMapping         (RX_HANDLE                        hHif);


  /*! \brief Creates a channel in the DPM
   * This function creates a channel in the DPM. It will be initialized with the configuration given
   * by the structure \ref RX_HIF_AREA_T.
   *
   * \param ptAreaCfg configuration parameters for the channel to be created.
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifCreateChannel                (const RX_HIF_CHANNEL_T*          ptChannelCfg);

  /*! \brief Identifies a channel in the DPM
   * This function identifies a channel in the DPM.
   *
   * \param pszIdn identifier of the channel
   * \param uInst area number of the channel if pszIdn == NULL
   * \param phArea receives handle to the channel
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifIdentifyChannel              (const STRING*                    pszIdn,
                                                 UINT                             uInst,
                                                 RX_HANDLE*                       phChannel);


  /*! \brief Update channel information block data
   * This function updates the channel information block data i.e. CommunicationClass, ProtocolClass and ProtocolConformanceClass
   *
   * \param hChannel handle to channel
   * \param ptSystemInfoData pointer to channel information block data
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetChannelInfoData           (RX_HANDLE                        hChannel,
                                                 DRV_HIF_CHANNEL_INFO_DATA_T*     ptChannelInfoData);
                                                                                                    
  /*! \brief Activates a callback on a channel
   * This function registers a callback in a given channel.
   * Caution! This function cannot be used together with \ref Drv_HifEnableSubblock or
   * \ref Drv_HifEnableBitFunction.
   *
   * \param hChannel handle to the channel
   * \param pfnIrq pointer to the callback
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableChannel                (RX_HANDLE                        hChannel,
                                                 PFN_HIF_CHANNEL_CBK              pfnIrq);

  /*! \brief Read out a specific handshake bit of the host side
   * This function reads out a handshake bit of the host side handshake cell.
   * The maximum bit number to be put in uHandshkBit depends on the actual configuration.
   *
   * \param hChannel handle to the channel
   * \param uHandshkBit number of the bit to read out
   * \param pfValue receives the value of the bit
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifGetHandshkBit                (RX_HANDLE                        hChannel,
                                                 UINT                             uHandshkBit,
                                                 BOOLEAN*                         pfValue);    /* reads the current value of the handshake bit */

  /*! \brief Read out a specific handshake bit of the host side
   * This function reads out a handshake bit of the host side handshake cell.
   * The maximum bit number to be put in uHandshkBit depends on the actual configuration.
   *
   * \param hChannel handle to the channel
   * \param uHandshkBit number of the bit to read out
   * \param pfValue receives the value of the bit
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifChangeHandshkBit             (RX_HANDLE                        hChannel,
                                                 UINT                             uHandshkBit,
                                                 BOOLEAN                          fEnable);       /* Callback function when any change in the system has been detected */

  /*! \brief Read out a specific handshake bit of the host side
   * This function reads out a handshake bit of the host side handshake cell.
   * The maximum bit number to be put in uHandshkBit depends on the actual configuration.
   *
   * \param hChannel handle to the channel
   * \param uHandshkBit number of the bit to read out
   * \param pfValue receives the value of the bit
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifChangeHostHandshkBit         (RX_HANDLE                        hChannel,
                                                 UINT                             uHandshkBit,
                                                 BOOLEAN                          fEnable);       /* Callback function when any change in the system has been detected */

  /*! \brief Creates a block in a given channel
   * This function creates a block in a given channel. The configuration of the block
   * is supplied via ptSubBlkCfg.
   * The maximum number of supported blocks is 16.
   *
   * \param hChannel handle to the channel
   * \param ptBlkCfg configuration of the block to be created
   *
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifCreateBlock                  (RX_HANDLE                        hChannel,
                                                 const RX_HIF_CHANNEL_BLOCK_T*    ptBlkCfg);


  RX_RESULT Drv_HifChangeHndshkMode             (RX_HANDLE                        hBlock,
                                                 RX_HIF_BLOCK_MODE                eMod);

  RX_RESULT Drv_HifIdentifyBlock                (const STRING*                    pszIdn,
                                                 UINT                             uInst,
                                                 RX_HANDLE                        hChannel,
                                                 RX_HANDLE*                       phBlock);

  RX_RESULT Drv_HifAccessBlockDone              (RX_HANDLE                        hBlock);

  RX_RESULT Drv_HifAccessBlockLocked            (RX_HANDLE                        hBlock,
                                                 BOOLEAN*                         pfLocked);

  RX_RESULT Drv_HifEnableBlock                  (RX_HANDLE                        hBlock,
                                                 PFN_HIF_SUBBLOCK_CBK             pfnCallback,
                                                 void*                            pvParam);

  RX_RESULT Drv_HifDisableBlock                 (RX_HANDLE                        hBlock);

  RX_RESULT Drv_HifReadFromBlock                (RX_HANDLE                        hBlock,
                                                 void*                            pvDest,
                                                 UINT                             uSiz);

  RX_RESULT Drv_HifWriteToBlock                 (RX_HANDLE                        hBlock,
                                                 const void*                      pvSrc,
                                                 UINT                             uSiz);

  RX_RESULT Drv_HifWaitForBlockConfirmed        (RX_HANDLE                        hBlock,
                                                 UINT                             uTimOpt);

  RX_RESULT Drv_HifGetBlockInformation          (RX_HANDLE                        hBlock,
                                                 void**                           ppvAdr,
                                                 RX_HIF_CHANNEL_BLOCK_T*          ptBlkCfg);

  RX_RESULT Drv_HifGetBlockBasePointer          (RX_HANDLE                        hBlock,
                                                 UINT8**                          ppabBase);

  RX_RESULT Drv_HifOffsetReadFromBlock          (RX_HANDLE                        hBlock,
                                                 void*                            pvDest,
                                                 UINT                             uSiz,
                                                 UINT                             uOffset);

  RX_RESULT Drv_HifOffsetWriteToBlock           (RX_HANDLE                        hBlock,
                                                 const void*                      pvSrc,
                                                 UINT                             uSize,
                                                 UINT                             uOffset);

  RX_RESULT Drv_HifEnableBitFunction            (RX_HANDLE                        hChannel,
                                                 UINT                             uHandShakeBit,
                                                 PFN_HIF_HSKBIT_CBK               pfnCallback,
                                                 void*                            pvParam,
                                                 RX_HIF_BITFUNCTION_TYPE          eType);

  RX_RESULT Drv_HifDisableBitFunction           (RX_HANDLE                        hChannel,
                                                 UINT                             uHandShakeBit);

  RX_RESULT Drv_HifSetComLedState               (UINT                             uChannelId,
                                                 UINT                             uLedNo,
                                                 DRV_HIF_LED_TYPE                 eLedType,
                                                 DRV_HIF_LED_COLOR                eLedColor,
                                                 DRV_HIF_LED_STATE                eLedState);

  RX_RESULT Drv_HifSetAppLedState               (UINT                             uChannelId,
                                                 UINT                             uLedNo,
                                                 DRV_HIF_LED_TYPE                 eLedType,
                                                 DRV_HIF_LED_COLOR                eLedColor,
                                                 DRV_HIF_LED_STATE                eLedState);

  RX_RESULT Drv_HifSetSystemStatusLedState      (DRV_HIF_LED_TYPE                 eLedType,
                                                 DRV_HIF_LED_COLOR                eLedColor,
                                                 DRV_HIF_LED_STATE                eLedState);

  RX_RESULT Drv_HifChangeCOS                    (RX_HANDLE                        hChannel,
                                                 UINT32                           ulSetCOS,
                                                 UINT32                           ulClrCOS);

  RX_RESULT Drv_HifEnableAppCOS                 (RX_HANDLE                        hChannel,
                                                 PFN_HIF_APPCOS_CBK               pfnCallback,
                                                 void*                            pvParam);

  RX_RESULT Drv_HifDisableAppCOS                (RX_HANDLE                        hChannel);

  RX_RESULT Drv_HifGetAppCOS                    (RX_HANDLE                        hChannel,
                                                 UINT32*                          pulAppCOS);

  /*! \brief Enable the callback for ApplicationCOS.INITIALIZATION
   * This function activates a callback on a given channel for ApplicationCOS.INITIALIZATION bit.
   * The function will call the callback with the current state on a successful initialization
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableInitCallback           (RX_HANDLE                        hChannel,
                                                 PFN_HIF_APPCOS_BIT_CBK           pfnCallback,
                                                 void*                            pvParam);

  /*! \brief Disable the callback for ApplicationCOS.INITIALIZATION
   * This function deactivates a callback on a given channel for ApplicationCOS.INITIALIZATION bit.
   * \param hChannel handle to the channel
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifDisableInitCallback          (RX_HANDLE                        hChannel);

  /*! \brief Enable the callback for ApplicationCOS.LOCK_CONFIGURATION
   * This function activates a callback on a given channel for ApplicationCOS.LOCK_CONFIGURATION bit.
   * The function will call the callback with the current state on a successful initialization
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableLockConfigCallback     (RX_HANDLE                        hChannel,
                                                 PFN_HIF_APPCOS_BIT_CBK           pfnCallback,
                                                 void*                            pvParam);

  /*! \brief Disable the callback for ApplicationCOS.LOCK_CONFIGURATION
   * This function deactivates a callback on a given channel for ApplicationCOS.LOCK_CONFIGURATION bit.
   * \param hChannel handle to the channel
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifDisableLockConfigCallback    (RX_HANDLE                        hChannel);

  /*! \brief Enable the callback for ApplicationCOS.APPLICATION_READY
   * This function activates a callback on a given channel for ApplicationCOS.APPLICATION_READY bit.
   * The function will call the callback with the current state on a successful initialization
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableAppReadyCallback       (RX_HANDLE                        hChannel,
                                                 PFN_HIF_APPCOS_BIT_CBK           pfnCallback,
                                                 void*                            pvParam);

  /*! \brief Disable the callback for ApplicationCOS.APPLICATION_READY
   * This function deactivates a callback on a given channel for ApplicationCOS.APPLICATION_READY bit.
   * \param hChannel handle to the channel
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifDisableAppReadyCallback      (RX_HANDLE                        hChannel);

  /*! \brief Enable the callback for ApplicationCOS.BUS_ON
   * This function activates a callback on a given channel for ApplicationCOS.BUS_ON bit.
   * The function will call the callback with the current state on a successful initialization
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableBusOnCallback          (RX_HANDLE                        hChannel,
                                                 PFN_HIF_APPCOS_BIT_CBK           pfnCallback,
                                                 void*                            pvParam);

  /*! \brief Disable the callback for ApplicationCOS.BUS_ON
   * This function deactivates a callback on a given channel for ApplicationCOS.BUS_ON bit.
   * \param hChannel handle to the channel
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifDisableBusOnCallback         (RX_HANDLE                        hChannel);

  /*! \brief Enable the callback for ApplicationCOS.DMA
   * This function activates a callback on a given channel for ApplicationCOS.DMA bit.
   * The function will call the callback with the current state on a successful initialization
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableDMACallback          (RX_HANDLE                        hChannel,
                                               PFN_HIF_APPCOS_BIT_CBK           pfnCallback,
                                               void*                            pvParam);

  /*! \brief Disable the callback for ApplicationCOS.DMA
   * This function deactivates a callback on a given channel for ApplicationCOS.DMA bit.
   * \param hChannel handle to the channel
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifDisableDMACallback         (RX_HANDLE                        hChannel);


  /*! \brief Set the value of the CommunicationCOS.READY
   * This function sets the value of the CommunicationCOS.READY bit.
   * \param value New value for CommunicationCOS.READY
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosReady               (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.RUN
   * This function sets the value of the CommunicationCOS.RUN bit.
   * \param value New value for CommunicationCOS.RUN
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosRun                 (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.BUS_ON
   * This function sets the value of the CommunicationCOS.BUS_ON bit.
   * \param value New value for CommunicationCOS.BUS_ON
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosBusOn               (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.CONFIGURATION_LOCKED
   * This function sets the value of the CommunicationCOS.CONFIGURATION_LOCKED bit.
   * \param value New value for CommunicationCOS.CONFIGURATION_LOCKED
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosConfigLocked        (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.CONFIGURATION_NEW
   * This function sets the value of the CommunicationCOS.CONFIGURATION_NEW bit.
   * \param value New value for CommunicationCOS.CONFIGURATION_NEW
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosConfigNew           (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.RESTART_REQUIRED
   * This function sets the value of the CommunicationCOS.RESTART_REQUIRED bit.
   * \param value New value for CommunicationCOS.RESTART_REQUIRED
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosRestartRequired     (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

  /*! \brief Set the value of the CommunicationCOS.DMA
   * This function sets the value of the CommunicationCOS.DMA bit.
   * \param value New value for CommunicationCOS.DMA
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetComCosDMA                 (RX_HANDLE                        hChannel,
                                                 BOOLEAN                          fValue);

      /*! \brief Setup a DMA transfer
   * This function setup a DMA
   * \param hChannel handle to the channel
   * \param ulNetXAddress pointer to data
   * \param ulDir Direction of DMA transfer
   * \param ulLength length of data to transfer
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifSetupDMA(RX_HANDLE hChannel, UINT32 ulNetXAddress, UINT32 ulDir, UINT32 ulLength);
  
  /*! \brief Enable the DMA mechansm
   * This function configures and enables the DMA register. It activates a callback when the DMA is executed
   * \param hChannel handle to the channel
   * \param pfnCallback pointer to callback
   * \param pvPrm user data pointer for the callback
   * \return RX_OK on success
   */
  RX_RESULT Drv_HifEnableDMA           (RX_HANDLE hChannel,
                                        PFN_HIF_DMA_CBK pfnCallback,
                                        void FAR *pvPrm );


  RX_RESULT Drv_HifClearCOSRdy        (RX_HANDLE hHif);

  /* old defines / source code compatibility */
#ifndef _DO_NOT_USE_OLD_DRV_HIF_DEFINES_
  #define Drv_HifCreateArea                         Drv_HifCreateChannel
  #define Drv_HifIdentifyArea                       Drv_HifIdentifyChannel
  #define Drv_HifEnableArea                         Drv_HifEnableChannel
  #define Drv_HifCreateSubblock                     Drv_HifCreateBlock
  #define Drv_HifIdentifySubblock                   Drv_HifIdentifyBlock
  #define Drv_HifAccessSubblockDone                 Drv_HifAccessBlockDone
  #define Drv_HifAccessSubblockLocked               Drv_HifAccessBlockLocked
  #define Drv_HifEnableSubblock                     Drv_HifEnableBlock
  #define Drv_HifDisableSubblock                    Drv_HifDisableBlock
  #define Drv_HifReadFromSubblock                   Drv_HifReadFromBlock
  #define Drv_HifWriteToSubblock                    Drv_HifWriteToBlock
  #define Drv_HifWaitForSubblockConfirmed           Drv_HifWaitForBlockConfirmed
  #define Drv_HifGetSubblockInformation             Drv_HifGetBlockInformation
  #define Drv_HifGetSubblockBasePointer             Drv_HifGetBlockBasePointer
  #define Drv_HifOffsetReadFromSubblock             Drv_HifOffsetReadFromBlock
  #define Drv_HifOffsetWriteToSubblock              Drv_HifOffsetWriteToBlock

  #define RX_HIF_AREA_LAYOUT                        RX_HIF_CHANNEL_LAYOUT
  #define RX_HIF_AREA_LAYOUT_UNDEFINED              RX_HIF_CHANNEL_LAYOUT_UNDEFINED
  #define RX_HIF_AREA_LAYOUT_NOT_AVAILABLE          RX_HIF_CHANNEL_LAYOUT_NOT_AVAILABLE
  #define RX_HIF_AREA_LAYOUT_RESERVED               RX_HIF_CHANNEL_LAYOUT_RESERVED
  #define RX_HIF_AREA_LAYOUT_SYSTEM                 RX_HIF_CHANNEL_LAYOUT_SYSTEM
  #define RX_HIF_AREA_LAYOUT_HANDSHAKE              RX_HIF_CHANNEL_LAYOUT_HANDSHAKE
  #define RX_HIF_AREA_LAYOUT_COM_CHANNEL            RX_HIF_CHANNEL_LAYOUT_COM_CHANNEL
  #define RX_HIF_AREA_LAYOUT_APPLICATION            RX_HIF_CHANNEL_LAYOUT_APPLICATION
  #define RX_HIF_AREA_LAYOUT_MAX                    RX_HIF_CHANNEL_LAYOUT_MAX
  #define RX_HIF_AREA_LAYOUT_USER_START             RX_HIF_CHANNEL_LAYOUT_USER_START

  #define RX_HIF_AREA_HDSHK_MODE                    RX_HIF_CHANNEL_HDSHK_MODE
  #define RX_HIF_AREA_HDSHK_MODE_NONE               RX_HIF_CHANNEL_HDSHK_MODE_NONE
  #define RX_HIF_AREA_HDSHK_MODE_8BIT               RX_HIF_CHANNEL_HDSHK_MODE_8BIT
  #define RX_HIF_AREA_HDSHK_MODE_16BIT              RX_HIF_CHANNEL_HDSHK_MODE_16BIT

  #define RX_HIF_SUBBLOCK_TYPE                      RX_HIF_BLOCK_TYPE
  #define RX_HIF_SUBBLOCK_TYPE_STATUS               RX_HIF_BLOCK_TYPE_STATUS
  #define RX_HIF_SUBBLOCK_TYPE_MAILBOX              RX_HIF_BLOCK_TYPE_MAILBOX
  #define RX_HIF_SUBBLOCK_TYPE_IO                   RX_HIF_BLOCK_TYPE_IO
  #define RX_HIF_SUBBLOCK_TYPE_PARAMETER            RX_HIF_BLOCK_TYPE_PARAMETER
  #define RX_HIF_SUBBLOCK_TYPE_PORT_STATE           RX_HIF_BLOCK_TYPE_PORT_STATE
  #define RX_HIF_SUBBLOCK_TYPE_IO_HI_PRIO           RX_HIF_BLOCK_TYPE_IO_HI_PRIO
  #define RX_HIF_SUBBLOCK_TYPE_USER                 RX_HIF_BLOCK_TYPE_USER

  #define RX_HIF_SUBBLOCK_DIRECTION                 RX_HIF_BLOCK_DIRECTION
  #define RX_HIF_SUBBLOCK_DIRECTION_FROMHOST        RX_HIF_BLOCK_DIRECTION_FROMHOST
  #define RX_HIF_SUBBLOCK_DIRECTION_TOHOST          RX_HIF_BLOCK_DIRECTION_TOHOST
  #define RX_HIF_SUBBLOCK_DIRECTION_FROMTOHOST      RX_HIF_BLOCK_DIRECTION_FROMTOHOST

  #define RX_HIF_SUBBLOCK_MODE                      RX_HIF_BLOCK_MODE
  #define RX_HIF_SUBBLOCK_MODE_UNDEFINED            RX_HIF_BLOCK_MODE_UNDEFINED
  #define RX_HIF_SUBBLOCK_MODE_DEVICE_SYNCHRONOUS   RX_HIF_BLOCK_MODE_DEVICE_SYNCHRONOUS
  #define RX_HIF_SUBBLOCK_MODE_DEVICE_CONTROL       RX_HIF_BLOCK_MODE_DEVICE_CONTROL
  #define RX_HIF_SUBBLOCK_MODE_NO_CONTROL           RX_HIF_BLOCK_MODE_NO_CONTROL
  #define RX_HIF_SUBBLOCK_MODE_HOST_CONTROL         RX_HIF_BLOCK_MODE_HOST_CONTROL
  #define RX_HIF_SUBBLOCK_MODE_HOST_SYNCHRONOUS     RX_HIF_BLOCK_MODE_HOST_SYNCHRONOUS
  #define RX_HIF_SUBBLOCK_MODE_SINGLE_BUFFER        RX_HIF_BLOCK_MODE_SINGLE_BUFFER
  #define RX_HIF_SUBBLOCK_MODE_TRIPLE_BUFFER        RX_HIF_BLOCK_MODE_TRIPLE_BUFFER

  #define RX_HIF_SUBBLOCK_TRANS_DPM                 RX_HIF_BLOCK_TRANS_DPM
  #define RX_HIF_SUBBLOCK_TRANS_DMA                 RX_HIF_BLOCK_TRANS_DMA

  #define RX_HIF_AREA_SUBBLOCK_T                    RX_HIF_CHANNEL_BLOCK_T
  #define RX_HIF_AREA_T                             RX_HIF_CHANNEL_T

  #define DRV_HIF_SUBBLOCK_AUTOMATICALLY_ENABLED    DRV_HIF_BLOCK_AUTOMATICALLY_ENABLED
  #define HAL_HIF_AREA_NUM_OF_AREABLOCKS_EXCEEDED   HAL_HIF_CHANNEL_NUM_OF_CHANNELBLOCKS_EXCEEDED
  #define HAL_HIF_AREA_LAYOUT_UNKNOWN               HAL_HIF_CHANNEL_LAYOUT_UNKNOWN
  #define HAL_HIF_AREA_SIZE_EXCEEDED                HAL_HIF_CHANNEL_SIZE_EXCEEDED
  #define HAL_HIF_AREA_HOST_MAILBOX_FULL            HAL_HIF_CHANNEL_HOST_MAILBOX_FULL
  #define HAL_HIF_AREA_SEGMENT_LIMIT                HAL_HIF_CHANNEL_SEGMENT_LIMIT
  #define HAL_HIF_AREA_SEGMENT_UNUSED               HAL_HIF_CHANNEL_SEGMENT_UNUSED
  #define HAL_HIF_AREA_NAME_INVALID                 HAL_HIF_CHANNEL_NAME_INVALID
  #define HAL_HIF_AREA_ALREADY_INITIALIZED          HAL_HIF_CHANNEL_ALREADY_INITIALIZED
  #define HAL_HIF_SUBBLOCK_UNKNOWN                  HAL_HIF_BLOCK_UNKNOWN
  #define HAL_HIF_SUBBLOCK_CREATION_FAILED          HAL_HIF_BLOCK_CREATION_FAILED
  #define HAL_HIF_SUBBLOCK_OFFSET_INVALID           HAL_HIF_BLOCK_OFFSET_INVALID

  #endif
#endif

#ifdef __cplusplus
}
#endif
