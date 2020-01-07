/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: DPM_Struct.h 348 2011-07-08 10:10:22Z mtrensch $

  Description:
    netX DPM definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-07-07  NC            File created.

******************************************************************************/


#ifndef _DPM_STRUCT_H
#define _DPM_STRUCT_H


typedef struct NETX_DPM_REGISTERS_Ttag
{
  volatile unsigned long ulDpmCfg0x0;
  volatile unsigned long aulReserved0[3];
  volatile unsigned long ulDpmAddrCfg;
  volatile unsigned long ulDpmTimingCfg;
  volatile unsigned long ulDpmRdyCfg;
  volatile unsigned long ulDpmStatus;
  volatile unsigned long ulDpmStatusErrReset;
  volatile unsigned long ulDpmStatusErrAddr;
  volatile unsigned long ulDpmMiscCfg;
  volatile unsigned long ulDpmIoMiscCfg;
  volatile unsigned long aulReserved1[2];
  volatile unsigned long ulDpmTunnelCfg;
  volatile unsigned long ulDpmITBAddr;
  volatile unsigned long ulDpmWin1End;
  volatile unsigned long ulDpmWin1Map;
  volatile unsigned long ulDpmWin2End;
  volatile unsigned long ulDpmWin2Map;
  volatile unsigned long ulDpmWin3End;
  volatile unsigned long ulDpmWin3Map;
  volatile unsigned long ulDpmWin4End;
  volatile unsigned long ulDpmWin4Map;
  volatile unsigned long aulReserved2[8];
  volatile unsigned long ulDpmIrqRaw;
  volatile unsigned long ulDpmIrqArmMaskSet;
  volatile unsigned long ulDpmIrqArmMaskReset;
  volatile unsigned long ulDpmIrqArmMasked;
  volatile unsigned long ulDpmIrqXpicMaskSet;
  volatile unsigned long ulDpmIrqXpicMaskReset;
  volatile unsigned long ulDpmIrqXpicMasked;
  volatile unsigned long ulDpmIrqFiqMaskSet;
  volatile unsigned long ulDpmIrqFiqMaskReset;
  volatile unsigned long ulDpmIrqFiqMasked;
  volatile unsigned long ulDpmIrqIrqMaskSet;
  volatile unsigned long ulDpmIrqIrqMaskReset;
  volatile unsigned long ulDpmIrqIrqMasked;
  volatile unsigned long aulReserved3[3];
  volatile unsigned long aulReserved4[3];
  volatile unsigned long ulDpmSysStaBigEnd16;
  volatile unsigned long aulReserved5[2];
  volatile unsigned long ulDpmSysSta;
  volatile unsigned long ulDpmResetRequest;
  volatile unsigned long ulDpmFirmwareIrqRaw;
  volatile unsigned long aulReserved6[3];
  volatile unsigned long ulDpmFirmwareIrqMask;
  volatile unsigned long ulReserved7;
  volatile unsigned long ulDpmNetxVersionBigEnd16;
  volatile unsigned long ulDpmNetxVersion;
} NETX_DPM_REGISTERS_T;


typedef struct NETX_HANDSHAKE_CTRL_REGISTERS_Ttag
{
  volatile unsigned long ulHandshakeBaseAddr;
  volatile unsigned long aulReserved0[3];
  volatile unsigned long ulHandshakeDpmIrqRawClear;
  volatile unsigned long ulHandshakeDpmIrqMasked;
  volatile unsigned long ulHandshakeDpmIrqMskSet;
  volatile unsigned long ulHandshakeDpmIrqMskReset;
  volatile unsigned long ulHandshakeArmIrqRawClear;
  volatile unsigned long ulHandshakeArmIrqMasked;
  volatile unsigned long ulHandshakeArmIrqMskSet;
  volatile unsigned long ulHandshakeArmIrqMskReset;
  volatile unsigned long ulHandshakeXpicIrqRawClear;
  volatile unsigned long ulHandshakeXpicIrqMasked;
  volatile unsigned long ulHandshakeXpicIrqMskSet;
  volatile unsigned long ulHandshakeXpicIrqMskReset;
  volatile unsigned long aulReserved1[16];
  volatile unsigned long aulHandshakeHscCtrl[16];
  volatile unsigned long ulHandshakeBufMan0Ctrl;
  volatile unsigned long ulHandshakeBufMan0StatusCtrlNetx;
  volatile unsigned long ulHandshakeBufMan0StatusCtrlHost;
  volatile unsigned long ulHandshakeBufMan0WinMap;
  volatile unsigned long ulHandshakeBufMan1Ctrl;
  volatile unsigned long ulHandshakeBufMan1StatusCtrlNetx;
  volatile unsigned long ulHandshakeBufMan1StatusCtrlHost;
  volatile unsigned long ulHandshakeBufMan1WinMap;
} NETX_HANDSHAKE_CTRL_REGISTERS_T;

typedef struct NETX_HIF_IO_CTRL_REGISTERS_Ttag
{
  volatile unsigned long ulHifIoCfg;
  volatile unsigned long aulHifPioOut[2];
  volatile unsigned long aulHifPioOutEn[2];
  volatile unsigned long aulHifPioIn[2];
} NETX_HIF_IO_CTRL_REGISTERS_T;

#endif
