/**********************************************************************************//**
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided  together with this
  project!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/
/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_ObjectDictionary.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_ObjectDictionary.c
  Module which does all the logic to create OD and handle indications of OD
**************************************************************************************/
#include "ExampleTask1_Resources.h"
#include "ExampleTask1_Functions.h" /* for ExampleTask1_SendRcxRegisterAppReq() */
#include "ExampleTask1_ObjectDictionary.h"
#include "ExampleTask1_ObjectCreator.h"
#include "OdV3_Public.h"

#define member_size(type, member) sizeof(((type *)0)->member)

#define PDO_MAP_ENTRY(index, subindex, length) (((index) << 16) | ((subindex) << 8) | (length))

#if !CREATE_PDO_MAPPING_DYNAMICALLY
static TLR_UINT8 s_bOutputNumElements = 2;
static TLR_UINT8 s_bInputNumElements = 2;

static TLR_UINT32 s_aulRxPdoMapping[2] =
{
    PDO_MAP_ENTRY(0x2000, 1, 8),
    PDO_MAP_ENTRY(0x2000, 2, 8)
};

static TLR_UINT32 s_aulTxPdoMapping[2] =
{
    PDO_MAP_ENTRY(0x3000, 1, 8),
    PDO_MAP_ENTRY(0x3000, 2, 8)
};
#endif

static TLR_STR s_abManufacturerDeviceName[] =      "Hilscher";
static TLR_STR s_abManufacturerHardwareVersion[] = "NXHX";
static TLR_STR s_abManufacturerSoftwareVersion[] = "NXLOM RCX ECS x.x.x.x";

static const TLR_UINT8   s_b1C00_NumElements   = 4;
static const TLR_UINT8   s_ab1C00_Elements[4]  = {1, 2, 3, 4};

static const TLR_UINT8   s_b1C12_NumElements   = 1;
static const TLR_UINT16  s_aus1C12_Elements[1] = {0x1600};

static const TLR_UINT8   s_b1C13_NumElements   = 1;
static const TLR_UINT16  s_aus1C13_Elements[1] = {0x1A00};

#define COE4000_NUM_OF_ELEMENTS  6
static const TLR_UINT8   s_b4000_NumElements = COE4000_NUM_OF_ELEMENTS;
static const TLR_UINT8   s_bOctetStringInitialValue[] = "OctetStringInitialValue";
static const TLR_UINT8   s_bBooleanInitTrueValue = 1;
static const TLR_UINT8   s_bValue55 = 0x55;
static const TLR_UINT16  s_usValue1234 = 0x1234;
static const TLR_UINT16  s_usValue55aa = 0x55AA;
static const TLR_UINT32  s_ulValue12345678 = 0x12345678;


typedef struct{ /* As described in ETG1000.6 V1.0.3 Table 65 */
  TLR_UINT32 ulIntegerValue;
  unsigned char szVisibleString[20]; /* assumption: string has 19 letters + zero*/
}ENUM_ELEMENT_T;

#define MY_ENUM_NUMELEMENTS  ( 1 + 2 ) /* 1 element for padding byte */
#define FIRST_ENUM_VALUE   (0)
#define SECOND_ENUM_VALUE  (1)
static const TLR_UINT8   s_bMyEnum_NumElements = MY_ENUM_NUMELEMENTS;
static const TLR_UINT8   s_bZero = 0;
static const ENUM_ELEMENT_T  s_EnumElements[] =
{
    { FIRST_ENUM_VALUE, "EnumElement0" },
    { SECOND_ENUM_VALUE, "EnumElement1" },
};

static const TLR_UINT32  s_ulInitialEnumValue = FIRST_ENUM_VALUE;

