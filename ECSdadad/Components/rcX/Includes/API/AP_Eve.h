/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Eve.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of Event Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_EVE_H
#define __AP_EVE_H
  
  /*
  **************************************************************************
  *   Size of one Event Group Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  #define RX_EVENTGROUP_SIZE (2884)
  
  /*
  **************************************************************************
  *   Size of one Mutliple Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  #define RX_MULTIPLE_SIZE (16)
  
  /*
  ************************************************************
  *   Eventgroup specifics
  ************************************************************
  */  
    
  #define RX_EVEGRP_MODE_ONE 1
  #define RX_EVEGRP_MODE_ALL 2
  
  #define RX_EVEGRP_MODE_SET 0
  #define RX_EVEGRP_MODE_CLR 1
  
  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  RX_RESULT FAR rX_EveCreateEventGroup      (CONST STRING FAR*      pszIdn, 
                                             RX_HANDLE              hEveGrp);
  
  RX_RESULT FAR rX_EveIdentifyEventGroup    (CONST STRING FAR*      pszIdn,
                                             UINT                   uInst,
                                             RX_HANDLE FAR*         phEveGrp); 
  
  RX_RESULT FAR rX_EveChangeEventGroup      (RX_HANDLE              hEveGrp,
                                             UINT32                 ulEvent,
                                             UINT                   uMode); 
  
  RX_RESULT FAR rX_EveWaitForEventGroup     (RX_HANDLE              hEveGrp,
                                             UINT                   uTimOpt);
  
  RX_RESULT FAR rX_EveDeleteEventGroup      (RX_HANDLE              hEveGrp);

  RX_RESULT FAR rX_EveWaitForMultiple       (UINT32                 ulObjSel,
                                             UINT32 FAR*            pulObjInd,
                                             UINT                   uTimOpt); 

  RX_RESULT FAR rX_EveSetupEventGroup       (RX_HANDLE              hEveGrp,
                                             UINT32                 ulEveMsk,
                                             UINT                   uMode,
                                             UINT32 FAR*            pulCurEve); 

  RX_RESULT FAR rX_EveCreateMultiple        (RX_HANDLE              hMlp,
                                             RX_HANDLE              hObj,
                                             UINT32                 ulEveMsk);

  RX_RESULT FAR rX_EveDeleteMultiple        (RX_HANDLE hMlp);

#endif /* __AP_EVE_H */

#ifdef __cplusplus
}
#endif
