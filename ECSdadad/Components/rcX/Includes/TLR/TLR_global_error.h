/******************************************************************************

  Copyright (C) 2010-2011 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_global_error.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR global error definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-08-18  NC            File updated after rebuild from latest MC files.
    2010-04-27  NC            File created.

******************************************************************************/


#ifndef __TLR_GLOBAL_ERROR_H
#define __TLR_GLOBAL_ERROR_H



/*****************************************************************************/
/*  Hilscher TLR_STATUS definitions */
/*****************************************************************************/

/*****************************************************************************/
/*  common status codes */
/*****************************************************************************/

/*  */
/*  MessageId: TLR_S_OK */
/*  */
/*  MessageText: */
/*  */
/*   Operation succeeded. */
/*  */
#define TLR_S_OK                         ((TLR_RESULT)0x00000000L)

/*  */
/*  MessageId: TLR_E_FAIL */
/*  */
/*  MessageText: */
/*  */
/*   Common error, detailed error information optionally present in the data area of packet. */
/*  */
#define TLR_E_FAIL                       ((TLR_RESULT)0xC0000001L)

/*  */
/*  MessageId: TLR_E_UNEXPECTED */
/*  */
/*  MessageText: */
/*  */
/*   Unexpected failure. */
/*  */
#define TLR_E_UNEXPECTED                 ((TLR_RESULT)0xC0000002L)

/*  */
/*  MessageId: TLR_E_OUTOFMEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Ran out of memory. */
/*  */
#define TLR_E_OUTOFMEMORY                ((TLR_RESULT)0xC0000003L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_COMMAND */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Command in Packet received. */
/*  */
#define TLR_E_UNKNOWN_COMMAND            ((TLR_RESULT)0xC0000004L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_DESTINATION */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Destination in Packet received. */
/*  */
#define TLR_E_UNKNOWN_DESTINATION        ((TLR_RESULT)0xC0000005L)

/*  */
/*  MessageId: TLR_E_UNKNOWN_DESTINATION_ID */
/*  */
/*  MessageText: */
/*  */
/*   Unknown Destination Id in Packet received. */
/*  */
#define TLR_E_UNKNOWN_DESTINATION_ID     ((TLR_RESULT)0xC0000006L)

/*  */
/*  MessageId: TLR_E_INVALID_PACKET_LEN */
/*  */
/*  MessageText: */
/*  */
/*   Packet length is invalid. */
/*  */
#define TLR_E_INVALID_PACKET_LEN         ((TLR_RESULT)0xC0000007L)

/*  */
/*  MessageId: TLR_E_INVALID_EXTENSION */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Extension in Packet received. */
/*  */
#define TLR_E_INVALID_EXTENSION          ((TLR_RESULT)0xC0000008L)

/*  */
/*  MessageId: TLR_E_INVALID_PARAMETER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Parameter in Packet found. */
/*  */
#define TLR_E_INVALID_PARAMETER          ((TLR_RESULT)0xC0000009L)

/*  */
/*  MessageId: TLR_E_INVALID_ALIGNMENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid alignment. */
/*  */
#define TLR_E_INVALID_ALIGNMENT          ((TLR_RESULT)0xC000000AL)

/*  */
/*  MessageId: TLR_E_WATCHDOG_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog error occurred. */
/*  */
#define TLR_E_WATCHDOG_TIMEOUT           ((TLR_RESULT)0xC000000CL)

/*  */
/*  MessageId: TLR_E_INVALID_LIST_TYPE */
/*  */
/*  MessageText: */
/*  */
/*   List type is invalid. */
/*  */
#define TLR_E_INVALID_LIST_TYPE          ((TLR_RESULT)0xC000000DL)

/*  */
/*  MessageId: TLR_E_UNKNOWN_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Handle is unknown. */
/*  */
#define TLR_E_UNKNOWN_HANDLE             ((TLR_RESULT)0xC000000EL)

/*  */
/*  MessageId: TLR_E_PACKET_OUT_OF_SEQ */
/*  */
/*  MessageText: */
/*  */
/*   A packet index has been not in the expected sequence. */
/*  */
#define TLR_E_PACKET_OUT_OF_SEQ          ((TLR_RESULT)0xC000000FL)

