/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: MMU.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    rcX netX100/500 MMU definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef __MMU_H
#define __MMU_H

/*********************************************/
/*! Mapping Table single entry               */
/*********************************************/
typedef struct MMU_MAPPING_TABLE_Ttag
{
  unsigned int uiPhysicalAddr;  /**< Physical Start Address of Region */
  unsigned int uiVirtualAddr;   /**< Virtual Start of region */
  unsigned int uiSize;          /**< Size of region in MB */
  
  unsigned char bCache;         /**< cache options for region (ARM_UNCACHEABLE, ARM_CACHEABLE) */
  unsigned char bBuffer;        /**< buffering options for region (ARM_UNBUFFERABLE, ARM_BUFFERABLE) */
  unsigned char bAccess;        /**< Access rights for region (ARM_ACCESS_PERM_XXX) */
  unsigned char bReserved;

} MMU_MAPPING_TABLE_T;

/* values for MMU_MAPPING_TABLE_T.bCache */
#define ARM_UNCACHEABLE                         0 /**< area is uncached   */
#define ARM_CACHEABLE                           1 /**< area is cached     */

/* values for MMU_MAPPING_TABLE_T.bBuffer */
#define ARM_UNBUFFERABLE                        0 /**< area is unbuffered */
#define ARM_BUFFERABLE                          1 /**< area is buffered   */

/* values for MMU_MAPPING_TABLE_T.bAccess */
#define ARM_ACCESS_PERM_NONE_NONE               0
#define ARM_ACCESS_PERM_RO_NONE                 0
#define ARM_ACCESS_PERM_RO_RO                   0
#define ARM_ACCESS_PERM_RW_NONE                 1
#define ARM_ACCESS_PERM_RW_RO                   2
#define ARM_ACCESS_PERM_RW_RW                   3

/* ATTENTION: the MMU table is terminated by an entry with a uiSize == 0*/
#define GLOBAL_MMU_TABLE  MMU_MAPPING_TABLE_T g_atrXMMUTable[]

#endif /* __MMU_H */
