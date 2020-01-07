/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Dia.h 1028 2012-07-31 12:40:52Z stephans $

  Description:
    USER - Headerfile of Diagnostic Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_DIA_H
  #define __AP_DIA_H
  
  
  
  /*
  **************************************************************************
  *   Size of one Information Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  #define RX_INFORMATION_SIZE (20)
  
  typedef struct RX_INFORMATION_ENTRY_Ttag {
    UINT          uLen;               /* Length of the referenced structure */
    void FAR*     pvStr;              /* Pointer to the structure to be referenced */
    UINT          uStructInfoLen;     /* Length of the structure information related to the structure */
    void FAR*     pvStructInfo;       /* Pointer to the structure information */
  } RX_INFORMATION_ENTRY_T;
  
  /*
  *****************************************************************
  *  Common Error codes and Status information reported by a Task *
  *****************************************************************
  */ 
  
  #define TASK_STA_OK       (0)
  #define TASK_STA_DISABLE  (1)
  #define TASK_STA_IDLE     (2)
  #define TASK_STA_NOT_INITIALIZED (-1)
  
  typedef struct RX_TASK_STATUS_Ttag
  {
    RX_HANDLE hTask;
    UINT32    ulStatusCode;
  } RX_TASK_STATUS_T;  
  
  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */ 
  
  void FAR        rX_DiaSetTaskStatus                         (UINT32                         ulStatus);


  RX_RESULT FAR   rX_DiaCreateInformationField                (RX_HANDLE                      hTskNfo,
                                                               UINT                           uLen,
                                                               void FAR*                      pvStr); 

  RX_RESULT FAR   rX_DiaCreateInformationFieldWithStructInfo  (RX_HANDLE                      hTskNfo,
                                                               UINT                           uLen,
                                                               void FAR*                      pvStruct,
                                                               UINT                           uStructInfoLen,
                                                               void FAR*                      pvStructInfo); 

  RX_RESULT FAR   rX_DiaRemoveInformationField                (RX_HANDLE                      hTask, 
                                                               UINT                           uNfoNum);

  RX_RESULT FAR   rX_DiaGetInformationField                   (RX_HANDLE                      hTsk,
                                                               UINT                           uNfoNum,
                                                               RX_INFORMATION_ENTRY_T FAR*    ptNfo);
  
  RX_RESULT FAR   rX_DiaGetTaskStatus                         (RX_HANDLE                      hTsk,
                                                               UINT32 FAR*                    pulStatus);

  RX_RESULT FAR   rX_DiaCreateHookTaskStatus                  (RX_HANDLE                      hHok,  
                                                               PFN_RX_HOOK_NOTIFY             fnNotify,
                                                               void FAR*                      pvInp);
  
  
#endif  

#ifdef __cplusplus
}
#endif

