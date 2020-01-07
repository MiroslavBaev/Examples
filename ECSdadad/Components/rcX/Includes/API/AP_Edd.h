/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Edd.h 1601 2013-10-09 06:43:59Z andreasme $

  Description:
    User header file of Ethernet Device Driver (EDD) Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_EDD_H
#define __AP_EDD_H

#define DRV_EDD_SIZE (80)

#include "Structs_Edd.h"

/****************************************************************************************
*  EDD, constants */

/* Functions to be sent via HalEddIoctl */
enum EDD_IOCTL_CMDtag {
  EDD_IOCTL_HAL_COMMAND_START                   = 0xa00,

  /**
   * Was EDD_IOCTL_GET_MAC_ADDRESS_REQ before. */
  EDD_IOCTL_GET_INTERFACE_MAC_ADDRESS_REQ       = 0xa0c,
  /* Requests a MAC address from the HAL interface,
     the pvData pointer is a pointer to a six byte array containing the mac address
  */
  /**
   * Was EDD_IOCTL_SET_MAC_ADDRESS_REQ before. */
  EDD_IOCTL_SET_INTERFACE_MAC_ADDRESS_REQ       = 0xa0e,
  /* Requests to set a MAC address in the HAL interface
     the pvData pointer is a pointer to a six byte array containing the mac address
  */

  EDD_IOCTL_GET_CONNECTION_STATE_REQ            = 0xa10,
  /* Requests the current connection state of the HAL interface
     pvData is a pointer to EDD_CONNECTION_STATE_T
  */

  EDD_IOCTL_ACTIVATE_REQ                        = 0xa12,
  /* Activates the HAL interface */

  EDD_IOCTL_DEACTIVATE_REQ                      = 0xa14,
  /* Deactivates the HAL interface */

  /** Query status of a certain port */
  EDD_IOCTL_GET_PORT_STATUS_REQ                 = 0xa16,
  /** Query information about a certain port */
  EDD_IOCTL_GET_PORT_INFO_REQ                   = 0xa18,
  /** Configure a ports mac address */
  EDD_IOCTL_SET_PORT_MACADDR_REQ                = 0xa1a,
  /** Configure port mautype */
  EDD_IOCTL_SET_PORT_MAUTYPE_REQ                = 0xa1c,
  /** Query configured port mautype */
  EDD_IOCTL_GET_PORT_MAUTYPE_REQ                = 0xa1e,


  EDD_IOCTL_SET_PROMISCUOUS_REQ                 = 0xa20,
  /* Sets promiscuous mode in the HAL interface
     if supported
  */

  EDD_IOCTL_CLR_PROMISCUOUS_REQ                 = 0xa22,
  /* Clears promiscuous mode in the HAL interface
     if supported
  */

  EDD_IOCTL_SET_MULTICAST_SINGLE_REQ            = 0xa24,
  /* Activates a single multicast address for Multicast Receive
     However, it might activate more than one multicast address
     pvData is a pointer to an ethernet address
     resembles to promiscuous mode if not supported by a specific filter
  */

  /**
   * FIXME This call makes absolutely no sense without specifying the
   * hash algorithm to use! */
  EDD_IOCTL_SET_MULTICAST_HASH_REQ              = 0xa26,
  /* Activates a multicast hash value
     pvData points to an UINT32 value
     resembles to promiscuous mode if not supported by a specific filter
  */

  EDD_IOCTL_SET_MULTICAST_ALL_REQ               = 0xa28,
  /* Activates all available multicast addresses
     resembles to promiscuous mode if not supported by a specific filter
  */

  EDD_IOCTL_DISABLE_ERROR_CHECK_REQ             = 0xa2a,
  /* Caution! Enabling this option might change the operation of Edd */
  /* Disables CRC Error Checking on the device
     Optional function
  */

  EDD_IOCTL_ENABLE_ERROR_CHECK_REQ              = 0xa2c,
  /* Caution! Enabling this option might change the operation of Edd */
  /* Re-Enables CRC Error Checking on the device
     Optional function
  */

  EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_REQ   = 0xa2e,
  /* Sets traffic class arrangement (priority control)
   pvData points to an EDD_IOCTL_TRAFFIC_CLASS_ARRANGEMENT_T structure
  */

  EDD_IOCTL_REQUEST_BUFFERS_REQ                 = 0xa30,
  /* not a HAL function call */

  EDD_IOCTL_GET_HAL_BUFFERS_REQ                 = 0xa32,
  /* Requests the number of Frames an ethernet device holds
  pvData is a pointer to an UINT32 which will receive the number of buffers
  */

  EDD_IOCTL_ENABLE_ARP_RESPONDER_REQ            = 0xa34,
  /* not a HAL function call */

  EDD_IOCTL_DISABLE_ARP_RESPONDER_REQ           = 0xa36,
  /* not a HAL function call */

  EDD_IOCTL_ENABLE_ICMP_ECHO_RESPONDER_REQ      = 0xa38,
  /* not a HAL function call */

  EDD_IOCTL_DISABLE_ICMP_ECHO_RESPONDER_REQ     = 0xa3a,
  /* not a HAL function call */

  EDD_IOCTL_SET_RESPONDER_IP_ADDRESS_REQ        = 0xa3c,
  /* not a HAL function call */

  EDD_IOCTL_CLR_MULTICAST_SINGLE_REQ            = 0xa3e,
  /* De-Activates a single multicast address for Multicast Receive
     However, it might activate more than one multicast address
     pvData is a pointer to an ethernet address
  */

  EDD_IOCTL_CLR_MULTICAST_HASH_REQ              = 0xa40,
  /* De-Activates a multicast hash value
     pvData points to an UINT32 value
  */

  EDD_IOCTL_CLR_MULTICAST_ALL_REQ               = 0xa42,
  /* De-Activates all available multicast addresses (if previously activated by EDD_IOCTL_SET_MULTICAST_ALL_REQ) */

  EDD_IOCTL_SET_CONNECTION_TYPE_REQ             = 0xa44,
  /* Sets a specific connection type on the device
    pvData points to EDD_CONNECTION_TYPE_T
    Optional function
  */

  EDD_IOCTL_SET_MDIX_REQ                        = 0xa46,

  EDD_IOCTL_GET_MDIX_REQ                        = 0xa48,

  EDD_IOCTL_GET_RESPONDER_IP_ADDRESS_REQ        = 0xa4a,
  /* not a HAL function call */

  EDD_IOCTL_GET_HAL_REQUIRED_BUFFERS_REQ        = 0xa4c,
  /* not required to implement on HAL */

  EDD_IOCTL_GET_NUM_PORTS_REQ                   = 0xa4e,
  /* requests the number of ports attached to a single device
  pvData points to an UINT32

  if the device has only one single port/link, it shall report
  the number of ports equal to 1.
  */

  EDD_IOCTL_GET_HW_STATS_REQ                    = 0xa50,

  EDD_IOCTL_REFRESH_MAC_FROM_SECPROM_REQ        = 0xa52,

  EDD_IOCTL_GET_HAL_NUM_PRIORITIES_REQ          = 0xa54,

