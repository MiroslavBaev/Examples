/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: rX_Includes.h 1326 2013-03-06 12:02:28Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2013-03-06 13:02:28 +0100 (Wed, 06 Mar 2013) $
    $Revision: 1326 $

   Targets:
     rcX      : yes

   Description:
      rcX main include file

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#include "TLR_INX_Includes.h"

#ifndef __RX_INCLUDES_H
#define __RX_INCLUDES_H
  
 /*************************************************************
  *  rcX internal data types, macros and error codes
  *************************************************************/
  #include "rX_Types.h"   /* General Data Types, UINT8, UINT16... */
  #include "rX_Macros.h"  /* Helpful Macros */
  #include "rX_Consts.h"  /* rcX Constants  */

  #include "rX_ErrorCodes.h" /* rcX Error codes */
  #include "rX_Priorities.h" 
  #include "rX_Tokens.h" 
  #include "rX_Functions.h" 
  #include "rX_StatusCodes.h" 

 /*************************************************************
  *  Middleware includes
  *************************************************************/

 /*************************************************************
  *  rcX Kernel Modules
  *************************************************************/
  #include "AP_Expt.h" /* CPU exception module */
  #include "AP_Sys.h"  /* System management module */
  #include "AP_Task.h"
  #include "AP_Eve.h"  /* Eventgroup / WaitMultiple */
  #include "AP_Que.h"  /* Queue module */
  #include "AP_Tim.h"  /* Timer module */
  #include "AP_Mem.h"  /* Memory module */
  #include "AP_Sem.h"  /* Semaphort module */
  #include "AP_Mtx.h"  /* Mutex module */
  #include "AP_Sig.h"  /* Signal module */
  #include "AP_Flt.h" 
  #include "AP_Dia.h" 
  #include "AP_Sec.h" 
  #include "AP_Hif.h" 
  #include "AP_HifSync.h" 
  #include "AP_HifPio.h" 
  #include "AP_Int.h" 
  #include "AP_Fiq.h" 
  #include "AP_Hti.h" 
  #include "AP_Bas.h" 
  #include "AP_MidSys.h" 
  #include "AP_Dbm.h" 
  #include "AP_SysTime.h" 
  #include "AP_Xc.h" 
  #include "AP_Vol.h" 
  #include "AP_Fld.h" 
  #include "AP_Rdk.h" 
  #include "AP_Rrd.h" 
  #include "AP_Gpio.h" 
  #include "AP_Fif.h" 
  #include "AP_Spi.h" 
  #include "AP_I2c.h"
  #include "AP_Sfl.h" 
  #include "AP_Pfl.h" 
  #include "AP_Pio.h" 
  #include "AP_Urt.h" 
  #include "AP_Led.h" 
  #include "AP_Dev.h" 
  #include "AP_Fat.h" 
  #include "AP_Edd.h"
  #include "AP_Phy.h"
  #include "AP_SramBus.h"   /* SRAM bus initialization */
  #include "AP_MMC.h"
  #include "AP_Rtc.h"
  #include "AP_IO.h"
  
 /*************************************************************
  *  Peripherals configuration
  *************************************************************/
  #include "rX_Config.h"  /* Peripheral Configuration definitions */
  
 /*************************************************************
  *  RX-Driver Modules includes
  *************************************************************/ 
  #include "rcX_User.h"
  #include "rcX_Public.h"
  #include <string.h>

  #include "AP_Ddp.h"

#endif /* inclusion lock */
