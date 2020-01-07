/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft f�r Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: TcpipTcpTask_Functionlist.h 31832 2013-02-01 12:39:32Z Eric $

  Description:
    Task Tcpip TcpTask - function list to enter or to leave a task

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-04-06  NC            added configurable filtering for ARP and IP frames
                              (Mantis ID 0013202)

    2010-09-21  NC            Added EIF mode TCPIP_SRT_EIF_MODE_PORT_FILTER_3
                              (Mantis ID 0007875)

    2010-05-26  NC            File created.

******************************************************************************/


#ifndef __TCPIP_TCP_TASK_FUNCTIONLIST_H
#define __TCPIP_TCP_TASK_FUNCTIONLIST_H



/****************************************************************************************
* Tcpip TcpTask, function list */

TLR_RESULT
TaskExit_TcpipTcpTask( TLR_VOID FAR*  pvRsc );

TLR_VOID
TaskLeave_TcpipTcpTask( TLR_VOID FAR*  pvLeaveParams );

TLR_VOID
TaskEnter_TcpipTcpTask( TLR_VOID FAR*  pvStartParams );




/* ---------------------------------------------------------------------------- */
/* Limits of TCPIP_STARTUPPARAMETER_VERSION_5  5 (TCP/IP stack V2.0.16.0)       */
/* ---------------------------------------------------------------------------- */

#define TCPIP_STARTUPPARAMETER_VERSION_6  6   /* ATTENTION: If you get here a   */
      /* compiler error because of new name of define (e.g. _3 --> _4), check   */
      /* startup parameters for changes/extensions!!                            */
      /* E.g, version 4 is because of incompatible changes in struct            */
      /* TCPIP_TCP_TASK_SRT_EIF_T (startup parameter ptEif)                     */


/*** Queue, pool element sizes ***/
/* Min/Default/Max TCP/IP stacks process queue size for AP packets */
/* (ulQueElemCntAp)                                                */
#define TCPIP_SRT_QUE_ELEM_CNT_AP_MIN           (4)
#define TCPIP_SRT_QUE_ELEM_CNT_AP_DEFAULT       (32)
#define TCPIP_SRT_QUE_ELEM_CNT_AP_MAX           (1024)  /* 8 per socket max     */
                                                        /* count (128 *8)       */

/* Min/Default/Max pool element count (ulPoolElemCnt) */
#define TCPIP_SRT_POOL_ELEM_CNT_MIN             (4)
#define TCPIP_SRT_POOL_ELEM_CNT_DEFAULT         (64)    /* Suggestion: 4  per   */
      /* (TCPIP_SRT_SOCKET_MAX_CNT_DEFAULT * 4)            socket               */
#define TCPIP_SRT_POOL_ELEM_CNT_MAX             (4096)  /* Maximum   : 32 per   */
      /* (TCPIP_SRT_SOCKET_MAX_CNT_MAX     * 8)            socket               */


/*** TCP/IP Stacks configuration ***/
/* Start flags (ulStartFlags) */
#define TCPIP_SRT_FLAG_DBM                      (0x00000001L) /* Use DBM/NXD    */
      /* database CONFIG.DBM/CONFIG.NXD. Otherwise, the stack must be           */
      /* configured via TCPIP_IP_CMD_SET_CONFIG command                         */

#define TCPIP_SRT_FLAG_DBM_ETHERNET_ADDR        (0x00000002L) /* Use MAC        */
      /* address from DBM/NXD database table ETHERNET. Otherwise, the MAC       */
      /* address comes from EDD. Conditon: TCPIP_SRT_FLAG_DBM must be set also  */

      /* !!Add new flags also by startup-parameter check in module              */
      /* TcpipTcpTask_Resources.c, function                                     */
      /* TaskResource_TcpipTcpTask_InitLocal()!!                                */

#define TCPIP_SRT_FLAG_FAST_START               (0x00000004L) /* Activate fast  */
      /* start of TCP/IP stack (suppress the Gratuitous ARPs)                   */
      /* IMPORTANT!!!: Do not enable fast startup and ACD simultaneously        */
#define TCPIP_SRT_FLAG_KEEP_ALIVE_PATCH         (0x00000008L) /* Activate       */
      /* answer, if we receive wrong keep-alive packets without any flags set   */

#define TCPIP_SRT_FLAG_ACTIVATE_ACD             (0x00000010L) /* Activate       */
      /* address conflict detection */
      /* IMPORTANT!!!: Do not enable fast startup and ACD simultaneously        */