  /** Register application callbacks for use
   * of secondary chassis mac address. This is the
   * fourth mac address in security memory which is
   * reserved for customer applications like
   * raw ethernet via ethernet interface task
   * (this commands availability depends on the used
   * xc code)
   */
  EDD_IOCTL_REGISTER_2NDCHASSIS_REQ             = 0xa56,
  /** Unregister application for use of secondary
   * chassis mac address
   */
  EDD_IOCTL_UNREGISTER_2NDCHASSIS_REQ           = 0xa58,

  EDD_IOCTL_EPLv2_INIT_REQ                      = 0xafc,

  EDD_IOCTL_EPLv2_RELEASE_REQ                   = 0xafe,
};



typedef UINT32 EDD_IOCTL_CMD;

/**
 * @defgroup rcx_drv_edd_compat EDD Compatibility defines
 *
 * For some reason there were double defines for
 * most of the EDD ioctl call numbers. This may cause severe inconsistencys.
 * All the following defines shall preserve backwards compatibility.
 *
 * @{
 */
#define EDD_IOCTL_GET_MAC_ADDRESS_REQ               (EDD_IOCTL_GET_INTERFACE_MAC_ADDRESS_REQ)
#define EDD_IOCTL_SET_MAC_ADDRESS_REQ               (EDD_IOCTL_SET_INTERFACE_MAC_ADDRESS_REQ)

#define DRV_EDD_PACKET_COMMAND_START                (EDD_IOCTL_HAL_COMMAND_START)
#define DRV_EDD_REGISTER_APPLICATION_REQ            (0xa00)
#define DRV_EDD_REGISTER_APPLICATION_CNF            (0xa01)
#define DRV_EDD_UNREGISTER_APPLICATION_REQ          (0xa02)
#define DRV_EDD_UNREGISTER_APPLICATION_CNF          (0xa03)
#define DRV_EDD_SEND_DATA_REQ                       (0xa04)
#define DRV_EDD_SEND_DATA_CNF                       (0xa05)
#define DRV_EDD_SEND_PTR_REQ                        (0xa06)
#define DRV_EDD_SEND_PTR_CNF                        (0xa07)
#define DRV_EDD_GET_FILTER_REQ                      (0xa08)
#define DRV_EDD_GET_FILTER_CNF                      (0xa09)
#define DRV_EDD_SET_FILTER_REQ                      (0xa0a)
#define DRV_EDD_SET_FILTER_CNF                      (0xa0b)
#define DRV_EDD_GET_INTERFACE_MAC_ADDRESS_REQ       (EDD_IOCTL_GET_INTERFACE_MAC_ADDRESS_REQ)
#define DRV_EDD_GET_MAC_ADDRESS_REQ                 (EDD_IOCTL_GET_INTERFACE_MAC_ADDRESS_REQ)
#define DRV_EDD_SET_INTERFACE_MAC_ADDRESS_REQ       (EDD_IOCTL_SET_INTERFACE_MAC_ADDRESS_REQ)
#define DRV_EDD_SET_MAC_ADDRESS_REQ                 (EDD_IOCTL_SET_INTERFACE_MAC_ADDRESS_REQ)
#define DRV_EDD_GET_CONNECTION_STATE_REQ            (EDD_IOCTL_GET_CONNECTION_STATE_REQ)
#define DRV_EDD_GET_CONNECTION_STATE_CNF            (EDD_IOCTL_GET_CONNECTION_STATE_CNF)
#define DRV_EDD_ACTIVATE_REQ                        (EDD_IOCTL_ACTIVATE_REQ)
#define DRV_EDD_ACTIVATE_CNF                        (EDD_IOCTL_ACTIVATE_CNF)
#define DRV_EDD_DEACTIVATE_REQ                      (EDD_IOCTL_DEACTIVATE_REQ)
#define DRV_EDD_DEACTIVATE_CNF                      (EDD_IOCTL_DEACTIVATE_CNF)
#define DRV_EDD_SET_PROMISCUOUS_REQ                 (EDD_IOCTL_SET_PROMISCUOUS_REQ)
#define DRV_EDD_SET_PROMISCUOUS_CNF                 (EDD_IOCTL_SET_PROMISCUOUS_CNF)
#define DRV_EDD_CLR_PROMISCUOUS_REQ                 (EDD_IOCTL_CLR_PROMISCUOUS_REQ)
#define DRV_EDD_CLR_PROMISCUOUS_CNF                 (EDD_IOCTL_CLR_PROMISCUOUS_CNF)
#define DRV_EDD_SET_MULTICAST_SINGLE_REQ            (EDD_IOCTL_SET_MULTICAST_SINGLE_REQ)
#define DRV_EDD_SET_MULTICAST_HASH_REQ              (EDD_IOCTL_SET_MULTICAST_HASH_REQ)
#define DRV_EDD_SET_MULTICAST_ALL_REQ               (EDD_IOCTL_SET_MULTICAST_ALL_REQ)
#define DRV_EDD_DISABLE_ERROR_CHECK_REQ             (EDD_IOCTL_DISABLE_ERROR_CHECK_REQ)
/* Caution! Enabling this option might change the operation of Edd */
#define DRV_EDD_ENABLE_ERROR_CHECK_REQ              (EDD_IOCTL_ENABLE_ERROR_CHECK_REQ)
#define DRV_EDD_SET_TRAFFIC_CLASS_ARRANGEMENT_REQ   (EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_REQ)
#define DRV_EDD_REQUEST_BUFFERS_REQ                 (EDD_IOCTL_REQUEST_BUFFERS_REQ)
#define DRV_EDD_GET_HAL_BUFFERS_REQ                 (EDD_IOCTL_GET_HAL_BUFFERS_REQ)
#define DRV_EDD_ENABLE_ARP_RESPONDER_REQ            (EDD_IOCTL_ENABLE_ARP_RESPONDER_REQ)
#define DRV_EDD_DISABLE_ARP_RESPONDER_REQ           (EDD_IOCTL_DISABLE_ARP_RESPONDER_REQ)
#define DRV_EDD_ENABLE_ICMP_ECHO_RESPONDER_REQ      (EDD_IOCTL_ENABLE_ICMP_ECHO_RESPONDER_REQ)
#define DRV_EDD_DISABLE_ICMP_ECHO_RESPONDER_REQ     (EDD_IOCTL_DISABLE_ICMP_ECHO_RESPONDER_REQ)
#define DRV_EDD_SET_RESPONDER_IP_ADDRESS_REQ        (EDD_IOCTL_SET_RESPONDER_IP_ADDRESS_REQ)
#define DRV_EDD_CLR_MULTICAST_SINGLE_REQ            (EDD_IOCTL_CLR_MULTICAST_SINGLE_REQ)
#define DRV_EDD_CLR_MULTICAST_HASH_REQ              (EDD_IOCTL_CLR_MULTICAST_HASH_REQ)
#define DRV_EDD_CLR_MULTICAST_ALL_REQ               (EDD_IOCTL_CLR_MULTICAST_ALL_REQ)
#define DRV_EDD_SET_CONNECTION_TYPE_REQ             (EDD_IOCTL_SET_CONNECTION_TYPE_REQ)
#define DRV_EDD_SET_MDIX_REQ                        (EDD_IOCTL_SET_MDIX_REQ)
#define DRV_EDD_GET_MDIX_REQ                        (EDD_IOCTL_GET_MDIX_REQ)
#define DRV_EDD_GET_RESPONDER_IP_ADDRESS_REQ        (EDD_IOCTL_GET_RESPONDER_IP_ADDRESS_REQ)
#define DRV_EDD_GET_HAL_REQUIRED_BUFFERS_REQ        (EDD_IOCTL_GET_HAL_REQUIRED_BUFFERS_REQ)
#define DRV_EDD_GET_NUM_PORTS_REQ                   (EDD_IOCTL_GET_NUM_PORTS_REQ)
  /* requests the number of ports attached to a single device
  pvData points to an UINT32

  if the device has only one single port/link, it shall report
  the number of ports equal to 1. */

