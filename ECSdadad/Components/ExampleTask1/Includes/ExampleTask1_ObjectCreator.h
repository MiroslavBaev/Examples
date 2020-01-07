/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_ObjectCreator.h 1617 2015-11-23 14:06:45Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_ObjectCreator.h
  Module which sends an create object/subobject request and does also fragment packet
  (as in DPM-API Manual)
  and fragmenting data of the packet (as in protocol api)
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATORTYPEDEF_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATORTYPEDEF_H_
#include "TLR_Includes.h"

/** Missing defines from object dictionary */
#define ECAT_OD_OBJCODE_NULL       0x00
#define ECAT_OD_OBJCODE_DOMAIN     0x02
#define ECAT_OD_OBJCODE_DEFTYPE    0x05
#define ECAT_OD_OBJCODE_DEFSTRUCT  0x06
#define ECAT_OD_OBJCODE_VAR        0x07
#define ECAT_OD_OBJCODE_ARRAY      0x08
#define ECAT_OD_OBJCODE_RECORD     0x09
#define ECAT_OD_OBJCODE_ENUM       0x28

#define COE_ODV3_VALUE_INFO_MASK  0x84

#define PDO_MAP_ENTRY(index, subindex, length) (((index) << 16) | ((subindex) << 8) | (length))

typedef struct COE_INIT_ODV3_Ttag
{
  TLR_UINT32              ulCmd;
  TLR_UINT16              usIndex;
  TLR_UINT8               bSubIndex;
  TLR_UINT32              ulCount;

  TLR_UINT8               bMaxNumOfSubObjs;
  TLR_UINT8               bObjectCode;
  TLR_UINT16              usAccessFlags;
  TLR_UINT8               bValueInfo;
  TLR_UINT8               bIndicationFlags;
  TLR_UINT16              usDatatype;
  /* following two are only evaluated on SimpleVar { */
  TLR_UINT16              usAccessRights;
  TLR_UINT32              ulMaxFieldUnits;
  /* } */
  const TLR_UINT32*       pulUnit;
  const TLR_STR*          pszName;
  void (*                 pfnNameGenerator)(TLR_UINT16  usIndex,
                                            TLR_UINT8   bSubIndex,
                                            TLR_STR*    pszNameBuf,
                                            TLR_UINT32  ulNameBufLen);
  const void*             pvMinimumValue;
  TLR_UINT32              ulMinimumValueLength;
  const void*             pvMaximumValue;
  TLR_UINT32              ulMaximumValueLength;
  const void*             pvInitialValue;
  TLR_UINT32              ulInitialValueLength;
  const void*             pvDefaultValue;
  TLR_UINT32              ulDefaultValueLength;

}COE_INIT_ODV3_T;

/**********************************************************************************//**
 * Typedef for ressources of ObjectDictionary* functions
 */
typedef enum ECS_DEMO_CALLTYPE_Etag
{
  ECS_DEMO_CT_INIT,
  ECS_DEMO_CT_FRAG,
}ECS_DEMO_CALLTYPE_E;

typedef struct SEND_COE_CREATE_STATES_Ttag
{
  ECS_DEMO_CALLTYPE_E eCallType;
  uint32_t ulDestId;
  uint32_t ulPartState;
  uint32_t ulPartPos;
  uint32_t ulTotalDataBytes;
  uint32_t ulTransferredDataBytes;
  uint32_t ulNameLength;
  uint32_t ulFragmentPos;
  uint8_t* pbMinimumValue;
  uint8_t* pbMaximumValue;
  uint8_t* pbDefaultValue;
  uint8_t* pbInitialValue;
  uint8_t  bValueInfo;
  char*    pszCreateName;
}SEND_COE_CREATE_STATES_T;

#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATORTYPEDEF_H_ */
#else
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATOR_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATOR_H_
#include <stdbool.h>

uint32_t ObjectCreator_SendCoeCreateObjReq(EXAMPLETASK1_RSC_T* ptRsc,
                                        const COE_INIT_ODV3_T* ptOdEntry,
                                                         bool* pfProcessingFinished);

#endif /* INCLUDE_TYPEDEF_ONLY */
#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_OBJECTCREATOR_H_ */