/* ACD defense options: when ACD is active, one of these options need to be set */
#define TCPIP_SRT_FLAG_ACD_DEFEND_DEF           (0x00000020L) /* Activates      */
      /* ACD option to defend ip address in any case                            */
#define TCPIP_SRT_FLAG_ACD_DEFEND_COND          (0x00000040L) /* Activates      */
      /* ACD option to defend the ip address with the condition, that there was */
      /* no ip address conflict within the last 10 seconds                      */
#define TCPIP_SRT_FLAG_ACD_NO_DEFENSE           (0x00000080L) /* Activates      */
      /* ACD option to drop the ip address in case of a conflict                */
#define TCPIP_SRT_FLAG_DISABLE_NET_IDENT        (0x00000100L)     
      /* Disables NetIdent protocol */
        
/* Min/Default/Max Cycletime of "TCP_UDP" task in ms (ulTcpCycleEvent) */
#define TCPIP_SRT_TCP_CYCLE_EVENT_MIN           (5)
#define TCPIP_SRT_TCP_CYCLE_EVENT_DEFAULT       (10)
#define TCPIP_SRT_TCP_CYCLE_EVENT_MAX           (20)

/* Min/Default/Max count of free queue elements (ulQueFreeElemCnt) */
#define TCPIP_SRT_QUE_FREE_ELEM_CNT_MIN         (4)
#define TCPIP_SRT_QUE_FREE_ELEM_CNT_DEFAULT     (128)   /* Default (Suggestion):*/
      /* 8 per socket                                                           */
#define TCPIP_SRT_QUE_FREE_ELEM_CNT_MAX         (4096)  /* Maximum: 32 per      */
      /* socket max count (128 * 32)                                            */

/* Min/Default/Max socket count (ulSocketMaxCnt) */
#define TCPIP_SRT_SOCKET_MAX_CNT_MIN            (1)
#define TCPIP_SRT_SOCKET_MAX_CNT_DEFAULT        (16)
#define TCPIP_SRT_SOCKET_MAX_CNT_MAX            (128)

/* Min/Default/Max size of Number of entries in ARP cache (ulArpCacheSize) */
#define TCPIP_SRT_ARP_CACHE_SIZE_MIN            (16)
#define TCPIP_SRT_ARP_CACHE_SIZE_DEFAULT        (64)    /* Default (Suggestion):*/
      /* 4 per socket, Depends on the host count                                */
#define TCPIP_SRT_ARP_CACHE_SIZE_MAX            (512)   /* Maximum: 4 per       */
      /* socket max count (128 * 4)                                             */


/*** EDD ***/
/* Min/Default/Max  queue/pool element count (ulEddQuePoolElemCnt) */
#define TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_MIN     (4)
#define TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_DEFAULT (32)
#define TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_MAX     (1024)  /* 8 per socket max     */
      /* count (128 *8)                                                         */

/* Min/Default/Max count of maximum outgoing EDD buffers (ulEddOutBufMaxCnt) */
#define TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_MIN       (1)
#define TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_DEFAULT   (10)    /* If this TCP/IP       */
      /* stacks instance is the only EDD user, we can use all 20 buffers of EDD */
      /* on netX (but these buffers are used for data send and receive - so we  */
      /* use per default only the half!)                                        */
      /* Otherwise, we must share the EDD buffers with other stack(s) of this   */
      /* instance                                                               */
#define TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_MAX       (20)    /* Maximum buffer count */
      /* of netX HAL EDD                                                        */

/*** EIF (Ethernet interface) ***/
/* EDD instance (ulEddInstance)                                                 */
#define TCPIP_SRT_EIF_EDD_INSTANCE_MIN          (0)
#define TCPIP_SRT_EIF_EDD_INSTANCE_MAX          (3)

/* Modes (ulEifMode)                                                            */
/*#define TCPIP_SRT_EIF_MODE_PORT_FILTER          (1) Only for V2.0.13.0!!      */
#define TCPIP_SRT_EIF_MODE_PORT_FILTER_2        (2) /* V2.0.14.0 and newer. The */
      /* new port filter mode is because of an incompatible change in struct    */
      /* TCPIP_TCP_TASK_SRT_EIF_T!!                                             */
#define TCPIP_SRT_EIF_MODE_PORT_FILTER_3        (3) /* Same as                  */
      /* TCPIP_SRT_EIF_MODE_PORT_FILTER_2, but netX stack process also ICMP and */
      /* IGMP packets to the own IP address                                     */