typedef UINT32 DRV_EDD_COMMAND_T;


/* Ethernet EtherType definitions */
#define RX_EDD_ETHERTYPE_VLAN           (0x8100)
#define RX_EDD_ETHERTYPE_IPv4           (0x0800)
#define RX_EDD_ETHERTYPE_ARP            (0x0806)

/* Length */
#define RX_EDD_LEN_MAC                  (6)
#define RX_EDD_LEN_VLAN                 (4)
#define RX_EDD_LEN_TYPE                 (2)
#define RX_EDD_LEN_DATA_MIN             (50)
#define RX_EDD_LEN_DATA_MAX             (1500)
#define RX_EDD_LEN_CRC                  (4)


/* Filter */
#define RX_EDD_FILTER_DIRECTED          (0x0001)    /* Frames with own MAC addess */
#define RX_EDD_FILTER_MULTICAST         (0x0002)    /* Frames with Multicast adresses */
#define RX_EDD_FILTER_MULTICAST_ALL     (0x0004)    /* Frames with all Multicast addresses */
#define RX_EDD_FILTER_BROADCAST         (0x0008)    /* Frames with Broadcast adresses */



/** Port Status enumeration */
enum EDD_PORT_STATUS_Etag
{
  /** Reserved value. do not use! */
  EDD_PORT_STATUS_RESERVED        = 0,
  /** Port is ready to pass packets */
  EDD_PORT_STATUS_UP              = 1,
  /** Port is down */
  EDD_PORT_STATUS_DOWN            = 2,
  /** Port is in some testing mode */
  EDD_PORT_STATUS_TESTING         = 3,
  /** Port status can not be determined */
  EDD_PORT_STATUS_UNKNOWN         = 4,
  /** Port is dormant (???) */
  EDD_PORT_STATUS_DORMANT         = 5,
  /** Port is not present (???) */
  EDD_PORT_STATUS_NOTPRESENT      = 6,
  /** A lower layer is down. (Maybe use this for special switches like ethercat/sercos...) */
  EDD_PORT_STATUS_LOWERLAYERDOWN  = 7,
};

/** Capabilities bitmask enumeratino
 *
 */
enum EDD_CAPABILITY_Etag
{
  /** Auto Negotiation Supported */
  EDD_CAPABILITY_AUTONEG = 0x01,
};

/** Mau type enumeration
 *
 * The bit number corresponding to a mau type according
 * the iana mau mib.
 */
enum EDD_MAU_TYPE_Etag
{
  /** Unkown */
  EDD_MAU_TYPE_UNKNOWN            = 0,
  /** 10 MBit Half Duplex Coper */
  EDD_MAU_TYPE_10BASET_HD         = 10,
  /** 10 MBit Full Duplex Coper */
  EDD_MAU_TYPE_10BASET_FD         = 11,
  /** 100 MBit Full Duplex Coper */
  EDD_MAU_TYPE_100BASETX_HD       = 15,
  /** 100 MBit Full Duplex Coper */
  EDD_MAU_TYPE_100BASETX_FD       = 16,
  /** 100 MBit Half Duplex Glass Fiber */
  EDD_MAU_TYPE_100BASEFX_HD       = 17,
  /** 100 MBit Full Duplex Glass Fiber */
  EDD_MAU_TYPE_100BASEFX_FD       = 18,
};

/** Bit Mask enumeration for valid counters
 *
 */
enum EDD_PORT_STATUS_CNT_VALID
{
  EDD_PORT_STATUS_CNT_INOCTETS        = 0x00000001,
  EDD_PORT_STATUS_CNT_INUCASTPKTS     = 0x00000002,
  EDD_PORT_STATUS_CNT_INDISCARDS      = 0x00000004,
  EDD_PORT_STATUS_CNT_INERRORS        = 0x00000008,
  EDD_PORT_STATUS_CNT_INUNKNOWNPROTOS = 0x00000010,
  EDD_PORT_STATUS_CNT_OUTOCTETS       = 0x00000020,
  EDD_PORT_STATUS_CNT_OUTUCASTPKTS    = 0x00000040,
  EDD_PORT_STATUS_CNT_OUTDISCARDS     = 0x00000080,
  EDD_PORT_STATUS_CNT_OUTERRORS       = 0x00000100,
};

/** MDI Mode enumeration
 *
 */
enum EDD_MDI_MODE
{
  EDD_MDI_MODE_RESERVED = 0,
  EDD_MDI_MODE_AUTO     = 1,
  EDD_MDI_MODE_MDI      = 2,
  EDD_MDI_MODE_MDIX     = 3,
};

// hal edd identifier
// connection state
/*
typedef struct DRV_EDD_CONNECTION_STATE_Ttag {
  UINT32    ulPortNo;
  UINT32    ulSpeed;                              // speed in MHz (only valid if link is up)
  BOOLEAN   fIsLinkUp;                            // link up flag (true = link is up, false = link is down)
  BOOLEAN   fIsFullDuplex;                        // full duplex flag (only valid if link is up, true = full duplex, false = half duplex)
} DRV_EDD_CONNECTION_STATE_T;
*/
typedef EDD_CONNECTION_STATE_T DRV_EDD_CONNECTION_STATE_T;

/* Timestamp data */
/*
typedef struct DRV_EDD_TIMESTAMP_Ttag
{
  UINT32 ulNanoseconds;
  UINT32 ulSeconds;
} DRV_EDD_TIMESTAMP_T;
*/
typedef EDD_TIMESTAMP_T DRV_EDD_TIMESTAMP_T;

/*
typedef struct DRV_EDD_CONNECTION_TYPE_Ttag
{
  UINT32    ulPortNo;
  BOOLEAN   fLoopbackEnabled;                       // enable loopback mode (TRUE = loopback enabled, FALSE = loopback disabled)
  BOOLEAN   fAutoNegEnabled;                        // enable autonegotiation (TRUE = autonegotiation enabled, FALSE = autonegotiation disabled)
  UINT32    ulSpeed;                                // link speed in MHz
  BOOLEAN   fUseFullDuplex;                         // enable Full Duplex (TRUE = Full Duplex enabled, FALSE = Full Duplex disabled)
} DRV_EDD_CONNECTION_TYPE_T;
*/
typedef EDD_CONNECTION_TYPE_T DRV_EDD_CONNECTION_TYPE_T;

/*
typedef struct DRV_EDD_MDIX_Ttag
{
  UINT32    ulPortNo;
  BOOLEAN   fAutoMdiXEnable;    // enable auto cross-over (MDI/MDI-X)
  BOOLEAN   fMdiX;              // TRUE= MDI-X , FALSE=MDI
} DRV_EDD_MDIX_T;
*/
typedef EDD_MDIX_T DRV_EDD_MDIX_T;

