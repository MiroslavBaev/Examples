/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:

    @version $Id: EcsV4_Legacy.h 40065 2013-11-05 14:28:51Z Sven $

   Description:

    EtherCAT Slave V4

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2012-06-19  RW            fixed mantis #0018319:
                               EcsV4_Legacy.h: cleaned up used warmstart revisions
                               (sync with Ecs_Public.h of V2.5.28.0:
                               removed all related to warmstart request rev.3)
     2012-05-23  RW            moved ECAT_DPM_SYNC_SOURCE_ defines to EcsV4_Public.h
     2012-05-16  RW            adjusted define for header to __ECSV4_LEGACY_H_
     2011-12-15  RW            Created
**************************************************************************************/

#ifndef __ECSV4_LEGACY_H_
#define __ECSV4_LEGACY_H_

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(ECS_INTERFACE_LEGACY)
#endif

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define MSK_ECAT_DPM_WARMSTART_APP_CONTROLLED                                         1

#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_ENABLE_SECOND_FLAG_SET                       0x00000001
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM2_NO_HOST_UPDATE                           0x00000004
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM3_NO_HOST_UPDATE                           0x00000008
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM4_NO_HOST_UPDATE                           0x00000010
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM5_NO_HOST_UPDATE                           0x00000020
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM6_NO_HOST_UPDATE                           0x00000040
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SM7_NO_HOST_UPDATE                           0x00000080
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM2                           0x00000400
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM3                           0x00000800
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM4                           0x00001000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM5                           0x00002000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM6                           0x00004000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_FREERUN_ON_SM7                           0x00008000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM2                       0x00040000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM3                       0x00080000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM4                       0x00100000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM5                       0x00200000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM6                       0x00400000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_SET_SELF_UPDATE_ON_SM7                       0x00800000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_CLEAR_APPLICATION_OBJECTS                    0x01000000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_DO_NOT_CREATE_DEFAULT_OBJECTS                0x02000000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_ENABLE_SYNC_OUTPUT_CONFIG                    0x04000000
#define MSK_ECAT_DPM_WARMSTART_STACK_CFG_CONFIGURE_BUS_SYNCHRONOUS_MODE               0x08000000

#define MSK_ECAT_DPM_WARMSTART_SII_CFG_COE_DETAILS                                    0x000000FF
#define MSK_ECAT_DPM_WARMSTART_SII_CFG_SET_COE_DETAILS                                0x00800000
#define MSK_ECAT_DPM_WARMSTART_SII_CFG_DO_NOT_UPDATE                                  0x01000000
#define MSK_ECAT_DPM_WARMSTART_SII_CFG_DO_NOT_BUILD_RXPDO_INFO                        0x02000000
#define MSK_ECAT_DPM_WARMSTART_SII_CFG_DO_NOT_BUILD_TXPDO_INFO                        0x04000000
#define MSK_ECAT_DPM_WARMSTART_SII_CFG_ADVERTISE_VOE_MBX_PROTOCOL                     0x08000000

#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC0_OUTPUT_TYPE                             0x01
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC0_POLARITY                                0x02
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC0_OUTPUT_ENABLE                           0x04
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC0_IRQ_ENABLE                              0x08
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC1_OUTPUT_TYPE                             0x10
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC1_POLARITY                                0x20
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC1_OUTPUT_ENABLE                           0x40
#define MSK_ECAT_DPM_WARMSTART_SYNC_PDI_SYNC1_IRQ_ENABLE                              0x80

#define MSK_ECAT_DPM_WARMSTART_OD_CFG_SET_INDICATION_TIMEOUT                          0x00000001
#define MSK_ECAT_DPM_WARMSTART_IDN_CFG_SET_INDICATION_TIMEOUT                         0x00000001

