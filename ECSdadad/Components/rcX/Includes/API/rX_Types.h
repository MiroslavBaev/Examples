/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: rX_Types.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX Abstract data type definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __RX_TYPES_H
#define __RX_TYPES_H

#include "rX_Compiler.h"
#include <stdint.h>

/******************************************************
* Redefine data types of ISO-C99 for being old
* (rcX V1/2) compatible
******************************************************/
typedef uint8_t       UINT8;
typedef int8_t        INT8;
typedef uint16_t      UINT16;
typedef int16_t       INT16;
typedef uint32_t      UINT32;
typedef int32_t       INT32;
typedef uint64_t      UINT64;
typedef int64_t       INT64;

typedef char          STRING;

typedef uint8_t       BYTE;  
typedef uint16_t      WORD;
typedef uint32_t      DWORD;


typedef int           INT;
typedef unsigned int  UINT;
typedef unsigned int  BOOLEAN;
typedef unsigned int  BOOL;

typedef void FAR*     RX_HANDLE;

/* Data types for backward compatibility only !!! */
typedef unsigned long  ULONG;
typedef void           VOID;
typedef char           CHAR;
typedef float          FLOAT;
/* Data types for backward compatibility only !!! */


/************************************************************
* Definition of old linked list. Preferred lists are from
* <sys/types.h> now, as they are typesafe
************************************************************/
typedef struct RX_DOUBLE_LINK_Ttag
{
  struct RX_DOUBLE_LINK_Ttag FAR * ptNxt;  /* Pointer to next entry */
  struct RX_DOUBLE_LINK_Ttag FAR * ptPrv;  /* Pointer to previous entry */
} RX_DOUBLE_LINK_T;

typedef struct RX_SINGLE_LINKtag
{
  struct RX_SINGLE_LINKtag FAR* ptNxt;  /* Pointer to next entry */
} RX_SINGLE_LINK;


/******************************************************
*       Constant-Defintions
******************************************************/
#ifndef FALSE
  #define FALSE (0)
#endif /* FALSE */

#ifndef TRUE
  #define TRUE  (1)
#endif /* TRUE */

#ifndef NULL
  #define NULL  ((void*)0)
#endif /* NULL */

#endif /* __RX_TYPES_H */
