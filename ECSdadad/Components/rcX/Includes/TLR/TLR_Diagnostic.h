/******************************************************************************

  Copyright (C) 2010-2011 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Diagnostic.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR diagnostic header (automatically generated header)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-08-18  NC            File updated after rebuild from latest MC files.
    2010-06-06  NC            File updated after rebuild from latest MC files.
    2010-04-22  NC            File created.

******************************************************************************/


#ifdef DO_NOT_INCLUDE_THIS_HEADER_IN_TLR_AUTOGEN_HEADERS
#ifndef __TLR_FACILITIES_H
#define __TLR_FACILITIES_H



/*****************************************************************************/
/*  type definition */
/*****************************************************************************/



/*****************************************************************************/
/*  bit masks */
/*****************************************************************************/

/* error code construction macro definitions for backward compatibility with older TLR versions */
#define  TLR_STATUS_BIT_TASK_INSTANCE(n)     ((n << 28) & 0x30000000)
#define  TLR_STATUS_BIT_TASK_IDENTIFIER(n)   ((n << 16) & 0x0FFF0000)
#define  TLR_STATUS_BIT_SEVERITY_NAME(n)     ((n << 30) & 0xC0000000)


/*****************************************************************************/
/*                                                                           */
/* TLR error codes are 32 bit values layed out as follows:                   */
/*                                                                           */
/*  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0          */
/*  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0          */
/* +---+-+-+-----------------------+-------------------------------+         */
/* |Sev|C|R|       Facility        |             Code              |         */
/* +---+-+-+-----------------------+-------------------------------+         */
/*                                                                           */
/* where                                                                     */
/*                                                                           */
/* Code     - is the facility's status code                                  */
/* Facility - is the facility code                                           */
/* R        - is a reserved bit                                              */
/* C        - is the customer code flag                                      */
/* Sev      - is the severity code                                           */
/*              00 - success                                                 */
/*              01 - informational                                           */
/*              10 - warning                                                 */
/*              11 - error                                                   */
/*                                                                           */
/*****************************************************************************/


/*  Symbol definitions for the facility codes */
#define TLR_UNQ_NR_VIRTUALSWITCH         0x27
#define TLR_UNQ_NR_VARAN_CLIENT_AP       0x9D
#define TLR_UNQ_NR_VARAN_CLIENT          0x9C
#define TLR_UNQ_NR_USER_AREA             0xFF0
#define TLR_UNQ_NR_USB_TLRROUTER         0x44
#define TLR_UNQ_NR_UDP_DEBUG_CLIENT      0x1B
#define TLR_UNQ_NR_TLR_TIMER             0x2
#define TLR_UNQ_NR_TLR_ROUTER            0x2F
#define TLR_UNQ_NR_TCPIP_TCP_AP          0x94
#define TLR_UNQ_NR_TCPIP_TCP             0x8
#define TLR_UNQ_NR_TCPIP_SOCKIF          0x74
#define TLR_UNQ_NR_TCPIP_IP              0x7
#define TLR_UNQ_NR_TCP_CONNECTOR         0x86
#define TLR_UNQ_NR_SSIO_AP               0x76
#define TLR_UNQ_NR_SSIO                  0x75
#define TLR_UNQ_NR_SNMP_SERVER           0x3B
#define TLR_UNQ_NR_SERVX                 0x92
#define TLR_UNQ_NR_SERCOSIII_SVC         0x33
#define TLR_UNQ_NR_SERCOSIII_SL_SVC      0x4F
#define TLR_UNQ_NR_SERCOSIII_SL_RTD      0x50
#define TLR_UNQ_NR_SERCOSIII_SL_IDN      0x85
#define TLR_UNQ_NR_SERCOSIII_SL_COM      0x4E
#define TLR_UNQ_NR_SERCOSIII_SL_AP       0x51
#define TLR_UNQ_NR_SERCOSIII_SIP         0xA0
#define TLR_UNQ_NR_SERCOSIII_MA_SVC      0x71
#define TLR_UNQ_NR_SERCOSIII_MA_NRT      0x79
#define TLR_UNQ_NR_SERCOSIII_MA_CP       0x70
#define TLR_UNQ_NR_SERCOSIII_MA_AP       0x72
#define TLR_UNQ_NR_SERCOSIII_ETH         0x36
#define TLR_UNQ_NR_SERCOSIII_DL          0x35
#define TLR_UNQ_NR_SERCOSIII_CYCLIC      0x37
#define TLR_UNQ_NR_SERCOSIII_API         0x34
#define TLR_UNQ_NR_SERCOS_SL             0x4B
#define TLR_UNQ_NR_RPC                   0x2E
#define TLR_UNQ_NR_RECORDING             0xA6
#define TLR_UNQ_NR_PROFINET_RTA          0x9F
#define TLR_UNQ_NR_PROFIDRIVE_PA         0x98
#define TLR_UNQ_NR_PROFIDRIVE_OD         0x99
#define TLR_UNQ_NR_PROFIDRIVE_AP         0x9A
#define TLR_UNQ_NR_PROFIDRIVE            0x97
#define TLR_UNQ_NR_PROFIBUS_MPI_RFC      0x73
#define TLR_UNQ_NR_PROFIBUS_MPI_AP       0x68
#define TLR_UNQ_NR_PROFIBUS_MPI          0x67
#define TLR_UNQ_NR_PROFIBUS_FSPMS        0x9
#define TLR_UNQ_NR_PROFIBUS_FSPMM2       0x69
#define TLR_UNQ_NR_PROFIBUS_FSPMM        0x38
#define TLR_UNQ_NR_PROFIBUS_DL           0x6
#define TLR_UNQ_NR_PROFIBUS_APS          0x1D
#define TLR_UNQ_NR_PROFIBUS_APM          0x39
#define TLR_UNQ_NR_POWERLINK_MN          0xA4
#define TLR_UNQ_NR_PNS_SOCKET_SRV        0x52
#define TLR_UNQ_NR_PNS_SOCKET            0x55
#define TLR_UNQ_NR_PNS_IF_INTERN         0x58
#define TLR_UNQ_NR_PNS_IF                0x30
#define TLR_UNQ_NR_PNS_EDD_LOW           0x54
#define TLR_UNQ_NR_PNS_EDD_HIGH          0x53
#define TLR_UNQ_NR_PNS_DCP               0x56
#define TLR_UNQ_NR_PNS_CLRPC             0x57
#define TLR_UNQ_NR_PNS_4BITIO            0x45
#define TLR_UNQ_NR_PNS_32BITIO           0x5E
#define TLR_UNQ_NR_PNIOD_LENZE_INIT      0x1C
#define TLR_UNQ_NR_PNIOD_LENZE           0x10
#define TLR_UNQ_NR_PNIOD_DPMIF           0x1A
#define TLR_UNQ_NR_PNIOD_16BITIO         0x3A
#define TLR_UNQ_NR_PNIO_MGT              0x13
#define TLR_UNQ_NR_PNIO_IRT_SCHED        0x81
#define TLR_UNQ_NR_PNIO_EDD              0xE
#define TLR_UNQ_NR_PNIO_DCP              0x12
#define TLR_UNQ_NR_PNIO_CMDEV            0xB
#define TLR_UNQ_NR_PNIO_CMCTL            0xA
#define TLR_UNQ_NR_PNIO_APDEV            0xD
#define TLR_UNQ_NR_PNIO_APCTL            0xC
#define TLR_UNQ_NR_PNIO_APCFG            0x14
#define TLR_UNQ_NR_PNIO_ACP              0x11
#define TLR_UNQ_NR_PACKET_ROUTER         0x83
#define TLR_UNQ_NR_OS                    0x1
#define TLR_UNQ_NR_OMB_OMB_AP            0x61
#define TLR_UNQ_NR_OMB_OMB               0x60
#define TLR_UNQ_NR_OD2                   0x28
#define TLR_UNQ_NR_NT100_GATEWAY         0x84
#define TLR_UNQ_NR_NETSCRIPT             0x80
#define TLR_UNQ_NR_NETPLC_IO_HANDLER     0xA3
#define TLR_UNQ_MPI_GATEWAY              0x78
#define TLR_UNQ_NR_MODBUS_RTU_PERIPH     0x9E
#define TLR_UNQ_NR_MODBUS_RTU_AP         0x6F
#define TLR_UNQ_NR_MODBUS_RTU            0x6E
#define TLR_UNQ_NR_MID_SYS               0x2B
#define TLR_UNQ_NR_MID_STARTUP           0x5F
#define TLR_UNQ_NR_MID_DBG               0x31
#define TLR_UNQ_NR_MIB_DATABASE          0x3C
#define TLR_UNQ_NR_MEMORY_MAP            0x77
#define TLR_UNQ_NR_MARSHALLER            0x82
#define TLR_UNQ_NR_LLDP                  0x3E
#define TLR_UNQ_NR_ITEM_SERVER           0x87
#define TLR_UNQ_NR_ISAGRAF_VM            0x8B
#define TLR_UNQ_NR_ISAGRAF_LOG           0x8C
#define TLR_UNQ_NR_ISAGRAF_ISARSI        0x88
#define TLR_UNQ_NR_ISAGRAF_ETCP          0x89
#define TLR_UNQ_NR_ISAGRAF               0x8A
#define TLR_UNQ_NR_IOLINK_MASTER         0x6D
#define TLR_UNQ_NR_IOLINK_AL             0xA5
#define TLR_UNQ_NR_IO_SIGNAL             0x91
#define TLR_UNQ_NR_INX                   0x93
#define TLR_UNQ_NR_ICONL_TIMER           0x2A
#define TLR_UNQ_NR_ICONL_RUN             0x29
#define TLR_UNQ_NR_GLOBAL                0x0
#define TLR_UNQ_NR_FODMI                 0x96
#define TLR_UNQ_NR_EXAMPLE_TASK3         0x5
#define TLR_UNQ_NR_EXAMPLE_TASK2         0x4
#define TLR_UNQ_NR_EXAMPLE_TASK1         0x3
#define TLR_UNQ_NR_ETHERNETIP_OBJECT     0x1F
#define TLR_UNQ_NR_ETHERNETIP_ENCAP      0x1E
#define TLR_UNQ_NR_ETH_INTF              0x5D
#define TLR_UNQ_NR_EPL_SDO               0x16
#define TLR_UNQ_NR_EPL_PLD               0x19
#define TLR_UNQ_NR_EPL_PDO               0x15
#define TLR_UNQ_NR_EPL_NMT               0x17
#define TLR_UNQ_NR_EPL_MN                0x3D
#define TLR_UNQ_NR_EPL_ALI               0x18
#define TLR_UNQ_NR_EIP_DLR               0x95
#define TLR_UNQ_NR_EIP_APS               0x59
#define TLR_UNQ_NR_EIP_APM               0x5A
#define TLR_UNQ_NR_ECS_LENZE             0x6C
#define TLR_UNQ_NR_ECAT_VOE              0x26
#define TLR_UNQ_NR_ECAT_SOE              0x22
#define TLR_UNQ_NR_ECAT_MASTER_AP        0x64
#define TLR_UNQ_NR_ECAT_MASTER           0x65
#define TLR_UNQ_NR_ECAT_FOE              0x24
#define TLR_UNQ_NR_ECAT_ESM              0x4D
#define TLR_UNQ_NR_ECAT_EOE              0x23
#define TLR_UNQ_NR_ECAT_DPM              0x4C
#define TLR_UNQ_NR_ECAT_COE              0x21
#define TLR_UNQ_NR_ECAT_BASE             0x20
#define TLR_UNQ_NR_ECAT_AOE              0x25
#define TLR_UNQ_NR_DRV_EDD               0xF
#define TLR_UNQ_NR_DPM_OD2               0x48
#define TLR_UNQ_NR_DNS_FAL               0x62
#define TLR_UNQ_NR_DNS_AP                0x63
#define TLR_UNQ_NR_DF1_AP                0x8E
#define TLR_UNQ_NR_DF1                   0x8D
#define TLR_UNQ_NR_DEVNET_FAL            0x47
#define TLR_UNQ_NR_DEVNET_APS            0x5C
#define TLR_UNQ_NR_DEVNET_AP             0x5B
#define TLR_UNQ_NR_DDL_ENPDDL            0x40
#define TLR_UNQ_NR_DDL_DDL               0x41
#define TLR_UNQ_NR_COMPONET_SLAVE_AP     0x7D
#define TLR_UNQ_NR_COMPONET_SLAVE        0x7C
#define TLR_UNQ_NR_CO_OBJDICT            0x9B
#define TLR_UNQ_NR_CCLINK_SLAVE          0x6A
#define TLR_UNQ_NR_CCLINK_APS            0x6B
#define TLR_UNQ_NR_CANOPEN_SLAVE         0x43
#define TLR_UNQ_NR_CANOPEN_MASTER        0x42
#define TLR_UNQ_NR_CANOPEN_APS           0x4A
#define TLR_UNQ_NR_CANOPEN_APM           0x49
#define TLR_UNQ_NR_CANDL_APSAMPLE        0x46
#define TLR_UNQ_NR_CAN_DL                0x3F
#define TLR_UNQ_NR_ASI_MASTER            0x7A
#define TLR_UNQ_NR_ASI_ECTRL             0x32
#define TLR_UNQ_NR_ASI_APM               0x7B
#define TLR_UNQ_NR_ASCII_AP              0x7F
#define TLR_UNQ_NR_ASCII                 0x7E
#define TLR_UNQ_NR_AN_TRANS              0x66
#define TLR_UNQ_NR_3S_PLC_HANDLER_AP     0xA2
#define TLR_UNQ_NR_3S_PLC_HANDLER        0xA1
#define TLR_UNQ_NR_3964R_AP              0x90
#define TLR_UNQ_NR_3964R                 0x8F