#define DRV_EDD_ALL_PORTS           EDD_ALL_PORTS    /* (0xfffffffe) */
#define DRV_EDD_DEFAULT_PORT        EDD_DEFAULT_PORT /* (0xffffffff) */

#define DRV_EDD_MULTI_PORT          EDD_MULTI_PORT  /* (0x80000000) */
#define DRV_EDD_MASTER_CONFIRMATION EDD_MASTER_CONFIRMATION /* (0x40000000) */ //flag will only be seen in conjunction with Multi port flag
//this flag marks a send confirmation that has been selected as a confirmation for applications that
//do not wish to use multiple send confirmations

#define DRV_EDD_PORT_MASK EDD_PORT_MASK /* (0x0000ffff) */


typedef struct RX_EDD_FRAME_BUF_Ttag RX_EDD_FRAME_BUF_T;
typedef EDD_ETHERNET_FRAME_T RX_EDD_ETHERNET_FRAME_T;

#define DRV_EDD_SEND_ALL_PORTS DRV_EDD_ALL_PORTS
#define DRV_EDD_SEND_DEFAULT_PORT DRV_EDD_DEFAULT_PORT


/****************************************************************************************
* Edd, packets */

typedef EDD_MAC_ADDR_T RX_EDD_MAC_ADDR_T;

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(AP_EDD)
#endif

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(AP_EDD)
#endif

#define RX_EDD_EVENT_DEVICE_READY             0x00000001
#define RX_EDD_EVENT_MAC_CHANGED              0x00000002

typedef void (* RX_EDD_EVENT_CALLBACK)(RX_HANDLE hEdd, UINT32 ulEventCode, void* pvEventParam, void* pvUserData);

/******************************************************************************
 * Callback functionality of EDD
 *    - receive callback (old style)
 *    - send complete callback (old style)
 *    - receive callback (new style)
 *    - send complete callback (new style)
 */

/* New API Send/Recv */
typedef RX_EDD_ETHERNET_FRAME_T FAR* (FAR* RX_EDD_CALLBACK_RECV_FRM)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, void FAR* pvUserData);
typedef void                    FAR  (FAR* RX_EDD_CALLBACK_SEND_FRM)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, void FAR* pvUserData);

/* New API Send/Recv including Timestamp */
typedef RX_EDD_ETHERNET_FRAME_T FAR* (FAR* RX_EDD_CALLBACK_RECV_TIMESTAMP)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, DRV_EDD_TIMESTAMP_T FAR* ptTimestamp, void FAR* pvUserData);
typedef void                    FAR  (FAR* RX_EDD_CALLBACK_SEND_TIMESTAMP)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, DRV_EDD_TIMESTAMP_T FAR* ptTimestamp, void FAR* pvUserData);

/* New API Recv including Timestamp and Port */
typedef RX_EDD_ETHERNET_FRAME_T FAR* (FAR* RX_EDD_CALLBACK_RECV_TIMESTAMP_PORT)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, DRV_EDD_TIMESTAMP_T FAR* ptTimestamp, UINT32 ulPortNo, void FAR* pvUserData);
typedef void                    FAR  (FAR* RX_EDD_CALLBACK_SEND_TIMESTAMP_PORT)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, DRV_EDD_TIMESTAMP_T FAR* ptTimestamp, UINT32 ulPortNo, void FAR* pvUserData);

/* New API Recv including Port */
typedef RX_EDD_ETHERNET_FRAME_T FAR* (FAR* RX_EDD_CALLBACK_RECV_PORT)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, UINT32 ulPortNo, void FAR* pvUserData);
typedef void                    FAR  (FAR* RX_EDD_CALLBACK_SEND_PORT)(RX_EDD_ETHERNET_FRAME_T FAR* ptBuf, UINT uiLength, UINT32 ulPortNo, void FAR* pvUserData);

/* New API Send Flow Control */
enum RX_EDD_FLW_RETURNtag
{
  RX_EDD_FLW_REJECT = 0, /* Reject frame from sending */
  RX_EDD_FLW_SEND = 1, /* Send frame directly to the Hal */
  RX_EDD_FLW_PENDING = 2 /* Hold back frame but return RX_OK to Frame Sender */
};

typedef UINT32 RX_EDD_FLW_RETURN;

/* callback types */
enum RX_EDD_CBK_TYPEtag
{
  RX_EDD_CBK_LEGACY = 1,
  RX_EDD_CBK_API2 = 2,
  RX_EDD_CBK_API2_TIMESTAMP = 3,
  RX_EDD_CBK_API2_PORT = 4,
  RX_EDD_CBK_API2_TIMESTAMP_PORT = 5,
  RX_EDD_CBK_MAX = 6
};
typedef UINT8 RX_EDD_CBK_TYPE;

typedef RX_EDD_FLW_RETURN            (FAR* RX_EDD_CALLBACK_FLW_FN)(
                                                                   RX_HANDLE                     hEdd,
                                                                   RX_EDD_FRAME_BUF_T FAR*       ptFrameBuf,
                                                                   void FAR*                     pvFlowCbkUserData);
/* return value TRUE if frame can be sent directly */


typedef void FAR (FAR* RX_EDD_LINKSTATUS_FN)(RX_HANDLE hEdd, UINT uiPortNo,  const DRV_EDD_CONNECTION_STATE_T FAR* ptConnectionState, void FAR* pvUserData);

/* collision callback */
typedef void FAR (FAR* RX_EDD_COLLISION_FN)(RX_HANDLE hEdd, UINT uiPortNo, void FAR* pvUserData);

/* rx error callback */
typedef void FAR (FAR* RX_EDD_RXER_FN)(RX_HANDLE hEdd, UINT uiPortNo, void FAR* pvUserData);

/******************************************************************************
 * Ioctl data definition
 */

typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_GET_STATS_APP_Ttag
{
  RX_HANDLE                             hApp;
  UINT                                  uiStatFrameOk;
  UINT                                  uiStatFrameRet;
  UINT                                  uiStatFrameDropBufExceed;
  UINT                                  uiStatFrameDropNoCbk;
} RX_EDD_IOCTL_GET_STATS_APP_T;

typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_GET_STATS_Ttag
{
  UINT                                  uiStatFrameDropUnknType;
  UINT                                  uiStatBufExceed;
} RX_EDD_IOCTL_GET_STATS_T;

/*
typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_SET_MULTICAST_SINGLE_Ttag
{
  RX_EDD_MAC_ADDR_T tMacAddr;
} RX_EDD_IOCTL_SET_MULTICAST_SINGLE_T;
*/
typedef EDD_IOCTL_SET_MULTICAST_SINGLE_T RX_EDD_IOCTL_SET_MULTICAST_SINGLE_T;

/*
typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_CLR_MULTICAST_SINGLE_Ttag
{
  RX_EDD_MAC_ADDR_T tMacAddr;
} RX_EDD_IOCTL_CLR_MULTICAST_SINGLE_T;
*/
typedef EDD_IOCTL_CLR_MULTICAST_SINGLE_T RX_EDD_IOCTL_CLR_MULTICAST_SINGLE_T;

