/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_INX_Includes.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR INX header file aggregation

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-29  NC            Modified include guard to stop recursion if
                              OS_Wrapper.h has already been opened.
    2010-04-12  NC            Case sensitivity for Linux.
    2010-03-23  NC            File created.

******************************************************************************/


#if !defined( __TLR_INX_INCLUDES_H ) && !defined( __OS_WRAPPER_H )
#define __TLR_INX_INCLUDES_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/

#include "TLR_Types.h"          /* TLR basic type definitions */
#include "TLR_Common.h"         /* TLR common definitions */
#include "TLR_Diag.h"           /* TLR diagnostics definitions */
#include "TLR_Commands.h"       /* TLR commands */
#include "TLR_Facilities.h"     /* TLR facility codes */
#include "TLR_TaskIdentifier.h" /* TLR task identifier codes */
#include "TLR_global_error.h"   /* TLR global error codes */
#include "tlr_router_error.h"   /* packet router error codes */
#include "OS_Wrapper.h"         /* wrapper for OS definitions and functions */
#include "TLS_Wrapper.h"        /* wrapper providing support and comfort functions based on TLR basics */


/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/


/* none */



/*****************************************************************************/
/* Class, Type, and Structure Definitions                                    */
/*****************************************************************************/


/* none */



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

#endif  /* __TLR_INX_INCLUDES_H */
