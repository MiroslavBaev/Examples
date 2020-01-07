/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Que.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX Queue function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_QUE_H
#define __AP_QUE_H

#ifdef __cplusplus
  extern "C" {
#endif
  
  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a queue
  ***************************************************************************/
  #define RX_QUEUE_SIZE (88)

  typedef void(FAR* PFN_RX_QUEUE_LOAD_CALLBACK)(RX_HANDLE hQueue, UINT uiLoad, INT iCnt, void FAR* pvParam);
  
  /*************************************************************
  *   Function Prototypes
  *************************************************************/
  RX_RESULT FAR rX_QueCreateQueue         (const STRING FAR*  pszIdn,
                                           RX_HANDLE          hQue,
                                           void FAR*FAR*      papvQue,
                                           UINT               uDep); 
                                    
  RX_RESULT FAR rX_QueIdentifyQueue       (const STRING FAR*  pszIdn,
                                           UINT               uInst,
                                           RX_HANDLE FAR*     phQue); 

  RX_RESULT FAR rX_QueDeleteQueue         (RX_HANDLE          hQue); 
  
  RX_RESULT FAR rX_QueWaitForPacket       (RX_HANDLE          hQue,
                                           void FAR* FAR*     ppvPkt,
                                           UINT               uTimOpt); 

  RX_RESULT FAR rX_QueSendPacket          (RX_HANDLE          hQue,
                                           void FAR*          pvPkt,
                                           UINT               uTimOpt); 
  
  RX_RESULT FAR rX_QueSendPriorityPacket  (RX_HANDLE          hQue,
                                           void FAR*          pvPkt,
                                           UINT               uTimOpt);

  RX_RESULT FAR rX_QuePostPacket          (RX_HANDLE          hQue,
                                           void FAR*          pvPkt);

#ifdef __GNUC__
  RX_RESULT FAR rX_QuePeekPacket          (RX_HANDLE          hQue,
                                           void FAR* FAR*     ppvPkt) __attribute__ ((deprecated));
#else
  RX_RESULT FAR rX_QuePeekPacket          (RX_HANDLE          hQue,
                                           void FAR* FAR*     ppvPkt);
#endif
 
  RX_RESULT FAR rX_QueGetQueueLoad        (RX_HANDLE          hQue,
                                           UINT32 FAR*        pulLd);

  RX_RESULT FAR rX_QueSetLoadCallback     (RX_HANDLE                  hQue,
                                           PFN_RX_QUEUE_LOAD_CALLBACK pfnCallback,
                                           void FAR*                  pvPrm);

  RX_RESULT rX_QueIdentifyMTU             (RX_HANDLE          hQue, 
                                           UINT32 FAR*        pulMTU);

#ifdef __cplusplus
  }
#endif

#endif /* __AP_QUE_H */
