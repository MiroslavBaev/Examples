/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_TaskIdentifier.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR task identifier definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-27  NC            File created.

******************************************************************************/


#ifdef DO_NOT_INCLUDE_THIS_HEADER_IN_TLR_AUTOGEN_HEADERS
#ifndef __TLR_FACILITIES_H
#define __TLR_FACILITIES_H


/* /////////////////////////////////////////////////////////////////////////////////// */
/*  type definition */
/* /////////////////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////////////// */
/*  bit masks */
/* /////////////////////////////////////////////////////////////////////////////////// */
#define  TLR_STATUS_BIT_TASK_INSTANCE(n)     ((n << 28) & 0x30000000)
#define  TLR_STATUS_BIT_TASK_IDENTIFIER(n)   ((n << 16) & 0x0FFF0000)
#define  TLR_STATUS_BIT_SEVERITY_NAME(n)     ((n << 30) & 0xC0000000)



/*  */
/*   Values are 32 bit values layed out as follows: */
/*  */
/*    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 */
/*    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 */
/*   +---+---+-----------------------+-------------------------------+ */
/*   |Sev|Ins|    Unique Task ID     |             Status Code       | */
/*   +---+---+-----------------------+-------------------------------+ */
/*  */
/*   where */
/*  */
/*     Sev - is the severity code */
/*  */
/*           00 - Success */
/*           01 - Informational */
/*           10 - Warning */
/*           11 - Error */
/*  */
/*     Ins - is the Task Instance */
/*  */
/*  */
/*  */
/*     Task ID - is the unique Task ID */
/*  */
/*     Status Code - is the specific status */
/*  */
/*  */
/*  Define the facility codes */
/*  */
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
#ifndef __TLR_TASKIDENTIFIER_H
#define __TLR_TASKIDENTIFIER_H
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Hilscher TLR_TASKIDENTIFIER definitions */
/* /////////////////////////////////////////////////////////////////////////////////// */

/*  */
/*  MessageId: TLR_TASK_UNKNOWN_IDENTIFIER */
/*  */
/*  MessageText: */
/*  */
/*   The task identifier is unknown. */
/*  */
#define TLR_TASK_UNKNOWN_IDENTIFIER      ((TLR_TASKIDENTIFIER)0x00000000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TLR Timer identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   TLR Timer Task. */
/*  */
#define TLR_TASK_TIMER                   ((TLR_TASKIDENTIFIER)0x00020001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  System task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MID_SYS */
/*  */
/*  MessageText: */
/*  */
/*   Middleware System Task. */
/*  */
#define TLR_TASK_MID_SYS                 ((TLR_TASKIDENTIFIER)0x00010001L)

/*  */
/*  MessageId: TLR_TASK_MID_DBG */
/*  */
/*  MessageText: */
/*  */
/*   Middleware System Debug Backend Task. */
/*  */
#define TLR_TASK_MID_DBG                 ((TLR_TASKIDENTIFIER)0x00010002L)

/*  */
/*  MessageId: TLR_TASK_RX_IDLE */
/*  */
/*  MessageText: */
/*  */
/*   RX IDLE Task. */
/*  */
#define TLR_TASK_RX_IDLE                 ((TLR_TASKIDENTIFIER)0x00010003L)

/*  */
/*  MessageId: TLR_TASK_IRQ_HANDLER */
/*  */
/*  MessageText: */
/*  */
/*   IRQ Handler Task. */
/*  */
#define TLR_TASK_IRQ_HANDLER             ((TLR_TASKIDENTIFIER)0x00010004L)

/*  */
/*  MessageId: TLR_TASK_IDLE */
/*  */
/*  MessageText: */
/*  */
/*   Idle Task. */
/*  */
#define TLR_TASK_IDLE                    ((TLR_TASKIDENTIFIER)0x00010005L)

/*  */
/*  MessageId: TLR_TASK_BOOTUP */
/*  */
/*  MessageText: */
/*  */
/*   Bootup Task. */
/*  */
#define TLR_TASK_BOOTUP                  ((TLR_TASKIDENTIFIER)0x00010006L)

/*  */
/*  MessageId: TLR_TASK_RX_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   rcX Timer. */
/*  */
#define TLR_TASK_RX_TIMER                ((TLR_TASKIDENTIFIER)0x00010007L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT Base stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Stack. */
/*  */
#define TLR_TASK_ECAT                    ((TLR_TASKIDENTIFIER)0x00200000L)

/*  */
/*  MessageId: TLR_TASK_ECAT_ESM */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT ESM Task. */
/*  */
#define TLR_TASK_ECAT_ESM                ((TLR_TASKIDENTIFIER)0x00200001L)

/*  */
/*  MessageId: TLR_TASK_ECAT_MBX */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Mailbox Task. */
/*  */
#define TLR_TASK_ECAT_MBX                ((TLR_TASKIDENTIFIER)0x00200002L)

/*  */
/*  MessageId: TLR_TASK_ECAT_CYCLIC_IN */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Cyclic Input Task. */
/*  */
#define TLR_TASK_ECAT_CYCLIC_IN          ((TLR_TASKIDENTIFIER)0x00200003L)

/*  */
/*  MessageId: TLR_TASK_ECAT_CYCLIC_OUT */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Cyclic Output Task. */
/*  */
#define TLR_TASK_ECAT_CYCLIC_OUT         ((TLR_TASKIDENTIFIER)0x00200004L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT CoE stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_COE */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT CoE Task. */
/*  */
#define TLR_TASK_ECAT_COE                ((TLR_TASKIDENTIFIER)0x00210001L)

/*  */
/*  MessageId: TLR_TASK_ECAT_COE_PDO */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT CoE PDO Task. */
/*  */
#define TLR_TASK_ECAT_COE_PDO            ((TLR_TASKIDENTIFIER)0x00210002L)