/*
typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_SET_MULTICAST_HASH_Ttag
{
  UINT32 ulHash;
} RX_EDD_IOCTL_SET_MULTICAST_HASH_T;
*/
typedef EDD_IOCTL_SET_MULTICAST_HASH_T RX_EDD_IOCTL_SET_MULTICAST_HASH_T;

/*
typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_CLR_MULTICAST_HASH_Ttag
{
  UINT32 ulHash;
} RX_EDD_IOCTL_CLR_MULTICAST_HASH_T;
*/
typedef EDD_IOCTL_CLR_MULTICAST_HASH_T RX_EDD_IOCTL_CLR_MULTICAST_HASH_T;

/*
typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_Ttag
{
  UINT32 ulClass;
} RX_EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_T;
*/
typedef EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_T RX_EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_T;

typedef __PACKED_PRE struct __PACKED_POST RX_EDD_IOCTL_REQUEST_BUFFERS_Ttag
{
  RX_HANDLE                             hApp;
  UINT                                  uiBuffers;
} RX_EDD_IOCTL_REQUEST_BUFFERS_T;

typedef EDD_IOCTL_GET_HAL_BUFFERS_T RX_EDD_IOCTL_GET_HAL_BUFFERS_T;

/** Port Status Ioctl Request
 *
 * The data structure associated with EDD_IOCTL_GET_PORT_STATUS_REQ ioctl.
 */
typedef struct EDD_IOCTL_GET_PORT_STATUS_Ttag
{
  /** The port to get the status for. [input] */
  UINT8                                 bPort;
  /** The admin status of the port. [output] */
  UINT8                                 bAdminStatus;
  /** The operational status of the port. [output] */
  UINT8                                 bOperStatus;
  /** The Mautype (connection type of the Port) given as bit number
   * according IANA mau mib. [output]*/
  UINT8                                 bMauType;
  /** The counters supported by this hal encoded as bitmask */
  UINT32                                ulValidCntsBf;
  /** The number of received bytes [output]*/
  UINT32                                ulInOctets;
  /** The number of received unicast packets [output]*/
  UINT32                                ulInUCastPkts;
  /** The number of dropped packets [output]*/
  UINT32                                ulInDiscards;
  /** The number of bad received packets [output]*/
  UINT32                                ulInErrors;
  /** The number of packets which have not been delivered to any upper layer [output]*/
  UINT32                                ulInUnkownProtos;
  /** The number of sent bytes [output]*/
  UINT32                                ulOutOctets;
  /** The number of sent unicast packets [output]*/
  UINT32                                ulOutUCastPkts;
  /** The number of discarded outgoing packets [outputs] */
  UINT32                                ulOutDiscards;
  /** The number of packets failed to sent */
  UINT32                                ulOutErrors;
} EDD_IOCTL_GET_PORT_STATUS_T;

/** Inline function to set a mau type bit in mau type bitfield
 *
 * @param [in] pbMauTypeArray points to the mau type bitfield
 * @param [in] bMauType is the bit number to set
 */
inline static void EDD_SET_MAUTYPE_BIT(UINT8 *pbMauTypeArray, UINT8 bMauType)
{
  pbMauTypeArray[bMauType / 8] |= 0x80 >> (bMauType % 8);
}

/** Inline function to clear a mau type bit in mau type bitfield
 *
 * @param [in] pbMauTypeArray points to the mau type bitfield
 * @param [in] bMauType is the bit number to clear
 */
inline static void EDD_CLR_MAUTYPE_BIT(UINT8 *pbMauTypeArray, UINT8 bMauType)
{
  pbMauTypeArray[bMauType / 8] &= ~(0x80 >> (bMauType % 8));
}

/** Inline function to check if a  mau type bit is set in mau type bitfield
 *
 * @param [in] pbMauTypeArray points to the mau type bitfield
 * @param [in] bMauType is the bit number to check for
 *
 * @return Non-Zero if the bit is set
 */
inline static int EDD_CHECK_MAUTYPE_BIT(const UINT8 *pbMauTypeArray, UINT8 bMauType)
{
  return pbMauTypeArray[bMauType / 8] & (0x80 >> (bMauType % 8));
}

/** Port Status Ioctl Request
 *
 * The data structure associated with EDD_IOCTL_GET_PORT_STATUS_REQ ioctl.
 */
typedef struct EDD_IOCTL_GET_PORT_INFO_Ttag
{
  /** The port to get the info for. [input] */
  UINT8                                 bPort;
  /** Reserved for future usage. Set to zero [input] */
  UINT8                                 bCapabilities;
  /** Mac Address of this Port. [output] */
  UINT8                                 abMacAddress[6];
  /** The maximum bandwidth of the port in bits per second. [output] */
  UINT32                                ulSpeed;
  /** The maximum packet size of this port [output] */
  INT32                                 ilMTU;
  /** Supported MAU Types of this Port [output] */
  UINT8                                 abMauTypes[16];
} EDD_IOCTL_GET_PORT_INFO_T;

/** Set Port MacAddr Ioctl Request
 * The data structure associated with EDD_IOCTL_SET_PORT_MACADDR_REQ ioctl.
 */
typedef struct EDD_IOCTL_SET_PORT_MACADDR_Ttag
{
  /** The port to set the mac address for. [input] */
  UINT8                                 bPort;
  /** Reserved for future usage. Set to zero [input] */
  UINT8                                 bReserved;
  /** The mac address to set. [input] */
  UINT8                                 abMacAddress[6];
} EDD_IOCTL_SET_PORT_MACADDR_T;


/** Set the Mau Type of the Port
 * The data structure associated with EDD_IOCTL_SET_PORT_MAUTYPE_REQ ioctl.
 */
typedef struct EDD_IOCTL_SET_PORT_MAUTYPE_Ttag
{
  /** The port to set the mac address for. [input] */
  UINT8                                 bPort;
  /** Bitfield of the mau types to enable. According IANA Mau mib. [input] */
  UINT8                                 abMauTypes[16];
  /** The mdi mode to set [input] */
  UINT8                                 bMdiMode;

} EDD_IOCTL_SET_PORT_MAUTYPE_T;

/** Get the configured mau type of a port */
typedef EDD_IOCTL_SET_PORT_MAUTYPE_T EDD_IOCTL_GET_PORT_MAUTYPE_T;

/** This structure contains fuunction pointers to the callbacks to be used by
 * the edd driver to indicate events on the secondary chassis mac interface.
 *
 * These function are to be implemented by the application (e.g. Ethernet
 * Interface Task) The first argument is the pointer to the structure itself.
 * This can be used to obtain an application resource pointer as follows:
 *
 * struct edd_2ndchassis_app_clb_t {
 *   EDD_2NDCHASSIS_APP_CLB_T tClb;
 *
 *   UINT32                   uSomeUserUint;
 * }
 *
 * void App_RecvFrame_ind(EDD_2NDCHASSIS_APP_CLB_T *ptSelf, VOID* hFrame)
 * {
 *   struct edd_2ndchassis_app_clb_t *ptRsc = (void*)(ptSelf);
 *
 *   ptRsc->uSomeUserUint = 5;
 * }
 */
