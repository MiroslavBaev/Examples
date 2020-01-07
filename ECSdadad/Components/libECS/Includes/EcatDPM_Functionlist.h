/**************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 **************************************************************************************

   Last Modification:
   
    @version $Id: EcatDPM_Functionlist.h 30007 2012-11-29 14:01:50Z Sven $

   Description:

    Task function list for configuration file

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2012-04-13  UJ            removed unused parameter fNoDisableBusUpdateTriggerOnHostUpdateEnabled
     2007-03-23  SB            Updated source header; Corrected Task entry function
     2007-03-21  SB            Code cleanup
**************************************************************************************/

#ifndef __ECAT_DPM_FUNCTIONLIST_H
#define __ECAT_DPM_FUNCTIONLIST_H

#include "EcsV4_Functionlist.h"

/*************************************************************************************/
/** @name Prototypes
 *
 * The following prototypes are declared to represent
 * - the entry point of task
 * @{
 */

void
TaskEnter_EcatDPM(void* pvInit);

/** @} */


/*************************************************************************************/
/** @name Task Version
 *
 * Subsequently the version of task is defined.
 */

/** version of task startup parameter */
#define ECAT_DPM_STARTUP_PARAM_VERSION (1)


/*************************************************************************************/
/** @name Startup Parameter
 *
 * The following definition represent the task startup parameter.
 * @{
 */

/** task startup parameter */
typedef struct ECAT_DPM_STARTUPPARAMETER_Ttag  ECAT_DPM_STARTUPPARAMETER_T;


/** task startup parameter
 *
 * The structure represent a set of the startup parameter, which can be defined
 * or have to be defined to configure the task.
 */
struct ECAT_DPM_STARTUPPARAMETER_Ttag    /* task startup parameter */
{
  TLR_UINT32                        ulTaskIdentifier;
  TLR_UINT32                        ulParamVersion;

  const ECS_STACK_PARAMETERS_T*     ptStackParameters;
  TLR_BOOLEAN                       fCombinedLed;   /* set to true when combined status indicator is used */
};

/** @} */


/*************************************************************************************/
#endif /* #ifndef __ECAT_DPM_FUNCTIONLIST_H */
