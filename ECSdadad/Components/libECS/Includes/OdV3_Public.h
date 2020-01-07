/**************************************************************************************
 Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OdV3_Public.h 3097 2015-11-10 09:46:16Z Sven $:


Changes:
 Date          Description
 -----------------------------------------------------------------------------------
 2010-07-28    Created
**************************************************************************************/

#ifndef __ODV3_PUBLIC_H
#define __ODV3_PUBLIC_H

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(ODV3_PUBLIC)
#endif

/*============================================================================*/
/* basic services */
#define ODV3_READ_OBJECT_REQ                              0x6A00
#define ODV3_READ_OBJECT_CNF                              0x6A01

#define ODV3_READ_OBJECT_IND                              0x6A00
#define ODV3_READ_OBJECT_RES                              0x6A01


#define ODV3_WRITE_OBJECT_REQ                             0x6A02
#define ODV3_WRITE_OBJECT_CNF                             0x6A03

#define ODV3_WRITE_OBJECT_IND                             0x6A02
#define ODV3_WRITE_OBJECT_RES                             0x6A03


#define ODV3_GET_OBJECT_LIST_REQ                          0x6A10
#define ODV3_GET_OBJECT_LIST_CNF                          0x6A11

#define ODV3_GET_OBJECT_LIST_IND                          0x6A10
#define ODV3_GET_OBJECT_LIST_RES                          0x6A11


#define ODV3_GET_OBJECT_INFO_REQ                          0x6A12
#define ODV3_GET_OBJECT_INFO_CNF                          0x6A13

#define ODV3_GET_OBJECT_INFO_IND                          0x6A12
#define ODV3_GET_OBJECT_INFO_RES                          0x6A13


#define ODV3_GET_SUBOBJECT_INFO_REQ                       0x6A14
#define ODV3_GET_SUBOBJECT_INFO_CNF                       0x6A15

#define ODV3_GET_SUBOBJECT_INFO_IND                       0x6A14
#define ODV3_GET_SUBOBJECT_INFO_RES                       0x6A15


#define ODV3_GET_OBJECT_ACCESS_INFO_REQ                   0x6A16
#define ODV3_GET_OBJECT_ACCESS_INFO_CNF                   0x6A17

#define ODV3_GET_OBJECT_ACCESS_INFO_IND                   0x6A16
#define ODV3_GET_OBJECT_ACCESS_INFO_RES                   0x6A17


#define ODV3_GET_OBJECT_SIZE_REQ                          0x6A18
#define ODV3_GET_OBJECT_SIZE_CNF                          0x6A19

#define ODV3_GET_OBJECT_SIZE_IND                          0x6A18
#define ODV3_GET_OBJECT_SIZE_RES                          0x6A19



/* special access type: only allowed on locally created objects / no virtual mode */
#define ODV3_READ_OBJECT_NO_IND_REQ                       0x6A1C
#define ODV3_READ_OBJECT_NO_IND_CNF                       0x6A1D


#define ODV3_GET_OBJECT_COUNT_REQ                         0x6A1E
#define ODV3_GET_OBJECT_COUNT_CNF                         0x6A1F

#define ODV3_GET_OBJECT_COUNT_IND                         0x6A1E
#define ODV3_GET_OBJECT_COUNT_RES                         0x6A1F

#define ODV3_REQUEST_ABORTED_IND                          0x6A2E
#define ODV3_REQUEST_ABORTED_RES                          0x6A2F

#define ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND         0x6A2A
#define ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES         0x6A2B

#define ODV3_GET_OBJECT_PROPERTIES_IND                    0x6A30
#define ODV3_GET_OBJECT_PROPERTIES_RES                    0x6A31

/*============================================================================*/
/* compound services */
#define ODV3_WRITE_ALL_BY_INDEX_REQ                       0x6A20
#define ODV3_WRITE_ALL_BY_INDEX_CNF                       0x6A21


#define ODV3_READ_ALL_BY_INDEX_REQ                        0x6A22
#define ODV3_READ_ALL_BY_INDEX_CNF                        0x6A23


#define ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ        0x6A24
#define ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF        0x6A25


#define ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ         0x6A26
#define ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF         0x6A27


#define ODV3_RESET_OBJECTS_REQ                            0x6A28
#define ODV3_RESET_OBJECTS_CNF                            0x6A29

#define ODV3_RESET_OBJECTS_IND                            0x6A28
#define ODV3_RESET_OBJECTS_RES                            0x6A29

/*============================================================================*/
/* management services */
#define ODV3_CREATE_OBJECT_REQ                            0x6A80
#define ODV3_CREATE_OBJECT_CNF                            0x6A81


#define ODV3_CREATE_SUBOBJECT_REQ                         0x6A82
#define ODV3_CREATE_SUBOBJECT_CNF                         0x6A83


#define ODV3_DELETE_OBJECT_REQ                            0x6A84
#define ODV3_DELETE_OBJECT_CNF                            0x6A85


#define ODV3_DELETE_SUBOBJECT_REQ                         0x6A86
#define ODV3_DELETE_SUBOBJECT_CNF                         0x6A87


#define ODV3_REGISTER_OBJECT_NOTIFY_REQ                   0x6A90
#define ODV3_REGISTER_OBJECT_NOTIFY_CNF                   0x6A91


#define ODV3_UNREGISTER_OBJECT_NOTIFY_REQ                 0x6A92
#define ODV3_UNREGISTER_OBJECT_NOTIFY_CNF                 0x6A93


#define ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ                0x6A94
#define ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF                0x6A95


#define ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ              0x6A96
#define ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF              0x6A97


#define ODV3_REGISTER_UNDEFINED_NOTIFY_REQ                0x6AA0
#define ODV3_REGISTER_UNDEFINED_NOTIFY_CNF                0x6AA1


#define ODV3_UNREGISTER_UNDEFINED_NOTIFY_REQ              0x6AA2
#define ODV3_UNREGISTER_UNDEFINED_NOTIFY_CNF              0x6AA3


#define ODV3_REGISTER_OBJINFO_NOTIFY_REQ                  0x6AA4
#define ODV3_REGISTER_OBJINFO_NOTIFY_CNF                  0x6AA5


#define ODV3_UNREGISTER_OBJINFO_NOTIFY_REQ                0x6AA6
#define ODV3_UNREGISTER_OBJINFO_NOTIFY_CNF                0x6AA7


#define ODV3_LOCK_OBJECT_DELETION_REQ                     0x6AB0
#define ODV3_LOCK_OBJECT_DELETION_CNF                     0x6AB1


#define ODV3_UNLOCK_OBJECT_DELETION_REQ                   0x6AB2
#define ODV3_UNLOCK_OBJECT_DELETION_CNF                   0x6AB3


#define ODV3_SET_OBJECT_NAME_REQ                          0x6AB4
#define ODV3_SET_OBJECT_NAME_CNF                          0x6AB5


#define ODV3_SET_SUBOBJECT_NAME_REQ                       0x6AB6
#define ODV3_SET_SUBOBJECT_NAME_CNF                       0x6AB7


/* internal request for stack use */
#define ODV3_RESET_OBJECT_DICTIONARY_REQ                  0x6AB8
#define ODV3_RESET_OBJECT_DICTIONARY_CNF                  0x6AB9


/******************************************************************************
 * Data type management
 */

#define ODV3_CREATE_DATATYPE_REQ                          0x6AC0
#define ODV3_CREATE_DATATYPE_CNF                          0x6AC1


#define ODV3_DELETE_DATATYPE_REQ                          0x6AC2
#define ODV3_DELETE_DATATYPE_CNF                          0x6AC3


/******************************************************************************
 * Timeout setup
 */

#define ODV3_SET_TIMEOUT_REQ                              0x6AD0
#define ODV3_SET_TIMEOUT_CNF                              0x6AD1