/*  */
/*  MessageId: TLR_TASK_ECAT_COE_SDO */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT CoE SDO Task. */
/*  */
#define TLR_TASK_ECAT_COE_SDO            ((TLR_TASKIDENTIFIER)0x00210003L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT VoE stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_VOE */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT VoE Task. */
/*  */
#define TLR_TASK_ECAT_VOE                ((TLR_TASKIDENTIFIER)0x00260001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT FoE stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_FOE */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT FoE Task. */
/*  */
#define TLR_TASK_ECAT_FOE                ((TLR_TASKIDENTIFIER)0x00240001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT EoE stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_EOE */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT EoE Task. */
/*  */
#define TLR_TASK_ECAT_EOE                ((TLR_TASKIDENTIFIER)0x00230001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT SoE stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_SOE_SSC */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT SoE SSC-Task. */
/*  */
#define TLR_TASK_ECAT_SOE_SSC            ((TLR_TASKIDENTIFIER)0x00220001L)

/*  */
/*  MessageId: TLR_TASK_ECAT_SOE_IDN */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT SoE IDN-Task. */
/*  */
#define TLR_TASK_ECAT_SOE_IDN            ((TLR_TASKIDENTIFIER)0x00220002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Example Tasks */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EXAMPLE_TASK1 */
/*  */
/*  MessageText: */
/*  */
/*   Example Task 1. */
/*  */
#define TLR_TASK_EXAMPLE_TASK1           ((TLR_TASKIDENTIFIER)0x00030001L)

/*  */
/*  MessageId: TLR_TASK_EXAMPLE_TASK2 */
/*  */
/*  MessageText: */
/*  */
/*   Example Task 2. */
/*  */
#define TLR_TASK_EXAMPLE_TASK2           ((TLR_TASKIDENTIFIER)0x00040001L)

/*  */
/*  MessageId: TLR_TASK_EXAMPLE_TASK3 */
/*  */
/*  MessageText: */
/*  */
/*   Example Task 3. */
/*  */
#define TLR_TASK_EXAMPLE_TASK3           ((TLR_TASKIDENTIFIER)0x00050001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Encapsulation */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EIP_ENCAP */
/*  */
/*  MessageText: */
/*  */
/*   EthernetIP Encapsulation Task. */
/*  */
#define TLR_TASK_EIP_ENCAP               ((TLR_TASKIDENTIFIER)0x001E0001L)

/*  */
/*  MessageId: TLR_TASK_EIP_CL1 */
/*  */
/*  MessageText: */
/*  */
/*   EthernetIP Encapsulation Task Class 1 services. */
/*  */
#define TLR_TASK_EIP_CL1                 ((TLR_TASKIDENTIFIER)0x001E0002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/IP Object */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EIP_OBJECT */
/*  */
/*  MessageText: */
/*  */
/*   EthernetIP Object Task. */
/*  */
#define TLR_TASK_EIP_OBJECT              ((TLR_TASKIDENTIFIER)0x001F0001L)




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFINET IO task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PNIO_CMCTL */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Controller Context Management Task. */
/*  */
#define TLR_TASK_PNIO_CMCTL              ((TLR_TASKIDENTIFIER)0x000A0001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_CMDEV */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Context Management Task. */
/*  */
#define TLR_TASK_PNIO_CMDEV              ((TLR_TASKIDENTIFIER)0x000B0001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_ACP */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO ACP Task. */
/*  */
#define TLR_TASK_PNIO_ACP                ((TLR_TASKIDENTIFIER)0x00110001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_DCP */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO DCP Task. */
/*  */
#define TLR_TASK_PNIO_DCP                ((TLR_TASKIDENTIFIER)0x00120001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_EDD */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO EDD Task. */
/*  */
#define TLR_TASK_PNIO_EDD                ((TLR_TASKIDENTIFIER)0x000E0001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_MGT */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO Management Task. */
/*  */
#define TLR_TASK_PNIO_MGT                ((TLR_TASKIDENTIFIER)0x00130001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_APCTL */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Controller Application Task. */
/*  */
#define TLR_TASK_PNIO_APCTL              ((TLR_TASKIDENTIFIER)0x000C0001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_APDEV */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Application Task. */
/*  */
#define TLR_TASK_PNIO_APDEV              ((TLR_TASKIDENTIFIER)0x000D0001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_APCFG */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Controller Configuration Task. */
/*  */
#define TLR_TASK_PNIO_APCFG              ((TLR_TASKIDENTIFIER)0x00140001L)

/*  */
/*  MessageId: TLR_TASK_PNS_IF */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Interface Task. */
/*  */
#define TLR_TASK_PNS_IF                  ((TLR_TASKIDENTIFIER)0x00300001L)

/*  */
/*  MessageId: TLR_TASK_PNIOD_16BITIO */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device 16Bit IO Application Task. */
/*  */
#define TLR_TASK_PNIOD_16BITIO           ((TLR_TASKIDENTIFIER)0x003A0001L)

/*  */
/*  MessageId: TLR_TASK_PNS_32BITIO */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device 32Bit IO Application Task. */
/*  */
#define TLR_TASK_PNS_32BITIO             ((TLR_TASKIDENTIFIER)0x005E0001L)

/*  */
/*  MessageId: TLR_TASK_PNS_4BITIO */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device 4Bit IO Application Task. */
/*  */
#define TLR_TASK_PNS_4BITIO              ((TLR_TASKIDENTIFIER)0x00450001L)

/*  */
/*  MessageId: TLR_TASK_PNS_SOCKET_SRV */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Socket Server Task. */
/*  */
#define TLR_TASK_PNS_SOCKET_SRV          ((TLR_TASKIDENTIFIER)0x00520001L)

/*  */
/*  MessageId: TLR_TASK_PNS_EDD_HIGH */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device High Priority EDD Task. */
/*  */
#define TLR_TASK_PNS_EDD_HIGH            ((TLR_TASKIDENTIFIER)0x00530001L)

/*  */
/*  MessageId: TLR_TASK_PNS_EDD_LOW */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Low Priority EDD Task. */
/*  */
#define TLR_TASK_PNS_EDD_LOW             ((TLR_TASKIDENTIFIER)0x00540001L)

