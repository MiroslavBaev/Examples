/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: AP_Sig.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX signal / event function prototypes and definitions

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __AP_SIG_H
#define __AP_SIG_H

#ifdef __cplusplus
  extern "C" {
#endif

  /*************************************************************
  *   Function Prototypes
  *************************************************************/
  RX_RESULT FAR   rX_SigCreateSignal    (const STRING FAR*    pszIdn,
                                         UINT FAR*            puSignl,
                                         BOOLEAN              fManRst);

  RX_RESULT FAR   rX_SigIdentifySignal  (const STRING FAR*    pszIdn,
                                         UINT                 uInst,
                                         UINT FAR*            puSignlIdx);

  RX_RESULT FAR   rX_SigDeleteSignal    (UINT                 uSignlIdx);

  RX_RESULT FAR   rX_SigWaitForSignal   (UINT                 uSignlIdx,
                                         UINT                 uTimOpt);

  RX_RESULT FAR   rX_SigSetSignal       (UINT                 uSignlIdx);

  RX_RESULT FAR   rX_SigResetSignal     (UINT                 uSignlIdx);


#ifdef __cplusplus
  }
#endif

#endif /* __AP_SIG_H */
