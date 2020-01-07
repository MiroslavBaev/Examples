/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_MidSys.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Mid Sys - public

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_MID_SYS_H
#define __AP_MID_SYS_H

/* router will check the link status or the remote application has to activate it */
#define MID_SYS_ROUTER_CHECKS_STATUS  0x00000001
/* Mid_Sys task shall not start the identification process on the link */
#define MID_SYS_ROUTER_NO_IDENTIFY    0x00000002
/* Mid_Sys task considers this router as mandatory for its Queue Identify function */
#define MID_SYS_ROUTER_MANDATORY      0x00000004

/***************************************************************************************/
/* Mid Sys public, constants */


/***************************************************************************************/
/* Mid Sys public, prototypes */


RX_FATAL FAR    MidSysInit                  (void FAR*        pvPar, 
                                             UINT             uPar);

RX_FATAL FAR    MidSysModuleLoadInit        (void FAR*        pvPar,
                                             UINT             uPar);
  
RX_FATAL FAR    MidSysDpmInit               (void FAR*        pvPar,
                                             UINT             uPar);
                                            
/* mandatory routers have to call this function in InitLocal otherwise the
   MID_SYS_ROUTER_MANDATORY flag will be ignored */
RX_RESULT FAR   Mid_SysRegisterRouter       (RX_HANDLE        hQueRouter,
                                             UINT32           ulMTU, 
                                             UINT32           ulFlags);
                                             
RX_RESULT FAR   Mid_SysModuleGetInitTable   (void FAR *       ptModuleUuid,
                                             void FAR*FAR*    ppvInitTable);
                                             
RX_RESULT FAR   Mid_SysModuleInstantiate    (void FAR*        ptModuleUuid,
                                             UINT             uInst,
                                             void FAR*        pvInitParam);
                                             
RX_RESULT FAR   Mid_SysTskIdentify          (UINT32           ulTskIdentifier,
                                             UINT             uInst,
                                             RX_HANDLE FAR*   phTsk);
                                             
RX_RESULT FAR   Mid_SysDpmCreateChannel     (RX_HIF_CHANNEL_T* ptChannel, 
                                             RX_HANDLE*        phChannel, 
                                             UINT32*           pulDPMChannel, 
                                             BOOLEAN           fCommit);

/***************************************************************************************/
#endif /* #ifndef __MID_SYS_H */

#ifdef __cplusplus
}
#endif