/*  */
/*  MessageId: TLR_TASK_PNS_SOCKET */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Socket Task. */
/*  */
#define TLR_TASK_PNS_SOCKET              ((TLR_TASKIDENTIFIER)0x00550001L)

/*  */
/*  MessageId: TLR_TASK_PNS_DCP */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device DCP Task. */
/*  */
#define TLR_TASK_PNS_DCP                 ((TLR_TASKIDENTIFIER)0x00560001L)

/*  */
/*  MessageId: TLR_TASK_PNS_CLRPC */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Connectionless RPC Task. */
/*  */
#define TLR_TASK_PNS_CLRPC               ((TLR_TASKIDENTIFIER)0x00570001L)

/*  */
/*  MessageId: TLR_TASK_PNS_IF_INTERN */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO-Device Stack Internal Interface Task. */
/*  */
#define TLR_TASK_PNS_IF_INTERN           ((TLR_TASKIDENTIFIER)0x00580001L)

/*  */
/*  MessageId: TLR_TASK_PNIO_IRT_SCHEDULER */
/*  */
/*  MessageText: */
/*  */
/*   PROFINET IO IRT Scheduler Task. */
/*  */
#define TLR_TASK_PNIO_IRT_SCHEDULER      ((TLR_TASKIDENTIFIER)0x00810001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  RPC task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_RPC_TASK */
/*  */
/*  MessageText: */
/*  */
/*   RPC Task. */
/*  */
#define TLR_TASK_RPC_TASK                ((TLR_TASKIDENTIFIER)0x002E0001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Router tasks */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ROUTER_OS_CONSOLE32 */
/*  */
/*  MessageText: */
/*  */
/*   TLR-Router OS_Console32. */
/*  */
#define TLR_TASK_ROUTER_OS_CONSOLE32     ((TLR_TASKIDENTIFIER)0x002F0000L)

/*  */
/*  MessageId: TLR_TASK_ROUTER_ECAT_VOE */
/*  */
/*  MessageText: */
/*  */
/*   TLR-Router EtherCAT VoE. */
/*  */
#define TLR_TASK_ROUTER_ECAT_VOE         ((TLR_TASKIDENTIFIER)0x002F0001L)

/*  */
/*  MessageId: TLR_TASK_ROUTER_HIF_PACKET */
/*  */
/*  MessageText: */
/*  */
/*   TLR-Router DPM. */
/*  */
#define TLR_TASK_ROUTER_HIF_PACKET       ((TLR_TASKIDENTIFIER)0x002F0002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PowerLink tasks */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EPL_NMT */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink NMT Task. */
/*  */
#define TLR_TASK_EPL_NMT                 ((TLR_TASKIDENTIFIER)0x00170000L)

/*  */
/*  MessageId: TLR_TASK_EPL_PCK */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink Packet Task. */
/*  */
#define TLR_TASK_EPL_PCK                 ((TLR_TASKIDENTIFIER)0x00170001L)

/*  */
/*  MessageId: TLR_TASK_EPL_DPM */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink DPM Task. */
/*  */
#define TLR_TASK_EPL_DPM                 ((TLR_TASKIDENTIFIER)0x00170002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PowerLink PDO task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EPL_PDO */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink PDO Task. */
/*  */
#define TLR_TASK_EPL_PDO                 ((TLR_TASKIDENTIFIER)0x00150000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PowerLink SDO task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EPL_SDO */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink SDO Task. */
/*  */
#define TLR_TASK_EPL_SDO                 ((TLR_TASKIDENTIFIER)0x00160000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PowerLink MN task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EPL_MN */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet PowerLink MN Task. */
/*  */
#define TLR_TASK_EPL_MN                  ((TLR_TASKIDENTIFIER)0x003D0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ASI_ECTRL */
/*  */
/*  MessageText: */
/*  */
/*   AS-Interface ECTRL task (ASi stack). */
/*  */
#define TLR_TASK_ASI_ECTRL               ((TLR_TASKIDENTIFIER)0x00320000L)

/*  */
/*  MessageId: TLR_TASK_ASI_AP */
/*  */
/*  MessageText: */
/*  */
/*   AS-Interface Application task (example). */
/*  */
#define TLR_TASK_ASI_AP                  ((TLR_TASKIDENTIFIER)0x00000002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCPUDP task identifiers (TCP/IP stack) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_TCPUDP */
/*  */
/*  MessageText: */
/*  */
/*   TCPUDP task (TCP/IP stack). */
/*  */
#define TLR_TASK_TCPUDP                  ((TLR_TASKIDENTIFIER)0x00080000L)

/*  */
/*  MessageId: TLR_TASK_TCPIP_AP */
/*  */
/*  MessageText: */
/*  */
/*   TCP/IP stack Application task (example). */
/*  */
#define TLR_TASK_TCPIP_AP                ((TLR_TASKIDENTIFIER)0x00000001L)

/*  */
/*  MessageId: TLR_TASK_TCPIP_SOCKIF */
/*  */
/*  MessageText: */
/*  */
/*   TCP/IP Socket Interface. */
/*  */
#define TLR_TASK_TCPIP_SOCKIF            ((TLR_TASKIDENTIFIER)0x00740002L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SERCOS III task identifiers (Slave) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_API */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII API task. */
/*  */
#define TLR_TASK_SERCOSIII_API           ((TLR_TASKIDENTIFIER)0x00340000L)

/*  */
/*  MessageId: TLR_TASK_SERCOSIII_DL */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII DL task. */
/*  */
#define TLR_TASK_SERCOSIII_DL            ((TLR_TASKIDENTIFIER)0x00350000L)

/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SVC */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII SVC task. */
/*  */
#define TLR_TASK_SERCOSIII_SVC           ((TLR_TASKIDENTIFIER)0x00330000L)