/* Flags (ulEifFlags)                                                           */
#define TCPIP_SRT_EIF_FLAG_EIF_REGISTER_RUN_TIME  (0x00000001L) /* Activate     */
      /* run-time registration of Ethernet interface                            */

/* Min/Default/Max for port range (ulEifPortStart, ulEifPortEnd)                */
#define TCPIP_SRT_EIF_PORT_MIN                  (1024)
#define TCPIP_SRT_EIF_PORT_MAX                  (0xFFFF)
#define TCPIP_SRT_EIF_PORT_DEFAULT_START        (0xE000)
#define TCPIP_SRT_EIF_PORT_DEFAULT_END          (0xEFFF)

/* Min/Default/Max count of EIF ports to filter for netX (ulEifPortNmb)         */
#define TCPIP_SRT_EIF_PORT_NMB_MIN              (0)
#define TCPIP_SRT_EIF_PORT_NMB_DEFAULT          (0)   /* 0 = Filter is off      */
#define TCPIP_SRT_EIF_PORT_NMB_MAX              (20)

/*** ARP ***/
/* Min/Default/Max of ARP cache timeout (ulArpTimeoutCache) in seconds          */
/* Remark: found in www: Dynamic ARP cache entries persist for 2-20 minutes,    */
/* depending on the system - so be carefull with too small/big values!          */
/* TCPIP_SRT_ARP_TIMEOUT_CACHE_DEFAULT is the suggestion!                       */
#define TCPIP_SRT_ARP_TIMEOUT_CACHE_MIN         (60)    /* 1 minute             */
#define TCPIP_SRT_ARP_TIMEOUT_CACHE_DEFAULT     (600)   /* 10 minutes           */
#define TCPIP_SRT_ARP_TIMEOUT_CACHE_MAX         (3600)  /* 1 hour               */

/*** NetLoad Limiter ***/
/* Maximum number of frames per system tick the tcp ip stack shall handle       */
#define TCPIP_SRT_NETLOAD_MAXFRAMESPERTICK_DEFAULT    (10) /* 6 Frames           */
/* Maximum number of unprocessed non-multicast arp frames in receive queue.
 * Usually responses to our own ARP requests                                    */
#define TCPIP_SRT_NETLOAD_MAXPENDING_ARP_DEFAULT      (6) /* 6 Frames           */

/* Maximum number of unprocessed multicast arp frames in receive queue. Usually
 * incoming ARP requests                                                        */
#define TCPIP_SRT_NETLOAD_MAXPENDING_MCASTARP_DEFAULT (4) /* 4 Frames           */

/* Maximum number of unprocessd non-multicast ip frames in receive queue.       */
#define TCPIP_SRT_NETLOAD_MAXPENDING_IP_DEFAULT       (10) /* 10 Frames         */

/* Maximum number of unprocessd multicast ip frames in receive queue.            */
#define TCPIP_SRT_NETLOAD_MAXPENDING_MCASTIP_DEFAULT  (5)  /* 5 Frames          */

