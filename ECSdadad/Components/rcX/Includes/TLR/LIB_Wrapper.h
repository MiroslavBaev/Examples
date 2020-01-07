/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: LIB_Wrapper.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    standard C library abstraction (key functions only)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-10-06  NC            If __RCX__ is defined, LIB_MALLOC and LIB_FREE
                              are based on rcX heap management functions.

    2010-04-07  NC            Changed Parameter names corresponding to the
                              manual

    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __LIB_WRAPPER_H
#define __LIB_WRAPPER_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/


/* none */



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


#ifdef __RCX__

  /* memory allocation */
  INLINE TLR_VOID* LIB_MALLOC(TLR_UINT32 ulNumBytes)
  {
    TLR_VOID* pvMem = NULL;
    rX_MemAllocateMemory (&pvMem, ulNumBytes);
    return (pvMem);
  }

  #define LIB_FREE(pvMem) rX_MemFreeMemory(pvMem)

  /* run-time memory handling */
  #define LIB_MEMCPY(pvMemDest, pvMemSrc, ulNumBytes) rX_BasMemCpyFast(pvMemDest, pvMemSrc, ulNumBytes)
  #define LIB_MEMSET(pvMem, iValue, ulNumBytes)       memset(pvMem, iValue, ulNumBytes)
  #define LIB_MEMCMP(pvMem1, pvMem2, ulNumBytes)      memcmp(pvMem1, pvMem2, ulNumBytes)

#else /* __RCX__ */

  /* memory allocation */
  #define LIB_MALLOC(ulNumBytes) malloc(ulNumBytes)
  #define LIB_FREE(pvMem)        free(pvMem)

  /* run-time memory handling */
  #define LIB_MEMCPY(pvMemDest, pvMemSrc, ulNumBytes) memcpy(pvMemDest, pvMemSrc, ulNumBytes)
  #define LIB_MEMSET(pvMem, iValue, ulNumBytes)       memset(pvMem, iValue, ulNumBytes)
  #define LIB_MEMCMP(pvMem1, pvMem2, ulNumBytes)      memcmp(pvMem1, pvMem2, ulNumBytes)

#endif  /* __RCX__ */


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __LIB_WRAPPER_H */