#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_VALID                                 0x80000000
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_SELECT                                0x0000000F
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_SELECT_COE                            0x00000000
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_SELECT_SOE                            0x00000001
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_PROTOCOL_DISABLES                     0x000FFFF0
#define SRT_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_PROTOCOL_DISABLES                     4
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DISABLE_EOE                           0x00000040
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DISABLE_FOE                           0x00000100
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DISABLE_VOE                           0x00080000
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DISABLE_ESM_SAFEOP_CHK                0x00100000
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DO_NOT_ADVERTISE_SDOINFO              0x00200000
#define MSK_ECAT_DPM_WARMSTART_STACK_MODE_FLAGS_DO_NOT_ADVERTISE_COMPLETE_ACCESS      0x00400000


#define MSK_ECAT_DPM_SET_CONFIG_APP_CONTROLLED                                        1

#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_ENABLE_SECOND_FLAG_SET                      0x00000001
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM2_NO_HOST_UPDATE                          0x00000004
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM3_NO_HOST_UPDATE                          0x00000008
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM4_NO_HOST_UPDATE                          0x00000010
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM5_NO_HOST_UPDATE                          0x00000020
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM6_NO_HOST_UPDATE                          0x00000040
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SM7_NO_HOST_UPDATE                          0x00000080
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM2                          0x00000400
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM3                          0x00000800
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM4                          0x00001000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM5                          0x00002000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM6                          0x00004000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_FREERUN_ON_SM7                          0x00008000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM2                      0x00040000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM3                      0x00080000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM4                      0x00100000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM5                      0x00200000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM6                      0x00400000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_SET_SELF_UPDATE_ON_SM7                      0x00800000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_CLEAR_APPLICATION_OBJECTS                   0x01000000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_DO_NOT_CREATE_DEFAULT_OBJECTS               0x02000000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_ENABLE_SYNC_OUTPUT_CONFIG                   0x04000000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_CFG_CONFIGURE_BUS_SYNCHRONOUS_MODE              0x08000000

#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_COE_DETAILS                                   0x000000FF
#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_SET_COE_DETAILS                               0x00800000
#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_DO_NOT_UPDATE                                 0x01000000
#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_DO_NOT_BUILD_RXPDO_INFO                       0x02000000
#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_DO_NOT_BUILD_TXPDO_INFO                       0x04000000
#define MSK_ECAT_DPM_SET_CONFIG_SII_CFG_ADVERTISE_VOE_MBX_PROTOCOL                    0x08000000

#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC0_OUTPUT_TYPE                            0x01
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC0_POLARITY                               0x02
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC0_OUTPUT_ENABLE                          0x04
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC0_IRQ_ENABLE                             0x08
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC1_OUTPUT_TYPE                            0x10
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC1_POLARITY                               0x20
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC1_OUTPUT_ENABLE                          0x40
#define MSK_ECAT_DPM_SET_CONFIG_SYNC_PDI_SYNC1_IRQ_ENABLE                             0x80

#define MSK_ECAT_DPM_SET_CONFIG_OD_CFG_SET_INDICATION_TIMEOUT                         0x00000001
#define MSK_ECAT_DPM_SET_CONFIG_IDN_CFG_SET_INDICATION_TIMEOUT                        0x00000001

#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_VALID                                0x80000000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_SELECT                               0x0000000F
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_SELECT_COE                           0x00000000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_SELECT_SOE                           0x00000001
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_PROTOCOL_DISABLES                    0x000FFFF0
#define SRT_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_PROTOCOL_DISABLES                    4
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_DISABLE_EOE                          0x00000040
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_DISABLE_FOE                          0x00000100
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_DISABLE_VOE                          0x00080000
#define MSK_ECAT_DPM_SET_CONFIG_STACK_MODE_FLAGS_USE_NEW_SYNC_SOURCE_VALUES           0x40000000

/* ----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_DPM_WARMSTART_REQ                                      0x00002CC4
#define ECAT_DPM_WARMSTART_CNF                                      0x00002CC5
#define ECAT_DPM_SET_CONFIG_REQ                                     0x00002CCA
#define ECAT_DPM_SET_CONFIG_CNF                                     0x00002CCB
#define ECAT_DPM_SET_CONFIGURATION_REQ                              0x00002CCA
#define ECAT_DPM_SET_CONFIGURATION_CNF                              0x00002CCB

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/******************************************************************************
 * ECAT_DPM_WARMSTART_REQ/
 * ECAT_DPM_WARMSTART_CNF
 */

