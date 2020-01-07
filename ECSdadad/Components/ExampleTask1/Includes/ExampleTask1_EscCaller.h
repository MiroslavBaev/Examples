/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_EscCaller.h 1304 2015-08-14 10:02:08Z Ricky $:
 
Description:
 See doxygen 
***********************************************************************************//**
  \file ExampleTask1_EscCaller.h
  \note EXAMPLETASK1_RSC_T must be included before with ESC_CALLER_T defined as
        ptRsc->tRem.tEscCaller in file ExampleTask1_Resources.h
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY
typedef struct ESC_CALLER_Ttag{
  TLR_HANDLE hEcatInterface;
}ESC_CALLER_T;
#else
#ifndef EXAMPLETASK1_ESCCALLER_H_
#define EXAMPLETASK1_ESCCALLER_H_
#include <stdint.h>

uint32_t EscCaller_Init(EXAMPLETASK1_RSC_T* ptRsc);

static inline TLR_HANDLE EscCaller_GetEscHandle(EXAMPLETASK1_RSC_T* ptRsc)
{
  return ptRsc->tRem.tEscCaller.hEcatInterface;
}
#endif /* INCLUDE_TYPEDEF_ONLY */
#endif /* EXAMPLETASK1_ESCCALLER_H_ */