/*  */
/*  MessageId: TLR_TASK_SERCOSIII_ETH */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII ETH task. */
/*  */
#define TLR_TASK_SERCOSIII_ETH           ((TLR_TASKIDENTIFIER)0x00360000L)

/*  */
/*  MessageId: TLR_TASK_SERCOSIII_NRT */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII NRT task. */
/*  */
#define TLR_TASK_SERCOSIII_NRT           ((TLR_TASKIDENTIFIER)0x00360001L)

/*  */
/*  MessageId: TLR_TASK_SERCOSIII_CYCLIC */
/*  */
/*  MessageText: */
/*  */
/*   SERCOSIII cyclic task. */
/*  */
#define TLR_TASK_SERCOSIII_CYCLIC        ((TLR_TASKIDENTIFIER)0x00370000L)




/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIBUS_DL */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS Data Link Layer Task. */
/*  */
#define TLR_TASK_PROFIBUS_DL             ((TLR_TASKIDENTIFIER)0x00060000L)

/*  */
/*  MessageId: TLR_TASK_PROFIBUS_FSPMS */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS Slave Fieldbus Service Protocol Machine Task. */
/*  */
#define TLR_TASK_PROFIBUS_FSPMS          ((TLR_TASKIDENTIFIER)0x00090000L)

/*  */
/*  MessageId: TLR_TASK_PROFIBUS_APS */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS Slave Application Task. */
/*  */
#define TLR_TASK_PROFIBUS_APS            ((TLR_TASKIDENTIFIER)0x001D0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS Master task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIBUS_FSPMM */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS Master Fieldbus Service Protocol Machine Task. */
/*  */
#define TLR_TASK_PROFIBUS_FSPMM          ((TLR_TASKIDENTIFIER)0x00380000L)

/*  */
/*  MessageId: TLR_TASK_PROFIBUS_APM */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS Master Application Task. */
/*  */
#define TLR_TASK_PROFIBUS_APM            ((TLR_TASKIDENTIFIER)0x00390000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIBUS Master task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SNMP_SERVER */
/*  */
/*  MessageText: */
/*  */
/*   SNMP Server Task. */
/*  */
#define TLR_TASK_SNMP_SERVER             ((TLR_TASKIDENTIFIER)0x003B0000L)

/*  */
/*  MessageId: TLR_TASK_MIB_DATABASE */
/*  */
/*  MessageText: */
/*  */
/*   MIB Database for SNMP and LLDP. */
/*  */
#define TLR_TASK_MIB_DATABASE            ((TLR_TASKIDENTIFIER)0x003C0000L)

/*  */
/*  MessageId: TLR_TASK_ICONL_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Icon-L Timer Task for iCon-L@netX. */
/*  */
#define TLR_TASK_ICONL_TIMER             ((TLR_TASKIDENTIFIER)0x002A0000L)

/*  */
/*  MessageId: TLR_TASK_ICONL_RUN */
/*  */
/*  MessageText: */
/*  */
/*   Icon-L Run Task for iCon-L@netX. */
/*  */
#define TLR_TASK_ICONL_RUN               ((TLR_TASKIDENTIFIER)0x00290000L)

/*  */
/*  MessageId: TLR_TASK_LLDP */
/*  */
/*  MessageText: */
/*  */
/*   LLDP protocol task */
/*  */
#define TLR_TASK_LLDP                    ((TLR_TASKIDENTIFIER)0x003E0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CAN task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CAN_DL */
/*  */
/*  MessageText: */
/*  */
/*   CAN DL Task (Data Link Layer). */
/*  */
#define TLR_TASK_CAN_DL                  ((TLR_TASKIDENTIFIER)0x003F0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DDL task identifiers (J060219 Bosch Rexroth DDL mit netX) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DDL_ENPDDL */
/*  */
/*  MessageText: */
/*  */
/*   ENPDDL gateway task. */
/*  */
#define TLR_TASK_DDL_ENPDDL              ((TLR_TASKIDENTIFIER)0x00400000L)

