/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Mtx.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX Mutex function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_MTX_H
#define __AP_MTX_H

#ifdef __cplusplus
  extern "C" {
#endif


  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a mutex
  ***************************************************************************/
  #define RX_MUTEX_SIZE (64)

  /*************************************************************
  * Function Prototypes
  *************************************************************/
  RX_RESULT FAR rX_MtxCreateMutex     (const STRING FAR*      pszIdn,
                                       RX_HANDLE              hMutex,
                                       UINT                   uMaxProc);

  RX_RESULT FAR rX_MtxIdentifyMutex   (const STRING FAR*      pszIdn,
                                       UINT                   uInst,
                                       RX_HANDLE FAR*         phMutex);

  RX_RESULT FAR rX_MtxDeleteMutex     (RX_HANDLE              hMutex);

  RX_RESULT FAR rX_MtxLockMutex       (RX_HANDLE              hMutex,
                                       UINT                   uiTiemout);

  RX_RESULT FAR rX_MtxUnlockMutex     (RX_HANDLE              hMutex);


#ifdef __cplusplus
}
#endif

#endif /* __AP_MTX_H */