const COE_INIT_ODV3_T s_tOdInitTable[] =
{
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1008,
        .bSubIndex = 0,
        .pszName = "Manufacturer Device Name",
        .bObjectCode = ECAT_OD_OBJCODE_VAR,
        .ulMaxFieldUnits = sizeof(s_abManufacturerDeviceName) - 1,
        .usDatatype = ECAT_OD_DTYPE_VISIBLE_STRING,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = s_abManufacturerDeviceName,
        .ulInitialValueLength = sizeof(s_abManufacturerDeviceName) - 1,
    },
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1009,
        .bSubIndex = 0,
        .pszName = "Manufacturer Hardware Version",
        .bObjectCode = ECAT_OD_OBJCODE_VAR,
        .ulMaxFieldUnits = sizeof(s_abManufacturerHardwareVersion) - 1,
        .usDatatype = ECAT_OD_DTYPE_VISIBLE_STRING,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = s_abManufacturerHardwareVersion,
        .ulInitialValueLength = sizeof(s_abManufacturerHardwareVersion) - 1,
    },
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x100A,
        .bSubIndex = 0,
        .pszName = "Manufacturer Software Version",
        .bObjectCode = ECAT_OD_OBJCODE_VAR,
        .ulMaxFieldUnits = sizeof(s_abManufacturerSoftwareVersion) - 1,
        .usDatatype = ECAT_OD_DTYPE_VISIBLE_STRING,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = s_abManufacturerSoftwareVersion,
        .ulInitialValueLength = sizeof(s_abManufacturerSoftwareVersion) - 1,
    },
#if !CREATE_PDO_MAPPING_DYNAMICALLY
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1600,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 2,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "RxPDO 0",
        .usDatatype = ECAT_OD_DTYPE_PDO_MAPPING,
        .usAccessFlags = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1600,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_bOutputNumElements,
        .ulInitialValueLength = sizeof(s_bOutputNumElements),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1600,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_aulRxPdoMapping[0],
        .ulInitialValueLength = sizeof(s_aulRxPdoMapping[0]),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1600,
        .bSubIndex = 2,
        .pszName = "SubIndex 002",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_aulRxPdoMapping[1],
        .ulInitialValueLength = sizeof(s_aulRxPdoMapping[1]),
    },
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1A00,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 2,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "TxPDO 0",
        .usDatatype = ECAT_OD_DTYPE_PDO_MAPPING,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1A00,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_bInputNumElements,
        .ulInitialValueLength = sizeof(s_bInputNumElements),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1A00,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_aulTxPdoMapping[0],
        .ulInitialValueLength = sizeof(s_aulTxPdoMapping[0]),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1A00,
        .bSubIndex = 2,
        .pszName = "SubIndex 002",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_aulTxPdoMapping[1],
        .ulInitialValueLength = sizeof(s_aulTxPdoMapping[1]),
    },
#endif
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 4,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "Sync Manager Communication Types",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .ulMaxFieldUnits = 1,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_b1C00_NumElements),
        .pvInitialValue = &s_b1C00_NumElements
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 1,
        .pszName = "Sync Manager 0",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_ab1C00_Elements[0]),
        .pvInitialValue = &s_ab1C00_Elements[0]
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 2,
        .pszName = "Sync Manager 1",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_ab1C00_Elements[1]),
        .pvInitialValue = &s_ab1C00_Elements[1]
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 3,
        .pszName = "Sync Manager 2",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_ab1C00_Elements[2]),
        .pvInitialValue = &s_ab1C00_Elements[2]
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C00,
        .bSubIndex = 4,
        .pszName = "Sync Manager 3",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_ab1C00_Elements[3]),
        .pvInitialValue = &s_ab1C00_Elements[3]
    },

    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1C12,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 1,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "Sync Manager 2 PDO Assignment",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .bValueInfo = 0
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C12,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .ulMaxFieldUnits = 1,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_b1C12_NumElements),
        .pvInitialValue = &s_b1C12_NumElements
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C12,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_aus1C12_Elements[0]),
        .pvInitialValue = &s_aus1C12_Elements[0]
    },

    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x1C13,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 1,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "Sync Manager 3 PDO Assignment",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .bValueInfo = 0
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C13,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .ulMaxFieldUnits = 1,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_b1C13_NumElements),
        .pvInitialValue = &s_b1C13_NumElements
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x1C13,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_aus1C13_Elements[0]),
        .pvInitialValue = &s_aus1C13_Elements[0]
    },
