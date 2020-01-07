/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: Structs_Edd.h 1553 2013-08-06 06:31:14Z MichaelT $

  Description:
    User header file of Ethernet Device Driver (EDD) Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __STRUCTS_EDD_H
#define __STRUCTS_EDD_H


/****************************************************************************************
*  EDD, constants */

enum EDD_PARAMETER_TYPEtag
{
  EDD_PARAM_END_OF_LIST                 = 0x0000, /* mandatory end of list parameter */
  EDD_PARAM_MAC_ADDR                    = 0x0001, /* pvParam is a pointer to a MAC address */

  DRV_EDD_PARAM_START                   = 0x4000, /* start of driver edd specific parameters */

  EDD_DEV_SPEC_PARAM_START              = 0x8000, /* start of device specific parameters */
  EDD_PARAM_MAX_FIFO_LEVEL              = 0x8001, /* pvParam is a static value */
  EDD_PARAM_USED_IND_BORDER             = 0x8002, /* pvParam is a static value */
  EDD_PARAM_AGING_TIME                  = 0x8003, /* pvParam is a static value, aging time in seconds on switch device */

  EDD_OS_PARAM_START                    = 0xC000, /* start of operating and device specific parameters */
};

typedef UINT32 EDD_PARAMETER_TYPE;

/* parameter block that is handed over to the HAL for parsing

   the last entry must have EDD_PARAM_END_OF_LIST in the field eParamType
*/
typedef struct EDD_PARAMETERS_Ttag
{
  EDD_PARAMETER_TYPE        eParamType;
  void FAR*                 pvParam;
  UINT32                    ulInstance;
} EDD_PARAMETERS_T;


/* hardware stat counter structure */

typedef struct EDD_PORT_HWSTAT_Ttag
{
  /* port to be read out */
  UINT32                    ulPortNo;
  /* count of frames that were transmitted correctly */
  UINT32                    ulTransmittedOkay;
  /* single collision frames counter */
  UINT32                    ulSingleCollisionFrames;
  /* multiple collision frames counter */
  UINT32                    ulMultipleCollisionFrames;
  /* late collisions counter */
  UINT32                    ulLateCollisions;
  /* link down during transmission counter */
  UINT32                    ulLinkDownDuringTransmission;
  /* utx underflow during transmission */
  UINT32                    ulUtxUnderflowDuringTransmission;
  /* count of frames that were received correctly */
  UINT32                    ulFramesReceivedOkay;
  /* fcs errors */
  UINT32                    ulFCSErrors;
  /* alignment errors */
  UINT32                    ulAlignmentErrors;
  /* Frame too long errors */
  UINT32                    ulFrameTooLongErrors;
  /* Runt frame errors */
  UINT32                    ulRuntFrames;
  /* Collision fragments received */
  UINT32                    ulCollisionFragmentsReceived;
  /* Frames dropped due to low resource */
  UINT32                    ulDroppedDueLowResource;
  /* Frames dropped due to urx overflow */
  UINT32                    ulUrxOverflows;
  /* current rx fifo fill */
  UINT32                    ulRxFifoFill;
  /* current tx fifo fill */
  UINT32                    ulTxFifoFill;
} EDD_PORT_HWSTAT_T;

/* Ethernet EtherType definitions */
#define EDD_ETHERTYPE_VLAN           (0x8100)
#define EDD_ETHERTYPE_IPv4           (0x0800)
#define EDD_ETHERTYPE_ARP            (0x0806)

/* Length */
#define EDD_LEN_MAC                  (6)
#define EDD_LEN_VLAN                 (4)
#define EDD_LEN_TYPE                 (2)
#define EDD_LEN_DATA_MIN             (50)
#define EDD_LEN_DATA_MAX             (1500)
#define EDD_LEN_CRC                  (4)

/* Hal_Edd specific boolean type to rule out Console32 / ARM BOOL type mismatches */
typedef UINT32 EDD_BOOL;