/*  */
/*  MessageId: TLR_E_PACKET_OUT_OF_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   The amount of fragmented data contained the packet sequence has been too large. */
/*  */
#define TLR_E_PACKET_OUT_OF_MEMORY       ((TLR_RESULT)0xC0000010L)

/*  */
/*  MessageId: TLR_E_QUE_PACKETDONE */
/*  */
/*  MessageText: */
/*  */
/*   The packet done function has failed. */
/*  */
#define TLR_E_QUE_PACKETDONE             ((TLR_RESULT)0xC0000011L)

/*  */
/*  MessageId: TLR_E_QUE_SENDPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The sending of a packet has failed. */
/*  */
#define TLR_E_QUE_SENDPACKET             ((TLR_RESULT)0xC0000012L)

/*  */
/*  MessageId: TLR_E_POOL_PACKET_GET */
/*  */
/*  MessageText: */
/*  */
/*   The request of a packet from packet pool has failed. */
/*  */
#define TLR_E_POOL_PACKET_GET            ((TLR_RESULT)0xC0000013L)

/*  */
/*  MessageId: TLR_E_POOL_PACKET_RELEASE */
/*  */
/*  MessageText: */
/*  */
/*   The release of a packet to packet pool has failed. */
/*  */
#define TLR_E_POOL_PACKET_RELEASE        ((TLR_RESULT)0xC0000014L)

/*  */
/*  MessageId: TLR_E_POOL_GET_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   The get packet pool load function has failed. */
/*  */
#define TLR_E_POOL_GET_LOAD              ((TLR_RESULT)0xC0000015L)

/*  */
/*  MessageId: TLR_E_QUE_GET_LOAD */
/*  */
/*  MessageText: */
/*  */
/*   The get queue load function has failed. */
/*  */
#define TLR_E_QUE_GET_LOAD               ((TLR_RESULT)0xC0000016L)

/*  */
/*  MessageId: TLR_E_QUE_WAITFORPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The waiting for a packet from queue has failed. */
/*  */
#define TLR_E_QUE_WAITFORPACKET          ((TLR_RESULT)0xC0000017L)

/*  */
/*  MessageId: TLR_E_QUE_POSTPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The posting of a packet has failed. */
/*  */
#define TLR_E_QUE_POSTPACKET             ((TLR_RESULT)0xC0000018L)

/*  */
/*  MessageId: TLR_E_QUE_PEEKPACKET */
/*  */
/*  MessageText: */
/*  */
/*   The peek of a packet from queue has failed. */
/*  */
#define TLR_E_QUE_PEEKPACKET             ((TLR_RESULT)0xC0000019L)

/*  */
/*  MessageId: TLR_E_REQUEST_RUNNING */
/*  */
/*  MessageText: */
/*  */
/*   Request is already running. */
/*  */
#define TLR_E_REQUEST_RUNNING            ((TLR_RESULT)0xC000001AL)

/*  */
/*  MessageId: TLR_E_CREATE_TIMER */
/*  */
/*  MessageText: */
/*  */
/*   Creating a timer failed. */
/*  */
#define TLR_E_CREATE_TIMER               ((TLR_RESULT)0xC000001BL)

/*  */
/*  MessageId: TLR_E_INIT_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General initialization fault. */
/*  */
#define TLR_E_INIT_FAULT                 ((TLR_RESULT)0xC0000100L)

/*  */
/*  MessageId: TLR_E_DATABASE_ACCESS_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Database access failure. */
/*  */
#define TLR_E_DATABASE_ACCESS_FAILED     ((TLR_RESULT)0xC0000101L)

/*  */
/*  MessageId: TLR_E_CIR_MASTER_PARAMETER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Master parameter can not activated at state operate. */
/*  */
#define TLR_E_CIR_MASTER_PARAMETER_FAILED ((TLR_RESULT)0xC0000102L)

/*  */
/*  MessageId: TLR_E_CIR_SLAVE_PARAMTER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Slave parameter can not activated at state operate. */
/*  */
#define TLR_E_CIR_SLAVE_PARAMTER_FAILED  ((TLR_RESULT)0xC0000103L)

/*  */
/*  MessageId: TLR_E_NOT_CONFIGURED */
/*  */
/*  MessageText: */
/*  */
/*   Configuration not available */
/*  */
#define TLR_E_NOT_CONFIGURED             ((TLR_RESULT)0xC0000119L)