#if !CREATE_PDO_MAPPING_DYNAMICALLY
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x2000,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 2,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "Outputs0",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x2000,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_bOutputNumElements,
        .ulInitialValueLength = sizeof(s_bOutputNumElements),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x2000,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = ODV3_INDICATION_FLAGS_ON_READ,
        .usAccessRights = ECAT_OD_READ_ALL | ECAT_OD_MAPPABLE_IN_RXPDO,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x2000,
        .bSubIndex = 2,
        .pszName = "SubIndex 002",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = ODV3_INDICATION_FLAGS_ON_READ,
        .usAccessRights = ECAT_OD_READ_ALL | ECAT_OD_MAPPABLE_IN_RXPDO,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x3000,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = 2,
        .bObjectCode = ECAT_OD_OBJCODE_ARRAY,
        .pszName = "Inputs0",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x3000,
        .bSubIndex = 0,
        .pszName = "Number of elements",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .pvInitialValue = &s_bInputNumElements,
        .ulInitialValueLength = sizeof(s_bInputNumElements),
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x3000,
        .bSubIndex = 1,
        .pszName = "SubIndex 001",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = ODV3_INDICATION_FLAGS_ON_READ,
        .usAccessRights = ECAT_OD_READ_ALL | ECAT_OD_MAPPABLE_IN_TXPDO,
        .bValueInfo = 0,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x3000,
        .bSubIndex = 2,
        .pszName = "SubIndex 002",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .bIndicationFlags = ODV3_INDICATION_FLAGS_ON_READ,
        .usAccessRights = ECAT_OD_READ_ALL | ECAT_OD_MAPPABLE_IN_TXPDO,
        .bValueInfo = 0,
    },
#endif
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 0,
        .bMaxNumOfSubObjs = COE4000_NUM_OF_ELEMENTS,
        .bObjectCode = ECAT_OD_OBJCODE_RECORD,
        .pszName = "Hello World Object",
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = ODV3_ACCESS_FLAGS_CREATE_SUBINDEX_0,
        .bValueInfo = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_b4000_NumElements),
        .pvInitialValue = &s_b4000_NumElements
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 1,
        .pszName = "Octet String",
        .ulMaxFieldUnits = sizeof(s_bOctetStringInitialValue),
        .usDatatype = ECAT_OD_DTYPE_OCTET_STRING,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_bOctetStringInitialValue),
        .pvInitialValue = &s_bOctetStringInitialValue[0]
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 2,
        .pszName = "Flag 1",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_BOOLEAN,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_bBooleanInitTrueValue),
        .pvInitialValue = &s_bBooleanInitTrueValue
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 3,
        .pszName = "UINT8 Value",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_bValue55),
        .pvInitialValue = &s_bValue55
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 4,
        .pszName = "UINT16 Value",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_usValue1234),
        .pvInitialValue = &s_usValue1234,
        .ulDefaultValueLength = sizeof(s_usValue55aa),
        .pvDefaultValue = &s_usValue55aa
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 5,
        .pszName = "UINT32 Value",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .bIndicationFlags = 0,
        .ulInitialValueLength = sizeof(s_ulValue12345678),
        .pvInitialValue = &s_ulValue12345678
    },
#if !USE_ENUM_DATATAYPE
    /* SubIndex 6 "ENUM Value" have to be created after INDEX_OF_MY_ENUM is created as datatype
     * therefore it cannot be called here */
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 6,
        .pszName = "ENUM Value",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED32, /* cannot use INDEX_OF_MY_ENUM here */
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .bIndicationFlags = 0,
        .ulInitialValueLength = sizeof(s_ulInitialEnumValue),
        .pvInitialValue = &s_ulInitialEnumValue
    },
#endif
#if USE_ENUM_DATATAYPE
    /* ENUM definition of MyEnum */
    {
        .ulCmd = ODV3_CREATE_OBJECT_REQ,
        .usIndex = INDEX_OF_MY_ENUM,
        .bMaxNumOfSubObjs = MY_ENUM_NUMELEMENTS,
        .bObjectCode = ECAT_OD_OBJCODE_ENUM,
        .pszName = "MyEnum",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = ODV3_ACCESS_FLAGS_CREATE_SUBINDEX_0,
        .bValueInfo = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .ulInitialValueLength = sizeof(s_bMyEnum_NumElements),
        .pvInitialValue = &s_bMyEnum_NumElements
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = INDEX_OF_MY_ENUM,
        .bSubIndex = 1,
        .pszName = "Padding",
        .ulMaxFieldUnits = 1,
        .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_bZero),
        .pvInitialValue = &s_bZero,
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = INDEX_OF_MY_ENUM,
        .bSubIndex = 2,
        .pszName = "Enum1",
        .ulMaxFieldUnits = sizeof(s_EnumElements[0]),
        .usDatatype = ECAT_OD_DTYPE_OCTET_STRING,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_EnumElements[0]),
        .pvInitialValue = &s_EnumElements[0],
    },
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = INDEX_OF_MY_ENUM,
        .bSubIndex = 3,
        .pszName = "Enum2",
        .ulMaxFieldUnits = sizeof(s_EnumElements[1]),
        .usDatatype = ECAT_OD_DTYPE_OCTET_STRING,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_READ_ALL,
        .bValueInfo = 0,
        .ulInitialValueLength = sizeof(s_EnumElements[1]),
        .pvInitialValue = &s_EnumElements[1],
    },