// hal edd identifier
// connection state
typedef struct EDD_CONNECTION_STATE_Ttag {
  UINT32        ulPortNo;
  UINT32        ulSpeed;                              // speed in MHz (only valid if link is up)
  EDD_BOOL      fIsLinkUp;                            // link up flag (true = link is up, false = link is down)
  EDD_BOOL      fIsFullDuplex;                        // full duplex flag (only valid if link is up, true = full duplex, false = half duplex)
} EDD_CONNECTION_STATE_T;


/* Timestamp data */
typedef __PACKED_PRE struct __PACKED_POST EDD_TIMESTAMP_Ttag
{
  UINT32 ulNanoseconds;
  UINT32 ulSeconds;
} EDD_TIMESTAMP_T;

typedef struct EDD_CONNECTION_TYPE_Ttag
{
  UINT32        ulPortNo;
  EDD_BOOL      fLoopbackEnabled;                       // enable loopback mode (TRUE = loopback enabled, FALSE = loopback disabled)
  EDD_BOOL      fAutoNegEnabled;                        // enable autonegotiation (TRUE = autonegotiation enabled, FALSE = autonegotiation disabled)
  UINT32        ulSpeed;                                    // link speed in MHz
  EDD_BOOL      fUseFullDuplex;                         // enable Full Duplex (TRUE = Full Duplex enabled, FALSE = Full Duplex disabled)
} EDD_CONNECTION_TYPE_T;

typedef struct EDD_MDIX_Ttag
{
  UINT32      ulPortNo;
  EDD_BOOL    fAutoMdiXEnable;            // enable auto cross-over (MDI/MDI-X)
  EDD_BOOL    fMdiX;                    // TRUE= MDI-X , FALSE=MDI
} EDD_MDIX_T;


/* flags used to mark Sending and Receiving of ports */
/* a single port device does not have to look to these values at all on HalEddSend function */
/* a number from 0 to number of ports -1 is valid too
   These specify the actual single port to send to if multiple ports are available
*/
#define EDD_ALL_PORTS (0xfffffffe)
#define EDD_DEFAULT_PORT (0xffffffff)

/* flags that will be set by HalEddSendCnf to distinguish frames that will be used twice during
   SendCnf runs
    A single frame of a multi-run condition will have set EDD_MASTER_CONFIRMATION in conjunction with
    EDD_MULTI_PORT.
    However, a single port device might never use these, since it can always place a zero into the
    port number request done by HalEddGetPort or HalEddFillCommblk

*/
#define EDD_MULTI_PORT (0x80000000)
#define EDD_MASTER_CONFIRMATION (0x40000000) //flag will only be seen in conjunction with Multi port flag

/* The lower 16 bits actually represent the port number coded in ulPortNo
*/
#define EDD_PORT_MASK (0x0000ffff)

//this flag marks a send confirmation that has been selected as a confirmation for applications that
//do not wish to use multiple send confirmations

/****************************************************************************************
* Edd, packets */

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(STRUCTS_EDD)
#endif


/* Ethernet MAC address */
typedef UINT8     EDD_MAC_ADDR_T[EDD_LEN_MAC];

/* Ethernet II telegram */
__PACKED_PRE struct __PACKED_POST EDD_ETHERNET_Ttag {

  EDD_MAC_ADDR_T        tDstAddr;         /* Destination MAC address */
  EDD_MAC_ADDR_T        tSrcAddr;         /* Source MAC address */
  UINT16                usType;           /* Ethernet II type */
  UINT8                 abData[EDD_LEN_DATA_MAX];

};
typedef struct EDD_ETHERNET_Ttag EDD_ETHERNET_T;

/* Ethernet II telegram with VLAN header */
__PACKED_PRE struct __PACKED_POST EDD_ETHERNET_VLAN_Ttag {

  EDD_MAC_ADDR_T        tDstAddr;         /* Destination MAC address */
  EDD_MAC_ADDR_T        tSrcAddr;         /* Source MAC address */
  UINT16                usVlanTag;        /* VLAN tag header */
  UINT16                usVlanCtrl;       /* VLAN tag control */
  UINT16                usType;           /* Ethernet II type */
  UINT8                 abData[EDD_LEN_DATA_MAX];

};
typedef struct EDD_ETHERNET_VLAN_Ttag EDD_ETHERNET_VLAN_T;