#define ODV3_GET_TIMEOUT_REQ                              0x6AD2
#define ODV3_GET_TIMEOUT_CNF                              0x6AD3


/******************************************************************************
 * Access flags
 * usAccessFlags field
 */
#define ODV3_ACCESS_FLAGS_SUBINDEX_0_WRITE_0_FIRST        0x0200      /* on writing all subindexes starting from subindex 0, write 0 to subindex 0 first */
#define ODV3_ACCESS_FLAGS_CREATE_SUBINDEX_0               0x0400      /* only on indexed objects, uses simple var bValueInfo fields (uses data type ODV3_DATATYPE_UNSIGNED8) */
#define ODV3_ACCESS_FLAGS_FORCE_INDEXED                   0x0800
#define ODV3_ACCESS_FLAGS_RXPDO_MAPPABLE                  0x1000
#define ODV3_ACCESS_FLAGS_TXPDO_MAPPABLE                  0x2000
#define ODV3_ACCESS_FLAGS_BACKUP                          0x4000
#define ODV3_ACCESS_FLAGS_SETTINGS                        0x8000


/******************************************************************************
 * Value Info
 * bValueInfo field
 */
#define ODV3_VALUE_INFO_NAME                              0x01
#define ODV3_VALUE_INFO_INITIAL_VALUE                     0x02
#define ODV3_VALUE_INFO_VIRTUAL                           0x04      /* make object/subobject virtual */
#define ODV3_VALUE_INFO_ECAT_UNIT                         0x08      /* EtherCAT only */
#define ODV3_VALUE_INFO_DEFAULT_VALUE                     0x10
#define ODV3_VALUE_INFO_MINIMUM                           0x20
#define ODV3_VALUE_INFO_MAXIMUM                           0x40
#define ODV3_VALUE_INFO_VARIABLE_SIZE_VALUE               0x80

/******************************************************************************
 * Indication flags
 * bIndicationFlags field
 */
#define ODV3_INDICATION_FLAGS_ON_READ                     0x01
#define ODV3_INDICATION_FLAGS_ON_WRITE                    0x02
#define ODV3_INDICATION_FLAGS_ON_RW_UNDEFINED_SUBOBJ      0x04      /* only on object level (one indication listener) */
#define ODV3_INDICATION_FLAGS_ON_INFO_UNDEFINED_SUBOBJ    0x08      /* only on object level (one indication listener) */
#define ODV3_INDICATION_FLAGS_SUPPORTED                   0x1F
#define ODV3_INDICATION_FLAGS_ALLOWED_ON_OBJ              0x0F
#define ODV3_INDICATION_FLAGS_ALLOWED_ON_SUBOBJ           0x03

/******************************************************************************
 * Needed Data type definitions
 */
#define ODV3_DATATYPE_UNSIGNED8                           0x0005

/******************************************************************************
 * Object Code definitions
 */
#define ODV3_OBJCODE_DOMAIN                               0x02
#define ODV3_OBJCODE_DEFTYPE                              0x05
#define ODV3_OBJCODE_DEFSTRUCT                            0x06
#define ODV3_OBJCODE_VAR                                  0x07
#define ODV3_OBJCODE_ARRAY                                0x08
#define ODV3_OBJCODE_RECORD                               0x09

/******************************************************************************
 * Multiple Parameter read/write access flags
 * bMultipleParaAccessFlags field
 */
#define ODV3_MULTIPLE_PARA_ACCESS_ALL_INDEXES               0x01    /* access all index starting at bSubIndex (0 or 1 allowed) (reserved for read/write multiple parameter) */
#define ODV3_MULTIPLE_PARA_ACCESS_BIT_TYPES_BIT_ALIGNED     0x02    /* access to bit types will be placed at bit boundaries */
#define ODV3_MULTIPLE_PARA_ACCESS_WRITE_SI0_TO_0_FIRST      0x04    /* write subindex 0 to zero first and final value as last transfer, object properties can enable it without having been set here */
#define ODV3_MULTIPLE_PARA_ACCESS_SUBINDEX_0_PADDED_TO_U16  0x08    /* on reading and writing all indexes, the subindex 0 is padded to 16bit integer (when object is not SimpleVar) */
#define ODV3_MULTIPLE_PARA_ACCESS_EVAL_SUBINDEX_0_ON_WRITE  0x10    /* on writing all by indexes, subindex 0 will be evaluated if transferred */
#define ODV3_MULTIPLE_PARA_ACCESS_CHECK_ACCESS_RIGHTS       0x20    /* reserved for future: first UINT16 in data contains access rights to be checked */

/******************************************************************************
 * Packet:  ODV3_CREATE_OBJECT_REQ/ODV3_CREATE_OBJECT_CNF
 *
 * Fragmentation:
 *                            Request             Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_OBJECT_REQ_DATA_Ttag
{
  /* non-fragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bMaxNumOfSubObjs;
  TLR_UINT8                                               bObjectCode;
  TLR_UINT16                                              usAccessFlags;      /* object-wise flag set, not related to access rights */
  TLR_UINT8                                               bValueInfo;
  TLR_UINT8                                               bIndicationFlags;
  TLR_UINT16                                              usDatatype;
  /* following two are only evaluated on SimpleVar { */
  TLR_UINT16                                              usAccessRights;
  TLR_UINT32                                              ulMaxFieldUnits;
  /* } */
  TLR_UINT32                                              ulTotalDataBytes;
  /* fragmentable part */
  /* bValueInfo determines what gets appended here */
  TLR_UINT8                                               abData[1024];
  /* order of fields: (no padding between)
   * - Unit (TLR_UINT32)
   * - Name (TLR_UINT32 ulNameLength, TLR_STR abName[ulNameLength]
   * - Minimum Value (TLR_UINT32 ulMinimumValueLength, TLR_UINT8 abData[ulMinimumValueLength])
   * - Maximum Value (TLR_UINT32 ulMaximumValueLength, TLR_UINT8 abData[ulMaximumValueLength])
   * - Initial Value (TLR_UINT32 ulInitialValueLength, TLR_UINT8 abData[ulInitialValueLength])
   * - Default Value (TLR_UINT32 ulDefaultValueLength, TLR_UINT8 abData[ulDefaultValueLength])
   */
} __TLR_PACKED_POST ODV3_CREATE_OBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_OBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_OBJECT_REQ_DATA_T                           tData;
} __TLR_PACKED_POST ODV3_CREATE_OBJECT_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_OBJECT_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_CREATE_OBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_OBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_OBJECT_CNF_DATA_T                           tData;
} __TLR_PACKED_POST ODV3_CREATE_OBJECT_CNF_T;


/* packet union */
typedef union ODV3_CREATE_OBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_OBJECT_REQ_T                                tReq;
  ODV3_CREATE_OBJECT_CNF_T                                tCnf;
} ODV3_CREATE_OBJECT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_CREATE_SUBOBJECT_REQ/ODV3_CREATE_SUBOBJECT_CNF
 *
 * Fragmentation:
 *                            Request             Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_SUBOBJECT_REQ_DATA_Ttag
{
  /* non-fragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bValueInfo;
  TLR_UINT8                                               bIndicationFlags;
  TLR_UINT16                                              usAccessRights;
  TLR_UINT16                                              usDatatype;
  TLR_UINT32                                              ulMaxFieldUnits;
  TLR_UINT32                                              ulTotalDataBytes;
  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
  /* order of fields: (no padding between)
   * - Unit (TLR_UINT32)
   * - Name (TLR_UINT32 ulNameLength, TLR_STR abName[ulNameLength]
   * - Minimum Value (TLR_UINT32 ulMinimumValueLength, TLR_UINT8 abData[ulMinimumValueLength])
   * - Maximum Value (TLR_UINT32 ulMaximumValueLength, TLR_UINT8 abData[ulMaximumValueLength])
   * - Initial Value (TLR_UINT32 ulInitialValueLength, TLR_UINT8 abData[ulInitialValueLength])
   * - Default Value (TLR_UINT32 ulDefaultValueLength, TLR_UINT8 abData[ulDefaultValueLength])
   */
} __TLR_PACKED_POST ODV3_CREATE_SUBOBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_SUBOBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_SUBOBJECT_REQ_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_CREATE_SUBOBJECT_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_SUBOBJECT_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_CREATE_SUBOBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_SUBOBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_SUBOBJECT_CNF_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_CREATE_SUBOBJECT_CNF_T;


