/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Expt.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX exception handler function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_EXPT_H
#define __AP_EXPT_H

#ifdef __cplusplus
  extern "C" {
#endif

  #define RX_EXCEPTION_TYPE_UND   0
  #define RX_EXCEPTION_TYPE_SWI   1
  #define RX_EXCEPTION_TYPE_DAB   2
  #define RX_EXCEPTION_TYPE_PAB   3
  #define RX_EXCEPTION_MAX        4

  typedef int RX_EXCEPTION_TYPE;

  typedef union
  {
    struct
    {
      UINT32  dfsr;
      UINT32  dfar;
      UINT32  r0;
      UINT32  r1;
      UINT32  r2;
      UINT32  r3;
      UINT32  r4;
      UINT32  r5;
      UINT32  r6;
      UINT32  r7;
      UINT32  r8;
      UINT32  r9;
      UINT32  r10;
      UINT32  r11;
      UINT32  r12;
      UINT32  sp;
      UINT32  lr;
      UINT32  pc;
      UINT32  cpsr;
    };
    
    struct
    {
      UINT32 ulFSR;    /* Fault status register                       */
      UINT32 ulFAR;    /* Fault address register                      */
      UINT32 aulR[11]; /* work registers (r0-r10)                     */
      UINT32 ulFP;     /* Frame pointer (r11)                         */
      UINT32 ulIP;     /* Intra-Procedure call scratch register (r12) */
      UINT32 ulSP;     /* Stack pointer (r13)                         */
      UINT32 ulLR;     /* Link Register (r14)                         */
      UINT32 ulPC;     /* Program counter (r15, pc)                   */
      UINT32 ulPSR;    /* Program status register (cpsr)              */
    };

  } RX_EXCEPTION_INFO_T;
  
  #define  RX_EXCEPTION_HOLD      (0) /* Exception was NOT handled -> endless loop */
  #define  RX_EXCEPTION_CONTINUE  (1) /* Exception was handled -> restore context  */
  typedef int RX_EXCEPTION_RETURN; 

  /*************************************************************
  *   Function Prototypes
  *************************************************************/

  typedef RX_EXCEPTION_RETURN(CALLBACK FAR* PFN_RX_EXCEPTION_HANDLER)(RX_EXCEPTION_TYPE uiExceptionType, RX_EXCEPTION_INFO_T FAR* ptExceptionFrame);

  RX_RESULT FAR   rX_CpuSetExceptionVector (int                      iType,
                                            PFN_RX_EXCEPTION_HANDLER pfnHandler);

  RX_RESULT FAR   rX_CpuGetExceptionVector (int                      iType,
                                            PFN_RX_EXCEPTION_HANDLER* ppfnHandler);


#ifdef __cplusplus
  }
#endif

#endif /* __AP_EXPT_H */
