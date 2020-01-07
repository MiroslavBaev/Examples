/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Mem.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX memory management (heap, triple buffer, SHM) function prototypes 
      and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_MEM_H
#define __AP_MEM_H

#ifdef __cplusplus
  extern "C" {
#endif


  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a shared memory
  ***************************************************************************/
  #define RX_SHAREDMEMORY_SIZE (120)

  /***************************************************************************
  * Size of the handle that needs to be allocated when creating a triple buffer
  ***************************************************************************/
  #define RX_TRIPLEBUFFER_SIZE (72)

  /*****************************************************************************
  *   Buffer Pointer definiton for a Triple Buffer
  *****************************************************************************/
  typedef struct RX_BUFFERPOOL_Ttag 
  {
    UINT8 FAR* pabBufA;
    UINT8 FAR* pabBufB;
    UINT8 FAR* pabBufC;
  } RX_BUFFERPOOL_T;

  typedef void (FAR* TRIPLEBUFFER_CALLBACK)(RX_HANDLE hTripleBuffer, void FAR* pvPrm);

  /*************************************************************
  *   Function Prototypes
  *************************************************************/
  
  /* Heap management */
  RX_FATAL FAR rXMemoryInit                     (void);

  RX_RESULT FAR rX_MemAllocateMemory            (void HUGE* FAR*        ppvMem,
                                                 UINT32                 ulSize);

  RX_RESULT FAR rX_MemFreeMemory                (void HUGE*             pvMem);

  RX_RESULT FAR rX_MemGetFreeMemory             (UINT32 FAR*            pulFreeMem,
                                                 UINT32 FAR*            pulLargestFreeBlock);
  RX_RESULT FAR rX_MemReAllocateMemory          (void HUGE* FAR*        ppvOldMem,
                                                 void HUGE* FAR*        ppvNewMem,
                                                 UINT32                 ulNewSiz);      /* Reallocate Memory, copy content od old block in new one */




  /* Shared memory */
#ifdef __GNUC__
  RX_RESULT FAR rX_MemCreateSharedMemory        (const STRING FAR*      pszIdn,
                                                 RX_HANDLE              hShm,
                                                 void FAR*              pvShm,
                                                 UINT32                 ulSize) __attribute__ ((deprecated));

  RX_RESULT FAR rX_MemIdentifySharedMemory      (const STRING FAR*      pszIdn,
                                                 UINT                   uInst,
                                                 RX_HANDLE FAR*         phShm) __attribute__ ((deprecated));

  RX_RESULT FAR rX_MemGetSharedMemoryInfo       (RX_HANDLE              hShm,
                                                 void FAR* FAR*         ppvShm,
                                                 UINT32 FAR*            pulSize) __attribute__ ((deprecated));

  RX_RESULT FAR rX_MemLockSharedMemory          (RX_HANDLE              hShm,
                                                 UINT                   uTimOpt) __attribute__ ((deprecated));

  RX_RESULT FAR rX_MemUnlockSharedMemory        (RX_HANDLE              hShm) __attribute__ ((deprecated));
#else
  RX_RESULT FAR rX_MemCreateSharedMemory        (const STRING FAR*      pszIdn,
                                                 RX_HANDLE              hShm,
                                                 void FAR*              pvShm,
                                                 UINT32                 ulSize);

  RX_RESULT FAR rX_MemIdentifySharedMemory      (const STRING FAR*      pszIdn,
                                                 UINT                   uInst,
                                                 RX_HANDLE FAR*         phShm);

  RX_RESULT FAR rX_MemGetSharedMemoryInfo       (RX_HANDLE              hShm,
                                                 void FAR* FAR*         ppvShm,
                                                 UINT32 FAR*            pulSize);

  RX_RESULT FAR rX_MemLockSharedMemory          (RX_HANDLE              hShm,
                                                 UINT                   uTimOpt);

  RX_RESULT FAR rX_MemUnlockSharedMemory        (RX_HANDLE              hShm);
#endif




  /* Triple buffers */
  RX_RESULT FAR rX_MemCreateTripleBuffer        (const STRING FAR*      pszIdn,
                                                 RX_HANDLE              hTrp,
                                                 RX_BUFFERPOOL_T FAR*   ptBufPool);

  RX_RESULT FAR rX_MemDeleteTripleBuffer        (RX_HANDLE              ptTrp);

  RX_RESULT FAR rX_MemIdentifyTripleBuffer      (const STRING FAR*      pszIdn,
                                                 UINT                   uInst,
                                                 RX_HANDLE FAR*         phTripleBuf);

  RX_RESULT FAR rX_MemExchangeGetCurrentBuffer  (RX_HANDLE              hTripleBuf,
                                                 UINT8 FAR* FAR*        ppabUsrBuf);

  RX_RESULT FAR rX_MemExchangeBuffer            (RX_HANDLE              hTripleBuf,
                                                 UINT8 FAR* FAR*        ppabUsrBuf);

  RX_RESULT FAR rX_MemGetExchangedBuffer        (RX_HANDLE              hTrp,
                                                 UINT8 FAR* FAR*        ppabUsrBuf);

  RX_RESULT FAR rX_MemGetExchangedBufferWait    (RX_HANDLE              hTrp,
                                                 UINT8 FAR* FAR*        ppabUsrBuf,
                                                 UINT                   uTimOpt);     /* Request for the last updated buffer, possibly wait for it to happen */

  RX_RESULT FAR rX_MemEnableTripleCallback      (RX_HANDLE              hTrp,
                                                 TRIPLEBUFFER_CALLBACK  pfnCallback,
                                                 void FAR*              pvPrm);

  RX_RESULT FAR rX_MemDisableTripleCallback     (RX_HANDLE              hTrp);


  /* MMU support module calls */
  RX_RESULT FAR rX_MemRequestPhysRegion         (UINT32                       ulPhysAddr,
                                                 UINT32                       ulSize,
                                                 BOOLEAN                      fCached,
                                                 void HUGE* FAR*              ppvMemAddr);

  RX_RESULT FAR rX_MemReleasePhysRegion         (void FAR*                    pvMemAddr,
                                                 UINT32                       ulSize);


#ifdef __cplusplus
  }
#endif
  
#endif /* __AP_MEM_H */
