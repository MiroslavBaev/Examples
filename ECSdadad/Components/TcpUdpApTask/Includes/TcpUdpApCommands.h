/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApCommands.h 1315 2015-09-14 14:43:13Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TcpUdpApCommands.h
**************************************************************************************/
#ifndef COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPCOMMANDS_H_
#define COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPCOMMANDS_H_

#include "TcpUdpApTask_Resources.h"



/* TCPIP_IP_CMD_SET_CONFIG */
TLR_RESULT
ApIpCmdSetConfigReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdSetConfigCnf( TCPIP_AP_TASK_RSC_T                  FAR*  ptRsc,
                     TCPIP_PACKET_IP_CMD_SET_CONFIG_CNF_T FAR*  ptPck );

/* TCPIP_IP_CMD_GET_CONFIG */
TLR_RESULT
ApIpCmdGetConfigReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdGetConfigCnf( TCPIP_AP_TASK_RSC_T                  FAR*  ptRsc,
                     TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_T FAR*  ptPck );


/* TCPIP_IP_CMD_SET_PARAM */
TLR_RESULT
ApIpCmdSetParamReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdSetParamCnf( TCPIP_AP_TASK_RSC_T                 FAR*  ptRsc,
                    TCPIP_PACKET_IP_CMD_SET_PARAM_CNF_T FAR*  ptPck );


/* TCPIP_IP_CMD_GET_PARAM */
TLR_RESULT
ApIpCmdGetParamReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdGetParamCnf( TCPIP_AP_TASK_RSC_T                 FAR*  ptRsc,
                    TCPIP_PACKET_IP_CMD_GET_PARAM_CNF_T FAR*  ptPck );


/* TCPIP_IP_CMD_GET_OPTIONS */
TLR_RESULT
ApIpCmdGetOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdGetOptionsCnf( TCPIP_AP_TASK_RSC_T                   FAR*  ptRsc,
                      TCPIP_PACKET_IP_CMD_GET_OPTIONS_CNF_T FAR*  ptPck );


/* TCPIP_IP_CMD_PING */
TLR_RESULT
ApIpCmdPingReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApIpCmdPingCnf( TCPIP_AP_TASK_RSC_T            FAR*  ptRsc,
                TCPIP_PACKET_IP_CMD_PING_CNF_T FAR*  ptPck );




/* TCPIP_TCP_UDP_CMD_OPEN */
TLR_RESULT
ApTcpUdpCmdOpenReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpUdpCmdOpenCnf( TCPIP_AP_TASK_RSC_T                 FAR*  ptRsc,
                    TCPIP_PACKET_TCP_UDP_CMD_OPEN_CNF_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_CLOSE */
TLR_RESULT
ApTcpUdpCmdCloseReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpUdpCmdCloseCnf( TCPIP_AP_TASK_RSC_T                  FAR*  ptRsc,
                     TCPIP_PACKET_TCP_UDP_CMD_CLOSE_CNF_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_CLOSE_ALL */
TLR_RESULT
ApTcpUdpCmdCloseAllReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpUdpCmdCloseAllCnf( TCPIP_AP_TASK_RSC_T                      FAR*  ptRsc,
                        TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_T FAR*  ptPck );


/* TCPIP_TCP_CMD_WAIT_CONNECT */
TLR_RESULT
ApTcpCmdWaitConnectReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpCmdWaitConnectCnf( TCPIP_AP_TASK_RSC_T                     FAR*  ptRsc,
                        TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_CNF_T FAR*  ptPck );


/* TCPIP_TCP_CMD_CONNECT */
TLR_RESULT
ApTcpCmdConnectReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpCmdConnectCnf( TCPIP_AP_TASK_RSC_T                FAR*  ptRsc,
                    TCPIP_PACKET_TCP_CMD_CONNECT_CNF_T FAR*  ptPck );


/* TCPIP_TCP_CMD_SEND */
TLR_RESULT
ApTcpCmdSendReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc,
                 TLR_UINT                  uiSendLen );

TLR_RESULT
ApTcpCmdSendCnf( TCPIP_AP_TASK_RSC_T             FAR*  ptRsc,
                 TCPIP_PACKET_TCP_CMD_SEND_CNF_T FAR*  ptPck );


/* TCPIP_UDP_CMD_SEND */
TLR_RESULT
ApUdpCmdSendReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc,
                 TLR_UINT                  uiSendLen );

TLR_RESULT
ApUdpCmdSendCnf( TCPIP_AP_TASK_RSC_T             FAR*  ptRsc,
                 TCPIP_PACKET_UDP_CMD_SEND_CNF_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION */
TLR_RESULT
ApTcpUdpCmdSetSockOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpUdpCmdSetSockOptionsCnf( \
                  TCPIP_AP_TASK_RSC_T                            FAR*  ptRsc,
                  TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION */
TLR_RESULT
ApTcpUdpCmdGetSockOptionsReq( TCPIP_AP_TASK_RSC_T FAR*  ptRsc );

TLR_RESULT
ApTcpUdpCmdGetSockOptionsCnf( \
                  TCPIP_AP_TASK_RSC_T                            FAR*  ptRsc,
                  TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_RECEIVE */
TLR_RESULT
ApTcpUdpCmdReceiveInd( TCPIP_AP_TASK_RSC_T                    FAR*  ptRsc,
                       TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_T FAR*  ptPck );



/* TCPIP_TCP_UDP_CMD_SHUTDOWN */
TLR_RESULT
ApTcpUdpCmdShutdownInd( TCPIP_AP_TASK_RSC_T                     FAR*  ptRsc,
                        TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_IND_T FAR*  ptPck );


/* TCPIP_TCP_UDP_CMD_RECEIVE_STOP */
TLR_RESULT
ApTcpUdpCmdReceiveStopInd( TCPIP_AP_TASK_RSC_T                         FAR*  ptRsc,
                           TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_STOP_IND_T FAR*  ptPck );


#endif /* COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPCOMMANDS_H_ */
