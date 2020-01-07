/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: rX_Modules.h 929 2012-04-18 08:13:16Z mtrensch $

  Description:
    Module support

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef _RCX_MODULE_ABI_H
#define _RCX_MODULE_ABI_H

#include "rX_TagLists.h"
#include "HilFileHeader.h"

typedef UINT32 RCX_MODULE_INIT_RESULT;

/* Values for RCX_MODULE_INIT_RESULT, returned by ModuleInitFunction() */
#define RCX_MODULE_S_OK               0
/* XXX RCX_MODULE_S_ERROR ? defined by not yet created header / defined during implementation */

#define RCX_MODULE_SECTION ".rcx_module"

typedef struct RCX_MODULE_DESCRIPTOR_Ttag RCX_MODULE_DESCRIPTOR_T;
typedef struct RCX_MODULE_START_INFO_Ttag RCX_MODULE_START_INFO_T;

typedef RCX_MODULE_INIT_RESULT (* RCX_MODULE_INIT_FN)(UINT32 ulChannelNo, RCX_MODULE_START_INFO_T* ptModuleInfo);

struct RCX_MODULE_DESCRIPTOR_Ttag
{
  UINT32                                  ulDescriptorVersion;
  STRING*                                 pszModuleName;
  RCX_MODULE_INIT_FN                      pfnModuleInitFunc;
  void*                                   apfnReserved[3];
};

#define RCX_MODULE_DESCRIPTOR_VERSION_RCX_V2_0    1
#define RCX_MODULE_DESCRIPTOR_VERSION_RCX_V2_1    2


struct RCX_MODULE_START_INFO_Ttag
{
  /* pointer to module header */
  HIL_FILE_MODULE_HEADER*                 ptModuleHeader;

  /* pointer to tag list */
  const RCX_MODULE_TAG_ENTRY_HEADER_T*    ptTagList;

  /* length of tag list specified by HIL_FILE_MODULE_HEADER (starting from tag list begin)
   * this allows to check whether a tag list has corrupt entries or is missing the RCX_MOD_TAG_UD_END entry.
  */
  UINT32                                  ulTagListSize;

  /* pointer to module descriptor */
  const RCX_MODULE_DESCRIPTOR_T*          ptModuleDescriptor;

  /* function table into rcX functions */
  void**                                  ppvJumpTable;
  UINT32                                  ulJumpTableElements;

  /* function table into libc functions */
  void**                                  ppvLibcJumpTable;
  UINT32                                  ulLibcJumpTableElements; /* all entries including special entries at start */
};

RCX_MODULE_INIT_RESULT
ModuleInitFunction(
                      UINT32                          ulChannelNo,
                      RCX_MODULE_START_INFO_T*        ptModuleInfo);

/* first function to be called within module if any inits need to prepend ModuleInitFunction */
RCX_MODULE_INIT_RESULT
ModuleInitFunctionTable(
                      UINT32                          ulChannelNo,
                      RCX_MODULE_START_INFO_T*        ptModuleInfo);

RCX_MODULE_INIT_RESULT
ModuleInitXc(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitPhy(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitEdd(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitHwTim(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitInt(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitIntPatchCfgByGroup(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      RCX_MOD_TAG_IT_INTERRUPT_TAG_T* ptGroupCfg);

RCX_MODULE_INIT_RESULT
ModuleInitFif(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitGpio(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitPio(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitUart(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

RCX_MODULE_INIT_RESULT
ModuleInitSpi(
                      void*                           pvSet,
                      UINT32                          ulNumSet,
                      UINT32                          ulChannelNo);

#endif
