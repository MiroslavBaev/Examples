/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Flt.h 936 2012-05-09 13:36:03Z stephans $

  Description:
    USER - Headerfile of Fault Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/

#ifndef __AP_FLT_H
#define __AP_FLT_H

#ifdef __cplusplus
  extern "C" {
#endif

  #include "rX_Config.h"

  enum RX_FAULT_FATAL_VECTOR_RETURNtag
  {
    RX_FAULT_FATAL_HOLD,
    RX_FAULT_FATAL_CONTINUE
  };
  typedef int RX_FAULT_FATAL_VECTOR_RETURN;
  
  typedef RX_FAULT_FATAL_VECTOR_RETURN(CALLBACK FAR* PFN_RCX_FATAL_VECTOR)(RX_FATAL eFat);
  typedef RX_FAULT_FATAL_VECTOR_RETURN(CALLBACK FAR* PFN_RCX_FAULT_VECTOR)(RX_PERIPHERAL_TYPE ePerType, const void FAR* pvCfg, RX_RESULT erXRes, void FAR* pvPrm);

  void FAR rX_FltSetFatalVector           (PFN_RCX_FATAL_VECTOR pfnFatalVector);
  void FAR rX_FltGetFatalVector           (PFN_RCX_FATAL_VECTOR FAR* ppfnFatalVector);

  void FAR rX_FltSetDriverFaultVector     (PFN_RCX_FAULT_VECTOR      pfnFaulVector,
                                           void FAR*                 pvPrm);
  void FAR rX_FltGetDriverFaultVector     (PFN_RCX_FAULT_VECTOR FAR* ppfnFaulVector,
                                           void FAR* FAR*            ppvPrm);

  RX_FATAL FAR   rX_FltDriverFault        (RX_PERIPHERAL_TYPE        ePerType, 
                                           const void FAR*           pvCfg,
                                           RX_RESULT                 erXRes,
                                           RX_FATAL                  erXFat);
#ifdef __cplusplus
  }
#endif

#endif /* __AP_FLT_H */
