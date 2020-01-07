/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_MidSys_PhysHif.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Mid Sys - Phys HIF

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_MID_SYS_PHYSHIF_H
#define __AP_MID_SYS_PHYSHIF_H


/***************************************************************************************/
/* Mid Sys public, constants */


/***************************************************************************************/
/* Mid Sys public, prototypes */


RX_FATAL FAR    _physHif_MidSysInit                  (void FAR*        pvPar,
                                             UINT             uPar);

RX_FATAL FAR    _physHif_MidSysModuleLoadInit        (void FAR*        pvPar,
                                             UINT             uPar);

RX_FATAL FAR    _physHif_MidSysDpmInit               (void FAR*        pvPar,
                                             UINT             uPar);

RX_FATAL FAR    _physHif_MidSysSerialFlashInit       (void FAR*        pvPar,
                                             UINT             uPar);

RX_FATAL FAR    _physHif_MidSysParallelFlashInit     (void FAR*        pvPar,
                                             UINT             uPar);

/* mandatory routers have to call this function in InitLocal otherwise the
   MID_SYS_ROUTER_MANDATORY flag will be ignored */
RX_RESULT FAR   _physHif_Mid_SysRegisterRouter       (RX_HANDLE        hQueRouter,
                                             UINT32           ulMTU,
                                             UINT32           ulFlags);

RX_RESULT FAR   _physHif_Mid_SysModuleGetInitTable   (void FAR *       ptModuleUuid,
                                             void FAR*FAR*    ppvInitTable);

RX_RESULT FAR   _physHif_Mid_SysModuleInstantiate    (void FAR*        ptModuleUuid,
                                             UINT             uInst,
                                             void FAR*        pvInitParam);

RX_RESULT FAR   _physHif_Mid_SysTskIdentify          (UINT32           ulTskIdentifier,
                                             UINT             uInst,
                                             RX_HANDLE FAR*   phTsk);

/***************************************************************************************/
#endif /* #ifndef __MID_SYS_PHYSHIF_H */

#ifdef __cplusplus
}
#endif