#endif
};

#if USE_ENUM_DATATAYPE
/* SubIndex 6 "ENUM Value" have to be created after INDEX_OF_MY_ENUM is created as datatype
 * therefore it will be created here */
static COE_INIT_ODV3_T s_ObjectsWhichUseOwnDataType[] =
{
    {
        .ulCmd = ODV3_CREATE_SUBOBJECT_REQ,
        .usIndex = 0x4000,
        .bSubIndex = 6,
        .pszName = "ENUM Value",
        .ulMaxFieldUnits = 1,
        .usDatatype = INDEX_OF_MY_ENUM,
        .usAccessFlags = 0,
        .usAccessRights = ECAT_OD_ACCESS_ALL,
        .bValueInfo = 0,
        .bIndicationFlags = 0,
        .ulInitialValueLength = sizeof(s_EnumElements[0].ulIntegerValue),
        .pvInitialValue = &s_EnumElements[0].ulIntegerValue
    },
};
#endif

/*************************************************************************************/
static bool State_Finish(EXAMPLETASK1_RSC_T* ptRsc)
{
  /** - Sends RCX_REGISTER_APP_REQ, because Statemashine finished */
  ExampleTask1_SendRcxStartStopCommReq(ptRsc);
  return false;
}

/*************************************************************************************/
static bool State_CreateStaticOdObjects(EXAMPLETASK1_RSC_T* ptRsc)
{
  bool fRetriggerFsm = false;
  TLR_RESULT eRslt = TLR_S_OK;
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  const COE_INIT_ODV3_T* ptCurrentObject = ptObjDict->ptCurrentObject;
  bool fProcessingFinished;

  if(ptCurrentObject <= ptObjDict->ptLastObject)
  {
    if(ODV3_CREATE_OBJECT_REQ == ptCurrentObject->ulCmd)
    {
      /** \note if fragmented packet, we will come here again for same object */
      eRslt = ObjectCreator_SendCoeCreateObjReq(ptRsc, ptCurrentObject, &fProcessingFinished);
    }else
    if(ODV3_CREATE_SUBOBJECT_REQ == ptCurrentObject->ulCmd)
    {
      /** \todo Implement eRslt = SendCoeCreateSubObjReq(ptRsc, ptCurrentObject); */
      /** \note if fragmented packet, we will come here again for same object */
      eRslt = ObjectCreator_SendCoeCreateObjReq(ptRsc, ptCurrentObject, &fProcessingFinished);
    }else{
      eRslt = TLR_E_INVALID_PARAMETER;
    }
    if(true == fProcessingFinished){
      ptObjDict->ptCurrentObject++; /* next object in lookup table */
    }
  }else{
    ptObjDict->pfnCurrenState = &State_Finish;
    fRetriggerFsm = true;
  }
  if(eRslt != TLR_S_OK)
  {
    TLR_TSK_SET_STATE(eRslt);
  }
  return fRetriggerFsm;
}

/*************************************************************************************/
static bool State_Initialize(EXAMPLETASK1_RSC_T* ptRsc)
{
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  ptObjDict->ptCurrentObject = &s_tOdInitTable[0];
  ptObjDict->ptLastObject = &s_tOdInitTable[MAX_CNT(s_tOdInitTable) - 1];

  ptObjDict->pfnCurrenState = &State_CreateStaticOdObjects;

  return true; /* retrigger FSM in this cycle with new state State_CreateStaticOdObjects */
}

/*************************************************************************************/
void ObjectDictionary_OdCreationFsm(EXAMPLETASK1_RSC_T* ptRsc)
{
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  ASSERT(NULL != ptObjDict->pfnCurrenState);

  while( true == ptObjDict->pfnCurrenState(ptRsc) ); /* trigger current state as long as FSM shall be retriggered */
}

/*************************************************************************************/
uint32_t ObjectDictionary_Init(EXAMPLETASK1_RSC_T* ptRsc)
{
  uint32_t ulRslt = TLR_S_OK;
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;

  ptObjDict->pfnCurrenState = &State_Initialize;

  return ulRslt;
}
