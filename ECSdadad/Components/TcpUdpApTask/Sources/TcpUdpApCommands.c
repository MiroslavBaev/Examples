/**********************************************************************************//**
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided  together with this
  project!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/
/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApCommands.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
\file TcpUdpApCommands.c
Contains needed commands given by <em>TCP IP - Packet Interface API 12 EN.pdf</em>.
Basis is example from
<a href="http://subversion01:8080/svn/Fieldbus/Fieldbus/TCPIP/tags/V2.1.30.0/Example/
ApTask_Customer/Sources/TcpipApTask_Process.c">
/svn/Fieldbus/Fieldbus/TCPIP/tags/V2.1.30.0/Example/ApTask_Customer/Sources/TcpipApTask_Process.c
</a>

**************************************************************************************/
#include "TcpUdpApCommands.h"
#include "TLR_Includes.h"       /* TLR INX includes       */
#include "TcpipTcpTask_Public.h"    /* Tcpip Task includes    */
#include "TLR_Results.h"

/*** Settings of AP task ***/

/* Modes (see revision above) */
/* #define AP_ECHO */

#define TCP_SERVER

/* Configuration values */
#define IP_ADDR_2         (0xC0A8D201)  /* Second IP address: 192.168.210.1    */
#define PORT_1            (1024)        /* Fist TCP/UDP port                    */
#define PORT_2            (1028)        /* Second TCP/UDP port                  */


/* Local configuration */
#define LOCAL_PORT        PORT_1        /* Local TCP/UDP port: PORT_1           */


/* Remote configuration */
#define REMOTE_IP_ADDR    IP_ADDR_2     /* IP address of remote host: IP_ADDR_2 */
#define REMOTE_PORT       PORT_2        /* TCP/UDP port of remote host: PORT_2  */

#define SET_TEST_DATA  /* return number of charakters received before */

/* TCPIP_IP_CMD_SET_PARAM */
TLR_RESULT
ApIpCmdSetParamReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_IP_CMD_SET_PARAM_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_ADD_ARP_ENTRY;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_IP_CMD_SET_PARAM_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulMode  = IP_PRM_ADD_ARP_ENTRY;

  ptPck->tData.unParam.tAddDelArpEntry.ulIpAddr = REMOTE_IP_ADDR;

  /* MAC address of REMOTE_IP_ADDR: 00-04-E2-C5-00-8A (Example!!) */
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[0] = 0x00;
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[1] = 0x04;
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[2] = 0xE2;
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[3] = 0xC5;
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[4] = 0x00;
  ptPck->tData.unParam.tAddDelArpEntry.abEthernetAddr[5] = 0x8A;

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApIpCmdSetParamCnf( TCPIP_AP_TASK_RSC_T                 FAR*  ptRsc,
                    TCPIP_PACKET_IP_CMD_SET_PARAM_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_IP_CMD_GET_PARAM */
TLR_RESULT
ApIpCmdGetParamReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_IP_CMD_GET_PARAM_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = \
                        TCPIP_DATA_IP_CMD_GET_PARAM_REQ_SIZE_GET_ARP_ENTRY_INDEX;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_IP_CMD_GET_PARAM_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulMode  = IP_PRM_GET_ARP_ENTRY_INDEX;
  ptPck->tData.unParam.tArpEntryIndex.ulIndex = 0;  /* First ARP cache entry */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}





/* TCPIP_IP_CMD_GET_OPTIONS */
TLR_RESULT
ApIpCmdGetOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_IP_CMD_GET_OPTIONS_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = 0;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_IP_CMD_GET_OPTIONS_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}



/* TCPIP_IP_CMD_PING */
TLR_RESULT
ApIpCmdPingReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_IP_CMD_PING_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_IP_CMD_PING_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_IP_CMD_PING_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulIpAddr  = REMOTE_IP_ADDR;
  ptPck->tData.ulTimeout = 1000;      /* 1 s           */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


/* TCPIP_TCP_UDP_CMD_OPEN */
TLR_RESULT
ApTcpUdpCmdOpenReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_UDP_CMD_OPEN_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_UDP_CMD_OPEN_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulIpAddr  = 0;     /* 0 = Bind socket to currently configured IP */
                                  /*     address                                */
  ptPck->tData.ulPort    = LOCAL_PORT;  /* 0 = Bind socket to next available    */
                                  /*     port in range 1024 ... 32257           */
#if defined( TCP_CLIENT ) || defined( TCP_SERVER )
  ptPck->tData.ulProtocol = TCP_PROTO_TCP;
#else
  ptPck->tData.ulProtocol = TCP_PROTO_UDP;