typedef struct EDD_2NDCHASSIS_APP_CLB_Ttag {
  /** Send confirmation callback. This callback is invoked by edd driver whenever
   * a frame transmit request has been fully executed. The callback will be invoked
   * exactyle once for each transmitt request. It can be used to implement load
   * limiting. (See Ethernet Interface Task Source for example)
   *
   * The applications callback implementation must have the following properties:
   * - The callback must be multi task safe as it might be called from different
   *   task contexts at the same time
   * - The callback must not perform expensive operations as it is typically run from
   *   a high priority protocol task
   *
   * @param [in] ptSelf points to the callback structure
   */
  void (*pfnSendFrame_cnf)(struct EDD_2NDCHASSIS_APP_CLB_Ttag *ptSelf);
  /** Receive frame indication callback. This callback is invoked by edd driver
   * whenever a frame for the secondary chassis mac interface has been received.
   * The handle shall be used by the application later on to retrieve the frames
   * content.
   *
   * The applications callback implementation must have the following properties:
   * - The callback must be multi task safe as it might be called from different
   *   task contexts at the same time
   * - The callback must not perform expensive operations as it is typically run from
   *   a high priority protocol task
   *
   * @param [in] ptSelf points to the callback structure
   * @param [in] hFrame is the handle of the frame
   */
  void (*pfnRecvFrame_ind)(struct EDD_2NDCHASSIS_APP_CLB_Ttag *ptSelf, VOID *hFrame);
} EDD_2NDCHASSIS_APP_CLB_T;


/** This structure contains fuunction pointers to the callbacks to be used by
 * the application to request actions on the secondary chassis mac interface.
 *
 * These function are provided by the edd driver. The first argument is the pointer
 * to the structure itself. This pointer is obtained via the associated IOCTL
 * EDD_IOCTL_REGISTER_2NDCHASSIS_REQ.
 *
 * EDD_IOCTL_REGISTER_2NDCHASSIS_T tRegIoctl;
 * tRegIoctl.ptAppClb = &(ptRsc->t2ndChassisAppClb);
 *
 * Drv_EddIoctl(hEdd, EDD_IOCTL_REGISTER_2NDCHASSIS_REQ, &tRegIoctl)
 *
 * tReqIoctl.ptEddClb->pfnSendFrame(tReqIoctl.ptEddClb,....);
 */
typedef struct EDD_2NDCHASSIS_EDD_CLB_Ttag {
  /** This function shall be used to request transmission of a frame using the
   * secondary chassis mac address.
   *
   * Transmission of such a frame involves:
   * - sending of the frame on ethernet port 0 and 1 depending on destination mac address
   * - forwarding of the frame to primary chassis mac (usually netX protocol stack)
   *
   * The edd hal implementation of this function might filter out several frames
   * which can disturb the realtime ethernet protocol.
   *
   * Each queued send request must be confirmed by the edd hal by a
   * single invocation of the send confirmation callback of EDD_2NDCHASSIS_APP_CLB_T.
   * Furthermore the edd hal is expected to enforce the secondary chassis
   * mac address into the source mac address field of the frame.
   *
   * @param [in] ptSelf points to the edd hal callback structure
   * @param [in] pvData points to the data to send
   * @param [in] ulLen is the length of the data to send
   * @param [in] ulPort is the port to send the data on (this is for future use only and shall
   *             be ignored by the edd hal and set to zero by the application)
   * @return The function will return zero if the send request has been queued. Non zero
   *         return value indicates that a problem occured and no request had been queued.
   *         On nonzero return value the send confirmation callback will not be invoked
   */
  UINT32 (*pfnSendFrame_req)(struct EDD_2NDCHASSIS_EDD_CLB_Ttag *ptSelf, VOID *pvData, UINT32 ulLen, UINT32 ulPort);
  /** This function shall be used to retrieve the data of a frame received on the
   * secondary chassis mac address. This function must be invoked once for
   * each edd hal call of the applications indication callback using the supplied
   * handle. This is required in order to free the associated resources within the edd
   * hal.
   *
   * If the application does not want to handle the data, the pvData, pulLen and pulPort
   * parameters might by set to NULL. In that case the edd hal will only free the
   * handles associated resources.
   *
   * The edd hal might implement a receive filter to filter out several frames
   * which might disturb the realtime ethernet protocol.
   *
   * @param [in]  ptSelf points to the edd hal callback structure
   * @param [in]  hFrame is the frame handle
   * @param [out] pvData points to a data buffer with minimum length of 1518 bytes
   * @param [out] pulLen points to a variable to receive the lenght of the data
   * @param [out] pulPort points to a variable to receive the port where the frame has been received
   *              (this field is reserved for future use and shall be ignored by the application.
   *               the edd hal shall fill this field with zero)
   */
  void (*pfnRecvFrame_rsp)(struct EDD_2NDCHASSIS_EDD_CLB_Ttag *ptSelf, VOID *hFrame, VOID *pvData, UINT32 *pulLen, UINT32* pulPort);
} EDD_2NDCHASSIS_EDD_CLB_T;

/** ioctl data structure to be used with EDD_IOCTL_REGISTER_2NDCHASSIS_REQ */
typedef struct {
  /** pointer to structure of application callback pointers
   * This parameter shall be provided by the application
   */
  EDD_2NDCHASSIS_APP_CLB_T     *ptAppClb;
  /** pointer to edd hal function pointers. This pointer is provided
   * by the edd hal to the application
   */
  EDD_2NDCHASSIS_EDD_CLB_T     *ptEddClb;
  /** mac addres of secondary chassis mac. this value is filled
   * by the edd hal to inform the application about the associated
   * mac address
   */
  EDD_MAC_ADDR_T                tMacAdress;
} EDD_IOCTL_REGISTER_2NDCHASSIS_T;


/*************************************************************
 *   Function Prototypes (Common Edd API)
 *************************************************************/

RX_FATAL  FAR DrvEddInit             (const void FAR*               pvCfg,
                                      UINT                          uNum); /* Make basic settings */

RX_RESULT FAR Drv_EddCreateEdd       (RX_HANDLE                     hEdd,
                                      const RX_EDD_SET_T FAR*       ptCfg); /* Creates a EDD Object */

RX_RESULT FAR Drv_EddDeleteEdd       (RX_HANDLE hEdd);

RX_RESULT FAR Drv_EddIdentifyEdd     (const STRING FAR*             pszIdn,
                                      UINT                          uInst,
                                      RX_HANDLE FAR*                phEdd);

RX_RESULT FAR Drv_EddUnregisterApp   (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp);

RX_RESULT FAR Drv_EddRegisterApp     (RX_HANDLE                     hEdd,
                                      RX_HANDLE FAR*                phEddApp);


/*************************************************************
 *   Function Prototypes (Edd network events)
 */
RX_RESULT Drv_EddRegisterForEddEvents(RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_EVENT_CALLBACK         pfnCallback,
                                      void*                         pvUserData);

RX_RESULT Drv_EddUnregisterForEddEvents(
                                      RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp);

/*************************************************************
 *   Function Prototypes (New Edd API)
 *************************************************************/

RX_RESULT FAR Drv_EddUnregisterCbk
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hApp,
                                      RX_HANDLE                     hEthType);

INLINE RX_RESULT FAR Drv_EddUnregisterEth
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hApp,
                                      RX_HANDLE                     hEthType)
{
  return Drv_EddUnregisterCbk(hEdd, hApp, hEthType);
}

/*************************************************************
 *   Function Prototypes (New Edd Flow Control API)
 *************************************************************/