/* Sub structure for EIF (Ethernet interface, ETH_INTF task) */
typedef struct TCPIP_TCP_TASK_SRT_EIF_Ttag
{
  TLR_STR FAR*  pszEddName; /* EDD name of ETH_INTF related EDD instance        */
                          /* (default is "ETHERNET_2PORT")                      */
  TLR_UINT32    ulEddInstance;  /* Instance of ETH_INTF related EDD (Must fit   */
                          /* with ulEddInstance of ETH_INTF startup parameter   */
                          /* ETH_INTF_STARTUPPARAMETER_T) Default is 1 (0 is    */
                          /* the normal EDD of TCP/IP stack)                    */
                          /* See also Drv_Edd.c/TcpipTcpTask_EddHalIntf.c       */

  TLR_STR FAR*  pszEifEthIntfName;  /* Ethernet interface task name (default is */
                          /* "ETH_INTF")                                        */

  TLR_UINT32    ulEifMode;  /* (Filter) mode (for future use, at the moment     */
                          /* only TCP/UDP port filter)                          */
                          /* See TCPIP_SRT_EIF_MODE_xx                          */

  TLR_UINT32    ulEifFlags; /* Flags, see TCPIP_SRT_EIF_FLAG_xx                 */

  TLR_UINT32    ulEifPortStart; /* TCP/UDP-Port range, start port               */
  TLR_UINT32    ulEifPortEnd;   /* TCP/UDP-Port range, end port                 */
                          /* Range: TCPIP_SRT_EIF_PORT_MIN ...                  */
                          /*        TCPIP_SRT_EIF_PORT_MAX                      */

  TLR_UINT32    ulEifReserved1; /* Reserved 1                                   */
  TLR_UINT32    ulEifReserved2; /* Reserved 2                                   */
  TLR_UINT32    ulEifReserved3; /* Reserved 3 (or use as pointer to further     */
                                /* parameters!?)                                */

  /* For other filter modes, use an union ... */
  union
  {
    struct  /* TCPIP_SRT_EIF_MODE_PORT_FILTER,TCPIP_SRT_EIF_MODE_PORT_FILTER_2/_3   */
    {
      TLR_UINT32    ulEifPortNmb; /* Number of TCP/UDP-Ports and port list to       */
                              /* filter for netX                                    */
                              /* Range: TCPIP_SRT_EIF_PORT_NMB_MIN ...              */
                              /*        TCPIP_SRT_EIF_PORT_NMB_MAX                  */

      TLR_UINT16    ausEifPortList[TCPIP_SRT_EIF_PORT_NMB_MAX]; /* EIF port list    */
                              /* The ports fo filter are element [0] ...            */
                              /* [ulEifPortNmb -1], if ulEifPortNmb is greater than */
                              /* zero                                               */
                              /* TCPIP_SRT_EIF_PORT_NMB_MAX must be equal, so the   */
                              /* array size is a multiple of DWORDs!                */
    } tPf;  /* tPf = Port filter */

    /* struct ... add further structs tXxx */

  } unMode; /* ulEifMode         */

} TCPIP_TCP_TASK_SRT_EIF_T;