/*  */
/*  MessageId: TLR_TASK_DDL_DDL */
/*  */
/*  MessageText: */
/*  */
/*   DDL protocol task. */
/*  */
#define TLR_TASK_DDL_DDL                 ((TLR_TASKIDENTIFIER)0x00410000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Master task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CANOPEN_MASTER */
/*  */
/*  MessageText: */
/*  */
/*   CANopen Master task (CANopen Master stack). */
/*  */
#define TLR_TASK_CANOPEN_MASTER          ((TLR_TASKIDENTIFIER)0x00420000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Slave task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CANOPEN_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   CANopen Slave task (CANopen Slave stack). */
/*  */
#define TLR_TASK_CANOPEN_SLAVE           ((TLR_TASKIDENTIFIER)0x00430000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  UsbTLRRouter identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_USB_TLRROUTER */
/*  */
/*  MessageText: */
/*  */
/*   Usb-TLR-Router Task (Usb-TLRRouter). */
/*  */
#define TLR_TASK_USB_TLRROUTER           ((TLR_TASKIDENTIFIER)0x00440000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CAN DL AP sample identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CANDL_APSAMPLE */
/*  */
/*  MessageText: */
/*  */
/*   CAN DL application sample Task. */
/*  */
#define TLR_TASK_CANDL_APSAMPLE          ((TLR_TASKIDENTIFIER)0x00460000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DeviceNet FAL (Fieldbus Application Layer) task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DEVNET_FAL */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet FAL Task (Fieldbus Application Layer). */
/*  */
#define TLR_TASK_DEVNET_FAL              ((TLR_TASKIDENTIFIER)0x00470000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DeviceNet AP task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DEVNET_AP */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet AP Task (Application). */
/*  */
#define TLR_TASK_DEVNET_AP               ((TLR_TASKIDENTIFIER)0x005B0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ObjectDictionary V2 DPM Adapter */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DPM_OD2 */
/*  */
/*  MessageText: */
/*  */
/*   Object Dictionary DPM-Adapter Task. */
/*  */
#define TLR_TASK_DPM_OD2                 ((TLR_TASKIDENTIFIER)0x00480000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Master application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CANOPEN_APM */
/*  */
/*  MessageText: */
/*  */
/*   CANopen Master Application Task. */
/*  */
#define TLR_TASK_CANOPEN_APM             ((TLR_TASKIDENTIFIER)0x00490000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Slave application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CANOPEN_APS */
/*  */
/*  MessageText: */
/*  */
/*   CANopen Slave Application Task. */
/*  */
#define TLR_TASK_CANOPEN_APS             ((TLR_TASKIDENTIFIER)0x004A0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Sercos3 Slave application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOS_SL */
/*  */
/*  MessageText: */
/*  */
/*   Sercos3 Slave Task. */
/*  */
#define TLR_TASK_SERCOS_SL               ((TLR_TASKIDENTIFIER)0x004B0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ECAT Slave DPM application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_DPM */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Slave DPM Task. */
/*  */
#define TLR_TASK_ECAT_DPM                ((TLR_TASKIDENTIFIER)0x004C0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ECAT Slave InxAp application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECAT_INXAP */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Slave InxAp Task. */
/*  */
#define TLR_TASK_ECAT_INXAP              ((TLR_TASKIDENTIFIER)0x004C0001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave Communication task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SL_COM */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Slave Communication Task. */
/*  */
#define TLR_TASK_SERCOSIII_SL_COM        ((TLR_TASKIDENTIFIER)0x004E0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave Sercice Channel task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SL_SVC */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Slave Service Channel Task. */
/*  */
#define TLR_TASK_SERCOSIII_SL_SVC        ((TLR_TASKIDENTIFIER)0x004F0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave Real Time Data task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SL_RTD */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Slave Real Time Data Task. */
/*  */
#define TLR_TASK_SERCOSIII_SL_RTD        ((TLR_TASKIDENTIFIER)0x00500000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave Application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SL_AP */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Slave Application Task. */
/*  */
#define TLR_TASK_SERCOSIII_SL_AP         ((TLR_TASKIDENTIFIER)0x00510000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Slave IDN task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIII_SL_IDN */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Slave IDN Task. */
/*  */
#define TLR_TASK_SERCOSIII_SL_IDN        ((TLR_TASKIDENTIFIER)0x00850000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/Ip Adapter Application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EIP_APS */
/*  */
/*  MessageText: */
/*  */
/*   EtherNet/Ip Adapter Application-Task. */
/*  */
#define TLR_TASK_EIP_APS                 ((TLR_TASKIDENTIFIER)0x00590000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet/Ip Scanner Application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EIP_APM */
/*  */
/*  MessageText: */
/*  */
/*   EtherNet/Ip Scanner Application-Task. */
/*  */
#define TLR_TASK_EIP_APM                 ((TLR_TASKIDENTIFIER)0x005A0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet Interface Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ETH_INTF */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet Interface Task. */
/*  */
#define TLR_TASK_ETH_INTF                ((TLR_TASKIDENTIFIER)0x005D0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MID Startup Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MID_STARTUP */
/*  */
/*  MessageText: */
/*  */
/*   MID Startup Task. */
/*  */
#define TLR_TASK_MID_STARTUP             ((TLR_TASKIDENTIFIER)0x005F0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  OMB task identifiers (Open Modbus TCP) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_OMB_OMBTASK */
/*  */
/*  MessageText: */
/*  */
/*   OMB task (Open Modbus TCP). */
/*  */
#define TLR_TASK_OMB_OMBTASK             ((TLR_TASKIDENTIFIER)0x00600000L)

/*  */
/*  MessageId: TLR_TASK_OMB_OMBAPTASK */
/*  */
/*  MessageText: */
/*  */
/*   OMB task (Open Modbus TCP) Application task. */
/*  */
#define TLR_TASK_OMB_OMBAPTASK           ((TLR_TASKIDENTIFIER)0x00610001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DNS task identifiers (DeviceNet Slave) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DNS_FAL */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet Slave FAL Task (Fieldbus Application Layer). */
/*  */
#define TLR_TASK_DNS_FAL                 ((TLR_TASKIDENTIFIER)0x00620000L)

/*  */
/*  MessageId: TLR_TASK_DNS_AP */
/*  */
/*  MessageText: */
/*  */
/*   DeviceNet Slave AP Task (Dualport Application). */
/*  */
#define TLR_TASK_DNS_AP                  ((TLR_TASKIDENTIFIER)0x00630000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  EtherCAT Master AP Task identifiers (EtherCAT Master AP Task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ETHERCAT_MASTER_AP */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Master AP Task. */
/*  */
#define TLR_TASK_ETHERCAT_MASTER_AP      ((TLR_TASKIDENTIFIER)0x00640000L)

/*  */
/*  MessageId: TLR_TASK_ETHERCAT_MASTER */
/*  */
/*  MessageText: */
/*  */
/*   EtherCAT Master Stack Task. */
/*  */
#define TLR_TASK_ETHERCAT_MASTER         ((TLR_TASKIDENTIFIER)0x00650000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Ethernet Analyzer Transfer Task identifiers (Ethernet Analyzer Transfer Task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_AN_TRANS */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet Analyzer Transfer Task. */
/*  */
#define TLR_TASK_AN_TRANS                ((TLR_TASKIDENTIFIER)0x00660000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Profibus MPI */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIBUS_MPI */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS MPI Task. */
/*  */
#define TLR_TASK_PROFIBUS_MPI            ((TLR_TASKIDENTIFIER)0x00670000L)

/*  */
/*  MessageId: TLR_TASK_PROFIBUS_MPI_AP */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS MPI Application Task. */
/*  */
#define TLR_TASK_PROFIBUS_MPI_AP         ((TLR_TASKIDENTIFIER)0x00680000L)