__PACKED_PRE union __PACKED_POST EDD_ETHERNET_FRAME_Ttag {

  EDD_ETHERNET_T       tEth;
  EDD_ETHERNET_VLAN_T  tEthVlan;

};
typedef union EDD_ETHERNET_FRAME_Ttag EDD_ETHERNET_FRAME_T;


/******************************************************************************
 * Ioctl data definition
 */

/* structures relating to certain IOCTLs */
typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_SET_MULTICAST_SINGLE_Ttag
{
  EDD_MAC_ADDR_T tMacAddr;
} EDD_IOCTL_SET_MULTICAST_SINGLE_T;

typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_CLR_MULTICAST_SINGLE_Ttag
{
  EDD_MAC_ADDR_T tMacAddr;
} EDD_IOCTL_CLR_MULTICAST_SINGLE_T;

typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_SET_MULTICAST_HASH_Ttag
{
  UINT32 ulHash;
} EDD_IOCTL_SET_MULTICAST_HASH_T;

typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_CLR_MULTICAST_HASH_Ttag
{
  UINT32 ulHash;
} EDD_IOCTL_CLR_MULTICAST_HASH_T;

typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_Ttag
{
  UINT32 ulClass;
} EDD_IOCTL_SET_TRAFFIC_CLASS_ARRANGEMENT_T;

typedef __PACKED_PRE struct __PACKED_POST EDD_IOCTL_GET_HAL_BUFFERS_Ttag
{
  UINT                                  uiNumHalBuffers;
} EDD_IOCTL_GET_HAL_BUFFERS_T;


/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(STRUCTS_EDD)
#endif

typedef struct EDD_CONNECTION_PARAMETERS_Ttag {
        EDD_BOOL fLoopbackEnabled;                       // enable loopback mode (TRUE = loopback enabled, FALSE = loopback disabled)
        EDD_BOOL fAutoNegEnabled;                        // enable autonegotiation (TRUE = autonegotiation enabled, FALSE = autonegotiation disabled)
        UINT     uSpeed;                                    // link speed in MHz
        EDD_BOOL fUseFullDuplex;                         // enable Full Duplex (TRUE = Full Duplex enabled, FALSE = Full Duplex disabled)
} EDD_CONNECTION_PARAMETERS_T;


/* communication block used by Hal/Drv_Edd interface

    the HAL has to fill in the following fields:
    ulTimestampOffset (0 if not supported, otherwise it is the offset from the frame ptr in bytes)
    ulPortNo (port number as specified above)
    ulErrorCode (error code that happened with that frame otherwise a zero has to be placed here)

    all other fields are used by Drv_Edd and shall not be changed by the HAL
*/
typedef struct EDD_COMMBLK_Ttag
{
  /* pointer to actual frame */
  EDD_ETHERNET_FRAME_T FAR*             ptFrame;
  /* offset to data area in frame (not valid on SendCnf) */
  UINT32                                ulOffset;
  /* length of entire ethernet frame */
  UINT32                                ulLength;
  /* timestamp offset */
  UINT32                                ulTimestampOffset;
  /* port number (coding as in Send) */
  UINT32                                ulPortNo;
  /* result code of frame */
  UINT32                                ulErrorCode;
  /* send callback (only valid in first slot) */
  void FAR*                             fnSendCbk;
  /* send priority for flow control applications (0 = default value), only valid in first slot */
  UINT32                                ulSendPriority;
  /* multiple send confirmations accepted */
  EDD_BOOL                              fMultipleSendCnfs;
  /* handle to edd */
  void FAR*                             hEdd;
} EDD_COMMBLK_T;

#endif /* #ifndef __STRUCTS_EDD_H */