typedef struct TCPIP_TCP_TASK_STARTUPPARAMETER_Ttag
{
  TLR_UINT32  ulTaskIdentifier;     /* task identifier see TLR_TaskIdentifier.h */
  TLR_UINT32  ulParamVersion;       /* structure version                        */


  /* -------------------------------------------------------------------------- */
  /* TCPIP_STARTUPPARAMETER_VERSION_5  5   (TCP/IP stack V2.0.16.0)             */
  /* -------------------------------------------------------------------------- */

  /*** Queue, pool element sizes ***/
  TLR_UINT32    ulQueElemCntAp; /* TCP/IP stacks process queue size for AP      */
                          /* packets                                            */
                          /* Remark: The real queue size is this value plus     */
                          /*         startup-parameter ulEddQuePoolElemCnt (EDD)*/
                          /*         plus 3 (reserve)                           */
                          /*         (ulQueElemCntAp + ulEddQuePoolElemCnt + 3) */
                          /* Range: TCPIP_SRT_QUE_ELEM_CNT_AP_MIN ...           */
                          /*        TCPIP_SRT_QUE_ELEM_CNT_AP_MAX               */

  TLR_UINT32    ulPoolElemCnt;  /* Size of pool elements for indication packets */
                          /* to AP. One pool element allocates (approx.) 1524   */
                          /* bytes                                              */
                          /* Range: TCPIP_SRT_POOL_ELEM_CNT_MIN  ...            */
                          /*        TCPIP_SRT_POOL_ELEM_CNT_MAX                 */


  /*** TCP/IP Stacks configuration ***/
  TLR_UINT32    ulStartFlags;   /* Start flags (see TCPIP_SRT_FLAG_xx above)    */

  TLR_UINT32    ulTcpCycleEvent;  /* Cycletime of "TCP_UDP" task in ms - call   */
                          /* intervall of functions like IpTick(),              */
                          /* tcp_Retransmitter, UdpTick(), TimerTick(), ...     */
                          /* Must be greater or equal the OS cycletime          */
                          /* ptRsc->tLoc.ulTcpOsCycleTime!                      */
                          /* Range: TCPIP_SRT_TCP_CYCLE_EVENT_MIN ...           */
                          /*        TCPIP_SRT_TCP_CYCLE_EVENT_MAX               */

  TLR_UINT32    ulQueFreeElemCnt; /* Count of free queue elements (module       */
                          /* TcpipQueue.c) This is the list of free queue       */
                          /* elements to hold AP requests temporarily over all  */
                          /* sockets.                                           */
                          /* Range: TCPIP_SRT_QUE_FREE_ELEM_CNT_MIN ...         */
                          /*        TCPIP_SRT_QUE_FREE_ELEM_CNT_MAX             */

  TLR_UINT32    ulSocketMaxCnt; /* Count of sockets, the TCP/IP stack allocates */
                          /* fix while startup-sequence. This socket count can  */
                          /* be used simultaneous for TCP or UDP communication. */
                          /* Every socket allocates sizeof(tcp_Socket) (2236)   */
                          /* bytes. The most space needs the receive buffer     */
                          /* abRecvBuf[TCP_RECV_BUF_SIZE] with 2048 bytes       */
                          /* Range: TCPIP_SRT_SOCKET_MAX_CNT_MIN ...            */
                          /*        TCPIP_SRT_SOCKET_MAX_CNT_MAX                */

  TLR_UINT32    ulArpCacheSize; /* Number of entries in ARP cache, must be      */
                          /* multiple of 16                                     */
                          /* Range: TCPIP_SRT_ARP_CACHE_SIZE_MIN ...            */
                          /*        TCPIP_SRT_ARP_CACHE_SIZE_MAX                */


  /*** EDD ***/
  TLR_STR FAR*  pszEddName;     /* EDD name                                     */

  TLR_UINT32    ulEddQuePoolElemCnt;  /* EDD: Sizes of:                         */
                          /*        - queue for received EDD packets            */
                          /*          and                                       */
                          /*        - resource pool for received EDD packets    */
                          /*       (both must have the same size)               */
                          /* Range: TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_MIN ...     */
                          /*        TCPIP_SRT_EDD_QUE_POOL_ELEM_CNT_MAX         */

  TLR_UINT32    ulEddOutBufMaxCnt;  /* Maximum count of outgoing EDD buffers,   */
                          /* the TCP/IP stack can use simultaneous              */
                          /* Range: TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_MIN ...       */
                          /*        TCPIP_SRT_EDD_OUT_BUF_MAX_CNT_MAX           */

  /* -------------------------------------------------------------------------- */
  /* appended TCPIP_STARTUPPARAMETER_VERSION 2 parameter (TCP/IP stack version  */
  /* V2.0.12.0) - special EIF version parameter!!                               */
  /* -------------------------------------------------------------------------- */

  /*** EIF (Ethernet Interface) ***/
  TCPIP_TCP_TASK_SRT_EIF_T FAR*  ptEif;

  /* -------------------------------------------------------------------------- */
  /* appended TCPIP_STARTUPPARAMETER_VERSION 3 parameter (TCP/IP stack version  */
  /* V2.0.13.0) - ARP cache timeout parameter!!                                 */
  /* -------------------------------------------------------------------------- */

  /*** ARP ***/
  TLR_UINT32    ulArpTimeoutCache;  /* ARP cache timeout (seconds)              */

  /* -------------------------------------------------------------------------- */
  /* appended TCPIP_STARTUPPARAMETER_VERSION_5 parameter (TCP/IP stack version  */
  /* V2.0.16.0) - netX hardware name (e.g. used for NetIdent protocol)!!        */
  /* -------------------------------------------------------------------------- */

  /*** netX hardware name ***/
  TLR_STR FAR*  pszHwNameNetX;     /* netX hardware name                        */
                          /* NULL or "": The internal hardware names are used   */
                          /* otherwise : This hardware name is used ("netXXX")  */
                          /* String length = 1 ... 63 characters                */

  /* !Append further starparameters here - don't change the existing structure! */
  /* ...                                                                        */

  /* -------------------------------------------------------------------------- */
  /* appended TCPIP_STARTUPPARAMETER_VERSION_6 parameter (TCP/IP stack version  */
  /* V2.1.11.0) - NetLoad Parameters !!        */
  /* -------------------------------------------------------------------------- */

  /*** NetLoad Limiter ***/
  TLR_UINT32    ulNetLoadMaxFramesPerTick;      /*  Maximum number of frames    */
                                 /* per systemtick the tcpip stack shall handle */

  TLR_UINT32    ulNetLoadMaxPendingARP;         /*  Maximum number of received  */
                            /* and still pending (not yet processed) ARP frames */

  TLR_UINT32    ulNetLoadMaxPendingMCastARP;    /*  Maximum number of received  */
                  /* and still pending (not yet processed) ARP multicast frames */

  TLR_UINT32    ulNetLoadMaxPendingIP;          /*  Maximum number of received  */
                             /* and still pending (not yet processed) ip frames */

  TLR_UINT32    ulNetLoadMaxPendingMCastIP;     /*  Maximum number of received  */
                   /* and still pending (not yet processed) multicast ip frames */
} TCPIP_TCP_TASK_STARTUPPARAMETER_T;




/***************************************************************************************/

#endif /* #ifndef __TCPIP_TCP_TASK_FUNCTIONLIST_H */