/*  */
/*  MessageId: TLR_TASK_PROFIBUS_MPI_RFC */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS MPI Task. */
/*  */
#define TLR_TASK_PROFIBUS_MPI_RFC        ((TLR_TASKIDENTIFIER)0x00730000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Profibus FSPMM2 */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIBUS_FSPMM2 */
/*  */
/*  MessageText: */
/*  */
/*   PROFIBUS FSPMM2 Task. */
/*  */
#define TLR_TASK_PROFIBUS_FSPMM2         ((TLR_TASKIDENTIFIER)0x00690000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CC-Link Slave */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CCLINK_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   CC-Link Slave Task. */
/*  */
#define TLR_TASK_CCLINK_SLAVE            ((TLR_TASKIDENTIFIER)0x006A0000L)

/*  */
/*  MessageId: TLR_TASK_CCLINK_APS */
/*  */
/*  MessageText: */
/*  */
/*   CC-Link Slave Application Task. */
/*  */
#define TLR_TASK_CCLINK_APS              ((TLR_TASKIDENTIFIER)0x006B0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Lenze EtherCAT Slave Anbindung */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ECS_LENZE_MAIN */
/*  */
/*  MessageText: */
/*  */
/*   Lenze EtherCAT slave interface for 9400, main task. */
/*  */
#define TLR_TASK_ECS_LENZE_MAIN          ((TLR_TASKIDENTIFIER)0x006C0000L)

/*  */
/*  MessageId: TLR_TASK_ECS_LENZE_BRIDGE */
/*  */
/*  MessageText: */
/*  */
/*   Lenze EtherCAT slave interface for 9400, bus bridge. */
/*  */
#define TLR_TASK_ECS_LENZE_BRIDGE        ((TLR_TASKIDENTIFIER)0x006C0001L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  IO-Link Master Task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_IOLINK_MASTER */
/*  */
/*  MessageText: */
/*  */
/*   IO-Link Master Task. */
/*  */
#define TLR_TASK_IOLINK_MASTER           ((TLR_TASKIDENTIFIER)0x006D0000L)

/*  */
/*  MessageId: TLR_TASK_IOLINK_AL */
/*  */
/*  MessageText: */
/*  */
/*   IO-Link Application Layer Task. */
/*  */
#define TLR_TASK_IOLINK_AL               ((TLR_TASKIDENTIFIER)0x00A50000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MODBUS RTU */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MODBUS_RTU */
/*  */
/*  MessageText: */
/*  */
/*   MODBUS RTU Task. */
/*  */
#define TLR_TASK_MODBUS_RTU              ((TLR_TASKIDENTIFIER)0x006E0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Master stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SIII_MA_CP */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Communication Phase Task */
/*  */
#define TLR_TASK_SIII_MA_CP              ((TLR_TASKIDENTIFIER)0x00700000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Master stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SIII_MA_AP */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III DPM AP Task */
/*  */
#define TLR_TASK_SIII_MA_AP              ((TLR_TASKIDENTIFIER)0x00720000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Master stack task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIIIMASTER_SVC */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III Service Channel Task */
/*  */
#define TLR_TASK_SERCOSIIIMASTER_SVC     ((TLR_TASKIDENTIFIER)0x00710000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SSIO task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SSIO */
/*  */
/*  MessageText: */
/*  */
/*   Serial Shift IO Task */
/*  */
#define TLR_TASK_SSIO                    ((TLR_TASKIDENTIFIER)0x00750000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SSIO AP task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SSIO_AP */
/*  */
/*  MessageText: */
/*  */
/*   Serial Shift IO Application Task */
/*  */
#define TLR_TASK_SSIO_AP                 ((TLR_TASKIDENTIFIER)0x00760000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MAP NIC task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MEMORY_MAP */
/*  */
/*  MessageText: */
/*  */
/*   netIC Mapping Task */
/*  */
#define TLR_TASK_MEMORY_MAP              ((TLR_TASKIDENTIFIER)0x00770000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  MPI Gateway task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MPI_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   MPI Gateway Task */
/*  */
#define TLR_TASK_MPI_GATEWAY             ((TLR_TASKIDENTIFIER)0x00780000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Master stack NRT task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERCOSIIIMASTER_NRT */
/*  */
/*  MessageText: */
/*  */
/*   Sercos III NRT Channel Task */
/*  */
#define TLR_TASK_SERCOSIIIMASTER_NRT     ((TLR_TASKIDENTIFIER)0x00790000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface Master task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ASI_MASTER */
/*  */
/*  MessageText: */
/*  */
/*   AS-Interface Master Task (AS-Interface Master stack). */
/*  */
#define TLR_TASK_ASI_MASTER              ((TLR_TASKIDENTIFIER)0x007A0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  AS-Interface Master application task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ASI_APM */
/*  */
/*  MessageText: */
/*  */
/*   AS-Interface Master Application Task. */
/*  */
#define TLR_TASK_ASI_APM                 ((TLR_TASKIDENTIFIER)0x007B0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CompoNet Slave task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_COMPONET_SLAVE */
/*  */
/*  MessageText: */
/*  */
/*   CompoNet Slave Task. */
/*  */
#define TLR_TASK_COMPONET_SLAVE          ((TLR_TASKIDENTIFIER)0x007C0000L)

/*  */
/*  MessageId: TLR_TASK_COMPONET_SLAVE_AP */
/*  */
/*  MessageText: */
/*  */
/*   CompoNet Slave Application Task. */
/*  */
#define TLR_TASK_COMPONET_SLAVE_AP       ((TLR_TASKIDENTIFIER)0x007D0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ASCII task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ASCII */
/*  */
/*  MessageText: */
/*  */
/*   ASCII Protocol Task. */
/*  */
#define TLR_TASK_ASCII                   ((TLR_TASKIDENTIFIER)0x007E0000L)