/*  */
/*  Define the severity codes */
/*  */
#define TLR_STATUS_TYPE_WARNING          0x2
#define TLR_STATUS_TYPE_SUCCESS          0x0
#define TLR_STATUS_TYPE_INFO             0x1
#define TLR_STATUS_TYPE_ERROR            0x3


/*  */
/*  MessageId: TLR_E_COMPILE_THIS_AS_TLR_FACILITIES */
/*  */
/*  MessageText: */
/*  */
/*   TLR Facilities Dummy Code. */
/*  */
#define TLR_E_COMPILE_THIS_AS_TLR_FACILITIES ((TLR_RESULT)0xC000FFFFL)

#endif /* TLR_FACILITIES_H */
#endif /* DO_NOT_INCLUDE_THIS_HEADER_IN_TLR_AUTOGEN_HEADERS */



#ifndef __ASI_ECTRL_DIAG_H
#define __ASI_ECTRL_DIAG_H

/*****************************************************************************/
/*  AS-Interface Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_ASI_ECTRL_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ASI_ECTRL_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0320001L)




#endif  /* __ASI_ECTRL_DIAG_H */

#ifndef __CANOPEN_APS_DIAG_H
#define __CANOPEN_APS_DIAG_H

/*****************************************************************************/
/*  CANopen Application Slave Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APS_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_CANOPEN_APS_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC04A0001L)




#endif  /* __CANOPEN_APS_DIAG_H */

#ifndef __CANOPEN_SLAVE_DIAG_H
#define __CANOPEN_SLAVE_DIAG_H

/*****************************************************************************/
/*  CANopen Slave Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_SLAVE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_CANOPEN_SLAVE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0430001L)




#endif  /* __CANOPEN_SLAVE_DIAG_H */

#ifndef __CANOPEN_APM_DIAG_H
#define __CANOPEN_APM_DIAG_H

/*****************************************************************************/
/*  CANopen Application Master Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0490001L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_OPEN_DBM_FILE */
/*  */
/*  MessageText: */
/*  */
/*   Configuration file could not be opened. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_OPEN_DBM_FILE ((TLR_RESULT)0xC0490002L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_DATASET */
/*  */
/*  MessageText: */
/*  */
/*   No pointer to dataset. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_DATASET   ((TLR_RESULT)0xC0490003L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Configuration table BUS_CAN not found. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_TABLE_BUS_CAN ((TLR_RESULT)0xC0490004L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_TABLE_BUS_CAN_EXT */
/*  */
/*  MessageText: */
/*  */
/*   Configuration table BUS_CAN_EXT not found. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_TABLE_BUS_CAN_EXT ((TLR_RESULT)0xC0490005L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_TABLE_NODES */
/*  */
/*  MessageText: */
/*  */
/*   Configuration table NODES not found. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_TABLE_NODES ((TLR_RESULT)0xC0490006L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_TABLE_PLC_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   Configuration table PLC_PARAM not found. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_TABLE_PLC_PARAM ((TLR_RESULT)0xC0490007L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of confifuration table BUS_CAN. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN ((TLR_RESULT)0xC0490008L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN_EXT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of confifuration table BUS_CAN_EXT. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_BUS_CAN_EXT ((TLR_RESULT)0xC0490009L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_PLC_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of confifuration table PLC_PARAM. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_PLC_PARAM ((TLR_RESULT)0xC049000AL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_NODE_ID_ALREADY_USED */
/*  */
/*  MessageText: */
/*  */
/*   The Node ID is already used. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_NODE_ID_ALREADY_USED ((TLR_RESULT)0xC049000BL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_INVALID_NODE_ID */
/*  */
/*  MessageText: */
/*  */
/*   The Node ID is not within valid range. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_INVALID_NODE_ID ((TLR_RESULT)0xC049000CL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_GLOBAL */
/*  */
/*  MessageText: */
/*  */
/*   Invalid size of confifuration table GLOBAL. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_SIZE_TABLE_GLOBAL ((TLR_RESULT)0xC049000DL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_DBM_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid name for database. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_DBM_NAME  ((TLR_RESULT)0xC049000EL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_ACTIVATE_WATCHDOG */
/*  */
/*  MessageText: */
/*  */
/*   Failed to activated watchdog supervision. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_ACTIVATE_WATCHDOG ((TLR_RESULT)0xC049000FL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_APM_PARAM_WATCHDOG_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for watchdog supervision. */
/*  */
#define TLR_DIAG_E_CANOPEN_APM_PARAM_WATCHDOG_TIME ((TLR_RESULT)0xC0490010L)




#endif  /* __CANOPEN_APM_DIAG_H */

#ifndef __CANOPEN_MASTER_DIAG_H
#define __CANOPEN_MASTER_DIAG_H

/*****************************************************************************/
/*  CANopen Master Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0420001L)

/*  */
/*  MessageId: TLR_DIAG_I_CANOPEN_MASTER_NODE_STATE_NOT_HANDLED */
/*  */
/*  MessageText: */
/*  */
/*   State of node not handled. */
/*  */
#define TLR_DIAG_I_CANOPEN_MASTER_NODE_STATE_NOT_HANDLED ((TLR_RESULT)0x40420002L)