/* packet union */
typedef union ODV3_CREATE_SUBOBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_SUBOBJECT_REQ_T                             tReq;
  ODV3_CREATE_SUBOBJECT_CNF_T                             tCnf;
} ODV3_CREATE_SUBOBJECT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_DELETE_OBJECT_REQ/ODV3_DELETE_OBJECT_CNF
 */
/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_OBJECT_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_DELETE_OBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_OBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_OBJECT_REQ_DATA_T                           tData;
} __TLR_PACKED_POST ODV3_DELETE_OBJECT_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_OBJECT_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_DELETE_OBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_OBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_OBJECT_CNF_DATA_T                           tData;
} __TLR_PACKED_POST ODV3_DELETE_OBJECT_CNF_T;


/* packet union */
typedef union ODV3_DELETE_OBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_OBJECT_REQ_T                                tReq;
  ODV3_DELETE_OBJECT_CNF_T                                tCnf;
} ODV3_DELETE_OBJECT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_DELETE_SUBOBJECT_REQ/ODV3_DELETE_SUBOBJECT_CNF
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_SUBOBJECT_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_DELETE_SUBOBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_SUBOBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_SUBOBJECT_REQ_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_DELETE_SUBOBJECT_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_SUBOBJECT_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_DELETE_SUBOBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_SUBOBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_SUBOBJECT_CNF_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_DELETE_SUBOBJECT_CNF_T;


/* packet union */
typedef union ODV3_DELETE_SUBOBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_SUBOBJECT_REQ_T                             tReq;
  ODV3_DELETE_SUBOBJECT_CNF_T                             tCnf;
} ODV3_DELETE_SUBOBJECT_PCK_T;

/******************************************************************************
 * Packet:  ODV3_READ_OBJECT_REQ/ODV3_READ_OBJECT_CNF
 * Packet:  ODV3_READ_OBJECT_IND/ODV3_READ_OBJECT_RES
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_OBJECT_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT16                                              usMaxSegLength;     /* max seg length in bytes or 0 for field not used */
} __TLR_PACKED_POST ODV3_READ_OBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_OBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_OBJECT_REQ_DATA_T                             tData;
} __TLR_PACKED_POST ODV3_READ_OBJECT_REQ_T;

typedef ODV3_READ_OBJECT_REQ_DATA_T ODV3_READ_OBJECT_IND_DATA_T;
typedef ODV3_READ_OBJECT_REQ_T ODV3_READ_OBJECT_IND_T;


/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_OBJECT_CNF_DATA_Ttag
{
  /* unfragmentable part, part of every fragment */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT16                                              usMaxSegLength;     /* max seg length in bytes or 0 for field not used */
  TLR_UINT32                                              ulTotalDataBytes;   /* needed for fragmentation support */

  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
} __TLR_PACKED_POST ODV3_READ_OBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_OBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_OBJECT_CNF_DATA_T                             tData;
} __TLR_PACKED_POST ODV3_READ_OBJECT_CNF_T;

typedef ODV3_READ_OBJECT_CNF_DATA_T ODV3_READ_OBJECT_RES_DATA_T;
typedef ODV3_READ_OBJECT_CNF_T ODV3_READ_OBJECT_RES_T;


/* packet union */
typedef union ODV3_READ_OBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_OBJECT_REQ_T                                  tReq;
  ODV3_READ_OBJECT_IND_T                                  tInd;
  ODV3_READ_OBJECT_RES_T                                  tRes;
  ODV3_READ_OBJECT_CNF_T                                  tCnf;
} ODV3_READ_OBJECT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_READ_OBJECT_NO_IND_REQ/ODV3_READ_OBJECT_NO_IND_CNF
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * This service does not trigger indication and is therefore only useful on objects that exists locally and do not use virtual mode
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 *
 * Remarks: this request must be identical in structure to ODV3_READ_OBJECT_REQ
 */

/* request packet */
typedef ODV3_READ_OBJECT_REQ_DATA_T ODV3_READ_OBJECT_NO_IND_REQ_DATA_T;
typedef ODV3_READ_OBJECT_REQ_T ODV3_READ_OBJECT_NO_IND_REQ_T;

/* confirmation packet */
typedef ODV3_READ_OBJECT_CNF_DATA_T ODV3_READ_OBJECT_NO_IND_CNF_DATA_T;
typedef ODV3_READ_OBJECT_CNF_T ODV3_READ_OBJECT_NO_IND_CNF_T;


/* packet union */
typedef union ODV3_READ_OBJECT_NO_IND_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_OBJECT_NO_IND_REQ_T                           tReq;
  ODV3_READ_OBJECT_NO_IND_CNF_T                           tCnf;
} ODV3_READ_OBJECT_NO_IND_PCK_T;


/******************************************************************************
 * Packet:  ODV3_WRITE_OBJECT_REQ/ODV3_WRITE_OBJECT_CNF
 * Packet:  ODV3_WRITE_OBJECT_IND/ODV3_WRITE_OBJECT_RES
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 *
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_REQ_DATA_Ttag
{
  /* unfragmentable part, part of every fragment */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  /* needed for fragmentation support */
  TLR_UINT32                                              ulTotalDataBytes;
  /* used on indication to signal that the receiver is implicitly receiveing the ODV3_WRITE_OBJECT_VALIDATED_IND
   * so, it will not get an indication of that type anymore.
   */
  TLR_BOOLEAN32                                           fValidationIsImplicit;
  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_REQ_DATA_T                            tData;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_REQ_T;

typedef ODV3_WRITE_OBJECT_REQ_DATA_T ODV3_WRITE_OBJECT_IND_DATA_T;
typedef ODV3_WRITE_OBJECT_REQ_T ODV3_WRITE_OBJECT_IND_T;

/* special value for ulTotalDataBytes */
#define ODV3_WRITE_OBJECT_REQ_TOTAL_DATA_BYTES_NOT_SPECIFIED      0xFFFFFFFF

#define ODV3_WRITE_OBJECT_IND_TOTAL_DATA_BYTES_NOT_SPECIFIED      0xFFFFFFFF

/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_CNF_DATA_Ttag
{
  /* unfragmentable part, part of every fragment */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_CNF_DATA_T                            tData;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_CNF_T;

typedef ODV3_WRITE_OBJECT_CNF_DATA_T ODV3_WRITE_OBJECT_RES_DATA_T;
typedef ODV3_WRITE_OBJECT_CNF_T ODV3_WRITE_OBJECT_RES_T;


/* packet union */
typedef union ODV3_WRITE_OBJECT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_REQ_T                                 tReq;
  ODV3_WRITE_OBJECT_IND_T                                 tInd;
  ODV3_WRITE_OBJECT_RES_T                                 tRes;
  ODV3_WRITE_OBJECT_CNF_T                                 tCnf;
} ODV3_WRITE_OBJECT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND/ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 *
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_BOOLEAN8                                            fSuccessful;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_DATA_T        tData;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_DATA_T        tData;
} __TLR_PACKED_POST ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_T;