/*  */
/*  MessageId: TLR_TASK_ASCII_AP */
/*  */
/*  MessageText: */
/*  */
/*   ASCII Application Task. */
/*  */
#define TLR_TASK_ASCII_AP                ((TLR_TASKIDENTIFIER)0x007F0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netscript task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_NETSCRIPT */
/*  */
/*  MessageText: */
/*  */
/*   netScript Task. */
/*  */
#define TLR_TASK_NETSCRIPT               ((TLR_TASKIDENTIFIER)0x00800000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Marshaller task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MARSHALLER */
/*  */
/*  MessageText: */
/*  */
/*   Marshaller: Main Task. */
/*  */
#define TLR_TASK_MARSHALLER              ((TLR_TASKIDENTIFIER)0x00820000L)

/*  */
/*  MessageId: TLR_TASK_PACKET_ROUTER */
/*  */
/*  MessageText: */
/*  */
/*   Marshaller: Packet Router Task. */
/*  */
#define TLR_TASK_PACKET_ROUTER           ((TLR_TASKIDENTIFIER)0x00830000L)

/*  */
/*  MessageId: TLR_TASK_TCP_CONNECTOR */
/*  */
/*  MessageText: */
/*  */
/*   Marshaller: TCP Connection Task. */
/*  */
#define TLR_TASK_TCP_CONNECTOR           ((TLR_TASKIDENTIFIER)0x00860000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netTAP 100 Gateway task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_NT100_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   netTAP Gateway Task. */
/*  */
#define TLR_TASK_NT100_GATEWAY           ((TLR_TASKIDENTIFIER)0x00840000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Item Server task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ITEM_SERVER */
/*  */
/*  MessageText: */
/*  */
/*   Item Server Task. */
/*  */
#define TLR_TASK_ITEM_SERVER             ((TLR_TASKIDENTIFIER)0x00870000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ISaGRAF task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_ISAGRAF_LOG */
/*  */
/*  MessageText: */
/*  */
/*   telnet task for ISaGRAF log. */
/*  */
#define TLR_TASK_ISAGRAF_LOG             ((TLR_TASKIDENTIFIER)0x008C0000L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_VM */
/*  */
/*  MessageText: */
/*  */
/*   Virtual Machine ISaGRAF task. */
/*  */
#define TLR_TASK_ISAGRAF_VM              ((TLR_TASKIDENTIFIER)0x008B0000L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF command task. */
/*  */
#define TLR_TASK_ISAGRAF                 ((TLR_TASKIDENTIFIER)0x008A0000L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_ETCP */
/*  */
/*  MessageText: */
/*  */
/*   Ethernet ISaGRAF interface. */
/*  */
#define TLR_TASK_ISAGRAF_ETCP            ((TLR_TASKIDENTIFIER)0x00890000L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_ISARSI */
/*  */
/*  MessageText: */
/*  */
/*   RS232 ISaGRAF interface. */
/*  */
#define TLR_TASK_ISAGRAF_ISARSI          ((TLR_TASKIDENTIFIER)0x00880000L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_MAINTENANCE */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF maintenance task. */
/*  */
#define TLR_TASK_ISAGRAF_MAINTENANCE     ((TLR_TASKIDENTIFIER)0x008A0001L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_NTP */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF NTP task. */
/*  */
#define TLR_TASK_ISAGRAF_NTP             ((TLR_TASKIDENTIFIER)0x008A0002L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_AP */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF AP task. */
/*  */
#define TLR_TASK_ISAGRAF_AP              ((TLR_TASKIDENTIFIER)0x008A0003L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_FTP */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF FTP task. */
/*  */
#define TLR_TASK_ISAGRAF_FTP             ((TLR_TASKIDENTIFIER)0x008A0004L)

/*  */
/*  MessageId: TLR_TASK_ISAGRAF_DS */
/*  */
/*  MessageText: */
/*  */
/*   ISaGRAF DS task. */
/*  */
#define TLR_TASK_ISAGRAF_DS              ((TLR_TASKIDENTIFIER)0x008A0005L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DF1 task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_DF1 */
/*  */
/*  MessageText: */
/*  */
/*   DF1 Protocol Task. */
/*  */
#define TLR_TASK_DF1                     ((TLR_TASKIDENTIFIER)0x008D0000L)

/*  */
/*  MessageId: TLR_TASK_DF1_AP */
/*  */
/*  MessageText: */
/*  */
/*   DF1 Application Task. */
/*  */
#define TLR_TASK_DF1_AP                  ((TLR_TASKIDENTIFIER)0x008E0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  3964R task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_3964R */
/*  */
/*  MessageText: */
/*  */
/*   3964R Protocol Task. */
/*  */
#define TLR_TASK_3964R                   ((TLR_TASKIDENTIFIER)0x008F0000L)

