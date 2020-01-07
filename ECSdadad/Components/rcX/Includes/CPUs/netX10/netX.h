/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: netX.h 414 2010-06-24 06:05:41Z MichaelT $

  Description:
    netX General Definitons

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef __NETX_H
 #define __NETX_H

  #define NETX_XPEC_MEM_SIZE 2048 /* Size of an xPEC memory is 2048 D-WORDS */
  
    /* Structure defintion of the Bootblock */
  typedef struct NETX_BOOTBLOCK_Ttag {
    UINT32 ulMagCok;

    union {
      UINT32 ulMemCtrl;      
      UINT32 ulSpeed;
      UINT32 ulRes;
    } unCtrl;

    UINT32 ulAppEnt;
    UINT32 ulAppChksm;
    UINT32 ulAppFilSiz;
    UINT32 ulAppSrtAdd;
    UINT32 ulSignt;
    union {
      UINT32 ulSdramGeneralCtrl;
      UINT32 ulExpBusReg;
    } unCtrl0;
    union {
      UINT32 ulSdramTimingCtrl;
      UINT32 ulIoRegMode0;
    } unCtrl1;
    union {
      UINT32 ulIoRegMode1; 
      UINT32 ulRes0; 
    } unCtrl2;
    union {
      UINT32 ulIfConf1; 
      UINT32 ulRes0; 
    } unCtrl3;
    union {
      UINT32 ulIfConf2; 
      UINT32 ulRes0; 
    } unCtrl4;
    UINT32 ulMiscAsicCtrl;
    UINT32 ulUserData;
    UINT32 ulSrcType;
    UINT32 ulBootChksm;
  } NETX_BOOTBLOCK_T;
  
#endif
