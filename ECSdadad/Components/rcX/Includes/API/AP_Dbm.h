/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Dbm.h 1553 2013-08-06 06:31:14Z MichaelT $

  Description:
    USER - Headerfile of Database Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_DBM_H
  #define __AP_DBM_H

  #include "rcX_Public.h"

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  
  RX_FATAL FAR    MidDatabaseInit               (void FAR*        pvPar,
                                                 UINT             uPar);
  
  RX_RESULT FAR Mid_DbmOpenDbmFile            (STRING FAR*      pszNam,
                                               RX_HANDLE FAR*   phDbmFil);

  RX_RESULT FAR Mid_DbmIdentifyTable          (STRING FAR*      pszNam,
                                               RX_HANDLE        hDbmFil,
                                               RX_HANDLE FAR*   phDbmTbl,
                                               DWORD FAR*       puNumofSet);

  RX_RESULT FAR Mid_DbmGetDatasetPointer      (RX_HANDLE        hDbmFil,
                                               RX_HANDLE        hDbmTbl, 
                                               DWORD            uSetIdx, 
                                               BYTE FAR* FAR*   ppbDatSet,
                                               DWORD FAR*       puRealSiz);

  RX_RESULT FAR Mid_DbmGetLLHandle            (/*[in]*/RX_HANDLE       hDbmFil,
                                               /*[in]*/RX_HANDLE       hDbmTbl, 
                                               /*[in]*/DWORD           dwKey,
                                               /*[out]*/RX_HANDLE FAR* phDbmLLTbl);

  RX_RESULT FAR Mid_DbmLLGetFirstRecordPtr    (/*[in]*/RX_HANDLE       hDbmFil,
                                               /*[in]*/RX_HANDLE       hDbmLLTbl, 
                                               /*[out]*/RX_HANDLE FAR* phPos, 
                                               /*[out]*/RX_HANDLE FAR* phRecord, 
                                               /*[out]*/BYTE FAR* FAR* ppbRecord,
                                               /*[out]*/DWORD FAR*     pdwSize);

  /* Read the next record in a linked list table */
  RX_RESULT FAR Mid_DbmLLGetNextRecordPtr     (/*[in]*/RX_HANDLE           hDbmFil,
                                               /*[in]*/RX_HANDLE           hDbmLLTbl, 
                                               /*[in/out]*/RX_HANDLE FAR*  phPos, 
                                               /*[out]*/RX_HANDLE FAR*     phRecord, 
                                               /*[out]*/BYTE FAR* FAR*     ppbRecord,
                                               /*[out]*/DWORD FAR*         pdwSize);

  RX_RESULT FAR Mid_DbmLLGetFirstKEY          (/*[in]*/RX_HANDLE           hDbmFil,
                                               /*[in]*/RX_HANDLE           hDbmLLTbl, 
                                               /*[out]*/RX_HANDLE FAR*     phPOS,
                                               /*[out]*/RX_HANDLE FAR*     phKEY);

  /* Read the next KEY in a linked list table */
  RX_RESULT FAR Mid_DbmLLGetNextKEY           (/*[in]*/RX_HANDLE           hDbmFil,
                                               /*[in]*/RX_HANDLE           hDbmLLTbl, 
                                               /*[in/out]*/RX_HANDLE FAR*  phPOS,
                                               /*[out]*/RX_HANDLE FAR*     phKEY);

  RX_RESULT FAR Mid_DbmCloseDbmFile           (RX_HANDLE        hDbmFil); 

  /* Read a property from a Table */
  #define TAB_PROP_NUMBER           1   /**< pdwRet will return the number (index) of this Table*/
  #define TAB_PROP_TYPE             2   /**< pdwRet will return the type of this Table (1,2,3 or 4)*/
  #define TAB_PROP_KEYCNT           3   /**< pdwRet will return the count of different KEYs if this Table is of type 4*/
  #define TAB_PROP_RECCNT           4   /**< pdwRet will return the count of Records if this Table is of type 1,2 or 3*/
  #define TAB_PROP_NAME             5   /**< pdwRet will return the name of this Table*/
  #define TAB_PROP_STRUCTAVAILABLE  6   /**< pdwRet will return TRUE if a structure is available*/
  #define TAB_PROP_RECORD_LENGTH    7   /**< pdwRet will return the calculated length of one record in bytes.<br>
    This will only work if the Table Type is 2,3 or 4 and if at least one record is present.<br>
    The function will return only the length of the first record which is found and not the 
    calculated length based on the structure definition.<br>
    <span class="red">This assumes all records have the same length!</span>*/
  #define TAB_PROP_VERSION          8   /**< pdwRet will return the Version of this Table.<br>*/
  #define TAB_PROP_RECKEYCNT        9   /**< pdwRet will return the count of all Records for all KEYs if this Table is of type 1,2 or 3*/

  RX_RESULT FAR Mid_DbmGetTabProperty         (/*[in]*/RX_HANDLE               hDbmFil,
                                               /*[in]*/RX_HANDLE               hDbmTbl,
                                               /*[in]*/DWORD                   dwProperty,   /*see TAB_PROP_..*/
                                               /*[out]*/DWORD FAR*             pdwRet);      /*depends on dwProperty*/

  /* Read a property from a Record */
  #define REC_PROP_NUMBER   1   /**< pdwRet will return the number (index) of this Record*/
  #define REC_PROP_LENGTH   2   /**< pdwRet will return the length in bytes */

  RX_RESULT FAR Mid_DbmGetRecProperty         (/*[in]*/RX_HANDLE               hDbmFil,
                                               /*[in]*/RX_HANDLE               hRecord,
                                               /*[in]*/DWORD                   dwProperty,   /*see REC_PROP_..*/
                                               /*[out]*/DWORD FAR*             pdwRet);      /*depends on dwProperty*/
  
  RX_RESULT FAR Mid_DbmWriteFile(RX_HANDLE hDbmFil);

  /* Read a property from the Database */
  #define DB_PROP_MD5             1   /**< ptMD5 will return the MD5 sum of this Database*/
  #define DB_PROP_FILE_LENGTH     2   /**< pdwRet will return the file length in bytes of this Database*/
  #define DB_PROP_MAJOR_VERSION   3   /**< pdwRet will return the major version of the tool which created this Database*/
  #define DB_PROP_MINOR_VERSION   4   /**< pdwRet will return the minor versin (if available)*/
  
#ifdef __RCX_PUBLIC_H
  RX_RESULT FAR Mid_DbmGetDatabaseProperty(   /*[in]*/ RX_HANDLE        hDbmFil,
                                              /*[in]*/ DWORD            dwProperty,   /*see DB_PROP_..*/
                                              /*[out]*/RCX_FILE_GET_MD5_CNF_DATA_T FAR* ptMD5,
                                              /*[out]*/DWORD FAR*       pdwRet);       /*depends on dwProperty*/
#endif /* #ifdef __RCX_PUBLIC_H */
#endif /* #ifndef __AP_DBM_H */

#ifdef __cplusplus
}
#endif
