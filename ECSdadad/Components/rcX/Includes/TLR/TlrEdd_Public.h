/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TlrEdd_Public.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR EDD - public declarations of task

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_EDD_PUBLIC_H
#define __TLR_EDD_PUBLIC_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/****************************************************************************************
* Tlr Edd, constants */

/* length */
#define TLR_EDD_LEN_BUFFER      (1520)
#define TLR_EDD_LEN_MAC         (6)
#define TLR_EDD_LEN_TYPE        (2)
#define TLR_EDD_LEN_DATA_MIN    (40)
#define TLR_EDD_LEN_DATA_MAX    (1490)
#define TLR_EDD_LEN_FRM_MIN     (40)
#define TLR_EDD_LEN_FRM_MAX     (1514)


/* filter */
#define TLR_EDD_FILTER_DIRECTED       (0x0001) /* nur Frames mit eigener MAC-Adresse */
#define TLR_EDD_FILTER_MULTICAST      (0x0002) /* Frames mit Multicast-Adressen */
#define TLR_EDD_FILTER_MULTICAST_ALL  (0x0004) /* Frames mit allen Multicast-Adressen */
#define TLR_EDD_FILTER_BROADCAST      (0x0008) /* Frames mit Broadicast-Adressen */



/****************************************************************************************
* Tlr Edd, packets */

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(TLR_EDD_PUBLIC)
#endif



/*
 * buffer to send/receive frames
 *  includes TLR packet header
 *  includes additional information about frame (length/offset/...)
 */
struct EDD_FRAME_BUFFER_Ttag 
{ 
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT32  ulLenFrm;       /* length of frame data */
  TLR_UINT32  ulOffset;       /* offset to frame data */
  TLR_UINT32  ulNext;         /* pointer to next packet EDD_FRAME_PACKET_Ttag */
  union
  {
    TLR_UINT8 abFrm[TLR_EDD_LEN_BUFFER];  /* frame data, internal buffer */
    TLR_VOID* pvData;                     /* frame data, external buffer */
  } data;
};

typedef struct EDD_FRAME_BUFFER_Ttag                  TLR_EDD_FRM_PCK_T;
typedef struct EDD_FRAME_BUFFER_Ttag                  TLR_EDD_BUFFER_T;


/*
 * callback functionality of EDD
 *    - receive callback
 *    - send complete callback
 */
typedef TLR_VOID (*TLR_EDD_CLB_RECV)(TLR_VOID* pvHdl, TLR_EDD_BUFFER_T FAR* FAR* pptEddBuff);
typedef TLR_VOID (*TLR_EDD_CLB_SEND)(TLR_EDD_BUFFER_T FAR* ptEddBuff);



/* 
 * Structures of all Request/Confirmation commands the task is able to send and receive
 *
 * Request and Confirmation Packets TLR_PACKET_EDD_xx_REQ/CNF
 * (xx = Command)
 *
 * Use the same order as the commands in TLR_Commands.h
 * TLR_EDD_xx_REQ/CNF (xx = Command)!
 */

/* request packets */

struct TLR_EDD_REGISTER_REQ_Ttag              /* request, register */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_EDD_CLB_RECV  fnRecv;   /* receive callback */
  TLR_VOID*         pvHdl;    /* application handle used to receive frames */
  TLR_UINT16        usEthII;  /* ethernet II type */
};

struct TLR_EDD_UNREGISTER_REQ_Ttag            /* request, unregister */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT32  ulIdEdd;        /* registered EDD handle */
};

struct TLR_EDD_GET_MACADDRESS_REQ_Ttag        /* request, get MAC address */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
};

struct TLR_EDD_GET_FILTER_REQ_Ttag            /* request, get filter */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
};

struct TLR_EDD_SET_MACADDRESS_REQ_Ttag        /* request, set MAC address */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT8   abMac[TLR_EDD_LEN_MAC];   /* MAC address */
};

struct TLR_EDD_SET_FILTER_REQ_Ttag            /* request, set filter */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT32  ulFilter;       /* filter */
};



/* confirmation packets */

struct TLR_EDD_REGISTER_CNF_Ttag              /* confirmation, register */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT32  ulIdEdd;        /* registered EDD handle */
};

struct TLR_EDD_UNREGISTER_CNF_Ttag            /* confirmation, unregister */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
};

struct TLR_EDD_GET_MACADDRESS_CNF_Ttag        /* confirmation, get MAC address */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT8   abMac[TLR_EDD_LEN_MAC];   /* MAC address */
};