/*  */
/*  MessageId: TLR_E_CONFIGURATION_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General configuration fault. */
/*  */
#define TLR_E_CONFIGURATION_FAULT        ((TLR_RESULT)0xC0000120L)

/*  */
/*  MessageId: TLR_E_INCONSISTENT_DATA_SET */
/*  */
/*  MessageText: */
/*  */
/*   Inconsistent configuration data. */
/*  */
#define TLR_E_INCONSISTENT_DATA_SET      ((TLR_RESULT)0xC0000121L)

/*  */
/*  MessageId: TLR_E_DATA_SET_MISMATCH */
/*  */
/*  MessageText: */
/*  */
/*   Configuration data set mismatch. */
/*  */
#define TLR_E_DATA_SET_MISMATCH          ((TLR_RESULT)0xC0000122L)

/*  */
/*  MessageId: TLR_E_INSUFFICIENT_LICENSE */
/*  */
/*  MessageText: */
/*  */
/*   Insufficient license. */
/*  */
#define TLR_E_INSUFFICIENT_LICENSE       ((TLR_RESULT)0xC0000123L)

/*  */
/*  MessageId: TLR_E_PARAMETER_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Parameter error. */
/*  */
#define TLR_E_PARAMETER_ERROR            ((TLR_RESULT)0xC0000124L)

/*  */
/*  MessageId: TLR_E_INVALID_NETWORK_ADDRESS */
/*  */
/*  MessageText: */
/*  */
/*   Network address invalid. */
/*  */
#define TLR_E_INVALID_NETWORK_ADDRESS    ((TLR_RESULT)0xC0000125L)

/*  */
/*  MessageId: TLR_E_NO_SECURITY_MEMORY */
/*  */
/*  MessageText: */
/*  */
/*   Security memory chip missing or broken. */
/*  */
#define TLR_E_NO_SECURITY_MEMORY         ((TLR_RESULT)0xC0000126L)

/*  */
/*  MessageId: TLR_E_NETWORK_FAULT */
/*  */
/*  MessageText: */
/*  */
/*   General communication fault. */
/*  */
#define TLR_E_NETWORK_FAULT              ((TLR_RESULT)0xC0000140L)

/*  */
/*  MessageId: TLR_E_CONNECTION_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   Connection closed. */
/*  */
#define TLR_E_CONNECTION_CLOSED          ((TLR_RESULT)0xC0000141L)

/*  */
/*  MessageId: TLR_E_CONNECTION_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Connection timeout. */
/*  */
#define TLR_E_CONNECTION_TIMEOUT         ((TLR_RESULT)0xC0000142L)

/*  */
/*  MessageId: TLR_E_LONELY_NETWORK */
/*  */
/*  MessageText: */
/*  */
/*   Lonely network. */
/*  */
#define TLR_E_LONELY_NETWORK             ((TLR_RESULT)0xC0000143L)

/*  */
/*  MessageId: TLR_E_DUPLICATE_NODE */
/*  */
/*  MessageText: */
/*  */
/*   Duplicate network address. */
/*  */
#define TLR_E_DUPLICATE_NODE             ((TLR_RESULT)0xC0000144L)

/*  */
/*  MessageId: TLR_E_CABLE_DISCONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Cable disconnected. */
/*  */
#define TLR_E_CABLE_DISCONNECT           ((TLR_RESULT)0xC0000145L)

/*  */
/*  MessageId: TLR_E_BUS_OFF */
/*  */
/*  MessageText: */
/*  */
/*   Bus Off flag is set. */
/*  */
#define TLR_E_BUS_OFF                    ((TLR_RESULT)0xC0000180L)

/*  */
/*  MessageId: TLR_E_CONFIG_LOCK */
/*  */
/*  MessageText: */
/*  */
/*   Changing configuration is not allowed. */
/*  */
#define TLR_E_CONFIG_LOCK                ((TLR_RESULT)0xC0000181L)

/*  */
/*  MessageId: TLR_E_APPLICATION_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   Application is not at ready state. */
/*  */
#define TLR_E_APPLICATION_NOT_READY      ((TLR_RESULT)0xC0000182L)

/*  */
/*  MessageId: TLR_E_RESET_IN_PROCESS */
/*  */
/*  MessageText: */
/*  */
/*   Application is performing a reset. */
/*  */
#define TLR_E_RESET_IN_PROCESS           ((TLR_RESULT)0xC0000183L)