/* packet union */
typedef union ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_T             tInd;
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_T             tRes;
} ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_ACCESS_INFO_REQ/ODV3_GET_OBJECT_ACCESS_INFO_CNF
 * Packet:  ODV3_GET_OBJECT_ACCESS_INFO_IND/ODV3_GET_OBJECT_ACCESS_INFO_RES
 *
 * ulSta must be TLR_S_OK on request/indication
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_ACCESS_INFO_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex;
  TLR_UINT8                                               bNumSubIndex; /* 0 ~ 256 entries */
} __TLR_PACKED_POST ODV3_GET_OBJECT_ACCESS_INFO_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_ACCESS_INFO_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_ACCESS_INFO_REQ_DATA_T                  tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_ACCESS_INFO_REQ_T;

typedef ODV3_GET_OBJECT_ACCESS_INFO_REQ_DATA_T ODV3_GET_OBJECT_ACCESS_INFO_IND_DATA_T;
typedef ODV3_GET_OBJECT_ACCESS_INFO_REQ_T ODV3_GET_OBJECT_ACCESS_INFO_IND_T;

/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_ACCESS_INFO_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex;
  /* bNumSubIndex can be lowered by requestee if the packet cannot be transferred otherwise (i.e. DPM),
   * the requestor has to issue a follow-up request if bMaxSubIndex + 1 > bNumSubIndex + bStartSubIndex.
   */
  TLR_UINT8                                               bNumSubIndex;
  /* up to bNumSubIndex, the confirmation must match its request */
  TLR_UINT8                                               bMaxSubIndex;
  TLR_UINT8                                               abReserved[3];
  TLR_UINT16                                              ausAccessRights[256];  /* actual amount of elements controlled by MAX(bNumSubIndex) */
} __TLR_PACKED_POST ODV3_GET_OBJECT_ACCESS_INFO_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_ACCESS_INFO_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_ACCESS_INFO_CNF_DATA_T                  tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_ACCESS_INFO_CNF_T;

#define ODV3_GET_OBJECT_ACCESS_INFO_RES_MIN_DATA_SIZE     (1 * sizeof(TLR_UINT16) + 4 * sizeof(TLR_UINT8))

typedef ODV3_GET_OBJECT_ACCESS_INFO_CNF_DATA_T ODV3_GET_OBJECT_ACCESS_INFO_RES_DATA_T;
typedef ODV3_GET_OBJECT_ACCESS_INFO_CNF_T ODV3_GET_OBJECT_ACCESS_INFO_RES_T;

/* packet union */
typedef union ODV3_GET_OBJECT_ACCESS_INFO_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_ACCESS_INFO_REQ_T                       tReq;
  ODV3_GET_OBJECT_ACCESS_INFO_IND_T                       tInd;
  ODV3_GET_OBJECT_ACCESS_INFO_RES_T                       tRes;
  ODV3_GET_OBJECT_ACCESS_INFO_CNF_T                       tCnf;
} ODV3_GET_OBJECT_ACCESS_INFO_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_SIZE_REQ/ODV3_GET_OBJECT_SIZE_CNF
 * Packet:  ODV3_GET_OBJECT_SIZE_IND/ODV3_GET_OBJECT_SIZE_RES
 *
 * ulSta must be TLR_S_OK on request/indication
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_SIZE_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex;
  TLR_UINT8                                               bNumSubIndex;
} __TLR_PACKED_POST ODV3_GET_OBJECT_SIZE_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_SIZE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_SIZE_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_SIZE_REQ_T;

typedef ODV3_GET_OBJECT_SIZE_REQ_DATA_T ODV3_GET_OBJECT_SIZE_IND_DATA_T;
typedef ODV3_GET_OBJECT_SIZE_REQ_T ODV3_GET_OBJECT_SIZE_IND_T;


/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_SIZE_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex;
  /* bNumSubIndex can be lowered by requestee if the packet cannot be transferred otherwise (i.e. DPM),
   * the requestor has to issue a follow-up request then.
   *
   * If there are no more subobjects, the value of bNumSubIndex has to be 0.
   */
  TLR_UINT8                                               bNumSubIndex;
  TLR_UINT32                                              aulSubObjDataBitSize[256];    /* only actual size defined by bNumSubIndex needs to be used */
} __TLR_PACKED_POST ODV3_GET_OBJECT_SIZE_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_SIZE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_SIZE_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_SIZE_CNF_T;

typedef ODV3_GET_OBJECT_SIZE_CNF_DATA_T ODV3_GET_OBJECT_SIZE_RES_DATA_T;
typedef ODV3_GET_OBJECT_SIZE_CNF_T ODV3_GET_OBJECT_SIZE_RES_T;

#define ODV3_GET_OBJECT_SIZE_RES_DATA_MIN_REQ_SIZE        (sizeof(TLR_UINT16) + 2 * sizeof(TLR_UINT8))
#define ODV3_GET_OBJECT_SIZE_CNF_DATA_MIN_REQ_SIZE        (sizeof(TLR_UINT16) + 2 * sizeof(TLR_UINT8))


/* packet union */
typedef union ODV3_GET_OBJECT_SIZE_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_SIZE_REQ_T                              tReq;
  ODV3_GET_OBJECT_SIZE_IND_T                              tInd;
  ODV3_GET_OBJECT_SIZE_RES_T                              tRes;
  ODV3_GET_OBJECT_SIZE_CNF_T                              tCnf;
} ODV3_GET_OBJECT_SIZE_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_LIST_REQ/ODV3_GET_OBJECT_LIST_CNF
 * Packet:  ODV3_GET_OBJECT_LIST_IND/ODV3_GET_OBJECT_LIST_RES
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_LIST_REQ_DATA_Ttag
{
  TLR_UINT16                                              usObjAccessMask;
  TLR_UINT16                                              usObjAccessCompare;
} __TLR_PACKED_POST ODV3_GET_OBJECT_LIST_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_LIST_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_LIST_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_LIST_REQ_T;

typedef ODV3_GET_OBJECT_LIST_REQ_DATA_T ODV3_GET_OBJECT_LIST_IND_DATA_T;
typedef ODV3_GET_OBJECT_LIST_REQ_T ODV3_GET_OBJECT_LIST_IND_T;


/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_LIST_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16                                              usObjAccessMask;
  TLR_UINT16                                              usObjAccessCompare;
  TLR_UINT32                                              ulTotalDataBytes;

  /* fragmentable part */
  TLR_UINT16                                              ausIndexes[512];
} __TLR_PACKED_POST ODV3_GET_OBJECT_LIST_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_LIST_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_LIST_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_LIST_CNF_T;

typedef ODV3_GET_OBJECT_LIST_CNF_DATA_T ODV3_GET_OBJECT_LIST_RES_DATA_T;
typedef ODV3_GET_OBJECT_LIST_CNF_T ODV3_GET_OBJECT_LIST_RES_T;


/* packet union */
typedef union ODV3_GET_OBJECT_LIST_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_LIST_REQ_T                              tReq;
  ODV3_GET_OBJECT_LIST_IND_T                              tInd;
  ODV3_GET_OBJECT_LIST_RES_T                              tRes;
  ODV3_GET_OBJECT_LIST_CNF_T                              tCnf;
} ODV3_GET_OBJECT_LIST_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_COUNT_REQ/ODV3_GET_OBJECT_COUNT_CNF
 * Packet:  ODV3_GET_OBJECT_COUNT_IND/ODV3_GET_OBJECT_COUNT_RES
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

#define ODV3_GET_OBJECT_COUNT_MAX_ENTRIES     20

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_COUNT_REQ_DATA_ENTRY_Ttag
{
  TLR_UINT16                                              usObjAccessMask;
  TLR_UINT16                                              usObjAccessCompare;
} __TLR_PACKED_POST ODV3_GET_OBJECT_COUNT_REQ_DATA_ENTRY_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_COUNT_REQ_DATA_Ttag
{
  ODV3_GET_OBJECT_COUNT_REQ_DATA_ENTRY_T                  atEntries[20];
} __TLR_PACKED_POST ODV3_GET_OBJECT_COUNT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_COUNT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_COUNT_REQ_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_COUNT_REQ_T;