RX_RESULT FAR Drv_EddSetFlowCbk      (RX_HANDLE                     hEdd,
                                      RX_EDD_CALLBACK_FLW_FN        fnFlowCbk,
                                      void FAR*                     pvUserData);

RX_RESULT FAR Drv_EddClearFlowCbk    (RX_HANDLE                     hEdd);

RX_RESULT FAR Drv_EddSendNoFlowCtl   (RX_HANDLE                     hEdd,
                                      RX_EDD_FRAME_BUF_T FAR*       ptBuf);

/*************************************************************
 *   Promiscuous Callback
 *************************************************************/

RX_RESULT FAR Drv_EddClearPromisc    (RX_HANDLE                     hEdd);

/*************************************************************
 *   Link Status Callback
 *************************************************************/

RX_RESULT FAR Drv_EddRegisterLinkStatus(RX_HANDLE                   hEdd,
                                        RX_EDD_LINKSTATUS_FN        fnCbk,
                                        void FAR*                   pvUserData,
                                        RX_HANDLE FAR*              phLinkStatusHook);

RX_RESULT FAR Drv_EddUnregisterLinkStatus(RX_HANDLE                 hEdd,
                                          RX_HANDLE                 hLinkStatusHook);

/*************************************************************
 *   Receive Error Callback
 *************************************************************/

RX_RESULT FAR Drv_EddRegisterRxError   (RX_HANDLE                   hEdd,
                                        RX_EDD_RXER_FN              fnCbk,
                                        void FAR*                   pvUserData,
                                        RX_HANDLE FAR*              phLinkStatusHook);

RX_RESULT FAR Drv_EddUnregisterRxError   (RX_HANDLE                 hEdd,
                                          RX_HANDLE                 hLinkStatusHook);

/*************************************************************
 *   Collision Callback
 *************************************************************/

RX_RESULT FAR Drv_EddRegisterColCbk    (RX_HANDLE                   hEdd,
                                        RX_EDD_COLLISION_FN         fnCbk,
                                        void FAR*                   pvUserData,
                                        RX_HANDLE FAR*              phColCbkHook);

RX_RESULT FAR Drv_EddUnregisterColCbk   (RX_HANDLE                  hEdd,
                                         RX_HANDLE                  hColCbkHook);




/**************************************************************************************************
 * Final design of upper sending/receiving layer API
 */

typedef UINT32 RX_EDD_TLR_PKT_HEADER_T[10];                   /* Should match the size of an TLR packet header actually */

typedef RX_EDD_FRAME_BUF_T      FAR* (FAR* RX_EDD_CALLBACK_RECV_BUF)(RX_EDD_FRAME_BUF_T FAR* ptBuf, void FAR* pvUserData);
typedef void                    FAR  (FAR* RX_EDD_CALLBACK_SEND_BUF)(RX_EDD_FRAME_BUF_T FAR* ptBuf, UINT32 ulPortNo);


typedef EDD_COMMBLK_T RX_EDD_COMMBLK_T;

struct RX_EDD_FRAME_BUF_Ttag
{
  RX_EDD_TLR_PKT_HEADER_T               tHead;
  RX_EDD_COMMBLK_T                      atEth[1]; /* on sending, receive use only first block */
};


enum RX_EDD_PROTOCOL_TYPEtag
{
  RX_EDD_PROTO_ETHERTYPE  = 0,
  RX_EDD_PROTO_UDP        = 1
};
typedef UINT8 RX_EDD_PROTOCOL_TYPE;





RX_RESULT FAR Drv_EddGetBuffer           (RX_HANDLE                       hEdd,
                                          RX_HANDLE                       hApp,
                                          RX_EDD_FRAME_BUF_T FAR* FAR*    pptBuf);

RX_RESULT FAR Drv_EddSendBuffer          (RX_HANDLE                       hEdd,
                                          RX_HANDLE                       hApp,
                                          RX_EDD_FRAME_BUF_T FAR*         ptBuf);

RX_RESULT FAR Drv_EddFreeBuffer          (RX_HANDLE                       hEdd,
                                          RX_HANDLE                       hApp,
                                          RX_EDD_FRAME_BUF_T FAR*         ptBuf);

RX_RESULT FAR Drv_EddRegisterEthCb       (RX_HANDLE                       hEdd,
                                          RX_HANDLE                       hApp,
                                          UINT16                          usEthType,
                                          RX_EDD_CALLBACK_RECV_BUF        fnRecvCbk,
                                          void FAR*                       pvUserData,
                                          RX_HANDLE FAR*                  phEddEth);

RX_RESULT FAR Drv_EddRegisterUdpCb       (RX_HANDLE                       hEdd,
                                          RX_HANDLE                       hApp,
                                          UINT16                          usUdpPort,
                                          RX_EDD_CALLBACK_RECV_BUF        fnRecvCbk,
                                          void FAR*                       pvUserData,
                                          RX_HANDLE FAR*                  phEddEth);

RX_RESULT FAR Drv_EddSetPromiscCb        (RX_HANDLE                       hEdd,
                                          RX_EDD_CALLBACK_RECV_BUF        fnRecvCbk,
                                          void FAR*                       pvUserData);

/**************************************************************************************************
 * Function Prototypes (Frame based API) (earlier design)
 */

RX_RESULT FAR Drv_EddGetFrame        (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR* FAR* pptFrame);

RX_RESULT FAR Drv_EddFreeFrame       (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      const RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame);

RX_RESULT FAR Drv_EddSendCbk         (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame,
                                      UINT                          uiLength,
                                      BOOLEAN                       fHighPrio,
                                      UINT                          uiPortNo,
                                      RX_EDD_CBK_TYPE               eCbkType,
                                      void FAR*                     pvSendCbk,
                                      void FAR*                     pvUserData);

INLINE RX_RESULT FAR Drv_EddSend     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame,
                                      UINT                          uiLength,
                                      BOOLEAN                       fHighPrio,
                                      RX_EDD_CALLBACK_SEND_FRM      fnSendCbk,
                                      void FAR*                     pvUserData)
{
  return Drv_EddSendCbk(hEdd, hEddApp, ptFrame, uiLength, fHighPrio, DRV_EDD_SEND_DEFAULT_PORT, RX_EDD_CBK_API2, (void FAR*)fnSendCbk, pvUserData);
}

INLINE RX_RESULT FAR Drv_EddSendTimestamp   (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame,
                                      UINT                          uiLength,
                                      BOOLEAN                       fHighPrio,
                                      RX_EDD_CALLBACK_SEND_TIMESTAMP fnSendCbk,
                                      void FAR*                     pvUserData)
{
  return Drv_EddSendCbk(hEdd, hEddApp, ptFrame, uiLength, fHighPrio, DRV_EDD_SEND_DEFAULT_PORT, RX_EDD_CBK_API2_TIMESTAMP, (void FAR*)fnSendCbk, pvUserData);
}

INLINE RX_RESULT FAR Drv_EddSendPort (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame,
                                      UINT                          uiLength,
                                      BOOLEAN                       fHighPrio,
                                      UINT                          uiPortNo,
                                      RX_EDD_CALLBACK_SEND_PORT      fnSendCbk,
                                      void FAR*                     pvUserData)
{
  return Drv_EddSendCbk(hEdd, hEddApp, ptFrame, uiLength, fHighPrio, uiPortNo, RX_EDD_CBK_API2_PORT, (void FAR*)fnSendCbk, pvUserData);
}