/*  */
/*  MessageId: TLR_E_WATCHDOG_TIME_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   Watchdog time is out of range. */
/*  */
#define TLR_E_WATCHDOG_TIME_INVALID      ((TLR_RESULT)0xC0000200L)

/*  */
/*  MessageId: TLR_E_APPLICATION_ALREADY_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   Application is already registered. */
/*  */
#define TLR_E_APPLICATION_ALREADY_REGISTERED ((TLR_RESULT)0xC0000201L)

/*  */
/*  MessageId: TLR_E_NO_APPLICATION_REGISTERED */
/*  */
/*  MessageText: */
/*  */
/*   No application registered. */
/*  */
#define TLR_E_NO_APPLICATION_REGISTERED  ((TLR_RESULT)0xC0000202L)

/*  */
/*  MessageId: TLR_S_FRAGMENTED */
/*  */
/*  MessageText: */
/*  */
/*   Fragment accepted. */
/*  */
#define TLR_S_FRAGMENTED                 ((TLR_RESULT)0x0000F005L)

/*  */
/*  MessageId: TLR_E_RESET_REQUIRED */
/*  */
/*  MessageText: */
/*  */
/*   Reset required. */
/*  */
#define TLR_E_RESET_REQUIRED             ((TLR_RESULT)0xC000F006L)

/*****************************************************************************/
/*  TLR Timer Packet Status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_E_TIMER_TASK_INVALID_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Task Instance is invalid. Multiple instances of TLR Timer task are forbidden. */
/*  */
#define TLR_E_TIMER_TASK_INVALID_INSTANCE ((TLR_RESULT)0xC0020001L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_PARAM_INVALID_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Interrupt Timer Handle is invalid. */
/*  */
#define TLR_E_TIMER_IRQ_PARAM_INVALID_HANDLE ((TLR_RESULT)0xC0020002L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_PARAM_INVALID_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Interrupt Timer Reload Value is invalid. */
/*  */
#define TLR_E_TIMER_IRQ_PARAM_INVALID_VALUE ((TLR_RESULT)0xC0020003L)

/*  */
/*  MessageId: TLR_E_TIMER_IRQ_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   There is no resource to create an interrupt timer. */
/*  */
#define TLR_E_TIMER_IRQ_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC0020004L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_HANDLE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Application Timer Handle is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_HANDLE ((TLR_RESULT)0xC0020005L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_VALUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Application Timer Reload Value is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_VALUE ((TLR_RESULT)0xC0020006L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PARAM_INVALID_QUEUE */
/*  */
/*  MessageText: */
/*  */
/*   Parameter Queue Handle is invalid. */
/*  */
#define TLR_E_TIMER_APPL_PARAM_INVALID_QUEUE ((TLR_RESULT)0xC0020007L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   There is no resource to create an application timer. */
/*  */
#define TLR_E_TIMER_APPL_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC0020008L)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_RESOURCE_INSERTED */
/*  */
/*  MessageText: */
/*  */
/*   Application timer is already inserted into timer list. */
/*  */
#define TLR_E_TIMER_APPL_RESOURCE_INSERTED ((TLR_RESULT)0xC0020009L)

/*  */
/*  MessageId: TLR_E_TIMER_PACKET_RESOURCE_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   No Resource to retry sending of packet. */
/*  */
#define TLR_E_TIMER_PACKET_RESOURCE_CREATE_FAILED ((TLR_RESULT)0xC002000AL)

/*  */
/*  MessageId: TLR_E_TIMER_TASK_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   TLR Timer Task not initialized. */
/*  */
#define TLR_E_TIMER_TASK_NOT_INITIALIZED ((TLR_RESULT)0xC002000BL)

/*  */
/*  MessageId: TLR_E_TIMER_APPL_PACKET_SENT */
/*  */
/*  MessageText: */
/*  */
/*   Packet of application timer was sent to queue. */
/*  */
#define TLR_E_TIMER_APPL_PACKET_SENT     ((TLR_RESULT)0xC002000CL)

/*****************************************************************************/
/*  User Area */
/*****************************************************************************/

/*  */
/*  MessageId: TLR_S_USER_AREA */
/*  */
/*  MessageText: */
/*  */
/*   User code. */
/*  */
#define TLR_S_USER_AREA                  ((TLR_RESULT)0x0FF00000L)



#endif  /* __TLR_GLOBAL_ERROR_H */

