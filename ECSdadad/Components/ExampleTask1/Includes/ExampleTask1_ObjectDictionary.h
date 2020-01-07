/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_ObjectDictionary.h 1711 2015-12-17 12:57:15Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_ObjectDictionary.h
  Module which does all the logic to create OD and handle indications of OD
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY
#include <stdbool.h>
#include "ExampleTask1_ObjectCreator.h"
/**********************************************************************************//**
 * Typedef for ressources of ObjectDictionary* functions
 */
typedef struct OBJECT_DICTIONARY_Ttag
{
  bool (*pfnCurrenState) (EXAMPLETASK1_RSC_T* ptRsc); /**< returns true if statemashine shall be triggered again in current cycle */
  const struct COE_INIT_ODV3_Ttag* ptCurrentObject;
  const struct COE_INIT_ODV3_Ttag* ptLastObject;
  SEND_COE_CREATE_STATES_T tEnvOfSendCoeCreateObjReq;
}OBJECT_DICTIONARY_T;
#else
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTDICTIONARY_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTDICTIONARY_H_

uint32_t ObjectDictionary_Init(EXAMPLETASK1_RSC_T* ptRsc);

void ObjectDictionary_OdCreationFsm(EXAMPLETASK1_RSC_T* ptRsc);

#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTDICTIONARY_H_ */
#endif /* INCLUDE_TYPEDEF_ONLY */