typedef ODV3_GET_OBJECT_COUNT_REQ_DATA_ENTRY_T ODV3_GET_OBJECT_COUNT_IND_DATA_ENTRY_T;
typedef ODV3_GET_OBJECT_COUNT_REQ_DATA_T ODV3_GET_OBJECT_COUNT_IND_DATA_T;
typedef ODV3_GET_OBJECT_COUNT_REQ_T ODV3_GET_OBJECT_COUNT_IND_T;


/* response/confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_COUNT_CNF_DATA_Ttag
{
  TLR_UINT16                                              ausCounts[20];
} __TLR_PACKED_POST ODV3_GET_OBJECT_COUNT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_COUNT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_COUNT_CNF_DATA_T                        tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_COUNT_CNF_T;

typedef ODV3_GET_OBJECT_COUNT_CNF_DATA_T ODV3_GET_OBJECT_COUNT_RES_DATA_T;
typedef ODV3_GET_OBJECT_COUNT_CNF_T ODV3_GET_OBJECT_COUNT_RES_T;


/* packet union */
typedef union ODV3_GET_OBJECT_COUNT_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_COUNT_REQ_T                             tReq;
  ODV3_GET_OBJECT_COUNT_IND_T                             tInd;
  ODV3_GET_OBJECT_COUNT_RES_T                             tRes;
  ODV3_GET_OBJECT_COUNT_CNF_T                             tCnf;
} ODV3_GET_OBJECT_COUNT_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_INFO_REQ/ODV3_GET_OBJECT_INFO_CNF
 * Packet:  ODV3_GET_OBJECT_INFO_IND/ODV3_GET_OBJECT_INFO_RES
 *
 * Description: Determine information about object
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_INFO_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_GET_OBJECT_INFO_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_INFO_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_INFO_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_INFO_REQ_T;

typedef ODV3_GET_OBJECT_INFO_REQ_DATA_T ODV3_GET_OBJECT_INFO_IND_DATA_T;
typedef ODV3_GET_OBJECT_INFO_REQ_T ODV3_GET_OBJECT_INFO_IND_T;


/* confirmation/response packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_INFO_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT16                                              usDatatype;
  TLR_UINT16                                              usAccessFlags;
  TLR_UINT8                                               bMaxNumOfSubObjs;
  TLR_UINT8                                               bObjectCode;
  TLR_UINT32                                              ulTotalDataBytes;   /* needed for fragmentation support */
  /* fragmentable part */
  TLR_UINT8                                               abName[1024];
} __TLR_PACKED_POST ODV3_GET_OBJECT_INFO_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_INFO_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_INFO_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_INFO_CNF_T;

typedef ODV3_GET_OBJECT_INFO_CNF_DATA_T ODV3_GET_OBJECT_INFO_RES_DATA_T;
typedef ODV3_GET_OBJECT_INFO_CNF_T ODV3_GET_OBJECT_INFO_RES_T;


/* packet union */
typedef union ODV3_GET_OBJECT_INFO_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_INFO_REQ_T                              tReq;
  ODV3_GET_OBJECT_INFO_IND_T                              tInd;
  ODV3_GET_OBJECT_INFO_RES_T                              tRes;
  ODV3_GET_OBJECT_INFO_CNF_T                              tCnf;
} ODV3_GET_OBJECT_INFO_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_SUBOBJECT_INFO_REQ/ODV3_GET_SUBOBJECT_INFO_CNF
 * Packet:  ODV3_GET_SUBOBJECT_INFO_IND/ODV3_GET_SUBOBJECT_INFO_RES
 *
 * Description: Determine information about subobject
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request/indication, otherwise it is considered an abort.
 *
 * indication receivers have to check ulSta whether, it is an abort on a fragmentation.
 */

/* request/indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_SUBOBJECT_INFO_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bRequestedValueInfo;
} __TLR_PACKED_POST ODV3_GET_SUBOBJECT_INFO_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_SUBOBJECT_INFO_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_SUBOBJECT_INFO_REQ_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_GET_SUBOBJECT_INFO_REQ_T;

typedef ODV3_GET_SUBOBJECT_INFO_REQ_DATA_T ODV3_GET_SUBOBJECT_INFO_IND_DATA_T;
typedef ODV3_GET_SUBOBJECT_INFO_REQ_T ODV3_GET_SUBOBJECT_INFO_IND_T;

#define ODV3_GET_SUBOBJECT_INFO_REQ_VALUE_INFO_NAME           0x01
#define ODV3_GET_SUBOBJECT_INFO_REQ_VALUE_INFO_ECAT_UNIT      0x10
#define ODV3_GET_SUBOBJECT_INFO_REQ_VALUE_INFO_DEFAULT_VALUE  0x20
#define ODV3_GET_SUBOBJECT_INFO_REQ_VALUE_INFO_MINIMUM_VALUE  0x40  /* always uses max length */
#define ODV3_GET_SUBOBJECT_INFO_REQ_VALUE_INFO_MAXIMUM_VALUE  0x80  /* always uses max length */



/* confirmation/response packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_SUBOBJECT_INFO_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bValueInfo;
  TLR_UINT32                                              ulTotalDataBytes;   /* needed for fragmentation support */
  TLR_UINT16                                              usAccessRights;
  TLR_UINT16                                              usDatatype;
  TLR_UINT32                                              ulDataBitLen;
  TLR_UINT16                                              usFieldLen;
  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
  /* order of fragmentable part is Unit Type, Default Value, Minimum Value, Maximum Value, Name */
} __TLR_PACKED_POST ODV3_GET_SUBOBJECT_INFO_CNF_DATA_T;

#define ODV3_GET_SUBOBJECT_INFO_CNF_VALUE_INFO_NAME           0x01
#define ODV3_GET_SUBOBJECT_INFO_CNF_VALUE_INFO_ECAT_UNIT      0x10
#define ODV3_GET_SUBOBJECT_INFO_CNF_VALUE_INFO_DEFAULT_VALUE  0x20
#define ODV3_GET_SUBOBJECT_INFO_CNF_VALUE_INFO_MINIMUM_VALUE  0x40  /* always uses max length */
#define ODV3_GET_SUBOBJECT_INFO_CNF_VALUE_INFO_MAXIMUM_VALUE  0x80  /* always uses max length */

typedef __TLR_PACKED_PRE struct ODV3_GET_SUBOBJECT_INFO_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_SUBOBJECT_INFO_CNF_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_GET_SUBOBJECT_INFO_CNF_T;

typedef ODV3_GET_SUBOBJECT_INFO_CNF_DATA_T ODV3_GET_SUBOBJECT_INFO_RES_DATA_T;
typedef ODV3_GET_SUBOBJECT_INFO_CNF_T ODV3_GET_SUBOBJECT_INFO_RES_T;


/* packet union */
typedef union ODV3_GET_SUBOBJECT_INFO_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_SUBOBJECT_INFO_REQ_T                           tReq;
  ODV3_GET_SUBOBJECT_INFO_IND_T                           tInd;
  ODV3_GET_SUBOBJECT_INFO_RES_T                           tRes;
  ODV3_GET_SUBOBJECT_INFO_CNF_T                           tCnf;
} ODV3_GET_SUBOBJECT_INFO_PCK_T;


