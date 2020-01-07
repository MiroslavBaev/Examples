/******************************************************************************

  Copyright (C) 2010-2011 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_global_diag.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR global diag definitions (legacy header)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-08-18  NC            File updated after rebuild from latest MC files.
    2010-04-27  NC            File created.

******************************************************************************/


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