INLINE RX_RESULT FAR Drv_EddSendPortTimestamp
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hEddApp,
                                      RX_EDD_ETHERNET_FRAME_T FAR*  ptFrame,
                                      UINT                          uiLength,
                                      BOOLEAN                       fHighPrio,
                                      UINT                          uiPortNo,
                                      RX_EDD_CALLBACK_SEND_TIMESTAMP_PORT fnSendCbk,
                                      void FAR*                     pvUserData)
{
  return Drv_EddSendCbk(hEdd, hEddApp, ptFrame, uiLength, fHighPrio, uiPortNo, RX_EDD_CBK_API2_TIMESTAMP_PORT, (void FAR*)fnSendCbk, pvUserData);
}

RX_RESULT FAR Drv_EddIoctl           (RX_HANDLE                     hEdd,
                                      UINT32                        ulCmd,
                                      void FAR*                     pvData);

RX_RESULT FAR Drv_EddRegisterCbk      (RX_HANDLE                    hEdd,
                                       RX_HANDLE                    hApp,
                                       RX_EDD_PROTOCOL_TYPE         eProtoType,
                                       UINT16                       usProtoValue,
                                       RX_EDD_CBK_TYPE              eCbkType,
                                       void FAR*                    pvCbk,
                                       void FAR*                    pvUserData,
                                       RX_HANDLE FAR*               phEddEth);

INLINE RX_RESULT FAR Drv_EddRegisterEthFrm
                                          (RX_HANDLE                     hEdd,
                                           RX_HANDLE                     hApp,
                                           UINT16                        usEtherType,
                                           RX_EDD_CALLBACK_RECV_FRM      fnRecvCbk,
                                           void FAR*                     pvUserData,
                                           RX_HANDLE FAR*                phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_ETHERTYPE, usEtherType, RX_EDD_CBK_API2, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

INLINE RX_RESULT FAR Drv_EddRegisterEthUdpFrm(RX_HANDLE                    hEdd,
                                       RX_HANDLE                    hApp,
                                       UINT16                       usUdpPort,
                                       RX_EDD_CALLBACK_RECV_FRM     fnRecvCbk,
                                       void FAR*                    pvUserData,
                                       RX_HANDLE FAR*               phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_UDP, usUdpPort, RX_EDD_CBK_API2, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}


INLINE RX_RESULT FAR Drv_EddRegisterEthTimestamp
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hApp,
                                      UINT16                        usEtherType,
                                      RX_EDD_CALLBACK_RECV_TIMESTAMP fnRecvCbk,
                                      void FAR*                     pvUserData,
                                      RX_HANDLE FAR*                phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_ETHERTYPE, usEtherType, RX_EDD_CBK_API2_TIMESTAMP, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

INLINE RX_RESULT FAR Drv_EddRegisterEthUdpTimestamp
                                     (RX_HANDLE                       hEdd,
                                      RX_HANDLE                       hApp,
                                      UINT16                          usUdpPort,
                                      RX_EDD_CALLBACK_RECV_TIMESTAMP  fnRecvCbk,
                                      void FAR*                       pvUserData,
                                      RX_HANDLE FAR*                  phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_UDP, usUdpPort, RX_EDD_CBK_API2_TIMESTAMP, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}


INLINE RX_RESULT FAR Drv_EddRegisterEthPort
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hApp,
                                      UINT16                        usEtherType,
                                      RX_EDD_CALLBACK_RECV_PORT     fnRecvCbk,
                                      void FAR*                     pvUserData,
                                      RX_HANDLE FAR*                phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_ETHERTYPE, usEtherType, RX_EDD_CBK_API2_PORT, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

INLINE RX_RESULT FAR Drv_EddRegisterEthUdpPort
                                     (RX_HANDLE                       hEdd,
                                      RX_HANDLE                       hApp,
                                      UINT16                          usUdpPort,
                                      RX_EDD_CALLBACK_RECV_PORT       fnRecvCbk,
                                      void FAR*                       pvUserData,
                                      RX_HANDLE FAR*                  phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_UDP, usUdpPort, RX_EDD_CBK_API2_PORT, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

INLINE RX_RESULT FAR Drv_EddRegisterEthPortTimestamp
                                     (RX_HANDLE                     hEdd,
                                      RX_HANDLE                     hApp,
                                      UINT16                        usEtherType,
                                      RX_EDD_CALLBACK_RECV_TIMESTAMP_PORT fnRecvCbk,
                                      void FAR*                     pvUserData,
                                      RX_HANDLE FAR*                phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_ETHERTYPE, usEtherType, RX_EDD_CBK_API2_TIMESTAMP, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

INLINE RX_RESULT FAR Drv_EddRegisterEthUdpPortTimestamp
                                     (RX_HANDLE                       hEdd,
                                      RX_HANDLE                       hApp,
                                      UINT16                          usUdpPort,
                                      RX_EDD_CALLBACK_RECV_TIMESTAMP_PORT  fnRecvCbk,
                                      void FAR*                       pvUserData,
                                      RX_HANDLE FAR*                  phEddEth)
{
  return Drv_EddRegisterCbk(hEdd, hApp, RX_EDD_PROTO_UDP, usUdpPort, RX_EDD_CBK_API2_TIMESTAMP_PORT, (void FAR*)fnRecvCbk, pvUserData, phEddEth);
}

/*************************************************************
 *   Promiscuous Callback
 *************************************************************/

RX_RESULT FAR Drv_EddSetPromiscCbk    (RX_HANDLE                    hEdd,
                                       RX_EDD_CBK_TYPE              eCbkType,
                                       void FAR*                    pvRecvCbk,
                                       void FAR*                    pvUserData);

INLINE RX_RESULT FAR Drv_EddSetPromisc(RX_HANDLE                    hEdd,
                                       RX_EDD_CALLBACK_RECV_FRM     fnRecvCbk,
                                       void FAR*                    pvUserData)
{
  return Drv_EddSetPromiscCbk(hEdd, RX_EDD_CBK_API2, (void FAR*)fnRecvCbk, pvUserData);
}

INLINE RX_RESULT FAR Drv_EddSetPromiscTimestamp
                                     (RX_HANDLE                     hEdd,
                                      RX_EDD_CALLBACK_RECV_TIMESTAMP fnRecvCbk,
                                      void FAR*                     pvUserData)
{
  return Drv_EddSetPromiscCbk(hEdd, RX_EDD_CBK_API2_TIMESTAMP, (void FAR*)fnRecvCbk, pvUserData);
}


#ifdef __NANOSEC_TIME_VALID
INLINE NANOSEC_TIME Drv_EddConvertTimestampToTime(DRV_EDD_TIMESTAMP_T FAR* ptTimestamp)
{
  NANOSEC_TIME uulTime=ptTimestamp->ulSeconds;
  uulTime*=(((NANOSEC_TIME)Drv_SysTimeGetSysTimeBorder())+1);
  return uulTime+ptTimestamp->ulNanoseconds;
}

#endif

#endif /* #ifndef __AP_EDD_H */

#ifdef __cplusplus
}
#endif
