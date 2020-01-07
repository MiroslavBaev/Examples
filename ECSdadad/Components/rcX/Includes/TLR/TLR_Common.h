/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_Common.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR common definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-27  VD            Moved all TLR_TASK_UID_xx back to TLR_Types.h
                              Moved TLR_TASK_UID_T back to TLR_Types.h

    2010-04-14  NC            Adapted TLR_TASK_ENTER and TLR_TASK_LEAVE to
                              rX_SysCreateTask() function pointer types
  
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_COMMON_H
#define __TLR_COMMON_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/


#include "TLR_Types.h"          /* basic TLR data type definitions */



/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/

/***************************** task state codes ******************************/

#define TLR_TASK_STATE_CANCELED                 (0x0000)
#define TLR_TASK_STATE_RUNNING                  (0x0001)
#define TLR_TASK_STATE_INIT                     (0x0002)
#define TLR_TASK_USER_SPECIFIC                  (0x0100)
#define TLR_TASK_STATE_MAX_STATE                (0xFFFF)



/*****************************************************************************/
/* Class, Type, and Structure Definitions                                    */
/*****************************************************************************/


/* task state code */
typedef TLR_UINT32  TLR_TASK_STATE;
typedef TLR_UINT32  TLR_TASKIDENTIFIER;

typedef struct TLR_TASK_Ttag
{
  TLR_VOID*   pvOSDependent;
  TLR_STR     szName[16];
  TLR_UINT32  ulPriority;  
} TLR_TASK_T;


/* function pointer prototypes for task entry points */
typedef TLR_VOID (*TLR_TASK_ENTER) (TLR_VOID* pvStartParams);
typedef TLR_VOID (*TLR_TASK_LEAVE) (TLR_VOID* pvLeaveParams);



/*****************************************************************************/
/* Global Variables                                                          */
/*****************************************************************************/


/* none */



/*****************************************************************************/
/* Macros                                                                    */
/*****************************************************************************/


/* none */



/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/


/* none */



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_COMMON_H */