/*  */
/*  MessageId: TLR_TASK_3964R_AP */
/*  */
/*  MessageText: */
/*  */
/*   3964R Application Task. */
/*  */
#define TLR_TASK_3964R_AP                ((TLR_TASKIDENTIFIER)0x00900000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  IO Signals task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_IO_SIGNAL */
/*  */
/*  MessageText: */
/*  */
/*   IO Signal Task. */
/*  */
#define TLR_TASK_IO_SIGNAL               ((TLR_TASKIDENTIFIER)0x00910000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  ServX task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SERVX */
/*  */
/*  MessageText: */
/*  */
/*   servX HTTP Server. */
/*  */
#define TLR_TASK_SERVX                   ((TLR_TASKIDENTIFIER)0x00920000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCPIP Application task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_TCPIP_TCP_AP */
/*  */
/*  MessageText: */
/*  */
/*   TCPUDP application task (TCP/IP stack). */
/*  */
#define TLR_TASK_TCPIP_TCP_AP            ((TLR_TASKIDENTIFIER)0x00940000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  DLR task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_EIP_DLR */
/*  */
/*  MessageText: */
/*  */
/*   EthernetIP DLR task. */
/*  */
#define TLR_TASK_EIP_DLR                 ((TLR_TASKIDENTIFIER)0x00950000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  FODMI task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_FODMI */
/*  */
/*  MessageText: */
/*  */
/*   Fibre optic diagnostic monitoring interface task. */
/*  */
#define TLR_TASK_FODMI                   ((TLR_TASKIDENTIFIER)0x00960000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIDRIVE task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIDRIVE */
/*  */
/*  MessageText: */
/*  */
/*   PROFIDRIVE task. */
/*  */
#define TLR_TASK_PROFIDRIVE              ((TLR_TASKIDENTIFIER)0x00970000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIDRIVE - PA task identifier     // not used // */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIDRIVE_PA */
/*  */
/*  MessageText: */
/*  */
/*   PROFIDRIVE parameter Access interface task. */
/*  */
#define TLR_TASK_PROFIDRIVE_PA           ((TLR_TASKIDENTIFIER)0x00980000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIDRIVE - AP task identifier     // not used // */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIDRIVE_AP */
/*  */
/*  MessageText: */
/*  */
/*   PROFIDRIVE user application task. */
/*  */
#define TLR_TASK_PROFIDRIVE_AP           ((TLR_TASKIDENTIFIER)0x009A0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PROFIDRIVE - OD task identifier      // not used // */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFIDRIVE_OD */
/*  */
/*  MessageText: */
/*  */
/*   PROFIDRIVE Object Dictionary task. */
/*  */
#define TLR_TASK_PROFIDRIVE_OD           ((TLR_TASKIDENTIFIER)0x00990000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  CANopen Object Dictionary */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_CO_OBJDICT */
/*  */
/*  MessageText: */
/*  */
/*   CANopen Object Dictionary task. */
/*  */
#define TLR_TASK_CO_OBJDICT              ((TLR_TASKIDENTIFIER)0x009B0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  VARAN Client Application */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_VARAN_CLIENT_AP */
/*  */
/*  MessageText: */
/*  */
/*   VARAN Client application task. */
/*  */
#define TLR_TASK_VARAN_CLIENT_AP         ((TLR_TASKIDENTIFIER)0x009D0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  VARAN Client */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_VARAN_CLIENT */
/*  */
/*  MessageText: */
/*  */
/*   VARAN Client task. */
/*  */
#define TLR_TASK_VARAN_CLIENT            ((TLR_TASKIDENTIFIER)0x009C0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Modbus RTU Peripheral Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_MODBUS_RTU_PERIPH */
/*  */
/*  MessageText: */
/*  */
/*   Modbus RTU Peripheral Task. */
/*  */
#define TLR_TASK_MODBUS_RTU_PERIPH       ((TLR_TASKIDENTIFIER)0x009E0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Profinet RTA Task */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_PROFINET_RTA */
/*  */
/*  MessageText: */
/*  */
/*   Profinet RTA (RealTime Acyclic) Task. */
/*  */
#define TLR_TASK_PROFINET_RTA            ((TLR_TASKIDENTIFIER)0x009F0000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  SercosIII Internet Protocol Service(SIP) task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_SIII_SIP */
/*  */
/*  MessageText: */
/*  */
/*   SercosIII Internet Protocol Service Task. */
/*  */
#define TLR_TASK_SIII_SIP                ((TLR_TASKIDENTIFIER)0x00A00000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  3S CodeSys PLC Handler task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_3S_PLC_HANDLER */
/*  */
/*  MessageText: */
/*  */
/*   3S CodeSys PLC Handler Task. */
/*  */
#define TLR_TASK_3S_PLC_HANDLER          ((TLR_TASKIDENTIFIER)0x00A10000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  3S CodeSys PLC Handler AP task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_3S_PLC_HANDLER_AP */
/*  */
/*  MessageText: */
/*  */
/*   3S CodeSys PLC Handler AP Task. */
/*  */
#define TLR_TASK_3S_PLC_HANDLER_AP       ((TLR_TASKIDENTIFIER)0x00A20000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  netPLC I/O Handler task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_NETPLC_IO_HANDLER */
/*  */
/*  MessageText: */
/*  */
/*   netPLC I/O Handler. */
/*  */
#define TLR_TASK_NETPLC_IO_HANDLER       ((TLR_TASKIDENTIFIER)0x00A30000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  PowerLink MN task identifiers */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN Task */
/*  */
#define TLR_TASK_POWERLINK_MN_TASK       ((TLR_TASKIDENTIFIER)0x00A40000L)

/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_AP_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN AP Task */
/*  */
#define TLR_TASK_POWERLINK_MN_AP_TASK    ((TLR_TASKIDENTIFIER)0x00A40001L)

/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_NEW_DATA_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN NewData Task */
/*  */
#define TLR_TASK_POWERLINK_MN_NEW_DATA_TASK ((TLR_TASKIDENTIFIER)0x00A40002L)

/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_SDO_UDP_SOCK_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN SDO UDP Socket Task */
/*  */
#define TLR_TASK_POWERLINK_MN_SDO_UDP_SOCK_TASK ((TLR_TASKIDENTIFIER)0x00A40003L)

/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_VETH_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN VirtualEthernet Task */
/*  */
#define TLR_TASK_POWERLINK_MN_VETH_TASK  ((TLR_TASKIDENTIFIER)0x00A40004L)

/*  */
/*  MessageId: TLR_TASK_POWERLINK_MN_JOB_TOKEN_TASK */
/*  */
/*  MessageText: */
/*  */
/*   PowerLink MN JobToken Task */
/*  */
#define TLR_TASK_POWERLINK_MN_JOB_TOKEN_TASK ((TLR_TASKIDENTIFIER)0x00A40005L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Recording task identifier */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_RECORDING */
/*  */
/*  MessageText: */
/*  */
/*   Recording and logging Task. */
/*  */
#define TLR_TASK_RECORDING               ((TLR_TASKIDENTIFIER)0x00A60000L)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  User Area */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  */
/*  MessageId: TLR_TASK_USER_AREA */
/*  */
/*  MessageText: */
/*  */
/*   User Area. */
/*  */
#define TLR_TASK_USER_AREA               ((TLR_TASKIDENTIFIER)0x0FF00000L)




#endif  /* __TLR_TASKIDENTIFIER_H */