/*  */
/*  MessageId: TLR_DIAG_S_CANOPEN_MASTER_NODE_STATE_COMPLETE */
/*  */
/*  MessageText: */
/*  */
/*   State of node is successfully complete. */
/*  */
#define TLR_DIAG_S_CANOPEN_MASTER_NODE_STATE_COMPLETE ((TLR_RESULT)0x00420003L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_COB_ID_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   COB-ID could not be set. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_COB_ID_FAILED ((TLR_RESULT)0xC0420004L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_ADD_REMOTE_NODE_REQUEST */
/*  */
/*  MessageText: */
/*  */
/*   Failed to add remote node. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_ADD_REMOTE_NODE_REQUEST ((TLR_RESULT)0xC0420005L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_HEARTBEAT_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat time could not be set. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_HEARTBEAT_TIME ((TLR_RESULT)0xC0420006L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_ADD_GUARDING_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   Node could not be added to node guarding list. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_ADD_GUARDING_SLAVE ((TLR_RESULT)0xC0420007L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_GUARDING_TIME */
/*  */
/*  MessageText: */
/*  */
/*   Node guard time could not be set. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_GUARDING_TIME ((TLR_RESULT)0xC0420008L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_START_NODE_GUARD */
/*  */
/*  MessageText: */
/*  */
/*   Node guarding could not be started. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_START_NODE_GUARD ((TLR_RESULT)0xC0420009L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_RESET_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Reset node failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_RESET_NODE ((TLR_RESULT)0xC042000AL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_STOP_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Stop node failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_STOP_NODE ((TLR_RESULT)0xC042000BL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_START_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Start node failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_START_NODE ((TLR_RESULT)0xC042000CL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_EMCY_COB_ID */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set Emergency COB-ID. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_EMCY_COB_ID ((TLR_RESULT)0xC042000DL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_START_SDO_UPLOAD */
/*  */
/*  MessageText: */
/*  */
/*   Failed to start SDO Upload request. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_START_SDO_UPLOAD ((TLR_RESULT)0xC042000EL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_START_SDO_DOWNLOAD */
/*  */
/*  MessageText: */
/*  */
/*   Failed to start SDO Download request. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_START_SDO_DOWNLOAD ((TLR_RESULT)0xC042000FL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_PUT_OBJECT_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Failed to write object data. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_PUT_OBJECT_DATA ((TLR_RESULT)0xC0420010L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_OBJECT_DATA_VALID */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set object data valid. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_OBJECT_DATA_VALID ((TLR_RESULT)0xC0420011L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_WRITE_PDO_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Failed to transmit PDO. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_WRITE_PDO_REQ ((TLR_RESULT)0xC0420012L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_READ_PDO_REQ */
/*  */
/*  MessageText: */
/*  */
/*   Failed to request PDO. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_READ_PDO_REQ ((TLR_RESULT)0xC0420013L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_DEVICE_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Node Device Type unequal to configured Device Type. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_DEVICE_TYPE ((TLR_RESULT)0xC0420014L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_UNEXPECTED_STATE */
/*  */
/*  MessageText: */
/*  */
/*   Node is not in expected state. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_UNEXPECTED_STATE ((TLR_RESULT)0xC0420015L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_LOST_CONNECTION */
/*  */
/*  MessageText: */
/*  */
/*   Connection to Node lost. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_LOST_CONNECTION ((TLR_RESULT)0xC0420016L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_GUARDING_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Node guarding error. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_GUARDING_ERROR ((TLR_RESULT)0xC0420017L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_HEARTBEAT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat error. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_HEARTBEAT_ERROR ((TLR_RESULT)0xC0420018L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_UNEXPECTED_BOOTUP */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected Bootup message from Node received. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_UNEXPECTED_BOOTUP ((TLR_RESULT)0xC0420019L)

/*  */
/*  MessageId: TLR_DIAG_I_CANOPEN_MASTER_NODE_EMERGENCY_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   Emergency message received from node. */
/*  */
#define TLR_DIAG_I_CANOPEN_MASTER_NODE_EMERGENCY_RECEIVED ((TLR_RESULT)0x4042001AL)

/*  */
/*  MessageId: TLR_DIAG_I_CANOPEN_MASTER_NODE_HEARTBEAT_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   Heartbeat supervision of node started. */
/*  */
#define TLR_DIAG_I_CANOPEN_MASTER_NODE_HEARTBEAT_STARTED ((TLR_RESULT)0x4042001BL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_SDO_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout during SDO transfer. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_SDO_TIMEOUT ((TLR_RESULT)0xC042001CL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_NODE_SDO_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Error during SDO transfer. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_NODE_SDO_ERROR ((TLR_RESULT)0xC042001DL)

/*  */
/*  MessageId: TLR_DIAG_I_CANOPEN_MASTER_NODE_DEACTIVATED */
/*  */
/*  MessageText: */
/*  */
/*   Node is deactivated in configuration. */
/*  */
#define TLR_DIAG_I_CANOPEN_MASTER_NODE_DEACTIVATED ((TLR_RESULT)0x4042001EL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_INIT_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of buffer failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_INIT_BUFFER ((TLR_RESULT)0xC042001FL)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_DELETE_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Delete node failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_DELETE_NODE ((TLR_RESULT)0xC0420020L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_START_SYNC */
/*  */
/*  MessageText: */
/*  */
/*   Failed to start SYNC-telegram. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_START_SYNC ((TLR_RESULT)0xC0420021L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_DL_REQ_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   CAN-DL request failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_DL_REQ_FAILED ((TLR_RESULT)0xC0420022L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_WATCHDOG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog failure detected. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_WATCHDOG_FAIL ((TLR_RESULT)0xC0420023L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_AUTO_CLEAR_ACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Auto-clear active. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_AUTO_CLEAR_ACTIVE ((TLR_RESULT)0xC0420024L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SEND_EMCY */
/*  */
/*  MessageText: */
/*  */
/*   Send emergency-telegram failed. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SEND_EMCY ((TLR_RESULT)0xC0420025L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_SET_NODE_PREOP */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set node preoperational. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_SET_NODE_PREOP ((TLR_RESULT)0xC0420026L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_INIT_LIBRARY */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialite CANopen library. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_INIT_LIBRARY ((TLR_RESULT)0xC0420027L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_RESET_COMMUNICATION */
/*  */
/*  MessageText: */
/*  */
/*   Failed to reset communication of node. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_RESET_COMMUNICATION ((TLR_RESULT)0xC0420028L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_ERROR_PASSIVE */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in error-passive state. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_ERROR_PASSIVE ((TLR_RESULT)0xC0420029L)

/*  */
/*  MessageId: TLR_DIAG_E_CANOPEN_MASTER_BUS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   CANopen is in bus-off state. */
/*  */
#define TLR_DIAG_E_CANOPEN_MASTER_BUS_OFF ((TLR_RESULT)0xC042002AL)




#endif  /* __CANOPEN_MASTER_DIAG_H */

#ifndef __DDL_ENPDDL_DIAG_H
#define __DDL_ENPDDL_DIAG_H

/*****************************************************************************/
/*  ENPDDL Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_PROCESS_CANCELED ((TLR_RESULT)0xC0400001L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_APPLICATION_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an application timer (Timer task). */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0400002L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_APPLICATION_TIMER_INIT_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize a packet of application timer (Timer task). */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC0400003L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_INVALID_STARTUP_PARAMETER_CYCLE_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulCycleEvent. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_INVALID_STARTUP_PARAMETER_CYCLE_EVENT ((TLR_RESULT)0xC0400004L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_CAN_DL_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the CAN_DL task. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_CAN_DL_IDENTIFY_FAILED ((TLR_RESULT)0xC0400005L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_CAN_DL_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The queue identification of CAN_DL task queue has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_CAN_DL_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0400006L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_ECAT_HAL_INITIALIZE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The initialization of ECAT HAL has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_ECAT_HAL_INITIALIZE_FAILED ((TLR_RESULT)0xC0400007L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_ECAT_HAL_GET_SYNC_MANAGER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The ECAT get sync manager function has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_ECAT_HAL_GET_SYNC_MANAGER_FAILED ((TLR_RESULT)0xC0400008L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_ECAT_ESM_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the ECAT_ESM task. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_ECAT_ESM_IDENTIFY_FAILED ((TLR_RESULT)0xC0400009L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_ECAT_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The queue identification of ECAT_ESM task queue has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_ECAT_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC040000AL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_GPIO_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The GPIO identification has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_GPIO_IDENTIFY_FAILED ((TLR_RESULT)0xC040000BL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_GPIO_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The GPIO initialization has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_GPIO_INITIALIZATION_FAILED ((TLR_RESULT)0xC040000CL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_PIO_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The PIO identification has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_PIO_IDENTIFY_FAILED ((TLR_RESULT)0xC040000DL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_PIO_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The PIO initialization has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_PIO_INITIALIZATION_FAILED ((TLR_RESULT)0xC040000EL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_PIO_CLEAR_OUTPUTS_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The PIO clear outputs has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_PIO_CLEAR_OUTPUTS_FAILED ((TLR_RESULT)0xC040000FL)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_LED_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The LED identification has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_LED_IDENTIFY_FAILED ((TLR_RESULT)0xC0400010L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_LED_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The LED initialization has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_LED_INITIALIZATION_FAILED ((TLR_RESULT)0xC0400011L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_GPIO_GET_INPUT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The GPIO get inputs has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_GPIO_GET_INPUT_FAILED ((TLR_RESULT)0xC0400012L)

/*  */
/*  MessageId: TLR_DIAG_E_DDL_ENPDDL_PIO_GET_INPUTS_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The PIO get inputs has failed. */
/*  */
#define TLR_DIAG_E_DDL_ENPDDL_PIO_GET_INPUTS_FAILED ((TLR_RESULT)0xC0400013L)




#endif  /* __DDL_ENPDDL_DIAG_H */

#ifndef __DPM_OD2_DIAG_H
#define __DPM_OD2_DIAG_H

/*****************************************************************************/
/*  Object Dictionary V2 DPM Adapter Task */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identification of Host Interface failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_FAILED ((TLR_RESULT)0xC0480001L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_CREATE_AREA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of Host Interface Area failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_CREATE_AREA_FAILED ((TLR_RESULT)0xC0480002L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_AREA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of Host Interface Area failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_AREA_FAILED ((TLR_RESULT)0xC0480003L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_INPUT_DATA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of Input Data subblock failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_INPUT_DATA_FAILED ((TLR_RESULT)0xC0480004L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_OUTPUT_DATA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of Output Data subblock failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_OUTPUT_DATA_FAILED ((TLR_RESULT)0xC0480005L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_STATUS_DATA_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of Status Data subblock failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_HIF_IDENTIFY_STATUS_DATA_FAILED ((TLR_RESULT)0xC0480006L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_IDENTIFY_OF_STATE_TASK_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of the queue of the state managing task failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_IDENTIFY_OF_STATE_TASK_QUEUE_FAILED ((TLR_RESULT)0xC0480007L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_IDENTIFY_OF_PROCESS_DATA_TASK_QUEUE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identify of the queue of the process data managing task failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_IDENTIFY_OF_PROCESS_DATA_TASK_QUEUE_FAILED ((TLR_RESULT)0xC0480008L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_UNKNOWN_STACK_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Unknown stack type specified. */
/*  */
#define TLR_DIAG_E_DPM_OD2_UNKNOWN_STACK_TYPE ((TLR_RESULT)0xC0480009L)

/*  */
/*  MessageId: TLR_DIAG_E_DPM_OD2_IDENTIFY_OBJ_DICT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identification of object dictionary failed. */
/*  */
#define TLR_DIAG_E_DPM_OD2_IDENTIFY_OBJ_DICT_FAILED ((TLR_RESULT)0xC048000AL)




#endif  /* __DPM_OD2_DIAG_H */

#ifndef __ECAT_DIAG_H
#define __ECAT_DIAG_H

/*****************************************************************************/
/*  EtherCAT DPM Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_ECAT_DPM_WATCHDOG_TRIGGERED */
/*  */
/*  MessageText: */
/*  */
/*   DPM Watchdog triggered. */
/*  */
#define TLR_DIAG_E_ECAT_DPM_WATCHDOG_TRIGGERED ((TLR_RESULT)0xC04C0001L)

/*****************************************************************************/
/*  EtherCAT Base Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_LOST_PCK_ALARM */
/*  */
/*  MessageText: */
/*  */
/*   Mailbox Packet Lost. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_LOST_PCK_ALARM ((TLR_RESULT)0xC0200001L)

/*  */
/*  MessageId: TLR_DIAG_W_ECAT_BASE_MAILBOX_POOL_EMPTY */
/*  */
/*  MessageText: */
/*  */
/*   Mailbox stopped due to empty packet pool. */
/*  */
#define TLR_DIAG_W_ECAT_BASE_MAILBOX_POOL_EMPTY ((TLR_RESULT)0x80200002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0200002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0200003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_DYNAMIC_DATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Dynamic Data invalid. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_DYNAMIC_DATA_INVALID ((TLR_RESULT)0xC0200004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_URX0_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Urx0 overflow. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_URX0_OVERFLOW ((TLR_RESULT)0xC0200005L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_UTX0_UNDERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Utx0 underflow. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_UTX0_UNDERFLOW ((TLR_RESULT)0xC0200006L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_URX1_OVERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Urx1 overflow. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_URX1_OVERFLOW ((TLR_RESULT)0xC0200007L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_UTX1_UNDERFLOW */
/*  */
/*  MessageText: */
/*  */
/*   Utx1 underflow. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_UTX1_UNDERFLOW ((TLR_RESULT)0xC0200008L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0200009L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_ESM_PACKET_POOL_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Packet pool identification of EcatEsm-task pool failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_ESM_PACKET_POOL_IDENTIFY_FAILED ((TLR_RESULT)0xC020000AL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_LOCK_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of lock failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_LOCK_CREATION_FAILED ((TLR_RESULT)0xC020000BL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_INVALID_ESM_DBM_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid ESM DBM data. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_INVALID_ESM_DBM_DATA ((TLR_RESULT)0xC020000CL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_INVALID_MBX_DBM_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid MBX DBM data. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_INVALID_MBX_DBM_DATA ((TLR_RESULT)0xC020000DL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of timer failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_TIMER_CREATE_FAILED ((TLR_RESULT)0xC020000EL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_PACKET_GET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Retrieving a packet from pool failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_PACKET_GET_FAILED ((TLR_RESULT)0xC020000FL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0200010L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_BASE_MUTEX_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of mutex failed. */
/*  */
#define TLR_DIAG_E_ECAT_BASE_MUTEX_CREATION_FAILED ((TLR_RESULT)0xC0200011L)

/*  */
/*  MessageId: TLR_DIAG_S_ECAT_BASE_STATE_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state INIT. */
/*  */
#define TLR_DIAG_S_ECAT_BASE_STATE_INIT  ((TLR_RESULT)0x00200012L)

/*  */
/*  MessageId: TLR_DIAG_S_ECAT_BASE_STATE_PREOP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state PREOP. */
/*  */
#define TLR_DIAG_S_ECAT_BASE_STATE_PREOP ((TLR_RESULT)0x00200013L)

/*  */
/*  MessageId: TLR_DIAG_S_ECAT_BASE_STATE_SAFEOP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state SAFEOP. */
/*  */
#define TLR_DIAG_S_ECAT_BASE_STATE_SAFEOP ((TLR_RESULT)0x00200014L)

/*  */
/*  MessageId: TLR_DIAG_S_ECAT_BASE_STATE_OP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state OPERATIONAL. */
/*  */
#define TLR_DIAG_S_ECAT_BASE_STATE_OP    ((TLR_RESULT)0x00200015L)

/*  */
/*  MessageId: TLR_DIAG_W_ECAT_BASE_STATE_ERR_INIT */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state ERR INIT. */
/*  */
#define TLR_DIAG_W_ECAT_BASE_STATE_ERR_INIT ((TLR_RESULT)0x80200012L)

/*  */
/*  MessageId: TLR_DIAG_W_ECAT_BASE_STATE_ERR_PREOP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state ERR PREOP. */
/*  */
#define TLR_DIAG_W_ECAT_BASE_STATE_ERR_PREOP ((TLR_RESULT)0x80200013L)

/*  */
/*  MessageId: TLR_DIAG_W_ECAT_BASE_STATE_ERR_SAFEOP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state ERR SAFEOP. */
/*  */
#define TLR_DIAG_W_ECAT_BASE_STATE_ERR_SAFEOP ((TLR_RESULT)0x80200014L)

/*  */
/*  MessageId: TLR_DIAG_W_ECAT_BASE_STATE_ERR_OP */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently in state ERR OP. */
/*  */
#define TLR_DIAG_W_ECAT_BASE_STATE_ERR_OP ((TLR_RESULT)0x80200015L)

/*  */
/*  MessageId: TLR_DIAG_S_ECAT_BASE_STATE_BOOTING */
/*  */
/*  MessageText: */
/*  */
/*   Slave is currently booting. */
/*  */
#define TLR_DIAG_S_ECAT_BASE_STATE_BOOTING ((TLR_RESULT)0x00200016L)

/*****************************************************************************/
/*  EtherCAT CoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_COE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   CoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_COE_NOT_INITIALIZED ((TLR_RESULT)0x80210001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_PDO_STAGE2_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   PDO configuration could not be loaded. */
/*  */
#define TLR_DIAG_E_ECAT_COE_PDO_STAGE2_FAILED ((TLR_RESULT)0xC0210002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_COE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0210003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_COE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0210004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_COULD_NOT_CREATE_OBJECT_DICTIONARY */
/*  */
/*  MessageText: */
/*  */
/*   Could not create object dictionary. */
/*  */
#define TLR_DIAG_E_ECAT_COE_COULD_NOT_CREATE_OBJECT_DICTIONARY ((TLR_RESULT)0xC0210005L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0210006L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_COE_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatCoE-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_COE_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0210007L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0210008L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_PACKET_GET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Retrieving a packet from pool failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_PACKET_GET_FAILED ((TLR_RESULT)0xC021000AL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of a timer failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_TIMER_CREATE_FAILED ((TLR_RESULT)0xC021000BL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_MUTEX_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of mutex failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_MUTEX_CREATION_FAILED ((TLR_RESULT)0xC021000CL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_SDO_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatSdo-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_SDO_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC021000DL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_PDO_DBM_DATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid EcatPdo task DBM data. */
/*  */
#define TLR_DIAG_E_ECAT_COE_PDO_DBM_DATA_INVALID ((TLR_RESULT)0xC021000EL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_COE_PDO_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatPdo-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_COE_PDO_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0210010L)

/*****************************************************************************/
/*  EtherCAT SoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_SOE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   SoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_SOE_NOT_INITIALIZED ((TLR_RESULT)0x80220001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_SOE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_SOE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0220002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_SOE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_SOE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0220003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_SOE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_SOE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0220004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_SOE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_SOE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0220005L)

/*****************************************************************************/
/*  EtherCAT EoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_EOE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   EoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_EOE_NOT_INITIALIZED ((TLR_RESULT)0x80230001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0230001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0230002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_MUTEX_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of mutex failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_MUTEX_CREATE_FAILED ((TLR_RESULT)0xC0230003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_VSWITCH_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of virtual switch failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_VSWITCH_CREATE_FAILED ((TLR_RESULT)0xC0230004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0230005L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0230006L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_INVALID_DBM_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid EcatEoE task DBM data. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_INVALID_DBM_DATA ((TLR_RESULT)0xC0230007L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_CONFIG_SETUP_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Setup of configuration access failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_CONFIG_SETUP_FAILED ((TLR_RESULT)0xC0230008L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_VSWITCH_PORT_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of Virtual Switch port failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_VSWITCH_PORT_CREATE_FAILED ((TLR_RESULT)0xC0230009L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_PACKET_GET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Retrieving a packet from pool failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_PACKET_GET_FAILED ((TLR_RESULT)0xC023000AL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of a timer failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_TIMER_CREATE_FAILED ((TLR_RESULT)0xC023000BL)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_EOE_TCPTASK_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of TCP-task failed. */
/*  */
#define TLR_DIAG_E_ECAT_EOE_TCPTASK_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC023000CL)

/*****************************************************************************/
/*  EtherCAT FoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_FOE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   FoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_FOE_NOT_INITIALIZED ((TLR_RESULT)0x80240001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0240001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0240002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0240003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0240004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_DBM_DATA_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Invalid EcatFoE task DBM data. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_DBM_DATA_INVALID ((TLR_RESULT)0xC0240005L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_DEF_HANDLER_INIT_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Initialization of default FoE handler failed. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_DEF_HANDLER_INIT_FAILED ((TLR_RESULT)0xC0240006L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_FOE_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of timer failed. */
/*  */
#define TLR_DIAG_E_ECAT_FOE_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0240007L)

/*****************************************************************************/
/*  EtherCAT AoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_AOE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   AoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_AOE_NOT_INITIALIZED ((TLR_RESULT)0x80250001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_AOE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_AOE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0250001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_AOE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_AOE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0250002L)

/*****************************************************************************/
/*  EtherCAT VoE Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_W_ECAT_VOE_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   VoE stack not initialized. */
/*  */
#define TLR_DIAG_W_ECAT_VOE_NOT_INITIALIZED ((TLR_RESULT)0x80260001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0260001L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_COULD_NOT_CREATE_STACK_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Could not create stack data storage. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_COULD_NOT_CREATE_STACK_DATA ((TLR_RESULT)0xC0260002L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_MBX_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatMbx-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_MBX_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0260003L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_ESM_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of EcatEsm-task queue failed. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_ESM_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0260004L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_ESM_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet to the EcatEsm-task failed. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_ESM_PACKET_SEND_FAILED ((TLR_RESULT)0xC0260005L)

/*  */
/*  MessageId: TLR_DIAG_E_ECAT_VOE_MBX_PACKET_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet to the EcatMbx-task failed. */
/*  */
#define TLR_DIAG_E_ECAT_VOE_MBX_PACKET_SEND_FAILED ((TLR_RESULT)0xC0260006L)




#endif  /* __ECAT_DIAG_H */

#ifndef __EIP_APM_DIAG_H
#define __EIP_APM_DIAG_H

/*****************************************************************************/
/*  Ethernet/IP Application Slave */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EIP_APM_TCP_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   TCP stack configuration failed. */
/*  */
#define TLR_DIAG_E_EIP_APM_TCP_CONFIG_FAIL ((TLR_RESULT)0xC05A0001L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_APM_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Existing connection is closed. */
/*  */
#define TLR_DIAG_E_EIP_APM_CONNECTION_CLOSED ((TLR_RESULT)0xC05A0002L)




#endif  /* __EIP_APM_DIAG_H */

#ifndef __EIP_APS_DIAG_H
#define __EIP_APS_DIAG_H

/*****************************************************************************/
/*  Ethernet/IP Application Slave */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EIP_APS_TCP_CONFIG_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   TCP stack configuration failed. */
/*  */
#define TLR_DIAG_E_EIP_APS_TCP_CONFIG_FAIL ((TLR_RESULT)0xC0590001L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_APS_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Existing connection is closed. */
/*  */
#define TLR_DIAG_E_EIP_APS_CONNECTION_CLOSED ((TLR_RESULT)0xC0590002L)




#endif  /* __EIP_APS_DIAG_H */

#ifndef __EIP_ENCAP_DIAG_H
#define __EIP_ENCAP_DIAG_H

/*****************************************************************************/
/*  Ethernet/IP Encapsulation */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_LIDENTITY_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to indicate the received List Identity information. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_LIDENTITY_PACKET ((TLR_RESULT)0xC01E0001L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_ENCAP_CMD_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to send a request to the ethernet interface. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_ENCAP_CMD_PACKET ((TLR_RESULT)0xC01E0002L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_REGISTER_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to send a register session request to the ethernet interface. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_REGISTER_PACKET ((TLR_RESULT)0xC01E0003L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_CMD_TCP_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Send packet to the ethenet interface failed. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_CMD_TCP_SEND_PACKET_FAIL ((TLR_RESULT)0xC01E0004L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_LSERVICE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to indicate the received List Service information. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_LSERVICE_PACKET ((TLR_RESULT)0xC01E0005L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_LINTERFACE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to indicate the received List Interface information. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_LINTERFACE_PACKET ((TLR_RESULT)0xC01E0006L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_MULTICAST_JOIN_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to join the multicast group. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_MULTICAST_JOIN_PACKET ((TLR_RESULT)0xC01E0007L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_MULTICAST_DROP_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to drop the multicast group. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_MULTICAST_DROP_PACKET ((TLR_RESULT)0xC01E0008L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_CONNECTING_INVALID_PACKET_ID */
/*  */
/*  MessageText: */
/*  */
/*   By establishing a new connection an invalid packet ID was received. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_CONNECTING_INVALID_PACKET_ID ((TLR_RESULT)0xC01E0009L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_WAIT_CONN_INVALID_PACKET_ID */
/*  */
/*  MessageText: */
/*  */
/*   By waiting for a connection an invalid packet ID was received. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_WAIT_CONN_INVALID_PACKET_ID ((TLR_RESULT)0xC01E000AL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_CEP_OVERRUN */
/*  */
/*  MessageText: */
/*  */
/*   No free connection endpoints are available. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_CEP_OVERRUN ((TLR_RESULT)0xC01E000BL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_CONNECTION_INACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Receive data from a inactiv or unknown connection. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_CONNECTION_INACTIVE ((TLR_RESULT)0xC01E000CL)

/*  */
/*  MessageId: TLR_DIAG_W_EIP_ENCAP_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Connection is closed. */
/*  */
#define TLR_DIAG_W_EIP_ENCAP_CONNECTION_CLOSED ((TLR_RESULT)0xC01E000DL)

/*  */
/*  MessageId: TLR_DIAG_W_EIP_ENCAP_CONNECTION_RESET */
/*  */
/*  MessageText: */
/*  */
/*   Connection is reseted. */
/*  */
#define TLR_DIAG_W_EIP_ENCAP_CONNECTION_RESET ((TLR_RESULT)0xC01E000EL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_RECEIVED_INVALID_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Receive invalid data, Connection is closed. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_RECEIVED_INVALID_DATA ((TLR_RESULT)0xC01E000FL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_UNKNOWN_CONNECTION_TYP */
/*  */
/*  MessageText: */
/*  */
/*   Receive data from a unknown connection typ. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_UNKNOWN_CONNECTION_TYP ((TLR_RESULT)0xC01E0010L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_CEP_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Command is not allowed at the actual connection endpoint state. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_CEP_STATE_ERROR ((TLR_RESULT)0xC01E0011L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_INDICATION_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to send a indication of the received data. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_INDICATION_PACKET ((TLR_RESULT)0xC01E0012L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_REVEIVER_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   No memory for a receive buffer is available, data could not received. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_REVEIVER_OUT_OF_MEMORY ((TLR_RESULT)0xC01E0013L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_ABORT_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to send a abort transport indication. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_ABORT_IND_PACKET ((TLR_RESULT)0xC01E0014L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_START_CONNECTION_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Starting the connection failed. Connection enpoint is invalid. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_START_CONNECTION_FAIL ((TLR_RESULT)0xC01E0015L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_ENCAP_NO_GET_TCP_CONFIG_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet for requesting the actual configuration from the TCP task. */
/*  */
#define TLR_DIAG_E_EIP_ENCAP_NO_GET_TCP_CONFIG_PACKET ((TLR_RESULT)0xC01E0016L)




#endif  /* __EIP_ENCAP_DIAG_H */

#ifndef __EIP_OBJECT_DIAG_H
#define __EIP_OBJECT_DIAG_H

/*****************************************************************************/
/*  Ethernet/IP Object */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_NO_SERVICE_RES_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to create a response of the request. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_NO_SERVICE_RES_PACKET ((TLR_RESULT)0xC01F0001L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_NO_GET_INP_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No free packet available to send the input data. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_NO_GET_INP_PACKET ((TLR_RESULT)0xC01F0002L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_ROUTING_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Routing a request to an object failed. A error ouccurred at the destination packet queue. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_ROUTING_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F0003L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_ROUTING_SEND_PACKET_CNF_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Sending the confirmation of a request failed. A error ouccurred at the packet queue. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_ROUTING_SEND_PACKET_CNF_FAIL ((TLR_RESULT)0xC01F0004L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_GETTING_UNKNOWN_CLASS_ID */
/*  */
/*  MessageText: */
/*  */
/*   Getting a confirmation of a request from a unknown object. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_GETTING_UNKNOWN_CLASS_ID ((TLR_RESULT)0xC01F0005L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_NO_CC_INSTANCE_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Instance of the CC object could not created. No free memory available. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_NO_CC_INSTANCE_MEMORY ((TLR_RESULT)0xC01F0006L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_CLOSE_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Completing a connection close command failed. Sending the command to the packet queue failed. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_CLOSE_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F0007L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_OPEN_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Completing a connection open command failed. Sending the command to the packet queue failed. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_OPEN_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F0008L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_DEL_TRANSP_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Sending the delete transport command failed. Encap Queue signal an error. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_DEL_TRANSP_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F0009L)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_FW_OPEN_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Sending the forward open command failed. Encap Queue signal an error. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_FW_OPEN_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F000AL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_START_TRANSP_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Sending the start transport command failed. Encap Queue signal an error. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_START_TRANSP_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F000BL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_CM_UNKNOWN_CNF */
/*  */
/*  MessageText: */
/*  */
/*   Connection manager received a confirmation of unknown service. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_CM_UNKNOWN_CNF ((TLR_RESULT)0xC01F000CL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_FW_CLOSE_SEND_PACKET_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Sending the forward close command failed. Encap Queue signal an error. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_FW_CLOSE_SEND_PACKET_FAIL ((TLR_RESULT)0xC01F000DL)

/*  */
/*  MessageId: TLR_DIAG_E_EIP_OBJECT_NO_RESET_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Fail to complete reset command. We did not get a empty packet. */
/*  */
#define TLR_DIAG_E_EIP_OBJECT_NO_RESET_PACKET ((TLR_RESULT)0xC01F000EL)




#endif  /* __EIP_OBJECT_DIAG_H */

#ifndef __EPL_DIAG_H
#define __EPL_DIAG_H

/*****************************************************************************/
/*  PowerLink NMT Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_EPL_NMT_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0170001L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of a timer failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0170002L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_OBJ_DICT_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of the object dictionary failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_OBJ_DICT_CREATE_FAILED ((TLR_RESULT)0xC0170003L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_EDD_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Identification of the Edd device failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_EDD_IDENTIFY_FAILED ((TLR_RESULT)0xC0170004L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_EDD_REQUEST_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   A request to the Edd device failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_EDD_REQUEST_FAILED ((TLR_RESULT)0xC0170005L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_INVALID_DBM_DATA */
/*  */
/*  MessageText: */
/*  */
/*   Invalid DBM data. */
/*  */
#define TLR_DIAG_E_EPL_NMT_INVALID_DBM_DATA ((TLR_RESULT)0xC0170006L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_LOCK_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of an Irq Lock failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_LOCK_CREATION_FAILED ((TLR_RESULT)0xC0170007L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_NMT_TIMER_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of timer failed. */
/*  */
#define TLR_DIAG_E_EPL_NMT_TIMER_CREATION_FAILED ((TLR_RESULT)0xC0170008L)

/*****************************************************************************/
/*  PowerLink PDO Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EPL_PDO_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_EPL_PDO_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0150001L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_PDO_PACKET_GET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Retrieving a packet from the pool failed. */
/*  */
#define TLR_DIAG_E_EPL_PDO_PACKET_GET_FAILED ((TLR_RESULT)0xC0150002L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_PDO_NMT_QUEUE_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Queue identification of the EplNmt task queue failed. */
/*  */
#define TLR_DIAG_E_EPL_PDO_NMT_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC0150003L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_PDO_SDO_QUEUE_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending to the EplSdo task queue failed. */
/*  */
#define TLR_DIAG_E_EPL_PDO_SDO_QUEUE_SEND_FAILED ((TLR_RESULT)0xC0150004L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_PDO_NMT_QUEUE_SEND_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending to the EplNmt task queue failed. */
/*  */
#define TLR_DIAG_E_EPL_PDO_NMT_QUEUE_SEND_FAILED ((TLR_RESULT)0xC0150005L)

/*****************************************************************************/
/*  PowerLink SDO Stack Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_EPL_SDO_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter. */
/*  */
#define TLR_DIAG_E_EPL_SDO_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC0160001L)

/*  */
/*  MessageId: TLR_DIAG_E_EPL_SDO_TIMER_CREATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of timer failed. */
/*  */
#define TLR_DIAG_E_EPL_SDO_TIMER_CREATION_FAILED ((TLR_RESULT)0xC0160002L)




#endif  /* __EPL_DIAG_H */

#ifndef __ETH_INF_DIAG_H
#define __ETH_INF_DIAG_H

/*****************************************************************************/
/*  Ethernet Interface Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid start-up parameter. */
/*  */
#define TLR_DIAG_E_ETH_INTF_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC05D0001L)

/*  */
/*  MessageId: TLR_DIAG_I_ETH_INTF_UNKNOWN_COMMAND_RECEIVED */
/*  */
/*  MessageText: */
/*  */
/*   Unknown command received. */
/*  */
#define TLR_DIAG_I_ETH_INTF_UNKNOWN_COMMAND_RECEIVED ((TLR_RESULT)0x405D0002L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_SEND_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to send packet. */
/*  */
#define TLR_DIAG_E_ETH_INTF_SEND_PACKET_FAILED ((TLR_RESULT)0xC05D0003L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_GET_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get packet. */
/*  */
#define TLR_DIAG_E_ETH_INTF_GET_PACKET_FAILED ((TLR_RESULT)0xC05D0004L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_PACKET_DONE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to return or release packet. */
/*  */
#define TLR_DIAG_E_ETH_INTF_PACKET_DONE_FAILED ((TLR_RESULT)0xC05D0005L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_SET_DRV_EDD_CFG */
/*  */
/*  MessageText: */
/*  */
/*   Failed to set driver EDD configuration. */
/*  */
#define TLR_DIAG_E_ETH_INTF_SET_DRV_EDD_CFG ((TLR_RESULT)0xC05D0006L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_GET_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get Ethernet buffer. */
/*  */
#define TLR_DIAG_E_ETH_INTF_GET_BUFFER   ((TLR_RESULT)0xC05D0007L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_FREE_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Failed to free Ethernet buffer. */
/*  */
#define TLR_DIAG_E_ETH_INTF_FREE_BUFFER  ((TLR_RESULT)0xC05D0008L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_SEND_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   Failed to send Ethernet buffer. */
/*  */
#define TLR_DIAG_E_ETH_INTF_SEND_BUFFER  ((TLR_RESULT)0xC05D0009L)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_GET_DRV_EDD_DIAG */
/*  */
/*  MessageText: */
/*  */
/*   Failed to get diagnostic information from driver EDD. */
/*  */
#define TLR_DIAG_E_ETH_INTF_GET_DRV_EDD_DIAG ((TLR_RESULT)0xC05D000AL)

/*  */
/*  MessageId: TLR_DIAG_E_ETH_INTF_INVALID_ETH_PORT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter for ethernet port. */
/*  */
#define TLR_DIAG_E_ETH_INTF_INVALID_ETH_PORT ((TLR_RESULT)0xC05D000BL)




#endif  /* __ETH_INF_DIAG_H */

#ifndef __MID_STARTUP_DIAG_H
#define __MID_STARTUP_DIAG_H

/*****************************************************************************/
/*  MID Startup Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_MID_STARTUP_INVALID_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid start-up parameter. */
/*  */
#define TLR_DIAG_E_MID_STARTUP_INVALID_STARTUP_PARAMETER ((TLR_RESULT)0xC05F0001L)




#endif  /* __MID_STARTUP_DIAG_H */

#ifndef __NETPLC_IO_HANDLER_DIAG_H
#define __NETPLC_IO_HANDLER_DIAG_H

/*****************************************************************************/
/*  netPLC I/O Handler diagnostics status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_MEM_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid memory address. (NULL pointer passing.) */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_MEM_ADDRESS ((TLR_RESULT)0xC0A30001L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_MEMORY ((TLR_RESULT)0xC0A30002L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   Resource initialization problem. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_RESOURCE ((TLR_RESULT)0xC0A30003L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_PARAMETER_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter value. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_PARAMETER_VALUE ((TLR_RESULT)0xC0A30004L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_STATE_MACHINE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid state. (Resetting state machine ...) */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_STATE_MACHINE ((TLR_RESULT)0xC0A30005L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_IO_OVERLAP */
/*  */
/*  MessageText: */
/*  */
/*   I/O resource overlap. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_IO_OVERLAP ((TLR_RESULT)0xC0A30006L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_ADDRESS_INFO */
/*  */
/*  MessageText: */
/*  */
/*   Invalid addressing information (PLC I/O image). */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_ADDRESS_INFO ((TLR_RESULT)0xC0A30007L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_PERIPHERAL_REF */
/*  */
/*  MessageText: */
/*  */
/*   Invalid netX peripheral reference (PIO, ADC, etc.). */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_PERIPHERAL_REF ((TLR_RESULT)0xC0A30008L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_PERIPHERAL_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid netX peripheral type. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_PERIPHERAL_TYPE ((TLR_RESULT)0xC0A30009L)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_ACCESS_RETRIES */
/*  */
/*  MessageText: */
/*  */
/*   Maximum number of retries exceeded during netX peripheral access. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_ACCESS_RETRIES ((TLR_RESULT)0xC0A3000AL)

/*  */
/*  MessageId: TLR_DIAG_E_NETPLC_IO_HANDLER_ACCESS_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout during netX peripheral access. */
/*  */
#define TLR_DIAG_E_NETPLC_IO_HANDLER_ACCESS_TIMEOUT ((TLR_RESULT)0xC0A3000BL)




#endif  /* __NETPLC_IO_HANDLER_DIAG_H */

#ifndef __OMB_OMBAPTASK_DIAG_H
#define __OMB_OMBAPTASK_DIAG_H

/*****************************************************************************/
/*  OMB OMBTASK Diagnostic Status codes */
/*****************************************************************************/
/*  Don't use startup-parameters - are not unique - collisions with TLR results */
/*  because of same facility TLR_UNQ_NR_OMB_OMB_AP!! */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB_AP */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBAPTASK_GOT_NO_OR_INVALID_STARTUP_PARAMETER */
/* Language        = English */
/* Got no or invalid Startup Parameter. */
/* . */
/* Language        = German */
/* Die Task hat keine oder keine gültigen Startup-Parameter bekommen. */
/* . */



#endif  /* __OMB_OMBAPTASK_DIAG_H */

#ifndef __OMB_OMBTASK_DIAG_H
#define __OMB_OMBTASK_DIAG_H

/*****************************************************************************/
/*  OMB OMBTASK Diagnostic Status codes */
/*****************************************************************************/
/*  Don't use startup-parameters - are not unique - collisions with TLR results */
/*  because of same facility TLR_UNQ_NR_OMB_OMB!! */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_GOT_NO_OR_INVALID_STARTUP_PARAMETER */
/* Language        = English */
/* Got no or invalid Startup Parameter. */
/* . */
/* Language        = German */
/* Die Task hat keine oder keine gültigen Startup-Parameter bekommen. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP */
/* Language        = English */
/* Invalid Startup Parameter ulQueElemCntAp. */
/* . */
/* Language        = German */
/* Ungültiger Startup-Parameter ulQueElemCntAp. */
/* . */
/* MessageId       = 0x0003 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/* Language        = English */
/* Invalid Startup Parameter ulPoolElemCnt. */
/* . */
/* Language        = German */
/* Ungültiger Startup-Parameter ulPoolElemCnt. */
/* . */
/* MessageId       = 0x0004 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_START_FLAGS */
/* Language        = English */
/* Invalid Startup Parameter ulStartFlags. */
/* . */
/* Language        = German */
/* Ungültiger Startup-Parameter ulStartFlags. */
/* . */
/* MessageId       = 0x0005 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_CYCLE_EVENT */
/* Language        = English */
/* Invalid Startup Parameter ulOmbCycleEvent. */
/* . */
/* Language        = German */
/* Ungültiger Startup-Parameter ulOmbCycleEvent. */
/* . */
/* MessageId       = 0x0006 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_APPLICATION_TIMER_CREATE_FAILED */
/* Language        = English */
/* Failed to create an application timer (Timer task). */
/* . */
/* Language        = German */
/* Die Erzeugung eines Application-Timers ist fehlgeschlagen (Timer-Task). */
/* . */
/* MessageId       = 0x0007 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_APPLICATION_TIMER_INIT_PACKET_FAILED */
/* Language        = English */
/* Failed to initialize a packet of application timer (Timer task). */
/* . */
/* Language        = German */
/* Die Initialisierung eines Packets des Application-Timers ist fehlgeschlagen (Timer task). */
/* . */
/* MessageId       = 0x0008 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_TCP_UDP_IDENTIFY_FAILED */
/* Language        = English */
/* Failed to identify the TCP_UDP task. */
/* . */
/* Language        = German */
/* Die Identifizierung der TCP_UDP Task ist fehlgeschlagen. */
/* . */
/* MessageId       = 0x0009 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_TCP_UDP_QUEUE_IDENTIFY_FAILED */
/* Language        = English */
/* The queue identification of TCP_UDP task queue has failed. */
/* . */
/* Language        = German */
/* Die Queue-Identifizierung der TCP_UDP Task Queue ist fehlgeschlagen. */
/* . */
/* MessageId       = 0x000A */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_OMB_OMB */
/* SymbolicName    = TLR_DIAG_E_OMB_OMBTASK_BUFFER_QUEUE_CREATE_FAILED */
/* Language        = English */
/* Creation of buffer queue failed. */
/* . */
/* Language        = German */
/* Es konnte keine Buffer-Queue erzeugt werden. */
/* . */



#endif  /* __DDL_ENPDDL_DIAG_H */

#ifndef __PROFIBUS_APM_DIAG_H
#define __PROFIBUS_APM_DIAG_H

/*****************************************************************************/
/*  PROFIBUS Master APM Diagnostic Status codes */
/*****************************************************************************/
/*****************************************************************************/
/*  Error codes 0x0000 .. 0x00FF  reserved error codes */
/*    the low byte of this error code corresponds to error codes of the */
/*    PROFIBUS stack V1 */
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_NO_FSPMM */
/*  */
/*  MessageText: */
/*  */
/*   No FSPMM-Task or -queue found to communicate. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_NO_FSPMM ((TLR_RESULT)0xC0390032L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_ADR_DOUBLE */
/*  */
/*  MessageText: */
/*  */
/*   Double station address detected. */
/*  */
#define TLR_DIAG_E_PROFIBUS_ADR_DOUBLE   ((TLR_RESULT)0xC039003AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_MAX_OUTPUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Maximum output offset reached. */
/*  */
#define TLR_DIAG_E_PROFIBUS_MAX_OUTPUT_OFFSET ((TLR_RESULT)0xC039003BL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_MAX_INPUT_OFFSET */
/*  */
/*  MessageText: */
/*  */
/*   Maximum input offset reached. */
/*  */
#define TLR_DIAG_E_PROFIBUS_MAX_INPUT_OFFSET ((TLR_RESULT)0xC039003CL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_OUTPUT_OVERLAP */
/*  */
/*  MessageText: */
/*  */
/*   Overlap in output data. */
/*  */
#define TLR_DIAG_E_PROFIBUS_OUTPUT_OVERLAP ((TLR_RESULT)0xC039003DL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_INPUT_OVERLAP */
/*  */
/*  MessageText: */
/*  */
/*   Overlap in input data. */
/*  */
#define TLR_DIAG_E_PROFIBUS_INPUT_OVERLAP ((TLR_RESULT)0xC039003EL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_WATCHDOG_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog Error. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_WATCHDOG_ERROR ((TLR_RESULT)0xC03900DCL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_AUTOCLEAR_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Autoclear activtead. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_AUTOCLEAR_ERROR ((TLR_RESULT)0xC03900DEL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_OUT_OF_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   No packet left to communicate. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_OUT_OF_PACKET ((TLR_RESULT)0xC03900E1L)

/*****************************************************************************/
/*  Error codes 0x0100 .. free error codes */
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_NO_INIT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Master state machine failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_NO_INIT_PACKET ((TLR_RESULT)0xC0390100L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_NO_SET_MODE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to set the Master mode failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_NO_SET_MODE_PACKET ((TLR_RESULT)0xC0390101L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_NO_SET_OUTPUT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to set output date fail. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_NO_SET_OUTPUT_PACKET ((TLR_RESULT)0xC0390102L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_NO_GET_INPUT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to request input data failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_NO_GET_INPUT_PACKET ((TLR_RESULT)0xC0390103L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_GET_INPUT_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Getting input data fail. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_GET_INPUT_FAIL ((TLR_RESULT)0xC0390104L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APM_SET_OUTPUT_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Write Slave output data failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APM_SET_OUTPUT_FAIL ((TLR_RESULT)0xC0390105L)




#endif  /* __PROFIBUS_APM_DIAG_H */

#ifndef __PROFIBUS_APS_DIAG_H
#define __PROFIBUS_APS_DIAG_H

/*****************************************************************************/
/*  PROFIBUS APS Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_MS0_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Slave's cyclic state machine failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_MS0_PACKET ((TLR_RESULT)0xC01D0001L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_MS1_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Slave acyclic Master Class 1 state machine failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_MS1_PACKET ((TLR_RESULT)0xC01D0002L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_MS2_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Slave acyclic Master Class 2 state machine failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_MS2_PACKET ((TLR_RESULT)0xC01D0003L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_SLAVE_DIAG_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send a Slave Diagnostic request failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_SLAVE_DIAG_PACKET ((TLR_RESULT)0xC01D0004L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_SET_CFG_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to set the new configuration data failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_SET_CFG_PACKET ((TLR_RESULT)0xC01D0005L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_USER_PRM_RESULT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send back the user parameter checking result failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_USER_PRM_RESULT_PACKET ((TLR_RESULT)0xC01D0006L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_EXT_USER_PRM_RESULT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send back the extended user parameter checking result failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_EXT_USER_PRM_RESULT_PACKET ((TLR_RESULT)0xC01D0007L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_CFG_RESULT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send back the configuration data checking result failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_CHECK_CFG_RESULT_PACKET ((TLR_RESULT)0xC01D0008L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_GET_OUTPUT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the request for getting the lastest outputs failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_GET_OUTPUT_PACKET ((TLR_RESULT)0xC01D0009L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_APPLICATION_READY_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the Applicaiton ready request failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_APPLICATION_READY_PACKET ((TLR_RESULT)0xC01D000AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_APS_NO_ABORT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the Applicaiton ready request failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_APS_NO_ABORT_PACKET ((TLR_RESULT)0xC01D000BL)




#endif  /* __PROFIBUS_APS_DIAG_H */

#ifndef __PROFIBUS_DL_DIAG_H
#define __PROFIBUS_DL_DIAG_H
/*****************************************************************************/
/*  PROFIBUS DL Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_DL_DATA_ACK_RES */
/*  */
/*  MessageText: */
/*  */
/*   Invalid "Data Ack (SDA)" response packet received. Response does not match to internally reserved communication block */
/*  */
#define TLR_DIAG_E_PROFIBUS_DL_DATA_ACK_RES ((TLR_RESULT)0xC0060001L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_DL_DATA_RES */
/*  */
/*  MessageText: */
/*  */
/*   Invalid "Data (SDN)" response packet received. Response does not match to internally reserved communication block */
/*  */
#define TLR_DIAG_E_PROFIBUS_DL_DATA_RES  ((TLR_RESULT)0xC0060002L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_DL_DATA_REPLY_RES */
/*  */
/*  MessageText: */
/*  */
/*   Invalid "Data Reply (SRD)" response packet received. Response does not match to internally reserved communication block */
/*  */
#define TLR_DIAG_E_PROFIBUS_DL_DATA_REPLY_RES ((TLR_RESULT)0xC0060003L)




#endif  /* __PROFIBUS_DL_DIAG_H */

#ifndef __PROFIBUS_FSPMM_DIAG_H
#define __PROFIBUS_FSPMM_DIAG_H

/*****************************************************************************/
/*  PROFIBUS Master APM Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_NO_INIT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Data Link failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_NO_INIT_PACKET ((TLR_RESULT)0xC0380001L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_BUS_PARAMETER_REJECTED */
/*  */
/*  MessageText: */
/*  */
/*   Command for setting the bus parameter is rejected. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_BUS_PARAMETER_REJECTED ((TLR_RESULT)0xC0380002L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_SSAP_ACTIVATE_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Activating the source SAP failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_SSAP_ACTIVATE_FAIL ((TLR_RESULT)0xC0380003L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   DMPMM state maschine is at an invalid state. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_STATE_ERROR ((TLR_RESULT)0xC0380004L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_FSPMM_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   FSPMM state maschine is at an invalid state. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_FSPMM_STATE_ERROR ((TLR_RESULT)0xC0380005L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_MSCY1M_STATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   MSCY1M state maschine is at an invalid state. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_MSCY1M_STATE_ERROR ((TLR_RESULT)0xC0380006L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_SSAP_ACTIVATE_RESPONDER_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Activate RSAP failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_SSAP_ACTIVATE_RESPONDER_FAIL ((TLR_RESULT)0xC0380007L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_NO_GLBCNTRL_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send global control failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_DMPMM_NO_GLBCNTRL_PACKET ((TLR_RESULT)0xC0380008L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_NOT_SUPPORTED */
/*  */
/*  MessageText: */
/*  */
/*   Function is not supported at the actual version of the stack. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_NOT_SUPPORTED ((TLR_RESULT)0xC0380009L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_NO_DATABASE */
/*  */
/*  MessageText: */
/*  */
/*   No database found. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_NO_DATABASE ((TLR_RESULT)0xC038000AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_INVALID_DATABASE */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Master state machine failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_INVALID_DATABASE ((TLR_RESULT)0xC038000BL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_UNKNOWN_TELEGRAM */
/*  */
/*  MessageText: */
/*  */
/*   Telegram with an unknown SAP was received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_UNKNOWN_TELEGRAM ((TLR_RESULT)0xC038000CL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_UNKNOWN_DPV1_CMD */
/*  */
/*  MessageText: */
/*  */
/*   Answer of an invalid DP V1 service received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_UNKNOWN_DPV1_CMD ((TLR_RESULT)0xC038000EL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMM_TASK_PRM_VERSION_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Ungltige Version der Task Parameter. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMM_TASK_PRM_VERSION_INVALID ((TLR_RESULT)0xC0380010L)




#endif  /* __PROFIBUS_FSPMM_DIAG_H */

#ifndef __PROFIBUS_FSPMS_DIAG_H
#define __PROFIBUS_FSPMS_DIAG_H

/*****************************************************************************/
/*  PROFIBUS FSPMS Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_INIT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Data Link Layer failed, bus parameter can not be configured. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_INIT_PACKET ((TLR_RESULT)0xC0090004L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_BUS_PARAMETER_REJECTED */
/*  */
/*  MessageText: */
/*  */
/*   The specified bus parameter are rejected by the Data Link Layer. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_BUS_PARAMETER_REJECTED ((TLR_RESULT)0xC0090005L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_RSAP_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the SAPs failed, Data Link Layer cannot be configured. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_RSAP_PACKET ((TLR_RESULT)0xC0090006L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_RSAP_ACTIVATION_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   The activation of a RSAP in the DMPMS state machine denied by the Data Link Layer. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_RSAP_ACTIVATION_DENIED ((TLR_RESULT)0xC0090007L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SAP_ACTIVATION_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   The activation of a SAP in the DMPMS state machine denied by the Data Link Layer. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SAP_ACTIVATION_DENIED ((TLR_RESULT)0xC0090008L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_SAPDEACTIVATE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to deactivate the SAPs failed, Data Link Layer cannot be configured. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_SAPDEACTIVATE_PACKET ((TLR_RESULT)0xC0090009L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SAP_DEACTIVATION_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   The deactivation of a SAP in the DMPMS state machine denied by the Data Link Layer. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SAP_DEACTIVATION_DENIED ((TLR_RESULT)0xC009000AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_START_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to start the Data Link Layer failed, Data Link Layer cannot be started. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_START_PACKET ((TLR_RESULT)0xC009000BL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_DATAEXCHANGE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to update the slaves data exchange buffer data failed, no Data Exchange update can be driven. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_DATAEXCHANGE_PACKET ((TLR_RESULT)0xC009000CL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_DIAG_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to update the slaves diagnostic data failed, no slave diag update can be driven. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_DIAG_PACKET ((TLR_RESULT)0xC009000DL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_CFG_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to update the slaves configuration data failed, no slave configuration update can be driven. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_CFG_PACKET ((TLR_RESULT)0xC009000EL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_RDINPUT_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to update the slaves input data failed, no slave input update can be driven. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_RDINPUT_PACKET ((TLR_RESULT)0xC009000FL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SETVALUE_FAILED_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Setting a specific Data Link value failed, value has not been set. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SETVALUE_FAILED_PACKET ((TLR_RESULT)0xC0090010L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_REPLY_UPDATE_FAILED_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Updating a specific reply buffer failed, buffer has not been updated. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_REPLY_UPDATE_FAILED_PACKET ((TLR_RESULT)0xC0090011L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_PRM_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the received Slave Parameter Data to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_PRM_IND_PACKET ((TLR_RESULT)0xC0090012L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_CFG_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the received Slave Configuration Data to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_CFG_IND_PACKET ((TLR_RESULT)0xC0090013L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_SLAVE_ADD_CHG_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the received Slave Set Slave Address command to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_SLAVE_ADD_CHG_IND_PACKET ((TLR_RESULT)0xC0090014L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_MINTSDR_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to configure the minTsdr-Timer failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_MINTSDR_PACKET ((TLR_RESULT)0xC0090015L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_NEW_OUTP_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the new output indication to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_NEW_OUTP_IND_PACKET ((TLR_RESULT)0xC0090016L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_GLOBAL_CONTROL_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the global control indication to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_GLOBAL_CONTROL_IND_PACKET ((TLR_RESULT)0xC0090017L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_SAP_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to initialize the Global Control SAP failed, Data Link Layer cannot be configured. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_NO_SAP_PACKET ((TLR_RESULT)0xC0090018L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_ALARM_RES_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   An Alarm response has been received while the ayclic State Machine is in "POWER-ON" state and has not been initialized yet. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_ALARM_RES_UNEXPECTED ((TLR_RESULT)0xC0090019L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_FSPMS_NO_STARTED_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send the start indication of the acyclic state machine to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_FSPMS_NO_STARTED_IND_PACKET ((TLR_RESULT)0xC009001AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_NO_RSAP_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to activate the server SAP of the acyclic state machine failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_NO_RSAP_PACKET ((TLR_RESULT)0xC009001BL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_RSAP_ACTIVATION_DENIED */
/*  */
/*  MessageText: */
/*  */
/*   The activation of a RSAP in the MSAC1S state machine denied by the Data Link Layer. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_RSAP_ACTIVATION_DENIED ((TLR_RESULT)0xC009001CL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_LSDUZERO_NORESPONSE */
/*  */
/*  MessageText: */
/*  */
/*   A DP-master network frame has been received in the MSAC1S state machine that has a zero length and no response was available. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_LSDUZERO_NORESPONSE ((TLR_RESULT)0xC009001DL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_REPLY_UPDATE_CONFIRMATION */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "OPEN" a reply update confirmation has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_REPLY_UPDATE_CONFIRMATION ((TLR_RESULT)0xC009001EL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_ALREADY_STARTED */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "OPEN" a new request to start has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_ALREADY_STARTED ((TLR_RESULT)0xC009001FL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_NO_REPLYUPDATE_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to update a response buffer failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_NO_REPLYUPDATE_PACKET ((TLR_RESULT)0xC0090020L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_REPLY_UPDATE_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Updating a response buffer within the Data Link Layer entity failed. Servce has been rejected. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_REPLY_UPDATE_ERROR ((TLR_RESULT)0xC0090021L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_WRES */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "VS-WRES" an unexpected reply update confirmation has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_WRES ((TLR_RESULT)0xC0090022L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_SRES */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "VS-SRES" an unexpected reply update confirmation has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_SRES ((TLR_RESULT)0xC0090023L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_SRES_IND */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "VS-SRES" an unexpected reply indication has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_VS_SRES_IND ((TLR_RESULT)0xC0090024L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_AA_SRES */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. In state "AA-SRES" an erroneous reply update confirmation has been received. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_STATE_CONFLICT_AA_SRES ((TLR_RESULT)0xC0090025L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_SAP_DEACTIVATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. A deactivation of an Service Access Point failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_SAP_DEACTIVATION_FAILED ((TLR_RESULT)0xC0090026L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_FSPMS_NO_ALARM_ACK_IND_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to send an Alarm Acknowledgement indication within the acyclic state machine to the application failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_FSPMS_NO_ALARM_ACK_IND_PACKET ((TLR_RESULT)0xC0090027L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_SET_SLAVE_DIAG_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   A conflict has been detected within the acyclic MSAC1S state machine. Requesting a Slave diagnostic failed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSAC1S_SET_SLAVE_DIAG_FAILED ((TLR_RESULT)0xC0090028L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_DL_ADD_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   Getting a packet from the pool to configure the new DL Address failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_NO_DL_ADD_PACKET ((TLR_RESULT)0xC0090029L)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_RETURN_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Returning a packet back to the origin failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_RETURN_PACKET_FAILED ((TLR_RESULT)0xC009002AL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_RETURN_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Returning a packet back to the origin failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_RETURN_PACKET_FAILED ((TLR_RESULT)0xC009002BL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_SEND_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_MSCY1S_SEND_PACKET_FAILED ((TLR_RESULT)0xC009002CL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SEND_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Sending a packet failed, service cannot be performed. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_DMPMS_SEND_PACKET_FAILED ((TLR_RESULT)0xC009002DL)

/*  */
/*  MessageId: TLR_DIAG_E_PROFIBUS_FSPMS_CONNECTION_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Timeout of the actual connection. */
/*  */
#define TLR_DIAG_E_PROFIBUS_FSPMS_CONNECTION_TIMEOUT ((TLR_RESULT)0xC009002EL)




#endif  /* __PROFIBUS_FSPMS_DIAG_H */

#ifndef __TCP_CONNECTOR_DIAG_H
#define __TCP_CONNECTOR_DIAG_H

/*****************************************************************************/
/*  Marshaller TCP Connector diagnostics status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_MEM_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid memory address. (NULL pointer passing.) */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_MEM_ADDRESS ((TLR_RESULT)0xC0860001L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Out of memory. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_MEMORY  ((TLR_RESULT)0xC0860002L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_RESOURCE */
/*  */
/*  MessageText: */
/*  */
/*   Resource initialization problem. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_RESOURCE ((TLR_RESULT)0xC0860003L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_PARAMETER_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid parameter value. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_PARAMETER_VALUE ((TLR_RESULT)0xC0860004L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_STATE_MACHINE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid state. (Resetting state machine ...) */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_STATE_MACHINE ((TLR_RESULT)0xC0860005L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_PROTOCOL_SUPPORT */
/*  */
/*  MessageText: */
/*  */
/*   TCP not supported by network protocol stack. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_PROTOCOL_SUPPORT ((TLR_RESULT)0xC0860006L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_ADDRESS_INFO */
/*  */
/*  MessageText: */
/*  */
/*   Invalid addressing information from network protocol stack. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_ADDRESS_INFO ((TLR_RESULT)0xC0860007L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_SERVICE_CNF */
/*  */
/*  MessageText: */
/*  */
/*   Error in service confirmation from network protocol stack. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_SERVICE_CNF ((TLR_RESULT)0xC0860008L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_SEND */
/*  */
/*  MessageText: */
/*  */
/*   Error while sending request to the network protocol stack. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_SEND    ((TLR_RESULT)0xC0860009L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_MAX_RETRIES */
/*  */
/*  MessageText: */
/*  */
/*   Maximum number of service retries exceeded. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_MAX_RETRIES ((TLR_RESULT)0xC086000AL)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_CONNECTOR_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Remote connection timeout. */
/*  */
#define TLR_DIAG_E_TCP_CONNECTOR_TIMEOUT ((TLR_RESULT)0xC086000BL)




#endif  /* __TCP_CONNECTOR_DIAG_H */

#ifndef __TCPIP_DIAG_H
#define __TCPIP_DIAG_H

/*****************************************************************************/
/*  TCP_UDP Diagnostic Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_DIAG_E_TCP_ERR_TASK_PROCESS_TERMINATED */
/*  */
/*  MessageText: */
/*  */
/*   The task process was terminated with error - see task status. */
/*  */
#define TLR_DIAG_E_TCP_ERR_TASK_PROCESS_TERMINATED ((TLR_RESULT)0xC0080001L)

/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_DIAG_E_TCP_ERR_INIT_RESET_CYCLE */
/* Language        = English */
/* Failed to reset the cyclic event. */
/* . */
/* Language        = German */
/* Das Reseten des zyklischen Events ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_DIAG_E_TCP_ERR_CODEDIAG_FATAL */
/*  */
/*  MessageText: */
/*  */
/*   A fatal error is occured. Terminate the task. */
/*  */
#define TLR_DIAG_E_TCP_ERR_CODEDIAG_FATAL ((TLR_RESULT)0xC0080003L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_TASK_F_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   Task is not initialized. */
/*  */
#define TLR_DIAG_E_TCP_TASK_F_NOT_INITIALIZED ((TLR_RESULT)0xC0080004L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_TASK_F_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the task. */
/*   Accept Init packets and Config packets only. */
/*  */
#define TLR_DIAG_E_TCP_TASK_F_INITIALIZATION_FAILED ((TLR_RESULT)0xC0080005L)

/*  */
/*  MessageId: TLR_DIAG_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid serial number. */
/*  */
#define TLR_DIAG_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER ((TLR_RESULT)0xC0080006L)

/*  */
/*  MessageId: TLR_DIAG_E_IP_ERR_INIT_IP_INIT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the IP layer - see task status. */
/*  */
#define TLR_DIAG_E_IP_ERR_INIT_IP_INIT_ERROR ((TLR_RESULT)0xC0080007L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_ERR_INIT_OS_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The configured operating system cycletime is out of range (0.1 ms ... 20 ms). */
/*  */
#define TLR_DIAG_E_TCP_ERR_INIT_OS_CYCLETIME ((TLR_RESULT)0xC0080008L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_TCP_TASK_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_DIAG_E_TCPIP_TCP_TASK_PROCESS_CANCELED ((TLR_RESULT)0xC0080009L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_EDD_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the EDD (Ethernet Device Driver). */
/*  */
#define TLR_DIAG_E_TCPIP_EDD_IDENTIFY_FAILED ((TLR_RESULT)0xC008000AL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an application timer (Timer task). */
/*  */
#define TLR_DIAG_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC008000BL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize a packet of application timer (Timer task). */
/*  */
#define TLR_DIAG_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC008000CL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulSocketMaxCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT ((TLR_RESULT)0xC008000DL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulPoolElemCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC008000EL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddOutBufMaxCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT ((TLR_RESULT)0xC008000FL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpCacheSize. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE ((TLR_RESULT)0xC0080010L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueFreeElemCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT ((TLR_RESULT)0xC0080011L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulTcpCycleEvent. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT ((TLR_RESULT)0xC0080012L)

/*  */
/*  MessageId: TLR_DIAG_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The combination of configured operating system cycletime and TCP/IP stacks cycletime (startup-parameter */
/*   ulTcpCycleEvent) is not possible. The operating system cycletime must be smaller or equal than the */
/*   TCP/IP stacks cycletime. */
/*  */
#define TLR_DIAG_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME ((TLR_RESULT)0xC0080013L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueElemCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP ((TLR_RESULT)0xC0080014L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddQuePoolElemCnt. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT ((TLR_RESULT)0xC0080015L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulStartFlags. Unknown flags are set. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC0080016L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter pszEddName. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME ((TLR_RESULT)0xC0080017L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEddName. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME ((TLR_RESULT)0xC0080018L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEddInstance. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE ((TLR_RESULT)0xC0080019L)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEifEthIntfName. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME ((TLR_RESULT)0xC008001AL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifMode. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE ((TLR_RESULT)0xC008001BL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIFs ulEifPortStart, ulEifPortEnd. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE ((TLR_RESULT)0xC008001CL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifPortNmb. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB ((TLR_RESULT)0xC008001DL)

/*  */
/*  MessageId: TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpTimeoutCache. */
/*  */
#define TLR_DIAG_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE ((TLR_RESULT)0xC008001EL)




#endif  /* __TCPIP_DIAG_H */

#ifndef __TLR_GLOBAL_DIAG_H
#define __TLR_GLOBAL_DIAG_H
/*****************************************************************************/
/*  Common Task status codes */
/*****************************************************************************/

/*  */
/*  MessageId: TLR_DIAG_STA_OK */
/*  */
/*  MessageText: */
/*  */
/*   Task Status ok. */
/*  */
#define TLR_DIAG_STA_OK                  ((TLR_RESULT)0x00000000L)

/*  */
/*  MessageId: TLR_DIAG_STA_DISABLED */
/*  */
/*  MessageText: */
/*  */
/*   Task is currently disabled. */
/*  */
#define TLR_DIAG_STA_DISABLED            ((TLR_RESULT)0x00000001L)

/*  */
/*  MessageId: TLR_DIAG_STA_IDLE */
/*  */
/*  MessageText: */
/*  */
/*   Task is not communicating. */
/*  */
#define TLR_DIAG_STA_IDLE                ((TLR_RESULT)0x00000002L)

/*  */
/*  MessageId: TLR_DIAG_STA_INIT_LOCAL_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Task has detected an error during the initialization of its local resources. */
/*  */
#define TLR_DIAG_STA_INIT_LOCAL_FAILED   ((TLR_RESULT)0xC0000003L)

/*  */
/*  MessageId: TLR_DIAG_STA_INIT_REMOTE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Task has detected an error during the initialization of its remote resources. */
/*  */
#define TLR_DIAG_STA_INIT_REMOTE_FAILED  ((TLR_RESULT)0xC0000004L)

/*  */
/*  MessageId: TLR_DIAG_STA_SELF_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Task's self-Identification failed. */
/*  */
#define TLR_DIAG_STA_SELF_IDENTIFY_FAILED ((TLR_RESULT)0xC0000005L)

/*  */
/*  MessageId: TLR_DIAG_STA_PROCESS_QUEUE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of process queue failed. */
/*  */
#define TLR_DIAG_STA_PROCESS_QUEUE_CREATE_FAILED ((TLR_RESULT)0xC0000006L)

/*  */
/*  MessageId: TLR_DIAG_STA_PACKET_POOL_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of packet pool failed. */
/*  */
#define TLR_DIAG_STA_PACKET_POOL_CREATE_FAILED ((TLR_RESULT)0xC0000007L)

/*  */
/*  MessageId: TLR_DIAG_STA_INFO_FIELD_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of diag information field failed. */
/*  */
#define TLR_DIAG_STA_INFO_FIELD_CREATE_FAILED ((TLR_RESULT)0xC0000008L)

/*  */
/*  MessageId: TLR_DIAG_STA_INFO_FIELD_ZERO_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Creation of diag information field failed. */
/*  */
#define TLR_DIAG_STA_INFO_FIELD_ZERO_CREATE_FAILED ((TLR_RESULT)0xC0000009L)

/*  */
/*  MessageId: TLR_DIAG_STA_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   The system has not been able to provide enough memory for this task to allow creating its resources. */
/*  */
#define TLR_DIAG_STA_OUTOFMEMORY         ((TLR_RESULT)0xC000000AL)

/*  */
/*  MessageId: TLR_DIAG_STA_STARTUP_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Startup parameter of task are not defined. */
/*  */
#define TLR_DIAG_STA_STARTUP_PARAMETER   ((TLR_RESULT)0xC000000BL)

/*  */
/*  MessageId: TLR_DIAG_STA_WATCHDOG */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog error occurred. */
/*  */
#define TLR_DIAG_STA_WATCHDOG            ((TLR_RESULT)0xC000000CL)

/*  */
/*  MessageId: TLR_DIAG_STA_RESET */
/*  */
/*  MessageText: */
/*  */
/*   Reset is performed. */
/*  */
#define TLR_DIAG_STA_RESET               ((TLR_RESULT)0x4000000DL)

/*  */
/*  MessageId: TLR_DIAG_STA_CONFIGURATION */
/*  */
/*  MessageText: */
/*  */
/*   no configuration activ. */
/*  */
#define TLR_DIAG_STA_CONFIGURATION       ((TLR_RESULT)0x4000000EL)

/*  */
/*  MessageId: TLR_DIAG_STA_FATAL_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Fatal error occurred. */
/*  */
#define TLR_DIAG_STA_FATAL_ERROR         ((TLR_RESULT)0xC000000FL)

/*****************************************************************************/
/*  User Area */
/*****************************************************************************/

/*  */
/*  MessageId: TLR_DIAG_USER_CODE */
/*  */
/*  MessageText: */
/*  */
/*   User codes. */
/*  */
#define TLR_DIAG_USER_CODE               ((TLR_RESULT)0x0FF00000L)



#endif /* __TLR_GLOBAL_DIAG_H */