/* request packet (Rev 0) */
typedef __TLR_PACKED_PRE struct ECAT_DPM_WARMSTART_OLD_REQ_DATA_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
} __TLR_PACKED_POST ECAT_DPM_WARMSTART_OLD_REQ_DATA_T;

typedef struct ECAT_DPM_WARMSTART_OLD_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_WARMSTART_OLD_REQ_DATA_T         tData;
} ECAT_DPM_WARMSTART_OLD_REQ_T;

/* request packet (Rev 1) */
typedef __TLR_PACKED_PRE struct ECAT_DPM_WARMSTART_R1_REQ_DATA_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
  TLR_UINT32 ulStackConfigurationFlags;
  TLR_UINT32 ulSIIConfigurationFlags;
  TLR_UINT8  bSyncPdiConfig;
  TLR_UINT16 usSyncImpulseLength;
  TLR_UINT32 ulDeviceType;
} __TLR_PACKED_POST ECAT_DPM_WARMSTART_R1_REQ_DATA_T;

/* request packet (Rev 1b) */
typedef __TLR_PACKED_PRE struct ECAT_DPM_WARMSTART_R1B_REQ_DATA_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
  TLR_UINT32 ulStackConfigurationFlags;
  TLR_UINT32 ulSIIConfigurationFlags;
  TLR_UINT8  bSyncPdiConfig;
  TLR_UINT16 usSyncImpulseLength;
  TLR_UINT32 ulDeviceType;
  TLR_UINT16 usStationAlias;
  TLR_UINT32 ulSm2ErrorThreshold;
  TLR_UINT32 ulSm3ErrorThreshold;
  TLR_UINT32 ulSyncFlagErrorThreshold;
} __TLR_PACKED_POST ECAT_DPM_WARMSTART_R1B_REQ_DATA_T;

/* request packet (Rev 2) */
typedef __TLR_PACKED_PRE struct ECAT_DPM_WARMSTART_R2_REQ_DATA_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
  TLR_UINT32 ulStackConfigurationFlags;
  TLR_UINT32 ulSIIConfigurationFlags;
  TLR_UINT8  bSyncPdiConfig;
  TLR_UINT16 usSyncImpulseLength;
  TLR_UINT32 ulDeviceType;
  TLR_UINT16 usStationAlias;
  TLR_UINT32 ulSm2ErrorThreshold;
  TLR_UINT32 ulSm3ErrorThreshold;
  TLR_UINT32 ulSyncFlagErrorThreshold;
  TLR_UINT32 ulOdConfigurationFlags;
  TLR_UINT32 ulSdoConfigurationFlags;
  TLR_UINT32 ulApConfigurationFlags;
  TLR_UINT32 ulIdnConfigurationFlags;
  TLR_UINT32 ulSoEConfigurationFlags;
  TLR_UINT32 ulOdIndicationTimeout;
  TLR_UINT32 ulIdnIndicationTimeout;
} __TLR_PACKED_POST ECAT_DPM_WARMSTART_R2_REQ_DATA_T;

/* request packet (Rev 4) */
typedef __TLR_PACKED_PRE struct ECAT_DPM_WARMSTART_R4_REQ_DATA_Ttag
{
  TLR_UINT32 ulSystemFlags;
  TLR_UINT32 ulWatchdogTime;
  TLR_UINT32 ulVendorId;
  TLR_UINT32 ulProductCode;
  TLR_UINT32 ulRevisionNumber;
  TLR_UINT32 ulSerialNumber;
  TLR_UINT32 ulProcessDataOutputSize;
  TLR_UINT32 ulProcessDataInputSize;
  TLR_UINT32 ulStackConfigurationFlags;
  TLR_UINT32 ulSIIConfigurationFlags;
  TLR_UINT8  bSyncPdiConfig;
  TLR_UINT16 usSyncImpulseLength;
  TLR_UINT32 ulDeviceType;
  TLR_UINT16 usStationAlias;
  TLR_UINT32 ulSm2ErrorThreshold;
  TLR_UINT32 ulSm3ErrorThreshold;
  TLR_UINT32 ulSyncFlagErrorThreshold;
  TLR_UINT32 ulOdConfigurationFlags;
  TLR_UINT32 ulSdoConfigurationFlags;
  TLR_UINT32 ulApConfigurationFlags;
  TLR_UINT32 ulIdnConfigurationFlags;
  TLR_UINT32 ulSoEConfigurationFlags;
  TLR_UINT32 ulOdIndicationTimeout;
  TLR_UINT32 ulIdnIndicationTimeout;
  TLR_UINT32 ulStackModeFlags;
  TLR_UINT8  bRxPDSource;
  TLR_UINT8  bTxPDSource;
  TLR_UINT8  bSyncSource;
  TLR_UINT8  bRxPDHskMode;
  TLR_UINT8  bTxPDHskMode;
  TLR_UINT8  bSyncHskMode;
} __TLR_PACKED_POST ECAT_DPM_WARMSTART_R4_REQ_DATA_T;