#endif

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpUdpCmdOpenCnf( TCPIP_AP_TASK_RSC_T                 FAR*  ptRsc,
                    TCPIP_PACKET_TCP_UDP_CMD_OPEN_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  if( TLR_S_OK == eRslt  )
  {
    ptRsc->tLoc.tTcpIpConfig.ulIpAddr = ptPck->tData.ulIpAddr;
    ptRsc->tLoc.ulPort                = ptPck->tData.ulPort;
    ptRsc->tLoc.ulProtocol            = ptPck->tData.ulProtocol;
    ptRsc->tLoc.ulSocket              = ptPck->tHead.ulDestId;
  }

  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_CLOSE */
TLR_RESULT
ApTcpUdpCmdCloseReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_UDP_CMD_CLOSE_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulTimeout = 0;  /* 0 = Default timeout (13 s) */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpUdpCmdCloseCnf( TCPIP_AP_TASK_RSC_T                  FAR*  ptRsc,
                     TCPIP_PACKET_TCP_UDP_CMD_CLOSE_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_CLOSE_ALL */
TLR_RESULT
ApTcpUdpCmdCloseAllReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, 0 );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulTimeout = 0; /* Use the individual socket's data send  */
                              /* timeout for TCP close operation        */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpUdpCmdCloseAllCnf( TCPIP_AP_TASK_RSC_T                      FAR*  ptRsc,
                        TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_TCP_CMD_WAIT_CONNECT */
TLR_RESULT
ApTcpCmdWaitConnectReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_CMD_WAIT_CONNECT_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulTimeoutSend    = 0; /* 0 = Default timeout (31 s)         */
  ptPck->tData.ulTimeoutListen  = 0; /* 0 = Wait until connection comes in */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpCmdWaitConnectCnf( TCPIP_AP_TASK_RSC_T                     FAR*  ptRsc,
                        TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  if( TLR_S_OK == eRslt  )
  {
    ptRsc->tLoc.ulRemoteIpAddr = ptPck->tData.ulIpAddr;
    ptRsc->tLoc.ulRemotePort   = ptPck->tData.ulPort;
  }

  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}



/* TCPIP_TCP_CMD_CONNECT */
TLR_RESULT
ApTcpCmdConnectReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_CMD_CONNECT_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_CMD_CONNECT_REQ_SIZE;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_CMD_CONNECT_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulIpAddr         = REMOTE_IP_ADDR;
  ptPck->tData.ulPort           = REMOTE_PORT;
  ptPck->tData.ulTimeoutSend    = 0; /* 0 = Default timeout (31 s) */
  ptPck->tData.ulTimeoutConnect = 0; /* 0 = Default timeout (31 s) */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


/* TCPIP_TCP_CMD_SEND */
TLR_RESULT
ApTcpCmdSendReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc,
                 TLR_UINT                  uiSendLen )
{
  TCPIP_PACKET_TCP_CMD_SEND_REQ_T*  ptPck;
  TLR_UINT                          uiIdx;            /* Data index     */


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_TCP_CMD_SEND_REQ_SIZE + uiSendLen;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_TCP_CMD_SEND_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulOptions  = TCP_SEND_OPT_PUSH;  /* Push flag */

#ifdef SET_TEST_DATA
  for( uiIdx = 0; uiIdx < uiSendLen; uiIdx++ )
  {
    ((TCPIP_PACKET_TCP_CMD_SEND_REQ_T*) ptPck)->tData.abData[uiIdx] \
                                                    = ptRsc->tLoc.bTestSndData++;
  }
#endif  /* #ifdef SET_TEST_DATA */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpCmdSendCnf( TCPIP_AP_TASK_RSC_T             FAR*  ptRsc,
                 TCPIP_PACKET_TCP_CMD_SEND_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_UDP_CMD_SEND */
TLR_RESULT
ApUdpCmdSendReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc,
                 TLR_UINT                  uiSendLen )
{
  TCPIP_PACKET_UDP_CMD_SEND_REQ_T*  ptPck;
  TLR_UINT                          uiIdx;            /* Data index     */


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen   = TCPIP_DATA_UDP_CMD_SEND_REQ_SIZE + uiSendLen;
  ptPck->tHead.ulId    = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta   = 0;
  ptPck->tHead.ulCmd   = TCPIP_UDP_CMD_SEND_REQ;
  ptPck->tHead.ulExt   = 0;
  ptPck->tHead.ulRout  = 0;

  ptPck->tData.ulIpAddr = REMOTE_IP_ADDR;
  ptPck->tData.ulPort     = REMOTE_PORT;
  ptPck->tData.ulOptions  = 0;

  for( uiIdx = 0; uiIdx < uiSendLen; uiIdx++ )  /* Set test data also without define of SEQUENCE_CHECK */
  {
    ((TCPIP_PACKET_UDP_CMD_SEND_REQ_T*) ptPck)->tData.abData[uiIdx] \
                                                    = ptRsc->tLoc.bTestSndData++;\
  }

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApUdpCmdSendCnf( TCPIP_AP_TASK_RSC_T             FAR*  ptRsc,
                 TCPIP_PACKET_UDP_CMD_SEND_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION */
TLR_RESULT
ApTcpUdpCmdSetSockOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen  = TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_SIZE;
  ptPck->tHead.ulId   = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta  = 0;
  ptPck->tHead.ulCmd  = TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ;
  ptPck->tHead.ulExt  = 0;
  ptPck->tHead.ulRout = 0;

  ptPck->tData.ulMode                = TCP_SOCK_SEND_TIMEOUT;
  ptPck->tData.unParam.ulTimeoutSend = 10000;  /* 10 s */

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}


TLR_RESULT
ApTcpUdpCmdSetSockOptionsCnf( \
                  TCPIP_AP_TASK_RSC_T                            FAR*  ptRsc,
                  TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool,ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION */
TLR_RESULT
ApTcpUdpCmdGetSockOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc )
{
  TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T*  ptPck;


  if( TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptPck ) != TLR_S_OK )
  {
    return( TLR_E_FAIL );
  }

  TLS_QUE_LINK_SET_NEW_DESTID( ptRsc->tRem.tQueTcpTask, ptRsc->tLoc.ulSocket );
  TLS_QUE_LINK_SET_PACKET_SRC( ptPck, ptRsc->tLoc.tLnkSrc );

  ptPck->tHead.ulLen  = TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_SIZE;
  ptPck->tHead.ulId   = ++ptRsc->tLoc.ulSndTcpId;
  ptPck->tHead.ulSta  = 0;
  ptPck->tHead.ulCmd  = TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_REQ;
  ptPck->tHead.ulExt  = 0;
  ptPck->tHead.ulRout = 0;

  ptPck->tData.ulMode = TCP_SOCK_SEND_TIMEOUT;

  if( TLS_QUE_SENDPACKET_FIFO( ptRsc->tRem.tQueTcpTask,
                               ptPck,
                               100                     ) != TLR_S_OK )
  {
    TLR_POOL_PACKET_RELEASE( ptRsc->tLoc.hPool, ptPck );
    return( TLR_E_FAIL );
  }

  return( TLR_S_OK );
}



/* TCPIP_TCP_UDP_CMD_RECEIVE */
TLR_RESULT
ApTcpUdpCmdReceiveInd( TCPIP_AP_TASK_RSC_T                    FAR*  ptRsc,
                       TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  if( ptPck->tHead.ulSrcId == ptRsc->tLoc.ulSocket )
  { /* Data received, copy to buffer */
    LIB_MEMCPY( &ptRsc->tLoc.abReceiveBuffer[0],
                    /* TLR_UINT8  abReceiveBuffer[TCPIP_MAX_TCP_UDP_DATA_CNT]; */
                &ptPck->tData.abData[0],
                (ptPck->tHead.ulLen - TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_SIZE) );

    ptRsc->tLoc.uiReceiveBufferLen = (ptPck->tHead.ulLen - \
                                        TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_SIZE);
  }
  /* else: Wrong socket handle */

  TLS_QUE_RETURNPACKET( ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_SHUTDOWN */
/* This function is never tested - only compiled!! */
TLR_RESULT
ApTcpUdpCmdShutdownInd( TCPIP_AP_TASK_RSC_T                     FAR*  ptRsc,
                        TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_IND_T FAR*  ptPck )
{
  TLR_RESULT                                     eRslt;
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_T FAR*  ptPckCloseAllCnf;


  eRslt = ApTcpUdpCmdCloseAllReq( ptRsc );

  if( TLR_S_OK == eRslt )
  { /* Command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ send successful */
    eRslt = TLR_QUE_WAITFORPACKET( ptRsc->tLoc.hQue,
                                   &ptPckCloseAllCnf,
                                   TLR_TIM_TIME_TO_TICK(10000) );
    if( TLR_S_OK == eRslt )
    {
      if( ptPckCloseAllCnf->tHead.ulCmd == TCPIP_TCP_UDP_CMD_CLOSE_ALL_CNF )
      {
        ApTcpUdpCmdCloseAllCnf( ptRsc, ptPckCloseAllCnf );
      }
    }
  }

  TLS_QUE_RETURNPACKET( ptPck );

  return( eRslt );
}




/* TCPIP_TCP_UDP_CMD_RECEIVE_STOP */
TLR_RESULT
ApTcpUdpCmdReceiveStopInd(
                          TCPIP_AP_TASK_RSC_T                         FAR*  ptRsc,
                          TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_STOP_IND_T FAR*  ptPck )
{
  TLR_RESULT  eRslt = ptPck->tHead.ulSta;


  if( ptPck->tHead.ulSrcId == ptRsc->tLoc.ulSocket )
  { /* End-of-data marker received - no further data receive */
    if( ptPck->tHead.ulSta == TLR_E_TCP_ERR_CONN_CLOSED )
    { /* Graceful close */
    }
    else if( ptPck->tHead.ulSta == TLR_E_TCP_ERR_CONN_RESET )
    { /* Hard close */
    }
  }
  /* else: Wrong socket handle */

  TLS_QUE_RETURNPACKET( ptPck );

  return( eRslt );
}
