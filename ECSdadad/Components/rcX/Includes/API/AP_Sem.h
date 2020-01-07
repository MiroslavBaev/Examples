/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Sem.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX semaphore function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_SEM_H
#define __AP_SEM_H
 
#ifdef __cplusplus
  extern "C" {
#endif
 
  
  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a semaphore
  ***************************************************************************/
  #define RX_SEMAPHORE_SIZE (52)
  
  
  /*************************************************************
  *   Function Prototypes
  *************************************************************/
  RX_RESULT FAR   rX_SemCreateSemaphore       (const STRING FAR*      pszIdn,
                                               RX_HANDLE              hSem,
                                               UINT                   uMaxProc); 
  
  RX_RESULT FAR   rX_SemIdentifySemaphore     (const STRING FAR*      pszIdn,
                                               UINT                   uInst,
                                               RX_HANDLE FAR*         phSem); 
  
  RX_RESULT FAR   rX_SemDeleteSemaphore       (RX_HANDLE              hSem); 
  
  RX_RESULT FAR   rX_SemPutSemaphore          (RX_HANDLE              hSem); 
  
  RX_RESULT FAR   rX_SemWaitForSemaphore      (RX_HANDLE              hSem,
                                               UINT                   uTimeoutOpt); 
  
  RX_RESULT FAR   rX_SemWaitForSemaphoreCount (RX_HANDLE              hSem, 
                                               UINT FAR*              puCurCnt, 
                                               UINT                   uTimeoutOpt);
  
  RX_RESULT FAR   rX_SemClearSemaphoreCount   (RX_HANDLE              hSem);
#ifdef __cplusplus
  }
#endif

#endif /* __AP_SEM_H */