/******************************************************************************
 * Packet:  ODV3_REQUEST_ABORTED_IND/ODV3_REQUEST_ABORTED_RES
 *
 * ulSta contains the reason for abort
 *
 * This indication is sent to the requestor if no active Request packet is contained within fragmentation.
 *
 * The following relationship between ulSrcId/ulDestId exists:
 * ODV3_READ_OBJECT_REQ           ODV3_REQUEST_ABORTED_IND
 * ulSrcId                        ulDestId
 * ulDestId                       ulSrcId
 *
 * ODV3_READ_OBJECT_REQ is a placeholder for all fragmented request services here since
 * the same rules applies to all those requests.
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ODV3_REQUEST_ABORTED_IND_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REQUEST_ABORTED_IND_T;


/* response packet */
typedef __TLR_PACKED_PRE struct ODV3_REQUEST_ABORTED_RES_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REQUEST_ABORTED_RES_T;


/* packet union */
typedef __TLR_PACKED_PRE union ODV3_REQUEST_ABORTED_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REQUEST_ABORTED_IND_T                              tInd;
  ODV3_REQUEST_ABORTED_RES_T                              tRes;
} __TLR_PACKED_POST ODV3_REQUEST_ABORTED_PCK_T;


/******************************************************************************
 * Packet:  ODV3_GET_OBJECT_PROPERTIES_IND/ODV3_GET_OBJECT_PROPERTIES_RES
 *
 */

/* indication packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_PROPERTIES_IND_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_GET_OBJECT_PROPERTIES_IND_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_PROPERTIES_IND_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_PROPERTIES_IND_DATA_T                   tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_PROPERTIES_IND_T;


/* response packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_PROPERTIES_RES_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT32                                              ulFlags;
} __TLR_PACKED_POST ODV3_GET_OBJECT_PROPERTIES_RES_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_OBJECT_PROPERTIES_RES_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_PROPERTIES_RES_DATA_T                   tData;
} __TLR_PACKED_POST ODV3_GET_OBJECT_PROPERTIES_RES_T;

#define ODV3_OBJECT_PROP_FLAG_ALL_INDEXES_ARE_FIXED_SIZE    0x00000001
#define ODV3_OBJECT_PROP_FLAG_IS_INDEXED                    0x00000002  /* is not a simple variable */
#define ODV3_OBJECT_PROP_FLAG_WRITE_SI0_TO_0_FIRST_REQUIRED 0x00000004  /* require ODV3_MULTIPLE_PARA_ACCESS_WRITE_SI0_TO_0_FIRST, setting this bit will set the actual transfer control bit */

/* packet union */
typedef __TLR_PACKED_PRE union ODV3_GET_OBJECT_PROPERTIES_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_OBJECT_PROPERTIES_IND_T                        tInd;
  ODV3_GET_OBJECT_PROPERTIES_RES_T                        tRes;
} __TLR_PACKED_POST ODV3_GET_OBJECT_PROPERTIES_PCK_T;


/******************************************************************************
 * Packet:  ODV3_REGISTER_OBJECT_NOTIFY_REQ/ODV3_REGISTER_OBJECT_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJECT_NOTIFY_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bIndicationFlags;
} __TLR_PACKED_POST ODV3_REGISTER_OBJECT_NOTIFY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJECT_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_OBJECT_NOTIFY_REQ_DATA_T                  tData;
} __TLR_PACKED_POST ODV3_REGISTER_OBJECT_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJECT_NOTIFY_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_REGISTER_OBJECT_NOTIFY_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJECT_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_OBJECT_NOTIFY_CNF_DATA_T                  tData;
} __TLR_PACKED_POST ODV3_REGISTER_OBJECT_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_REGISTER_OBJECT_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_OBJECT_NOTIFY_REQ_T                       tReq;
  ODV3_REGISTER_OBJECT_NOTIFY_CNF_T                       tCnf;
} ODV3_REGISTER_OBJECT_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_UNREGISTER_OBJECT_NOTIFY_REQ/ODV3_UNREGISTER_OBJECT_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_DATA_T                tData;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_DATA_T                tData;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_UNREGISTER_OBJECT_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_OBJECT_NOTIFY_REQ_T                     tReq;
  ODV3_UNREGISTER_OBJECT_NOTIFY_CNF_T                     tCnf;
} ODV3_UNREGISTER_OBJECT_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ/ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 *
 * on simple variables use ODV3_REGISTER_OBJECT_NOTIFY_REQ
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bIndicationFlags;
} __TLR_PACKED_POST ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_DATA_T               tData;
} __TLR_PACKED_POST ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_DATA_T               tData;
} __TLR_PACKED_POST ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_REGISTER_SUBOBJECT_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_SUBOBJECT_NOTIFY_REQ_T                    tReq;
  ODV3_REGISTER_SUBOBJECT_NOTIFY_CNF_T                    tCnf;
} ODV3_REGISTER_SUBOBJECT_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ/ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_DATA_T             tData;
} __TLR_PACKED_POST ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_DATA_T             tData;
} __TLR_PACKED_POST ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_UNREGISTER_SUBOBJECT_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_SUBOBJECT_NOTIFY_REQ_T                  tReq;
  ODV3_UNREGISTER_SUBOBJECT_NOTIFY_CNF_T                  tCnf;
} ODV3_UNREGISTER_SUBOBJECT_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_REGISTER_UNDEFINED_NOTIFY_REQ/ODV3_REGISTER_UNDEFINED_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_UNDEFINED_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REGISTER_UNDEFINED_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_UNDEFINED_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REGISTER_UNDEFINED_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_REGISTER_UNDEFINED_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_UNDEFINED_NOTIFY_REQ_T                    tReq;
  ODV3_REGISTER_UNDEFINED_NOTIFY_CNF_T                    tCnf;
} ODV3_REGISTER_UNDEFINED_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_UNREGISTER_UNDEFINED_NOTIFY_REQ/ODV3_UNREGISTER_UNDEFINED_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_UNDEFINED_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNREGISTER_UNDEFINED_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_UNDEFINED_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNREGISTER_UNDEFINED_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_UNREGISTER_UNDEFINED_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_UNDEFINED_NOTIFY_REQ_T                  tReq;
  ODV3_UNREGISTER_UNDEFINED_NOTIFY_CNF_T                  tCnf;
} ODV3_UNREGISTER_UNDEFINED_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_REGISTER_OBJINFO_NOTIFY_REQ/ODV3_REGISTER_OBJINFO_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJINFO_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REGISTER_OBJINFO_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_REGISTER_OBJINFO_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_REGISTER_OBJINFO_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_REGISTER_OBJINFO_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_REGISTER_OBJINFO_NOTIFY_REQ_T                      tReq;
  ODV3_REGISTER_OBJINFO_NOTIFY_CNF_T                      tCnf;
} ODV3_REGISTER_OBJINFO_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_UNREGISTER_OBJINFO_NOTIFY_REQ/ODV3_UNREGISTER_OBJINFO_NOTIFY_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJINFO_NOTIFY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJINFO_NOTIFY_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_UNREGISTER_OBJINFO_NOTIFY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNREGISTER_OBJINFO_NOTIFY_CNF_T;


/* packet union */
typedef union ODV3_UNREGISTER_OBJINFO_NOTIFY_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNREGISTER_OBJINFO_NOTIFY_REQ_T                    tReq;
  ODV3_UNREGISTER_OBJINFO_NOTIFY_CNF_T                    tCnf;
} ODV3_UNREGISTER_OBJINFO_NOTIFY_PCK_T;


/******************************************************************************
 * Packet:  ODV3_LOCK_OBJECT_DELETION_REQ/ODV3_LOCK_OBJECT_DELETION_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_LOCK_OBJECT_DELETION_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_LOCK_OBJECT_DELETION_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_LOCK_OBJECT_DELETION_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_LOCK_OBJECT_DELETION_CNF_T;


/* packet union */
typedef union ODV3_LOCK_OBJECT_DELETION_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_LOCK_OBJECT_DELETION_REQ_T                         tReq;
  ODV3_LOCK_OBJECT_DELETION_CNF_T                         tCnf;
} ODV3_LOCK_OBJECT_DELETION_PCK_T;