struct TLR_EDD_GET_FILTER_CNF_Ttag            /* confirmation, get filter */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
  TLR_UINT32  ulFilter;       /* filter */
};

struct TLR_EDD_SET_MACADDRESS_CNF_Ttag        /* confirmation, set MAC address */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
};

struct TLR_EDD_SET_FILTER_CNF_Ttag            /* confirmation, set filter */
{
  TLR_PACKET_HEADER;          /* packet header, defines */
};



typedef struct TLR_EDD_REGISTER_REQ_Ttag              TLR_EDD_REG_REQ_T;
typedef struct TLR_EDD_REGISTER_CNF_Ttag              TLR_EDD_REG_CNF_T;
typedef struct TLR_EDD_UNREGISTER_REQ_Ttag            TLR_EDD_UNREG_REQ_T;
typedef struct TLR_EDD_UNREGISTER_CNF_Ttag            TLR_EDD_UNREG_CNF_T;
typedef struct TLR_EDD_GET_MACADDRESS_REQ_Ttag        TLR_EDD_GET_ADDR_REQ_T;
typedef struct TLR_EDD_GET_MACADDRESS_CNF_Ttag        TLR_EDD_GET_ADDR_CNF_T;
typedef struct TLR_EDD_GET_FILTER_REQ_Ttag            TLR_EDD_GET_FILTER_REQ_T;
typedef struct TLR_EDD_GET_FILTER_CNF_Ttag            TLR_EDD_GET_FILTER_CNF_T;
typedef struct TLR_EDD_SET_MACADDRESS_REQ_Ttag        TLR_EDD_SET_ADDR_REQ_T;
typedef struct TLR_EDD_SET_MACADDRESS_CNF_Ttag        TLR_EDD_SET_ADDR_CNF_T;
typedef struct TLR_EDD_SET_FILTER_REQ_Ttag            TLR_EDD_SET_FILTER_REQ_T;
typedef struct TLR_EDD_SET_FILTER_CNF_Ttag            TLR_EDD_SET_FILTER_CNF_T;



struct TLR_EDD_PACKET_REGISTER_Ttag           /* packets, register */
{
  union
  {
    TLR_EDD_REG_REQ_T tReq;
    TLR_EDD_REG_CNF_T tCnf;
  };
};

struct TLR_EDD_PACKET_UNREGISTER_Ttag         /* packets, unregister */
{
  union
  {
    TLR_EDD_UNREG_REQ_T tReq;
    TLR_EDD_UNREG_CNF_T tCnf;
  };
};

struct TLR_EDD_PACKET_GET_MACADDRESS_Ttag     /* packets, get MAC Address */
{
  union
  {
    TLR_EDD_GET_ADDR_REQ_T tReq;
    TLR_EDD_GET_ADDR_CNF_T tCnf;
  };
};

struct TLR_EDD_PACKET_GET_FITLER_Ttag         /* packets, get filter */
{
  union
  {
    TLR_EDD_GET_FILTER_REQ_T tReq;
    TLR_EDD_GET_FILTER_CNF_T tCnf;
  };
};

struct TLR_EDD_PACKET_SET_MACADDRESS_Ttag     /* packets, set MAC Address */
{
  union
  {
    TLR_EDD_SET_ADDR_REQ_T tReq;
    TLR_EDD_SET_ADDR_CNF_T tCnf;
  };
};

struct TLR_EDD_PACKET_SET_FITLER_Ttag         /* packets, set filter */
{
  union
  {
    TLR_EDD_SET_FILTER_REQ_T tReq;
    TLR_EDD_SET_FILTER_CNF_T tCnf;
  };
};



typedef struct TLR_EDD_PACKET_REGISTER_Ttag           TLR_EDD_PACK_REG_T;
typedef struct TLR_EDD_PACKET_UNREGISTER_Ttag         TLR_EDD_PACK_UNREG_T;
typedef struct TLR_EDD_PACKET_GET_MACADDRESS_Ttag     TLR_EDD_PACK_GET_ADDR_T;
typedef struct TLR_EDD_PACKET_GET_FITLER_Ttag         TLR_EDD_PACK_GET_FITLER_T;
typedef struct TLR_EDD_PACKET_SET_MACADDRESS_Ttag     TLR_EDD_PACK_SET_ADDR_T;
typedef struct TLR_EDD_PACKET_SET_FITLER_Ttag         TLR_EDD_PACK_SET_FITLER_T;



/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(TLR_EDD_PUBLIC)
#endif



/***************************************************************************************/



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_EDD_PUBLIC_H */
