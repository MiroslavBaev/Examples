/****************************************************************************
  File          : AP_DbmDyn.h
-----------------------------------------------------------------------------
  Author        : Hilscher GmbH,  Copyright (c) 2009
  
                  Hilscher GmbH, Copyright (c) 2009
                  All Rights Reserved
                  
                  Redistribution or unauthorized use without expressed written 
                  agreement from the Author is forbidden

  Date          : 19-March-2003
  
  Project       : rcX - realtime communication-system for netX
-----------------------------------------------------------------------------
  Description:

    USER - Headerfile of dynamic Database Module
      
-----------------------------------------------------------------------------
  Todo:
-----------------------------------------------------------------------------
  Changes:

    Name   Date          Version    Description
    -----------------------------------------------------------------------
    hp     18-March-2009    1.000   created
****************************************************************************/
/** 
 \file AP_DbmDyn.h
  Definitions of the API relevant Prototypes and defines.
  \par License: Copyright &copy; Hilscher GmbH. All Rights Reserved.
  \todo Select the correct settings in the following list.
  \li \c Win32/ANSI    : yes/yes
  \li \c Win32/Unicode : yes
  \li \c WinCE         : no
  \li \c using MFC     : no
  
  \section DbmRCX_h_history History:
  \version see <a href=".\OwnHtml\version.html" title="Versions">Versions</a>
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_DBMDYN_H
  #define __AP_DBMDYN_H

#ifndef _WIN32
#include "rcX_Public.h"
#endif /*ndef _WIN32*/

  /************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  RX_FATAL FAR    MidDynDatabaseInit(         /*[in]*/ void FAR*         pvPar,
                                              /*[in]*/ UINT              uPar);  
  /************************** DATABASE **************************************/
  RX_RESULT FAR Mid_DbmDynDatabaseOpen(       /*[in]*/ STRING FAR*       pszNam,
                                              /*[in/out]*/ RX_HANDLE FAR*    phDbmDyn);

  RX_RESULT FAR Mid_DbmDynDatabaseWrite(      /*[in]*/ STRING FAR*       pszNam,
                                              /*[in]*/ RX_HANDLE         hDbmDyn);

  RX_RESULT FAR Mid_DbmDynDatabaseClose(      /*[in]*/ RX_HANDLE         hDbmDyn); 

  /* Read a property from the Database */
  #define DYNDB_PROP_MD5             1   /**< ptMD5 will return the MD5 sum of this Database*/
  #define DYNDB_PROP_FILE_LENGTH     2   /**< pdwRet will return the file length in bytes of this Database*/
  #define DYNDB_PROP_MAJOR_VERSION   3   /**< pdwRet will return the major version of the tool which created this Database*/
  #define DYNDB_PROP_MINOR_VERSION   4   /**< pdwRet will return the minor versin (if available)*/
  #define DYNDB_PROP_IS_CHANGED      5   /**< pdwRet will return TRUE if the database was changed*/
  RX_RESULT FAR Mid_DbmDynGetDatabaseProperty(/*[in]*/ RX_HANDLE              hDbmDyn,
                                              /*[in]*/ DWORD                  dwProperty,
                                              /*[in]*/ DWORD                  dwLength,
                                              /*[out]*/BYTE FAR*              pbProperty,
                                              /*[out]*/DWORD FAR*             pdwCopied);

  /**************************** TABLES **************************************/
  RX_RESULT FAR Mid_DbmDynTableOpen(          /*[in]*/ enum eDbmFN       eFN,
                                              /*[in]*/ enum eDbmRW       eRW,
                                              /*[in]*/ STRING FAR*       pszName,
                                              /*[in]*/ RX_HANDLE         hDbmDyn,
                                              /*[out]*/RX_HANDLE FAR*    phDbmTbl);

  RX_RESULT FAR Mid_DbmDynTableClose(         /*[in]*/ RX_HANDLE         hDbmDyn,
                                              /*[in]*/ RX_HANDLE         hDbmTbl);

  /* Read a property from a Table */
  #define DYNTAB_PROP_TYPE             1   /**< pdwRet will return the type of this Table (1,2,3 or 4)*/
  #define DYNTAB_PROP_RECCNT           2   /**< pdwRet will return the count of Records if this Table is of type 1,2 or 3*/
  #define DYNTAB_PROP_NAME             3   /**< pdwRet will return the name of this Table as a */
  #define DYNTAB_PROP_STRUCTAVAILABLE  4   /**< pdwRet will return TRUE if a structure is available*/
  #define DYNTAB_PROP_RECORD_LENGTH    5   /**< pdwRet will return the calculated length of one record in bytes.<br>
    This will only work if the Table Type is 2,3 or 4 and if at least one record is present.<br>
    The function will return only the length of the first record which is found and not the 
    calculated length based on the structure definition.<br>
    <span class="red">This assumes all records have the same length!</span>*/
  #define DYNTAB_PROP_VERSION          6   /**< pdwRet will return the Version of this Table.<br>*/
  #define DYNTAB_PROP_STRCUTCNT        7   /**< pdwRet will return the count of Structure Elements if this Table holds a structure definition*/
  #define DYNTAB_PROP_KEYCNT           8   /**< pdwRet will return the count of Keys if this Table is of type eDbmTableTypeLinkedList*/
  #define DYNTAB_PROP_HASKEYS          9   /**< pdwRet will return TRUE if this Table has Key references in the structure definition.*/

  RX_RESULT FAR Mid_DbmDynGetTableProperty(   /*[in]*/ RX_HANDLE              hDbmDyn,
                                              /*[in]*/ RX_HANDLE              hDbmTbl,
                                              /*[in]*/ DWORD                  dwProperty,
                                              /*[in]*/ DWORD                  dwLength,
                                              /*[in]*/ DWORD                  dwKey, /*tbd*/
                                              /*[out]*/BYTE FAR*              pbProperty,
                                              /*[out]*/DWORD FAR*             pdwCopied);

  /**************************** RECORDS *************************************/
  RX_RESULT FAR Mid_DbmDynRecordOpen(         /*[in]*/ enum eDbmFN        eFN,
                                              /*[in]*/ enum eDbmRW        eRW,
                                              /*[in]*/ DWORD              dwRecNumber,
                                              /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[out]*/RX_HANDLE FAR*     phDbmRec);

  RX_RESULT FAR Mid_DbmDynRecordClose(        /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[in]*/ RX_HANDLE          hDbmRec);

  RX_RESULT FAR Mid_DbmDynRecordRead(         /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[in]*/ RX_HANDLE          hDbmRec,
                                              /*[in]*/ DWORD              dwLength,
                                              /*[out]*/BYTE FAR*          pbRecData,
                                              /*[out]*/DWORD FAR*         pdwCopied);

  RX_RESULT FAR Mid_DbmDynRecordDelete(       /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[in]*/ RX_HANDLE          hDbmRec);

  RX_RESULT FAR Mid_DbmDynRecordNew(          /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[out]*/RX_HANDLE FAR*     phDbmRec,
                                              /*[in]*/ DWORD              dwLength,
                                              /*[in]*/ BYTE FAR*          pbRecData);

  RX_RESULT FAR Mid_DbmDynRecordWrite(        /*[in]*/ RX_HANDLE          hDbmDyn,
                                              /*[in]*/ RX_HANDLE          hDbmTbl,
                                              /*[in]*/ RX_HANDLE          hDbmRec,
                                              /*[in]*/ DWORD              dwLength,
                                              /*[in]*/ BYTE FAR*          pbRecData);

  /* Read a property from a Record */
  #define DYNREC_PROP_NUMBER   1   /**< pdwRet will return the number (index) of this Record*/
  #define DYNREC_PROP_LENGTH   2   /**< pdwRet will return the length in bytes */

  RX_RESULT FAR Mid_DbmDynGetRecordProperty ( /*[in]*/ RX_HANDLE              hDbmDyn,
                                              /*[in]*/ RX_HANDLE              hTable,
                                              /*[in]*/ RX_HANDLE              hRecord,
                                              /*[in]*/ DWORD                  dwProperty,
                                              /*[in]*/ DWORD                  dwLength,
                                              /*[out]*/BYTE FAR*              pbProperty,
                                              /*[out]*/DWORD FAR*             pdwCopied);
                                              
  
#endif /* #ifndef __AP_DBMDYN_H */

#ifdef __cplusplus
}
#endif