/******************************************************************************
 * Packet:  ODV3_UNLOCK_OBJECT_DELETION_REQ/ODV3_UNLOCK_OBJECT_DELETION_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_UNLOCK_OBJECT_DELETION_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNLOCK_OBJECT_DELETION_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_UNLOCK_OBJECT_DELETION_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_UNLOCK_OBJECT_DELETION_CNF_T;


/* packet union */
typedef union ODV3_UNLOCK_OBJECT_DELETION_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_UNLOCK_OBJECT_DELETION_REQ_T                       tReq;
  ODV3_UNLOCK_OBJECT_DELETION_CNF_T                       tCnf;
} ODV3_UNLOCK_OBJECT_DELETION_PCK_T;


/******************************************************************************
 * Packet:  ODV3_WRITE_ALL_BY_INDEX_REQ/ODV3_WRITE_ALL_BY_INDEX_CNF
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_ALL_BY_INDEX_REQ_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex; /* 0 or 1 valid */
  TLR_UINT8                                               bMultipleParaAccessFlags; /* access flags for multiple parameter access */
  TLR_UINT32                                              ulTotalDataBytes;
  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
} __TLR_PACKED_POST ODV3_WRITE_ALL_BY_INDEX_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_ALL_BY_INDEX_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_ALL_BY_INDEX_REQ_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_WRITE_ALL_BY_INDEX_REQ_T;

/* special value for ulTotalDataBytes */
#define ODV3_WRITE_ALL_BY_INDEX_REQ_TOTAL_DATA_BYTES_NOT_SPECIFIED      0xFFFFFFFF


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_ALL_BY_INDEX_CNF_DATA_Ttag
{
  /* unfragmentable part */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex; /* 0 or 1 valid */
} __TLR_PACKED_POST ODV3_WRITE_ALL_BY_INDEX_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_ALL_BY_INDEX_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_ALL_BY_INDEX_CNF_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_WRITE_ALL_BY_INDEX_CNF_T;


/* packet union */
typedef union ODV3_WRITE_ALL_BY_INDEX_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_ALL_BY_INDEX_REQ_T                           tReq;
  ODV3_WRITE_ALL_BY_INDEX_CNF_T                           tCnf;
} ODV3_WRITE_ALL_BY_INDEX_PCK_T;


/******************************************************************************
 * Packet:  ODV3_READ_ALL_BY_INDEX_REQ/ODV3_READ_ALL_BY_INDEX_CNF
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_ALL_BY_INDEX_REQ_DATA_Ttag
{
  /* unfragmentable part */
  /* first five bytes must be identical to ODV3_READ_OBJECT_REQ_DATA_T */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex; /* 0 or 1 valid */
  TLR_UINT8                                               bMultipleParaAccessFlags; /* access flags for multiple parameter access */
  TLR_UINT16                                              usMaxSegLength;     /* max seg length in bytes or 0 for field not used */
} __TLR_PACKED_POST ODV3_READ_ALL_BY_INDEX_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_ALL_BY_INDEX_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_ALL_BY_INDEX_REQ_DATA_T                       tData;
} __TLR_PACKED_POST ODV3_READ_ALL_BY_INDEX_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_ALL_BY_INDEX_CNF_DATA_Ttag
{
  /* unfragmentable part (must be identical to ODV3_READ_OBJECT_CNF_DATA_T) */
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bStartSubIndex; /* 0 or 1 valid */
  TLR_UINT32                                              ulTotalDataBytes;

  /* fragmentable part */
  TLR_UINT8                                               abData[1024];
} __TLR_PACKED_POST ODV3_READ_ALL_BY_INDEX_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_ALL_BY_INDEX_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_ALL_BY_INDEX_CNF_DATA_T                       tData;
} __TLR_PACKED_POST ODV3_READ_ALL_BY_INDEX_CNF_T;


/* packet union */
typedef union ODV3_READ_ALL_BY_INDEX_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_ALL_BY_INDEX_REQ_T                            tReq;
  ODV3_READ_ALL_BY_INDEX_CNF_T                            tCnf;
} ODV3_READ_ALL_BY_INDEX_PCK_T;


/******************************************************************************
 * Packet:  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ/ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * Attention! fragmenting may happen in both directions
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bMultipleParaAccessFlags; /* access flags for multiple parameter access */
  TLR_UINT32                                              ulDataByteSize;   /* if (ulDataByteSize & 3) != 0, abData is padded to 4 byte border */
  TLR_UINT8                                               abData[1];        /* variable size */
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_Ttag
{
  TLR_UINT32                                              ulTotalDataBytes;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_T      atEntries[1];
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_T       tData;
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT32                                              ulAbortcode;
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_Ttag
{
  TLR_UINT32                                              ulTotalDataBytes;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_T      atEntries[1];
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_T       tData;
} __TLR_PACKED_POST ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_T;


/* packet union */
typedef union ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_REQ_T            tReq;
  ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_CNF_T            tCnf;
} ODV3_WRITE_MULTIPLE_PARAMETER_BY_INDEX_PCK_T;


/******************************************************************************
 * Packet:  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ/ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF
 *
 * Fragmentation:
 *                            Request/Indication  Response/Confirmation
 * TLR_PACKET_SEQ_FIRST       ulDestId = 0        ulDestId = X
 * TLR_PACKET_SEQ_MIDDLE      ulDestId = X        ulDestId == X
 * TLR_PACKET_SEQ_LAST        ulDestId = X        ulDestId == X
 *
 * X is a handle to the running transfer
 *
 * Attention! fragmenting may happen in both directions
 *
 * ulSta must be TLR_S_OK on request, otherwise it is considered an abort.
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT8                                               bMultipleParaAccessFlags; /* access flags for multiple parameter access */
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_Ttag
{
  TLR_UINT32                                              ulTotalDataBytes;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_ENTRY_T       atEntries[1];
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_DATA_T        tData;
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_UINT32                                              ulAbortcode;      /* if != 0, ulDataByteSize = 0 */
  TLR_UINT32                                              ulDataByteSize;   /* if (ulDataByteSize & 3) != 0, abData is padded to 4 byte border */
  TLR_UINT8                                               abData[1];        /* variable size */
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_Ttag
{
  TLR_UINT32                                              ulTotalDataBytes;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_ENTRY_T       atEntries[1];
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_DATA_T        tData;
} __TLR_PACKED_POST ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_T;


/* packet union */
typedef union ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_REQ_T             tReq;
  ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_CNF_T             tCnf;
} ODV3_READ_MULTIPLE_PARAMETER_BY_INDEX_PCK_T;


/******************************************************************************
 * Packet:  ODV3_RESET_OBJECTS_REQ/ODV3_RESET_OBJECTS_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECTS_REQ_RANGE_ENTRIES_Ttag
{
  TLR_UINT16                                              usRangeStart;
  TLR_UINT16                                              usRangeCount;   /* 0 = 65536 objects */
} __TLR_PACKED_POST ODV3_RESET_OBJECTS_REQ_RANGE_ENTRIES_T;

typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECTS_REQ_DATA_Ttag
{
  ODV3_RESET_OBJECTS_REQ_RANGE_ENTRIES_T                  atEntries[1];
} __TLR_PACKED_POST ODV3_RESET_OBJECTS_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECTS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_RESET_OBJECTS_REQ_DATA_T                           tData;
} __TLR_PACKED_POST ODV3_RESET_OBJECTS_REQ_T;