typedef struct ECAT_DPM_WARMSTART_R1_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_WARMSTART_R1_REQ_DATA_T          tData;
} ECAT_DPM_WARMSTART_R1_REQ_T;

typedef struct ECAT_DPM_WARMSTART_R1B_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_WARMSTART_R1B_REQ_DATA_T         tData;
} ECAT_DPM_WARMSTART_R1B_REQ_T;

typedef struct ECAT_DPM_WARMSTART_R2_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_WARMSTART_R2_REQ_DATA_T          tData;
} ECAT_DPM_WARMSTART_R2_REQ_T;

typedef struct ECAT_DPM_WARMSTART_R4_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  ECAT_DPM_WARMSTART_R4_REQ_DATA_T          tData;
} ECAT_DPM_WARMSTART_R4_REQ_T;

/* confirmation packet */
typedef struct ECAT_DPM_WARMSTART_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_DPM_WARMSTART_CNF_T;

#if defined(__ECS_USE_R1_WARMSTART_REQUEST__)
/* Rev1 warmstart packet */
typedef ECAT_DPM_WARMSTART_R1_REQ_T         ECAT_DPM_WARMSTART_REQ_T;
#elif defined(__ECS_USE_R0_WARMSTART_REQUEST__)
/* this is the old warmstart packet for applications wanting to use the old format */
typedef ECAT_DPM_WARMSTART_OLD_REQ_T        ECAT_DPM_WARMSTART_REQ_T;
#elif defined(__ECS_USE_R2_WARMSTART_REQUEST__)
/* rev2 warmstart packet to be enabled by default */
typedef ECAT_DPM_WARMSTART_R2_REQ_T         ECAT_DPM_WARMSTART_REQ_T;
#else
typedef ECAT_DPM_WARMSTART_R4_REQ_T         ECAT_DPM_WARMSTART_REQ_T;
#endif

/******************************************************************************
 * ECS_DPM_SET_CONFIG_REQ/
 * ECS_DPM_SET_CONFIG_CNF
 */

typedef ECAT_DPM_WARMSTART_R4_REQ_DATA_T ECAT_DPM_SET_CONFIG_REQ_DATA_T;
typedef ECAT_DPM_WARMSTART_R4_REQ_DATA_T ECAT_DPM_SET_CONFIGURATION_REQ_DATA_T;

/* request packet */
typedef struct ECAT_DPM_SET_CONFIG_REQ_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
  ECAT_DPM_SET_CONFIG_REQ_DATA_T              tData;
} ECAT_DPM_SET_CONFIG_REQ_T;

typedef ECAT_DPM_SET_CONFIG_REQ_T ECAT_DPM_SET_CONFIGURATION_REQ_T;

/* confirmation packet */
typedef struct ECAT_DPM_SET_CONFIG_CNF_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
  /* no data part */
} ECAT_DPM_SET_CONFIG_CNF_T;

typedef ECAT_DPM_SET_CONFIG_CNF_T ECAT_DPM_SET_CONFIGURATION_CNF_T;

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(ECS_INTERFACE_LEGACY)
#endif

#endif /* __ECSV4_LEGACY_H_ */
