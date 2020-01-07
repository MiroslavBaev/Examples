/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: Xc_Struct.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX communication channel definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _XC_STRUCT_H
#define _XC_STRUCT_H

//-------------------------------------

// size of ram areas in dwords (32 bits)
#define XMAC_RPU_DWORD_RAMSIZE 0x0100
#define XMAC_TPU_DWORD_RAMSIZE 0x0100
#define XPEC_DWORD_RAMSIZE 0x0800

typedef struct {
        volatile unsigned long aulRpuProgram[XMAC_RPU_DWORD_RAMSIZE];
        volatile unsigned long aulTpuProgram[XMAC_TPU_DWORD_RAMSIZE];
        volatile unsigned long aulSr[16];
        volatile unsigned long ulStatusShared0;
        volatile unsigned long ulConfigShared0;
        volatile unsigned long ulStatusShared1;
        volatile unsigned long ulConfigShared1;
        volatile unsigned long aulReserved0[4];
        volatile unsigned long aulUrxUtx[2];
        volatile unsigned long aulReserved1[2];
        volatile unsigned long ulUrx;
        volatile unsigned long ulUtx;
        volatile unsigned long ulRx;
        volatile unsigned long ulRxHw;
        volatile unsigned long ulRxHwCount;
        volatile unsigned long ulTx;
        volatile unsigned long ulTxHw;
        volatile unsigned long ulTxHwCount;
        volatile unsigned long ulTxSend;
        volatile unsigned long ulRpuPc;
        volatile unsigned long ulTpuPc;
        volatile unsigned long aulWr[10];
        volatile unsigned long ulSysTime;
        volatile unsigned long ulSysTimeUpper;
        volatile unsigned long aulCmpStatus[4];
        volatile unsigned long ulAluFlags;
        volatile unsigned long ulStatusInt;
        volatile unsigned long ulStatBits;
        volatile unsigned long ulStatusMii;
        volatile unsigned long ulStatusMii2;
        volatile unsigned long ulConfigMii;
        volatile unsigned long ulConfigNibbleFifo;
        volatile unsigned long ulConfigSbu;
        volatile unsigned long ulSbuRateMulAdd;
        volatile unsigned long ulSbuRateMulStart;
        volatile unsigned long ulSbuRateMul;
        volatile unsigned long ulStartSamplePos;
        volatile unsigned long ulStopSamplePos;
        volatile unsigned long ulConfigObu;
        volatile unsigned long ulObuRateMulAdd;
        volatile unsigned long ulObuRateMulStart;
        volatile unsigned long ulObuRateMul;
        volatile unsigned long ulStartTransPos;
        volatile unsigned long ulStopTransPos;
        volatile unsigned long ulRpuCount1;
        volatile unsigned long ulRpuCount2;
        volatile unsigned long ulTpuCount1;
        volatile unsigned long ulTpuCount2;
        volatile unsigned long ulRxCount;
        volatile unsigned long ulTxCount;
        volatile unsigned long ulRpmMask0;
        volatile unsigned long ulRpmVal0;
        volatile unsigned long ulRpmMask1;
        volatile unsigned long ulRpmVal1;
        volatile unsigned long ulTpmMask0;
        volatile unsigned long ulTpmVal0;
        volatile unsigned long ulTpmMask1;
        volatile unsigned long ulTpmVal1;
        volatile unsigned long aulReserved2[28];
        volatile unsigned long ulRxTxNofBits;
        volatile unsigned long ulReserved3;
        volatile unsigned long ulRxCrcPolynomialL;
        volatile unsigned long ulRxCrcPolynomialH;
        volatile unsigned long ulRxCrcL;
        volatile unsigned long ulRxCrcH;
        volatile unsigned long ulRxCrcCfg;
        volatile unsigned long ulTxCrcPolynomialL;
        volatile unsigned long ulTxCrcPolynomialH;
        volatile unsigned long ulTxCrcL;
        volatile unsigned long ulTxCrcH;
        volatile unsigned long ulTxCrcCfg;
        volatile unsigned long ulRpuHoldPc;
        volatile unsigned long ulTpuHoldPc;
} XMAC_AREA_T, *PXMAC_AREA_T;

typedef struct {
        volatile unsigned long aulR[8];
        volatile unsigned long ulRange01;
        volatile unsigned long ulRange23;
        volatile unsigned long ulRange45;
        volatile unsigned long ulRange67;
        volatile unsigned long ulTimer0;
        volatile unsigned long ulTimer1;
        volatile unsigned long ulTimer2;
        volatile unsigned long ulTimer3;
        volatile unsigned long ulUrxCount;
        volatile unsigned long ulUtxCount;
        volatile unsigned long ulPc;
        volatile unsigned long ulZero;
        volatile unsigned long ulStatCfg;
        volatile unsigned long ulEcMaskA;
        volatile unsigned long ulEcMaskB;
        volatile unsigned long ulEcMask0;
        volatile unsigned long ulEcMask1;
        volatile unsigned long ulEcMask2;
        volatile unsigned long ulEcMask3;
        volatile unsigned long ulEcMask4;
        volatile unsigned long ulEcMask5;
        volatile unsigned long ulEcMask6;
        volatile unsigned long ulEcMask7;
        volatile unsigned long ulEcMask8;
        volatile unsigned long ulEcMask9;
        volatile unsigned long ulTimer4;
        volatile unsigned long ulTimer5;
        volatile unsigned long ulIrq;
        volatile unsigned long ulSystimeNs;
        volatile unsigned long ulFifoData;
        volatile unsigned long ulSystimeS;
        volatile unsigned long ulAdc;
        volatile unsigned long aulSr[16];
        volatile unsigned long aulStatCfg[4];
        volatile unsigned long aulUrtx[4];
        volatile unsigned long ulXpuHoldPc;
        
        volatile unsigned long aulReserved0[4031];
        volatile unsigned long aulPRam[XPEC_DWORD_RAMSIZE];
        volatile unsigned long aulRam[XPEC_DWORD_RAMSIZE];
} XPEC_AREA_T, *PXPEC_AREA_T;

typedef struct
{
  volatile unsigned long aulIrq[2];
} XPEC_IRQ_AREA_T, *PXPEC_IRQ_AREA_T;

#endif