/* indication packet */
typedef ODV3_RESET_OBJECTS_REQ_RANGE_ENTRIES_T ODV3_RESET_OBJECTS_IND_RANGE_ENTRIES_T;
typedef ODV3_RESET_OBJECTS_REQ_DATA_T ODV3_RESET_OBJECTS_IND_DATA_T;
typedef ODV3_RESET_OBJECTS_REQ_T ODV3_RESET_OBJECTS_IND_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECTS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_RESET_OBJECTS_CNF_T;


/* response packet */
typedef ODV3_RESET_OBJECTS_CNF_T ODV3_RESET_OBJECTS_RES_T;


/* packet union */
typedef union ODV3_RESET_OBJECTS_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_RESET_OBJECTS_REQ_T                                tReq;
  ODV3_RESET_OBJECTS_IND_T                                tInd;
  ODV3_RESET_OBJECTS_RES_T                                tRes;
  ODV3_RESET_OBJECTS_CNF_T                                tCnf;
} ODV3_RESET_OBJECTS_PCK_T;


/******************************************************************************
 * Packet:  ODV3_SET_OBJECT_NAME_REQ/ODV3_SET_OBJECT_NAME_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_OBJECT_NAME_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_STR                                                 szName[200];  /* must be NUL-terminated */
} __TLR_PACKED_POST ODV3_SET_OBJECT_NAME_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_SET_OBJECT_NAME_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_OBJECT_NAME_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_SET_OBJECT_NAME_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_OBJECT_NAME_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
} __TLR_PACKED_POST ODV3_SET_OBJECT_NAME_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_SET_OBJECT_NAME_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_OBJECT_NAME_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_SET_OBJECT_NAME_CNF_T;


/* packet union */
typedef union ODV3_SET_OBJECT_NAME_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_OBJECT_NAME_REQ_T                              tReq;
  ODV3_SET_OBJECT_NAME_CNF_T                              tCnf;
} ODV3_SET_OBJECT_NAME_PCK_T;


/******************************************************************************
 * Packet:  ODV3_SET_SUBOBJECT_NAME_REQ/ODV3_SET_SUBOBJECT_NAME_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_SUBOBJECT_NAME_REQ_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
  TLR_STR                                                 szName[200];  /* must be NUL-terminated */
} __TLR_PACKED_POST ODV3_SET_SUBOBJECT_NAME_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_SET_SUBOBJECT_NAME_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_SUBOBJECT_NAME_REQ_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_SET_SUBOBJECT_NAME_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_SUBOBJECT_NAME_CNF_DATA_Ttag
{
  TLR_UINT16                                              usIndex;
  TLR_UINT8                                               bSubIndex;
} __TLR_PACKED_POST ODV3_SET_SUBOBJECT_NAME_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_SET_SUBOBJECT_NAME_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_SUBOBJECT_NAME_CNF_DATA_T                      tData;
} __TLR_PACKED_POST ODV3_SET_SUBOBJECT_NAME_CNF_T;


/* packet union */
typedef union ODV3_SET_SUBOBJECT_NAME_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_SUBOBJECT_NAME_REQ_T                           tReq;
  ODV3_SET_SUBOBJECT_NAME_CNF_T                           tCnf;
} ODV3_SET_SUBOBJECT_NAME_PCK_T;


/******************************************************************************
 * Packet:  ODV3_CREATE_DATATYPE_REQ/ODV3_CREATE_DATATYPE_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_DATATYPE_REQ_DATA_Ttag
{
  TLR_UINT16                                              usDatatype;
  TLR_UINT32                                              ulDatatypeBitLength;
} __TLR_PACKED_POST ODV3_CREATE_DATATYPE_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_DATATYPE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_DATATYPE_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_CREATE_DATATYPE_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_CREATE_DATATYPE_CNF_DATA_Ttag
{
  TLR_UINT16                                              usDatatype;
} __TLR_PACKED_POST ODV3_CREATE_DATATYPE_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_CREATE_DATATYPE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_DATATYPE_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_CREATE_DATATYPE_CNF_T;


/* packet union */
typedef union ODV3_CREATE_DATATYPE_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_CREATE_DATATYPE_REQ_T                              tReq;
  ODV3_CREATE_DATATYPE_CNF_T                              tCnf;
} ODV3_CREATE_DATATYPE_PCK_T;


/******************************************************************************
 * Packet:  ODV3_DELETE_DATATYPE_REQ/ODV3_DELETE_DATATYPE_CNF
 *
 * ulSta must be TLR_S_OK on request
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_DATATYPE_REQ_DATA_Ttag
{
  TLR_UINT16                                              usDatatype;
} __TLR_PACKED_POST ODV3_DELETE_DATATYPE_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_DATATYPE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_DATATYPE_REQ_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_DELETE_DATATYPE_REQ_T;


/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_DELETE_DATATYPE_CNF_DATA_Ttag
{
  TLR_UINT16                                              usDatatype;
} __TLR_PACKED_POST ODV3_DELETE_DATATYPE_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_DELETE_DATATYPE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_DATATYPE_CNF_DATA_T                         tData;
} __TLR_PACKED_POST ODV3_DELETE_DATATYPE_CNF_T;


/* packet union */
typedef union ODV3_DELETE_DATATYPE_PCK_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_DELETE_DATATYPE_REQ_T                              tReq;
  ODV3_DELETE_DATATYPE_CNF_T                              tCnf;
} ODV3_DELETE_DATATYPE_PCK_T;

/******************************************************************************
 * Packet:  ODV3_RESET_OBJECT_DICTIONARY_REQ/ODV3_RESET_OBJECT_DICTIONARY_CNF
 *
 * internal request for stack use
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECT_DICTIONARY_REQ_DATA_Ttag
{
  TLR_UINT16                                              ausIndexes[500];
  /*
   * ausIndexes: dynamic list => tHead.ulLen = numentries * sizeof(TLR_UINT16)
   * list must be sorted
   */
} __TLR_PACKED_POST ODV3_RESET_OBJECT_DICTIONARY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECT_DICTIONARY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_RESET_OBJECT_DICTIONARY_REQ_DATA_T                 tData;
} __TLR_PACKED_POST ODV3_RESET_OBJECT_DICTIONARY_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_RESET_OBJECT_DICTIONARY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_RESET_OBJECT_DICTIONARY_CNF_T;


/******************************************************************************
 * Packet:  ODV3_SET_TIMEOUT_REQ/ODV3_SET_TIMEOUT_CNF
 *
 * internal request for stack use
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_TIMEOUT_REQ_DATA_Ttag
{
  TLR_UINT32 ulTimeoutMs;
} __TLR_PACKED_POST ODV3_SET_TIMEOUT_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_SET_TIMEOUT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_SET_TIMEOUT_REQ_DATA_T                             tData;
} __TLR_PACKED_POST ODV3_SET_TIMEOUT_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_SET_TIMEOUT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_SET_TIMEOUT_CNF_T;


/******************************************************************************
 * Packet:  ODV3_GET_TIMEOUT_REQ/ODV3_GET_TIMEOUT_CNF
 *
 * internal request for stack use
 */

/* request packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_TIMEOUT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
} __TLR_PACKED_POST ODV3_GET_TIMEOUT_REQ_T;

/* confirmation packet */
typedef __TLR_PACKED_PRE struct ODV3_GET_TIMEOUT_CNF_DATA_Ttag
{
  TLR_UINT32 ulTimeoutMs;
} __TLR_PACKED_POST ODV3_GET_TIMEOUT_CNF_DATA_T;

typedef __TLR_PACKED_PRE struct ODV3_GET_TIMEOUT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                     tHead;
  ODV3_GET_TIMEOUT_CNF_DATA_T                             tData;
} __TLR_PACKED_POST ODV3_GET_TIMEOUT_CNF_T;

/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(ODV3_PUBLIC)
#endif


#endif
