/******************************************************************************

  Copyright (C) 2010-2011 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Facilities.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR facilities

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-08-18  NC            File updated after rebuild from latest MC files.
    2010-04-27  NC            File created.

******************************************************************************/


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
