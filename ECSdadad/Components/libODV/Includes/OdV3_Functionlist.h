/**************************************************************************************
 Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OdV3_Functionlist.h 3097 2015-11-10 09:46:16Z Sven $:


Changes:
 Date          Description
 -----------------------------------------------------------------------------------
 2011-05-09    cleaned up function prototypes
 **************************************************************************************/

#ifndef _ODV3_FUNCTIONLIST_H
#define _ODV3_FUNCTIONLIST_H


/*************************************************************************************/
/** @name Compatibility modules
 *
 * @{
 */

void OdV3_Compatibility_Ecs(void* pvRsc,
                            void* pvPck);
void OdV3_Compatibility_Pls(void* pvRsc,
                            void* pvPck);

/** @} */

/*************************************************************************************/
/** @name Task Version
 *
 * Subsequently the version of task is defined.
 */

/** version of task startup parameter */
#define ODV3_STARTUP_PARAM_VERSION_V1 (1)


/*************************************************************************************/
/** @name Startup Parameter
 *
 * The following definition represent the task startup parameter.
 * @{
 */

/** task startup parameter */
typedef struct ODV3_STARTUPPARAMETER_Ttag  ODV3_STARTUPPARAMETER_T;

typedef struct ODV3_PARAMETERS_TASK_Ttag
{
  TLR_STR                           abName[16];
  TLR_UINT32                        ulThreshold;
  TLR_UINT32                        ulPriority;
  TLR_UINT32                        ulToken;
} ODV3_PARAMETERS_TASK_T;

typedef enum ODV3_OD_INIT_TYPE_Etag
{
  ODV3_OD_INIT_END,
  ODV3_OD_INIT_DATATYPE
} ODV3_OD_INIT_TYPE_E;

typedef struct ODV3_OD_VAL_INIT_Ttag
{
  TLR_UINT32                ulBitLength;
  void*                     pvDataValue;
} ODV3_OD_VAL_INIT_T;

typedef struct ODV3_OD_INIT_Ttag
{
  ODV3_OD_INIT_TYPE_E       eInitType;

  TLR_UINT16                usDataType;
  TLR_UINT32                ulDataBitLength;
} ODV3_OD_INIT_T;

/** task startup parameter
 *
 * The structure represent a set of the startup parameter, which can be defined
 * or have to be defined to configure the task.
 */
struct ODV3_STARTUPPARAMETER_Ttag    /* task startup parameter */
{
  void (*                     pfnCompatibilityModule)(void*, void*);
  TLR_UINT32                  ulInstance;
  TLR_STR                     abQueName[16];
  TLR_STR                     abPoolName[16];
  ODV3_PARAMETERS_TASK_T      tOdTask;
  const ODV3_OD_INIT_T*       ptOdInit;
  TLR_UINT32                  ulResetObjDictCheckSrc;
  /* check function to adjust for simple variable bSubIndex */
  TLR_RESULT (*               pfnCheckSimpleVarSubIndex)(TLR_UINT8 bSubIndex);
  TLR_UINT32                  ulResetObjectsCheckSrc;
};

TLR_RESULT
OdV3_CheckSimpleVarSubIndex_CANopen(TLR_UINT8 bSubIndex);
#define OdV3_CheckSimpleVarSubIndex_ECS OdV3_CheckSimpleVarSubIndex_CANopen
TLR_RESULT
OdV3_CheckSimpleVarSubIndex_PLS(TLR_UINT8 bSubIndex);

/** @} */

/*************************************************************************************/
/** @name Prototypes
 *
 * The following prototypes are declared to represent
 * - the entry point of task
 * @{
 */

typedef struct ODV3_Ttag
{
  TLR_HANDLE                  hQue;
} ODV3_T;

TLR_RESULT
OdV3_StackInitialize(   const ODV3_STARTUPPARAMETER_T*  ptStartupParam,
                        ODV3_T**                        pptOdV3);

TLR_RESULT
OdV3_StackDeinitialize( ODV3_T*                         ptOdV3);

/** @} */


#endif
